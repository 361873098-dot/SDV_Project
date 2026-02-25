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

#ifndef PORT_IPW_H
#define PORT_IPW_H

/**
*   @file    Port_Ipw.h
*
*   @internal
*   @defgroup Port_IPW Port IPW
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Siul2_Port_Ip.h"
#include "Port_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_IPW_H                    43
#define PORT_AR_RELEASE_MAJOR_VERSION_IPW_H     4
#define PORT_AR_RELEASE_MINOR_VERSION_IPW_H     4
#define PORT_AR_RELEASE_REVISION_VERSION_IPW_H  0
#define PORT_SW_MAJOR_VERSION_IPW_H             4
#define PORT_SW_MINOR_VERSION_IPW_H             0
#define PORT_SW_PATCH_VERSION_IPW_H             2

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Ipw.h and Siul2_Port_Ip.h are of the same vendor */
#if (PORT_VENDOR_ID_IPW_H != SIUL2_PORT_IP_VENDOR_ID_H)
    #error "Port_Ipw.h and Siul2_Port_Ip.h have different vendor ids"
#endif
/* Check if Port_Ipw.h and Siul2_Port_Ip.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_H    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_H    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_H != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Ipw.h and Siul2_Port_Ip.h are different"
#endif

/* Check if Port_Ipw.h and Siul2_Port_Ip.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_H != SIUL2_PORT_IP_SW_MAJOR_VERSION_H) || \
     (PORT_SW_MINOR_VERSION_IPW_H != SIUL2_PORT_IP_SW_MINOR_VERSION_H) || \
     (PORT_SW_PATCH_VERSION_IPW_H != SIUL2_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Ipw.h and Siul2_Port_Ip.h are different"
#endif

/* Check if Port_Ipw.h and Port_Cfg.h are of the same vendor */
#if (PORT_VENDOR_ID_IPW_H != PORT_CFG_VENDOR_ID_H)
    #error "Port_Ipw.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if Port_Ipw.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_H    != PORT_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_H    != PORT_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_H != PORT_CFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Ipw.h and Port_Cfg.h are different"
#endif

/* Check if Port_Ipw.h and Port_Cfg.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_H != PORT_CFG_SW_MAJOR_VERSION_H) || \
     (PORT_SW_MINOR_VERSION_IPW_H != PORT_CFG_SW_MINOR_VERSION_H) || \
     (PORT_SW_PATCH_VERSION_IPW_H != PORT_CFG_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Ipw.h and Port_Cfg.h are different"
#endif
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define SIUL2_MODE_BIT_OFFSET_MASK_U8  ((uint8)0x0F)
/* @brief Mask definitions for MSCR bit field IBE */
#define SIUL2_MSCR_IBE_U32                              ((uint32)0x00080000U)
#define SIUL2_MSCR_IBE_ON_U32                           ((uint32)0x00080000U)

#define SIUL2_MSCR_OBE_U32                          ((uint32)0x00200000U)
#define SIUL2_MSCR_OBE_ON_U32                       ((uint32)0x00200000U)

#define SIUL2_MSCR_SSS_U32                          ((uint32)0x00000007U)
#define SIUL2_MSCR_SSS_OFFSET_U32                   ((uint32)0)

/*
* @brief Initializing value for the unused IMCR registers in order to avoid writting in not valid
*        memory areas
*/
#define SIUL2_UNUSED_IMCR_PATTERN_U8        ((uint32)0xFFU)
/* @brief Mode bit offset mask */
#define SIUL2_BIT_OFFSET_MASK_U8                        ((uint8)0x0F)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/
/* Allocate defined section for PORT code */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/*!
 * @brief        Initializes the SIUL2 IP Driver
 * @details      The function Port_Siul2_Init will initialize ALL ports and port pins with the
 *               configuration set pointed to by the parameter pConfigPtr.
 *
 * @param[in]    pConfigPtr  A pointer to the structure which contains initialization parameters
 *
 * @return void
 *
 *
 **/
void Port_Ipw_Init
(
    const Port_ConfigType * pConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/*!
 * @brief   Sets the port pin direction
 * @details Sets the pin direction at runtime, changing it only if the pin is configurated as
 *          changeable.
 *
 * @param[in]     PinIndex        Pin ID number
 * @param[in]     eDirection      Port Pin direction
 * @param[in]     pConfigPtr      A pointer to the structure which contains initialization parameters
 *
 * @return Error code after execution
 * @retval 0   No error occured
 * @retval 1   Pin direction cannot be changed
 *
 *
 **/
Std_ReturnType Port_Ipw_SetPinDirection
(
    Port_PinType PinIndex,
    Port_PinDirectionType eDirection,
    const Port_ConfigType * pConfigPtr
);

#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

/*!
 * @brief   Refreshes port direction.
 * @details This service shall refresh the direction of all configured ports to the configured
 *          direction. The PORT driver shall exclude from refreshing those port pins that are
 *          configured as pin direction changeable during runtime.
 *
 * @param[in] numPins    Number of pins to be refreshed
 *
 * @return void
 *
 *
 **/
void Port_Ipw_RefreshPortDirection
(
    const Port_ConfigType * pConfigPtr
);

#ifdef PORT_SET_AS_UNUSED_PIN_API
#if (STD_ON == PORT_SET_AS_UNUSED_PIN_API)
/*!
 * @brief   Set as unused pin.
 * @details This function shall configure the referenced pin with all
 *          the properties specified in the NotUsedPortPin container.
 *
 * @param[in] PinIndex       Pin ID number.
 * @param[in] pConfigPtr     A pointer to the structure which contains initialization parameters
 *
 * @return void
 *
 **/
void Port_Ipw_SetAsUnusedPin
(
    Port_PinType PinIndex,
    const Port_ConfigType * pConfigPtr
);

/*!
 * @brief   Set as used pin.
 * @details This function shall configure the referenced pin with
 *          all the properties that where set during the Port_Init operation.
 *
 * @param[in] PinIndex     Pin ID number.
 * @param[in] pConfigPtr     A pointer to the structure which contains initialization parameters
 *
 * @return void
 *
 *
 **/
void Port_Ipw_SetAsUsedPin
(
    Port_PinType PinIndex,
    const Port_ConfigType * pConfigPtr
);

#endif /* (STD_ON == PORT_SET_AS_UNUSED_PIN_API) */
#endif

#ifdef PORT_RESET_PIN_MODE_API
#if (STD_ON == PORT_RESET_PIN_MODE_API)
/*!
 * @brief reset the port pin mode.
 *
 * @details The function @p Port_Ipw_SetPinMode will reset the port pin mode of the
 *          referenced pin during runtime.
 *
 *
 * @param[in] PinIndex       Pin ID number.
 * @param[in] pConfigPtr     Pointer to the initialization data structure
 *
 * @return void
 *
 *
 **/
void Port_Ipw_ResetPinMode
(
    Port_PinType PinIndex,
    const Port_ConfigType * pConfigPtr
);

#endif /* (STD_ON == PORT_RESET_PIN_MODE_API) */
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)
/*!
 * @brief Sets the port pin mode.
 *
 * @details The function @p Port_Ipw_SetPinMode will set the port pin mode of the
 *          referenced pin during runtime.
 *
* @param[in] PinIndex       Pin ID number.
* @param[in] PinMode        New Port Pin mode to be set on port pin.
* @param[in] pConfigPtr     Pointer to the initialization data structure
 *
 * @return void
 *
 **/
Std_ReturnType Port_Ipw_SetPinMode
(
    Port_PinType PinIndex,
    Port_PinModeType PinMode,
    const Port_ConfigType * pConfigPtr
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*PORT_IPW_H*/
