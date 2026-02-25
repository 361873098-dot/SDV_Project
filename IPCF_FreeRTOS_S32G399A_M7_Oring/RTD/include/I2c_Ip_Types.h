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
#ifndef I2C_IP_TYPES_H
#define I2C_IP_TYPES_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "I2c_Ip_Callbacks.h"
#include "I2c_Ip_CfgDefines.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_TYPES_VENDOR_ID                      43
#define I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION       4
#define I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define I2C_IP_TYPES_SW_MAJOR_VERSION               4
#define I2C_IP_TYPES_SW_MINOR_VERSION               0
#define I2C_IP_TYPES_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION  != STD_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of I2c_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and I2c_Ip_Callbacks.h header file are of the same vendor */
#if (I2C_IP_TYPES_VENDOR_ID != I2C_IP_CALLBACKS_VENDOR_ID)
    #error "I2c_Ip_Types.h and I2c_Ip_Callbacks.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_Callbacks.h header file are of the same Autosar version */
#if ((I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != I2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_Types.h and I2c_Ip_Callbacks.h are different"
#endif
/* Check if current file and I2c_Ip_Callbacks.h header file are of the same Software version */
#if ((I2C_IP_TYPES_SW_MAJOR_VERSION != I2C_IP_CALLBACKS_SW_MAJOR_VERSION) || \
     (I2C_IP_TYPES_SW_MINOR_VERSION != I2C_IP_CALLBACKS_SW_MINOR_VERSION) || \
     (I2C_IP_TYPES_SW_PATCH_VERSION != I2C_IP_CALLBACKS_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_Types.h and I2c_Ip_Callbacks.h are different"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same vendor */
#if (I2C_IP_TYPES_VENDOR_ID != I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "I2c_Ip_Types.h and I2c_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION != I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_Types.h and I2c_Ip_CfgDefines.h are different"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((I2C_IP_TYPES_SW_MAJOR_VERSION != I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2C_IP_TYPES_SW_MINOR_VERSION != I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2C_IP_TYPES_SW_PATCH_VERSION != I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_Types.h and I2c_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

typedef enum
{
    /* I2C specific error codes */
    I2C_IP_SUCCESS_STATUS                     = 0x000U,  /**<  Status success */
    I2C_IP_ERROR_STATUS                       = 0x001U,  /**<  Error occurred, transfer was not successful */
    I2C_IP_BUSY_STATUS                        = 0x002U,  /**<  I2c module is busy, transfer is in progress */
    I2C_IP_TIMEOUT_STATUS                     = 0x003U,  /**<  Timeout occurred */
    I2C_IP_RECEIVED_NACK_STATUS               = 0x004U,  /**<  NACK signal received  */
    I2C_IP_TX_UNDERRUN_STATUS                 = 0x005U,  /**<  TX underrun error */
    I2C_IP_RX_OVERRUN_STATUS                  = 0x006U,  /**<  RX overrun error */
    I2C_IP_ARBITRATION_LOST_STATUS            = 0x007U,  /**<  Arbitration lost */
#if ((STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE) && (STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT))
    I2C_IP_DMA_ERROR_STATUS                   = 0x008U,  /**<  Error occurred on dma transfer, the transfer was not successful */
#endif
    I2C_IP_BUS_BUSY_STATUS                    = 0x009U   /**<  I2C bus is busy, cannot start transfer */
}I2c_Ip_StatusType;


/*! @brief Type of I2C transfer (based on interrupts or DMA).
 * implements I2c_Ip_TransferType_enum
 */
typedef enum
{
   I2C_USING_DMA         = 0,    /**<  The driver will use DMA to perform I2C transfer */
   I2C_USING_INTERRUPTS  = 1,    /**<  The driver will use interrupts to perform I2C transfer */
}  I2c_Ip_TransferType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief Slave internal context structure
 *
 * This structure is used by the slave-mode driver for its internal logic. It must
 * be provided by the application through the I2C_DRV_SlaveInit() function.
 * The application should make no assumptions about the content of this structure.
 *
 * Implements: i2c_slave_state_t_Class
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    I2c_Ip_StatusType Status;                        /* The I2C slave status */
    volatile boolean TransferInProgress;             /* Slave is busy because of an ongoing transfer */
    boolean ListeningMode;                           /* Specifies if slave is in listening mode */
    boolean ReadyForAddressing;                      /* Specifies if slave is ready for addressing */
    uint32 BufferSize;                               /* Size of the TX buffer */
    uint8 * DataBuffer;                              /* Pointer to tx/rx Buffer */
    uint8 SlaveAddress;                              /* Slave address */
    boolean TxUnderrunWarning;                       /* Possible slave tx underrun */
    boolean DataAck;                                 /* Data acknowledge enable or disable */
    boolean GlitchFilter;                            /* Specifies if glitch filter is enabled */
    I2c_Ip_SlaveCallbackType SlaveCallback;          /* Slave callback function */
    uint8 CallbackParam;                             /* Parameter for the slave callback function */
/*! @endcond */
} I2c_Ip_SlaveStateType;

/*!
 * @brief Slave configuration structure
 *
 * This structure is used to provide configuration parameters for the I2C slave at initialization time.
 * implements I2c_Ip_SlaveConfigType_struct
 */
typedef struct
{
    uint8 SlaveAddress;                        /**<  7 bit slave address */
    boolean ListeningMode;                     /* Specifies if slave is in listening mode */
    boolean GlitchFilter;                      /**<  Specifies if glitch filter is enabled */
    I2c_Ip_SlaveCallbackType SlaveCallback;    /**<  Slave callback function */
    uint8 CallbackParam;                       /**<  Parameter for the slave callback function */
    uint8 SlaveIndex;                          /**<  Slave Index */
} I2c_Ip_SlaveConfigType;

/*!
 * @brief Master internal context structure
 *
 * This structure is used by the master-mode driver for its internal logic. It must
 * be provided by the application through the I2C_DRV_MasterInit() function.
 * The application should make no assumptions about the content of this structure.
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */

    uint8 * RxBuff;                            /* Pointer to receive data buffer */
    uint32 RxSize;                             /* Size of receive data buffer */
    const uint8 * TxBuff;                      /* Pointer to transmit data buffer */
    boolean Blocking;                          /* Specifies if the transfer is blocking */
    uint32 TxSize;                             /* Size of transmit data buffer */
    volatile I2c_Ip_StatusType Status;         /* Status of last driver operation */
    uint8 SlaveAddress;                        /* Slave address */
    volatile boolean I2cIdle;                  /* Idle/busy state of the driver */
    boolean SendStop;                          /* Specifies if STOP condition must be generated after current transfer */
    I2c_Ip_TransferType TransferType;          /* Type of I2C transfer */
    uint8 DmaTxChannel;                        /* Dma tx logic channel number  */
    uint8 DmaRxChannel;                        /* Dma rx logic channel number */
    boolean SendData;                          /* Master is in transmitting or receive mode*/
    boolean StopGenerated;                     /* Specifies if stop was generated for the previous transfer */
    boolean GlitchFilter;                      /* Specifies if glitch filter is enabled */
    I2c_Ip_MasterCallbackType MasterCallback;  /* Master callback function */
    uint8 CallbackParam;                       /* Parameter for the master callback function */
/*! @endcond */
} I2c_Ip_MasterStateType;

/*!
 * @brief Master configuration structure
 *
 * This structure is used to provide configuration parameters for the I2C master at initialization time.
 * implements I2c_Ip_MasterConfigType_struct
 */
typedef struct
{
    uint8 SlaveAddress;                         /**<  Slave address, 7-bit */
    uint8 BaudRate;                             /**<  Value of IBFD register */
    I2c_Ip_TransferType TransferType;           /**<  Type of I2C transfer */
    uint8 DmaTxChannel;                         /**<  Dma logic Tx channel number. If DMA mode isn't used this field will be ignored */
    uint8 DmaRxChannel;                         /**<  Dma logic Rx channel number. If DMA mode isn't used this field will be ignored */
    boolean GlitchFilter;                       /**<  Specifies if glitch filter is enabled */
    I2c_Ip_MasterCallbackType MasterCallback;   /**<  Master callback function. Note that this function will be
                                                 called from the interrupt service routine at the end of a transfer,
                                                 so its execution time should be as small as possible. It can be
                                                 NULL if you want to check manually the status of the transfer. */
    uint8 CallbackParam;                        /**<  Parameter for the master callback function */
    uint8 MasterIndex;                          /**<  Master Index */
} I2c_Ip_MasterConfigType;

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

#endif /* I2C_IP_TYPES_H */

