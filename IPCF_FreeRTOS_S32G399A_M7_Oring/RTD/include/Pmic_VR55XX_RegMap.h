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

#ifndef REG_ESYS_VR55XX_H
#define REG_ESYS_VR55XX_H

/**
*   @file Reg_eSys_VR55XX.h
*
*   @addtogroup PMIC_VR5510 Pmic VR5510 driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define REG_ESYS_VR55XX_VENDOR_ID                    43
#define REG_ESYS_VR55XX_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_VR55XX_AR_RELEASE_MINOR_VERSION     4
#define REG_ESYS_VR55XX_AR_RELEASE_REVISION_VERSION  0
#define REG_ESYS_VR55XX_SW_MAJOR_VERSION             4
#define REG_ESYS_VR55XX_SW_MINOR_VERSION             0
#define REG_ESYS_VR55XX_SW_PATCH_VERSION             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**********************************************************************************/
/*                        OTP FAIL-SAFE REGISTER ADDRESSES                        */
/**********************************************************************************/
#define PMIC_VR55XX_FS_CFG_UVOV_1_OTP_ADDR8                ((uint8)0x0BU)
#define PMIC_VR55XX_FS_CFG_UVOV_2_OTP_ADDR8                ((uint8)0x0CU)
#define PMIC_VR55XX_FS_CFG_UVOV_3_OTP_ADDR8                ((uint8)0x0DU)
#define PMIC_VR55XX_FS_CFG_UVOV_4_OTP_ADDR8                ((uint8)0x0EU)
#define PMIC_VR55XX_FS_CFG_UVOV_5_OTP_ADDR8                ((uint8)0x0FU)
#define PMIC_VR55XX_FS_CFG_UVOV_6_OTP_ADDR8                ((uint8)0x10U)
#define PMIC_VR55XX_FS_CFG_UVOV_7_OTP_ADDR8                ((uint8)0x11U)
#define PMIC_VR55XX_FS_CFG_UVOV_8_OTP_ADDR8                ((uint8)0x12U)
#define PMIC_VR55XX_FS_CFG_UVOV_9_OTP_ADDR8                ((uint8)0x13U)
#define PMIC_VR55XX_FS_CFG_PGOOD_OTP_ADDR8                 ((uint8)0x14U)
#define PMIC_VR55XX_FS_CFG_ABIST1_OTP_ADDR8                ((uint8)0x15U)
#define PMIC_VR55XX_FS_CFG_ASIL_OTP_ADDR8                  ((uint8)0x16U)
#define PMIC_VR55XX_FS_CFG_I2C_OTP_ADDR8                   ((uint8)0x17U)
#define PMIC_VR55XX_FS_CFG_1_OTP_ADDR8                     ((uint8)0x18U)
#define PMIC_VR55XX_FS_CFG_2_OTP_ADDR8                     ((uint8)0x19U)
#define PMIC_VR55XX_FS_CFG_DEGLITCH1_OTP_ADDR8             ((uint8)0x1AU)
#define PMIC_VR55XX_FS_CFG_DEGLITCH2_OTP_ADDR8             ((uint8)0x1BU)
#define PMIC_VR55XX_FS_CFG_DEGLITCH3_OTP_ADDR8             ((uint8)0x1CU)
#define PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OTP_ADDR8            ((uint8)0x24U)
#define PMIC_VR55XX_FS_CFG_LBIST_BYP_OTP_ADDR8             ((uint8)0x25U)
#define PMIC_VR55XX_FS_CFG_LBIST_BYP_NOT_OTP_ADDR8         ((uint8)0x26U)

/**********************************************************************************/
/*                           OTP MAIN REGISTER ADDRESSES                          */
/**********************************************************************************/
#define PMIC_VR55XX_M_CFG_VPRE_1_OTP_ADDR8                 ((uint8)0x18U)
#define PMIC_VR55XX_M_CFG_VPRE_2_OTP_ADDR8                 ((uint8)0x19U)
#define PMIC_VR55XX_M_CFG_VPRE_3_OTP_ADDR8                 ((uint8)0x1AU)
#define PMIC_VR55XX_M_CFG_BOOST_1_OTP_ADDR8                ((uint8)0x1BU)
#define PMIC_VR55XX_M_CFG_BOOST_2_OTP_ADDR8                ((uint8)0x1CU)
#define PMIC_VR55XX_M_CFG_BOOST_3_OTP_ADDR8                ((uint8)0x1DU)
#define PMIC_VR55XX_M_CFG_BUCK1_1_OTP_ADDR8                ((uint8)0x1EU)
#define PMIC_VR55XX_M_CFG_BUCK1_2_OTP_ADDR8                ((uint8)0x1FU)
#define PMIC_VR55XX_M_CFG_BUCK2_1_OTP_ADDR8                ((uint8)0x20U)
#define PMIC_VR55XX_M_CFG_BUCK2_2_OTP_ADDR8                ((uint8)0x21U)
#define PMIC_VR55XX_M_CFG_BUCK3_1_OTP_ADDR8                ((uint8)0x22U)
#define PMIC_VR55XX_M_CFG_BUCK3_2_OTP_ADDR8                ((uint8)0x23U)
#define PMIC_VR55XX_M_CFG_LDO_ALL1_OTP_ADDR8               ((uint8)0x24U)
#define PMIC_VR55XX_M_CFG_LDO_ALL2_OTP_ADDR8               ((uint8)0x25U)
#define PMIC_VR55XX_M_CFG_SEQ_1_OTP_ADDR8                  ((uint8)0x26U)
#define PMIC_VR55XX_M_CFG_SEQ_2_OTP_ADDR8                  ((uint8)0x27U)
#define PMIC_VR55XX_M_CFG_SEQ_3_OTP_ADDR8                  ((uint8)0x28U)
#define PMIC_VR55XX_M_CFG_SEQ_4_OTP_ADDR8                  ((uint8)0x29U)
#define PMIC_VR55XX_M_CFG_CLOCK_1_OTP_ADDR8                ((uint8)0x2AU)
#define PMIC_VR55XX_M_CFG_CLOCK_2_OTP_ADDR8                ((uint8)0x2BU)
#define PMIC_VR55XX_M_CFG_CLOCK_3_OTP_ADDR8                ((uint8)0x2CU)
#define PMIC_VR55XX_M_CFG_CLOCK_4_OTP_ADDR8                ((uint8)0x2DU)
#define PMIC_VR55XX_M_CFG_SM_1_OTP_ADDR8                   ((uint8)0x2EU)
#define PMIC_VR55XX_M_CFG_SM_2_OTP_ADDR8                   ((uint8)0x2FU)
#define PMIC_VR55XX_M_CFG_I2C_OTP_ADDR8                    ((uint8)0x30U)
#define PMIC_VR55XX_M_CFG_DEVID_OTP_ADDR8                  ((uint8)0x31U)
#define PMIC_VR55XX_M_CFG_SSRAMP_OTP_ADDR8                 ((uint8)0x32U)

/**********************************************************************************/
/*                             MAIN REGISTER ADDRESSES                            */
/**********************************************************************************/
#define PMIC_VR55XX_TEST_MODE_MAIN_UNIT_ADDR8              ((uint8)0x20U)
#define PMIC_VR55XX_TEST_MODE_FAIL_SAFE_UNIT_ADDR8         ((uint8)0x21U)

#define PMIC_VR55XX_M_FLAG_ADDR8                           ((uint8)0x00U)
#define PMIC_VR55XX_M_MODE_ADDR8                           ((uint8)0x01U)
#define PMIC_VR55XX_M_SM_CTRL1_ADDR8                       ((uint8)0x02U)
#define PMIC_VR55XX_M_REG_CTRL1_ADDR8                      ((uint8)0x03U)
#define PMIC_VR55XX_M_REG_CTRL2_ADDR8                      ((uint8)0x04U)
#define PMIC_VR55XX_M_REG_CTRL3_ADDR8                      ((uint8)0x05U)
#define PMIC_VR55XX_M_TSD_CFG_ADDR8                        ((uint8)0x06U)
#define PMIC_VR55XX_M_AMUX_ADDR8                           ((uint8)0x07U)
#define PMIC_VR55XX_M_CLOCK1_ADDR8                         ((uint8)0x08U)
#define PMIC_VR55XX_M_CLOCK2_ADDR8                         ((uint8)0x09U)
#define PMIC_VR55XX_M_INT_MASK1_ADDR8                      ((uint8)0x0AU)
#define PMIC_VR55XX_M_INT_MASK2_ADDR8                      ((uint8)0x0BU)
#define PMIC_VR55XX_M_FLAG1_ADDR8                          ((uint8)0x0CU)
#define PMIC_VR55XX_M_FLAG2_ADDR8                          ((uint8)0x0DU)
#define PMIC_VR55XX_M_FLAG3_ADDR8                          ((uint8)0x0EU)
#define PMIC_VR55XX_M_VMON_REGX_ADDR8                      ((uint8)0x0FU)
#define PMIC_VR55XX_M_LVB1_SVS_ADDR8                       ((uint8)0x10U)
#define PMIC_VR55XX_M_LVB1_STBY_DVS_ADDR8                  ((uint8)0x11U)
#define PMIC_VR55XX_M_MIRRORCMD_ADDR8                      ((uint8)0x12U)
#define PMIC_VR55XX_M_MIRRORDATA_ADDR8                     ((uint8)0x13U)
#define PMIC_VR55XX_M_OTPCMD_ADDR8                         ((uint8)0x16U)
#define PMIC_VR55XX_M_OTPSTATUS0_ADDR8                     ((uint8)0x17U)
#define PMIC_VR55XX_M_TM_ENTRY_ADDR8                       ((uint8)0x1FU)
#define PMIC_VR55XX_M_TM_STATUS1_ADDR8                     ((uint8)0x25U)
#define PMIC_VR55XX_M_MEMORY0_ADDR8                        ((uint8)0x29U)
#define PMIC_VR55XX_M_MEMORY1_ADDR8                        ((uint8)0x2AU)
#define PMIC_VR55XX_M_DEVICEID_ADDR8                       ((uint8)0x2BU)

/**********************************************************************************/
/*                          FAIL-SAFE REGISTER ADDRESSES                          */
/**********************************************************************************/
#define PMIC_VR55XX_FS_GRL_FLAGS_ADDR8                             ((uint8)0x00U)

/* To be written only during the "INIT_FS" state */
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_ADDR8                 ((uint8)0x01U)
#define PMIC_VR55XX_FS_I_NOT_OVUV_SAFE_REACTION1_ADDR8             ((uint8)0x02U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_ADDR8                 ((uint8)0x03U)
#define PMIC_VR55XX_FS_I_NOT_OVUV_SAFE_REACTION2_ADDR8             ((uint8)0x04U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_ADDR8                         ((uint8)0x05U)
#define PMIC_VR55XX_FS_I_NOT_ABIST2_CTRL_ADDR8                     ((uint8)0x06U)
#define PMIC_VR55XX_FS_I_WD_CFG_ADDR8                              ((uint8)0x07U)
#define PMIC_VR55XX_FS_I_NOT_WD_CFG_ADDR8                          ((uint8)0x08U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_ADDR8                         ((uint8)0x09U)
#define PMIC_VR55XX_FS_I_NOT_SAFE_INPUTS_ADDR8                     ((uint8)0x0AU)
#define PMIC_VR55XX_FS_I_FSSM_ADDR8                                ((uint8)0x0BU)
#define PMIC_VR55XX_FS_I_NOT_FSSM_ADDR8                            ((uint8)0x0CU)
#define PMIC_VR55XX_FS_I_SVS_ADDR8                                 ((uint8)0x0DU)
#define PMIC_VR55XX_FS_I_NOT_SVS_ADDR8                             ((uint8)0x0EU)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8                         ((uint8)0x0FU)
#define PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8                     ((uint8)0x10U)
#define PMIC_VR55XX_FS_WD_SEED_ADDR8                               ((uint8)0x11U)
#define PMIC_VR55XX_FS_WD_ANSWER_ADDR8                             ((uint8)0x12U)
#define PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8                        ((uint8)0x13U)
#define PMIC_VR55XX_FS_RELEASE_FS0B_ADDR8                          ((uint8)0x14U)
#define PMIC_VR55XX_FS_SAFE_IOS_ADDR8                              ((uint8)0x15U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8                           ((uint8)0x16U)
#define PMIC_VR55XX_FS_INTB_MASK_ADDR8                             ((uint8)0x17U)
#define PMIC_VR55XX_FS_STATES_ADDR8                                ((uint8)0x18U)

#define PMIC_VR55XX_FS_MIRRORCMD_ADDR8                             ((uint8)0x19U)
#define PMIC_VR55XX_FS_MIRRORDATA_ADDR8                            ((uint8)0x1AU)
#define PMIC_VR55XX_FS_OTPCMD_ADDR8                                ((uint8)0x1DU)
#define PMIC_VR55XX_FS_OTPSTATUS0_ADDR8                            ((uint8)0x1EU)
#define PMIC_VR55XX_FS_TM_ENTRY_ADDR8                              ((uint8)0x26U)
#define PMIC_VR55XX_FS_TM_STATUS1_ADDR8                            ((uint8)0x2BU)

/**********************************************************************************/
/*                            OTP MAIN REGISTER MASKS                             */
/**********************************************************************************/

/*                              CFG_VPRE_1_OTP MASKS                              */
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_MASK8                 ((uint8)0x3FU)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_SHIFT8                ((uint8)0U)

/*                              CFG_VPRE_2_OTP MASKS                              */
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPREDIS_OTP_MASK8               ((uint8)0x80U)
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPREV_STBY_EN_OTP_MASK8         ((uint8)0x40U)


#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_MASK8                ((uint8)0x3FU)
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_SHIFT8               ((uint8)0U)

/*                              CFG_VPRE_3_OTP MASKS                              */
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_MASK8              ((uint8)0x03U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_MASK8              ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_SHIFT8             ((uint8)2U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_MASK8              ((uint8)0x30U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_SHIFT8             ((uint8)4U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_MASK8              ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_SHIFT8             ((uint8)6U)

/*                              CFG_BOOST_1_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_MASK8               ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_SHIFT8              ((uint8)0U)

#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBOS_VBOOST_OTP_MASK8         ((uint8)0x10U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_EXT_STBY_DISCH_OTP_MASK8      ((uint8)0X20U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_PSYNC_PGOOD_EXT_OTP_MASK8     ((uint8)0X40U)

/*                              CFG_BOOST_2_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_MASK8              ((uint8)0x1FU)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_MASK8         ((uint8)0x60U)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_SHIFT8        ((uint8)5U)

#define PMIC_VR55XX_CFG_BOOST_2_OTP_BOOSTEN_OTP_MASK8             ((uint8)0x80U)

/*                              CFG_BOOST_3_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_MASK8              ((uint8)0x03U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_MASK8            ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_SHIFT8           ((uint8)2U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_MASK8           ((uint8)0x30U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_SHIFT8          ((uint8)4U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_MASK8           ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_SHIFT8          ((uint8)6U)

/*                              CFG_BUCK1_1_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_MASK8               ((uint8)0xFFU)
#define PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_SHIFT8              ((uint8)0x0U)

/*                              CFG_BUCK1_2_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BUCK1_2_OTP_VB12MULTIPH_OTP_MASK8          ((uint8)0x01U)

#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_MASK8           ((uint8)0x06U)
#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_SHIFT8          ((uint8)1U)

#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_MASK8        ((uint8)0x18U)
#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_SHIFT8       ((uint8)3U)

#define PMIC_VR55XX_CFG_BUCK1_2_OTP_STBY_PGOOD_DLY_OTP_MASK8       ((uint8)0x20U)

#define PMIC_VR55XX_CFG_BUCK1_2_OTP_PWRON2_GATE_EN_OTP_MASK8       ((uint8)0x40U)
#define PMIC_VR55XX_CFG_BUCK1_2_OTP_PSYNC_PWRDWN_EN_OTP_MASK8      ((uint8)0x80U)

/*                              CFG_BUCK2_1_OTP MASKS                             */
#define PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_MASK8               ((uint8)0xFFU)
#define PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_SHIFT8              ((uint8)0x0U)

/*                            CFG_BUCK2_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK3_GM_OTP_MASK8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK3_RC_OTP_MASK8             ((uint8)0x02U)

#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_MASK8           ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_SHIFT8          ((uint8)2U)

#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2EN_OTP_MASK8              ((uint8)0x10U)

#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_MASK8        ((uint8)0x60U)
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_SHIFT8       ((uint8)5U)

#define PMIC_VR55XX_CFG_BUCK2_2_OTP_AMUX_FOUT_OTP_MASK8            ((uint8)0x80U)

/*                            CFG_BUCK3_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_MASK8               ((uint8)0x1FU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_SHIFT8              ((uint8)0U)

#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_MASK8        ((uint8)0x60U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_SHIFT8       ((uint8)5U)

#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3EN_OTP_MASK8              ((uint8)0x80U)

/*                            CFG_BUCK3_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_MASK8           ((uint8)0x03U)
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_SHIFT8          ((uint8)0U)

#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_MASK8           ((uint8)0x1CU)
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_SHIFT8          ((uint8)2U)

#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_MASK8           ((uint8)0xE0U)
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_SHIFT8          ((uint8)5U)

/*                            CFG_LDO_ALL1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO1EN_OTP_MASK8              ((uint8)0x01U)
#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO2EN_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3EN_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_HVLDOEN_OTP_MASK8             ((uint8)0x08U)

#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_MASK8               ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_SHIFT8              ((uint8)4U)

/*                            CFG_LDO_ALL2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_MASK8               ((uint8)0x07U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_SHIFT8              ((uint8)0U)

#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1ILIM_OTP_MASK8            ((uint8)0x08U)

#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_MASK8               ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_SHIFT8              ((uint8)4U)

/*                            CFG_SEQ_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_MASK8                 ((uint8)0x07U)
#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_SHIFT8                ((uint8)0U)

#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_MASK8                 ((uint8)0x38U)
#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_SHIFT8                ((uint8)3U)

#define PMIC_VR55XX_CFG_SEQ_1_OTP_LDO2_LS_OTP_MASK8                ((uint8)0x40U)
#define PMIC_VR55XX_CFG_SEQ_1_OTP_LDO3_LS_OTP_MASK8                ((uint8)0x80U)

/*                            CFG_SEQ_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_MASK8                  ((uint8)0x07U)
#define PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_SHIFT8                 ((uint8)0U)

#define PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_MASK8                 ((uint8)0x38U)
#define PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_SHIFT8                ((uint8)3U)

#define PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_MASK8                 ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_SHIFT8                ((uint8)6U)

/*                            CFG_SEQ_3_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_MASK8                  ((uint8)0x07U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_SHIFT8                 ((uint8)0U)

#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_MASK8                  ((uint8)0x38U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_SHIFT8                 ((uint8)3U)

#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_MASK8             ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_SHIFT8            ((uint8)6U)

/*                            CFG_SEQ_4_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_MASK8                 ((uint8)0x07U)
#define PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_SHIFT8                ((uint8)0U)

#define PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_MASK8                 ((uint8)0x38U)
#define PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_SHIFT8                ((uint8)3U)

#define PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_SLOT_EN_OTP_MASK8          ((uint8)0x40U)
#define PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDO_TRANS_MODE_OTP_MASK8       ((uint8)0x80U)

/*                            CFG_CLOCK_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_MASK8             ((uint8)0x07U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_SHIFT8            ((uint8)0U)

#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_MASK8              ((uint8)0x38U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_SHIFT8             ((uint8)3U)

#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_MASK8         ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_SHIFT8        ((uint8)6U)

/*                            CFG_CLOCK_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_MASK8              ((uint8)0x07U)
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_MASK8             ((uint8)0x38U)
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_SHIFT8            ((uint8)3U)

#define PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_SSRAMP_OTP_MASK8          ((uint8)0x40U)
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_VPRE_AUTO_ON_OTP_MASK8         ((uint8)0x80U)

/*                            CFG_CLOCK_3_OTP MASKS                          */
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_MASK8             ((uint8)0x07U)
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_MASK8             ((uint8)0x38U)
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_SHIFT8             ((uint8)3U)

#define PMIC_VR55XX_CFG_CLOCK_3_OTP_AUTORETRY_TIMEOUT_OTP_MASK8    ((uint8)0x40U)
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_DSM_EN_OTP_MASK8               ((uint8)0x80U)

/*                            CFG_CLOCK_4_OTP MASKS                          */
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_MASK8             ((uint8)0x03U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_SHIFT8            ((uint8)0U)

#define PMIC_VR55XX_CFG_CLOCK_4_OTP_PLL_SEL_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_VPRE_CLK_SEL_OTP_MASK8         ((uint8)0x08U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_VBST_CLK_SEL_OTP_MASK8         ((uint8)0x10U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK1_CLK_SEL_OTP_MASK8        ((uint8)0x20U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK2_CLK_SEL_OTP_MASK8        ((uint8)0x40U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_BUCK3_CLK_SEL_OTP_MASK8        ((uint8)0x80U)

/*                            CFG_SM_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SM_1_OTP_HVLDO_TSDCFG_OTP_MASK8            ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SM_1_OTP_LDO3_TSDCFG_OTP_MASK8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SM_1_OTP_LDO2_TSDCFG_OTP_MASK8             ((uint8)0x04U)
#define PMIC_VR55XX_CFG_SM_1_OTP_LDO1_TSDCFG_OTP_MASK8             ((uint8)0x08U)
#define PMIC_VR55XX_CFG_SM_1_OTP_BUCK3_TSDCFG_OTP_MASK8            ((uint8)0x10U)
#define PMIC_VR55XX_CFG_SM_1_OTP_BUCK2_TSDCFG_OTP_MASK8            ((uint8)0x20U)
#define PMIC_VR55XX_CFG_SM_1_OTP_BUCK1_TSDCFG_OTP_MASK8            ((uint8)0x40U)
#define PMIC_VR55XX_CFG_SM_1_OTP_BOOST_TSDCFG_OTP_MASK8            ((uint8)0x80U)

/*                            CFG_SM_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SM_2_OTP_PSYNC_EN_OTP_MASK8                ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SM_2_OTP_PSYNC_CFG_OTP_MASK8               ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_EN_OTP_MASK8            ((uint8)0x04U)
#define PMIC_VR55XX_CFG_SM_2_OTP_AUTORETRY_INFINITE_OTP_MASK8      ((uint8)0x08U)
#define PMIC_VR55XX_CFG_SM_2_OTP_VPRE_OFF_DLY_OTP_MASK8            ((uint8)0x10U)

#define PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_MASK8         ((uint8)0xE0U)
#define PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_SHIFT8        ((uint8)5U)

/*                            CFG_I2C_OTP MASKS                          */
#define PMIC_VR55XX_CFG_I2C_OTP_VSUPCFG_OTP_MASK8                  ((uint8)0x01U)

#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_MASK8               ((uint8)0x1EU)
#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_SHIFT8              ((uint8)1U)

#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_MASK8         ((uint8)0xE0U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_SHIFT8        ((uint8)5U)

/*                            CFG_DEVID_OTP MASKS                          */
#define PMIC_VR55XX_CFG_DEVID_OTP_DEVICEID_OTP_MASK8               ((uint8)0x0FU)

#define PMIC_VR55XX_CFG_DEVID_OTP_STBY_TIMER_EN_OTP_MASK8          ((uint8)0x10U)
#define PMIC_VR55XX_CFG_DEVID_OTP_STBY_DISCH_OTP_MASK8             ((uint8)0x20U)
#define PMIC_VR55XX_CFG_DEVID_OTP_STBY_POLARITY_OTP_MASK8          ((uint8)0x40U)
#define PMIC_VR55XX_CFG_DEVID_OTP_STBY_PGOOD_EN_OTP_MASK8          ((uint8)0x80U)

/*                            CFG_SSRAMP_OTP MASKS                          */
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_MASK8        ((uint8)0x03U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_SHIFT8       ((uint8)0U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_MASK8            ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_SHIFT8           ((uint8)2U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_MASK8          ((uint8)0x30U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SHIFT8         ((uint8)4U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_MASK8          ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_SHIFT8         ((uint8)6U)


/**********************************************************************************/
/*                            OTP FAIL-SAFE REGISTER MASKS                        */
/**********************************************************************************/
/*                            CFG_UVOV_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_MASK8               ((uint8)0xFFU)
#define PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_SHIFT8              ((uint8)0U)

/*                            CFG_UVOV_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_3_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_MASK8              ((uint8)0x3FU)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_FULL_OFFSET_OTP_MASK8        ((uint8)0x40U)

/*                            CFG_UVOV_4_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_5_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_6_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_7_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_8_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_UVOV_9_OTP MASKS                          */
#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_SHIFT8             ((uint8)0U)

#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_MASK8              ((uint8)0xF0U)
#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_SHIFT8             ((uint8)4U)

/*                            CFG_PGOOD_OTP MASKS                          */
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VCORE_OTP_MASK8              ((uint8)0x01U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VDDIO_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON1_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON2_OTP_MASK8              ((uint8)0x08U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON3_OTP_MASK8              ((uint8)0x10U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_VMON4_OTP_MASK8              ((uint8)0x20U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_RSTB2PGOOD_OTP_MASK8         ((uint8)0x40U)
#define PMIC_VR55XX_CFG_PGOOD_OTP_PGOOD_HVLDO_VMON_OTP_MASK8         ((uint8)0x80U)

/*                            CFG_ABIST1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VCORE_OTP_MASK8              ((uint8)0x01U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VDDIO_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON1_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON2_OTP_MASK8              ((uint8)0x08U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON3_OTP_MASK8              ((uint8)0x10U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_VMON4_OTP_MASK8              ((uint8)0x20U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_ABIST1_HVLDO_VMON_OTP_MASK8         ((uint8)0x40U)
#define PMIC_VR55XX_CFG_ABIST1_OTP_DIS8S_OTP_MASK8                     ((uint8)0x80U)

/*                            CFG_ASIL_OTP MASKS                          */
#define PMIC_VR55XX_CFG_ASIL_OTP_VMON1_EN_OTP_MASK8              ((uint8)0x01U)
#define PMIC_VR55XX_CFG_ASIL_OTP_VMON2_EN_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_ASIL_OTP_VMON3_EN_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_ASIL_OTP_VMON4_EN_OTP_MASK8              ((uint8)0x08U)
#define PMIC_VR55XX_CFG_ASIL_OTP_HVLDO_VMON_EN_OTP_MASK8         ((uint8)0x20U)

/*                            CFG_I2C_OTP MASKS                          */
#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_MASK8              ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_SHIFT8             ((uint8)0U)
#define PMIC_VR55XX_CFG_I2C_OTP_WDI_POL_OTP_MASK8               ((uint8)0x20U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_VMON_EN_OTP_MASK8         ((uint8)0x40U)

/*                            CFG_1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_1_OTP_VDDIO_V_OTP_MASK8              ((uint8)0x04U)
#define PMIC_VR55XX_CFG_1_OTP_FCCU_OR_WDI_OTP_MASK8          ((uint8)0x08U)
#define PMIC_VR55XX_CFG_1_OTP_HVLDO_MODE_OTP_MASK8           ((uint8)0x20U)

#define PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_MASK8              ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_SHIFT8             ((uint8)6U)

/*                            CFG_2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_2_OTP_RSTB_DELAY_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_2_OTP_STBY_EN_OTP_MASK8                 ((uint8)0x04U)
#define PMIC_VR55XX_CFG_2_OTP_STBY_POLARITY_OTP_MASK8           ((uint8)0x08U)
#define PMIC_VR55XX_CFG_2_OTP_STBY_SAFE_DIS_OTP_MASK8           ((uint8)0x10U)
#define PMIC_VR55XX_CFG_2_OTP_STBY_WINDOW_EN_OTP_MASK8          ((uint8)0x20U)

#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_MASK8         ((uint8)0xC0U)
#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_SHIFT8        ((uint8)6U)

/*                            CFG_DEGLITCH1_OTP MASKS                          */
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_MCU_OTP_MASK8              ((uint8)0x01U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_MASK8              ((uint8)0x06U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_SHIFT8             ((uint8)1U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_VDDIO_OTP_MASK8            ((uint8)0x08U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_MASK8            ((uint8)0x30U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_SHIFT8           ((uint8)4U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_HVLDO_OTP_MASK8            ((uint8)0x40U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_OV_VMON1_OTP_MASK8            ((uint8)0x80U)

/*                            CFG_DEGLITCH2_OTP MASKS                          */
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_MASK8            ((uint8)0x03U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_SHIFT8           ((uint8)0U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_MASK8            ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_SHIFT8           ((uint8)2U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_OV_VMON2_OTP_MASK8            ((uint8)0x10U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_MASK8            ((uint8)0x60U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_SHIFT8           ((uint8)5U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_OV_VMON3_OTP_MASK8            ((uint8)0x80U)

/*                            CFG_DEGLITCH3_OTP MASKS                          */
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_MASK8            ((uint8)0x03U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_SHIFT8           ((uint8)0U)

#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_OV_VMON4_OTP_MASK8            ((uint8)0x04U)

#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_MASK8            ((uint8)0x18U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_SHIFT8           ((uint8)3U)

/*                            CFG_LBIST_BYP_OTP MASKS                          */
#define PMIC_VR55XX_CFG_LBIST_BYP_OTP_UV_LBIST_DIS_OTP_MASK8        ((uint8)0xFFU)

/*                            CFG_ASIL_LEVEL_OTP MASKS                          */
#define PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FCCU_EN_OTP_MASK8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_DIS_OTP_MASK8              ((uint8)0x02U)
#define PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_SELECTION_OTP_MASK8        ((uint8)0x04U)
#define PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_FLT_RECOVERY_EN_OTP_MASK8     ((uint8)0x08U)
/**********************************************************************************/
/*                              MAIN REGISTER MASKS                               */
/**********************************************************************************/
/*                                  M_FLAG MASKS                                  */
#define PMIC_VR55XX_M_FLAG_TSD_BIST_ERR_G_MASK16                     ((uint16)0x0001U)
#define PMIC_VR55XX_M_FLAG_VSUP_G_MASK16                             ((uint16)0x0002U)
#define PMIC_VR55XX_M_FLAG_STBY_TIMER_G_MASK16                       ((uint16)0x0004U)
#define PMIC_VR55XX_M_FLAG_HVLDO_G_MASK16                            ((uint16)0x0008U)
#define PMIC_VR55XX_M_FLAG_LDO3_G_MASK16                             ((uint16)0x0010U)
#define PMIC_VR55XX_M_FLAG_LDO2_G_MASK16                             ((uint16)0x0020U)
#define PMIC_VR55XX_M_FLAG_LDO1_G_MASK16                             ((uint16)0x0040U)
#define PMIC_VR55XX_M_FLAG_BUCK3_G_MASK16                            ((uint16)0x0080U)
#define PMIC_VR55XX_M_FLAG_BUCK2_G_MASK16                            ((uint16)0x0100U)
#define PMIC_VR55XX_M_FLAG_BUCK1_G_MASK16                            ((uint16)0x0200U)
#define PMIC_VR55XX_M_FLAG_BOOST_G_MASK16                            ((uint16)0x0400U)
#define PMIC_VR55XX_M_FLAG_VPRE_G_MASK16                             ((uint16)0x0800U)
#define PMIC_VR55XX_M_FLAG_PWRON_G_MASK16                            ((uint16)0x1000U)
#define PMIC_VR55XX_M_FLAG_COM_ERR_MASK16                            ((uint16)0x2000U)
#define PMIC_VR55XX_M_FLAG_VBOS_G_MASK16                             ((uint16)0x4000U)
#define PMIC_VR55XX_M_FLAG_DIE_CENTER_TEMPFLG_G_MASK16               ((uint16)0x8000U)

/*                                  M_MODE MASKS                                  */
#define PMIC_VR55XX_M_MODE_STBY_PGOOD_TEST_EN_MASK16                 ((uint16)0x0001U)
#define PMIC_VR55XX_M_MODE_PWRON1DIS_MASK16                          ((uint16)0x0002U)
#define PMIC_VR55XX_M_MODE_PWRON2DIS_MASK16                          ((uint16)0x0004U)
#define PMIC_VR55XX_M_MODE_STBY_PGOOD_TEST_LVL_MASK16                ((uint16)0x0008U)
#define PMIC_VR55XX_M_MODE_PWRON2_DSM_EN_MASK16                      ((uint16)0x0010U)
#define PMIC_VR55XX_M_MODE_MAIN_NORMAL_MASK16                        ((uint16)0x0020U)
#define PMIC_VR55XX_M_MODE_EXT_FIN_DIS_MASK16                        ((uint16)0x0040U)
#define PMIC_VR55XX_M_MODE_PLL_LOCKED_MASK16                         ((uint16)0x0080U)

/*                                   M_SM_CTRL1                                   */
#define PMIC_VR55XX_M_SM_CTRL1_GOTO_OFF_MASK16                     ((uint16)0x0001U)
#define PMIC_VR55XX_M_SM_CTRL1_STBY_TIMER_EN_MASK16                ((uint16)0x0400U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_MASK16            ((uint16)0xF000U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_SHIFT16           ((uint16)12U)

/*                                  M_REG_CTRL1                                   */
#define PMIC_VR55XX_M_REG_CTRL1_LDO3EN_MASK16                      ((uint16)0x0001U)
#define PMIC_VR55XX_M_REG_CTRL1_LDO2EN_MASK16                      ((uint16)0x0002U)
#define PMIC_VR55XX_M_REG_CTRL1_LDO1EN_MASK16                      ((uint16)0x0004U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK3EN_MASK16                     ((uint16)0x0008U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK2EN_MASK16                     ((uint16)0x0010U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK1EN_MASK16                     ((uint16)0x0020U)
#define PMIC_VR55XX_M_REG_CTRL1_BOOSTEN_MASK16                     ((uint16)0x0040U)
#define PMIC_VR55XX_M_REG_CTRL1_VPREEN_MASK16                      ((uint16)0x0080U)
#define PMIC_VR55XX_M_REG_CTRL1_LDO3DIS_MASK16                     ((uint16)0x0100U)
#define PMIC_VR55XX_M_REG_CTRL1_LDO2DIS_MASK16                     ((uint16)0x0200U)
#define PMIC_VR55XX_M_REG_CTRL1_LDO1DIS_MASK16                     ((uint16)0x0400U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK3DIS_MASK16                    ((uint16)0x0800U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK2DIS_MASK16                    ((uint16)0x1000U)
#define PMIC_VR55XX_M_REG_CTRL1_BUCK1DIS_MASK16                    ((uint16)0x2000U)
#define PMIC_VR55XX_M_REG_CTRL1_BOOSTDIS_MASK16                    ((uint16)0x4000U)
#define PMIC_VR55XX_M_REG_CTRL1_VPREDIS_MASK16                     ((uint16)0x8000U)

/*                                  M_REG_CTRL2                                   */
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MASK16                    ((uint16)0x0003U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_SHIFT16                   ((uint16)0U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_MASK16                    ((uint16)0x000CU)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_SHIFT16                   ((uint16)2U)

#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_MASK16                      ((uint16)0x0030U)
#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_SHIFT16                     ((uint16)4U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRE_PLDWN_DIS_MASK16              ((uint16)0x0040U)
#define PMIC_VR55XX_M_REG_CTRL2_HVLDOEN_MASK16                     ((uint16)0x0080U)
#define PMIC_VR55XX_M_REG_CTRL2_HVLDODIS_MASK16                    ((uint16)0x0100U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_MASK16                ((uint16)0x3000U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_SHIFT16               ((uint16)12U)

/*                                  M_REG_CTRL3                                   */
#define PMIC_VR55XX_M_REG_CTRL3_BUCK1_STBY_MASK16                  ((uint16)0x0001U)
#define PMIC_VR55XX_M_REG_CTRL3_BUCK2_STBY_MASK16                  ((uint16)0x0004U)
#define PMIC_VR55XX_M_REG_CTRL3_BUCK3_STBY_MASK16                  ((uint16)0x0010U)
#define PMIC_VR55XX_M_REG_CTRL3_VPREV_STBY_MASK16                  ((uint16)0x0040U)
#define PMIC_VR55XX_M_REG_CTRL3_HVLDO_STBY_MASK16                  ((uint16)0x0100U)
#define PMIC_VR55XX_M_REG_CTRL3_LDO1_STBY_MASK16                   ((uint16)0x0400U)
#define PMIC_VR55XX_M_REG_CTRL3_LDO2_STBY_MASK16                   ((uint16)0x1000U)
#define PMIC_VR55XX_M_REG_CTRL3_LDO3_STBY_MASK16                   ((uint16)0x4000U)

/*                                   M_TSD_CFG                                    */
#define PMIC_VR55XX_M_TSD_CFG_HVLDO_TSDCFG_MASK16                  ((uint16)0x0001U)
#define PMIC_VR55XX_M_TSD_CFG_LDO3_TSDCFG_MASK16                   ((uint16)0x0002U)
#define PMIC_VR55XX_M_TSD_CFG_LDO2_TSDCFG_MASK16                   ((uint16)0x0004U)
#define PMIC_VR55XX_M_TSD_CFG_LDO1_TSDCFG_MASK16                   ((uint16)0x0008U)
#define PMIC_VR55XX_M_TSD_CFG_BUCK3_TSDCFG_MASK16                  ((uint16)0x0010U)
#define PMIC_VR55XX_M_TSD_CFG_BUCK2_TSDCFG_MASK16                  ((uint16)0x0020U)
#define PMIC_VR55XX_M_TSD_CFG_BUCK1_TSDCFG_MASK16                  ((uint16)0x0040U)
#define PMIC_VR55XX_M_TSD_CFG_BOOST_TSDCFG_MASK16                  ((uint16)0x0080U)

#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_MASK16               ((uint16)0x0700U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_SHIFT16              ((uint16)8U)

/*                                     M_AMUX                                     */
#define PMIC_VR55XX_M_AMUX_AMUX_MASK16                             ((uint16)0x001FU)
#define PMIC_VR55XX_M_AMUX_AMUX_SHIFT16                            ((uint16)0U)

#define PMIC_VR55XX_M_AMUX_RATIO_MASK16                            ((uint16)0x0020U)

/*                                    M_CLOCK1                                    */
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16                   ((uint16)0x000FU)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_SHIFT16                  ((uint16)0U)

#define PMIC_VR55XX_M_CLOCK1_MOD_EN_MASK16                         ((uint16)0x0010U)
#define PMIC_VR55XX_M_CLOCK1_FIN_DIV_MASK16                        ((uint16)0x0020U)
#define PMIC_VR55XX_M_CLOCK1_EXT_FIN_SEL_MASK16                    ((uint16)0x0040U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_SEL_MASK16                       ((uint16)0x0080U)

#define PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_MASK16                     ((uint16)0x0700U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_SHIFT16                    ((uint16)8U)

#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_MASK16                   ((uint16)0x7800U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_SHIFT16                  ((uint16)11U)

#define PMIC_VR55XX_M_CLOCK1_MOD_CONF_MASK16                       ((uint16)0x8000U)

/*                                    M_CLOCK2                                    */
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_MASK16                  ((uint16)0x0003U)
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_SHIFT16                 ((uint16)0U)

/*                                  M_INT_MASK1                                   */
#define PMIC_VR55XX_M_INT_MASK1_LDO3_TSDFLG_M_MASK16               ((uint16)0x0001U)
#define PMIC_VR55XX_M_INT_MASK1_LDO2_TSDFLG_M_MASK16               ((uint16)0x0002U)
#define PMIC_VR55XX_M_INT_MASK1_LDO1_TSDFLG_M_MASK16               ((uint16)0x0004U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK3_TSDFLG_M_MASK16              ((uint16)0x0008U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK2_TSDFLG_M_MASK16              ((uint16)0x0010U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK1_TSDFLG_M_MASK16              ((uint16)0x0020U)
#define PMIC_VR55XX_M_INT_MASK1_BOOST_TSDFLG_M_MASK16              ((uint16)0x0040U)
#define PMIC_VR55XX_M_INT_MASK1_HVLDO_TSDFLG_M_MASK16              ((uint16)0x0080U)
#define PMIC_VR55XX_M_INT_MASK1_LDO3OC_M_MASK16                    ((uint16)0x0100U)
#define PMIC_VR55XX_M_INT_MASK1_LDO2OC_M_MASK16                    ((uint16)0x0200U)
#define PMIC_VR55XX_M_INT_MASK1_LDO1OC_M_MASK16                    ((uint16)0x0400U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK3OC_M_MASK16                   ((uint16)0x0800U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK2OC_M_MASK16                   ((uint16)0x1000U)
#define PMIC_VR55XX_M_INT_MASK1_BUCK1OC_M_MASK16                   ((uint16)0x2000U)

#define PMIC_VR55XX_M_INT_MASK1_HVLDOOC_M_MASK16                   ((uint16)0x8000U)

/*                                  M_INT_MASK2                                   */
#define PMIC_VR55XX_M_INT_MASK2_PWRON1FLG_M_MASK16                 ((uint16)0x0001U)
#define PMIC_VR55XX_M_INT_MASK2_PWRON2FLG_M_MASK16                 ((uint16)0x0002U)
#define PMIC_VR55XX_M_INT_MASK2_VSUPUVH_M_MASK16                   ((uint16)0x0004U)
#define PMIC_VR55XX_M_INT_MASK2_VSUPUVL_M_MASK16                   ((uint16)0x0008U)
#define PMIC_VR55XX_M_INT_MASK2_VSUPUV7_M_MASK16                   ((uint16)0x0010U)
#define PMIC_VR55XX_M_INT_MASK2_VPREUVH_M_MASK16                   ((uint16)0x0020U)
#define PMIC_VR55XX_M_INT_MASK2_VPREUVL_M_MASK16                   ((uint16)0x0040U)
#define PMIC_VR55XX_M_INT_MASK2_VPREOC_M_MASK16                    ((uint16)0x0080U)
#define PMIC_VR55XX_M_INT_MASK2_VPREOV2_M_MASK16                   ((uint16)0x0100U)
#define PMIC_VR55XX_M_INT_MASK2_HVLDO_INPUT_UVL_M_MASK16           ((uint16)0x0200U)
#define PMIC_VR55XX_M_INT_MASK2_TSD_BIST_ERR_FLG_M_MASK16          ((uint16)0x0400U)
#define PMIC_VR55XX_M_INT_MASK2_VBOOSTOV_M_MASK16                  ((uint16)0x0800U)
#define PMIC_VR55XX_M_INT_MASK2_VBOOSTUVH_M_MASK16                 ((uint16)0x1000U)
#define PMIC_VR55XX_M_INT_MASK2_VBOSUVH_M_MASK16                   ((uint16)0x2000U)
#define PMIC_VR55XX_M_INT_MASK2_COM_ERR_M_MASK16                   ((uint16)0x4000U)
#define PMIC_VR55XX_M_INT_MASK2_DIE_CENTER_TEMPFLG_M_MASK16        ((uint16)0x8000U)

/*                                  M_FLAG1                                       */
#define PMIC_VR55XX_M_FLAG1_RWBITS_MASK16                          ((uint16)0xBFFFU)

/*                                  M_FLAG2                                       */
#define PMIC_VR55XX_M_FLAG2_RWBITS_MASK16                          ((uint16)0xFFFFU)

/*                                  M_FLAG3                                       */
#define PMIC_VR55XX_M_FLAG3_RWBITS_MASK16                          ((uint16)0xFFCFU)

/*                                  M_LVB1_STBY_DVS                               */
#define PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_MASK16              ((uint16)0xFFFFU)
#define PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_SHIFT16             ((uint16)0x0U)

/*                                  M_VMON_REGx                                   */
#define PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_MASK16            ((uint16)0x0007U)
#define PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_SHIFT16           ((uint16)0U)

#define PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_MASK16            ((uint16)0x0038U)
#define PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_SHIFT16           ((uint16)3U)

#define PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_MASK16            ((uint16)0x01C0U)
#define PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_SHIFT16           ((uint16)6U)

#define PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_MASK16            ((uint16)0x0E00U)
#define PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_SHIFT16           ((uint16)9U)

/*                                   M_DEVICEID                                   */
#define PMIC_VR55XX_M_DEVICEID_DEV_ID_MASK16                       ((uint16)0x000FU)
#define PMIC_VR55XX_M_DEVICEID_DEV_ID_SHIFT16                      ((uint16)0U)

#define PMIC_VR55XX_M_DEVICEID_FAM_ID_MASK16                       ((uint16)0x00F0U)
#define PMIC_VR55XX_M_DEVICEID_FAM_ID_SHIFT16                      ((uint16)4U)

#define PMIC_VR55XX_M_DEVICEID_MMREV_MASK16                        ((uint16)0x0700U)
#define PMIC_VR55XX_M_DEVICEID_MMREV_SHIFT16                       ((uint16)8U)

#define PMIC_VR55XX_M_DEVICEID_FMREV_MASK16                        ((uint16)0x7000U)
#define PMIC_VR55XX_M_DEVICEID_FMREV_SHIFT16                       ((uint16)12U)

/*                                   M_TM_STATUS1                                   */
#define PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16                ((uint16)0x0040U)

/*                                   M_MIRRORCMD                                   */
#define PMIC_VR55XX_M_MIRRORCMD_WRITE_MASK16              ((uint16)0x0100U)

/*                                   M_OTPSTATUS0                                   */
#define PMIC_VR55XX_M_OTPSTATUS0_BOOT_ERROR_MASK16              ((uint16)0x1000U)

/**********************************************************************************/
/*                            FAIL-SAFE REGISTER MASKS                            */
/**********************************************************************************/

/*                            FS_GRL_FLAGS                                         */
#define PMIC_VR55XX_FS_GRL_FLAGS_WD_G_MASK16                                    ((uint16)0x4000U)
/*                            FS_I_OVUV_SAFE_REACTION1                            */
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_FS_IMPACT_MASK16          ((uint16)0x0003U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_FS_IMPACT_SHIFT16         ((uint16)0U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_FS_IMPACT_MASK16          ((uint16)0x000CU)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_FS_IMPACT_SHIFT16         ((uint16)2U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_FS_IMPACT_MASK16     ((uint16)0x0030U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_FS_IMPACT_SHIFT16    ((uint16)4U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_FS_IMPACT_MASK16     ((uint16)0x00C0U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_FS_IMPACT_SHIFT16    ((uint16)6U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_FS_IMPACT_MASK16       ((uint16)0x0300U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_FS_IMPACT_SHIFT16      ((uint16)8U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_FS_IMPACT_MASK16       ((uint16)0x0C00U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_FS_IMPACT_SHIFT16      ((uint16)10U)

/*                            FS_I_OVUV_SAFE_REACTION2                            */
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_FS_IMPACT_MASK16          ((uint16)0x0003U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_FS_IMPACT_SHIFT16         ((uint16)0U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_FS_IMPACT_MASK16          ((uint16)0x000CU)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_FS_IMPACT_SHIFT16         ((uint16)2U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_FS_IMPACT_MASK16          ((uint16)0x0030U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_FS_IMPACT_SHIFT16         ((uint16)4U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_FS_IMPACT_MASK16          ((uint16)0x00C0U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_FS_IMPACT_SHIFT16         ((uint16)6U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_FS_IMPACT_MASK16          ((uint16)0x0300U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_FS_IMPACT_SHIFT16         ((uint16)8U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_FS_IMPACT_MASK16          ((uint16)0x0C00U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_FS_IMPACT_SHIFT16         ((uint16)10U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_FS_IMPACT_MASK16          ((uint16)0x3000U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_FS_IMPACT_SHIFT16         ((uint16)12U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_FS_IMPACT_MASK16          ((uint16)0xC000U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_FS_IMPACT_SHIFT16         ((uint16)14U)

/*                                FS_I_ABIST2_CTRL                                */
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VDDIO_ABIST2_MASK16                        ((uint16)0x0001U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VCORE_ABIST2_MASK16                        ((uint16)0x0002U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_HVLDO_VMON_ABIST2_MASK16                   ((uint16)0x0004U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON1_ABIST2_MASK16                        ((uint16)0x0008U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON2_ABIST2_MASK16                        ((uint16)0x0010U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON3_ABIST2_MASK16                        ((uint16)0x0020U)
#define PMIC_VR55XX_FS_I_ABIST2_CTRL_VMON4_ABIST2_MASK16                        ((uint16)0x0040U)

/*                                  FS_I_WD_CFG                                   */
#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_MASK16                             ((uint16)0xC000U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_SHIFT16                            ((uint16)14U)

#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_MASK16                             ((uint16)0x1800U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_SHIFT16                            ((uint16)11U)

#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_MASK16                             ((uint16)0x0300U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_SHIFT16                            ((uint16)8U)

#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_CNT_MASK16                               ((uint16)0x0070U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_CNT_SHIFT16                              ((uint16)4U)

#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_CNT_MASK16                               ((uint16)0x000FU)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_CNT_SHIFT16                              ((uint16)0U)

/*                                FS_I_SAFE_INPUTS                                */
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_MASK16                  ((uint16)0x000FU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_SHIFT16                 ((uint16)0U)

#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU2_FS_IMPACT_MASK16                     ((uint16)0x0040U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU1_FS_IMPACT_MASK16                     ((uint16)0x0080U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU12_FS_IMPACT_MASK16                    ((uint16)0x0100U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU2_FLT_POL_MASK16                       ((uint16)0x0400U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU1_FLT_POL_MASK16                       ((uint16)0x0800U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU12_FLT_POL_MASK16                      ((uint16)0x1000U)

#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_MASK16                            ((uint16)0xC000U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_SHIFT16                           ((uint16)14U)

/*                                    FS_I_SVS                                    */
#define PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_SIGN_MASK16                             ((uint16)0x0200U)

#define PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_MASK16                                  ((uint16)0xFC00U)
#define PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_SHIFT16                                 ((uint16)10U)

/*                                    FS_I_FSSM                                   */
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_MASK16                                ((uint16)0x000FU)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_SHIFT16                               ((uint16)0U)

#define PMIC_VR55XX_FS_I_FSSM_CLK_DIS8S_MASK16                                  ((uint16)0x0010U)
#define PMIC_VR55XX_FS_I_FSSM_CLK_MON_DIS_MASK16                                ((uint16)0x0020U)
#define PMIC_VR55XX_FS_I_FSSM_LPCLK_MON_DIS_MASK16                              ((uint16)0x0040U)
#define PMIC_VR55XX_FS_I_FSSM_BACKUP_SAFETY_PATH_MASK16                         ((uint16)0x0080U)
#define PMIC_VR55XX_FS_I_FSSM_RSTB_DUR_MASK16                                   ((uint16)0x0200U)

#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_MASK16                             ((uint16)0x1800U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_SHIFT16                            ((uint16)11U)

#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_MASK16                          ((uint16)0xC000U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_SHIFT16                         ((uint16)14U)

/*                                FS_WD_WINDOW_DUR                                */
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_MASK16                        ((uint16)0x000FU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_SHIFT16                       ((uint16)0U)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_MASK16                              ((uint16)0x0700U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_SHIFT16                             ((uint16)8U)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_MASK16                           ((uint16)0xF000U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_SHIFT16                          ((uint16)12U)

/*                                   FS_WD_SEED                                   */
#define PMIC_VR55XX_FS_WD_SEED_WD_SEED_MASK16                                   ((uint16)0xFFFFU)

/*                                  FS_INTB_MASK                                  */
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_FCCU1_MASK16                           ((uint16)0x0001U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_FCCU2_MASK16                           ((uint16)0x0002U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_HVLDO_VMON_OV_UV_MASK16                ((uint16)0x0004U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_BAD_WD_REFRESH_MASK16                  ((uint16)0x0008U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VCOREMON_OV_UV_MASK16                  ((uint16)0x0010U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VDDIO_OV_UV_MASK16                     ((uint16)0x0020U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON1_OV_UV_MASK16                     ((uint16)0x0040U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON2_OV_UV_MASK16                     ((uint16)0x0080U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON3_OV_UV_MASK16                     ((uint16)0x0100U)
#define PMIC_VR55XX_FS_INTB_MASK_INT_INH_VMON4_OV_UV_MASK16                     ((uint16)0x0200U)

/*                                   FS_SAFE_IOS                                   */
#define PMIC_VR55XX_FS_SAFE_IOS_STBY_REQ_MASK16             ((uint16)0x0002U)
#define PMIC_VR55XX_FS_SAFE_IOS_GOTO_INITFS_MASK16          ((uint16)0x0004U)
#define PMIC_VR55XX_FS_SAFE_IOS_FS0B_SNS_MASK16             ((uint16)0x0020U)
#define PMIC_VR55XX_FS_SAFE_IOS_RST_REQ_MASK16              ((uint16)0x0080U)
#define PMIC_VR55XX_FS_SAFE_IOS_W_BITS_MASK16               ((uint16)0xD39EU)
#define PMIC_VR55XX_FS_SAFE_IOS_RSTB_SNS_MASK16             ((uint16)0x0400U)
#define PMIC_VR55XX_FS_SAFE_IOS_PGOOD_SNS_MASK16            ((uint16)0x2000U)

/*                                   FS_OVUVREG_STATUS                                */
#define PMIC_VR55XX_FS_OVUVREG_STATUS_RWBITS_MASK32                     ((uint16)0xFFFFU)

/*                                   FS_DIAG_SAFETY                                   */
#define PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16                    ((uint16)0x0004U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16                    ((uint16)0x0008U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16                ((uint16)0x0010U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16                     ((uint16)0x0200U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_ABIST1_OK_MASK16                     ((uint16)0x0400U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_BAD_WD_TIMING_MASK16                 ((uint16)0x0800U)
#define PMIC_VR55XX_FS_DIAG_SAFETY_BAD_WD_DATA_MASK16                   ((uint16)0x1000U)

#define PMIC_VR55XX_FS_DIAG_SAFETY_RWBITS_MASK32                        ((uint16)0xF9E0U)

/*                                   FS_STATES                                   */
#define PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16                ((uint16)0x001FU)
#define PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16               ((uint16)0x0200U)
#define PMIC_VR55XX_FS_STATES_OTP_CORRUPT_MASK16               ((uint16)0x0800U)
#define PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16                  ((uint16)0x2000U)
#define PMIC_VR55XX_FS_STATES_DBG_EXIT_MASK16                  ((uint16)0x4000U)
#define PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16              ((uint16)0x8000U)

/*                                   FS_TM_STATUS1                                   */

/*                                   FS_MIRRORCMD                                   */
#define PMIC_VR55XX_FS_MIRRORCMD_WRITE_MASK16                 ((uint16)0x0100U)

/*                                   FS_OTPSTATUS0                                   */
#define PMIC_VR55XX_FS_OTPSTATUS0_BOOT_ERROR_MASK16           ((uint16)0x1000U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* REG_ESYS_VR55XX_H */
