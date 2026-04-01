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
#include "picc_link.h"      /* PICC_LinkState_e */

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
 *   Both callback fields (methodHandler and eventHandler) are OPTIONAL.
 *   Passing NULL means the application uses polling mode for that feature.
 *   Passing a valid function pointer enables immediate callback mode in
 *   addition to polling.
 *
 * Link state handling:
 *   Link state callbacks are intentionally not part of the application
 *   configuration. Applications query link state explicitly through the
 *   public PICC_GetLinkState(channelId) API when needed.
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
    uint16                   Client_linkReq_PeriodMs; /**< CLIENT connection request period (ms), 0=default 10ms. Ignored for SERVER. */
    PICC_MethodCallback_t    methodHandler;     /**< Method request callback (NULL = use PICC_GetMethodData polling) */
    PICC_EventCallback_t     eventHandler;      /**< Event notification callback (NULL = use PICC_GetEventData polling) */
} PICC_AppConfig_t;

/*==================================================================================================
 *                              Public API — Initialization (1 function)
 *==================================================================================================*/

/**
 * @brief Register one application with the PICC driver
 *
 * Performs all internal registrations (Link, Method handler, Event handler)
 * in a single call. The application layer only needs to call this function
 * once during its own Xxx_Init().
 *
 * This function is designed to be universally compatible across all application
 * modules. Different applications can independently choose polling mode
 * or immediate callback mode for Method/Event handling by setting the
 * corresponding fields in PICC_AppConfig_t.
 *
 * Prerequisites:
 *   - PICC_PreOS_Init() must have been called first.
 *
 *
 * @par Callback Documentation:
 * When initializing PICC_Init(), you can pass callback functions in 'config'. 
 * 
 * @warning ⚠️ ISR CONTEXT EXECUTION WARNING ⚠️
 *          Both `methodHandler` and `eventHandler` run directly within the IPCF hardware 
 *          RX Interrupt Service Routine (ISR) context.
 *          Application implementations MUST adhere to the following strict rules:
 *          1. **MAX EXECUTION TIME**: Must not exceed 50 microseconds.
 *          2. **NO BLOCKING**: Absolutely NO blocking OS calls (e.g., vTaskDelay, blocking on Semaphores/Mutexes, infinite loops).
 *          3. **PURPOSE**: Only use for instant hardware capture (e.g., timestamps) or rapid non-blocking state/variable updates.
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
 * @param[in] config    Pointer to application configuration (IDs, role, channel,
 *                      and optional Method/Event callbacks).
 *
 * @return PICC_E_OK        on success
 * @return PICC_E_PARAM     if config is NULL or appIndex is out of range
 * @return PICC_E_NOT_INIT  if PICC infrastructure (mailbox) not yet initialized

 */
sint8 PICC_Init(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config);

/*==================================================================================================
 *                              Public API — Sending M->A (3 functions)
 *==================================================================================================*/

/**
 * @brief Send an Event notification from M-Core to A-Core
 *
 * This function is used by M-Core to send a fire-and-forget notification to A-Core.
 * The driver automatically uses the localId, remoteId, and channelId from the
 * application's PICC_Init() configuration.
 *
 * @note IPCF Protocol Rule 3 constraints:
 *       1. M-Core should generally use `PICC_EVENT_WITHOUT_ACK`.
 *       2. If the application explicitly requires `PICC_EVENT_WITH_ACK`, M-Core will send
 *          the notification requiring an ACK, but due to M-Core's real-time constraints,
 *          the protocol layer will silently IGNORE the resulting EVENT_ACK from A-Core
 *          without blocking or processing it.
 *
 * @param[in] appIndex Application index (e.g., PICC_APP_PWR, PICC_APP_TIMESYNC).
 * @param[in] eventId  Event ID to send.
 * @param[in] data     Pointer to the event payload data.
 * @param[in] len      Length of the event payload data (max 32 bytes).
 * @param[in] withAck  Whether ACK is needed (PICC_EVENT_WITH_ACK or PICC_EVENT_WITHOUT_ACK).
 *
 * @return PICC_E_OK on success.
 *         Negative error code on failure (e.g., PICC_E_NOT_INIT, PICC_E_PARAM).
 */
sint8 PICC_SendEvent(PICC_AppIndex_e appIndex, uint8 eventId,
                     const uint8 *data, uint16 len, PICC_EventType_e withAck);

/**
 * @brief Send a Method Request from M-Core to A-Core
 *
 * This function is used by the M-Core (acting as a Client) to send a request
 * to the A-Core (acting as a Server). The driver automatically uses the remoteId
 * and channelId from the application's PICC_Init() configuration.
 *
 * @note IPCF Protocol Rule 3 constraints:
 *       Due to the real-time nature of M-Core hardware, this API does NOT block to
 *       wait for A-Core's response. It completely operates asynchronously.
 *       M-Core apps MUST capture the returned Session ID of this function, and
 *       later use it in `PICC_GetResponseData()` to asynchronously poll and match 
 *       the exact RESPONSE message returning from A-core.
 *       Supported Method Types:
 *         - PICC_METHOD_WITH_RESPONSE: Request requires business logic response.
 *         - PICC_METHOD_NO_RETURN_WITH_ACK: Request requires protocol ACK only.
 *         - PICC_METHOD_NO_RETURN_WITHOUT_ACK: Fire and forget request.
 *
 * @param[in] appIndex Application index (e.g., PICC_APP_OTA, PICC_APP_PWR).
 * @param[in] methodId Method ID to be invoked on the A-Core side.
 * @param[in] data     Pointer to the request payload data.
 * @param[in] len      Length of the request payload data (max 32 bytes).
 * @param[in] type     Request type (e.g., requires ACK, or requires full Response). @see PICC_MethodType_e
 *
 * @return A non-zero Session ID on success (used later to match the response).
 *         Returns 0 on failure (e.g., link disconnected, app not registered).
 */
uint8 PICC_MethodRequest(PICC_AppIndex_e appIndex, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type);

/**
 * @brief Send a Method Response from M-Core to A-Core
 *
 * This function is used by the M-Core (acting as a Server) to reply to a Method Request
 * that was previously sent by the A-Core (Client). The driver automatically uses the
 * remoteId and channelId from the application's PICC_Init() configuration.
 *
 * @param[in] appIndex   Application index (e.g., PICC_APP_PWR, PICC_APP_OTA).
 * @param[in] methodId   The Method ID that M-Core is responding to.
 * @param[in] sessionId  The unique Session ID extracted from the original A-Core request.
 * @param[in] returnCode Execution result code (e.g., 0x00 for Success, 0x01 for Error).
 * @param[in] data       Pointer to the response payload data.
 * @param[in] len        Length of the response payload data (max 32 bytes).
 *
 * @return PICC_E_OK on success.
 *         Negative error code on failure (e.g., PICC_E_NOT_INIT, PICC_E_PARAM).
 */
sint8 PICC_MethodResponse(PICC_AppIndex_e appIndex, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len);

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
 * if A-Core has replied. The sessionId parameter is critical for matching the correct
 * response when multiple async requests with the same methodId are outstanding.
 *
 * Session ID Matching Rules:
 *   - Non-zero sessionId: Only returns a response whose sessionId matches exactly.
 *     This is the RECOMMENDED usage for async Method calls, as the sessionId was
 *     returned by PICC_MethodRequest() and uniquely identifies each request.
 *   - Zero sessionId (0): Matches the first available response for this methodId
 *     regardless of session. This provides backward compatibility but risks
 *     returning the wrong response if multiple requests share the same methodId.
 *
 * @param[in]  appIndex    M-Core Application index (e.g., PICC_APP_PWR).
 * @param[in]  methodId    The Method ID mapping to the original request sent by M-Core.
 * @param[in]  sessionId   Session ID returned by PICC_MethodRequest(). Use this to match
 *                          the exact response. Pass 0 only if session matching is not needed.
 * @param[out] returnCode  Buffer to store the return code sent back by A-Core.
 * @param[out] data        Buffer to store the response payload data generated by A-Core.
 * @param[in]  maxLen      Maximum size of the 'data' buffer provided by M-Core.
 * @param[out] actualLen   Returns the actual length of the response payload received from A-Core.
 * @param[out] cbResult    Buffer to store the result produced by the M-Core callback handler (pass NULL if not needed/registered).
 * @param[out] cbResultLen Returns the length of the callback result (pass NULL if not needed/registered).
 *
 * @return PICC_E_OK       = A-Core has responded and data is retrieved.
 *         PICC_E_NO_DATA  = A-Core has not responded yet (or sessionId mismatch).
 *         PICC_E_PARAM    = Invalid parameters provided.
 */
sint8 PICC_GetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                           uint8 sessionId, uint8 *returnCode,
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
 *                              Public API — Status Query (2 functions)
 *==================================================================================================*/

/**
 * @brief Get the physical channel health state (heartbeat-based)
 *
 * Returns CONNECTED if the heartbeat on the specified IPCF channel is alive,
 * DISCONNECTED if the heartbeat has timed out. This checks the physical
 * transport layer, NOT the application-level connection handshake.
 *
 * For per-app connection state, use PICC_GetAppLinkState() instead.
 *
 * @param[in] channelId IPCF channel ID.
 * @return Physical channel health state.
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId);

/**
 * @brief Get the application-level link connection state (per-app)
 *
 * Each application (ProviderID/ConsumerID pair) independently performs
 * connection handshake with the remote peer. This API returns the
 * connection state for the specified appIndex.
 *
 * @param[in] appIndex Application index (e.g., PICC_APP_PWR).
 * @return Application-level link state (DISCONNECTED, CONNECTING, or CONNECTED).
 */
PICC_LinkState_e PICC_GetAppLinkState(PICC_AppIndex_e appIndex);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_API_H */
