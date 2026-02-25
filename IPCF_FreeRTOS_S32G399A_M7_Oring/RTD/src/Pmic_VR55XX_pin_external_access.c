/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   (c) Copyright 2020-2023 NXP
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file Pmic_VR55XX_pin_external_access.c
*
*   @addtogroup pin_external_access
*   @{
*/

#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_VR55XX_pin_external_access.h"

#ifdef USE_IPV_SIUL2
#include "Siul2_Port_Ip.h"
#include "Siul2_Dio_Ip.h"
#else
#include "Port.h"
#include "Dio.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_VENDOR_ID_C                      43
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C       4
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C               4
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MINOR_VERSION_C               0
#define PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Pin External Access header file */
#if ( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_VENDOR_ID_C != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_VENDOR_ID)
    #error "Pin External Access source file and Pin External Access header file have different vendor ids"
#endif
#if (( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    ) || \
     ( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C    != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    ) || \
     ( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of Pin External Access source file and Pin External Access header file are different"
#endif
#if (( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MAJOR_VERSION) || \
     ( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MINOR_VERSION_C != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_MINOR_VERSION) || \
     ( PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_PATCH_VERSION_C != PMIC_VR55XX_PIN_EXTERNAL_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pin External Access source file and Pin External Access header file are different"
#endif


#ifdef USE_IPV_SIUL2
    /* Check if current file and Siul2_Port_Ip header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
        )
    #error "AutoSar Version Numbers of Pin External Access source file and Siul2_Port_Ip.h are different"
    #endif
    /* Check if current file and Siul2_Dio_Ip header file are of the same version */
    #if ((PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != SIUL2_DIO_IP_AR_RELEASE_MAJOR_VERSION_H) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != SIUL2_DIO_IP_AR_RELEASE_MINOR_VERSION_H) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != SIUL2_DIO_IP_AR_RELEASE_REVISION_VERSION_H) \
        )
    #error "AutoSar Version Numbers of Pin External Access source file and Siul2_Dio_Ip.h are different"
    #endif
    #endif
#else
    /* Check if current file and Port header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != PORT_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != PORT_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Pin External Access source file and Port.h are different"
    #endif
    /* Check if current file and Dio header file are of the same version */
    #if ((PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != DIO_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != DIO_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_PIN_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Pin External Access source file and Dio.h are different"
    #endif
    #endif
#endif

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/



/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_Port_SetPinMode
 * Description   : Set pin operation mode
 *
 *END**************************************************************************/
void Pmic_VR55XX_Port_SetPinMode(const uint8 u8Siul2Instance, const uint32 u32Pin, const uint8 u8Mode)
{
#ifdef USE_IPV_SIUL2
    uint32 u32RegValue = PORT_READ32(SIUL2_MSCR_ADDR32(u8Siul2Instance, u32Pin));

    u32RegValue &= ~SIUL2_MSCR_SSS_MASK;
    u32RegValue |= SIUL2_MSCR_SSS(u8Mode);
    PORT_WRITE32(SIUL2_MSCR_ADDR32(u8Siul2Instance, u32Pin), u32RegValue);
#else
    (void)u8Siul2Instance;
    Port_SetPinMode((Port_PinType)u32Pin, (Port_PinModeType)u8Mode);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_Dio_FlipChannel
 * Description   : Inverts the level of a pin.
 *
 *END**************************************************************************/
void Pmic_VR55XX_Dio_FlipChannel(const uint8 u8Siul2Instance, const uint16 u16ChannelId)
{
#ifdef USE_IPV_SIUL2
    /* Read value pin */
    uint8 u8ChannelLevel = *((uint8 *)(SIUL2_DIO_IP_GPDI_ADDR32(u8Siul2Instance, u16ChannelId)));
    /* Flip value pin and write again */
    u8ChannelLevel = (uint8)(((uint8)(~u8ChannelLevel)) & SIUL2_DIO_IP_GPDI_MASK_U8);
    (*(uint8*)(SIUL2_DIO_IP_GPDO_ADDR32(u8Siul2Instance, u16ChannelId))) = u8ChannelLevel;

#else
    (void)u8Siul2Instance;
#if (STD_ON == DIO_FLIP_CHANNEL_API)
    (void)Dio_FlipChannel((Dio_ChannelType)u16ChannelId);
#else
    (void)u16ChannelId;
#endif
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_Dio_WriteChannel
 * Description   : Write the level of a pin.
 *
 *END**************************************************************************/
void Pmic_VR55XX_Dio_WriteChannel(const uint8 u8Siul2Instance, const uint16 u16ChannelId, const boolean bLevel)
{
#ifdef USE_IPV_SIUL2
    (*(uint8*)(SIUL2_DIO_IP_GPDO_ADDR32(u8Siul2Instance, u16ChannelId))) = bLevel;

#else
    (void)u8Siul2Instance;
    Dio_WriteChannel((Dio_ChannelType)u16ChannelId, (TRUE == bLevel) ? (Dio_LevelType)STD_HIGH : (Dio_LevelType)STD_LOW);
#endif
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_Dio_ReadChannel
 * Description   : Read the level of a pin.
 *
 *END**************************************************************************/
boolean Pmic_VR55XX_Dio_ReadChannel(const uint8 u8Siul2Instance, const uint16 u16ChannelId)
{
    boolean bLevel;

#ifdef USE_IPV_SIUL2
    uint8 u8RetValue = (*(uint8*)(SIUL2_DIO_IP_GPDI_ADDR32(u8Siul2Instance, u16ChannelId)));
    u8RetValue &= SIUL2_DIO_IP_GPDI_MASK_U8;

    bLevel = (u8RetValue > 0U) ? TRUE : FALSE;

#else
    (void)u8Siul2Instance;
    bLevel = ((Dio_LevelType)STD_HIGH == Dio_ReadChannel((Dio_ChannelType)u16ChannelId)) ? TRUE : FALSE;
#endif

    return bLevel;
}
#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/
