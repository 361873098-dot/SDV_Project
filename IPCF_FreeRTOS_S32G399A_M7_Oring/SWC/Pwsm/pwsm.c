/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: pwsm.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      PWSM
*  Specification:
*  Date:                $Date: 2025/12/18  $
*
*  Description:     This Unit processes the power supply module
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"
#include "pwsm_cnf.h"
#include "pwsm.h"
#include "Dio.h"
#include "Mcu.h"

/* The ONLY PICC header needed by the application layer */
#include "picc_api.h"


/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/

static volatile Pwsm_StateType Pwsm_State = PWSM_STATE_NO_INIT; /**< Holds the current PWSM state. */
static volatile Pwsm_MsgStateType Pwsm_MsgState = PWSM_MSG_STATE_IDLE;	/**< Holds the current PWSM MSG state. */
static uint8 Pwsm_RstReq = FALSE;
static uint16 Pwsm_ShutdownTimer = 0U;
static uint16 Pwsm_RxMsgTimeOutId2 = 0U;
static uint16 Pwsm_RxMsgTimeOutId8 = 0U;
static uint16 Pwsm_RxMsgTimeOutId11 = 0U;

/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/
uint8 Igk_Status = 1;
uint8 McuRst = 0;

uint8 buf[8];
uint16 len;
/***********************************************************************************************************************
 *  Function name    : Pwsm_Init()
 *
 *  Description      : Initialize PWSM module and register with PICC driver
 *
 ***********************************************************************************************************************/
void Pwsm_Init(void)
{
    static const PICC_AppConfig_t cfg = {
        .localId           = PWR_PROVIDER_ID,     /* 0x01 */
        .remoteId          = PWR_CONSUMER_ID,     /* 0x06 */
        .role              = PICC_ROLE_SERVER,
        .channelId         = PWR_CHANNEL_ID,      /* 2 */
        .methodHandler     = NULL,  /* Pure polling mode, no callback needed */
        .eventHandler      = NULL   /* Pure polling mode, no callback needed */
    };
    
    static const PICC_AppConfig_t dm_cfg = {
        .localId           = DM_PROVIDER_ID,     /* 0x02 */
        .remoteId          = DM_CONSUMER_ID,     /* 0x07 */
        .role              = PICC_ROLE_SERVER,
        .channelId         = PWR_CHANNEL_ID,      /* 2 */
        .methodHandler     = NULL,  /* Pure polling mode, no callback needed */
        .eventHandler      = NULL   /* Pure polling mode, no callback needed */
    };


    (void)PICC_Init(PICC_APP_PWR, &cfg);
    (void)PICC_Init(PICC_APP_DIAG, &dm_cfg);


}

/***********************************************************************************************************************
 *  Function name    : Pwsm_CommEvent()
 *
 *  Description      : Handles the power management communication state machine
 *
 ***********************************************************************************************************************/
void Pwsm_CommEvent(void)
{


    switch (Pwsm_MsgState)
    {
    case PWSM_MSG_STATE_IDLE:
    {
    	Igk_Status = Pwsm_GetIgkStatus();
        if(!Igk_Status)
        {
        	Pwsm_MsgState = PWSM_STATE_MSG_TX_ID1;
        }
        else if (PICC_GetMethodData(PICC_APP_DIAG, PWR_METHOD_STATE_RESET, buf, sizeof(buf), &len, NULL, NULL) == PICC_E_OK)
    	{
    		if (len == 2U && buf[0] == PWR_CORE_A &&  buf[1] == PWR_STATE_RESET)
    		{
    			Pwsm_MsgState = PWSM_STATE_MSG_TX_ID1;
    			Pwsm_RstReq = TRUE;
    		}
    	}
        break;
    }

    case PWSM_STATE_MSG_TX_ID1:
    {
        /* Send Event ID 0x01 (PWR_EVENT_STATE_NOTIFY) */
        uint8 payload[1] = { (uint8)PWR_STATE_STANDBY };
        (void)PICC_SendEvent(PICC_APP_PWR, PWR_EVENT_STATE_NOTIFY, payload, 1U, PICC_EVENT_WITH_ACK);
        Pwsm_RxMsgTimeOutId2 = 0U;
        Pwsm_RxMsgTimeOutId8 = 0U;
        Pwsm_MsgState = PWSM_STATE_MSG_RX_ID2;
        break;
    }

    case PWSM_STATE_MSG_RX_ID2:
        Pwsm_RxMsgTimeOutId2++;
        
        /* Poll for Method ID 2 (PWR_METHOD_STATE_ACK) */
        if (PICC_GetMethodData(PICC_APP_PWR, PWR_METHOD_STATE_ACK, buf, sizeof(buf), &len, NULL, NULL) == PICC_E_OK)
        {
            if (len >= 2U && buf[0] == PWR_CORE_A) {
                Pwsm_MsgState = PWSM_STATE_MSG_RX_ID8;
            }
        }
        else if(Pwsm_RxMsgTimeOutId2 >= PWSM_MSG_TIMEOUT_RX_ID2)
        {
            /* Timeout */
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        break;

    case PWSM_STATE_MSG_RX_ID8:
        Pwsm_RxMsgTimeOutId8++;
        
        /* Poll for Method ID 8 (PWR_METHOD_EVENT_DONE) */
        if (PICC_GetMethodData(PICC_APP_PWR, PWR_METHOD_EVENT_DONE, buf, sizeof(buf), &len, NULL, NULL) == PICC_E_OK)
        {
            if (len >= 1U && buf[0] == (uint8)PWR_DONE_FIRST_STEP) {
                Pwsm_MsgState = PWSM_STATE_MSG_TX_ID4;  /* Enter state to send Event ID=4 */
            }
        }
        else if(Pwsm_RxMsgTimeOutId8 >= PWSM_MSG_TIMEOUT_RX_ID8)
        {
            /* Timeout */
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        break;

    case PWSM_STATE_MSG_TX_ID4:
    {
        /* Send Event ID 4 (PWR_EVENT_CTRL_CMD) */
        uint8 payload[2] = { PWR_CORE_A, (uint8)PWR_CMD_HARDWARE_SHUTDOWN };
        (void)PICC_SendEvent(PICC_APP_PWR, PWR_EVENT_CTRL_CMD,
                             payload, 2U, PICC_EVENT_WITH_ACK);
        Pwsm_RxMsgTimeOutId11 = 0U;
        Pwsm_MsgState = PWSM_STATE_MSG_RX_ID11;
        break;
    }

    case PWSM_STATE_MSG_RX_ID11:
        Pwsm_RxMsgTimeOutId11++;
        
        /* Poll for Method ID 11 (PWR_METHOD_CTRL_ACK) */
        if (PICC_GetMethodData(PICC_APP_PWR, PWR_METHOD_CTRL_ACK, buf, sizeof(buf), &len, NULL, NULL) == PICC_E_OK)
        {
            if (len >= 2U && buf[0] == PWR_CORE_A) {
                Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
            }
        }
        else if(Pwsm_RxMsgTimeOutId11 >= PWSM_MSG_TIMEOUT_RX_ID11)
        {
            /* Timeout */
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        break;

    default:
        break;
    }
}

/***********************************************************************************************************************
 *  Function name    : Pwsm_Main()
 *
 *  Description      : Implements all activities of the PWSM State Manager.
 *
 ***********************************************************************************************************************/
void Pwsm_Main(void)
{
    switch (Pwsm_State)
    {
        case PWSM_STATE_NO_INIT:
            /* Move to next step */
            Pwsm_State = PWSM_STATE_STARTUP_INIT;
        break;

        case PWSM_STATE_STARTUP_INIT:
            /* Keep wake up */
            Pwsm_WriteWakeup(STD_HIGH);
            /* Set Rst of Ethernet switch */
            Pwsm_EthSwitchRst(STD_HIGH);
            /* Move to next step */
            Pwsm_State = PWSM_STATE_RUN;
        break;

        case PWSM_STATE_RUN:

            /*Send Event/Method 0x01 to A core to prepare shutdown*/
            Pwsm_CommEvent();
            if((Pwsm_MsgState == PWSM_STATE_MSG_SHUTDOWN_DONE) || (Pwsm_MsgState == PWSM_MSG_STATE_NO_RESPONSE))
            {
                Pwsm_State = PWSM_STATE_POST_RUN;
            }
#if 0
            if(!Igk_Status)
            {
                /*Send Event/Method 0x01 to A core to prepare shutdown*/
                Pwsm_CommEvent();
                if((Pwsm_MsgState == PWSM_STATE_MSG_SHUTDOWN_DONE) || (Pwsm_MsgState == PWSM_MSG_STATE_NO_RESPONSE))
                {
                    Pwsm_State = PWSM_STATE_POST_RUN;
                }
            }
#endif
        break;

        case PWSM_STATE_POST_RUN:
            /*Get feedback message from A core or time out*/
            Pwsm_ShutdownTimer = 0U;
            Pwsm_State = PWSM_STATE_SHUTDOWN;
        break;

        case PWSM_STATE_SHUTDOWN:
            /*Check if shutdown delay is over*/
            if (Pwsm_ShutdownTimer < PWSM_SHUTDOWN_DELAY_TICKS)
            {
                Pwsm_ShutdownTimer++;
            }
            else if(Pwsm_RstReq)
            {
            	Mcu_PerformReset();
            }
            else
            {           
                /*Release wake up*/
                Pwsm_WriteWakeup(STD_LOW);
            }
        break;

        default:
            break;
    }
}

/***********************************************************************************************************************
 *  Function name    : Pwsm_GetState()
 *
 *  Description      : This API returns the current state of the PWSM.
 *
 ***********************************************************************************************************************/
Std_ReturnType Pwsm_GetState(Pwsm_StateType *state)
{
    Std_ReturnType ReturnValue = E_OK;
    if (state != NULL_PTR)
    {
        *state = Pwsm_State;
    }
    else
    {
        ReturnValue = E_NOT_OK;
    }
    return ReturnValue;
}

/***********************************************************************************************************************
 *  Function name    : Pwsm_ResetMsgState()
 *
 *  Description      : Reset message state machine to initial state. Call this when restarting shutdown sequence.
 *
 ***********************************************************************************************************************/
void Pwsm_ResetMsgState(void)
{
    Pwsm_MsgState = PWSM_STATE_MSG_TX_ID1;
    Pwsm_RxMsgTimeOutId2 = 0U;
    Pwsm_RxMsgTimeOutId8 = 0U;
    Pwsm_RxMsgTimeOutId11 = 0U;
}
