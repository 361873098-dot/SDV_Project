/**
 * @file picc_pwr_cnf.h
 * @brief Power Management Module - Configuration and Constants Definition
 *
 * Contains all ID configuration and enum type definitions for power management protocol.
 * - Provider/Consumer ID
 * - Event/Method ID
 * - Payload enum values
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_PWR_CNF_H
#define PICC_PWR_CNF_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "ipc-types.h"
#include "picc_protocol.h"  /* For PICC_ROLE_SERVER/CLIENT */

/*==================================================================================================
 *                                         IPCF Channel Configuration
 *==================================================================================================*/

/** IPCF data channel ID - Must match A-Core's link channel */
#define PWR_CHANNEL_ID              (2U)


/*==================================================================================================
 *                                         Service Layer ID Configuration (power management)
 *==================================================================================================*/

/** M-Core power master Provider ID */
#define PWR_PROVIDER_ID             (1U)

/** A-Core power middleware Consumer ID */
#define PWR_CONSUMER_ID             (6U)

/** A-Core identifier (for Payload) */
#define PWR_CORE_A                  (3U)

/**
 * @brief Power management service role
 * 
 * - PICC_ROLE_SERVER: M-Core as Server, sends Event, receives Method requests
 * - PICC_ROLE_CLIENT: M-Core as Client, receives Event, sends Method requests
 */
#define PWR_SERVICE_ROLE            PICC_ROLE_SERVER

/*==================================================================================================
 *                                         Event ID Configuration
 *==================================================================================================*/

/** Power state notification Event ID */
#define PWR_EVENT_STATE_NOTIFY      (1U)

/** Power control command Event ID */
#define PWR_EVENT_CTRL_CMD          (4U)

/*==================================================================================================
 *                                         Method ID Configuration
 *==================================================================================================*/

/** Power mode state notification acknowledgement Method ID */
#define PWR_METHOD_STATE_ACK        (2U)

/** Power event completion notification Method ID */
#define PWR_METHOD_EVENT_DONE       (8U)

/** Power control command notification acknowledgement Method ID */
#define PWR_METHOD_CTRL_ACK         (11U)

/*==================================================================================================
 *                                         Enum Types - Payload Values
 *==================================================================================================*/

/**
 * @brief Power state (Event ID=1 Payload value)
 */
typedef enum {
    PWR_STATE_RUN        = 2U,   /**< Enter run state */
    PWR_STATE_STANDBY    = 4U,   /**< Enter standby state */
    PWR_STATE_RESET      = 5U    /**< Enter reset state */
} Power_State_e;

/**
 * @brief Power control command (Event ID=4 Payload value)
 */
typedef enum {
    PWR_CMD_SHUTDOWN          = 2U,   /**< Enter SHUTDOWN */
    PWR_CMD_HARDWARE_SHUTDOWN = 3U    /**< Enter HARDWARE_SHUTDOWN */
} Power_Cmd_e;

/**
 * @brief Power event completion type (Method ID=8 Payload value)
 */
typedef enum {
    PWR_DONE_FIRST_STEP  = 3U    /**< First step shutdown complete */
} Power_DoneType_e;

/*==================================================================================================
 *                                         State Machine Enum
 *==================================================================================================*/

/**
 * @brief Power management state machine
 */
typedef enum {
    PWR_SM_IDLE = 0U,               /**< Idle */
    PWR_SM_WAIT_STATE_ACK,          /**< Waiting for power state ack (Method ID=2) */
    PWR_SM_WAIT_PHASE1_DONE,        /**< Waiting for phase 1 completion (Method ID=8) */
    PWR_SM_WAIT_CTRL_ACK,           /**< Waiting for power control command ack (Method ID=11) */
    PWR_SM_SHUTDOWN_COMPLETE        /**< Shutdown complete */
} Power_StateMachine_e;

#if defined(__cplusplus)
}
#endif

#endif /* PICC_PWR_CNF_H */
