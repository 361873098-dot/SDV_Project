/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SYSTEM_IP_TRUSTEDFUNCTIONS_H_
#define SYSTEM_IP_TRUSTEDFUNCTIONS_H_

/**
*   @file
*
*   @defgroup   System_Ip System IP
*   @ingroup    Platform
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "System_Ip_CfgDefines.h"
#include "Devassert.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_VENDOR_ID                          43
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                   4
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                   2
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and System_Ip_DeviceRegisters header file are of the same vendor */
#if (CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_VENDOR_ID)
    #error "System_Ip_TrustedFunctions.h and System_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and System_Ip_CfgDefines header file are of the same Autosar version */
#if ((CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \\\
     (CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \\\
     (CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION) \\\
    )
    #error "AutoSar Version Numbers of System_Ip_TrustedFunctions.h and System_Ip_CfgDefines.h are different"
#endif
/* Check if current file and System_Ip_DeviceRegisters header file are of the same Software version */
#if ((CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \\\
     (CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \\\
     (CDD_PLATFORM_SYSTEM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION) \\\
    )
    #error "Software Version Numbers of System_Ip_TrustedFunctions.h and System_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"


/**
 * @internal
 * @brief         Selects the access priority on the AHBS port of the Cortex-M7.
 */
extern void System_Ip_SetAhbSlavePriorityPrivileged(boolean bPriority);
#if ((SYSTEM_IP_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
 * @internal
 * @brief         Enables/disables core-related interrupt exceptions.
 */
extern void System_Ip_ConfigIrqPrivileged(System_Ip_IrqType eIrq, boolean bEnable);
#endif
#ifdef MCM_HAS_WABS_SUPPORTED
/**
 * @internal
 * @brief         Clears Write Abort on Slave flag.
 */
extern void System_Ip_ClearWriteAbortFlagPrivileged(void);
#endif
#ifdef MCM_HAS_PLATFORM_REVISION
/**
 * @internal
 * @brief         Returns platform revision.
 */
extern uint32 System_Ip_GetPlatformRevisionPrivileged(void);
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

#endif /* System_IP_TRUSTEDFUNCTIONS_H_ */

/** @} */
