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

#ifndef PMIC_IPW_TYPES_H
#define PMIC_IPW_TYPES_H

/**
*   @file Pmic_Ipw_Types.h
*
*   @addtogroup PMIC_IPW Pmic Ipw driver
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
#include "CDD_Pmic_Cfg.h"
#include "Pmic_VR55XX_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_IPW_TYPES_VENDOR_ID                       43
#define PMIC_IPW_TYPES_MODULE_ID                       255
#define PMIC_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define PMIC_IPW_TYPES_AR_RELEASE_MINOR_VERSION        4
#define PMIC_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define PMIC_IPW_TYPES_SW_MAJOR_VERSION                4
#define PMIC_IPW_TYPES_SW_MINOR_VERSION                0
#define PMIC_IPW_TYPES_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h are of the same vendor */
#if (PMIC_IPW_TYPES_VENDOR_ID != PMIC_CFG_VENDOR_ID)
    #error "Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h have different vendor ids"
#endif
/* Check if the files Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h are of the same Autosar version */
#if ((PMIC_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PMIC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PMIC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PMIC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h are different"
#endif
/* Check if the files Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h are of the same software version */
#if ((PMIC_IPW_TYPES_SW_MAJOR_VERSION != PMIC_CFG_SW_MAJOR_VERSION) || \
     (PMIC_IPW_TYPES_SW_MINOR_VERSION != PMIC_CFG_SW_MINOR_VERSION) || \
     (PMIC_IPW_TYPES_SW_PATCH_VERSION != PMIC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw_Types.h and CDD_Pmic_Cfg.h are different"
#endif

/* Check if current file and Pmic_VR55XX_Types header file are of the same vendor */
#if (PMIC_IPW_TYPES_VENDOR_ID != PMIC_VR55XX_TYPES_VENDOR_ID)
    #error "Pmic_Ipw_Types.h and Pmic_VR55XX_Types.h have different vendor ids"
#endif
/* Check if current file and Pmic_VR55XX_Types header file are of the same Autosar version */
#if ((PMIC_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PMIC_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PMIC_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PMIC_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw_Types.h and Pmic_VR55XX_Types.h are different"
#endif
/* Check if current file and Pmic_VR55XX_Types header file are of the same Software version */
#if ((PMIC_IPW_TYPES_SW_MAJOR_VERSION != PMIC_VR55XX_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_IPW_TYPES_SW_MINOR_VERSION != PMIC_VR55XX_TYPES_SW_MINOR_VERSION) || \
     (PMIC_IPW_TYPES_SW_PATCH_VERSION != PMIC_VR55XX_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw_Types.h and Pmic_VR55XX_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief   The structure contains the mode configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_ModeConfigType * Pmic_Ipw_pVR55XXModeConfig;

} Pmic_Ipw_ModeConfigType;


/**
* @brief   The structure contains the clock configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_ClockConfigType * Pmic_Ipw_pVR55XXClockConfig;

} Pmic_Ipw_ClockConfigType;


/**
* @brief   The structure contains the reaction configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_ReactionConfigType * Pmic_Ipw_pVR55XXReactionConfig;

} Pmic_Ipw_ReactionConfigType;


#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/**
* @brief   The structure contains the AMUX channel configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_AmuxChannelConfigType * Pmic_Ipw_pVR55XXAmuxChannelConfig;

} Pmic_Ipw_AmuxChannelConfigType;
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/**
* @brief   The structure contains the SVS configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_SVSConfigType * Pmic_Ipw_pVR55XXSVSConfig;
} Pmic_Ipw_SVSConfigType;
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
/**
* @brief   The structure contains the watchdog configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_WatchdogConfigType * Pmic_Ipw_pVR55XXWatchdogConfig;

} Pmic_Ipw_WatchdogConfigType;
#endif


/**
* @brief   The structure contains the hardware configuration type.
*/
typedef struct
{
    const Pmic_VR55XX_ConfigType * Pmic_Ipw_pVR55XXHwDeviceConfig;

} Pmic_Ipw_HwDeviceConfigType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_IPW_TYPES_H */
