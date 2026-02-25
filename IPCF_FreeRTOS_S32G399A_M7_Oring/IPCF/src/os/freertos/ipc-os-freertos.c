/**
 * IPC Shared Memory Driver - FreeRTOS Specific Implementation
 *
 * Copyright 2018-2019,2021-2024 NXP
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

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_OS_VENDOR_ID_C                    43
#define IPC_OS_AR_RELEASE_MAJOR_VERSION_C     4
#define IPC_OS_AR_RELEASE_MINOR_VERSION_C     4
#define IPC_OS_AR_RELEASE_REVISION_VERSION_C  0
#define IPC_OS_SW_MAJOR_VERSION_C             4
#define IPC_OS_SW_MINOR_VERSION_C             10
#define IPC_OS_SW_PATCH_VERSION_C             0

/*
 * FILE VERSION CHECKS
 */
/* Check if ipc-os-freertos.c file and ipc-shm.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-os-freertos.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-os-freertos.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-freertos.c and ipc-shm.h are different"
#endif
/* Check if ipc-os-freertos.c file and ipc-shm.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-freertos.c and ipc-shm.h are different"
#endif

/* Check if ipc-os-freertos.c file and ipc-os.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_OS_VENDOR_ID)
	#error "ipc-os-freertos.c and ipc-os.h have different vendor IDs"
#endif
/* Check if ipc-os-freertos.c file and ipc-os.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_OS_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_OS_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_OS_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-freertos.c and ipc-os.h are different"
#endif
/* Check if ipc-os-freertos.c file and ipc-os.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_OS_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_OS_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_OS_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-freertos.c and ipc-os.h are different"
#endif

/* Check if ipc-os-freertos.c file and ipc-hw.h file are of the same vendor */
#if (IPC_OS_VENDOR_ID_C != IPC_HW_VENDOR_ID)
	#error "ipc-os-freertos.c and ipc-hw.h have different vendor IDs"
#endif
/* Check if ipc-os-freertos.c file and ipc-hw.h file are of the same Autosar version */
#if ((IPC_OS_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_OS_AR_RELEASE_MINOR_VERSION_C != IPC_HW_AR_RELEASE_MINOR_VERSION) || \
	(IPC_OS_AR_RELEASE_REVISION_VERSION_C != IPC_HW_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-os-freertos.c and ipc-hw.h are different"
#endif
/* Check if ipc-os-freertos.c file and ipc-hw.h file are of the same software version */
#if ((IPC_OS_SW_MAJOR_VERSION_C != IPC_HW_SW_MAJOR_VERSION) || \
	(IPC_OS_SW_MINOR_VERSION_C != IPC_HW_SW_MINOR_VERSION) || \
	(IPC_OS_SW_PATCH_VERSION_C != IPC_HW_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-os-freertos.c and ipc-hw.h are different"
#endif

#ifndef IPC_SOFTIRQ_STACK_SIZE
	#define IPC_SOFTIRQ_STACK_SIZE 256 /* 4-byte words */
#endif
#ifndef IPC_SOFTIRQ_PRIORITY
	#define IPC_SOFTIRQ_PRIORITY (configMAX_PRIORITIES - 1)
#endif

/**
 * enum msg_receive - used to indicate notification received for a new message
 *
 * @MSG_NOT_RECEIVED: no new message received from the remote core
 * @MSG_IS_RECEIVED: new message received from the remote core
 */
enum msg_receive {
	MSG_NOT_RECEIVED = 0U,
	MSG_IS_RECEIVED = 1U,
};

/* IPC softirq task */
static void ipc_shm_softirq(void);

#if (configSUPPORT_STATIC_ALLOCATION == 1)
StackType_t IPC_xStack[IPC_SOFTIRQ_STACK_SIZE];
StaticTask_t IPC_xTaskBuffer;
#endif

/**
 * struct ipc_os_priv_instance - OS specific private data per instance
 * @local_shm:      local shared memory address
 * @remote_shm:     remote shared memory address
 * @state:          state of instance
 * @rx_irq_num:     rx interrupt number
 * @msg_received:	state to indicate notification received for a new message
 * @rx_cb:          upper layer rx callback
 */
struct ipc_os_priv_instance {
	uintptr local_shm;
	uintptr remote_shm;
	uint8 state;
	sint16 rx_irq_num;
	uint8 msg_received;
	uint32 (*rx_cb)(const uint8 instance, uint32 budget);
};

/**
 * struct ipc_os_priv_type - OS specific private data
 * @id:         private data per instance
 * @softirq_handle: rx task handle used by the ISR to notify the rx task
 * @task_is_initialized: flag to know if the softirq task is initialized
 */
static struct ipc_os_priv_type {
	struct ipc_os_priv_instance id[IPC_SHM_MAX_INSTANCES];
	TaskHandle_t softirq_handle;
	boolean task_is_initialized;
} ipc_os_priv;

/**
 * ipc_os_init() - OS specific initialization code
 * @cfg:        configuration parameters
 * @rx_cb:      rx callback to be called from rx softirq
 *
 * When inter_core_rx_irq is disabled by passing IPC_IRQ_NONE as value, the
 * softirq task will not be created.
 *
 * Return: IPC_SHM_E_OK on success, -IPC_SHM_E_NOMEM if the softirq task creation
 *         failed, -IPC_SHM_E_INVAL for invalid parameter rx_cb
 */
sint8 ipc_os_init(const uint8 instance, const struct ipc_shm_cfg *cfg,
		uint32 (*rx_cb)(const uint8, uint32))
{
	BaseType_t os_status = 0;
	sint8 err = -IPC_SHM_E_INVAL;

	if (rx_cb != NULL) {
		/* save params */
		ipc_os_priv.id[instance].local_shm = cfg->local_shm_addr;
		ipc_os_priv.id[instance].remote_shm = cfg->remote_shm_addr;
		ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_ENABLED;
		ipc_os_priv.id[instance].rx_cb = rx_cb;
		ipc_os_priv.id[instance].rx_irq_num = cfg->inter_core_rx_irq;
		ipc_os_priv.id[instance].msg_received = (uint8)MSG_NOT_RECEIVED;

		if ((ipc_os_priv.id[instance].rx_irq_num == IPC_IRQ_NONE)
			|| (ipc_os_priv.task_is_initialized != FALSE)) {
			/* softirq is not needed when polling */
			err = IPC_SHM_E_OK;
		} else {
			/* create the shm rx softirq task */
#if (configSUPPORT_DYNAMIC_ALLOCATION == 1)
			os_status = xTaskCreate(
						(TaskFunction_t)&ipc_shm_softirq,
						"softirq",
						IPC_SOFTIRQ_STACK_SIZE,
						NULL,
						IPC_SOFTIRQ_PRIORITY,
						&ipc_os_priv.softirq_handle);

			if (os_status != pdPASS) {
				err = -IPC_SHM_E_NOMEM;
			} else {
				ipc_os_priv.task_is_initialized = TRUE;
				err = IPC_SHM_E_OK;
			}
#else
			ipc_os_priv.softirq_handle = xTaskCreateStatic(
						(TaskFunction_t)&ipc_shm_softirq,
						"softirq",
						IPC_SOFTIRQ_STACK_SIZE,
						NULL,
						IPC_SOFTIRQ_PRIORITY,
						IPC_xStack,
						&IPC_xTaskBuffer);

			if (ipc_os_priv.softirq_handle == NULL) {
				err = -IPC_SHM_E_NOMEM;
			} else {
				ipc_os_priv.task_is_initialized = TRUE;
				err = IPC_SHM_E_OK;
			}
#endif
		}
	}

	return err;
}

/**
 * ipc_os_free_irq() - disable irq if not use by nother instances
 */
static void ipc_os_free_irq(const uint8 instance)
{
	int keep_irq_enable = 0;
	uint8 i = 0;

	/* disable notifications from remote */
	if (ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE) {
		for (i = 0 ; i < IPC_SHM_MAX_INSTANCES ; i++) {
			if (instance == i)
				continue;
			if (ipc_os_priv.id[i].rx_irq_num == ipc_os_priv.id[instance].rx_irq_num) {
				keep_irq_enable++;
				break;
			}
		}
		if (keep_irq_enable == 0)
			ipc_hw_irq_disable(instance);
	}
}

/**
 * ipc_os_free() - free OS specific resources
 */
void ipc_os_free(const uint8 instance)
{
	uint8 instance_id = 0;
	int keep_softirq_active = 0;

	/* disable notifications from remote */
	ipc_os_free_irq(instance);

	/* clear private data */
	ipc_os_priv.id[instance].rx_cb = NULL;
	ipc_os_priv.id[instance].state = IPC_SHM_INSTANCE_DISABLED;

	/* Check if all non-polling instances are disable*/
	for(instance_id = 0; instance_id < IPC_SHM_MAX_INSTANCES; instance_id++) {
		if ((ipc_os_priv.id[instance_id].state == IPC_SHM_INSTANCE_ENABLED)
				&& (ipc_os_priv.id[instance_id].rx_irq_num != IPC_IRQ_NONE))
			keep_softirq_active++;
	}


	if ((ipc_os_priv.id[instance].rx_irq_num != IPC_IRQ_NONE)
			&& (keep_softirq_active == 0)) {
		/* kill deferred interrupt handler task if no instance exist */
		if (ipc_os_priv.task_is_initialized != FALSE) {
			vTaskDelete(ipc_os_priv.softirq_handle);
			ipc_os_priv.task_is_initialized = FALSE;
		}
	}
}

/**
 * ipc_shm_softirq() - task acting as deferred interrupt handler
 *
 * This task waits to be signaled by the interrupt handler, then calls the upper
 * layer callback registered with ipc_os_init(). If ipc_os_free() is called,
 * task execution terminates. Memory is freed next time the idle task is run.
 */
static void ipc_shm_softirq(void)
{
	uint32 work = 0;
	uint8 i = 0;

	/* wait for signal from interrupt handler */
	(void)ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

	for ( ; ; ) {
		for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
			if ((ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				|| (ipc_os_priv.id[i].msg_received == (uint8)MSG_NOT_RECEIVED)
				|| (ipc_os_priv.id[i].rx_irq_num == IPC_IRQ_NONE))
				continue;

			do {
				/* call upper layer callback */
				work = ipc_os_priv.id[i].rx_cb(i, IPC_SOFTIRQ_BUDGET);

				/* yield and wait for reschedule */
				taskYIELD();
			} while (work >= IPC_SOFTIRQ_BUDGET);

			/* reset the flag used to notify  message received */
			ipc_os_priv.id[i].msg_received = (uint8)MSG_NOT_RECEIVED;
		}

		for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
			if (ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				continue;

			/* work done, re-enable irq */
			ipc_hw_irq_enable(i);
		}

		/* wait for signal from interrupt handler */
		(void) ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
	}
}

/**
 * ipc_shm_hardirq() - driver interrupt service routine
 *
 * In case of FreeRTOS this ISR is set from the application.
 */
void ipc_shm_hardirq(void)
{
	BaseType_t higher_prio_task_woken = (BaseType_t)pdFALSE;
	UBaseType_t task_critical_status_from_isr;
	uint8 i = 0;

	/* ensure the ipc_shm_softirq is initialized */
	if (ipc_os_priv.task_is_initialized != FALSE) {
		task_critical_status_from_isr = taskENTER_CRITICAL_FROM_ISR();

		for (i = 0; i < IPC_SHM_MAX_INSTANCES; i++) {
			if (ipc_os_priv.id[i].state == IPC_SHM_INSTANCE_DISABLED)
				continue;

			/* disable notifications from remote */
			ipc_hw_irq_disable(i);

			/* clear notification */
			ipc_hw_irq_clear(i);

			/* set the flag for each instance */
			ipc_os_priv.id[i].msg_received = (uint8)MSG_IS_RECEIVED;
		}

		/* schedule deferred interrupt handler */
		vTaskNotifyGiveFromISR(ipc_os_priv.softirq_handle, &higher_prio_task_woken);
		taskEXIT_CRITICAL_FROM_ISR(task_critical_status_from_isr);
		portYIELD_FROM_ISR(higher_prio_task_woken);
	}
}

/**
 * ipc_shm_hardirq_instance() - driver interrupt service routine
 *
 * This function is set as core to core ISR by the application.
 */
void ipc_shm_hardirq_instance(const uint8 instance)
{
	BaseType_t higher_prio_task_woken = (BaseType_t)pdFALSE;
	UBaseType_t task_critical_status_from_isr;

	/* ensure the ipc_shm_softirq is initialized */
	if (ipc_os_priv.task_is_initialized != FALSE) {
		task_critical_status_from_isr = taskENTER_CRITICAL_FROM_ISR();
		if (ipc_os_priv.id[instance].state != IPC_SHM_INSTANCE_DISABLED) {
			/* disable notifications from remote */
			ipc_hw_irq_disable(instance);
			/* clear notification */
			ipc_hw_irq_clear(instance);

			/* set the flag used to notify message is received */
			if (ipc_os_priv.id[instance].msg_received == (uint8)MSG_NOT_RECEIVED) {
				ipc_os_priv.id[instance].msg_received = (uint8)MSG_IS_RECEIVED;
			}

			/* schedule deferred interrupt handler */
			vTaskNotifyGiveFromISR(ipc_os_priv.softirq_handle,
					&higher_prio_task_woken);
		}
		taskEXIT_CRITICAL_FROM_ISR(task_critical_status_from_isr);
		portYIELD_FROM_ISR(higher_prio_task_woken);
	}
}

/**
 * ipc_os_get_local_shm() - get local shared mem address
 */
uintptr ipc_os_get_local_shm(const uint8 instance)
{
	return ipc_os_priv.id[instance].local_shm;
}

/**
 * ipc_os_get_remote_shm() - get remote shared mem address
 */
uintptr ipc_os_get_remote_shm(const uint8 instance)
{
	return ipc_os_priv.id[instance].remote_shm;
}

/**
 * ipc_os_poll_channels() - invoke rx callback configured at initialization
 */
sint8 ipc_os_poll_channels(const uint8 instance)
{
	sint8 err = IPC_SHM_E_OK;

	/* the softirq will handle rx operation if rx interrupt is configured */
	if (ipc_os_priv.id[instance].rx_irq_num == IPC_IRQ_NONE) {
		/* call upper layer callback until work is done */
		(void)ipc_os_priv.id[instance].rx_cb(instance, IPC_SOFTIRQ_BUDGET);
	} else {
		err = -IPC_SHM_E_INVAL;
	}

	return err;
}

#if defined(__cplusplus)
}
#endif
