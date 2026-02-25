
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
PWSM_MSG_STATE_NO_INIT = ((uint8)0),
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
#define PWSM_SHUTDOWN_DELAY_TICKS   ((uint16)100U)
/* 2s = 200 * 10ms (increased from 200ms to allow A-core sufficient response time) */
#define PWSM_MSG_TIMEOUT_RX_ID2      ((uint16)200U)
/* 10s = 1000 * 10ms  */
#define PWSM_MSG_TIMEOUT_RX_ID8      ((uint16)100U)
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


