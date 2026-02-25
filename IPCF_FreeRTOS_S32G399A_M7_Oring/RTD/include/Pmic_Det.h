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

#ifndef PMIC_DET_H
#define PMIC_DET_H

/**
*   @file Pmic_Det.h
*
*   @addtogroup PMIC_HLD Pmic HLD
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
#include "Pmic_Types.h"
#include "Pmic_Internals.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_DET_VENDOR_ID                      43
#define PMIC_DET_MODULE_ID                      255
#define PMIC_DET_AR_RELEASE_MAJOR_VERSION       4
#define PMIC_DET_AR_RELEASE_MINOR_VERSION       4
#define PMIC_DET_AR_RELEASE_REVISION_VERSION    0
#define PMIC_DET_SW_MAJOR_VERSION               4
#define PMIC_DET_SW_MINOR_VERSION               0
#define PMIC_DET_SW_PATCH_VERSION               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Pmic_Types header file are of the same vendor */
#if (PMIC_DET_VENDOR_ID != PMIC_TYPES_VENDOR_ID)
    #error "Pmic_Det.h and Pmic_Types.h have different vendor ids"
#endif
/* Check if source file and Pmic_Types header file are of the same Autosar version */
#if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_MINOR_VERSION    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_REVISION_VERSION != PMIC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Det.h and Pmic_Types.h are different"
#endif
/* Check if source file and Pmic_Types header file are of the same Software version */
#if ((PMIC_DET_SW_MAJOR_VERSION != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_DET_SW_MINOR_VERSION != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_DET_SW_PATCH_VERSION != PMIC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Det.h and Pmic_Types.h are different"
#endif

/* Check if source file and Pmic_Internals header file are of the same vendor */
#if (PMIC_DET_VENDOR_ID != PMIC_INTERNALS_VENDOR_ID)
    #error "Pmic_Det.h and Pmic_Internals.h have different vendor ids"
#endif
/* Check if source file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_MINOR_VERSION    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_REVISION_VERSION != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Det.h and Pmic_Internals.h are different"
#endif
/* Check if source file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_DET_SW_MAJOR_VERSION != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_DET_SW_MINOR_VERSION != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_DET_SW_PATCH_VERSION != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Det.h and Pmic_Internals.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"


/**
* @brief            API checks the Pmic_Init executed successfully before.
* @details          The API will report the det error if Pmic_Init did not execute successfully before.
*
* @param[in]        ePmicServiceID   The ID of PMIC API service.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_HLDChecksEntry(const Pmic_ApiServiceIdType ePmicServiceID);

/**
* @brief            API checks the Pmic driver status in Pmic_Init API
*
* @param[in]        eRetStatus   the status of process before entrance this function. This will use to set the driver status.
* @param[in]        ePmicServiceID   The ID of PMIC API service.
*
* @api
*
*/
void Pmic_HLDChecksExit(const Std_ReturnType eRetStatus, const Pmic_ApiServiceIdType ePmicServiceID);

/**
* @brief            API checks the PMIC device already initialized before call another API.
* @details          The API will report the det error if u32DeviceId is out of range. The det error also reports if PMIC device un-initialized.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        ePmicServiceID   The ID of PMIC API service.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_HLDDeviceChecksEntry(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ApiServiceIdType ePmicServiceID);

/**
* @brief            API checks the Pmic driver status when user executes the Pmic_InitDevice, Pmic_EmulateDeviceOTP API
*
* @param[in]        eRetStatus   the status of process before entrance this function.
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        ePmicServiceID   The ID of PMIC API service.
*
* @api
*
*/
void Pmic_HLDDeviceChecksExit(const Std_ReturnType eRetStatus, const Pmic_DeviceIndexType u32DeviceId, const Pmic_ApiServiceIdType ePmicServiceID);

/**
* @brief            API checks the Pmic_Init parameter input valid.
*
* @param[in]        pConfigPtr   The pointer driver configuration.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_Init(const Pmic_ConfigType * pConfigPtr);
/**
* @brief            API checks the Pmic_ReadRegister parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u8RegAddr  The PMIC register address
* @param[in]        pu16ValueOut   The pointer stores the reading value.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const uint8 u8RegAddr, const uint16 * pu16ValueOut);
/**
* @brief            API checks the Pmic_WriteRegister parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u8RegAddr  The PMIC register address
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const uint8 u8RegAddr);
/**
* @brief            API checks the Pmic_Setmode parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32ModeSettingId  The mode setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingId);
/**
* @brief            API checks the Pmic_InitClock parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32ClockSettingId  The clock setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID);

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/**
* @brief            API checks the Pmic_SetAnalogMux parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32AmuxChannelId  The amux setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelId);
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/**
* @brief            API checks the Pmic_SwitchSVS parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32SvsSettingID  The SVS setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID);
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
/**
* @brief            API checks the Pmic_ConfigureWatchdog parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32WatchdogSettingId  The watchdog setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingId);
/**
* @brief            API checks the Pmic_TriggerWatchdog parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId);
#endif
/**
* @brief            API checks the Pmic_GotoInitFS parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId);
/**
* @brief            API checks the Pmic_GetRawFaultEvents parameter input valid.
*
* @param[in]        pRawFaultEventsOut   The pointer stores the fault error counter.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_GetRawFaultEvents(const Pmic_RawFaultType * pRawFaultEventsOut);
/**
* @brief            API checks the Pmic_SetReactions parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32ReactionSettingId   The reaction setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingId);

#if (STD_ON == PMIC_DEVICE_INFO_API)
/**
* @brief            API checks the Pmic_GetDeviceInfo parameter input valid.
*
* @param[in]        pDeviceInfoOut   The pointer gets the device information.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_GetDeviceInfo(const Pmic_DeviceInfoType * pDeviceInfoOut);
#endif

#if (STD_ON == PMIC_VERSION_INFO_API)
/**
* @brief            API checks the Pmic_GetVersionInfo parameter input valid.
*
* @param[in]        pVersionInfo   The pointer gets the driver version information.
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_GetVersionInfo(const Std_VersionInfoType * pVersionInfo);
#endif /* STD_ON == PMIC_VERSION_INFO_API*/

/**
* @brief            API checks status and report the run time error.
*
* @param[in]        eStatusCode   The status of driver
* @param[in]        eServiceId    The API service id
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
void Pmic_Det_Check_ReportErrors(const Pmic_ReturnType eStatusCode, const Pmic_ApiServiceIdType eServiceId);


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_DET_H */
