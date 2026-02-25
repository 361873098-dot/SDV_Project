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

#ifndef I2C_IPW_H
#define I2C_IPW_H

/**
*     @file
*
*     @addtogroup I2C_DRIVER I2c Driver
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
#include "CDD_I2c.h"
#include "I2c_Ip.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IPW_VENDOR_ID                     43
#define I2C_IPW_MODULE_ID                     255
#define I2C_IPW_AR_RELEASE_MAJOR_VERSION      4
#define I2C_IPW_AR_RELEASE_MINOR_VERSION      4
#define I2C_IPW_AR_RELEASE_REVISION_VERSION   0
#define I2C_IPW_SW_MAJOR_VERSION              4
#define I2C_IPW_SW_MINOR_VERSION              0
#define I2C_IPW_SW_PATCH_VERSION              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c.h header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID != I2C_VENDOR_ID)
    #error "I2c_Ipw.h and CDD_I2c.h have different vendor ids"
#endif

/* Check if current file and CDD_I2c.h header file are of the same module */
#if (I2C_IPW_MODULE_ID != I2C_MODULE_ID)
    #error "I2c_Ipw.h and CDD_I2c.h have different module ids"
#endif

/* Check if current file and CDD_I2c.h header file are of the same Autosar version */
#if ((I2C_IPW_AR_RELEASE_MAJOR_VERSION    != I2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IPW_AR_RELEASE_MINOR_VERSION    != I2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IPW_AR_RELEASE_REVISION_VERSION != I2C_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ipw.h and CDD_I2c.h are different"
#endif

/* Check if current file and CDD_I2c.h header file are of the same Software version */
#if ((I2C_IPW_SW_MAJOR_VERSION != I2C_SW_MAJOR_VERSION) || \
     (I2C_IPW_SW_MINOR_VERSION != I2C_SW_MINOR_VERSION) || \
     (I2C_IPW_SW_PATCH_VERSION != I2C_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ipw.h and CDD_I2c.h are different"
#endif

/* Check if current file and I2c_Ip.h header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID != I2C_IP_VENDOR_ID)
    #error "I2c_Ipw.h and I2c_Ip.h have different vendor ids"
#endif

/* Check if current file and I2c_Ip.h header file are of the same module */
#if (I2C_IPW_MODULE_ID != I2C_IP_MODULE_ID)
    #error "I2c_Ipw.h and I2c_Ip.h have different module ids"
#endif

/* Check if current file and I2c_Ip.h header file are of the same Autosar version */
#if ((I2C_IPW_AR_RELEASE_MAJOR_VERSION    != I2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IPW_AR_RELEASE_MINOR_VERSION    != I2C_IP_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IPW_AR_RELEASE_REVISION_VERSION != I2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ipw.h and I2c_Ip.h are different"
#endif

/* Check if current file and I2c_Ip.h header file are of the same Software version */
#if ((I2C_IPW_SW_MAJOR_VERSION != I2C_IP_SW_MAJOR_VERSION) || \
     (I2C_IPW_SW_MINOR_VERSION != I2C_IP_SW_MINOR_VERSION) || \
     (I2C_IPW_SW_PATCH_VERSION != I2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ipw.h and I2c_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if ((I2C_IPW_AR_RELEASE_MAJOR_VERSION    != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (I2C_IPW_AR_RELEASE_MINOR_VERSION    != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of I2c_Ipw.h and Dem.h are different"
        #endif
    #endif
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

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

void I2c_Ipw_SlaveCallback(I2c_Ip_SlaveEventType Event, uint8 UserData);

void I2c_Ipw_MasterCallback(I2c_Ip_MasterEventType Event, uint8 UserData);

void I2c_Ipw_InitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr);

I2c_StatusType I2c_Ipw_GetStatus(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr);

void I2c_Ipw_DeInitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr);

void  I2c_Ipw_PrepareSlaveBuffer(uint8 Channel, uint8 NumberOfBytes, I2c_DataType * DataBuffer);

Std_ReturnType I2c_Ipw_AsyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType);

Std_ReturnType I2c_Ipw_SyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType);

void I2c_Ipw_StartListening(uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IPW_H */
