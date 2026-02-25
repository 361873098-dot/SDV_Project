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
#ifndef IPC_UTIL_H
#define IPC_UTIL_H

#ifdef __cplusplus
extern "C"{
#endif

/*
 * SOURCE FILE VERSION INFORMATION
 */
#define IPC_UTIL_VENDOR_ID                           43
#define IPC_UTIL_MODULE_ID                           255
#define IPC_UTIL_AR_RELEASE_MAJOR_VERSION            4
#define IPC_UTIL_AR_RELEASE_MINOR_VERSION            4
#define IPC_UTIL_AR_RELEASE_REVISION_VERSION         0
#define IPC_UTIL_SW_MAJOR_VERSION                    4
#define IPC_UTIL_SW_MINOR_VERSION                    10
#define IPC_UTIL_SW_PATCH_VERSION                    0

/**
 * ipc_memcpy() - copy a specific size of memory from a source location to the destination location
 *
 * @dst  : used to store the address of the destination memory location where the data going to copy
 * @src  : used to store the address of the source memory location from where data is copied
 * @size : required size of memory to be copied from the source to the destination
 *
 * Return:         void
 */
void ipc_memcpy(void *dst, const void *src, uint32 data_size);

#ifdef __cplusplus
}
#endif

#endif /* IPC_UTIL_H */
