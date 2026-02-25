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
#include "I2c_Ip_PBcfg.h"

#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
#include "Dma_Ip.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_PBCFG_VENDOR_ID_C                     43
#define I2C_IP_PBCFG_MODULE_ID_C                     255
#define I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define I2C_IP_PBCFG_SW_MAJOR_VERSION_C              4
#define I2C_IP_PBCFG_SW_MINOR_VERSION_C              0
#define I2C_IP_PBCFG_SW_PATCH_VERSION_C              2


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip_PBcfg.h file are of the same vendor */
#if (I2C_IP_PBCFG_VENDOR_ID_C != I2C_IP_PBCFG_VENDOR_ID)
    #error "I2c_Ip_PBcfg.c and I2c_Ip_PBcfg.h have different vendor IDs"
#endif
/* Check if current file and I2c_Ip_PBcfg.h file are of the same module */
#if (I2C_IP_PBCFG_MODULE_ID_C != I2C_IP_PBCFG_MODULE_ID)
    #error "I2c_Ip_PBcfg.c and I2c_Ip_PBcfg.h have different module IDs"
#endif
/* Check if current file and I2c_Ip_PBcfg.h file are of the same Autosar version */
#if ((I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C     != I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C  != I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_PBcfg.c and I2c_Ip_PBcfg.h are different"
#endif
/* Check if current file and I2c_Ip_PBcfg.h file are of the same software version */
#if ((I2C_IP_PBCFG_SW_MAJOR_VERSION_C != I2C_IP_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_IP_PBCFG_SW_MINOR_VERSION_C != I2C_IP_PBCFG_SW_MINOR_VERSION) || \
     (I2C_IP_PBCFG_SW_PATCH_VERSION_C != I2C_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_PBcfg.c and I2c_Ip_PBcfg.h are different"
#endif

#if (I2C_IP_DMA_FEATURE_AVAILABLE == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
            (I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C  != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Dma_Ip.h and I2c_Ip_PBcfg.c are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* I2C_IP_DMA_FEATURE_AVAILABLE */
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/* Channel configuration for channel IIC_4 - configured as master */
const I2c_Ip_MasterConfigType I2c_IICMasterChannel0 =
{
    /* Slave address */
    0U,
    /* Baudrate */
    41U,
    /* Transfer Type */
    I2C_USING_INTERRUPTS,
    /* Dma tx channel */
    (uint8)0U,
    /* Dma rx channel */
    (uint8)0U,
    /* Glitch filter */
    (boolean)FALSE,
    /* Master Callback */
    NULL_PTR,
    /* I2c Master Callback Parameter */
    0,

    /* Master Index */
    0
};



#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

