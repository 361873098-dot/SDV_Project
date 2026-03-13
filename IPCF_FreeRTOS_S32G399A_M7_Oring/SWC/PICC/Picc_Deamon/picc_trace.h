/**
 * @file picc_trace.h
 * @brief M-Core Inter-Core Communication Debug Trace - Interface Definition
 *
 * Provides TX/RX data trace for TRACE32 debugging observation.
 * Uses 2D array to record multiple entries for periodic data observation.
 * Data format per row: data[row][0]=channelId, data[row][1]=dataLen, data[row][2..]=actual data
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_TRACE_H
#define PICC_TRACE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_protocol.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Maximum data columns per trace entry (increased to capture full stacked packets) */
#define PICC_TRACE_MAX_COLS    (32U)

/** Maximum trace entries (rows) for periodic observation */
#define PICC_TRACE_MAX_ROWS    (10U)

/*==================================================================================================
 *                                         Type Definitions
 *==================================================================================================*/

/**
 * @brief Trace buffer structure (TX or RX)
 * 
 * 2D circular buffer for periodic data observation in TRACE32:
 *   data[row][0] = channelId
 *   data[row][1] = dataLen (actual payload length)
 *   data[row][2..] = actual payload data
 * 
 * writeIndex indicates the next row to be written (circular).
 */
typedef struct {
    uint8   data[PICC_TRACE_MAX_ROWS][PICC_TRACE_MAX_COLS];  /**< 2D data buffer */
    uint8   writeIndex;                                       /**< Current write row index */
} PICC_TraceBuffer_t;

/**
 * @brief Complete trace data structure
 */
typedef struct {
    PICC_TraceBuffer_t tx;  /**< TX trace buffer */
    PICC_TraceBuffer_t rx;  /**< RX trace buffer */
} PICC_ChannelTrace_t;

/*==================================================================================================
 *                                         Global Variables (for TRACE32)
 *==================================================================================================*/

/** 
 * @brief Trace data - accessible in TRACE32
 * 
 * g_piccTrace.tx.data[row][0] = channelId
 * g_piccTrace.tx.data[row][1] = dataLen
 * g_piccTrace.tx.data[row][2..] = TX data
 * g_piccTrace.tx.writeIndex = current write position
 * 
 * g_piccTrace.rx.data[row][0] = channelId
 * g_piccTrace.rx.data[row][1] = dataLen
 * g_piccTrace.rx.data[row][2..] = RX data
 * g_piccTrace.rx.writeIndex = current write position
 */
extern PICC_ChannelTrace_t g_piccTrace;

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Initialize trace module
 */
void PICC_TraceInit(void);

/**
 * @brief Record TX data
 * 
 * @param[in] channelId Channel ID
 * @param[in] data      Data to record
 * @param[in] len       Data length
 */
void PICC_TraceTx(uint8 channelId, const uint8 *data, uint32 len);

/**
 * @brief Record RX data
 * 
 * @param[in] channelId Channel ID
 * @param[in] data      Data to record
 * @param[in] len       Data length
 */
void PICC_TraceRx(uint8 channelId, const uint8 *data, uint32 len);

/**
 * @brief Clear all trace data
 */
void PICC_TraceClear(void);

/**
 * @brief Get trace buffer pointer for external access
 * 
 * @param[in] channelId Channel ID (unused, kept for API compatibility)
 * @return Pointer to trace structure
 */
PICC_ChannelTrace_t* PICC_TraceGetChannel(uint8 channelId);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_TRACE_H */
