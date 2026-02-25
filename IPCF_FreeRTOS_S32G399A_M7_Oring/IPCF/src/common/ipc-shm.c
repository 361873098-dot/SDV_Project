/**
 * IPC Shared Memory Driver - API Implementation
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
#include "ipc-os.h"
#include "ipc-hw.h"
#include "ipc-queue.h"

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_SHM_VENDOR_ID_C                    43
#define IPC_SHM_AR_RELEASE_MAJOR_VERSION_C     4
#define IPC_SHM_AR_RELEASE_MINOR_VERSION_C     4
#define IPC_SHM_AR_RELEASE_REVISION_VERSION_C  0
#define IPC_SHM_SW_MAJOR_VERSION_C             4
#define IPC_SHM_SW_MINOR_VERSION_C             10
#define IPC_SHM_SW_PATCH_VERSION_C             0

/*
 * FILE VERSION CHECKS
 */
/* Check if ipc-shm.c file and ipc-shm.h file are of the same vendor */
#if (IPC_SHM_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-shm.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-shm.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_SHM_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-shm.c and ipc-shm.h are different"
#endif
/* Check if ipc-shm.c file and ipc-shm.h file are of the same software version */
#if ((IPC_SHM_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_SHM_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_SHM_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-shm.c and ipc-shm.h are different"
#endif

/* Check if ipc-shm.c file and ipc-os.h file are of the same vendor */
#if (IPC_SHM_VENDOR_ID_C != IPC_OS_VENDOR_ID)
	#error "ipc-shm.c and ipc-os.h have different vendor IDs"
#endif
/* Check if ipc-shm.c file and ipc-os.h file are of the same Autosar version */
#if ((IPC_SHM_AR_RELEASE_MAJOR_VERSION_C != IPC_OS_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_MINOR_VERSION_C != IPC_OS_AR_RELEASE_MINOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_REVISION_VERSION_C != IPC_OS_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-shm.c and ipc-os.h are different"
#endif
/* Check if ipc-shm.c file and ipc-os.h file are of the same software version */
#if ((IPC_SHM_SW_MAJOR_VERSION_C != IPC_OS_SW_MAJOR_VERSION) || \
	(IPC_SHM_SW_MINOR_VERSION_C != IPC_OS_SW_MINOR_VERSION) || \
	(IPC_SHM_SW_PATCH_VERSION_C != IPC_OS_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-shm.c and ipc-os.h are different"
#endif

/* Check if ipc-shm.c file and ipc-hw.h file are of the same vendor */
#if (IPC_SHM_VENDOR_ID_C != IPC_HW_VENDOR_ID)
	#error "ipc-shm.c and ipc-hw.h have different vendor IDs"
#endif
/* Check if ipc-shm.c file and ipc-hw.h file are of the same Autosar version */
#if ((IPC_SHM_AR_RELEASE_MAJOR_VERSION_C != IPC_HW_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_MINOR_VERSION_C != IPC_HW_AR_RELEASE_MINOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_REVISION_VERSION_C != IPC_HW_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-shm.c and ipc-hw.h are different"
#endif
/* Check if ipc-shm.c file and ipc-hw.h file are of the same software version */
#if ((IPC_SHM_SW_MAJOR_VERSION_C != IPC_HW_SW_MAJOR_VERSION) || \
	(IPC_SHM_SW_MINOR_VERSION_C != IPC_HW_SW_MINOR_VERSION) || \
	(IPC_SHM_SW_PATCH_VERSION_C != IPC_HW_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-shm.c and ipc-hw.h are different"
#endif

/* Check if ipc-shm.c file and ipc-queue.h file are of the same vendor */
#if (IPC_SHM_VENDOR_ID_C != IPC_QUEUE_VENDOR_ID)
	#error "ipc-shm.c and ipc-queue.h have different vendor IDs"
#endif
/* Check if ipc-shm.c file and ipc-queue.h file are of the same Autosar version */
#if ((IPC_SHM_AR_RELEASE_MAJOR_VERSION_C != IPC_QUEUE_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_MINOR_VERSION_C != IPC_QUEUE_AR_RELEASE_MINOR_VERSION) || \
	(IPC_SHM_AR_RELEASE_REVISION_VERSION_C != IPC_QUEUE_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-shm.c and ipc-queue.h are different"
#endif
/* Check if ipc-shm.c file and ipc-queue.h file are of the same software version */
#if ((IPC_SHM_SW_MAJOR_VERSION_C != IPC_QUEUE_SW_MAJOR_VERSION) || \
	(IPC_SHM_SW_MINOR_VERSION_C != IPC_QUEUE_SW_MINOR_VERSION) || \
	(IPC_SHM_SW_PATCH_VERSION_C != IPC_QUEUE_SW_PATCH_VERSION))
#error "Software Version Numbers of ipc-shm.c and ipc-queue.h are different"
#endif

/* magic number to indicate the driver is initialized */
#define IPC_SHM_STATE_READY 0x3252455646435049ULL
#define IPC_SHM_STATE_CLEAR 0u

/* Indicates that the unmanaged channel initialization is in progress */
#define IPC_SHM_UCHAN_INIT_IN_PROGRESS   0x54494E49UL
/* Indicates that the unmanaged channel initialization is done */
#define IPC_UCHAN_INIT_DONE              0x55435049UL

/* flag telling if buffer is from remote OS */
#define IPC_BUFFER_FROM_LOCAL  0u
#define IPC_BUFFER_FROM_REMOTE 1u

/**
 * enum ipc_shm_instance_state - used for IPC instance status
 * @IPC_SHM_INSTANCE_USED:  instance is used
 * @IPC_SHM_INSTANCE_FREE:  instance is free and can be used
 * @IPC_SHM_INSTANCE_ERROR: there are some errors
 */
enum ipc_shm_instance_state {
	IPC_SHM_INSTANCE_USED = 0u,
	IPC_SHM_INSTANCE_FREE = 1u,
	IPC_SHM_INSTANCE_ERROR = 2u,
};

/**
 * struct ipc_shm_pool_addr - struct stores temporary addresses of local/remote
 *                            memory
 * @local_pool_shm:  address of local buffer pool
 * @remote_pool_shm: address of remote buffer pool
 */
struct ipc_shm_pool_addr {
	uintptr local_pool_shm;
	uintptr remote_pool_shm;
};

/**
 * struct ipc_shm_bd - buffer descriptor (store buffer location and data size)
 * @pool_id:   index of buffer pool
 * @buf_id:    index of buffer from buffer pool
 * @data_size: size of data written in buffer
 */
struct ipc_shm_bd {
	uint16 pool_id;
	uint16 buf_id;
	uint32 data_size;
};

/**
 * struct ipc_shm_pool - buffer pool private data
 * @num_bufs:         number of buffers in pool
 * @buf_size:         size of buffers
 * @shm_size:         size of shared memory mapped by this pool (queue + bufs)
 * @local_pool_addr:  address of local buffer pool
 * @remote_pool_addr: address of remote buffer pool
 * @bd_queue:         queue containing BDs of free buffers
 *
 * bd_queue has two rings: one for pushing BDs (release ring) and one for
 * popping BDs (acquire ring).
 * Local IPC pushes BDs into release ring when local app finishes processing a
 * received buffer and calls ipc_shm_release_buf(). Remote IPC pops BDs from its
 * acquire ring (our release ring) when remote app calls ipc_shm_acquire_buf()
 * to prepare for a Tx operation.
 *
 * The relation between local and remote bd_queue rings is:
 *     local acquire ring == remote release ring
 *     local release ring == remote acquire ring
 */
struct ipc_shm_pool {
	uint16 num_bufs;
	uint32 buf_size;
	uint32 shm_size;
	uintptr local_pool_addr;
	uintptr remote_pool_addr;
	struct ipc_queue bd_queue;
};

/**
 * struct ipc_managed_channel - managed channel private data
 * @bd_queue:  queue containing BDs of sent/received buffers
 * @num_pools: number of buffer pools
 * @pools:     buffer pools private data
 * @rx_cb:     receive callback
 * @cb_arg:    optional receive callback argument
 *
 * bd_queue has two rings: one for pushing BDs (Tx ring) and one for popping
 * BDs (Rx ring).
 * Local IPC device reads BDs pushed into bd_queue by remote IPC and remote
 * IPC device reads BDs pushed into bd_queue by local IPC.
 *
 * The relation between local and remote bd_queue rings is:
 *     local Tx ring == remote Rx ring
 *     local Rx ring == remote Tx ring
 */
struct ipc_managed_channel {
	struct ipc_queue bd_queue;
	uint16 num_pools;
	struct ipc_shm_pool pools[IPC_SHM_MAX_POOLS];
	void (*rx_cb)(void *cb_arg, const uint8 instance, uint8 chan_id,
			void *buf, uint32 size);
	void *cb_arg;
};

/**
 * struct ipc_channel_umem - unmanaged channel memory control structure
 * @sentinel:        magic word to ensure unmanaged channel integrity
 * @tx_count:        local channel Tx counter (it wraps around at max uint32)
 * @remote_tx_count: copy of remote Tx counter
 * @mem:             local channel unmanaged memory buffer
 *
 * tx_count is used by remote peer in Rx intr handler to determine if this
 * channel had a Tx operation and decide whether to call the app Rx callback.
 */
struct ipc_channel_umem {
	uint32 sentinel;
	volatile uint32 tx_count;
	volatile uint32 remote_tx_count;
	uint8 reserved[4];
	uint8 mem[];
};

/**
 * struct ipc_unmanaged_channel - unmanaged channel private data
 * @size:        unmanaged channel memory size requested by app
 * @local_umem:  local channel unmanaged memory
 * @remote_umem: remote channel unmanaged memory
 * @rx_cb:       receive callback
 * @cb_arg:      optional receive callback argument
 */
struct ipc_unmanaged_channel {
	uint32 size;
	struct ipc_channel_umem *local_mem;
	struct ipc_channel_umem *remote_mem;
	void (*rx_cb)(void *cb_arg, const uint8 instance, uint8 chan_id,
			void *buf);
	void *cb_arg;
};

/**
 * struct ipc_shm_channel - ipc channel private data
 * @id:   channel id
 * @type: channel type (see ipc_shm_channel_type)
 * @ch:   managed/unmanaged channel private data
 */
struct ipc_shm_channel {
	uint8 id;
	enum ipc_shm_channel_type type;
	union {
		struct ipc_managed_channel mng;
		struct ipc_unmanaged_channel umng;
	} ch;
};

/**
 * struct ipc_shm_global - ipc shm global data shared with remote
 * @state: state to indicate whether local is initialized
 *
 * Global data is located at beginning of local/remote shared memory so the size
 * of this struct should chosen so that memory alignment is preserved.
 */
struct ipc_shm_global {
	uint64 state;
};

/**
 * struct ipc_shm_priv - ipc shm private data
 * @shm_size:     local/remote shared memory size
 * @num_channels: number of shared memory channels
 * @channels:     ipc channels private data
 * @global:       local global data shared with remote
 */
struct ipc_shm_priv {
	uint32 shm_size;
	uint8 num_channels;
	struct ipc_shm_channel channels[IPC_SHM_MAX_CHANNELS];
	struct ipc_shm_global *global;
};

/* ipc shm private data */
static struct ipc_shm_priv ipc_shm_priv_data[IPC_SHM_MAX_INSTANCES];

/* get channel with validation (can be used in API functions) */
static inline struct ipc_shm_channel *get_channel(const uint8 instance,
		uint8 chan_id)
{
	struct ipc_shm_channel *channel = NULL;

	if (chan_id >= ipc_shm_priv_data[instance].num_channels) {
		channel = NULL;
	} else {
		channel = &ipc_shm_priv_data[instance].channels[chan_id];
	}

	return channel;
}

/* get managed channel with validation */
static inline struct ipc_managed_channel *get_managed_chan(
		const uint8 instance, uint8 chan_id)
{
	struct ipc_managed_channel *channel = NULL;
	struct ipc_shm_channel *chan = get_channel(instance, chan_id);

	if ((chan == NULL) || (chan->type != IPC_SHM_MANAGED)) {
		channel = NULL;
	} else {
		channel = &chan->ch.mng;
	}

	return channel;
}

/* get unmanaged channel with validation */
static inline struct ipc_unmanaged_channel *get_unmanaged_chan(
		const uint8 instance, uint8 chan_id)
{
	struct ipc_unmanaged_channel *channel = NULL;
	struct ipc_shm_channel *chan = get_channel(instance, chan_id);

	if ((chan == NULL) || (chan->type != IPC_SHM_UNMANAGED)) {
		channel = NULL;
	} else {
		channel = &chan->ch.umng;
	}

	return channel;
}

/* check integrity of uchan: the boundaries have not been altered */
static sint8 ipc_check_uchan_integrity(const struct ipc_unmanaged_channel *uchan)
{
	sint8 err = -IPC_SHM_E_INTEGRITY;

	if ((uchan->local_mem->sentinel == (uint32)IPC_UCHAN_INIT_DONE)
			&& (uchan->remote_mem->sentinel == (uint32)IPC_UCHAN_INIT_DONE))
		err = IPC_SHM_E_OK;

	return err;
}

/* check integrity of uchan: the boundaries have not been altered */
static sint8 ipc_check_uchan_local_integrity(const struct ipc_unmanaged_channel *uchan)
{
	sint8 err = -IPC_SHM_E_INTEGRITY;

	if (uchan->local_mem->sentinel == (uint32)IPC_UCHAN_INIT_DONE)
		err = IPC_SHM_E_OK;

	return err;
}

/* check integrity of mchan: the boundaries have not been altered */
static sint8 ipc_check_mchan_integrity(struct ipc_managed_channel *mchan)
{
	sint8 err = IPC_SHM_E_OK;
	uint16 pool_id;
	struct ipc_shm_pool *pool = NULL;

	if (IPC_SHM_E_OK == ipc_queue_check_integrity(&mchan->bd_queue)) {
		/* check all the pool bd boundaries */
		for (pool_id = 0; pool_id < mchan->num_pools; pool_id++) {
			pool = &mchan->pools[pool_id];
			if (IPC_SHM_E_OK != ipc_queue_check_integrity(&pool->bd_queue))
				err = -IPC_SHM_E_INTEGRITY;
		}
	} else {
		err = -IPC_SHM_E_INTEGRITY;
	}
	return err;
}

/**
 * ipc_channel_rx() - handle Rx for a single channel
 * @instance: instance id
 * @chan_id:  channel id
 * @budget:   available work budget (number of messages to be processed)
 *
 * Return:	work done
 */
static uint32 ipc_channel_rx(const uint8 instance, uint8 chan_id, uint32 budget)
{
	struct ipc_shm_channel *chan =
			&ipc_shm_priv_data[instance].channels[chan_id];
	struct ipc_managed_channel *mchan = &chan->ch.mng;
	struct ipc_unmanaged_channel *uchan = &chan->ch.umng;
	struct ipc_shm_pool *pool;
	struct ipc_shm_bd bd;
	uintptr buf_addr;
	uint32 buf_offset;
	uint32 remote_tx_count;
	sint8 result = 0;
	uint32 work = 0;

	/* unmanaged channels: call Rx callback if channel Tx counter changed */
	if (chan->type == IPC_SHM_UNMANAGED) {

		if (IPC_SHM_E_OK == ipc_check_uchan_integrity(uchan)) {
			remote_tx_count = uchan->remote_mem->tx_count;

			/* call Rx cb if remote Tx counter changed */
			if (remote_tx_count != uchan->local_mem->remote_tx_count) {

				/* save new remote Tx counter */
				uchan->local_mem->remote_tx_count = remote_tx_count;

				uchan->rx_cb(uchan->cb_arg, instance, chan->id,
						(void *)uchan->remote_mem->mem);

				work = budget;
			}
		}
	} else {
		/* managed channels: process incoming BDs in the limit of budget */
		while (work < budget) {
			result = ipc_queue_pop(&mchan->bd_queue, &bd);
			if (result != IPC_SHM_E_OK) {
				break;
			}
			pool = &mchan->pools[bd.pool_id];
			buf_offset = pool->buf_size * bd.buf_id;
			buf_addr = pool->remote_pool_addr + buf_offset;

			/* check if buf_addr is valid */
			if ((buf_addr >= ipc_os_get_remote_shm(instance)) &&
				((buf_addr + pool->buf_size) <= (ipc_os_get_remote_shm(instance) +
				ipc_shm_priv_data[instance].shm_size))) {
				mchan->rx_cb(mchan->cb_arg, instance, chan->id,
					(void *)buf_addr, bd.data_size);
			}

			work++;
		}
	}

	return work;
}

/**
 * ipc_instance_is_free() - determine if the instance is used or not
 * @instance: instance id
 *
 * This function return the state of instance.
 *
 * Return: IPC_SHM_INSTANCE_FREE if instance is free,
 *     IPC_SHM_INSTANCE_USED otherwise or
 *     IPC_SHM_INSTANCE_ERROR if there is errors
 */
static enum ipc_shm_instance_state ipc_instance_is_free(const uint8 instance)
{
	enum ipc_shm_instance_state err = IPC_SHM_INSTANCE_ERROR;

	if (instance < IPC_SHM_MAX_INSTANCES) {
		if (ipc_shm_priv_data[instance].global != NULL) {
			if (ipc_shm_priv_data[instance].global->state == (uint64)IPC_SHM_STATE_READY) {
				err = IPC_SHM_INSTANCE_USED;
			}

			if (ipc_shm_priv_data[instance].global->state == (uint64)IPC_SHM_STATE_CLEAR) {
				err = IPC_SHM_INSTANCE_FREE;
			}
		}
	}

	return err;
}

/**
 * ipc_shm_rx() - shm Rx handler, called from softirq
 * @instance: instance id
 * @budget:   available work budget (number of messages to be processed)
 *
 * This function handles all channels using a fair handling algorithm: all
 * channels are treated equally and no channel is starving.
 *
 * Return:	work done
 */
static uint32 ipc_shm_rx(const uint8 instance, uint32 budget)
{
	uint8 num_chans = ipc_shm_priv_data[instance].num_channels;
	uint32 chan_budget, chan_work;
	uint8 more_work = 1u;
	uint32 work = 0u;
	uint8 chan_id = 0u;

	/* fair channel handling algorithm */
	while ((work < budget) && (more_work > 0u)) {
		chan_budget = (budget - work) / (num_chans);
		if (chan_budget == 0u) {
			chan_budget = 1u;
		}
		more_work = 0u;

		/* flush dcache before using it */
		ipc_hw_flush_cache_remote(instance);

		for (chan_id = 0; chan_id < num_chans; chan_id++) {
			chan_work = ipc_channel_rx(instance, chan_id, chan_budget);
			work += chan_work;

			if (chan_work == chan_budget)
				more_work = 1u;
		}
	}

	return work;
}

/**
 * ipc_buffer_populate() - populate bd_queue with free BDs
 * @instance: instance id
 * @mng_pool: addresses of local/remote memory of target pool
 * @pool_id:  pool index in channel
 * @pool:     buffer pool private data configuration
 * @cfg:      pool configuration parameters
 *
 * To ensure freedom from interference when writing in shared memory, only one
 * IPC is allowed to write in a BD ring, so the IPC that pushes BDs in the
 * release ring at the end of an Rx operation must also initialize it. That's
 * why local IPC initializes bd_queue with BDs pointing to remote free buffers.
 * Since the shared memory configuration is symmetric and remote base address
 * is known, local IPC can compute the remote BD info.
 *
 * Return: IPC_SHM_E_OK for success, error code otherwise
 */
static sint8 ipc_buffer_populate(const uint8 instance, struct ipc_shm_pool_addr *mng_pool,
			uint16 pool_id, struct ipc_shm_pool *pool, const struct ipc_shm_pool_cfg *cfg)
{
	sint8 err = -IPC_SHM_E_INVAL;
	struct ipc_shm_bd bd;
	uint16 buf_id = 0u;
	uint32 queue_mem_size = ipc_queue_mem_size(&pool->bd_queue);

	/* init actual local buffer pool addr */
	pool->local_pool_addr = mng_pool->local_pool_shm + queue_mem_size;
	/* init actual remote buffer pool addr */
	pool->remote_pool_addr = mng_pool->remote_pool_shm + queue_mem_size;

	pool->shm_size = queue_mem_size + (cfg->buf_size * cfg->num_bufs);

	/* check if pool fits into shared memory */
	if ((mng_pool->local_pool_shm + pool->shm_size)
			> (ipc_os_get_local_shm(instance)
				+ ipc_shm_priv_data[instance].shm_size)) {
		err = -IPC_SHM_E_NOMEM;
	} else {
		/* populate bd_queue with free BDs from remote pool */
		for (buf_id = 0; buf_id < pool->num_bufs; buf_id++) {
			bd.pool_id = pool_id;
			bd.buf_id = buf_id;
			bd.data_size = 0;

			err = ipc_queue_push(&pool->bd_queue, &bd);
			if (err != IPC_SHM_E_OK) {
				break;
			}
		}
	}

	return err;
}

/**
 * ipc_buf_pool_init() - init buffer pool
 * @instance: instance id
 * @chan_id:  channel index
 * @pool_id:  pool index in channel
 * @mng_pool: addresses of local/remote memory of target pool
 * @cfg:      pool configuration parameters
 *
 * To ensure freedom from interference when writing in shared memory, only one
 * IPC is allowed to write in a BD ring, so the IPC that pushes BDs in the
 * release ring at the end of an Rx operation must also initialize it. That's
 * why local IPC initializes bd_queue with BDs pointing to remote free buffers.
 * Since the shared memory configuration is symmetric and remote base address
 * is known, local IPC can compute the remote BD info.
 *
 * Return: IPC_SHM_E_OK for success, error code otherwise
 */
static sint8 ipc_buf_pool_init(const uint8 instance, uint8 chan_id, uint16 pool_id,
		struct ipc_shm_pool_addr *mng_pool, const struct ipc_shm_pool_cfg *cfg)
{
	struct ipc_managed_channel *chan
		= &ipc_shm_priv_data[instance].channels[chan_id].ch.mng;
	struct ipc_shm_pool *pool = &chan->pools[pool_id];
	struct ipc_queue_data queue_data;
	sint8 err = -IPC_SHM_E_INVAL;

	if (cfg->num_bufs <= IPC_SHM_MAX_BUFS_PER_POOL) {
		pool->num_bufs = cfg->num_bufs;
		pool->buf_size = cfg->buf_size;

		/* Preapare queue data parameter */
		queue_data.queue_type = IPC_SHM_POOL_QUEUE;
		queue_data.elem_size = (uint8)sizeof(struct ipc_shm_bd);
		queue_data.elem_num = (uint16)cfg->num_bufs;
		queue_data.push_addr = mng_pool->local_pool_shm;
		queue_data.pop_addr = mng_pool->remote_pool_shm;

		/* init pool bd_queue with push ring mapped at the start of local
		 * pool shm and pop ring mapped at start of remote pool shm
		 */
		err = ipc_queue_init(&pool->bd_queue, queue_data);

		if (err == IPC_SHM_E_OK) {
			err = ipc_buffer_populate(instance, mng_pool, pool_id, pool, cfg);
			if (err == IPC_SHM_E_OK) {
				/* Mark queue as initialized if everything is ok */
				pool->bd_queue.push_ring->sentinel = IPC_QUEUE_INIT_DONE;
			}
		}
	}

	return err;
}

/**
 * ipc_get_total_buf_per_chan() - get total buffers of an managed channel
 *
 * @instance: instance id
 * @chan_id:  channel id
 * @cfg:      managed channel configuration
 *
 * Return: total buffers, 0 if error
 */
static uint32 ipc_get_total_buf_per_chan(const uint8 instance, uint8 chan_id,
		const struct ipc_shm_managed_cfg *cfg)
{
	struct ipc_managed_channel *chan =
		&ipc_shm_priv_data[instance].channels[chan_id].ch.mng;
	const struct ipc_shm_pool_cfg *pool_cfg;
	uint32 prev_buf_size = 0u;
	uint32 total_bufs = 0u;
	sint8 err = -IPC_SHM_E_INVAL;
	uint8 pool_id = 0;

	if ((cfg->num_pools > 0u) && (cfg->num_pools <= IPC_SHM_MAX_POOLS)) {
		err = IPC_SHM_E_OK;
		/* save managed channel parameters */
		chan->rx_cb = cfg->rx_cb;
		chan->cb_arg = cfg->cb_arg;
		chan->num_pools = cfg->num_pools;

		/* check that pools are sorted in ascending order by buf size
		 * and count total number of buffers from all pools
		 */
		for (pool_id = 0; pool_id < chan->num_pools; pool_id++) {
			pool_cfg = &cfg->pools[pool_id];

			if (pool_cfg->buf_size < prev_buf_size) {
				err = -IPC_SHM_E_INVAL;
			} else {
				prev_buf_size = pool_cfg->buf_size;
				total_bufs += pool_cfg->num_bufs;
			}
			if ((err != IPC_SHM_E_OK)
					|| (total_bufs > IPC_SHM_MAX_BUFS_PER_CHANNEL)) {
				err = -IPC_SHM_E_INVAL;
				break;
			}
		}
	}

	if (err != IPC_SHM_E_OK) {
		total_bufs = 0u;
	}

	return total_bufs;
}

/**
 * managed_pools_init() - initialize managed channel
 *
 * @instance:   instance id
 * @chan_id:    channel id
 * @local_shm:  local shared memory
 * @remote_shm: remote shared memort
 * @cfg:        managed channel configuration
 *
 * Return: IPC_SHM_E_OK for success, error code otherwise
 */
static sint8 managed_pools_init(const uint8 instance, uint8 chan_id,
		uintptr local_shm, uintptr remote_shm,
		const struct ipc_shm_managed_cfg *cfg)
{
	sint8 err = -IPC_SHM_E_INVAL;
	struct ipc_managed_channel *chan =
		&ipc_shm_priv_data[instance].channels[chan_id].ch.mng;
	struct ipc_shm_pool_addr mng_pool_addr
			= { .local_pool_shm = (uintptr)NULL,
				.remote_pool_shm = (uintptr)NULL};
	uint32 queue_mem_size = ipc_queue_mem_size(&chan->bd_queue);
	uint16 pool_id = 0;

	/* init&map buffer pools after channel bd_queue */
	mng_pool_addr.local_pool_shm = local_shm + queue_mem_size;
	mng_pool_addr.remote_pool_shm = remote_shm + queue_mem_size;

	/* check if pool fits into shared memory */
	if ((mng_pool_addr.local_pool_shm)
			> (ipc_os_get_local_shm(instance)
				+ ipc_shm_priv_data[instance].shm_size)) {
		err = -IPC_SHM_E_NOMEM;
	} else {
		for (pool_id = 0; pool_id < chan->num_pools; pool_id++) {
			err = ipc_buf_pool_init(instance, chan_id, pool_id,
				&mng_pool_addr, &cfg->pools[pool_id]);
			if (err != IPC_SHM_E_OK) {
				break;
			}

			/* compute next pool local
			 * and remote shm base address
			 */
			mng_pool_addr.local_pool_shm
					+= chan->pools[pool_id].shm_size;
			mng_pool_addr.remote_pool_shm
					+= chan->pools[pool_id].shm_size;
		}
	}

	return err;
}
/**
 * managed_channel_init() - initialize managed channel
 *
 * @instance:   instance id
 * @chan_id:    channel id
 * @local_shm:  local shared memory
 * @remote_shm: remote shared memort
 * @cfg:        managed channel configuration
 *
 * Return: IPC_SHM_E_OK for success, error code otherwise
 */
static sint8 managed_channel_init(const uint8 instance, uint8 chan_id,
		uintptr local_shm, uintptr remote_shm,
		const struct ipc_shm_managed_cfg *cfg)
{
	struct ipc_managed_channel *chan =
		&ipc_shm_priv_data[instance].channels[chan_id].ch.mng;
	struct ipc_queue_data queue_data;
	uint32 total_bufs = ipc_get_total_buf_per_chan(instance, chan_id, cfg);
	sint8 err = -IPC_SHM_E_INVAL;

	if (total_bufs != 0u) {
		/* Preapare queue data parameter */
		queue_data.queue_type = IPC_SHM_CHANNEL_QUEUE;
		queue_data.elem_size = (uint8)sizeof(struct ipc_shm_bd);
		queue_data.elem_num = (uint16)total_bufs;
		queue_data.push_addr = local_shm;
		queue_data.pop_addr = remote_shm;

		/* init channel bd_queue with push ring mapped at the start of local
		 * channel shm and pop ring mapped at start of remote channel shm
		 */
		err = ipc_queue_init(&chan->bd_queue, queue_data);

		if (err == IPC_SHM_E_OK) {
			/* Mark queue as initialized if everything is ok */
			chan->bd_queue.push_ring->sentinel = IPC_QUEUE_INIT_DONE;
			err = managed_pools_init(instance, chan_id, local_shm, remote_shm, cfg);
		}
	}

	return err;
}

/**
 * unmanaged_channel_init() - initialize unmanaged channel
 *
 * @instance:   instance id
 * @chan_id:    channel id
 * @local_shm:  local shared memory
 * @remote_shm: remote shared memort
 * @cfg:        unmanaged channel configuration
 *
 * Return: IPC_SHM_E_OK for success, error code otherwise
 */
static sint8 unmanaged_channel_init(const uint8 instance, uint8 chan_id,
		uintptr local_shm, uintptr remote_shm,
		const struct ipc_shm_unmanaged_cfg *cfg)
{
	struct ipc_unmanaged_channel *chan
		= &ipc_shm_priv_data[instance].channels[chan_id].ch.umng;
	sint8 err = -IPC_SHM_E_INVAL;

	if (cfg->size <= IPC_SHM_MAX_UMNG_SIZE) {
		/* save unmanaged channel parameters */
		chan->size = cfg->size;
		chan->rx_cb = cfg->rx_cb;
		chan->cb_arg = cfg->cb_arg;

		chan->local_mem = (struct ipc_channel_umem *) local_shm;
		chan->remote_mem = (struct ipc_channel_umem *) remote_shm;

		/* Check if remote unmanaged channel initialization is in progress */
		if (chan->remote_mem->sentinel == (uint32)IPC_SHM_UCHAN_INIT_IN_PROGRESS) {
			err = -IPC_SHM_E_REMOTE_INIT_IN_PROGRESS;
		} else {
			/* Mark that the queue initialization is in progress */
			chan->local_mem->sentinel = (uint32)IPC_SHM_UCHAN_INIT_IN_PROGRESS;
			/* Check if remote initialization is in progress */
			if (chan->remote_mem->sentinel == (uint32)IPC_UCHAN_INIT_DONE) {
				/* Use values from remote if it is already initialized */
				chan->local_mem->tx_count = chan->remote_mem->remote_tx_count;
				chan->local_mem->remote_tx_count = chan->remote_mem->tx_count;
			} else {
				chan->local_mem->tx_count = 0;
				chan->local_mem->remote_tx_count = 0;
			}

			/* Mark queue as initialized */
			chan->local_mem->sentinel = (uint32)IPC_UCHAN_INIT_DONE;
			err = IPC_SHM_E_OK;
		}
	}

	return err;
}

/**
 * ipc_shm_init_a_channel() - initialize a shared memory IPC channel
 * @instance:   instance id
 * @chan_id:    channel index
 * @local_shm:  local channel shared memory address
 * @remote_shm: remote channel shared memory address
 * @cfg:        channel configuration parameters
 *
 * Return: 0 for success, error code otherwise
 */
static sint8 ipc_shm_init_a_channel(const uint8 instance, uint8 chan_id,
		uintptr local_shm, uintptr remote_shm,
		const struct ipc_shm_channel_cfg *cfg)
{
	struct ipc_shm_channel *chan =
			&ipc_shm_priv_data[instance].channels[chan_id];
	sint8 err = -IPC_SHM_E_INVAL;

	/* save common channel parameters */
	chan->id = chan_id;
	chan->type = cfg->type;

	if (cfg->type == IPC_SHM_MANAGED) {
		if ((cfg->ch.managed.rx_cb == NULL)
			|| (cfg->ch.managed.pools == NULL)) {
			err = -IPC_SHM_E_INVAL;
		} else {
			err = managed_channel_init(instance, chan_id, local_shm,
					remote_shm, &cfg->ch.managed);
		}
	} else if (cfg->type == IPC_SHM_UNMANAGED) {
		if (cfg->ch.unmanaged.rx_cb == NULL) {
			err = -IPC_SHM_E_INVAL;
		} else {
			err = unmanaged_channel_init(instance, chan_id, local_shm,
					remote_shm, &cfg->ch.unmanaged);
		}
	} else {
		err = -IPC_SHM_E_INVAL;
	}

	return err;
}

/**
 * ipc_shm_free_managed_channel() - Free the specified managed channel
 *
 * @instance:  instance id
 * @chan_id:   channel id
 * @chan_type: channel type
 *
 */
static void ipc_shm_free_managed_channel(struct ipc_managed_channel *mchan)
{
	uint16 pool_id = 0;

	if ((mchan->bd_queue.push_ring->sentinel
		== IPC_QUEUE_INIT_DONE)
			|| (mchan->bd_queue.push_ring->sentinel
			== IPC_QUEUE_INIT_IN_PROGRESS)) {
		/* Free channel queue */
		ipc_queue_free(&mchan->bd_queue);
		/* Free the queues from all pools */
		for (pool_id = 0; pool_id < mchan->num_pools; pool_id++) {
			if (mchan->pools[pool_id].bd_queue.push_ring == NULL)
				continue;
			if ((mchan->pools[pool_id].bd_queue.push_ring->sentinel
				== IPC_QUEUE_INIT_DONE)
					|| (mchan->pools[pool_id].bd_queue.push_ring->sentinel
					== IPC_QUEUE_INIT_IN_PROGRESS)) {
				ipc_queue_free(&mchan->pools[pool_id].bd_queue);
			}
		}
	}
}

/**
 * ipc_shm_free_channel() - Free the specified channel from the specified instance
 *
 * @instance:  instance id
 * @chan_id:   channel id
 * @chan_type: channel type
 *
 */
static void ipc_shm_free_channel(const uint8 instance, uint8 chan_id,
								enum ipc_shm_channel_type chan_type)
{
	struct ipc_unmanaged_channel *uchan = NULL;
	struct ipc_managed_channel *mchan = NULL;

	if (chan_type == IPC_SHM_MANAGED) {
		mchan = &ipc_shm_priv_data[instance].channels[chan_id].ch.mng;

		if (mchan->bd_queue.push_ring != NULL) {
			/* Free all managed channel queue */
			ipc_shm_free_managed_channel(mchan);
		}
	} else if (chan_type == IPC_SHM_UNMANAGED) {
		uchan = &ipc_shm_priv_data[instance].channels[chan_id].ch.umng;
		if (uchan->local_mem != NULL) {
			uchan->local_mem->sentinel = 0;
			uchan->local_mem->tx_count = 0;
			uchan->local_mem->remote_tx_count = 0;
		}
	} else {
	}
}

/**
 * get_chan_memmap_size() - Get channel local mapped memory size
 *
 * @instance: instance id
 * @chan_id:  channel id
 *
 * Return: Channel memory size
 */
static uint32 get_chan_memmap_size(const uint8 instance, uint8 chan_id)
{
	struct ipc_shm_channel *chan =
			&ipc_shm_priv_data[instance].channels[chan_id];
	struct ipc_managed_channel *mchan;
	uint32 mapped_mem_size = 0u;
	uint8 pool_id = 0u;

	/* unmanaged channels: control structure size + channel memory size */
	if (chan->type == IPC_SHM_UNMANAGED) {
		mapped_mem_size = (uint32)(sizeof(struct ipc_channel_umem) +
			chan->ch.umng.size);
	} else {
		/* managed channels: size of BD queue + size of buf pools */
		mchan = &chan->ch.mng;
		mapped_mem_size = ipc_queue_mem_size(&mchan->bd_queue);
		for (pool_id = 0; pool_id < mchan->num_pools; pool_id++) {
			mapped_mem_size += mchan->pools[pool_id].shm_size;
		}
	}

	return mapped_mem_size;
}

/**
 * ipc_shm_init_channels() - initialize all shared memory IPC channel
 *
 * @instance: instance id
 * @cfg:      ipc-shm instance configuration
 *
 * Return: 0 for success, error code otherwise
 */
static sint8 ipc_shm_init_channels(uint8 instance,
	const struct ipc_shm_cfg *cfg)
{
	uintptr local_shm = ipc_os_get_local_shm(instance);
	uintptr local_chan_shm;
	uintptr remote_chan_shm;
	uint32 chan_offset = (uint32)sizeof(struct ipc_shm_global);
	uint32 chan_size;
	uint8 chan_id = 0;
	sint8 err = -IPC_SHM_E_INVAL;

	/* global data stored at
	 * beginning of local shared memory
	 */
	ipc_shm_priv_data[instance].global = (struct ipc_shm_global *)local_shm;
	ipc_shm_priv_data[instance].global->state = IPC_SHM_STATE_CLEAR;

	/* init channels */
	local_chan_shm = local_shm + (uintptr)chan_offset;
	remote_chan_shm = ipc_os_get_remote_shm(instance) + (uintptr)chan_offset;
	for (chan_id = 0; chan_id < ipc_shm_priv_data[instance].num_channels; chan_id++) {
		if (cfg->channels != NULL) {
			err = ipc_shm_init_a_channel(instance, chan_id, local_chan_shm,
					remote_chan_shm, &cfg->channels[chan_id]);
			if (err == IPC_SHM_E_OK) {
				/* compute next channel local
				 * remote shm base address
				 */
				chan_size = get_chan_memmap_size(instance, chan_id);
				local_chan_shm += chan_size;
				remote_chan_shm += chan_size;
			} else {
				break;
			}
		}
	}

	return err;
}

/**
 * ipc_shm_init_instance_priv - initialize hw, os and channels of the
 *                              specific instance
 *
 * @instance: instance id
 * @cfg:      ipc-shm instance configuration
 *
 * Return IPC_SHM_E_OK on success, error code otherwise
 */
static sint8 ipc_shm_init_instance_priv(uint8 instance, const struct ipc_shm_cfg *cfg)
{
	sint8 err = 0;

	/* save api params */
	ipc_shm_priv_data[instance].shm_size = cfg->shm_size;
	ipc_shm_priv_data[instance].num_channels = cfg->num_channels;

	/* pass interrupt and core data to hw */
	err = ipc_hw_init(instance, cfg);
	if (err == IPC_SHM_E_OK) {
		/* init OS specific resources */
		err = ipc_os_init(instance, cfg, &ipc_shm_rx);
		if (err != IPC_SHM_E_OK) {
			ipc_hw_free(instance);
		} else {
			err = ipc_shm_init_channels(instance, cfg);
			if (err != IPC_SHM_E_OK) {
				ipc_os_free(instance);
				ipc_hw_free(instance);
			}
		}
	}

	return err;
}

sint8 ipc_shm_init_instance(uint8 instance, const struct ipc_shm_cfg *cfg)
{
	sint8 err = -IPC_SHM_E_INVAL;
	uint8 chan_id = 0;

	if ((ipc_instance_is_free(instance) != IPC_SHM_INSTANCE_USED)
			&& (cfg != NULL)
			&& (cfg->local_shm_addr != (uintptr)NULL)
			&& (cfg->remote_shm_addr != (uintptr)NULL)
			&& (cfg->num_channels > 0u)
			&& (cfg->num_channels <= IPC_SHM_MAX_CHANNELS)) {
		err = ipc_shm_init_instance_priv(instance, cfg);
		if (err != IPC_SHM_E_OK) {
			/* Free all channels from the specified instance in case of error */
			for (chan_id = 0;
					chan_id < ipc_shm_priv_data[instance].num_channels;
					chan_id++) {
				if (cfg->channels != NULL)
					ipc_shm_free_channel(instance, chan_id, cfg->channels[chan_id].type);
			}
		} else {
			/* clear interrupt flags */
			ipc_hw_irq_clear(instance);
			/* enable interrupt notifications */
			ipc_hw_irq_enable(instance);
			/* Set magic word */
			ipc_shm_priv_data[instance].global->state = (uint64)IPC_SHM_STATE_READY;
			/* flush and invalidate local dcache */
			ipc_hw_flush_cache_local(instance);
		}
	}

	return err;
}

void ipc_shm_free_instance(const uint8 instance)
{
	uint8 chan_id = 0;

	if (ipc_instance_is_free(instance) == IPC_SHM_INSTANCE_USED) {
		/* reset state */
		ipc_shm_priv_data[instance].global->state = IPC_SHM_STATE_CLEAR;
		ipc_shm_priv_data[instance].global = NULL;

		/* Free all channels from the specified instance */
		for (chan_id = 0;
				chan_id < ipc_shm_priv_data[instance].num_channels;
				chan_id++) {
			ipc_shm_free_channel(instance, chan_id,
					ipc_shm_priv_data[instance].channels[chan_id].type);
		}

		/* flush and invalidate local dcache */
		ipc_hw_flush_cache_local(instance);

		/* disable hardirq */
		ipc_hw_irq_disable(instance);

		/* Free OS and HW for the specified instance */
		ipc_os_free(instance);
		ipc_hw_free(instance);
	}
}

void ipc_shm_free(void)
{
	uint8 instance_id = 0;

	/* Free all instances */
	for (instance_id = 0; instance_id < IPC_SHM_MAX_INSTANCES; instance_id++) {
		ipc_shm_free_instance(instance_id);
	}
}

/**
 * ipc_shm_acquire_buf_from_pool() - Get buffer from a channel
 * @instance:       instance id
 * @chan_id:        channel index
 * @chan:           managed channel configuration
 *
 * Return address of the buffer or NULL if buffer is not found or invalid
 */
static uintptr ipc_shm_acquire_buf_from_pool(const uint8 instance, uint32 mem_size,
						struct ipc_managed_channel *chan)
{
	struct ipc_shm_pool *pool = NULL;
	uintptr buf_addr = (uintptr)NULL;
	struct ipc_shm_bd bd = {.pool_id = 0u, .buf_id = 0u, .data_size = 0u};
	uint16 pool_id;

	/* find first non-empty pool that accommodates the requested size */
	for (pool_id = 0; pool_id < chan->num_pools; pool_id++) {
		pool = &chan->pools[pool_id];

		/* check if pool buf size covers the requested size */
		if (mem_size > pool->buf_size)
			continue;

		/* check if pool has any free buffers left */
		if (ipc_queue_pop(&pool->bd_queue, &bd) == 0)
			break;
	}

	if (pool_id == chan->num_pools) {
		buf_addr = (uintptr)NULL;
	} else {
		buf_addr = pool->local_pool_addr +
			(uint32)(bd.buf_id * pool->buf_size);

		/* check if buf_addr is valid */
		if ((buf_addr < ipc_os_get_local_shm(instance)) ||
			((buf_addr + pool->buf_size) > (ipc_os_get_local_shm(instance) +
			ipc_shm_priv_data[instance].shm_size))) {
			buf_addr = (uintptr)NULL;
		}
	}

	return buf_addr;
}

void *ipc_shm_acquire_buf(const uint8 instance, uint8 chan_id, uint32 mem_size)
{
	struct ipc_managed_channel *chan;
	uintptr buf_addr = (uintptr)NULL;

	/* check if instance is valid and remote is ready */
	if (ipc_shm_is_remote_ready(instance) == IPC_SHM_E_OK) {

		chan = get_managed_chan(instance, chan_id);

		if ((chan == NULL) || (mem_size == 0u)
				|| (IPC_SHM_E_OK != ipc_check_mchan_integrity(chan))) {
			buf_addr = (uintptr)NULL;
		} else {
			buf_addr = ipc_shm_acquire_buf_from_pool(instance, mem_size, chan);
		}
	}

	return (void *)buf_addr;
}

sint8 ipc_shm_init(const struct ipc_shm_instances_cfg *cfg)
{
	uint8 instance_id = 0;
	sint8 err = -IPC_SHM_E_INVAL;

	if (cfg != NULL) {
		if ((cfg->num_instances > IPC_SHM_MAX_INSTANCES)
				|| (cfg->num_instances == 0u)) {
			err = -IPC_SHM_E_INVAL;
		} else {
			/* init all instances */
			for (instance_id = 0; instance_id < cfg->num_instances; instance_id++) {
				if (ipc_instance_is_free(instance_id) == IPC_SHM_INSTANCE_USED) {
					continue;
				}
				err = ipc_shm_init_instance(instance_id, &cfg->shm_cfg[instance_id]);
				if (err != IPC_SHM_E_OK) {
					break;
				}
			}
		}
	}

	return err;
}

/**
 * find_pool_for_buf() - Find the pool that owns the specified buffer.
 * @chan:    managed channel pointer
 * @buf:     buffer pointer
 * @remote:  flag telling if buffer is from remote OS
 * @pool_index: pool index on success
 *
 * Return IPC_SHM_E_OK on success, error code otherwise
 */
static sint8 find_pool_for_buf(struct ipc_managed_channel *chan,
		uintptr buf, uint8 remote, uint16 *pool_index)
{
	struct ipc_shm_pool *pool;
	uintptr addr;
	uint32 pool_size;
	uint16 pool_id;
	sint8 err = -IPC_SHM_E_INVAL;

	for (pool_id = 0U; pool_id < chan->num_pools; pool_id++) {
		pool = &chan->pools[pool_id];

		if (remote == IPC_BUFFER_FROM_REMOTE) {
			addr = pool->remote_pool_addr;
		} else {
			addr = pool->local_pool_addr;
		}

		pool_size = pool->num_bufs * pool->buf_size;

		if ((buf >= addr) && (buf < (addr + pool_size))) {
			*pool_index = pool_id;
			err = IPC_SHM_E_OK;
			break;
		}
	}

	return err;
}

sint8 ipc_shm_release_buf(const uint8 instance, uint8 chan_id, const void *buf)
{
	struct ipc_managed_channel *chan;
	struct ipc_shm_pool *pool;
	struct ipc_shm_bd bd;
	sint8 err = -IPC_SHM_E_INVAL;

	/* check if instance is valid */
	if (ipc_shm_is_remote_ready(instance) == IPC_SHM_E_OK) {
		chan = get_managed_chan(instance, chan_id);
		if ((chan != NULL) && (buf != NULL)) {

			err = ipc_check_mchan_integrity(chan);
			if (IPC_SHM_E_OK == err) {
				/* Find the pool that owns the buffer */
				err = find_pool_for_buf(chan, (uintptr)buf,
							IPC_BUFFER_FROM_REMOTE, &bd.pool_id);

				if (IPC_SHM_E_OK == err) {
					pool = &chan->pools[bd.pool_id];
					bd.buf_id = (uint16)(((uintptr)buf
							- pool->remote_pool_addr) /	pool->buf_size);
					bd.data_size = 0; /* reset size of written data in buffer */

					err = ipc_queue_push(&pool->bd_queue, &bd);

					/* flush and invalidate local dcache */
					ipc_hw_flush_cache_local(instance);
				}
			}
		}
	}

	return err;
}

/**
 * ipc_shm_buf_tx() - find buffer in a pool and notify remote
 * @instance:       instance id
 * @buf:            buffer pointer
 * @size:           size of data written in buffer
 * @chan:           managed channel private data
 *
 * Return: 0 on success, error code otherwise
 */
static sint8 ipc_shm_buf_tx(const uint8 instance, void *buf, uint32 size,
				struct ipc_managed_channel *chan)
{
	struct ipc_shm_pool *pool;
	struct ipc_shm_bd bd;
	sint8 err = ipc_check_mchan_integrity(chan);

	if (IPC_SHM_E_OK == err) {
		/* Find the pool that owns the buffer */
		err = find_pool_for_buf(chan, (uintptr)buf,
					IPC_BUFFER_FROM_LOCAL, &bd.pool_id);

		if (IPC_SHM_E_OK == err) {
			pool = &chan->pools[bd.pool_id];
			bd.buf_id = (uint16)(((uintptr)buf
					- pool->local_pool_addr) / pool->buf_size);
			bd.data_size = size;

			/* push buffer descriptor in queue */
			err = ipc_queue_push(&chan->bd_queue, &bd);
			if (IPC_SHM_E_OK == err) {
				/* flush and invalidate local dcache */
				ipc_hw_flush_cache_local(instance);

				/* notify remote that data is available */
				ipc_hw_irq_notify(instance);
			}
		}
	}

	return err;
}

sint8 ipc_shm_tx(const uint8 instance, uint8 chan_id, void *buf, uint32 size)
{
	struct ipc_managed_channel *chan;
	sint8 err = -IPC_SHM_E_INVAL;

	/* check if instance is used */
	if (ipc_shm_is_remote_ready(instance) == IPC_SHM_E_OK) {

		chan = get_managed_chan(instance, chan_id);

		if ((chan != NULL) && (buf != NULL) && (size != 0u)) {
			err = ipc_shm_buf_tx(instance, buf, size, chan);
		}
	}

	return err;
}

void *ipc_shm_unmanaged_acquire(const uint8 instance, uint8 chan_id)
{
	struct ipc_unmanaged_channel *chan = NULL;
	uint8 *umng_mem = NULL;

	/* check if instance is used */
	if (ipc_instance_is_free(instance) == IPC_SHM_INSTANCE_USED) {

		chan = get_unmanaged_chan(instance, chan_id);
		if (chan != NULL) {
			if (IPC_SHM_E_OK == ipc_check_uchan_local_integrity(chan)) {
				umng_mem = chan->local_mem->mem;
			}
		}
	}

	/* for unmanaged channels return entire channel memory */
	return (void *)umng_mem;
}

sint8 ipc_shm_unmanaged_tx(const uint8 instance, uint8 chan_id)
{
	struct ipc_unmanaged_channel *chan = NULL;
	sint8 err = -IPC_SHM_E_INVAL;

	/* check if instance is valid */
	if (ipc_shm_is_remote_ready(instance) == IPC_SHM_E_OK) {
		chan = get_unmanaged_chan(instance, chan_id);
		if (chan != NULL) {

			err = ipc_check_uchan_integrity(chan);
			if (IPC_SHM_E_OK == err) {
				chan->local_mem->tx_count++;

				/* flush and invalidate dcache */
				ipc_hw_flush_cache_local(instance);

				ipc_hw_irq_notify(instance);
			}
		}
	}

	return err;
}

sint8 ipc_shm_is_remote_ready(const uint8 instance)
{
	struct ipc_shm_global *remote_global;
	sint8 err = -IPC_SHM_E_INVAL;

	/* check if instance is used */
	if (ipc_instance_is_free(instance) == IPC_SHM_INSTANCE_USED) {
		/* flush and invalidate remote dcache */
		ipc_hw_flush_cache_remote(instance);

		/* global data of remote at beginning of remote shared memory */
		remote_global = (struct ipc_shm_global *)ipc_os_get_remote_shm(
				instance);

		if (remote_global->state != (uint64)IPC_SHM_STATE_READY) {
			err = -IPC_SHM_E_NOT_READY;
		} else {
			err = IPC_SHM_E_OK;
		}
	}

	return err;
}

sint8 ipc_shm_poll_channels(const uint8 instance)
{
	struct ipc_shm_global *remote_global;
	enum ipc_shm_instance_state result = ipc_instance_is_free(instance);
	sint8 err = IPC_SHM_E_OK;

	/* check if instance is used */
	if (result == IPC_SHM_INSTANCE_USED) {
		/* flush and invalidate remote dcache */
		ipc_hw_flush_cache_remote(instance);

		/* global data of remote at beginning of remote shared memory */
		remote_global = (struct ipc_shm_global *)ipc_os_get_remote_shm(instance);

		/* check if remote is ready before polling */
		if (remote_global->state != (uint64)IPC_SHM_STATE_READY) {
			err = -IPC_SHM_E_NOT_READY;
		} else {
			err = ipc_os_poll_channels(instance);
		}
	} else {
		if (result == IPC_SHM_INSTANCE_FREE) {
			err = -IPC_SHM_E_NOT_READY;
		} else {
			err = -IPC_SHM_E_INVAL;
		}
	}

	return err;
}

#if defined(__cplusplus)
}
#endif
