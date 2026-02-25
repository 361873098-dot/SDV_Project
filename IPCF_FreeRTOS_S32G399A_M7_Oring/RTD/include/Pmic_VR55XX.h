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

#ifndef PMIC_VR55XX_H
#define PMIC_VR55XX_H

/**
*   @file Pmic_VR55XX.h
*
*   @addtogroup PMIC_VR5510 Pmic VR5510 driver
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
#include "Pmic_VR55XX_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define PMIC_VR55XX_VENDOR_ID                        43
#define PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION         4
#define PMIC_VR55XX_AR_RELEASE_MINOR_VERSION         4
#define PMIC_VR55XX_AR_RELEASE_REVISION_VERSION      0
#define PMIC_VR55XX_SW_MAJOR_VERSION                 4
#define PMIC_VR55XX_SW_MINOR_VERSION                 0
#define PMIC_VR55XX_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Pmic_VR55XX_Types header file are from the same vendor */
#if (PMIC_VR55XX_VENDOR_ID != PMIC_VR55XX_TYPES_VENDOR_ID)
    #error "Pmic_VR55XX.h and Pmic_VR55XX_Types.h have different vendor ids"
#endif
/* Check if source file and Pmic_VR55XX_Types header file are of the same Autosar version */
#if ((PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION    != PMIC_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_MINOR_VERSION    != PMIC_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_REVISION_VERSION != PMIC_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_VR55XX.h and Pmic_VR55XX_Types.h are different"
#endif
/* Check if source file and Pmic_VR55XX_Types header file are of the same Software version */
#if ((PMIC_VR55XX_SW_MAJOR_VERSION != PMIC_VR55XX_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_VR55XX_SW_MINOR_VERSION != PMIC_VR55XX_TYPES_SW_MINOR_VERSION) || \
     (PMIC_VR55XX_SW_PATCH_VERSION != PMIC_VR55XX_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_VR55XX.h and Pmic_VR55XX_Types.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Mcal header file are of the same Autosar version */
    #if ((PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Pmic_VR55XX.h and Mcal.h are different"
    #endif
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


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"
/*!
* @brief Pmic_VR55XX_I2C_ReadRegister.
*
* @param[in] u32DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[in] pu16ValueOut.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_I2C_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut);

/*!
* @brief Pmic_VR55XX_I2C_WriteRegister.
*
* @param[in] u32DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[in] u16WriteValue.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_I2C_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, const uint16 u16WriteValue);

/*!
* @brief Pmic_VR55XX_InitDevice.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_InitDevice(const Pmic_DeviceIndexType u32DeviceId);

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_VR55XX_EmulateDeviceOTP.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_EmulateDeviceOTP(const Pmic_DeviceIndexType u32DeviceId);
#endif
/*!
* @brief Pmic_VR55XX_InitClock.
*
*
* @param[in] u32DeviceId.
* @param[in] ClockSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID);
/*!
* @brief Pmic_VR55XX_SetMode.
*
*
* @param[in] u32DeviceId.
* @param[in] u32ModeSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingID);

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/*!
* @brief Pmic_VR55XX_SetAnalogMux.
*
*
* @param[in] u32DeviceId.
* @param[in] u32AmuxChannelID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelID);
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/*!
* @brief Pmic_VR55XX_SwitchSVS.
*
*
* @param[in] u32DeviceId.
* @param[in] u32SvsSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID);
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
/*!
* @brief Pmic_VR55XX_ConfigureWatchdog.
*
*
* @param[in] u32DeviceId.
* @param[in] u32WatchdogSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingID);

/*!
* @brief Pmic_VR55XX_TriggerWatchdog.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId);

/*!
* @brief Pmic_VR55XX_DisableWatchdog.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_DisableWatchdog(const Pmic_DeviceIndexType u32DeviceId);

/*!
* @brief Pmic_VR55XX_ReleaseFs0b.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_ReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId);
#endif

/*!
* @brief Pmic_VR55XX_GetRawFaultEvents.
*
*
* @param[in] u32DeviceId.
* @param[in] pRawFaultEventsOut_VR55XX.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GetRawFaultEvents(const Pmic_DeviceIndexType u32DeviceId, Pmic_VR55XX_RawFaultType * pRawFaultEventsOut_VR55XX);
/*!
* @brief Pmic_VR55XX_SetReactions.
*
*
* @param[in] u32DeviceId.
* @param[in] u32ReactionSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingID);

#if (STD_ON == PMIC_DEVICE_INFO_API)
/*!
* @brief Pmic_VR55XX_GetDeviceInfo.
*
*
* @param[in] u32DeviceId.
* @param[in] pDeviceInfoOut.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GetDeviceInfo(const Pmic_DeviceIndexType u32DeviceId, Pmic_VR55XX_DeviceInfoType * pDeviceInfoOut);
#endif

/*!
* @brief Pmic_VR55XX_GotoInitFS.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId);

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* PMIC_VR55XX_H */
