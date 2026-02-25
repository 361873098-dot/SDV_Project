/**
 * @file picc_stack.c
 * @brief M-Core Inter-Core Communication Message Stacking Layer - Implementation
 *
 * Implements message stacking functionality:
 * - Send on 10ms period or when buffer is full
 * - Add Counter(2B) + CRC16(2B) before sending
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_stack.h"
#include "picc_heartbeat.h"
#include "picc_trace.h" /* For TX/RX debug trace */
#include "Picc_main.h"    /* For HANDLE_ERROR */
#include "ipc-shm.h"
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */
#include "FreeRTOS.h"
#include "task.h"
/* NOTE: timers.h removed - no longer using FreeRTOS timers */

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Maximum supported Stack channel count */
#define PICC_STACK_MAX_INSTANCES (2U)

/** Stack instance structure */
typedef struct {
    PICC_StackConfig_t  config;       /**< Configuration */
    PICC_StackContext_t context;      /**< Context */
    boolean             initialized;  /**< Whether initialized */
} PICC_StackInstance_t;

/** Stack instance array (index 0=Channel1, index 1=Channel2) */
static PICC_StackInstance_t g_stackInstances[PICC_STACK_MAX_INSTANCES];

/** Message receive callback (globally shared) */
static PICC_StackMsgCallback_t g_stackMsgCallback = NULL;

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Get Stack instance
 * 
 * @param channelId Channel ID (1 or 2)
 * @return Stack instance pointer, NULL on failure
 */
static PICC_StackInstance_t* PICC_GetStackInstance(uint8 channelId)
{
    uint8 index;
    
    /* Channel ID to array index (1->0, 2->1) */
    if (channelId == 0U || channelId > PICC_STACK_MAX_INSTANCES) {
        return NULL;
    }
    
    index = channelId - 1U;
    return &g_stackInstances[index];
}

/**
 * @brief Actually send stacked data (for specified channel)
 * 
 * @param channelId Channel ID
 * @return 0 on success, non-zero on failure
 */
static sint8 PICC_StackDoSendForChannel(uint8 channelId)
{
    PICC_StackInstance_t *inst;
    uint8 *shmBuf;
    uint16 totalLen;
    uint16 crc;
    uint32 i;
    sint8 err;
    uint8 crcEnableFlag;
    uint16 counterOffset;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        HANDLE_ERROR(-31);  /* Stack: Invalid channel in DoSend */
        return -1;
    }

    /* [FIX] Check if remote (A-core) is ready before trying to send.
     * If not ready, skip sending but keep data for retry next period.
     * This is normal during startup or A-core restart - not an error.
     */
    if (ipc_shm_is_remote_ready(IPCF_INSTANCE0) != 0) {
        /* Remote not ready - skip sending but preserve data for retry */
        return 0;  /* Return success - normal condition during startup */
    }

    /* Enter critical section to protect context, avoid racing with PICC_StackAddMessage */
    taskENTER_CRITICAL();

    if (inst->context.usedSize == 0U) {
        taskEXIT_CRITICAL();
        return 0;  /* No data to send */
    }

    /* Calculate total length: CRC_Enable(1B) + data + Counter(2B) + CRC16(2B) */
    totalLen = PICC_STACK_CRC_ENABLE_SIZE + inst->context.usedSize + 
               PICC_STACK_COUNTER_SIZE + PICC_STACK_CRC_SIZE;

    /* Get IPCF send buffer */
    shmBuf = (uint8 *)ipc_shm_acquire_buf(IPCF_INSTANCE0, inst->config.channelId, totalLen);
    if (shmBuf == NULL) {
        /* IPCF buffer temporarily unavailable (all buffers in flight).
         * Keep data for retry next period - do NOT clear.
         */
        taskEXIT_CRITICAL();
        return -1;  /* Signal failure, but data preserved for retry */
    }

    /* [Byte 0] Fill CRC enable flag */
    crcEnableFlag = (inst->config.crcEnabled == PICC_STACK_CRC_ENABLED) ? 
                    PICC_STACK_CRC_ENABLED : PICC_STACK_CRC_DISABLED;
    shmBuf[0] = crcEnableFlag;

    /* [Bytes 1~N] Copy stacked protocol packets */
    for (i = 0U; i < inst->context.usedSize; i++) {
        shmBuf[PICC_STACK_CRC_ENABLE_SIZE + i] = inst->context.buffer[i];
    }

    /* [Bytes N+1, N+2] Fill Counter (big-endian) */
    counterOffset = PICC_STACK_CRC_ENABLE_SIZE + inst->context.usedSize;
    shmBuf[counterOffset]      = (uint8)(inst->context.txCounter >> 8U);
    shmBuf[counterOffset + 1U] = (uint8)(inst->context.txCounter & 0xFFU);

    /* Calculate CRC16 (on CRC_Enable + data + Counter) */
    crc = PICC_CRC16(shmBuf, counterOffset + PICC_STACK_COUNTER_SIZE);

    /* [Last 2 Bytes] Fill CRC16 (big-endian) */
    shmBuf[counterOffset + PICC_STACK_COUNTER_SIZE]      = (uint8)(crc >> 8U);
    shmBuf[counterOffset + PICC_STACK_COUNTER_SIZE + 1U] = (uint8)(crc & 0xFFU);

    /* [DEBUG] Record TX data for TRACE32 observation (before send attempt) */
    PICC_TraceTx(inst->config.channelId, shmBuf, totalLen);

    /* Send */
    /* Note: Assumes ipc_shm_tx is fast enough and non-blocking */
    err = ipc_shm_tx(IPCF_INSTANCE0, inst->config.channelId, shmBuf, totalLen);
    if (err != 0) {
        (void)ipc_shm_release_buf(IPCF_INSTANCE0, inst->config.channelId, shmBuf);
        taskEXIT_CRITICAL();
        HANDLE_ERROR(-32);  /* Stack: IPCF TX failed */
        return -2;
    }

    /* Update counter */
    inst->context.txCounter++;
    if (inst->context.txCounter == 0U) {
        inst->context.txCounter = 1U;  /* Avoid zero value */
    }

    /* Clear buffer */
    inst->context.usedSize = 0U;

    taskEXIT_CRITICAL();

    return 0;
}

/**
 * @brief Process all stack channels - send buffered data
 * 
 * Called from PICC periodic task (10ms).
 * Replaces the timer-based approach for better code organization.
 */
void PICC_StackProcess(void)
{
    uint8 i;
    PICC_StackInstance_t *inst;
    
    for (i = 0U; i < PICC_STACK_MAX_INSTANCES; i++) {
        inst = &g_stackInstances[i];
        if (inst->initialized != FALSE) {
            (void)PICC_StackDoSendForChannel(inst->config.channelId);
        }
    }
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Initialize stack layer for specified channel
 * 
 * @param config Configuration parameters
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackInitChannel(const PICC_StackConfig_t *config)
{
    PICC_StackInstance_t *inst;
    
    if (config == NULL) {
        HANDLE_ERROR(-1);  /* Config parameter is NULL */
        return -1;
    }
    
    inst = PICC_GetStackInstance(config->channelId);
    if (inst == NULL) {
        HANDLE_ERROR(-2);  /* Invalid channelId */
        return -2;
    }
    
    if (inst->initialized != FALSE) {
        return 0;  /* Already initialized, return success */
    }
    
    /* Save configuration */
    inst->config = *config;
    
    /* Initialize context */
    inst->context.usedSize    = 0U;
    inst->context.txCounter   = 1U;
    inst->context.rxCounter   = 0U;
    inst->context.timerRunning = FALSE;
    
    /* NOTE: Timer removed - PICC_StackProcess() is called from PICC_PeriodicTask */
    inst->initialized = TRUE;
    
    return 0;
}

/**
 * @brief Deinitialize stack layer for specified channel
 * 
 * @param channelId Channel ID
 */
void PICC_StackDeinitChannel(uint8 channelId)
{
    PICC_StackInstance_t *inst;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        return;
    }
    
    /* NOTE: Timer removed - no timer cleanup needed */
    inst->context.usedSize = 0U;
    inst->initialized = FALSE;
}

/**
 * @brief Add message to specified channel's stack buffer
 * 
 * @param channelId Channel ID
 * @param data Message data
 * @param len Message length
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackAddMessageToChannel(uint8 channelId, const uint8 *data, uint32 len)
{
    PICC_StackInstance_t *inst;
    uint32 i;
    sint8 ret = 0;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        return -1;
    }

    if ((data == NULL) || (len == 0U)) {
        HANDLE_ERROR(-33);  /* Stack: AddMessage data is NULL or len is 0 */
        return -2;
    }

    /* Check again (single message too large) */
    if (len > PICC_STACK_PAYLOAD_MAX_SIZE) {
        HANDLE_ERROR(-34);  /* Stack: Message too large */
        return -3;
    }

    /* Enter critical section */
    taskENTER_CRITICAL();

    /* Check if would exceed buffer */
    if ((inst->context.usedSize + len) > PICC_STACK_PAYLOAD_MAX_SIZE) {
        /* Buffer full - try to send current buffer first */
        ret = PICC_StackDoSendForChannel(channelId);
        if (ret != 0) {
            /* Send failed - return error to prevent buffer overflow */
            taskEXIT_CRITICAL();
            return -4;
        }
    }

    /* Add to buffer */
    for (i = 0U; i < len; i++) {
        inst->context.buffer[inst->context.usedSize] = data[i];
        inst->context.usedSize++;
    }

    /* Exit critical section */
    taskEXIT_CRITICAL();

    return ret;
}

/**
 * @brief Immediately send specified channel stack buffer contents
 * 
 * @param channelId Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackFlushChannel(uint8 channelId)
{
    PICC_StackInstance_t *inst;
    sint8 ret;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        HANDLE_ERROR(-35);  /* Stack: Invalid channel in FlushChannel */
        return -1;
    }

    ret = PICC_StackDoSendForChannel(channelId);
    if (ret != 0 && ret != -1) {  /* -1 is buffer unavailable, normal case */
        HANDLE_ERROR(-36);  /* Stack: FlushChannel send failed */
    }
    return ret;
}

/**
 * @brief Clear buffer for specified channel (discard pending data)
 * 
 * Used when high-priority message needs to be sent but buffer is full.
 */
void PICC_StackClearBuffer(uint8 channelId)
{
    PICC_StackInstance_t *inst;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        return;
    }
    
    taskENTER_CRITICAL();
    inst->context.usedSize = 0U;  /* Clear buffer by resetting used size */
    taskEXIT_CRITICAL();
}

/**
 * @brief Process received stacked data
 
 [00][01 01 06 00 00 00 00 01 AA][01 08 06 01 80 00 00 02 BB CC] [00 0F] [AB CD]
  -- +------ message 1 (9B) ----++------- message 2 (10B) -----+ ------   -----         
 CRC_En                                                          Counter  CRC16

 */
sint8 PICC_StackProcessRx(const uint8 *data, uint32 len,
                          uint8 instanceId, uint8 channelId)
{
    PICC_StackInstance_t *inst;
    uint8 crcEnableFlag;
    uint16 rxCounter;
    uint16 crcReceived;
    uint16 crcCalculated;
    uint32 payloadLen;
    uint32 offset;
    uint32 counterOffset;
    PICC_MsgHeader_t header;
    const uint8 *payload;
    uint16 msgPayloadLen;
    sint8 msgCount = 0;
    
    inst = PICC_GetStackInstance(channelId);
    if (inst == NULL || inst->initialized == FALSE) {
        HANDLE_ERROR(-37);  /* Stack: Invalid channel in ProcessRx */
        return -1;
    }

    /* Minimum length: CRC_Enable(1B) + Counter(2B) + CRC16(2B) = 5 bytes */
    if ((data == NULL) || (len < PICC_STACK_OVERHEAD_SIZE)) {
        HANDLE_ERROR(-38);  /* Stack: ProcessRx invalid data or length */
        return -2;
    }

    /* [DEBUG] Record RX data for TRACE32 observation */
    PICC_TraceRx(channelId, data, len);

    /* [Byte 0] Parse CRC enable flag */
    crcEnableFlag = data[0];

    /* Calculate counter offset: len - CRC16(2B) - Counter(2B) */
    counterOffset = len - PICC_STACK_CRC_SIZE - PICC_STACK_COUNTER_SIZE;

    /* Parse Counter (big-endian, before CRC16) */
    rxCounter = (uint16)((uint16)data[counterOffset] << 8U) | 
                (uint16)data[counterOffset + 1U];

    /* Parse CRC16 (big-endian, at end of data) */
    crcReceived = (uint16)((uint16)data[len - 2U] << 8U) | (uint16)data[len - 1U];

    /* Verify CRC if enabled */
    if (crcEnableFlag == PICC_STACK_CRC_ENABLED) {
        /* Calculate CRC16 (excluding last 2 bytes CRC) */
        crcCalculated = PICC_CRC16(data, len - PICC_STACK_CRC_SIZE);

        if (crcReceived != crcCalculated) {
            HANDLE_ERROR(-3);  /* CRC verification failed */
            return -3;
        }
    }

    /* Store receive counter to corresponding channel instance */
    inst->context.rxCounter = rxCounter;

    /* Parse stacked messages */
    /* Payload length = total - CRC_Enable(1B) - Counter(2B) - CRC16(2B) */
    payloadLen = len - PICC_STACK_OVERHEAD_SIZE;
    offset = PICC_STACK_CRC_ENABLE_SIZE;  /* Start after CRC enable flag */

    /* [R6] Check if heartbeat message (special format 9 bytes, no protocol header) */
    if (payloadLen == PICC_HEARTBEAT_MSG_SIZE) {
        const uint8 *heartbeatData = &data[offset];
        if (PICC_HeartbeatIsPing(heartbeatData, PICC_HEARTBEAT_MSG_SIZE) != FALSE) {
            /* Received Ping, reply Pong */
            (void)PICC_HeartbeatHandlePing(instanceId, channelId);
            return 1;  /* Processed 1 heartbeat message */
        }
        if (PICC_HeartbeatIsPong(heartbeatData, PICC_HEARTBEAT_MSG_SIZE) != FALSE) {
            /* Received Pong, reset heartbeat count */
            PICC_HeartbeatReset(instanceId, channelId);
            return 1;  /* Processed 1 heartbeat message */
        }
    }

    /* Parse protocol messages until reaching counter position */
    while (offset < counterOffset) {
        /* Parse single message */
        if (PICC_UnpackMessage(&data[offset], payloadLen, &header, &payload, &msgPayloadLen) == 0) {
            /* Calculate this message's total length */
            uint32 msgTotalLen = PICC_HEADER_SIZE + (uint32)msgPayloadLen;

            /* Call callback to process message - Passes instance/channel */
            if (g_stackMsgCallback != NULL) {
                g_stackMsgCallback(&header, payload, msgPayloadLen, instanceId, channelId);
            }
            
            offset += msgTotalLen;
            /* Prevent underflow: check before subtraction */
            if (msgTotalLen > payloadLen) {
                break;
            }
            payloadLen -= msgTotalLen;
            msgCount++;
        } else {
            break;  /* Parse failed, stop */
        }
    }

    return msgCount;
}

/**
 * @brief Register message receive callback (globally shared)
 */
sint8 PICC_StackRegisterMsgCallback(PICC_StackMsgCallback_t callback)
{
    g_stackMsgCallback = callback;
    return 0;
}

#if defined(__cplusplus)
}
#endif
