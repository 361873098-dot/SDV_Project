/**
 * @file picc_pwr_main.h
 * @brief Power Management Module - Main Logic Layer Interface
 *
 * Contains power management API functions and state machine interface.
 * - M-Core power master (ProviderID=1) acts as Server
 * - A-Core power middleware (ConsumerID=6) acts as Client
 *
 * Event send mode: NOTIFICATION_WITH_ACK
 * Note: After M-Core sends WITH_ACK Event, it doesn't wait for/process A-Core's ACK reply
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_PWR_MAIN_H
#define PICC_PWR_MAIN_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_pwr_cnf.h"
#include "picc_api.h"

/*==================================================================================================
 *                                         Initialization/Deinitialization
 *==================================================================================================*/

/**
 * @brief Initialize power management module
 * 
 * @return 0 on success, non-zero on failure
 */
sint8 Pwr_Init(void);

/**
 * @brief Deinitialize power management module
 */
void Pwr_Deinit(void);

/*==================================================================================================
 *                                         Message Processing
 *==================================================================================================*/

/**
 * @brief Method request handler (M-Core as Server handles A-Core requests)
 * 
 * Called automatically by PICC, no manual registration needed.
 */
uint8 Pwr_MethodHandler(uint8 consumerId, uint8 methodId,
                        const uint8 *reqData, uint16 reqLen,
                        uint8 *rspData, uint16 *rspLen);

/*==================================================================================================
 *                                         M-Core Send Interface
 *==================================================================================================*/

/**
 * @brief Send power state notification (Event ID=1)
 * 
 * M-Core power master sends to A-Core power middleware.
 * 
 * @param[in] state Power state
 * @return 0 on success, non-zero on failure
 */
sint8 Pwr_SendStateNotify(Power_State_e state);

/**
 * @brief Send power control command (Event ID=4)
 * 
 * M-Core power master sends to A-Core power middleware.
 * 
 * @param[in] cmd Control command
 * @return 0 on success, non-zero on failure
 */
sint8 Pwr_SendCtrlCmd(Power_Cmd_e cmd);

/*==================================================================================================
 *                                         State Machine Interface
 *==================================================================================================*/

/**
 * @brief Initiate power shutdown process (async, non-blocking)
 * 
 * M-Core as power master (Server) sends Event notification to A-Core power middleware (Client).
 * 
 * Two-phase shutdown process (fully async):
 * 1. Send power state notification (Event ID=1, Standby) -> return immediately
 * 2. A-Core replies Method (ID=2) -> Pwr_InternalStateAckHandler called
 * 3. A-Core completes phase 1, sends Method (ID=8) -> Pwr_InternalDoneHandler called
 * 4. A-Core replies Method (ID=11) -> Pwr_InternalCtrlAckHandler called, shutdown complete
 * 
 * @return 0 on success, non-zero on failure
 */
sint8 Pwr_StartShutdown(void);

void Pwr_InternalStateAckHandler(const uint8 *payload, uint16 payloadLen);

/**
 * @brief Get power state machine state
 */
Power_StateMachine_e Pwr_GetState(void);

/*==================================================================================================
 *                                         Reception Flag Query APIs (for PWSM)
 *==================================================================================================*/

/**
 * @brief Check if Method ID=2 (state acknowledgement) was received
 * @return TRUE if received, FALSE otherwise
 */
boolean Pwr_IsStateAckReceived(void);

/**
 * @brief Clear Method ID=2 received flag
 */
void Pwr_ClearStateAckFlag(void);

/**
 * @brief Check if Method ID=8 (phase 1 done) was received
 * @return TRUE if received, FALSE otherwise
 */
boolean Pwr_IsPhase1DoneReceived(void);

/**
 * @brief Clear Method ID=8 received flag
 */
void Pwr_ClearPhase1DoneFlag(void);

/**
 * @brief Check if Method ID=11 (control ack) was received
 * @return TRUE if received, FALSE otherwise
 */
boolean Pwr_IsCtrlAckReceived(void);

/**
 * @brief Clear Method ID=11 received flag
 */
void Pwr_ClearCtrlAckFlag(void);

/*==================================================================================================
 *                                         Payload Getter APIs (for Application Layer)
 *==================================================================================================*/

/**
 * @brief Get Method ID=2 (state ack) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetStateAckPayload(uint8 *data, uint16 maxLen);

/**
 * @brief Get Method ID=8 (phase1 done) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetPhase1DonePayload(uint8 *data, uint16 maxLen);

/**
 * @brief Get Method ID=11 (ctrl ack) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetCtrlAckPayload(uint8 *data, uint16 maxLen);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_PWR_MAIN_H */
