/**
 * @file picc_link.c
 * @brief M-Core Inter-Core Communication Link Management Layer - Implementation
 *
 * Implements per-app connection request/response and disconnect notification.
 * Each registered application (ProviderID/ConsumerID pair) independently
 * maintains its own connection state, handshake, and reconnection logic.
 *
 * Note: Heartbeat (Ping/Pong) is in picc_heartbeat.c
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_link.h"
#include "FreeRTOS.h"
#include "Picc_main.h" /* For PICC_HANDLE_ERROR */
#include "ipc-shm.h"
#include "ipcf_Ip_Cfg_Defines.h" /* For IPCF_INSTANCE0 */
#include "picc_stack.h"
#include "picc_heartbeat.h" /* For PICC_HeartbeatGetMissCount */
#include "task.h" /* For taskENTER_CRITICAL, taskEXIT_CRITICAL */

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Send flow control: maximum backoff value (100 * 10ms = 1000ms) */
#define PICC_SEND_BACKOFF_MAX       (100U)

/** Send flow control: backoff increment (number of periods added on each buffer full) */
#define PICC_SEND_BACKOFF_INCREMENT (10U)

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Link context array — one slot per registered application */
static PICC_LinkContext_t g_linkContexts[PICC_MAX_LINK_APPS];

/*==================================================================================================
 *                                         Private Function Declarations
 *==================================================================================================*/
static PICC_LinkContext_t* PICC_GetLinkContextByIds(uint8 localId, uint8 remoteId);
static PICC_LinkContext_t* PICC_GetLinkContextByHeader(uint8 providerId, uint8 consumerId, uint8 channelId);

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Get link context by local/remote ID pair
 *
 * Used for internal state queries (e.g., PICC_LinkGetStateByIds).
 */
static PICC_LinkContext_t* PICC_GetLinkContextByIds(uint8 localId, uint8 remoteId)
{
    uint32 i;
    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        if ((g_linkContexts[i].config.isUsed != FALSE) &&
            (g_linkContexts[i].config.localId == localId) &&
            (g_linkContexts[i].config.remoteId == remoteId)) {
            return &g_linkContexts[i];
        }
    }
    return NULL;
}

/**
 * @brief Get link context by protocol header ProviderID/ConsumerID + channelId
 *
 * Used when processing received messages. The mapping between header fields
 * and local/remote IDs depends on the app's role:
 *   - SERVER: localId = ProviderID, remoteId = ConsumerID
 *   - CLIENT: localId = ConsumerID, remoteId = ProviderID
 *
 * @param[in] providerId ProviderID from received message header
 * @param[in] consumerId ConsumerID from received message header
 * @param[in] channelId  IPCF channel the message was received on
 * @return Matching context, or NULL if not found
 */
static PICC_LinkContext_t* PICC_GetLinkContextByHeader(uint8 providerId, uint8 consumerId, uint8 channelId)
{
    uint32 i;
    PICC_LinkContext_t *ctx;

    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        ctx = &g_linkContexts[i];
        if (ctx->config.isUsed == FALSE) {
            continue;
        }
        if (ctx->config.channelId != channelId) {
            continue;
        }

        if (ctx->config.role == PICC_ROLE_SERVER) {
            /* SERVER: localId = ProviderID, remoteId = ConsumerID */
            if ((ctx->config.localId == providerId) &&
                (ctx->config.remoteId == consumerId)) {
                return ctx;
            }
        } else {
            /* CLIENT: localId = ConsumerID, remoteId = ProviderID */
            if ((ctx->config.localId == consumerId) &&
                (ctx->config.remoteId == providerId)) {
                return ctx;
            }
        }
    }
    return NULL;
}

/**
 * @brief Send link related message (unified through Stack stacking)
 *
 * @note [R7] All sent messages go through Stack, ensuring CRC+Counter protection
 */
static sint8 PICC_LinkSendMessage(uint8 providerId, uint8 consumerId,
                                  PICC_LinkSubType_e subType, uint8 returnCode,
                                  uint8 instanceId, uint8 channelId)
{
    uint8 txBuf[PICC_HEADER_SIZE + sizeof(PICC_LinkPayload_t)];
    PICC_MsgHeader_t header;
    PICC_LinkPayload_t linkPayload;
    uint32 packedLen;

    (void)instanceId;  /* Currently Stack uses fixed IPCF_INSTANCE0 */

    /* [Fix] Check if remote is ready before sending, prevent errors when A-Core not started.
     * However, for responses (confirmed messages) or disconnects, we should still attempt sending
     * to ensure the link state is synchronized, even if the remote side is already shutting down.
     */
    if (ipc_shm_is_remote_ready(IPCF_INSTANCE0) != 0) {
        if ((returnCode != (uint8)PICC_RET_OK) && (subType == PICC_LINK_CONNECT)) {
            /* Not a response and not a disconnect - skip sending */
            return -10;
        }
    }

    /* Construct protocol header */
    header.providerId = providerId;
    header.methodId   = PICC_LINK_METHOD_ID;
    header.consumerId = consumerId;
    header.sessionId  = 0x00U;
    header.msgType    = (uint8)PICC_MSG_LINK_AVAILABLE;
    header.returnCode = returnCode;

    /* Construct Payload */
    linkPayload.subType   = (uint8)subType;
    linkPayload.clientId  = consumerId;
    linkPayload.mediaType = (uint8)PICC_MEDIA_IPCF;
    linkPayload.serverId  = providerId;

    /* Pack message */
    packedLen = PICC_PackMessage(txBuf, sizeof(txBuf), &header,
                                 (const uint8 *)&linkPayload, sizeof(PICC_LinkPayload_t));
    if (packedLen == 0U) {
        PICC_HANDLE_ERROR(-1);  /* Failed to pack link message */
        return -1;
    }

    /* Unified sending through Stack, auto adds CRC+Counter */
    return PICC_StackAddMessageToChannel(channelId, txBuf, packedLen);
}

/**
 * @brief Update connection state (critical section protected)
 */
static void PICC_LinkSetState(PICC_LinkContext_t *ctx, PICC_LinkState_e newState)
{
    taskENTER_CRITICAL();
    ctx->state = newState;
    taskEXIT_CRITICAL();
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Link process - called from PICC periodic task (10ms)
 *
 * Iterates all registered app link contexts.
 * For each CLIENT app in CONNECTING state, sends connection request
 * at the app's configured period (Client_linkReq_PeriodMs).
 *
 * SERVER apps do nothing here — they are purely passive.
 */
void PICC_LinkProcess(void)
{
    uint32 i;
    PICC_LinkContext_t *ctx;

    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        ctx = &g_linkContexts[i];

        if ((ctx->config.isUsed == FALSE) || (ctx->isInitialized == FALSE)) {
            continue;
        }

        /* Only CLIENT role in CONNECTING state sends connection requests */
        if ((ctx->config.role == PICC_ROLE_CLIENT) &&
            (ctx->state == PICC_LINK_STATE_CONNECTING)) {

            /* Per-app period timing */
            uint16 periodTicks;
            sint8 sendResult;

            ctx->periodCounter++;

            /* Calculate period in 10ms ticks */
            if (ctx->config.Client_linkReq_PeriodMs == 0U) {
                periodTicks = PICC_LINK_REQUEST_PERIOD_MS / 10U;
            } else {
                periodTicks = ctx->config.Client_linkReq_PeriodMs / 10U;
            }
            if (periodTicks == 0U) {
                periodTicks = 1U; /* Minimum 10ms */
            }

            if (ctx->periodCounter >= periodTicks) {
                ctx->periodCounter = 0U;

                /* [Flow control] If backoff count exists, skip this send */
                if (ctx->backoffCounter > 0U) {
                    ctx->backoffCounter--;
                } else {
                    /* Send connection request:
                     * ProviderID = remoteId (A-Core Server's ID)
                     * ConsumerID = localId  (M-Core Client's own ID)
                     */
                    sendResult = PICC_LinkSendMessage(
                        ctx->config.remoteId,   /* ProviderID */
                        ctx->config.localId,    /* ConsumerID */
                        PICC_LINK_CONNECT,
                        (uint8)PICC_RET_NOT_OK, /* ReturnCode=0x01 request */
                        ctx->config.instanceId,
                        ctx->config.channelId);

                    /* [Flow control - Per-app Exponential Backoff]
                     * Doubles backoff on each failure, capped at maximum.
                     * Sequence: 10→20→40→80→100 (100ms→200ms→400ms→800ms→1000ms)
                     */
                    if (sendResult != 0) {
                        if (ctx->backoffCounter == 0U) {
                            ctx->backoffCounter = PICC_SEND_BACKOFF_INCREMENT;
                        } else {
                            ctx->backoffCounter = ctx->backoffCounter * 2U;
                            if (ctx->backoffCounter > PICC_SEND_BACKOFF_MAX) {
                                ctx->backoffCounter = PICC_SEND_BACKOFF_MAX;
                            }
                        }
                    } else {
                        ctx->backoffCounter = 0U;
                    }
                }
            }
        }
        /* SERVER role: do nothing, purely passive */
    }
}

/**
 * @brief One-time initialization of the link management layer
 *
 * Clears all link app contexts. Must be called once during
 * PICC_InfraInit() before any PICC_Init()/PICC_LinkRegisterApp() calls.
 */
void PICC_LinkLayerInit(void)
{
    uint32 i;

    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        g_linkContexts[i].config.isUsed = FALSE;
        g_linkContexts[i].isInitialized = FALSE;
        g_linkContexts[i].state = PICC_LINK_STATE_DISCONNECTED;
        g_linkContexts[i].periodCounter = 0U;
        g_linkContexts[i].backoffCounter = 0U;
    }
}

/**
 * @brief Register a single application link context
 *
 * Finds a free slot and registers one app's link context.
 * Does NOT clear or affect any other registered apps.
 *
 * [R5] Role auto-start mechanism:
 *   - CLIENT: Auto enters CONNECTING state, PICC_LinkProcess will
 *             periodically send connection requests
 *   - SERVER: Stays in DISCONNECTED state, passively listens for
 *             Client connection requests from A-Core
 *
 * @param[in] config Link configuration for this app
 * @return 0 on success, -1 on failure (no free slot or bad param)
 */
sint8 PICC_LinkRegisterApp(const PICC_LinkConfig_t *config)
{
    uint32 i;
    sint8 slot = -1;

    if (config == NULL) {
        PICC_HANDLE_ERROR(-1);
        return -1;
    }

    /* Check if already registered (same localId + remoteId) */
    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        if ((g_linkContexts[i].config.isUsed != FALSE) &&
            (g_linkContexts[i].config.localId == config->localId) &&
            (g_linkContexts[i].config.remoteId == config->remoteId)) {
            /* Already registered, update config and return success */
            g_linkContexts[i].config = *config;
            g_linkContexts[i].config.isUsed = TRUE;
            return 0;
        }
        /* Record first free slot */
        if ((slot == -1) && (g_linkContexts[i].config.isUsed == FALSE)) {
            slot = (sint8)i;
        }
    }

    if (slot == -1) {
        PICC_HANDLE_ERROR(-4);  /* No free slot for link app */
        return -1;
    }

    /* Register this app's link context */
    g_linkContexts[slot].config = *config;
    g_linkContexts[slot].config.isUsed = TRUE;
    g_linkContexts[slot].periodCounter = 0U;
    g_linkContexts[slot].backoffCounter = 0U;

    /* [R5] Role auto-start mechanism */
    if (config->role == PICC_ROLE_CLIENT) {
        g_linkContexts[slot].state = PICC_LINK_STATE_CONNECTING;
    } else {
        g_linkContexts[slot].state = PICC_LINK_STATE_DISCONNECTED;
    }

    g_linkContexts[slot].isInitialized = TRUE;

    return 0;
}

/**
 * @brief Deinitialize link management layer
 */
void PICC_LinkDeinit(void)
{
    uint32 i;

    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        g_linkContexts[i].isInitialized = FALSE;
        g_linkContexts[i].config.isUsed = FALSE;
        g_linkContexts[i].state = PICC_LINK_STATE_DISCONNECTED;
        g_linkContexts[i].periodCounter = 0U;
        g_linkContexts[i].backoffCounter = 0U;
    }
}

/**
 * @brief Handle connection response (Client role)
 *
 * Called when M-Core is acting as CLIENT and receives a connection
 * response from A-Core SERVER.
 *
 * Message Flow:
 *   1. CLIENT (M-Core) sends LINK_CONNECT request with ReturnCode=0x01
 *   2. SERVER (A-Core) receives request, replies with ReturnCode=0x00 (agree)
 *   3. CLIENT receives response -> this function is called
 *   4. CLIENT updates state to CONNECTED if ReturnCode=0x00
 *
 * @note This function does NOT send any message, it only processes the
 *       incoming response and updates the local connection state.
 */
sint8 PICC_LinkHandleResponse(const PICC_MsgHeader_t *header,
                              const uint8 *payload, uint16 len,
                              uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;

    (void)len;
    (void)instanceId;

    if ((header == NULL) || (payload == NULL)) {
        PICC_HANDLE_ERROR(-6);
        return -1;
    }

    linkPayload = (const PICC_LinkPayload_t *)payload;

    /* Find matching app context by header IDs */
    ctx = PICC_GetLinkContextByHeader(header->providerId, header->consumerId, channelId);
    if ((ctx != NULL) && (ctx->config.role == PICC_ROLE_CLIENT)) {
        /* Check if this is a connection response */
        if (linkPayload->subType == (uint8)PICC_LINK_CONNECT) {
            if (header->returnCode == (uint8)PICC_RET_OK) {
                PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTED);
            } else {
                PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
            }
        }
    }

    return 0;
}

/**
 * @brief Handle incoming connection request (Server role)
 *
 * Called when M-Core is acting as SERVER and receives a connection
 * request from A-Core CLIENT.
 *
 * Message Flow:
 *   1. CLIENT (A-Core) sends LINK_CONNECT request with ReturnCode=0x01
 *   2. SERVER (M-Core) receives request -> this function is called
 *   3. SERVER sends LINK_CONNECT response with ReturnCode=0x00 (agree)
 *   4. SERVER updates state to CONNECTED
 *
 * @note Per [R5]: Server stays in DISCONNECTED state after startup, passively
 *       listening for Client connection requests.
 */
sint8 PICC_LinkHandleRequest(const PICC_MsgHeader_t *header,
                             const uint8 *payload, uint16 len,
                             uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;
    sint8 ret;

    (void)len;
    (void)instanceId;

    if ((header == NULL) || (payload == NULL)) {
        PICC_HANDLE_ERROR(-7);
        return -1;
    }

    linkPayload = (const PICC_LinkPayload_t *)payload;

    if (linkPayload->subType == (uint8)PICC_LINK_CONNECT) {

        /* Find matching app context by header IDs */
        ctx = PICC_GetLinkContextByHeader(header->providerId, header->consumerId, channelId);
        if ((ctx != NULL) && (ctx->config.role == PICC_ROLE_SERVER)) {

            /* Send connection response - agree to connect */
            ret = PICC_LinkSendMessage(ctx->config.localId,  /* ProviderID = Server's localId */
                                       header->consumerId,    /* ConsumerID */
                                       PICC_LINK_CONNECT,
                                       (uint8)PICC_RET_OK,
                                       ctx->config.instanceId,
                                       ctx->config.channelId);
            if (ret == 0) {
                PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTED);
            } else {
                PICC_HANDLE_ERROR(-8);  /* Failed to send link response */
            }
        }
    }

    return 0;
}

/**
 * @brief Handle incoming disconnect notification or reconnect request
 *
 * Called when M-Core receives a disconnect/reconnect message from A-Core,
 * regardless of whether M-Core is CLIENT or SERVER.
 *
 * Disconnect Flow (A-Core APP exits):
 *   1. A-Core PICC Daemon detects APP exit
 *   2. A-Core sends LINK_DISCONNECT with ReturnCode=0x01
 *   3. M-Core receives notification -> this function is called
 *   4. M-Core replies LINK_DISCONNECT with ReturnCode=0x00 (confirm)
 *   5. If M-Core is CLIENT: auto enters CONNECTING state to reconnect
 *      If M-Core is SERVER: stays in DISCONNECTED, waits for CLIENT
 *
 * Reconnect Flow (A-Core Daemon restarts, A-Core is SERVER):
 *   1. A-Core Daemon crashes and restarts
 *   2. A-Core SERVER sends LINK_RECONNECT notification
 *   3. M-Core CLIENT receives -> this function is called
 *   4. M-Core CLIENT re-enters CONNECTING state to send new requests
 *
 * @note Per [R5]: CLIENT will keep retrying connection requests, so resources
 *       can be safely released on disconnect.
 * @note M-Core never actively sends disconnect notifications per protocol.
 */
sint8 PICC_LinkHandleDisconnect(const PICC_MsgHeader_t *header,
                                const uint8 *payload, uint16 len,
                                uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;

    (void)len;
    (void)instanceId;

    if (payload == NULL) {
        PICC_HANDLE_ERROR(-10);
        return -1;
    }
    linkPayload = (const PICC_LinkPayload_t *)payload;

    /* Find matching app context by header IDs (idMatch is done inside) */
    ctx = PICC_GetLinkContextByHeader(header->providerId, header->consumerId, channelId);
    if (ctx == NULL) {
        /* Not for any registered app, ignore silently */
        return 0;
    }

    if (linkPayload->subType == (uint8)PICC_LINK_DISCONNECT) {

        /* [R5] Received disconnect notification (ReturnCode usually 0x01) */
        /* 1. Set state to disconnected */
        PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);

        /* 2. Reply disconnect confirmation (ReturnCode=0x00) */
        /* Protocol: ProviderID/ConsumerID stay the same for the pairing */
        (void)PICC_LinkSendMessage(header->providerId,  /* Keep Provider ID */
                                   header->consumerId,  /* Keep Consumer ID */
                                   PICC_LINK_DISCONNECT,
                                   (uint8)PICC_RET_OK,  /* Confirm: 0x00 */
                                   IPCF_INSTANCE0, channelId);

        /* [R5] After disconnect, CLIENT should auto-reconnect */
        if (ctx->config.role == PICC_ROLE_CLIENT) {
            PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
            ctx->periodCounter = 0U;
            ctx->backoffCounter = 0U;
        }

    } else if (linkPayload->subType == (uint8)PICC_LINK_RECONNECT) {
        PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
        if (ctx->config.role == PICC_ROLE_CLIENT) {
            PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
            ctx->periodCounter = 0U;
            ctx->backoffCounter = 0U;
        }
    }

    return 0;
}

/**
 * @brief Get current connection state for physical channel (heartbeat-based)
 *
 * Returns CONNECTED if the heartbeat on the specified channel is alive
 * (miss count < timeout threshold), DISCONNECTED otherwise.
 *
 * @note This is for physical channel health, NOT for per-app connection state.
 *       Use PICC_LinkGetStateByIds() for per-app state.
 */
PICC_LinkState_e PICC_LinkGetState(uint8 channelId)
{
    uint8 missCount;

    missCount = PICC_HeartbeatGetMissCount(IPCF_INSTANCE0, channelId);
    if (missCount < PICC_HEARTBEAT_TIMEOUT_COUNT) {
        return PICC_LINK_STATE_CONNECTED;
    }
    return PICC_LINK_STATE_DISCONNECTED;
}

/**
 * @brief Get application-level link state by ID pair
 *
 * @param[in] localId  Local ID (ProviderID for Server, ConsumerID for Client)
 * @param[in] remoteId Remote ID (peer's ID)
 * @return Connection state for the specified app pair
 */
PICC_LinkState_e PICC_LinkGetStateByIds(uint8 localId, uint8 remoteId)
{
    PICC_LinkContext_t *ctx = PICC_GetLinkContextByIds(localId, remoteId);
    if (ctx != NULL) {
        return ctx->state;
    }
    return PICC_LINK_STATE_DISCONNECTED;
}

/**
 * @brief Trigger reconnect on all apps on specified channel (called by heartbeat on timeout)
 *
 * [R6] On heartbeat timeout, the physical channel is considered faulty.
 * All apps on that channel must transition:
 *   - CLIENT: Set to CONNECTING state to trigger auto reconnect
 *   - SERVER: Set to DISCONNECTED state and wait for CLIENT to reconnect
 */
void PICC_LinkTriggerReconnect(uint8 instanceId, uint8 channelId)
{
    uint32 i;
    PICC_LinkContext_t *ctx;

    (void)instanceId;

    for (i = 0U; i < PICC_MAX_LINK_APPS; i++) {
        ctx = &g_linkContexts[i];

        if (ctx->config.isUsed == FALSE) {
            continue;
        }
        if (ctx->config.channelId != channelId) {
            continue;
        }

        if (ctx->config.role == PICC_ROLE_CLIENT) {
            PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
            ctx->periodCounter = 0U;
            ctx->backoffCounter = 0U;
        } else {
            /* SERVER: Set to DISCONNECTED, wait for CLIENT to reconnect */
            PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
        }
    }
}

/**
 * @brief Process received link management message (dispatch by subType)
 *
 * Finds the target app context by matching ProviderID/ConsumerID from the
 * message header, then dispatches to the appropriate handler based on the
 * link subType and the app's role.
 */
sint8 PICC_LinkProcessMessage(const PICC_MsgHeader_t *header,
                              const uint8 *payload, uint16 len,
                              uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;

    if ((header == NULL) || (payload == NULL)) {
        PICC_HANDLE_ERROR(-11);
        return -1;
    }

    /* [FIX] Disconnect notification only has 1 or 2 bytes payload.
     * Only CONNECT requires the full PICC_LinkPayload_t (4 bytes). */
    if (len < 1U) {
        PICC_HANDLE_ERROR(-12);
        return -1;
    }

    linkPayload = (const PICC_LinkPayload_t *)payload;

    /* Find matching app context by header IDs */
    ctx = PICC_GetLinkContextByHeader(header->providerId, header->consumerId, channelId);
    if (ctx == NULL) {
        /* No matching app registered for this ProviderID/ConsumerID pair, ignore */
        return 0;
    }

    switch (linkPayload->subType) {
        case (uint8)PICC_LINK_CONNECT:
            if (ctx->config.role == PICC_ROLE_SERVER) {
                /* Server receives Connection Request from A-Core Client */
                return PICC_LinkHandleRequest(header, payload, len, instanceId, channelId);
            } else {
                /* Client receives Connection Response from A-Core Server */
                return PICC_LinkHandleResponse(header, payload, len, instanceId, channelId);
            }

        case (uint8)PICC_LINK_DISCONNECT:
        case (uint8)PICC_LINK_RECONNECT:
            return PICC_LinkHandleDisconnect(header, payload, len, instanceId, channelId);

        default:
            /* Unknown subType */
            break;
    }

    return 0;
}

#if defined(__cplusplus)
}
#endif
