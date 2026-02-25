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

#ifndef POWER_IP_SPECIFIC_H
#define POWER_IP_SPECIFIC_H

/**
*   @file       Power_Ip_Specific.h
*   @version    4.0.2
*
*   @brief   POWER IP driver header file.
*   @details POWER IP driver header file.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip_Cfg_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_SPECIFIC_VENDOR_ID                       43
#define POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_SPECIFIC_SW_MAJOR_VERSION                4
#define POWER_IP_SPECIFIC_SW_MINOR_VERSION                0
#define POWER_IP_SPECIFIC_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file have same versions */
#if (POWER_IP_SPECIFIC_VENDOR_ID  != POWER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION != POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h are different"
#endif

/* Check if Power_Ip_Specific.h file and Power_Ip_Cfg_Defines.h file are of the same Software version */
#if ((POWER_IP_SPECIFIC_SW_MAJOR_VERSION != POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (POWER_IP_SPECIFIC_SW_MINOR_VERSION != POWER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (POWER_IP_SPECIFIC_SW_PATCH_VERSION != POWER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_Specific.h and Power_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief  The function Mcu_GetResetRawValue shall return an implementation specific value which does
*         not correspond to a valid value of the reset status register and is not equal to 0 if this
*         function is called prior to calling of the function Mcu_Init, and if supported by the
*         hardware.
*
*/

#define MCU_RAW_RESET_DEFAULT      ((uint32)0xFFFFFFFFUL)

#define MC_RGM_FES_RWBITS_MASK32    ((uint32)(MC_RGM_FES_F_FR_31_MASK | \
                                              MC_RGM_FES_F_FR_30_MASK | \
                                              MC_RGM_FES_F_FR_21_MASK | \
                                              MC_RGM_FES_F_FR_20_MASK | \
                                              MC_RGM_FES_F_FR_18_MASK | \
                                              MC_RGM_FES_F_FR_6_MASK  | \
                                              MC_RGM_FES_F_FR_4_MASK  | \
                                              MC_RGM_FES_F_FR_3_MASK  | \
                                              MC_RGM_FES_F_EXR_MASK))

#define MC_RGM_DES_RWBITS_MASK32    ((uint32)(MC_RGM_DES_F_DR_31_MASK | \
                                              MC_RGM_DES_F_DR_30_MASK | \
                                              MC_RGM_DES_F_DR_18_MASK | \
                                              MC_RGM_DES_F_DR_17_MASK | \
                                              MC_RGM_DES_F_DR_16_MASK | \
                                              MC_RGM_DES_F_DR_13_MASK | \
                                              MC_RGM_DES_F_DR_12_MASK | \
                                              MC_RGM_DES_F_DR_11_MASK | \
                                              MC_RGM_DES_F_DR_10_MASK | \
                                              MC_RGM_DES_F_DR_9_MASK  | \
                                              MC_RGM_DES_F_DR_8_MASK  | \
                                              MC_RGM_DES_F_DR_6_MASK  | \
                                              MC_RGM_DES_F_DR_4_MASK  | \
                                              MC_RGM_DES_F_DR_3_MASK  | \
                                              MC_RGM_DES_F_DR_1_MASK  | \
                                              MC_RGM_DES_F_POR_MASK))

#define MC_RGM_FES_IRQ_BITS_MASK    ((uint32)(MC_RGM_FES_F_FR_31_MASK | \
                                              MC_RGM_FES_F_EXR_MASK))

#define MC_RGM_DES_IRQ_BITS_MASK    ((uint32) 0x00000000U)

#define MC_RGM_RAWRESET_FES_BASE_SHIFT_U32      ((uint32)0U)
#define MC_RGM_RAWRESET_DES_BASE_SHIFT_U32      ((uint32)16U)

#define MC_RGM_FERD_RWBITS_MASK     ((uint32)(MC_RGM_FES_F_FR_31_MASK | \
                                              MC_RGM_FES_F_EXR_MASK))

/***********************************************************/
/*             MC_RGM_GetResetRawValue Defines             */
/***********************************************************/
#define MC_RGM_RAWRESET_FES_F_EXT_RST_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0x0U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_FCCU_RST_MASK32              ((uint32)( ( (uint32)0x01U << (uint32)0x1U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_ST_DONE_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0x2U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_SWT0_RST_MASK32            ((uint32)( ( (uint32)0x01U << (uint32)0x3U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_HSE_RAM_ECC_RST_MASK32     ((uint32)( ( (uint32)0x01U << (uint32)0x4U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_HSE_BOOT_ERR_RST_MASK32    ((uint32)( ( (uint32)0x01U << (uint32)0x5U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_HSE_CORE_LOCK_RST_MASK32   ((uint32)( ( (uint32)0x01U << (uint32)0x6U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_SW_FUNC_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0x7U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_FES_F_DEBUG_FUNC_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0x8U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_WAKEUP_MASK32                    ((uint32)( ( (uint32)0x01U << (uint32)0x9U ) << MC_RGM_RAWRESET_FES_BASE_SHIFT_U32 ))

#define MC_RGM_RAWRESET_DES_F_POR_MASK32                 ((uint32)( ( (uint32)0x01U << (uint32)0x0U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_NC_SPD_RST_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0x1U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_FCCU_FTR_MASK32            ((uint32)( ( (uint32)0x01U << (uint32)0x2U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_STCU_URF_MASK32            ((uint32)( ( (uint32)0x01U << (uint32)0x3U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_MC_RGM_FRE_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0x4U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_FXOSC_FAIL_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0x5U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_CORE_LOL_MASK32            ((uint32)( ( (uint32)0x01U << (uint32)0x6U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_PERIPH_LOL_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0x7U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_DDR_LOL_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0x8U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_ACC_LOL_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0x9U ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_XBAR_DIV3_CLK_FAIL_MASK32  ((uint32)( ( (uint32)0x01U << (uint32)0xAU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_HSE_LC_RST_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0xBU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_HSE_SNVS_RST_MASK32        ((uint32)( ( (uint32)0x01U << (uint32)0xCU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_HSE_SWT_RST_MASK32         ((uint32)( ( (uint32)0x01U << (uint32)0xDU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_SW_DEST_MASK32             ((uint32)( ( (uint32)0x01U << (uint32)0xEU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))
#define MC_RGM_RAWRESET_DES_F_DEBUG_DEST_MASK32          ((uint32)( ( (uint32)0x01U << (uint32)0xFU ) << MC_RGM_RAWRESET_DES_BASE_SHIFT_U32 ))


#define MC_RGM_PRST0_COFB0_RSTEN_RWBITS_MASK    ((uint32)0xFFFFFFFFU)
#define MC_RGM_PRST2_COFB0_RSTEN_RWBITS_MASK    ((uint32)0x000001FFU)
#define MC_RGM_PRST3_COFB0_RSTEN_RWBITS_MASK    ((uint32)0x000001FFU)

#define MC_RGM_PRST0_COFB0_RSTEN_PERIPH_MASK    ((uint32)0x00030038U)   /* Ignored the last three bits that touch the cores. */
#define MC_RGM_PRST1_COFB0_RSTEN_PERIPH_MASK    ((uint32)0x0000001FU)
#define MC_RGM_PRST2_COFB0_RSTEN_PERIPH_MASK    ((uint32)0x00000007U)
#define MC_RGM_PRST3_COFB0_RSTEN_PERIPH_MASK    ((uint32)0x00000007U)

/***********************************************************/
/*               MC_RGM_PRST_MAIN_PRST_INDEX               */
/***********************************************************/
#define MC_RGM_PRST_MAIN_PRST_INDEX         ((uint32)0U)

#define MC_RGM_PRST0_COFB0_RSTEN(value)               ( (uint32)( (uint32)(value) & MC_RGM_PRST0_COFB0_RSTEN_RWBITS_MASK ) )
#define MC_RGM_PRST1_COFB0_RSTEN(value)               ( (uint32)( (uint32)(value) & MC_RGM_PRST1_COFB0_RSTEN_RWBITS_MASK ) )
#define MC_RGM_PRST2_COFB0_RSTEN(value)               ( (uint32)( (uint32)(value) & MC_RGM_PRST2_COFB0_RSTEN_RWBITS_MASK ) )
#define MC_RGM_PRST3_COFB0_RSTEN(value)               ( (uint32)( (uint32)(value) & MC_RGM_PRST3_COFB0_RSTEN_RWBITS_MASK ) )

/***********************************************************/
/*                 MC_RGM_PRSTX_COFBX_RSTEN                */
/***********************************************************/
#define MC_RGM_MAIN_PRST_CORES_SHIFT                     ((uint32)0U)
#define MC_RGM_SECONDARY_PRST_CORES_SHIFT                ((uint32)1U)

#define MC_RGM_PRST0_COFB0_RSTEN_CORES_MASK(CoreIndex) ((uint32)( ( (uint32)0x01U << (uint32)CoreIndex ) << MC_RGM_MAIN_PRST_CORES_SHIFT ))
#define MC_RGM_PRST1_COFB0_RSTEN_CORES_MASK(CoreIndex) ((uint32)( ( (uint32)0x01U << (uint32)CoreIndex ) << MC_RGM_SECONDARY_PRST_CORES_SHIFT ))

#define MC_RGM_PRTN_RST_MASK    MC_RGM_PRST_0_PERIPH_0_RST_MASK
/***********************************************************/
/*                    RDC_RDx_CTRL_REG                     */
/***********************************************************/
#define RDC_RDX_CTRL_REG_CTRL_LOCK                      ((uint32)0x00000000U)
#define RDC_RDX_CTRL_REG_CTRL_UNLOCK                    (RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK)

#define RESET_RDX_CTRL_REG_RDX_INTERCONNECT_INTERFACE_DISABLE_VALUE_U32(value) ((uint32)( (uint32)( (value) & RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK ) >> RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_SHIFT ))

#define RDC_RDX_CTRL_REG_ICON_INTF_ENABLE               ((uint32)0x00000000U)
#define RDC_RDX_CTRL_REG_ICON_INTF_DISABLE              (RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK)


/***********************************************************/
/*                     RDC_RDx_STAT_REG                    */
/***********************************************************/
#define RDC_RDX_STAT_REG_RDX_INTERCONNECT_INTERFACE_DISABLE_STAT_VALUE_U32(value) ((uint32)( (uint32)( (value) & RESET_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT_MASK ) >> RESET_RD1_STAT_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_STAT_SHIFT ))
/***********************************************************/
/*                       MC_ME_PRTNx                       */
/***********************************************************/
#define MC_ME_PRTN0_PUPD_RWBITS_MASK        ((uint32)(MC_ME_PRTN0_PUPD_PCUD_MASK))
#define MC_ME_PRTN1_PUPD_RWBITS_MASK        ((uint32)(MC_ME_PRTN1_PUPD_PCUD_MASK | \
                                                      MC_ME_PRTN1_PUPD_OSSUD_MASK))
#define MC_ME_PRTN2_PUPD_RWBITS_MASK        ((uint32)(MC_ME_PRTN2_PUPD_PCUD_MASK | \
                                                      MC_ME_PRTN2_PUPD_OSSUD_MASK))
#define MC_ME_PRTN3_PUPD_RWBITS_MASK        ((uint32)(MC_ME_PRTN3_PUPD_PCUD_MASK | \
                                                      MC_ME_PRTN3_PUPD_OSSUD_MASK))
#define MC_ME_PRTN0_COFB0_CLKEN(value)      (((uint32)(((uint32)(value)) & MC_ME_PRTN0_COFB0_CLKEN_RWBITS_MASK)))
#define MC_ME_PRTN2_COFB0_CLKEN(value)      (((uint32)(((uint32)(value)) & MC_ME_PRTN2_COFB0_CLKEN_RWBITS_MASK)))
#define MC_ME_PRTN3_COFB0_CLKEN(value)      (((uint32)(((uint32)(value)) & MC_ME_PRTN3_COFB0_CLKEN_RWBITS_MASK)))

/***********************************************************/
/*                    MC_ME_MODE_CONF                      */
/***********************************************************/
#define MC_ME_MODE_CONF(value)              ((uint32)(((uint32)(value)) & ((uint32)(MC_ME_MODE_CONF_MASK))))
/**
* @brief            This macro is used to define the position of the first reset reason.
*
*/
#define POWER_IP_FIRST_RESET_REASON_POS      ((uint32)MCU_POWER_ON_RESET)

/***********************************************************************/
/*         Macros are used for struct header bellow                    */
/***********************************************************************/
/** Number of domains of the RESET module. */
#define POWER_IP_RESET_DOMAIN_COUNT                      (4u)
/** Number of instances of the RESET module. */
#define POWER_IP_RESET_INSTANCE_COUNT                    (1u)

#define POWER_IP_MC_ME_PRTN_COUNT                        (4U)
#define POWER_IP_MC_ME_CORE_COUNT                        (8U)
#define POWER_IP_MC_ME_COFB_COUNT                        (4U)

/** MC_RGM - Size of Registers Arrays */
#define POWER_IP_MC_RGM_PRST_COUNT                       (8U)
#define POWER_IP_MC_RGM_PSTAT_COUNT                      (8U)
#define POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT              (2U)

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{
    volatile uint32 RDC_CTRL_REG[POWER_IP_RESET_DOMAIN_COUNT];
    uint8 RESERVED_1[112];
    volatile const uint32 RDC_STAT_REG[POWER_IP_RESET_DOMAIN_COUNT];
} Power_Ip_RDC_Type;

typedef struct
{
    volatile uint32 PRTN_CORE_PCONF;                 /**< Partition Core Process Configuration Register, offset: 0x140 */
    volatile uint32 PRTN_CORE_PUPD;                  /**< Partition Core Process Update Register, offset: 0x144 */
    volatile const  uint32 PRTN_CORE_STAT;           /**< Partition Core Status Register, offset: 0x148 */
    volatile uint32 PRTN_CORE_ADDR;                  /**< Partition Core Address Register, offset: 0x14C */
    uint8 RESERVED[16U];
} Power_Ip_MC_ME_Prtn_Core_Type;

typedef struct
{
    volatile uint32 PRTN_PCONF;                       /**< Partition Process Configuration Register, offset: 0x100 */
    volatile uint32 PRTN_PUPD;                        /**< Partition Process Update Register, offset: 0x104 */
    volatile const  uint32 PRTN_STAT;                 /**< Partition Status Register, offset: 0x108 */
    uint8 RESERVED_0[4U];
    volatile const  uint32 PRTN_COFB_STAT[POWER_IP_MC_ME_COFB_COUNT];    /**< Partition COFB Sets Clock Status Register, offset: 0x110 */
    uint8 RESERVED_1[16U];
    volatile uint32 PRTN_COFB_CLKEN[POWER_IP_MC_ME_COFB_COUNT];          /**< Partition COFB Sets Clock Enable Register, offset: 0x130 */
    Power_Ip_MC_ME_Prtn_Core_Type McMePrtnCoreArray[POWER_IP_MC_ME_CORE_COUNT]; /**< Partition Core Array */
    uint8 RESERVED_2[192U];
} Power_Ip_MC_ME_Prtn_Type;

typedef struct
{
    volatile uint32 CTL_KEY;                           /**< Control Key Register, offset: 0x0 */
    volatile uint32 MODE_CONF;                         /**< Mode Configuration Register, offset: 0x4 */
    volatile uint32 MODE_UPD;                          /**< Mode Update Register, offset: 0x8 */
    volatile const uint32 MODE_STAT;                   /**< Mode Status Register, offset: 0xC */
    volatile uint32 MAIN_COREID;                       /**< Main Core ID Register, offset: 0x10 */
    uint8 RESERVED[236U];
    Power_Ip_MC_ME_Prtn_Type McMePrtnArray[POWER_IP_MC_ME_PRTN_COUNT];   /**< Partition Array */
} Power_Ip_MC_ME_Type;

/** MC_RGM - Register Layout Typedef */
typedef struct {
    volatile uint32 DES;                               /**< Destructive Event Status Register, offset: 0x0 */
    uint8 RESERVED_0[4];
    volatile uint32 FES;                               /**< Functional /External Reset Status Register, offset: 0x8 */
    volatile uint32 FERD;                              /**< Functional Event Reset Disable Register, offset: 0xC */
    uint8 RESERVED_1[4];
    volatile uint32 FREC;                              /**< Functional Reset Escalation Counter Register, offset: 0x14 */
    volatile uint32 FRET;                              /**< Functional Reset Escalation Threshold Register, offset: 0x18 */
    volatile uint32 DRET;                              /**< Destructive Reset Escalation Threshold Register, offset: 0x1C */
    volatile uint32 ERCTRL;                            /**< External Reset Control Register, offset: 0x20 */
    volatile uint32 RDSS;                              /**< Reset During Standby Status Register, offset: 0x24 */
    uint8 RESERVED_2[24];
    struct {                                            /* offset: 0x40, array step: 0x8 */
        volatile uint32 PRST_COFB[POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT];  /**< Peripheral Reset, array offset: 0x40, array step: 0x8 */
    } PRST[POWER_IP_MC_RGM_PRST_COUNT];
    uint8 RESERVED_3[192];
    struct {                                         /* offset: 0x140, array step: 0x8 */
        volatile const uint32 PSTAT_COFB[POWER_IP_MC_RGM_PRST_COFB_MAX_COUNT];  /**< Peripheral Reset Status Register, array offset: 0x140, array step: 0x8 */
    } PSTAT[POWER_IP_MC_RGM_PSTAT_COUNT];
} Power_Ip_MC_RGM_Type;

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_SPECIFIC_H */

