/**
 * @file picc_api.c
 * @brief PICC Driver Public API — Implementation
 *
 * Implements the 8 public API functions + internal mailbox for received data.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_api.h"
#include "picc_protocol.h"
#include "picc_stack.h"
#include "picc_heartbeat.h"
#include "picc_trace.h"
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */

/*==================================================================================================
 *                                         Mailbox Configuration
 *==================================================================================================*/

/** Max number of different msgId slots per app per type */
#define PICC_RX_MAX_SLOTS       (4U)

/** Max payload bytes stored per slot */
#define PICC_RX_MAX_DATA_LEN    (32U)

/*==================================================================================================
 *                                         Internal Types
 *==================================================================================================*/

/** Legacy infrastructure config (used internally by PICC_InfraInit) */
typedef struct {
    uint8        linkLocalId;
    uint8        linkRemoteId;
    PICC_Role_e  linkRole;
    uint8        channelId;
} PICC_InfraConfig_t;

/** Single receive slot */
typedef struct {
    boolean  ready;                         /**< New data available */
    uint8    msgId;                         /**< methodId or eventId */
    uint8    returnCode;                    /**< Only for Response type */
    uint8    data[PICC_RX_MAX_DATA_LEN];    /**< Payload data copy */
    uint16   dataLen;                       /**< Actual payload length */
} PICC_RxSlot_t;

/** Per-application mailbox (3 types of incoming messages) */
typedef struct {
    PICC_RxSlot_t method[PICC_RX_MAX_SLOTS];    /**< Method requests (Server receives) */
    PICC_RxSlot_t response[PICC_RX_MAX_SLOTS];  /**< Method responses (Client receives) */
    PICC_RxSlot_t event[PICC_RX_MAX_SLOTS];     /**< Event notifications */
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
 *                                         Forward Declarations
 *==================================================================================================*/

static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 instanceId, uint8 channelId);

static void PICC_HeartbeatTimeoutHandler(uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                                         Internal Helper Functions
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
            for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
                g_rxMailbox[a].method[s].ready = FALSE;
                g_rxMailbox[a].method[s].msgId = 0xFFU;
                g_rxMailbox[a].response[s].ready = FALSE;
                g_rxMailbox[a].response[s].msgId = 0xFFU;
                g_rxMailbox[a].event[s].ready = FALSE;
                g_rxMailbox[a].event[s].msgId = 0xFFU;
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
 * @brief Find appIndex by remoteId (for events: providerId == our remoteId)
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
                              const uint8 *payload, uint16 payloadLen)
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
        /* All slots occupied with different msgIds, overwrite slot 0 */
        freeSlot = 0U;
    }

    copyLen = (payloadLen > PICC_RX_MAX_DATA_LEN) ? PICC_RX_MAX_DATA_LEN : payloadLen;
    slots[freeSlot].msgId = msgId;
    slots[freeSlot].returnCode = returnCode;
    for (s = 0U; s < copyLen; s++) {
        slots[freeSlot].data[s] = payload[s];
    }
    slots[freeSlot].dataLen = payloadLen;
    slots[freeSlot].ready = TRUE;
}

/**
 * @brief Read data from a slot (by msgId). If found and ready, copies data and clears flag.
 * @return PICC_E_OK if data available, PICC_E_NO_DATA if not
 */
static sint8 PICC_ReadFromSlot(PICC_RxSlot_t *slots, uint8 msgId, uint8 *returnCode,
                                uint8 *data, uint16 maxLen, uint16 *actualLen)
{
    uint8 s;
    uint16 copyLen;

    for (s = 0U; s < PICC_RX_MAX_SLOTS; s++) {
        if ((slots[s].msgId == msgId) && (slots[s].ready == TRUE)) {
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
            slots[s].ready = FALSE;  /* Clear flag */
            return PICC_E_OK;
        }
    }
    return PICC_E_NO_DATA;
}

/**
 * @brief Store received message into the appropriate mailbox
 *
 * Called from PICC_ProcessSingleMessage() BEFORE picc_service dispatches.
 */
static void PICC_StoreToMailbox(const PICC_MsgHeader_t *header,
                                 const uint8 *payload, uint16 payloadLen)
{
    uint8 appIdx;

    switch (header->msgType) {
        /* Method Request (Server receives from A-core) */
        case (uint8)PICC_MSG_REQUEST:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITH_ACK:
        case (uint8)PICC_MSG_REQUEST_NO_RETURN_WITHOUT_ACK:
            /* Match by providerId == our localId (Server's ProviderID) */
            appIdx = PICC_FindAppByLocalId(header->providerId);
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreToSlot(g_rxMailbox[appIdx].method,
                                 header->methodId, 0U, payload, payloadLen);
            }
            break;

        /* Method Response (Client receives reply from A-core) */
        case (uint8)PICC_MSG_RESPONSE:
            /* Match by consumerId == our localId (Client's ConsumerID) */
            appIdx = PICC_FindAppByLocalId(header->consumerId);
            if (appIdx == 0xFFU) {
                /* Try remoteId match (Server receiving ACK-type responses) */
                appIdx = PICC_FindAppByRemoteId(header->consumerId);
            }
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreToSlot(g_rxMailbox[appIdx].response,
                                 header->methodId, header->returnCode,
                                 payload, payloadLen);
            }
            break;

        /* Event Notification (receiving Event from A-core) */
        case (uint8)PICC_MSG_NOTIFICATION_WITH_ACK:
        case (uint8)PICC_MSG_NOTIFICATION_WITHOUT_ACK:
            /* Match by providerId == our remoteId (A-core's ProviderID) */
            appIdx = PICC_FindAppByRemoteId(header->providerId);
            if (appIdx == 0xFFU) {
                /* Or match by providerId == our localId */
                appIdx = PICC_FindAppByLocalId(header->providerId);
            }
            if (appIdx < (uint8)PICC_APP_MAX) {
                PICC_StoreToSlot(g_rxMailbox[appIdx].event,
                                 header->methodId, 0U, payload, payloadLen);
            }
            break;

        default:
            /* ACK, EVENT_ACK, ERROR, LINK — not stored in mailbox */
            break;
    }
}

/**
 * @brief Heartbeat timeout handler — triggers link reconnect
 */
static void PICC_HeartbeatTimeoutHandler(uint8 instanceId, uint8 channelId)
{
    PICC_LinkTriggerReconnect(instanceId, channelId);
}

/*==================================================================================================
 *                            Internal Infrastructure Init (called by PICC_PreOS_Init)
 *==================================================================================================*/

/**
 * @brief Initialize PICC infrastructure (trace, service layer, stack callback)
 *
 * This is the old PICC_Init() logic, now internal-only.
 * Called by PICC_PreOS_Init() in picc_main.c.
 */
void PICC_InfraInit(void)
{
    /* 1. Initialize debug trace module */
    PICC_TraceInit();

    /* 2. Initialize service layer registry */
    PICC_ServiceLayerInit();

    /* 3. Register stack layer message callback */
    (void)PICC_StackRegisterMsgCallback(PICC_ProcessSingleMessage);

    /* 4. Initialize app contexts and mailboxes */
    PICC_InitContexts();

    g_piccInfraInit = TRUE;
}

/**
 * @brief Initialize specified IPCF channel (Stack + Heartbeat)
 *
 * Called by PICC_PreOS_Init() for each channel.
 */
sint8 PICC_InitChannel(uint8 instanceId, uint8 channelId)
{
    PICC_StackConfig_t stackCfg;
    sint8 ret;
    static boolean heartbeatInitialized = FALSE;

    /* 1. Initialize heartbeat module on first channel init */
    if (heartbeatInitialized == FALSE) {
        ret = PICC_HeartbeatInit();
        if (ret != 0) {
            return PICC_E_NOT_INIT;
        }
        (void)PICC_HeartbeatRegisterTimeoutCallback(PICC_HeartbeatTimeoutHandler);
        heartbeatInitialized = TRUE;
    }

    /* 2. Initialize Stack layer for this channel */
    stackCfg.channelId  = channelId;
    stackCfg.maxSize    = PICC_STACK_MAX_SIZE;
    stackCfg.periodMs   = PICC_STACK_SEND_PERIOD_MS;
    stackCfg.crcEnabled = PICC_STACK_CRC_ENABLED;
    ret = PICC_StackInitChannel(&stackCfg);
    if (ret != 0) {
        return ret;
    }

    /* 3. Add channel to heartbeat monitoring */
    ret = PICC_HeartbeatAddChannel(instanceId, channelId);
    if (ret != 0) {
        return ret;
    }

    return PICC_E_OK;
}

/*==================================================================================================
 *                              Public API — Initialization
 *==================================================================================================*/

/**
 * @brief Register one application with the PICC driver
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
    if (g_piccInfraInit == FALSE) {
        return PICC_E_NOT_INIT;
    }

    /* Ensure contexts are initialized */
    PICC_InitContexts();

    /* 1. Store config */
    g_appContexts[(uint8)appIndex].config = *config;
    g_appContexts[(uint8)appIndex].isRegistered = TRUE;

    /* 2. Register Link */
    linkCfg.localId    = config->localId;
    linkCfg.remoteId   = config->remoteId;
    linkCfg.role       = config->role;
    linkCfg.channelId  = config->channelId;
    linkCfg.instanceId = IPCF_INSTANCE0;
    linkCfg.isUsed     = TRUE;
    ret = PICC_LinkInit(&linkCfg);
    if (ret != 0) {
        g_appContexts[(uint8)appIndex].isRegistered = FALSE;
        return ret;
    }
    ret = PICC_LinkAddChannel(IPCF_INSTANCE0, config->channelId);
    if (ret != 0) {
        g_appContexts[(uint8)appIndex].isRegistered = FALSE;
        return ret;
    }

    /* 3. Register Link state callback (optional) */
    if (config->linkStateCallback != NULL) {
        (void)PICC_LinkRegisterStateCallback(config->linkStateCallback);
    }

    /* 4. Register Method handler (optional, for immediate callback processing) */
    if (config->methodHandler != NULL) {
        (void)PICC_RegisterMethodHandler(config->localId, config->methodHandler);
    }

    /* 5. Register Event handler (optional, for immediate callback processing) */
    if (config->eventHandler != NULL) {
        (void)PICC_RegisterEventHandler(config->remoteId, config->eventHandler);
    }

    return PICC_E_OK;
}

/*==================================================================================================
 *                              Public API — Sending (M -> A)
 *==================================================================================================*/

/* PICC_SendEvent() is implemented in picc_service.c */

/**
 * @brief Send Method request (Client role)
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId)
{
    if (g_piccInfraInit == FALSE) {
        return 0U;
    }

    if (PICC_LinkGetState(channelId) != PICC_LINK_STATE_CONNECTED) {
        return 0U;
    }

    return PICC_ServiceMethodSend(providerId, methodId, data, len, type, instanceId, channelId);
}

/**
 * @brief Send Method response (Server role)
 */
sint8 PICC_MethodResponse(uint8 consumerId, uint8 methodId,
                          uint8 sessionId, uint8 returnCode,
                          const uint8 *data, uint16 len,
                          uint8 instanceId, uint8 channelId)
{
    if (g_piccInfraInit == FALSE) {
        return PICC_E_NOT_INIT;
    }

    return PICC_ServiceResponseSend(consumerId, methodId, sessionId,
                                    returnCode, data, len, instanceId, channelId);
}

/*==================================================================================================
 *                              Public API — Receiving (A -> M)
 *==================================================================================================*/

/**
 * @brief Get A-core Method request data (Server role)
 */
sint8 PICC_GetMethodData(PICC_AppIndex_e appIndex, uint8 methodId,
                         uint8 *data, uint16 maxLen, uint16 *actualLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }

    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].method,
                             methodId, NULL, data, maxLen, actualLen);
}

/**
 * @brief Get A-core Method response data (Client role)
 */
sint8 PICC_GetResponseData(PICC_AppIndex_e appIndex, uint8 methodId,
                           uint8 *returnCode,
                           uint8 *data, uint16 maxLen, uint16 *actualLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }

    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].response,
                             methodId, returnCode, data, maxLen, actualLen);
}

/**
 * @brief Get A-core Event notification data
 */
sint8 PICC_GetEventData(PICC_AppIndex_e appIndex, uint8 eventId,
                        uint8 *data, uint16 maxLen, uint16 *actualLen)
{
    if ((uint8)appIndex >= (uint8)PICC_APP_MAX) {
        return PICC_E_PARAM;
    }
    if (g_appContexts[(uint8)appIndex].isRegistered == FALSE) {
        return PICC_E_PARAM;
    }

    return PICC_ReadFromSlot(g_rxMailbox[(uint8)appIndex].event,
                             eventId, NULL, data, maxLen, actualLen);
}

/*==================================================================================================
 *                              Public API — Status
 *==================================================================================================*/

/**
 * @brief Get connection state for specified channel
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId)
{
    return PICC_LinkGetState(channelId);
}

/*==================================================================================================
 *                                    Internal: Message Processing
 *==================================================================================================*/

/**
 * @brief Process single decoded message (internal callback registered with Stack)
 *
 * 1. Stores data to mailbox (so apps can poll via PICC_Get*Data)
 * 2. Dispatches to service layer (calls registered callbacks if any)
 */
static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 instanceId, uint8 channelId)
{
    if (header == NULL) {
        return;
    }

    if (header->msgType == (uint8)PICC_MSG_LINK_AVAILABLE) {
        /* Link message — handled by Link layer directly */
        (void)PICC_LinkProcessMessage(header, payload, payloadLen, instanceId, channelId);
    } else {
        /* Store to mailbox FIRST (so polling always works) */
        PICC_StoreToMailbox(header, payload, payloadLen);
        /* Then dispatch to service layer (calls user callbacks if registered) */
        (void)PICC_ServiceProcessMessage(header, payload, payloadLen, instanceId, channelId);
    }
}

/*==================================================================================================
 *                                    Internal: RX Data Entry Point
 *==================================================================================================*/

/**
 * @brief Process received IPCF raw data (called from data_chan_rx_cb in picc_main.c)
 */
sint8 PICC_ProcessRxData(const uint8 instance, uint8 chan_id, const void *buf, uint32 size)
{
    const uint8 *data;
    sint8 ret;

    if (buf == NULL) {
        return PICC_E_PARAM;
    }

    data = (const uint8 *)buf;

    if (size >= PICC_STACK_OVERHEAD_SIZE) {
        ret = PICC_StackProcessRx(data, size, instance, chan_id);
        if (ret >= 0) {
            return PICC_E_OK;
        }
        return PICC_E_PARAM;
    }

    return PICC_E_PARAM;
}

#if defined(__cplusplus)
}
#endif
