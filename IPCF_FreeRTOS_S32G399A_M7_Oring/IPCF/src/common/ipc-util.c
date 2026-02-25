/**
 * IPC Shared Memory Driver - Util Functions Implementation
 *
 * Copyright 2023 NXP
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

#ifdef __cplusplus
extern "C"{
#endif

#include "ipc-shm.h"
#include "ipc-util.h"

#define IPC_UTIL_VENDOR_ID_C                         43
#define IPC_UTIL_AR_RELEASE_MAJOR_VERSION_C          4
#define IPC_UTIL_AR_RELEASE_MINOR_VERSION_C          4
#define IPC_UTIL_AR_RELEASE_REVISION_VERSION_C       0
#define IPC_UTIL_SW_MAJOR_VERSION_C                  4
#define IPC_UTIL_SW_MINOR_VERSION_C                  10
#define IPC_UTIL_SW_PATCH_VERSION_C                  0

/* Check if ipc-util.c file and ipc-shm.h file are of the same vendor */
#if (IPC_UTIL_VENDOR_ID_C != IPC_SHM_VENDOR_ID)
	#error "ipc-util.c and ipc-shm.h have different vendor IDs"
#endif
/* Check if ipc-util.c file and ipc-shm.h file are of the same Autosar version */
#if ((IPC_UTIL_AR_RELEASE_MAJOR_VERSION_C != IPC_SHM_AR_RELEASE_MAJOR_VERSION) || \
	(IPC_UTIL_AR_RELEASE_MINOR_VERSION_C != IPC_SHM_AR_RELEASE_MINOR_VERSION) || \
	(IPC_UTIL_AR_RELEASE_REVISION_VERSION_C != IPC_SHM_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version Numbers of ipc-util.c and ipc-shm.h are different"
#endif
/* Check if ipc-util.c file and ipc-shm.h file are of the same software version */
#if ((IPC_UTIL_SW_MAJOR_VERSION_C != IPC_SHM_SW_MAJOR_VERSION) || \
	(IPC_UTIL_SW_MINOR_VERSION_C != IPC_SHM_SW_MINOR_VERSION) || \
	(IPC_UTIL_SW_PATCH_VERSION_C != IPC_SHM_SW_PATCH_VERSION))
	#error "Software Version Numbers of ipc-util.c and ipc-shm.h are different"
#endif

/* Check if ipc-util source file and ipc-util header file are of the same vendor */
#if (IPC_UTIL_VENDOR_ID_C !=  IPC_UTIL_VENDOR_ID)
	#error "ipc-util.c and ipc-util.h have different vendor ids"
#endif

/* Check if ipc-util source file and ipc-util header file are of the same Autosar version */
#if ((IPC_UTIL_AR_RELEASE_MAJOR_VERSION_C    !=  IPC_UTIL_AR_RELEASE_MAJOR_VERSION) || \
	 (IPC_UTIL_AR_RELEASE_MINOR_VERSION_C    !=  IPC_UTIL_AR_RELEASE_MINOR_VERSION) || \
	 (IPC_UTIL_AR_RELEASE_REVISION_VERSION_C !=  IPC_UTIL_AR_RELEASE_REVISION_VERSION) \
	)
	#error "AutoSar Version Numbers of ipc-util.c and ipc-util.h are different"
#endif

/* Check if ipc-util source file and ipc-util header file are of the same Software version */
#if ((IPC_UTIL_SW_MAJOR_VERSION_C !=  IPC_UTIL_SW_MAJOR_VERSION) || \
	 (IPC_UTIL_SW_MINOR_VERSION_C !=  IPC_UTIL_SW_MINOR_VERSION) || \
	 (IPC_UTIL_SW_PATCH_VERSION_C !=  IPC_UTIL_SW_PATCH_VERSION)    \
	)
	#error "Software Version Numbers of ipc-util.c and ipc-util.h are different"
#endif

void ipc_memcpy(void *dst, const void *src, uint32 data_size)
{
	uint8 *tmp_dst = (uint8 *)dst;
	const uint8 *tmp_src = (const uint8 *)src;
	uint32 i = 0u;

	/* Check if the pointers given as arguments are valid */
	if ((NULL != tmp_dst) && (NULL != tmp_src)) {
		/* Copy the value from the source to destination */
		for (i = 0; i < data_size; i++) {
			tmp_dst[i] = tmp_src[i];
		}
	}
}

#ifdef __cplusplus
}
#endif
