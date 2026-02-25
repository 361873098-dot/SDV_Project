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


#ifndef PMIC_INTERNALS_H
#define PMIC_INTERNALS_H

/**
*   @file Pmic_Internals.h
*
*   @addtogroup PMIC_HLD Pmic HLD
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
#include "Pmic_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_INTERNALS_VENDOR_ID                       43
#define PMIC_INTERNALS_MODULE_ID                       255
#define PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION        4
#define PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION        4
#define PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION     0
#define PMIC_INTERNALS_SW_MAJOR_VERSION                4
#define PMIC_INTERNALS_SW_MINOR_VERSION                0
#define PMIC_INTERNALS_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_Internals.h and Pmic_Types.h are of the same vendor */
#if (PMIC_INTERNALS_VENDOR_ID != PMIC_TYPES_VENDOR_ID)
    #error "Pmic_Internals.h and Pmic_Types.h have different vendor ids"
#endif
/* Check if the files Pmic_Internals.h and Pmic_Types.h are of the same Autosar version */
#if ((PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION   ) || \
     (PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION   ) || \
     (PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION != PMIC_TYPES_AR_RELEASE_REVISION_VERSION)    \
    )
     #error "AutoSar Version Numbers of Pmic_Internals.h and Pmic_Types.h are different"
#endif
/* Check if the files Pmic_Internals.h and Pmic_Types.h are of the same software version */
#if ((PMIC_INTERNALS_SW_MAJOR_VERSION != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_INTERNALS_SW_MINOR_VERSION != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_INTERNALS_SW_PATCH_VERSION != PMIC_TYPES_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Pmic_Internals.h and Pmic_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define MAX_I2C_ADDRESS_REGISTER ((uint8)0x39)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief Internal return codes
 * @details The enumeration with all the internal return codes interpreted by the driver
 */
/* Default Values. */
#define PMIC_E_OK         (uint32)0x00000000U       /**!< @brief Function returned successfully. */
#define PMIC_E_NOK        (uint32)0x00000001U       /**!< @brief Function returned unsuccessfully. */

/* DET Runtime & Transient Errors. */
#define PMIC_E_COM        (uint32)0x00000002U       /**!< @brief Function returned with communication error. */
#define PMIC_E_DATA       (uint32)0x00000004U       /**!< @brief Function returned with corrupted data. */

/* DEM Extended Production Errors. */
#define PMIC_E_CORRUPTED  (uint32)0x00000010U       /**!< @brief Function returned with corrupted HW integrity. */
#define PMIC_E_SIGNAL     (uint32)0x00000020U       /**!< @brief Function returned with shorted safety signals. */
#define PMIC_E_CLOCK      (uint32)0x00000040U       /**!< @brief Function returned with clock failure. */
#define PMIC_E_TIMEOUT    (uint32)0x00000080U       /**!< @brief Function returned with timeout. */

/* General Masks. */
#define PMIC_E_DET        (uint32)0x00000006U       /**!< @brief Function returned with a non-development DET error. */

typedef uint32 Pmic_ReturnType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define PMIC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"


extern const Pmic_ConfigType * Pmic_pConfigStruct;

#if (PMIC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
extern const Pmic_DemConfigType * Pmic_pDemConfigStruct;
#endif


#define PMIC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"


#define PMIC_START_SEC_VAR_CLEARED_BOOLEAN
#include "Pmic_MemMap.h"


#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/**
* @brief    Array used to indicate whether the indexed device is in test mode.
*/
extern boolean Pmic_abTestMode[PMIC_MAX_DEVICECONFIGS];
#endif
/**
* @brief    Array used to indicate whether the indexed device encountered an error.
*/
extern boolean Pmic_abErrorDetected[PMIC_MAX_DEVICECONFIGS];
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
/**
* @brief    Array used to indicate watchdog trigger will be forwarded to the device
*/
extern boolean Pmic_abGateWdgTrigger[PMIC_MAX_DEVICECONFIGS];
/**
* @brief    Array used to check watchdog trigger in progress or not.
*           When Wdg_trigger is in-progress, variable will set true.
*/
extern boolean Pmic_abIsWdgTrigger[PMIC_MAX_DEVICECONFIGS];
#endif

#define PMIC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Pmic_MemMap.h"

/*==================================================================================================
                                   INTERNAL FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_INTERNALS_H */
