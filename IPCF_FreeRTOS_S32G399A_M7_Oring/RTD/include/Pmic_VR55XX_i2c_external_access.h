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

#ifndef PMIC_VR55XX_I2C_EXTERNAL_ACCESS_H
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_H

/**
*   @file Pmic_VR55XX_i2c_external_access.h
*
*   @addtogroup i2c_external_access
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_VENDOR_ID                      43
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION       4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MAJOR_VERSION               4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MINOR_VERSION               0
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against StandardTypes.h */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION    ) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION    ) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of i2c_external_access.h and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    /* I2C instance (non-AUTOSAR) / I2C channel (AUTOSAR) */
    uint32 u32I2c;
    /* I2C slave address */
    uint16 u16SlaveAddress;
    /* I2C sync/async transmission */
    boolean bSyncTransmit;
    /* I2C repeat start bit. */
    boolean bRepeatedStart;
    /* I2C buffer size */
    uint8 u8NumberOfBytes;
    /* I2C timeout */
    uint32 u32Timeout;
} Pmic_VR55XX_I2cSetupType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/*!
 * @brief I2c transfer.
 *
 * This function transfers data via I2C.
 *
 * @param[in] I2cSetupTypePtr    pointer setup I2c interface
 * @param[in] TxBufferPtr        I2C Tx buffer
 * @param[in/out] RxBufferPtr        I2C Rx buffer
 */
Std_ReturnType Pmic_VR55XX_I2cTransferExternal(const Pmic_VR55XX_I2cSetupType * pI2cSetupTypePtr, uint8 * pTxBufferPtr, uint8 * pRxBufferPtr);


#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/

#endif  /* PMIC_VR55XX_I2C_EXTERNAL_ACCESS_H */
