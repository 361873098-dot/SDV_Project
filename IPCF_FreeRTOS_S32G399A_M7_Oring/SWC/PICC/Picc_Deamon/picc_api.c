/**
 * @file picc_api.c
 * @brief M-Core Inter-Core Communication Application Interface Layer - API Implementation
 *
 * Provides unified interface implementation for upper layer APP calls.
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
#include "picc_trace.h"  /* For TX/RX debug trace */
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */

/*==================================================================================================
 *                                         Global Variables
 *==================================================================================================*/

/** PICC global configuration (accessible by other modules) */
PICC_InitConfig_t g_piccConfig;

/** Whether initialized */
static boolean g_piccInitialized = FALSE;

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/* Forward declarations */
static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                       const uint8 *payload, uint16 payloadLen,
                                       uint8 instanceId, uint8 channelId);

/**
 * @brief Heartbeat timeout handler - triggers link reconnect
 * 
 * [R6] On heartbeat timeout, set CONNECTING state to trigger auto reconnect.
 * Note: Only the primary channel (Channel 1) triggers Link reconnect.
 *       Additional channels only report timeout but don't trigger reconnect.
 */
static void PICC_HeartbeatTimeoutHandler(uint8 instanceId, uint8 channelId)
{
    /* [FIX] Only the primary channel (Channel 1) triggers Link reconnect.
     * Additional channels (Channel 2, etc.) can have heartbeat monitoring
     * for health status, but they don't participate in Link management.
     * This prevents the bug where heartbeat timeout on Channel 2 causes
     * Link requests to be sent on that channel.
     */
    if (channelId == g_piccConfig.channelId) {
        /* Primary channel - trigger reconnect */
        PICC_LinkTriggerReconnect(instanceId, channelId);
    }
    /* For additional channels, we could optionally notify app layer here
     * but we don't trigger Link reconnect */
}
/**
 * @brief Initialize PICC infrastructure
 * 
 * Initializes application-level infrastructure only:
 * - Debug trace module
 * - Service layer registry
 * - Stack message callback
 * 
 * Channel-level init (Stack/Heartbeat) is done via PICC_InitChannel().
 * Link registration is done via PICC_LinkRegister() for each application.
 */
sint8 PICC_Init(const PICC_InitConfig_t *config)
{
    if (config == NULL) {
        return PICC_E_PARAM;
    }

    /* Store config for backward compatibility */
    g_piccConfig = *config;

    /* 1. Initialize debug trace module */
    PICC_TraceInit();

    /* 2. Initialize service layer registry */
    PICC_ServiceLayerInit();

    /* 3. Register stack layer message callback */
    (void)PICC_StackRegisterMsgCallback(PICC_ProcessSingleMessage);

    g_piccInitialized = TRUE;

    return PICC_E_OK;
}

/**
 * @brief Deinitialize PICC module
 */
void PICC_Deinit(void)
{
    PICC_ServiceLayerDeinit();
    PICC_LinkDeinit();
    g_piccInitialized = FALSE;
}

/**
 * @brief Check if PICC module is initialized
 */
boolean PICC_IsInitialized(void)
{
    return g_piccInitialized;
}

/**
 * @brief Add additional communication channel (DEPRECATED)
 */
sint8 PICC_AddChannel(uint8 instanceId, uint8 channelId)
{
    /* Delegate to new unified API */
    return PICC_InitChannel(instanceId, channelId);
}

/**
 * @brief Initialize specified IPCF channel (Stack + Heartbeat)
 * 
 * Channel-level initialization. Must be called BEFORE PICC_Init().
 * Heartbeat starts immediately and is independent of application-level connection.
 * 
 * [R6] Heartbeat is sent regardless of connection status.
 */
sint8 PICC_InitChannel(uint8 instanceId, uint8 channelId)
{
    PICC_StackConfig_t stackCfg;
    sint8 ret;
    static boolean heartbeatInitialized = FALSE;
    static boolean traceInitialized = FALSE;
    
    /* Initialize trace module on first channel init */
    if (traceInitialized == FALSE) {
        PICC_TraceInit();
        traceInitialized = TRUE;
    }
    
    /* 1. Initialize heartbeat module on first channel init
     * [R6] Heartbeat is channel-level, not application-level.
     */
    if (heartbeatInitialized == FALSE) {
        ret = PICC_HeartbeatInit();
        if (ret != 0) {
            return PICC_E_NOT_INIT;
        }
        /* Register heartbeat timeout callback ONCE (not per-channel)
         * [R6] Heartbeat is independent of application-level connection status.
         */
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
    
    /* 3. Add channel to heartbeat monitoring
     * [R6] Heartbeat starts immediately when channel is initialized.
     */
    ret = PICC_HeartbeatAddChannel(instanceId, channelId);
    if (ret != 0) {
        return ret;
    }
    
    return PICC_E_OK;
}

/**
 * @brief Register application-level Link configuration
 * 
 * Uses the same config structure as PICC_Init for convenience.
 * Each application can register its own Link configuration.
 */
sint8 PICC_LinkRegister(const PICC_InitConfig_t *config)
{
    PICC_LinkConfig_t linkCfg;
    sint8 ret;
    
    if (config == NULL) {
        return PICC_E_PARAM;
    }
    
    if (g_piccInitialized == FALSE) {
        return PICC_E_NOT_INIT;
    }
    
    /* Setup link configuration using the same structure as PICC_Init */
    linkCfg.localId    = config->linkLocalId;
    linkCfg.remoteId   = config->linkRemoteId;
    linkCfg.role       = config->linkRole;
    linkCfg.channelId  = config->channelId;
    linkCfg.instanceId = IPCF_INSTANCE0;
    linkCfg.isUsed     = TRUE;
    
    /* First: Initialize Link for this application (sets g_linkContexts[0]) */
    ret = PICC_LinkInit(&linkCfg);
    if (ret != 0) {
        return ret;
    }
    
    /* Then: Register additional channels (requires g_linkContexts[0] initialized) */
    ret = PICC_LinkAddChannel(linkCfg.instanceId, linkCfg.channelId);
    if (ret != 0) {
        return ret;
    }
    
    /* NOTE: Heartbeat timeout callback is now registered in PICC_InitChannel
     * (channel layer), NOT here (application layer).
     * [R6] Heartbeat operates regardless of connection status.
     */
    
    return PICC_E_OK;
}

/**
 * @brief Start connection (Client mode)
 */
sint8 PICC_StartConnect(void)
{
    if (g_piccInitialized == FALSE) {
        return PICC_E_NOT_INIT;
    }

    return PICC_LinkSendRequest();
}

/* Event send API moved to picc_service.h: PICC_SendEvent() */

/**
 * @brief Send Method request (Client role)
 */
uint8 PICC_MethodRequest(uint8 providerId, uint8 methodId,
                         const uint8 *data, uint16 len,
                         PICC_MethodType_e type,
                         uint8 instanceId, uint8 channelId)
{
    if (g_piccInitialized == FALSE) {
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
    if (g_piccInitialized == FALSE) {
        return PICC_E_NOT_INIT;
    }

    return PICC_ServiceResponseSend(consumerId, methodId, sessionId,
                                    returnCode, data, len, instanceId, channelId);
}

/* Note: Event/Method handler registration APIs moved to picc_service.h:
 * - PICC_RegisterEventHandler()
 * - PICC_RegisterMethodHandler()
 * - PICC_RegisterResponseHandler()
 */

/**
 * @brief Register connection state change callback
 */
sint8 PICC_RegisterLinkStateCallback(PICC_LinkStateCallback_t callback)
{
    return PICC_LinkRegisterStateCallback(callback);
}

/**
 * @brief Get connection state for specified channel
 */
PICC_LinkState_e PICC_GetLinkState(uint8 channelId)
{
    return PICC_LinkGetState(channelId);
}

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Process single message (internal callback)
 */
/**
 * @brief Process single message (internal callback)
 */
static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 instanceId, uint8 channelId)
{
    /* (Unused linkPayload removed) */

    if (header == NULL) {
        return;
    }

    /* Dispatch based on message type */
    if (header->msgType == (uint8)PICC_MSG_LINK_AVAILABLE) {
        /* Link related message - dispatch using unified Link layer handler */
        (void)PICC_LinkProcessMessage(header, payload, payloadLen, instanceId, channelId);
    } else {
        /* Service related message */
        (void)PICC_ServiceProcessMessage(header, payload, payloadLen, instanceId, channelId);
    }
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Process received IPCF message
 * 
 * All messages are in stacked format: [CRC_Enable 1B][Messages N B][Counter 2B][CRC16 2B]
 * Including heartbeat messages, heartbeat payload is only 9-byte special format
 * Heartbeat detection moved to PICC_StackProcessRx
 */
sint8 PICC_ProcessRxData(const uint8 instance,uint8 chan_id, const void *buf, uint32 size)
{
    const uint8 *data;
    sint8 ret;

    if (buf == NULL) {
        return PICC_E_PARAM;
    }

    data = (const uint8 *)buf;

    /* [R7] All received data is in stacked format: [Counter 2B][Messages][CRC16 2B] */
    if (size >= PICC_STACK_OVERHEAD_SIZE) {
        ret = PICC_StackProcessRx(data, size, instance, chan_id);
        if (ret >= 0) {
            return PICC_E_OK;
        }
        /* CRC verification failed or other error, return error code */
        return PICC_E_PARAM;
    }

    /* Data too small, doesn't conform to stacked format */
    return PICC_E_PARAM;
}

#if defined(__cplusplus)
}
#endif
