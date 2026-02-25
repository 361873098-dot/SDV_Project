/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IIC
*   Dependencies         : MCU,PORT,DET,RTE
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   Copyright 2020-2023 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef I2C_IP_CALLBACKS_H
#define I2C_IP_CALLBACKS_H

/**
*     @file
*
*     @addtogroup IIC_DRIVER IIC Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_CALLBACKS_VENDOR_ID                      43
#define I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION       4
#define I2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION    0
#define I2C_IP_CALLBACKS_SW_MAJOR_VERSION               4
#define I2C_IP_CALLBACKS_SW_MINOR_VERSION               0
#define I2C_IP_CALLBACKS_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

 /*!
 * @brief Define the enum of the events which can trigger I2C slave callback
 *
 * This enum should include the events for all platforms
 * implements I2c_Ip_SlaveEventType_enum
 */
typedef enum
{
    I2C_SLAVE_EVENT_ERROR_BIT = 0x00U,
    I2C_SLAVE_EVENT_UNDERRUN = 0x01U,
    I2C_SLAVE_EVENT_OVERRUN = 0x02U,
    I2C_SLAVE_EVENT_RX_FULL = 0x03U,
    I2C_SLAVE_EVENT_TX_EMPTY = 0x04U,
    I2C_SLAVE_EVENT_TX_REQ = 0x05U,
    I2C_SLAVE_EVENT_RX_REQ = 0x06U,
    I2C_SLAVE_EVENT_STOP = 0X07U
}I2c_Ip_SlaveEventType;

 /*!
 * @brief Define the enum of the events which can trigger I2C master callback
 *
 * This enum should include the events for all platforms
 * implements I2c_Ip_MasterEventType_enum
 */
typedef enum
{
    I2C_MASTER_EVENT_NACK                              = 0x08U,
    I2C_MASTER_EVENT_ARBITRATION_LOST                  = 0x09U,
    I2C_MASTER_EVENT_END_TRANSFER                      = 0x0BU,
    I2C_MASTER_EVENT_DMA_TRANSFER_ERROR                = 0x0CU
}I2c_Ip_MasterEventType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Callback for all peripherals which supports I2C features for slave mode */
/* implements I2c_Ip_SlaveCallbackType_typedef */
typedef void (*I2c_Ip_SlaveCallbackType)(I2c_Ip_SlaveEventType Event,
                                         uint8 UserData);

/* Callback for all peripherals which supports I2C features for master mode */
/* implements I2c_Ip_MasterCallbackType_typedef */
typedef void (*I2c_Ip_MasterCallbackType)(I2c_Ip_MasterEventType Event,
                                          uint8 UserData);

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IP_CALLBACKS_H */

