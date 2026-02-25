/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
*   Dependencies         : none
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

#ifndef SIUL2_PORT_IP_DEFINES
#define SIUL2_PORT_IP_DEFINES

/**
*   @file    Siul2_Port_Ip_Defines.h
*
*   @addtogroup Port_CFG
*   @{
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
#include "S32G399A_SIUL2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_DEFINES_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H        4
#define SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H                4
#define SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H                0
#define SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H                2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Number of SIUL2 instances present on the subderivative
*/
#define SIUL2_NUM_SIUL2_INSTANCES_U8 (2)

/**
* @brief Macros defined for the SIUL2 IPV that are protected.
*/
#define MCAL_SIUL2_REG_PROT_AVAILABLE   (STD_ON)
/**
* @brief Macros defined for the protection size
*/
#define SIUL2_PROT_MEM_U32    ((uint32)0x00000008UL)

/**
* @brief Support for User mode.
* If this parameter has been configured to STD_ON, the PORT driver code can be executed from both supervisor and user mode.
*/
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef PORT_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/* Pre-processor switch to enable/disable development error detection for Siul2 Ip API */
#define SIUL2_PORT_IP_DEV_ERROR_DETECT                   (STD_OFF)

/* Enabled/Disabled Siul2_Port_Ip_Init_UnusedPins function */
#define SIUL2_PORT_IP_INIT_UNUSED_PIN                          (STD_OFF)

/*! @brief SIUL2 module has RCVR bit */
#define FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT        (STD_OFF)

/*! @brief SIUL2 module has ODE bit */
#define FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN             (STD_ON)

#define SIUL2_0_MSCR_BASE                (IP_SIUL2_0->MSCR)
#define SIUL2_1_MSCR_BASE                (IP_SIUL2_1->MSCR)

/** SIUL2_0 */
/** Peripheral PORTA base pointer */
#define PORTA                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x00))
/** Peripheral PORTB base pointer */
#define PORTB                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x10))
/** Peripheral PORTC base pointer */
#define PORTC                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x20))
/** Peripheral PORTD base pointer */
#define PORTD                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x30))
/** Peripheral PORTE base pointer */
#define PORTE                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x40))
/** Peripheral PORTF base pointer */
#define PORTF                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x50))
/** Peripheral PORTG base pointer */
#define PORTG                            ((Siul2_Port_Ip_PortType *)(SIUL2_0_MSCR_BASE + 0x60))
/** SIUL2_1 */
/** Peripheral PORTH base pointer */
#define PORTH                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x70))
/** Peripheral PORTJ base pointer */
#define PORTJ                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0x90))
/** Peripheral PORTK base pointer */
#define PORTK                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0xA0))
/** Peripheral PORTL base pointer */
#define PORTL                            ((Siul2_Port_Ip_PortType *)(SIUL2_1_MSCR_BASE + 0xB0))

/*==================================================================================================
*                                             ENUMS
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

#endif /* SIUL2_PORT_IP_DEFINES */

