/**
 * @file picc_mailbox.h
 * @brief PICC Mailbox Module — Internal Driver Interface
 *
 * Manages per-application receive mailboxes and app registration context.
 * This is an INTERNAL driver header — application layers should NOT include this file.
 * Application layers only include picc_api.h.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_MAILBOX_H
#define PICC_MAILBOX_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_api.h"        /* PICC_AppIndex_e, PICC_AppConfig_t, error codes */
#include "picc_protocol.h"   /* PICC_MsgHeader_t */

/** Maximum callback result size in bytes */
#define PICC_CB_RESULT_MAX_LEN  (8U)

/*==================================================================================================
 *                                  Mailbox Initialization
 *==================================================================================================*/

/**
 * @brief Initialize all app contexts and mailboxes, mark infrastructure ready
 *
 * Called once by PICC_InfraInit() in picc_main.c.
 */
void PICC_MailboxInit(void);

/**
 * @brief Check if infrastructure is initialized
 * @return TRUE if ready, FALSE otherwise
 */
boolean PICC_MailboxIsReady(void);

/*==================================================================================================
 *                                  App Registration
 *==================================================================================================*/

/**
 * @brief Register an application's config in the mailbox context
 *
 * Stores the config so that incoming messages can be routed to the correct mailbox.
 * Called by PICC_Init() in picc_api.c.
 *
 * @param[in] appIndex  Application index
 * @param[in] config    Application configuration
 * @return PICC_E_OK on success, PICC_E_PARAM on invalid index
 */
sint8 PICC_MailboxRegisterApp(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config);

/**
 * @brief Check if an application is registered
 */
boolean PICC_MailboxIsAppRegistered(PICC_AppIndex_e appIndex);

/**
 * @brief Unregister an application (clear registration)
 */
void PICC_MailboxUnregisterApp(PICC_AppIndex_e appIndex);

/**
 * @brief Get a registered application's config
 *
 * @param[in]  appIndex  Application index
 * @param[out] config    Output config pointer
 * @return PICC_E_OK on success, PICC_E_PARAM if not registered or out of range
 */
sint8 PICC_MailboxGetAppConfig(PICC_AppIndex_e appIndex, const PICC_AppConfig_t **config);

/*==================================================================================================
 *                                  Mailbox Store (incoming messages)
 *==================================================================================================*/

/**
 * @brief Store received message into the appropriate mailbox
 *
 * Called from PICC_ProcessSingleMessage() in picc_main.c.
 * Routes message to the correct app's mailbox based on header IDs.
 *
 * @param[in] header      Protocol header
 * @param[in] payload     Message payload
 * @param[in] payloadLen  Payload length
 */
void PICC_StoreToMailbox(const PICC_MsgHeader_t *header,
                          const uint8 *payload, uint16 payloadLen);

/**
 * @brief Store callback result into the mailbox slot that was just written
 *
 * Called from PICC_ProcessSingleMessage() after the callback returns.
 *
 * @param[in] header      Protocol header (used to find the correct slot)
 * @param[in] cbResult    Callback result data
 * @param[in] cbResultLen Callback result length (max PICC_CB_RESULT_MAX_LEN)
 */
void PICC_StoreCallbackResult(const PICC_MsgHeader_t *header,
                               const uint8 *cbResult, uint16 cbResultLen);

/*==================================================================================================
 *                                  Mailbox Read (polling)
 *==================================================================================================*/

/**
 * @brief Read Method request data from mailbox
 *
 * @param[out] cbResult    Optional callback result buffer (NULL to ignore)
 * @param[out] cbResultLen Optional callback result length (NULL to ignore)
 */
sint8 PICC_MailboxGetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                                uint8 *data, uint16 maxLen, uint16 *actualLen,
                                uint8 *cbResult, uint16 *cbResultLen);

/**
 * @brief Read Method response data from mailbox
 *
 * @param[in]  sessionId   Session ID returned by PICC_MethodRequest().
 *                          Used to match the correct async response.
 *                          Pass 0 to match any session (legacy compatible).
 * @param[out] cbResult    Optional callback result buffer (NULL to ignore)
 * @param[out] cbResultLen Optional callback result length (NULL to ignore)
 */
sint8 PICC_MailboxGetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                                  uint8 sessionId, uint8 *returnCode,
                                  uint8 *data, uint16 maxLen, uint16 *actualLen,
                                  uint8 *cbResult, uint16 *cbResultLen);

/**
 * @brief Read Event notification data from mailbox
 *
 * @param[out] cbResult    Optional callback result buffer (NULL to ignore)
 * @param[out] cbResultLen Optional callback result length (NULL to ignore)
 */
sint8 PICC_MailboxGetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                               uint8 *data, uint16 maxLen, uint16 *actualLen,
                               uint8 *cbResult, uint16 *cbResultLen);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_MAILBOX_H */
