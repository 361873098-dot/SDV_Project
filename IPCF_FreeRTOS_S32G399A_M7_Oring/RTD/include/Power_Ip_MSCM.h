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

#ifndef POWER_IP_MSCM_H
#define POWER_IP_MSCM_H

/**
*   @file       Power_Ip_MSCM.h
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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_Specific.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_MSCM_VENDOR_ID                        43
#define POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION         4
#define POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION         4
#define POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION      0
#define POWER_IP_MSCM_SW_MAJOR_VERSION                 4
#define POWER_IP_MSCM_SW_MINOR_VERSION                 0
#define POWER_IP_MSCM_SW_PATCH_VERSION                 2


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_MSCM.h file and Power_Ip_Cfg_Defines.h file have same versions */
#if (POWER_IP_MSCM_VENDOR_ID  != POWER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Power_Ip_MSCM.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_MSCM.h file and Power_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((POWER_IP_MSCM_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MSCM_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MSCM_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_MSCM.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_MSCM.h file and Power_Ip_Cfg_Defines.h file are of the same Software version */
#if ((POWER_IP_MSCM_SW_MAJOR_VERSION != POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_MSCM_SW_MINOR_VERSION != POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_MSCM_SW_PATCH_VERSION != POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_MSCM.h and Power_Ip_Cfg_Defines.h are different"
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define MSCM_CORE_PERSONALITY_MASK32        ((uint32)0xFF000000U)

#define MSCM_CPXTYPE_A53_MASK32             ((uint32)0x41000000U)
#define MSCM_CPXTYPE_M7_MASK32              ((uint32)0x43000000U)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief            Type of the return value of the function Mcu_GetCpxType.
* @details          The type of Mcu_CpxType is an enumeration with the following values:
*                   POWER_IP_CORE_A53, POWER_IP_CORE_CM7.
*
*/
typedef enum
{
    POWER_IP_CORE_UNDEFINED = 0x00U,     /**< @brief Undefined core. */
    POWER_IP_CORE_A53,                   /**< @brief Cortex A53 core. */
    POWER_IP_CORE_CM7,                   /**< @brief Cortex M7 core. */

} Power_Ip_MSCM_CpxType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


Power_Ip_MSCM_CpxType Power_Ip_MSCM_GetPersonality(void);


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_MSCM_H */


