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

#ifndef PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_H
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_H

/**
*   @file Pmic_VR55XX_ocotp_external_access.h
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
#include "StandardTypes.h"
#include "Mcal.h"
#include "CDD_Pmic_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_VENDOR_ID                      43
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION       4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MAJOR_VERSION               4
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_MINOR_VERSION               0
#define PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against StandardTypes.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION    ) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION    ) || \
     ( PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of ocotp_external_access.h and StandardTypes.h are different"
#endif
#endif

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#if (PMIC_DIE_PROCESS_ENABLE == STD_ON)
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/*!
 * @brief Ocotp read shadow register
 *
 * This function transfers data via OCOTP.
 *
 * @param[in] u32OcotpInstance OCOTP instance
 * @param[in] u32OcotpIndex    OCOTP register index
 * @param[out] u32Data         OCOTP raw register data.
 */
Std_ReturnType Pmic_VR55XX_Ocotp_ReadShadowRegister(const uint32 u32OcotpInstance, const uint32 u32OcotpIndex, uint32 * u32Data);


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"
#endif

#if defined(__cplusplus)
}
#endif

/** @}*/

#endif  /* PMIC_VR55XX_OCOTP_EXTERNAL_ACCESS_H */
