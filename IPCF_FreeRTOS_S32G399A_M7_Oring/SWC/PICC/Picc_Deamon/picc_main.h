/**
 * @file Picc_main.h
 * @brief M-Core Inter-Core Communication Application - Header File
 *
 * IPC Shared Memory Driver application with PICC middleware.
 *
 * Copyright 2020-2024 NXP
 * All Rights Reserved.
 */

#ifndef PICC_MAIN_H
#define PICC_MAIN_H

#if defined(__cplusplus)
extern "C"{
#endif

/*==================================================================================================
 *                                         Header Includes
 *==================================================================================================*/

#include "picc_api.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Enable diagnostic data recording feature (for testing only) */
#define PICC_DIAG_RECORD_ENABLE         (1U)

/** Error handling macro, auto passes file and line number (used by PICC module) */
#define PICC_HANDLE_ERROR(err)       PICC_handle_error((err), __FILE__, __LINE__)

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief PICC Pre-OS Initialization
 *
 * Initializes IPCF driver, PICC channels/services/links.
 * Called from main() before vTaskStartScheduler().
 * Does NOT depend on the RTOS scheduler being active.
 */
void PICC_PreOS_Init(void);

/**
 * @brief RX message processing task (event-driven, queue blocking)
 *
 * This task blocks on the RX queue waiting for IPCF messages.
 * Created by OsTask_Creation_All() in Ostask_main.c.
 *
 * @param[in] params  FreeRTOS task parameter (unused)
 */
void PICC_Rx_Msg_10ms_Task(void *params);

/**
 * @brief Error handling function
 *
 * @param[in] error Error code
 * @param[in] file  File where error occurred
 * @param[in] line  Line where error occurred
 */
void PICC_handle_error(sint8 error, const char *file, int line);

#if (PICC_DIAG_RECORD_ENABLE == 1U)
/**
 * @brief Add TX data to diagnostic record buffer
 *
 * @param[in] data    Data buffer to record
 * @param[in] len     Data length
 */
void PICC_DiagRecordAddTx(const uint8 *data, uint32 len);

/**
 * @brief Update link state diagnostic fields in g_diagRecord_Debug
 *
 * Reads current per-app link state and per-channel link state,
 * stores them in g_diagRecord_Debug for TRACE32 inspection.
 * Values: 0=DISCONNECTED, 1=CONNECTING, 2=CONNECTED
 */
void PICC_DiagUpdateLinkState(void);
#endif

#if defined(__cplusplus)
}
#endif

#endif /* PICC_MAIN_H */
