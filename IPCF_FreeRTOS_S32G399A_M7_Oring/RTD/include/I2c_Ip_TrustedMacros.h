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

#ifndef I2C_IP_TRUSTEDMACROS_H
#define I2C_IP_TRUSTEDMACROS_H

/**
*     @file
*
*     @addtogroup IIC_DRIVER IIC Driver
*     @{
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
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_TRUSTEDMACROS_VENDOR_ID                    43
#define I2C_IP_TRUSTEDMACROS_MODULE_ID                    255
#define I2C_IP_TRUSTEDMACROS_AR_RELEASE_MAJOR_VERSION     4
#define I2C_IP_TRUSTEDMACROS_AR_RELEASE_MINOR_VERSION     4
#define I2C_IP_TRUSTEDMACROS_AR_RELEASE_REVISION_VERSION  0
#define I2C_IP_TRUSTEDMACROS_SW_MAJOR_VERSION             4
#define I2C_IP_TRUSTEDMACROS_SW_MINOR_VERSION             0
#define I2C_IP_TRUSTEDMACROS_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Osif header file are of the same Autosar version */
    #if ((I2C_IP_TRUSTEDMACROS_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_IP_TRUSTEDMACROS_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of I2c_Ip_TrustedMacros.h and Osif.h are different"
    #endif
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

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterInit(Instance, UserConfigPtr) \
    OsIf_Trusted_Call_Return2param(I2c_Ip_MasterInit_Privileged, (Instance), (UserConfigPtr))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterInit(Instance, UserConfigPtr) \
    I2c_Ip_MasterInit_Privileged(Instance, UserConfigPtr)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_SlaveInit(Instance, UserConfigPtr) \
    OsIf_Trusted_Call_Return2param(I2c_Ip_SlaveInit_Privileged, (Instance), (UserConfigPtr))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_SlaveInit(Instance, UserConfigPtr) \
    I2c_Ip_SlaveInit_Privileged(Instance, UserConfigPtr)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterDeinit(Instance) \
    OsIf_Trusted_Call_Return1param(I2c_Ip_MasterDeinit_Privileged,(Instance))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterDeinit(Instance) \
    I2c_Ip_MasterDeinit_Privileged(Instance)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_SlaveDeinit(Instance) \
    OsIf_Trusted_Call_Return1param(I2c_Ip_SlaveDeinit_Privileged,(Instance))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_SlaveDeinit(Instance) \
    I2c_Ip_SlaveDeinit_Privileged(Instance)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSendData(Instance, TxBuff, TxSize, SendStop) \
    OsIf_Trusted_Call_Return4param(I2c_Ip_MasterSendData_Privileged,(Instance), (TxBuff), (TxSize), (SendStop))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSendData(Instance, TxBuff, TxSize, SendStop) \
    I2c_Ip_MasterSendData_Privileged(Instance, TxBuff, TxSize, SendStop)
#endif



#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterReceiveDataBlocking(Instance, RxBuff, RxSize, SendStop, Timeout) \
    OsIf_Trusted_Call_Return5param(I2c_Ip_MasterReceiveDataBlocking_Privileged,(Instance), (RxBuff), (RxSize), (SendStop), (Timeout))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterReceiveDataBlocking(Instance, RxBuff, RxSize, SendStop, Timeout) \
    I2c_Ip_MasterReceiveDataBlocking_Privileged(Instance, RxBuff, RxSize, SendStop, Timeout)
#endif



#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSendDataBlocking(Instance, TxBuff, TxSize, SendStop, Timeout) \
    OsIf_Trusted_Call_Return5param(I2c_Ip_MasterSendDataBlocking_Privileged, (Instance), (TxBuff), (TxSize), (SendStop), (Timeout))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSendDataBlocking(Instance, TxBuff, TxSize, SendStop, Timeout) \
    I2c_Ip_MasterSendDataBlocking_Privileged(Instance, TxBuff, TxSize, SendStop, Timeout)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterReceiveData(Instance, RxBuff, RxSize, SendStop) \
    OsIf_Trusted_Call_Return4param(I2c_Ip_MasterReceiveData_Privileged,(Instance), (RxBuff), (RxSize), (SendStop))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterReceiveData(Instance, RxBuff, RxSize, SendStop) \
    I2c_Ip_MasterReceiveData_Privileged(Instance, RxBuff, RxSize, SendStop)
#endif



#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSetBaudRate(Instance, PrescaledShift, PrescalerDivider, ShiftTapPoint) \
    OsIf_Trusted_Call_Return4param(I2c_Ip_MasterSetBaudRate_Privileged,(Instance), (PrescaledShift), (PrescalerDivider), (ShiftTapPoint))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_MasterSetBaudRate(Instance, PrescaledShift, PrescalerDivider, ShiftTapPoint) \
    I2c_Ip_MasterSetBaudRate_Privileged(Instance, PrescaledShift, PrescalerDivider, ShiftTapPoint)
#endif


#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_ModuleIRQHandler(Instance) \
    OsIf_Trusted_Call1param(I2c_Ip_ModuleIRQHandler_Privileged,(Instance))
#else
/**
* @violates @ref I2c_Ip_TrustedMacros_h_REF_6 A function should be used in preference to a function-like macro
* where they are interchangeable.
*/
#define  I2c_Ip_ModuleIRQHandler(Instance) \
    I2c_Ip_ModuleIRQHandler_Privileged(Instance)
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IP_TRUSTEDMACROS_H */

