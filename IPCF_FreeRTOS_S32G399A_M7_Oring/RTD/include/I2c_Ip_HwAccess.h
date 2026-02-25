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

#ifndef I2C_IP_HWACCESS_H
#define I2C_IP_HWACCESS_H

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
#include "I2c_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_HWACCESS_VENDOR_ID                      43
#define I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       4
#define I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define I2C_IP_HWACCESS_SW_MAJOR_VERSION               4
#define I2C_IP_HWACCESS_SW_MINOR_VERSION               0
#define I2C_IP_HWACCESS_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same vendor */
#if (I2C_IP_HWACCESS_VENDOR_ID != I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "I2c_Ip_HwAccess.h and I2c_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_HwAccess.h and I2c_Ip_CfgDefines.h are different"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((I2C_IP_HWACCESS_SW_MAJOR_VERSION != I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2C_IP_HWACCESS_SW_MINOR_VERSION != I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2C_IP_HWACCESS_SW_PATCH_VERSION != I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_HwAccess.h and I2c_Ip_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Prescaled Shift (MUL) Mask */
#define I2C_PRESCALED_SHIFT_MASK                 (0xC0U)
#define I2C_PRESCALED_SHIFT_SHIFT                (6U)

/* Prescaler Divider Mask */
#define I2C_PRESCALER_DIVIDER_MASK               (0x38U)
#define I2C_PRESCALER_DIVIDER_SHIFT              (3U)

/* Shift Tap Point */
#define I2C_SHIFT_TAP_POINT_MASK                 (0x07U)
#define ENABLE_BIT(x)                            ((uint8)((TRUE == x)?1U:0U))

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/** I2C - Register Layout Typedef */
/*! @brief I2C module types
 * Implements : i2c_module_type_Class
 */
typedef enum
{
    I2C_SLAVE =  0,             /**<  The I2C module is in slave mode >*/
    I2C_MASTER = 1,             /**<  The I2C module is in master mode >*/
}I2c_Ip_ModuleType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/*!
 * @brief Enable or disable the I2C module.
 *
 * This function enables or disables the I2C module.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  specifies whether to enable or disable the I2C Bus module
 */
static inline void I2c_Ip_SetModuleEnable(I2C_Type *BaseAddr,
                                        boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_MDIS_MASK));
    RegValue |= I2C_IBCR_MDIS(ENABLE_BIT(!Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Enable or disable the I2C Bus module interrupts.
 *
 * This function enables or disables the I2C Bus Interrupts.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  specifies whether to enable or disable the I2C Bus interrupts
 */
static inline void I2c_Ip_SetBusIRQEnable(I2C_Type *BaseAddr,
                                        boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_IBIE_MASK));
    RegValue |= I2C_IBCR_IBIE(ENABLE_BIT(Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Master/Slave module select.
 *
 * When the MSSL bit is changed from from 0 to 1 master mode
 * is selected.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable Master/Slave select
 */
static inline void I2c_Ip_SetModuleModSelect(I2C_Type *BaseAddr,
                                           I2c_Ip_ModuleType ModuleType)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_MSSL_MASK));
    RegValue |= I2C_IBCR_MSSL(ModuleType);
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Master/Slave module select.
 *
 * When the MSSL bit is changed from from 0 to 1 master mode
 * is selected.
 *
 * @param BaseAddr  base address of the I2C module
 * @return module mode of operation (master or slave)
 */
static inline boolean I2c_Ip_GetModuleModSelect(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBCR_MSSL_MASK == ((uint8)BaseAddr->IBCR & I2C_IBCR_MSSL_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Transmit/Receive mode select.
 *
 * This function enable the transmitting or receiving mode.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  0 for receive and 1 for transmit
 */
static inline void I2c_Ip_SetModuleTransmitMode(I2C_Type *BaseAddr,
                                              boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_TXRX_MASK));
    RegValue |= I2C_IBCR_TXRX(ENABLE_BIT(Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Get transmit/receive mode select.
 *
 * This function enable the transmitting or receiving mode.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  0 for receive and 1 for transmit
 */

static inline boolean I2c_Ip_GetModuleTransmitMode(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBCR_TXRX_MASK == ((uint8) BaseAddr->IBCR & I2C_IBCR_TXRX_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Enable/Disable glitch filter.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  specifies whether to enable or disable the glitch filter
 * for the i2c instance
 */
static inline void I2c_Ip_SetGlitchFilter(I2C_Type *BaseAddr,
                                        boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBDBG;

    RegValue &= (uint8)(~I2C_IBDBG_GLFLT_EN_MASK);
    RegValue |= I2C_IBDBG_GLFLT_EN(ENABLE_BIT(Enable));
    BaseAddr->IBDBG = (uint8)RegValue;
}

/*!
 * @brief Checks glitch filter bit.
 *
 * @param BaseAddr  base address of the I2C module
 */
static inline boolean I2c_Ip_GetGlitchFilter(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBDBG_GLFLT_EN_MASK == ((uint8) BaseAddr->IBDBG & I2C_IBDBG_GLFLT_EN_MASK))?TRUE:FALSE);

    return RetValue;
}

/*!
 * @brief Data acknowledge mode select.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  specifies whether to enable or disable the I2C acknowledge signal
 * for both master and slave
 */
static inline void I2c_Ip_SetDataAcknowledge(I2C_Type *BaseAddr,
                                           boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_NOACK_MASK));
    RegValue |= I2C_IBCR_NOACK(ENABLE_BIT(!Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief DMA TX/RX request signals enable.
 *
 *This function will enable or disable the DMA TX/RX request signals.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable  specifies whether to enable or disable the DMA Tx/RX request signals
 * for both data and slave
 */
static inline void I2c_Ip_SetDMAEnable(I2C_Type *BaseAddr,
                                     boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_DMAEN_MASK));
    RegValue |= I2C_IBCR_DMAEN(ENABLE_BIT(Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Generate repeat start cycle.
 *
 * This function will generate a repeat start condition on the bus.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable generate a repeated START condition on the bus if the
 * module is in master mode
 */
static inline void I2c_Ip_SetRepeatStart(I2C_Type *BaseAddr,
                                       boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBCR;

    RegValue &= (uint8) (~(I2C_IBCR_RSTA_MASK));
    RegValue |= I2C_IBCR_RSTA(ENABLE_BIT(Enable));
    BaseAddr->IBCR = (uint8) RegValue;
}

/*!
 * @brief Check if the module is addressed as slave.
 *
 * @param BaseAddr  base address of the I2C module
 */
static inline boolean I2c_Ip_GetAddressAsSlave(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_IAAS_MASK == ((uint8) BaseAddr->IBSR & I2C_IBSR_IAAS_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Return the idle/busy state of the I2C bus
 *
 * This function returns true if the I2C bus is busy and false if the bus is idle.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  the idle/busy state of the I2C bus
 */
static inline boolean I2c_Ip_GetBusBusyEvent(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_IBB_MASK == ((uint8)BaseAddr->IBSR & I2C_IBSR_IBB_MASK))?TRUE:FALSE);

    return (boolean) RetValue;
}

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
/*!
 * @brief Check the occurrence of an arbitration lost event
 *
 * This function returns true if the I2C master detects an arbitration lost
 * condition, as defined by the I2C standard.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  indication of an arbitration lost event
 */
static inline boolean I2c_Ip_GetMasterArbitrationLostEvent(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_IBAL_MASK == ((uint8) BaseAddr->IBSR & I2C_IBSR_IBAL_MASK))?TRUE:FALSE);

    return  RetValue;
}
#endif

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
/*!
 * @brief Clear the occurrence of an arbitration lost event
 *
 * This function clears the arbitration lost flag.
 *
 * @param BaseAddr  base address of the I2C module
 */
static inline void I2c_Ip_ClearMasterArbitrationLostFlag(I2C_Type *BaseAddr)
{
    BaseAddr->IBSR = I2C_IBSR_IBAL(1) | I2C_IBSR_IBIF(0);
}
#endif

/*!
 * @brief Check if the slave is transmit or receive mode.
 *
 * This function returns TRUE if the I2C is in transmitting mode
 * and false if the slave is in receive mode.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  indication that slave is in transmitting mode
 */
static inline boolean I2c_Ip_GetSlaveTransmitMode(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_SRW_MASK == ((uint8) BaseAddr->IBSR & I2C_IBSR_SRW_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Check if acknowledge received.
 *
 * This function verify if a acknowledge bit is received.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  true if acknowledge signal is received.
 */
static inline boolean I2c_Ip_GetReceivedACK(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = !((boolean)((I2C_IBSR_RXAK_MASK == ((uint8)BaseAddr->IBSR & I2C_IBSR_RXAK_MASK))?TRUE:FALSE));

    return RetValue;
}

/*!
 * @brief Clear the I-Bus interrupt flag.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable a true value will clear the I-Bus Interruption flag
 */
static inline void I2c_Ip_ClearBusInterruptFlag(I2C_Type *BaseAddr)
{
    BaseAddr->IBSR = I2C_IBSR_IBIF(1);
}


/*!
 * @brief Read the I-Bus interrupt flag.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  true if interrupt flag is set
 */
static inline boolean I2c_Ip_GetBusInterruptFlag(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_IBIF_MASK == ((uint8)BaseAddr->IBSR & I2C_IBSR_IBIF_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Return the received data
 *
 * This function returns data received by the I2C module after
 * an address match occurred.
 *
 * @param BaseAddr  base address of the I2C module
 * @return  data received by the I2C module
 */
static inline uint8 I2c_Ip_GetDataIBDR(const I2C_Type *BaseAddr)
{
    uint8 RegValue = BaseAddr->IBDR;

    RegValue = (RegValue & I2C_IBDR_DATA_MASK) >> I2C_IBDR_DATA_SHIFT;

    return (uint8) RegValue;
}


/*!
 * @brief Return the value of the transfer complete flag
 *
 * This function returns the value of the transfer complete flag
 *
 * @param BaseAddr  base address of the I2C module
 * @return true if transfer is completed, false if transfer is in progress
 */
static inline boolean I2c_Ip_GetTCF(const I2C_Type *BaseAddr)
{
    boolean RetValue;

    RetValue = (boolean)((I2C_IBSR_TCF_MASK == ((uint8)BaseAddr->IBSR & I2C_IBSR_TCF_MASK))?TRUE:FALSE);

    return  RetValue;
}

/*!
 * @brief Write data which will be transmitted in master or slave mode.
 *
 * This function transmits data in both master and slave mode.
 *
 * @param BaseAddr  base address of the I2C module
 * @param  Data to be send
 */
static inline void I2c_Ip_SetDataIBDR(I2C_Type *BaseAddr,
                                    uint8 Data)
{
    BaseAddr->IBDR = (uint8) Data;
}

/*IBIC Interrupt config register*/

/*!
 * @brief Enable/Disable Bus Idle Interrupt.
 *
 * This function can be used to enable generation of an interrupt once the
 * I2C Bus becomes idle.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Enable a true value will enable the Bus Idle Interrupt
 */
static inline void I2c_Ip_SetBusIdleIRQ(I2C_Type *BaseAddr,
                                      boolean Enable)
{
    uint8 RegValue = (uint8) BaseAddr->IBIC;

    RegValue &= (uint8) (~(I2C_IBIC_BIIE_MASK));
    RegValue |= I2C_IBIC_BIIE(ENABLE_BIT(Enable));
    BaseAddr->IBIC = (uint8) RegValue;
}

/*!
 * @brief Set slave address for I2C module.
 *
 * @param BaseAddr  base address of the I2C module
 * @param Data  address for slave
 */
static inline void I2c_Ip_SetSlaveAddress(I2C_Type *BaseAddr,
                                        uint8 Data)
{
    uint8 RegValue = (uint8) BaseAddr->IBAD;

    RegValue &= (uint8) (~(I2C_IBAD_ADR_MASK));
    RegValue |= I2C_IBAD_ADR(Data);
    BaseAddr->IBAD = (uint8) RegValue;
}

/*!
 * @brief Reset Module State
 *
 * This function reset the value of I2C Bus Control register and
 * the value of I2C Bus Interrupt Configuration Register.
 *
 * @param BaseAddr  base address of the I2C module
 */
static inline void I2c_Ip_ResetModuleState(I2C_Type *BaseAddr)
{
    /* Reset the I2C Bus Control Register values */
    BaseAddr->IBCR = 0x80;

    /* Reset the I2C Bus Interrupt Configuration Register */
    BaseAddr->IBIC = 0x00;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IP_HWACCESS_H */

