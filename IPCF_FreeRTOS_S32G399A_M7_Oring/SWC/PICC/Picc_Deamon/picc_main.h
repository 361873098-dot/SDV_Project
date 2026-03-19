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

/** Error handling macro, auto passes file and line number (used by PICC module) */
#define HANDLE_ERROR(err)       handle_error((err), __FILE__, __LINE__)

/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief PICC Pre-OS Initialization
 *
 * Initializes IPCF driver, PICC channels/services/links, and power management.
 * Called from main() before vTaskStartScheduler().
 * Does NOT depend on the RTOS scheduler being active.
 */
void PICC_PreOS_Init(void);

/**
 * @brief Initialize PICC infrastructure (internal to picc_main)
 */
void PICC_InfraInit(void);

/**
 * @brief Initialize IPCF channel for PICC (internal to picc_main)
 */
sint8 PICC_InitChannel(uint8 instanceId, uint8 channelId);

/**
 * @brief Process received data (internal to picc_main)
 */
sint8 PICC_ProcessRxData(const uint8 instance, uint8 chan_id, const void *buf, uint32 size);

/**
 * @brief RX message processing task (event-driven, queue blocking)
 *
 * This task blocks on the RX queue waiting for IPCF messages.
 * Created by OsTask_Creation_All() in Ostask_main.c.
 *
 * @param[in] params  FreeRTOS task parameter (unused)
 */
void App_Rx_Msg_10ms_Task(void *params);

/**
 * @brief Error handling function
 * 
 * @param[in] error Error code
 * @param[in] file  File where error occurred
 * @param[in] line  Line where error occurred
 */
void handle_error(sint8 error, const char *file, int line);

#if defined(__cplusplus)
}
#endif

#endif /* PICC_MAIN_H */
