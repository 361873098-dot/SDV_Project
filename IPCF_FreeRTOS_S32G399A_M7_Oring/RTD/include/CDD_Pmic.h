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

#ifndef CDD_PMIC_H
#define CDD_PMIC_H

/**
*   @file CDD_Pmic.h
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
#include "StandardTypes.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VENDOR_ID                       43
#define PMIC_MODULE_ID                       255
#define PMIC_AR_RELEASE_MAJOR_VERSION        4
#define PMIC_AR_RELEASE_MINOR_VERSION        4
#define PMIC_AR_RELEASE_REVISION_VERSION     0
#define PMIC_SW_MAJOR_VERSION                4
#define PMIC_SW_MINOR_VERSION                0
#define PMIC_SW_PATCH_VERSION                2
#define PMIC_INSTANCE_ID                     0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic.h and Pmic_Types.h are of the same vendor */
#if (PMIC_VENDOR_ID != PMIC_TYPES_VENDOR_ID)
    #error "Pmic.h and Pmic_Types.h have different vendor ids"
#endif
/* Check if the files Pmic.h and Pmic_Types.h are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION   ) || \
     (PMIC_AR_RELEASE_MINOR_VERSION    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION   ) || \
     (PMIC_AR_RELEASE_REVISION_VERSION != PMIC_TYPES_AR_RELEASE_REVISION_VERSION)    \
    )
     #error "AutoSar Version Numbers of Pmic.h and Pmic_Types.h are different"
#endif
/* Check if the files Pmic.h and Pmic_Types.h are of the same software version */
#if ((PMIC_SW_MAJOR_VERSION != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION != PMIC_TYPES_SW_PATCH_VERSION)    \
    )
  #error "Software Version Numbers of Pmic.h and Pmic_Types.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the Pmic.h and StandardTypes.h are of the same version */
  #if ( (PMIC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (PMIC_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of Pmic.h and StandardTypes.h are different"
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
#if (STD_OFF == PMIC_PRECOMPILE_SUPPORT)
#define PMIC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

PMIC_CONFIG_EXT

#define PMIC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"
#endif
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/*!
* @brief Pmic_Init.
*
*
* @param[in] pConfigPtr.
*
* @return void.
*/
void Pmic_Init(const Pmic_ConfigType * pConfigPtr);
/*!
* @brief Pmic_InitDevice.
*
*
* @param[in] DeviceId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_InitDevice(const Pmic_DeviceIndexType DeviceId);

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_EmulateDeviceOTP.
*
*
* @param[in] DeviceId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_EmulateDeviceOTP(const Pmic_DeviceIndexType DeviceId);
#endif /* (STD_ON == PMIC_OTP_EMULATION_MODE_API) */
/*!
* @brief Pmic_ReadRegister.
*
*
* @param[in] DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[in] pu16ValueOut.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_ReadRegister(const Pmic_DeviceIndexType DeviceId,const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut);
/*!
* @brief Pmic_WriteRegister.
*
*
* @param[in] DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[in] u16WriteValue.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_WriteRegister(const Pmic_DeviceIndexType DeviceId,const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, const uint16 u16WriteValue);
/*!
* @brief Pmic_InitClock.
*
*
* @param[in] DeviceId.
* @param[in] ClockSettingId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_InitClock(const Pmic_DeviceIndexType DeviceId, const Pmic_ClockSettingIndexType ClockSettingId);
/*!
* @brief Pmic_SetMode.
*
*
* @param[in] DeviceId.
* @param[in] ModeSettingId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_SetMode(const Pmic_DeviceIndexType DeviceId, const Pmic_ModeIndexType ModeSettingId);

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/*!
* @brief Pmic_SetAnalogMux.
*
*
* @param[in] DeviceId.
* @param[in] AmuxChannelId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_SetAnalogMux(const Pmic_DeviceIndexType DeviceId, const Pmic_AmuxChannelIndexType AmuxChannelId);
#endif /* (STD_ON == PMIC_SET_ANALOG_MUX_API) */

#if (STD_ON == PMIC_SWITCH_SVS_API)
/*!
* @brief Pmic_SwitchSVS.
*
*
* @param[in] DeviceId.
* @param[in] SvsSettingID.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_SwitchSVS(const Pmic_DeviceIndexType DeviceId, const Pmic_SvsSettingIndexType SvsSettingID);
#endif /* (STD_ON == PMIC_SWITCH_SVS_API) */

#if (STD_ON == PMIC_WATCHDOG_API)
/*!
* @brief Pmic_ConfigureWatchdog.
*
*
* @param[in] DeviceId.
* @param[in] WatchdogSettingId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_ConfigureWatchdog(const Pmic_DeviceIndexType DeviceId, const Pmic_WatchdogSettingIndexType WatchdogSettingId);

/*!
* @brief Pmic_TriggerWatchdog.
*
*
* @param[in] DeviceId.
*
* @return void.
*/
void Pmic_TriggerWatchdog(const Pmic_DeviceIndexType DeviceId);
/*!
* @brief Pmic_DisableWatchdog.
*
*
* @param[in] DeviceId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_DisableWatchdog(const Pmic_DeviceIndexType DeviceId);
/**
* @brief            PMIC executes the release safety FS0B pin.
* @details          This function is used to release the safety FS0B pin.
*                   The API will not release the FS0B pin and return the E_NOT_OK if the PMIC device is not in the ASSERT_FS0B state.
*                   This API will report the E_NOT_OK if the Pmic_Init and Pmic_InitDevice APIs were not called successfully before.
*                   This function has powerful in case PMIC reacted to assert the FS0B pin and is stuck in the ASSERT_FS0B state.
*                   If users want PMIC to release FS0B and switch to the NORMAL_FS state.
*
* @param[in]        DeviceId            The ID of device.
*
* @return           E_OK: Release FS0B pin successfully
*                   E_NOT_OK: Release FS0B pin unsuccessfully
* @api
*
*/
Std_ReturnType Pmic_ReleaseFs0b(const Pmic_DeviceIndexType DeviceId);
#endif /* (STD_ON == PMIC_WATCHDOG_API) */
/*!
* @brief Pmic_GotoInitFS.
*
*
* @param[in] DeviceId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_GotoInitFS(const Pmic_DeviceIndexType DeviceId);
/*!
* @brief Pmic_GetRawFaultEvents.
*
*
* @param[in] DeviceId.
* @param[out] pRawFaultEventsOut.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_GetRawFaultEvents(const Pmic_DeviceIndexType DeviceId, Pmic_RawFaultType * pRawFaultEventsOut);
/*!
* @brief Pmic_SetReactions.
*
*
* @param[in] DeviceId.
* @param[in] ReactionSettingId.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_SetReactions(const Pmic_DeviceIndexType DeviceId, const Pmic_ReactionSettingIndexType ReactionSettingId);

#if (STD_ON == PMIC_DEVICE_INFO_API)
/*!
* @brief Pmic_GetDeviceInfo.
*
*
* @param[in] DeviceId.
* @param[in] pDeviceInfoOut.
*
* @return Std_ReturnType.
*/
Std_ReturnType Pmic_GetDeviceInfo(const Pmic_DeviceIndexType DeviceId, Pmic_DeviceInfoType * pDeviceInfoOut);
#endif /* (STD_ON == PMIC_DEVICE_INFO_API) */

#if (STD_ON == PMIC_VERSION_INFO_API)
/*!
* @brief Pmic_GetVersionInfo.
*
*
* @param[in] pVersionInfoOut.
*
* @return void.
*/
void Pmic_GetVersionInfo(Std_VersionInfoType * pVersionInfoOut);
#endif /* STD_ON == PMIC_VERSION_INFO_API */


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_PMIC_H */
