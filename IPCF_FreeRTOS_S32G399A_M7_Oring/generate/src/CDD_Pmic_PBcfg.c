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
*   @file    Pmic_PBcfg.c
*
*   @addtogroup PMIC_DRIVER_CONFIGURATION PMIC Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                          INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_PBCFG_VENDOR_ID_C                     43
#define PMIC_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PMIC_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define PMIC_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define PMIC_PBCFG_SW_MAJOR_VERSION_C              4
#define PMIC_PBCFG_SW_MINOR_VERSION_C              0
#define PMIC_PBCFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files CDD_Pmic_PBcfg.c and Pmic_Types.h are of the same vendor */
#if (PMIC_PBCFG_VENDOR_ID_C != PMIC_TYPES_VENDOR_ID)
    #error "CDD_Pmic_PBcfg.c and Pmic_Types.h have different vendor ids"
#endif
/* Check if the files CDD_Pmic_PBcfg.c and Pmic_Types.h are of the same Autosar version */
#if ((PMIC_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_PBCFG_AR_RELEASE_MINOR_VERSION_C    != PMIC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_PBCFG_AR_RELEASE_REVISION_VERSION_C != PMIC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Pmic_PBcfg.c and Pmic_Types.h are different"
#endif
/* Check if the files CDD_Pmic_PBcfg.c and Pmic_Types.h are of the same software version */
#if ((PMIC_PBCFG_SW_MAJOR_VERSION_C != PMIC_TYPES_SW_MAJOR_VERSION) || \
     (PMIC_PBCFG_SW_MINOR_VERSION_C != PMIC_TYPES_SW_MINOR_VERSION) || \
     (PMIC_PBCFG_SW_PATCH_VERSION_C != PMIC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Pmic_PBcfg.c and Pmic_Types.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PMIC_START_SEC_CONST_UNSPECIFIED
#include "Pmic_MemMap.h"
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
extern const Pmic_DemConfigType Pmic_DemConfig;
#endif
#define PMIC_STOP_SEC_CONST_UNSPECIFIED
#include "Pmic_MemMap.h"
/*==================================================================================================
                                       FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

#define PMIC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

static const Pmic_VR55XX_ReactionConfigType Pmic_VR55XX_ReactionConfigPB_0_0 =
{
    /* The ID for Reaction configuration. */
    (uint8)0
    ,
    /* The M_INT_MASK1 register configuration.*/
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_INT_MASK1_HVLDOOC_M_MASK16
    ,
    /* The M_INT_MASK2 register configuration.*/
    ((uint16)0x0000U)
    ,
    /* The M_TSD_CFG register configuration.*/
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_TSD_CFG_HVLDO_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_LDO3_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_LDO2_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_LDO1_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_BUCK3_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_BUCK2_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_BUCK1_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_BOOST_TSDCFG_MASK16
    | PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_U16(PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_105_SELECT_U16)
    ,
    /* The FS_INTB_MASK register configuration.*/
    ((uint16)0x0000U)
};

static const Pmic_VR55XX_ModeConfigType Pmic_VR55XX_ModeConfigPB_0_0 =
{
    /* The ID for Mode configuration. */
    (uint8)0,
    /* The selected target mode.*/
    PMIC_NORMAL_MODE,
    /* The M_MODE register configuration. */
    ((uint16)0x0000U)
    ,
    /* The M_SM_CTRL1 register configuration. */
    ((uint16)0x0000U)
    ,
    /* The M_REG_CTRL1 register configuration. */
    ((uint16)0x0000U)
    ,
    /* The M_REG_CTRL2 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_U16(PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_130_MA_SELECT_U16)
    | PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_U16(PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_520_MA_SELECT_U16)
    | PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_U16(PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_130_MA_SELECT_U16)
    | PMIC_VR55XX_M_REG_CTRL2_VBSTSR_U16(PMIC_VR55XX_M_REG_CTRL2_VBSTSR_500_SELECT_U16)
    ,
    /* The M_REG_CTRL3 register configuration. */
    ((uint16)0x0000U)
    ,
    /* The M_VMON_REGx register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16)
    | PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_U16(PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16)
    ,
    /* The M_LVB1_STBY_DVS register configuration. */
    ((uint16)0x0000U)

};
static const Pmic_VR55XX_ClockConfigType Pmic_VR55XX_ClockConfigPB_0_0 =
{
    /* The ID for clock configuration. */
    (uint8)0,
    /* External FIN selection at PLL input */
    (boolean)FALSE,    /* The M_CLOCK1 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_U16(PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_20000000_SELECT_U16)
    | PMIC_VR55XX_M_CLOCK1_FOUT_SEL_MASK16
    | PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_U16((uint16)0U)
    | PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_U16(PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_DISABLED_SELECT_U16)
    ,
    /* The M_CLOCK2 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_U16(PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_600000_SELECT_U16)
};


#if (STD_ON == PMIC_WATCHDOG_API)

static const Pmic_VR55XX_WatchdogConfigType Pmic_VR55XX_WatchdogConfigPB_0_0 =
{
    /* The ID for watchdog configuration. */
    (uint8)0,
    /* The FS_WD_WINDOW_DUR register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_3MS_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_64MS_SELECT_U16)
};
#endif

static const Pmic_VR55XX_InitConfigType Pmic_VR55XX_InitConfigPB_0 =
{
    /* The FS_I_SVS register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_U16((uint16)0U)
    ,

    /* The FS_I_OVUV_SAFE_REACTION1 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    ,

    /* The FS_I_OVUV_SAFE_REACTION2 register configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_U16(PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    ,

    /* The FS_I_WD_CFG configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_U16((uint16)1U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_U16((uint16)0U)
    | PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_U16(PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    ,

    /* The FS_WD_WINDOW_DUR configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16)
    | PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_64MS_SELECT_U16)
    ,
    /* The FS_WD_SEED configuration. */
    ((uint16)0x5ab2U)
    ,
    /* The FS_I_ABIST2_CTRL configuration. */
    ((uint16)0x0000U)
    ,

    /* The FS_I_SAFE_INPUTS configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_U16(PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_10MS_SELECT_U16)
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU2_FS_IMPACT_MASK16
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU1_FS_IMPACT_MASK16
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU12_FS_IMPACT_MASK16
    | PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_U16(PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_DISABLED_SELECT_U16)
    ,

    /* The FS_I_FSSM configuration. */
    ((uint16)0x0000U)
    | PMIC_VR55XX_FS_I_FSSM_BACKUP_SAFETY_PATH_MASK16
    | PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_U16(PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_FS0B_AND_RSTB_ASSERT_SELECT_U16)
    | PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_U16(PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_6_SELECT_U16)
};

static const Pmic_VR55XX_Otp_RegisterConfigType Pmic_VR55XX_aOtpMainRegisterConfigPB_0[PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER] =
{
    /*The CFG_VPRE_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_U8(PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_3_3_V_SELECT_U8)
    },

    /*The CFG_VPRE_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_VPRE_2_OTP_VPREV_STBY_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_U8(PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_60_SELECT_U8)
    },

    /*The CFG_VPRE_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_VPRE_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_520_MA_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_520_MA_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_80NS_SELECT_U8)
        | PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_U8(PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_120_MV_SELECT_U8)
    },

    /*The CFG_BOOST_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_U8(PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_00_V_SELECT_U8)
    },

    /*The CFG_BOOST_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_U8(PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_67_SELECT_U8 )
        | PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_U8(PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_60NS_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_2_OTP_BOOSTEN_OTP_MASK8
    },

    /*The CFG_BOOST_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BOOST_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_500_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_3_A_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_125_PF_SELECT_U8)
        | PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_U8(PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_500_KOHM_SELECT_U8)
    },

    /*The CFG_BUCK1_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK1_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_U8((uint8)64U)
    },

    /*The CFG_BUCK1_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK1_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_VB12MULTIPH_OTP_MASK8
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_3_6_A_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_1_0_UH_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK1_2_OTP_PWRON2_GATE_EN_OTP_MASK8
    },

    /*The CFG_BUCK2_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK2_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_U8((uint8)64U)
    },

    /*The CFG_BUCK2_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK2_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_3_6_A_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2EN_OTP_MASK8
        | PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_1_0_UH_SELECT_U8)
    },

    /*The CFG_BUCK3_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK3_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_U8(PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_1_V_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_1_0_UH_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3EN_OTP_MASK8
    },

    /*The CFG_BUCK3_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_BUCK3_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_U8(PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_3_6_A_SELECT_U8)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_U8((uint8)4U)
        | PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_U8((uint8)4U)
    },

    /*The CFG_LDO_ALL1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_LDO_ALL1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO1EN_OTP_MASK8
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO2EN_OTP_MASK8
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3EN_OTP_MASK8
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_HVLDOEN_OTP_MASK8
        | PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_8_V_SELECT_U8)
    },

    /*The CFG_LDO_ALL2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_LDO_ALL2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_1_8_V_SELECT_U8)
        | PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_U8(PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_8_V_SELECT_U8)
    },

    /*The CFG_SEQ_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_1_OTP_LDO3_LS_OTP_MASK8
    },

    /*The CFG_SEQ_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_U8(PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_0_8_V_SELECT_U8)
    },

    /*The CFG_SEQ_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_U8(PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_250US_SELECT_U8)
    },

    /*The CFG_SEQ_4_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SEQ_4_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_SLOT_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_TRANS_MODE_OTP_MASK8
    },

    /*The CFG_CLOCK_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_U8(PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_44_SELECT_U8)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_U8(PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_120NS_SELECT_U8)
    },

    /*The CFG_CLOCK_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_SSRAMP_OTP_MASK8
        | PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_AUTO_ON_OTP_MASK8
    },

    /*The CFG_CLOCK_3_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_U8((uint8)0U)
    },

    /*The CFG_CLOCK_4_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_CLOCK_4_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_U8(PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_9_SELECT_U8)
        | PMIC_VR55XX_CFG_CLOCK_4_OTP_VPRE_CLK_SEL_OTP_MASK8
    },

    /*The CFG_SM_1_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SM_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SM_1_OTP_HVLDO_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO3_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO2_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_LDO1_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK3_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK2_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_BUCK1_TSDCFG_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_1_OTP_BOOST_TSDCFG_OTP_MASK8
    },

    /*The CFG_SM_2_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SM_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_INFINITE_OTP_MASK8
        | PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_U8((uint8)2)
    },

    /*The CFG_I2C_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_I2C_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_U8(PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_LDO3_SELECT_U8)
    },

    /*The CFG_DEVID_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_DEVID_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_TIMER_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_DEVID_OTP_STBY_PGOOD_EN_OTP_MASK8
    },
    /*The CFG_SSRAMP_OTP register configuration.*/
    {
        PMIC_VR55XX_M_CFG_SSRAMP_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_U8(PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_130_MA_SELECT_U8)
        | PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_U8(PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_DVS_15_6_SELECT_U8)
        | PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_U8(PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_DVS_10_42_SELECT_U8)
        | PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_U8(PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SELECT_00_U8)
    }
};

static const Pmic_VR55XX_Otp_RegisterConfigType Pmic_VR55XX_aOtpFailSafeRegisterConfigPB_0[PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER] =
{
    /*The CFG_UVOV_1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_U8((uint8)64U)
    },

    /*The CFG_UVOV_2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_3_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_U8(PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_16_STEPS_AVAILABLE_SELECT_U8)
    },

    /*The CFG_UVOV_4_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_4_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_5_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_5_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_6_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_6_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_7_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_7_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_8_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_8_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_UVOV_9_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_UVOV_9_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_U8((uint8)0U)
    },

    /*The CFG_PGOOD_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_PGOOD_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VCORE_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VDDIO_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON1_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON2_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON3_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON4_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_RSTB2PGOOD_OTP_MASK8
        | PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_HVLDO_VMON_OTP_MASK8
    },

    /*The CFG_ABIST1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ABIST1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VCORE_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VDDIO_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON1_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON2_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON3_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON4_OTP_MASK8
        | PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_HVLDO_VMON_OTP_MASK8
    },
    /*The CFG_ASIL_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ASIL_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON1_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON2_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON3_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_OTP_VMON4_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_OTP_HVLDO_VMON_EN_OTP_MASK8
    },
    /*The CFG_I2C_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_I2C_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_U8((uint8)0U)
        | PMIC_VR55XX_CFG_I2C_OTP_VDDIO_VMON_EN_OTP_MASK8
    },
    /*The CFG_1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_1_OTP_VDDIO_V_OTP_MASK8
        | PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_U8(PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_0_8_V_SELECT_U8)
    },
    /*The CFG_2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_2_OTP_STBY_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_2_OTP_STBY_WINDOW_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_U8(PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_1024MS_SELECT_U8)
    },
    /*The CFG_DEGLITCH1_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH1_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_25US_SELECT_U8)
        | PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_25US_SELECT_U8)
    },
    /*The CFG_DEGLITCH2_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH2_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_25US_SELECT_U8)
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_25US_SELECT_U8)
        | PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_25US_SELECT_U8)
    },
    /*The CFG_DEGLITCH3_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_DEGLITCH3_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_25US_SELECT_U8)
        | PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_U8(PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_25US_SELECT_U8)
    },
    /*The CFG_ASIL_LEVEL_OTP_ADDR8 register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OTP_ADDR8,
        ((uint8)0x00U)
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FCCU_EN_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_SELECTION_OTP_MASK8
        | PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FLT_RECOVERY_EN_OTP_MASK8
    },
    /*The CFG_LBIST_BYP_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_LBIST_BYP_OTP_ADDR8,
        PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_ENABLE_SELECT_U8
    },
    /*The CFG_LBIST_BYP_NOT_OTP register configuration.*/
    {
        PMIC_VR55XX_FS_CFG_LBIST_BYP_NOT_OTP_ADDR8,
        PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_ENABLE_SELECT_U8
    }
};

static const Pmic_VR55XX_OtpConfigType Pmic_VR55XX_OtpConfigPB_0 =
{
    PMIC_VR55XX_NUMBER_OF_OTP_MAIN_REGISTER,
    &Pmic_VR55XX_aOtpMainRegisterConfigPB_0,

    PMIC_VR55XX_NUMBER_OF_OTP_FAIL_SAFE_REGISTER,
    &Pmic_VR55XX_aOtpFailSafeRegisterConfigPB_0
};

static const Pmic_Ipw_ModeConfigType Pmic_Ipw_ModeConfigPB_0[1U] =
{
    /* Start of Pmic_Ipw_ModeConfigPB_0_0[0] */
    {
        &Pmic_VR55XX_ModeConfigPB_0_0
    } /* End of Pmic_Ipw_ModeConfigPB_0_0[0]. */
};

static const Pmic_Ipw_ClockConfigType Pmic_Ipw_ClockConfigPB_0[1U] =
{
    /* Start of Pmic_Ipw_ClockConfigPB_0_0[0] */
    {
        &Pmic_VR55XX_ClockConfigPB_0_0
    } /* End of Pmic_Ipw_ClockConfigPB_0_0[0]. */
};

static const Pmic_Ipw_ReactionConfigType Pmic_Ipw_ReactionConfigPB_0[1U] =
{
    /* Start of Pmic_Ipw_ReactionConfigPB_0_0[0] */
    {
        &Pmic_VR55XX_ReactionConfigPB_0_0
    } /* End of Pmic_Ipw_ReactionConfigPB_0_0[0]. */
};
#if (STD_ON == PMIC_WATCHDOG_API)
static const Pmic_Ipw_WatchdogConfigType Pmic_Ipw_WatchdogConfigPB_0[1U] =
{
    /* Start of Pmic_Ipw_WatchdogConfigPB_0_0[0] */
    {
        &Pmic_VR55XX_WatchdogConfigPB_0_0
    } /* End of Pmic_Ipw_WatchdogConfigPB_0_0[0]. */
};
#endif

static const Pmic_VR55XX_ConfigType Pmic_VR55XX_DeviceInitConfigPB_0 =
{
    &Pmic_VR55XX_OtpConfigPB_0,
    &Pmic_VR55XX_InitConfigPB_0
};

static const Pmic_Ipw_HwDeviceConfigType Pmic_Ipw_HwDeviceConfigPB_0 =
{
    &Pmic_VR55XX_DeviceInitConfigPB_0
};

static const Pmic_InterfaceUnitConfigType Pmic_InterfaceUnitConfigPB_0=
{
    /* The type of the interface. */
    PMIC_INTERFACE_I2C,
    /* The I2C channel*/
    (uint8)0U,
    /* Main unit I2c address */
    (uint8)0x20U,
    /* Fail-safe unit I2c address*/
    (uint8)0x21U,
    /* Scl pin index */
    (uint32)0U,
    /* I2c scl pin - initial mode */
    (uint8)PORT_GPIO_MODE,
    /* I2c scl pin - mode */
    (uint8)SIUL2_0_PORT34_I2C_4_I2C4_SCL_INOUT,
    /* operating frequency */
    (uint32)133333333U,
    /* I2c channel frequency */
    (uint32)347222U,
    /* Dio channel id */
    (uint16)34U
};
static const Pmic_DeviceConfigType Pmic_DeviceConfigPB[1U] =
{
    /* Start of Pmic_DeviceConfigPB[0] */
    {
    /* ID of device */
    (uint8)0U,
    /* The number mode setting configuration of device */
    1U,
    /* The number clock setting configuration of device */
    1U,
    /* The number reaction setting configuration of device */
    1U,
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    /* The number amux setting configuration of device */
    0U,
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    /* The number svs setting configuration of device */
    0U,
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    /* The number watchdog setting configuration of device */
    1U,
#endif
    /* Pointer to device mode configuration structure*/
    &Pmic_Ipw_ModeConfigPB_0,
    /* Pointer to device clock configuration structure*/
    &Pmic_Ipw_ClockConfigPB_0,
    /* Pointer to device reaction configuration structure*/
    &Pmic_Ipw_ReactionConfigPB_0,
#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
    /* Pointer to device amux configuration structure*/
    NULL_PTR,
#endif
#if (STD_ON == PMIC_SWITCH_SVS_API)
    /* Pointer to device svs configuration structure*/
    NULL_PTR,
#endif
#if (STD_ON == PMIC_WATCHDOG_API)
    /* Pointer to device watchdog configuration structure*/
    &Pmic_Ipw_WatchdogConfigPB_0,
#endif
    /* Pointer to device interface unit configuration structure*/
    &Pmic_InterfaceUnitConfigPB_0,
    /* Pointer to device HW configuration structure*/
    &Pmic_Ipw_HwDeviceConfigPB_0
    }
    /* End of Pmic_DeviceConfigPB[0]. */
};
/**
* @brief          Initialization data for the PMIC driver.
* @details        A pointer to such a structure is provided to the PMIC initialization routines for configuration.
*
*/
const Pmic_ConfigType Pmic_Config =
{
#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    /* Index of Ocotp channel read eFuse Word OCOTP_BANK0_WORD6. */
    (uint32)0U,
#endif
    /* Total number of configured PMIC devices. */
    (uint8)PMIC_MAX_DEVICECONFIGS,
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
    /* Pointer to callout configured by user for watchdog task notifications. */
    NULL_PTR,
#endif
    /* Pointer to list of PMIC device configurations. */
    &Pmic_DeviceConfigPB,
#if (STD_OFF == PMIC_DISABLE_DEM_REPORT_ERROR_STATUS)
    /* Pointer to DEM error reporting configurations. */
    &Pmic_DemConfig
#endif
};

#define PMIC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

