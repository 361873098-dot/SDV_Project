/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   (c) Copyright 2020-2023 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/**
*   @file    CDD_Pmic_Cfg.c
*
*   @addtogroup PMIC_DRIVER_CONFIGURATION PMIC Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_Types.h"

#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
  #include "Dem.h"
#endif /* (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_CFG_VENDOR_ID_C                     43
#define PMIC_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PMIC_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define PMIC_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define PMIC_CFG_SW_MAJOR_VERSION_C              4
#define PMIC_CFG_SW_MINOR_VERSION_C              0
#define PMIC_CFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_Cfg.c and Pmic_Types.h are of the same vendor */
#if (PMIC_CFG_VENDOR_ID_C != PMIC_TYPES_VENDOR_ID)
    #error "Pmic_Cfg.c and Pmic_Types.h have different vendor ids"
#endif
/* Check if the files Pmic_Cfg.c and Pmic_Types.h are of the same Autosar version */
#if ((PMIC_CFG_AR_RELEASE_MAJOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_CFG_AR_RELEASE_MINOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_CFG_AR_RELEASE_REVISION_VERSION_C != PMIC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Cfg.c and Pmic_Types.h are different"
#endif
/* Check if the files Pmic_Cfg.c and Pmic_Types.h are of the same software version */
#if ((PMIC_CFG_SW_MAJOR_VERSION_C  != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_CFG_SW_MINOR_VERSION_C  != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_CFG_SW_PATCH_VERSION_C  != PMIC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Cfg.c and Pmic_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    /* Check if the files Pmic_Cfg.c and Dem.h are of the same version */
    #if ((PMIC_CFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_CFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Pmic_Cfg.c and Dem.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define PMIC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"
#if (PMIC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
const Pmic_DemConfigType Pmic_DemConfig =
{
    /* DEM error reporting PMIC_E_ACESS_FAILURE */
    {(uint32)STD_OFF, 0U},

    /* DEM error reporting PMIC_E_INTEGRITY_CORRUPTED */
    {(uint32)STD_OFF, 0U},

    /* DEM error reporting PMIC_E_SIGNAL_SHORTED */
    {(uint32)STD_OFF, 0U},

    /* DEM error reporting PMIC_E_CLOCK_FAILURE */
    {(uint32)STD_OFF, 0U},

    /* DEM error reporting PMIC_E_TIMEOUT_FAILURE */
    {(uint32)STD_OFF, 0U}
};
#endif /* (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS) */
#define PMIC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

