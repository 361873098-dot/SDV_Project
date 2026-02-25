/**
 * @file Ecum_Period_task.h
 * @brief EcuM Periodic Task Module Header
 *
 * Provides unified periodic task management for all modules.
 */

#ifndef ECUM_PERIOD_TASK_H
#define ECUM_PERIOD_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         FUNCTION PROTOTYPES
 *==================================================================================================*/

/**
 * @brief 10ms Periodic Task
 *
 * Handles all periodic processing with 10ms period:
 * - PICC Stack processing
 * - PICC Heartbeat processing
 * - PICC Link processing
 * - Power State Machine
 *
 * @param pvParameters FreeRTOS task parameters (unused)
 */
void EcuM_Period_10ms_Task(void *pvParameters);

#ifdef __cplusplus
}
#endif

#endif /* ECUM_PERIOD_TASK_H */
