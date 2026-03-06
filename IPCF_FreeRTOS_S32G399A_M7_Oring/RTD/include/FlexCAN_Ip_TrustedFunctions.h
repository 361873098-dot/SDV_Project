/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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

#ifndef FLEXCAN_IP_TRUSTEDFUNCTIONS_H
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_H

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexCAN_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                      43
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H               4
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip.h header file are of the same vendor */
#if (FLEXCAN_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
    #error "FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip.h header file are of the same Autosar version */
#if ((FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip.h header file are of the same Software version */
#if ((FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip_TrustedFunctions.h and FlexCAN_Ip.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"

#if (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON)
#if (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON)
#if (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON)
#if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/**
 *  @brief Configures High Resolution Timestamp source.
 */
extern void FlexCAN_ConfigTimestampModule(const Flexcan_Ip_TimeStampConfigType * config);
#endif /* (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE) */
#endif /* (FLEXCAN_IP_HR_TIMESTAMP_SRC_SELECTABLE == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_HR_TIMER == STD_ON) */
#endif /* (FLEXCAN_IP_FEATURE_HAS_TS_ENABLE == STD_ON) */

#if (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE)
/**
 *  @brief Sets the UAA bit in REG_PROT to make the instance accessible.
 */
extern void FlexCAN_SetUserAccessAllowed(const FLEXCAN_Type * pBase);

/**
 *  @brief Clears the UAA bit in REG_PROT to make the instance accessible.
 */
extern void FlexCAN_ClrUserAccessAllowed(const FLEXCAN_Type * pBase);
#endif /* (STD_ON == FLEXCAN_IP_SET_USER_ACCESS_ALLOWED_AVAILABLE) */

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#endif /* FLEXCAN_IP_TRUSTEDFUNCTIONS_H */
