/**
 * @file picc_pwr_main.c
 * @brief Power Management Module - Main Logic Layer Implementation
 *
 * Implements power management core functionality:
 * - Power state notification (Event ID=1)
 * - Power control command (Event ID=4)
 * - Power mode state acknowledgement handling (Method ID=2)
 * - Power event completion notification handling (Method ID=8)
 * - Power control command acknowledgement handling (Method ID=11)
 * - Two-phase shutdown state machine
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_pwr_main.h"
#include "picc_service.h"   /* For PICC_RegisterMethodHandler, PICC_SendEvent */
#include "Picc_main.h"           /* For HANDLE_ERROR */
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */

/* External timing diagnostic variables from pwsm.c */
extern uint16 Pwsm_RxMsgTimeOutId8;

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Whether initialized */
static boolean g_pwrInitialized = FALSE;

/** Power management state machine */
static volatile Power_StateMachine_e g_stateMachine = PWR_SM_IDLE;

/** Reception status flags - for PWSM to query */
static volatile boolean g_stateAckReceived = FALSE;    /**< Method ID=2 received */
static volatile boolean g_phase1DoneReceived = FALSE;  /**< Method ID=8 received */
static volatile boolean g_ctrlAckReceived = FALSE;     /**< Method ID=11 received */

/** Payload data storage for application layer access */
#define PWR_MAX_PAYLOAD_LEN  (8U)  /**< Maximum payload length to store */

typedef struct {
    uint8  data[PWR_MAX_PAYLOAD_LEN];  /**< Payload data */
    uint16 len;                         /**< Actual payload length */
} Pwr_PayloadData_t;

static Pwr_PayloadData_t g_stateAckPayload = {0};   /**< Method ID=2 payload */
static Pwr_PayloadData_t g_phase1DonePayload = {0}; /**< Method ID=8 payload */
static Pwr_PayloadData_t g_ctrlAckPayload = {0};    /**< Method ID=11 payload */

/*==================================================================================================
 *                                         Application Layer Callback Handlers
 *
 * These functions are called when M-Core receives Method requests from A-Core.
 * Application layer can add custom logic in these functions.
 *==================================================================================================*/

/**
 * @brief Power state acknowledgement handler (Method ID=2)
 */
 void Pwr_InternalStateAckHandler(const uint8 *payload, uint16 payloadLen)
{
    uint8 coreId;
    uint16 copyLen;
    uint16 i;
    
    if ((payload == NULL) || (payloadLen < 2U)) {
        return;
    }
    
    coreId = payload[0];
    
    if (coreId != PWR_CORE_A) {
        return;
    }
    
    /* Save payload for application layer */
    copyLen = (payloadLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : payloadLen;
    for (i = 0U; i < copyLen; i++) {
        g_stateAckPayload.data[i] = payload[i];
    }
    g_stateAckPayload.len = payloadLen;
    
    /* Note: State machine transition is controlled by PWSM (pwsm.c) */
    /* This handler only sets the flag, PWSM polls it and controls the flow */
    
    /* Set flag to notify PWSM application layer */
    g_stateAckReceived = TRUE;
}

/**
 * @brief Power event completion handler (Method ID=8)
 */
static void Pwr_InternalDoneHandler(const uint8 *payload, uint16 payloadLen)
{
    Power_DoneType_e doneType;
    uint16 copyLen;
    
    if ((payload == NULL) || (payloadLen < 1U)) {
        return;
    }
    
    doneType = (Power_DoneType_e)payload[0];
    
    if (doneType == PWR_DONE_FIRST_STEP) {
        /* A-Core phase 1 shutdown complete */
        /* Note: State machine transition is controlled by PWSM (pwsm.c) */
        /* This handler only sets the flag, PWSM polls it and controls Event ID=4 sending */
        
        /* Save payload for application layer */
        copyLen = (payloadLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : payloadLen;
        for (uint16 i = 0U; i < copyLen; i++) {
            g_phase1DonePayload.data[i] = payload[i];
        }
        g_phase1DonePayload.len = payloadLen;
        
        /* Set flag to notify PWSM application layer */
        g_phase1DoneReceived = TRUE;
    }
}

/**
 * @brief Power control command acknowledgement handler (Method ID=11)
 */
static void Pwr_InternalCtrlAckHandler(const uint8 *payload, uint16 payloadLen)
{
    uint8 coreId;
    uint16 copyLen;
    
    if ((payload == NULL) || (payloadLen < 2U)) {
        return;
    }
    
    coreId = payload[0];
    
    if (coreId != PWR_CORE_A) {
        return;
    }
    
    /* Save payload for application layer */
    copyLen = (payloadLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : payloadLen;
    for (uint16 i = 0U; i < copyLen; i++) {
        g_ctrlAckPayload.data[i] = payload[i];
    }
    g_ctrlAckPayload.len = payloadLen;
    
    /* Note: State machine transition is controlled by PWSM (pwsm.c) */
    /* This handler only sets the flag, PWSM polls it and controls the flow */
    
    /* Set flag to notify PWSM application layer */
    g_ctrlAckReceived = TRUE;
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Initialize power management module
 */
sint8 Pwr_Init(void)
{
    sint8 ret = 0;
    
    if (PWR_SERVICE_ROLE == PICC_ROLE_SERVER) {
        /* Server role: Receive and handle A-Core Method requests */
        ret = PICC_RegisterMethodHandler(PWR_PROVIDER_ID, Pwr_MethodHandler);
        if (ret != 0) {
            return ret;
        }
    }
    
    g_stateMachine = PWR_SM_IDLE;
    g_pwrInitialized = TRUE;

    return 0;
}

/**
 * @brief Deinitialize power management module
 */
void Pwr_Deinit(void)
{
    g_pwrInitialized = FALSE;
    g_stateMachine   = PWR_SM_IDLE;
}

/**
 * @brief Method request handler (M-Core as Server handles A-Core requests)
 */
uint8 Pwr_MethodHandler(uint8 consumerId, uint8 methodId,
                        const uint8 *reqData, uint16 reqLen,
                        uint8 *rspData, uint16 *rspLen)
{
    (void)consumerId;
    (void)rspData;

    *rspLen = 0U;  /* Default no response data */

    if (methodId == PWR_METHOD_STATE_ACK) {
        Pwr_InternalStateAckHandler(reqData, reqLen);
    } else if (methodId == PWR_METHOD_EVENT_DONE) {
        Pwr_InternalDoneHandler(reqData, reqLen);
    } else if (methodId == PWR_METHOD_CTRL_ACK) {
        Pwr_InternalCtrlAckHandler(reqData, reqLen);
    }

    return (uint8)PICC_RET_OK;
}

/**
 * @brief Send power state notification (Event ID=1)
 */
sint8 Pwr_SendStateNotify(Power_State_e state)
{
    uint8 payload[1];

    if (g_pwrInitialized == FALSE) {
        HANDLE_ERROR(-1);
        return -1;
    }

    payload[0] = (uint8)state;

    return PICC_SendEvent(PWR_PROVIDER_ID,
                          PWR_EVENT_STATE_NOTIFY,
                          PWR_CONSUMER_ID,
                          payload, 1U,
                          PICC_EVENT_WITH_ACK,
                          g_piccConfig.channelId);
}

/**
 * @brief Send power control command (Event ID=4)
 */
sint8 Pwr_SendCtrlCmd(Power_Cmd_e cmd)
{
    uint8 payload[2];

    if (g_pwrInitialized == FALSE) {
        HANDLE_ERROR(-1);
        return -1;
    }

    payload[0] = PWR_CORE_A;
    payload[1] = (uint8)cmd;

    return PICC_SendEvent(PWR_PROVIDER_ID,
                          PWR_EVENT_CTRL_CMD,
                          PWR_CONSUMER_ID,
                          payload, 2U,
                          PICC_EVENT_WITH_ACK,
                          g_piccConfig.channelId);
}

/**
 * @brief Initiate power shutdown process (async, non-blocking)
 */
sint8 Pwr_StartShutdown(void)
{
    sint8 ret;
    
    if (g_stateMachine != PWR_SM_IDLE) {
        return -1;  /* Shutdown in progress */
    }
    
    if (PICC_GetLinkState(g_piccConfig.channelId) != PICC_LINK_STATE_CONNECTED) {
        return -2;
    }
    
    ret = Pwr_SendStateNotify(PWR_STATE_STANDBY);
    if (ret != 0) {
        return -3;
    }
    
    g_stateMachine = PWR_SM_WAIT_STATE_ACK;
    
    return 0;
}

/**
 * @brief Get power state machine state
 */
Power_StateMachine_e Pwr_GetState(void)
{
    return g_stateMachine;
}

/*==================================================================================================
 *                                         Reception Flag Query APIs (for PWSM)
 *==================================================================================================*/

/**
 * @brief Check if Method ID=2 (state acknowledgement) was received
 */
boolean Pwr_IsStateAckReceived(void)
{
    return g_stateAckReceived;
}

/**
 * @brief Clear Method ID=2 received flag
 */
void Pwr_ClearStateAckFlag(void)
{
    g_stateAckReceived = FALSE;
}

/**
 * @brief Check if Method ID=8 (phase 1 done) was received
 */
boolean Pwr_IsPhase1DoneReceived(void)
{
    return g_phase1DoneReceived;
}

/**
 * @brief Clear Method ID=8 received flag
 */
void Pwr_ClearPhase1DoneFlag(void)
{
    g_phase1DoneReceived = FALSE;
}

/**
 * @brief Check if Method ID=11 (control ack) was received
 */
boolean Pwr_IsCtrlAckReceived(void)
{
    return g_ctrlAckReceived;
}

/**
 * @brief Clear Method ID=11 received flag
 */
void Pwr_ClearCtrlAckFlag(void)
{
    g_ctrlAckReceived = FALSE;
}

/*==================================================================================================
 *                                         Payload Getter APIs (for Application Layer)
 *==================================================================================================*/

/**
 * @brief Get Method ID=2 (state ack) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetStateAckPayload(uint8 *data, uint16 maxLen)
{
    uint16 copyLen;
    
    if ((data == NULL) || (g_stateAckPayload.len == 0U)) {
        return 0U;
    }
    
    copyLen = (g_stateAckPayload.len > maxLen) ? maxLen : g_stateAckPayload.len;
    copyLen = (copyLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : copyLen;
    
    for (uint16 i = 0U; i < copyLen; i++) {
        data[i] = g_stateAckPayload.data[i];
    }
    
    return g_stateAckPayload.len;
}

/**
 * @brief Get Method ID=8 (phase1 done) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetPhase1DonePayload(uint8 *data, uint16 maxLen)
{
    uint16 copyLen;
    
    if ((data == NULL) || (g_phase1DonePayload.len == 0U)) {
        return 0U;
    }
    
    copyLen = (g_phase1DonePayload.len > maxLen) ? maxLen : g_phase1DonePayload.len;
    copyLen = (copyLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : copyLen;
    
    for (uint16 i = 0U; i < copyLen; i++) {
        data[i] = g_phase1DonePayload.data[i];
    }
    
    return g_phase1DonePayload.len;
}

/**
 * @brief Get Method ID=11 (ctrl ack) payload data
 * @param[out] data   Buffer to copy payload data
 * @param[in]  maxLen Maximum buffer size
 * @return Actual payload length, 0 if not received
 */
uint16 Pwr_GetCtrlAckPayload(uint8 *data, uint16 maxLen)
{
    uint16 copyLen;
    
    if ((data == NULL) || (g_ctrlAckPayload.len == 0U)) {
        return 0U;
    }
    
    copyLen = (g_ctrlAckPayload.len > maxLen) ? maxLen : g_ctrlAckPayload.len;
    copyLen = (copyLen > PWR_MAX_PAYLOAD_LEN) ? PWR_MAX_PAYLOAD_LEN : copyLen;
    
    for (uint16 i = 0U; i < copyLen; i++) {
        data[i] = g_ctrlAckPayload.data[i];
    }
    
    return g_ctrlAckPayload.len;
}

#if defined(__cplusplus)
}
#endif
