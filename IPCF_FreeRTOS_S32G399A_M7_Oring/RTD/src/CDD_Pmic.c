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
*   @file CDD_Pmic.c
*
*   @addtogroup PMIC_HLD
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
#include "CDD_Pmic.h"
#include "Pmic_Det.h"
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
#include "Pmic_Dem.h"
#endif
#include "Pmic_Ipw.h"
#include "Pmic_Internals.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VENDOR_ID_C                     43
#define PMIC_AR_RELEASE_MAJOR_VERSION_C      4
#define PMIC_AR_RELEASE_MINOR_VERSION_C      4
#define PMIC_AR_RELEASE_REVISION_VERSION_C   0
#define PMIC_SW_MAJOR_VERSION_C              4
#define PMIC_SW_MINOR_VERSION_C              0
#define PMIC_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CDD_Pmic header file are of the same vendor */
#if (PMIC_VENDOR_ID_C != PMIC_VENDOR_ID)
    #error "CDD_Pmic.c and CDD_Pmic.h have different vendor ids"
#endif
/* Check if source file and CDD_Pmic header file are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION_C    != PMIC_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_AR_RELEASE_MINOR_VERSION_C    != PMIC_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_AR_RELEASE_REVISION_VERSION_C != PMIC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic.c and CDD_Pmic.h are different"
#endif
/* Check if source file and CDD_Pmic header file are of the same Software version */
#if ((PMIC_SW_MAJOR_VERSION_C != PMIC_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION_C != PMIC_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION_C != PMIC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic.c and CDD_Pmic.h are different"
#endif

/* Check if source file and Pmic_Det header file are of the same vendor */
#if (PMIC_VENDOR_ID_C != PMIC_DET_VENDOR_ID)
    #error "CDD_Pmic.c and Pmic_Det.h have different vendor ids"
#endif
/* Check if source file and Pmic_Det header file are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION_C    != PMIC_DET_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_AR_RELEASE_MINOR_VERSION_C    != PMIC_DET_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_AR_RELEASE_REVISION_VERSION_C != PMIC_DET_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic.c and Pmic_Det.h are different"
#endif
/* Check if source file and Pmic_Det header file are of the same Software version */
#if ((PMIC_SW_MAJOR_VERSION_C != PMIC_DET_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION_C != PMIC_DET_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION_C != PMIC_DET_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic.c and Pmic_Det.h are different"
#endif

#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
/* Check if source file and Pmic_Dem header file are of the same vendor */
#if (PMIC_VENDOR_ID_C != PMIC_DEM_VENDOR_ID)
    #error "CDD_Pmic.c and Pmic_Dem.h have different vendor ids"
#endif
/* Check if source file and Pmic_Dem header file are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION_C    != PMIC_DEM_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_AR_RELEASE_MINOR_VERSION_C    != PMIC_DEM_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_AR_RELEASE_REVISION_VERSION_C != PMIC_DEM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic.c and Pmic_Dem.h are different"
#endif
/* Check if source file and Pmic_Dem header file are of the same Software version */
#if ((PMIC_SW_MAJOR_VERSION_C != PMIC_DEM_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION_C != PMIC_DEM_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION_C != PMIC_DEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic.c and Pmic_Dem.h are different"
#endif
#endif

/* Check if source file and Pmic_Ipw header file are of the same vendor */
#if (PMIC_VENDOR_ID_C != PMIC_IPW_VENDOR_ID)
    #error "CDD_Pmic.c and Pmic_Ipw.h have different vendor ids"
#endif
/* Check if source file and Pmic_Ipw header file are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION_C    != PMIC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_AR_RELEASE_MINOR_VERSION_C    != PMIC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_AR_RELEASE_REVISION_VERSION_C != PMIC_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic.c and Pmic_Ipw.h are different"
#endif
/* Check if source file and Pmic_Ipw header file are of the same Software version */
#if ((PMIC_SW_MAJOR_VERSION_C != PMIC_IPW_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION_C != PMIC_IPW_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION_C != PMIC_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic.c and Pmic_Ipw.h are different"
#endif

/* Check if source file and Pmic_Internals header file are of the same vendor */
#if (PMIC_VENDOR_ID_C != PMIC_INTERNALS_VENDOR_ID)
    #error "CDD_Pmic.c and Pmic_Internals.h have different vendor ids"
#endif
/* Check if source file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_AR_RELEASE_MAJOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_AR_RELEASE_MINOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_AR_RELEASE_REVISION_VERSION_C != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic.c and Pmic_Internals.h are different"
#endif
/* Check if source file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_SW_MAJOR_VERSION_C != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_SW_MINOR_VERSION_C != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_SW_PATCH_VERSION_C != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic.c and Pmic_Internals.h are different"
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
#if (STD_ON == PMIC_PRECOMPILE_SUPPORT)

#define PMIC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

extern const Pmic_ConfigType Pmic_Config;

#define PMIC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

#endif /* #if (STD_ON == PMIC_PRECOMPILE_SUPPORT) */
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PMIC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"


/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
const Pmic_ConfigType * Pmic_pConfigStruct;


#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
/**
* @brief          DEM errors configuration pointer.
* @details        This is used to report DEM errors in the PMIC driver.
*/
const Pmic_DemConfigType * Pmic_pDemConfigStruct;
#endif


#define PMIC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"



#define PMIC_START_SEC_VAR_CLEARED_BOOLEAN
#include "Pmic_MemMap.h"


#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/**
* @brief    Array used to indicate whether the indexed device is in test mode.
*/
boolean Pmic_abTestMode[PMIC_MAX_DEVICECONFIGS];
#endif

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
/**
* @brief    Array used to indicate watchdog trigger will be forwarded to the device
*/
boolean Pmic_abGateWdgTrigger[PMIC_MAX_DEVICECONFIGS];
/**
* @brief    Array used to check watchdog trigger in progress or not.
*           When Wdg_trigger is in-progress, variable will set true.
*/
boolean Pmic_abIsWdgTrigger[PMIC_MAX_DEVICECONFIGS];
#endif
/**
* @brief    Array used to indicate whether the indexed device encountered an error.
*/
boolean Pmic_abErrorDetected[PMIC_MAX_DEVICECONFIGS];

#define PMIC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Pmic_MemMap.h"

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
* @brief            PMIC driver initialization function.
* @details          This routine initializes the PMIC Driver.
*                   The intention of this function is to make the configuration setting for reaction
*                   , mode, clock, amux, watchdog visible within the PMIC Driver.
*                   In addition, the configuration also store the dem error report and the channel id
*                   to read the OCOTP_DIE bit to configure the SVS.
*
* @param[in]        pConfigPtr   Pointer to configuration structure.
*
* @return           void
*
* @api
*
*
* @implements Pmic_Init_Activity
*/
void Pmic_Init(const Pmic_ConfigType * pConfigPtr)
{
    uint32 u32NoDeviceConfigs;
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_NOT_OK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_INIT_ID) )
    {
        if ((Std_ReturnType)E_OK == Pmic_Check_Init(pConfigPtr))
        {

#if (STD_ON == PMIC_PRECOMPILE_SUPPORT)
            Pmic_pConfigStruct = &Pmic_Config;
            (void)pConfigPtr;
#else
            Pmic_pConfigStruct = pConfigPtr;
#endif /* (STD_ON == PMIC_PRECOMPILE_SUPPORT) */

#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
            /* Get a local copy of the DEM error reporting structure. */
            Pmic_pDemConfigStruct = Pmic_pConfigStruct->Pmic_pDemConfig;
#endif /* (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS) */

            for (u32NoDeviceConfigs = (uint32)0U; u32NoDeviceConfigs < Pmic_pConfigStruct->Pmic_u8NrOfDevices; u32NoDeviceConfigs++)
            {
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
                Pmic_abTestMode[u32NoDeviceConfigs]       =  FALSE;
#endif

                Pmic_abErrorDetected[u32NoDeviceConfigs]  =  FALSE;

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
                Pmic_abGateWdgTrigger[u32NoDeviceConfigs] = FALSE;
#else
                Pmic_abGateWdgTrigger[u32NoDeviceConfigs] = TRUE;
#endif
                Pmic_abIsWdgTrigger[u32NoDeviceConfigs] = FALSE;
#endif
            }

            eCheckStatus = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Clean the store pointer in case of an error. */
            Pmic_pConfigStruct = NULL_PTR;
        }

        Pmic_HLDChecksExit(eCheckStatus, PMIC_INIT_ID);
    }
}

/**
* @brief            PMIC device initialization function.
* @details          This routine initializes the PMIC Device.
*                   The intention of this function is to make device ready for application.
*                   Initializes Fail_Safe Unit, clear fault error and release FS0B safety pin.
*
* @param[in]        DeviceId   The ID of device.
*
* @return           E_OK: Initialization is successful
*                   E_NOT_OK: Initialization is unsuccessful
* @api
*
*
* @implements Pmic_InitDevice_Activity
*/
Std_ReturnType Pmic_InitDevice(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_INIT_DEVICE_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_INIT_DEVICE_ID))
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_InitDevice(DeviceId);
            Pmic_HLDDeviceChecksExit((Std_ReturnType)eInternalStatus, DeviceId, PMIC_INIT_DEVICE_ID);
        }
        Pmic_HLDChecksExit((Std_ReturnType)eInternalStatus, PMIC_INIT_DEVICE_ID);
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_INIT_DEVICE_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/**
* @brief            PMIC device OTP initialization function.
* @details          The intention of this function is to initialize device's OTP registers.
*                   Emulate the  Fail_Safe Unit and Main Unit OTP registers.
*                   Use for development purposes only.
*
* @param[in]        DeviceId   The ID of device.
*
* @return           E_OK: Initialization is successful
*                   E_NOT_OK: Initialization is unsuccessful
* @api
*
*
* @implements Pmic_EmulateDeviceOTP_Activity
*/
Std_ReturnType Pmic_EmulateDeviceOTP(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_EMULATE_DEVICE_OTP_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_EMULATE_DEVICE_OTP_ID))
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_EmulateDeviceOTP(DeviceId);
            Pmic_HLDDeviceChecksExit((Std_ReturnType)eInternalStatus, DeviceId, PMIC_EMULATE_DEVICE_OTP_ID);
        }
        Pmic_HLDChecksExit((Std_ReturnType)eInternalStatus, PMIC_EMULATE_DEVICE_OTP_ID);
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_EMULATE_DEVICE_OTP_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}
#endif /* (STD_ON == PMIC_OTP_EMULATION_MODE_API) */

/**
* @brief            PMIC reading register function.
* @details          The intention of this function is to read register value.
*
* @param[in]        DeviceId        The ID of device.
*                   eDestination    Interface destination selection.
*                   u8RegAddr       Address of register.
*       [out]       pu16ValueOut    Value in register.
*
* @return           E_OK: Reading register is successful
*                   E_NOT_OK: Reading register is unsuccessful
* @api
*
*
* @implements Pmic_ReadRegister_Activity
*/
Std_ReturnType Pmic_ReadRegister(const Pmic_DeviceIndexType DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_READ_REGISTER_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_Check_ReadRegister(DeviceId, u8RegAddr, pu16ValueOut) )
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_ReadRegister(DeviceId, eDestination, u8RegAddr, pu16ValueOut);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_READ_REGISTER_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

/**
* @brief            PMIC writing register function.
* @details          The intention of this function is to write value to register.
*
* @param[in]        DeviceId        The ID of device.
*                   eDestination    Interface destination selection.
*                   u8RegAddr       Address of register.
*                   u16WriteValue   Value written to register.
*
* @return           E_OK: Writing register is successful
*                   E_NOT_OK: Writing register is unsuccessful
* @api
*
* @implements Pmic_WriteRegister_Activity
*/
Std_ReturnType Pmic_WriteRegister(const Pmic_DeviceIndexType DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, const uint16 u16WriteValue)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_WRITE_REGISTER_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_Check_WriteRegister(DeviceId, u8RegAddr) )
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_WriteRegister(DeviceId, eDestination, u8RegAddr, u16WriteValue);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_WRITE_REGISTER_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

/**
* @brief            PMIC setting clock function.
* @details          The intention of this function is to set clock.
*
* @param[in]        DeviceId        The ID of device.
*                   ClockSettingId  The ID of clock setting.
*
* @return           E_OK: Setting clock is successful
*                   E_NOT_OK: Setting clock is unsuccessful
* @api
*
* @implements Pmic_InitClock_Activity
*/
Std_ReturnType Pmic_InitClock(const Pmic_DeviceIndexType DeviceId, const Pmic_ClockSettingIndexType ClockSettingId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_INIT_CLOCK_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_INIT_CLOCK_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_InitClock(DeviceId, ClockSettingId) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_InitClock(DeviceId, ClockSettingId);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_INIT_CLOCK_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}


/**
* @brief            PMIC setting mode function.
* @details          The intention of this function is to set mode of device:
*                   - Sets regulators ON or OFF.
*                   - Changes mode of device.
*                   - Wake-ups device.
*
* @param[in]        DeviceId             The ID of device.
*                   ModeSettingId        The ID of mode.
*
* @return           E_OK: Setting mode is successful
*                   E_NOT_OK: Setting mode is unsuccessful
* @api
*
* @implements Pmic_SetMode_Activity
*/
Std_ReturnType Pmic_SetMode(const Pmic_DeviceIndexType DeviceId, const Pmic_ModeIndexType ModeSettingId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_SET_MODE_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_SET_MODE_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_SetMode(DeviceId, ModeSettingId) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_SetMode(DeviceId, ModeSettingId);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_SET_MODE_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/**
* @brief            PMIC setting analog mux function.
* @details          The intention of this function is to set analog mux assignment.
*
* @param[in]        DeviceId             The ID of device.
*                   AmuxChannelId        The ID of analog mux channel setting.
*
* @return           E_OK: Setting analog mux channel is successful
*                   E_NOT_OK: Setting analog mux channel is unsuccessful
* @api
*
*
* @implements Pmic_SetAnalogMux_Activity
*/
Std_ReturnType Pmic_SetAnalogMux(const Pmic_DeviceIndexType DeviceId, const Pmic_AmuxChannelIndexType AmuxChannelId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_SET_ANALOG_MUX_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_SET_ANALOG_MUX_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_SetAnalogMux(DeviceId, AmuxChannelId) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_SetAnalogMux(DeviceId, AmuxChannelId);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_SET_ANALOG_MUX_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}
#endif /* (STD_ON == PMIC_SET_ANALOG_API */

#if (STD_ON == PMIC_SWITCH_SVS_API)
/**
* @brief            PMIC re-configure static voltage scaler function.
* @details          The function will switch fail safe static voltage scale value after device was initialized.
*
* @param[in]        DeviceId             The ID of device.
*                   SvsSettingID         The ID of SVS setting.
*
* @return           E_OK: Setting SVS successfully
*                   E_NOT_OK: Setting SVS unsuccessfully
* @api
*
* @implements Pmic_SwitchSVS_Activity
*/
Std_ReturnType Pmic_SwitchSVS(const Pmic_DeviceIndexType DeviceId, const Pmic_SvsSettingIndexType SvsSettingID)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_SWITCH_SVS_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_SWITCH_SVS_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_SwitchSVS(DeviceId, SvsSettingID) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_SwitchSVS(DeviceId, SvsSettingID);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_SWITCH_SVS_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}
#endif /* (STD_ON == PMIC_SWITCH_SVS_API) */

#if (STD_ON == PMIC_WATCHDOG_API)
/**
* @brief            PMIC configuring watchdog function.
* @details          The intention of this function is to configure watchdog.
*                   Set the watchdog window during, watchdog closed or opened window.
*                   Function requires a good watchdog_refresh to complete the watchdog setting.
*                   This action can be done through notification if the macro PMIC_EXTERNAL_WATCHDOG_API is STD_OFF
*                   or the external watchdog module control if the macro PMIC_EXTERNAL_WATCHDOG_API is STD_ON
*                   And then the new duration and duty-cycle watchdog window setting will be updated immediately.
*                   Noted: Function cannot disable the watchdog window.
*
* @param[in]        DeviceId             The ID of device.
*                   WatchdogSettingId    The ID of watchdog setting.
*
* @return           E_OK: Configuring watchdog is successful
*                   E_NOT_OK: Configuring watchdog is unsuccessful
* @api
*
*
* @implements Pmic_ConfigureWatchdog_Activity
*/
Std_ReturnType Pmic_ConfigureWatchdog(const Pmic_DeviceIndexType DeviceId, const Pmic_WatchdogSettingIndexType WatchdogSettingId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_CONFIGURE_WATCHDOG_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_CONFIGURE_WATCHDOG_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_ConfigureWatchdog(DeviceId, WatchdogSettingId) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_ConfigureWatchdog(DeviceId, WatchdogSettingId);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_CONFIGURE_WATCHDOG_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

/**
* @brief            PMIC triggering watchdog function.
* @details          The intention of this function is to trigger device watchdog.
*                   Synchronizes mcu and pmic device.
*
* @param[in]        DeviceId    The ID of device.
*
* @return           E_OK: Triggering watchdog status is successful
*                   E_NOT_OK: Triggering watchdog status is unsuccessful
* @api
*
*
* @implements Pmic_TriggerWatchdog_Activity
*/
void Pmic_TriggerWatchdog(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_TRIGGER_WATCHDOG_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_Check_TriggerWatchdog(DeviceId))
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_TriggerWatchdog(DeviceId);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_TRIGGER_WATCHDOG_ID);
}

/**
* @brief            PMIC disable watchdog function.
* @details          The intention of this function is to disable device watchdog.
*                   Synchronizes mcu and pmic device.
*
* @param[in]        DeviceId    The ID of device.
*
* @return           E_OK: Disable watchdog status successfully
*                   E_NOT_OK: Disable watchdog status unsuccessfully
* @api
*
*
* @implements Pmic_DisableWatchdog_Activity
*/
Std_ReturnType Pmic_DisableWatchdog(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_DISABLE_WATCHDOG_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_DISABLE_WATCHDOG_ID))
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_DisableWatchdog(DeviceId);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_DISABLE_WATCHDOG_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

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
*
* @implements Pmic_ReleaseFs0b_Activity
*/
Std_ReturnType Pmic_ReleaseFs0b(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_RELEASE_FS0B_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_RELEASE_FS0B_ID))
        {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_ReleaseFs0b(DeviceId);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_RELEASE_FS0B_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}
#endif /* (STD_ON == PMIC_WATCHDOG_API) */

/**
* @brief            PMIC switch device back to InitFS mode.
* @details          The function should switch device back to InitFS mode. This function is called if user want to
*                   update the user configuration. Pmic_InitDevice must be called after executing this function.
*                   For example: Device was initialized successfully and drive cannot configure user configuration again.
*                   When Pmic_GotoInitFS is called, the watchdog service will be disabled until you call Pmic_InitDevice().
*                   This way makes sure that the driver can ignore trigger activity while user is changing the user_configuration (failsafe register value)
*                   To change the configuration, Pmic_GotoInitFS must be called and following by Pmic_InitDevice().
*                   Synchronizes mcu and pmic device.
*
* @param[in]        DeviceId    The ID of device.
*
* @return           E_OK: Switch InitFS successfully
*                   E_NOT_OK: Switch InitFS unsuccessfully
* @api
*
*
* @implements Pmic_GotoInitFS_Activity
*/
Std_ReturnType Pmic_GotoInitFS(const Pmic_DeviceIndexType DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_GOTO_INITFS_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_Check_GotoInitFS(DeviceId))
        {
            Pmic_abErrorDetected[DeviceId] = FALSE;
            eInternalStatus = Pmic_Ipw_GotoInitFS(DeviceId);
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_GOTO_INITFS_ID);
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    Pmic_Dem_Check_Device(eInternalStatus);
#endif

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

/**
* @brief            PMIC getting raw fault events function.
* @details          The intention of this function is to get raw fault events from main-unit and fail-safe-unit flag registers:
*                   - Over current events.
*                   - Over temperature shutdown events.
*                   - Over voltage events.
*                   - Under voltage events.
*                   - Regulator real-time states.
*                   - FCCU state.
*                   - Watchdog state.
*                   - Safety IO pin events.
*
* @param[in]        DeviceId              The ID of device.
*       [out]       pRawFaultEventsOut    The pointer to a variable storing raw fault events.
*
* @return           E_OK: Getting raw fault events is successful
*                   E_NOT_OK: Getting raw fault events is unsuccessful
* @api
*
*
* @implements Pmic_GetRawFaultEvents_Activity
*/
Std_ReturnType Pmic_GetRawFaultEvents(const Pmic_DeviceIndexType DeviceId, Pmic_RawFaultType * pRawFaultEventsOut)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_GET_RAW_FAULT_EVENTS_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_GET_RAW_FAULT_EVENTS_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_GetRawFaultEvents(pRawFaultEventsOut) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_GetRawFaultEvents(DeviceId, pRawFaultEventsOut);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_GET_RAW_FAULT_EVENTS_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}


/**
* @brief            PMIC setting system reactions function.
* @details          The intention of this function is to set reactions when the system events occurs.
*
* @param[in]        DeviceId            The ID of device.
*                   ReactionSettingId   The ID of reaction setting.
*
* @return           E_OK: Setting system events is successful
*                   E_NOT_OK: Setting system events is unsuccessful
* @api
*
*
* @implements Pmic_SetReactions_Activity
*/
Std_ReturnType Pmic_SetReactions(const Pmic_DeviceIndexType DeviceId, const Pmic_ReactionSettingIndexType ReactionSettingId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_SET_REACTIONS_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_SET_REACTIONS_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_SetReactions(DeviceId, ReactionSettingId) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_SetReactions(DeviceId, ReactionSettingId);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_SET_REACTIONS_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}

#if (STD_ON == PMIC_DEVICE_INFO_API)
/**
* @brief            PMIC getting device information function.
* @details          The intention of this function is to get device information:
*                   - Family ID
*                   - Device ID
*
* @param[in]        DeviceId            The ID of device.
*       [out]       pDeviceInfoOut      The pointer to a variable storing device information.
*
* @return           E_OK: Getting device information is successful.
*                   E_NOT_OK: Getting device information is unsuccessful.
* @api
*
*
* @implements Pmic_GetDeviceInfo_Activity
*/
Std_ReturnType Pmic_GetDeviceInfo(const Pmic_DeviceIndexType DeviceId, Pmic_DeviceInfoType * pDeviceInfoOut)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_NOK;

    if ((Std_ReturnType)E_OK == Pmic_HLDChecksEntry(PMIC_GET_DEVICE_INFO_ID))
    {
        if ((Std_ReturnType)E_OK == Pmic_HLDDeviceChecksEntry(DeviceId, PMIC_GET_DEVICE_INFO_ID))
        {
            if ((Std_ReturnType)E_OK == Pmic_Check_GetDeviceInfo(pDeviceInfoOut) )
            {
                Pmic_abErrorDetected[DeviceId] = FALSE;
                eInternalStatus = Pmic_Ipw_GetDeviceInfo(DeviceId, pDeviceInfoOut);
            }
        }
    }

    Pmic_Det_Check_ReportErrors(eInternalStatus, PMIC_GET_DEVICE_INFO_ID);

    return ((eInternalStatus == PMIC_E_OK)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK));
}
#endif /* (STD_ON == PMIC_DEVICE_INFO_API) */

#if (STD_ON == PMIC_VERSION_INFO_API)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] pVersionInfoOut   Pointer for storing the version information
*                               of this module.
*
* @return                       void.
*
* @api
*
* @note    Service ID: 0x12.
* @note    Synchronous, non re-entrant function.
*
* @implements Pmic_GetVersionInfo_Activity
*/
void Pmic_GetVersionInfo(Std_VersionInfoType * pVersionInfoOut)
{
    if ((Std_ReturnType)E_OK == Pmic_Check_GetVersionInfo(pVersionInfoOut) )
    {
        (pVersionInfoOut)->vendorID         = (uint16)PMIC_VENDOR_ID;
        (pVersionInfoOut)->moduleID         = (uint16)PMIC_MODULE_ID;
        (pVersionInfoOut)->sw_major_version = (uint8)PMIC_SW_MAJOR_VERSION;
        (pVersionInfoOut)->sw_minor_version = (uint8)PMIC_SW_MINOR_VERSION;
        (pVersionInfoOut)->sw_patch_version = (uint8)PMIC_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == PMIC_VERSION_INFO_API */


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
