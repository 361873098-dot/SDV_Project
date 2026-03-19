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

#include "Mcal.h"
#include "Platform.h"


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
#include "picc_stack.h"     /* For PICC_STACK_MAX_SIZE, PICC_ProcessRxData */

/* Power management configuration (for PWR_PROVIDER_ID, PWR_CONSUMER_ID, etc.) */
#include "picc_pwr_main.h"
#include "picc_pwr_cnf.h"
#include "Port.h"
/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Control channel configuration */
#define CTRL_CHAN_ID            (0U)
#define CTRL_CHAN_SIZE          (64U)

/** Maximum message length */

#define MAX_MSG_LEN             (PICC_STACK_MAX_SIZE)

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
static App_Data_t g_unmngDat;


/** link with generated variables */
const void *rx_mng_cb_arg = &g_appData;

const void *rx_unmg_cb_arg  = &g_unmngDat;


/** Receive queue handle */
static QueueHandle_t g_rxQueue = NULL;

/** Exit code (for main loop) */
volatile uint8 exit_code;

/*==================================================================================================
 *                                         FreeRTOS Static Memory
 *==================================================================================================*/

#if (configSUPPORT_STATIC_ALLOCATION == 1)

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
void PICC_data_mng_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *buf,
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
void PICC_data_unmng_rx_cb(void *arg, const uint8 instance, uint8 chan_id, void *mem)
{
    App_Data_t *appPtr = (App_Data_t *)(*((uintptr *)arg));
    
    (void)instance;
    (void)chan_id;
    (void)mem;

    if (appPtr != &g_unmngDat) {
        HANDLE_ERROR(-IPC_SHM_E_INVAL);
        return;
    }
}

/*==================================================================================================
 *                                         PreOS Initialization
 *==================================================================================================*/

/**
 * @brief PICC Pre-OS Initialization (called from main() before vTaskStartScheduler)
 * 
 * Performs all one-time initialization:
 * - IPCF driver init (internally creates softirq task)
 * - PICC channel/service/link init
 * - Power management init
 * 
 * @note This function does NOT depend on the RTOS scheduler being active.
 *       All FreeRTOS API calls used here (xQueueCreate, xTaskCreate inside
 *       ipc_shm_init) are valid before vTaskStartScheduler().
 */
void PICC_PreOS_Init(void)
{
    sint8 err = -IPC_SHM_E_INVAL;
    PICC_InitConfig_t piccCfg;

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
}

/*==================================================================================================
 *                                         RX Message Task (Event-Driven)
 *==================================================================================================*/

/**
 * @brief RX message processing task (event-driven, queue blocking)
 * 
 * Handles received messages from IPCF.
 * This task blocks on the RX queue waiting for messages.
 * 
 * @note This task MUST remain as an independent FreeRTOS task because it uses
 *       xQueueReceive with portMAX_DELAY (infinite blocking).
 *       It is created by OsTask_Creation_All() in Ostask_main.c.
 */
void App_Rx_Msg_10ms_Task(void *params)
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

#if defined(__cplusplus)
}
#endif
