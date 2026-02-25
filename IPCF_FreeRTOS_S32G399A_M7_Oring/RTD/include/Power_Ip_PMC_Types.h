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

#ifndef POWER_IP_PMC_TYPES_H
#define POWER_IP_PMC_TYPES_H

/**
*   @file       Power_Ip_PMC_Types.h
*   @version    4.0.2
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
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
#define POWER_IP_PMC_TYPES_VENDOR_ID                       43
#define POWER_IP_PMC_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_PMC_TYPES_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_PMC_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_PMC_TYPES_SW_MAJOR_VERSION                4
#define POWER_IP_PMC_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_PMC_TYPES_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_PMC_TYPES_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_PMC_Types.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_PMC_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PMC_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PMC_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_PMC_Types.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_PMC_Types.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_PMC_TYPES_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_PMC_TYPES_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_PMC_TYPES_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_PMC_Types.h and Power_Ip_Specific.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration for PMC.
* @details          The power control unit (PMC) acts as a bridge for mapping the PMC peripheral
 *                  to the PMC address space.
*/
typedef struct
{
    uint32 NcspdCtrl;             /**< @brief Non-Critical Supply Presence Detector Control Register (NCSPD_CTL) */

} Power_Ip_PMC_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_PMC_TYPES_H */

