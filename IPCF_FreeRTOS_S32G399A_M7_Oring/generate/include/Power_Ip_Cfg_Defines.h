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

#ifndef POWER_IP_CFG_DEFINES_H
#define POWER_IP_CFG_DEFINES_H

/**
*   @file       Power_Ip_Cfg_Defines.h
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
#include "StandardTypes.h"
#include "S32G399A_MC_ME.h"
#include "S32G399A_MC_RGM.h"
#include "S32G399A_PMC.h"
#include "S32G399A_RESET.h"
#include "S32G399A_SCB.h"
#include "S32G399A_MSCM.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_DEFINES_VENDOR_ID                       43
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION                4
#define POWER_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define POWER_IP_CFG_DEFINES_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_Cfg_Defines.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
#define MC_RGM_PRST1_COFB0_RSTEN_RWBITS_MASK    ((uint32)0x000001FFU)

/**
* @brief            If this parameter is set to TRUE, the Reset Generation Module (RGM) initialization has to be disabled from the MCU driver.
*/

#define POWER_IP_DISABLE_RGM_INIT                   (STD_OFF)

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_PMC_INIT                   (STD_OFF)

/**
* @brief            Support for Low Power mode.
*/
#define POWER_IP_ENTER_LOW_POWER_MODE                    (STD_OFF)

/**
* @brief
*/
#define POWER_IP_PERFORM_RESET_API                       (STD_ON)

/**
* @brief            Configure PRTNm_COREn_ADDR registers
*/
#define POWER_IP_CONFIGURE_CADDRN                        (STD_OFF)

/**
* @brief            Support for Functional Reset Disable (FERD regiter present).
*/
#define POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT   (STD_ON)

/**
* @brief            Max number of MC_ME partitions.
*/
#define POWER_IP_MAX_NUMBER_OF_PARTITIONS           ((uint8)4U)

/**
* @brief            ISR Mcu_ResetAlternate_ISR is/is not available (STD_ON/STD_OFF)
*/
#define POWER_IP_RESET_ALTERNATE_ISR_USED                (STD_OFF)

/**
* @brief
*/
#define POWER_IP_HAS_OUTPUT_SAFE_STATE         (STD_ON)

/**
* @brief
*/
#define POWER_IP_RESET_DURING_STANDBY_SUPPORTED      (STD_ON)

#define POWER_IP_RESET_DOMAINS_SUPPORTED                 (STD_ON)

#define POWER_IP_WARM_RESET_SUPPORT                 (STD_ON)

/**
* @brief            ISR Mcu_PMC_UnderOverVoltage_ISR is/is not available (STD_ON/STD_OFF)
*/
#define POWER_IP_VOLTAGE_ERROR_ISR_USED                  (STD_OFF)

/**
* @brief           This define controls the availability of function Mcu_SleepOnExit
*/
#define POWER_IP_SLEEPONEXIT_SUPPORT         (STD_ON)

/**
* @brief            Support Mc_Me COFB (COFB regiter present).
*/
#define POWER_IP_MC_ME_COFB_SUPPORT                 (STD_ON)

/**
* @brief            Support Mc_Me PRTN2_COFB0_STAT (PRTN2_COFB0_STAT regiter reserved).
*/
#define POWER_IP_MC_ME_PRTN2_COFB0_STAT_RESERVED    (STD_ON)

/***********************************************************/
/*                       MC_ME_PRTNx                       */
/***********************************************************/
#define MC_ME_PRTN0_COFB0_CLKEN_RWBITS_MASK     ((uint32)(MC_ME_PRTN0_COFB0_CLKEN_REQ0_MASK | \
                                                          MC_ME_PRTN0_COFB0_CLKEN_REQ1_MASK))
#define MC_ME_PRTN2_COFB0_CLKEN_RWBITS_MASK     ((uint32)(MC_ME_PRTN2_COFB0_CLKEN_REQ0_MASK | \
                                                          MC_ME_PRTN2_COFB0_CLKEN_REQ1_MASK | \
                                                          MC_ME_PRTN2_COFB0_CLKEN_REQ2_MASK | \
                                                          MC_ME_PRTN2_COFB0_CLKEN_REQ3_MASK))
#define MC_ME_PRTN3_COFB0_CLKEN_RWBITS_MASK     ((uint32)0x00000000U)

/***********************************************************/
/*                    MC_ME_MAIN_COREID                    */
/***********************************************************/

#define MC_ME_MAIN_COREID_U32(value)                    ((uint32)( (uint32)(MC_ME_MAIN_COREID_CIDX(value)) | (uint32)(MC_ME_MAIN_COREID_PIDX(value)) ))
#define MC_ME_MAIN_COREID_NOT_USED_U32                  ((uint32)0x1FU)

#define MC_ME_MAIN_COREID_PIDX_CM7_0_U32                (MC_ME_MAIN_COREID_PIDX((uint32)0U))
#define MC_ME_MAIN_COREID_PIDX_CM7_1_U32                (MC_ME_MAIN_COREID_PIDX((uint32)0U))
#define MC_ME_MAIN_COREID_PIDX_CM7_2_U32                (MC_ME_MAIN_COREID_PIDX((uint32)0U))
#define MC_ME_MAIN_COREID_PIDX_HSE_CM7_U32              (MC_ME_MAIN_COREID_PIDX((uint32)0U))
#define MC_ME_MAIN_COREID_PIDX_A53_0_U32                (MC_ME_MAIN_COREID_PIDX((uint32)1U))
#define MC_ME_MAIN_COREID_PIDX_A53_1_U32                (MC_ME_MAIN_COREID_PIDX((uint32)1U))
#define MC_ME_MAIN_COREID_PIDX_A53_2_U32                (MC_ME_MAIN_COREID_PIDX((uint32)1U))
#define MC_ME_MAIN_COREID_PIDX_A53_3_U32                (MC_ME_MAIN_COREID_PIDX((uint32)1U))

#define MC_ME_MAIN_COREID_CIDX_CM7_0_U32                (MC_ME_MAIN_COREID_CIDX((uint32)0U))
#define MC_ME_MAIN_COREID_CIDX_CM7_1_U32                (MC_ME_MAIN_COREID_CIDX((uint32)1U))
#define MC_ME_MAIN_COREID_CIDX_CM7_2_U32                (MC_ME_MAIN_COREID_CIDX((uint32)2U))
#define MC_ME_MAIN_COREID_CIDX_HSE_CM7_U32              (MC_ME_MAIN_COREID_CIDX((uint32)3U))
#define MC_ME_MAIN_COREID_CIDX_A53_0_U32                (MC_ME_MAIN_COREID_CIDX((uint32)0U))
#define MC_ME_MAIN_COREID_CIDX_A53_1_U32                (MC_ME_MAIN_COREID_CIDX((uint32)1U))
#define MC_ME_MAIN_COREID_CIDX_A53_2_U32                (MC_ME_MAIN_COREID_CIDX((uint32)2U))
#define MC_ME_MAIN_COREID_CIDX_A53_3_U32                (MC_ME_MAIN_COREID_CIDX((uint32)3U))

/***********************************************************/
/*                    MC_ME_MODE_CONF                      */
/***********************************************************/
#define MC_ME_MODE_STAT_PREV_MODE_STANDBY_U32           (MC_ME_MODE_STAT_PREV_MODE_MASK)
#define MC_ME_MODE_CONF_MASK                            ((uint32)(MC_ME_MODE_CONF_DEST_RST_MASK) | (uint32)(MC_ME_MODE_CONF_FUNC_RST_MASK) | (uint32)(MC_ME_MODE_CONF_STANDBY_MASK) )
/***********************************************************/
/*                       MC_RGM_RDSS                       */
/***********************************************************/
#define MC_RGM_FES_RES_OCCURED_DURING_STANDBY_U32               ((uint32)MC_RGM_RDSS_FES_RES_MASK)
#define MC_RGM_FES_RES_NOT_OCCURED_DURING_STANDBY_U32           ((uint32)0x00000000U)

#define MC_RGM_DES_RES_OCCURED_DURING_STANDBY_U32               ((uint32)MC_RGM_RDSS_DES_RES_MASK)
#define MC_RGM_DES_RES_NOT_OCCURED_DURING_STANDBY_U32           ((uint32)0x00000000U)

#define MC_RGM_RDSS_RWBITS_MASK_U32         ((uint32)MC_RGM_RDSS_DES_RES_MASK | (uint32)MC_RGM_RDSS_FES_RES_MASK)

#define MC_RGM_RDSS_FES_RES_MASK_U32        ((uint32)MC_RGM_RDSS_FES_RES_MASK)
#define MC_RGM_RDSS_DES_RES_MASK_U32        ((uint32)MC_RGM_RDSS_DES_RES_MASK)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_DEFINES_H */


