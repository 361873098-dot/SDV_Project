/**
 * @file Ostask_main.c
 * @brief Centralized FreeRTOS Task Management Module
 *
 * Implements the AUTOSAR-RTE-style task scheduling architecture:
 *   - All periodic business Runnables are aggregated into period-grouped functions
 *     (TASK_M0_10MS, TASK_M0_100MS, TASK_M0_1000MS, etc.)
 *   - A single FreeRTOS 10ms thread drives all period groups via counter-based dispatch
 *   - Event-driven (queue/notification blocking) tasks remain as independent FreeRTOS
 *     tasks but are created here for centralized visibility
 *   - Future business modules only need to add one function call to the appropriate
 *     period group — no new FreeRTOS task or stack allocation required
 *
 * Task creation overview (OsTask_Creation_All):
 *   +------------------+----------+--------------+-------------------------------+
 *   | Task Name        | Priority | Stack(Words) | Purpose                       |
 *   +------------------+----------+--------------+-------------------------------+
 *   | OS_10ms          | 2        | 256          | Unified periodic task (10ms)  |
 *   | App_Rx_Msg       | 3        | 192          | IPCF RX queue processing      |
 *   +------------------+----------+--------------+-------------------------------+
 *
 * Note: softirq task (priority 4, 256 Words) is created internally by
 *       ipc_shm_init() in IPCF driver — NOT managed here.
 */

#if defined(__cplusplus)
extern "C"{
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"

/* Module header */
#include "Ostask_main.h"

/* Application module headers - for periodic Runnables */
#include "FlexCAN_Ip_main.h"        /* AINFC_Can_Cyclic_10ms()                  */
#include "TJA1145A_Spi_Baremetal.h"  /* Spi_Baremetal_Tja1145_PeriodicTest()     */
#include "picc_stack.h"              /* PICC_StackProcess()                      */
#include "picc_heartbeat.h"          /* PICC_HeartbeatProcess()                  */
#include "picc_link.h"               /* PICC_LinkProcess()                       */
#include "pwsm.h"                    /* Pwsm_Main()                             */
#include "diag_mgmt.h"               /* DiagMgmt_Main()                         */
#include "System_Cpuload.h"          /* EcuM_Diag_Update()                       */

/* Event-driven task declaration */
#include "Picc_main.h"               /* App_Rx_Msg_10ms_Task()                  */

/*==================================================================================================
 *                                         MACRO DEFINITIONS
 *==================================================================================================*/

/** Unified 1ms periodic task stack size (Words) */
#define OSTASK_1MS_STACK_SIZE       (128U)  /* 512B */

/** Unified 10ms periodic task stack size (Words) */
#define OSTASK_10MS_STACK_SIZE      (256U)  /* 1KB */

/** PICC RX message processing task stack size (Words) */
#define OSTASK_RX_MSG_STACK_SIZE    (192U)  /* 768B */

/*==================================================================================================
 *                                         PRIVATE VARIABLES
 *==================================================================================================*/

/** 10ms task execution counter (for sub-period dispatch and debugging) */

static uint32 g_OsTask_1ms_cnt=0;
static uint32 g_OsTask_2ms_cnt=0;
static uint32 g_OsTask_5ms_cnt=0;

static uint32 g_OsTask_10ms_cnt = 0U;
static uint32 g_OsTask_20ms_cnt = 0U;

static uint32 g_OsTask_50ms_cnt = 0U;
static uint32 g_OsTask_100ms_cnt = 0U;
static uint32 g_OsTask_1000ms_cnt = 0U;




/*==================================================================================================
 *                                  PERIODIC RUNNABLE FUNCTIONS
 *
 * Each TASK_M0_xxxMS() function is a "period bucket" that aggregates all
 * business Runnables sharing the same execution period. To add a new periodic
 * function, simply append one line to the appropriate bucket below.
 *==================================================================================================*/

/**
 * @brief 1ms period Runnables (reserved for future use)
 * @note Requires a dedicated 1ms FreeRTOS thread if activated
 */
void TASK_M0_1MS(void)
{
	g_OsTask_1ms_cnt++;

}

/**
 * @brief 2ms period Runnables (reserved for future use)
 * @note Requires a dedicated 2ms FreeRTOS thread if activated
 */
void TASK_M0_2MS(void)
{
	g_OsTask_2ms_cnt++;

}

/**
 * @brief 5ms period Runnables (reserved for future use)
 * @note Requires a dedicated 5ms FreeRTOS thread if activated
 */
void TASK_M0_5MS(void)
{
	g_OsTask_5ms_cnt++;

}

/**
 * @brief 10ms period Runnables
 *
 * Executed every 10ms by the unified periodic thread.
 */
void TASK_M0_10MS(void)
{
    /* FlexCAN cyclic processing (2 TX + 2 RX) */
    AINFC_Can_Cyclic_10ms();

    /* PICC Stack: Send buffered messages on all channels */
    PICC_StackProcess();

    /* PICC Heartbeat: Send Ping every 2000ms */
    PICC_HeartbeatProcess();

    /* PICC Link: Handle connection requests (Client mode) */
    PICC_LinkProcess();

    /* Power State Machine */
    Pwsm_Main();

    /* Diagnostic Management: DoIP activation line status (30ms period) */
    DiagMgmt_Main();

#if (PICC_DIAG_RECORD_ENABLE == 1U)
    /* Update link state diagnostics (appLinkState + channelLinkState) */
    PICC_DiagUpdateLinkState();
#endif
}

/**
 * @brief 20ms period Runnables (reserved for future use)
 *
 * Dispatched from the 10ms thread (counter % 2 == 0).
 */
void TASK_M0_20MS(void)
{
	g_OsTask_20ms_cnt++;

}

/**
 * @brief 50ms period Runnables (reserved for future use)
 *
 * Dispatched from the 10ms thread (counter % 5 == 0).
 */
void TASK_M0_50MS(void)
{
	g_OsTask_50ms_cnt++;

}

/**
 * @brief 100ms period Runnables
 *
 * Dispatched from the 10ms thread (counter % 10 == 0).
 */
void TASK_M0_100MS(void)
{
	g_OsTask_100ms_cnt++;

    /* TJA1145 SPI periodic test (for SPI waveform debugging) */
    Spi_Baremetal_Tja1145_PeriodicTest();
}

/**
 * @brief 1000ms period Runnables
 *
 * Dispatched from the 10ms thread (counter % 100 == 0).
 */
void TASK_M0_1000MS(void)
{
	g_OsTask_1000ms_cnt++;

    /* RTOS diagnostics update (CPU load, stack watermark, heap) */
    EcuM_Diag_Update();
}

/*==================================================================================================
 *                                   FREERTOS THREAD: 10ms BASE
 *
 * Single FreeRTOS task that drives all periodic Runnables.
 * Sub-periods (20ms, 50ms, 100ms, 1000ms) are dispatched via counter modulo.
 *==================================================================================================*/

/**
 * @brief Unified 1ms periodic thread
 *
 * Drives sub-10ms period groups: 1ms, 2ms, 5ms
 */
static void OsTask_1ms_Thread(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(1);
    static uint32 s_1ms_cnt = 0U;

    (void)pvParameters;

    xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        s_1ms_cnt++;

        /* ---- Base 1ms ---- */
        TASK_M0_1MS();

        /* ---- Sub-period dispatch ---- */
        if ((s_1ms_cnt % 2U) == 0U) {
            TASK_M0_2MS();
        }
        if ((s_1ms_cnt % 5U) == 0U) {
            TASK_M0_5MS();
        }

        /* Wait until next 1ms period */
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

/**
 * @brief Unified 10ms periodic thread
 *
 * Drives 10ms and longer period groups: 10ms, 20ms, 50ms, 100ms, 1000ms
 */
static void OsTask_10ms_Thread(void *pvParameters)
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(10);

    (void)pvParameters;

    /* Initialize the xLastWakeTime variable with current time */
    xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        g_OsTask_10ms_cnt++;

        /* ---- Base 10ms ---- */
        TASK_M0_10MS();

        /* ---- Sub-period dispatch ---- */
        if ((g_OsTask_10ms_cnt % 2U) == 0U) {
            TASK_M0_20MS();
        }
        if ((g_OsTask_10ms_cnt % 5U) == 0U) {
            TASK_M0_50MS();
        }
        if ((g_OsTask_10ms_cnt % 10U) == 0U) {
            TASK_M0_100MS();
        }
        if ((g_OsTask_10ms_cnt % 100U) == 0U) {
            TASK_M0_1000MS();
        }

        /* Wait until next 10ms period - allows lower priority tasks to run */
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

/*==================================================================================================
 *                                  CENTRALIZED TASK CREATION
 *==================================================================================================*/

/**
 * @brief Create all application FreeRTOS tasks and start the scheduler
 *
 * This is the SINGLE entry point for all RTOS task creation.
 * Called from main() after all PreOS and application initialization is complete.
 *
 * @note This function does NOT return (vTaskStartScheduler takes over).
 *
 * Tasks NOT created here (managed by their own modules):
 *   - softirq (created by ipc_shm_init() inside PICC_PreOS_Init)
 *   - CpuTest (created by EcuM_CpuLoadTest_Init, disabled by default)
 *   - Tmr Svc (FreeRTOS kernel internal)
 *   - IDLE    (FreeRTOS kernel internal)
 */
void OsTask_Creation_All(void)
{
    BaseType_t os_status;

    /* ========================================================================
     * 1. Unified 1ms periodic task
     *    Drives: 1ms, 2ms, 5ms period groups
     * ======================================================================== */
    os_status = xTaskCreate(OsTask_1ms_Thread,
                            "OS_1ms",
                            OSTASK_1MS_STACK_SIZE,
                            NULL,
                            tskIDLE_PRIORITY + 2,
                            NULL);
    if (os_status != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    /* ========================================================================
     * 2. Unified 10ms periodic task
     *    Drives: CAN, PICC, TJA1145, PowerSM, Diagnostics
     * ======================================================================== */
    os_status = xTaskCreate(OsTask_10ms_Thread,
                            "OS_10ms",
                            OSTASK_10MS_STACK_SIZE,
                            NULL,
                            tskIDLE_PRIORITY + 2,
                            NULL);
    if (os_status != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    /* ========================================================================
     * 3. PICC RX message processing task (event-driven, queue blocking)
     *    Blocks on xQueueReceive(portMAX_DELAY) - must be independent task
     * ======================================================================== */
    os_status = xTaskCreate((TaskFunction_t)PICC_Rx_Msg_10ms_Task,
                            "App_Rx_Msg",
                            OSTASK_RX_MSG_STACK_SIZE,
                            NULL,
                            tskIDLE_PRIORITY + 3,
                            NULL);
    if (os_status != pdPASS) {
        taskDISABLE_INTERRUPTS();
        while (1) { /* Task creation failed */ }
    }

    /* ========================================================================
     * Start FreeRTOS scheduler - does NOT return
     * ======================================================================== */
    vTaskStartScheduler();
}

/*==================================================================================================
 *                                      FREERTOS HOOKS
 *==================================================================================================*/

/**
 * @brief FreeRTOS malloc failed hook
 */
void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    while (1) {
        /* block indefinitely */
    }
}

/**
 * @brief FreeRTOS stack overflow hook
 */
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)pxTask;

    taskDISABLE_INTERRUPTS();
    while (1) {
        /* block indefinitely */
    }
}

#if defined(__cplusplus)
}
#endif
