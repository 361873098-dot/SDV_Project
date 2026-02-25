/**
 * IPC Shared Memory Driver - Real-Time OS Abstraction Layer API
 *
 * Copyright 2018,2021,2023 NXP
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
#ifndef IPC_OS_H
#define IPC_OS_H

#if defined(__cplusplus)
extern "C"{
#endif

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_OS_VENDOR_ID                    43
#define IPC_OS_AR_RELEASE_MAJOR_VERSION     4
#define IPC_OS_AR_RELEASE_MINOR_VERSION     4
#define IPC_OS_AR_RELEASE_REVISION_VERSION  0
#define IPC_OS_SW_MAJOR_VERSION             4
#define IPC_OS_SW_MINOR_VERSION             10
#define IPC_OS_SW_PATCH_VERSION             0

/* softirq work budget used to prevent CPU starvation */
#define IPC_SOFTIRQ_BUDGET 128u

#define IPC_SHM_INSTANCE_DISABLED   0u
#define IPC_SHM_INSTANCE_ENABLED    1u

sint8 ipc_os_init(const uint8 instance, const struct ipc_shm_cfg *cfg,
		uint32 (*rx_cb)(const uint8, uint32));
void ipc_os_free(const uint8 instance);
uintptr ipc_os_get_local_shm(const uint8 instance);
uintptr ipc_os_get_remote_shm(const uint8 instance);
sint8 ipc_os_poll_channels(const uint8 instance);

#if defined USING_OS_XOS
void ipc_shm_hardirq(void *arg);
#elif defined USING_OS_ZEPHYR
void ipc_shm_hardirq(const void *arg);
#else
void ipc_shm_hardirq(void);
#endif
void ipc_shm_hardirq_instance(const uint8 instance);

#if defined(__cplusplus)
}
#endif

#endif /* IPC_OS_H */
