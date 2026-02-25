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

#ifndef CDD_PMIC_CFG_H
#define CDD_PMIC_CFG_H

/**
*   @file CDD_Pmic_Cfg.h
*
*   @addtogroup PMIC_DRIVER_CONFIGURATION PMIC Driver Configurations
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
#include "Mcal.h"
#include "CDD_Pmic_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define PMIC_MODULE_ID_CFG                    255
#define PMIC_CFG_VENDOR_ID                    43
#define PMIC_CFG_AR_RELEASE_MAJOR_VERSION     4
#define PMIC_CFG_AR_RELEASE_MINOR_VERSION     4
#define PMIC_CFG_AR_RELEASE_REVISION_VERSION  0
#define PMIC_CFG_SW_MAJOR_VERSION             4
#define PMIC_CFG_SW_MINOR_VERSION             0
#define PMIC_CFG_SW_PATCH_VERSION             2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((PMIC_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_Pmic_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          The symbolic names of all the available devices (given in a particular configuration).
*/
#define PmicConf_PmicDevice_PmicDevice_0    ((uint32)0U)

/**
* @brief            Create defines with the IDs assigned to PMIC Clock configurations.
*                   These IDs will be transmitted as input parameters to Pmic_InitClock() API.
*/
#define PmicConf_PmicDevice_0_PmicClockSettingConfig_PmicClockSettingConfig_0    ((uint32)0U)

/**
* @brief            Create defines with the IDs assigned to PMIC Mode configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SetMode() API.
*/
#define PmicConf_PmicDevice_0_PmicModeSettingConf_PmicModeSettingConf_0    ((uint32)0U)

/**
* @brief            Create defines with the IDs assigned to PMIC Reaction configurations.
*                   These IDs will be transmitted as input parameters to Pmic_SetReactions() API.
*/
#define PmicConf_PmicDevice_0_PmicReactionsSettingConf_PmicReactionsSettingConf_0    ((uint32)0U)

/**
* @brief            Create defines with the IDs assigned to PMIC Watchdog configurations.
*                   These IDs will be transmitted as input parameters to Pmic_ConfigureWatchdog() API.
*/
#define PmicConf_PmicDevice_0_PmicWatchdogSettingConf_PmicWatchdogSettingConf_0    ((uint32)0U)


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define PMIC_PRECOMPILE_SUPPORT    (STD_ON)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define PMIC_DEV_ERROR_DETECT    (STD_OFF)  /* Disable Development Error Detection */

/**
* @brief   Switches the Ip Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define PMIC_IP_DEV_ERROR_DETECT    (STD_OFF)  /* Disable Development Error Detection */

/**
* @brief          Support for version info API.
* @details        Switches the Pmic_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define PMIC_VERSION_INFO_API    (STD_OFF) /* Disable API Pmic_GetVersionInfo     */

/**
* @brief          Support for device info API.
* @details        Switches the Pmic_GetDeviceInfo() API ON or OFF.
*
* @api
*/
#define PMIC_DEVICE_INFO_API    (STD_OFF) /* Disable API Pmic_GetDeviceInfo     */

/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define PMIC_DISABLE_DEM_REPORT_ERROR_STATUS    (STD_ON)

/**
* @brief            Enable/Disable the API for setting the AMUX pin.
*/
#define PMIC_SET_ANALOG_MUX_API    (STD_OFF)

/**
* @brief            Enable/Disable the API for setting the failsafe static voltage scaler SVS.
*/
#define PMIC_SWITCH_SVS_API    (STD_OFF)

/**
* @brief            Enable/Disable the Watchdog API.
*/
#define PMIC_WATCHDOG_API    (STD_ON)

/**
* @brief            Enable/Disable the External Watchdog Primitives.
*/
#define PMIC_EXTERNAL_WATCHDOG_API    (STD_OFF)

/**
* @brief            Check if at least one Pmic device has watchdog monitoring enabled.
*/
#define PMIC_WATCHDOG_ENABLED    (STD_ON)

/**
* @brief            Enable/Disable the Emulation OTP API.
*/
#define PMIC_OTP_EMULATION_MODE_API    (STD_OFF)
/**
* @brief            Enable/Disable timeout mechanism using loop counting.
*/
#define PMIC_TIMEOUT_MECHANISM_LOOPS    (STD_ON)


/**
* @brief            Maximum duration before returning PMIC_E_TIMEOUT. The unit of measurement is given by PmicTimeoutMechanism.
*/
#define PMIC_TIMEOUT_DURATION    (50000U)

/**
* @brief            Support for the DIE_PROCESS Setup.
*/
#define PMIC_DIE_PROCESS_ENABLE    (STD_OFF)
/**
* @brief            Support for the user mode.
*/
#define PMIC_ENABLE_USER_MODE_SUPPORT    (STD_OFF)
/**
* @brief            Support for the I2C interface.
*/
#define PMIC_INTERFACE_I2C_USED    (STD_ON)

/**
* @brief            Support for the SPI interface.
*/
#define PMIC_INTERFACE_SPI_USED    (STD_OFF)

/**
* @brief            Used in calculating the size of the internal buffer used for the "Pmic_ReadRegister" and "Pmic_WriteRegister" functions.
*/
#define PMIC_BYTES_PER_COMMAND_U32    ((uint8)5U)

/**
* @brief            The number of bytes representing the actual data within the packet/command.
*/
#define PMIC_PAYLOAD_SIZE_U32    ((uint8)4U)

/**
* @brief            The SIUL_2 instance of I2C pin.
*/
#define PMIC_SIUL_INSTANCE_U8    ((uint8)0U)

/**
* @brief            The number of OTP main register.
*/
#define PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER    ((uint8)27U)

/**
* @brief            The number of OTP main register.
*/
#define PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER    ((uint8)21U)

/**
* @brief            Maximum number of PMIC device configurations.
*/
#define PMIC_MAX_DEVICECONFIGS    ((uint32)1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            The Pmic_DeviceIndexType specifies the identification (ID) for a Pmic mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_DeviceIndexType_typedef
*/
typedef uint32 Pmic_DeviceIndexType;

/**
* @brief            The Pmic_ModeIndexType specifies the identification (ID) for a Pmic mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ModeIndexType_typedef
*/
typedef uint32 Pmic_ModeIndexType;

/**
* @brief            The Pmic_ClockSettingIndexType specifies the identification (ID) for a Pmic clock setting, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ClockSettingIndexType_typedef
*/
typedef uint32 Pmic_ClockSettingIndexType;
/**
* @brief            The Pmic_ReactionSettingIndexType specifies the identification (ID) for a Pmic reaction setting, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_ReactionSettingIndexType_typedef
*/
typedef uint32 Pmic_ReactionSettingIndexType;

/**
* @brief            The Pmic_WatchdogSettingIndexType specifies the identification (ID) for a Pmic watchdog configuration, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
* @implements       Pmic_WatchdogSettingIndexType_typedef
*/
typedef uint32 Pmic_WatchdogSettingIndexType;

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

#endif /* CDD_PMIC_CFG_H */

