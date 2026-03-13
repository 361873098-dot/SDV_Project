/**
 * @file picc_link.c
 * @brief M-Core Inter-Core Communication Link Management Layer - Implementation
 *
 * Implements connection request/response and disconnect notification.
 * Note: Heartbeat (Ping/Pong) is now in picc_heartbeat.c
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_link.h"
#include "FreeRTOS.h"
#include "Picc_main.h" /* For HANDLE_ERROR */
#include "ipc-shm.h"
#include "ipcf_Ip_Cfg_Defines.h" /* For IPCF_INSTANCE0 */
#include "picc_stack.h"
#include "task.h" /* For taskENTER_CRITICAL, taskEXIT_CRITICAL */

/* NOTE: timers.h removed - no longer using FreeRTOS timers */

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Link context array */
static PICC_LinkContext_t g_linkContexts[PICC_MAX_CHANNELS];

/** State change callback */
static PICC_LinkStateCallback_t g_stateCallback = NULL;

/** Send flow control: backoff counter (incremented when buffer full, used to reduce send frequency) */
static uint8 g_sendBackoffCounter = 0U;

/** Send flow control: maximum backoff value (100 * 10ms = 1000ms) */
#define PICC_SEND_BACKOFF_MAX       (100U)

/** Send flow control: backoff increment (number of periods added on each buffer full) */
#define PICC_SEND_BACKOFF_INCREMENT (10U)

/*==================================================================================================
 *                                         Private Function Declarations
 *==================================================================================================*/
static PICC_LinkContext_t* PICC_GetLinkContext(uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Get context by Channel ID
 */
static PICC_LinkContext_t* PICC_GetLinkContext(uint8 instanceId, uint8 channelId)
{
    uint32 i;
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        if (g_linkContexts[i].config.isUsed != FALSE && 
            g_linkContexts[i].config.instanceId == instanceId &&
            g_linkContexts[i].config.channelId == channelId) {
            return &g_linkContexts[i];
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
        HANDLE_ERROR(-1);  /* Failed to pack link message */
        return -1;
    }

    /* Unified sending through Stack, auto adds CRC+Counter */
    return PICC_StackAddMessageToChannel(channelId, txBuf, packedLen);
}

/**
 * @brief Update connection state
 */
static void PICC_LinkSetState(PICC_LinkContext_t *ctx, PICC_LinkState_e newState)
{
    PICC_LinkState_e oldState;
    boolean stateChanged = FALSE;
    
    /* [FIX] Use critical section to atomically check-and-update state */
    taskENTER_CRITICAL();
    oldState = ctx->state;
    if (oldState != newState) {
        ctx->state = newState;
        stateChanged = TRUE;
    }
    taskEXIT_CRITICAL();
    
    /* Call callback outside critical section to avoid potential deadlock */
    if (stateChanged && g_stateCallback != NULL) {
        /* Pass channelId or RemoteId, still passing RemoteId here */
        g_stateCallback(ctx->config.remoteId, newState);
    }
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Link process - called from PICC periodic task (10ms)
 * 
 * Handles connection requests (10ms)
 * Replaces the timer-based approach.
 */
void PICC_LinkProcess(void)
{
    uint32 i;
    PICC_LinkContext_t *ctx;

    /* Iterate through all active channels */
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        ctx = &g_linkContexts[i];
        
        if (ctx->config.isUsed == FALSE || ctx->isInitialized == FALSE) {
            continue;
        }

        /* Handle connection requests (Client role only and in CONNECTING state) */
        if ((ctx->config.role == PICC_ROLE_CLIENT) && 
            (ctx->state == PICC_LINK_STATE_CONNECTING)) {
            
            /* [Flow control] If backoff count exists, skip this send */
            if (g_sendBackoffCounter > 0U) {
                g_sendBackoffCounter--;
            } else {
                /* Send connection request */
                sint8 sendResult = PICC_LinkSendMessage(ctx->config.remoteId,
                                                        ctx->config.localId,
                                                        PICC_LINK_CONNECT,
                                                        (uint8)PICC_RET_NOT_OK,
                                                        ctx->config.instanceId,
                                                        ctx->config.channelId);
                
                /* [Flow control - Hybrid Exponential Backoff]
                 * Doubles backoff on each failure, capped at maximum.
                 * Sequence: 10→20→40→80→100 (100ms→200ms→400ms→800ms→1000ms)
                 * Balances quick initial retries with longer waits for persistent failures.
                 */
                if (sendResult != 0) {
                    if (g_sendBackoffCounter == 0U) {
                        /* First failure - start with base increment */
                        g_sendBackoffCounter = PICC_SEND_BACKOFF_INCREMENT;
                    } else {
                        /* Subsequent failures - double the backoff */
                        g_sendBackoffCounter = g_sendBackoffCounter * 2U;
                        
                        /* Cap at maximum to prevent overflow */
                        if (g_sendBackoffCounter > PICC_SEND_BACKOFF_MAX) {
                            g_sendBackoffCounter = PICC_SEND_BACKOFF_MAX;
                        }
                    }
                } else {
                    /* Send succeeded - reset backoff counter for clean slate */
                    g_sendBackoffCounter = 0U;
                }
            }
        }
    }
}

/**
 * @brief Initialize link management layer
 */
sint8 PICC_LinkInit(const PICC_LinkConfig_t *config)
{
    uint32 i;

    if (config == NULL) {
        HANDLE_ERROR(-1);  /* Link config parameter is NULL */
        return -1;
    }

    /* Clear all contexts */
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        g_linkContexts[i].config.isUsed = FALSE;
        g_linkContexts[i].isInitialized = FALSE;
        g_linkContexts[i].state = PICC_LINK_STATE_DISCONNECTED;
    }

    /* Initialize first channel */
    g_linkContexts[0].config = *config;
    g_linkContexts[0].config.isUsed = TRUE;
    
    /* [R5] Role auto-start mechanism:
     * - CLIENT: Auto enters CONNECTING state, timer will periodically send connection requests
     * - SERVER: Stays in DISCONNECTED state, passively listens for Client connection requests
     */
    if (config->role == PICC_ROLE_CLIENT) {
        g_linkContexts[0].state = PICC_LINK_STATE_CONNECTING;
    } else {
        g_linkContexts[0].state = PICC_LINK_STATE_DISCONNECTED;
    }
    
    g_linkContexts[0].isInitialized = TRUE;

    /* NOTE: Timer removed - PICC_LinkProcess() is called from PICC_PeriodicTask */
    return 0;
}

/**
 * @brief Add additional communication channel
 */
sint8 PICC_LinkAddChannel(uint8 instanceId, uint8 channelId)
{
    uint32 i;
    sint8 slot = -1;
    
    /* Check if already exists */
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        if (g_linkContexts[i].config.isUsed != FALSE && 
            g_linkContexts[i].config.instanceId == instanceId &&
            g_linkContexts[i].config.channelId == channelId) {
            return 0; /* Already exists, return success */
        }
        /* Record first free slot */
        if (slot == -1 && g_linkContexts[i].config.isUsed == FALSE) {
            slot = (sint8)i;
        }
    }

    if (slot == -1) {
        HANDLE_ERROR(-4);  /* No free slot for link channel */
        return -1; /* No free slot */
    }

    /* Reuse first channel's config, only modify channel/instance */
    /* Assume at least one channel is initialized (LinkInit called) */
    if (g_linkContexts[0].isInitialized == FALSE) {
        HANDLE_ERROR(-5);  /* Primary link channel not initialized */
        return -2;
    }
    
    g_linkContexts[slot].config = g_linkContexts[0].config;
    g_linkContexts[slot].config.instanceId = instanceId;
    g_linkContexts[slot].config.channelId = channelId;
    g_linkContexts[slot].config.isUsed = TRUE;
    
    g_linkContexts[slot].state = PICC_LINK_STATE_DISCONNECTED;
    g_linkContexts[slot].isInitialized = TRUE;
    
    /* [FIX] Additional channels do NOT participate in Link management.
     * Only the primary channel (initialized via PICC_LinkInit) sends Link requests.
     * Additional channels are for data transfer only and share the link state 
     * with the primary channel.
     * 
     * Do NOT set state to CONNECTING here - this prevents Link requests 
     * from being sent on this channel.
     */

    return 0;
}

/**
 * @brief Deinitialize link management layer
 */
void PICC_LinkDeinit(void)
{
    uint32 i;
    
    /* NOTE: Timer removed - no timer cleanup needed */
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        g_linkContexts[i].isInitialized = FALSE;
        g_linkContexts[i].config.isUsed = FALSE;
        g_linkContexts[i].state = PICC_LINK_STATE_DISCONNECTED;
    }
    
    g_stateCallback = NULL;
}

/**
 * @brief Send connection request (Client role)
 */
sint8 PICC_LinkSendRequest(void)
{
    uint32 i;
    sint8 ret = 0;

    /* Iterate through all Client role channels to initiate connection */
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        if (g_linkContexts[i].config.isUsed != FALSE && 
            g_linkContexts[i].config.role == PICC_ROLE_CLIENT) {
            
            PICC_LinkSetState(&g_linkContexts[i], PICC_LINK_STATE_CONNECTING);
            
            if (PICC_LinkSendMessage(g_linkContexts[i].config.remoteId,
                                     g_linkContexts[i].config.localId,
                                     PICC_LINK_CONNECT,
                                     (uint8)PICC_RET_NOT_OK,
                                     g_linkContexts[i].config.instanceId,
                                     g_linkContexts[i].config.channelId) != 0) {
                ret = -1;
            }
        }
    }
    return ret;
}

/**
 * @brief Handle connection response (Client role)
 * 
 * This function is called when the M-Core is acting as a CLIENT and receives
 * a connection response from the remote SERVER (A-Core).
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

    if ((header == NULL) || (payload == NULL)) {
        HANDLE_ERROR(-6);  /* Link handle response parameter NULL */
        return -1;
    }
    
    linkPayload = (const PICC_LinkPayload_t *)payload;

    /* Find exact matching context */
    ctx = PICC_GetLinkContext(instanceId, channelId);
    if (ctx != NULL) {
        if (ctx->config.role == PICC_ROLE_CLIENT &&
            ctx->config.remoteId == header->providerId &&
            ctx->config.localId == header->consumerId) {
            
            /* Check if connection response */
            if (linkPayload->subType == (uint8)PICC_LINK_CONNECT) {
                if (header->returnCode == (uint8)PICC_RET_OK) {
                    PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTED);
                } else {
                    PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
                }
            }
        }
    }

    return 0;
}

/**
 * @brief Handle incoming connection request (Server role)
 * 
 * This function is called when the M-Core is acting as a SERVER and receives
 * a connection request from the remote CLIENT (A-Core).
 * 
 * Message Flow:
 *   1. CLIENT (A-Core) sends LINK_CONNECT request with ReturnCode=0x01
 *   2. SERVER (M-Core) receives request -> this function is called
 *   3. SERVER sends LINK_CONNECT response with ReturnCode=0x00 (agree)
 *   4. SERVER updates state to CONNECTED
 * 
 * @note The function name "HandleRequest" means "process the incoming request",
 *       NOT "send a request". The SERVER never initiates connection requests;
 *       it only responds to requests from CLIENTs.
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

    if ((header == NULL) || (payload == NULL)) {
        HANDLE_ERROR(-7);  /* Link handle request parameter NULL */
        return -1;
    }

    linkPayload = (const PICC_LinkPayload_t *)payload;

    if (linkPayload->subType == (uint8)PICC_LINK_CONNECT) {
        
        ctx = PICC_GetLinkContext(instanceId, channelId);
        /* Server receives Request: header->consumerId is Client */
        if (ctx != NULL && ctx->config.role == PICC_ROLE_SERVER &&
            ctx->config.localId == header->providerId &&
            ctx->config.remoteId == header->consumerId) {
            
            /* Send connection response - agree to connect */
            ret = PICC_LinkSendMessage(ctx->config.localId,  /* ProviderID */
                                       header->consumerId,   /* ConsumerID */
                                       PICC_LINK_CONNECT,
                                       (uint8)PICC_RET_OK,
                                       ctx->config.instanceId,
                                       ctx->config.channelId);
            if (ret == 0) {
                PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTED);
            } else {
                HANDLE_ERROR(-8);  /* Failed to send link response */
            }
        }
    }

    return 0;
}

/**
 * @brief Send disconnect notification
 * 
 * @note M-Core typically does not actively disconnect. Per [R5], only A-Core
 *       sends disconnect notifications when its APP exits.
 */
sint8 PICC_LinkSendDisconnect(void)
{
    sint8 ret = 0;
    uint32 i;
    PICC_LinkContext_t *ctx;
    sint8 sendRet;

    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        ctx = &g_linkContexts[i];
        if (ctx->config.isUsed) {
            
            uint8 pId = (ctx->config.role == PICC_ROLE_CLIENT) ? ctx->config.remoteId : ctx->config.localId;
            uint8 cId = (ctx->config.role == PICC_ROLE_CLIENT) ? ctx->config.localId : ctx->config.remoteId;
            
            sendRet = PICC_LinkSendMessage(pId, cId, PICC_LINK_DISCONNECT, (uint8)PICC_RET_NOT_OK, 
                                     ctx->config.instanceId, ctx->config.channelId);
            if (sendRet == 0) {
                PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
            } else {
                HANDLE_ERROR(-9);  /* Failed to send disconnect */
                ret = -1;
            }
        }
    }
    return ret;
}

/**
 * @brief Handle incoming disconnect notification or reconnect request
 * 
 * This function is called when M-Core receives a disconnect/reconnect message
 * from A-Core, regardless of whether M-Core is CLIENT or SERVER.
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
 */
sint8 PICC_LinkHandleDisconnect(const PICC_MsgHeader_t *header,
                                const uint8 *payload, uint16 len,
                                uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;

    (void)len;

    if (payload == NULL) {
        HANDLE_ERROR(-10);  /* Link handle disconnect payload NULL */
        return -1;
    }
    linkPayload = (const PICC_LinkPayload_t *)payload;

    ctx = PICC_GetLinkContext(instanceId, channelId);
    if (ctx != NULL) {
        if (linkPayload->subType == (uint8)PICC_LINK_DISCONNECT) {
            
            /* [R5] Received disconnect notification (ReturnCode usually 0x01) */
            /* 1. Set state to disconnected */
            PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
            
            /* 2. Reply disconnect confirmation (ReturnCode=0x00) */
            /* Note: consumerId(from header)->ProviderID, providerId(from header)->ConsumerID */
            /* But LinkSendMessage is (ProviderID, ConsumerID...) */
            /* If I am Client: Header Provider=Server, Consumer=Me. Reply Provider=Me(Client?), Consumer=Server. */
            /* Protocol says: */
            /* Client replies Disconnect Confirmation: ProviderID=Client(0xCD?), ConsumerID=Server(0xC9?) - wait diagram numbers. */
            /* Diagram: 
               Server Send Disconnect: ProviderID=0xCD(Server), ConsumerID=0xC9(Client).
               Client Reply Confirm:   ProviderID=0xCD(Server), ConsumerID=0xC9(Client). ReturnCode=0x00. Payload[0]=0x02. 
               Wait, the diagram shows the SAME ProviderID/ConsumerID header for the reply?
               Check Diagram carefully:
               Request: CD 00 C9 ... ReturnCode 01
               Reply:   CD 00 C9 ... ReturnCode 00
               Both have ProviderID=CD(Server), ConsumerID=C9(Client).
               Only ReturnCode changes.
               
               Means: The header fields ProviderID/ConsumerID identify the SESSION connection, NOT the direction of the specific packet sender?
               OR The diagram notation is: ProviderID=ServerID, ConsumerID=ClientID.
               
               Let's check standard Request/Response:
               Request: CE 03 D2 ...
               Response: CE 03 D2 ...
               Yes, ProviderID and ConsumerID seem stable for the pairing.
               
               So when calling PICC_LinkSendMessage:
               ProviderID should always be the Server's ID?
               ConsumerID should always be the Client's ID?
               
               Caller: PICC_LinkSendMessage(providerId, consumerId, ...)
               
               If I am Client (M-Core):
               My ID = ctx->config.localId (ConsumerID).
               Remote ID = ctx->config.remoteId (ProviderID).
               
               When I reply, I should keep ProviderID=Remote, ConsumerID=Local.
            */
            
            sint8 sendRet = PICC_LinkSendMessage(header->providerId,  /* Keep Provider ID */
                                                 header->consumerId,  /* Keep Consumer ID */
                                                 PICC_LINK_DISCONNECT,
                                                 (uint8)PICC_RET_OK,  /* Confirm: 0x00 */
                                                 instanceId, channelId);

            /* [R5] After disconnect, CLIENT should auto-reconnect */
            if (ctx->config.role == PICC_ROLE_CLIENT) {
                /* Set to CONNECTING state, timer will handle reconnection */
                PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
            }

        } else if (linkPayload->subType == (uint8)PICC_LINK_RECONNECT) {
            PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
            if (ctx->config.role == PICC_ROLE_CLIENT) {
                /* No need to call SendRequest immediately, timer will handle it */
                PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
            }
        }
    }

    return 0;
}

/**
 * @brief Get current connection state for specified channel
 */
PICC_LinkState_e PICC_LinkGetState(uint8 channelId)
{
    uint32 i;
    
    for (i = 0U; i < PICC_MAX_CHANNELS; i++) {
        if (g_linkContexts[i].config.isUsed && 
            g_linkContexts[i].config.channelId == channelId) {
            return g_linkContexts[i].state;
        }
    }
    return PICC_LINK_STATE_DISCONNECTED;
}

/**
 * @brief Register connection state change callback
 */
sint8 PICC_LinkRegisterStateCallback(PICC_LinkStateCallback_t callback)
{
    g_stateCallback = callback;
    return 0;
}

/**
 * @brief Trigger reconnect on specified channel (called by heartbeat on timeout)
 * 
 * [R6] On heartbeat timeout:
 * 1. Report fault to app layer through state change callback
 * 2. CLIENT: Set to CONNECTING state to trigger auto reconnect
 * 3. SERVER: Set to DISCONNECTED state and wait for CLIENT to reconnect
 */
void PICC_LinkTriggerReconnect(uint8 instanceId, uint8 channelId)
{
    PICC_LinkContext_t *ctx = PICC_GetLinkContext(instanceId, channelId);
    if (ctx != NULL) {
        /* [FIX] Only CLIENT should enter CONNECTING state on heartbeat timeout.
         * SERVER should stay in DISCONNECTED and wait for CLIENT to send
         * connection requests.
         */
        if (ctx->config.role == PICC_ROLE_CLIENT) {
            PICC_LinkSetState(ctx, PICC_LINK_STATE_CONNECTING);
        } else {
            /* SERVER: Set to DISCONNECTED, wait for CLIENT to reconnect */
            PICC_LinkSetState(ctx, PICC_LINK_STATE_DISCONNECTED);
        }
    }
}

/**
 * @brief Process received link management message
 */
sint8 PICC_LinkProcessMessage(const PICC_MsgHeader_t *header,
                              const uint8 *payload, uint16 len,
                              uint8 instanceId, uint8 channelId)
{
    const PICC_LinkPayload_t *linkPayload;
    PICC_LinkContext_t *ctx;

    if ((header == NULL) || (payload == NULL)) {
        HANDLE_ERROR(-11);
        return -1;
    }

    /* [FIX] Disconnect notification only has 1 or 2 bytes payload.
     * Only CONNECT requires the full PICC_LinkPayload_t (4 bytes). */
    if (len < 1U) {
        HANDLE_ERROR(-12);
        return -1;
    }

    linkPayload = (const PICC_LinkPayload_t *)payload;

    ctx = PICC_GetLinkContext(instanceId, channelId);
    if (ctx == NULL) {
        /* Context not found for this channel, ignore */
        return 0;
    }

    switch (linkPayload->subType) {
        case PICC_LINK_CONNECT:
            if (ctx->config.role == PICC_ROLE_SERVER) {
                /* Server receives Connection Request */
                return PICC_LinkHandleRequest(header, payload, len, instanceId, channelId);
            } else {
                /* Client receives Connection Response */
                return PICC_LinkHandleResponse(header, payload, len, instanceId, channelId);
            }

        case PICC_LINK_DISCONNECT:
        case PICC_LINK_RECONNECT:
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

