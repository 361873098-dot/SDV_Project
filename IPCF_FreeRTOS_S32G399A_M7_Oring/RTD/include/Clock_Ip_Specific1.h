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

#ifndef CLOCK_IP_SPECIFIC1_H
#define CLOCK_IP_SPECIFIC1_H

/**
*   @file    Clock_Ip_Specific1.h
*   @version    4.0.2
*
*   @brief   CLOCK IP specific header file.
*   @details CLOCK IP specific header file.
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

#include "Mcal.h"
#include "Clock_Ip_Cfg_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC1_VENDOR_ID                       43
#define CLOCK_IP_SPECIFIC1_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_SPECIFIC1_AR_RELEASE_MINOR_VERSION        4
#define CLOCK_IP_SPECIFIC1_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_SPECIFIC1_SW_MAJOR_VERSION                4
#define CLOCK_IP_SPECIFIC1_SW_MINOR_VERSION                0
#define CLOCK_IP_SPECIFIC1_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Specific1.h file and Mcal.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC1_AR_RELEASE_MAJOR_VERSION    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC1_AR_RELEASE_MINOR_VERSION    != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific1.h and Mcal.h are different"
#endif
#endif

/* Check if Clock_Ip_Specific1.h file and Clock_Ip_Cfg_Defines.h file have same versions */
#if (CLOCK_IP_SPECIFIC1_VENDOR_ID  != CLOCK_IP_CFG_DEFINES_VENDOR_ID)
    #error "Clock_Ip_Specific1.h and Clock_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Specific1.h file and Clock_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC1_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC1_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC1_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Specific1.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/* Check if Clock_Ip_Specific1.h file and Clock_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC1_SW_MAJOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC1_SW_MINOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC1_SW_PATCH_VERSION != CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Specific1.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#define CLOCK_IP_DIVIDER_CALLBACKS_COUNT                                               4U
#define CLOCK_IP_CGM_X_DE_DIV_STAT_WITHOUT_PHASE                                       1U
#define CLOCK_IP_CGM_X_DE_DIV_WITHOUT_PHASE                                            2U
#define CLOCK_IP_PLLDIG_PLL0DIV_DE_DIV_OUTPUT                                          3U

#define CLOCK_IP_DIVIDERTRIGGER_CALLBACKS_COUNT                                        1U

#define CLOCK_IP_XOSC_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_FXOSC_OSCON_BYP_EOCV_GM_SEL                                           1U

#define CLOCK_IP_IRCOSC_CALLBACKS_COUNT                                                1U

#define CLOCK_IP_GATE_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_MC_ME_PARTITION_COFB_ENABLE_REQUEST                                   1U

#define CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT                                    2U
#define CLOCK_IP_DFS_MFI_MFN                                                           1U
#define CLOCK_IP_NUMBER_OF_HARDWARE_DFS                                                12U
#define CLOCK_IP_DFS_SUPPORT                                                  (STD_ON)

#define CLOCK_IP_PLL_CALLBACKS_COUNT                                                   3U
#define CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN_SSCGBYP_SPREADCTL_STEPNO_STEPSIZE           1U
#define CLOCK_IP_PLLDIG_RDIV_MFI_MFN_SDMEN                                             2U
#define CLOCK_IP_NUMBER_OF_HARDWARE_PLL                                                4U

#define CLOCK_IP_SELECTOR_CALLBACKS_COUNT                                              4U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWIP                                             1U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_RAMPDOWN_RAMPUP_SWIP                             2U
#define CLOCK_IP_CGM_X_CSC_CSS_CS_GRIP                                                 3U

#define CLOCK_IP_PCFS_CALLBACKS_COUNT                                                  2U
#define CLOCK_IP_CGM_X_PCFS_SDUR_DIVC_DIVE_DIVS                                        1U

#define CLOCK_IP_CMU_CALLBACKS_COUNT                                                   2U
#define CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF                                        1U

#define CLOCK_IP_ALL_CALLBACKS_COUNT                                                   7U



#define CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT                  2u
#define CLOCK_IP_MC_CGM_PCFS_COUNT                         64u
#define CLOCK_IP_PRTN_COFB_NO                            4u

#define CLOCK_IP_MC_CGM_INSTANCES_COUNT      6U
#define CLOCK_IP_MC_CGM_MUXS_COUNT           17U
#define CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE   1U
#define CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE    4U
#define CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE    2U
#define CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE    28U
#define CLOCK_IP_MC_ME_PARTITIONS_COUNT      4U
#define CLOCK_IP_DFS_INFO_SIZE               63U
#define CLOCK_IP_CMU_INFO_SIZE               55U
#define CLOCK_IP_GATE_INFO_SIZE              12U
#define CLOCK_IP_EXTENSIONS_SIZE             25U



#define MC_CGM_MUX_DC_DE_MASK                MC_CGM_MUX_0_DC_0_DE_MASK
#define MC_CGM_MUX_DC_DE_SHIFT               MC_CGM_MUX_0_DC_0_DE_SHIFT
#define MC_CGM_MUX_CSC_SAFE_SW_MASK          MC_CGM_MUX_0_CSS_SAFE_SW_MASK
#define MC_CGM_MUX_CSC_CLK_SW_MASK           MC_CGM_MUX_0_CSC_CLK_SW_MASK
#define MC_CGM_MUX_CSC_RAMPUP_MASK           MC_CGM_MUX_0_CSC_RAMPUP_MASK
#define MC_CGM_MUX_CSC_RAMPDOWN_MASK         MC_CGM_MUX_0_CSC_RAMPDOWN_MASK
#define MC_CGM_MUX_CSS_SWIP_MASK             MC_CGM_MUX_0_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWIP_IN_PROGRESS      MC_CGM_MUX_CSS_SWIP_MASK
#define MC_CGM_MUX_CSS_SWTRG_MASK            MC_CGM_MUX_0_CSS_SWTRG_MASK
#define MC_CGM_MUX_CSS_SWTRG_SHIFT           MC_CGM_MUX_0_CSS_SWTRG_SHIFT
#define CLOCK_IP_MC_CGM_MUX_CSS_SWTRG_SUCCEEDED       1U
#define MC_CGM_MUX_CSS_CLK_SW_MASK           MC_CGM_MUX_0_CSS_CLK_SW_MASK
#define CLOCK_IP_MC_CGM_MUX_CSS_CLK_SW_NOT_REQUESTED  0U
#define MC_CGM_MUX_CSC_CG_MASK               MC_CGM_MUX_1_CSC_CG_MASK
#define MC_CGM_MUX_CSC_FCG_MASK              MC_CGM_MUX_1_CSC_FCG_MASK
#define MC_CGM_MUX_CSS_CS_MASK               MC_CGM_MUX_1_CSS_CS_MASK
#define MC_CGM_MUX_CSS_CS_TRANSPARENT        MC_CGM_MUX_CSS_CS_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_PENDING MC_CGM_MUX_DIV_UPD_STAT_DIV_STAT_MASK
#define MC_CGM_PCFS_DIVC_INIT(x)             MC_CGM_PCFS_DIVC12_INIT(x)
#define MC_CGM_PCFS_DIVC_RATE(x)             MC_CGM_PCFS_DIVC12_RATE(x)
#define MC_CGM_PCFS_DIVE_DIVE(x)             MC_CGM_PCFS_DIVE12_DIVE(x)
#define MC_CGM_PCFS_DIVS_DIVS(x)             MC_CGM_PCFS_DIVS12_DIVS(x)
#define DFS_PORTSR_PORTSTAT_MASK             (DFS_PORTSR_PORTSTAT5_MASK | DFS_PORTSR_PORTSTAT4_MASK | DFS_PORTSR_PORTSTAT3_MASK | DFS_PORTSR_PORTSTAT2_MASK | DFS_PORTSR_PORTSTAT1_MASK | DFS_PORTSR_PORTSTAT0_MASK)
#define DFS_PORTSR_PORTSTAT_SHIFT            (DFS_PORTSR_PORTSTAT0_SHIFT)
#define DFS_PORTSR_PORTSTAT(x)               (((uint32)(((uint32)(x)) << DFS_PORTSR_PORTSTAT_SHIFT)) & DFS_PORTSR_PORTSTAT_MASK)

#define CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED          CMU_FC_GCR_FCE_MASK
#define CLOCK_IP_CMU_FREQUENCY_CHECK_STOPPED          0U
#define CLOCK_IP_CMU_ISR_MASK                         3U

#define CLOCK_IP_FXOSC_ALC_SUPPORTED                  (STD_OFF)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


typedef struct {
  uint32 CSC;
  const  uint32 CSS;
  uint32 Divider[CLOCK_IP_MC_CGM_MUX_MUX_DIV_COUNT];
  uint8 RESERVED_0[36];
  uint32 MUX_DIV_TRIG_CTRL;               /**< Clock Mux 0 Divider trigger Control Register, offset: 0x334 */
  uint32 MUX_DIV_TRIG;                    /**< Clock Mux 0 Divider trigger Register, offset: 0x338 */
  const  uint32 MUX_DIV_UPD_STAT;

}volatile Clock_Ip_CgmMuxType;


typedef struct {

    uint32 PCFS_SDUR;                           /**< PCFS Step Duration, offset: 0x0 */
    struct {                                    /* offset: 0x4, array step: 0xC */
      uint32 DIVC;                              /**< PCFS Divider Change 12 Register, array offset: 0x4, array step: 0xC */
      uint32 DIVE;                              /**< PCFS Divider End 12 Register, array offset: 0x8, array step: 0xC */
      uint32 DIVS;                              /**< PCFS Divider Start 12 Register, array offset: 0xC, array step: 0xC */
    } PCFS[CLOCK_IP_MC_CGM_PCFS_COUNT];

}Clock_Ip_CgmPcfsType;


typedef struct {
    volatile uint32 PRTN_COFB_CLKEN[CLOCK_IP_PRTN_COFB_NO];
}Clock_Ip_McmePartitionSetType;

typedef struct {
     volatile const  uint32 PRTN_COFB_STAT[CLOCK_IP_PRTN_COFB_NO];
}Clock_Ip_McmePartitionGetType;

typedef struct {
    volatile uint32 PRTN_PCONF;
    volatile uint32 PRTN_PUPD;
    volatile const  uint32 PRTN_STAT;
}Clock_Ip_McmePartitionTriggerType;

/** XOSC - Register Layout Typedef */
typedef struct {
    uint32 CTRL;                        /**< XOSC Control Register, offset: 0x0 */
    const  uint32 STAT;                        /**< Oscillator Status Register, offset: 0x4 */
}volatile Clock_Ip_ExtOSCType;

/** CMU - Register Layout Typedef */
typedef struct {
    uint32 GCR;                               /**< Global Configuration Register, offset: 0x0 */
    uint32 RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
    uint32 HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
    uint32 LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
    volatile uint32 SR;                                /**< Status Register, offset: 0x10 */
    uint32 IER;                               /**< Interrupt Enable Register, offset: 0x14 */

}Clock_Ip_ClockMonitorType;

typedef struct{

    Clock_Ip_NameType Name;       /* Name of the clock that can be monitored/supports cmu (clock monitor) */
    Clock_Ip_NameType Reference;  /* Name of the reference clock */
    Clock_Ip_NameType Bus;        /* Name of the bus clock */

    Clock_Ip_ClockMonitorType* CmuInstance;

}Clock_Ip_CmuInfoType;

typedef struct
{
    uint8 PartitionValue;
    uint8 ColectionValue;
    uint8 RequestValueShift;
    uint32 RequestValueMask;

}Clock_Ip_GateInfoType;

typedef struct
{
    uint32 SelectorValueMask;
    uint32 SelectorValueShift;
    uint32 DividerValueMask;
    uint32 DividerValueShift;

}Clock_Ip_ClockExtensionType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

extern Clock_Ip_CgmMuxType* const Clock_Ip_apxCgm[CLOCK_IP_MC_CGM_INSTANCES_COUNT][CLOCK_IP_MC_CGM_MUXS_COUNT];
extern volatile Clock_Ip_CgmPcfsType* const Clock_Ip_apxCgmPcfs[CLOCK_IP_MC_CGM_INSTANCES_COUNT];
extern Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE];
extern PLLDIG_Type* const Clock_Ip_pxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE];
extern DFS_Type* const Clock_Ip_apxDfs[CLOCK_IP_DFS_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_ClockMonitorType * const Clock_Ip_apxCmu[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];
extern Clock_Ip_NameType const Clock_Ip_aeCmuNames[CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE];

extern volatile Clock_Ip_McmePartitionSetType* const Clock_Ip_apxMcMeSetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
extern volatile const Clock_Ip_McmePartitionGetType* const Clock_Ip_apxMcMeGetPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
extern volatile Clock_Ip_McmePartitionTriggerType* const Clock_Ip_apxMcMeTriggerPartitions[CLOCK_IP_MC_ME_PARTITIONS_COUNT];
extern const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_NUMBER_OF_HARDWARE_DFS];

extern const Clock_Ip_CmuInfoType Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE];

extern const Clock_Ip_GateInfoType Clock_Ip_axGateInfo[CLOCK_IP_GATE_INFO_SIZE];

extern const Clock_Ip_ClockExtensionType Clock_Ip_axFeatureExtensions[CLOCK_IP_EXTENSIONS_SIZE];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"

extern const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_FEATURE_PRODUCERS_NO];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
void Clock_Ip_McMeEnterKey(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CLOCK_IP_SPECIFIC1_H */

