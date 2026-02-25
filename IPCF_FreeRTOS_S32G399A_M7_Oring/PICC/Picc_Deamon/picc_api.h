/**
 * @file picc_api.h
 * @brief M-Core Inter-Core Communication Application Interface Layer - API Definition
 *
 * Provides unified interface for upper layer APP calls, decoupling data from IPCF middleware.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_API_H
#define PICC_API_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_service.h"
#include "picc_link.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** PICC error codes */
#define PICC_E_OK               (0)
#define PICC_E_NOT_INIT         (-1)
#define PICC_E_PARAM            (-2)
#define PICC_E_NOMEM            (-3)
#define PICC_E_SEND             (-4)
#define PICC_E_NOT_CONNECTED    (-5)

/*==================================================================================================
 *                                         Structure Definitions
 *==================================================================================================*/

/**
 * @brief PICC infrastructure initialization configuration
 * 
 * PICC only initializes Link layer (connection handshake/heartbeat) and Stack layer (message stacking/CRC).
 * Each service module (power management/health management etc.) registers independently via PICC_Register*Handler().
 */
typedef struct {
    /* Link layer configuration - connection handshake/heartbeat */
    uint8        linkLocalId;     /**< Link layer local ID (CLIENT is ConsumerID, SERVER is ProviderID) */
    uint8        linkRemoteId;    /**< Link layer remote ID (CLIENT is ProviderID, SERVER is ConsumerID) */
    PICC_Role_e  linkRole;        /**< Link layer role */
    
    /* IPCF channel configuration */
    uint8        channelId;       /**< Primary IPCF channel ID */
} PICC_InitConfig_t;

/** PICC global configuration (accessible by other modules) */
extern PICC_InitConfig_t g_piccConfig;

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Initialize PICC module
 * 
 * @param[in] config Initialization configuration
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_Init(const PICC_InitConfig_t *config);

/**
 * @brief Deinitialize PICC module
 */
void PICC_Deinit(void);

/**
 * @brief Check if PICC module is initialized
 * 
 * @return TRUE if initialized, FALSE otherwise
 */
boolean PICC_IsInitialized(void);

/**
 * @brief Start connection (Client mode)
 * 
 * Manually trigger connection request sending. Usually not needed as PICC_Init() auto starts based on role:
 * - CLIENT role: Auto enters CONNECTING state and periodically sends connection requests
 * - SERVER role: Stays in passive listening state
 * 
 * @note Can be used for manual reconnection or to override auto-start behavior
 * @return 0 on success (request sent), non-zero on failure
 */
sint8 PICC_StartConnect(void);

/**
 * @brief Add additional communication channel (DEPRECATED - use PICC_InitChannel instead)
 * 
 * After PICC_Init initializes primary channel, call this to add extra channels.
 * 
 * @deprecated Use PICC_InitChannel() for clearer API
 * @param[in] instanceId IPCF instance ID (usually IPCF_INSTANCE0)
 * @param[in] channelId  IPCF channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_AddChannel(uint8 instanceId, uint8 channelId);

/**
 * @brief Initialize specified IPCF channel (Stack + Heartbeat)
 * 
 * Channel-level initialization. Heartbeat starts immediately and is
 * independent of application-level connection state.
 * 
 * Example:
 *   PICC_Init();                          // Base infrastructure
 *   PICC_InitChannel(IPCF_INSTANCE0, 1U); // Channel 1 (heartbeat starts)
 *   PICC_InitChannel(IPCF_INSTANCE0, 2U); // Channel 2 (heartbeat starts)
 *   PICC_LinkRegister(...);               // Application link registration
 * 
 * @param[in] instanceId IPCF instance ID (usually IPCF_INSTANCE0)
 * @param[in] channelId  IPCF channel ID (1 or 2)
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_InitChannel(uint8 instanceId, uint8 channelId);

/**
 * @brief Register application-level Link configuration
 * 
 * Uses the same config structure as PICC_Init for convenience.
 * Each application can register its own Link configuration.
 * 
 * @param[in] config Same configuration structure as PICC_Init
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_LinkRegister(const PICC_InitConfig_t *config);

/* Event sending: use PICC_SendEvent(providerId, eventId, ...) from picc_service.h */

/**
 * @brief Send Method request (Client role)
 * 
 * @param[in] providerId Service provider ID
 * @param[in] methodId   Method ID (0x01-0xFE)
 * @param[in] data       Request data
 * @param[in] len        Data length
 * @param[in] type       Method type @see PICC_MethodType_e
 * @param[in] instanceId IPCF instance ID (usually IPCF_INSTANCE0)
 * @param[in] channelId  IPCF channel ID (0-2 based on current config)
 * @return Session ID (>0), returns 0 on failure
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId);

/**
 * @brief Send Method response (Server role)
 * 
 * @param[in] consumerId Requester ID
 * @param[in] methodId   Method ID
 * @param[in] sessionId  Session ID
 * @param[in] returnCode Return code
 * @param[in] data       Response data
 * @param[in] len        Data length
 * @param[in] instanceId IPCF instance ID (should match request source)
 * @param[in] channelId  IPCF channel ID (should match request source)
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_MethodResponse(uint8 consumerId, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len,
                          uint8 instanceId, uint8 channelId);

/* ========================================================================
 * Event/Method Handler Registration
 * ========================================================================
 * New architecture: Each service module directly calls registration APIs in picc_service.h:
 * - PICC_RegisterEventHandler(providerId, callback)
 * - PICC_RegisterMethodHandler(localProviderId, callback)
 * - PICC_RegisterResponseHandler(callback)
 */

/**
 * @brief Register connection state change callback
 * 
 * @param[in] callback Callback function
 * @return 0 on success
 */
sint8 PICC_RegisterLinkStateCallback(PICC_LinkStateCallback_t callback);

/**
 * @brief Get connection state for specified channel
 * 
 * @param[in] channelId IPCF channel ID
 * @return Connection state @see PICC_LinkState_e
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId);

/**
 * @brief Process received IPCF message
 * 
 * Called by data_chan_rx_cb in sample.c, completes protocol parsing and message dispatching.
 * 
 * @param[in] instance  IPCF instance ID
 * @param[in] chan_id   Receive channel ID (IPCF channel)
 * @param[in] buf       Receive buffer
 * @param[in] size      Receive data length
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_ProcessRxData(const uint8 instance, uint8 chan_id, const void *buf, uint32 size);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_API_H */
