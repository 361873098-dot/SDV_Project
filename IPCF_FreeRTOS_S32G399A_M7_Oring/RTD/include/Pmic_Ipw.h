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

#ifndef PMIC_IPW_H
#define PMIC_IPW_H

/**
*   @file Pmic_Ipw.h
*
*   @addtogroup PMIC_IPW Pmic Ipw driver
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
#include "Pmic_Internals.h"
#include "Pmic_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_IPW_VENDOR_ID                       43
#define PMIC_IPW_MODULE_ID                       255
#define PMIC_IPW_AR_RELEASE_MAJOR_VERSION        4
#define PMIC_IPW_AR_RELEASE_MINOR_VERSION        4
#define PMIC_IPW_AR_RELEASE_REVISION_VERSION     0
#define PMIC_IPW_SW_MAJOR_VERSION                4
#define PMIC_IPW_SW_MINOR_VERSION                0
#define PMIC_IPW_SW_PATCH_VERSION                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pmic_Internals header file are of the same vendor */
#if (PMIC_IPW_VENDOR_ID != PMIC_INTERNALS_VENDOR_ID)
    #error "Pmic_Ipw.h and Pmic_Internals.h have different vendor ids"
#endif
/* Check if current file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_IPW_AR_RELEASE_MAJOR_VERSION    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_MINOR_VERSION    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_REVISION_VERSION != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw.h and Pmic_Internals.h are different"
#endif
/* Check if current file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_IPW_SW_MAJOR_VERSION != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_IPW_SW_MINOR_VERSION != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_IPW_SW_PATCH_VERSION != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw.h and Pmic_Internals.h are different"
#endif

/* Check if current file and Pmic_Types header file are of the same vendor */
#if (PMIC_IPW_VENDOR_ID != PMIC_TYPES_VENDOR_ID)
    #error "Pmic_Ipw.h and Pmic_Types.h have different vendor ids"
#endif
/* Check if current file and Pmic_Types header file are of the same Autosar version */
#if ((PMIC_IPW_AR_RELEASE_MAJOR_VERSION    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_MINOR_VERSION    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_REVISION_VERSION != PMIC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw.h and Pmic_Types.h are different"
#endif
/* Check if current file and Pmic_Types header file are of the same Software version */
#if ((PMIC_IPW_SW_MAJOR_VERSION != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_IPW_SW_MINOR_VERSION != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_IPW_SW_PATCH_VERSION != PMIC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw.h and Pmic_Types.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Mcal header file are of the same Autosar version */
#if ((PMIC_IPW_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw.h and Mcal.h are different"
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
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

Pmic_ReturnType Pmic_Ipw_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut);

Pmic_ReturnType Pmic_Ipw_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 u16WriteValue);

Pmic_ReturnType Pmic_Ipw_InitDevice(const Pmic_DeviceIndexType u32DeviceId);

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
Pmic_ReturnType Pmic_Ipw_EmulateDeviceOTP(const Pmic_DeviceIndexType u32DeviceId);
#endif

Pmic_ReturnType Pmic_Ipw_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID);

Pmic_ReturnType Pmic_Ipw_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingID);

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
Pmic_ReturnType Pmic_Ipw_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelID);
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
Pmic_ReturnType Pmic_Ipw_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID);
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
Pmic_ReturnType Pmic_Ipw_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingID);

Pmic_ReturnType Pmic_Ipw_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId);
Pmic_ReturnType Pmic_Ipw_DisableWatchdog(const Pmic_DeviceIndexType u32DeviceId);
Pmic_ReturnType Pmic_Ipw_ReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId);
#endif

Pmic_ReturnType Pmic_Ipw_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId);

Pmic_ReturnType Pmic_Ipw_GetRawFaultEvents(const Pmic_DeviceIndexType u32DeviceId, Pmic_RawFaultType * pRawFaultEventsOut);

Pmic_ReturnType Pmic_Ipw_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingID);

#if (STD_ON == PMIC_DEVICE_INFO_API)
Pmic_ReturnType Pmic_Ipw_GetDeviceInfo(const Pmic_DeviceIndexType u32DeviceId, Pmic_DeviceInfoType * pDeviceInfoOut);
#endif

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_IPW_H */
