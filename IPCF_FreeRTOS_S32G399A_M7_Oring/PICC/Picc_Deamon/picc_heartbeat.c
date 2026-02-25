/**
 * @file picc_heartbeat.c
 * @brief M-Core Inter-Core Communication Heartbeat Layer - Implementation
 *
 * Low-level heartbeat (Ping/Pong) functionality for IPC channel health monitoring.
 * Independent of application-level connection state (no CONSUMER_ID/PROVIDER_ID).
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "picc_heartbeat.h"
#include "FreeRTOS.h"
#include "Picc_main.h"    /* For HANDLE_ERROR */
#include "ipcf_Ip_Cfg_Defines.h"  /* For IPCF_INSTANCE0 */
#include "picc_stack.h"

/* NOTE: timers.h removed - no longer using FreeRTOS timers */

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Heartbeat timer period (same as link request period for shared timer) */
#define PICC_HEARTBEAT_TIMER_PERIOD_MS  (10U)

/*==================================================================================================
 *                                         Private Types
 *==================================================================================================*/

/**
 * @brief Heartbeat channel context
 */
typedef struct {
    uint8    instanceId;                /**< IPCF instance ID */
    uint8    channelId;                 /**< IPCF channel ID */
    volatile uint8 missCount;           /**< Heartbeat miss count */
    boolean  isUsed;                    /**< Is channel in use */
} PICC_HeartbeatContext_t;

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/

/** Heartbeat channel contexts */
static PICC_HeartbeatContext_t g_hbContexts[PICC_HEARTBEAT_MAX_CHANNELS];

/** Heartbeat timer counter (counts up to 2000ms) - incremented each 10ms call */
static uint16 g_hbTimerCounter = 0U;

/** Timeout callback */
static PICC_HeartbeatTimeoutCallback_t g_timeoutCallback = NULL;

/** Whether module is initialized */
static boolean g_hbInitialized = FALSE;

/*==================================================================================================
 *                                         Private Functions
 *==================================================================================================*/

/**
 * @brief Get heartbeat context by channel ID
 */
static PICC_HeartbeatContext_t* PICC_GetHeartbeatContext(uint8 instanceId, uint8 channelId)
{
    uint32 i;
    (void)instanceId;  /* Currently only supports IPCF_INSTANCE0 */
    
    for (i = 0U; i < PICC_HEARTBEAT_MAX_CHANNELS; i++) {
        if (g_hbContexts[i].isUsed && g_hbContexts[i].channelId == channelId) {
            return &g_hbContexts[i];
        }
    }
    return NULL;
}

/**
 * @brief Heartbeat process - called from PICC periodic task (10ms)
 * 
 * [R6] Sends Ping every 2000ms and checks timeout.
 * Replaces the timer-based approach.
 */
void PICC_HeartbeatProcess(void)
{
    uint32 i;
    PICC_HeartbeatContext_t *ctx;

    if (g_hbInitialized == FALSE) {
        return;
    }

    g_hbTimerCounter++;
    
    /* 2000ms period (200 * 10ms) */
    if (g_hbTimerCounter >= (PICC_HEARTBEAT_PERIOD_MS / PICC_HEARTBEAT_TIMER_PERIOD_MS)) {
        g_hbTimerCounter = 0U;

        /* Iterate through all monitored channels */
        for (i = 0U; i < PICC_HEARTBEAT_MAX_CHANNELS; i++) {
            ctx = &g_hbContexts[i];
            
            if (ctx->isUsed == FALSE) {
                continue;
            }

            /* [R6] Send Ping on each channel */
            (void)PICC_HeartbeatSendPing(ctx->instanceId, ctx->channelId);

            /* [R6] Increment miss count and check timeout */
            ctx->missCount++;
            if (ctx->missCount >= PICC_HEARTBEAT_TIMEOUT_COUNT) {
                /* Timeout - notify application via callback */
                if (g_timeoutCallback != NULL) {
                    g_timeoutCallback(ctx->instanceId, ctx->channelId);
                }
                ctx->missCount = 0U;  /* Reset after notification */
            }
        }
    }
}

/*==================================================================================================
 *                                         Public Functions
 *==================================================================================================*/

/**
 * @brief Initialize heartbeat module
 */
sint8 PICC_HeartbeatInit(void)
{
    uint32 i;
    
    if (g_hbInitialized) {
        return 0;  /* Already initialized */
    }
    
    /* Initialize contexts */
    for (i = 0U; i < PICC_HEARTBEAT_MAX_CHANNELS; i++) {
        g_hbContexts[i].instanceId = 0U;
        g_hbContexts[i].channelId = 0U;
        g_hbContexts[i].missCount = 0U;
        g_hbContexts[i].isUsed = FALSE;
    }
    
    g_hbTimerCounter = 0U;
    g_timeoutCallback = NULL;
    
    /* NOTE: Timer removed - PICC_HeartbeatProcess() is called from PICC_PeriodicTask */
    g_hbInitialized = TRUE;
    return 0;
}

/**
 * @brief Deinitialize heartbeat module
 */
void PICC_HeartbeatDeinit(void)
{
    uint32 i;
    
    /* NOTE: Timer removed - no timer cleanup needed */
    for (i = 0U; i < PICC_HEARTBEAT_MAX_CHANNELS; i++) {
        g_hbContexts[i].isUsed = FALSE;
    }
    
    g_hbInitialized = FALSE;
}

/**
 * @brief Add channel to heartbeat monitoring
 */
sint8 PICC_HeartbeatAddChannel(uint8 instanceId, uint8 channelId)
{
    uint32 i;
    sint8 freeSlot = -1;
    
    /* Check if already exists */
    for (i = 0U; i < PICC_HEARTBEAT_MAX_CHANNELS; i++) {
        if (g_hbContexts[i].isUsed && 
            g_hbContexts[i].channelId == channelId) {
            return 0;  /* Already exists, success */
        }
        if (freeSlot == -1 && g_hbContexts[i].isUsed == FALSE) {
            freeSlot = (sint8)i;
        }
    }
    
    if (freeSlot == -1) {
        HANDLE_ERROR(-3);  /* No free slot for heartbeat channel */
        return -1;  /* No free slot */
    }
    
    g_hbContexts[freeSlot].instanceId = instanceId;
    g_hbContexts[freeSlot].channelId = channelId;
    g_hbContexts[freeSlot].missCount = 0U;
    g_hbContexts[freeSlot].isUsed = TRUE;
    
    return 0;
}

/**
 * @brief Send heartbeat Ping [R6]
 */
sint8 PICC_HeartbeatSendPing(uint8 instanceId, uint8 channelId)
{
    static const uint8 pingMsg[PICC_HEARTBEAT_MSG_SIZE] = {
        0xFFU, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x01U, 0x00U
    };
    sint8 ret;

    (void)instanceId;  /* Currently Stack uses fixed IPCF_INSTANCE0 */

    /* Send through Stack layer */
    ret = PICC_StackAddMessageToChannel(channelId, pingMsg, PICC_HEARTBEAT_MSG_SIZE);
    /* Note: Don't HANDLE_ERROR here - Ping failures are normal when A-core is not ready */
    return ret;
}

/**
 * @brief Send heartbeat Pong [R6]
 * 
 * Immediately flushes stack buffer to ensure Pong is sent without waiting for 10ms timer.
 * This fixes the timing issue where only one channel receives Pong when A-core sends
 * Ping to both channels simultaneously.
 * 
 * @note Design rationale:
 *   1. AddMessage() only ADDS Pong to buffer, does NOT send it
 *      (Exception: If buffer is full, it sends OLD data first to make room)
 *   2. Flush() immediately sends the buffer content (including the just-added Pong)
 *   3. Two AddMessage() calls handle buffer-full case with priority handling
 */
sint8 PICC_HeartbeatSendPong(uint8 instanceId, uint8 channelId)
{
    static const uint8 pongMsg[PICC_HEARTBEAT_MSG_SIZE] = {
        0xFFU, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x01U, 0x01U
    };
    sint8 ret;

    (void)instanceId;  /* Currently Stack uses fixed IPCF_INSTANCE0 */

    /* ========================================================================
     * Step 1: Add Pong to stack buffer
     * ======================================================================== */
    /* AddMessage() behavior:
     *   - If buffer has space: Add Pong to buffer, return 0
     *   - If buffer is full: Send OLD buffer data first, then add Pong, return 0
     *   - If buffer full AND send fails: Return -4 (cannot add)
     * 
     * IMPORTANT: Even if AddMessage() calls DoSend internally when buffer is full,
     *            it only sends the OLD data that was already in buffer.
     *            The NEW Pong message is added AFTER the send, so it remains
     *            in the buffer waiting to be sent.
     */
    ret = PICC_StackAddMessageToChannel(channelId, pongMsg, PICC_HEARTBEAT_MSG_SIZE);
    
    /* ========================================================================
     * Step 2: Handle buffer-full case
     * ======================================================================== */
    if (ret == -4) {
        /* Buffer is full AND previous send failed.
         * Pong is high-priority - we must send it even if it means dropping old data.
         * Solution: Clear buffer (discard old messages), then add Pong again.
         */
        PICC_StackClearBuffer(channelId);
        ret = PICC_StackAddMessageToChannel(channelId, pongMsg, PICC_HEARTBEAT_MSG_SIZE);
        /* After clear, buffer is empty, so AddMessage will definitely succeed */
    }
    
    /* ========================================================================
     * Step 3: Immediately send the Pong (don't wait for 10ms timer)
     * ======================================================================== */
    if (ret == 0) {
        /* At this point, Pong is in the buffer but NOT yet sent.
         * Flush() immediately sends the buffer content to ensure fast response.
         * Without Flush(), Pong would wait up to 10ms until next StackProcess() call.
         */
        (void)PICC_StackFlushChannel(channelId);
    } else {
        HANDLE_ERROR(-5);  /* Failed to send heartbeat Pong */
    }
    return ret;
}

/**
 * @brief Handle received Ping, reply Pong
 */
sint8 PICC_HeartbeatHandlePing(uint8 instanceId, uint8 channelId)
{
    sint8 ret;
    /* When we receive Ping, reset our miss count and reply Pong */
    /* [FIX] Do NOT reset missCount here, only reply Pong */
    ret = PICC_HeartbeatSendPong(instanceId, channelId);
    if (ret != 0) {
        HANDLE_ERROR(-6);  /* Failed to handle Ping (Pong send failed) */
    }
    return ret;
}

/**
 * @brief Reset heartbeat miss count
 */
void PICC_HeartbeatReset(uint8 instanceId, uint8 channelId)
{
    PICC_HeartbeatContext_t *ctx = PICC_GetHeartbeatContext(instanceId, channelId);
    if (ctx != NULL) {
        /* [FIX] Use critical section to prevent race with Timer callback */
        taskENTER_CRITICAL();
        ctx->missCount = 0U;
        taskEXIT_CRITICAL();
    }
}

/**
 * @brief Check if data is a Ping message
 */
boolean PICC_HeartbeatIsPing(const uint8 *data, uint32 len)
{
    static const uint8 pingPattern[PICC_HEARTBEAT_MSG_SIZE] = {
        0xFFU, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x01U, 0x00U
    };
    uint32 i;

    if (data == NULL || len != PICC_HEARTBEAT_MSG_SIZE) {
        return FALSE;
    }

    for (i = 0U; i < PICC_HEARTBEAT_MSG_SIZE; i++) {
        if (data[i] != pingPattern[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

/**
 * @brief Check if data is a Pong message
 */
boolean PICC_HeartbeatIsPong(const uint8 *data, uint32 len)
{
    static const uint8 pongPattern[PICC_HEARTBEAT_MSG_SIZE] = {
        0xFFU, 0x00U, 0xFFU, 0x00U, 0xFFU, 0x00U, 0x00U, 0x01U, 0x01U
    };
    uint32 i;

    if (data == NULL || len != PICC_HEARTBEAT_MSG_SIZE) {
        return FALSE;
    }

    for (i = 0U; i < PICC_HEARTBEAT_MSG_SIZE; i++) {
        if (data[i] != pongPattern[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

/**
 * @brief Register heartbeat timeout callback
 */
sint8 PICC_HeartbeatRegisterTimeoutCallback(PICC_HeartbeatTimeoutCallback_t callback)
{
    g_timeoutCallback = callback;
    return 0;
}

/**
 * @brief Get heartbeat miss count for specified channel
 */
uint8 PICC_HeartbeatGetMissCount(uint8 instanceId, uint8 channelId)
{
    PICC_HeartbeatContext_t *ctx = PICC_GetHeartbeatContext(instanceId, channelId);
    if (ctx != NULL) {
        return ctx->missCount;
    }
    return 0U;
}

#if defined(__cplusplus)
}
#endif
