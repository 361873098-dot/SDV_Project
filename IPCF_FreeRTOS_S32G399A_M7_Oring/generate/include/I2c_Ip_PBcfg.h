/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : IIC
* Dependencies : MCU,PORT,DET,RTE
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 4.0.2
* Build Version : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
* Copyright 2020-2023 NXP
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
#ifndef I2C_IP_PBCFG_H
#define I2C_IP_PBCFG_H
/**
*   @file
*
*   @addtogroup IIC_DRIVER_CONFIGURATION IIC Driver Configurations
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I2c_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_PBCFG_VENDOR_ID                     43
#define I2C_IP_PBCFG_MODULE_ID                     255
#define I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION      4
#define I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define I2C_IP_PBCFG_SW_MAJOR_VERSION              4
#define I2C_IP_PBCFG_SW_MINOR_VERSION              0
#define I2C_IP_PBCFG_SW_PATCH_VERSION              2


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip_Types.h header file are of the same vendor */
#if (I2C_IP_PBCFG_VENDOR_ID != I2C_IP_TYPES_VENDOR_ID)
    #error "I2c_Ip_PBcfg.h and I2c_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_Types.h header file are of the same Autosar version */
#if ((I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION     != I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION     != I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION  != I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_PBcfg.h and I2c_Ip_Types.h are different"
#endif
/* Check if current file and I2c_Ip_Types.h header file are of the same software version */
#if ((I2C_IP_PBCFG_SW_MAJOR_VERSION != I2C_IP_TYPES_SW_MAJOR_VERSION) || \
     (I2C_IP_PBCFG_SW_MINOR_VERSION != I2C_IP_TYPES_SW_MINOR_VERSION) || \
     (I2C_IP_PBCFG_SW_PATCH_VERSION != I2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_PBcfg.h and I2c_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/* Channel configuration for channel IIC_4 - configured as master */
extern const I2c_Ip_MasterConfigType I2c_IICMasterChannel0;

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IP_PBCFG_H */

