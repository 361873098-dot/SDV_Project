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

#ifndef I2C_IP_IRQ_H
#define I2C_IP_IRQ_H

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
#include "OsIf.h"
#include "I2c_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_IRQ_VENDOR_ID                      43
#define I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION       4
#define I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define I2C_IP_IRQ_SW_MAJOR_VERSION               4
#define I2C_IP_IRQ_SW_MINOR_VERSION               0
#define I2C_IP_IRQ_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION  != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf.h and I2c_Ip_Irq.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same vendor */
#if (I2C_IP_IRQ_VENDOR_ID != I2C_IP_CFGDEFINES_VENDOR_ID)
    #error "I2c_Ip_Irq.h and I2c_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Autosar version */
#if ((I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION    != I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION != I2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ip_Irq.h and I2c_Ip_CfgDefines.h are different"
#endif
/* Check if current file and I2c_Ip_CfgDefines.h header file are of the same Software version */
#if ((I2C_IP_IRQ_SW_MAJOR_VERSION != I2C_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2C_IP_IRQ_SW_MINOR_VERSION != I2C_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2C_IP_IRQ_SW_PATCH_VERSION != I2C_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_Irq.h and I2c_Ip_CfgDefines.h are different"
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

#if (I2C_INSTANCE_COUNT >= 1U)
ISR(I2c_Ip_IRQHandler0);
#endif

#if (I2C_INSTANCE_COUNT >= 2U)
ISR(I2c_Ip_IRQHandler1);
#endif

#if (I2C_INSTANCE_COUNT >= 3U)
ISR(I2c_Ip_IRQHandler2);
#endif

#if (I2C_INSTANCE_COUNT >= 4U)
ISR(I2c_Ip_IRQHandler3);
#endif

#if (I2C_INSTANCE_COUNT >= 5U)
ISR(I2c_Ip_IRQHandler4);
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I2C_IP_IRQ_H */

