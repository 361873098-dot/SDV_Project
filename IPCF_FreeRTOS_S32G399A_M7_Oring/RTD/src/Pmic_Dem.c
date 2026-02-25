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
*   @file Pmic_Dem.c
*
*   @addtogroup PMIC_HLD
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
#include "Pmic_Dem.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_DEM_VENDOR_ID_C                       43
#define PMIC_DEM_AR_RELEASE_MAJOR_VERSION_C        4
#define PMIC_DEM_AR_RELEASE_MINOR_VERSION_C        4
#define PMIC_DEM_AR_RELEASE_REVISION_VERSION_C     0
#define PMIC_DEM_SW_MAJOR_VERSION_C                4
#define PMIC_DEM_SW_MINOR_VERSION_C                0
#define PMIC_DEM_SW_PATCH_VERSION_C                2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The module's implementer shall avoid the integration of incompatible files.
*
*/
/* Check if source file and Pmic_Internals header file are of the same vendor */
#if (PMIC_DEM_VENDOR_ID_C != PMIC_INTERNALS_VENDOR_ID)
    #error "Pmic_Dem.c and Pmic_Internals.h have different vendor ids"
#endif
/* Check if source file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_DEM_AR_RELEASE_MAJOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_MINOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_REVISION_VERSION_C != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Dem.c and Pmic_Internals.h are different"
#endif
/* Check if source file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_DEM_SW_MAJOR_VERSION_C != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_DEM_SW_MINOR_VERSION_C != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_DEM_SW_PATCH_VERSION_C != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Dem.c and Pmic_Internals.h are different"
#endif

/* Check if current file and Pmic_Dem header file are of the same vendor */
#if (PMIC_DEM_VENDOR_ID_C != PMIC_DEM_VENDOR_ID)
    #error "Pmic_Dem.c and Pmic_Dem.h have different vendor ids"
#endif
/* Check if current file and Pmic_Dem header file are of the same Autosar version */
#if ((PMIC_DEM_AR_RELEASE_MAJOR_VERSION_C    != PMIC_DEM_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_MINOR_VERSION_C    != PMIC_DEM_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_DEM_AR_RELEASE_REVISION_VERSION_C != PMIC_DEM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_Dem.c and Pmic_Dem.h are different"
#endif
/* Check if current file and Pmic_Dem header file are of the same software version */
#if ((PMIC_DEM_SW_MAJOR_VERSION_C != PMIC_DEM_SW_MAJOR_VERSION) || \
     (PMIC_DEM_SW_MINOR_VERSION_C != PMIC_DEM_SW_MINOR_VERSION) || \
     (PMIC_DEM_SW_PATCH_VERSION_C != PMIC_DEM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_Dem.c and Pmic_Dem.h are different"
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
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/**
* @brief            API checks status and report the device run time error.
* @details          The function will report when users cannot access the device, time out by hardware checking, the wrong hardware behavior,
*                   clock setting failure, safety pin cannot release.
*
* @param[in]        eStatusCode             The status of device need to report runtime.
*
* @api
*
*/
void Pmic_Dem_Check_Device(const Pmic_ReturnType eStatusCode)
{
    if (0U != (eStatusCode & PMIC_E_COM))
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_AccessFailure.state)
        {
             /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_AccessFailure.id, DEM_EVENT_STATUS_PREFAILED);
        }
    }
    else
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_AccessFailure.state)
        {
             /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_AccessFailure.id, DEM_EVENT_STATUS_PREPASSED);
        }
    }

    if (0U != (eStatusCode & PMIC_E_TIMEOUT))
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_TimeoutFailure.state)
        {
             /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_TimeoutFailure.id, DEM_EVENT_STATUS_FAILED);
        }
    }

    if (0U != (eStatusCode & PMIC_E_CORRUPTED))
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_IntegrityCorrupted.state)
        {
            /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_IntegrityCorrupted.id, DEM_EVENT_STATUS_FAILED);
        }
    }

    if (0U != (eStatusCode & PMIC_E_SIGNAL))
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_SignalShorted.state)
        {
             /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_SignalShorted.id, DEM_EVENT_STATUS_FAILED);
        }
    }
    if (0U != (eStatusCode & PMIC_E_CLOCK))
    {
        if ((uint32)STD_ON == Pmic_pDemConfigStruct->Pmic_E_ClockFailure.state)
        {
             /* BSW modules calling Dem_SetEventStatus can safely ignore the return value */
            (void)Dem_SetEventStatus((Dem_EventIdType)Pmic_pDemConfigStruct->Pmic_E_ClockFailure.id, DEM_EVENT_STATUS_FAILED);
        }
    }
}

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif

/** @} */
