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

/** Default connection request period (ms) for CLIENT apps */
#define PICC_LINK_REQUEST_PERIOD_MS     (10U)

/** Maximum supported physical channels */
#define PICC_MAX_CHANNELS               (2U)

/** Maximum supported link app contexts (per-app, matches PICC_APP_MAX) */
#define PICC_MAX_LINK_APPS              (10U)

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
    uint16       Client_linkReq_PeriodMs; /**< CLIENT connection request period (ms), 0=default 10ms */
    boolean      isUsed;        /**< Is slot in use */
} PICC_LinkConfig_t;

/**
 * @brief Link context
 */
typedef struct {
    PICC_LinkConfig_t config;           /**< Link configuration */
    volatile PICC_LinkState_e state;    /**< Current state (volatile) */
    boolean           isInitialized;    /**< Whether initialized */
    uint16            periodCounter;    /**< Per-app period counter for CLIENT request timing */
    uint8             backoffCounter;   /**< Per-app send backoff counter */
} PICC_LinkContext_t;

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief One-time initialization of the link management layer
 * 
 * Clears all link app contexts. Must be called once during
 * PICC_InfraInit() before any PICC_Init()/PICC_LinkRegisterApp() calls.
 */
void PICC_LinkLayerInit(void);

/**
 * @brief Register a single application link context
 * 
 * Finds a free slot and registers the app without affecting other contexts.
 * CLIENT role: auto enters CONNECTING state.
 * SERVER role: stays in DISCONNECTED state.
 * 
 * @param[in] config Link configuration for this app
 * @return 0 on success, -1 on failure (no free slot or bad param)
 */
sint8 PICC_LinkRegisterApp(const PICC_LinkConfig_t *config);

/**
 * @brief Deinitialize link management module
 */
void PICC_LinkDeinit(void);

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
 * @brief Get application-level link state by ID pair
 * 
 * @param[in] localId  Local ID
 * @param[in] remoteId Remote ID
 * @return Connection state for the specified app pair
 */
PICC_LinkState_e PICC_LinkGetStateByIds(uint8 localId, uint8 remoteId);

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
