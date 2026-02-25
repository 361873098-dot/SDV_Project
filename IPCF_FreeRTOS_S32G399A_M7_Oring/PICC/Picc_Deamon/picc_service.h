/**
 * @file picc_service.h
 * @brief M-Core Inter-Core Communication Service Layer - Interface Definition
 *
 * Implements Event and Method service processing, including auto ACK reply (middleware layer).
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_SERVICE_H
#define PICC_SERVICE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_protocol.h"

/*==================================================================================================
 *                                         Enum Types
 *==================================================================================================*/

/**
 * @brief Method type
 */
typedef enum {
    PICC_METHOD_WITH_RESPONSE           = 0U,  /**< With Response */
    PICC_METHOD_NO_RETURN_WITH_ACK,            /**< No Response, with ACK */
    PICC_METHOD_NO_RETURN_WITHOUT_ACK          /**< No Response, no ACK */
} PICC_MethodType_e;

/**
 * @brief Event type
 */
typedef enum {
    PICC_EVENT_WITH_ACK    = 0U,  /**< With ACK */
    PICC_EVENT_WITHOUT_ACK        /**< No ACK */
} PICC_EventType_e;

/*==================================================================================================
 *                                         Callback Function Types
 *==================================================================================================*/

/**
 * @brief Event receive callback function type
 * 
 * @param[in] providerId  Service provider ID
 * @param[in] eventId     Event ID
 * @param[in] data        Data
 * @param[in] len         Data length
 */
typedef void (*PICC_EventCallback_t)(uint8 providerId, uint8 eventId,
                                     const uint8 *data, uint16 len);

/**
 * @brief Method request callback function type (Server role)
 * 
 * @param[in]  consumerId  Requester ID
 * @param[in]  methodId    Method ID
 * @param[in]  reqData     Request data
 * @param[in]  reqLen      Request data length
 * @param[out] rspData     Response data buffer
 * @param[out] rspLen      Response data length
 * @return Return code @see PICC_ReturnCode_e
 */
typedef uint8 (*PICC_MethodCallback_t)(uint8 consumerId, uint8 methodId,
                                       const uint8 *reqData, uint16 reqLen,
                                       uint8 *rspData, uint16 *rspLen);

/**
 * @brief Method response callback function type (Client role)
 * 
 * @param[in] providerId  Service provider ID
 * @param[in] methodId    Method ID
 * @param[in] sessionId   Session ID
 * @param[in] returnCode  Return code
 * @param[in] rspData     Response data
 * @param[in] rspLen      Response data length
 */
typedef void (*PICC_ResponseCallback_t)(uint8 providerId, uint8 methodId,
                                        uint8 sessionId, uint8 returnCode,
                                        const uint8 *rspData, uint16 rspLen);

/*==================================================================================================
 *                                         Service Registration Limits
 *==================================================================================================*/

/** Maximum number of registered Event handlers */
#define PICC_MAX_EVENT_HANDLERS     (4U)

/** Maximum number of registered Method handlers */
#define PICC_MAX_METHOD_HANDLERS    (4U)

/*==================================================================================================
 *                                         Function Declarations - Internal Init (called by PICC_Init)
 *==================================================================================================*/

/**
 * @brief Initialize service layer (internal use, called by PICC_Init)
 */
void PICC_ServiceLayerInit(void);

/**
 * @brief Deinitialize service layer (internal use)
 */
void PICC_ServiceLayerDeinit(void);

/*==================================================================================================
 *                                         Function Declarations - Send Interface
 *==================================================================================================*/

/* Event sending: use PICC_SendEvent() below */

/**
 * @brief Send Method request (Client role)
 * 
 * @param[in] providerId Service provider ID
 * @param[in] methodId   Method ID
 * @param[in] data       Request data
 * @param[in] len        Request data length
 * @param[in] type       Method type
 * @return Session ID (>0), returns 0 on failure
 */
uint8 PICC_ServiceMethodSend(uint8 providerId, uint8 methodId,
                             const uint8 *data, uint16 len,
                             PICC_MethodType_e type,
                             uint8 instanceId, uint8 channelId);

/**
 * @brief Send Method response (Server role)
 * 
 * @param[in] consumerId Target client ID
 * @param[in] methodId   Method ID
 * @param[in] sessionId  Session ID
 * @param[in] returnCode Return code
 * @param[in] data       Response data
 * @param[in] len        Response data length
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_ServiceResponseSend(uint8 consumerId, uint8 methodId,
                               uint8 sessionId, uint8 returnCode,
                               const uint8 *data, uint16 len,
                               uint8 instanceId, uint8 channelId);

/**
 * @brief Process received message (called by middleware)
 * 
 * Dispatches to corresponding handler based on message type, auto replies ACK.
 * 
 * @param[in] header     Message header
 * @param[in] payload    Payload data
 * @param[in] len        Payload length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_ServiceProcessMessage(const PICC_MsgHeader_t *header,
                                 const uint8 *payload, uint16 len,
                                 uint8 instanceId, uint8 channelId);

/**
 * @brief Register Event receive handler (supports multi-module registration)
 * 
 * @param[in] providerId Target ProviderID (for message routing)
 * @param[in] callback   Callback function
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_RegisterEventHandler(uint8 providerId, PICC_EventCallback_t callback);

/**
 * @brief Register Method request handler (Server role, supports multi-module registration)
 * 
 * @param[in] localProviderId Local module's ProviderID (for matching header.providerId)
 * @param[in] callback        Callback function
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_RegisterMethodHandler(uint8 localProviderId, PICC_MethodCallback_t callback);

/**
 * @brief Register Method response handler (Client role)
 * 
 * @param[in] callback Callback function
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_RegisterResponseHandler(PICC_ResponseCallback_t callback);

/**
 * @brief Send Event notification
 * 
 * @param[in] providerId  Sender's ProviderID
 * @param[in] eventId     Event ID
 * @param[in] consumerId  Target client ID
 * @param[in] data        Data
 * @param[in] len         Data length
 * @param[in] withAck     Whether ACK is needed
 * @param[in] channelId   IPCF channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_SendEvent(uint8 providerId, uint8 eventId, uint8 consumerId,
                     const uint8 *data, uint16 len, PICC_EventType_e withAck,
                     uint8 channelId);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_SERVICE_H */
