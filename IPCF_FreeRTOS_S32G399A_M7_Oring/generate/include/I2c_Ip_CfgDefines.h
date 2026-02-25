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

#ifndef I2C_IP_CFGDEFINES_H
#define I2C_IP_CFGDEFINES_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "S32G399A_I2C.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_CFGDEFINES_VENDOR_ID                       43
#define I2C_IP_CFGDEFINES_MODULE_ID                       255
#define I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION        4
#define I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define I2C_IP_CFGDEFINES_SW_MAJOR_VERSION                4
#define I2C_IP_CFGDEFINES_SW_MINOR_VERSION                0
#define I2C_IP_CFGDEFINES_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define I2C_IP_NUMBER_OF_MASTER_INSTANCES 1U
#define I2C_IP_NUMBER_OF_SLAVE_INSTANCES 0U

/**
* @brief Define size of MUL array
*/
#define I2C_MUL_ARRAY_SIZE 3U

/**
* @brief Define MUL array
*/
#define I2C_MUL_ARRAY    {1U, 2U, 4U}

/**
* @brief Define size of divider array
*/
#define I2C_DIVIDER_ARRAY_SIZE  8U

/**
* @brief Define SCL2TAP array
*/
#define I2C_SCL2TAP_ARRAY          {4U, 4U, 6U, 6U, 14U, 30U, 62U, 126U}

/**
* @brief Define SCL2TAP array when glitch filter is enabled
*/
#define I2C_SCL2TAP_GLITCH_ARRAY   {11U, 12U, 14U, 14U, 14U, 30U, 62U, 126U}

/**
* @brief Define SCLTAP array
*/
#define I2C_SCLTAP_ARRAY           {5U, 6U, 7U, 8U, 9U, 10U, 12U, 15U}

/**
* @brief Define TAP2TAP array
*/
#define I2C_TAP2TAP_ARRAY          {1U, 2U, 4U, 8U, 16U, 32U, 64U, 128U}


/**
* @brief            Development error detection for IP layer
*/
#define I2C_IP_DEV_ERROR_DETECT   STD_ON

/**
* @brief            Dma transfer error of the i2c module enable/disabled
*/
#define I2C_IP_DMA_TRANSFER_ERROR_DETECT   STD_OFF

/**
* @brief            Events error detection for IP layer
*/
#define I2C_IP_EVENT_ERROR_DETECT   STD_OFF

/**
* @brief            Dma support enable/disabled
*/
#define I2C_IP_DMA_FEATURE_AVAILABLE    STD_OFF
/**
* @brief            Enable User Mode Support.
*/
#define I2C_ENABLE_USER_MODE_SUPPORT    STD_OFF
/**
* @brief            I2c timeout type
*/
#define I2C_TIMEOUT_TYPE    OSIF_COUNTER_DUMMY

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running I2C in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT macro needs to be defined.
  #endif /* (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /* I2C_IP_CFGDEFINES_H */

