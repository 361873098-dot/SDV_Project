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
 * @brief Prepare and start main task
 */
void PICC_Mian_Task(void);

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

#endif /* MAIN_H */
