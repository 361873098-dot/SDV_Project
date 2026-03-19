/**
 * @file picc_api.h
 * @brief PICC Driver Public API — Application Layer Interface
 *
 * This is the ONLY header file that application layers (Pwsm, OTA, etc.) should include.
 * It exposes exactly 8 public functions:
 *   - PICC_Init()          : Register an application
 *   - PICC_SendEvent()     : Send Event notification (M->A)  [declared in picc_service.h]
 *   - PICC_MethodRequest() : Send Method request, Client (M->A)
 *   - PICC_MethodResponse(): Send Method response, Server (M->A)
 *   - PICC_GetMethodData() : Get received Method request data (A->M)
 *   - PICC_GetResponseData(): Get received Method response data (A->M)
 *   - PICC_GetEventData()  : Get received Event data (A->M)
 *   - PICC_GetLinkState()  : Query link connection state
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_API_H
#define PICC_API_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_service.h"   /* PICC_SendEvent, PICC_EventCallback_t, PICC_MethodCallback_t */
#include "picc_link.h"      /* PICC_LinkState_e, PICC_LinkStateCallback_t */

/*==================================================================================================
 *                                         Error Codes
 *==================================================================================================*/

#define PICC_E_OK               (0)
#define PICC_E_NOT_INIT         (-1)
#define PICC_E_PARAM            (-2)
#define PICC_E_NOMEM            (-3)
#define PICC_E_SEND             (-4)
#define PICC_E_NOT_CONNECTED    (-5)
#define PICC_E_NO_DATA          (-6)   /**< No new data available */

/*==================================================================================================
 *                                         Application Index Enum
 *==================================================================================================*/

/**
 * @brief Application index for PICC_Init()
 *
 * Used as direct array index (O(1) lookup).
 */
typedef enum {
    PICC_APP_PWR      = 0U,   /**< Power Management    (ProviderID: 0x01) */
    PICC_APP_OTA      = 1U,   /**< OTA                 (ProviderID: 0x11) */
    PICC_APP_HEALTH   = 2U,   /**< Health Management   (ProviderID: 0x21) */
    PICC_APP_COMM     = 3U,   /**< Communication Mgmt  (ProviderID: 0x31) */
    PICC_APP_STORAGE  = 4U,   /**< Storage Module      (ProviderID: 0x41) */
    PICC_APP_DIAG     = 5U,   /**< Diagnostic Module   (ProviderID: 0x51) */
    PICC_APP_TIMESYNC = 6U,   /**< Time Synchronization(ProviderID: 0x61) */
    PICC_APP_SOA      = 7U,   /**< SOA Module          (ProviderID: 0x71) */
    PICC_APP_RSV0     = 8U,   /**< Reserved 0 */
    PICC_APP_RSV1     = 9U,   /**< Reserved 1 */
    PICC_APP_MAX      = 10U   /**< Max count (array size) */
} PICC_AppIndex_e;

/*==================================================================================================
 *                                         Application Configuration
 *==================================================================================================*/

/**
 * @brief Per-application PICC configuration
 *
 * Passed to PICC_Init() to register one application.
 * All internal registrations (Link, Method handler, Event handler) are
 * performed automatically inside PICC_Init().
 *
 * If methodHandler/eventHandler is NULL, the driver still stores received
 * data in its internal mailbox. The application can later retrieve data
 * using PICC_GetMethodData() / PICC_GetEventData().
 */
typedef struct {
    uint8                    localId;           /**< Local ID (ProviderID for Server, ConsumerID for Client) */
    uint8                    remoteId;          /**< Remote ID */
    PICC_Role_e              role;              /**< PICC_ROLE_SERVER or PICC_ROLE_CLIENT */
    uint8                    channelId;         /**< IPCF channel ID (1 or 2) */
    PICC_LinkStateCallback_t linkStateCallback; /**< Link state callback (can be NULL) */
    PICC_MethodCallback_t    methodHandler;     /**< Method handler (can be NULL, use polling) */
    PICC_EventCallback_t     eventHandler;      /**< Event handler (can be NULL, use polling) */
} PICC_AppConfig_t;

/*==================================================================================================
 *                              Public API — Initialization (1 function)
 *==================================================================================================*/

/**
 * @brief Register one application with the PICC driver
 *
 * Performs all internal registrations (Link, Method handler, Event handler,
 * Link state callback). The application layer only needs to call this once
 * during its own Xxx_Init().
 *
 * PICC_PreOS_Init() must have been called first.
 *
 * @param[in] appIndex  Application index (PICC_AppIndex_e)
 * @param[in] config    Application configuration and callback pointers
 * @return PICC_E_OK on success, negative on failure
 */
sint8 PICC_Init(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config);

/*==================================================================================================
 *                              Public API — Sending M->A (3 functions)
 *==================================================================================================*/

/* PICC_SendEvent() is declared in picc_service.h (included above) */

/**
 * @brief Send Method request (Client role, M->A)
 *
 * @param[in] providerId Target provider ID
 * @param[in] methodId   Method ID
 * @param[in] data       Request data
 * @param[in] len        Data length
 * @param[in] type       Method type @see PICC_MethodType_e
 * @param[in] instanceId IPCF instance ID
 * @param[in] channelId  IPCF channel ID
 * @return Session ID (>0) on success, 0 on failure
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId);

/**
 * @brief Send Method response (Server role, M->A)
 *
 * @param[in] consumerId Requester ID
 * @param[in] methodId   Method ID
 * @param[in] sessionId  Session ID (from request)
 * @param[in] returnCode Return code
 * @param[in] data       Response data
 * @param[in] len        Data length
 * @param[in] instanceId IPCF instance ID
 * @param[in] channelId  IPCF channel ID
 * @return PICC_E_OK on success, negative on failure
 */
sint8 PICC_MethodResponse(uint8 consumerId, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len,
                          uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                              Public API — Receiving A->M (3 functions)
 *==================================================================================================*/

/**
 * @brief Get A-core Method request data (Server role receives A-core request)
 *
 * Checks internally whether new data is available.
 * If available, copies data to buffer and clears the ready flag.
 *
 * @param[in]  appIndex   Application index
 * @param[in]  methodId   Method ID to check
 * @param[out] data       Buffer to receive data
 * @param[in]  maxLen     Buffer max length
 * @param[out] actualLen  Actual data length received
 * @return PICC_E_OK      = new data retrieved (flag cleared)
 *         PICC_E_NO_DATA = no new data
 *         PICC_E_PARAM   = invalid parameters
 */
sint8 PICC_GetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                         uint8 *data, uint16 maxLen, uint16 *actualLen);

/**
 * @brief Get A-core Method response data (Client role receives A-core reply)
 *
 * After sending PICC_MethodRequest(), poll this to get the A-core response.
 *
 * @param[in]  appIndex    Application index
 * @param[in]  methodId    Method ID
 * @param[out] returnCode  A-core return code (PICC_RET_OK etc.)
 * @param[out] data        Buffer to receive response data
 * @param[in]  maxLen      Buffer max length
 * @param[out] actualLen   Actual data length
 * @return PICC_E_OK       = new response retrieved
 *         PICC_E_NO_DATA  = no response yet
 *         PICC_E_PARAM    = invalid parameters
 */
sint8 PICC_GetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                           uint8 *returnCode,
                           uint8 *data, uint16 maxLen, uint16 *actualLen);

/**
 * @brief Get A-core Event notification data
 *
 * @param[in]  appIndex    Application index
 * @param[in]  eventId     Event ID to check
 * @param[out] data        Buffer to receive event data
 * @param[in]  maxLen      Buffer max length
 * @param[out] actualLen   Actual data length
 * @return PICC_E_OK       = new event retrieved
 *         PICC_E_NO_DATA  = no new event
 *         PICC_E_PARAM    = invalid parameters
 */
sint8 PICC_GetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                        uint8 *data, uint16 maxLen, uint16 *actualLen);

/*==================================================================================================
 *                              Public API — Status Query (1 function)
 *==================================================================================================*/

/**
 * @brief Get link connection state for specified channel
 *
 * @param[in] channelId IPCF channel ID
 * @return Connection state @see PICC_LinkState_e
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_API_H */
