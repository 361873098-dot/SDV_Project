/**
 * IPC Shared Memory Driver - Common Chassis Generic Implementation
 *
 * Copyright 2021-2023 NXP
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
#if defined(__cplusplus)
extern "C"{
#endif

#include "ipc-shm.h"
#include "ipc-os.h"
#include "ipc-hw.h"
#include "ipc-hw-platform.h"

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_HW_PLATFORM_VENDOR_ID_C                    43
#define IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION_C     4
#define IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION_C     4
#define IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION_C  0
#define IPC_HW_PLATFORM_SW_MAJOR_VERSION_C             4
#define IPC_HW_PLATFORM_SW_MINOR_VERSION_C             10
#define IPC_HW_PLATFORM_SW_PATCH_VERSION_C             0

/*
 * FILE VERSION CHECKS
 */
/* Check if ipc-hw-s32g3xx.c file and ipc-shm.h file are of the same vendor */
#if (IPC_HW_PLATFORM_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-hw-s32g3xx.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-hw-s32g3xx.c and ipc-shm.h are different"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-shm.h file are of the same software version */
#if ((IPC_HW_PLATFORM_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-hw-s32g3xx.c and ipc-shm.h are different"
#endif

/* Check if ipc-hw-s32g3xx.c file and ipc-hw.h file are of the same vendor */
#if (IPC_HW_PLATFORM_VENDOR_ID_C != IPC_HW_VENDOR_ID)
	#error "ipc-hw-s32g3xx.c and ipc-hw.h have different vendor IDs"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-hw.h file are of the same Autosar version */
#if ((IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION_C != IPC_HW_AR_RELEASE_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION_C != IPC_HW_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-hw-s32g3xx.c and ipc-hw.h are different"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-hw.h file are of the same software version */
#if ((IPC_HW_PLATFORM_SW_MAJOR_VERSION_C != IPC_HW_SW_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_MINOR_VERSION_C != IPC_HW_SW_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_PATCH_VERSION_C != IPC_HW_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-hw-s32g3xx.c and ipc-hw.h are different"
#endif

/* Check if ipc-hw-s32g3xx.c file and ipc-hw-platform.h file are of the same vendor */
#if (IPC_HW_PLATFORM_VENDOR_ID_C != IPC_HW_PLATFORM_VENDOR_ID)
	#error "ipc-hw-s32g3xx.c and ipc-hw-platform.h have different vendor IDs"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-hw-platform.h file are of the same Autosar version */
#if ((IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION_C != IPC_HW_PLATFORM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION_C != IPC_HW_PLATFORM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-hw-s32g3xx.c and ipc-hw-platform.h are different"
#endif
/* Check if ipc-hw-s32g3xx.c file and ipc-hw-platform.h file are of the same software version */
#if ((IPC_HW_PLATFORM_SW_MAJOR_VERSION_C != IPC_HW_PLATFORM_SW_MAJOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_MINOR_VERSION_C != IPC_HW_PLATFORM_SW_MINOR_VERSION) || \
	(IPC_HW_PLATFORM_SW_PATCH_VERSION_C != IPC_HW_PLATFORM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-hw-s32g3xx.c and ipc-hw-platform.h are different"
#endif

/**
 * struct ipc_hw_priv_type - platform specific private data
 *
 * @msi_tx_irq:     MSI index of inter-core interrupt corresponds to mscm_tx_irq
 * @msi_rx_irq:     MSI index of inter-core interrupt corresponds to mscm_rx_irq
 * @remote_core:    remote core to trigger the interrupt on
 * @local_core:     local core on where this instance is running
 * @shm_size:       local/remote shared memory size
 * @mscm_tx_irq:    MSCM inter-core interrupt reserved for shm driver tx
 * @mscm_rx_irq:    MSCM inter-core interrupt reserved for shm driver rx
 */
static struct ipc_hw_priv_type {
	uint8 msi_tx_irq;
	uint8 msi_rx_irq;
	uint8 remote_core;
	uint8 local_core;
	uint32 shm_size;
	sint16 mscm_tx_irq;
	sint16 mscm_rx_irq;
} ipc_hw_priv[IPC_SHM_MAX_INSTANCES];

/**
 * ipc_hw_get_core_index_m7() - Validate and get core index if core type is m7
 *
 * @core: core type
 *
 * Return: core_index if core type is m7
 */
static sint8 ipc_hw_get_core_index_m7(uint8 index)
{
	sint8 core_index;

	switch (index) {
	case (uint8)IPC_CORE_INDEX_0:
		core_index = (sint8)IPC_M7_0;
		break;
	case (uint8)IPC_CORE_INDEX_1:
		core_index = (sint8)IPC_M7_1;
		break;
	case (uint8)IPC_CORE_INDEX_2:
		core_index = (sint8)IPC_M7_2;
		break;
	case (uint8)IPC_CORE_INDEX_3:
		core_index = (sint8)IPC_M7_3;
		break;
	default:
		core_index = -IPC_SHM_E_INVAL;
		break;
	}

	return core_index;
}

/**
 * ipc_hw_get_core_index_a53() - Validate and get core index if core type is a53
 *
 * @core: core type
 *
 * Return: core_index if core type is a53
 */
static sint8 ipc_hw_get_core_index_a53(uint8 index)
{
	sint8 core_index;

	switch (index) {
	case (uint8)IPC_CORE_INDEX_0:
		core_index = (sint8)IPC_A53_0;
		break;
	case (uint8)IPC_CORE_INDEX_1:
		core_index = (sint8)IPC_A53_1;
		break;
	case (uint8)IPC_CORE_INDEX_2:
		core_index = (sint8)IPC_A53_2;
		break;
	case (uint8)IPC_CORE_INDEX_3:
		core_index = (sint8)IPC_A53_3;
		break;
	case (uint8)IPC_CORE_INDEX_4:
		core_index = (sint8)IPC_A53_4;
		break;
	case (uint8)IPC_CORE_INDEX_5:
		core_index = (sint8)IPC_A53_5;
		break;
	case (uint8)IPC_CORE_INDEX_6:
		core_index = (sint8)IPC_A53_6;
		break;
	case (uint8)IPC_CORE_INDEX_7:
		core_index = (sint8)IPC_A53_7;
		break;
	default:
		core_index = -IPC_SHM_E_INVAL;
		break;
	}

	return core_index;
}

/**
 * ipc_hw_set_remote_core() - get remote core for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid core
 */
static sint8 ipc_hw_set_remote_core(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = -IPC_SHM_E_INVAL;
	sint8 core_idx = 0;

	if (cfg->remote_core.type == IPC_CORE_A53) {
		if ((cfg->remote_core.index >= IPC_CORE_INDEX_0)
				&& (cfg->remote_core.index <= IPC_CORE_INDEX_7)) {
			core_idx = ipc_hw_get_core_index_a53((uint8)cfg->remote_core.index);
			if (core_idx >= (sint8)IPC_A53_0) {
				ipc_hw_priv[instance].remote_core = (uint8)core_idx;
				err = IPC_SHM_E_OK;
			}
		}
	} else if (cfg->remote_core.type == IPC_CORE_M7) {
		if ((cfg->remote_core.index >= IPC_CORE_INDEX_0)
				&& (cfg->remote_core.index <= IPC_CORE_INDEX_3)) {
			core_idx = ipc_hw_get_core_index_m7((uint8)cfg->remote_core.index);
			if (core_idx >= (sint8)IPC_M7_0) {
				ipc_hw_priv[instance].remote_core = (uint8)core_idx;
				err = IPC_SHM_E_OK;
			}
		}
	} else {
		err = -IPC_SHM_E_INVAL;
	}

	return err;
}

/**
 * ipc_hw_set_local_core() - get local core for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid core
 */
static sint8 ipc_hw_set_local_core(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = -IPC_SHM_E_INVAL;
	sint8 core_idx = 0;

	if (cfg->local_core.type == IPC_CORE_A53) {
		if ((cfg->local_core.index >= IPC_CORE_INDEX_0)
				&& (cfg->local_core.index <= IPC_CORE_INDEX_7)) {
			core_idx = ipc_hw_get_core_index_a53((uint8)cfg->local_core.index);
			if (core_idx >= (sint8)IPC_A53_0) {
				ipc_hw_priv[instance].local_core = (uint8)core_idx;
				err = IPC_SHM_E_OK;
			}
		}
	} else if (cfg->local_core.type == IPC_CORE_M7) {
		if ((cfg->local_core.index >= IPC_CORE_INDEX_0)
				&& (cfg->local_core.index <= IPC_CORE_INDEX_3)) {
			core_idx = ipc_hw_get_core_index_m7((uint8)cfg->local_core.index);
			if (core_idx >= (sint8)IPC_M7_0) {
				ipc_hw_priv[instance].local_core = (uint8)core_idx;
				err = IPC_SHM_E_OK;
			}
		}
	} else {
		err = -IPC_SHM_E_INVAL;
	}

	return err;
}

/**
 * ipc_hw_set_core() - get local and remote core for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid core
 */
static sint8 ipc_hw_set_core(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = IPC_SHM_E_OK;
	uint8 local_core_idx = (uint8)(IP_MSCM->CPXNUM & MSCM_CPXNUM_CPN_MASK);

	/* Get local and remote core */
	err = ipc_hw_set_remote_core(instance, cfg);
	if (err == IPC_SHM_E_OK) {
		err = ipc_hw_set_local_core(instance, cfg);
	}

	if (err == IPC_SHM_E_OK) {
		if ((ipc_hw_priv[instance].remote_core
					!= ipc_hw_priv[instance].local_core)
				&& (ipc_hw_priv[instance].local_core
						== local_core_idx)) {
			err = IPC_SHM_E_OK;
		} else {
			err = -IPC_SHM_E_INVAL;
		}
	}

	return err;
}

/**
 * ipc_hw_set_tx_irq_idx() - get tx irq and msi index for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid interrupt
 */
static sint8 ipc_hw_set_tx_irq_idx(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = IPC_SHM_E_OK;

	ipc_hw_priv[instance].mscm_tx_irq = cfg->inter_core_tx_irq;

	switch (cfg->inter_core_tx_irq) {
	case IPC_IRQ_NONE:
	    ipc_hw_priv[instance].mscm_tx_irq = IPC_IRQ_NONE;
		break;
	case (sint16)MSCM_INT0_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)0u;
		break;
	case (sint16)MSCM_INT1_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)1u;
		break;
	case (sint16)MSCM_INT2_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)2u;
		break;
	case (sint16)MSCM_INT3_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)5u;
		break;
	case (sint16)MSCM_INT4_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)6u;
		break;
	case (sint16)MSCM_INT5_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)7u;
		break;
	case (sint16)MSCM_INT6_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)8u;
		break;
	case (sint16)MCSCM_INT7_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)9u;
		break;
	case (sint16)MCSCM_INT8_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)10u;
		break;
	case (sint16)MCSCM_INT9_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)11u;
		break;
	case (sint16)MCSCM_INT10_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)12u;
		break;
	case (sint16)MCSCM_INT11_IRQn:
		ipc_hw_priv[instance].msi_tx_irq = (uint8)13u;
		break;
	default:
		err = -IPC_SHM_E_INVAL;
		break;
	}

	return err;
}

/**
 * ipc_hw_set_rx_irq_idx() - get rx irq and msi index for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid interrupt
 */
static sint8 ipc_hw_set_rx_irq_idx(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = IPC_SHM_E_OK;

	ipc_hw_priv[instance].mscm_rx_irq = cfg->inter_core_rx_irq;

	switch (cfg->inter_core_rx_irq) {
	case IPC_IRQ_NONE:
	    ipc_hw_priv[instance].mscm_rx_irq = IPC_IRQ_NONE;
		break;
	case (sint16)MSCM_INT0_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)0u;
		break;
	case (sint16)MSCM_INT1_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)1u;
		break;
	case (sint16)MSCM_INT2_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)2u;
		break;
	case (sint16)MSCM_INT3_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)5u;
		break;
	case (sint16)MSCM_INT4_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)6u;
		break;
	case (sint16)MSCM_INT5_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)7u;
		break;
	case (sint16)MSCM_INT6_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)8u;
		break;
	case (sint16)MCSCM_INT7_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)9u;
		break;
	case (sint16)MCSCM_INT8_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)10u;
		break;
	case (sint16)MCSCM_INT9_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)11u;
		break;
	case (sint16)MCSCM_INT10_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)12u;
		break;
	case (sint16)MCSCM_INT11_IRQn:
		ipc_hw_priv[instance].msi_rx_irq = (uint8)13u;
		break;
	default:
		err = -IPC_SHM_E_INVAL;
		break;
	}

	return err;
}

/**
 * ipc_hw_set_irq_idx() - get irq and msi index for platform private data
 *
 * @instance: configuration parameters
 * @cfg::     Local core type from ipcf configuration
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for invalid interrupt
 */
static sint8 ipc_hw_set_irq_idx(const uint8 instance,
						const struct ipc_shm_cfg *cfg)
{
	sint8 err = IPC_SHM_E_OK;

	if ((cfg->inter_core_rx_irq == cfg->inter_core_tx_irq)
				&& (cfg->inter_core_rx_irq != IPC_IRQ_NONE)) {
		err = -IPC_SHM_E_INVAL;
	} else {
		/* Get remote core */
		err = ipc_hw_set_tx_irq_idx(instance, cfg);
		if (err == IPC_SHM_E_OK) {
			err = ipc_hw_set_rx_irq_idx(instance, cfg);
		}
	}

	return err;
}

/**
 * ipc_hw_init() - platform specific initialization
 *
 * @cfg:    configuration parameters
 *
 * inter_core_tx_irq and inter_core_rx_irq can be disabled by passing
 * IPC_IRQ_NONE, if polling is desired in either transmit, receive or both
 * notification path. When inter_core_rx_irq is disabled, the receive interrupt
 * is not used at all so operations such as enabling, disabling and clearing
 * the interrupt do nothing. When inter_core_tx_irq is disabled, notify
 * operation does nothing. If both inter_core_rx_irq and inter_core_tx_irq are
 * disabled, then the ipc-hw layer acts as a dummy interface.
 *
 * When enabled, inter_core_tx_irq and inter_core_rx_irq are not allowed to have
 * the same value to avoid possible race conditions when updating the value of
 * the IRSPRCn register. If the value IPC_CORE_DEFAULT is passed as remote_core,
 * the default value defined for the selected platform will be used instead.
 *
 * Return: IPC_SHM_E_OK for success, -IPC_SHM_E_INVAL for either inter core
 *         interrupt invalid or invalid remote core
 */
sint8 ipc_hw_init(const uint8 instance, const struct ipc_shm_cfg *cfg)
{
	sint8 err = IPC_SHM_E_OK;

	err = ipc_hw_set_core(instance, cfg);
	if (err == IPC_SHM_E_OK) {
		err = ipc_hw_set_irq_idx(instance, cfg);
	}

	if (err == IPC_SHM_E_OK) {
		ipc_hw_priv[instance].shm_size = cfg->shm_size;

		/**
		 * disable rx irq source to avoid receiving an interrupt from remote
		 * before any of the buffer rings are initialized
		 */
		ipc_hw_irq_disable(instance);

		/* clear irq notification */
		ipc_hw_irq_clear(instance);
	}

	return err;
}

/**
 * ipc_hw_free() - free hw resources
 */
void ipc_hw_free(const uint8 instance)
{
	ipc_hw_irq_clear(instance);
}

/**
 * ipc_hw_irq_enable() - enable notifications from remote
 *
 * The MSCM_IRSPRCn register works with the NVIC interrupt IDs, and the NVIC ID
 * of the first MSCM inter-core interrupt is 1. In order to obtain the correct
 * index for the interrupt routing register, this value is added to mscm_rx_irq.
 */
void ipc_hw_irq_enable(const uint8 instance)
{
	/*
	 * enable MSCM core-to-core interrupt routing
	 * Only apply to local core is M7/RTOS
	 * (IPC_M7_3 >= local_core >= IPC_M7_0)
	 * Not apply to A53 running Linux
	 */

	if (ipc_hw_priv[instance].mscm_rx_irq != IPC_IRQ_NONE) {
#if !defined(USING_OS_AUTOSAROS)
		/* enable MSCM core-to-core interrupt routing */
		IP_MSCM->IRSPRC[ipc_hw_priv[instance].mscm_rx_irq]
			|= ((uint16)1u << (ipc_hw_priv[instance].local_core
			- (uint8)IPC_M7_0 + 1u));
#endif
	}
}

/**
 * ipc_hw_irq_disable() - disable notifications from remote
 *
 * The MSCM_IRSPRCn register works with the NVIC interrupt IDs, and the NVIC ID
 * of the first MSCM inter-core interrupt is 1. In order to obtain the correct
 * index for the interrupt routing register, this value is added to mscm_rx_irq.
 */
void ipc_hw_irq_disable(const uint8 instance)
{
	/*
	 * disable MSCM core-to-core interrupt routing
	 * Only apply to local core is M7/RTOS
	 * (IPC_M7_3 >= local_core >= IPC_M7_0)
	 * Not apply to A53 running Linux
	 */

	if (ipc_hw_priv[instance].mscm_rx_irq != IPC_IRQ_NONE) {
#if !defined(USING_OS_AUTOSAROS)
		/* disable MSCM core-to-core interrupt routing */
		IP_MSCM->IRSPRC[ipc_hw_priv[instance].mscm_rx_irq]
			&= ~((uint16)1u << (ipc_hw_priv[instance].local_core
			- (uint8)IPC_M7_0 + 1u));
#endif
	}
}

/**
 * ipc_hw_irq_notify() - notify remote that data is available
 */
void ipc_hw_irq_notify(const uint8 instance)
{
	uint8 remote_core;
	uint8 msi_tx_index;

	if (ipc_hw_priv[instance].mscm_tx_irq != IPC_IRQ_NONE) {
		remote_core = ipc_hw_priv[instance].remote_core;
		msi_tx_index = ipc_hw_priv[instance].msi_tx_irq;

		/* trigger MSCM core-to-core directed interrupt */
		IPC_MSCM_IRCPnIRx->IRCPnIRx[remote_core][msi_tx_index].IPC_IGR
			|= IPC_MSCM_IRCPnIGRx_INT_EN;
	}
}
/**
 * ipc_hw_irq_clear() - clear available data notification
 */
void ipc_hw_irq_clear(const uint8 instance)
{
	uint8 local_core;
	uint8 remote_core;
	uint8 msi_rx_index;

	if (ipc_hw_priv[instance].mscm_rx_irq != IPC_IRQ_NONE) {
		local_core = ipc_hw_priv[instance].local_core;
		remote_core = ipc_hw_priv[instance].remote_core;
		msi_rx_index = ipc_hw_priv[instance].msi_rx_irq;

		if (((uint8)IPC_M7_0 <= remote_core)
				&& (remote_core <= (uint8)IPC_M7_3)) {
			/* clear MSCM core-to-core directed interrupt */
			IPC_MSCM_IRCPnIRx->IRCPnIRx[local_core][msi_rx_index].IPC_ISR
				= ((uint32)1u << remote_core);
		} else {
			IPC_MSCM_IRCPnIRx->IRCPnIRx[local_core][msi_rx_index].IPC_ISR
				= (uint32)IPC_MSCM_IRCPnISRx_CLEAR_A53;
		}
	}
}

/* generic cache flush */
#if defined(IPC_D_CACHE_ENABLE)
static void ipc_hw_flush_cache(uint32 data_addr, uint32 data_size)
{
	uintptr data_addr_tmp = data_addr;
	uintptr data_size_tmp = data_size;

	MCAL_DATA_SYNC_BARRIER();
	MCAL_INSTRUCTION_SYNC_BARRIER();

	do {
		S32_SCB->DCCIMVAC = data_addr_tmp;
		data_addr_tmp += IPC_DCACHE_LINE_SIZE;
		data_size_tmp -= IPC_DCACHE_LINE_SIZE;
	} while (data_size_tmp > 0u);

	MCAL_DATA_SYNC_BARRIER();
	MCAL_INSTRUCTION_SYNC_BARRIER();
}
#endif

/**
 * ipc_hw_flush_cache_local() - Clear and invalidate cache content
 * @instance:	instance id
 *
 * Before sending, flush + invalidate local cache in order write back the
 * contents to main memory and mark the cache lines as invalid so that
 * the future reads will be done from the memory.
 */
void ipc_hw_flush_cache_local(const uint8 instance)
{
#if defined(IPC_D_CACHE_ENABLE)
	uintptr data_addr = ipc_os_get_local_shm(instance);
	uintptr data_size = ipc_hw_priv[instance].shm_size;
	uintptr tmp_size = data_size + (data_addr & (IPC_DCACHE_LINE_SIZE - 1U));
	uintptr tmp_addr = data_addr /* & ~(IPC_DCACHE_LINE_SIZE - 1U) */;

	ipc_hw_flush_cache(tmp_addr, tmp_size);
#else
	(void)instance;
#endif
}

/**
 * ipc_hw_flush_cache_remote() - Clear and invalidate cache content
 * @instance:	instance id
 *
 * Before receiving, flush + invalidate remote cache in order write back the
 * contents to main memory and mark the cache lines as invalid so that
 * the future reads will be done from the memory.
 */
void ipc_hw_flush_cache_remote(const uint8 instance)
{
#if defined(IPC_D_CACHE_ENABLE)
	uintptr data_addr = ipc_os_get_remote_shm(instance);
	uintptr data_size = ipc_hw_priv[instance].shm_size;
	uintptr tmp_size = data_size + (data_addr & (IPC_DCACHE_LINE_SIZE - 1U));
	uintptr tmp_addr = data_addr /* & ~(IPC_DCACHE_LINE_SIZE - 1U) */;

	ipc_hw_flush_cache(tmp_addr, tmp_size);
#else
	(void)instance;
#endif
}

#if defined(__cplusplus)
}
#endif
