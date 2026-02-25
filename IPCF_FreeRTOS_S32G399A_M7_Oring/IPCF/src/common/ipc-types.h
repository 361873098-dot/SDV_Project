/**
 * IPC Shared Memory Driver - IPC types implementation
 *
 * Copyright 2023-2024 NXP
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
#ifndef IPC_TYPES_H
#define IPC_TYPES_H

#if defined(__cplusplus)
extern "C"{
#endif

#include "ipcf_Ip_Cfg_Defines.h"

#ifndef IPCF_TYPES
	#include "Mcal.h"
#else
	#include <stdint.h>
	#include <stdbool.h>
	#include <stddef.h>
#endif

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_TYPES_VENDOR_ID                           43
#define IPC_TYPES_MODULE_ID                           255
#define IPC_TYPES_AR_RELEASE_MAJOR_VERSION            4
#define IPC_TYPES_AR_RELEASE_MINOR_VERSION            4
#define IPC_TYPES_AR_RELEASE_REVISION_VERSION         0
#define IPC_TYPES_SW_MAJOR_VERSION                    4
#define IPC_TYPES_SW_MINOR_VERSION                    10
#define IPC_TYPES_SW_PATCH_VERSION                    0

/*
 * FILE VERSION CHECKS
 */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((IPC_TYPES_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
		(IPC_TYPES_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
	)
	#error "AutoSar Version Numbers of ipc-types.h and Mcal.h are different"
#endif
#endif

/*
 * Check if ipc-types.h file and ipcf_Ip_Cfg_Defines.h configuration header file
 * are of the same vendor
 */
#if (IPC_TYPES_VENDOR_ID != IPCF_IP_CFG_DEFINES_VENDOR_ID)
	#error "ipc-types.h and ipcf_Ip_Cfg_Defines.h have different vendor IDs"
#endif
/*
 * Check if ipc-types.h file and ipcf_Ip_Cfg_Defines.h configuration header file
 * are of the same Autosar version
 */
#if ((IPC_TYPES_AR_RELEASE_MAJOR_VERSION != IPCF_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_TYPES_AR_RELEASE_MINOR_VERSION != IPCF_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
	(IPC_TYPES_AR_RELEASE_REVISION_VERSION != IPCF_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-types.h and ipcf_Ip_Cfg_Defines.h are different"
#endif
/*
 * Check if ipc-types.h file and ipcf_Ip_Cfg_Defines.h configuration header file
 * are of the same software version
 */
#if ((IPC_TYPES_SW_MAJOR_VERSION != IPCF_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
	(IPC_TYPES_SW_MINOR_VERSION != IPCF_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
	(IPC_TYPES_SW_PATCH_VERSION != IPCF_IP_CFG_DEFINES_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-types.h and ipcf_Ip_Cfg_Defines.h are different"
#endif

#if defined(IPCF_TYPES)
	/**
	 * @brief          8bit Type Processor
	 * @implements     CPU_TYPE_enum
	 */
	#define CPU_TYPE_8 8

	/**
	 * @brief          16bit Type Processor
	 * @implements     CPU_TYPE_enum
	 */
	#define CPU_TYPE_16 16

	/**
	 * @brief          32bit Type Processor
	 * @implements     CPU_TYPE_enum
	 */
	#define CPU_TYPE_32 32

	/**
	 * @brief          64bit Type Processor
	 * @implements     CPU_TYPE_enum
	 */
	#define CPU_TYPE_64 64
	/**
	 * @brief: The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long
	 *        unsigned integer.
	 * @implements boolean_type
	 */
	typedef bool boolean;


	/**
	 * @brief: Unsigned 8 bit integer with range of
	 *         0 ..+255 (0x00..0xFF) - 8 bit
	 * @implements uint8_type
	 */
	typedef uint8_t uint8;

	/**
	 * @brief: Unsigned 16 bit integer with range of
	 *         0 ..+65535 (0x0000..0xFFFF) - 16 bit
	 * @implements uint16_type
	 */
	typedef uint16_t uint16;

	/**
	 * @brief: Unsigned 32 bit integer with range of
	 *         0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
	 *        32 bit
	 * @implements uint32_type
	 */
	typedef uint32_t uint32;

	/**
	 * @brief: Unsigned 64 bit integer with range of
	 *         0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF) - 64 bit
	 */
	typedef uint64_t uint64;


	/**
	 * @brief: Signed 8 bit integer with range of
	 *         -128 ..+127 (0x80..0x7F) - 7 bit + 1 sign bit
	 * @implements sint8_type
	 */
	typedef int8_t sint8;

	/**
	 * @brief: Signed 16 bit integer with range of
	 *         -32768 ..+32767 (0x8000..0x7FFF) -
	 *        15 bit + 1 sign bit
	 * @implements sint16_type
	 */
	typedef int16_t sint16;

	/**
	 * @brief: Signed 32 bit integer with range of
	 *         -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 31 bit + 1 sign bit
	 * @implements sint32_type
	 */
	typedef int32_t sint32;

	/**
	 * @brief: Signed 64 bit integer with range of
	 *         -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )
	 *         63 bit + 1 sign bit
	 */
	typedef int64_t sint64;

	/**
	 * @brief: Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 8 bit
	 * @implements uint8_least_type
	 */
	typedef uint_least8_t uint8_least;

	/**
	 * @brief:  Unsigned integer at least 16 bit long.
	 *          Range of at least 0 ..+65535 (0x0000..0xFFFF) - 16 bit
	 * @implements uint16_least_type
	 */
	typedef uint_least16_t uint16_least;

	/**
	 * @brief: Unsigned integer at least 32 bit long.
	 *         Range of at least 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 32 bit
	 * @implements uint32_least_type
	 */
	typedef uint_least32_t uint32_least;

	/**
	 * @brief: Signed integer at least 8 bit long. Range - at least -128 ..+127.
	 *        At least 7 bit + 1 bit sign
	 * @implements sint8_least_type
	 */
	typedef int_least8_t sint8_least;

	/*
	 * @brief: Signed integer at least 16 bit long. Range - at least -32768 ..+32767.
	 *         At least 15 bit + 1 bit sign
	 * @implements sint16_least_type
	 */
	typedef int_least16_t sint16_least;

	/*
	 * @brief: Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647.
	 *         At least 31 bit + 1 bit sign
	 * @implements sint32_least_type
	 */
	typedef int_least32_t sint32_least;

	/*
	 * @brief: 32bit long floating point data type
	 * @implements float32_type
	 */
	typedef float float32;

	/*
	 * @brief: 64bit long floating point data type
	 * @implements float64_type
	 */
	typedef double float64;
#endif /* IPCF_TYPES */

#if (CPU_TYPE == CPU_TYPE_64)
	typedef uint64 uintptr;
#elif (CPU_TYPE == CPU_TYPE_32)
	typedef uint32 uintptr;
#else
	#error "Unsupported CPU_TYPE"
#endif

#if !defined(NULL)
	#define NULL ((void *)0)
#endif

/* Maximum value of standard type */
#define IPC_UINT16_MAX                  (0xFFFFu)

/* Maximum number of total buffers per channel */
#define IPC_SHM_MAX_BUFS_PER_CHANNEL    (IPC_UINT16_MAX - 1u)

/* Maximum unmanaged channel size */
#define IPC_SHM_MAX_UMNG_SIZE           (IPC_UINT16_MAX)

/*
 * Various error codes that this IPC driver uses for generating errors.
 */
/* No error, successful operation. */
#define	IPC_SHM_E_OK                         0

/* The value specified the operation is not ready. */
#define	IPC_SHM_E_NOT_READY                  1

/* There is not enough memory space to allocate. */
#define	IPC_SHM_E_NOMEM                      2

/* The value specified for the argument is not correct. */
#define	IPC_SHM_E_INVAL                      3

/* There is not enough buffer space for the requested operation. */
#define IPC_SHM_E_NO_QUEUE                   4

/* The operation, though supported in general, is not supported. */
#define IPC_SHM_E_NOTSUP                     5

/* A buffer descriptor was corrupt, channel integrity was compromised */
#define IPC_SHM_E_INTEGRITY                  6

/* Indicate that channel is initializing */
#define IPC_SHM_E_REMOTE_INIT_IN_PROGRESS    7

/* magic number to indicate the queue is initializing */
#define IPC_QUEUE_INIT_IN_PROGRESS           0x54494E4946435049ULL

/* magic number to indicate the queue integrity */
#define IPC_QUEUE_INIT_DONE                  0x474E495246435049ULL

/*
 * Used when using MRU driver
 */
#define IPC_IRQ_MRU -2

/*
 * Used when polling is desired on either transmit or receive path
 */
#define IPC_IRQ_NONE -1

/*
 * Maximum number of shared memory channels that can be configured
 */
#ifndef IPC_SHM_MAX_CHANNELS
#define IPC_SHM_MAX_CHANNELS 8U
#endif

/*
 * Maximum number of buffer pools that can be configured for a managed channel
 */
#ifndef IPC_SHM_MAX_POOLS
#define IPC_SHM_MAX_POOLS 4U
#endif

/*
 * Maximum number of buffers per pool
 */
#ifndef IPC_SHM_MAX_BUFS_PER_POOL
#define IPC_SHM_MAX_BUFS_PER_POOL 4096U
#endif

/*
 * Maximum number of instances
 */
#ifndef IPC_SHM_MAX_INSTANCES
#define IPC_SHM_MAX_INSTANCES	4u
#endif

/*
 * Used for boolean false value
 */
#ifndef FALSE
#define FALSE        (0U)
#endif

/*
 * Used for boolean true value
 */
#ifndef TRUE
#define TRUE        (1U)
#endif

/**
 * enum ipc_shm_channel_type - channel type
 * @IPC_SHM_MANAGED:     channel with buffer management enabled
 * @IPC_SHM_UNMANAGED:   buf mgmt disabled, app owns entire channel memory
 *
 * For unmanaged channels the application has full control over channel memory
 * and no buffer management is done by ipc-shm device.
 */
enum ipc_shm_channel_type {
	IPC_SHM_MANAGED,
	IPC_SHM_UNMANAGED
};

/**
 * enum ipc_shm_queue_type -  queue type
 * @IPC_SHM_CHANNEL_QUEUE:    Channel queue
 * @IPC_SHM_POOL_QUEUE:       Pool buffer queue
 *
 */
enum ipc_shm_queue_type {
	IPC_SHM_CHANNEL_QUEUE = 0,
	IPC_SHM_POOL_QUEUE = 1,
};

/**
 * enum ipc_shm_core_type - core type
 * @IPC_CORE_A53:       ARM Cortex-A53 core
 * @IPC_CORE_M7:        ARM Cortex-M7 core
 * @IPC_CORE_M4:        ARM Cortex-M4 core
 * @IPC_CORE_Z7:        PowerPC e200z7 core
 * @IPC_CORE_Z4:        PowerPC e200z4 core
 * @IPC_CORE_Z2:        PowerPC e200z2 core
 * @IPC_CORE_R52:       ARM Cortex-R52 core
 * @IPC_CORE_M33:       ARM Cortex-M33 core
 * @IPC_CORE_BBE32:     Tensilica ConnX BBE32EP core
 * @IPC_CORE_DEFAULT:   used for letting driver auto-select remote core type
 */
enum ipc_shm_core_type {
	IPC_CORE_DEFAULT,
	IPC_CORE_A53,
	IPC_CORE_M7,
	IPC_CORE_M4,
	IPC_CORE_Z7,
	IPC_CORE_Z4,
	IPC_CORE_Z2,
	IPC_CORE_R52,
	IPC_CORE_M33,
	IPC_CORE_BBE32,
};

/**
 * enum ipc_shm_core_index - core index
 * @IPC_CORE_INDEX_0:   Processor index 0
 * @IPC_CORE_INDEX_1:   Processor index 1
 * @IPC_CORE_INDEX_2:   Processor index 2
 * @IPC_CORE_INDEX_3:   Processor index 3
 * @IPC_CORE_INDEX_4:   Processor index 4
 * @IPC_CORE_INDEX_5:   Processor index 5
 * @IPC_CORE_INDEX_6:   Processor index 6
 * @IPC_CORE_INDEX_7:   Processor index 7
 */
enum ipc_shm_core_index {
	IPC_CORE_INDEX_0 = 0x01u,
	IPC_CORE_INDEX_1 = 0x02u,
	IPC_CORE_INDEX_2 = 0x04u,
	IPC_CORE_INDEX_3 = 0x08u,
	IPC_CORE_INDEX_4 = 0x10u,
	IPC_CORE_INDEX_5 = 0x20u,
	IPC_CORE_INDEX_6 = 0x40u,
	IPC_CORE_INDEX_7 = 0x80u,
};

/**
 * struct ipc_shm_pool_cfg - memory buffer pool parameters
 * @num_bufs:   number of buffers
 * @buf_size:   buffer size
 */
struct ipc_shm_pool_cfg {
	uint16 num_bufs;
	uint32 buf_size;
};

/**
 * struct ipc_shm_managed_cfg - managed channel parameters
 * @num_pools:   number of buffer pools
 * @pools:       memory buffer pools parameters
 * @rx_cb:       receive callback
 * @cb_arg:      optional receive callback argument
 */
struct ipc_shm_managed_cfg {
	uint8 num_pools;
	struct ipc_shm_pool_cfg *pools;
	void (*rx_cb)(void *cb_arg, const uint8 instance, uint8 chan_id,
			void *buf, uint32 size);
	void *cb_arg;
};

/**
 * struct ipc_shm_unmanaged_cfg - unmanaged channel parameters
 * @size:     unmanaged channel memory size
 * @rx_cb:    receive callback
 * @cb_arg:   optional receive callback argument
 */
struct ipc_shm_unmanaged_cfg {
	uint32 size;
	void (*rx_cb)(void *cb_arg, const uint8 instance, uint8 chan_id,
			void *mem);
	void *cb_arg;
};

/**
 * struct ipc_shm_channel_cfg - channel parameters
 * @type:	channel type from &enum ipc_shm_channel_type
 * @ch.managed:     managed channel parameters
 * @ch.unmanaged:   unmanaged channel parameters
 */
struct ipc_shm_channel_cfg {
	enum ipc_shm_channel_type type;
	union {
		struct ipc_shm_managed_cfg managed;
		struct ipc_shm_unmanaged_cfg unmanaged;
	} ch;
};

/**
 * struct ipc_shm_remote_core - remote core type and index
 * @type:    core type from &enum ipc_shm_core_type
 * @index:   core number
 *
 * Core type can be IPC_CORE_DEFAULT, in which case core index doesn't matter
 * because it's chosen automatically by the driver.
 */
struct ipc_shm_remote_core {
	enum ipc_shm_core_type type;
	enum ipc_shm_core_index index;
};

/**
 * struct ipc_shm_local_core - local core type, index and trusted cores
 * @type:      core type from &enum ipc_shm_core_type
 * @index:     core number targeted by remote core interrupt
 * @trusted:   trusted cores mask
 *
 * Core type can be IPC_CORE_DEFAULT, in which case core index doesn't matter
 * because it's chosen automatically by the driver.
 *
 * Trusted cores mask specifies which cores (of the same core type) have access
 * to the inter-core interrupt status register of the targeted core. The mask
 * can be formed from &enum ipc_shm_core_index.
 */
struct ipc_shm_local_core {
	enum ipc_shm_core_type type;
	enum ipc_shm_core_index index;
	uint32 trusted;
};

/**
 * struct ipc_shm_cfg - IPC shm parameters
 * @local_shm_addr:      local shared memory physical address
 * @remote_shm_addr:     remote shared memory physical address
 * @shm_size:            local/remote shared memory size
 * @mru_tx_channel_id:   mru channel index for shm driver Tx
 * @mru_rx_channel_id:   mru channel index for shm driver Rx
 * @inter_core_tx_irq:   inter-core interrupt reserved for shm driver Tx
 * @inter_core_rx_irq:   inter-core interrupt reserved for shm driver Rx
 * @local_core:          local core targeted by remote core interrupt
 * @remote_core:         remote core to trigger the interrupt on
 * @num_channels:        number of shared memory channels
 * @channels:            IPC channels parameters array
 * @isr_id_handler:      the name of OsIsr defined to handle the interrupt
 *                       (only if using AutosarOS)
 *
 * The TX and RX interrupts used must be different. For ARM platforms, a default
 * value can be assigned to the local and remote core using IPC_CORE_DEFAULT.
 * Local core is only used for platforms on which Linux may be running on
 * multiple cores, and is ignored for RTOS and baremetal implementations.
 *
 * Local and remote channel and buffer pool configurations must be symmetric.
 */
struct ipc_shm_cfg {
	uintptr local_shm_addr;
	uintptr remote_shm_addr;
	uint32 shm_size;
	sint16 inter_core_tx_irq;
	sint16 inter_core_rx_irq;
	uint8 mru_tx_channel_id;
	uint8 mru_rx_channel_id;
	struct ipc_shm_local_core local_core;
	struct ipc_shm_remote_core remote_core;
	uint8 num_channels;
	struct ipc_shm_channel_cfg *channels;
#ifdef USING_OS_AUTOSAROS
	ISRType isr_id_handler;
#endif
};

/**
 * struct ipc_shm_instances_cfg - IPC shm parameters
 * @num_instances:   number of shared memory instances
 * @shm_cfg:         IPC shm parameters array
 *
 */
struct ipc_shm_instances_cfg {
	uint8 num_instances;
	struct ipc_shm_cfg *shm_cfg;
};

#if defined(__cplusplus)
}
#endif

#endif /* IPC_TYPES_H */
