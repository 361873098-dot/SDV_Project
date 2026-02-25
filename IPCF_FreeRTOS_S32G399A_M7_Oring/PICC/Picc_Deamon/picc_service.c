/**
 * @file picc_service.c
 * @brief M-Core Inter-Core Communication Service Layer - Implementation
 *
 * Implements Event and Method service processing, including auto ACK reply (middleware layer).
 * Supports multi-module registration, routing messages to corresponding modules by ProviderID.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_service.h"
#include "picc_link.h"
#include "picc_stack.h"
#include "Picc_main.h"    /* For HANDLE_ERROR */
#include "ipc-shm.h"
#include "FreeRTOS.h"
#include "task.h"

/*==================================================================================================
 *                                         Private Types
 *==================================================================================================*/

/** Event handler registration entry */
typedef struct {
    uint8                 providerId;   /**< Target ProviderID */
    PICC_EventCallback_t  callback;     /**< Callback function */
    boolean               isUsed;       /**< Is slot in use */
} PICC_EventHandler_t;

/** Method handler registration entry */
typedef struct {
    uint8                  localProviderId;  /**< Local module's ProviderID */
    PICC_MethodCallback_t  callback;         /**< Callback function */
    boolean                isUsed;           /**< Is slot in use */
} PICC_MethodHandler_t;

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Event handler registry */
static PICC_EventHandler_t g_eventHandlers[PICC_MAX_EVENT_HANDLERS];

/** Method handler registry */
static PICC_MethodHandler_t g_methodHandlers[PICC_MAX_METHOD_HANDLERS];

/** Method response callback (Client role, only one needed) */
static PICC_ResponseCallback_t g_responseCallback = NULL;

/** Session ID counter */
static uint8 g_sessionIdCounter = PICC_SESSION_ID_MIN;

/** Response data buffer */
static uint8 g_rspBuffer[PICC_MAX_PAYLOAD_SIZE];

/** TX buffer for message packing (static to avoid stack overflow with large payloads) */
static uint8 g_txBuffer[PICC_HEADER_SIZE + PICC_MAX_PAYLOAD_SIZE];

/** Whether service layer is initialized */
static boolean g_serviceInitialized = FALSE;

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Get next Session ID
 */
static uint8 PICC_GetNextSessionId(void)
{
    uint8 id = g_sessionIdCounter;
    g_sessionIdCounter++;
    if (g_sessionIdCounter == 0U) {
        g_sessionIdCounter = PICC_SESSION_ID_MIN;
    }
    return id;
}

/**
 * @brief Send ACK message (unified through Stack stacking)
 */
static sint8 PICC_ServiceSendAck(uint8 msgType, uint8 providerId, uint8 consumerId,
                                 uint8 methodId, uint8 sessionId,
                                 uint8 instanceId, uint8 channelId)
{
    uint8 txBuf[PICC_HEADER_SIZE];
    PICC_MsgHeader_t header;
    uint32 packedLen;
    sint8 ret;
    
    (void)instanceId;

    header.providerId = providerId;
    header.methodId   = methodId;
    header.consumerId = consumerId;
    header.sessionId  = sessionId;
    header.msgType    = msgType;
    header.returnCode = (uint8)PICC_RET_OK;

    packedLen = PICC_PackMessage(txBuf, sizeof(txBuf), &header, NULL, 0U);
    if (packedLen == 0U) {
        HANDLE_ERROR(-11);  /* Service: Failed to pack ACK message */
        return -1;
    }

    ret = PICC_StackAddMessageToChannel(channelId, txBuf, packedLen);
    if (ret != 0) {
        HANDLE_ERROR(-12);  /* Service: Failed to add ACK to stack */
    }
    return ret;
}

/**
 * @brief Send message (unified through Stack stacking)
 * 
 * @note Uses static g_txBuffer to avoid stack overflow with large payloads.
 *       This function is NOT thread-safe - only call from single task context.
 */
static sint8 PICC_ServiceSendMessage(const PICC_MsgHeader_t *header,
                                     const uint8 *payload, uint16 payloadLen,
                                     uint8 channelId)
{
    uint32 packedLen;
    sint8 ret;
    
    if (header == NULL) {
        HANDLE_ERROR(-13);  /* Service: SendMessage header is NULL */
        return -1;
    }
    
    /* [FIX] Enter critical section to protect g_txBuffer from concurrent access
     * (Timer callback and Task may call this simultaneously) */
    taskENTER_CRITICAL();
    
    packedLen = PICC_PackMessage(g_txBuffer, sizeof(g_txBuffer), header, payload, payloadLen);
    if (packedLen == 0U) {
        taskEXIT_CRITICAL();
        HANDLE_ERROR(-14);  /* Service: Failed to pack message */
        return -1;
    }
    
    ret = PICC_StackAddMessageToChannel(channelId, g_txBuffer, packedLen);
    
    taskEXIT_CRITICAL();
    
    if (ret != 0) {
        HANDLE_ERROR(-15);  /* Service: Failed to add message to stack */
    }
    return ret;
}

/**
 * @brief Handle Event notification (route to registered handlers)
 */
static sint8 PICC_ServiceHandleEvent(const PICC_MsgHeader_t *header,
                                     const uint8 *payload, uint16 len,
                                     uint8 instanceId, uint8 channelId)
{
    uint32 i;
    
    /* If Event with ACK, auto reply EVENT_ACK */
    if (header->msgType == (uint8)PICC_MSG_NOTIFICATION_WITH_ACK) {
        (void)PICC_ServiceSendAck((uint8)PICC_MSG_EVENT_ACK,
                                  header->providerId,
                                  header->consumerId,
                                  header->methodId,
                                  header->sessionId,
                                  instanceId, channelId);
    }

    /* Route to handler matching ProviderID */
    for (i = 0U; i < PICC_MAX_EVENT_HANDLERS; i++) {
        if (g_eventHandlers[i].isUsed && 
            g_eventHandlers[i].providerId == header->providerId &&
            g_eventHandlers[i].callback != NULL) {
            g_eventHandlers[i].callback(header->providerId, header->methodId, payload, len);
        }
    }

    return 0;
}

/**
 * @brief Handle Method request (route to registered handlers)
 */
static sint8 PICC_ServiceHandleRequest(const PICC_MsgHeader_t *header,
                                       const uint8 *payload, uint16 len,
                                       uint8 instanceId, uint8 channelId)
{
    uint32 i;
    uint8 returnCode = (uint8)PICC_RET_OK;
    uint16 rspLen = 0U;
    PICC_MsgHeader_t rspHeader;

    /* If REQUEST_NO_RETURN_WITH_ACK, auto reply ACK */
    if (header->msgType == (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK) {
        (void)PICC_ServiceSendAck((uint8)PICC_MSG_ACK,
                                  header->providerId,
                                  header->consumerId,
                                  header->methodId,
                                  header->sessionId,
                                  instanceId, channelId);
    }

    /* Route to handler matching ProviderID */
    for (i = 0U; i < PICC_MAX_METHOD_HANDLERS; i++) {
        if (g_methodHandlers[i].isUsed && 
            g_methodHandlers[i].localProviderId == header->providerId &&
            g_methodHandlers[i].callback != NULL) {
            returnCode = g_methodHandlers[i].callback(header->consumerId,
                                                      header->methodId,
                                                      payload, len,
                                                      g_rspBuffer, &rspLen);
            break;  /* Only one handler matches */
        }
    }

    /* If REQUEST requires Response, send response */
    if (header->msgType == (uint8)PICC_MSG_REQUEST) {
        rspHeader.providerId = header->providerId;
        rspHeader.methodId   = header->methodId;
        rspHeader.consumerId = header->consumerId;
        rspHeader.sessionId  = header->sessionId;
        rspHeader.msgType    = (uint8)PICC_MSG_RESPONSE;
        rspHeader.returnCode = returnCode;

        (void)PICC_ServiceSendMessage(&rspHeader, g_rspBuffer, rspLen, channelId);
    }

    return 0;
}

/**
 * @brief Handle Method response (Client role)
 */
static sint8 PICC_ServiceHandleResponse(const PICC_MsgHeader_t *header,
                                        const uint8 *payload, uint16 len)
{
    if (g_responseCallback != NULL) {
        g_responseCallback(header->providerId,
                          header->methodId,
                          header->sessionId,
                          header->returnCode,
                          payload, len);
    }
    return 0;
}

/*==================================================================================================
 *                                         Public Functions - Initialization
 *==================================================================================================*/

/**
 * @brief Initialize service layer (called by PICC_Init)
 */
void PICC_ServiceLayerInit(void)
{
    uint32 i;
    
    /* Clear registry */
    for (i = 0U; i < PICC_MAX_EVENT_HANDLERS; i++) {
        g_eventHandlers[i].isUsed = FALSE;
        g_eventHandlers[i].callback = NULL;
    }
    
    for (i = 0U; i < PICC_MAX_METHOD_HANDLERS; i++) {
        g_methodHandlers[i].isUsed = FALSE;
        g_methodHandlers[i].callback = NULL;
    }
    
    g_responseCallback = NULL;
    g_sessionIdCounter = PICC_SESSION_ID_MIN;
    g_serviceInitialized = TRUE;
}

/**
 * @brief Deinitialize service layer
 */
void PICC_ServiceLayerDeinit(void)
{
    uint32 i;
    
    for (i = 0U; i < PICC_MAX_EVENT_HANDLERS; i++) {
        g_eventHandlers[i].isUsed = FALSE;
    }
    
    for (i = 0U; i < PICC_MAX_METHOD_HANDLERS; i++) {
        g_methodHandlers[i].isUsed = FALSE;
    }
    
    g_responseCallback = NULL;
    g_serviceInitialized = FALSE;
}

/*==================================================================================================
 *                                         Public Functions - Handler Registration
 *==================================================================================================*/

/**
 * @brief Register Event receive handler
 */
sint8 PICC_RegisterEventHandler(uint8 providerId, PICC_EventCallback_t callback)
{
    uint32 i;
    
    if (callback == NULL) {
        HANDLE_ERROR(-16);  /* Service: Event handler callback is NULL */
        return -1;
    }
    
    /* Find free slot */
    for (i = 0U; i < PICC_MAX_EVENT_HANDLERS; i++) {
        if (g_eventHandlers[i].isUsed == FALSE) {
            g_eventHandlers[i].providerId = providerId;
            g_eventHandlers[i].callback = callback;
            g_eventHandlers[i].isUsed = TRUE;
            return 0;
        }
    }
    
    HANDLE_ERROR(-17);  /* Service: Event handler registry full */
    return -2;  /* Registry full */
}

/**
 * @brief Register Method request handler
 */
sint8 PICC_RegisterMethodHandler(uint8 localProviderId, PICC_MethodCallback_t callback)
{
    uint32 i;
    
    if (callback == NULL) {
        HANDLE_ERROR(-18);  /* Service: Method handler callback is NULL */
        return -1;
    }
    
    /* Find free slot */
    for (i = 0U; i < PICC_MAX_METHOD_HANDLERS; i++) {
        if (g_methodHandlers[i].isUsed == FALSE) {
            g_methodHandlers[i].localProviderId = localProviderId;
            g_methodHandlers[i].callback = callback;
            g_methodHandlers[i].isUsed = TRUE;
            return 0;
        }
    }
    
    HANDLE_ERROR(-19);  /* Service: Method handler registry full */
    return -2;  /* Registry full */
}

/**
 * @brief Register Method response handler
 */
sint8 PICC_RegisterResponseHandler(PICC_ResponseCallback_t callback)
{
    g_responseCallback = callback;
    return 0;
}

/*==================================================================================================
 *                                         Public Functions - Sending
 *==================================================================================================*/

/**
 * @brief Send Event notification
 */
sint8 PICC_SendEvent(uint8 providerId, uint8 eventId, uint8 consumerId,
                     const uint8 *data, uint16 len, PICC_EventType_e withAck,
                     uint8 channelId)
{
    PICC_MsgHeader_t header;
    sint8 ret;

    if (g_serviceInitialized == FALSE) {
        HANDLE_ERROR(-20);  /* Service: Not initialized for SendEvent */
        return -1;
    }

    header.providerId = providerId;
    header.methodId   = eventId;
    header.consumerId = consumerId;
    header.sessionId  = (withAck == PICC_EVENT_WITH_ACK) ? PICC_GetNextSessionId() : 0x00U;
    header.msgType    = (withAck == PICC_EVENT_WITH_ACK) ?
                        (uint8)PICC_MSG_NOTIFICATION_WITH_ACK :
                        (uint8)PICC_MSG_NOTIFICATION_WITHOUT_ACK;
    header.returnCode = (uint8)PICC_RET_OK;

    ret = PICC_ServiceSendMessage(&header, data, len, channelId);
    if (ret != 0) {
        HANDLE_ERROR(-21);  /* Service: SendEvent failed */
    }
    return ret;
}

/**
 * @brief Send Method request (Client role)
 */
uint8 PICC_ServiceMethodSend(uint8 providerId, uint8 methodId,
                             const uint8 *data, uint16 len,
                             PICC_MethodType_e type,
                             uint8 instanceId, uint8 channelId)
{
    PICC_MsgHeader_t header;
    uint8 sessionId;
    sint8 ret;

    (void)instanceId;

    if (g_serviceInitialized == FALSE) {
        HANDLE_ERROR(-22);  /* Service: Not initialized for MethodSend */
        return 0U;
    }

    sessionId = PICC_GetNextSessionId();

    header.providerId = providerId;
    header.methodId   = methodId;
    header.consumerId = 0U;  /* Set by caller at higher layer */
    header.sessionId  = sessionId;
    header.returnCode = (uint8)PICC_RET_OK;

    switch (type) {
        case PICC_METHOD_WITH_RESPONSE:
            header.msgType = (uint8)PICC_MSG_REQUEST;
            break;
        case PICC_METHOD_NO_RETURN_WITH_ACK:
            header.msgType = (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK;
            break;
        case PICC_METHOD_NO_RETURN_WITHOUT_ACK:
            header.msgType = (uint8)PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK;
            break;
        default:
            HANDLE_ERROR(-23);  /* Service: Invalid method type */
            return 0U;
    }

    ret = PICC_ServiceSendMessage(&header, data, len, channelId);
    if (ret != 0) {
        HANDLE_ERROR(-24);  /* Service: MethodSend failed */
        return 0U;
    }

    return sessionId;
}

/**
 * @brief Send Method response (Server role)
 */
sint8 PICC_ServiceResponseSend(uint8 consumerId, uint8 methodId,
                               uint8 sessionId, uint8 returnCode,
                               const uint8 *data, uint16 len,
                               uint8 instanceId, uint8 channelId)
{
    PICC_MsgHeader_t header;
    sint8 ret;

    (void)instanceId;

    if (g_serviceInitialized == FALSE) {
        HANDLE_ERROR(-25);  /* Service: Not initialized for ResponseSend */
        return -1;
    }

    header.providerId = 0U;  /* Set by caller */
    header.methodId   = methodId;
    header.consumerId = consumerId;
    header.sessionId  = sessionId;
    header.msgType    = (uint8)PICC_MSG_RESPONSE;
    header.returnCode = returnCode;

    ret = PICC_ServiceSendMessage(&header, data, len, channelId);
    if (ret != 0) {
        HANDLE_ERROR(-26);  /* Service: ResponseSend failed */
    }
    return ret;
}

/*==================================================================================================
 *                                         Public Functions - Message Processing
 *==================================================================================================*/

/**
 * @brief Process received message
 */
sint8 PICC_ServiceProcessMessage(const PICC_MsgHeader_t *header,
                                 const uint8 *payload, uint16 len,
                                 uint8 instanceId, uint8 channelId)
{
    if (header == NULL) {
        HANDLE_ERROR(-27);  /* Service: ProcessMessage header is NULL */
        return -1;
    }

    switch (header->msgType) {
        /* Event notification */
        case (uint8)PICC_MSG_NOTIFICATION_WITH_ACK:
        case (uint8)PICC_MSG_NOTIFICATION_WITHOUT_ACK:
            return PICC_ServiceHandleEvent(header, payload, len, instanceId, channelId);

        /* Method request */
        case (uint8)PICC_MSG_REQUEST:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK:
            return PICC_ServiceHandleRequest(header, payload, len, instanceId, channelId);

        /* Method response */
        case (uint8)PICC_MSG_RESPONSE:
            return PICC_ServiceHandleResponse(header, payload, len);

        /* ACK messages - handled automatically by middleware, not reported to app layer */
        case (uint8)PICC_MSG_ACK:
        case (uint8)PICC_MSG_EVENT_ACK:
            break;

        /* Note: PICC_MSG_LINK_AVAILABLE is handled by PICC_ProcessSingleMessage in picc_api.c
         * before this function is called, so no need to handle it here. */

        default:
            break;
    }

    return 0;
}

#if defined(__cplusplus)
}
#endif
