/**
 * @file    EcuM_CpuLoadTest.c
 * @brief   CPU Load Stress-Test -- creates a task that burns a known % of CPU.
 *
 * The task uses DWT CYCCNT (cycle counter) for precise busy-waiting,
 * ensuring the generated load is accurate regardless of tick jitter.
 *
 * Runtime control via Trace32:
 *   Var.Set g_cpuLoadTestPercent = 30   --> burns 30% CPU
 *   Var.Set g_cpuLoadTestPercent = 0    --> test idle (no load)
 *   Var.Set g_cpuLoadTestPercent = 50   --> burns 50% CPU
 */

#include "EcuM_CpuLoadTest.h"

#if (ECUM_CPULOAD_TEST_ENABLE == 1U)

#include "FreeRTOS.h"
#include "task.h"

/*==================================================================================================
 *                                        INTERNAL DEFINES
 *==================================================================================================*/

/** Stack size for the stress-test task (in words, not bytes) */
#define CPULOAD_TEST_STACK_SIZE (128U)

/** DWT Cycle Counter register address (Cortex-M7) */
#define DWT_CYCCNT_REG (*(volatile unsigned long *)0xE0001004UL)

/** CPU clock in Hz -- must match configCPU_CLOCK_HZ */
#define CPU_CLOCK_HZ (400000000UL)

/** Number of CPU cycles that correspond to 1 ms */
#define CYCLES_PER_MS (CPU_CLOCK_HZ / 1000UL)

/** Test period in FreeRTOS ticks (100 ms at 1000 Hz tick rate) */
#define TEST_PERIOD_TICKS pdMS_TO_TICKS(100U)

/*==================================================================================================
 *                                     RUNTIME CONTROL VARIABLE
 *==================================================================================================*/

/**
 * @brief  Runtime-adjustable target CPU load percentage.
 *
 * Placed in non-cacheable memory so Trace32 writes are immediately visible
 * to the CPU (no D-cache coherency issues).
 *
 * Values:
 *   0      = test task idles (no CPU load generated)
 *   1..95  = busy-wait for that many ms per 100 ms period
 *   >95    = clamped to 95 internally to prevent system starvation
 *
 * Change at any time in Trace32:
 *   Var.Set g_cpuLoadTestPercent = 30
 */
volatile uint32 g_cpuLoadTestPercent
    __attribute__((section(".mcal_bss_no_cacheable")));

/*==================================================================================================
 *                                        TASK IMPLEMENTATION
 *==================================================================================================*/

/**
 * @brief  CPU load stress-test task.
 *
 * Each 100 ms period:
 *   1. Read g_cpuLoadTestPercent (can be changed live via Trace32)
 *   2. If > 0: busy-spin for that many ms worth of DWT cycles
 *   3. Sleep for the remaining time
 */
static void CpuLoadTest_Task(void *pvParameters) {
  TickType_t xLastWakeTime = xTaskGetTickCount();
  (void)pvParameters;

  for (;;) {
    /* Read current target (volatile -- always fetches latest value) */
    uint32 targetPercent = g_cpuLoadTestPercent;

    if (targetPercent > 0U) {
      /* Clamp to 95 to avoid starving the system */
      if (targetPercent > 95U) {
        targetPercent = 95U;
      }

      /* Calculate how many DWT cycles to burn */
      unsigned long busyCycles = (unsigned long)targetPercent * CYCLES_PER_MS;

      /* --- Busy phase: spin until target cycles are consumed --- */
      unsigned long startCycle = DWT_CYCCNT_REG;
      while ((DWT_CYCCNT_REG - startCycle) < busyCycles) {
        __asm volatile("nop");
      }
    }

    /* --- Sleep phase: yield CPU for the rest of the 100 ms --- */
    vTaskDelayUntil(&xLastWakeTime, TEST_PERIOD_TICKS);
  }
}

/*==================================================================================================
 *                                        PUBLIC API
 *==================================================================================================*/

void EcuM_CpuLoadTest_Init(void) {
  /* Start with 0 = no load (user sets via Trace32 when needed) */
  g_cpuLoadTestPercent = 0U;

  (void)xTaskCreate(CpuLoadTest_Task, "CpuTest", CPULOAD_TEST_STACK_SIZE,
                    (void *)0, (UBaseType_t)ECUM_CPULOAD_TEST_PRIORITY,
                    (TaskHandle_t *)0);
}

#else /* ECUM_CPULOAD_TEST_ENABLE == 0 */

void EcuM_CpuLoadTest_Init(void) { /* do nothing */ }

#endif /* ECUM_CPULOAD_TEST_ENABLE */
