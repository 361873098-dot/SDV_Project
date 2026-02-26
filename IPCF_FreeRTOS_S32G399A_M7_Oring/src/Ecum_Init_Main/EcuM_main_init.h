/**
 * @file EcuM_main_init.h
 * @brief EcuM Initialization Module Header
 *
 * Provides unified initialization management following AUTOSAR EcuM pattern.
 * Separates PreOS (hardware) initialization from PostOS (RTOS-dependent)
 * initialization.
 */

#ifndef ECUM_MAIN_INIT_H
#define ECUM_MAIN_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcal.h" /* For uint8, uint16, uint32 platform types */

/*==================================================================================================
 *                                         MACRO DEFINITIONS
 *==================================================================================================*/

/** Maximum number of tasks to monitor */
#define ECUM_DIAG_MAX_TASKS (8U)

/** Task name max length (matches configMAX_TASK_NAME_LEN) */
#define ECUM_DIAG_TASK_NAME_LEN (10U)

/**
 * @brief Diagnostic update period in milliseconds
 *
 * Controls how often EcuM_Diag_Update() is called from the 10ms periodic task.
 * Change this value to adjust the update frequency:
 *   1000U = 1 second (default)
 *   2000U = 2 seconds
 *   5000U = 5 seconds
 *
 * @note Must be a multiple of 10 (10ms task base period)
 */
#define ECUM_DIAG_UPDATE_PERIOD_MS (1000U)

/*==================================================================================================
 *                                         TYPE DEFINITIONS
 *==================================================================================================*/

/**
 * @brief Per-task diagnostic information
 */
typedef struct {
  char name[ECUM_DIAG_TASK_NAME_LEN]; /**< Task name */
  uint16 stackHighWaterMark; /**< Min remaining stack since creation (words) */
  uint8 priority;            /**< Current task priority */
  uint8 state;               /**< Task state:
                                0=Running,1=Ready,2=Blocked,3=Suspended,4=Deleted */
  uint32 runtimeCounter;     /**< Total runtime counter value (ticks) */
  uint8 cpuLoadPercent;      /**< CPU usage % (0-100) */
} EcuM_TaskDiag_t;

/**
 * @brief System-level diagnostic information
 *
 * All fields are updated by EcuM_Diag_Update().
 * View this struct in Trace32 via: Var.View g_ecuMDiag
 */
typedef struct {
  /* Per-task diagnostics */
  EcuM_TaskDiag_t tasks[ECUM_DIAG_MAX_TASKS]; /**< Per-task info array */
  uint8 taskCount;                            /**< Number of active tasks */

  /* Heap diagnostics */
  uint32 freeHeapSize;        /**< Current free heap (bytes) */
  uint32 minEverFreeHeapSize; /**< Minimum ever free heap (bytes) */
  uint32 totalHeapSize;       /**< Total configured heap (bytes) */
  uint8 heapUsagePercent; /**< Heap usage % = (total - free) / total * 100 */

  /* CPU load diagnostics */
  uint32 totalRuntime;  /**< Total runtime counter (ticks) */
  uint8 overallCpuLoad; /**< Overall CPU load % = 100 - idle% */

  /* System info */
  uint32 uptimeSeconds; /**< System uptime (seconds) */
  uint32 updateCount;   /**< Diagnostic update counter */
} EcuM_DiagInfo_t;

/*==================================================================================================
 *                                         GLOBAL VARIABLES
 *==================================================================================================*/

/** Global diagnostic data - observe via Trace32: Var.View g_ecuMDiag */
extern volatile EcuM_DiagInfo_t g_ecuMDiag;

/*==================================================================================================
 *                                         FUNCTION PROTOTYPES
 *==================================================================================================*/

/**
 * @brief Pre-OS Initialization
 *
 * Performs all hardware initialization before RTOS scheduler starts:
 * - Clock initialization
 * - Platform initialization (includes interrupt controller)
 * - Port/GPIO initialization
 * - DMA initialization
 * - SPI initialization
 * - TJA1145A CAN transceiver initialization
 *
 * @note Must be called before EcuM_StartOS()
 */
void EcuM_PreOS_Init(void);

/**
 * @brief Start RTOS and create tasks
 *
 * Creates all application tasks and starts the RTOS scheduler:
 * - EcuM_PostOS_Init_Task (priority 4) - One-time RTOS-dependent init (PICC
 * module)
 * - PICC_Rx_Msg_Task (priority 3) - IPCF RX message processing
 * - EcuM_Period_10ms_Task (priority 2) - Periodic task (CAN, PICC, Power SM)
 *
 * @note This function does not return (scheduler takes over)
 */
void EcuM_StartOS(void);

/**
 * @brief Update RTOS diagnostic information
 *
 * Collects CPU load, stack usage and heap info for all RTOS tasks.
 * Should be called periodically (recommended: every 1 second).
 * Results are stored in g_ecuMDiag for Trace32 observation.
 *
 * @note Call from RTOS task context only (not from ISR).
 */
void EcuM_Diag_Update(void);

#ifdef __cplusplus
}
#endif

#endif /* ECUM_MAIN_INIT_H */
