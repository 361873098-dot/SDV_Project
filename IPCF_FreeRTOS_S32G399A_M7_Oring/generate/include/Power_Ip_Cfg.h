/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef POWER_IP_CFG_H
#define POWER_IP_CFG_H

/**
*   @file       Power_Ip_Cfg.h
*   @version    4.0.2
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_PBcfg.h"



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_VENDOR_ID                      43
#define POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION       4
#define POWER_IP_CFG_AR_RELEASE_MINOR_VERSION       4
#define POWER_IP_CFG_AR_RELEASE_REVISION_VERSION    0
#define POWER_IP_CFG_SW_MAJOR_VERSION               4
#define POWER_IP_CFG_SW_MINOR_VERSION               0
#define POWER_IP_CFG_SW_PATCH_VERSION               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same vendor */
#if (POWER_IP_CFG_VENDOR_ID != POWER_IP_PBCFG_VENDOR_ID)
    #error "Power_Ip_Cfg.h and Power_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same Autosar version */
#if ((POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_MINOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_REVISION_VERSION != POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Cfg.h and Power_Ip_PBcfg.h are different"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same Software version */
#if ((POWER_IP_CFG_SW_MAJOR_VERSION != POWER_IP_PBCFG_SW_MAJOR_VERSION) || \
     (POWER_IP_CFG_SW_MINOR_VERSION != POWER_IP_PBCFG_SW_MINOR_VERSION) || \
     (POWER_IP_CFG_SW_PATCH_VERSION != POWER_IP_PBCFG_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Power_Ip_Cfg.h and Power_Ip_PBcfg.h are different"
#endif


/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
#define POWER_IP_DEV_ERROR_DETECT         (STD_OFF)

#define POWER_IP_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define POWER_IP_TIMEOUT_VALUE_US            (50000U)


/**
* @brief        Support for User mode.
*               If this parameter has been configured to 'TRUE' the Clock can be executed from both supervisor and user mode.
*/
#define POWER_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Clock in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
  #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
/**
* @brief            Create defines with the values assigned to Mcu Reset Reason configurations.
*                   These values can be  retrieved from Mcu_GetResetReason Api.
*/
#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET   ((uint8)0U)
#define McuConf_McuResetReasonConf_MCU_NC_SPD_RST_RESET   ((uint8)1U)
#define McuConf_McuResetReasonConf_MCU_FCCU_FTR_RESET   ((uint8)2U)
#define McuConf_McuResetReasonConf_MCU_STCU_URF_RESET   ((uint8)3U)
#define McuConf_McuResetReasonConf_MCU_MC_RGM_FRE_RESET   ((uint8)4U)
#define McuConf_McuResetReasonConf_MCU_FXOSC_FAIL_RESET   ((uint8)5U)
#define McuConf_McuResetReasonConf_MCU_CORE_LOL_RESET   ((uint8)6U)
#define McuConf_McuResetReasonConf_MCU_PERIPH_LOL_RESET   ((uint8)7U)
#define McuConf_McuResetReasonConf_MCU_DDR_LOL_RESET   ((uint8)8U)
#define McuConf_McuResetReasonConf_MCU_ACC_LOL_RESET   ((uint8)9U)
#define McuConf_McuResetReasonConf_MCU_XBAR_DIV3_CLK_FAIL_RESET   ((uint8)10U)
#define McuConf_McuResetReasonConf_MCU_HSE_LC_RST_RESET   ((uint8)11U)
#define McuConf_McuResetReasonConf_MCU_HSE_SNVS_RST_RESET   ((uint8)12U)
#define McuConf_McuResetReasonConf_MCU_HSE_SWT_RST_RESET   ((uint8)13U)
#define McuConf_McuResetReasonConf_MCU_SW_DEST_RESET   ((uint8)14U)
#define McuConf_McuResetReasonConf_MCU_DEBUG_DEST_RESET   ((uint8)15U)
#define McuConf_McuResetReasonConf_MCU_EXT_RESET   ((uint8)16U)
#define McuConf_McuResetReasonConf_MCU_FCCU_RST_RESET   ((uint8)17U)
#define McuConf_McuResetReasonConf_MCU_ST_DONE_RESET   ((uint8)18U)
#define McuConf_McuResetReasonConf_MCU_SWT0_RST_RESET   ((uint8)19U)
#define McuConf_McuResetReasonConf_MCU_HSE_RAM_ECC_RST_RESET   ((uint8)20U)
#define McuConf_McuResetReasonConf_MCU_HSE_BOOT_ERR_RST_RESET   ((uint8)21U)
#define McuConf_McuResetReasonConf_MCU_HSE_CORE_LOCK_RST_RESET   ((uint8)22U)
#define McuConf_McuResetReasonConf_MCU_SW_FUNC_RESET   ((uint8)23U)
#define McuConf_McuResetReasonConf_MCU_DEBUG_FUNC_RESET   ((uint8)24U)
#define McuConf_McuResetReasonConf_MCU_WAKEUP_REASON   ((uint8)25U)
#define McuConf_McuResetReasonConf_MCU_NO_RESET_REASON   ((uint8)26U)
#define McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON   ((uint8)27U)
#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED   ((uint8)28U)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/**
* @brief            The type Power_Ip_ResetType, represents the different reset that a specified POWER_IP can have.
* @details          The POWER_IP shall provide at least the values MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Power_Ip_ResetType.
*
* @implements   Power_Ip_ResetType_Enumeration
*/
typedef enum
{
    /* 'Destructive' Event Status Register (MC_RGM_DES) */
    MCU_POWER_ON_RESET = McuConf_McuResetReasonConf_MCU_POWER_ON_RESET,                           /**< @brief Power on reset event. RGM_DES[F_POR]. */
    MCU_NC_SPD_RST_RESET = McuConf_McuResetReasonConf_MCU_NC_SPD_RST_RESET,                       /**< @brief Non-critical supply presence detector fail event. RGM_DES[F_DR1]. */
    MCU_FCCU_FTR_RESET = McuConf_McuResetReasonConf_MCU_FCCU_FTR_RESET,                           /**< @brief FCCU failure to react. RGM_DES[F_DR3]. */
    MCU_STCU_URF_RESET = McuConf_McuResetReasonConf_MCU_STCU_URF_RESET,                           /**< @brief STCU unrecoverable fault. RGM_DES[F_DR4]. */
    MCU_MC_RGM_FRE_RESET = McuConf_McuResetReasonConf_MCU_MC_RGM_FRE_RESET,                       /**< @brief Functional reset escalation. RGM_DES[F_DR6]. */
    MCU_FXOSC_FAIL_RESET = McuConf_McuResetReasonConf_MCU_FXOSC_FAIL_RESET,                       /**< @brief FXOSC failure. RGM_DES[F_DR8]. */
    MCU_CORE_LOL_RESET = McuConf_McuResetReasonConf_MCU_CORE_LOL_RESET,                           /**< @brief CORE_PLL and related DFS loss of lock. RGM_DES[F_DR9]. */
    MCU_PERIPH_LOL_RESET = McuConf_McuResetReasonConf_MCU_PERIPH_LOL_RESET,                       /**< @brief PERIPH_PLL and related DFS loss of lock. RGM_DES[F_DR10]. */
    MCU_DDR_LOL_RESET = McuConf_McuResetReasonConf_MCU_DDR_LOL_RESET,                             /**< @brief DDR_PLL loss of lock. RGM_DES[F_DR11]. */
    MCU_ACC_LOL_RESET = McuConf_McuResetReasonConf_MCU_ACC_LOL_RESET,                             /**< @brief ACCEL_PLL loss of lock. RGM_DES[F_DR12]. */
    MCU_XBAR_DIV3_CLK_FAIL_RESET = McuConf_McuResetReasonConf_MCU_XBAR_DIV3_CLK_FAIL_RESET,       /**< @brief XBAR_DIV3_CLK failure. RGM_DES[F_DR13]. */
    MCU_HSE_LC_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_LC_RST_RESET,                       /**< @brief Life-cycle error. RGM_DES[F_DR16].. */
    MCU_HSE_SNVS_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_SNVS_RST_RESET,                   /**< @brief HSE SNVS tamper detected. RGM_DES[F_DR17]. */
    MCU_HSE_SWT_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_SWT_RST_RESET,                     /**< @brief HSE SWT timeout. RGM_DES[F_DR18]. */
    MCU_SW_DEST_RESET = McuConf_McuResetReasonConf_MCU_SW_DEST_RESET,                             /**< @brief Software destructive reset. RGM_DES[F_DR30]. */
    MCU_DEBUG_DEST_RESET = McuConf_McuResetReasonConf_MCU_DEBUG_DEST_RESET,                       /**< @brief Debug destructive reset. RGM_DES[F_DR31]. */

    /* 'Functional' Event Status Register (MC_RGM_FES) */
    MCU_EXT_RESET = McuConf_McuResetReasonConf_MCU_EXT_RESET,                                     /**< @brief External functional reset. RGM_FES[F_FR0]. */
    MCU_FCCU_RST_RESET = McuConf_McuResetReasonConf_MCU_FCCU_RST_RESET,                           /**< @brief FCCU Reset Reaction. RGM_FES[F_FR3]. */
    MCU_ST_DONE_RESET = McuConf_McuResetReasonConf_MCU_ST_DONE_RESET,                             /**< @brief Self-Test Done. RGM_FES[F_FR4]. */
    MCU_SWT0_RST_RESET = McuConf_McuResetReasonConf_MCU_SWT0_RST_RESET,                           /**< @brief SWT0 Timeout. RGM_FES[F_FR6]. */
    MCU_HSE_RAM_ECC_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_RAM_ECC_RST_RESET,             /**< @brief HSE memory ECC error. RGM_FES[F_FR18]. */
    MCU_HSE_BOOT_ERR_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_BOOT_ERR_RST_RESET,           /**< @brief HSE Boot Failure Error. RGM_FES[F_FR20]. */
    MCU_HSE_CORE_LOCK_RST_RESET = McuConf_McuResetReasonConf_MCU_HSE_CORE_LOCK_RST_RESET,         /**< @brief HSE M7 Core Lock. RGM_FES[F_FR21]. */
    MCU_SW_FUNC_RESET = McuConf_McuResetReasonConf_MCU_SW_FUNC_RESET,                             /**< @brief Software functional reset. RGM_FES[F_FR30]. */
    MCU_DEBUG_FUNC_RESET = McuConf_McuResetReasonConf_MCU_DEBUG_FUNC_RESET,                       /**< @brief Debug functional reset. RGM_FES[F_FR31]. */

    MCU_WAKEUP_REASON = McuConf_McuResetReasonConf_MCU_WAKEUP_REASON,                             /**< @brief Wake-up event detected. */
    MCU_NO_RESET_REASON = McuConf_McuResetReasonConf_MCU_NO_RESET_REASON,                         /**< @brief No reset reason found */
    MCU_MULTIPLE_RESET_REASON = McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON,             /**< @brief More than one reset events are logged except "Power on event" */
    MCU_RESET_UNDEFINED = McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED                          /**< @brief Undefined reset source. */

} Power_Ip_ResetType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_H */


