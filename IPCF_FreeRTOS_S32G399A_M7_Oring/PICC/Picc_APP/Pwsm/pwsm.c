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
#include "Dio.h"
#include "picc_pwr_main.h"


/***********************************************************************************************************************
*  function-like macros
***********************************************************************************************************************/


/***********************************************************************************************************************
*  local type definitions (STRUCT, TYPEDEF, ...)
***********************************************************************************************************************/


/***********************************************************************************************************************
*  local variable definitions (module local variables)
***********************************************************************************************************************/

static volatile Pwsm_StateType Pwsm_State = PWSM_STATE_NO_INIT; /**< Holds the current PWSM state. */
static volatile Pwsm_MsgStateType Pwsm_MsgState = PWSM_STATE_MSG_TX_ID1;	/**< Holds the current PWSM MSG state. */
/***********************************************************************************************************************
*  local constants (CONST) and enumerations (ENUM)
***********************************************************************************************************************/
static uint16 Pwsm_ShutdownTimer = 0U;
static uint16 Pwsm_RxMsgTimeOutId2 = 0U;
static uint16 Pwsm_RxMsgTimeOutId8 = 0U;
static uint16 Pwsm_RxMsgTimeOutId11 = 0U;
static uint8 Pwsm_RxBuffer[64] = {0U}; /**< Holds the received data from A core. */
static uint32 Pwsm_TestShutdownTimer = 0U;
/***********************************************************************************************************************
*  local function declarations (prototypes of module local functions)
***********************************************************************************************************************/


/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/
uint8 Igk_Status = 1;

/***********************************************************************************************************************
 *  Function name    : Pwsm_CommEvent()
 *
 *  Description      : 
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void Pwsm_CommEvent(void)
{
    switch (Pwsm_MsgState)
    {

    case  PWSM_STATE_MSG_TX_ID1:
        /* Send Event ID 0x01 */
        Pwr_SendStateNotify(PWR_STATE_STANDBY);
        Pwsm_RxMsgTimeOutId2 = 0U;
        Pwsm_RxMsgTimeOutId8 = 0U;
        Pwsm_MsgState = PWSM_STATE_MSG_RX_ID2;
        break;

    case  PWSM_STATE_MSG_RX_ID2:
		
		Pwsm_RxMsgTimeOutId2++;
		
		/* [BUG FIX] Corrected conditional logic
         * Issue: If Method ID=2 arrived after timeout, it skipped the success path and went to timeout path
         * Fix: Prioritize checking if message is received (even if timed out), check timeout only if message NOT received
         * 
         * Logic Priority:
         * 1. If Method ID=2 received -> Process and move to next state (regardless of timeout)
         * 2. If NOT received AND Timed out -> Go to SHUTDOWN_DONE
         * 3. If NOT received AND NOT Timed out -> Continue waiting
         */
        if (Pwr_IsStateAckReceived())
        {
            /* Method ID=2 received, process and move to next state */
            uint8 stateAckPayload[8];
            uint16 stateAckLen;         
            stateAckLen = Pwr_GetStateAckPayload(stateAckPayload, sizeof(stateAckPayload));
            (void)stateAckLen;  /* Prevent compiler warning */

            Pwr_ClearStateAckFlag();

            Pwsm_MsgState = PWSM_STATE_MSG_RX_ID8;
        }
        else if(Pwsm_RxMsgTimeOutId2 >= PWSM_MSG_TIMEOUT_RX_ID2)
        {
            /* Timeout and message not received, go to shutdown done state */
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        else
        {
            /* Continue waiting */
        }

#if 0
        /* ... removed commented out code ... */
#endif
		break;

	case  PWSM_STATE_MSG_RX_ID8:

		Pwsm_RxMsgTimeOutId8++;
		
		/* [BUG FIX] ... */
		if (Pwr_IsPhase1DoneReceived())
		{
			/* Method ID=8 received, process and enter send Event ID=4 state */
			uint8 phase1DonePayload[8];
			uint16 phase1DoneLen;
			
			phase1DoneLen = Pwr_GetPhase1DonePayload(phase1DonePayload, sizeof(phase1DonePayload));
			(void)phase1DoneLen;  /* Prevent compiler warning */

			Pwr_ClearPhase1DoneFlag();
			Pwsm_MsgState = PWSM_STATE_MSG_TX_ID4;  /* Enter state to send Event ID=4 */
		}
		else if(Pwsm_RxMsgTimeOutId8 >= PWSM_MSG_TIMEOUT_RX_ID8)
		{
			/* Timeout and message not received, go to shutdown done state */
			Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
		}
		else
		{
			/* Continue waiting */
		}

	case  PWSM_STATE_MSG_TX_ID4:
	
		Pwr_SendCtrlCmd(PWR_CMD_HARDWARE_SHUTDOWN);
		Pwsm_RxMsgTimeOutId11 = 0U;
		Pwsm_MsgState = PWSM_STATE_MSG_RX_ID11;
		break;


	case  PWSM_STATE_MSG_RX_ID11:
	
        Pwsm_RxMsgTimeOutId11++;
        
        /* [BUG FIX] Corrected conditional logic, consistent with other states
         * Issue: Missing timeout handling, if Method ID=11 not received, would stay in this state forever
         * 
         * Logic Priority:
         * 1. If Method ID=11 received -> Process and enter SHUTDOWN_DONE
         * 2. If NOT received AND Timed out -> Enter SHUTDOWN_DONE
         * 3. If NOT received AND NOT Timed out -> Continue waiting
         */
        if (Pwr_IsCtrlAckReceived())
        {
            /* Method ID=11 received, process and complete shutdown sequence */
            uint8 ctrlAckPayload[8];
            uint16 ctrlAckLen;
            
            ctrlAckLen = Pwr_GetCtrlAckPayload(ctrlAckPayload, sizeof(ctrlAckPayload));
            (void)ctrlAckLen;  /* Prevent compiler warning */

            Pwr_ClearCtrlAckFlag();
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        else if(Pwsm_RxMsgTimeOutId11 >= PWSM_MSG_TIMEOUT_RX_ID11)
        {
            /* Timeout and message not received, still enter shutdown done state (since Event ID=4 was sent) */
            Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
        }
        else
        {
            /* Continue waiting */
        }
		break;

		#if 0		
		if((Pwsm_RxBuffer[0] == 0x01) && (Pwsm_RxMsgTimeOutId11 < PWSM_MSG_TIMEOUT_RX_ID11))
		{
			Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
		}
		else
		{
			Pwsm_MsgState = PWSM_STATE_MSG_SHUTDOWN_DONE;
		}
	
		break;	
#endif

	default:
		break;
	}


}
/***********************************************************************************************************************
 *  Function name    : Pwsm_Main()
 *
 *  Description      : Implements all activities of the PWSM State Manager.
 *
 *  List of arguments: none
 *
 *  Return value     : none
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

			/* Mark this function due to HW resource conflict with A core */

			/*Keep wake up*/
			Pwsm_WriteWakeup(STD_HIGH);
			/* Move to next step */
			Pwsm_State = PWSM_STATE_RUN;
		break;


		case PWSM_STATE_RUN:

		/* Mark this function due to HW resource conflict with A core */
			Igk_Status = Pwsm_GetIgkStatus();

			if(!Igk_Status)
			{
				/*Send Event/Method 0x01 to A core to prepare shutdown*/
				
				Pwsm_CommEvent();
				if((Pwsm_MsgState == PWSM_STATE_MSG_SHUTDOWN_DONE) || (Pwsm_MsgState == PWSM_MSG_STATE_NO_RESPONSE))
				{
					Pwsm_State = PWSM_STATE_POST_RUN;
				}
				
			}

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
			else
			{			
			/* Mark this function due to HW resource conflict with A core */	

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
 *  List of arguments: The value of the internal state variable.
 *
 *  Return value     : E_NOT_OK - Null pointer passed as parameter
 *  				   E_OK - The PWSM state is available and returned
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
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void Pwsm_ResetMsgState(void)
{

	/* Also reset Pwr module flags */
	Pwr_ClearStateAckFlag();
	Pwr_ClearPhase1DoneFlag();
	Pwr_ClearCtrlAckFlag();
}

