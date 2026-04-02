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
*  File name:           $Source: diag_mgmt.h $
*  Revision:            $Revision: 1.1 $
*  Author:              $Author: Auto Generated $
*  Module acronym:      DIAG_MGMT
*  Specification:       Schaeffler_A-Sample Diagnostic Management (DoIP Activation Line)
*  Date:                $Date: 2026/04/02 $
*
*  Description:     Diagnostic Management module header
*                   Implements DIAG_4: M-Core (Server) sends DoIP activation
*                   line status to A-Core (Client) via IPCF Event notification.
*
*                   Protocol details (from cross-core design document):
*                     - ProviderID (M-Core Server): 52 (0x34)
*                     - ConsumerID (A-Core Client): 60 (0x3C)
*                     - EventID: 5 (DoIP activation line status)
*                     - MessageType: NOTIFICATION_WITHOUT_ACK (0x09)
*                     - Payload: 1 byte (DiagnosisType enum value)
*                     - Send Period: 30ms (triggered, only when Test_input != 0)
*                     - Channel: HP (High Priority, channel 1)
*                     - Transport: IPCF
*
*                   Roles:
*                     M-Core = Server (ProviderID=52): passive for link,
*                       A-Core Client sends connection request.
*                       M-Core proactively pushes Event to A-Core.
*                     A-Core = Client (ConsumerID=60): sends link request,
*                       receives Event notification.
*
*********************************************************************************
*
*  Changes:
*    v1.1: Fixed role from CLIENT to SERVER. M-Core is Server (ProviderID=52),
*          does NOT send link-connect requests. Changed send mechanism from
*          PICC_MethodRequest to PICC_SendEvent (Server->Client notification).
*
*********************************************************************************/

#ifndef DIAG_MGMT_H
#define DIAG_MGMT_H

#if defined(__cplusplus)
extern "C"{
#endif

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"

/***********************************************************************************************************************
*  Macro Definitions
***********************************************************************************************************************/

/** IPCF data channel ID for diagnostic management (HP = High Priority = channel 1) */
#define DIAG_MGMT_CHANNEL_ID            (1U)

/** M-Core Server ProviderID for DIAG_4 */
#define DIAG_MGMT_PROVIDER_ID           (52U)   /* 0x34 */

/** A-Core Client ConsumerID for DIAG_4 */
#define DIAG_MGMT_CONSUMER_ID           (60U)   /* 0x3C */

/** Event ID for DoIP activation line status notification */
#define DIAG_MGMT_EVENT_DOIP_ACT_LINE   (5U)

/** Send period in units of 10ms task ticks (30ms = 3 * 10ms) */
#define DIAG_MGMT_SEND_PERIOD_TICKS     (3U)

/***********************************************************************************************************************
*  Type Definitions
***********************************************************************************************************************/

/**
 * @brief DoIP activation line diagnosis type
 *
 * Matches the A-Core enum DiagnosisType:
 *   kNoObd  = 0x00  — No OBD active, do not send
 *   kObdCan = 0x01  — OBD-CAN active (high priority)
 *   kObdEth = 0x02  — OBD-ETH / DoIP activation line active
 *
 * When both kObdCan and kObdEth are triggered simultaneously,
 * the higher-priority value (lower numeric) takes precedence.
 */
typedef enum {
    DIAG_MGMT_NO_OBD    = 0x00U,   /**< No OBD — do not send */
    DIAG_MGMT_OBD_CAN   = 0x01U,   /**< OBD-CAN active (high priority) */
    DIAG_MGMT_OBD_ETH   = 0x02U    /**< OBD-ETH / DoIP activation (lower priority) */
} DiagMgmt_DiagType_e;

/***********************************************************************************************************************
*  Global Variable Declarations
***********************************************************************************************************************/

/**
 * @brief Test input variable — controls DoIP activation line report
 *
 * Set by application or test harness:
 *   0 = kNoObd  : do not send
 *   1 = kObdCan : send OBD-CAN status (high priority)
 *   2 = kObdEth : send OBD-ETH / DoIP activation status
 *
 * This value is directly used as the 1-byte Event notification payload.
 */
extern volatile uint8 Test_input;

/***********************************************************************************************************************
*  Function Declarations
***********************************************************************************************************************/

/**
 * @brief Initialize the Diagnostic Management module
 *
 * Registers with the PICC driver using PICC_APP_RSV0 slot:
 *   - Role: SERVER (M-Core is the service provider)
 *   - ProviderID: 52 (M-Core Server, localId)
 *   - ConsumerID: 60 (A-Core Client, remoteId)
 *   - Channel: 1 (HP)
 *
 * As SERVER, M-Core does NOT send link-connect requests.
 * A-Core (Client) initiates the connection.
 *
 * Must be called after PICC_PreOS_Init() and before the scheduler starts.
 */
void DiagMgmt_Init(void);

/**
 * @brief Diagnostic Management 10ms periodic main function
 *
 * Called from TASK_M0_10MS() every 10ms.
 * Internally uses a counter to achieve 30ms send period.
 *
 * Behavior:
 *   - If Test_input == 0 (kNoObd): no Event notification is sent.
 *   - If Test_input == 1 (kObdCan) or 2 (kObdEth): sends an Event notification
 *     (NOTIFICATION_WITHOUT_ACK, 0x09) with Test_input as the 1-byte payload
 *     every 30ms.
 */
void DiagMgmt_Main(void);

#if defined(__cplusplus)
}
#endif

#endif /* DIAG_MGMT_H */
