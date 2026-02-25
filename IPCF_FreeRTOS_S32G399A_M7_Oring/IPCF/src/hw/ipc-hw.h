/**
 * IPC Shared Memory Driver - Hardware Platform Abstraction Layer API
 *
 * Copyright 2018,2021-2023 NXP
 * All Rights Reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */
#ifndef IPC_HW_H
#define IPC_HW_H

#if defined(__cplusplus)
extern "C"{
#endif

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_HW_VENDOR_ID                    43
#define IPC_HW_AR_RELEASE_MAJOR_VERSION     4
#define IPC_HW_AR_RELEASE_MINOR_VERSION     4
#define IPC_HW_AR_RELEASE_REVISION_VERSION  0
#define IPC_HW_SW_MAJOR_VERSION             4
#define IPC_HW_SW_MINOR_VERSION             10
#define IPC_HW_SW_PATCH_VERSION             0

sint8 ipc_hw_init(const uint8 instance, const struct ipc_shm_cfg *cfg);
void ipc_hw_free(const uint8 instance);
void ipc_hw_irq_enable(const uint8 instance);
void ipc_hw_irq_disable(const uint8 instance);
void ipc_hw_irq_notify(const uint8 instance);
void ipc_hw_irq_clear(const uint8 instance);
void ipc_hw_flush_cache_local(const uint8 instance);
void ipc_hw_flush_cache_remote(const uint8 instance);

#if defined(S32K358) || defined(S32K388)
void ipc_shm_mu_notification(void);
#endif

#if defined(S32N) || defined(S32ZE)
void ipc_shm_mru_notification(uint8 RxChannelId, const uint32 *RxBuffer, uint8 BufferSize);
#endif

#if defined(__cplusplus)
}
#endif

#endif /* IPC_HW_H */
