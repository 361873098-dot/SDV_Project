/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2026
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: diag_mgmt.c $
*  Revision:            $Revision: 1.1 $
*  Author:              $Author: Auto Generated $
*  Module acronym:      DIAG_MGMT
*  Specification:       Schaeffler_A-Sample Diagnostic Management (DoIP Activation Line)
*  Date:                $Date: 2026/04/02 $
*
*  Description:     Diagnostic Management module implementation
*                   Implements DIAG_4: M-Core (Server, ProviderID=52) sends
*                   DoIP activation line status to A-Core (Client, ConsumerID=60)
*                   via IPCF Event notification.
*
*                   Roles:
*                     M-Core = Server: does NOT send link-connect requests.
*                     A-Core = Client: sends link-connect requests to M-Core.
*
*                   Send mechanism: PICC_SendEvent (Server->Client notification)
*                     EventID=5, payload=Test_input value, 30ms period
*                     NOTIFICATION_WITHOUT_ACK (per M-Core real-time constraints)
*
*********************************************************************************
*
*  Changes:
*    v1.1: Fixed M-Core role from CLIENT to SERVER (ProviderID=52).
*          Changed send from PICC_MethodRequest to PICC_SendEvent.
*          Server is passive for link, no connect requests sent.
*
*********************************************************************************/

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"
#include "diag_mgmt.h"

/* The ONLY PICC header needed by the application layer */
#include "picc_api.h"

/***********************************************************************************************************************
*  Global Variable Definitions
***********************************************************************************************************************/

/**
 * @brief Test input variable — controls DoIP activation line report
 *
 * 0 = no send, 1 = kObdCan (high priority), 2 = kObdEth
 */
volatile uint8 Test_input = 0U;

/***********************************************************************************************************************
*  Local Variable Definitions
***********************************************************************************************************************/

/** 10ms tick counter for 30ms period dispatch */
static uint16 DiagMgmt_PeriodCounter = 0U;

/***********************************************************************************************************************
*  Function Implementations
***********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function name    : DiagMgmt_Init()
 *
 *  Description      : Initialize DiagMgmt module and register with PICC driver
 *
 *  Configuration:
 *    - localId  = DIAG_MGMT_PROVIDER_ID (52) — M-Core is Server (provider)
 *    - remoteId = DIAG_MGMT_CONSUMER_ID (60) — A-Core is Client (consumer)
 *    - role     = PICC_ROLE_SERVER
 *    - channel  = 1 (HP)
 *    - No callbacks (polling mode)
 *
 *  As SERVER, M-Core does NOT send link-connect requests.
 *  A-Core (Client, ConsumerID=60) will initiate the connection.
 *
 ***********************************************************************************************************************/
void DiagMgmt_Init(void)
{
    static const PICC_AppConfig_t diagMgmt_cfg = {
        .localId                = DIAG_MGMT_PROVIDER_ID,   /* 52 (0x34) - M-Core Server */
        .remoteId               = DIAG_MGMT_CONSUMER_ID,   /* 60 (0x3C) - A-Core Client */
        .role                   = PICC_ROLE_SERVER,
        .channelId              = DIAG_MGMT_CHANNEL_ID,    /* 1 (HP) */
        .Client_linkReq_PeriodMs = 0U,                     /* Ignored for SERVER role */
        .methodHandler          = NULL,  /* No Method handler needed */
        .eventHandler           = NULL   /* No Event handler needed */
    };

    (void)PICC_Init(PICC_APP_RSV0, &diagMgmt_cfg);

    /* Initialize state */
    DiagMgmt_PeriodCounter = 0U;
}

/***********************************************************************************************************************
 *  Function name    : DiagMgmt_Main()
 *
 *  Description      : Periodic 10ms main function for Diagnostic Management
 *
 *  Logic:
 *    1. Every 10ms call, increment PeriodCounter.
 *    2. Every 30ms (PeriodCounter % 3 == 0), check Test_input:
 *       - If Test_input == 0: no Event is sent (kNoObd).
 *       - If Test_input == 1: send Event with payload = 1 (kObdCan, high priority).
 *       - If Test_input == 2: send Event with payload = 2 (kObdEth).
 *    3. Uses PICC_SendEvent with PICC_EVENT_WITHOUT_ACK.
 *       Per IPCF protocol: M-Core only sends Event without ACK due to
 *       real-time constraints (no synchronous wait).
 *
 ***********************************************************************************************************************/
void DiagMgmt_Main(void)
{
    DiagMgmt_PeriodCounter++;

    /* Check every 30ms (3 x 10ms ticks) */
    if ((DiagMgmt_PeriodCounter % DIAG_MGMT_SEND_PERIOD_TICKS) == 0U)
    {
        /* Read current Test_input — take a snapshot */
        uint8 currentInput = Test_input;

        if (currentInput != DIAG_MGMT_NO_OBD)
        {
            /*
             * Test_input is 1 (kObdCan) or 2 (kObdEth) — send Event notification.
             *
             * Protocol frame (constructed by PICC driver):
             *   ProviderID = 52 (0x34) — M-Core Server
             *   EventID    = 5         — DoIP activation line
             *   ConsumerID = 60 (0x3C) — A-Core Client
             *   SessionID  = 0x00      — No ACK, no session tracking
             *   MessageType= 0x09      — NOTIFICATION_WITHOUT_ACK
             *   ReturnCode = 0x00
             *   Length     = 0x0001    — 1 byte payload
             *   Payload    = currentInput (1=kObdCan, 2=kObdEth)
             */
            uint8 payload[1];
            payload[0] = currentInput;

            (void)PICC_SendEvent(PICC_APP_RSV0,
                                 DIAG_MGMT_EVENT_DOIP_ACT_LINE,
                                 payload,
                                 1U,
                                 PICC_EVENT_WITHOUT_ACK);
        }
        /* else: Test_input == 0 (kNoObd), no Event sent */
    }
}
