/**
 * IPC Shared Memory Driver - queue implementation
 *
 * Copyright 2018-2019,2022-2024 NXP
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
#include "ipc-queue.h"
#include "ipc-util.h"

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_QUEUE_VENDOR_ID_C                    43
#define IPC_QUEUE_AR_RELEASE_MAJOR_VERSION_C     4
#define IPC_QUEUE_AR_RELEASE_MINOR_VERSION_C     4
#define IPC_QUEUE_AR_RELEASE_REVISION_VERSION_C  0
#define IPC_QUEUE_SW_MAJOR_VERSION_C             4
#define IPC_QUEUE_SW_MINOR_VERSION_C             10
#define IPC_QUEUE_SW_PATCH_VERSION_C             0

/*
 * FILE VERSION CHECKS
 */
/* Check if ipc-queue.c file and ipc-shm.h file are of the same vendor */
#if (IPC_QUEUE_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-queue.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-queue.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_QUEUE_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-queue.c and ipc-shm.h are different"
#endif
/* Check if ipc-queue.c file and ipc-shm.h file are of the same software version */
#if ((IPC_QUEUE_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_QUEUE_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_QUEUE_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-queue.c and ipc-shm.h are different"
#endif

/* Check if ipc-queue.c file and ipc-queue.h file are of the same vendor */
#if (IPC_QUEUE_VENDOR_ID_C != IPC_QUEUE_VENDOR_ID)
	#error "ipc-queue.c and ipc-queue.h have different vendor IDs"
#endif
/* Check if ipc-queue.c file and ipc-queue.h file are of the same Autosar version */
#if ((IPC_QUEUE_AR_RELEASE_MAJOR_VERSION_C != IPC_QUEUE_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_MINOR_VERSION_C != IPC_QUEUE_AR_RELEASE_MINOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_REVISION_VERSION_C != IPC_QUEUE_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-queue.c and ipc-queue.h are different"
#endif
/* Check if ipc-queue.c file and ipc-queue.h file are of the same software version */
#if ((IPC_QUEUE_SW_MAJOR_VERSION_C != IPC_QUEUE_SW_MAJOR_VERSION) || \
	(IPC_QUEUE_SW_MINOR_VERSION_C != IPC_QUEUE_SW_MINOR_VERSION) || \
	(IPC_QUEUE_SW_PATCH_VERSION_C != IPC_QUEUE_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-queue.c and ipc-queue.h are different"
#endif

/* Check if ipc-queue.c file and ipc-util.h file are of the same vendor */
#if (IPC_QUEUE_VENDOR_ID_C != IPC_UTIL_VENDOR_ID)
	#error "ipc-queue.c and ipc-util.h have different vendor IDs"
#endif
/* Check if ipc-queue.c file and ipc-util.h file are of the same Autosar version */
#if ((IPC_QUEUE_AR_RELEASE_MAJOR_VERSION_C != IPC_UTIL_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_MINOR_VERSION_C != IPC_UTIL_AR_RELEASE_MINOR_VERSION) || \
	(IPC_QUEUE_AR_RELEASE_REVISION_VERSION_C != IPC_UTIL_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-queue.c and ipc-util.h are different"
#endif
/* Check if ipc-queue.c file and ipc-util.h file are of the same software version */
#if ((IPC_QUEUE_SW_MAJOR_VERSION_C != IPC_UTIL_SW_MAJOR_VERSION) || \
	(IPC_QUEUE_SW_MINOR_VERSION_C != IPC_UTIL_SW_MINOR_VERSION) || \
	(IPC_QUEUE_SW_PATCH_VERSION_C != IPC_UTIL_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-queue.c and ipc-util.h are different"
#endif

sint8 ipc_queue_pop(struct ipc_queue *queue, void *buf)
{
	uint32 write; /* cache write index for thread-safety */
	uint32 read; /* cache read index for thread-safety */
	void *src;
	sint8 err = -IPC_SHM_E_INVAL;

	if ((queue != NULL) && (buf != NULL)) {
		write = queue->pop_ring->write;

		/* read indexes of push/pop rings are swapped (interference freedom) */
		read = queue->push_ring->read;

		if ((read >= queue->elem_num) || (write >= queue->elem_num)) {
			/* Check if read and write are valid value */
			err = -IPC_SHM_E_INVAL;
		} else if (ipc_queue_check_integrity(queue) != IPC_SHM_E_OK) {
			/* Check integrity of queue */
			err = -IPC_SHM_E_INTEGRITY;
		} else if (read == write) {
			/* check if queue is empty */
			err = -IPC_SHM_E_NO_QUEUE;
		} else {
			/* copy queue element in buffer */
			src = &queue->pop_ring->data[read * queue->elem_size];
			ipc_memcpy(buf, src, queue->elem_size);

			/* increment read index with wrap around */
			queue->push_ring->read = (read + 1u) % queue->elem_num;
			err = IPC_SHM_E_OK;
		}
	}

	return err;
}

sint8 ipc_queue_push(struct ipc_queue *queue, const void *buf)
{
	uint32 write; /* cache write index for thread-safety */
	uint32 read; /* cache read index for thread-safety */
	void *dst;
	sint8 err = -IPC_SHM_E_INVAL;

	if ((queue != NULL) && (buf != NULL)) {
		write = queue->push_ring->write;

		/* read indexes of push/pop rings are swapped (interference freedom) */
		read = queue->pop_ring->read;

		if ((read >= queue->elem_num) || (write >= queue->elem_num)) {
			/* Check if read and write are valid value */
			err = -IPC_SHM_E_INVAL;
		} else if (((write + 1u) % queue->elem_num) == read) {
			/* check if queue is full ([write + 1 == read] because of sentinel) */
			err = -IPC_SHM_E_NOMEM;
		} else {
			/* copy element from buffer in queue */
			dst = &queue->push_ring->data[write * queue->elem_size];
			ipc_memcpy(dst, buf, queue->elem_size);

			/* increment write index with wrap around */
			queue->push_ring->write = (write + 1u) % queue->elem_num;

			err = IPC_SHM_E_OK;
		}
	}

	return err;
}

/**
 * ipc_queue_sync_index() - synchronize queue read/write index with remote memory
 * @queue:                  [IN] queue pointer
 * @queue_type:             [IN] indicate queue of channel or pool buffer
 *
 * Return: 0 on success, error code otherwise
 */
static sint8 ipc_queue_sync_index(struct ipc_queue *queue,
									enum ipc_shm_queue_type queue_type)
{
	sint8 err = 0;

	/* Check if remote initialization is in progress */
	if (queue->pop_ring->sentinel == IPC_QUEUE_INIT_IN_PROGRESS) {
		err = -IPC_SHM_E_REMOTE_INIT_IN_PROGRESS;
	} else {
		/* Mark that the queue initialization is in progress */
		queue->push_ring->sentinel = IPC_QUEUE_INIT_IN_PROGRESS;

		if (queue->pop_ring->sentinel == IPC_QUEUE_INIT_DONE) {
			/* Use values from remote if it is already initialized */
			queue->push_ring->write = queue->pop_ring->read;
			if (queue_type == IPC_SHM_CHANNEL_QUEUE) {
				queue->push_ring->read = queue->pop_ring->write
										% queue->elem_num;
			} else {
				queue->push_ring->read = (queue->pop_ring->write + 1u)
										% queue->elem_num;
			}
		} else {
			queue->push_ring->write = 0;
			queue->push_ring->read = 0;
		}
		err = IPC_SHM_E_OK;
	}

	return err;
}

sint8 ipc_queue_init(struct ipc_queue *queue, struct ipc_queue_data queue_data)
{
	sint8 err = -IPC_SHM_E_INVAL;

	if ((queue != NULL)
			&& (queue_data.push_addr != (uintptr)NULL)
			&& (queue_data.pop_addr != (uintptr)NULL)
			&& (queue_data.elem_num != 0u)
			&& (queue_data.elem_size != 0u)
			&& ((queue_data.elem_size % 8u) == 0u)
			&& ((queue_data.queue_type == IPC_SHM_CHANNEL_QUEUE)
				|| (queue_data.queue_type == IPC_SHM_POOL_QUEUE))) {
		/* add 1 sentinel element in queue for lock-free thread-safety */
		queue->elem_num = queue_data.elem_num + 1u;

		queue->elem_size = queue_data.elem_size;

		/* map and init push ring in local memory */
		queue->push_ring = (struct ipc_ring *)queue_data.push_addr;
		/* map pop ring in remote memory (init is done by remote) */
		queue->pop_ring = (struct ipc_ring *)queue_data.pop_addr;
		/* Synchronize read/write indexes */
		err = ipc_queue_sync_index(queue, queue_data.queue_type);
	}

	return err;
}

void ipc_queue_free(struct ipc_queue *queue)
{
	/* Clear push ring sentinel and data */
	if (queue != NULL) {
		if (queue->push_ring != NULL) {
			if ((queue->push_ring->sentinel == IPC_QUEUE_INIT_DONE)
					|| (queue->push_ring->sentinel == IPC_QUEUE_INIT_IN_PROGRESS)) {
				queue->elem_num = 0;
				queue->elem_size = 0;
				queue->push_ring->sentinel = 0;
				queue->push_ring->write = 0;
				queue->push_ring->read = 0;
			}
		}
		queue->push_ring = NULL;
	}
}

sint8 ipc_queue_check_integrity(struct ipc_queue *queue)
{
	sint8 err = -IPC_SHM_E_INTEGRITY;

	/* Check integrity of both push and pop ring */
	if ((IPC_QUEUE_INIT_DONE == queue->pop_ring->sentinel) &&
			(IPC_QUEUE_INIT_DONE == queue->push_ring->sentinel))
		err = IPC_SHM_E_OK;

	return err;
}

#if defined(__cplusplus)
}
#endif
