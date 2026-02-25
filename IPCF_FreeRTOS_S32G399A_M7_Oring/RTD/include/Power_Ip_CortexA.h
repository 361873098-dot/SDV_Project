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

#ifndef POWER_IP_CORTEXA_H
#define POWER_IP_CORTEXA_H


/**
*   @file       Power_Ip_CortexA.h
*   @version    4.0.2
*
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Power_Ip_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CORTEXA_VENDOR_ID                       43
#define POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_CORTEXA_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_CORTEXA_SW_MAJOR_VERSION                4
#define POWER_IP_CORTEXA_SW_MINOR_VERSION                0
#define POWER_IP_CORTEXA_SW_PATCH_VERSION                2


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_CortexA.h file and Power_Ip_Cfg.h file have same versions */
#if (POWER_IP_CORTEXA_VENDOR_ID  != POWER_IP_CFG_VENDOR_ID)
    #error "Power_Ip_CortexA.h and Power_Ip_Cfg.h have different vendor IDs"
#endif

/* Check if Power_Ip_CortexA.h file and Power_Ip_Cfg.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXA_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_CortexA.h and Power_Ip_Cfg.h are different"
#endif

/* Check if Power_Ip_CortexA.h file and Power_Ip_Cfg.h file are of the same Software version */
#if ((POWER_IP_CORTEXA_SW_MAJOR_VERSION != POWER_IP_CFG_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXA_SW_MINOR_VERSION != POWER_IP_CFG_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXA_SW_PATCH_VERSION != POWER_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_CortexA.h and Power_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_CortexA.h file and Mcal.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_CortexA.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


#if (defined(MCAL_PLATFORM_ARM) && (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64))

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
#define  Call_Power_Ip_CortexA64_WarmReset() \
    OsIf_Trusted_Call(Power_Ip_CortexA64_WarmReset)
  #else
#define  Call_Power_Ip_CortexA64_WarmReset() \
    Power_Ip_CortexA64_WarmReset()
  #endif
#endif

void Power_Ip_CortexA64_WarmReset(void);
#endif /* (defined(MCAL_PLATFORM_ARM) && (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)) */


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_CORTEXA_H */


