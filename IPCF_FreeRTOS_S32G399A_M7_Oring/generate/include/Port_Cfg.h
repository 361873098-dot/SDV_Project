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

#ifndef PORT_CFG_H
#define PORT_CFG_H

/**
*   @file    Port_Cfg.h
*
*   @implements Port_Cfg.h_Artifact
*   @defgroup   Port_CFG Port CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port_PBcfg.h"
#include "Siul2_Port_Ip_Types.h"
#include "Siul2_Port_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_CFG_VENDOR_ID_H                       43
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_MINOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_REVISION_VERSION_H     0
#define PORT_CFG_SW_MAJOR_VERSION_H                4
#define PORT_CFG_SW_MINOR_VERSION_H                0
#define PORT_CFG_SW_PATCH_VERSION_H                2

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_VENDOR_ID_PBCFG_H)
    #error "Port_Cfg.h and Port_PBcfg.h have different vendor IDs"
#endif
 /* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_AR_RELEASE_MINOR_VERSION_PBCFG_H) ||   \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_PBCFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_PBCFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_PBCFG_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_TYPES_VENDOR_ID_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Types.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Types.h are different"
#endif

/* Check if the files Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != SIUL2_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Cfg.h and Siul2_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif
/* Check if Port_Cfg.h and Siul2_Port_Ip_Cfg.h are of the same Software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_MINOR_VERSION_H != SIUL2_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CFG_SW_PATCH_VERSION_H != SIUL2_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Siul2_Port_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/* @implements Port_PinType_typedef */
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
  PORT_PIN_IN = 0,        /**< @brief Sets port pin as input. */
  PORT_PIN_OUT,           /**< @brief Sets port pin as output. */
  PORT_PIN_INOUT,         /**< @brief Sets port pin as bidirectional. */
  PORT_PIN_HIGH_Z         /**< @brief Sets port pin as high_z. */
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
* @brief   A SIUL2 register value.
* @details A port register shall be written with a 32 bits value (type Port_RegValueType).
*          The type Port_RegValueType shall be used with the function call Port_SetPinMode
*
*/
typedef uint32 Port_RegValueType;

/**
* @brief Data type used for IMCR Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
*
* @api
*/
typedef uint8  Port_Siul2_ImcrConfigType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p SIUPin.
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;         /**< @brief Index of the pin's Mscr */
  uint32 u32MSCR;            /**< @brief Pad Control Register */
#ifdef IPV_SIUL2_ODC_SUPPORT_U8
  uint32 u32ODC;             /**< @brief Pad Output Driver Control Configuration */
#endif
  uint8 u8MscrSiulInstance; /**< @brief Siul Instance */
  uint8 u8PDO;              /**< @brief Pad Data Output */
  Port_PinDirectionType ePadDir;            /**< @brief Pad Data Direction */
  boolean bGPIO;              /**< @brief GPIO initial mode*/
  boolean bDC;                /**< @brief Direction changebility*/
  boolean bMC;                /**< @brief Mode changebility*/
  boolean bImcr;              /**< @brief Imcr available */
  uint16 u16ImcrIdx;         /**< @brief Index of the pin's Imcr*/
} Port_Siul2_PinConfigType;


/**
* @brief   Default pin.
* @details This structure contains information about Mscr and Siul Instance for unused pins
*
* @api
*/
typedef struct
{
  uint16 u16MscrIdx;           /**< @brief Id of not used Mscr */
  uint8 u8MscrSiulInstance;   /**< @brief Siul Instance of not used Mscr */
}Port_Siul2_UnUsedPinType;

/**
* @brief   Default pin configuration.
* @details This structure contains all configuration parameters of a Default pin
*
* @api
*/
typedef struct
{
  uint32   u32MSCR;          /**< Content of Mscr Register */
  uint8   u8PDO;            /**< Pad Data Output */
} Port_Siul2_UnUsedPinConfigType;

/**
* @brief   DiPort signal configuration.
* @details This structure contains all configuration parameters of a DiPort Signal pin
*
* @api
*/
typedef struct
{
  uint8 u8MscrSiulInstance;   /**< @brief Siul Instance of the Mscr configuring the DiPort signal */
  uint16 u16MscrIdx;           /**< @brief Index of the Mscr configuring the DiPort signal */
  uint8 u8MscrValue;          /**< @brief Value of the Mscr configuring the DiPort signal */
} Port_DiPort_SignalConfigType;

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define PORT_CONFIG_EXT \
PORT_CONFIG_PB \

/**
* @brief Enable/Disable multicore function from the driver
*/
#define PORT_MULTICORE_ENABLED              (STD_OFF)

/**
* @brief The number of SIUL2 instances on the platform
*/
#define PORT_NUM_SIUL2_INSTANCES_U8         ((uint8)2)

/**
* @brief List of identifiers for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_U8             ((uint8)0)
#define PORT_SIUL2_1_U8             ((uint8)1)

/**
* @brief Defines specifying number of IMCRs for each of the SIUL2 instances on the platform
*/
#define PORT_SIUL2_0_NUM_IMCRS_U16             ((uint16)84)
#define PORT_SIUL2_1_NUM_IMCRS_U16             ((uint16)496)

#define SHL_PAD_U32(x)                      ((uint32)(((uint32)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                 ((uint16)0xFFFFU)

/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Input Mode */
#define PORT_ONLY_INPUT_MODE            ((Port_PinModeType)7)
/** @brief Port Input 1 Mode */
#define PORT_INPUT1_MODE                ((Port_PinModeType)8)
/** @brief Port Input 2 Mode */
#define PORT_INPUT2_MODE                ((Port_PinModeType)9)
/** @brief Port Input 3 Mode */
#define PORT_INPUT3_MODE                ((Port_PinModeType)10)
/** @brief Port Input 4 Mode */
#define PORT_INPUT4_MODE                ((Port_PinModeType)11)
/** @brief Port Input 5 Mode */
#define PORT_INPUT5_MODE                ((Port_PinModeType)12)
/** @brief Port Input 6 Mode */
#define PORT_INPUT6_MODE                ((Port_PinModeType)13)
/** @brief Port Input 7 Mode */
#define PORT_INPUT7_MODE                ((Port_PinModeType)14)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)15)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)16)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)17)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)18)
/** @brief Port Input/Output 5 Mode */
#define PORT_INOUT5_MODE                ((Port_PinModeType)19)
/** @brief Port Input/Output 6 Mode */
#define PORT_INOUT6_MODE                ((Port_PinModeType)20)

/** @brief Number of distinct pin modes for all pins on the platform */
#define PORT_NUM_PIN_MODES_U8           ((uint8)21)

/** @brief Informs the IP layer that there is no support
*          for ANALOG function on this platform */
#define PORT_NO_ANALOG_MODE             (STD_ON)

/** @brief Number of 16 pins blocks containing all pins on the platform */
#define PORT_NUM_16PIN_BLOCKS_U8         ((uint8)12)

/** @brief Port Abstraction Modes */
#define SIUL2_0_PORT0_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT0_JTAGC_TDI                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT1_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT1_JTAGC_TDO                                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT2_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT2_BOOT_BOOTMOD_0                           (PORT_INPUT1_MODE)
#define SIUL2_0_PORT3_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT3_BOOT_BOOTMOD_1                           (PORT_INPUT1_MODE)
#define SIUL2_0_PORT4_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT4_FLEXRAY_0_FR_DBG_0                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT4_JTAGC_TCK                                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT5_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT5_JTAGC_TMS_OUT                            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT5_JTAGC_TMS_IN                             (PORT_INPUT1_MODE)
#define SIUL2_0_PORT5_JTAGC_TMS_INOUT                          (PORT_INOUT1_MODE)
#define SIUL2_0_PORT6_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT6_DSPI_1_DSPI1_SOUT                        (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT6_FLEXRAY_0_FR_DBG_2                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT7_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_OUT                    (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_OUT                 (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT7_FLEXRAY_0_FR_DBG_3                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_IN                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_INOUT                  (PORT_INOUT2_MODE)
#define SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_INOUT               (PORT_INOUT3_MODE)
#define SIUL2_0_PORT8_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT8_LLCE_LPSPI_0_LLCE_LPSPI0_SIN             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_OUT                 (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_INOUT               (PORT_INOUT4_MODE)
#define SIUL2_0_PORT9_GPIO                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_OUT         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_OUT                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT9_BOOT_RCON0                               (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_IN          (PORT_INPUT1_MODE)
#define SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_IN                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT9_GMAC_0_GMAC0_PST_TS_TRIG_1               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT9_GMAC_0_GMAC0_AUX_TRIG_3                  (PORT_INPUT5_MODE)
#define SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_INOUT       (PORT_INOUT1_MODE)
#define SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_INOUT               (PORT_INOUT2_MODE)
#define SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT10_GPI                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT10_BOOT_RCON1                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT10_LLCE_LPSPI_0_LLCE_LPSPI0_SIN            (PORT_INPUT1_MODE)
#define SIUL2_0_PORT10_DSPI_5_DSPI5_SIN                        (PORT_INPUT2_MODE)
#define SIUL2_0_PORT10_WKPU_WKUP22                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT10_GMAC_0_GMAC0_PST_TS_TRIG_0              (PORT_INPUT3_MODE)
#define SIUL2_0_PORT10_GMAC_0_GMAC0_AUX_TRIG_2                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT11_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT11_GMAC_0_GMAC0_PPS_2                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT11_DSPI_5_DSPI5_SOUT                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_OUT       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT11_BOOT_RCON2                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_IN        (PORT_INPUT2_MODE)
#define SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_INOUT     (PORT_INOUT4_MODE)
#define SIUL2_0_PORT12_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT12_GMAC_0_GMAC0_PPS_3                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_OUT                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_OUT       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT12_BOOT_RCON3                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_IN                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_INOUT                 (PORT_INOUT3_MODE)
#define SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT     (PORT_INOUT4_MODE)
#define SIUL2_0_PORT13_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_OUT                    (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT13_LINFLEX_1_LIN1_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT13_BOOT_RCON4                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_IN                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT13_FLEXTIMER_0_FTM0_EXT_CLK                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT13_PFE_MAC1_PFE_MAC1_RX_ER                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_INOUT                  (PORT_INOUT1_MODE)
#define SIUL2_0_PORT14_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT14_BOOT_RCON5                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT14_DSPI_0_DSPI0_SIN                        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT14_LINFLEX_0_LIN0_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_0_PORT15_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT15_DSPI_0_DSPI0_SOUT                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT15_LINFLEX_0_LIN0_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT15_BOOT_RCON6                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT15_PFE_MAC1_PFE_MAC1_COL                   (PORT_INPUT2_MODE)
#define SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT16_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT16_I2C_0_I2C0_SDA_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT16_BOOT_RCON7                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT16_I2C_0_I2C0_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT16_LINFLEX_1_LIN1_RX                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_IN                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT16_PFE_MAC1_PFE_MAC1_CRS                   (PORT_INPUT5_MODE)
#define SIUL2_0_PORT16_I2C_0_I2C0_SDA_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT17_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT17_I2C_0_I2C0_SCL_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT17_FLEXCAN_0_CAN0_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT17_I2C_4_I2C4_SCL_OUT                      (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT17_BOOT_RCON8                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT17_I2C_0_I2C0_SCL_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT17_I2C_4_I2C4_SCL_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT17_I2C_0_I2C0_SCL_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT17_I2C_4_I2C4_SCL_INOUT                    (PORT_INOUT4_MODE)
#define SIUL2_0_PORT18_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT18_I2C_4_I2C4_SDA_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT18_BOOT_RCON9                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT18_I2C_4_I2C4_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT18_FLEXCAN_0_CAN0_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT18_I2C_4_I2C4_SDA_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT19_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT19_I2C_1_I2C1_SCL_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT19_FLEXCAN_1_CAN1_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT19_LLCE_FLEXRAY_LLCE_FR_DBG_0              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT19_BOOT_RCON10                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT19_I2C_1_I2C1_SCL_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT19_SIUL_OFFCC_EIRQ_0                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT19_I2C_1_I2C1_SCL_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT20_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT20_I2C_1_I2C1_SDA_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT20_LLCE_FLEXRAY_LLCE_FR_DBG_1              (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT20_BOOT_RCON11                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT20_I2C_1_I2C1_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT20_FLEXCAN_1_CAN1_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT20_SIUL_OFFCC_EIRQ_1                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT20_I2C_1_I2C1_SDA_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT21_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT21_I2C_2_I2C2_SCL_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT21_LLCE_FLEXRAY_LLCE_FR_DBG_2              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT21_BOOT_RCON12                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT21_I2C_2_I2C2_SCL_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT21_CTU_CTU_EXT_TRIG                        (PORT_INPUT2_MODE)
#define SIUL2_0_PORT21_SIUL_OFFCC_EIRQ_2                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT21_I2C_2_I2C2_SCL_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT22_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT22_I2C_2_I2C2_SDA_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT22_LLCE_FLEXRAY_LLCE_FR_DBG_3              (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT22_BOOT_RCON13                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT22_I2C_2_I2C2_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT22_SIUL_OFFCC_EIRQ_3                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT22_I2C_2_I2C2_SDA_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT23_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT23_I2C_3_I2C3_SCL_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT23_PFE_MAC1_PFE_MAC1_MDC                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT23_GMAC_0_GMAC0_MDC                        (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT23_BOOT_RCON14                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT23_I2C_3_I2C3_SCL_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT23_SIUL_OFFCC_EIRQ_4                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT23_I2C_3_I2C3_SCL_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT24_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT24_I2C_0_I2C0_SDA_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT24_GMAC_0_GMAC0_MD_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT24_BOOT_RCON15                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT24_I2C_0_I2C0_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT24_SIUL_OFFCC_EIRQ_5                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT24_GMAC_0_GMAC0_MD_IN                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT24_I2C_0_I2C0_SDA_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT24_GMAC_0_GMAC0_MD_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_0_PORT25_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT25_LINFLEX_1_LIN1_TX                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT25_FLEXCAN_3_CAN3_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT25_DSPI_4_DSPI4_SOUT                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT25_DSPI_0_DSPI0_PCS1                       (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT25_PFE_PFE_UART_TX                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT25_BOOT_RCON16                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT25_SIUL_OFFCC_EIRQ_6                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT25_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT26_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT26_DSPI_0_DSPI0_PCS2                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT26_BOOT_RCON17                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT26_LINFLEX_1_LIN1_RX                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT26_FLEXCAN_3_CAN3_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_IN                    (PORT_INPUT4_MODE)
#define SIUL2_0_PORT26_SIUL_OFFCC_EIRQ_7                       (PORT_INPUT5_MODE)
#define SIUL2_0_PORT26_PFE_PFE_UART_RX                         (PORT_INPUT6_MODE)
#define SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT27_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT27_FLEXRAY_0_FR_TXE_A_b                    (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT27_FLEXCAN_2_CAN2_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT27_LINFLEX_2_LIN2_TX                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_OUT        (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT27_BOOT_RCON18                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_IN         (PORT_INPUT1_MODE)
#define SIUL2_0_PORT27_FLEXTIMER_1_FTM1_EXT_CLK                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT27_SIUL_OFFCC_EIRQ_8                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT27_MISC_TAMPER_EXTIN0                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT27_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_INOUT      (PORT_INOUT4_MODE)
#define SIUL2_0_PORT28_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT28_FLEXRAY_0_FR_TXD_A                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT28_MISC_TAMPER_LOOP_OUT0                   (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_OUT       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_OUT        (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT28_BOOT_RCON19                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT28_FLEXCAN_2_CAN2_RX                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT28_LINFLEX_2_LIN2_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_IN         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT28_SIUL_OFFCC_EIRQ_9                       (PORT_INPUT5_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN        (PORT_INPUT6_MODE)
#define SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT     (PORT_INOUT4_MODE)
#define SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_INOUT      (PORT_INOUT5_MODE)
#define SIUL2_0_PORT29_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT29_FLEXCAN_3_CAN3_TX                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT29_I2C_3_I2C3_SDA_OUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_OUT       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT29_BOOT_RCON20                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT29_I2C_3_I2C3_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT29_FLEXRAY_0_FR_RXD_A                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT29_SIUL_OFFCC_EIRQ_10                      (PORT_INPUT4_MODE)
#define SIUL2_0_PORT29_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT29_PFE_MAC2_PFE_MAC2_CRS                   (PORT_INPUT6_MODE)
#define SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_IN        (PORT_INPUT7_MODE)
#define SIUL2_0_PORT29_I2C_3_I2C3_SDA_INOUT                    (PORT_INOUT2_MODE)
#define SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_INOUT     (PORT_INOUT4_MODE)
#define SIUL2_0_PORT30_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT30_FLEXRAY_0_FR_TXE_B_b                    (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_OUT       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT30_I2C_3_I2C3_SCL_OUT                      (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT30_BOOT_RCON21                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT30_FLEXCAN_3_CAN3_RX                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT30_I2C_3_I2C3_SCL_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT30_FLEXTIMER_1_FTM1_CH3                    (PORT_INPUT3_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_IN        (PORT_INPUT4_MODE)
#define SIUL2_0_PORT30_PFE_MAC2_PFE_MAC2_COL                   (PORT_INPUT5_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN        (PORT_INPUT6_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_INOUT     (PORT_INOUT2_MODE)
#define SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT30_I2C_3_I2C3_SCL_INOUT                    (PORT_INOUT4_MODE)
#define SIUL2_0_PORT31_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT31_FLEXRAY_0_FR_TXD_B                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT31_I2C_0_I2C0_SDA_OUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT31_FLEXTIMER_1_FTM1_CH3                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT31_BOOT_RCON22                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT31_I2C_0_I2C0_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT31_SIUL_OFFCC_EIRQ_12                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT31_PFE_MAC2_PFE_MAC2_PST_TS_TRIG_0         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN        (PORT_INPUT4_MODE)
#define SIUL2_0_PORT31_I2C_0_I2C0_SDA_INOUT                    (PORT_INOUT2_MODE)
#define SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT32_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT32_I2C_0_I2C0_SCL_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT32_PFE_MAC0_PFE_MAC0_PPS_0                 (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT32_BOOT_RCON23                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT32_FLEXRAY_0_FR_RXD_B                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT32_I2C_0_I2C0_SCL_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT32_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0         (PORT_INPUT4_MODE)
#define SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN        (PORT_INPUT5_MODE)
#define SIUL2_0_PORT32_I2C_0_I2C0_SCL_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT33_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT33_I2C_4_I2C4_SDA_OUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT33_BOOT_RCON24                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT33_SIUL_OFFCC_EIRQ_13                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT33_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0         (PORT_INPUT2_MODE)
#define SIUL2_0_PORT33_PFE_MAC0_PFE_MAC0_CRS                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT33_I2C_4_I2C4_SDA_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT33_I2C_4_I2C4_SDA_INOUT                    (PORT_INOUT1_MODE)
#define SIUL2_0_PORT34_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT34_I2C_4_I2C4_SCL_OUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT34_BOOT_RCON25                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT34_SIUL_OFFCC_EIRQ_14                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT34_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0         (PORT_INPUT2_MODE)
#define SIUL2_0_PORT34_PFE_MAC0_PFE_MAC0_COL                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT34_I2C_4_I2C4_SCL_IN                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT34_I2C_4_I2C4_SCL_INOUT                    (PORT_INOUT2_MODE)
#define SIUL2_0_PORT35_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT35_PFE_MAC0_PFE_MAC0_PPS_0                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT35_BOOT_RCON26                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT35_SIUL_OFFCC_EIRQ_15                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT36_GPI                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT36_BOOT_RCON27                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT36_LLCE_LIN_1_LLCE_LIN1_RX                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT36_LINFLEX_1_LIN1_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT36_WKPU_WKUP17                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT36_SIUL_OFFCC_EIRQ_27                      (PORT_INPUT3_MODE)
#define SIUL2_0_PORT36_ADCSAR_0_ADCSAR0_TRIG                   (PORT_INPUT4_MODE)
#define SIUL2_0_PORT37_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT37_LLCE_LIN_2_LLCE_LIN2_TX                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT37_BOOT_RCON28                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT37_SIUL_OFFCC_EIRQ_28                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT37_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0         (PORT_INPUT2_MODE)
#define SIUL2_0_PORT37_ADCSAR_1_ADCSAR1_TRIG                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT38_GPI                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT38_BOOT_RCON29                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT38_LLCE_LIN_2_LLCE_LIN2_RX                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT38_WKPU_WKUP18                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT38_SIUL_OFFCC_EIRQ_29                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT38_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0         (PORT_INPUT3_MODE)
#define SIUL2_0_PORT38_ADCSAR_1_ADCSAR1_INJ_TRIG               (PORT_INPUT4_MODE)
#define SIUL2_0_PORT39_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT39_LLCE_LIN_3_LLCE_LIN3_TX                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT39_PFE_MAC0_PFE_MAC0_PPS_0                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT39_BOOT_RCON30                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT39_SIUL_OFFCC_EIRQ_30                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT39_PFE_MAC0_PFE_MAC0_COL                   (PORT_INPUT2_MODE)
#define SIUL2_0_PORT40_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT40_LLCE_LIN_1_LLCE_LIN1_TX                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT40_LINFLEX_1_LIN1_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT40_BOOT_RCON31                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT40_SIUL_OFFCC_EIRQ_31                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT40_ADCSAR_0_ADCSAR0_INJ_TRIG               (PORT_INPUT2_MODE)
#define SIUL2_0_PORT41_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT41_LINFLEX_0_LIN0_TX                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT41_FLEXCAN_2_CAN2_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_OUT                    (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT41_DSPI_1_DSPI1_PCS1                       (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT41_PFE_PFE_UART_TX                         (PORT_ALT6_FUNC_MODE)
#define SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_IN                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT41_PFE_MAC0_PFE_MAC0_RX_ER                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT41_PFE_MAC2_PFE_MAC2_RX_ER                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_INOUT                  (PORT_INOUT4_MODE)
#define SIUL2_0_PORT42_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT42_DSPI_1_DSPI1_PCS2                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT42_LINFLEX_0_LIN0_RX                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT42_FLEXCAN_2_CAN2_RX                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT42_DSPI_4_DSPI4_SIN                        (PORT_INPUT4_MODE)
#define SIUL2_0_PORT42_PFE_PFE_UART_RX                         (PORT_INPUT5_MODE)
#define SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_0_PORT43_GPI                                     (PORT_GPIO_MODE)
#define SIUL2_0_PORT43_FLEXCAN_0_CAN0_RX                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT43_LLCE_CAN_0_LLCE_CAN0_RX                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT43_WKPU_WKUP0                              (PORT_ONLY_INPUT_MODE)
#define SIUL2_0_PORT44_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT44_FLEXCAN_0_CAN0_TX                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT44_LLCE_CAN_0_LLCE_CAN0_TX                 (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT45_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT45_MISC_TAMPER_LOOP_OUT0                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT45_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1           (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT46_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT46_USDHC_0_SD0_CLK                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT47_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT47_USDHC_0_SD0_CMD_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT47_USDHC_0_SD0_CMD_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_IN                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT47_USDHC_0_SD0_CMD_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT48_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT48_USDHC_0_SD0_D_0_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT48_QUADSPI_QSPI_CS_B0                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT48_I2C_2_I2C2_SCL_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT48_USDHC_0_SD0_D_0_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT48_I2C_2_I2C2_SCL_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT48_USDHC_0_SD0_D_0_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT48_I2C_2_I2C2_SCL_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT49_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT49_USDHC_0_SD0_D_1_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT49_QUADSPI_QSPI_CS_B1                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT49_I2C_1_I2C1_SCL_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT49_USDHC_0_SD0_D_1_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT49_QUADSPI_QSPI_INTB_b                     (PORT_INPUT2_MODE)
#define SIUL2_0_PORT49_I2C_1_I2C1_SCL_IN                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT49_USDHC_0_SD0_D_1_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT49_I2C_1_I2C1_SCL_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT50_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT50_USDHC_0_SD0_D_2_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT50_I2C_1_I2C1_SDA_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT50_I2C_1_I2C1_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT50_USDHC_0_SD0_D_2_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_IN                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT50_USDHC_0_SD0_D_2_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT50_I2C_1_I2C1_SDA_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT51_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT51_USDHC_0_SD0_D_3_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT51_I2C_3_I2C3_SCL_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT51_USDHC_0_SD0_D_3_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_IN                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT51_I2C_3_I2C3_SCL_IN                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT51_USDHC_0_SD0_D_3_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT51_I2C_3_I2C3_SCL_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT52_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT52_USDHC_0_SD0_D_4_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT52_I2C_2_I2C2_SDA_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT52_DSPI_0_DSPI0_PCS1                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT52_I2C_2_I2C2_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT52_USDHC_0_SD0_D_4_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_IN                   (PORT_INPUT3_MODE)
#define SIUL2_0_PORT52_USDHC_0_SD0_D_4_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_INOUT                (PORT_INOUT2_MODE)
#define SIUL2_0_PORT52_I2C_2_I2C2_SDA_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT53_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT53_USDHC_0_SD0_D_5_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT53_I2C_3_I2C3_SDA_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT53_DSPI_0_DSPI0_PCS2                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT53_I2C_3_I2C3_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT53_USDHC_0_SD0_D_5_IN                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_IN                (PORT_INPUT3_MODE)
#define SIUL2_0_PORT53_USDHC_0_SD0_D_5_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT53_I2C_3_I2C3_SDA_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT54_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT54_USDHC_0_SD0_D_6_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT54_QUADSPI_QSPI_CK_B                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT54_DSPI_1_DSPI1_PCS1                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT54_USDHC_0_SD0_D_6_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT54_USDHC_0_SD0_D_6_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT55_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT55_USDHC_0_SD0_D_7_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT55_QUADSPI_QSPI_CK_B_b                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C0_SCL_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT55_DSPI_1_DSPI1_PCS2                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT55_USDHC_0_SD0_D_7_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C0_SCL_IN                       (PORT_INPUT2_MODE)
#define SIUL2_0_PORT55_USDHC_0_SD0_D_7_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT55_I2C_0_I2C0_SCL_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT56_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT56_USDHC_0_SD0_RST                         (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT57_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT57_USDHC_0_SD0_VSELECT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT58_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT58_USDHC_0_SD0_DQS                         (PORT_INPUT1_MODE)
#define SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_IN                (PORT_INPUT2_MODE)
#define SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_0_PORT59_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_OUT       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT59_MISC_TAMPER_EXTIN0                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN        (PORT_INPUT2_MODE)
#define SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT     (PORT_INOUT2_MODE)
#define SIUL2_0_PORT60_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT60_GMAC_0_GMAC0_MDC                        (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT60_PFE_MAC1_PFE_MAC1_MDC                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_IN        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT61_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT61_GMAC_0_GMAC0_MD_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT61_GMAC_0_GMAC0_MD_IN                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_IN        (PORT_INPUT3_MODE)
#define SIUL2_0_PORT61_GMAC_0_GMAC0_MD_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT62_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_C2_TXD_2              (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN        (PORT_INPUT3_MODE)
#define SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_RX_ER                 (PORT_INPUT4_MODE)
#define SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_TXD_2                 (PORT_INPUT5_MODE)
#define SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT63_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT63_DSPI_3_DSPI3_SOUT                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_OUT       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT63_GMAC_0_GMAC0_RMII_REF_CLK               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_C2_TXD_3              (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT63_GMAC_0_GMAC0_RX_ER                      (PORT_INPUT1_MODE)
#define SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_RMII_REF_CLK          (PORT_INPUT3_MODE)
#define SIUL2_0_PORT63_FLEXTIMER_1_FTM1_EXT_CLK                (PORT_INPUT4_MODE)
#define SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN        (PORT_INPUT5_MODE)
#define SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_TXD_3                 (PORT_INPUT6_MODE)
#define SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT     (PORT_INOUT3_MODE)
#define SIUL2_0_PORT64_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT64_LINFLEX_2_LIN2_TX                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT64_FLEXCAN_0_CAN0_TX                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_OUT                (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_OUT            (PORT_ALT5_FUNC_MODE)
#define SIUL2_0_PORT64_GMAC_0_GMAC0_COL                        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_IN                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_IN             (PORT_INPUT4_MODE)
#define SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_INOUT              (PORT_INOUT4_MODE)
#define SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_INOUT          (PORT_INOUT5_MODE)
#define SIUL2_0_PORT65_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT65_GMAC_0_GMAC0_CRS                        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_IN                  (PORT_INPUT2_MODE)
#define SIUL2_0_PORT65_LINFLEX_2_LIN2_RX                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT65_FLEXCAN_0_CAN0_RX                       (PORT_INPUT4_MODE)
#define SIUL2_0_PORT65_PFE_MAC2_PFE_MAC2_RXDV_IN               (PORT_INPUT5_MODE)
#define SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_IN                 (PORT_INPUT6_MODE)
#define SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT66_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT66_DSPI_0_DSPI0_PCS3                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_IN             (PORT_INPUT2_MODE)
#define SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_INOUT          (PORT_INOUT2_MODE)
#define SIUL2_0_PORT67_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_OUT             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT67_DSPI_0_DSPI0_PCS4                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_INOUT           (PORT_INOUT2_MODE)
#define SIUL2_0_PORT68_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_OUT             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT68_DSPI_1_DSPI1_PCS3                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_INOUT           (PORT_INOUT2_MODE)
#define SIUL2_0_PORT69_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_OUT             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT69_DSPI_1_DSPI1_PCS4                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_INOUT           (PORT_INOUT2_MODE)
#define SIUL2_0_PORT70_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_OUT             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT70_DSPI_2_DSPI2_PCS3                       (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_IN              (PORT_INPUT1_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC0_RX_ER                      (PORT_INPUT2_MODE)
#define SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_RX_ER                 (PORT_INPUT3_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_IN                   (PORT_INPUT4_MODE)
#define SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_INOUT           (PORT_INOUT2_MODE)
#define SIUL2_0_PORT71_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_OUT           (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_OUT             (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT71_DSPI_2_DSPI2_PCS4                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_IN            (PORT_INPUT1_MODE)
#define SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_RMII_REF_CLK          (PORT_INPUT2_MODE)
#define SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_IN              (PORT_INPUT3_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_IN                   (PORT_INPUT4_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_INOUT         (PORT_INOUT2_MODE)
#define SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_INOUT           (PORT_INOUT3_MODE)
#define SIUL2_0_PORT72_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT72_DSPI_3_DSPI3_PCS3                       (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_OUT            (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_IN                  (PORT_INPUT1_MODE)
#define SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_IN             (PORT_INPUT2_MODE)
#define SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_INOUT          (PORT_INOUT3_MODE)
#define SIUL2_0_PORT73_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT73_DSPI_3_DSPI3_PCS4                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT73_PFE_MAC1_PFE_MAC1_RXDV_IN               (PORT_INPUT1_MODE)
#define SIUL2_0_PORT73_GMAC_0_GMAC0_RXDV_IN                    (PORT_INPUT2_MODE)
#define SIUL2_0_PORT74_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT74_DSPI_4_DSPI4_PCS3                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT74_GMAC_0_GMAC0_RXD_0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT74_PFE_MAC1_PFE_MAC1_RXD_0_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT75_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT75_DSPI_4_DSPI4_PCS4                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT75_GMAC_0_GMAC0_RXD_1_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT75_PFE_MAC1_PFE_MAC1_RXD_1_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT76_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT76_DSPI_5_DSPI5_PCS3                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT76_GMAC_0_GMAC0_RXD_2_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT76_PFE_MAC1_PFE_MAC1_RXD_2_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT77_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT77_DSPI_5_DSPI5_PCS4                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT77_GMAC_0_GMAC0_RXD_3_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT77_PFE_MAC1_PFE_MAC1_RXD_3_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT78_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_OUT             (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_OUT             (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT78_DSPI_0_DSPI0_PCS5                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_IN              (PORT_INPUT2_MODE)
#define SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_IN              (PORT_INPUT3_MODE)
#define SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_INOUT           (PORT_INOUT1_MODE)
#define SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_INOUT           (PORT_INOUT2_MODE)
#define SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT79_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT79_I2C_3_I2C3_SCL_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT79_DSPI_0_DSPI0_PCS6                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT79_I2C_3_I2C3_SCL_IN                       (PORT_INPUT3_MODE)
#define SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT79_I2C_3_I2C3_SCL_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT80_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT80_PFE_MAC2_PFE_MAC2_MDC                   (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT80_PFE_MAC0_PFE_MAC0_MDC                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT80_DSPI_0_DSPI0_PCS7                       (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT81_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_OUT                 (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_OUT                (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_IN                 (PORT_INPUT1_MODE)
#define SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_IN                  (PORT_INPUT3_MODE)
#define SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_INOUT               (PORT_INOUT1_MODE)
#define SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_INOUT              (PORT_INOUT3_MODE)
#define SIUL2_0_PORT82_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT82_PFE_MAC0_PFE_MAC0_MDC                   (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT82_PFE_MAC2_PFE_MAC2_MDC                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT82_I2C_3_I2C3_SDA_OUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT82_GMAC_0_GMAC0_RMII_REF_CLK               (PORT_ALT4_FUNC_MODE)
#define SIUL2_0_PORT82_I2C_3_I2C3_SDA_IN                       (PORT_INPUT1_MODE)
#define SIUL2_0_PORT82_I2C_3_I2C3_SDA_INOUT                    (PORT_INOUT3_MODE)
#define SIUL2_0_PORT83_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT83_MISC_CLKOUT0                            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT84_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT84_MISC_CLKOUT1                            (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT85_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT86_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT87_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT88_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT89_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT90_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT91_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT92_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_IN                (PORT_INPUT1_MODE)
#define SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_0_PORT93_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_OUT                  (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_IN                   (PORT_INPUT1_MODE)
#define SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_INOUT                (PORT_INOUT1_MODE)
#define SIUL2_0_PORT94_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT94_QUADSPI_QSPI_INTA_b                     (PORT_INPUT1_MODE)
#define SIUL2_0_PORT95_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_OUT                (PORT_ALT2_FUNC_MODE)
#define SIUL2_0_PORT95_FLEXRAY_0_FR_DBG_1                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_0_PORT95_DSPI_1_DSPI1_SIN                        (PORT_INPUT1_MODE)
#define SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_IN                 (PORT_INPUT2_MODE)
#define SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_INOUT              (PORT_INOUT2_MODE)
#define SIUL2_0_PORT96_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT96_QUADSPI_QSPI_CK_A                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT97_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT97_QUADSPI_QSPI_CK_A_b                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT98_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT98_QUADSPI_QSPI_CK_2A                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT99_GPIO                                    (PORT_GPIO_MODE)
#define SIUL2_0_PORT99_QUADSPI_QSPI_CK_2A_b                    (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT100_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_0_PORT100_QUADSPI_QSPI_CS_A0                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_0_PORT101_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_0_PORT101_QUADSPI_QSPI_CS_A1                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT112_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_IN                 (PORT_INPUT1_MODE)
#define SIUL2_1_PORT112_FLEXCAN_1_CAN1_RX                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT112_PFE_MAC2_PFE_MAC2_RXD_3_IN             (PORT_INPUT4_MODE)
#define SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT113_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_OUT            (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT113_I2C_1_I2C1_SDA_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT113_I2C_1_I2C1_SDA_IN                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT113_SIUL_OFFCC_EIRQ_23                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN       (PORT_INPUT3_MODE)
#define SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_IN             (PORT_INPUT4_MODE)
#define SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_IN             (PORT_INPUT5_MODE)
#define SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_INOUT          (PORT_INOUT1_MODE)
#define SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_INOUT          (PORT_INOUT2_MODE)
#define SIUL2_1_PORT113_I2C_1_I2C1_SDA_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_1_PORT114_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_OUT            (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT114_I2C_1_I2C1_SCL_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT114_DSPI_5_DSPI5_PCS1                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT114_I2C_1_I2C1_SCL_IN                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT114_SIUL_OFFCC_EIRQ_24                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_RX_ER                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_RX_ER                (PORT_INPUT4_MODE)
#define SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_IN             (PORT_INPUT6_MODE)
#define SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_IN             (PORT_INPUT7_MODE)
#define SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_INOUT          (PORT_INOUT1_MODE)
#define SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_INOUT          (PORT_INOUT2_MODE)
#define SIUL2_1_PORT114_I2C_1_I2C1_SCL_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_1_PORT115_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_OUT            (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT115_GMAC_0_GMAC0_RMII_REF_CLK              (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT115_DSPI_5_DSPI5_PCS2                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT115_FLEXTIMER_0_FTM0_CH5                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT115_SIUL_OFFCC_EIRQ_25                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN       (PORT_INPUT3_MODE)
#define SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_RMII_REF_CLK         (PORT_INPUT4_MODE)
#define SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_RMII_REF_CLK         (PORT_INPUT5_MODE)
#define SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_IN             (PORT_INPUT6_MODE)
#define SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_IN             (PORT_INPUT7_MODE)
#define SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_INOUT          (PORT_INOUT1_MODE)
#define SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_INOUT          (PORT_INOUT2_MODE)
#define SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_1_PORT116_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_OUT           (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_OUT           (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_IN            (PORT_INPUT1_MODE)
#define SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_IN            (PORT_INPUT2_MODE)
#define SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT116_FLEXTIMER_0_FTM0_EXT_CLK               (PORT_INPUT4_MODE)
#define SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_INOUT         (PORT_INOUT3_MODE)
#define SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_INOUT         (PORT_INOUT4_MODE)
#define SIUL2_1_PORT117_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_OUT       (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT117_PFE_MAC0_PFE_MAC0_RXDV_IN              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT117_PFE_MAC2_PFE_MAC2_RXDV_IN              (PORT_INPUT2_MODE)
#define SIUL2_1_PORT117_SIUL_OFFCC_EIRQ_26                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN        (PORT_INPUT4_MODE)
#define SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT     (PORT_INOUT1_MODE)
#define SIUL2_1_PORT118_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_OUT               (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_OUT       (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT118_PFE_MAC0_PFE_MAC0_RXD_0_IN             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT118_PFE_MAC2_PFE_MAC2_RXD_0_IN             (PORT_INPUT2_MODE)
#define SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN        (PORT_INPUT4_MODE)
#define SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_INOUT             (PORT_INOUT1_MODE)
#define SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT     (PORT_INOUT2_MODE)
#define SIUL2_1_PORT119_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT119_I2C_2_I2C2_SDA_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT119_PFE_MAC0_PFE_MAC0_RXD_1_IN             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT119_PFE_MAC2_PFE_MAC2_RXD_1_IN             (PORT_INPUT2_MODE)
#define SIUL2_1_PORT119_I2C_2_I2C2_SDA_IN                      (PORT_INPUT3_MODE)
#define SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN       (PORT_INPUT4_MODE)
#define SIUL2_1_PORT119_I2C_2_I2C2_SDA_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT120_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT120_I2C_2_I2C2_SCL_OUT                     (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT120_DSPI_4_DSPI4_PCS1                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT120_PFE_MAC0_PFE_MAC0_RXD_2_IN             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT120_PFE_MAC2_PFE_MAC2_RXD_2_IN             (PORT_INPUT2_MODE)
#define SIUL2_1_PORT120_I2C_2_I2C2_SCL_IN                      (PORT_INPUT3_MODE)
#define SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN       (PORT_INPUT4_MODE)
#define SIUL2_1_PORT120_I2C_2_I2C2_SCL_INOUT                   (PORT_INOUT1_MODE)
#define SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT121_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT121_DSPI_4_DSPI4_PCS2                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT121_PFE_MAC0_PFE_MAC0_RXD_3_IN             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT121_PFE_MAC2_PFE_MAC2_RXD_3_IN             (PORT_INPUT2_MODE)
#define SIUL2_1_PORT122_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_OUT           (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_OUT           (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT122_I2C_0_I2C0_SDA_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_IN            (PORT_INPUT1_MODE)
#define SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_IN            (PORT_INPUT2_MODE)
#define SIUL2_1_PORT122_I2C_0_I2C0_SDA_IN                      (PORT_INPUT3_MODE)
#define SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_INOUT         (PORT_INOUT1_MODE)
#define SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_INOUT         (PORT_INOUT2_MODE)
#define SIUL2_1_PORT122_I2C_0_I2C0_SDA_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT144_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_OUT            (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_OUT            (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT144_I2C_0_I2C0_SCL_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT144_I2C_0_I2C0_SCL_IN                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_IN             (PORT_INPUT2_MODE)
#define SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_IN             (PORT_INPUT3_MODE)
#define SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_INOUT          (PORT_INOUT1_MODE)
#define SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_INOUT          (PORT_INOUT2_MODE)
#define SIUL2_1_PORT144_I2C_0_I2C0_SCL_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT145_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT145_LLCE_CAN_1_LLCE_CAN1_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT145_FLEXTIMER_0_FTM0_PHA                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_IN       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT146_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT146_LLCE_CAN_1_LLCE_CAN1_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT146_WKPU_WKUP1                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT147_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT147_LLCE_CAN_2_LLCE_CAN2_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_IN       (PORT_INPUT1_MODE)
#define SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT148_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT148_LLCE_CAN_2_LLCE_CAN2_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT148_WKPU_WKUP2                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT149_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT149_LLCE_CAN_3_LLCE_CAN3_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT149_FLEXTIMER_0_FTM0_PHB                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT150_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT150_LLCE_CAN_3_LLCE_CAN3_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT150_WKPU_WKUP3                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT151_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT151_LLCE_CAN_4_LLCE_CAN4_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT151_PFE_MAC0_PFE_MAC0_PPS_0                (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_IN                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT151_SIUL_OFFCC_EIRQ_0                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_1_PORT152_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT152_LLCE_CAN_4_LLCE_CAN4_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT152_FLEXTIMER_0_FTM0_EXT_CLK               (PORT_INPUT2_MODE)
#define SIUL2_1_PORT152_PFE_MAC0_PFE_MAC0_RX_ER                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT152_PFE_MAC2_PFE_MAC2_RX_ER                (PORT_INPUT4_MODE)
#define SIUL2_1_PORT152_WKPU_WKUP4                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT152_SIUL_OFFCC_EIRQ_1                      (PORT_INPUT5_MODE)
#define SIUL2_1_PORT153_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT153_LLCE_CAN_5_LLCE_CAN5_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT153_I2C_0_I2C0_SDA_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_IN                    (PORT_INPUT1_MODE)
#define SIUL2_1_PORT153_I2C_0_I2C0_SDA_IN                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_1_PORT153_I2C_0_I2C0_SDA_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT154_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT154_LLCE_CAN_5_LLCE_CAN5_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT154_WKPU_WKUP5                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT154_SIUL_OFFCC_EIRQ_8                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT155_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT155_LLCE_CAN_6_LLCE_CAN6_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT155_DSPI_4_DSPI4_PCS1                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT155_RTC_RTC_EXT_CLK                        (PORT_INPUT2_MODE)
#define SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_INOUT                (PORT_INOUT2_MODE)
#define SIUL2_1_PORT156_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT156_LLCE_CAN_6_LLCE_CAN6_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT156_WKPU_WKUP6                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT156_DSPI_2_DSPI2_SCK                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT156_FLEXTIMER_1_FTM1_PHA                   (PORT_INPUT3_MODE)
#define SIUL2_1_PORT157_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT157_LLCE_CAN_7_LLCE_CAN7_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT157_DSPI_2_DSPI2_SOUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT157_DSPI_4_DSPI4_PCS2                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT158_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT158_LLCE_CAN_7_LLCE_CAN7_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT158_WKPU_WKUP7                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT158_DSPI_2_DSPI2_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT158_FLEXTIMER_1_FTM1_PHB                   (PORT_INPUT3_MODE)
#define SIUL2_1_PORT159_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT159_LLCE_CAN_8_LLCE_CAN8_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT159_I2C_0_I2C0_SCL_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT159_DSPI_5_DSPI5_PCS1                      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_IN                    (PORT_INPUT1_MODE)
#define SIUL2_1_PORT159_I2C_0_I2C0_SCL_IN                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_1_PORT159_I2C_0_I2C0_SCL_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT160_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT160_LLCE_CAN_8_LLCE_CAN8_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT160_WKPU_WKUP8                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT160_SIUL_OFFCC_EIRQ_9                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT161_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT161_LLCE_CAN_9_LLCE_CAN9_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT161_I2C_0_I2C0_SDA_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT161_DSPI_5_DSPI5_PCS2                      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT161_I2C_0_I2C0_SDA_IN                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_INOUT                (PORT_INOUT2_MODE)
#define SIUL2_1_PORT161_I2C_0_I2C0_SDA_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT162_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT162_LLCE_CAN_9_LLCE_CAN9_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT162_WKPU_WKUP9                             (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT162_DSPI_3_DSPI3_SCK                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT163_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT163_LLCE_CAN_10_LLCE_CAN10_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT163_DSPI_3_DSPI3_SOUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT163_I2C_1_I2C1_SCL_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT163_I2C_1_I2C1_SCL_IN                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT163_I2C_1_I2C1_SCL_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT164_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT164_LLCE_CAN_10_LLCE_CAN10_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT164_WKPU_WKUP10                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT164_DSPI_3_DSPI3_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT165_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT165_LLCE_CAN_11_LLCE_CAN11_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT165_I2C_1_I2C1_SDA_OUT                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_IN                    (PORT_INPUT1_MODE)
#define SIUL2_1_PORT165_I2C_1_I2C1_SDA_IN                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT165_SIUL_OFFCC_EIRQ_10                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_1_PORT165_I2C_1_I2C1_SDA_INOUT                   (PORT_INOUT3_MODE)
#define SIUL2_1_PORT166_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT166_LLCE_CAN_11_LLCE_CAN11_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT166_WKPU_WKUP11                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT166_DSPI_4_DSPI4_SCK                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT167_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT167_LLCE_CAN_12_LLCE_CAN12_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_IN                (PORT_INPUT2_MODE)
#define SIUL2_1_PORT167_PFE_MAC0_PFE_MAC0_COL                  (PORT_INPUT3_MODE)
#define SIUL2_1_PORT167_PFE_MAC2_PFE_MAC2_COL                  (PORT_INPUT4_MODE)
#define SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_INOUT                (PORT_INOUT2_MODE)
#define SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_1_PORT168_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT168_LLCE_CAN_12_LLCE_CAN12_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT168_WKPU_WKUP12                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT168_SIUL_OFFCC_EIRQ_11                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT168_PFE_MAC0_PFE_MAC0_CRS                  (PORT_INPUT3_MODE)
#define SIUL2_1_PORT168_PFE_MAC2_PFE_MAC2_CRS                  (PORT_INPUT4_MODE)
#define SIUL2_1_PORT169_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT169_LLCE_CAN_13_LLCE_CAN13_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT169_DSPI_4_DSPI4_SOUT                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_OUT      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN       (PORT_INPUT1_MODE)
#define SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT    (PORT_INOUT3_MODE)
#define SIUL2_1_PORT170_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT170_LLCE_CAN_13_LLCE_CAN13_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT170_WKPU_WKUP13                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT170_DSPI_4_DSPI4_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT170_PFE_MAC0_PFE_MAC0_RX_ER                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT170_PFE_MAC2_PFE_MAC2_RX_ER                (PORT_INPUT4_MODE)
#define SIUL2_1_PORT171_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT171_LLCE_CAN_14_LLCE_CAN14_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT171_LINFLEX_2_LIN2_TX                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_OUT      (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_OUT                  (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_IN                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_IN                   (PORT_INPUT2_MODE)
#define SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN       (PORT_INPUT3_MODE)
#define SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT    (PORT_INOUT4_MODE)
#define SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_INOUT                (PORT_INOUT5_MODE)
#define SIUL2_1_PORT172_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT172_LLCE_CAN_14_LLCE_CAN14_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT172_WKPU_WKUP14                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT172_LINFLEX_2_LIN2_RX                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT172_DSPI_5_DSPI5_SCK                       (PORT_INPUT3_MODE)
#define SIUL2_1_PORT173_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT173_LLCE_CAN_15_LLCE_CAN15_TX              (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT173_DSPI_5_DSPI5_SOUT                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT173_MISC_TAMPER_LOOP_OUT0                  (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_IN                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_1_PORT174_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT174_LLCE_CAN_15_LLCE_CAN15_RX              (PORT_INPUT1_MODE)
#define SIUL2_1_PORT174_WKPU_WKUP15                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT174_DSPI_5_DSPI5_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT174_MISC_TAMPER_EXTIN0                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT175_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT175_LLCE_LIN_0_LLCE_LIN0_TX                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT175_LINFLEX_0_LIN0_TX                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_OUT      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_OUT                   (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT175_I2C_1_I2C1_SCL_OUT                     (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT175_LLCE_LPSPI_3_LLCE_LPSPI3_SIN           (PORT_ALT6_FUNC_MODE)
#define SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_IN                    (PORT_INPUT1_MODE)
#define SIUL2_1_PORT175_I2C_1_I2C1_SCL_IN                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN       (PORT_INPUT3_MODE)
#define SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT    (PORT_INOUT3_MODE)
#define SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_INOUT                 (PORT_INOUT4_MODE)
#define SIUL2_1_PORT175_I2C_1_I2C1_SCL_INOUT                   (PORT_INOUT5_MODE)
#define SIUL2_1_PORT176_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT176_LLCE_LIN_0_LLCE_LIN0_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT176_WKPU_WKUP16                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT176_LINFLEX_0_LIN0_RX                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT177_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT177_LLCE_FLEXRAY_LLCE_FR_TXE_A_b           (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_OUT       (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT177_PFE_MAC1_PFE_MAC1_MDC                  (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT177_GMAC_0_GMAC0_MDC                       (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT177_SIUL_OFFCC_EIRQ_2                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_IN                (PORT_INPUT2_MODE)
#define SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_IN        (PORT_INPUT3_MODE)
#define SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_INOUT     (PORT_INOUT2_MODE)
#define SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT178_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT178_LLCE_FLEXRAY_LLCE_FR_TXD_A             (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_OUT               (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT178_GMAC_0_GMAC0_MD_OUT                    (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT178_SIUL_OFFCC_EIRQ_3                      (PORT_INPUT1_MODE)
#define SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_IN                (PORT_INPUT2_MODE)
#define SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT178_GMAC_0_GMAC0_MD_IN                     (PORT_INPUT4_MODE)
#define SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_INOUT             (PORT_INOUT4_MODE)
#define SIUL2_1_PORT178_GMAC_0_GMAC0_MD_INOUT                  (PORT_INOUT5_MODE)
#define SIUL2_1_PORT179_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT179_LLCE_FLEXRAY_LLCE_FR_RXD_A             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT179_LLCE_LPSPI_3_LLCE_LPSPI3_SIN           (PORT_INPUT2_MODE)
#define SIUL2_1_PORT179_WKPU_WKUP20                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT179_SIUL_OFFCC_EIRQ_4                      (PORT_INPUT3_MODE)
#define SIUL2_1_PORT180_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT180_LLCE_FLEXRAY_LLCE_FR_TXE_B_b           (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_OUT               (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT180_GMAC_0_GMAC0_PST_TS_TRIG_0             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT180_GMAC_0_GMAC0_AUX_TRIG_2                (PORT_INPUT2_MODE)
#define SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT180_SIUL_OFFCC_EIRQ_5                      (PORT_INPUT4_MODE)
#define SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_INOUT             (PORT_INOUT2_MODE)
#define SIUL2_1_PORT181_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT181_LLCE_FLEXRAY_LLCE_FR_TXD_B             (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_OUT      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_OUT               (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT181_GMAC_0_GMAC0_PST_TS_TRIG_1             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT181_GMAC_0_GMAC0_AUX_TRIG_3                (PORT_INPUT2_MODE)
#define SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT181_SIUL_OFFCC_EIRQ_6                      (PORT_INPUT4_MODE)
#define SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_INOUT    (PORT_INOUT2_MODE)
#define SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_INOUT             (PORT_INOUT3_MODE)
#define SIUL2_1_PORT182_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT182_LLCE_FLEXRAY_LLCE_FR_RXD_B             (PORT_INPUT1_MODE)
#define SIUL2_1_PORT182_WKPU_WKUP21                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT182_SIUL_OFFCC_EIRQ_7                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT183_GPI                                    (PORT_GPIO_MODE)
#define SIUL2_1_PORT183_LLCE_LIN_3_LLCE_LIN3_RX                (PORT_INPUT1_MODE)
#define SIUL2_1_PORT183_PFE_MAC0_PFE_MAC0_CRS                  (PORT_INPUT2_MODE)
#define SIUL2_1_PORT183_WKPU_WKUP19                            (PORT_ONLY_INPUT_MODE)
#define SIUL2_1_PORT184_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_OUT                   (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT184_FLEXCAN_2_CAN2_TX                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT184_FLEXRAY_0_FR_DBG_0                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT184_LLCE_FLEXRAY_LLCE_FR_DBG_0             (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT184_PFE_MAC2_PFE_MAC2_C2_TX_CLK            (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT184_USB_USB_ULPI_CLK                       (PORT_INPUT1_MODE)
#define SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_IN                    (PORT_INPUT2_MODE)
#define SIUL2_1_PORT184_SIUL_OFFCC_EIRQ_16                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT184_PFE_MAC2_PFE_MAC2_TX_CLK               (PORT_INPUT4_MODE)
#define SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_INOUT                 (PORT_INOUT1_MODE)
#define SIUL2_1_PORT185_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT185_DSPI_2_DSPI2_SOUT                      (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT185_FLEXCAN_3_CAN3_TX                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT185_FLEXRAY_0_FR_DBG_1                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT185_LLCE_FLEXRAY_LLCE_FR_DBG_1             (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT185_PFE_MAC2_PFE_MAC2_C2_TX_EN             (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT185_USB_USB_ULPI_DIR                       (PORT_INPUT1_MODE)
#define SIUL2_1_PORT185_SIUL_OFFCC_EIRQ_17                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT185_PFE_MAC2_PFE_MAC2_TX_EN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT186_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT186_USB_USB_ULPI_STP                       (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_OUT                  (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_OUT      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT186_PFE_MAC2_PFE_MAC2_C2_TXD_0             (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT186_DSPI_2_DSPI2_PCS1                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_IN                   (PORT_INPUT1_MODE)
#define SIUL2_1_PORT186_FLEXCAN_3_CAN3_RX                      (PORT_INPUT2_MODE)
#define SIUL2_1_PORT186_SIUL_OFFCC_EIRQ_18                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN       (PORT_INPUT4_MODE)
#define SIUL2_1_PORT186_PFE_MAC2_PFE_MAC2_TXD_0                (PORT_INPUT5_MODE)
#define SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_INOUT                (PORT_INOUT2_MODE)
#define SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT    (PORT_INOUT3_MODE)
#define SIUL2_1_PORT187_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_OUT      (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT187_PFE_MAC2_PFE_MAC2_C2_TXD_1             (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT187_DSPI_2_DSPI2_PCS2                      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT187_USB_USB_ULPI_NXT                       (PORT_INPUT1_MODE)
#define SIUL2_1_PORT187_DSPI_2_DSPI2_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT187_FLEXCAN_2_CAN2_RX                      (PORT_INPUT3_MODE)
#define SIUL2_1_PORT187_SIUL_OFFCC_EIRQ_19                     (PORT_INPUT4_MODE)
#define SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT187_PFE_MAC2_PFE_MAC2_TXD_1                (PORT_INPUT6_MODE)
#define SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT    (PORT_INOUT1_MODE)
#define SIUL2_1_PORT188_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT188_FLEXRAY_0_FR_DBG_2                     (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT188_LLCE_FLEXRAY_LLCE_FR_DBG_2             (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_OUT               (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT188_DSPI_3_DSPI3_PCS1                      (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_OUT       (PORT_ALT6_FUNC_MODE)
#define SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_IN                 (PORT_INPUT1_MODE)
#define SIUL2_1_PORT188_DSPI_3_DSPI3_SIN                       (PORT_INPUT2_MODE)
#define SIUL2_1_PORT188_SIUL_OFFCC_EIRQ_20                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN        (PORT_INPUT4_MODE)
#define SIUL2_1_PORT188_PFE_MAC2_PFE_MAC2_RXD_0_IN             (PORT_INPUT5_MODE)
#define SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_IN                (PORT_INPUT6_MODE)
#define SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_INOUT             (PORT_INOUT4_MODE)
#define SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT     (PORT_INOUT6_MODE)
#define SIUL2_1_PORT189_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_OUT                   (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT189_FLEXRAY_0_FR_DBG_3                     (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT189_LLCE_FLEXRAY_LLCE_FR_DBG_3             (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_OUT       (PORT_ALT5_FUNC_MODE)
#define SIUL2_1_PORT189_DSPI_3_DSPI3_PCS2                      (PORT_ALT6_FUNC_MODE)
#define SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_IN                 (PORT_INPUT1_MODE)
#define SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_IN                    (PORT_INPUT2_MODE)
#define SIUL2_1_PORT189_SIUL_OFFCC_EIRQ_21                     (PORT_INPUT3_MODE)
#define SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN        (PORT_INPUT4_MODE)
#define SIUL2_1_PORT189_PFE_MAC2_PFE_MAC2_RXD_1_IN             (PORT_INPUT5_MODE)
#define SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_INOUT                 (PORT_INOUT2_MODE)
#define SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT     (PORT_INOUT5_MODE)
#define SIUL2_1_PORT190_GPIO                                   (PORT_GPIO_MODE)
#define SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_OUT                (PORT_ALT1_FUNC_MODE)
#define SIUL2_1_PORT190_FLEXCAN_1_CAN1_TX                      (PORT_ALT2_FUNC_MODE)
#define SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_OUT      (PORT_ALT3_FUNC_MODE)
#define SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_OUT               (PORT_ALT4_FUNC_MODE)
#define SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_IN                 (PORT_INPUT1_MODE)
#define SIUL2_1_PORT190_SIUL_OFFCC_EIRQ_22                     (PORT_INPUT2_MODE)
#define SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_IN                (PORT_INPUT3_MODE)
#define SIUL2_1_PORT190_PFE_MAC2_PFE_MAC2_RXD_2_IN             (PORT_INPUT4_MODE)
#define SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN       (PORT_INPUT5_MODE)
#define SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_INOUT              (PORT_INOUT1_MODE)
#define SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT    (PORT_INOUT3_MODE)
#define SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_INOUT             (PORT_INOUT4_MODE)

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)
/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
#define PORT_SET_PIN_MODE_API           (STD_ON)

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Use/remove Port_SetAsUnusedPin/Port_SetAsUnusedPin function from the compiled driver
*
* @implements
*/
#define PORT_SET_AS_UNUSED_PIN_API           (STD_OFF)

/**
* @brief Use/remove Port_ResetPinMode function from the compiled driver
*
* @implements
*/
#define PORT_RESET_PIN_MODE_API               (STD_OFF)

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API                 (STD_ON)

/**
* @brief The number of configured partition on the platform
*/
#define PORT_MAX_PARTITION              (1U)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
#define PortConf_PortPin_I2C4_CLK 0
#define PortConf_PortPin_I2C4_SDA 1
#define PortConf_PortPin_IGN_KEY 2
#define PortConf_PortPin_VR5510_PWRON2 3

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)4)

/**
* @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16    (138U)
/**
* @brief Port driver Pre-Compile configuration switch
*/
#define    PORT_PRECOMPILE_SUPPORT      (STD_ON)

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Defines for number of entries in the INOUT tables for each of the SIUL2 instances
*/
#define PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)134)
#define PORT_SIUL2_1_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)77)

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
/**
* @brief   Type defining the size of the arrays used to keep the information about pin mode availability
* @details
*
* @api
*/
typedef uint16 Port_PinModeAvailabilityArrayType[PORT_NUM_PIN_MODES_U8][PORT_NUM_16PIN_BLOCKS_U8];

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*/
typedef struct
{
    uint16 u16NumPins;                                                           /**< @brief Number of used pads (to be configured) */
    uint16 u16NumUnusedPins;                                                     /**< @brief Number of unused pads */
    uint16 au16NumImcrs[PORT_NUM_SIUL2_INSTANCES_U8];                            /**< @brief Used pads IMCRs number */
    const Port_Siul2_UnUsedPinType *pUnusedPads;                                 /**< @brief Unused pad id's array and SIUL2 instance */
    const Port_Siul2_UnUsedPinConfigType *pUnusedPadConfig;                      /**< @brief Unused pad configuration */
#ifdef PORT_SIUL2_AE_U8
    const Port_Siul2_UnUsedPinConfigType *pSiul2AEUnusedPadConfig;               /**< @brief Unused pad configuration for SIUL2_AE */
#endif /* PORT_SIUL2_AE_U8 */
    const Port_Siul2_PinConfigType *pUsedPadConfig;                              /**< @brief Used pads data configuration */
    const Port_Siul2_ImcrConfigType *pImcrConfig[PORT_NUM_SIUL2_INSTANCES_U8];   /**< @brief Used pads IMCR configuration */
    const uint32 *pau32Port_PinToPartitionMap;                                   /**< @brief Pointer to pin partition mapping */
    const uint8 *pau8Port_PartitionList;                                         /**< @brief Pointer to used partitions */
    const Siul2_Port_Ip_PinSettingsConfig *IpConfigPtr;                          /**< @brief Ip configuration */
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
* @api
*/
typedef struct
{
    uint16 u16ImcrIdx;   /**< @brief The id of the INMUX register to be configured */
    uint8  u8ImcrSSS;    /**< @brief The value of the INMUX reg for signal allocation */
    uint8  u8ImcrSiulInstance;       /**< @brief The mode to be configured */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
*
* @api
*/
typedef struct
{
    uint16 u16MscrIdx;               /**< @brief The id of the MSCR register to be configured */
    uint8  u8Mode;                   /**< @brief The mode to be configured */
    uint16 u16ImcrIdx;               /**< @brief The id of the INMUX register to be configured */
    uint8  u8ImcrSSS;                /**< @brief The value of the INMUX reg for signal allocation */
    uint8  u8ImcrSiulInstance;       /**< @brief SIUL2 instance where IMCR resides */
} Port_InoutSettingType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
extern const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"


#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
extern const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
extern const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8];

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
extern const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8];

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */
/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */

