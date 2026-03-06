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

#ifndef FLEXCAN_IP_DEVICEREG_H_
#define FLEXCAN_IP_DEVICEREG_H_

/**
*   @file FlexCAN_Ip_DeviceReg.h
*
*   @addtogroup FlexCAN
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
#include "StandardTypes.h"
#include "FlexCAN_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_DEVICEREG_VENDOR_ID_H                      43
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H       4
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H               4
#define FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H               2
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same vendor */
#if (FLEXCAN_IP_DEVICEREG_VENDOR_ID_H != FLEXCAN_IP_CFGDEFINES_VENDOR_ID_H)
    #error "FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Software version */
#if ((FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Default value for register */
/**
* @brief Default value for the MCR register
*/
#define FLEXCAN_IP_MCR_DEFAULT_VALUE_U32               ((uint32)0xD890000FU)

/**
* @brief Default value for the CTRL1 register
*/
#define FLEXCAN_IP_CTRL1_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the TIMER register
*/
#define FLEXCAN_IP_TIMER_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ECR register
*/
#define FLEXCAN_IP_ECR_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the ESR1 register
*/
#define FLEXCAN_IP_ESR1_DEFAULT_VALUE_U32              ((uint32)0x003B0006U)

/**
* @brief Default value for the IMASKx register
*/
#define FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the IFLAG4 register
*/
#define FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32             ((uint32)0xFFFFFFFFU)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CTRL2_DEFAULT_VALUE_U32             ((uint32)0x00100000U)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CBT_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the MECR register
*/
#define FLEXCAN_IP_MECR_DEFAULT_VALUE_U32              ((uint32)0x000C0080U)

/**
* @brief Default value for the ERRIAR register
*/
#define FLEXCAN_IP_ERRIAR_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERRIDPR register
*/
#define FLEXCAN_IP_ERRIDPR_DEFAULT_VALUE_U32           ((uint32)0x00000000U)

/**
* @brief Default value for the ERRIPPR register
*/
#define FLEXCAN_IP_ERRIPPR_DEFAULT_VALUE_U32           ((uint32)0x00000000U)

/**
* @brief Default value for the ERRSR register
*/
#define FLEXCAN_IP_ERRSR_DEFAULT_VALUE_U32             ((uint32)0x000D000DU)

/**
* @brief Default value for the FDCTRL register
*/
#define FLEXCAN_IP_FDCTRL_DEFAULT_VALUE_U32            ((uint32)0x80004100U)

/**
* @brief Default value for the FDCBT register
*/
#define FLEXCAN_IP_FDCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ERFCR register
*/
#define FLEXCAN_IP_ERFCR_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERFIER register
*/
#define FLEXCAN_IP_ERFIER_DEFAULT_VALUE_U32            ((uint32)0x00000000U)

/**
* @brief Default value for the ERFSR register
*/
#define FLEXCAN_IP_ERFSR_DEFAULT_VALUE_U32             ((uint32)0xF8000000U)

/**
* @brief Default value for the EPRS register
*/
#define FLEXCAN_IP_EPRS_DEFAULT_VALUE_U32              ((uint32)0x00000000U)

/**
* @brief Default value for the ENCBT register
*/
#define FLEXCAN_IP_ENCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the EDCBT register
*/
#define FLEXCAN_IP_EDCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ETDC register
*/
#define FLEXCAN_IP_ETDC_DEFAULT_VALUE_U32              ((uint32)0x00000000U)


#if (defined(S32G2XX) || defined(S32G3XX))
    /* @brief number of CAN peripheral has Enhanced Rx FIFO mode */
    #define FLEXCAN_IP_FEATURE_ENHANCED_RX_FIFO_NUM            (4U)
    /** Array initializer of CAN peripheral base addresses has Enhanced Rx FIFO mode*/
    #define FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO       { IP_CAN_0, IP_CAN_1, IP_CAN_2, IP_CAN_3 }
    /* @brief number of CAN peripheral has expandable memory */
    #define FLEXCAN_IP_FEATURE_EXPANDABLE_MEMORY_NUM           (4U)
    /** Array initializer of CAN peripheral base addresses has expandable memory */
    #define FLEXCAN_IP_BASE_PTRS_HAS_EXPANDABLE_MEMORY      { IP_CAN_0, IP_CAN_1, IP_CAN_2, IP_CAN_3 }
#elif defined(S32R45)
    /* @brief number of CAN peripheral has Enhanced Rx FIFO mode */
    #define FLEXCAN_IP_FEATURE_ENHANCED_RX_FIFO_NUM            (8U)
    /** Array initializer of CAN peripheral base addresses has Enhanced Rx FIFO mode*/
    #define FLEXCAN_IP_BASE_PTRS_HAS_ENHANCED_RX_FIFO       { IP_CAN_0, IP_CAN_1, IP_CAN_2, IP_CAN_3, IP_CAN_4, IP_CAN_5, IP_CAN_6, IP_CAN_7 }
    /* @brief number of CAN peripheral has expandable memory */
    #define FLEXCAN_IP_FEATURE_EXPANDABLE_MEMORY_NUM           (8U)
    /** Array initializer of CAN peripheral base addresses has expandable memory */
    #define FLEXCAN_IP_BASE_PTRS_HAS_EXPANDABLE_MEMORY      { IP_CAN_0, IP_CAN_1, IP_CAN_2, IP_CAN_3, IP_CAN_4, IP_CAN_5, IP_CAN_6, IP_CAN_7 }
#endif

#define FLEXCAN_IP_FEATURE_BUSOFF_ERROR_INTERRUPT_UNIFIED      (STD_OFF)

/* specifies if the Enhanced Fifo has separated ISR */
#define FLEXCAN_IP_FEATURE_HAS_ENHANCED_RX_FIFO_INT_SEPARATED    (STD_OFF)

/* Workaround for difference base address naming defined in BASE */
/** Peripheral FLEXCAN_0 base address */
#define FLEXCAN_0_BASE IP_CAN_0_BASE
/** Peripheral FLEXCAN_1 base address */
#define FLEXCAN_1_BASE IP_CAN_1_BASE
/** Peripheral FLEXCAN_2 base address */
#define FLEXCAN_2_BASE IP_CAN_2_BASE
/** Peripheral FLEXCAN_3 base address */
#define FLEXCAN_3_BASE IP_CAN_3_BASE

#if defined(S32R45)
/** Peripheral FLEXCAN_0 base address */
#define FLEXCAN_4_BASE IP_CAN_4_BASE
/** Peripheral FLEXCAN_1 base address */
#define FLEXCAN_5_BASE IP_CAN_5_BASE
/** Peripheral FLEXCAN_2 base address */
#define FLEXCAN_6_BASE IP_CAN_6_BASE
/** Peripheral FLEXCAN_3 base address */
#define FLEXCAN_7_BASE IP_CAN_7_BASE
#endif

#define FLEXCAN_IP_RAM1n_COUNT                           512u

/* Registers used By Timestamp HR source in FlexCAN_ConfigTimestampModule */
#define FLEXCAN_IP_TIMESTAMP_REG IP_SRC->TIMESTAMP_CONTROL_REGISTER
#define FLEXCAN_IP_TIMESTAMP_SEL(x) SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL(x)
#define FLEXCAN_IP_TIMESTAMP_EN_MASK SRC_TIMESTAMP_CONTROL_REGISTER_TS_ENABLE_MASK
#define FLEXCAN_IP_TIMESTAMP_SEL_MASK SRC_TIMESTAMP_CONTROL_REGISTER_CAN_TS_CNT_SEL_MASK

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXCAN_IP_DEVICEREG_H_ */
