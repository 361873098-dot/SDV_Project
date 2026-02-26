/**
 * @file EcuM_main_init.c
 * @brief EcuM Initialization Module Implementation
 *
 * Unified initialization management following AUTOSAR EcuM pattern.
 * Implements the hybrid architecture with PreOS/PostOS separation.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

/* EcuM module headers */

#include "EcuM_main_init.h"

/* RTD Drivers Headers */
#include "CDD_I2c.h"
#include "Clock_Ip.h"
#include "FlexCAN_Ip.h"
#include "Platform.h"
#include "Port.h"
#include "Siul2_Port_Ip.h"

/* Generated headers */
#include "Clock_Ip_PBcfg.h"
#include "FlexCAN_Ip_Sa_PBcfg.h"
#include "Siul2_Port_Ip_Cfg.h"

/* Application headers */
#include "FlexCAN_Ip_main.h"
#include "Pmic_driver_main.h"
#include "TJA1145A_Spi_Baremetal.h"
#include "picc_main.h"

/* FreeRTOS headers (for diagnostics) */
#include "FreeRTOS.h"
#include "task.h"

#include <string.h>

/*==================================================================================================
 *                                         MACRO DEFINITIONS
 *==================================================================================================*/

/** FlexCAN instance */
#define FLEXCAN_INST 0U

/*==================================================================================================
 *                                         EXTERNAL DECLARATIONS
 *==================================================================================================*/

/* CAN IRQ handler - defined in FlexCAN_Ip_Irq.c */
// extern void CAN0_ORED_0_7_MB_IRQHandler(void);

/*==================================================================================================
 *                                         INIT  VARIABLES
 *==================================================================================================*/

/** Global diagnostic data instance */
volatile EcuM_DiagInfo_t g_ecuMDiag;

/** Temporary buffer for uxTaskGetSystemState - static to avoid large stack
 * usage */
static TaskStatus_t s_taskStatusArray[ECUM_DIAG_MAX_TASKS];

/*==================================================================================================*/

/*==================================================================================================
 *                                         DWT CYCLE COUNTER
 *
 * Cortex-M7 Data Watchpoint and Trace (DWT) unit - standard ARM register
 * addresses. Used for high-precision CPU runtime statistics (1 microsecond
 * resolution). These are direct register addresses to avoid CMSIS header
 * dependency.
 *==================================================================================================*/

/** DWT Control Register */
#define DWT_CTRL_REG (*(volatile uint32 *)0xE0001000U)
/** DWT Cycle Count Register - counts CPU cycles at configCPU_CLOCK_HZ (400MHz)
 */
#define DWT_CYCCNT_REG (*(volatile uint32 *)0xE0001004U)
/** Debug Exception and Monitor Control Register */
#define DEMCR_REG (*(volatile uint32 *)0xE000EDFCU)

/** DEMCR: Trace Enable bit */
#define DEMCR_TRCENA (1UL << 24)
/** DWT_CTRL: Cycle Count Enable bit */
#define DWT_CYCCNTENA (1UL << 0)

/**
 * @brief Initialize DWT cycle counter for FreeRTOS runtime stats
 *
 * Called by FreeRTOS via portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() macro.
 * Enables the Cortex-M7 DWT cycle counter at full CPU frequency (400MHz).
 */
void vMainConfigureTimerForRunTimeStats(void) {
  DEMCR_REG |= DEMCR_TRCENA;     /* Enable trace system */
  DWT_CYCCNT_REG = 0U;           /* Reset cycle counter */
  DWT_CTRL_REG |= DWT_CYCCNTENA; /* Enable cycle counter */
}

/**
 * @brief Get current runtime counter value for FreeRTOS stats
 *
 * Called by FreeRTOS via portGET_RUN_TIME_COUNTER_VALUE() macro.
 * Returns raw DWT cycle count (400MHz, wraps every ~10.7s).
 *
 * IMPORTANT: Must NOT divide here! FreeRTOS computes deltas using
 * unsigned subtraction (new - old), which correctly handles uint32
 * overflow ONLY when the counter wraps at the natural 2^32 boundary.
 * Any division would create an artificial wrap point, breaking deltas.
 *
 * @return Raw CPU cycle count
 */
unsigned long ulMainGetRunTimeCounterValue(void) {
  return (unsigned long)DWT_CYCCNT_REG;
}

/*==================================================================================================
 *                                         PRIVATE FUNCTIONS
 *==================================================================================================*/

/** Maximum FreeRTOS task number for differential tracking */
#define ECUM_MAX_TASK_NUMBER (16U)

/** Previous runtime counters indexed by FreeRTOS xTaskNumber (stable ID) */
static uint32 s_prevRuntimeByTaskNum[ECUM_MAX_TASK_NUMBER];

/** Previous total runtime for delta calculation */
static uint32 s_prevTotalRuntime = 0U;

/**
 * @brief Update RTOS diagnostic information
 *
 * Uses differential calculation for CPU load:
 *   - Computes delta = currentRuntime - previousRuntime (unsigned, handles
 * overflow)
 *   - CPU% = deltaTask / (deltaTotal / 100)
 * This gives accurate per-second CPU load regardless of counter overflow.
 *
 * Runtime counter unit: raw CPU cycles (400MHz).
 * Displayed runtimeCounter: converted to microseconds for readability.
 */
void EcuM_Diag_Update(void) {
  UBaseType_t uxArraySize;
  uint32 ulTotalRunTime;
  uint32 i;
  uint8 idleCpuPercent = 0U;
  uint32 deltaTotalRuntime;
  uint32 deltaTaskRuntime;
  uint32 divisor;
  UBaseType_t taskNum;

  /* ========================================================================
   * 1. Get system state for all tasks
   * ======================================================================== */
  uxArraySize = uxTaskGetNumberOfTasks();
  if (uxArraySize > ECUM_DIAG_MAX_TASKS) {
    uxArraySize = ECUM_DIAG_MAX_TASKS;
  }

  uxArraySize =
      uxTaskGetSystemState(s_taskStatusArray, uxArraySize, &ulTotalRunTime);

  g_ecuMDiag.taskCount = (uint8)uxArraySize;

  /* ========================================================================
   * 2. Differential calculation setup
   *    deltaTotalRuntime handles uint32 overflow correctly via unsigned math
   * ======================================================================== */
  deltaTotalRuntime = ulTotalRunTime - s_prevTotalRuntime;

  /* divisor = deltaTotalRuntime / 100, avoids overflow in (delta * 100) */
  divisor = deltaTotalRuntime / 100U;
  if (divisor == 0U) {
    divisor = 1U; /* Prevent division by zero on first call */
  }

  /* ========================================================================
   * 3. Fill per-task diagnostic info
   * ======================================================================== */
  for (i = 0U; i < uxArraySize; i++) {
    /* Copy task name */
    strncpy((char *)g_ecuMDiag.tasks[i].name, s_taskStatusArray[i].pcTaskName,
            ECUM_DIAG_TASK_NAME_LEN - 1U);
    g_ecuMDiag.tasks[i].name[ECUM_DIAG_TASK_NAME_LEN - 1U] = '\0';

    /* Stack high water mark (minimum remaining stack in words) */
    g_ecuMDiag.tasks[i].stackHighWaterMark =
        (uint16)s_taskStatusArray[i].usStackHighWaterMark;

    /* Task priority and state */
    g_ecuMDiag.tasks[i].priority =
        (uint8)s_taskStatusArray[i].uxCurrentPriority;
    g_ecuMDiag.tasks[i].state = (uint8)s_taskStatusArray[i].eCurrentState;

    /* Runtime counter - convert from CPU cycles to microseconds for display */
    g_ecuMDiag.tasks[i].runtimeCounter =
        (uint32)(s_taskStatusArray[i].ulRunTimeCounter / 400U);

    /* ---- Differential CPU load calculation ---- */
    taskNum = s_taskStatusArray[i].xTaskNumber;
    if (taskNum < ECUM_MAX_TASK_NUMBER) {
      /* Delta = current - previous (unsigned subtraction handles overflow) */
      deltaTaskRuntime = (uint32)s_taskStatusArray[i].ulRunTimeCounter -
                         s_prevRuntimeByTaskNum[taskNum];

      g_ecuMDiag.tasks[i].cpuLoadPercent = (uint8)(deltaTaskRuntime / divisor);

      /* Clamp to 100% max (rounding can cause slight over) */
      if (g_ecuMDiag.tasks[i].cpuLoadPercent > 100U) {
        g_ecuMDiag.tasks[i].cpuLoadPercent = 100U;
      }

      /* Save current value for next differential */
      s_prevRuntimeByTaskNum[taskNum] =
          (uint32)s_taskStatusArray[i].ulRunTimeCounter;
    } else {
      g_ecuMDiag.tasks[i].cpuLoadPercent = 0U;
    }

    /* Track idle task for overall CPU load calculation */
    if (s_taskStatusArray[i].uxCurrentPriority == tskIDLE_PRIORITY) {
      idleCpuPercent = g_ecuMDiag.tasks[i].cpuLoadPercent;
    }
  }

  /* Clear remaining unused task slots */
  for (; i < ECUM_DIAG_MAX_TASKS; i++) {
    memset((void *)&g_ecuMDiag.tasks[i], 0, sizeof(EcuM_TaskDiag_t));
  }

  /* ========================================================================
   * 4. Overall CPU load = 100% - idle%
   * ======================================================================== */
  g_ecuMDiag.overallCpuLoad =
      (idleCpuPercent <= 100U) ? (100U - idleCpuPercent) : 0U;

  /* Save total runtime for next differential */
  s_prevTotalRuntime = ulTotalRunTime;

  /* Convert totalRuntime to microseconds for display */
  g_ecuMDiag.totalRuntime = ulTotalRunTime / 400U;

  /* ========================================================================
   * 5. Heap diagnostics
   * ======================================================================== */
  g_ecuMDiag.freeHeapSize = (uint32)xPortGetFreeHeapSize();
  g_ecuMDiag.minEverFreeHeapSize = (uint32)xPortGetMinimumEverFreeHeapSize();
  g_ecuMDiag.totalHeapSize = (uint32)configTOTAL_HEAP_SIZE;

  if (g_ecuMDiag.totalHeapSize > 0U) {
    g_ecuMDiag.heapUsagePercent =
        (uint8)(((g_ecuMDiag.totalHeapSize - g_ecuMDiag.freeHeapSize) * 100U) /
                g_ecuMDiag.totalHeapSize);
  }

  /* ========================================================================
   * 6. System uptime and update counter
   * ======================================================================== */
  g_ecuMDiag.uptimeSeconds = (uint32)(xTaskGetTickCount() / configTICK_RATE_HZ);
  g_ecuMDiag.updateCount++;
}

/*==================================================================================================
 *										   main()
 * Entry
 *==================================================================================================*/

/**
 * @brief Application entry point
 */
int main(void) {
  /* Initialize diagnostic data (SRAM may not be auto-zeroed) */
  memset((void *)&g_ecuMDiag, 0, sizeof(EcuM_DiagInfo_t));

  Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

  /* Platform initialization */
  Platform_Init(NULL_PTR);

  /* Initialize pins */
  Port_Init(NULL_PTR);

  Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

  /* Initialize I2c driver */
  I2c_Init(NULL_PTR);

  Pmic_driver_init();

  Clock_Ip_EnableModuleClock(SPI5_CLK);

  Spi_Baremetal_Init(2U); /* Prescaler = 2 for ~1MHz SPI clock */

  Spi_Baremetal_Tja1145_Init();

  FlexCAN_Ip_Init(FLEXCAN_INST, &FlexCAN_State0, &FlexCAN_Config0);

  FlexCAN_Ip_SetStartMode(FLEXCAN_INST);

  FlexCAN_Process_Init();

  Spi_Baremetal_Tja1145_SetCanActive();

  AINFC_CAN_Main_task();

  /* Start main task */
  PICC_Mian_Task();

  /* Main loop (normally won't reach here - scheduler takes over) */
  for (;;) {
    /* Idle loop */
  }

  return 0;
}

#ifdef __cplusplus
}
#endif
