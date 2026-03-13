/**
 * @file picc_heartbeat.h
 * @brief M-Core Inter-Core Communication Heartbeat Layer - Interface Definition
 *
 * Low-level heartbeat (Ping/Pong) functionality for IPC channel health monitoring.
 * Independent of application-level connection state (no CONSUMER_ID/PROVIDER_ID).
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_HEARTBEAT_H
#define PICC_HEARTBEAT_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_protocol.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Heartbeat period (ms) [R6]: 2 second period */
#define PICC_HEARTBEAT_PERIOD_MS        (2000U)

/** Heartbeat timeout count threshold [R6]: 3 consecutive misses indicates fault */
#define PICC_HEARTBEAT_TIMEOUT_COUNT    (3U)

/** Heartbeat message length [R6]: Special format 9 bytes */
#define PICC_HEARTBEAT_MSG_SIZE         (9U)

/** Maximum supported channels */
#define PICC_HEARTBEAT_MAX_CHANNELS     (2U)

/*==================================================================================================
 *                                         Callback Types
 *==================================================================================================*/

/**
 * @brief Heartbeat timeout callback function type
 * 
 * Called when heartbeat timeout occurs on a channel.
 * 
 * @param[in] instanceId  Instance ID where timeout occurred
 * @param[in] channelId   Channel ID where timeout occurred
 */
typedef void (*PICC_HeartbeatTimeoutCallback_t)(uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Initialize heartbeat module
 * 
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_HeartbeatInit(void);

/**
 * @brief Deinitialize heartbeat module
 */
void PICC_HeartbeatDeinit(void);

/**
 * @brief Add channel to heartbeat monitoring
 * 
 * @param[in] instanceId IPCF instance ID
 * @param[in] channelId  IPCF channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_HeartbeatAddChannel(uint8 instanceId, uint8 channelId);

/**
 * @brief Send heartbeat Ping [R6]
 * 
 * Ping message format: ff 00 ff 00 ff 00 00 01 00 (9 bytes)
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_HeartbeatSendPing(uint8 instanceId, uint8 channelId);

/**
 * @brief Send heartbeat Pong [R6]
 * 
 * Pong message format: ff 00 ff 00 ff 00 00 01 01 (9 bytes)
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_HeartbeatSendPong(uint8 instanceId, uint8 channelId);

/**
 * @brief Handle received Ping, reply Pong
 * 
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_HeartbeatHandlePing(uint8 instanceId, uint8 channelId);

/**
 * @brief Reset heartbeat miss count for specified channel
 * 
 * Called when Pong is received.
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 */
void PICC_HeartbeatReset(uint8 instanceId, uint8 channelId);

/**
 * @brief Check if data is a Ping message
 * 
 * @param[in] data Data buffer
 * @param[in] len  Data length
 * @return TRUE if Ping message, FALSE otherwise
 */
boolean PICC_HeartbeatIsPing(const uint8 *data, uint32 len);

/**
 * @brief Check if data is a Pong message
 * 
 * @param[in] data Data buffer
 * @param[in] len  Data length
 * @return TRUE if Pong message, FALSE otherwise
 */
boolean PICC_HeartbeatIsPong(const uint8 *data, uint32 len);

/**
 * @brief Register heartbeat timeout callback
 * 
 * @param[in] callback Callback function
 * @return 0 on success
 */
sint8 PICC_HeartbeatRegisterTimeoutCallback(PICC_HeartbeatTimeoutCallback_t callback);

/**
 * @brief Get heartbeat miss count for specified channel
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 * @return Miss count
 */
uint8 PICC_HeartbeatGetMissCount(uint8 instanceId, uint8 channelId);

/**
 * @brief Heartbeat process - called from PICC periodic task (10ms)
 * 
 * [R6] Sends Ping every 2000ms and checks timeout.
 */
void PICC_HeartbeatProcess(void);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_HEARTBEAT_H */
