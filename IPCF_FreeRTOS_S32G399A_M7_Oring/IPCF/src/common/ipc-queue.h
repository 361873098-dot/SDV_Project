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
#ifndef IPC_QUEUE_H
#define IPC_QUEUE_H

#if defined(__cplusplus)
extern "C"{
#endif

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_QUEUE_VENDOR_ID                    43
#define IPC_QUEUE_AR_RELEASE_MAJOR_VERSION     4
#define IPC_QUEUE_AR_RELEASE_MINOR_VERSION     4
#define IPC_QUEUE_AR_RELEASE_REVISION_VERSION  0
#define IPC_QUEUE_SW_MAJOR_VERSION             4
#define IPC_QUEUE_SW_MINOR_VERSION             10
#define IPC_QUEUE_SW_PATCH_VERSION             0

/**
 * struct ipc_ring - memory mapped circular buffer ring
 * @sentinel: a magic word to ensure ring integrity
 * @write:    write index, position used to store next byte in the buffer
 * @read:     read index, read next byte from this position
 * @data:     circular buffer
 */
struct ipc_ring {
	uint64 sentinel;
	volatile uint32 write;
	volatile uint32 read;
	uint8 data[];
};

/**
 * struct ipc_queue - Dual-Ring Shared-Memory Lock-Free FIFO Queue
 * @elem_num:  number of elements in queue
 * @elem_size: element size in bytes (8-byte multiple)
 * @push_ring: push buffer ring mapped in local shared memory
 * @pop_ring:  pop buffer ring mapped in remote shared memory
 *
 * This queue has two buffer rings one for pushing data and one for popping
 * data and works in conjunction with a complementary queue configured by
 * another IPC device (called remote) where the push/pop rings are reversed:
 *     local push_ring == remote pop_ring
 *     local pop_ring == remote push_ring
 *
 * The queue has freedom from interference between local and remote memory
 * domains by executing all write operations only in local memory (push_ring).
 * Read indexes of push_ring and pop_ring are swapped to avoid writing read
 * index in remote memory when doing pop operations.
 *
 * The queue is thread safe as long as only one thread is pushing and only one
 * thread is popping: Single-Producer - Single-Consumer. This thread safety
 * is lock-free and needs one additional sentinel element in rings between
 * write and read index that is never written.
 */
struct ipc_queue {
	uint16 elem_num;
	uint8 elem_size;
	struct ipc_ring *push_ring;
	struct ipc_ring *pop_ring;
};

/**
 * struct ipc_queue_data -  stores queue data used for initialization
 * @elem_size:  element size in bytes (8-byte multiple)
 * @elem_num:   number of elements in queue
 * @queue_type: indicate queue of channel or pool buffer
 * @push_addr:  push buffer ring mapped in local shared memory
 * @pop_addr:   pop buffer ring mapped in remote shared memory
 *
 */
struct ipc_queue_data {
	uint8 elem_size;
	uint16 elem_num;
	enum ipc_shm_queue_type queue_type;
	uintptr push_addr;
	uintptr pop_addr;
};


/**
 * ipc_queue_init() - initializes queue and maps push/pop rings in memory
 * @queue:            [IN] queue pointer
 * @queue_data:       [IN] stores queue data use to initialize a queue
 *
 * Element size must be 8-byte multiple to ensure memory alignment.
 *
 * Queue will add one additional sentinel element to its size for lock-free
 * single-producer - single-consumer thread-safety.
 *
 * Return: IPC_SHM_E_OK on success, error code otherwise
 */
sint8 ipc_queue_init(struct ipc_queue *queue, struct ipc_queue_data queue_data);


/**
 * ipc_queue_free() - free a queue
 * @queue:            [IN] queue pointer
 *
 * Clear queue sentinel and queue pointer
 */
void ipc_queue_free(struct ipc_queue *queue);


/**
 * ipc_queue_push() - pushes element into the queue
 * @queue:            [IN] queue pointer
 * @buf:              [IN] pointer to element to be pushed into the queue
 *
 * Element is pushed into the push ring that is mapped in local shared memory
 * and corresponds to the remote pop ring.
 *
 * Return:	IPC_SHM_E_OK on success, error code otherwise
 */
sint8 ipc_queue_push(struct ipc_queue *queue, const void *buf);


/**
 * ipc_queue_pop() - removes element from queue
 * @queue:           [IN] queue pointer
 * @buf:             [OUT] pointer where to copy the removed element
 *
 * Element is removed from pop ring that is mapped in remote shared memory and
 * it corresponds to the remote push ring.
 *
 * Return:	IPC_SHM_E_OK on success, error code otherwise
 */
sint8 ipc_queue_pop(struct ipc_queue *queue, void *buf);


/**
 * ipc_queue_check_integrity() - check if the sentinel was not overwritten
 * @queue:	[IN] queue pointer
 *
 * Check if the sentinel was not overwritten
 *
 * Return: IPC_SHM_E_OK on success, error code otherwise
 */
sint8 ipc_queue_check_integrity(struct ipc_queue *queue);

/**
 * ipc_queue_mem_size() - return queue footprint in local mapped memory
 * @queue:	[IN] queue pointer
 *
 * Return local mapped memory footprint: local ring control data + ring buffer.
 *
 * Return: size of local mapped memory occupied by queue
 */
static inline uint32 ipc_queue_mem_size(struct ipc_queue *queue)
{
	/* local ring control room + ring size */
	return (uint32)sizeof(struct ipc_ring)
		+ ((uint32)queue->elem_num * (uint32)queue->elem_size);
}

#if defined(__cplusplus)
}
#endif

#endif /* IPC_QUEUE_H */
