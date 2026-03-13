/**
 * @file Ostask_main.h
 * @brief Centralized FreeRTOS Task Management Module - Header
 *
 * Provides the unified task creation entry point and periodic Runnable
 * function declarations for the AUTOSAR-RTE-style scheduling architecture.
 */

#ifndef OSTASK_MAIN_H
#define OSTASK_MAIN_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "Mcal.h"  /* For uint32, etc. */

/*==================================================================================================
 *                                  PERIODIC RUNNABLE DECLARATIONS
 *
 * Period buckets — add your module's periodic function call inside the
 * corresponding TASK_M0_xxxMS() implementation in Ostask_main.c.
 *==================================================================================================*/

void TASK_M0_1MS(void);     /**< 1ms   (requires dedicated thread if used) */
void TASK_M0_2MS(void);     /**< 2ms   (requires dedicated thread if used) */
void TASK_M0_5MS(void);     /**< 5ms   (requires dedicated thread if used) */
void TASK_M0_10MS(void);    /**< 10ms  (base period, always active)        */
void TASK_M0_20MS(void);    /**< 20ms  (sub-period of 10ms thread)         */
void TASK_M0_50MS(void);    /**< 50ms  (sub-period of 10ms thread)         */
void TASK_M0_100MS(void);   /**< 100ms (sub-period of 10ms thread)         */
void TASK_M0_1000MS(void);  /**< 1000ms(sub-period of 10ms thread)         */

/*==================================================================================================
 *                                  TASK CREATION ENTRY POINT
 *==================================================================================================*/

/**
 * @brief Create all application FreeRTOS tasks and start the scheduler
 *
 * This is the SINGLE entry point for all RTOS task creation.
 * Called from main() after all PreOS initialization is complete.
 *
 * @note This function does NOT return (vTaskStartScheduler takes over).
 */
void OsTask_Creation_All(void);

#if defined(__cplusplus)
}
#endif
	
#endif /* OSTASK_MAIN_H */
