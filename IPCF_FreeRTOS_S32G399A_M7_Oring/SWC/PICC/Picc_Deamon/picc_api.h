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
 * Passed to PICC_Init() to register one application with the PICC driver.
 * All internal registrations (Link, Method handler, Event handler) are
 * performed automatically inside PICC_Init().
 *
 * Callback Design Principle:
 *   All three callback fields (linkStateCallback, methodHandler, eventHandler)
 *   are OPTIONAL. Passing NULL means the application uses polling mode for
 *   that particular feature. Passing a valid function pointer enables
 *   immediate callback mode IN ADDITION to polling (both work simultaneously).
 *
 * linkStateCallback:
 *   - NULL  : Application polls link state via PICC_GetLinkState(channelId).
 *             Suitable for periodic tasks (e.g., Pwsm 10ms cycle).
 *   - !NULL : Driver calls this function immediately when link state changes
 *             (connected/disconnected). Suitable for applications requiring
 *             instant reaction (e.g., DIAG module raising DTC on disconnect).
 *
 * methodHandler:
 *   - NULL  : Received Method requests are stored in the internal mailbox.
 *             Application retrieves data via PICC_GetMethodData() polling.
 *             Suitable for non-time-critical services (e.g., power management).
 *   - !NULL : Driver calls this function immediately when an A-core Method
 *             request arrives. The callback can return response data directly.
 *             Suitable for time-critical services (e.g., OTA flash write,
 *             diagnostic data read) where 10ms polling delay is unacceptable.
 *             NOTE: Mailbox storage still occurs even when callback is set.
 *
 * eventHandler:
 *   - NULL  : Received Event notifications are stored in the internal mailbox.
 *             Application retrieves data via PICC_GetEventData() polling.
 *   - !NULL : Driver calls this function immediately when an A-core Event
 *             notification arrives. Suitable for microsecond-precision tasks
 *             (e.g., time synchronization timestamp capture).
 *             NOTE: Mailbox storage still occurs even when callback is set.
 *
 * This design ensures PICC_Init() is fully compatible with all application
 * scenarios — from simple polling to complex real-time callback processing —
 * without requiring any API changes.
 */
typedef struct {
    uint8                    localId;           /**< Local ID (ProviderID for Server, ConsumerID for Client) */
    uint8                    remoteId;          /**< Remote ID (peer's ProviderID or ConsumerID) */
    PICC_Role_e              role;              /**< PICC_ROLE_SERVER or PICC_ROLE_CLIENT */
    uint8                    channelId;         /**< IPCF channel ID (1 or 2) */
    PICC_LinkStateCallback_t linkStateCallback; /**< Link state change callback (NULL = use PICC_GetLinkState polling) */
    PICC_MethodCallback_t    methodHandler;     /**< Method request callback (NULL = use PICC_GetMethodData polling) */
    PICC_EventCallback_t     eventHandler;      /**< Event notification callback (NULL = use PICC_GetEventData polling) */
} PICC_AppConfig_t;

/*==================================================================================================
 *                              Public API — Initialization (1 function)
 *==================================================================================================*/

/**
 * @brief Register one application with the PICC driver
 *
 * Performs all internal registrations (Link, Method handler, Event handler,
 * Link state callback) in a single call. The application layer only needs
 * to call this function once during its own Xxx_Init().
 *
 * This function is designed to be universally compatible across all application
 * modules. Different applications can independently choose polling mode
 * (callback = NULL) or immediate callback mode for each feature by setting
 * the corresponding fields in PICC_AppConfig_t.
 *
 * Prerequisites:
 *   - PICC_PreOS_Init() must have been called first.
 *
 *
 * @par Callback Documentation:
 * When initializing PICC_Init(), you can pass callback functions in 'config'. The signatures 
 * and exact parameter meanings are documented below:
 *
 * @par eventHandler Signature:
 * `void My_EventHandler(uint8 providerId, uint8 eventId, const uint8 *data, uint16 len, uint8 *cbResult, uint16 *cbResultLen)`
 *  - @b providerId : [Input] The A-Core Server's Provider ID that broadcasted this event.
 *  - @b eventId    : [Input] The specific Event ID generated by A-Core.
 *  - @b data       : [Input] Raw notification payload data sent from A-Core.
 *  - @b len        : [Input] Length of the notification payload.
 *  - @b cbResult   : [Output] Buffer mapped to PICC mailbox. M-Core handler writes its instant calculation result here.
 *  - @b cbResultLen: [Output] Indicates how many bytes of 'cbResult' the M-Core handler populated.
 *
 * @par methodHandler Signature:
 * `uint8 My_MethodHandler(uint8 consumerId, uint8 methodId, const uint8 *reqData, uint16 reqLen, uint8 *rspData, uint16 *rspLen, uint8 *cbResult, uint16 *cbResultLen)`
 *  - @b consumerId : [Input] The A-Core Client's ID who initiated this Method Request.
 *  - @b methodId   : [Input] The Method ID A-Core wants to call on M-Core.
 *  - @b reqData    : [Input] Raw request payload data block sent from A-Core.
 *  - @b reqLen     : [Input] Length of the request payload data.
 *  - @b rspData    : [Output] Buffer for M-Core handler to write the Response data to be sent back to A-Core.
 *  - @b rspLen     : [Output] Length of the Response data M-Core wants to send back.
 *  - @b cbResult   : [Output] Buffer mapped to PICC mailbox. M-Core handler writes its internal parsing result here.
 *  - @b cbResultLen: [Output] Indicates how many bytes of 'cbResult' the M-Core handler populated.
 *
 * @param[in] appIndex  Application index from PICC_AppIndex_e enum (e.g., PICC_APP_PWR).
 * @param[in] config    Pointer to application configuration (IDs, Role, Channel, and Callback functions).
 *
 * @return PICC_E_OK        on success
 * @return PICC_E_PARAM     if config is NULL or appIndex is out of range
 * @return PICC_E_NOT_INIT  if PICC infrastructure (mailbox) not yet initialized

 */
sint8 PICC_Init(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config);

/*==================================================================================================
 *                              Public API — Sending M->A (3 functions)
 *==================================================================================================*/

/* PICC_SendEvent() is declared in picc_service.h (included above) */

/**
 * @brief Send a Method Request from M-Core to A-Core
 *
 * This function is used by the M-Core (acting as a Client) to send a request 
 * to the A-Core (acting as a Server). M-Core asks A-Core to perform a specific action.
 *
 * @param[in] providerId Target A-Core Server's Provider ID (who you are talking to).
 * @param[in] methodId   Method ID to be invoked on the A-Core side.
 * @param[in] data       Pointer to the request payload data that M-Core wants to send to A-Core.
 * @param[in] len        Length of the request payload data (max 32 bytes).
 * @param[in] type       Request type (e.g., requires ACK, or requires full Response). @see PICC_MethodType_e
 * @param[in] instanceId IPCF instance ID (typically IPCF_INSTANCE0 for S32G3).
 * @param[in] channelId  IPCF channel ID used by this application (1 or 2).
 *
 * @return A non-zero Session ID on success (used later to match the response).
 *         Returns 0 on failure (e.g., link disconnected, mailbox full).
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId);

/**
 * @brief Send a Method Response from M-Core to A-Core
 *
 * This function is used by the M-Core (acting as a Server) to reply to a Method Request
 * that was previously sent by the A-Core (Client). M-Core reports the execution result.
 *
 * @param[in] consumerId A-Core Client's ID (the one who originally sent the request).
 * @param[in] methodId   The Method ID that M-Core is responding to.
 * @param[in] sessionId  The unique Session ID extracted from the original A-Core request.
 * @param[in] returnCode Execution result code generated by M-Core (e.g., 0x00 for Success, 0x01 for Error).
 * @param[in] data       Pointer to the response payload data that M-Core wants to send back to A-Core.
 * @param[in] len        Length of the response payload data (max 32 bytes).
 * @param[in] instanceId IPCF instance ID (typically IPCF_INSTANCE0).
 * @param[in] channelId  IPCF channel ID used by this application (1 or 2).
 *
 * @return PICC_E_OK on success.
 *         Negative error code on failure (e.g., PICC_E_NOT_INIT).
 */
sint8 PICC_MethodResponse(uint8 consumerId, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len,
                          uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                              Public API — Receiving A->M (3 functions)
 *==================================================================================================*/

/**
 * @brief Retrieve a Method Request sent by A-Core to M-Core (M-Core is Server)
 *
 * Polling API for M-Core application tasks. It queries the local mailbox to see if 
 * A-Core has sent a new Method Request for the specified methodId. If a 'methodHandler' 
 * callback was registered, this function also retrieves the secondary calculation result 
 * ('cbResult') produced instantly by that callback.
 *
 * @param[in]  appIndex    M-Core Application index (e.g., PICC_APP_OTA).
 * @param[in]  methodId    The specific Method ID M-Core is looking for.
 * @param[out] data        Buffer to store the raw payload data sent by A-Core.
 * @param[in]  maxLen      Maximum size of the 'data' buffer provided by M-Core.
 * @param[out] actualLen   Returns the actual length of the payload data received from A-Core.
 * @param[out] cbResult    Buffer to store the result produced by the M-Core callback handler (pass NULL if not needed/registered).
 * @param[out] cbResultLen Returns the length of the callback result (pass NULL if not needed/registered).
 *
 * @return PICC_E_OK      = New request from A-Core was successfully retrieved.
 *         PICC_E_NO_DATA = No new request from A-Core has arrived yet.
 *         PICC_E_PARAM   = Invalid parameters provided.
 */
sint8 PICC_GetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                         uint8 *data, uint16 maxLen, uint16 *actualLen,
                         uint8 *cbResult, uint16 *cbResultLen);

/**
 * @brief Retrieve a Method Response returned by A-Core to M-Core (M-Core is Client)
 *
 * After M-Core calls PICC_MethodRequest(), it uses this API in a periodic task to check 
 * if A-Core has replied. Once A-Core replies, M-Core reads the target returnCode and data.
 *
 * @param[in]  appIndex    M-Core Application index (e.g., PICC_APP_PWR).
 * @param[in]  methodId    The Method ID mapping to the original request sent by M-Core.
 * @param[out] returnCode  Buffer to store the return code sent back by A-Core.
 * @param[out] data        Buffer to store the response payload data generated by A-Core.
 * @param[in]  maxLen      Maximum size of the 'data' buffer provided by M-Core.
 * @param[out] actualLen   Returns the actual length of the response payload received from A-Core.
 * @param[out] cbResult    Buffer to store the result produced by the M-Core callback handler (pass NULL if not needed/registered).
 * @param[out] cbResultLen Returns the length of the callback result (pass NULL if not needed/registered).
 *
 * @return PICC_E_OK       = A-Core has responded and data is retrieved.
 *         PICC_E_NO_DATA  = A-Core has not responded yet.
 *         PICC_E_PARAM    = Invalid parameters provided.
 */
sint8 PICC_GetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                           uint8 *returnCode,
                           uint8 *data, uint16 maxLen, uint16 *actualLen,
                           uint8 *cbResult, uint16 *cbResultLen);

/**
 * @brief Retrieve an Event Notification sent by A-Core to M-Core (Fire & Forget)
 *
 * Polling API for M-Core application tasks to check if A-Core has broadcast an Event.
 * If an 'eventHandler' was registered (e.g., to capture timestamps instantly), the 
 * result generated by that callback is simultaneously collected via 'cbResult'.
 *
 * @param[in]  appIndex    M-Core Application index (e.g., PICC_APP_TIMESYNC).
 * @param[in]  eventId     The specific Event ID M-Core is checking for.
 * @param[out] data        Buffer to store the payload data broadcasted by A-Core.
 * @param[in]  maxLen      Maximum size of the 'data' buffer provided by M-Core.
 * @param[out] actualLen   Returns the actual length of the event payload received from A-Core.
 * @param[out] cbResult    Buffer to store the result produced by the M-Core callback handler (pass NULL if not needed/registered).
 * @param[out] cbResultLen Returns the length of the callback result (pass NULL if not needed/registered).
 *
 * @return PICC_E_OK       = New event from A-Core was successfully retrieved.
 *         PICC_E_NO_DATA  = No new event from A-Core has arrived.
 *         PICC_E_PARAM    = Invalid parameters provided.
 */
sint8 PICC_GetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                        uint8 *data, uint16 maxLen, uint16 *actualLen,
                        uint8 *cbResult, uint16 *cbResultLen);

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
