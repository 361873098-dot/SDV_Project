/**
 * @file picc_stack.h
 * @brief M-Core Inter-Core Communication Message Stacking Layer - Interface Definition
 *
 * Implements message stacking functionality:
 * - Send on 10ms period or when buffer is full
 * - Add Counter(2B) + CRC16(2B) before sending
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_STACK_H
#define PICC_STACK_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_protocol.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Stack send period (ms) */
#define PICC_STACK_SEND_PERIOD_MS       (10U)

/** CRC enable flag field size */
#define PICC_STACK_CRC_ENABLE_SIZE      (1U)

/** CRC enable flag values */
#define PICC_STACK_CRC_ENABLED          (0x00U)  /**< CRC enabled */
#define PICC_STACK_CRC_DISABLED         (0x01U)  /**< CRC disabled */

/** Stack buffer maximum size (supports up to 4095 bytes IPCF frame + 5 bytes overhead) */
#define PICC_STACK_MAX_SIZE             (4100U)

/** Counter field size */
#define PICC_STACK_COUNTER_SIZE         (2U)

/** CRC16 field size */
#define PICC_STACK_CRC_SIZE             (2U)

/** Stack overhead size (CRC_Enable + Counter + CRC16) */
#define PICC_STACK_OVERHEAD_SIZE        (PICC_STACK_CRC_ENABLE_SIZE + PICC_STACK_COUNTER_SIZE + PICC_STACK_CRC_SIZE)

/** Maximum payload size */
#define PICC_STACK_PAYLOAD_MAX_SIZE     (PICC_STACK_MAX_SIZE - PICC_STACK_OVERHEAD_SIZE)

/*==================================================================================================
 *                                         Callback Function Types
 *==================================================================================================*/

/**
 * @brief Message receive callback function type
 * 
 * @param[in] header  Parsed message header
 * @param[in] payload Payload data
 * @param[in] len     Payload length
 */
/**
 * @brief Message receive callback function type
 * 
 * @param[in] header     Parsed message header
 * @param[in] payload    Payload data
 * @param[in] len        Payload length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 */
typedef void (*PICC_StackMsgCallback_t)(const PICC_MsgHeader_t *header,
                                        const uint8 *payload, uint16 len,
                                        uint8 instanceId, uint8 channelId);

/*==================================================================================================
 *                                         Structure Definitions
 *==================================================================================================*/

/**
 * @brief Stack configuration
 */
typedef struct {
    uint8   channelId;      /**< IPCF channel ID */
    uint16  maxSize;        /**< Maximum stack size */
    uint16  periodMs;       /**< Send period (ms) */
    boolean crcEnabled;     /**< CRC enable flag (TRUE=enabled, default) */
} PICC_StackConfig_t;

/**
 * @brief Stack buffer context
 */
typedef struct {
    uint8   buffer[PICC_STACK_MAX_SIZE];    /**< Stack buffer */
    uint16  usedSize;                        /**< Used size */
    uint16  txCounter;                       /**< Transmit counter */
    uint16  rxCounter;                       /**< Receive counter (for verification) */
    boolean timerRunning;                    /**< Is timer running */
} PICC_StackContext_t;

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Initialize stack layer for specified channel
 * 
 * @param[in] config Stack configuration (includes channelId)
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackInitChannel(const PICC_StackConfig_t *config);

/**
 * @brief Deinitialize stack layer for specified channel
 * 
 * @param[in] channelId Channel ID
 */
void PICC_StackDeinitChannel(uint8 channelId);

/**
 * @brief Add message to specified channel's stack buffer
 * 
 * If buffer is full, automatically triggers send.
 * 
 * @param[in] channelId Channel ID
 * @param[in] data Message data
 * @param[in] len  Message length
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackAddMessageToChannel(uint8 channelId, const uint8 *data, uint32 len);

/**
 * @brief Immediately send specified channel stack buffer contents
 * 
 * Manual trigger send, don't wait for timer.
 * 
 * @param[in] channelId Channel ID
 * @return 0 on success, non-zero on failure
 */
sint8 PICC_StackFlushChannel(uint8 channelId);

/**
 * @brief Process received stacked data
 * 
 * Verify Counter and CRC16, parse out individual messages.
 * 
 * @param[in] data       Receive data
 * @param[in] len        Data length
 * @param[in] instanceId Receive instance ID
 * @param[in] channelId  Receive channel ID
 * @return Number of parsed messages, negative value on failure
 */
sint8 PICC_StackProcessRx(const uint8 *data, uint32 len,
                          uint8 instanceId, uint8 channelId);

/**
 * @brief Clear buffer for specified channel (discard pending data)
 * 
 * Used when high-priority message needs to be sent but buffer is full.
 * 
 * @param[in] channelId Channel ID
 */
void PICC_StackClearBuffer(uint8 channelId);

/**
 * @brief Register message receive callback (globally shared)
 * 
 * @param[in] callback Callback function
 * @return 0 on success
 */
sint8 PICC_StackRegisterMsgCallback(PICC_StackMsgCallback_t callback);

/**
 * @brief Process all stack channels - send buffered data
 * 
 * Called from PICC periodic task (10ms).
 */
void PICC_StackProcess(void);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_STACK_H */
