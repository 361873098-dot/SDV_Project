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
/**
*   @file       Power_Ip_PBcfg.c
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
#include "Power_Ip_Cfg.h"
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_PBCFG_VENDOR_ID_C                      43
#define POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_PBCFG_SW_MAJOR_VERSION_C               4
#define POWER_IP_PBCFG_SW_MINOR_VERSION_C               0
#define POWER_IP_PBCFG_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_PBCFG_VENDOR_ID_C != POWER_IP_CFG_VENDOR_ID)
    #error "Power_Ip_PBcfg.c and Power_Ip_Cfg.h have different vendor ids"
#endif
/* Check if source file and Power_Ip_Cfg.h file are of the same Autosar version */
#if ((POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PBcfg.c and Power_Ip_Cfg.h are different"
#endif
/* Check if source file and Power_Ip_Cfg.h file are of the same Software version */
#if ((POWER_IP_PBCFG_SW_MAJOR_VERSION_C != POWER_IP_CFG_SW_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_SW_MINOR_VERSION_C != POWER_IP_CFG_SW_MINOR_VERSION) || \
     (POWER_IP_PBCFG_SW_PATCH_VERSION_C != POWER_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_PBcfg.c and Power_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_PBcfg.c and StandardTypes.h are different"
#endif

#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcu_MemMap.h"









static const Power_Ip_MC_ME_CoreConfigType Power_Ip_MC_ME_aPartition0CoreConfigPB_0[4U] =
{
    /* The configuration structure for Partition 0 Core 0. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the partition. */
        (uint8)0U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN0_CORE0_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 0 Core 1. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the partition. */
        (uint8)1U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN0_CORE1_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 0 Core 2. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the partition. */
        (uint8)2U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN0_CORE2_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 0 Core 4. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the partition. */
        (uint8)4U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN0_CORE4_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

};

static const Power_Ip_MC_ME_CoreConfigType Power_Ip_MC_ME_aPartition1CoreConfigPB_0[8U] =
{
    /* The configuration structure for Partition 1 Core 0. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)0U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE0_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 1. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)1U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE1_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 2. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)2U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE2_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 3. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)3U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE3_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 4. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)4U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE4_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 5. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)5U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE5_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 6. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)6U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE6_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

    /* The configuration structure for Partition 1 Core 7. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the partition. */
        (uint8)7U,

        /* The boot address of the core. */
        (uint32 *)0x0U,

        /* The process configuration register value of the core. */
        MC_ME_PRTN1_CORE7_PCONF_CCE
        (
            MC_ME_PRTNX_COREX_PCONF_CCE_DIS_U32
        )
    },

};



static const Power_Ip_MC_ME_CofbConfigType Power_Ip_MC_ME_aPartition0CofbConfigPB_0[1U] = 
{
    /* The configuration structure for Partition 0 COFB 0. */
    {
        /* Specifies whether the given COFB set is under MCU control. */
        (boolean)TRUE,

        /* The index of the COFB set within the partition. */
        (uint8)0U,

        /* The clock enable register value of the COFB set. */
        MC_ME_PRTN0_COFB0_CLKEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the COFB blocks to be updated. */
        MC_ME_PRTN0_COFB0_CLKEN_RWBITS_MASK
    }

};

static const Power_Ip_MC_ME_CofbConfigType Power_Ip_MC_ME_aPartition2CofbConfigPB_0[1U] = 
{
    /* The configuration structure for Partition 2 COFB 0. */
    {
        /* Specifies whether the given COFB set is under MCU control. */
        (boolean)TRUE,

        /* The index of the COFB set within the partition. */
        (uint8)0U,

        /* The clock enable register value of the COFB set. */
        MC_ME_PRTN2_COFB0_CLKEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the COFB blocks to be updated. */
        MC_ME_PRTN2_COFB0_CLKEN_RWBITS_MASK
    }

};



static const Power_Ip_MC_ME_PartitionConfigType Power_Ip_MC_ME_aPartitionConfigPB_0[4U] = 
{
    /* The configuration structure for Partition 0. */
    {
        /* Specifies whether the given partition is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given partition's power management is under MCU control. */
        (boolean)TRUE,

        /* Partition Index */
        (uint8)0U,

        /* The process configuration register value of the partition. */
        (
            MC_ME_PRTNX_PCONF_PCE_EN_U32 |
            MC_ME_PRTNX_PCONF_OSSE_DIS_U32
        ),

        /* Mask containing the Partition triggers (PCE/OSSE/etc) to be updated. */
        MC_ME_PRTN0_PUPD_RWBITS_MASK,

        /* Number of COFBs within Partition 0 */
        (uint8)1U,
        /* Configuration for the COFBs within Partition 0. */
        &Power_Ip_MC_ME_aPartition0CofbConfigPB_0,

        /* Number of Cores within Partition 0 */
        (uint8)4U,
        /* Configuration for the Cores within Partition 0. */
        &Power_Ip_MC_ME_aPartition0CoreConfigPB_0
    },

    /* The configuration structure for Partition 1. */
    {
        /* Specifies whether the given partition is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given partition's power management is under MCU control. */
        (boolean)TRUE,

        /* Partition Index */
        (uint8)1U,

        /* The process configuration register value of the partition. */
        (
            MC_ME_PRTNX_PCONF_PCE_DIS_U32 |
            MC_ME_PRTNX_PCONF_OSSE_EN_U32
        ),

        /* Mask containing the Partition triggers (PCE/OSSE/etc) to be updated. */
        MC_ME_PRTN1_PUPD_RWBITS_MASK,

        /* Number of COFBs within Partition 1 */
        (uint8)0U,
        /* Configuration for the COFBs within Partition 1. */
        (NULL_PTR),

        /* Number of Cores within Partition 1 */
        (uint8)8U,
        /* Configuration for the Cores within Partition 1. */
        &Power_Ip_MC_ME_aPartition1CoreConfigPB_0
    },

    /* The configuration structure for Partition 2. */
    {
        /* Specifies whether the given partition is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given partition's power management is under MCU control. */
        (boolean)TRUE,

        /* Partition Index */
        (uint8)2U,

        /* The process configuration register value of the partition. */
        (
            MC_ME_PRTNX_PCONF_PCE_DIS_U32 |
            MC_ME_PRTNX_PCONF_OSSE_EN_U32
        ),

        /* Mask containing the Partition triggers (PCE/OSSE/etc) to be updated. */
        MC_ME_PRTN2_PUPD_RWBITS_MASK,

        /* Number of COFBs within Partition 2 */
        (uint8)1U,
        /* Configuration for the COFBs within Partition 2. */
        &Power_Ip_MC_ME_aPartition2CofbConfigPB_0,

        /* Number of Cores within Partition 2 */
        (uint8)0U,
        /* Configuration for the Cores within Partition 2. */
        (NULL_PTR)
    },

    /* The configuration structure for Partition 3. */
    {
        /* Specifies whether the given partition is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given partition's power management is under MCU control. */
        (boolean)TRUE,

        /* Partition Index */
        (uint8)3U,

        /* The process configuration register value of the partition. */
        (
            MC_ME_PRTNX_PCONF_PCE_DIS_U32 |
            MC_ME_PRTNX_PCONF_OSSE_EN_U32
        ),

        /* Mask containing the Partition triggers (PCE/OSSE/etc) to be updated. */
        MC_ME_PRTN3_PUPD_RWBITS_MASK,

        /* Number of COFBs within Partition 3 */
        (uint8)0U,
        /* Configuration for the COFBs within Partition 3. */
        (NULL_PTR),

        /* Number of Cores within Partition 3 */
        (uint8)0U,
        /* Configuration for the Cores within Partition 3. */
        (NULL_PTR)
    },

};


/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
static const Power_Ip_MC_ME_ModeConfigType Power_Ip_MC_ME_ModeConfigPB_0 =
{
#if (defined(POWER_IP_RESET_DURING_STANDBY_SUPPORTED))
#if (POWER_IP_RESET_DURING_STANDBY_SUPPORTED == STD_ON)
#if (defined(POWER_IP_ENTER_LOW_POWER_MODE) && (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON))
    /* MC_ME Main Core ID register */
    MC_ME_MAIN_COREID_U32
    (
        MC_ME_MAIN_COREID_NOT_USED_U32
    ),
#endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
#endif
#endif
    /* MC_ME Mode Partition Settings. */
    &Power_Ip_MC_ME_aPartitionConfigPB_0
};

static const Power_Ip_MC_RGM_CoreConfigType Power_Ip_MC_RGM_aDomain0CoreConfigPB_0[4U] = 
{
    /* The configuration structure for Domain 0 Core 0. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the domain. */
        (uint8)0U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST0_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(0U)
    },

    /* The configuration structure for Domain 0 Core 1. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the domain. */
        (uint8)1U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST0_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(1U)
    },

    /* The configuration structure for Domain 0 Core 2. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the domain. */
        (uint8)2U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST0_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(2U)
    },

    /* The configuration structure for Domain 0 Core 4. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)FALSE,

        /* The index of the core within the domain. */
        (uint8)4U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST0_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(6U)
    },

};
static const Power_Ip_MC_RGM_CoreConfigType Power_Ip_MC_RGM_aDomain1CoreConfigPB_0[8U] = 
{
    /* The configuration structure for Domain 1 Core 0. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)0U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(0U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(0U)
    },

    /* The configuration structure for Domain 1 Core 1. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)1U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(1U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(1U)
    },

    /* The configuration structure for Domain 1 Core 2. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)2U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(2U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(2U)
    },

    /* The configuration structure for Domain 1 Core 3. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)3U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(3U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(3U)
    },

    /* The configuration structure for Domain 1 Core 4. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)4U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(4U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(4U)
    },

    /* The configuration structure for Domain 1 Core 5. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)5U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(5U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(5U)
    },

    /* The configuration structure for Domain 1 Core 6. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)6U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(6U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(6U)
    },

    /* The configuration structure for Domain 1 Core 7. */
    {
        /* Specifies whether the given core is under MCU control. */
        (boolean)TRUE,

        /* The index of the core within the domain. */
        (uint8)7U,

        /* The reset enable register value of the core. */
        MC_RGM_PRST1_COFB0_RSTEN
        (
            ((uint32)0x00000000U)
            | MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(7U)
        ),

        /* Mask containing the Core blocks to be updated. */
        MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(7U)
    },

};


static const Power_Ip_MC_RGM_CofbConfigType Power_Ip_MC_RGM_aDomain0CofbConfigPB_0[1U] =
{
    /* The configuration structure for Domain 0 COFB 0 (i.e. PRST0_0). */
    {
        /* Specifies whether the given COFB set is under MCU control. */
        (boolean)TRUE,

        /* The index of the COFB set within the domain. */
        (uint8)0U,

        /* The reset enable register value of the COFB set. */
        MC_RGM_PRST0_COFB0_RSTEN
        (
            ((uint32)0x00000000U) | MC_RGM_PRST_0_PERIPH_3_RST_MASK | MC_RGM_PRST_0_PERIPH_4_RST_MASK | MC_RGM_PRST_0_PERIPH_5_RST_MASK | MC_RGM_PRST_0_PERIPH_16_RST_MASK | MC_RGM_PRST_0_PERIPH_17_RST_MASK 
        ),

        /* Mask containing the COFB blocks to be updated. */
        MC_RGM_PRST0_COFB0_RSTEN_PERIPH_MASK
    },

};


static const Power_Ip_MC_RGM_DomainConfigType Power_Ip_MC_RGM_aDomainConfigPB_0[4U] =
{
    /* The configuration structure for Domain 0. */
    {
        /* Specifies whether the given domain is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given domain's power management is under MCU control. */
        (boolean)TRUE,

        /* Domain Index */
        (uint8)0U,

        /* The process configuration register value of the domain. */
        RDC_RDX_CTRL_REG_ICON_INTF_ENABLE,

        /* Number of COFBs within Domain 0 */
        (uint8)1U,
        /* Configuration for the COFBs within Domain 0. */
        &Power_Ip_MC_RGM_aDomain0CofbConfigPB_0,

        /* Number of Cores within Domain 0 */
        (uint8)4U,
        /* Configuration for the Cores within Domain 0. */
        &Power_Ip_MC_RGM_aDomain0CoreConfigPB_0
    },
    /* The configuration structure for Domain 1. */
    {
        /* Specifies whether the given domain is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given domain's power management is under MCU control. */
        (boolean)TRUE,

        /* Domain Index */
        (uint8)1U,

        /* The process configuration register value of the domain. */
        RDC_RDX_CTRL_REG_ICON_INTF_DISABLE,

        /* Number of COFBs within Domain 1 */
        (uint8)0U,
        /* Configuration for the COFBs within Domain 1. */
        (NULL_PTR),

        /* Number of Cores within Domain 1 */
        (uint8)8U,
        /* Configuration for the Cores within Domain 1. */
        &Power_Ip_MC_RGM_aDomain1CoreConfigPB_0
    },
    /* The configuration structure for Domain 2. */
    {
        /* Specifies whether the given domain is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given domain's power management is under MCU control. */
        (boolean)TRUE,

        /* Domain Index */
        (uint8)2U,

        /* The process configuration register value of the domain. */
        RDC_RDX_CTRL_REG_ICON_INTF_DISABLE,

        /* Number of COFBs within Domain 2 */
        (uint8)0U,
        /* Configuration for the COFBs within Domain 2. */
        (NULL_PTR),

        /* Number of Cores within Domain 2 */
        (uint8)0U,
        /* Configuration for the Cores within Domain 2. */
        (NULL_PTR)
    },
    /* The configuration structure for Domain 3. */
    {
        /* Specifies whether the given domain is under MCU control. */
        (boolean)TRUE,

        /* Specifies whether the given domain's power management is under MCU control. */
        (boolean)TRUE,

        /* Domain Index */
        (uint8)3U,

        /* The process configuration register value of the domain. */
        RDC_RDX_CTRL_REG_ICON_INTF_DISABLE,

        /* Number of COFBs within Domain 3 */
        (uint8)0U,
        /* Configuration for the COFBs within Domain 3. */
        (NULL_PTR),

        /* Number of Cores within Domain 3 */
        (uint8)0U,
        /* Configuration for the Cores within Domain 3. */
        (NULL_PTR)
    },
};


/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
static const Power_Ip_MC_RGM_ModeConfigType Power_Ip_MC_RGM_ModeConfigPB_0 =
{
    /* MC_RGM Mode Domain Settings. */
    &Power_Ip_MC_RGM_aDomainConfigPB_0
};

/**
* @brief          Initialization mode data.
* @details        Static configuration realized by calling Mcu_SetMode() API.
*
*/
const Power_Ip_ModeConfigType Power_Ip_aModeConfigPB[1U] =
{

    /* Start of Mcu_aModeConfig[0] */
    {
        /* Mode Configuration ID. */
        (Power_Ip_ModeType)0U,

        /* The Power Mode name (code). */
        POWER_IP_RUN_MODE,

        /* The Sleep On Exit configuration. */
        (boolean)FALSE,
        /* MC_ME IP Mode settings. */
        &Power_Ip_MC_ME_ModeConfigPB_0,
        /* MC_RGM IP Mode settings. */
        &Power_Ip_MC_RGM_ModeConfigPB_0
    } /* End of Mcu_aModeConfig[0] */
};


/**
* @brief          Initialization data for MC_RGM hardware IP.
* @details        Static configuration assigned at startup by calling Mcu_Init() API.
*
*/
static const Power_Ip_MC_RGM_ConfigType Power_Ip_MC_RGM_ConfigPB =
{
#if (POWER_IP_PERFORM_RESET_API == STD_ON)
    /* MC_ResetType: Functional vs Destructive. */
    (MCU_FUNC_RESET),
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */

#if (defined(POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT) && (POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT == STD_ON))
    /* Func_ResetOpt: FERD Register Configuration. */
    (
        0U
    ),
#endif /* POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT */

    /* Func_Threshold_Reset: RGM_FRET Register Configuration. */
    MC_RGM_FRET_FRET((uint32)15U),

    /* Dest_Threshold_Reset: RGM_DRET Register Configuration. */
    MC_RGM_DRET_DRET((uint32)0U)
};


/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static const Power_Ip_PMC_ConfigType Power_Ip_PMC_ConfigPB =
{
    /* Non-Critical Supply Presence Detector Control Register (NCSPD_CTL). */
    (
        ((uint32)0x00000000U) 
    )
};


/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
const Power_Ip_HwIPsConfigType Power_Ip_HwIPsConfigPB =
{
    /* Configuration for MC_RGM (Reset Generation Module) hardware IP. */
    &Power_Ip_MC_RGM_ConfigPB,

    /* Configuration for PMU (Power Management Unit) hardware IP, part of PCU. */
    &Power_Ip_PMC_ConfigPB,
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */


