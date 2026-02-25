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
*   @file Pmic_VR55XX_ocotp_external_access.c
*
*   @addtogroup ocotp_external_access
*   @{
*/

#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_VR55XX_ocotp_external_access.h"
#if (PMIC_DIE_PROCESS_ENABLE == STD_ON)
#ifdef USE_IPV_OCOTP
#include "Ocotp_Ip.h"
#else
#include "CDD_Ocotp.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_VENDOR_ID_C                      43
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C       4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C               4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MINOR_VERSION_C               0
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Ocotp External Access header file */
#if ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_VENDOR_ID_C != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_VENDOR_ID)
    #error "Ocotp External Access source file and Ocotp External Access header file have different vendor ids"
#endif
#if (( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    ) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C    != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    ) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of Ocotp External Access source file and Ocotp External Access header file are different"
#endif
#if (( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MAJOR_VERSION) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MINOR_VERSION_C != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MINOR_VERSION) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_PATCH_VERSION_C != PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocotp External Access source file and Ocotp External Access header file are different"
#endif

#ifdef PMIC_DIE_PROCESS_ENABLE
#if (PMIC_DIE_PROCESS_ENABLE == STD_ON)
#ifdef USE_IPV_OCOTP
    /* Check if current file and Ocotp header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != OCOTP_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != OCOTP_IP_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != OCOTP_IP_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Ocotp External Access source file and Ocotp_Ip.h are different"
    #endif
    #endif
#else
    /* Check if current file and ocotp header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C !=  CDD_OCOTP_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C !=  CDD_OCOTP_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C !=   CDD_OCOTP_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Ocotp External Access source file and Cdd_Ocotp.h are different"
    #endif
    #endif
#endif /* USE_IPV_OCOTP */
#endif /* (PMIC_DIE_PROCESS_ENABLE == STD_ON) */
#endif /* PMIC_DIE_PROCESS_ENABLE */
/*==================================================================================================
*                                        LOCAL VARIABLES
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
#if (PMIC_DIE_PROCESS_ENABLE == STD_ON)
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"
/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_Ocotp_ReadShadowRegister
 * Description   : Read Ocotp register
 *
 *END**************************************************************************/
Std_ReturnType Pmic_VR55XX_Ocotp_ReadShadowRegister(const uint32 u32OcotpInstance, const uint32 u32OcotpIndex, uint32 * u32Data)
{
    Std_ReturnType Status;
    uint32 u32DataCheck = 0U;
#ifdef USE_IPV_OCOTP
    Status = E_OK;

    if (Ocotp_Ip_ReadShadowRegister(u32OcotpInstance, u32OcotpIndex, &u32DataCheck) != STATUS_OCOTP_IP_SUCCESS)
    {
        Status = E_NOT_OK;
    }
#else
    (void)u32OcotpInstance;
    Status = Ocotp_ReadShadowRegister((Ocotp_ChannelType)u32OcotpIndex, &u32DataCheck);
#endif
    MCAL_FAULT_INJECTION_POINT(PMIC_FIP_04_CHANGE_OCOTP_DATA);
    *u32Data = u32DataCheck;

    return Status;
}

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"
#endif
#if defined(__cplusplus)
}
#endif

/** @}*/
