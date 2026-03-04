/**
 * @file    EcuM_CpuLoadTest.h
 * @brief   CPU Load Stress-Test module for diagnostic validation.
 *
 * Creates a FreeRTOS task that generates a KNOWN and MEASURABLE CPU load.
 * The load percentage is controlled at runtime via a global variable
 * that can be modified live in Trace32:
 *
 *   Var.Set g_cpuLoadTestPercent = 30   --> 30% CPU load
 *   Var.Set g_cpuLoadTestPercent = 0    --> no load (idle)
 *   Var.Set g_cpuLoadTestPercent = 50   --> 50% CPU load
 *
 * When ECUM_CPULOAD_TEST_ENABLE == 0, all functions compile to empty stubs.
 */
#ifndef ECUM_CPULOAD_TEST_H
#define ECUM_CPULOAD_TEST_H

#include "Platform_Types.h"

/*==================================================================================================
 *                                       TEST CONFIGURATION
 *==================================================================================================*/

/**
 * @brief Master switch: set to 1 to enable the CPU load stress-test task.
 *        Set to 0 (default) to completely disable -- zero code footprint.
 */
#ifndef ECUM_CPULOAD_TEST_ENABLE
#define ECUM_CPULOAD_TEST_ENABLE 0U
#endif

/**
 * @brief FreeRTOS priority for the stress-test task (1 = just above IDLE).
 */
#ifndef ECUM_CPULOAD_TEST_PRIORITY
#define ECUM_CPULOAD_TEST_PRIORITY 1U
#endif

/*==================================================================================================
 *                                     RUNTIME CONTROL VARIABLE
 *==================================================================================================*/

/**
 * @brief  Runtime-adjustable target CPU load percentage (0..95).
 *
 * 0  = test task idles (no CPU load generated)
 * 1..95 = busy-wait for that many ms per 100 ms period
 *
 * Non-cacheable memory -- Trace32 writes take effect immediately.
 * Only available when ECUM_CPULOAD_TEST_ENABLE == 1.
 */
#if (ECUM_CPULOAD_TEST_ENABLE == 1U)
extern volatile uint32 g_cpuLoadTestPercent;
#endif

/*==================================================================================================
 *                                       PUBLIC API
 *==================================================================================================*/

/**
 * @brief  Create the CPU load test task.
 *         Call once from main() before vTaskStartScheduler().
 *         Does nothing if ECUM_CPULOAD_TEST_ENABLE == 0.
 */
void EcuM_CpuLoadTest_Init(void);

#endif /* ECUM_CPULOAD_TEST_H */
