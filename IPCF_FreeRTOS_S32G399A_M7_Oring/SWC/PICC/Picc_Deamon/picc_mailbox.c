/**
 * @file picc_mailbox.c
 * @brief PICC Mailbox Module — Implementation
 *
 * Manages per-application receive mailboxes:
 *   - App context storage (registration, config)
 *   - Incoming message routing and slot storage
 *   - Polling read interface for Method/Response/Event data
 *
 * This is an INTERNAL driver module. Application layers do NOT call these
 * functions directly — they use PICC_GetMethodData() etc. from picc_api.h.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_mailbox.h"

/*==================================================================================================
 *                                         Configuration
 *==================================================================================================*/

/** Max number of different msgId slots per app per type */
#define PICC_RX_MAX_SLOTS       (6U)

/** Max payload bytes stored per slot */
#define PICC_RX_MAX_DATA_LEN    (32U)

/*==================================================================================================
 *                                         Internal Types
 *==================================================================================================*/

/** Single receive slot */
typedef struct {
    boolean  ready;                         /**< New data available */
    uint8    msgId;                         /**< methodId or eventId */
    uint8    sessionId;                     /**< Session ID (for async Response matching) */
    uint8    returnCode;                    /**< Only for Response type */
    uint8    data[PICC_RX_MAX_DATA_LEN];    /**< Payload data copy */
    uint16   dataLen;                       /**< Actual payload length */
    uint8    cbResult[PICC_CB_RESULT_MAX_LEN]; /**< Callback-produced result */
    uint16   cbResultLen;                   /**< Callback result length (0 if no callback) */
} PICC_RxSlot_t;

/** Per-application mailbox (3 types of incoming messages) */
typedef struct {
    PICC_RxSlot_t method[PICC_RX_MAX_SLOTS];    /**< Method requests (Server receives) */
    PICC_RxSlot_t response[PICC_RX_MAX_SLOTS];  /**< Method responses (Client receives) */
    PICC_RxSlot_t event[PICC_RX_MAX_SLOTS];     /**< Event notifications */
    uint8 methodVictim;                         /**< Round-robin victim for method slots */
    uint8 responseVictim;                       /**< Round-robin victim for response slots */
    uint8 eventVictim;                          /**< Round-robin victim for event slots */
} PICC_RxMailbox_t;

/** Per-application context */
typedef struct {
    boolean          isRegistered;
    PICC_AppConfig_t config;
} PICC_AppContext_t;

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Whether infrastructure is initialized */
static boolean g_piccInfraInit = FALSE;

/** Per-application context */
static PICC_AppContext_t g_appContexts[PICC_APP_MAX];

/** Per-application receive mailbox */
static PICC_RxMailbox_t g_rxMailbox[PICC_APP_MAX];

/** Whether g_appContexts/g_rxMailbox have been zeroed */
static boolean g_contextsInited = FALSE;

/*==================================================================================================
 *                                         Static Helper Functions
 *==================================================================================================*/

/**
 * @brief Initialize all app contexts and mailboxes (called once)
 */
static void PICC_InitContexts(void)
{
    uint8 a, s;
    if (g_contextsInited == FALSE) {
        for (a = 0U; a < (uint8)PICC_APP_MAX; a++) {
            g_appContexts[a].isRegistered = FALSE;
            g_rxMailbox[a].methodVictim = 0U;
            g_rxMailbox[a].responseVictim = 0U;
            g_rxMailbox[a].eventVictim = 0U;
            for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
                g_rxMailbox[a].method[s].ready = FALSE;
                g_rxMailbox[a].method[s].msgId = 0xFFU;
                g_rxMailbox[a].method[s].sessionId = 0U;
                g_rxMailbox[a].method[s].dataLen = 0U;
                g_rxMailbox[a].method[s].cbResultLen = 0U;
                g_rxMailbox[a].response[s].ready = FALSE;
                g_rxMailbox[a].response[s].msgId = 0xFFU;
                g_rxMailbox[a].response[s].sessionId = 0U;
                g_rxMailbox[a].response[s].dataLen = 0U;
                g_rxMailbox[a].response[s].cbResultLen = 0U;
                g_rxMailbox[a].event[s].ready = FALSE;
                g_rxMailbox[a].event[s].msgId = 0xFFU;
                g_rxMailbox[a].event[s].sessionId = 0U;
                g_rxMailbox[a].event[s].dataLen = 0U;
                g_rxMailbox[a].event[s].cbResultLen = 0U;
            }
        }
        g_contextsInited = TRUE;
    }
}

/**
 * @brief Find appIndex by localId
 * @return appIndex (0..MAX-1) or 0xFF if not found
 */
static uint8 PICC_FindAppByLocalId(uint8 localId)
{
    uint8 i;
    for (i = 0U; i < (uint8)PICC_APP_MAX; i++) {
        if (g_appContexts[i].isRegistered &&
            g_appContexts[i].config.localId == localId) {
            return i;
        }
    }
    return 0xFFU;
}

/**
 * @brief Find appIndex by remoteId
 */
static uint8 PICC_FindAppByRemoteId(uint8 remoteId)
{
    uint8 i;
    for (i = 0U; i < (uint8)PICC_APP_MAX; i++) {
        if (g_appContexts[i].isRegistered &&
            g_appContexts[i].config.remoteId == remoteId) {
            return i;
        }
    }
    return 0xFFU;
}

/**
 * @brief Store data into a slot array (find by msgId, reuse or allocate)
 */
static void PICC_StoreToSlot(PICC_RxSlot_t *slots, uint8 msgId, uint8 returnCode,
                              const uint8 *payload, uint16 payloadLen,
                              uint8 *victimIdx)
{
    uint8 s;
    uint8 freeSlot = 0xFFU;
    uint16 copyLen;

    /* Find existing slot with same msgId, or first free slot */
    for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
        if (slots[s].msgId == msgId) {
            freeSlot = s;
            break;
        }
        if ((freeSlot == 0xFFU) && (slots[s].msgId == 0xFFU)) {
            freeSlot = s;
        }
    }

    if (freeSlot == 0xFFU) {
        /* All slots occupied with different msgIds, evict in round-robin order. */
        freeSlot = *victimIdx;
        *victimIdx = (uint8)((*victimIdx + 1U) % PICC_RX_MAX_SLOTS);
    }

    copyLen = (payloadLen > PICC_RX_MAX_DATA_LEN) ? PICC_RX_MAX_DATA_LEN : payloadLen;
    slots[freeSlot].msgId = msgId;
    slots[freeSlot].sessionId = 0U;    /* Default: no session (Method/Event use msgId only) */
    slots[freeSlot].returnCode = returnCode;
    for (s = 0U; s < copyLen; s++) {
        slots[freeSlot].data[s] = payload[s];
    }
    slots[freeSlot].dataLen = payloadLen;
    slots[freeSlot].cbResultLen = 0U;  /* Clear cbResult, will be filled later if callback exists */
    slots[freeSlot].ready = TRUE;
}

/**
 * @brief Store Response data into a slot array using (msgId + sessionId) as composite key.
 *
 * Unlike PICC_StoreToSlot which matches only by msgId (suitable for Method request
 * and Event where only one outstanding message per ID exists), this function uses
 * both msgId AND sessionId to locate an existing slot. This prevents consecutive
 * async Method responses with the same methodId but different sessionIds from
 * silently overwriting each other.
 *
 * Slot search priority:
 *   1. Exact match: same msgId AND same sessionId -> overwrite (duplicate response)
 *   2. First free slot (msgId == 0xFF)
 *   3. Round-robin eviction if all slots are occupied
 */
static void PICC_StoreResponseToSlot(PICC_RxSlot_t *slots, uint8 msgId,
                                      uint8 sessionId, uint8 returnCode,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 *victimIdx)
{
    uint8 s;
    uint8 freeSlot = 0xFFU;
    uint16 copyLen;

    /* Find existing slot with same (msgId + sessionId), or first free slot */
    for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
        if ((slots[s].msgId == msgId) && (slots[s].sessionId == sessionId)) {
            freeSlot = s;
            break;  /* Exact match: overwrite this slot */
        }
        if ((freeSlot == 0xFFU) && (slots[s].msgId == 0xFFU)) {
            freeSlot = s;
        }
    }

    if (freeSlot == 0xFFU) {
        /* All slots occupied, evict in round-robin order */
        freeSlot = *victimIdx;
        *victimIdx = (uint8)((*victimIdx + 1U) % PICC_RX_MAX_SLOTS);
    }

    copyLen = (payloadLen > PICC_RX_MAX_DATA_LEN) ? PICC_RX_MAX_DATA_LEN : payloadLen;
    slots[freeSlot].msgId = msgId;
    slots[freeSlot].sessionId = sessionId;
    slots[freeSlot].returnCode = returnCode;
    for (s = 0U; s < copyLen; s++) {
        slots[freeSlot].data[s] = payload[s];
    }
    slots[freeSlot].dataLen = payloadLen;
    slots[freeSlot].cbResultLen = 0U;
    slots[freeSlot].ready = TRUE;
}

/**
 * @brief Read data from a slot (by msgId, optionally by sessionId).
 *        If found and ready, copies data + cbResult and clears flag.
 *
 * @param[in] filterSessionId  Session ID filter. 0x00 = match any session (for Method/Event).
 *                              Non-zero = match exact sessionId (for async Response).
 * @return PICC_E_OK if data available, PICC_E_NO_DATA if not
 */
static sint8 PICC_ReadFromSlot(PICC_RxSlot_t *slots, uint8 msgId,
                                uint8 filterSessionId, uint8 *returnCode,
                                uint8 *data, uint16 maxLen, uint16 *actualLen,
                                uint8 *cbResult, uint16 *cbResultLen)
{
    uint8 s;
    uint16 copyLen;

    for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
        if ((slots[s].msgId == msgId) && (slots[s].ready == TRUE)) {
            /* If sessionId filter is non-zero, must also match sessionId */
            if ((filterSessionId != 0U) && (slots[s].sessionId != filterSessionId)) {
                continue;  /* Same methodId but different session, skip */
            }
            /* Found matching slot with new data */
            if (returnCode != NULL) {
                *returnCode = slots[s].returnCode;
            }
            copyLen = (slots[s].dataLen > maxLen) ? maxLen : slots[s].dataLen;
            copyLen = (copyLen > PICC_RX_MAX_DATA_LEN) ? PICC_RX_MAX_DATA_LEN : copyLen;
            if (data != NULL) {
                uint16 i;
                for (i = 0U; i < copyLen; i++) {
                    data[i] = slots[s].data[i];
                }
            }
            if (actualLen != NULL) {
                *actualLen = slots[s].dataLen;
            }
            /* Output callback result if requested */
            if (cbResult != NULL && cbResultLen != NULL) {
                uint16 i;
                uint16 cbCopy = slots[s].cbResultLen;
                if (cbCopy > PICC_CB_RESULT_MAX_LEN) {
                    cbCopy = PICC_CB_RESULT_MAX_LEN;
                }
                for (i = 0U; i < cbCopy; i++) {
                    cbResult[i] = slots[s].cbResult[i];
                }
                *cbResultLen = cbCopy;
            } else if (cbResultLen != NULL) {
                *cbResultLen = 0U;
            }
            slots[s].ready = FALSE;
            slots[s].msgId = 0xFFU;
            slots[s].sessionId = 0U;
            slots[s].returnCode = 0U;
            slots[s].dataLen = 0U;
            slots[s].cbResultLen = 0U;
            return PICC_E_OK;
        }
    }
    return PICC_E_NO_DATA;
}

/*==================================================================================================
 *                                  Public Interface — Initialization
 *==================================================================================================*/

void PICC_MailboxInit(void)
{
    PICC_InitContexts();
    g_piccInfraInit = TRUE;
}

boolean PICC_MailboxIsReady(void)
{
    return g_piccInfraInit;
}

/*==================================================================================================
 *                                  Public Interface — App Registration
 *==================================================================================================*/

sint8 PICC_MailboxRegisterApp(PICC_AppIndex_e appIndex, const PICC_AppConfig_t *config)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (config == NULL) {
        return PICC_E_PARAM;
    }

    g_appContexts[(uint8)appIndex].config = *config;
    g_appContexts[(uint8)appIndex].isRegistered = TRUE;
    return PICC_E_OK;
}

boolean PICC_MailboxIsAppRegistered(PICC_AppIndex_e appIndex)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return FALSE;
    }
    return g_appContexts[(uint8)appIndex].isRegistered;
}

void PICC_MailboxUnregisterApp(PICC_AppIndex_e appIndex)
{
    if ((uint8)appIndex < (uint8)PICC_APP_MAX) {
        g_appContexts[(uint8)appIndex].isRegistered = FALSE;
    }
}

sint8 PICC_MailboxGetAppConfig(PICC_AppIndex_e appIndex, const PICC_AppConfig_t **config)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }
    if (config == NULL) {
        return PICC_E_PARAM;
    }
    *config = &g_appContexts[(uint8)appIndex].config;
    return PICC_E_OK;
}

/*==================================================================================================
 *                                  Public Interface — Store (incoming)
 *==================================================================================================*/

void PICC_StoreToMailbox(const PICC_MsgHeader_t *header,
                          const uint8 *payload, uint16 payloadLen)
{
    uint8 appIdx;

    switch (header->msgType) {
        /* Method Request (Server receives from A-core) */
        case (uint8)PICC_MSG_REQUEST:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK:
            appIdx = PICC_FindAppByLocalId(header->providerId);
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreToSlot(g_rxMailbox[appIdx].method,
                                 header->methodId, 0U, payload, payloadLen,
                                 &g_rxMailbox[appIdx].methodVictim);
            }
            break;

        /* Method Response (Client receives reply from A-core) */
        case (uint8)PICC_MSG_RESPONSE:
            appIdx = PICC_FindAppByLocalId(header->consumerId);
            if (appIdx == 0xFFU) {
                appIdx = PICC_FindAppByRemoteId(header->consumerId);
            }
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreResponseToSlot(g_rxMailbox[appIdx].response,
                                 header->methodId, header->sessionId,
                                 header->returnCode,
                                 payload, payloadLen,
                                 &g_rxMailbox[appIdx].responseVictim);
            }
            break;

        /* Event Notification (receiving Event from A-core) */
        case (uint8)PICC_MSG_NOTIFICATION_WITH_ACK:
        case (uint8)PICC_MSG_NOTIFICATION_WITHOUT_ACK:
            appIdx = PICC_FindAppByRemoteId(header->providerId);
            if (appIdx == 0xFFU) {
                appIdx = PICC_FindAppByLocalId(header->providerId);
            }
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreToSlot(g_rxMailbox[appIdx].event,
                                 header->methodId, 0U, payload, payloadLen,
                                 &g_rxMailbox[appIdx].eventVictim);
            }
            break;

        default:
            /* ACK, EVENT_ACK, ERROR, LINK — not stored in mailbox */
            break;
    }
}

/*==================================================================================================
 *                                  Public Interface — Store Callback Result
 *==================================================================================================*/

void PICC_StoreCallbackResult(const PICC_MsgHeader_t *header,
                               const uint8 *cbResult, uint16 cbResultLen)
{
    uint8 appIdx;
    PICC_RxSlot_t *slots = NULL;
    uint8 msgId;
    uint8 s;
    uint16 copyLen;

    if (header == NULL || cbResult == NULL || cbResultLen == 0U) {
        return;
    }

    switch (header->msgType) {
        case (uint8)PICC_MSG_REQUEST:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK:
            appIdx = PICC_FindAppByLocalId(header->providerId);
            if (appIdx < (uint8)PICC_APP_MAX) {
                slots = g_rxMailbox[appIdx].method;
            }
            break;
        case (uint8)PICC_MSG_NOTIFICATION_WITH_ACK:
        case (uint8)PICC_MSG_NOTIFICATION_WITHOUT_ACK:
            appIdx = PICC_FindAppByRemoteId(header->providerId);
            if (appIdx == 0xFFU) {
                appIdx = PICC_FindAppByLocalId(header->providerId);
            }
            if (appIdx < (uint8)PICC_APP_MAX) {
                slots = g_rxMailbox[appIdx].event;
            }
            break;
        default:
            return;
    }

    if (slots == NULL) {
        return;
    }

    msgId = header->methodId;
    copyLen = (cbResultLen > PICC_CB_RESULT_MAX_LEN) ? PICC_CB_RESULT_MAX_LEN : cbResultLen;

    /* Find the slot that was just written (same msgId, ready=TRUE) */
    for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
        if (slots[s].msgId == msgId && slots[s].ready == TRUE) {
            uint16 i;
            for (i = 0U; i < copyLen; i++) {
                slots[s].cbResult[i] = cbResult[i];
            }
            slots[s].cbResultLen = copyLen;
            break;
        }
    }
}

/*==================================================================================================
 *                                  Public Interface — Read (polling)
 *==================================================================================================*/

sint8 PICC_MailboxGetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                                uint8 *data, uint16 maxLen, uint16 *actualLen,
                                uint8 *cbResult, uint16 *cbResultLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }
    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].method,
                             methodId, 0U, NULL, data, maxLen, actualLen,
                             cbResult, cbResultLen);
}

sint8 PICC_MailboxGetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                                  uint8 sessionId, uint8 *returnCode,
                                  uint8 *data, uint16 maxLen, uint16 *actualLen,
                                  uint8 *cbResult, uint16 *cbResultLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }
    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].response,
                             methodId, sessionId, returnCode, data, maxLen, actualLen,
                             cbResult, cbResultLen);
}

sint8 PICC_MailboxGetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                               uint8 *data, uint16 maxLen, uint16 *actualLen,
                               uint8 *cbResult, uint16 *cbResultLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }
    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].event,
                             eventId, 0U, NULL, data, maxLen, actualLen,
                             cbResult, cbResultLen);
}

#if defined(__cplusplus)
}
#endif
