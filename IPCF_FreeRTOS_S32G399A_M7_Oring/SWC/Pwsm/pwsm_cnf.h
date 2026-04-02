
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
*  File name:           $Source: pwsm_cnf.h $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      PWSM
*  Specification:
*  Date:                $Date: 2025/12/18  $
*
*  Description:     Head file of the power supply module
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


#ifndef PWSM_CNF_H
#define PWSM_CNF_H

#if defined(__cplusplus)
extern "C"{
#endif

#include "Platform.h"

/***********************************************************************************************************************
*  Power Management ID Configuration (migrated from picc_pwr_cnf.h)
***********************************************************************************************************************/

/** IPCF data channel ID for power management */
#define PWR_CHANNEL_ID              (2U)

/** M-Core power master Provider ID */
#define PWR_PROVIDER_ID             (1U)
#define DM_PROVIDER_ID             (2U)

/** A-Core power middleware Consumer ID */
#define PWR_CONSUMER_ID             (6U)
#define DM_CONSUMER_ID             (7U)

/** A-Core identifier (for Payload) */
#define PWR_CORE_A                  (3U)

/** Event IDs */
#define PWR_EVENT_STATE_NOTIFY      (1U)    /**< Power state notification */
#define PWR_EVENT_CTRL_CMD          (4U)    /**< Power control command */

/** Method IDs */
#define PWR_METHOD_STATE_ACK        (2U)    /**< State acknowledgement */
#define PWR_METHOD_STATE_RESET        (10U)    /**< State acknowledgement */


#define PWR_METHOD_EVENT_DONE       (8U)    /**< Phase 1 completion */
#define PWR_METHOD_CTRL_ACK         (11U)   /**< Control command ack */

/**
 * @brief Power state (Event ID=1 Payload value)
 */
typedef enum {
    PWR_STATE_RUN        = 2U,
    PWR_STATE_STANDBY    = 4U,
    PWR_STATE_RESET      = 5U
} Power_State_e;

/**
 * @brief Power control command (Event ID=4 Payload value)
 */
typedef enum {
    PWR_CMD_SHUTDOWN          = 2U,
    PWR_CMD_HARDWARE_SHUTDOWN = 3U
} Power_Cmd_e;

/**
 * @brief Power event completion type (Method ID=8 Payload value)
 */
typedef enum {
    PWR_DONE_FIRST_STEP  = 3U
} Power_DoneType_e;

/***********************************************************************************************************************
*  local constants (CONST) and enumerations (ENUM)
***********************************************************************************************************************/


/***********************************************************************************************************************
*  local function declarations (prototypes of module local functions)
***********************************************************************************************************************/
typedef enum
{
PWSM_STATE_NO_INIT = ((uint8)0),
PWSM_STATE_STARTUP_INIT = ((uint8)0x11),
PWSM_STATE_WAKEUP_VALIDATION = ((uint8)0x12),
PWSM_STATE_RUN = ((uint8)0x13),
PWSM_STATE_POST_RUN = ((uint8)0x14),
PWSM_STATE_SHUTDOWN = ((uint8)0x15),

} Pwsm_StateType;

typedef enum
{
PWSM_MSG_STATE_IDLE = ((uint8)0),
PWSM_STATE_MSG_TX_ID1 = ((uint8)0x11),
PWSM_STATE_MSG_RX_ID2 = ((uint8)0x12),
PWSM_STATE_MSG_RX_ID8 = ((uint8)0x13),
PWSM_STATE_MSG_TX_ID4 = ((uint8)0x14),
PWSM_STATE_MSG_RX_ID11 = ((uint8)0x15),
PWSM_MSG_STATE_NO_RESPONSE = ((uint8)0x16),
PWSM_STATE_MSG_SHUTDOWN_DONE = ((uint8)0x17),
} Pwsm_MsgStateType;

/***********************************************************************************************************************
*  global function definitions
***********************************************************************************************************************/
/* 10s = 1000 * 10ms */
#define PWSM_SHUTDOWN_DELAY_TICKS   ((uint16)2500U)
/* 2s = 200 * 10ms (increased from 200ms to allow A-core sufficient response time) */
#define PWSM_MSG_TIMEOUT_RX_ID2      ((uint16)200U)
/* 10s = 1000 * 10ms (increased from 1s: A-core needs time to complete Phase 1 shutdown) */
#define PWSM_MSG_TIMEOUT_RX_ID8      ((uint16)1000U)
/* 200ms */
#define PWSM_MSG_TIMEOUT_RX_ID11      ((uint16)20U)


/***********************************************************************************************************************
 *  Function name    : Pwsm_WriteWakeup()
 *
 *  Description      : Write level to specified channel.
 *
 *  List of arguments: none
 *
 *  Return value     : Level: Specifies the channel desired level.
 *
 ***********************************************************************************************************************/
extern void Pwsm_WriteWakeup(uint8 Level);

/***********************************************************************************************************************
 *  Function name    : Pwsm_GetIgkStatus()
 *
 *  Description      : Get status of ignition key.
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
extern uint8 Pwsm_GetIgkStatus(void);


/***********************************************************************************************************************
 *  Function name    : Pwsm_EthSwitchRst()
 *
 *  Description      : Write level to specified channel.
 *
 *  List of arguments: none
 *
 *  Return value     : Level: Specifies the channel desired level.
 *
 ***********************************************************************************************************************/
extern void Pwsm_EthSwitchRst(uint8 Level);


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
extern void Pwsm_ResetMsgState(void);


#if defined(__cplusplus)
}
#endif

#endif


