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

/**
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define PORT_VENDOR_ID_PBCFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        4
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define PORT_SW_MAJOR_VERSION_PBCFG_C                4
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                2

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

/**
* @brief Array containing list of partition which used in driver
*/
const uint8 au8Port_PartitionList[PORT_MAX_PARTITION] =
{
    1
};

#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap[PORT_MAX_CONFIGURED_PADS_U16] =
{
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001
};

#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

/**
* @brief Array containing list of MSCRs that are not used and should be configured with values from NotUsedPortPin container
*/
static const Port_Siul2_UnUsedPinType Port_aUnusedPads[PORT_MAX_UNUSED_PADS_U16] =
{
    { (uint16)2, PORT_SIUL2_0_U8 },
    { (uint16)3, PORT_SIUL2_0_U8 },
    { (uint16)6, PORT_SIUL2_0_U8 },
    { (uint16)7, PORT_SIUL2_0_U8 },
    { (uint16)8, PORT_SIUL2_0_U8 },
    { (uint16)9, PORT_SIUL2_0_U8 },
    { (uint16)10, PORT_SIUL2_0_U8 },
    { (uint16)11, PORT_SIUL2_0_U8 },
    { (uint16)12, PORT_SIUL2_0_U8 },
    { (uint16)13, PORT_SIUL2_0_U8 },
    { (uint16)14, PORT_SIUL2_0_U8 },
    { (uint16)15, PORT_SIUL2_0_U8 },
    { (uint16)16, PORT_SIUL2_0_U8 },
    { (uint16)17, PORT_SIUL2_0_U8 },
    { (uint16)18, PORT_SIUL2_0_U8 },
    { (uint16)19, PORT_SIUL2_0_U8 },
    { (uint16)20, PORT_SIUL2_0_U8 },
    { (uint16)21, PORT_SIUL2_0_U8 },
    { (uint16)22, PORT_SIUL2_0_U8 },
    { (uint16)23, PORT_SIUL2_0_U8 },
    { (uint16)24, PORT_SIUL2_0_U8 },
    { (uint16)25, PORT_SIUL2_0_U8 },
    { (uint16)26, PORT_SIUL2_0_U8 },
    { (uint16)27, PORT_SIUL2_0_U8 },
    { (uint16)28, PORT_SIUL2_0_U8 },
    { (uint16)29, PORT_SIUL2_0_U8 },
    { (uint16)30, PORT_SIUL2_0_U8 },
    { (uint16)31, PORT_SIUL2_0_U8 },
    { (uint16)32, PORT_SIUL2_0_U8 },
    { (uint16)35, PORT_SIUL2_0_U8 },
    { (uint16)36, PORT_SIUL2_0_U8 },
    { (uint16)37, PORT_SIUL2_0_U8 },
    { (uint16)38, PORT_SIUL2_0_U8 },
    { (uint16)39, PORT_SIUL2_0_U8 },
    { (uint16)40, PORT_SIUL2_0_U8 },
    { (uint16)45, PORT_SIUL2_0_U8 },
    { (uint16)59, PORT_SIUL2_0_U8 },
    { (uint16)60, PORT_SIUL2_0_U8 },
    { (uint16)61, PORT_SIUL2_0_U8 },
    { (uint16)62, PORT_SIUL2_0_U8 },
    { (uint16)63, PORT_SIUL2_0_U8 },
    { (uint16)64, PORT_SIUL2_0_U8 },
    { (uint16)65, PORT_SIUL2_0_U8 },
    { (uint16)66, PORT_SIUL2_0_U8 },
    { (uint16)67, PORT_SIUL2_0_U8 },
    { (uint16)68, PORT_SIUL2_0_U8 },
    { (uint16)69, PORT_SIUL2_0_U8 },
    { (uint16)70, PORT_SIUL2_0_U8 },
    { (uint16)71, PORT_SIUL2_0_U8 },
    { (uint16)72, PORT_SIUL2_0_U8 },
    { (uint16)73, PORT_SIUL2_0_U8 },
    { (uint16)74, PORT_SIUL2_0_U8 },
    { (uint16)75, PORT_SIUL2_0_U8 },
    { (uint16)76, PORT_SIUL2_0_U8 },
    { (uint16)77, PORT_SIUL2_0_U8 },
    { (uint16)78, PORT_SIUL2_0_U8 },
    { (uint16)79, PORT_SIUL2_0_U8 },
    { (uint16)80, PORT_SIUL2_0_U8 },
    { (uint16)81, PORT_SIUL2_0_U8 },
    { (uint16)82, PORT_SIUL2_0_U8 },
    { (uint16)83, PORT_SIUL2_0_U8 },
    { (uint16)84, PORT_SIUL2_0_U8 },
    { (uint16)85, PORT_SIUL2_0_U8 },
    { (uint16)86, PORT_SIUL2_0_U8 },
    { (uint16)87, PORT_SIUL2_0_U8 },
    { (uint16)88, PORT_SIUL2_0_U8 },
    { (uint16)89, PORT_SIUL2_0_U8 },
    { (uint16)90, PORT_SIUL2_0_U8 },
    { (uint16)91, PORT_SIUL2_0_U8 },
    { (uint16)92, PORT_SIUL2_0_U8 },
    { (uint16)93, PORT_SIUL2_0_U8 },
    { (uint16)94, PORT_SIUL2_0_U8 },
    { (uint16)95, PORT_SIUL2_0_U8 },
    { (uint16)96, PORT_SIUL2_0_U8 },
    { (uint16)97, PORT_SIUL2_0_U8 },
    { (uint16)98, PORT_SIUL2_0_U8 },
    { (uint16)99, PORT_SIUL2_0_U8 },
    { (uint16)100, PORT_SIUL2_0_U8 },
    { (uint16)101, PORT_SIUL2_0_U8 },
    { (uint16)112, PORT_SIUL2_1_U8 },
    { (uint16)113, PORT_SIUL2_1_U8 },
    { (uint16)114, PORT_SIUL2_1_U8 },
    { (uint16)115, PORT_SIUL2_1_U8 },
    { (uint16)116, PORT_SIUL2_1_U8 },
    { (uint16)117, PORT_SIUL2_1_U8 },
    { (uint16)118, PORT_SIUL2_1_U8 },
    { (uint16)119, PORT_SIUL2_1_U8 },
    { (uint16)120, PORT_SIUL2_1_U8 },
    { (uint16)121, PORT_SIUL2_1_U8 },
    { (uint16)122, PORT_SIUL2_1_U8 },
    { (uint16)144, PORT_SIUL2_1_U8 },
    { (uint16)145, PORT_SIUL2_1_U8 },
    { (uint16)146, PORT_SIUL2_1_U8 },
    { (uint16)147, PORT_SIUL2_1_U8 },
    { (uint16)148, PORT_SIUL2_1_U8 },
    { (uint16)149, PORT_SIUL2_1_U8 },
    { (uint16)150, PORT_SIUL2_1_U8 },
    { (uint16)151, PORT_SIUL2_1_U8 },
    { (uint16)152, PORT_SIUL2_1_U8 },
    { (uint16)153, PORT_SIUL2_1_U8 },
    { (uint16)154, PORT_SIUL2_1_U8 },
    { (uint16)155, PORT_SIUL2_1_U8 },
    { (uint16)156, PORT_SIUL2_1_U8 },
    { (uint16)157, PORT_SIUL2_1_U8 },
    { (uint16)158, PORT_SIUL2_1_U8 },
    { (uint16)159, PORT_SIUL2_1_U8 },
    { (uint16)160, PORT_SIUL2_1_U8 },
    { (uint16)161, PORT_SIUL2_1_U8 },
    { (uint16)162, PORT_SIUL2_1_U8 },
    { (uint16)163, PORT_SIUL2_1_U8 },
    { (uint16)164, PORT_SIUL2_1_U8 },
    { (uint16)165, PORT_SIUL2_1_U8 },
    { (uint16)166, PORT_SIUL2_1_U8 },
    { (uint16)168, PORT_SIUL2_1_U8 },
    { (uint16)169, PORT_SIUL2_1_U8 },
    { (uint16)170, PORT_SIUL2_1_U8 },
    { (uint16)172, PORT_SIUL2_1_U8 },
    { (uint16)176, PORT_SIUL2_1_U8 },
    { (uint16)177, PORT_SIUL2_1_U8 },
    { (uint16)178, PORT_SIUL2_1_U8 },
    { (uint16)179, PORT_SIUL2_1_U8 },
    { (uint16)180, PORT_SIUL2_1_U8 },
    { (uint16)181, PORT_SIUL2_1_U8 },
    { (uint16)182, PORT_SIUL2_1_U8 },
    { (uint16)183, PORT_SIUL2_1_U8 },
    { (uint16)184, PORT_SIUL2_1_U8 },
    { (uint16)185, PORT_SIUL2_1_U8 },
    { (uint16)186, PORT_SIUL2_1_U8 },
    { (uint16)187, PORT_SIUL2_1_U8 },
    { (uint16)188, PORT_SIUL2_1_U8 },
    { (uint16)189, PORT_SIUL2_1_U8 },
    { (uint16)190, PORT_SIUL2_1_U8 }
};

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_Siul2_UnUsedPinConfigType Port_UnusedPinConfig =
{
    /**
    * @note: Configuration of Default pin
    */
    (uint32)0x00080000, (uint8)0
};

/**
* @brief Pin default configuration data for configPB
*/
static const Port_Siul2_PinConfigType Port_aUsedPinConfigs[PORT_MAX_CONFIGURED_PADS_U16] =
{
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)34, (uint32)0x00390002, (uint8)PORT_SIUL2_0_U8, (uint8)2, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 211 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)33, (uint32)0x00393001, (uint8)PORT_SIUL2_0_U8, (uint8)0, PORT_PIN_INOUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 212 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)57, (uint32)0x0009c000, (uint8)PORT_SIUL2_0_U8, (uint8)2, PORT_PIN_IN, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)167, (uint32)0x00210000, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)43, (uint32)0x00093000, (uint8)PORT_SIUL2_0_U8, (uint8)1, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 1 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)44, (uint32)0x00213001, (uint8)PORT_SIUL2_0_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)171, (uint32)0x00213005, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)175, (uint32)0x00211004, (uint8)PORT_SIUL2_1_U8, (uint8)0, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)173, (uint32)0x00211003, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_OUT, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)FALSE, 65535 },
    /* Mscr Id, Mscr Value, Mscr Siul Instance, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable, Is Imcr Available, Imcr Id */
    { (uint16)174, (uint32)0x00093000, (uint8)PORT_SIUL2_1_U8, (uint8)1, PORT_PIN_IN, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE, (boolean)TRUE, 495 }
};

/* SIUL2_0 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_0
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_0_ImcrInitConfig[PORT_SIUL2_0_NUM_IMCRS_U16] =
{
    (uint8)0xff,
    (uint8)0x02,
    (uint8)0xFFU,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0xff,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00
};


/* SIUL2_1 */
/**
* @brief IMCR configuration set by Port_Init() for SIUL2 instance: SIUL2_1
*/
static const Port_Siul2_ImcrConfigType Port_aSIUL2_1_ImcrInitConfig[PORT_SIUL2_1_NUM_IMCRS_U16] =
{
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x03,
    (uint8)0x03,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0xFFU,
    (uint8)0xFFU,
    (uint8)0x00,
    (uint8)0x00,
    (uint8)0x03
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
*/
const Port_ConfigType Port_Config =
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
    {
        PORT_SIUL2_0_NUM_IMCRS_U16,
        PORT_SIUL2_1_NUM_IMCRS_U16
    },
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_aUnusedPads,
#else
    NULL_PTR,
#endif
    &Port_UnusedPinConfig,
    Port_aUsedPinConfigs,
    {
        Port_aSIUL2_0_ImcrInitConfig,
        Port_aSIUL2_1_ImcrInitConfig
    },
    au32Port_PinToPartitionMap,
    au8Port_PartitionList,
    g_pin_mux_InitConfigArr
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
