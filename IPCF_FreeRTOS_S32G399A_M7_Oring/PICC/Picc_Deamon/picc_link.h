/**
 * @file picc_link.h
 * @brief M-Core Inter-Core Communication Link Management Layer - Interface Definition
 *
 * Implements application-level connection request/response and disconnect notification.
 * This layer uses CONSUMER_ID/PROVIDER_ID for connection handshake.
 *
 * Note: Heartbeat (Ping/Pong) functionality is now in picc_heartbeat.h/c
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_LINK_H
#define PICC_LINK_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_protocol.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Connection request period (ms) */
#define PICC_LINK_REQUEST_PERIOD_MS     (10U)

/** Maximum supported channels */
#define PICC_MAX_CHANNELS               (2U)

/*==================================================================================================
 *                                         Enum Types
 *==================================================================================================*/

/**
 * @brief Connection state
 */
typedef enum {
    PICC_LINK_STATE_DISCONNECTED = 0U,  /**< Disconnected */
    PICC_LINK_STATE_CONNECTING,         /**< Connecting (waiting for response) */
    PICC_LINK_STATE_CONNECTED           /**< Connected */
} PICC_LinkState_e;

/*==================================================================================================
 *                                         Structure Definitions
 *==================================================================================================*/

/**
 * @brief Link configuration (application-level IDs)
 */
typedef struct {
    uint8        localId;       /**< Local ID (ConsumerID as Client, ProviderID as Server) */
    uint8        remoteId;      /**< Remote ID (ProviderID as Client, ConsumerID as Server) */
    PICC_Role_e  role;          /**< Role */
    uint8        instanceId;    /**< IPCF instance ID */
    uint8        channelId;     /**< IPCF channel ID */
    boolean      isUsed;        /**< Is slot in use */
} PICC_LinkConfig_t;

/**
 * @brief Link context
 */
typedef struct {
    PICC_LinkConfig_t config;           /**< Link configuration */
    volatile PICC_LinkState_e state;    /**< Current state (volatile) */
    boolean           isInitialized;    /**< Whether initialized */
} PICC_LinkContext_t;

/**
 * @brief Connection state change callback function type
 */
typedef void (*PICC_LinkStateCallback_t)(uint8 remoteId, PICC_LinkState_e state);

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Initialize link management module
 * 
 * @param[in] config Link configuration
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkInit(const PICC_LinkConfig_t *config);

/**
 * @brief Add additional communication channel
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkAddChannel(uint8 instanceId, uint8 channelId);

/**
 * @brief Deinitialize link management module
 */
void PICC_LinkDeinit(void);

/**
 * @brief Send connection request (Client role)
 * 
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkSendRequest(void);

/**
 * @brief Handle connection response (Client role)
 * 
 * @param[in] header     Message header
 * @param[in] payload    Payload data
 * @param[in] len        Payload length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkHandleResponse(const PICC_MsgHeader_t *header,
                              const uint8 *payload, uint16 len,
                              uint8 instanceId, uint8 channelId);

/**
 * @brief Handle connection request (Server role)
 * 
 * @param[in] header     Message header
 * @param[in] payload    Payload data
 * @param[in] len        Payload length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkHandleRequest(const PICC_MsgHeader_t *header,
                             const uint8 *payload, uint16 len,
                             uint8 instanceId, uint8 channelId);

/**
 * @brief Send disconnect notification
 * 
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkSendDisconnect(void);

/**
 * @brief Handle disconnect notification
 * 
 * @param[in] header     Message header
 * @param[in] payload    Payload data
 * @param[in] len        Payload length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkHandleDisconnect(const PICC_MsgHeader_t *header,
                                const uint8 *payload, uint16 len,
                                uint8 instanceId, uint8 channelId);

/**
 * @brief Get current connection state for specified channel
 * 
 * @param[in] channelId IPCF channel ID
 * @return Connection state
 */
PICC_LinkState_e PICC_LinkGetState(uint8 channelId);

/**
 * @brief Register connection state change callback
 * 
 * @param[in] callback Callback function
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkRegisterStateCallback(PICC_LinkStateCallback_t callback);

/**
 * @brief Set link state to CONNECTING (called by heartbeat on timeout)
 * 
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 */
void PICC_LinkTriggerReconnect(uint8 instanceId, uint8 channelId);

/**
 * @brief Link process - called from PICC periodic task (10ms)
 * 
 * Handles connection requests (Client role).
 */
void PICC_LinkProcess(void);

/**
 * @brief Process received link management message (dispatch by subType)
 * 
 * @param[in] header     Protocol header
 * @param[in] payload    Payload
 * @param[in] len        Payload length
 * @param[in] instanceId Instance ID
 * @param[in] channelId  Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkProcessMessage(const PICC_MsgHeader_t *header,
                              const uint8 *payload, uint16 len,
                              uint8 instanceId, uint8 channelId);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_LINK_H */
