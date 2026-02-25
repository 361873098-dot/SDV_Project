/*
 *
 * IPC Shared Memory Driver - IPCF configuraton
 *
 * Copyright 2020-2024 NXP
 * All Rights Reserved.
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 *
 */
#if defined(__cplusplus)
extern "C"{
#endif

#include "ipc-types.h"
#include "ipcf_Ip_Cfg.h"

/**
 * SOURCE FILE VERSION INFORMATION
 */
#define IPCF_IP_CFG_VENDOR_ID_C                    43
#define IPCF_IP_CFG_MODULE_ID_C                    255
#define IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C     4
#define IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C     4
#define IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C  0
#define IPCF_IP_CFG_SW_MAJOR_VERSION_C             4
#define IPCF_IP_CFG_SW_MINOR_VERSION_C             10
#define IPCF_IP_CFG_SW_PATCH_VERSION_C             0

/**
 * FILE VERSION CHECKS
 */
#if (IPCF_IP_CFG_VENDOR_ID_C != IPC_TYPES_VENDOR_ID)
	#error "ipcf_Ip_Cfg.c and ipc-types.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPC_TYPES_AR_RELEASE_MINOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPC_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPC_TYPES_SW_MAJOR_VERSION) || \
	(IPCF_IP_CFG_SW_MINOR_VERSION_C != IPC_TYPES_SW_MINOR_VERSION) || \
	(IPCF_IP_CFG_SW_PATCH_VERSION_C != IPC_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipc-types.h are different"
#endif

#if (IPCF_IP_CFG_VENDOR_ID_C != IPCF_IP_CFG_VENDOR_ID)
	#error "ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h have different vendor ids"
#endif
#if ((IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION_C != IPCF_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
	(IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION_C != IPCF_IP_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif
#if ((IPCF_IP_CFG_SW_MAJOR_VERSION_C != IPCF_IP_CFG_SW_MAJOR_VERSION) || \
	(IPCF_IP_CFG_SW_MINOR_VERSION_C != IPCF_IP_CFG_SW_MINOR_VERSION) || \
	(IPCF_IP_CFG_SW_PATCH_VERSION_C != IPCF_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of ipcf_Ip_Cfg.c and ipcf_Ip_Cfg.h are different"
#endif

/* Pools must be sorted in ascending order by buffer size */
static struct ipc_shm_pool_cfg ipcf_shm_cfg_buf_pools0_1[3] = {
	{
		.num_bufs = 30,
		.buf_size = 64,
	},
	{
		.num_bufs = 20,
		.buf_size = 256,
	},
	{
		.num_bufs = 10,
		.buf_size = 4096,
	},
};
/* Pools must be sorted in ascending order by buffer size */
static struct ipc_shm_pool_cfg ipcf_shm_cfg_buf_pools0_2[3] = {
	{
		.num_bufs = 30,
		.buf_size = 64,
	},
	{
		.num_bufs = 20,
		.buf_size = 256,
	},
	{
		.num_bufs = 10,
		.buf_size = 4096,
	},
};

static struct ipc_shm_channel_cfg ipcf_shm_cfg_channels0[3] = {
	{
		.type = IPC_SHM_UNMANAGED,
		.ch = {
			.unmanaged = {
				.size = 64,
				.rx_cb = ctrl_chan_rx_cb,
				.cb_arg = &rx_cb_arg,
			},
		},
	},
	{
		.type = IPC_SHM_MANAGED,
		.ch = {
			.managed = {
				.num_pools = 3,
				.pools = ipcf_shm_cfg_buf_pools0_1,
				.rx_cb = data_chan_rx_cb,
				.cb_arg = &rx_cb_arg,
			},
		},
	},
	{
		.type = IPC_SHM_MANAGED,
		.ch = {
			.managed = {
				.num_pools = 3,
				.pools = ipcf_shm_cfg_buf_pools0_2,
				.rx_cb = data_chan_rx_cb,
				.cb_arg = &rx_cb_arg,
			},
		},
	},
};



/* ipc shm configuration */
struct ipc_shm_cfg ipcf_shm_cfg_instances[1] = {
	{
		.local_shm_addr  = 0x34200000,
		.remote_shm_addr = 0x34100000,
		.shm_size  = 0x100000,
		.inter_core_tx_irq = MSCM_INT1_IRQn,
		.inter_core_rx_irq = MSCM_INT2_IRQn,
		.local_core = {
			.type = IPC_CORE_M7,
			.index = IPC_CORE_INDEX_0,
		},
		.remote_core = {
			.type = IPC_CORE_A53,
			.index = IPC_CORE_INDEX_0,
		},
		.num_channels = 3,
		.channels = ipcf_shm_cfg_channels0,
	},
};

struct ipc_shm_instances_cfg ipcf_shm_instances_cfg = {
	.num_instances = 1u,
	.shm_cfg = ipcf_shm_cfg_instances,
};


#if defined(__cplusplus)
}
#endif

