/**
 * @file main.c
 * @brief M-Core Inter-Core Communication Application - Main Program
 *
 * IPC Shared Memory Driver application with PICC middleware.
 * Integrates PICC inter-core communication middleware module for A-Core communication.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C"{
#endif

/*==================================================================================================
 *                                         Header Includes
 *==================================================================================================*/
#include "Mcu.h"
/* MCU/Platform initialization */
#include "Mcal.h"
#include "Platform.h"
#include "CDD_Pmic.h"
#include "CDD_I2c.h"

/* Application headers */
#include "Picc_main.h"

/* IPCF driver */
#include "ipc-shm.h"
#include "ipcf_Ip_Cfg_Defines.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* PICC module */
#include "picc_api.h"
#include "picc_stack.h"     /* For PICC_StackProcess */
#include "picc_heartbeat.h" /* For PICC_HeartbeatProcess */
#include "picc_link.h"      /* For PICC_LinkProcess */

/* Power management module */
#include "picc_pwr_main.h"
#include "picc_pwr_cnf.h"
#include "pwsm.h"
#include "Port.h"
/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Main task stack size (512 words = 2KB) */
#define MAIN_TASK_STACK_SIZE    (512U)


#define PICC_INIT_TASK_STACK_SIZE   (256U)  // 1KB
#define RX_TASK_STACK_SIZE          (192U)  // 768B
#define PERIODIC_TASK_STACK_SIZE    (256U)  // 1KB


/** Control channel configuration */
#define CTRL_CHAN_ID            (0U)
#define CTRL_CHAN_SIZE          (64U)

/** Maximum message length */
#define MAX_MSG_LEN             (PICC_STACK_MAX_SIZE)

/** Wait timeout */
#define WAIT_TIMEOUT            (1000U / portTICK_PERIOD_MS)

/*==================================================================================================
 *                                         Private Type Definitions
 *==================================================================================================*/

/**
 * @brief Application private data
 */
typedef struct {
    sint8          *ctrl_shm;      /**< Control channel shared memory */
    volatile uint16 rx_count;      /**< Receive message count */
    volatile uint16 tx_count;      /**< Send/Process message count */
    volatile uint16 error_count;   /**< Error count */
    volatile sint8  last_error;    /**< Last error code */
    volatile uint8  link_state;    /**< Current connection state */
    const char     *error_file;    /**< Error occurred file name */
    int             error_line;    /**< Error occurred line number */
    uint8           last_rx_ch;    /**< Last receive channel */
} App_Data_t;

/**
 * @brief Receive message structure (for queue)
 */
typedef struct {
    uint8   instance;   /**< IPCF instance */
    uint8   chanId;     /**< Channel ID */
    void   *buf;        /**< Buffer pointer */
    uint32  size;       /**< Data size */
    boolean isManaged;  /**< TRUE=Managed(needs release), FALSE=Unmanaged */
} App_RxMsg_t;

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Application data */
static App_Data_t g_appData;

/** link with generated variables */
const void *rx_cb_arg = &g_appData;

/** Receive queue handle */
static QueueHandle_t g_rxQueue = NULL;

/** Exit code (for main loop) */
volatile uint8 exit_code;

uint32 task_M7_0_10ms_cnt = 0;

uint16 read_m_deviceid;
uint16 read_m_mode;
uint16 read_m_flag1;
uint16 read_m_flag2;
uint16 read_m_flag3_0;
uint16 read_m_flag3;
uint16 read_fs_state;
uint16 read_m_otp_vpre;
uint32 TestLoopCnt = 999999999;
uint32 loop_cnt = 0;
/*==================================================================================================
 *                                         FreeRTOS Static Memory
 *==================================================================================================*/

#if (configSUPPORT_STATIC_ALLOCATION == 1)

static StackType_t xStack[MAIN_TASK_STACK_SIZE];
static StaticTask_t xTaskBuffer;

static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
        StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

#if (configUSE_TIMERS == 1)
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
        StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
#endif

#endif /* configSUPPORT_STATIC_ALLOCATION */

/*==================================================================================================
 *                                         PICC Callback Functions
 *==================================================================================================*/

/**
 * @brief Connection state change callback
 */
static void App_LinkStateCallback(uint8 remoteId, PICC_LinkState_e state)
{
    (void)remoteId;
    
    if (state == PICC_LINK_STATE_CONNECTED) {
        /* Connected */
    } else if (state == PICC_LINK_STATE_DISCONNECTED) {
        /* Disconnected */
    } else {
        /* Connecting */
    }
    
    g_appData.link_state = (uint8)state;
}

/*==================================================================================================
 *                                         IPCF Callback Functions
 *==================================================================================================*/

/**
 * @brief Data channel receive callback - ISR context
 * 
 * @note Only pushes message to queue, no complex processing
 */
void data_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *buf,
        uint32 size)
{
    App_Data_t *appPtr = (App_Data_t *)(*((uintptr *)arg));
    App_RxMsg_t msg;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    (void)instance;

    if (appPtr != &g_appData || size > MAX_MSG_LEN) {
        HANDLE_ERROR(-IPC_SHM_E_INVAL);
        return;
    }

    appPtr->last_rx_ch = chan_id;

    /* Construct message */
    msg.instance  = instance;
    msg.chanId    = chan_id;
    msg.buf       = buf;
    msg.size      = size;
    msg.isManaged = TRUE;

    /* Push to queue (non-blocking) */
    if (g_rxQueue != NULL) {
        if (xQueueSendFromISR(g_rxQueue, &msg, &xHigherPriorityTaskWoken) != pdPASS) {
            (void)ipc_shm_release_buf(instance, chan_id, buf);
            appPtr->error_count++;

        }
    } else {
        (void)ipc_shm_release_buf(instance, chan_id, buf);
    }

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * @brief Control channel receive callback - ISR context
 */
void ctrl_chan_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *mem)
{
    App_Data_t *appPtr = (App_Data_t *)(*((uintptr *)arg));
    
    (void)instance;
    (void)chan_id;
    (void)mem;

    if (appPtr != &g_appData) {
        HANDLE_ERROR(-IPC_SHM_E_INVAL);
        return;
    }
}

/*==================================================================================================
 *                                         Initialization Task
 *==================================================================================================*/

/**
 * @brief PICC Initialization Task
 * 
 * Performs all one-time initialization:
 * - IPCF driver init
 * - PICC channel/service/link init
 * - Power management init
 * 
 * Deletes itself after initialization completes.
 * Periodic tasks are handled by App_Main_10ms_Task.
 */
static void PICC_Init_Task(void *params)
{
    sint8 err = -IPC_SHM_E_INVAL;
    PICC_InitConfig_t piccCfg;

    (void)params;

    /* ========================================================================
     * 1. Initialize receive queue
     * ======================================================================== */
    g_rxQueue = xQueueCreate(10, sizeof(App_RxMsg_t));
    if (g_rxQueue == NULL) {
        HANDLE_ERROR(-1);
    }

    /* ========================================================================
     * 2. Initialize application data
     * ======================================================================== */
    g_appData.rx_count    = 0U;
    g_appData.tx_count    = 0U;
    g_appData.error_count = 0U;
    g_appData.last_error  = 0;
    g_appData.error_file  = NULL;
    g_appData.error_line  = 0;
    g_appData.link_state  = (uint8)PICC_LINK_STATE_DISCONNECTED;

    /* ========================================================================
     * 3. Initialize IPCF driver
     * ======================================================================== */
    do {
        err = ipc_shm_init(&ipcf_shm_instances_cfg);
    } while (err == -IPC_SHM_E_REMOTE_INIT_IN_PROGRESS);
    
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    /* Remove blocking wait, allow program to continue */
    if (ipc_shm_is_remote_ready(IPCF_INSTANCE0) != 0) {
        /* Remote not ready, but don't block */
    }

    /* Get control channel memory */
    g_appData.ctrl_shm = ipc_shm_unmanaged_acquire(IPCF_INSTANCE0, CTRL_CHAN_ID);
    if (g_appData.ctrl_shm == NULL) {
        HANDLE_ERROR(-IPC_SHM_E_NOMEM);
    }

    /* ========================================================================
     * 4. Initialize IPCF channels (Stack + Heartbeat) - CHANNEL LAYER
     * [R6] Heartbeat starts immediately, independent of connection state
     * ======================================================================== */
    err = PICC_InitChannel(IPCF_INSTANCE0, 1U);
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    err = PICC_InitChannel(IPCF_INSTANCE0, 2U);
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    /* ========================================================================
     * 5. Initialize PICC application infrastructure (Service Layer)
     * ======================================================================== */
    piccCfg.linkLocalId  = PWR_PROVIDER_ID;
    piccCfg.linkRemoteId = PWR_CONSUMER_ID;
    piccCfg.linkRole     = PICC_ROLE_SERVER;
    piccCfg.channelId    = PWR_CHANNEL_ID;

    err = PICC_Init(&piccCfg);
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    /* ========================================================================
     * 6. Register application-level Link (Power Management)
     * ======================================================================== */
    err = PICC_LinkRegister(&piccCfg);
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    /* ========================================================================
     * 7. Initialize power management module
     * ======================================================================== */
    err = Pwr_Init();
    if (err != 0) {
        HANDLE_ERROR(err);
    }

    /* ========================================================================
     * 8. Register Link state callback
     * ======================================================================== */
    (void)PICC_RegisterLinkStateCallback(App_LinkStateCallback);

    /* ========================================================================
     * Initialization complete - delete this task
     * ======================================================================== */
    vTaskDelete(NULL);
}

/*==================================================================================================
 *                                         Main 10ms Task
 *==================================================================================================*/

/**
 * @brief Main 10ms periodic task
 * 
 * Handles received messages from IPCF.
 * This task blocks on the RX queue waiting for messages.
 */
static void App_Rx_Msg_10ms_Task(void *params)
{
    App_RxMsg_t rxMsg;
    sint8 err;

    (void)params;

  

    /* Main loop - process received messages */
    while (1) {
        if (xQueueReceive(g_rxQueue, &rxMsg, portMAX_DELAY) == pdPASS) {
            
            /* Process received message */
            (void)PICC_ProcessRxData(rxMsg.instance, rxMsg.chanId, rxMsg.buf, rxMsg.size);
            
            /* Release buffer (Managed channel only) */
            if (rxMsg.isManaged != FALSE) {
                err = ipc_shm_release_buf(rxMsg.instance, rxMsg.chanId, rxMsg.buf);
                if (err != 0) {
                    /* Log release error */
                }
            }
            
            g_appData.tx_count++;
        }
    }
}

/*==================================================================================================
 *                                         Error Handling
 *==================================================================================================*/

/**
 * @brief Error handling function
 * 
 * @note Only records error, doesn't block system, allows continued execution for debugging
 */
void handle_error(sint8 error, const char *file, int line)
{
    g_appData.last_error = error;
    g_appData.error_file = file;
    g_appData.error_line = line;
    g_appData.error_count++;
    
    /* Only record error, don't block */
    /* To block for fatal error debugging, uncomment below */
    /*
    taskDISABLE_INTERRUPTS();
    while (1) { }
    */
}


/***********************************************************************************************************************
 *  Function name    : task_M7_0_10ms()
 *
 *  Description      : Periodic task on core M7_0 (10ms period)
 *                     Handles PICC communication and power state machine.
 *
 *  List of arguments: none
 *
 *  Return value     : none
 *
 ***********************************************************************************************************************/
void task_M7_0_10ms( void *pvParameters )
{
    TickType_t xLastWakeTime;
    const TickType_t xPeriod = pdMS_TO_TICKS(10);  /* 10ms period */
    
    (void)pvParameters;
    
    /* Initialize the xLastWakeTime variable with current time */
    xLastWakeTime = xTaskGetTickCount();

    for(;;)
    {
        task_M7_0_10ms_cnt++;

        /* PICC Stack: Send buffered messages on all channels */
        PICC_StackProcess();

        /* PICC Heartbeat: Send Ping every 2000ms */
        PICC_HeartbeatProcess();

        /* PICC Link: Handle connection requests (Client mode) */
        PICC_LinkProcess();

        /* Power State Machine */
        Pwsm_Main();

        /* [FIX] Wait until next 10ms period - allows lower priority tasks to run */
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}


/*==================================================================================================
 *                                         Initialization Entry
 *==================================================================================================*/

/**
 * @brief Prepare and start tasks
 * 
 * Creates the following tasks:
 * - PICC_Init_Task: One-time initialization (priority 4, deletes itself)
 * - App_Main_10ms_Task: RX message processing (priority 1)
 * - task_M7_0_10ms: PICC periodic + Power state machine (priority 2)
 */
void PICC_Mian_Task(void)
{
#if (configSUPPORT_DYNAMIC_ALLOCATION == 1)
    BaseType_t os_status;

    /* Create initialization task (high priority, runs once then deletes itself) */
    os_status = xTaskCreate((TaskFunction_t)PICC_Init_Task,
                "PICC_Init_Task",
                PICC_INIT_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 4,  /* High priority for init */
                NULL);
    if (os_status != pdPASS) {
        HANDLE_ERROR((sint8)os_status);
    }

    /* Create main RX processing task
     * [FIX] Priority 3 (higher than task_M7_0_10ms priority 2)
     * Ensures messages are processed before state machine checks flags
     * This fixes the race condition where Method ID=8 arrived but flag not yet set
     */
    os_status = xTaskCreate((TaskFunction_t)App_Rx_Msg_10ms_Task,
                "App_Main_10ms",
                RX_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 3,
                NULL);
    if (os_status != pdPASS) {
        HANDLE_ERROR((sint8)os_status);
    }

    /* Create power state machine task */
    os_status = xTaskCreate((TaskFunction_t)task_M7_0_10ms,
                "task_M7_0_10ms",
                PERIODIC_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 2,
                NULL);
    if (os_status != pdPASS) {
        HANDLE_ERROR((sint8)os_status);
    }

#endif

#if (configSUPPORT_STATIC_ALLOCATION == 1)
    xTaskCreateStatic((TaskFunction_t)PICC_Init_Task,
                "PICC_Init_Task",
                MAIN_TASK_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 4,
                xStack,
                &xTaskBuffer);
#endif

    vTaskStartScheduler();
}

/*==================================================================================================
 *                                         FreeRTOS Hooks
 *==================================================================================================*/

void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    while (1) {
        /* block indefinitely */
    }
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)pxTask;

    taskDISABLE_INTERRUPTS();
    while (1) {
        /* block indefinitely */
    }
}

/*==================================================================================================
 *                                         main() Entry
 *==================================================================================================*/

/**
 * @brief Application entry point
 */
int main(void)
{

    /* Initialize pins */
   Port_Init(NULL_PTR);

    /* Platform initialization */
    Platform_Init(NULL_PTR);

    /* Initialize I2c driver */
    I2c_Init(NULL_PTR);

	/* Initialize Pmic driver */
	Pmic_Init(NULL_PTR);

	/* Install Gpio ISR */

   /* Initialize Vr5510 device */
	Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);


	/*	Read FLAG3 Register	*/
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, &read_m_flag3_0);
  /*	Read M_DEVICEID Register	*/
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_DEVICEID_ADDR8, &read_m_deviceid);

  /*	Read M_MODE Register	*/
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, &read_m_mode);

  /*	Read M_FLAG Register	*/
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG1_ADDR8, &read_m_flag1);
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG2_ADDR8, &read_m_flag2);
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, &read_m_flag3);

  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CFG_VPRE_2_OTP_ADDR8, &read_m_otp_vpre);

  /*	Read FS_STATE Register	*/
  Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &read_fs_state);


    /* Start main task */
    PICC_Mian_Task();

    /* Main loop (normally won't reach here) */
    for (;;) {
    	if (exit_code != 0) {
            break;
        }
    }
    
    return exit_code;
}

#if defined(__cplusplus)
}
#endif
