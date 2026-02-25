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
*   @file       Clock_Ip_Data.c
*   @version    4.0.2
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip_Private.h"

#if defined(CLOCK_IP_PLATFORM_SPECIFIC)

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DATA_VENDOR_ID_C                      43
#define CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DATA_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_DATA_SW_MINOR_VERSION_C               0
#define CLOCK_IP_DATA_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_DATA_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Data.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_DATA_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_DATA_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Data.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Data.c and RegLockMacros.h are different"
    #endif
    #endif
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/



#define CLOCK_IP_NO_CALLBACK                   0U
#define CLOCK_IP_GATE_HWMUX_DIV_CMU            1U
#define CLOCK_IP_PCFS_DFS                      1U
#define CLOCK_IP_PLL_MOD                       1U
#define CLOCK_IP_HWMUX_DIV_CMU                 2U
#define CLOCK_IP_GATE                          2U
#define CLOCK_IP_PLL                           2U
#define CLOCK_IP_DFS                           2U
#define CLOCK_IP_HWMUX_CMU                     3U
#define CLOCK_IP_PCFS_PLL_OUT                  3U
#define CLOCK_IP_GATE_HWMUX_CMU                4U
#define CLOCK_IP_PLL_OUT                       4U
#define CLOCK_IP_HWMUX_PCFS                    5U
#define CLOCK_IP_FAST_XOSC_CMU                 5U
#define CLOCK_IP_HWMUX_PCFS_DIV                6U
#define CLOCK_IP_CMU                           6U
#define CLOCK_IP_HWMUX_DIV                     7U
#define CLOCK_IP_SWMUX_DIV_CLKOUT              8U
#define CLOCK_IP_HWMUX                         9U
#define CLOCK_IP_GATE_SGMII                    10U
#define CLOCK_IP_RTC_SEL                       11U

#define CLOCK_IP_XBAR_2X_EXTENSION             0U        
#define CLOCK_IP_XBAR_DIV2_EXTENSION           0U        
#define CLOCK_IP_XBAR_DIV3_EXTENSION           0U        
#define CLOCK_IP_XBAR_DIV4_EXTENSION           0U        
#define CLOCK_IP_XBAR_DIV6_EXTENSION           0U        
#define CLOCK_IP_XBAR_EXTENSION                0U        
#define CLOCK_IP_A53_CORE_DIV10_EXTENSION      1U       
#define CLOCK_IP_A53_CORE_DIV2_EXTENSION       1U        
#define CLOCK_IP_A53_CORE_EXTENSION            1U      
#define CLOCK_IP_DDR_EXTENSION                 2U
#define CLOCK_IP_PFE_PE_EXTENSION              3U
#define CLOCK_IP_PFE_SYS_EXTENSION             3U
#define CLOCK_IP_PER_EXTENSION                 4U
#define CLOCK_IP_GMAC0_REF_EXTENSION           5U
#define CLOCK_IP_GMAC0_REF_DIV_EXTENSION       5U
#define CLOCK_IP_PFEMAC0_REF_DIV_EXTENSION     6U
#define CLOCK_IP_PFEMAC1_REF_DIV_EXTENSION     7U
#define CLOCK_IP_PFEMAC2_REF_DIV_EXTENSION     8U
#define CLOCK_IP_CLKOUT0_EXTENSION             9U
#define CLOCK_IP_CLKOUT1_EXTENSION             10U
#define CLOCK_IP_DAPB_EXTENSION                11U
#define CLOCK_IP_FLEXCAN_EXTENSION             12U
#define CLOCK_IP_FLEXRAY_EXTENSION             13U
#define CLOCK_IP_FLEXTIMERA_EXTENSION          14U
#define CLOCK_IP_FLEXTIMERB_EXTENSION          15U
#define CLOCK_IP_GMAC_TS_EXTENSION             16U
#define CLOCK_IP_GMAC0_RX_EXTENSION            17U
#define CLOCK_IP_GMAC0_TX_EXTENSION            18U
#define CLOCK_IP_LBIST_EXTENSION               19U
#define CLOCK_IP_LIN_BAUD_EXTENSION            20U
#define CLOCK_IP_PFEMAC0_RX_EXTENSION          21U
#define CLOCK_IP_PFEMAC0_TX_EXTENSION          22U
#define CLOCK_IP_PFEMAC1_RX_EXTENSION          23U
#define CLOCK_IP_PFEMAC1_TX_EXTENSION          24U
#define CLOCK_IP_PFEMAC2_RX_EXTENSION          25U
#define CLOCK_IP_PFEMAC2_TX_EXTENSION          26U
#define CLOCK_IP_QSPI_2X_EXTENSION             27U
#define CLOCK_IP_SPI_EXTENSION                 28U
#define CLOCK_IP_SDHC_EXTENSION                29U

#define CLOCK_IP_COREPLL_INSTANCE                       0U 
#define CLOCK_IP_PERIPHPLL_INSTANCE                     1U
#define CLOCK_IP_DDRPLL_INSTANCE                        2U
#define CLOCK_IP_ACCELPLL_INSTANCE                      3U

#define CLOCK_IP_COREDFS_INSTANCE                       0U
#define CLOCK_IP_PERIPHDFS_INSTANCE                     1U

#define CLOCK_IP_CGM0_INSTANCE                          0U
#define CLOCK_IP_CGM1_INSTANCE                          1U
#define CLOCK_IP_CGM2_INSTANCE                          2U
#define CLOCK_IP_CGM5_INSTANCE                          5U

#define CLOCK_IP_CMU_0_INSTANCE                         0U
#define CLOCK_IP_CMU_5_INSTANCE                         5U
#define CLOCK_IP_CMU_6_INSTANCE                         6U
#define CLOCK_IP_CMU_7_INSTANCE                         7U
#define CLOCK_IP_CMU_8_INSTANCE                         8U
#define CLOCK_IP_CMU_9_INSTANCE                         9U
#define CLOCK_IP_CMU_10_INSTANCE                        10U
#define CLOCK_IP_CMU_11_INSTANCE                        11U
#define CLOCK_IP_CMU_12_INSTANCE                        12U
#define CLOCK_IP_CMU_13_INSTANCE                        13U
#define CLOCK_IP_CMU_14_INSTANCE                        14U
#define CLOCK_IP_CMU_15_INSTANCE                        15U
#define CLOCK_IP_CMU_16_INSTANCE                        16U
#define CLOCK_IP_CMU_17_INSTANCE                        17U
#define CLOCK_IP_CMU_18_INSTANCE                        18U
#define CLOCK_IP_CMU_20_INSTANCE                        20U
#define CLOCK_IP_CMU_21_INSTANCE                        21U
#define CLOCK_IP_CMU_22_INSTANCE                        22U
#define CLOCK_IP_CMU_27_INSTANCE                        27U
#define CLOCK_IP_CMU_28_INSTANCE                        28U
#define CLOCK_IP_CMU_39_INSTANCE                        39U
#define CLOCK_IP_CMU_46_INSTANCE                        46U
#define CLOCK_IP_CMU_47_INSTANCE                        47U
#define CLOCK_IP_CMU_48_INSTANCE                        48U
#define CLOCK_IP_CMU_49_INSTANCE                        49U
#define CLOCK_IP_CMU_50_INSTANCE                        50U
#define CLOCK_IP_CMU_51_INSTANCE                        51U

#define CLOCK_IP_DIV_0_INDEX                            0U
#define CLOCK_IP_DIV_1_INDEX                            1U
#define CLOCK_IP_DIV_2_INDEX                            2U
#define CLOCK_IP_DIV_3_INDEX                            3U
#define CLOCK_IP_DIV_4_INDEX                            4U
#define CLOCK_IP_DIV_5_INDEX                            5U
#define CLOCK_IP_DIV_6_INDEX                            6U
#define CLOCK_IP_DIV_7_INDEX                            7U

#define CLOCK_IP_PCFS_3_INDEX                           3U
#define CLOCK_IP_PCFS_11_INDEX                          11U
#define CLOCK_IP_PCFS_32_INDEX                          32U

#define CLOCK_IP_PRT0_COL0_REQ0_INDEX                   0U
#define CLOCK_IP_PRT0_COL0_REQ1_INDEX                   1U
#define CLOCK_IP_PRT2_COL0_REQ0_INDEX                   2U
#define CLOCK_IP_PRT2_COL0_REQ1_INDEX                   3U
#define CLOCK_IP_PRT2_COL0_REQ2_INDEX                   4U
#define CLOCK_IP_PRT2_COL0_REQ3_INDEX                   5U

#define CLOCK_IP_PARTITION_0_INDEX                      0U
#define CLOCK_IP_PARTITION_2_INDEX                      2U
#define CLOCK_IP_COLLECTION_0_INDEX                     0U

#define CLOCK_IP_SEL_0_INDEX                            0U
#define CLOCK_IP_SEL_1_INDEX                            1U
#define CLOCK_IP_SEL_2_INDEX                            2U
#define CLOCK_IP_SEL_3_INDEX                            3U
#define CLOCK_IP_SEL_4_INDEX                            4U
#define CLOCK_IP_SEL_5_INDEX                            5U
#define CLOCK_IP_SEL_6_INDEX                            6U
#define CLOCK_IP_SEL_7_INDEX                            7U
#define CLOCK_IP_SEL_8_INDEX                            8U
#define CLOCK_IP_SEL_9_INDEX                            9U
#define CLOCK_IP_SEL_10_INDEX                           10U
#define CLOCK_IP_SEL_11_INDEX                           11U
#define CLOCK_IP_SEL_12_INDEX                           12U
#define CLOCK_IP_SEL_14_INDEX                           14U
#define CLOCK_IP_SEL_15_INDEX                           15U
#define CLOCK_IP_SEL_16_INDEX                           16U
                                       




/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_8
#include "Mcu_MemMap.h"

const uint8 Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_GATE_HWMUX_DIV_CMU */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_PLLDIG_PLL0DIV_DE_DIV_OUTPUT,                      /* CLOCK_IP_PCFS_PLL_OUT */
    CLOCK_IP_PLLDIG_PLL0DIV_DE_DIV_OUTPUT,                      /* CLOCK_IP_PLL_OUT */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_PCFS_DIV */
    CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE,                   /* CLOCK_IP_HWMUX_DIV */
    CLOCK_IP_CGM_X_DE_DIV_WITHOUT_PHASE,                        /* CLOCK_IP_SWMUX_DIV_CLKOUT */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8DividerTriggerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8XoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL,                       /* CLOCK_IP_FAST_XOSC_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8GateCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST_WITHOUT_STAT,  /* CLOCK_IP_GATE_HWMUX_DIV_CMU */
    CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST_WITHOUT_STAT,  /* CLOCK_IP_GATE */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST_WITHOUT_STAT,  /* CLOCK_IP_GATE_HWMUX_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST_WITHOUT_STAT,  /* CLOCK_IP_GATE_SGMII */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8FractionalDividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_DFS_MFI_MFN,                                       /* CLOCK_IP_PCFS_DFS */
    CLOCK_IP_DFS_MFI_MFN,                                       /* CLOCK_IP_DFS */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8PllCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE,/* CLOCK_IP_PLL_MOD */
    CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN,                         /* CLOCK_IP_PLL */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_GATE_HWMUX_DIV_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_GATE_HWMUX_CMU */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP,         /* CLOCK_IP_HWMUX_PCFS */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP,         /* CLOCK_IP_HWMUX_PCFS_DIV */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX_DIV */
    CLOCK_IP_CGM_X_CSC_CSS_CS_GRIP,                             /* CLOCK_IP_SWMUX_DIV_CLKOUT */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP,                         /* CLOCK_IP_HWMUX */
    CLOCK_IP_GENCTRL1_CTRL_SUPPORT,                             /* CLOCK_IP_GATE_SGMII */
    CLOCK_IP_RTC_RTCC_CLKSELECT,                                /* CLOCK_IP_RTC_SEL */
};
const uint8 Clock_Ip_au8PcfsCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS,                    /* CLOCK_IP_PCFS_DFS */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS,                    /* CLOCK_IP_PCFS_PLL_OUT */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8CmuCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_GATE_HWMUX_DIV_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_HWMUX_DIV_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_HWMUX_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_GATE_HWMUX_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_FAST_XOSC_CMU */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF,                    /* CLOCK_IP_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};




/* Clock features mapping */
const uint8 Clock_Ip_au8ClockFeatures[CLOCK_IP_NAMES_NO][CLOCK_IP_FEATURES_NO] =
/*   \
************************************************************************************************************************************************************************************************************************************************************************************************  \
*************************************     *************************       *************************   E   *****************************       *************       *********************       **********************       *************************       *****************       *************  \
*************************************  I  *************************   C   *************************   X   *****************************       *************   S   *********************   D   **********************       *************************       *****************       *************  \
*************************************  N  *************************   A   *************************   T   *****************************   P   *************   E   *********************   I   **********************   G   *************************   P   *****************       *************  \
*************************************  S  *************************   L   *************************   E   *****************************   O   *************   L   *********************   V   **********************   A   *************************   C   *****************   C   *************  \
*************************************  T  *************************   L   *************************   N   *****************************   W   *************   E   *********************   I   **********************   T   *************************   F   *****************   M   *************  \
*************************************  A  *************************   B   *************************   S   *****************************   E   *************   C   *********************   D   **********************   E   *************************   S   *****************   U   *************  \
*************************************  N  *************************   A   *************************   I   *****************************   R   *************   T   *********************   E   **********************       *************************       *****************       *************  \
*************************************  C  *************************   C   *************************   O   *****************************       *************   O   *********************   R   **********************       *************************       *****************       *************  \
*************************************  E  *************************   K   *************************   N   *****************************       *************   R   *********************       **********************       *************************       *****************       *************  \
*************************************     *************************       *************************       ****************************        *************       *********************       **********************       *************************       *****************       *************  \
*************************************************************************************************************************************************************************************************************************************************************************************************/\
{ \
/*   FIRC_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FIRC_CLK clock             */ \
/*   FXOSC_CLK clock            */ {0U,                            CLOCK_IP_FAST_XOSC_CMU,         0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_0_INSTANCE},   /*   FXOSC_CLK clock            */ \
/*   SIRC_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SIRC_CLK clock             */ \
/*   COREPLL_CLK clock          */ {CLOCK_IP_COREPLL_INSTANCE,     CLOCK_IP_PLL_MOD,               0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   COREPLL_CLK clock          */ \
/*   PERIPHPLL_CLK clock        */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   PERIPHPLL_CLK clock        */ \
/*   DDRPLL_CLK clock           */ {CLOCK_IP_DDRPLL_INSTANCE,      CLOCK_IP_PLL_MOD,               0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DDRPLL_CLK clock           */ \
/*   ACCELPLL_CLK clock         */ {CLOCK_IP_ACCELPLL_INSTANCE,    CLOCK_IP_PLL_MOD,               0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ACCELPLL_CLK clock         */ \
/*   COREPLL_PHI0 clock         */ {CLOCK_IP_COREPLL_INSTANCE,     CLOCK_IP_PCFS_PLL_OUT,          0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            CLOCK_IP_PCFS_3_INDEX,  0U},                        /*   COREPLL_PHI0 clock         */ \
/*   COREPLL_PHI1 clock         */ {CLOCK_IP_COREPLL_INSTANCE,     CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_1_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_PHI1 clock         */ \
/*   COREPLL_DFS1 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_PCFS_DFS,              0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            CLOCK_IP_PCFS_11_INDEX, 0U},                        /*   COREPLL_DFS1 clock         */ \
/*   COREPLL_DFS2 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_1_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_DFS2 clock         */ \
/*   COREPLL_DFS3 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_2_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_DFS3 clock         */ \
/*   COREPLL_DFS4 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_3_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_DFS4 clock         */ \
/*   COREPLL_DFS5 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_4_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_DFS5 clock         */ \
/*   COREPLL_DFS6 clock         */ {CLOCK_IP_COREDFS_INSTANCE,     CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_5_INDEX,        0U,                            0U,                     0U},                        /*   COREPLL_DFS6 clock         */ \
/*   PERIPHPLL_PHI0 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI0 clock       */ \
/*   PERIPHPLL_PHI1 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_1_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI1 clock       */ \
/*   PERIPHPLL_PHI2 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_2_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI2 clock       */ \
/*   PERIPHPLL_PHI3 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_3_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI3 clock       */ \
/*   PERIPHPLL_PHI4 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_4_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI4 clock       */ \
/*   PERIPHPLL_PHI5 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_5_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI5 clock       */ \
/*   PERIPHPLL_PHI6 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_6_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI6 clock       */ \
/*   PERIPHPLL_PHI7 clock       */ {CLOCK_IP_PERIPHPLL_INSTANCE,   CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_7_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_PHI7 clock       */ \
/*   PERIPHPLL_DFS1 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS1 clock       */ \
/*   PERIPHPLL_DFS2 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_1_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS2 clock       */ \
/*   PERIPHPLL_DFS3 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_2_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS3 clock       */ \
/*   PERIPHPLL_DFS4 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_3_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS4 clock       */ \
/*   PERIPHPLL_DFS5 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_4_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS5 clock       */ \
/*   PERIPHPLL_DFS6 clock       */ {CLOCK_IP_PERIPHDFS_INSTANCE,   CLOCK_IP_DFS,                   0U,                                 0U,                 0U,                          CLOCK_IP_DIV_5_INDEX,        0U,                            0U,                     0U},                        /*   PERIPHPLL_DFS6 clock       */ \
/*   DDRPLL_PHI0 clock          */ {CLOCK_IP_DDRPLL_INSTANCE,      CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   DDRPLL_PHI0 clock          */ \
/*   ACCELPLL_PHI0 clock        */ {CLOCK_IP_ACCELPLL_INSTANCE,    CLOCK_IP_PLL_OUT,               0U,                                 0U,                 0U,                          CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   ACCELPLL_PHI0 clock        */ \
/*   ACCELPLL_PHI1 clock        */ {CLOCK_IP_ACCELPLL_INSTANCE,    CLOCK_IP_PCFS_PLL_OUT,          0U,                                 0U,                 0U,                          CLOCK_IP_DIV_1_INDEX,        0U,                            CLOCK_IP_PCFS_32_INDEX, 0U},                        /*   ACCELPLL_PHI1 clock        */ \
/*   rtc_ext_ref clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   rtc_ext_ref clock        */ \
/*   ftm_0_ext_ref clock        */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ftm_0_ext_ref clock        */ \
/*   ftm_1_ext_ref clock        */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ftm_1_ext_ref clock        */ \
/*   gmac_0_ext_ref clock       */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   gmac_0_ext_ref clock       */ \
/*   gmac_0_ext_rx clock        */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   gmac_0_ext_rx clock        */ \
/*   gmac_0_ext_tx clock        */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   gmac_0_ext_tx clock        */ \
/*   gmac_ext_ts clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   gmac_ext_ts clock          */ \
/*   pfe_mac_0_ext_ref clock    */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_0_ext_ref clock    */ \
/*   pfe_mac_0_ext_rx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_0_ext_rx clock     */ \
/*   pfe_mac_0_ext_tx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_0_ext_tx clock     */ \
/*   pfe_mac_1_ext_ref clock    */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_1_ext_ref clock    */ \
/*   pfe_mac_1_ext_rx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_1_ext_rx clock     */ \
/*   pfe_mac_1_ext_tx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_1_ext_tx clock     */ \
/*   pfe_mac_2_ext_ref clock    */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_2_ext_ref clock    */ \
/*   pfe_mac_2_ext_rx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_2_ext_rx clock     */ \
/*   pfe_mac_2_ext_tx clock     */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   pfe_mac_2_ext_tx clock     */ \
/*   SERDES_0_XPCS_0_TX clock   */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_0_XPCS_0_TX clock   */ \
/*   SERDES_0_XPCS_0_CDR clock  */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_0_XPCS_0_CDR clock  */ \
/*   SERDES_0_XPCS_1_TX clock   */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_0_XPCS_1_TX clock   */ \
/*   SERDES_0_XPCS_1_CDR clock  */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_0_XPCS_1_CDR clock  */ \
/*   SERDES_1_XPCS_0_TX clock   */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_1_XPCS_0_TX clock   */ \
/*   SERDES_1_XPCS_0_CDR clock  */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_1_XPCS_0_CDR clock  */ \
/*   SERDES_1_XPCS_1_TX clock   */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_1_XPCS_1_TX clock   */ \
/*   SERDES_1_XPCS_1_CDR clock  */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SERDES_1_XPCS_1_CDR clock  */ \
/*   XBAR_2X_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_PCFS,            CLOCK_IP_XBAR_2X_EXTENSION,         0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   XBAR_2X_CLK clock          */ \
/*   XBAR_CLK clock             */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_XBAR_EXTENSION,            0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   XBAR_CLK clock             */ \
/*   XBAR_DIV2_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_XBAR_DIV2_EXTENSION,       0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   XBAR_DIV2_CLK clock        */ \
/*   XBAR_DIV3_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_CMU,                   CLOCK_IP_XBAR_DIV3_EXTENSION,       0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_7_INSTANCE},   /*   XBAR_DIV3_CLK clock        */ \
/*   XBAR_DIV4_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_XBAR_DIV4_EXTENSION,       0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   XBAR_DIV4_CLK clock        */ \
/*   XBAR_DIV6_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_XBAR_DIV6_EXTENSION,       0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   XBAR_DIV6_CLK clock        */ \
/*   A53_CORE_CLK clock         */ {CLOCK_IP_CGM1_INSTANCE,        CLOCK_IP_HWMUX_PCFS,            CLOCK_IP_A53_CORE_EXTENSION,        0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   A53_CORE_CLK clock         */ \
/*   A53_CORE_DIV2_CLK clock    */ {CLOCK_IP_CGM1_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_A53_CORE_DIV2_EXTENSION,   0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   A53_CORE_DIV2_CLK clock    */ \
/*   A53_CORE_DIV10_CLK clock   */ {CLOCK_IP_CGM1_INSTANCE,        CLOCK_IP_NO_CALLBACK,           CLOCK_IP_A53_CORE_DIV10_EXTENSION,  0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   A53_CORE_DIV10_CLK clock   */ \
/*   DDR_CLK clock              */ {CLOCK_IP_CGM5_INSTANCE,        CLOCK_IP_HWMUX_CMU,             CLOCK_IP_DDR_EXTENSION,             0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_20_INSTANCE},  /*   DDR_CLK clock              */ \
/*   PFE_PE_CLK clock           */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_HWMUX_PCFS_DIV,        CLOCK_IP_PFE_PE_EXTENSION,          0U,                 CLOCK_IP_SEL_0_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PFE_PE_CLK clock           */ \
/*   PFE_SYS_CLK clock          */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_CMU,                   CLOCK_IP_PFE_SYS_EXTENSION,         0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_39_INSTANCE},  /*   PFE_SYS_CLK clock          */ \
/*   PER_CLK clock              */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_PER_EXTENSION,             0U,                 CLOCK_IP_SEL_3_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     CLOCK_IP_CMU_10_INSTANCE},  /*   PER_CLK clock              */ \
/*   GMAC0_REF_CLK clock        */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX,                 CLOCK_IP_GMAC0_REF_EXTENSION,       0U,                 CLOCK_IP_SEL_15_INDEX,       0U,                          0U,                            0U,                     0U},                           /*   GMAC0_REF_CLK clock        */ \
/*   GMAC0_REF_DIV_CLK clock    */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_GMAC0_REF_DIV_EXTENSION,   0U,                 CLOCK_IP_SEL_15_INDEX,       CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   GMAC0_REF_DIV_CLK clock    */ \
/*   PFEMAC0_REF_DIV_CLK clock  */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_PFEMAC0_REF_DIV_EXTENSION, 0U,                 CLOCK_IP_SEL_7_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PFEMAC0_REF_DIV_CLK clock  */ \
/*   PFEMAC1_REF_DIV_CLK clock  */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_PFEMAC1_REF_DIV_EXTENSION, 0U,                 CLOCK_IP_SEL_8_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PFEMAC1_REF_DIV_CLK clock  */ \
/*   PFEMAC2_REF_DIV_CLK clock  */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_PFEMAC2_REF_DIV_EXTENSION, 0U,                 CLOCK_IP_SEL_9_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   PFEMAC2_REF_DIV_CLK clock  */ \
/*   SERDES_REF_CLK clock       */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_11_INSTANCE},  /*   SERDES_REF_CLK clock       */ \
/*   THE_LAST_PRODUCER_CLK      */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   THE_LAST_PRODUCER_CLK      */ \
/*   ADC0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ADC0_CLK clock             */ \
/*   ADC1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ADC1_CLK clock             */ \
/*   CLKOUT0_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_SWMUX_DIV_CLKOUT,      CLOCK_IP_CLKOUT0_EXTENSION,         0U,                 CLOCK_IP_SEL_1_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   CLKOUT0_CLK clock          */ \
/*   CLKOUT1_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_SWMUX_DIV_CLKOUT,      CLOCK_IP_CLKOUT1_EXTENSION,         0U,                 CLOCK_IP_SEL_2_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     0U},                        /*   CLKOUT1_CLK clock          */ \
/*   CORE_A53_CLUSTER_0_CLK     */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_27_INSTANCE},  /*   CORE_A53_CLUSTER_0_CLK     */ \
/*   CORE_A53_CLUSTER_1_CLK     */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_28_INSTANCE},  /*   CORE_A53_CLUSTER_1_CLK     */ \
/*   CORE_M7_0_CLK clock        */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_6_INSTANCE},   /*   CORE_M7_0_CLK clock        */ \
/*   CORE_M7_1_CLK clock        */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_8_INSTANCE},   /*   CORE_M7_1_CLK clock        */ \
/*   CORE_M7_2_CLK clock        */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_9_INSTANCE},   /*   CORE_M7_2_CLK clock        */ \
/*   CRC0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   CRC0_CLK clock             */ \
/*   CTU0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   CTU0_CLK clock             */ \
/*   CTU1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   CTU1_CLK clock             */ \
/*   DAPB_CLK clock             */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_DAPB_EXTENSION,            0U,                 CLOCK_IP_SEL_0_INDEX,        CLOCK_IP_DIV_1_INDEX,        0U,                            0U,                     0U},                        /*   DAPB_CLK clock             */ \
/*   DDR0_CLK clock             */ {0U,                            CLOCK_IP_GATE,                  0U,                                 0U,                 0U,                          0U,                          CLOCK_IP_PRT0_COL0_REQ1_INDEX, 0U,                     0U},                        /*   DDR0_CLK clock             */ \
/*   DMA0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMA0_CLK clock             */ \
/*   DMA1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMA1_CLK clock             */ \
/*   DMAMUX0_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMAMUX0_CLK clock          */ \
/*   DMAMUX1_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMAMUX1_CLK clock          */ \
/*   DMAMUX2_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMAMUX2_CLK clock          */ \
/*   DMAMUX3_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMAMUX3_CLK clock          */ \
/*   DMA_CRC0_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMA_CRC0_CLK clock         */ \
/*   DMA_CRC1_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   DMA_CRC1_CLK clock         */ \
/*   EIM0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   EIM0_CLK clock             */ \
/*   EIM1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   EIM1_CLK clock             */ \
/*   EIM2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   EIM2_CLK clock             */ \
/*   EIM3_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   EIM3_CLK clock             */ \
/*   EIM_CLK clock              */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   EIM_CLK clock              */ \
/*   ERM0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   ERM0_CLK clock             */ \
/*   FLEXCAN_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_CMU,             CLOCK_IP_FLEXCAN_EXTENSION,         0U,                 CLOCK_IP_SEL_7_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_13_INSTANCE},  /*   FLEXCAN_CLK clock          */ \
/*   FLEXCAN0_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FLEXCAN0_CLK clock         */ \
/*   FLEXCAN1_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FLEXCAN1_CLK clock         */ \
/*   FLEXCAN2_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FLEXCAN2_CLK clock         */ \
/*   FLEXCAN3_CLK clock         */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FLEXCAN3_CLK clock         */ \
/*   FLEXRAY_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_FLEXRAY_EXTENSION,         0U,                 CLOCK_IP_SEL_6_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_12_INSTANCE},  /*   FLEXRAY_CLK clock          */ \
/*   FRAY0_CLK clock            */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FRAY0_CLK clock            */ \
/*   FLEXTIMERA_CLK clock       */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_FLEXTIMERA_EXTENSION,      0U,                 CLOCK_IP_SEL_4_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   FLEXTIMERA_CLK clock       */ \
/*   FTIMER0_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FTIMER0_CLK clock          */ \
/*   FLEXTIMERB_CLK clock       */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_FLEXTIMERB_EXTENSION,      0U,                 CLOCK_IP_SEL_5_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   FLEXTIMERB_CLK clock       */ \
/*   FTIMER1_CLK clock          */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   FTIMER1_CLK clock          */ \
/*   GMAC_TS_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_GMAC_TS_EXTENSION,         0U,                 CLOCK_IP_SEL_9_INDEX,        0U,                          0U,                            0U,                     CLOCK_IP_CMU_15_INSTANCE},  /*   GMAC_TS_CLK clock          */ \
/*   GMAC0_TS_CLK clock         */ {0U,                            CLOCK_IP_GATE,                  0U,                                 0U,                 0U,                          0U,                          CLOCK_IP_PRT2_COL0_REQ3_INDEX, 0U,                     0U},                        /*   GMAC0_TS_CLK clock         */ \
/*   GMAC0_RX_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_CMU,             CLOCK_IP_GMAC0_RX_EXTENSION,        0U,                 CLOCK_IP_SEL_11_INDEX,       0U,                          0U,                            0U,                     CLOCK_IP_CMU_21_INSTANCE},  /*   GMAC0_RX_CLK clock         */ \
/*   GMAC0_TX_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_GMAC0_TX_EXTENSION,        0U,                 CLOCK_IP_SEL_10_INDEX,       CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     CLOCK_IP_CMU_14_INSTANCE},  /*   GMAC0_TX_CLK clock         */ \
/*   IIC0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   IIC0_CLK clock             */ \
/*   IIC1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   IIC1_CLK clock             */ \
/*   IIC2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   IIC2_CLK clock             */ \
/*   IIC3_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   IIC3_CLK clock             */ \
/*   IIC4_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   IIC4_CLK clock             */ \
/*   LBIST_CLK clock            */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_LBIST_EXTENSION,           0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   LBIST_CLK clock            */ \
/*   LBIST0_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST0_CLK clock           */ \
/*   LBIST1_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST1_CLK clock           */ \
/*   LBIST2_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST2_CLK clock           */ \
/*   LBIST3_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST3_CLK clock           */ \
/*   LBIST4_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST4_CLK clock           */ \
/*   LBIST5_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST5_CLK clock           */ \
/*   LBIST6_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST6_CLK clock           */ \
/*   LBIST7_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LBIST7_CLK clock           */ \
/*   LIN_BAUD_CLK clock         */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX,                 CLOCK_IP_LIN_BAUD_EXTENSION,        0U,                 CLOCK_IP_SEL_8_INDEX,        0U,                          0U,                            0U,                     0U},                        /*   LIN_BAUD_CLK clock         */ \
/*   LINFLEXD_CLK clock         */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_16_INSTANCE},  /*   LINFLEXD_CLK clock         */ \
/*   LIN0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LIN0_CLK clock             */ \
/*   LIN1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LIN1_CLK clock             */ \
/*   LIN2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   LIN2_CLK clock             */ \
/*   OCOTP0_CLK clock           */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   OCOTP0_CLK clock           */ \
/*   PFEMAC0_RX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_HWMUX_CMU,        CLOCK_IP_PFEMAC0_RX_EXTENSION,      0U,                 CLOCK_IP_SEL_4_INDEX,        0U,                          CLOCK_IP_PRT2_COL0_REQ0_INDEX, 0U,                     CLOCK_IP_CMU_47_INSTANCE},  /*   PFEMAC0_RX_CLK clock       */ \
/*   PFEMAC0_TX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_SGMII,            0U,                                 0U,                 CLOCK_IP_SEL_0_INDEX,        0U,                          CLOCK_IP_PRT2_COL0_REQ0_INDEX, 0U,                     0U},                        /*   PFEMAC0_TX_CLK clock       */ \
/*   PFEMAC0_TX_DIV_CLK clock   */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_PFEMAC0_TX_EXTENSION,      0U,                 CLOCK_IP_SEL_1_INDEX,        CLOCK_IP_DIV_0_INDEX,        0U,                            0U,                     CLOCK_IP_CMU_46_INSTANCE},  /*   PFEMAC0_TX_DIV_CLK clock   */ \
/*   PFEMAC1_RX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_HWMUX_CMU,        CLOCK_IP_PFEMAC1_RX_EXTENSION,      0U,                 CLOCK_IP_SEL_5_INDEX,        0U,                          CLOCK_IP_PRT2_COL0_REQ1_INDEX, 0U,                     CLOCK_IP_CMU_49_INSTANCE},  /*   PFEMAC1_RX_CLK clock       */ \
/*   PFEMAC1_TX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_HWMUX_DIV_CMU,    CLOCK_IP_PFEMAC1_TX_EXTENSION,      0U,                 CLOCK_IP_SEL_2_INDEX,        CLOCK_IP_DIV_0_INDEX,        CLOCK_IP_PRT2_COL0_REQ1_INDEX, 0U,                     CLOCK_IP_CMU_48_INSTANCE},  /*   PFEMAC1_TX_CLK clock   */ \
/*   PFEMAC2_RX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_HWMUX_CMU,        CLOCK_IP_PFEMAC2_RX_EXTENSION,      0U,                 CLOCK_IP_SEL_6_INDEX,        0U,                          CLOCK_IP_PRT2_COL0_REQ2_INDEX, 0U,                     CLOCK_IP_CMU_51_INSTANCE},  /*   PFEMAC2_RX_CLK clock       */ \
/*   PFEMAC2_TX_CLK clock       */ {CLOCK_IP_CGM2_INSTANCE,        CLOCK_IP_GATE_HWMUX_DIV_CMU,    CLOCK_IP_PFEMAC2_TX_EXTENSION,      0U,                 CLOCK_IP_SEL_3_INDEX,        CLOCK_IP_DIV_0_INDEX,        CLOCK_IP_PRT2_COL0_REQ2_INDEX, 0U,                     CLOCK_IP_CMU_50_INSTANCE},  /*   PFEMAC2_TX_CLK clock   */ \
/*   PIT0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   PIT0_CLK clock             */ \
/*   PIT1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   PIT1_CLK clock             */ \
/*   QSPI_2X_CLK clock          */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV,             CLOCK_IP_QSPI_2X_EXTENSION,         0U,                 CLOCK_IP_SEL_12_INDEX,       0U,                          0U,                            0U,                     0U},                        /*   QSPI_2X_CLK clock          */ \
/*   QSPI_1X_CLK clock          */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_17_INSTANCE},  /*   QSPI_1X_CLK clock         */ \
/*   QSPI0_CLK clock            */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   QSPI0_CLK clock            */ \
/*   RTC_CLK clock              */ {0U,                            CLOCK_IP_RTC_SEL,               0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   RTC_CLK clock              */
/*   RTC0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   RTC0_CLK clock             */ \
/*   SIUL0_CLK clock            */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SIUL0_CLK clock            */ \
/*   SIUL1_CLK clock            */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SIUL1_CLK clock            */ \
/*   SPI_CLK clock              */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_CMU,             CLOCK_IP_SPI_EXTENSION,             0U,                 CLOCK_IP_SEL_16_INDEX,       0U,                          0U,                            0U,                     CLOCK_IP_CMU_22_INSTANCE},  /*   SPI_CLK clock              */ \
/*   SPI0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI0_CLK clock             */ \
/*   SPI1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI1_CLK clock             */ \
/*   SPI2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI2_CLK clock             */ \
/*   SPI3_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI3_CLK clock             */ \
/*   SPI4_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI4_CLK clock             */ \
/*   SPI5_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SPI5_CLK clock             */ \
/*   STM0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM0_CLK clock             */ \
/*   STM1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM1_CLK clock             */ \
/*   STM2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM2_CLK clock             */ \
/*   STM3_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM3_CLK clock             */ \
/*   STM4_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM4_CLK clock             */ \
/*   STM5_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM5_CLK clock             */ \
/*   STM6_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM6_CLK clock             */ \
/*   STM7_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   STM7_CLK clock             */ \
/*   SWT0_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT0_CLK clock             */ \
/*   SWT1_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT1_CLK clock             */ \
/*   SWT2_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT2_CLK clock             */ \
/*   SWT3_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT3_CLK clock             */ \
/*   SWT4_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT4_CLK clock             */ \
/*   SWT5_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT5_CLK clock             */ \
/*   SWT6_CLK clock             */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   SWT6_CLK clock             */ \
/*   SDHC_CLK clock             */ {CLOCK_IP_CGM0_INSTANCE,        CLOCK_IP_HWMUX_DIV_CMU,         CLOCK_IP_SDHC_EXTENSION,            0U,                 CLOCK_IP_SEL_14_INDEX,       0U,                          0U,                            0U,                     CLOCK_IP_CMU_18_INSTANCE},  /*   SDHC_CLK clock             */ \
/*   USDHC0_CLK clock           */ {0U,                            CLOCK_IP_GATE,                  0U,                                 0U,                 0U,                          0U,                          CLOCK_IP_PRT0_COL0_REQ0_INDEX, 0U,                     0U},                        /*   USDHC0_CLK clock           */ \
/*   WKPU0_CLK clock            */ {0U,                            CLOCK_IP_NO_CALLBACK,           0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     0U},                        /*   WKPU0_CLK clock            */ \
/*   XBAR_DIV3_FAIL_CLK clock   */ {0U,                            CLOCK_IP_CMU,                   0U,                                 0U,                 0U,                          0U,                          0U,                            0U,                     CLOCK_IP_CMU_5_INSTANCE},   /*   XBAR_DIV3_FAIL_CLK clock   */ \
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8
#include "Mcu_MemMap.h"




/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"
/*!
 * @brief Converts a clock name to a selector entry hardware value
 */
const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_NAMES_NO] = {
    0U,                                       /*!< FIRC_CLK                                */
    2U,                                       /*!< FXOSC_CLK                               */
    1U,                                       /*!< SIRC_CLK                                */
    0U,                                       /*!< COREPLL_CLK                             */
    0U,                                       /*!< PERIPHPLL_CLK                           */
    0U,                                       /*!< DDRPLL_CLK                              */
    0U,                                       /*!< ACCELPLL_CLK                            */
    4U,                                       /*!< CORE_PLL_PHI0_CLK                       */
    5U,                                       /*!< CORE_PLL_PHI1_CLK                       */
    12U,                                      /*!< CORE_PLL_DFS1_CLK                       */
    13U,                                      /*!< CORE_PLL_DFS2_CLK                       */
    14U,                                      /*!< CORE_PLL_DFS3_CLK                       */
    15U,                                      /*!< CORE_PLL_DFS4_CLK                       */
    16U,                                      /*!< CORE_PLL_DFS5_CLK                       */
    17U,                                      /*!< CORE_PLL_DFS6_CLK                       */
    18U,                                      /*!< PERIPH_PLL_PHI0_CLK                     */
    19U,                                      /*!< PERIPH_PLL_PHI1_CLK                     */
    20U,                                      /*!< PERIPH_PLL_PHI2_CLK                     */
    21U,                                      /*!< PERIPH_PLL_PHI3_CLK                     */
    22U,                                      /*!< PERIPH_PLL_PHI4_CLK                     */
    23U,                                      /*!< PERIPH_PLL_PHI5_CLK                     */
    24U,                                      /*!< PERIPH_PLL_PHI6_CLK                     */
    25U,                                      /*!< PERIPH_PLL_PHI7_CLK                     */
    26U,                                      /*!< PERIPH_PLL_DFS1_CLK                     */
    27U,                                      /*!< PERIPH_PLL_DFS2_CLK                     */
    28U,                                      /*!< PERIPH_PLL_DFS3_CLK                     */
    29U,                                      /*!< PERIPH_PLL_DFS4_CLK                     */
    30U,                                      /*!< PERIPH_PLL_DFS5_CLK                     */
    31U,                                      /*!< PERIPH_PLL_DFS6_CLK                     */
    36U,                                      /*!< DDR_PLL_PHI0_CLK                        */
    32U,                                      /*!< ACCEL_PLL_PHI0_CLK                      */
    33U,                                      /*!< ACCEL_PLL_PHI1_CLK                      */
    3U,                                       /*!< RTC_EXT_REF_CLK                         */
    34U,                                      /*!< FTM_0_EXT_REF_CLK                       */
    35U,                                      /*!< FTM_1_EXT_REF_CLK                       */
    39U,                                      /*!< GMAC_0_EXT_REF_CLK                      */
    38U,                                      /*!< GMAC_0_EXT_RX_CLK                       */
    37U,                                      /*!< GMAC_0_EXT_TX_CLK                       */
    44U,                                      /*!< GMAC_EXT_TS_CLK                         */
    50U,                                      /*!< PFE_MAC_0_EXT_REF_CLK                   */
    49U,                                      /*!< PFE_MAC_0_EXT_RX_CLK                    */
    48U,                                      /*!< PFE_MAC_0_EXT_TX_CLK                    */
    53U,                                      /*!< PFE_MAC_1_EXT_REF_CLK                   */
    52U,                                      /*!< PFE_MAC_1_EXT_RX_CLK                    */
    51U,                                      /*!< PFE_MAC_1_EXT_TX_CLK                    */
    56U,                                      /*!< PFE_MAC_2_EXT_REF_CLK                   */
    55U,                                      /*!< PFE_MAC_2_EXT_RX_CLK                    */
    54U,                                      /*!< PFE_MAC_2_EXT_TX_CLK                    */
    40U,                                      /*!< SERDES_0_XPCS_0_TX                      */
    41U,                                      /*!< SERDES_0_XPCS_0_CDR                     */
    46U,                                      /*!< SERDES_0_XPCS_1_TX                      */
    47U,                                      /*!< SERDES_0_XPCS_1_CDR                     */
    57U,                                      /*!< SERDES_1_XPCS_0_TX                      */
    58U,                                      /*!< SERDES_1_XPCS_0_CDR                     */
    62U,                                      /*!< SERDES_1_XPCS_1_TX                      */
    63U,                                      /*!< SERDES_1_XPCS_1_CDR                     */
    0U,                                       /*!< XBAR_2X_CLK                             */
    0U,                                       /*!< XBAR_CLK                                */
    0U,                                       /*!< XBAR_DIV2_CLK                           */
    0U,                                       /*!< XBAR_DIV3_CLK                           */
    0U,                                       /*!< XBAR_DIV4_CLK                           */
    0U,                                       /*!< XBAR_DIV6_CLK                           */
    0U,                                       /*!< A53_CORE_CLK                            */
    0U,                                       /*!< A53_CORE_DIV2_CLK                       */
    0U,                                       /*!< A53_CORE_DIV10_CLK                      */
    0U,                                       /*!< DDR_CLK                                 */
    0U,                                       /*!< PFE_PE_CLK                              */
    0U,                                       /*!< PFE_SYS_CLK                             */
    0U,                                       /*!< PER_CLK                                 */
    0U,                                       /*!< GMAC0_REF_CLK                           */
    45U,                                      /*!< GMAC0_REF_DIV_CLK                       */
    59U,                                      /*!< PFEMAC0_REF_DIV_CLK                     */
    60U,                                      /*!< PFEMAC1_REF_DIV_CLK                     */
    61U,                                      /*!< PFEMAC2_REF_DIV_CLK                     */
    0U,                                       /*!< SERDES_REF_CLK                          */
    0U,                                       /*!< THE_LAST_PRODUCER_CLK           */
    0U,                                       /*!< ADC0_CLK                        */
    0U,                                       /*!< ADC1_CLK                        */
    0U,                                       /*!< CLKOUT0_CLK                     */
    0U,                                       /*!< CLKOUT1_CLK                     */
    0U,                                       /*!< CORE_A53_CLUSTER_0_CLK          */
    0U,                                       /*!< CORE_A53_CLUSTER_1_CLK          */
    0U,                                       /*!< CORE_M7_0_CLK                   */
    0U,                                       /*!< CORE_M7_1_CLK                   */
    0U,                                       /*!< CORE_M7_2_CLK                   */
    0U,                                       /*!< CRC0_CLK                        */
    0U,                                       /*!< CTU0_CLK                        */
    0U,                                       /*!< CTU1_CLK                        */
    0U,                                       /*!< DAPB_CLK                        */
    0U,                                       /*!< DDR0_CLK                        */
    0U,                                       /*!< DMA0_CLK                        */
    0U,                                       /*!< DMA1_CLK                        */
    0U,                                       /*!< DMAMUX0_CLK                     */
    0U,                                       /*!< DMAMUX1_CLK                     */
    0U,                                       /*!< DMAMUX2_CLK                     */
    0U,                                       /*!< DMAMUX3_CLK                     */
    0U,                                       /*!< DMA_CRC0_CLK                    */
    0U,                                       /*!< DMA_CRC1_CLK                    */
    0U,                                       /*!< EIM0_CLK                        */
    0U,                                       /*!< EIM1_CLK                        */
    0U,                                       /*!< EIM2_CLK                        */
    0U,                                       /*!< EIM3_CLK                        */
    0U,                                       /*!< EIM_CLK                         */
    0U,                                       /*!< ERM0_CLK                        */
    0U,                                       /*!< FLEXCAN_CLK                     */
    0U,                                       /*!< FLEXCAN0_CLK                    */
    0U,                                       /*!< FLEXCAN1_CLK                    */
    0U,                                       /*!< FLEXCAN2_CLK                    */
    0U,                                       /*!< FLEXCAN3_CLK                    */
    0U,                                       /*!< FLEXRAY_CLK                     */
    0U,                                       /*!< FRAY0_CLK                       */
    0U,                                       /*!< FLEXTIMERA_CLK                  */
    0U,                                       /*!< FTIMER0_CLK                     */
    0U,                                       /*!< FLEXTIMERB_CLK                  */
    0U,                                       /*!< FTIMER1_CLK                     */
    0U,                                       /*!< GMAC_TS_CLK                     */
    0U,                                       /*!< GMAC0_TS_CLK                    */
    0U,                                       /*!< GMAC0_RX_CLK                    */
    0U,                                       /*!< GMAC0_TX_CLK                    */
    0U,                                       /*!< IIC0_CLK                        */
    0U,                                       /*!< IIC1_CLK                        */
    0U,                                       /*!< IIC2_CLK                        */
    0U,                                       /*!< IIC3_CLK                        */
    0U,                                       /*!< IIC4_CLK                        */
    0U,                                       /*!< LBIST_CLK                       */
    0U,                                       /*!< LBIST0_CLK                      */
    0U,                                       /*!< LBIST1_CLK                      */
    0U,                                       /*!< LBIST2_CLK                      */
    0U,                                       /*!< LBIST3_CLK                      */
    0U,                                       /*!< LBIST4_CLK                      */
    0U,                                       /*!< LBIST5_CLK                      */
    0U,                                       /*!< LBIST6_CLK                      */
    0U,                                       /*!< LBIST7_CLK                      */
    0U,                                       /*!< LIN_BAUD_CLK                    */
    0U,                                       /*!< LINFLEXD_CLK                    */
    0U,                                       /*!< LIN0_CLK                        */
    0U,                                       /*!< LIN1_CLK                        */
    0U,                                       /*!< LIN2_CLK                        */
    0U,                                       /*!< OCOTP0_CLK                      */
    0U,                                       /*!< PFEMAC0_RX_CLK                  */
    0U,                                       /*!< PFEMAC0_TX_CLK                  */
    0U,                                       /*!< PFEMAC0_TX_DIV_CLK              */
    0U,                                       /*!< PFEMAC1_RX_CLK                  */
    0U,                                       /*!< PFEMAC1_TX_CLK                  */
    0U,                                       /*!< PFEMAC2_RX_CLK                  */
    0U,                                       /*!< PFEMAC2_TX_CLK                  */
    0U,                                       /*!< PIT0_CLK                        */
    0U,                                       /*!< PIT1_CLK                        */
    0U,                                       /*!< QSPI_2X_CLK                     */
    0U,                                       /*!< QSPI_1X_CLK                     */
    0U,                                       /*!< QSPI0_CLK                       */
    0U,                                       /*!< RTC_CLK                         */
    0U,                                       /*!< RTC0_CLK                        */
    0U,                                       /*!< SIUL0_CLK                       */
    0U,                                       /*!< SIUL1_CLK                       */
    0U,                                       /*!< SPI_CLK                         */
    0U,                                       /*!< SPI0_CLK                        */
    0U,                                       /*!< SPI1_CLK                        */
    0U,                                       /*!< SPI2_CLK                        */
    0U,                                       /*!< SPI3_CLK                        */
    0U,                                       /*!< SPI4_CLK                        */
    0U,                                       /*!< SPI5_CLK                        */
    0U,                                       /*!< STM0_CLK                        */
    0U,                                       /*!< STM1_CLK                        */
    0U,                                       /*!< STM2_CLK                        */
    0U,                                       /*!< STM3_CLK                        */
    0U,                                       /*!< STM4_CLK                        */
    0U,                                       /*!< STM5_CLK                        */
    0U,                                       /*!< STM6_CLK                        */
    0U,                                       /*!< STM7_CLK                        */
    0U,                                       /*!< SWT0_CLK                        */
    0U,                                       /*!< SWT1_CLK                        */
    0U,                                       /*!< SWT2_CLK                        */
    0U,                                       /*!< SWT3_CLK                        */
    0U,                                       /*!< SWT4_CLK                        */
    0U,                                       /*!< SWT5_CLK                        */
    0U,                                       /*!< SWT6_CLK                        */
    0U,                                       /*!< SDHC_CLK                        */
    0U,                                       /*!< USDHC0_CLK                      */
    0U,                                       /*!< WKPU0_CLK                       */
    0U,                                       /*!< XBAR_DIV3_FAIL_CLK              */
};

/*!
 * @brief Converts a clock name to a RTC selector entry hardware value
 */
const uint16 Clock_Ip_au16SelectorEntryRtcHardwareValue[CLOCK_IP_PRODUCERS_NO] = {
    2U,                                       /*!< FIRC_CLK                         */
    0U,                                       /*!< FXOSC_CLK                     NA */
    0U,                                       /*!< SIRC_CLK                         */
    0U,                                       /*!< COREPLL_CLK                   NA */
    0U,                                       /*!< PERIPHPLL_CLK                 NA */
    0U,                                       /*!< DDRPLL_CLK                    NA */
    0U,                                       /*!< ACCELPLL_CLK                  NA */
    0U,                                       /*!< CORE_PLL_PHI0_CLK             NA */
    0U,                                       /*!< CORE_PLL_PHI1_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS1_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS2_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS3_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS4_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS5_CLK             NA */
    0U,                                       /*!< CORE_PLL_DFS6_CLK             NA */
    0U,                                       /*!< PERIPH_PLL_PHI0_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI1_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI2_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI3_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI4_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI5_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI6_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_PHI7_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS1_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS2_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS3_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS4_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS5_CLK           NA */
    0U,                                       /*!< PERIPH_PLL_DFS6_CLK           NA */
    0U,                                       /*!< DDR_PLL_PHI0_CLK              NA */
    0U,                                       /*!< ACCEL_PLL_PHI0_CLK            NA */
    0U,                                       /*!< ACCEL_PLL_PHI1_CLK            NA */
    3U,                                       /*!< RTC_EXT_REF_CLK                  */
    0U,                                       /*!< FTM_0_EXT_REF_CLK             NA */
    0U,                                       /*!< FTM_1_EXT_REF_CLK             NA */
    0U,                                       /*!< GMAC_0_EXT_REF_CLK            NA */
    0U,                                       /*!< GMAC_0_EXT_RX_CLK             NA */
    0U,                                       /*!< GMAC_0_EXT_TX_CLK             NA */
    0U,                                       /*!< GMAC_EXT_TS_CLK               NA */
    0U,                                       /*!< PFE_MAC_0_EXT_REF_CLK         NA */
    0U,                                       /*!< PFE_MAC_0_EXT_RX_CLK          NA */
    0U,                                       /*!< PFE_MAC_0_EXT_TX_CLK          NA */
    0U,                                       /*!< PFE_MAC_1_EXT_REF_CLK         NA */
    0U,                                       /*!< PFE_MAC_1_EXT_RX_CLK          NA */
    0U,                                       /*!< PFE_MAC_1_EXT_TX_CLK          NA */
    0U,                                       /*!< PFE_MAC_2_EXT_REF_CLK         NA */
    0U,                                       /*!< PFE_MAC_2_EXT_RX_CLK          NA */
    0U,                                       /*!< PFE_MAC_2_EXT_TX_CLK          NA */
    0U,                                       /*!< SERDES_0_XPCS_0_TX            NA */
    0U,                                       /*!< SERDES_0_XPCS_0_CDR           NA */
    0U,                                       /*!< SERDES_0_XPCS_1_TX            NA */
    0U,                                       /*!< SERDES_0_XPCS_1_CDR           NA */
    0U,                                       /*!< SERDES_1_XPCS_0_TX            NA */
    0U,                                       /*!< SERDES_1_XPCS_0_CDR           NA */
    0U,                                       /*!< SERDES_1_XPCS_1_TX            NA */
    0U,                                       /*!< SERDES_1_XPCS_1_CDR           NA */
    0U,                                       /*!< XBAR_2X_CLK                   NA */
    0U,                                       /*!< XBAR_CLK                      NA */
    0U,                                       /*!< XBAR_DIV2_CLK                 NA */
    0U,                                       /*!< XBAR_DIV3_CLK                 NA */
    0U,                                       /*!< XBAR_DIV4_CLK                 NA */
    0U,                                       /*!< XBAR_DIV6_CLK                 NA */
    0U,                                       /*!< A53_CORE_CLK                  NA */
    0U,                                       /*!< A53_CORE_DIV2_CLK             NA */
    0U,                                       /*!< A53_CORE_DIV10_CLK            NA */
    0U,                                       /*!< DDR_CLK                       NA */
    0U,                                       /*!< PFE_PE_CLK                    NA */
    0U,                                       /*!< PFE_SYS_CLK                   NA */
    0U,                                       /*!< PER_CLK                       NA */
    0U,                                       /*!< GMAC0_REF_CLK                 NA */
    0U,                                       /*!< GMAC0_REF_DIV_CLK             NA */
    0U,                                       /*!< PFEMAC0_REF_DIV_CLK           NA */
    0U,                                       /*!< PFEMAC1_REF_DIV_CLK           NA */
    0U,                                       /*!< PFEMAC2_REF_DIV_CLK           NA */
    0U,                                       /*!< SERDES_REF_CLK                NA */
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"




/* Clock start constant section data */
#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
/* Clock name types */
const uint32 Clock_Ip_au8ClockNameTypes[CLOCK_IP_NAMES_NO] =
{
/*   FIRC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FIRC_CLK clock            */        \
/*   FXOSC_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FXOSC_CLK clock           */        \
/*   SIRC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SIRC_CLK clock            */        \
/*   COREPLL_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_CLK clock         */        \
/*   PERIPHPLL_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_CLK clock       */        \
/*   DDRPLL_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DDRPLL_CLK clock          */        \
/*   ACCELPLL_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ACCELPLL_CLK clock        */        \
/*   COREPLL_PHI0 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_PHI0 clock        */        \
/*   COREPLL_PHI1 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_PHI1 clock        */        \
/*   COREPLL_DFS1 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS1 clock        */        \
/*   COREPLL_DFS2 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS2 clock        */        \
/*   COREPLL_DFS3 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS3 clock        */        \
/*   COREPLL_DFS4 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS4 clock        */        \
/*   COREPLL_DFS5 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS5 clock        */        \
/*   COREPLL_DFS6 clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   COREPLL_DFS6 clock        */        \
/*   PERIPHPLL_PHI0 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI0 clock      */        \
/*   PERIPHPLL_PHI1 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI1 clock      */        \
/*   PERIPHPLL_PHI2 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI2 clock      */        \
/*   PERIPHPLL_PHI3 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI3 clock      */        \
/*   PERIPHPLL_PHI4 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI4 clock      */        \
/*   PERIPHPLL_PHI5 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI5 clock      */        \
/*   PERIPHPLL_PHI6 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI6 clock      */        \
/*   PERIPHPLL_PHI7 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_PHI7 clock      */        \
/*   PERIPHPLL_DFS1 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS1 clock      */        \
/*   PERIPHPLL_DFS2 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS2 clock      */        \
/*   PERIPHPLL_DFS3 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS3 clock      */        \
/*   PERIPHPLL_DFS4 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS4 clock      */        \
/*   PERIPHPLL_DFS5 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS5 clock      */        \
/*   PERIPHPLL_DFS6 clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PERIPHPLL_DFS6 clock      */        \
/*   DDRPLL_PHI0 clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DDRPLL_PHI0 clock         */        \
/*   ACCELPLL_PHI0 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ACCELPLL_PHI0 clock       */        \
/*   ACCELPLL_PHI1 clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ACCELPLL_PHI1 clock       */        \
/*   rtc_ext_ref clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   rtc_ext_ref clock         */        \
/*   ftm_0_ext_ref clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ftm_0_ext_ref clock       */        \
/*   ftm_1_ext_ref clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ftm_1_ext_ref clock       */        \
/*   gmac_0_ext_ref clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   gmac_0_ext_ref clock      */        \
/*   gmac_0_ext_rx clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   gmac_0_ext_rx clock       */        \
/*   gmac_0_ext_tx clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   gmac_0_ext_tx clock       */        \
/*   gmac_ext_ts clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   gmac_ext_ts clock         */        \
/*   pfe_mac_0_ext_ref clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_0_ext_ref clock   */        \
/*   pfe_mac_0_ext_rx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_0_ext_rx clock    */        \
/*   pfe_mac_0_ext_tx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_0_ext_tx clock    */        \
/*   pfe_mac_1_ext_ref clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_1_ext_ref clock   */        \
/*   pfe_mac_1_ext_rx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_1_ext_rx clock    */        \
/*   pfe_mac_1_ext_tx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_1_ext_tx clock    */        \
/*   pfe_mac_2_ext_ref clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_2_ext_ref clock   */        \
/*   pfe_mac_2_ext_rx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_2_ext_rx clock    */        \
/*   pfe_mac_2_ext_tx clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   pfe_mac_2_ext_tx clock    */        \
/*   SERDES_0_XPCS_0_TX clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_0_XPCS_0_TX clock  */        \
/*   SERDES_0_XPCS_0_CDR clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_0_XPCS_0_CDR clock */        \
/*   SERDES_0_XPCS_1_TX clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_0_XPCS_1_TX clock  */        \
/*   SERDES_0_XPCS_1_CDR clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_0_XPCS_1_CDR clock */        \
/*   SERDES_1_XPCS_0_TX clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_1_XPCS_0_TX clock  */        \
/*   SERDES_1_XPCS_0_CDR clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_1_XPCS_0_CDR clock */        \
/*   SERDES_1_XPCS_1_TX clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_1_XPCS_1_TX clock  */        \
/*   SERDES_1_XPCS_1_CDR clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_1_XPCS_1_CDR clock */        \
/*   XBAR_2X_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_2X_CLK clock         */        \
/*   XBAR_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_CLK clock            */        \
/*   XBAR_DIV2_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_DIV2_CLK clock       */        \
/*   XBAR_DIV3_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_DIV3_CLK clock       */        \
/*   XBAR_DIV4_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_DIV4_CLK clock       */        \
/*   XBAR_DIV6_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_DIV6_CLK clock       */        \
/*   A53_CORE_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   A53_CORE_CLK clock        */        \
/*   A53_CORE_DIV2_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   A53_CORE_DIV2_CLK clock   */        \
/*   A53_CORE_DIV10_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   A53_CORE_DIV10_CLK clock  */        \
/*   DDR_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DDR_CLK clock             */        \
/*   PFE_PE_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFE_PE_CLK clock          */        \
/*   PFE_SYS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFE_SYS_CLK clock         */        \
/*   PER_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PER_CLK clock             */        \
/*   GMAC0_REF_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC0_REF_CLK clock       */        \
/*   GMAC0_REF_DIV_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC0_REF_DIV_CLK clock   */        \
/*   PFEMAC0_REF_DIV_CLK clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC0_REF_DIV_CLK clock */        \
/*   PFEMAC1_REF_DIV_CLK clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC1_REF_DIV_CLK clock */        \
/*   PFEMAC2_REF_DIV_CLK clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC2_REF_DIV_CLK clock */        \
/*   SERDES_REF_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SERDES_REF_CLK clock      */        \
/*   THE_LAST_PRODUCER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   THE_LAST_PRODUCER_CLK     */        \
/*   ADC0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ADC0_CLK clock            */        \
/*   ADC1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ADC1_CLK clock            */        \
/*   CLKOUT0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CLKOUT0_CLK clock         */        \
/*   CLKOUT1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CLKOUT1_CLK clock         */        \
/*   CORE_A53_CLUSTER_0_CLK clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) , /*   CORE_A53_CLUSTER_0_CLK clock */     \
/*   CORE_A53_CLUSTER_1_CLK clock */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) , /*   CORE_A53_CLUSTER_1_CLK clock */     \
/*   CORE_M7_0_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CORE_M7_0_CLK clock       */        \
/*   CORE_M7_1_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CORE_M7_1_CLK clock       */        \
/*   CORE_M7_2_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CORE_M7_2_CLK clock       */        \
/*   CRC0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CRC0_CLK clock            */        \
/*   CTU0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CTU0_CLK clock            */        \
/*   CTU1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   CTU1_CLK clock            */        \
/*   DAPB_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DAPB_CLK clock            */        \
/*   DDR0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DDR0_CLK clock            */        \
/*   DMA0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMA0_CLK clock            */        \
/*   DMA1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMA1_CLK clock            */        \
/*   DMAMUX0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMAMUX0_CLK clock         */        \
/*   DMAMUX1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMAMUX1_CLK clock         */        \
/*   DMAMUX2_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMAMUX2_CLK clock         */        \
/*   DMAMUX3_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMAMUX3_CLK clock         */        \
/*   DMA_CRC0_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMA_CRC0_CLK clock        */        \
/*   DMA_CRC1_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   DMA_CRC1_CLK clock        */        \
/*   EIM0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   EIM0_CLK clock            */        \
/*   EIM1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   EIM1_CLK clock            */        \
/*   EIM2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   EIM2_CLK clock            */        \
/*   EIM3_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   EIM3_CLK clock            */        \
/*   EIM_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   EIM_CLK clock             */        \
/*   ERM0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   ERM0_CLK clock            */        \
/*   FLEXCAN_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXCAN_CLK clock         */        \
/*   FLEXCAN0_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXCAN0_CLK clock        */        \
/*   FLEXCAN1_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXCAN1_CLK clock        */        \
/*   FLEXCAN2_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXCAN2_CLK clock        */        \
/*   FLEXCAN3_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXCAN3_CLK clock        */        \
/*   FLEXRAY_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXRAY_CLK clock         */        \
/*   FRAY0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FRAY0_CLK clock           */        \
/*   FLEXTIMERA_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXTIMERA_CLK clock      */        \
/*   FTIMER0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FTIMER0_CLK clock         */        \
/*   FLEXTIMERB_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FLEXTIMERB_CLK clock      */        \
/*   FTIMER1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   FTIMER1_CLK clock         */        \
/*   GMAC_TS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC_TS_CLK clock         */        \
/*   GMAC0_RX_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC0_RX_CLK clock        */        \
/*   GMAC0_TX_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC0_TX_CLK clock        */        \
/*   GMAC0_TS_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   GMAC0_TS_CLK clock        */        \
/*   IIC0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   IIC0_CLK clock            */        \
/*   IIC1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   IIC1_CLK clock            */        \
/*   IIC2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   IIC2_CLK clock            */        \
/*   IIC3_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   IIC3_CLK clock            */        \
/*   IIC4_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   IIC4_CLK clock            */        \
/*   LBIST_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST_CLK clock           */        \
/*   LBIST0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST0_CLK clock          */        \
/*   LBIST1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST1_CLK clock          */        \
/*   LBIST2_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST2_CLK clock          */        \
/*   LBIST3_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST3_CLK clock          */        \
/*   LBIST4_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST4_CLK clock          */        \
/*   LBIST5_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST5_CLK clock          */        \
/*   LBIST6_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST6_CLK clock          */        \
/*   LBIST7_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LBIST7_CLK clock          */        \
/*   LIN_BAUD_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LIN_BAUD_CLK clock        */        \
/*   LINFLEXD_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LINFLEXD_CLK clock        */        \
/*   LIN0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LIN0_CLK clock            */        \
/*   LIN1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LIN1_CLK clock            */        \
/*   LIN2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   LIN2_CLK clock            */        \
/*   OCOTP0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   OCOTP0_CLK clock          */        \
/*   PFEMAC0_RX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC0_RX_CLK clock      */        \
/*   PFEMAC0_TX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC0_TX_CLK clock      */        \
/*   PFEMAC0_TX_DIV_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC0_TX_DIV_CLK clock  */        \
/*   PFEMAC1_RX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC1_RX_CLK clock      */        \
/*   PFEMAC1_TX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC1_TX_CLK clock  */        \
/*   PFEMAC2_RX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC2_RX_CLK clock      */        \
/*   PFEMAC2_TX_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PFEMAC2_TX_CLK clock  */        \
/*   PIT0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PIT0_CLK clock            */        \
/*   PIT1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   PIT1_CLK clock            */        \
/*   QSPI_2X_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   QSPI_2X_CLK clock         */        \
/*   QSPI_1X_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   QSPI_1X_CLK clock         */        \
/*   QSPI0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   QSPI0_CLK clock           */        \
/*   RTC_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,   /*   RTC_CLK clock             */         \
/*   RTC0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   RTC0_CLK clock            */        \
/*   SIUL0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SIUL0_CLK clock           */        \
/*   SIUL1_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SIUL1_CLK clock           */        \
/*   SPI_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI_CLK clock             */        \
/*   SPI0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI0_CLK clock            */        \
/*   SPI1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI1_CLK clock            */        \
/*   SPI2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI2_CLK clock            */        \
/*   SPI3_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI3_CLK clock            */        \
/*   SPI4_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI4_CLK clock            */        \
/*   SPI5_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SPI5_CLK clock            */        \
/*   STM0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM0_CLK clock            */        \
/*   STM1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM1_CLK clock            */        \
/*   STM2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM2_CLK clock            */        \
/*   STM3_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM3_CLK clock            */        \
/*   STM4_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM4_CLK clock            */        \
/*   STM5_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM5_CLK clock            */        \
/*   STM6_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM6_CLK clock            */        \
/*   STM7_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   STM7_CLK clock            */        \
/*   SWT0_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT0_CLK clock            */        \
/*   SWT1_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT1_CLK clock            */        \
/*   SWT2_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT2_CLK clock            */        \
/*   SWT3_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT3_CLK clock            */        \
/*   SWT4_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT4_CLK clock            */        \
/*   SWT5_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT5_CLK clock            */        \
/*   SWT6_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SWT6_CLK clock            */        \
/*   SDHC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   SDHC_CLK clock            */        \
/*   USDHC0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   USDHC0_CLK clock          */        \
/*   WKPU0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   WKPU0_CLK clock           */        \
/*   XBAR_DIV3_FAIL_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,    /*   XBAR_DIV3_FAIL_CLK clock  */        \
};
    #endif /* CLOCK_IP_DEV_ERROR_DETECT == STD_ON */
#endif /* CLOCK_IP_DEV_ERROR_DETECT */

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"


/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

Clock_Ip_CgmMuxType* const Clock_Ip_apxCgm[CLOCK_IP_MC_CGM_INSTANCES_COUNT][CLOCK_IP_MC_CGM_MUXS_COUNT] =
{
    {
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_0_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_1_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_2_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_3_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_4_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_5_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_6_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_7_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_8_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_9_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_10_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_11_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_12_CSC)),
        NULL_PTR,
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_14_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_15_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_0->MUX_16_CSC))
    },

    {
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_1->MUX_0_CSC)),
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },

    {
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_0_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_1_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_2_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_3_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_4_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_5_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_6_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_7_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_8_CSC)),
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_2->MUX_9_CSC)),
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },

    {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },

    {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },

    {
        (Clock_Ip_CgmMuxType*)(&(IP_MC_CGM_5->MUX_0_CSC)),
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },

};
volatile Clock_Ip_CgmPcfsType* const Clock_Ip_apxCgmPcfs[CLOCK_IP_MC_CGM_INSTANCES_COUNT] =
{
    (volatile Clock_Ip_CgmPcfsType*)(&(IP_MC_CGM_0->PCFS_SDUR)),
    (volatile Clock_Ip_CgmPcfsType*)(&(IP_MC_CGM_1->PCFS_SDUR)),
    (volatile Clock_Ip_CgmPcfsType*)(&(IP_MC_CGM_2->PCFS_SDUR)),
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE] = {(Clock_Ip_ExtOSCType*)IP_FXOSC};
PLLDIG_Type* const Clock_Ip_pxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE] = {IP_CORE_PLL, IP_PERIPH_PLL, IP_DDR_PLL, IP_ACCEL_PLL};
DFS_Type* const Clock_Ip_apxDfs[CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE] = {IP_CORE_DFS,IP_PERIPH_DFS};
Clock_Ip_ClockMonitorType* const Clock_Ip_apxCmu[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE] =
{

    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_0,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_5,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_6,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_7,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_8,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_9,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_10,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_11,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_12,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_13,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_14,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_15,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_16,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_17,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_18,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_20,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_21,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_22,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_27,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_28,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_39,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_46,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_47,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_48,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_49,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_50,
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_51,
};
Clock_Ip_NameType const Clock_Ip_aeCmuNames[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE] =
{
        FXOSC_CLK,
        XBAR_DIV3_FAIL_CLK,
        CORE_M7_0_CLK,
        XBAR_DIV3_CLK,
        CORE_M7_1_CLK,
        CORE_M7_2_CLK,
        PER_CLK,
        SERDES_REF_CLK,
        FLEXRAY_CLK,
        FLEXCAN_CLK,
        GMAC0_TX_CLK,
        GMAC_TS_CLK,
        LINFLEXD_CLK,
        QSPI_1X_CLK,
        SDHC_CLK,
        DDR_CLK,
        GMAC0_RX_CLK,
        SPI_CLK,
        CORE_A53_CLUSTER_0_CLK,
        CORE_A53_CLUSTER_1_CLK,
        PFE_PE_CLK,
        PFEMAC0_TX_DIV_CLK,
        PFEMAC0_RX_CLK,
        PFEMAC1_TX_CLK,
        PFEMAC1_RX_CLK,
        PFEMAC2_TX_CLK,
        PFEMAC2_RX_CLK,
};

Clock_Ip_CmuInfoType const Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE] =  {

/* CLOCK_IP_CMU_0_INSTANCE */
{
    FXOSC_CLK,                                       /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_0,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_5_INSTANCE */
{
    XBAR_DIV3_FAIL_CLK,                              /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_5,         /* Cmu instance */
},
/* CLOCK_IP_CMU_6_INSTANCE */
{
    CORE_M7_0_CLK,                                   /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_6,         /* Cmu instance */
},
/* CLOCK_IP_CMU_7_INSTANCE */
{
    XBAR_DIV6_CLK,                                   /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_7,         /* Cmu instance */
},
/* CLOCK_IP_CMU_8_INSTANCE */
{
    CORE_M7_1_CLK,                                   /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_8,         /* Cmu instance */
},
/* CLOCK_IP_CMU_9_INSTANCE */
{
    CORE_M7_2_CLK,                                   /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_9,         /* Cmu instance */
},
/* CLOCK_IP_CMU_10_INSTANCE */
{
    PER_CLK,                                         /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_10,        /* Cmu instance */
},
/* CLOCK_IP_CMU_11_INSTANCE */
{
    SERDES_REF_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_11,        /* Cmu instance */
},
/* CLOCK_IP_CMU_12_INSTANCE */
{
    FLEXRAY_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_12,        /* Cmu instance */
},
/* CLOCK_IP_CMU_13_INSTANCE */
{
    FLEXCAN_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_13,        /* Cmu instance */
},
/* CLOCK_IP_CMU_14_INSTANCE */
{
    GMAC0_TX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_14,        /* Cmu instance */
},
/* CLOCK_IP_CMU_15_INSTANCE */
{
    GMAC_TS_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_15,        /* Cmu instance */
},
/* CLOCK_IP_CMU_16_INSTANCE */
{
    LINFLEXD_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_16,        /* Cmu instance */
},
/* CLOCK_IP_CMU_17_INSTANCE */
{
    QSPI_1X_CLK,                                     /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_17,        /* Cmu instance */
},
/* CLOCK_IP_CMU_18_INSTANCE */
{
    SDHC_CLK,                                        /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_18,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_20_INSTANCE */
{
    DDR_CLK,                                         /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_20,        /* Cmu instance */
},
/* CLOCK_IP_CMU_21_INSTANCE */
{
    GMAC0_RX_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_21,        /* Cmu instance */
},
/* CLOCK_IP_CMU_22_INSTANCE */
{
    SPI_CLK,                                         /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_22,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_27_INSTANCE */
{
    CORE_A53_CLUSTER_0_CLK,                          /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_27,        /* Cmu instance */
},
/* CLOCK_IP_CMU_28_INSTANCE */
{
    CORE_A53_CLUSTER_1_CLK,                          /* Name of the clock that supports cmu (clock monitor) */
    FIRC_CLK,                                        /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_28,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_39_INSTANCE */
{
    PFE_PE_CLK,                                      /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_39,        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* Reserved cmu instance */
{
    RESERVED_CLK,                                    /* Name of the clock that supports cmu (clock monitor) */
    RESERVED_CLK,                                    /* Name of the reference clock */
    RESERVED_CLK,                                    /* Name of the bus clock */
    NULL_PTR,                                        /* Cmu instance */
},
/* CLOCK_IP_CMU_46_INSTANCE */
{
    PFEMAC0_TX_DIV_CLK,                              /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_46,        /* Cmu instance */
},
/* CLOCK_IP_CMU_47_INSTANCE */
{
    PFEMAC0_RX_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_47,        /* Cmu instance */
},
/* CLOCK_IP_CMU_48_INSTANCE */
{
    PFEMAC1_TX_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_48,        /* Cmu instance */
},
/* CLOCK_IP_CMU_49_INSTANCE */
{
    PFEMAC1_RX_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_49,        /* Cmu instance */

},
/* CLOCK_IP_CMU_50_INSTANCE */
{
    PFEMAC2_TX_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_50,        /* Cmu instance */


},
/* CLOCK_IP_CMU_51_INSTANCE */
{
    PFEMAC2_RX_CLK,                                  /* Name of the clock that supports cmu (clock monitor) */
    FXOSC_CLK,                                       /* Name of the reference clock */
    XBAR_DIV6_CLK,                                   /* Name of the bus clock */
    (Clock_Ip_ClockMonitorType*)IP_CMU_FC_51,        /* Cmu instance */
},
};


        
volatile Clock_Ip_McmePartitionSetType* const Clock_Ip_apxMcMeSetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
    (volatile Clock_Ip_McmePartitionSetType*)((volatile uint8*)&IP_MC_ME->PRTN0_COFB0_CLKEN),
    NULL_PTR,
    (volatile Clock_Ip_McmePartitionSetType*)((volatile uint8*)&IP_MC_ME->PRTN2_COFB0_CLKEN),
    (volatile Clock_Ip_McmePartitionSetType*)((volatile uint8*)&IP_MC_ME->PRTN3_COFB0_CLKEN),
};
volatile const Clock_Ip_McmePartitionGetType* const Clock_Ip_apxMcMeGetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
    (volatile const Clock_Ip_McmePartitionGetType*)((volatile const uint8*)&IP_MC_ME->PRTN0_COFB0_STAT),
    NULL_PTR,
    (volatile const Clock_Ip_McmePartitionGetType*)((volatile const uint8*)&IP_MC_ME->PRTN2_COFB0_STAT),
    (volatile const Clock_Ip_McmePartitionGetType*)((volatile const uint8*)&IP_MC_ME->PRTN3_COFB0_STAT),
};
volatile Clock_Ip_McmePartitionTriggerType* const Clock_Ip_apxMcMeTriggerPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT] =
{
    (volatile Clock_Ip_McmePartitionTriggerType*)((volatile uint8*)&IP_MC_ME->PRTN0_PCONF),
    NULL_PTR,
    (volatile Clock_Ip_McmePartitionTriggerType*)((volatile uint8*)&IP_MC_ME->PRTN2_PCONF),
    (volatile Clock_Ip_McmePartitionTriggerType*)((volatile uint8*)&IP_MC_ME->PRTN3_PCONF),
};








const Clock_Ip_ClockNameSourceType Clock_Ip_aeSourceTypeClockName[CLOCK_IP_PRODUCERS_NO + 1U] = {
    IRCOSC_TYPE,                               /*!< FIRC_CLK                                */
    XOSC_TYPE,                                 /*!< FXOSC_CLK                               */
    IRCOSC_TYPE,                               /*!< SIRC_CLK                                */
    PLL_TYPE,                                  /*!< COREPLL_CLK                             */
    PLL_TYPE,                                  /*!< PERIPHPLL_CLK                           */
    PLL_TYPE,                                  /*!< DDRPLL_CLK                              */
    PLL_TYPE,                                  /*!< ACCELPLL_CLK                            */
    PLL_TYPE,                                  /*!< CORE_PLL_PHI0_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_PHI1_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS1_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS2_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS3_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS4_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS5_CLK                       */
    PLL_TYPE,                                  /*!< CORE_PLL_DFS6_CLK                       */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI0_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI1_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI2_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI3_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI4_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI5_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI6_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_PHI7_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS1_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS2_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS3_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS4_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS5_CLK                     */
    PLL_TYPE,                                  /*!< PERIPH_PLL_DFS6_CLK                     */
    PLL_TYPE,                                  /*!< DDR_PLL_PHI0_CLK                        */
    PLL_TYPE,                                  /*!< ACCEL_PLL_PHI0_CLK                      */
    PLL_TYPE,                                  /*!< ACCEL_PLL_PHI1_CLK                      */
    EXT_CLK_TYPE,                              /*!< RTC_EXT_REF_CLK                         */
    EXT_CLK_TYPE,                              /*!< FTM_0_EXT_REF_CLK                       */
    EXT_CLK_TYPE,                              /*!< FTM_1_EXT_REF_CLK                       */
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_REF_CLK                      */
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_RX_CLK                       */
    EXT_CLK_TYPE,                              /*!< GMAC_0_EXT_TX_CLK                       */
    EXT_CLK_TYPE,                              /*!< GMAC_EXT_TS_CLK                         */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_0_EXT_REF_CLK                   */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_0_EXT_RX_CLK                    */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_0_EXT_TX_CLK                    */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_1_EXT_REF_CLK                   */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_1_EXT_RX_CLK                    */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_1_EXT_TX_CLK                    */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_2_EXT_REF_CLK                   */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_2_EXT_RX_CLK                    */
    EXT_CLK_TYPE,                              /*!< PFE_MAC_2_EXT_TX_CLK                    */
    SERDES_TYPE,                              /*!< SERDES_0_XPCS_0_TX                      */
    SERDES_TYPE,                              /*!< SERDES_0_XPCS_0_CDR                     */
    SERDES_TYPE,                              /*!< SERDES_0_XPCS_1_TX                      */
    SERDES_TYPE,                              /*!< SERDES_0_XPCS_1_CDR                     */
    SERDES_TYPE,                              /*!< SERDES_1_XPCS_0_TX                      */
    SERDES_TYPE,                              /*!< SERDES_1_XPCS_0_CDR                     */
    SERDES_TYPE,                              /*!< SERDES_1_XPCS_1_TX                      */
    SERDES_TYPE,                              /*!< SERDES_1_XPCS_1_CDR                     */
    UKNOWN_TYPE,                               /*!< XBAR_2X_CLK                             */
    UKNOWN_TYPE,                               /*!< XBAR_CLK                                */
    UKNOWN_TYPE,                               /*!< XBAR_DIV2_CLK                           */
    UKNOWN_TYPE,                               /*!< XBAR_DIV3_CLK                           */
    UKNOWN_TYPE,                               /*!< XBAR_DIV4_CLK                           */
    UKNOWN_TYPE,                               /*!< XBAR_DIV6_CLK                           */
    UKNOWN_TYPE,                               /*!< A53_CORE_CLK                            */
    UKNOWN_TYPE,                               /*!< A53_CORE_DIV2_CLK                       */
    UKNOWN_TYPE,                               /*!< A53_CORE_DIV10_CLK                      */
    UKNOWN_TYPE,                               /*!< DDR_CLK                                 */
    UKNOWN_TYPE,                               /*!< PFE_PE_CLK                              */
    UKNOWN_TYPE,                               /*!< PFE_SYS_CLK                             */
    UKNOWN_TYPE,                               /*!< PER_CLK                                 */
    UKNOWN_TYPE,                               /*!< GMAC0_REF_CLK                           */
    UKNOWN_TYPE,                               /*!< GMAC0_REF_DIV_CLK                       */
    UKNOWN_TYPE,                               /*!< PFEMAC0_REF_DIV_CLK                     */
    UKNOWN_TYPE,                               /*!< PFEMAC1_REF_DIV_CLK                     */
    UKNOWN_TYPE,                               /*!< PFEMAC2_REF_DIV_CLK                     */
    UKNOWN_TYPE,                               /*!< SERDES_REF_CLK                          */
    UKNOWN_TYPE,                               /*!< THE_LAST_PRODUCER_CLK                   */
};

const Clock_Ip_NameType Clock_Ip_aeHwPllName[CLOCK_IP_NUMBER_OF_HARDWARE_PLL] =
{
    COREPLL_CLK,                    /* COREPLL_CLK Clock */
    PERIPHPLL_CLK,                  /* PERIPHPLL_CLK Clock */
    DDRPLL_CLK,                     /* DDRPLL_CLK Clock */
    ACCELPLL_CLK                    /* ACCELPLL_CLK Clock */
};
const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_NUMBER_OF_HARDWARE_DFS] =
{
    CORE_PLL_DFS1_CLK,              /* CORE_PLL_DFS1_CLK Clock */
    CORE_PLL_DFS2_CLK,              /* CORE_PLL_DFS2_CLK Clock */
    CORE_PLL_DFS3_CLK,              /* CORE_PLL_DFS3_CLK Clock */
    CORE_PLL_DFS4_CLK,              /* CORE_PLL_DFS4_CLK Clock */
    CORE_PLL_DFS5_CLK,              /* CORE_PLL_DFS5_CLK Clock */
    CORE_PLL_DFS6_CLK,              /* CORE_PLL_DFS6_CLK Clock */
    PERIPH_PLL_DFS1_CLK,            /* PERIPH_PLL_DFS1_CLK Clock */
    PERIPH_PLL_DFS2_CLK,            /* PERIPH_PLL_DFS2_CLK Clock */
    PERIPH_PLL_DFS3_CLK,            /* PERIPH_PLL_DFS3_CLK Clock */
    PERIPH_PLL_DFS4_CLK,            /* PERIPH_PLL_DFS4_CLK Clock */
    PERIPH_PLL_DFS5_CLK,            /* PERIPH_PLL_DFS5_CLK Clock */
    PERIPH_PLL_DFS6_CLK,            /* PERIPH_PLL_DFS6_CLK Clock */
};

const Clock_Ip_ClockExtensionType Clock_Ip_axFeatureExtensions[CLOCK_IP_EXTENSIONS_SIZE] = {
    /* Selector value mask            Selector value shift              Divider value mask             Divider value shift  */
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,    MC_CGM_MUX_0_CSC_SELCTL_SHIFT,    0U,                            0U},                             /*   CLOCK_IP_XBAR_2X_EXTENSION */
    {MC_CGM_1_MUX_0_CSC_SELCTL_MASK,  MC_CGM_1_MUX_0_CSC_SELCTL_SHIFT,  0U,                            0U},                             /*   CLOCK_IP_A53_CORE_EXTENSION */
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,    MC_CGM_MUX_0_CSC_SELCTL_SHIFT,    0U,                            0U},                             /*   CLOCK_IP_DDR_EXTENSION */
    {MC_CGM_2_MUX_0_CSC_SELCTL_MASK,  MC_CGM_2_MUX_0_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_0_DC_0_DIV_MASK,  MC_CGM_2_MUX_0_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFE_PE_EXTENSION  */
    {MC_CGM_MUX_3_CSC_SELCTL_MASK,    MC_CGM_MUX_3_CSC_SELCTL_SHIFT,    MC_CGM_MUX_3_DC_0_DIV_MASK,    MC_CGM_MUX_0_DC_0_DIV_SHIFT},    /*   CLOCK_IP_PER_EXTENSION   */
    {MC_CGM_MUX_15_CSC_SELCTL_MASK,   MC_CGM_MUX_15_CSC_SELCTL_SHIFT,   MC_CGM_MUX_15_DC_0_DIV_MASK,   MC_CGM_MUX_15_DC_0_DIV_SHIFT},   /*   CLOCK_IP_GMAC0_REF_DIV_EXTENSION    */
    {MC_CGM_2_MUX_7_CSC_SELCTL_MASK,  MC_CGM_2_MUX_7_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_7_DC_0_DIV_MASK,  MC_CGM_2_MUX_7_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC0_REF_DIV_EXTENSION  */
    {MC_CGM_2_MUX_8_CSC_SELCTL_MASK,  MC_CGM_2_MUX_8_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_8_DC_0_DIV_MASK,  MC_CGM_2_MUX_8_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC1_REF_DIV_EXTENSION  */
    {MC_CGM_2_MUX_9_CSC_SELCTL_MASK,  MC_CGM_2_MUX_9_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_9_DC_0_DIV_MASK,  MC_CGM_2_MUX_9_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC2_REF_DIV_EXTENSION  */
    {MC_CGM_MUX_1_CSC_SELCTL_MASK,    MC_CGM_MUX_1_CSC_SELCTL_SHIFT,    MC_CGM_MUX_1_DC_0_DIV_MASK,    MC_CGM_MUX_1_DC_0_DIV_SHIFT},    /*   CLOCK_IP_CLKOUT0_EXTENSION    */    
    {MC_CGM_MUX_2_CSC_SELCTL_MASK,    MC_CGM_MUX_2_CSC_SELCTL_SHIFT,    MC_CGM_MUX_2_DC_0_DIV_MASK,    MC_CGM_MUX_2_DC_0_DIV_SHIFT},    /*   CLOCK_IP_CLKOUT1_EXTENSION    */    
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,    MC_CGM_MUX_0_CSC_SELCTL_SHIFT,    MC_CGM_MUX_0_DC_1_DIV_MASK,    MC_CGM_MUX_0_DC_1_DIV_SHIFT},    /*   CLOCK_IP_DAPB_EXTENSION    */    
    {MC_CGM_MUX_7_CSC_SELCTL_MASK,    MC_CGM_MUX_7_CSC_SELCTL_SHIFT,    0U,                            0U},                             /*   CLOCK_IP_FLEXCAN_EXTENSION */
    {MC_CGM_MUX_6_CSC_SELCTL_MASK,    MC_CGM_MUX_6_CSC_SELCTL_SHIFT,    MC_CGM_MUX_6_DC_0_DIV_MASK,    MC_CGM_MUX_6_DC_0_DIV_SHIFT},    /*   CLOCK_IP_FLEXRAY_EXTENSION */
    {MC_CGM_MUX_4_CSC_SELCTL_MASK,    MC_CGM_MUX_4_CSC_SELCTL_SHIFT,    MC_CGM_MUX_4_DC_0_DIV_MASK,    MC_CGM_MUX_4_DC_0_DIV_SHIFT},    /*   CLOCK_IP_FLEXTIMERA_EXTENSION */
    {MC_CGM_MUX_5_CSC_SELCTL_MASK,    MC_CGM_MUX_5_CSC_SELCTL_SHIFT,    MC_CGM_MUX_5_DC_0_DIV_MASK,    MC_CGM_MUX_5_DC_0_DIV_SHIFT},    /*   CLOCK_IP_FLEXTIMERB_EXTENSION */
    {MC_CGM_MUX_9_CSC_SELCTL_MASK,    MC_CGM_MUX_9_CSC_SELCTL_SHIFT,    MC_CGM_MUX_9_DC_0_DIV_MASK,    MC_CGM_MUX_9_DC_0_DIV_SHIFT},    /*   CLOCK_IP_GMAC_TS_EXTENSION */
    {MC_CGM_MUX_11_CSC_SELCTL_MASK,   MC_CGM_MUX_11_CSC_SELCTL_SHIFT,   0U,                            0U},                             /*   CLOCK_IP_GMAC0_RX_EXTENSION */
    {MC_CGM_MUX_10_CSC_SELCTL_MASK,   MC_CGM_MUX_10_CSC_SELCTL_SHIFT,   MC_CGM_MUX_10_DC_0_DIV_MASK,   MC_CGM_MUX_10_DC_0_DIV_SHIFT},   /*   CLOCK_IP_GMAC0_TX_EXTENSION    */
    {MC_CGM_MUX_0_CSC_SELCTL_MASK,    MC_CGM_MUX_0_CSC_SELCTL_SHIFT,    MC_CGM_MUX_0_DC_0_DIV_MASK,    MC_CGM_MUX_0_DC_0_DIV_SHIFT},    /*   CLOCK_IP_LBIST_EXTENSION    */      
    {MC_CGM_MUX_8_CSC_SELCTL_MASK,    MC_CGM_MUX_8_CSC_SELCTL_SHIFT,    0U,                            0U},                             /*   CLOCK_IP_LIN_BAUD_EXTENSION */    
    {MC_CGM_2_MUX_4_CSC_SELCTL_MASK,  MC_CGM_2_MUX_4_CSC_SELCTL_SHIFT,  0U,                            0U},                             /*   CLOCK_IP_PFEMAC0_RX_EXTENSION */
    {MC_CGM_2_MUX_1_CSC_SELCTL_MASK,  MC_CGM_2_MUX_1_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_1_DC_0_DIV_MASK,  MC_CGM_2_MUX_1_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC0_TX_EXTENSION  */    
    {MC_CGM_2_MUX_5_CSC_SELCTL_MASK,  MC_CGM_2_MUX_5_CSC_SELCTL_SHIFT,  0U,                            0U},                             /*   CLOCK_IP_PFEMAC1_RX_EXTENSION */
    {MC_CGM_2_MUX_2_CSC_SELCTL_MASK,  MC_CGM_2_MUX_2_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_2_DC_0_DIV_MASK,  MC_CGM_2_MUX_2_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC1_TX_EXTENSION  */    
    {MC_CGM_2_MUX_6_CSC_SELCTL_MASK,  MC_CGM_2_MUX_6_CSC_SELCTL_SHIFT,  0U,                            0U},                             /*   CLOCK_IP_PFEMAC2_RX_EXTENSION */
    {MC_CGM_2_MUX_3_CSC_SELCTL_MASK,  MC_CGM_2_MUX_3_CSC_SELCTL_SHIFT,  MC_CGM_2_MUX_3_DC_0_DIV_MASK,  MC_CGM_2_MUX_3_DC_0_DIV_SHIFT},  /*   CLOCK_IP_PFEMAC2_TX_EXTENSION  */    
    {MC_CGM_MUX_12_CSC_SELCTL_MASK,   MC_CGM_MUX_12_CSC_SELCTL_SHIFT,   MC_CGM_MUX_12_DC_0_DIV_MASK,   MC_CGM_MUX_12_DC_0_DIV_SHIFT},   /*   CLOCK_IP_QSPI_2X_EXTENSION */
    {MC_CGM_MUX_16_CSC_SELCTL_MASK,   MC_CGM_MUX_16_CSC_SELCTL_SHIFT,   0U,                            0U},                             /*   CLOCK_IP_SPI_EXTENSION */
    {MC_CGM_MUX_14_CSC_SELCTL_MASK,   MC_CGM_MUX_14_CSC_SELCTL_SHIFT,   MC_CGM_MUX_14_DC_0_DIV_MASK,   MC_CGM_MUX_14_DC_0_DIV_SHIFT},   /*   CLOCK_IP_SDHC_EXTENSION */
};


Clock_Ip_GateInfoType const Clock_Ip_axGateInfo[CLOCK_IP_GATE_INFO_SIZE] =  {
    /* Partition value index                   Selector value index               Request value shift                  Request value mask  */
    {CLOCK_IP_PARTITION_0_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN0_COFB0_CLKEN_REQ0_SHIFT,  MC_ME_PRTN0_COFB0_CLKEN_REQ0_MASK},     /*   USDHC0_CLK clock                          */ \
    {CLOCK_IP_PARTITION_0_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN0_COFB0_CLKEN_REQ1_SHIFT,  MC_ME_PRTN0_COFB0_CLKEN_REQ1_MASK},     /*   DDR0_CLK clock                            */ \
    {CLOCK_IP_PARTITION_2_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN2_COFB0_CLKEN_REQ0_SHIFT,  MC_ME_PRTN2_COFB0_CLKEN_REQ0_MASK},     /*   PFEMAC0_RX_CLK/PFEMAC0_TX_CLK clock       */ \
    {CLOCK_IP_PARTITION_2_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN2_COFB0_CLKEN_REQ1_SHIFT,  MC_ME_PRTN2_COFB0_CLKEN_REQ1_MASK},     /*   PFEMAC1_RX_CLK/PFEMAC1_TX_CLK clock       */ \
    {CLOCK_IP_PARTITION_2_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN2_COFB0_CLKEN_REQ2_SHIFT,  MC_ME_PRTN2_COFB0_CLKEN_REQ2_MASK},     /*   PFEMAC2_RX_CLK/PFEMAC2_TX_CLK clock       */ \
    {CLOCK_IP_PARTITION_2_INDEX,               CLOCK_IP_COLLECTION_0_INDEX,       MC_ME_PRTN2_COFB0_CLKEN_REQ3_SHIFT,  MC_ME_PRTN2_COFB0_CLKEN_REQ3_MASK},     /*   GMAC0_TS_CLK clock                        */ \
};



/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


#endif /* (CLOCK_IP_PLATFORM_SPECIFIC) */

#ifdef __cplusplus
}
#endif

/** @} */

