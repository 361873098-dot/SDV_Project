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


#ifndef PMIC_DEM_H
#define PMIC_DEM_H

/**
*   @file Pmic_Dem.h
*
*   @addtogroup PMIC_HLD Pmic HLD
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
#include "CDD_Pmic_Cfg.h"

#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
  #include "Dem.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_DEM_VENDOR_ID                       43
#define PMIC_DEM_MODULE_ID                       255
#define PMIC_DEM_AR_RELEASE_MAJOR_VERSION        4
#define PMIC_DEM_AR_RELEASE_MINOR_VERSION        4
#define PMIC_DEM_AR_RELEASE_REVISION_VERSION     0
#define PMIC_DEM_SW_MAJOR_VERSION                4
#define PMIC_DEM_SW_MINOR_VERSION                0
#define PMIC_DEM_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_Dem.h and CDD_Pmic_Cfg.h are of the same vendor */
#if (PMIC_DEM_VENDOR_ID != PMIC_CFG_VENDOR_ID)
    #error "Pmic_Dem.h and CDD_Pmic_Cfg.h have different vendor ids"
#endif
/* Check if the files Pmic_Dem.h and CDD_Pmic_Cfg.h are of the same Autosar version */
#if ((PMIC_DEM_AR_RELEASE_MAJOR_VERSION    != PMIC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_MINOR_VERSION    != PMIC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_REVISION_VERSION != PMIC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Dem.h and CDD_Pmic_Cfg.h are different"
#endif
/* Check if the files Pmic_Dem.h and CDD_Pmic_Cfg.h are of the same software version */
#if ((PMIC_DEM_SW_MAJOR_VERSION != PMIC_CFG_SW_MAJOR_VERSION) || \
     (PMIC_DEM_SW_MINOR_VERSION != PMIC_CFG_SW_MINOR_VERSION) || \
     (PMIC_DEM_SW_PATCH_VERSION != PMIC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Dem.h and CDD_Pmic_Cfg.h are different"
#endif


#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and DEM header file are of the same version */
  #if ( (PMIC_DEM_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (PMIC_DEM_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of Pmic_Dem.h and Dem.h are different"
  #endif
#endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"
/**
* @brief            API checks status and report the device run time error.
* @details          The function will report when users cannot access the device, time out by hardware checking, the wrong hardware behavior,
*                   clock setting failure, safety pin cannot release.
*
* @param[in]        eStatusCode             The status of device need to report runtime.
*
* @api
*
*/
void Pmic_Dem_Check_Device(const Pmic_ReturnType eStatusCode);

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"
#endif /* (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_DEM_H */


