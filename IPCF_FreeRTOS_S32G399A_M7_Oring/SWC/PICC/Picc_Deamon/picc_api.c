/**
 * @file picc_api.c
 * @brief PICC Driver Public API — Implementation
 *
 * This file contains ONLY the 8 public API functions.
 * All internal logic is delegated to:
 *   - picc_mailbox.c  : App registration, mailbox store/read
 *   - picc_service.c  : Event sending, method/response protocol
 *   - picc_link.c     : Link state management
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_api.h"
#include "picc_mailbox.h"
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */

/*==================================================================================================
 *                              Public API — Initialization (1 function)
 *==================================================================================================*/

/**
 * @brief Register an application with the PICC driver and initialize its context
 *
 * This function must be called by each application module (e.g., PWSM, OTA) before using 
 * any other PICC transmission or reception APIs. It registers the module's Provider ID 
 * and callback functions, sets up the mailbox, and initializes the underlying IPCF channel.
 *
 * @param[in] appIndex Application index (e.g., PICC_APP_PWR)
 * @param[in] config   Pointer to the application configuration structure.
 *                     Contains local/remote ID, role, and optional callback pointers.
 *
 * @return PICC_E_OK on success
 *         PICC_E_PARAM if parameters are invalid
 *         PICC_E_NOT_INIT if the mailbox infrastructure is not ready
 */
sint8 PICC_Init(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config)
{
    PICC_LinkConfig_t linkCfg;
    sint8 ret;

    if (config == NULL) {
        return PICC_E_PARAM;
    }
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (PICC_MailboxIsReady() == FALSE) {
        return PICC_E_NOT_INIT;
    }

    /* 1. Register app in mailbox context */
    ret = PICC_MailboxRegisterApp(appIndex, config);
    if (ret != PICC_E_OK) {
        return ret;
    }

    /* 2. Register Link */
    linkCfg.localId    = config->localId;
    linkCfg.remoteId   = config->remoteId;
    linkCfg.role       = config->role;
    linkCfg.channelId  = config->channelId;
    linkCfg.instanceId = IPCF_INSTANCE0;
    linkCfg.isUsed     = TRUE;
    ret = PICC_LinkInit(&linkCfg);
    if (ret != 0) {
        PICC_MailboxUnregisterApp(appIndex);
        return ret;
    }
    ret = PICC_LinkAddChannel(IPCF_INSTANCE0, config->channelId);
    if (ret != 0) {
        PICC_MailboxUnregisterApp(appIndex);
        return ret;
    }

    /* 3. Register Link state callback (optional) */
    if (config->linkStateCallback != NULL) {
        (void)PICC_LinkRegisterStateCallback(config->linkStateCallback);
    }

    /* 4. Register Method handler (optional) */
    if (config->methodHandler != NULL) {
        (void)PICC_RegisterMethodHandler(config->localId, config->methodHandler);
    }

    /* 5. Register Event handler (optional) */
    if (config->eventHandler != NULL) {
        (void)PICC_RegisterEventHandler(config->remoteId, config->eventHandler);
    }

    return PICC_E_OK;
}

/*==================================================================================================
 *                              Public API — Sending M->A (3 functions)
 *==================================================================================================*/

/* PICC_SendEvent() is implemented in picc_service.c */

/**
 * @brief Send a Method Request to the remote core (Client role)
 *
 * This function sends a request message from the local Client to the remote Server. 
 * The caller can choose whether the request requires an ACK or a full Response 
 * using the `type` parameter.
 *
 * @param[in] providerId Target Server's Provider ID
 * @param[in] methodId   Method ID to be invoked
 * @param[in] data       Pointer to the request payload data
 * @param[in] len        Length of the request payload (max 32 bytes)
 * @param[in] type       Request type (e.g., PICC_METHOD_TYPE_REQUEST, PICC_METHOD_TYPE_NO_RETURN_WITH_ACK)
 * @param[in] instanceId IPCF Instance ID (typically IPCF_INSTANCE0)
 * @param[in] channelId  IPCF Channel ID assigned to this application
 *
 * @return Returns a generated Session ID (> 0) on success.
 *         Returns 0 on failure (e.g., channel disconnected).
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId)
{
    if (PICC_MailboxIsReady() == FALSE) {
        return 0U;
    }

    if (PICC_LinkGetState(channelId) != PICC_LINK_STATE_CONNECTED) {
        return 0U;
    }

    return PICC_ServiceMethodSend(providerId, methodId, data, len, type, instanceId, channelId);
}

/**
 * @brief Send a Method Response to the remote core (Server role)
 *
 * When the local Server finishes processing a Method Request, it calls this function 
 * to return the outcome and optional response data to the remote Client.
 *
 * @param[in] consumerId Requester's Client ID (from the original request header)
 * @param[in] methodId   Method ID being responded to
 * @param[in] sessionId  Session ID matching the original request
 * @param[in] returnCode Processing result code (e.g., PICC_RET_OK or specific error)
 * @param[in] data       Pointer to the response payload data
 * @param[in] len        Length of the response payload (max 32 bytes)
 * @param[in] instanceId IPCF Instance ID (typically IPCF_INSTANCE0)
 * @param[in] channelId  IPCF Channel ID assigned to this application
 *
 * @return PICC_E_OK on success
 *         Negative error code on failure
 */
sint8 PICC_MethodResponse(uint8 consumerId, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len,
                          uint8 instanceId, uint8 channelId)
{
    if (PICC_MailboxIsReady() == FALSE) {
        return PICC_E_NOT_INIT;
    }

    return PICC_ServiceResponseSend(consumerId, methodId, sessionId,
                                    returnCode, data, len, instanceId, channelId);
}

/*==================================================================================================
 *                              Public API — Receiving A->M (3 functions)
 *==================================================================================================*/

/**
 * @brief Retrieve a received Method Request from the mailbox (Server role)
 *
 * Polling interface for reading incoming Method Requests. If a methodHandler callback 
 * was registered during PICC_Init(), the callback's result is also returned here.
 *
 * @param[in]  appIndex    Application index (e.g., PICC_APP_PWR)
 * @param[in]  methodId    The specific Method ID to poll for
 * @param[out] data        Buffer to store the received payload from A-core
 * @param[in]  maxLen      Maximum capacity of the `data` buffer
 * @param[out] actualLen   Pointer to store the actual number of payload bytes received
 * @param[out] cbResult    Buffer to store the result produced by the callback (pass NULL if not needed)
 * @param[out] cbResultLen Pointer to store the length of the callback result (pass NULL if not needed)
 *
 * @return PICC_E_OK if new data was successfully retrieved
 *         PICC_E_NO_DATA if no new data has arrived
 *         PICC_E_PARAM for invalid parameters
 */
sint8 PICC_GetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                         uint8 *data, uint16 maxLen, uint16 *actualLen,
                         uint8 *cbResult, uint16 *cbResultLen)
{
    return PICC_MailboxGetMethodData(appIndex, methodId, data, maxLen, actualLen,
                                     cbResult, cbResultLen);
}

/**
 * @brief Retrieve a received Method Response from the mailbox (Client role)
 *
 * Polling interface for reading incoming Method Responses. Called by the Client 
 * after sending a Method Request to check if the Server has replied.
 *
 * @param[in]  appIndex    Application index (e.g., PICC_APP_PWR)
 * @param[in]  methodId    The specific Method ID to check the response for
 * @param[out] returnCode  Pointer to store the remote Server's return code
 * @param[out] data        Buffer to store the response payload from A-core
 * @param[in]  maxLen      Maximum capacity of the `data` buffer
 * @param[out] actualLen   Pointer to store the actual number of payload bytes received
 * @param[out] cbResult    Buffer to store the result produced by the callback (pass NULL if not needed)
 * @param[out] cbResultLen Pointer to store the length of the callback result (pass NULL if not needed)
 *
 * @return PICC_E_OK if a new response was successfully retrieved
 *         PICC_E_NO_DATA if no response has arrived yet
 *         PICC_E_PARAM for invalid parameters
 */
sint8 PICC_GetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                           uint8 *returnCode,
                           uint8 *data, uint16 maxLen, uint16 *actualLen,
                           uint8 *cbResult, uint16 *cbResultLen)
{
    return PICC_MailboxGetResponseData(appIndex, methodId, returnCode, data, maxLen, actualLen,
                                       cbResult, cbResultLen);
}

/**
 * @brief Retrieve a received Event Notification from the mailbox
 *
 * Polling interface for reading incoming Event Notifications. If an eventHandler callback 
 * was registered during PICC_Init(), the callback's result is also returned here.
 *
 * @param[in]  appIndex    Application index (e.g., PICC_APP_PWR)
 * @param[in]  eventId     The specific Event ID to poll for
 * @param[out] data        Buffer to store the event payload from A-core
 * @param[in]  maxLen      Maximum capacity of the `data` buffer
 * @param[out] actualLen   Pointer to store the actual number of payload bytes received
 * @param[out] cbResult    Buffer to store the result produced by the callback (pass NULL if not needed)
 * @param[out] cbResultLen Pointer to store the length of the callback result (pass NULL if not needed)
 *
 * @return PICC_E_OK if a new event was successfully retrieved
 *         PICC_E_NO_DATA if no new event has arrived
 *         PICC_E_PARAM for invalid parameters
 */
sint8 PICC_GetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                        uint8 *data, uint16 maxLen, uint16 *actualLen,
                        uint8 *cbResult, uint16 *cbResultLen)
{
    return PICC_MailboxGetEventData(appIndex, eventId, data, maxLen, actualLen,
                                    cbResult, cbResultLen);
}

/*==================================================================================================
 *                              Public API — Status (1 function)
 *==================================================================================================*/

/**
 * @brief Get the current IPCF channel connection state
 *
 * Indicates whether the underlying IPCF link is connected or disconnected.
 * This can be used in polling mode when no linkStateCallback is registered.
 *
 * @param[in] channelId IPCF Channel ID
 *
 * @return PICC_LINK_STATE_CONNECTED if the channel is up and running
 *         PICC_LINK_STATE_DISCONNECTED if the channel is down
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId)
{
    return PICC_LinkGetState(channelId);
}

#if defined(__cplusplus)
}
#endif
