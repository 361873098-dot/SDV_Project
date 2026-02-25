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

#ifndef I2C_IP_H
#define I2C_IP_H

/**
*     @file
*
*     @addtogroup IIC_DRIVER IIC Driver
*     @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

 /*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I2c_Ip_Cfg.h"
#include "I2c_Ip_Types.h"
#include "I2c_Ip_TrustedMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_MODULE_ID                      255
#define I2C_IP_VENDOR_ID                      43
#define I2C_IP_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IP_AR_RELEASE_MINOR_VERSION       4
#define I2C_IP_AR_RELEASE_REVISION_VERSION    0
#define I2C_IP_SW_MAJOR_VERSION               4
#define I2C_IP_SW_MINOR_VERSION               0
#define I2C_IP_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip_Cfg.h header file are of the same vendor */
#if (I2C_IP_VENDOR_ID != I2C_IP_CFG_VENDOR_ID)
    #error "I2c_Ip.h and I2c_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_Cfg.h header file are of the same module */
#if (I2C_IP_MODULE_ID != I2C_IP_CFG_MODULE_ID)
    #error "I2c_Ip.h and I2c_Ip_Cfg.h have different module ids"
#endif
/* Check if current file and I2c_Ip_Cfg.h header file are of the same Autosar version */
#if ((I2C_IP_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_AR_RELEASE_MINOR_VERSION    != I2C_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_AR_RELEASE_REVISION_VERSION != I2C_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip.h and I2c_Ip_Cfg.h are different"
#endif
/* Check if current file and I2c_Ip_Cfg.h header file are of the same Software version */
#if ((I2C_IP_SW_MAJOR_VERSION != I2C_IP_CFG_SW_MAJOR_VERSION) || \
     (I2C_IP_SW_MINOR_VERSION != I2C_IP_CFG_SW_MINOR_VERSION) || \
     (I2C_IP_SW_PATCH_VERSION != I2C_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip.h and I2c_Ip_Cfg.h are different"
#endif
/* Check if current file and I2c_Ip_Types.h header file are of the same vendor */
#if (I2C_IP_VENDOR_ID != I2C_IP_TYPES_VENDOR_ID)
    #error "I2c_Ip.h and I2c_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_Types.h header file are of the same Autosar version */
#if ((I2C_IP_AR_RELEASE_MAJOR_VERSION    != I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_AR_RELEASE_MINOR_VERSION    != I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_AR_RELEASE_REVISION_VERSION != I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip.h and I2c_Ip_Types.h are different"
#endif
/* Check if current file and I2c_Ip_Types.h header file are of the same Software version */
#if ((I2C_IP_SW_MAJOR_VERSION != I2C_IP_TYPES_SW_MAJOR_VERSION) || \
     (I2C_IP_SW_MINOR_VERSION != I2C_IP_TYPES_SW_MINOR_VERSION) || \
     (I2C_IP_SW_PATCH_VERSION != I2C_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip.h and I2c_Ip_Types.h are different"
#endif
/* Check if current file and I2c_Ip_TrustedMacros.h header file are of the same vendor */
#if (I2C_IP_VENDOR_ID != I2C_IP_TRUSTEDMACROS_VENDOR_ID)
    #error "I2c_Ip.h and I2c_Ip_TrustedMacros.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_TrustedMacros.h header file are of the same Autosar version */
#if ((I2C_IP_AR_RELEASE_MAJOR_VERSION    != I2C_IP_TRUSTEDMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_AR_RELEASE_MINOR_VERSION    != I2C_IP_TRUSTEDMACROS_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_AR_RELEASE_REVISION_VERSION != I2C_IP_TRUSTEDMACROS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip.h and I2c_Ip_TrustedMacros.h are different"
#endif
/* Check if current file and I2c_Ip_TrustedMacros.h header file are of the same Software version */
#if ((I2C_IP_SW_MAJOR_VERSION != I2C_IP_TRUSTEDMACROS_SW_MAJOR_VERSION) || \
     (I2C_IP_SW_MINOR_VERSION != I2C_IP_TRUSTEDMACROS_SW_MINOR_VERSION) || \
     (I2C_IP_SW_PATCH_VERSION != I2C_IP_TRUSTEDMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip.h and I2c_Ip_TrustedMacros.h are different"
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

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/* Master state structure array */
#if(I2C_IP_NUMBER_OF_MASTER_INSTANCES != 0U)
extern I2c_Ip_MasterStateType I2c_Ip_aMasterState[I2C_IP_NUMBER_OF_MASTER_INSTANCES];
#endif

/* Slave state structure array */
#if(I2C_IP_NUMBER_OF_SLAVE_INSTANCES != 0U)
extern I2c_Ip_SlaveStateType I2c_Ip_aSlaveState[I2C_IP_NUMBER_OF_SLAVE_INSTANCES];
#endif

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @note put all I2C code into defined section
*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @brief Initialize the I2C master mode driver
 *
 * This function initializes the I2C driver in master mode.
 *
 * @param Instance      I2C peripheral instance number
 * @param userConfigPtr    Pointer to the I2C master user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterInit_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterInit_Privileged(uint8 Instance,
                                               const I2c_Ip_MasterConfigType * UserConfigPtr);

/*!
 * @brief Initialize the I2C slave mode driver
 *
 * @param Instance      I2C peripheral instance number
 * @param userConfigPtr    Pointer to the I2C slave user configuration structure. The function
 *                         reads configuration data from this structure and initializes the
 *                         driver accordingly. The application may free this structure after
 *                         the function returns.
 * @return    Error or success status returned by API
 * implements I2c_Ip_SlaveInit_Activity
 */
I2c_Ip_StatusType I2c_Ip_SlaveInit_Privileged(uint8 Instance,
                                              const I2c_Ip_SlaveConfigType * UserConfigPtr);

/*!
 * @brief Return the current status of the I2C master transfer
 *
 * This function can be called during a non-blocking transmission to check the
 * status of the transfer.
 *
 * @param Instance  I2C peripheral instance number
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterGetTransferStatus_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterGetTransferStatus(uint8 Instance);

/*!
 * @brief Return the current status of the I2C slave transfer
 *
 * This function can be called during a non-blocking transmission to check the
 * status of the transfer.
 *
 * @param Instance  I2C peripheral instance number
 * @return    Error or success status returned by API
 * implements I2c_Ip_SlaveGetTransferStatus_Activity
 */
I2c_Ip_StatusType I2c_Ip_SlaveGetTransferStatus(uint8 Instance);

/*!
 * @brief De-initialize the I2C master mode driver
 *
 * This function de-initializes the I2C driver in master mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param Instance  I2C peripheral instance number
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterDeinit_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterDeinit_Privileged(uint8 Instance);

/*!
 *@brief Slave module de-initialization function
 * This function de-initializes the I2C driver in slave mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param Instance I2C peripheral instance number
 * @return    Error or success status returned by API
 * implements I2c_Ip_SlaveDeinit_Activity
 */
I2c_Ip_StatusType I2c_Ip_SlaveDeinit_Privileged(uint8 Instance);


/*!
 * @brief Provide a buffer for transmitting data
 *
 * This function provides a buffer from which the I2C slave-mode driver can
 * transmit data. It can be called for example from the user callback provided at
 * initialization time, when the driver reports events I2C_SLAVE_EVENT_TX_REQ or
 * I2C_SLAVE_EVENT_TX_EMPTY.
 *
 * @param Instance  I2C peripheral instance number
 * @param TxBuff      pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @return    Error or success status returned by API
 * implements I2c_Ip_SlaveSetBuffer_Activity
 */
I2c_Ip_StatusType I2c_Ip_SlaveSetBuffer(uint8 Instance,
                                        uint8 *TxBuff,
                                        uint32 TxSize);

/**
* @brief   Makes a slave channel available for processing requests (addressing) in case
*          slave is in not listening mode.
* @details When called, the slave channel becomes available for starting incoming or outgoing transfers.
*
* @param[in] Instance  I2C peripheral instance number
* implements I2c_Ip_StartListening_Activity
*/
void I2c_Ip_StartListening(uint8 Instance);

/*!
 * @brief Perform a non-blocking send transaction on the I2C bus
 *
 * This function starts the transmission of a block of data to the currently
 * configured slave address and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine.
 *
 * @param Instance  I2C peripheral instance number
 * @param TxBuff      pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @param bsendStop    specifies whether or not to generate stop condition after the transmission
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterSendData_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterSendData_Privileged(uint8 Instance,
                                                   const uint8 *TxBuff,
                                                   uint32 TxSize,
                                                   boolean SendStop);

/*!
 * @brief Perform a blocking receive transaction on the I2C bus
 *
 * This function receives a block of data from the currently configured slave address,
 * and only returns when the transmission is complete.
 *
 * @param Instance  I2C peripheral instance number
 * @param RxBuff      pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the reception
 * @param Timeout   timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterReceiveDataBlocking_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterReceiveDataBlocking_Privileged(uint8 Instance,
                                                              uint8 *RxBuff,
                                                              uint32 RxSize,
                                                              boolean SendStop,
                                                              uint32 Timeout);

/*!
 * @brief Perform a blocking send transaction on the I2C bus
 *
 * This function sends a block of data to the currently configured slave address, and
 * only returns when the transmission is complete.
 *
 * @param Instance  I2C peripheral instance number
 * @param TxBuff      pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the transmission
 * @param Timeout   timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterSendDataBlocking_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterSendDataBlocking_Privileged(uint8 Instance,
                                                           const uint8 * TxBuff,
                                                           uint32 TxSize,
                                                           boolean SendStop,
                                                           uint32 Timeout);


/*!
 * @brief Set the slave address for the I2C communication
 *
 * This function sets the slave address which will be used for any future
 * transfer initiated by the I2C master.
 *
 * @param Instance  I2C peripheral instance number
 * @param Address    slave 7-bit address
 * implements I2c_Ip_MasterSetSlaveAddress_Activity
 */
void I2c_Ip_MasterSetSlaveAddress(uint8 Instance,
                                  uint8 Address);

/*!
 * @brief Perform a non-blocking receive transaction on the I2C bus
 *
 * This function starts the reception of a block of data from the currently
 * configured slave address and returns immediately.
 * The rest of the reception is handled by the interrupt service routine.
 *
 * @param Instance  I2C peripheral instance number
 * @param RxBuff      pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @param SendStop    specifies whether or not to generate stop condition after the reception
 * @return    Error or success status returned by API
 * implements I2c_Ip_MasterReceiveData_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterReceiveData_Privileged(uint8 Instance,
                                                      uint8 *RxBuff,
                                                      uint32 RxSize,
                                                      boolean SendStop);


/*!
 * @brief Get the master baud rate for the I2C communication
 *
 * This function returns the master baud rate of the I2C master module.
 *
 * @param Instance    I2C peripheral instance number
 * @param InputClock  I2C input clock in Hz
 * @param BaudRate    calculated baud rate in Hz
 * @return success status returned by the API
 * implements I2c_Ip_MasterGetBaudRate_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterGetBaudRate(uint8 Instance,
                                           uint32 InputClock,
                                           uint32 * BaudRate);

/*!
 * @brief Set the master baud rate for the I2C communication
 *
 * This function sets the master baud rate of the I2C master module.
 *
 * @param Instance  I2C peripheral instance number
 * @param PrescaledShift prescaled shift (mul) value
 * @param PrescalerDivider  prescaler divider value
 * @param ShiftTapPoint shift tap to point value
 * implements I2c_Ip_MasterSetBaudRate_Activity
 */
I2c_Ip_StatusType I2c_Ip_MasterSetBaudRate_Privileged(uint8 Instance,
                                                      uint8 PrescaledShift,
                                                      uint8 PrescalerDivider,
                                                      uint8 ShiftTapPoint);


/**
* @brief   Interrupt handler signature for I2C module.
*
* @return            void
*
*/
extern void I2c_Ip_ModuleIRQHandler_Privileged(uint8 Instance);

/*!
 * @brief Set the master callback
 *
 * This function sets the master callback of the I2C master module.
 *
 * @param Instance  I2C peripheral instance number
 * @param MasterCallback master callback
 * implements I2c_Ip_SetMasterCallback_Activity
 */
void I2c_Ip_SetMasterCallback(uint8 Instance,
                              I2c_Ip_MasterCallbackType MasterCallback);

/*!
 * @brief Set the slave callback
 *
 * This function sets the slave callback of the I2C slave module.
 *
 * @param Instance  I2C peripheral instance number
 * @param SlaveCallback slave callback
 * implements I2c_Ip_SetSlaveCallback_Activity
 */
void I2c_Ip_SetSlaveCallback(uint8 Instance,
                             I2c_Ip_SlaveCallbackType SlaveCallback);

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
#if (I2C_INSTANCE_COUNT >= 1U)
void I2c_Ip_DmaCompleteNotification0(void);
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_DmaErrorNotification0(void);
#endif
#endif /* I2C_INSTANCE_COUNT >= 1U */

#if (I2C_INSTANCE_COUNT >= 2U)
void I2c_Ip_DmaCompleteNotification1(void);
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_DmaErrorNotification1(void);
#endif
#endif /* I2C_INSTANCE_COUNT >= 2U */

#if (I2C_INSTANCE_COUNT >= 3U)
void I2c_Ip_DmaCompleteNotification2(void);
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_DmaErrorNotification2(void);
#endif
#endif /* I2C_INSTANCE_COUNT >= 3U */

#if (I2C_INSTANCE_COUNT >= 4U)
void I2c_Ip_DmaCompleteNotification3(void);
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_DmaErrorNotification3(void);
#endif
#endif /* I2C_INSTANCE_COUNT >= 4U */

#if (I2C_INSTANCE_COUNT >= 5U)
void I2c_Ip_DmaCompleteNotification4(void);
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_DmaErrorNotification4(void);
#endif
#endif /* I2C_INSTANCE_COUNT >= 5U */

#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* I2C_IP_H */

