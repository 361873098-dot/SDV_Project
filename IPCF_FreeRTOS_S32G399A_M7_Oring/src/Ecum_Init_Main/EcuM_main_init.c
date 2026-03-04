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
#include "EcuM_CpuLoadTest.h"

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

/** Global diagnostic data instance (non-cacheable: Trace32 reads SRAM directly)
 */
volatile EcuM_DiagInfo_t g_ecuMDiag
    __attribute__((section(".mcal_bss_no_cacheable")));

/** Temporary buffer for uxTaskGetSystemState - static to avoid large stack
 * usage */
static TaskStatus_t s_taskStatusArray[ECUM_DIAG_MAX_TASKS]
    __attribute__((section(".mcal_bss_no_cacheable")));

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
 * PRIVATE VARIABLES
 *==================================================================================================*/

/** Maximum number of tasks we can track differentials for (protects memory) */
#define ECUM_MAX_TRACKED_TASKS (16U)

/** Internal structure to safely track task runtime across updates */
typedef struct {
  TaskHandle_t handle;            /* Unique FreeRTOS task handle */
  uint32 prevRuntime;             /* Previous DWT counter snapshot */
  unsigned long long accumCycles; /* 64-bit accumulated RAW CPU cycles */
} EcuM_TaskTracking_t;

/** Tracking array mapping TaskHandle to its runtime history */
static EcuM_TaskTracking_t s_taskTracker[ECUM_MAX_TRACKED_TASKS]
    __attribute__((section(".mcal_bss_no_cacheable")));

/** Previous total runtime for delta calculation */
static uint32 s_prevTotalRuntime
    __attribute__((section(".mcal_bss_no_cacheable")));

/** 64-bit Accumulated total RAW CPU cycles (avoids microsecond truncation
 * drift) */
static unsigned long long s_accumTotalCycles
    __attribute__((section(".mcal_bss_no_cacheable")));

/** Timestamp to detect if update period exceeds DWT wrap time (10.7 seconds) */
static TickType_t s_lastUpdateTick
    __attribute__((section(".mcal_bss_no_cacheable")));

/*==================================================================================================
 * PRIVATE FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Initialize diagnostic subsystem (call once from main, before
 * scheduler)
 *
 * Clears all diagnostic state to known-good zeros.
 * Must be called before any RTOS task runs EcuM_Diag_Update().
 */
void EcuM_Diag_Init(void) {
  volatile uint8 *p;
  uint32 i;

  /* Zero g_ecuMDiag: volatile-safe, compiler CANNOT optimize this away */
  p = (volatile uint8 *)&g_ecuMDiag;
  for (i = 0U; i < sizeof(g_ecuMDiag); i++) {
    p[i] = 0U;
  }

  /* Zero s_taskTracker: not volatile, but use same pattern for safety */
  {
    volatile uint8 *q = (volatile uint8 *)s_taskTracker;
    for (i = 0U; i < sizeof(s_taskTracker); i++) {
      q[i] = 0U;
    }
  }

  s_prevTotalRuntime = 0U;
  s_accumTotalCycles = 0ULL;
  s_lastUpdateTick = 0;
}

/**
 * @brief Update RTOS diagnostic information
 *
 * Safely handles DWT 32-bit overflow using unsigned subtraction.
 * Tracks tasks by TaskHandle_t to support dynamic task deletion/creation.
 * Eliminates microsecond truncation drift by accumulating raw 400MHz cycles.
 *
 * @pre EcuM_Diag_Init() must have been called once before first invocation.
 */
void EcuM_Diag_Update(void) {
  UBaseType_t uxArraySize;
  uint32 ulTotalRunTime;
  uint32 i;
  uint8 j;
  uint8 idleCpuPercent = 0U;
  uint32 deltaTotalRuntime;
  uint32 deltaTaskRuntime;
  uint32 divisor;
  uint8 trackerSlot;
  TaskHandle_t currentHandle;
  TaskHandle_t idleHandle;
  TickType_t currentTick;

  /* ========================================================================
   * 1. Check polling frequency safety (The 10.73s Trap Fix)
   * ======================================================================== */
  currentTick = xTaskGetTickCount();
  if (s_lastUpdateTick != 0) {
    /* DWT cycle counter wraps every 10.73s at 400MHz. Unsigned subtraction
       gives correct deltas for ANY interval < 10.73s. We only skip when the
       interval approaches the wrap point (10s threshold = 0.73s safety). */
    if ((currentTick - s_lastUpdateTick) >= pdMS_TO_TICKS(10000)) {
      /* Reset total runtime baseline */
      uxArraySize = uxTaskGetNumberOfTasks();
      if (uxArraySize > ECUM_DIAG_MAX_TASKS) {
        uxArraySize = ECUM_DIAG_MAX_TASKS;
      }
      uxArraySize =
          uxTaskGetSystemState(s_taskStatusArray, uxArraySize, &ulTotalRunTime);
      s_prevTotalRuntime = ulTotalRunTime;

      /* Reset per-task baselines */
      for (i = 0U; i < uxArraySize; i++) {
        for (j = 0U; j < ECUM_MAX_TRACKED_TASKS; j++) {
          if (s_taskTracker[j].handle == s_taskStatusArray[i].xHandle) {
            s_taskTracker[j].prevRuntime =
                s_taskStatusArray[i].ulRunTimeCounter;
            break;
          }
        }
      }

      s_lastUpdateTick = currentTick;
      g_ecuMDiag.diagSkipCount++;
      return; /* Skip this cycle, next call will have clean baselines */
    }
  }
  s_lastUpdateTick = currentTick;

  /* ========================================================================
   * 2. Get system state for all tasks
   * ======================================================================== */
  uxArraySize = uxTaskGetNumberOfTasks();
  if (uxArraySize > ECUM_DIAG_MAX_TASKS) {
    uxArraySize = ECUM_DIAG_MAX_TASKS;
  }

  uxArraySize =
      uxTaskGetSystemState(s_taskStatusArray, uxArraySize, &ulTotalRunTime);
  g_ecuMDiag.taskCount = (uint8)uxArraySize;

  /* ========================================================================
   * 3. Differential calculation setup
   * deltaTotalRuntime handles uint32 overflow correctly via unsigned math
   * ======================================================================== */
  deltaTotalRuntime = ulTotalRunTime - s_prevTotalRuntime;

  /* divisor = deltaTotalRuntime / 100, avoids overflow in (delta * 100) */
  divisor = deltaTotalRuntime / 100U;
  if (divisor == 0U) {
    divisor = 1U; /* Prevent division by zero on first call */
  }

  /* Note: Requires INCLUDE_xTaskGetIdleTaskHandle set to 1 in FreeRTOSConfig.h
   */
  idleHandle = xTaskGetIdleTaskHandle();

  /* ========================================================================
   * 4. Fill per-task diagnostic info
   * ======================================================================== */
  for (i = 0U; i < uxArraySize; i++) {
    currentHandle = s_taskStatusArray[i].xHandle;

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

    /* ---- Dynamic Task Tracking (Fix for xTaskNumber flaw) ---- */
    trackerSlot = 255U; /* Invalid slot by default */

    /* Search for existing task or find an empty slot */
    for (j = 0U; j < ECUM_MAX_TRACKED_TASKS; j++) {
      if (s_taskTracker[j].handle == currentHandle) {
        trackerSlot = j; /* Found existing task */
        break;
      }
      if ((s_taskTracker[j].handle == NULL) && (trackerSlot == 255U)) {
        trackerSlot = j; /* Found first available empty slot */
      }
    }

    if (trackerSlot < ECUM_MAX_TRACKED_TASKS) {
      /* If it's a new task, initialize its tracking baseline */
      if (s_taskTracker[trackerSlot].handle != currentHandle) {
        s_taskTracker[trackerSlot].handle = currentHandle;
        /* CPU% baseline: start from "now" so first delta=0, no spike */
        s_taskTracker[trackerSlot].prevRuntime =
            s_taskStatusArray[i].ulRunTimeCounter;
        /* Cumulative time: capture runtime already accumulated since creation
         */
        s_taskTracker[trackerSlot].accumCycles =
            (unsigned long long)s_taskStatusArray[i].ulRunTimeCounter;
      }

      /* Delta = current - previous (unsigned subtraction handles 32-bit
       * overflow) */
      deltaTaskRuntime = s_taskStatusArray[i].ulRunTimeCounter -
                         s_taskTracker[trackerSlot].prevRuntime;

      /* Calculate CPU Load % with rounding */
      g_ecuMDiag.tasks[i].cpuLoadPercent =
          (uint8)((((unsigned long long)deltaTaskRuntime * 10ULL) / divisor +
                   5ULL) /
                  10ULL);

      if (g_ecuMDiag.tasks[i].cpuLoadPercent > 100U) {
        g_ecuMDiag.tasks[i].cpuLoadPercent = 100U;
      }

      /* Accumulate RAW 64-bit cycles (Fix for precision drift) */
      s_taskTracker[trackerSlot].accumCycles +=
          (unsigned long long)deltaTaskRuntime;

      /* Convert accumulated raw cycles to microseconds for the final diagnostic
       * structure */
      g_ecuMDiag.tasks[i].runtimeCounter =
          s_taskTracker[trackerSlot].accumCycles / 400ULL;

      /* Save current value for next differential */
      s_taskTracker[trackerSlot].prevRuntime =
          s_taskStatusArray[i].ulRunTimeCounter;
    } else {
      /* Tracking array is full */
      g_ecuMDiag.tasks[i].cpuLoadPercent = 0U;
      g_ecuMDiag.tasks[i].runtimeCounter = 0ULL;
    }

    /* Track idle task (Fix for Priority 0 overlap) */
    if (currentHandle == idleHandle) {
      idleCpuPercent = g_ecuMDiag.tasks[i].cpuLoadPercent;
    }
  }

  /* Clear remaining unused task slots in diagnostic struct */
  for (; i < ECUM_DIAG_MAX_TASKS; i++) {
    memset((void *)&g_ecuMDiag.tasks[i], 0, sizeof(EcuM_TaskDiag_t));
  }

  /* ========================================================================
   * 5. Overall CPU load = 100% - idle%
   * ======================================================================== */
  g_ecuMDiag.overallCpuLoad =
      (idleCpuPercent <= 100U) ? (100U - idleCpuPercent) : 0U;

  /* Save total runtime for next differential */
  s_prevTotalRuntime = ulTotalRunTime;

  /* Accumulate 64-bit total RAW cycles, then convert to microseconds */
  s_accumTotalCycles += (unsigned long long)deltaTotalRuntime;
  g_ecuMDiag.totalRuntime = s_accumTotalCycles / 400ULL;

  /* ========================================================================
   * 6. Heap diagnostics
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
   * 7. System uptime and update counter
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
  /* Initialize diagnostic subsystem (must be first, before any RTOS call) */
  EcuM_Diag_Init();

  /* CPU load stress-test (only active when ECUM_CPULOAD_TEST_ENABLE == 1) */
  EcuM_CpuLoadTest_Init();

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
