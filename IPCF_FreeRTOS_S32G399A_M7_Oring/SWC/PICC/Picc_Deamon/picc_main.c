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
#include "picc_mailbox.h"   /* For PICC_StoreToMailbox, PICC_MailboxInit */
#include "picc_stack.h"     /* For PICC_STACK_MAX_SIZE, PICC_StackProcessRx, PICC_StackRegisterMsgCallback */
#include "picc_protocol.h"  /* For PICC_MsgHeader_t, PICC_MSG_LINK_AVAILABLE */
#include "picc_heartbeat.h" /* For PICC_HeartbeatInit, PICC_HeartbeatProcess */
#include "picc_trace.h"     /* For PICC_TraceInit */

#include "Port.h"

/* Forward declaration — defined below PICC_PreOS_Init */
static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 instanceId, uint8 channelId);
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

#if (PICC_DIAG_RECORD_ENABLE == 1U)
/*==================================================================================================
 *                                   Diagnostic Recording Variables
 *==================================================================================================*/

/** Diagnostic record buffer: 20 rows × 30 bytes per row */
#define PICC_DIAG_RECORD_ROWS       (20U)
#define PICC_DIAG_RECORD_COLS       (30U)

/** Diagnostic record structure */
typedef struct {
    uint8   buffer[PICC_DIAG_RECORD_ROWS][PICC_DIAG_RECORD_COLS];  /**< Data buffer */
    uint16  currentRow;                                              /**< Current row index (0-19) */
    uint16  currentCol;                                              /**< Current column index in row */
    uint16  totalRecords;                                            /**< Total records count */
} PICC_DiagRecord_t;

/** Combined diagnostic record (view in TRACE32: Var.View g_diagRecord_Debug) */
typedef struct {
    PICC_DiagRecord_t tx;  /**< TX diagnostic buffer */
    PICC_DiagRecord_t rx;  /**< RX diagnostic buffer */
    PICC_LinkState_e appLinkState[PICC_APP_MAX];       /**< Per-app link state (index=PICC_AppIndex_e, value=PICC_LinkState_e) */
    PICC_LinkState_e  channelLinkState[PICC_MAX_CHANNELS]; /**< Per-channel link state (index=0..1 => channelId 1..2) */
} PICC_ChannelDiag_t;

PICC_ChannelDiag_t g_diagRecord_Debug;


/**
 * @brief Initialize diagnostic record structure
 */
static void PICC_DiagRecordInit(PICC_DiagRecord_t *record)
{
    uint16 i, j;

    if (record == NULL) {
        return;
    }

    for (i = 0U; i < PICC_DIAG_RECORD_ROWS; i++) {
        for (j = 0U; j < PICC_DIAG_RECORD_COLS; j++) {
            record->buffer[i][j] = 0U;
        }
    }

    record->currentRow = 0U;
    record->currentCol = 0U;
    record->totalRecords = 0U;
}

/**
 * @brief Add data to diagnostic record buffer (parse stacked packet, one message per row)
 *
 * Parses stacked packet format:
 *   [CRC_Enable(1B)] [N × Protocol_Message] [Counter(2B)] [CRC(2B)]
 * Each Protocol_Message: [Header(8B)] [Payload(variable)]
 * Header: [ProviderID][MethodID][ConsumerID][SessionID][MsgType][RetCode][Len_Hi][Len_Lo]
 *
 * Each protocol message is stored in its own row:
 *   buffer[row][0..N] = one complete protocol message bytes
 *
 * Heartbeat messages (ProviderID=0xFF or MethodID=0xFF) are filtered out.
 *
 * @param[in] record  Diagnostic record structure
 * @param[in] data    Raw stacked packet data buffer
 * @param[in] len     Data length
 */
static void PICC_DiagRecordAdd(PICC_DiagRecord_t *record, const uint8 *data, uint32 len)
{
    uint32 offset;
    uint16 payloadLen;
    uint32 msgLen;
    uint32 copyLen;
    uint32 col;
    uint16 row;
    const uint8 *msgPtr;

    if (record == NULL || data == NULL || len == 0U) {
        return;
    }

    /* Minimum stacked packet: [CRC_Enable 1B][Header 8B][Counter 2B][CRC 2B] = 13 bytes */
    if (len < 13U) {
        return;
    }

    /* Parse stacked packet: skip CRC_Enable byte, parse until Counter/CRC area */
    /* Data area ends at len - 4 (2B Counter + 2B CRC) */
    offset = 1U;  /* Skip CRC_Enable byte */

    while (offset + PICC_HEADER_SIZE <= (len - 4U)) {
        msgPtr = &data[offset];

        /* Get payload length from header bytes 6-7 (big-endian) */
        payloadLen = ((uint16)msgPtr[6] << 8U) | (uint16)msgPtr[7];
        msgLen = PICC_HEADER_SIZE + payloadLen;

        /* Sanity check: message should not exceed remaining data area */
        if (offset + msgLen > (len - 4U)) {
            break;
        }

        /* Filter heartbeat messages (ProviderID=0xFF or MethodID=0xFF) */
        if ((msgPtr[0] == 0xFFU) || (msgPtr[1] == 0xFFU)) {
            offset += msgLen;
            continue;
        }



        /* Store this protocol message in a new row */
        row = record->currentRow;

        /* Copy message bytes (limited by column width) */
        copyLen = msgLen;
        if (copyLen > PICC_DIAG_RECORD_COLS) {
            copyLen = PICC_DIAG_RECORD_COLS;
        }

        for (col = 0U; col < copyLen; col++) {
            record->buffer[row][col] = msgPtr[col];
        }

        /* Clear remaining columns in this row */
        for (col = copyLen; col < PICC_DIAG_RECORD_COLS; col++) {
            record->buffer[row][col] = 0U;
        }

        /* Advance to next row (circular) */
        record->currentRow++;
        if (record->currentRow >= PICC_DIAG_RECORD_ROWS) {
            record->currentRow = 0U;
        }

        record->totalRecords++;

        /* Move to next message in stacked packet */
        offset += msgLen;
    }
}

#endif /* PICC_DIAG_RECORD_ENABLE */

#if (PICC_DIAG_RECORD_ENABLE == 1U)
/**
 * @brief Add TX data to diagnostic record buffer (called from picc_stack.c)
 *
 * @param[in] data    Data buffer to record
 * @param[in] len     Data length
 */
void PICC_DiagRecordAddTx(const uint8 *data, uint32 len)
{
    PICC_DiagRecordAdd(&g_diagRecord_Debug.tx, data, len);
}

/**
 * @brief Update link state diagnostic fields in g_diagRecord_Debug
 *
 * Reads current app-level link state (per PICC_AppIndex_e) and
 * channel-level link state (channelId 1 and 2) into the diagnostic
 * structure, so TRACE32 can inspect them via:
 *   Var.View g_diagRecord_Debug.appLinkState
 *   Var.View g_diagRecord_Debug.channelLinkState
 *
 * Values: 0=DISCONNECTED, 1=CONNECTING, 2=CONNECTED
 *
 * Called from TASK_M0_10MS() periodic task.
 */
void PICC_DiagUpdateLinkState(void)
{
    uint8 i;

    /* Update per-app link states */
    for (i = 0U; i < (uint8)PICC_APP_MAX; i++) {
        g_diagRecord_Debug.appLinkState[i] = PICC_GetAppLinkState((PICC_AppIndex_e)i);
    }

    /* Update per-channel link states (channelId 1 and 2 mapped to index 0 and 1) */
    g_diagRecord_Debug.channelLinkState[0] = PICC_GetLinkState(1U);
    g_diagRecord_Debug.channelLinkState[1] = PICC_GetLinkState(2U);
}
#endif /* PICC_DIAG_RECORD_ENABLE */

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
        PICC_HANDLE_ERROR(-IPC_SHM_E_INVAL);
        return;
    }

    appPtr->last_rx_ch = chan_id;

#if (PICC_DIAG_RECORD_ENABLE == 1U)
    /* Record received data to diagnostic buffer (excludes heartbeat) */
    PICC_DiagRecordAdd(&g_diagRecord_Debug.rx, (const uint8 *)buf, size);
#endif

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
        PICC_HANDLE_ERROR(-IPC_SHM_E_INVAL);
        return;
    }
}

/*==================================================================================================
 *                                   Infrastructure Initialization
 *==================================================================================================*/

/**
 * @brief Heartbeat timeout handler — triggers link reconnect
 */
static void PICC_HeartbeatTimeoutHandler(uint8 instanceId, uint8 channelId)
{
    PICC_LinkTriggerReconnect(instanceId, channelId);
}

/**
 * @brief Initialize PICC infrastructure (trace, service layer, mailbox)
 *
 * Called by PICC_PreOS_Init() before channel initialization.
 */
void PICC_InfraInit(void)
{
    /* 1. Initialize debug trace module */
    PICC_TraceInit();

    /* 2. Initialize service layer registry */
    PICC_ServiceLayerInit();

    /* 3. Stack message callback is registered separately in PICC_PreOS_Init */

    /* 4. Initialize app contexts and mailboxes */
    PICC_MailboxInit();

    /* 5. One-time initialization of link management layer (per-app contexts) */
    PICC_LinkLayerInit();
}

/**
 * @brief Initialize specified IPCF channel (Stack + Heartbeat)
 *
 * Called by PICC_PreOS_Init() for each channel.
 */
sint8 PICC_InitChannel(uint8 instanceId, uint8 channelId)
{
    PICC_StackConfig_t stackCfg;
    sint8 ret;
    static boolean heartbeatInitialized = FALSE;

    /* 1. Initialize heartbeat module on first channel init */
    if (heartbeatInitialized == FALSE) {
        ret = PICC_HeartbeatInit();
        if (ret != 0) {
            return PICC_E_NOT_INIT;
        }
        (void)PICC_HeartbeatRegisterTimeoutCallback(PICC_HeartbeatTimeoutHandler);
        heartbeatInitialized = TRUE;
    }

    /* 2. Initialize Stack layer for this channel */
    stackCfg.channelId  = channelId;
    stackCfg.maxSize    = PICC_STACK_MAX_SIZE;
    stackCfg.periodMs   = PICC_STACK_SEND_PERIOD_MS;
    stackCfg.crcEnabled = PICC_STACK_CRC_ENABLED;
    ret = PICC_StackInitChannel(&stackCfg);
    if (ret != 0) {
        return ret;
    }

    /* 3. Add channel to heartbeat monitoring */
    ret = PICC_HeartbeatAddChannel(instanceId, channelId);
    if (ret != 0) {
        return ret;
    }

    return PICC_E_OK;
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
 * 
 * @note This function does NOT depend on the RTOS scheduler being active.
 *       All FreeRTOS API calls used here (xQueueCreate, xTaskCreate inside
 *       ipc_shm_init) are valid before vTaskStartScheduler().
 */
void PICC_PreOS_Init(void)
{
    sint8 err = -IPC_SHM_E_INVAL;

    /* ========================================================================
     * 1. Initialize receive queue
     * ======================================================================== */
    g_rxQueue = xQueueCreate(10, sizeof(App_RxMsg_t));
    if (g_rxQueue == NULL) {
        PICC_HANDLE_ERROR(-1);
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

#if (PICC_DIAG_RECORD_ENABLE == 1U)
    /* Initialize diagnostic record buffers */
    PICC_DiagRecordInit(&g_diagRecord_Debug.rx);
    PICC_DiagRecordInit(&g_diagRecord_Debug.tx);

    /* Initialize link state diagnostic fields */
    for (uint8 k = 0U; k < (uint8)PICC_APP_MAX; k++) {
        g_diagRecord_Debug.appLinkState[k] = (uint8)PICC_LINK_STATE_DISCONNECTED;
    }
    g_diagRecord_Debug.channelLinkState[0] = (uint8)PICC_LINK_STATE_DISCONNECTED;
    g_diagRecord_Debug.channelLinkState[1] = (uint8)PICC_LINK_STATE_DISCONNECTED;
#endif

    /* ========================================================================
     * 3. Initialize IPCF driver
     * ======================================================================== */
    do {
        err = ipc_shm_init(&ipcf_shm_instances_cfg);
    } while (err == -IPC_SHM_E_REMOTE_INIT_IN_PROGRESS);
    
    if (err != 0) {
        PICC_HANDLE_ERROR(err);
    }

    if (ipc_shm_is_remote_ready(IPCF_INSTANCE0) != 0) {
        /* Remote not ready, but don't block */
    }

    /* Get control channel memory */
    g_appData.ctrl_shm = ipc_shm_unmanaged_acquire(IPCF_INSTANCE0, CTRL_CHAN_ID);
    if (g_appData.ctrl_shm == NULL) {
        PICC_HANDLE_ERROR(-IPC_SHM_E_NOMEM);
    }

    /* ========================================================================
     * 4. Initialize PICC infrastructure (trace, service layer)
     * ======================================================================== */
    PICC_InfraInit();

    /* ========================================================================
     * 4b. Register stack message callback (message dispatcher)
     * ======================================================================== */
    (void)PICC_StackRegisterMsgCallback(PICC_ProcessSingleMessage);

    /* ========================================================================
     * 5. Initialize IPCF channels (Stack + Heartbeat)
     * [R6] Heartbeat starts immediately, independent of connection state
     * ======================================================================== */
    err = PICC_InitChannel(IPCF_INSTANCE0, 1U);
    if (err != 0) {
        PICC_HANDLE_ERROR(err);
    }

    err = PICC_InitChannel(IPCF_INSTANCE0, 2U);
    if (err != 0) {
        PICC_HANDLE_ERROR(err);
    }

    /* ========================================================================
     * NOTE: Application-specific initialization (PICC_Init per app) is now
     *       performed by each application's own Xxx_Init() function,
     *       e.g. Pwsm_Init() calls PICC_Init(PICC_APP_PWR, &cfg).
     *       This is called from Ostask_main.c after PICC_PreOS_Init().
     * ======================================================================== */
}

/*==================================================================================================
 *                                    Message Dispatching
 *==================================================================================================*/

/**
 * @brief Process single decoded message (callback registered with Stack layer)
 *
 * 1. Link messages -> PICC_LinkProcessMessage
 * 2. Service messages -> Store to mailbox, then dispatch to service layer
 */
static void PICC_ProcessSingleMessage(const PICC_MsgHeader_t *header,
                                      const uint8 *payload, uint16 payloadLen,
                                      uint8 instanceId, uint8 channelId)
{
    if (header == NULL) {
        return;
    }

    if (header->msgType == (uint8)PICC_MSG_LINK_AVAILABLE) {
        /* Link message — handled by Link layer directly */
        (void)PICC_LinkProcessMessage(header, payload, payloadLen, instanceId, channelId);
    } else {
        uint8  cbResult[PICC_CB_RESULT_MAX_LEN];
        uint16 cbResultLen = 0U;

        /* Store to mailbox FIRST (so polling always works) */
        PICC_StoreToMailbox(header, payload, payloadLen);

        /* Dispatch to service layer — callback writes cbResult */
        (void)PICC_ServiceProcessMessage(header, payload, payloadLen,
                                         instanceId, channelId,
                                         cbResult, &cbResultLen);

        /* Store callback result into the same mailbox slot */
        if (cbResultLen > 0U) {
            PICC_StoreCallbackResult(header, cbResult, cbResultLen);
        }
    }
}

/*==================================================================================================
 *                                         RX Message Task (Event-Driven)
 *==================================================================================================*/

/**
 * @brief Process received IPCF raw data
 * 
 * Unpacks the stacked format and dispatches individual messages
 * via PICC_StackProcessRx -> PICC_ProcessSingleMessage callback.
 *
 * @param[in] instance  IPCF instance
 * @param[in] chan_id   Channel ID
 * @param[in] buf       Raw data buffer
 * @param[in] size      Buffer size
 * @return PICC_E_OK on success, negative on failure
 */
static sint8 PICC_ProcessRxData(const uint8 instance, uint8 chan_id,
                                 const void *buf, uint32 size)
{
    const uint8 *data;
    sint8 ret;

    if (buf == NULL) {
        return PICC_E_PARAM;
    }

    data = (const uint8 *)buf;

    if (size >= PICC_STACK_OVERHEAD_SIZE) {
        ret = PICC_StackProcessRx(data, size, instance, chan_id);
        if (ret >= 0) {
            return PICC_E_OK;
        }
        return PICC_E_PARAM;
    }

    return PICC_E_PARAM;
}

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
void PICC_Rx_Msg_10ms_Task(void *params)
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
void PICC_handle_error(sint8 error, const char *file, int line)
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
