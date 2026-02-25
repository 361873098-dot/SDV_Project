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
#ifndef PMIC_TYPES_H
#define PMIC_TYPES_H

/**
*   @file Pmic_Types.h
*
*   @addtogroup PMIC_HLD Pmic HLD
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Pmic_Cfg.h"
#include "Pmic_Ipw_Types.h"
#include "StandardTypes.h"
#if (!defined(USE_IPV_SIUL2))
#include "Port.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_TYPES_VENDOR_ID                         43
#define PMIC_TYPES_MODULE_ID                         255
#define PMIC_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define PMIC_TYPES_AR_RELEASE_MINOR_VERSION          4
#define PMIC_TYPES_AR_RELEASE_REVISION_VERSION       0
#define PMIC_TYPES_SW_MAJOR_VERSION                  4
#define PMIC_TYPES_SW_MINOR_VERSION                  0
#define PMIC_TYPES_SW_PATCH_VERSION                  2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_Types.h and CDD_Pmic_Cfg.h are of the same vendor */
#if (PMIC_TYPES_VENDOR_ID != PMIC_CFG_VENDOR_ID)
    #error "Pmic_Types.h and CDD_Pmic_Cfg.h have different vendor ids"
#endif
/* Check if the files Pmic_Types.h and CDD_Pmic_Cfg.h are of the same Autosar version */
#if ((PMIC_TYPES_AR_RELEASE_MAJOR_VERSION    != PMIC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_TYPES_AR_RELEASE_MINOR_VERSION    != PMIC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_TYPES_AR_RELEASE_REVISION_VERSION != PMIC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Types.h and CDD_Pmic_Cfg.h are different"
#endif
/* Check if the files Pmic_Types.h and CDD_Pmic_Cfg.h are of the same software version */
#if ((PMIC_TYPES_SW_MAJOR_VERSION != PMIC_CFG_SW_MAJOR_VERSION) || \
     (PMIC_TYPES_SW_MINOR_VERSION != PMIC_CFG_SW_MINOR_VERSION) || \
     (PMIC_TYPES_SW_PATCH_VERSION != PMIC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Types.h and CDD_Pmic_Cfg.h are different"
#endif

/* Check if the files Pmic_Types.h and Pmic_Ipw_Types.h are of the same vendor */
#if (PMIC_TYPES_VENDOR_ID != PMIC_IPW_TYPES_VENDOR_ID)
    #error "Pmic_Types.h and Pmic_Ipw_Types.h have different vendor ids"
#endif
/* Check if the files Pmic_Types.h and Pmic_Ipw_Types.h are of the same Autosar version */
#if ((PMIC_TYPES_AR_RELEASE_MAJOR_VERSION    != PMIC_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_TYPES_AR_RELEASE_MINOR_VERSION    != PMIC_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_TYPES_AR_RELEASE_REVISION_VERSION != PMIC_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Types.h and Pmic_Ipw_Types.h are different"
#endif
/* Check if the files Pmic_Types.h and Pmic_Ipw_Types.h are of the same software version */
#if ((PMIC_TYPES_SW_MAJOR_VERSION != PMIC_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_TYPES_SW_MINOR_VERSION != PMIC_IPW_TYPES_SW_MINOR_VERSION) || \
     (PMIC_TYPES_SW_PATCH_VERSION != PMIC_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Types.h and Pmic_Ipw_Types.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if the Pmic_Types.h and StandardTypes.h are of the same version */
  #if ((PMIC_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
       (PMIC_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of Pmic_Types.h and StandardTypes.h are different"
  #endif

#if (!defined(USE_IPV_SIUL2))
/* Check if the Pmic_Types.h and StandardTypes.h are of the same version */
  #if ((PMIC_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION) || \
       (PMIC_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of Pmic_Types.h and Port.h are different"
  #endif

#endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief          API service IDs.
* @details        Service IDs of the PMIC API.
* @implements     Pmic_ApiServiceIdType_enumeration
*/
typedef enum
{
    PMIC_INIT_ID                 = (uint8)0x00U, /**< @brief Pmic_Init() ID.                    */
    PMIC_INIT_DEVICE_ID          = (uint8)0x01U, /**< @brief Pmic_InitDevice() ID.              */
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
    PMIC_EMULATE_DEVICE_OTP_ID   = (uint8)0x02U, /**< @brief Pmic_EmulateDeviceOTP() ID.        */
#endif
    PMIC_READ_REGISTER_ID        = (uint8)0x03U, /**< @brief Pmic_ReadRegister() ID.            */
    PMIC_WRITE_REGISTER_ID       = (uint8)0x04U, /**< @brief Pmic_WriteRegister() ID.           */
    PMIC_INIT_CLOCK_ID           = (uint8)0x05U, /**< @brief Pmic_InitClock() ID.               */
    PMIC_SET_MODE_ID             = (uint8)0x06U, /**< @brief Pmic_SetMode() ID.                 */
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    PMIC_SET_ANALOG_MUX_ID       = (uint8)0x07U, /**< @brief Pmic_SetAnalogMux() ID.            */
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    PMIC_CONFIGURE_WATCHDOG_ID   = (uint8)0x08U, /**< @brief Pmic_ConfigureWatchdog() ID.       */
    PMIC_TRIGGER_WATCHDOG_ID     = (uint8)0x09U, /**< @brief Pmic_TriggerWatchdog() ID.         */
#endif
    PMIC_GET_RAW_FAULT_EVENTS_ID = (uint8)0x0AU, /**< @brief Pmic_GetRawFaultEvents() ID.       */
    PMIC_SET_REACTIONS_ID        = (uint8)0x0BU, /**< @brief Pmic_SetReactions() ID.            */
#if (STD_ON == PMIC_DEVICE_INFO_API)
    PMIC_GET_DEVICE_INFO_ID      = (uint8)0x0CU, /**< @brief Pmic_GetDeviceInfo() ID.           */
#endif
#if (STD_ON == PMIC_VERSION_INFO_API)
    PMIC_GET_VERSION_INFO_ID     = (uint8)0x0DU, /**< @brief Pmic_GetVersionInfo() ID.          */
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    PMIC_DISABLE_WATCHDOG_ID     = (uint8)0x0EU, /**< @brief Pmic_DisableWatchdog() ID          */
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    PMIC_SWITCH_SVS_ID           = (uint8)0x0FU, /**< @brief Pmic_SwitchSVS() ID.               */
#endif
    PMIC_GOTO_INITFS_ID          = (uint8)0x10U, /**< @brief Pmic_GotoInitFS() ID.               */
    PMIC_RELEASE_FS0B_ID         = (uint8)0x11U, /**< @brief Pmic_ReleaseFs0b() ID.               */

} Pmic_ApiServiceIdType;

/**
* @brief          Error IDs.
* @details        Error IDs of the PMIC API.
* @implements     Pmic_ErrorIdType_enumeration
*/
typedef enum
{
    /* Development Errors */
    PMIC_E_UNINIT           = (uint8)0x01U, /**< @brief Driver uninitialized.               */
    PMIC_E_INIT_FAILED      = (uint8)0x02U, /**< @brief Invalid configuration pointer.      */
    PMIC_E_DEVICE_UNINIT    = (uint8)0x03U, /**< @brief Device uninitialized.               */
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
    PMIC_E_DEVICE_OTP_UNEMU = (uint8)0x04U, /**< @brief Un-emulated OTP on blank device.    */
#endif
    PMIC_E_PARAM_POINTER    = (uint8)0x05U, /**< @brief Invalid pointer argument.           */
    PMIC_E_PARAM_DEVICE     = (uint8)0x06U, /**< @brief Invalid device ID.                  */
    PMIC_E_PARAM_MODE       = (uint8)0x07U, /**< @brief Invalid mode configuration ID.      */
    PMIC_E_PARAM_CLOCK      = (uint8)0x08U, /**< @brief Invalid clock configuration ID.     */
    PMIC_E_PARAM_WDG        = (uint8)0x09U, /**< @brief Invalid watchdog configuration ID.  */
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    PMIC_E_PARAM_AMUX       = (uint8)0x0AU, /**< @brief Invalid AMUX channel ID             */
#endif
    PMIC_E_PARAM_REACTION   = (uint8)0x0BU, /**< @brief Invalid reaction configuration ID.  */
    PMIC_E_PARAM_REG_ADDR   = (uint8)0x0CU, /**< @brief Invalid register address.           */

    /* Runtime Errors */
    PMIC_E_COMM_FAILURE     = (uint8)0x0DU, /**< @brief Underlying communication failed     */

    /* Transient Errors */
    PMIC_E_INVALID_DATA     = (uint8)0x0EU, /**< @brief CRC Verification Failed             */
#if (STD_ON == PMIC_SWITCH_SVS_API)
    PMIC_E_PARAM_SVS        = (uint8)0x0FU  /**< @brief Invalid SVS ID                      */
#endif

} Pmic_ErrorIdType;

/**
 * @brief    Interface selection
 * @details  The enumeration with interface possibilities
 */
typedef enum
{
    PMIC_INTERFACE_I2C  = 0x0U,    /**< @brief Device communicates through I2C. */
    PMIC_INTERFACE_SPI  = 0x1U     /**< @brief Device communicates through SPI. */

} Pmic_InterfaceType;

/**
 * @brief    Interface destination selection.
 * @details  The enumeration with interface destination possibilities.
 */
typedef enum
{
    PMIC_MAIN_UNIT       = 0x0U,   /**< @brief Interface with the Main Unit.      */
    PMIC_FAIL_SAFE_UNIT  = 0x1U    /**< @brief Interface with the Fail-Safe Unit. */

} Pmic_InterfaceDstType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
/**
* @brief           This gives the call-out type for watchdog task notifications.
*/
typedef void      (*Pmic_WdgTaskNotificationType)(const Pmic_DeviceIndexType DeviceId, const uint8 u8WdWindowValue, const uint8 u8WdDcValue);
#endif

/**
 * @brief      The structure containing the raw fault events for a PMIC device.
 * @details    Contains various error flags of the Main-Unit and Fail-Safe Unit.
 * @implements Pmic_RawFaultType_struct
 */
typedef struct
{
    Pmic_VR55XX_RawFaultType Pmic_RawFaultEvents;

} Pmic_RawFaultType;

#if (STD_ON == PMIC_DEVICE_INFO_API)
/**
 * @brief      The device information structure for a PMIC device.
 * @details    It contains the family id and the device id of the PMIC device.
 * @implements Pmic_DeviceInfoType_struct
 */
typedef struct
{
    Pmic_VR55XX_DeviceInfoType Pmic_DeviceInfoValue;

} Pmic_DeviceInfoType;
#endif /* (STD_ON == PMIC_DEVICE_INFO_API) */

/**
 * @brief    The interface configuration structure for a PMIC device.
 * @details  It contains the type of the interface, of the communication, and the device address.
 */
typedef struct
{
    Pmic_InterfaceType eInterfaceType;                     /**< @brief The type of the interface. */
    uint8    u8ChannelId;                                  /**< @brief The channel id of the interface. */
    uint8    u8MainUnitAddress;                            /**< @brief The address used to communicate with the Main Unit. */
    uint8    u8FailSafeUnitAddress;                        /**< @brief The address used to communicate with the Fail-Safe Unit. */

    uint32    u32I2cSclPinIndex;                           /**< @brief  The scl pin index */
    uint8     u8I2cSclPinInitialMode;                      /**< @brief  The device's i2c scl pin - initial mode */
    uint8     u8I2cSclPinMode;                             /**< @brief  The device's i2c scl pin - mode */
    uint32    u32CPUFreq;                                  /**< @brief  The device's operating frequency */
    uint32    u32I2cFreq;                                  /**< @brief  The device's i2c channel frequency */
    uint16   u16I2cSclDioChannelId;                        /**< @brief  The device's dio channel id */

} Pmic_InterfaceUnitConfigType;


/**
 * @brief      Configuration structure for a PMIC device.
 * @details    It contains the configuration that a particular PMIC device is using.
 * @implements Pmic_DeviceConfigType_struct
 */
typedef struct
{
    uint8 u8DeviceUnitId;                                                       /**< @brief Numeric instance value of the PMIC device. */
    uint8 u8NrOfModeConfigs;                                                    /**< @brief Total number of mode configurations. */
    uint8 u8NrOfClockConfigs;                                                   /**< @brief Total number of clock configurations. */
    uint8 u8NrOfReactionConfigs;                                                /**< @brief Total number of reaction configurations. */
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    uint8 u8NrOfAmuxChannelConfigs;                                             /**< @brief Total number of AMUX channel configurations. */
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    uint8 u8NrOfSVSConfigs;                                                     /**< @brief Total number of SVS configurations. */
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    uint8 u8NrOfWatchdogConfigs;                                                /**< @brief Total number of watchdog configurations. */
#endif
    const Pmic_Ipw_ModeConfigType (*paModeConfig)[];                            /**< @brief Mode data configurations. */
    const Pmic_Ipw_ClockConfigType (*paClockConfig)[];                          /**< @brief Clock data configurations. */
    const Pmic_Ipw_ReactionConfigType (*paReactionConfig)[];                    /**< @brief Reaction data configurations. */
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    const Pmic_Ipw_AmuxChannelConfigType (*paAmuxChannelConfig)[];              /**< @brief AMUX channel configurations. */
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    const Pmic_Ipw_SVSConfigType (*paSVSConfig)[];                              /**< @brief SVS configurations. */
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    const Pmic_Ipw_WatchdogConfigType (*paWatchdogConfig)[];                    /**< @brief Watchdog data configurations. */
#endif
    const Pmic_InterfaceUnitConfigType * pInterfaceConfig;                      /**< @brief The configuration of the interface used to communicate with the PMIC device. */
    const Pmic_Ipw_HwDeviceConfigType * pHwDeviceConfig;                        /**< @brief The hardware configuration of the PMIC device. */

} Pmic_DeviceConfigType;


#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting.
* @implements       Pmic_DemConfigType_struct
*/
typedef struct
{
    Mcal_DemErrorType Pmic_E_AccessFailure;
    Mcal_DemErrorType Pmic_E_IntegrityCorrupted;
    Mcal_DemErrorType Pmic_E_SignalShorted;
    Mcal_DemErrorType Pmic_E_ClockFailure;
    Mcal_DemErrorType Pmic_E_TimeoutFailure;

} Pmic_DemConfigType;
#endif /* (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS) */


/**
 * @brief      Configuration structure of the driver.
 * @details    It contains the configuration used for initializing the driver.
 * @implements Pmic_ConfigType_struct
 */
typedef struct
{
#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    uint32 Pmic_u32DiePreocessOcotpIndex;                                        /**< @brief Index of Ocotp channel read OCOTP_BANK0_WORD6. */
#endif
    uint8 Pmic_u8NrOfDevices;                                                    /**< @brief Total number of configured PMIC devices. */
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
    const Pmic_WdgTaskNotificationType Pmic_pWdgTaskNotification;                /**< @brief Pointer to callout configured by user for watchdog task notifications. */
#endif
    const Pmic_DeviceConfigType (*Pmic_paDeviceConfig)[PMIC_MAX_DEVICECONFIGS];  /**< @brief Pointer to list of PMIC device configurations. */
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    const Pmic_DemConfigType * Pmic_pDemConfig;                                  /**< @brief DEM error reporting configuration. */
#endif

} Pmic_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* PMIC_TYPES_H */
