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
*   @file Pmic_Ipw.c
*
*   @addtogroup PMIC_IPW Pmic Ipw driver
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_Ipw.h"
#include "Pmic_VR55XX.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_IPW_VENDOR_ID_C                     43
#define PMIC_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define PMIC_IPW_AR_RELEASE_MINOR_VERSION_C      4
#define PMIC_IPW_AR_RELEASE_REVISION_VERSION_C   0
#define PMIC_IPW_SW_MAJOR_VERSION_C              4
#define PMIC_IPW_SW_MINOR_VERSION_C              0
#define PMIC_IPW_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Pmic_Ipw header file are of the same vendor */
#if (PMIC_IPW_VENDOR_ID_C != PMIC_IPW_VENDOR_ID)
    #error "Pmic_Ipw.c and Pmic_Ipw.h have different vendor ids"
#endif
/* Check if current file and Pmic_Ipw header file are of the same Autosar version */
#if ((PMIC_IPW_AR_RELEASE_MAJOR_VERSION_C    != PMIC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_MINOR_VERSION_C    != PMIC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_REVISION_VERSION_C != PMIC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw.c and Pmic_Ipw.h are different"
#endif
/* Check if current file and Pmic_Ipw header file are of the same Software version */
#if ((PMIC_IPW_SW_MAJOR_VERSION_C != PMIC_IPW_SW_MAJOR_VERSION) || \
     (PMIC_IPW_SW_MINOR_VERSION_C != PMIC_IPW_SW_MINOR_VERSION) || \
     (PMIC_IPW_SW_PATCH_VERSION_C != PMIC_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw.c and Pmic_Ipw.h are different"
#endif

/* Check if current file and Pmic_VR55XX header file are of the same vendor */
#if (PMIC_IPW_VENDOR_ID_C != PMIC_VR55XX_VENDOR_ID)
    #error "Pmic_Ipw.c and Pmic_VR55XX.h have different vendor ids"
#endif
/* Check if current file and Pmic_VR55XX header file are of the same Autosar version */
#if ((PMIC_IPW_AR_RELEASE_MAJOR_VERSION_C    != PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_MINOR_VERSION_C    != PMIC_VR55XX_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_IPW_AR_RELEASE_REVISION_VERSION_C != PMIC_VR55XX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Ipw.c and Pmic_VR55XX.h are different"
#endif
/* Check if current file and Pmic_VR55XX header file are of the same Software version */
#if ((PMIC_IPW_SW_MAJOR_VERSION_C != PMIC_VR55XX_SW_MAJOR_VERSION) || \
     (PMIC_IPW_SW_MINOR_VERSION_C != PMIC_VR55XX_SW_MINOR_VERSION) || \
     (PMIC_IPW_SW_PATCH_VERSION_C != PMIC_VR55XX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Ipw.c and Pmic_VR55XX.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
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
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/**
*   @brief   This function read register value via I2c
*
*/
Pmic_ReturnType Pmic_Ipw_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut)
{
    return Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, eDestination, u8RegAddr, pu16ValueOut);
}

/**
*   @brief   This function write register value via I2c
*
*/
Pmic_ReturnType Pmic_Ipw_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 u16WriteValue)
{
    return Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, eDestination, u8RegAddr, u16WriteValue);
}

/**
*   @brief   This function initializes device
*
*/
Pmic_ReturnType Pmic_Ipw_InitDevice(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_InitDevice(u32DeviceId);
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/**
*   @brief   This function emulate OTP for device.
*
*/
Pmic_ReturnType Pmic_Ipw_EmulateDeviceOTP(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_EmulateDeviceOTP(u32DeviceId);
}
#endif

/**
*   @brief   This function initializes driver.
*
*/
Pmic_ReturnType Pmic_Ipw_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID)
{
    return Pmic_VR55XX_InitClock(u32DeviceId, u32ClockSettingID);
}

/**
*   @brief   This function set mode operation.
*
*/
Pmic_ReturnType Pmic_Ipw_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingID)
{
    return Pmic_VR55XX_SetMode(u32DeviceId, u32ModeSettingID);
}

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/**
*   @brief   This function set analog mux channel.
*
*/
Pmic_ReturnType Pmic_Ipw_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelID)
{
    return Pmic_VR55XX_SetAnalogMux(u32DeviceId, u32AmuxChannelID);
}
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/**
*   @brief   This function re-configures the static voltage scaler value.
*
*/
Pmic_ReturnType Pmic_Ipw_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID)
{
    return Pmic_VR55XX_SwitchSVS(u32DeviceId, u32SvsSettingID);
}
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
/**
*   @brief   This function re-configures the watchdog window except window disabling.
*
*/
Pmic_ReturnType Pmic_Ipw_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingID)
{
    return Pmic_VR55XX_ConfigureWatchdog(u32DeviceId, u32WatchdogSettingID);
}

/**
*   @brief   This function trigger watchdog for initialization device, maintain the operation.
*
*/
Pmic_ReturnType Pmic_Ipw_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_TriggerWatchdog(u32DeviceId);
}

/**
*   @brief   This function disable watchdog.
*
*/
Pmic_ReturnType Pmic_Ipw_DisableWatchdog(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_DisableWatchdog(u32DeviceId);
}

/**
*   @brief   This function release the FS0b pin.
*
*/
Pmic_ReturnType Pmic_Ipw_ReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_ReleaseFs0b(u32DeviceId);
}
#endif

/**
*   @brief   This function switch device back to InitFS mode.
*
*/
Pmic_ReturnType Pmic_Ipw_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId)
{
    return Pmic_VR55XX_GotoInitFS(u32DeviceId);
}

/**
*   @brief   This function gets the fault error event.
*
*/
Pmic_ReturnType Pmic_Ipw_GetRawFaultEvents(const Pmic_DeviceIndexType u32DeviceId, Pmic_RawFaultType * pRawFaultEventsOut)
{
    return Pmic_VR55XX_GetRawFaultEvents(u32DeviceId, &(pRawFaultEventsOut->Pmic_RawFaultEvents));
}

/**
*   @brief   This function set reaction when fault occurs.
*
*/
Pmic_ReturnType Pmic_Ipw_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingID)
{
    return Pmic_VR55XX_SetReactions(u32DeviceId, u32ReactionSettingID);
}

#if (STD_ON == PMIC_DEVICE_INFO_API)
/**
*   @brief   This function gets the device information.
*
*/
Pmic_ReturnType Pmic_Ipw_GetDeviceInfo(const Pmic_DeviceIndexType u32DeviceId, Pmic_DeviceInfoType * pDeviceInfoOut)
{
    return Pmic_VR55XX_GetDeviceInfo(u32DeviceId, &(pDeviceInfoOut->Pmic_DeviceInfoValue));
}
#endif

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
