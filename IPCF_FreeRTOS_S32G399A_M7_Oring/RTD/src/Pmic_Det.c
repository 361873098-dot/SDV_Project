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
*   @file Pmic_Det.c
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
#include "Pmic_Internals.h"
#include "Det.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_DET_VENDOR_ID_C                      43
#define PMIC_DET_AR_RELEASE_MAJOR_VERSION_C       4
#define PMIC_DET_AR_RELEASE_MINOR_VERSION_C       4
#define PMIC_DET_AR_RELEASE_REVISION_VERSION_C    0
#define PMIC_DET_SW_MAJOR_VERSION_C               4
#define PMIC_DET_SW_MINOR_VERSION_C               0
#define PMIC_DET_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CDD_Pmic header file are of the same vendor */
#if (PMIC_DET_VENDOR_ID_C != PMIC_VENDOR_ID)
    #error "Pmic_Det.c and CDD_Pmic.h have different vendor ids"
#endif
/* Check if source file and CDD_Pmic header file are of the same Autosar version */
#if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION_C    != PMIC_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_MINOR_VERSION_C    != PMIC_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_REVISION_VERSION_C != PMIC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Det.c and CDD_Pmic.h are different"
#endif
/* Check if source file and CDD_Pmic header file are of the same Software version */
#if ((PMIC_DET_SW_MAJOR_VERSION_C != PMIC_SW_MAJOR_VERSION) || \
     (PMIC_DET_SW_MINOR_VERSION_C != PMIC_SW_MINOR_VERSION) || \
     (PMIC_DET_SW_PATCH_VERSION_C != PMIC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Det.c and CDD_Pmic.h are different"
#endif

/* Check if source file and Pmic_Det header file are of the same vendor */
#if (PMIC_DET_VENDOR_ID_C != PMIC_DET_VENDOR_ID)
    #error "Pmic_Det.c and Pmic_Det.h have different vendor ids"
#endif
/* Check if source file and Pmic_Det header file are of the same Autosar version */
#if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION_C    != PMIC_DET_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_MINOR_VERSION_C    != PMIC_DET_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_REVISION_VERSION_C != PMIC_DET_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Det.c and Pmic_Det.h are different"
#endif
/* Check if source file and Pmic_Det header file are of the same Software version */
#if ((PMIC_DET_SW_MAJOR_VERSION_C != PMIC_DET_SW_MAJOR_VERSION) || \
     (PMIC_DET_SW_MINOR_VERSION_C != PMIC_DET_SW_MINOR_VERSION) || \
     (PMIC_DET_SW_PATCH_VERSION_C != PMIC_DET_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Det.c and Pmic_Det.h are different"
#endif

/* Check if source file and Pmic_Internals header file are of the same vendor */
#if (PMIC_DET_VENDOR_ID_C != PMIC_INTERNALS_VENDOR_ID)
    #error "Pmic_Det.c and Pmic_Internals.h have different vendor ids"
#endif
/* Check if source file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_MINOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DET_AR_RELEASE_REVISION_VERSION_C != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Det.c and Pmic_Internals.h are different"
#endif
/* Check if source file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_DET_SW_MAJOR_VERSION_C != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_DET_SW_MINOR_VERSION_C != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_DET_SW_PATCH_VERSION_C != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Det.c and Pmic_Internals.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == PMIC_DEV_ERROR_DETECT)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((PMIC_DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (PMIC_DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Pmic_Det.c and Det.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief  This enumerated type contains the PMIC driver's possible states.
*/
typedef enum
{
    PMIC_DRIVER_UNINIT = 0x0U,  /**< @brief The PMIC driver is uninitialized. */
    PMIC_DRIVER_INIT   = 0x1U   /**< @brief The PMIC driver is initialized.   */

} Pmic_DriverStatusType;

/**
* @brief  This enumerated type contains the PMIC devices' possible states.
*/
typedef enum
{
    PMIC_DEVICE_UNINIT    = 0x0U,  /**< @brief The PMIC device is uninitialized.  */
    PMIC_DEVICE_INIT      = 0x1U,  /**< @brief The PMIC device is initialized.    */
    PMIC_DEVICE_OTP_UNEMU = 0x2U   /**< @brief The PMIC device OTP is unemulated. */

} Pmic_DeviceStatusType;

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

#define PMIC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"
/**
*  @brief Variable that indicates the state of the driver.
*/
/* WARNING: For this initialization to work, the value of "PMIC_DRIVER_UNINIT" MUST be equal to "0" */
static Pmic_DriverStatusType Pmic_eDriverStatus;

/**
* @brief  Array that indicates the state of each configured device.
*/
/* WARNING: For this initialization to work, the value of "PMIC_DEVICE_UNINIT" MUST be equal to "0" */
static Pmic_DeviceStatusType Pmic_aDeviceStatus[PMIC_MAX_DEVICECONFIGS];

#define PMIC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

static inline Std_ReturnType Pmic_Check_DeviceID(const Pmic_DeviceIndexType u32DeviceId);
static inline Std_ReturnType Pmic_Check_Pointer(const void * pvStructure);
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
static inline Std_ReturnType Pmic_Report_Det(const Std_ReturnType eCheckStatus, const Pmic_ApiServiceIdType eServiceId, const Pmic_ErrorIdType eErrorId);
#endif /* (STD_ON == PMIC_DEV_ERROR_DETECT) */
static uint8 Pmic_GetErrorIdCheck(const Pmic_ErrorIdType eErrorId);
static uint8 Pmic_GetServiceIdCheck(const Pmic_ApiServiceIdType eServiceId);
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* PMIC state check the pointer input. */
static inline Std_ReturnType Pmic_Check_Pointer(const void * pvStructure)
{
    return ( (pvStructure != NULL_PTR)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK) );
}

/* PMIC state check the device index in the list. */
static inline Std_ReturnType Pmic_Check_DeviceID(const Pmic_DeviceIndexType u32DeviceId)
{
    return ( (u32DeviceId < Pmic_pConfigStruct->Pmic_u8NrOfDevices)? ((Std_ReturnType) E_OK) : ((Std_ReturnType) E_NOT_OK) );
}

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
/* PMIC state report det_error with API service*/
static inline Std_ReturnType Pmic_Report_Det(const Std_ReturnType eCheckStatus, const Pmic_ApiServiceIdType eServiceId, const Pmic_ErrorIdType eErrorId)
{
    if ( (Std_ReturnType)E_NOT_OK == eCheckStatus)
    {
        (void)Det_ReportError((uint16)PMIC_MODULE_ID, PMIC_INSTANCE_ID, Pmic_GetServiceIdCheck(eServiceId), Pmic_GetErrorIdCheck(eErrorId));
    }

    return eCheckStatus;
}

#endif /* (STD_ON == PMIC_DEV_ERROR_DETECT) */

/* PMIC APi convert eErrorId enum to value. It is used into Det report error */
static uint8 Pmic_GetErrorIdCheck(const Pmic_ErrorIdType eErrorId)
{
    uint8 u8ErrorId = (uint8)0xFFU;

    switch (eErrorId)
    {
        case PMIC_E_UNINIT:
            u8ErrorId = (uint8)0x01U; /* Driver uninitialized.               */
            break;
        case PMIC_E_INIT_FAILED:
            u8ErrorId = (uint8)0x02U; /* Invalid configuration pointer.      */
            break;
        case PMIC_E_DEVICE_UNINIT:
            u8ErrorId = (uint8)0x03U; /* Device uninitialized.               */
            break;
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
        case PMIC_E_DEVICE_OTP_UNEMU:
            u8ErrorId = (uint8)0x04U; /* Un-emulated OTP on blank device.    */
            break;
#endif
        case PMIC_E_PARAM_POINTER:
            u8ErrorId = (uint8)0x05U; /* Invalid pointer argument.           */
            break;
        case PMIC_E_PARAM_DEVICE:
            u8ErrorId = (uint8)0x06U; /* Invalid device ID.                  */
            break;
        case PMIC_E_PARAM_MODE:
            u8ErrorId = (uint8)0x07U; /* Invalid mode configuration ID.      */
            break;
        case PMIC_E_PARAM_CLOCK:
            u8ErrorId = (uint8)0x08U; /* Invalid clock configuration ID.     */
            break;
        case PMIC_E_PARAM_WDG:
            u8ErrorId = (uint8)0x09U; /* Invalid watchdog configuration ID.  */
            break;
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
        case PMIC_E_PARAM_AMUX:
            u8ErrorId = (uint8)0x0AU; /* Invalid AMUX channel ID             */
            break;
#endif
        case PMIC_E_PARAM_REACTION:
            u8ErrorId = (uint8)0x0BU; /* Invalid reaction configuration ID.  */
            break;
        case PMIC_E_PARAM_REG_ADDR:
            u8ErrorId = (uint8)0x0CU; /* Invalid register address.           */
            break;

    /* Runtime Errors */
        case PMIC_E_COMM_FAILURE:
            u8ErrorId = (uint8)0x0DU; /* Underlying communication failed     */
            break;

    /* Transient Errors */
        case PMIC_E_INVALID_DATA:
            u8ErrorId = (uint8)0x0EU; /* CRC Verification Failed             */
            break;
#if (STD_ON == PMIC_SWITCH_SVS_API)
        case PMIC_E_PARAM_SVS:
            u8ErrorId = (uint8)0x0FU; /* Invalid SVS ID                      */
            break;
#endif
        default:
            /* Unsupport ID */
            break;
    }

    return u8ErrorId;
}

/* PMIC APi convert eServiceId enum to value. It is used into Det report error */
static uint8 Pmic_GetServiceIdCheck(const Pmic_ApiServiceIdType eServiceId)
{
    uint8 u8ServiceId = (uint8)0xFFU;

    switch (eServiceId)
    {
        case PMIC_INIT_ID:
            u8ServiceId = (uint8)0x00U; /* Pmic_Init() ID.                    */
            break;
        case PMIC_INIT_DEVICE_ID:
            u8ServiceId = (uint8)0x01U; /* Pmic_InitDevice() ID.              */
            break;
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
        case PMIC_EMULATE_DEVICE_OTP_ID:
            u8ServiceId = (uint8)0x02U; /* Pmic_EmulateDeviceOTP() ID.        */
            break;
#endif
        case PMIC_READ_REGISTER_ID:
            u8ServiceId = (uint8)0x03U; /* Pmic_ReadRegister() ID.            */
            break;
        case PMIC_WRITE_REGISTER_ID:
            u8ServiceId = (uint8)0x04U; /* Pmic_WriteRegister() ID.           */
            break;
        case PMIC_INIT_CLOCK_ID:
            u8ServiceId = (uint8)0x05U; /* Pmic_InitClock() ID.               */
            break;
        case PMIC_SET_MODE_ID:
            u8ServiceId = (uint8)0x06U; /* Pmic_SetMode() ID.                 */
            break;
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
        case PMIC_SET_ANALOG_MUX_ID:
            u8ServiceId = (uint8)0x07U; /* Pmic_SetAnalogMux() ID.            */
            break;
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
        case PMIC_CONFIGURE_WATCHDOG_ID:
            u8ServiceId = (uint8)0x08U; /* Pmic_ConfigureWatchdog() ID.       */
            break;
        case PMIC_TRIGGER_WATCHDOG_ID:
            u8ServiceId = (uint8)0x09U; /* Pmic_TriggerWatchdog() ID.         */
            break;
#endif
        case PMIC_GET_RAW_FAULT_EVENTS_ID:
            u8ServiceId = (uint8)0x0AU; /* Pmic_GetRawFaultEvents() ID.       */
            break;
        case PMIC_SET_REACTIONS_ID:
            u8ServiceId = (uint8)0x0BU; /* Pmic_SetReactions() ID.            */
            break;
#if (STD_ON == PMIC_DEVICE_INFO_API)
        case PMIC_GET_DEVICE_INFO_ID:
            u8ServiceId = (uint8)0x0CU; /* Pmic_GetDeviceInfo() ID.           */
            break;
#endif
#if (STD_ON == PMIC_VERSION_INFO_API)
        case PMIC_GET_VERSION_INFO_ID:
            u8ServiceId = (uint8)0x0DU; /* Pmic_GetVersionInfo() ID.          */
            break;
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
        case PMIC_DISABLE_WATCHDOG_ID:
            u8ServiceId = (uint8)0x0EU; /* Pmic_DisableWatchdog() ID          */
            break;
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
        case PMIC_SWITCH_SVS_ID:
            u8ServiceId = (uint8)0x0FU; /* Pmic_SwitchSVS() ID.               */
            break;
#endif
        case PMIC_GOTO_INITFS_ID:
            u8ServiceId = (uint8)0x10U; /* Pmic_GotoInitFS() ID.               */
            break;
        case PMIC_RELEASE_FS0B_ID:
            u8ServiceId = (uint8)0x11U; /* Pmic_ReleaseFs0b() ID.               */
            break;
        default:
            /* Unsupport ID */
            break;
    }

    return u8ServiceId;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

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
Std_ReturnType Pmic_HLDChecksEntry(const Pmic_ApiServiceIdType ePmicServiceID)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (PMIC_INIT_ID != ePmicServiceID)
    {
        if (PMIC_DRIVER_UNINIT == Pmic_eDriverStatus) /* If "Pmic_Init" was not called (i.e driver is uninitialized). */
        {
            eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
            (void)Pmic_Report_Det(eCheckStatus, ePmicServiceID, PMIC_E_UNINIT);
#endif
        }
    }

    return eCheckStatus;
}

/**
* @brief            API checks the Pmic driver status in Pmic_Init API
*
* @param[in]        eRetStatus   the status of process before entrance this function. This will use to set the driver status.
* @param[in]        ePmicServiceID   The ID of PMIC API service.
*
* @api
*
*/
 void Pmic_HLDChecksExit(const Std_ReturnType eRetStatus, const Pmic_ApiServiceIdType ePmicServiceID)
{
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
    Pmic_DeviceIndexType u32DeviceId;
#endif

    if (PMIC_INIT_ID == ePmicServiceID)
    {
        if ((Std_ReturnType)E_OK == (Std_ReturnType)eRetStatus)
        {
            Pmic_eDriverStatus = PMIC_DRIVER_INIT;

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            for (u32DeviceId = 0U; u32DeviceId < PMIC_MAX_DEVICECONFIGS; ++u32DeviceId)
            {
                Pmic_aDeviceStatus[u32DeviceId] = PMIC_DEVICE_OTP_UNEMU;
            }
#endif
        }
        else
        {
            Pmic_eDriverStatus = PMIC_DRIVER_UNINIT;
        }
    }
}

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
Std_ReturnType Pmic_HLDDeviceChecksEntry(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ApiServiceIdType ePmicServiceID)
{
    Std_ReturnType eCheckStatus = Pmic_Check_DeviceID(u32DeviceId);
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, ePmicServiceID, PMIC_E_PARAM_DEVICE);
#endif

    if ( (Std_ReturnType) E_OK == eCheckStatus)
    {
        switch (ePmicServiceID)
        {
            case PMIC_INIT_DEVICE_ID:
            {
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
                if (PMIC_DEVICE_OTP_UNEMU == Pmic_aDeviceStatus[u32DeviceId]) /* If "Pmic_EmulateDeviceOTP" was not called (i.e device OTP is unemulated). */
                {
                    eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
                    (void)Pmic_Report_Det(eCheckStatus, ePmicServiceID, PMIC_E_DEVICE_OTP_UNEMU);
#endif
                }
#endif
                break;
            }
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            case PMIC_EMULATE_DEVICE_OTP_ID:
            {
                /* Nothing to be done */
                break;
            }
#endif
            default:
            {
                if (PMIC_DEVICE_INIT != Pmic_aDeviceStatus[u32DeviceId]) /* If "Pmic_InitDevice" was not called (i.e device is uninitialized). */
                {
                    eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
                    (void)Pmic_Report_Det(eCheckStatus, ePmicServiceID, PMIC_E_DEVICE_UNINIT);
#endif
                }

                break;
            }
        }
    }

    return eCheckStatus;
}

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
 void Pmic_HLDDeviceChecksExit(const Std_ReturnType eRetStatus, const Pmic_DeviceIndexType u32DeviceId, const Pmic_ApiServiceIdType ePmicServiceID)
{
    if ( (Std_ReturnType)E_OK == (Std_ReturnType)eRetStatus )
    {
        switch (ePmicServiceID)
        {
            case PMIC_INIT_DEVICE_ID:
            {
                Pmic_aDeviceStatus[u32DeviceId] = PMIC_DEVICE_INIT;
                break;
            }

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            case PMIC_EMULATE_DEVICE_OTP_ID:
            {
                Pmic_aDeviceStatus[u32DeviceId] = PMIC_DEVICE_UNINIT;
                break;
            }
#endif

            default:
            {
                /* Nothing to do */
                break;
            }
        }
    }
}

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
Std_ReturnType Pmic_Check_Init(const Pmic_ConfigType * pConfigPtr)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

#if (STD_OFF == PMIC_PRECOMPILE_SUPPORT)
    eCheckStatus = Pmic_Check_Pointer(pConfigPtr);
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_INIT_ID, PMIC_E_INIT_FAILED);
#endif

#else /* STD_ON == PMIC_PRECOMPILE_SUPPORT */
    if (NULL_PTR != pConfigPtr)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_INIT_ID, PMIC_E_INIT_FAILED);
#endif
    }

#endif /* (STD_ON == PMIC_PRECOMPILE_SUPPORT) */

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const uint8 u8RegAddr,const uint16 * pu16ValueOut)
{
    Std_ReturnType eCheckStatus = Pmic_Check_DeviceID(u32DeviceId);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_READ_REGISTER_ID, PMIC_E_PARAM_DEVICE);
#endif
    if ((Std_ReturnType)E_OK ==  eCheckStatus)
    {
        eCheckStatus = Pmic_Check_Pointer(pu16ValueOut);
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_READ_REGISTER_ID, PMIC_E_PARAM_POINTER);
#endif
        if ((Std_ReturnType)E_OK ==  eCheckStatus)
        {
            if (MAX_I2C_ADDRESS_REGISTER < u8RegAddr)
            {
                eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
                (void)Pmic_Report_Det(eCheckStatus, PMIC_READ_REGISTER_ID, PMIC_E_PARAM_REG_ADDR);
#endif
            }
        }
    }
    else
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
    }

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const uint8 u8RegAddr)
{
    Std_ReturnType eCheckStatus = Pmic_Check_DeviceID(u32DeviceId);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_WRITE_REGISTER_ID, PMIC_E_PARAM_DEVICE);
#endif
    if ((Std_ReturnType)E_OK ==  eCheckStatus)
    {
        if (MAX_I2C_ADDRESS_REGISTER < u8RegAddr)
        {
            eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
            (void)Pmic_Report_Det(eCheckStatus, PMIC_WRITE_REGISTER_ID, PMIC_E_PARAM_REG_ADDR);
#endif
        }
    }

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingId)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32ModeSettingId >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfModeConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_SET_MODE_ID, PMIC_E_PARAM_MODE);
#endif
    }

    return eCheckStatus;
}

/**
* @brief            API checks the Pmic_InitClock parameter input valid.
*
* @param[in]        u32DeviceId   The ID of PMIC device
* @param[in]        u32ClockSettingID  The clock setting index
*
* @return           E_OK: Check is successful
*                   E_NOT_OK: Check is unsuccessful
* @api
*
*/
Std_ReturnType Pmic_Check_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32ClockSettingID >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfClockConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_INIT_CLOCK_ID, PMIC_E_PARAM_CLOCK);
#endif
    }

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelId)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32AmuxChannelId >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfAmuxChannelConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_SET_ANALOG_MUX_ID, PMIC_E_PARAM_AMUX);
#endif
    }

    return eCheckStatus;
}
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
Std_ReturnType Pmic_Check_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32SvsSettingID >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfSVSConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_SWITCH_SVS_ID, PMIC_E_PARAM_SVS);
#endif
    }

    return eCheckStatus;
}
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
Std_ReturnType Pmic_Check_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingId)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32WatchdogSettingId >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfWatchdogConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_CONFIGURE_WATCHDOG_ID, PMIC_E_PARAM_WDG);
#endif
    }

    return eCheckStatus;
}
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
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
Std_ReturnType Pmic_Check_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId)
{
    Std_ReturnType eCheckStatus = Pmic_Check_DeviceID(u32DeviceId);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_TRIGGER_WATCHDOG_ID, PMIC_E_PARAM_DEVICE);
#endif

    return eCheckStatus;
}
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
Std_ReturnType Pmic_Check_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId)
{
    Std_ReturnType eCheckStatus = Pmic_Check_DeviceID(u32DeviceId);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_GOTO_INITFS_ID, PMIC_E_PARAM_DEVICE);
#endif

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_GetRawFaultEvents(const Pmic_RawFaultType * pRawFaultEventsOut)
{
    Std_ReturnType eCheckStatus = Pmic_Check_Pointer(pRawFaultEventsOut);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_GET_RAW_FAULT_EVENTS_ID, PMIC_E_PARAM_POINTER);
#endif

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingId)
{
    Std_ReturnType eCheckStatus = (Std_ReturnType)E_OK;

    if (u32ReactionSettingId >= (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].u8NrOfReactionConfigs)
    {
        eCheckStatus = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == PMIC_DEV_ERROR_DETECT)
        (void)Pmic_Report_Det(eCheckStatus, PMIC_SET_REACTIONS_ID, PMIC_E_PARAM_REACTION);
#endif
    }

    return eCheckStatus;
}

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
Std_ReturnType Pmic_Check_GetDeviceInfo(const Pmic_DeviceInfoType * pDeviceInfoOut)
{
    Std_ReturnType eCheckStatus = Pmic_Check_Pointer(pDeviceInfoOut);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_GET_DEVICE_INFO_ID, PMIC_E_PARAM_POINTER);
#endif

    return eCheckStatus;
}
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
Std_ReturnType Pmic_Check_GetVersionInfo(const Std_VersionInfoType * pVersionInfo)
{
    Std_ReturnType eCheckStatus = Pmic_Check_Pointer(pVersionInfo);

#if (STD_ON == PMIC_DEV_ERROR_DETECT)
    eCheckStatus = Pmic_Report_Det(eCheckStatus, PMIC_GET_VERSION_INFO_ID, PMIC_E_PARAM_POINTER);
#endif

    return eCheckStatus;
}
#endif /* (STD_ON == PMIC_VERSION_INFO_API) */

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
void Pmic_Det_Check_ReportErrors(const Pmic_ReturnType eStatusCode, const Pmic_ApiServiceIdType eServiceId)
{
    if (0U != (eStatusCode & PMIC_E_DET))
    {
        if (0U != (eStatusCode & PMIC_E_COM))
        {
            (void) Det_ReportRuntimeError((uint16)PMIC_MODULE_ID, (uint8)PMIC_INSTANCE_ID, Pmic_GetServiceIdCheck(eServiceId), Pmic_GetErrorIdCheck(PMIC_E_COMM_FAILURE));
        }

        if (0U != (eStatusCode & PMIC_E_DATA))
        {
            (void) Det_ReportTransientFault((uint16)PMIC_MODULE_ID, (uint8)PMIC_INSTANCE_ID, Pmic_GetServiceIdCheck(eServiceId), Pmic_GetErrorIdCheck(PMIC_E_INVALID_DATA));
        }
    }
}


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
