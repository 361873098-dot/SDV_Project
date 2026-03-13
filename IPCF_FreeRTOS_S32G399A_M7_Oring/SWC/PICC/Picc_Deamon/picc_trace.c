/**
 * @file picc_trace.c
 * @brief M-Core Inter-Core Communication Debug Trace - Implementation
 *
 * Implements TX/RX data trace for TRACE32 debugging observation.
 * Uses 2D circular buffer to record periodic TX/RX data.
 * Data format per row: data[row][0]=channelId, data[row][1]=dataLen, data[row][2..]=actual data
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_trace.h"
#include "FreeRTOS.h"
#include "task.h"

/*==================================================================================================
 *                                         Global Variables
 *==================================================================================================*/
#define TX_RX_FILETER    1
/**
 * @brief Global trace data - accessible in TRACE32
 * 
 * Usage in TRACE32:
 *   g_piccTrace.tx.data[row][0] = channelId
 *   g_piccTrace.tx.data[row][1] = dataLen
 *   g_piccTrace.tx.data[row][2..] = actual TX data
 *   g_piccTrace.tx.writeIndex = last written row
 *   
 *   g_piccTrace.rx.data[row][0] = channelId
 *   g_piccTrace.rx.data[row][1] = dataLen
 *   g_piccTrace.rx.data[row][2..] = actual RX data
 *   g_piccTrace.rx.writeIndex = last written row
 */
PICC_ChannelTrace_t g_piccTrace = {0};

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Initialize trace module
 */
void PICC_TraceInit(void)
{
    uint32 row;
    uint32 col;
    
    /* Clear TX buffer */
    for (row = 0U; row < PICC_TRACE_MAX_ROWS; row++) {
        for (col = 0U; col < PICC_TRACE_MAX_COLS; col++) {
            g_piccTrace.tx.data[row][col] = 0U;
        }
    }
    g_piccTrace.tx.writeIndex = 0U;
    
    /* Clear RX buffer */
    for (row = 0U; row < PICC_TRACE_MAX_ROWS; row++) {
        for (col = 0U; col < PICC_TRACE_MAX_COLS; col++) {
            g_piccTrace.rx.data[row][col] = 0U;
        }
    }
    g_piccTrace.rx.writeIndex = 0U;
}

/**
 * @brief Record TX data - Parse stacked packet and store each message separately
 * 
 * Stacked packet format: [CRC_Enable 1B][N protocol messages...][Counter 2B][CRC 2B]
 * Each protocol message: [Header 8B][Payload variable]
 * Header format: [ProviderID][MethodID][ConsumerID][SessionID][MsgType][ReturnCode][Length 2B big-endian]
 * 
 * Output per row: data[row][0]=channelId, data[row][1]=msgLen, data[row][2..]=single message
 */
void PICC_TraceTx(uint8 channelId, const uint8 *data, uint32 len)
{
    uint32 col;
    uint8 row;
    uint32 offset;
    uint32 msgLen;
    uint16 payloadLen;
    uint32 copyLen;
    const uint8 *msgPtr;
    
    if (data == NULL || len == 0U) {
        return;
    }
    
    /* Minimum stacked packet: [CRC_Enable 1B][Header 8B][Counter 2B][CRC 2B] = 13 bytes */
    if (len < 13U) {
        return;
    }
    
    /* [FIX] Enter critical section to protect trace buffer from concurrent access */
    taskENTER_CRITICAL();
    
    /* Parse stacked packet: skip CRC_Enable byte (offset 0), parse messages until Counter/CRC */
    /* Stacked data ends at len - 4 (2B counter + 2B CRC) */
    offset = 1U;  /* Skip CRC_Enable byte */
    
    while (offset + PICC_HEADER_SIZE <= (len - 4U)) {
        msgPtr = &data[offset];
        
        /* [USER REQUEST] Filter only ping/pong messages (ProviderID=0xFF or MethodID=0xFF)
         * Keep all other messages including Link (MethodID=0x00) and all application messages. */
        if ((msgPtr[0] == 0xFFU) || (msgPtr[1] == 0xFFU)) {
            /* Skip ping/pong message: parse its length and move to next */
            payloadLen = ((uint16)msgPtr[6] << 8U) | (uint16)msgPtr[7];
            offset += PICC_HEADER_SIZE + payloadLen;
            continue;
        }
        
        /* Get payload length from header bytes 6-7 (big-endian) */
        payloadLen = ((uint16)msgPtr[6] << 8U) | (uint16)msgPtr[7];
        msgLen = PICC_HEADER_SIZE + payloadLen;
        
        /* Sanity check: message should not exceed remaining data */
        if (offset + msgLen > (len - 4U)) {
            break;
        }
        
        /* Get current write row */
        row = g_piccTrace.tx.writeIndex;
        
        /* data[row][0] = channelId */
        g_piccTrace.tx.data[row][0] = channelId;
        
        /* data[row][1] = msgLen (single message length) */
        g_piccTrace.tx.data[row][1] = (msgLen > 255U) ? 255U : (uint8)msgLen;
        
        /* Limit copy length (reserve 2 bytes for channelId and msgLen) */
        copyLen = msgLen;
        if (copyLen > (PICC_TRACE_MAX_COLS - 2U)) {
            copyLen = PICC_TRACE_MAX_COLS - 2U;
        }
        
        /* Copy single message starting from column 2 */
        for (col = 0U; col < copyLen; col++) {
            g_piccTrace.tx.data[row][col + 2U] = msgPtr[col];
        }
        
        /* Clear remaining columns */
        for (col = copyLen + 2U; col < PICC_TRACE_MAX_COLS; col++) {
            g_piccTrace.tx.data[row][col] = 0U;
        }
        
        /* Update write index (circular) */
        g_piccTrace.tx.writeIndex++;
        if (g_piccTrace.tx.writeIndex >= PICC_TRACE_MAX_ROWS) {
            g_piccTrace.tx.writeIndex = 0U;
        }
        
        /* Move to next message in stacked packet */
        offset += msgLen;
    }
    
    taskEXIT_CRITICAL();
}

/**
 * @brief Record RX data - Parse stacked packet and store each message separately
 * 
 * Stacked packet format: [CRC_Enable 1B][N protocol messages...][Counter 2B][CRC 2B]
 * Each protocol message: [Header 8B][Payload variable]
 * Header format: [ProviderID][MethodID][ConsumerID][SessionID][MsgType][ReturnCode][Length 2B big-endian]
 * 
 * Output per row: data[row][0]=channelId, data[row][1]=msgLen, data[row][2..]=single message
 */
void PICC_TraceRx(uint8 channelId, const uint8 *data, uint32 len)
{
    uint32 col;
    uint8 row;
    uint32 offset;
    uint32 msgLen;
    uint16 payloadLen;
    uint32 copyLen;
    const uint8 *msgPtr;
    
    if (data == NULL || len == 0U) {
        return;
    }
    
    /* Minimum stacked packet: [CRC_Enable 1B][Header 8B][Counter 2B][CRC 2B] = 13 bytes */
    if (len < 13U) {
        return;
    }
    
    /* [FIX] Enter critical section to protect trace buffer from concurrent access */
    taskENTER_CRITICAL();
    
    /* Parse stacked packet: skip CRC_Enable byte (offset 0), parse messages until Counter/CRC */
    /* Stacked data ends at len - 4 (2B counter + 2B CRC) */
    offset = 1U;  /* Skip CRC_Enable byte */
    
    while (offset + PICC_HEADER_SIZE <= (len - 4U)) {
        msgPtr = &data[offset];
        
        /* [USER REQUEST] Filter only ping/pong messages (ProviderID=0xFF or MethodID=0xFF)
         * Keep all other messages including Link (MethodID=0x00) and all application messages. */
        if ((msgPtr[0] == 0xFFU) || (msgPtr[1] == 0xFFU)) {
            /* Skip ping/pong message: parse its length and move to next */
            payloadLen = ((uint16)msgPtr[6] << 8U) | (uint16)msgPtr[7];
            offset += PICC_HEADER_SIZE + payloadLen;
            continue;
        }
        
        /* Get payload length from header bytes 6-7 (big-endian) */
        payloadLen = ((uint16)msgPtr[6] << 8U) | (uint16)msgPtr[7];
        msgLen = PICC_HEADER_SIZE + payloadLen;
        
        /* Sanity check: message should not exceed remaining data */
        if (offset + msgLen > (len - 4U)) {
            break;
        }
        
        /* Get current write row */
        row = g_piccTrace.rx.writeIndex;
        
        /* data[row][0] = channelId */
        g_piccTrace.rx.data[row][0] = channelId;
        
        /* data[row][1] = msgLen (single message length) */
        g_piccTrace.rx.data[row][1] = (msgLen > 255U) ? 255U : (uint8)msgLen;
        
        /* Limit copy length (reserve 2 bytes for channelId and msgLen) */
        copyLen = msgLen;
        if (copyLen > (PICC_TRACE_MAX_COLS - 2U)) {
            copyLen = PICC_TRACE_MAX_COLS - 2U;
        }
        
        /* Copy single message starting from column 2 */
        for (col = 0U; col < copyLen; col++) {
            g_piccTrace.rx.data[row][col + 2U] = msgPtr[col];
        }
        
        /* Clear remaining columns */
        for (col = copyLen + 2U; col < PICC_TRACE_MAX_COLS; col++) {
            g_piccTrace.rx.data[row][col] = 0U;
        }
        
        /* Update write index (circular) */
        g_piccTrace.rx.writeIndex++;
        if (g_piccTrace.rx.writeIndex >= PICC_TRACE_MAX_ROWS) {
            g_piccTrace.rx.writeIndex = 0U;
        }
        
        /* Move to next message in stacked packet */
        offset += msgLen;
    }
    
    taskEXIT_CRITICAL();
}

/**
 * @brief Clear all trace data
 */
void PICC_TraceClear(void)
{
    PICC_TraceInit();
}

/**
 * @brief Get trace buffer pointer for external access
 */
PICC_ChannelTrace_t* PICC_TraceGetChannel(uint8 channelId)
{
    (void)channelId;  /* Unused, kept for API compatibility */
    return &g_piccTrace;
}

#if defined(__cplusplus)
}
#endif
