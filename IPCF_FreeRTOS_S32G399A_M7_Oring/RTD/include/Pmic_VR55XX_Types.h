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


#ifndef PMIC_VR55XX_TYPES_H
#define PMIC_VR55XX_TYPES_H

/**
*   @file Pmic_VR55XX_Types.h
*
*   @addtogroup PMIC_VR5510 Pmic VR5510 driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Pmic_Cfg.h"
#include "Pmic_VR55XX_RegMap.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define PMIC_VR55XX_TYPES_VENDOR_ID                        43
#define PMIC_VR55XX_TYPES_MODULE_ID                        255
#define PMIC_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define PMIC_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION         4
#define PMIC_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION      0
#define PMIC_VR55XX_TYPES_SW_MAJOR_VERSION                 4
#define PMIC_VR55XX_TYPES_SW_MINOR_VERSION                 0
#define PMIC_VR55XX_TYPES_SW_PATCH_VERSION                 2

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h are of the same vendor */
#if (PMIC_VR55XX_TYPES_VENDOR_ID != PMIC_CFG_VENDOR_ID)
    #error "Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h have different vendor ids"
#endif
/* Check if the files Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h are of the same Autosar version */
#if ((PMIC_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION    != PMIC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION    != PMIC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION != PMIC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h are different"
#endif
/* Check if the files Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h are of the same software version */
#if ((PMIC_VR55XX_TYPES_SW_MAJOR_VERSION != PMIC_CFG_SW_MAJOR_VERSION) || \
     (PMIC_VR55XX_TYPES_SW_MINOR_VERSION != PMIC_CFG_SW_MINOR_VERSION) || \
     (PMIC_VR55XX_TYPES_SW_PATCH_VERSION != PMIC_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_VR55XX_Types.h and CDD_Pmic_Cfg.h are different"
#endif

/* Check if current file and Reg_eSys_VR55XX header file are of the same vendor */
#if (PMIC_VR55XX_TYPES_VENDOR_ID != REG_ESYS_VR55XX_VENDOR_ID)
    #error "Pmic_VR55XX_Types.h and Reg_eSys_VR55XX.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_VR55XX header file are of the same Autosar version */
#if ((PMIC_VR55XX_TYPES_AR_RELEASE_MAJOR_VERSION    != REG_ESYS_VR55XX_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_VR55XX_TYPES_AR_RELEASE_MINOR_VERSION    != REG_ESYS_VR55XX_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_VR55XX_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_VR55XX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_VR55XX_Types.h and Reg_eSys_VR55XX.h are different"
#endif
/* Check if current file and Reg_eSys_VR55XX header file are of the same Software version */
#if ((PMIC_VR55XX_TYPES_SW_MAJOR_VERSION != REG_ESYS_VR55XX_SW_MAJOR_VERSION) || \
     (PMIC_VR55XX_TYPES_SW_MINOR_VERSION != REG_ESYS_VR55XX_SW_MINOR_VERSION) || \
     (PMIC_VR55XX_TYPES_SW_PATCH_VERSION != REG_ESYS_VR55XX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_VR55XX_Types.h and Reg_eSys_VR55XX.h are different"
#endif

/*==================================================================================================
                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
typedef struct
{
   uint8 u8RegisterAddr;   /* register address, added by hand in the code template */
   uint8 u8RegisterData;   /* generated value, as it's already defined */

} Pmic_VR55XX_Otp_RegisterConfigType;

typedef struct
{
    uint8  u8NoOfOtpMainRegister;
    const Pmic_VR55XX_Otp_RegisterConfigType (*paOtpMainConfig)[];

    uint8  u8NoOfOtpFailSafeRegister;
    const Pmic_VR55XX_Otp_RegisterConfigType (*paOtpFailSafeConfig)[];

} Pmic_VR55XX_OtpConfigType;

typedef struct
{
    uint16 u16FailSafeSvsReg;
    uint16 u16FailSafeReactionReg1;
    uint16 u16FailSafeReactionReg2;
    uint16 u16FailSafeWatchdogConfigReg;
    uint16 u16FailSafeWatchdogDurationReg;
    uint16 u16FailSafeWatchdogSeedReg;
    uint16 u16FailSafeAbist2Reg;
    uint16 u16FailSafeInputsReg;
    uint16 u16FailSafeStateMachineReg;

} Pmic_VR55XX_InitConfigType;

typedef struct
{
    const Pmic_VR55XX_OtpConfigType *  pDeviceOtpConfig;
    const Pmic_VR55XX_InitConfigType * pDeviceInitConfig;

} Pmic_VR55XX_ConfigType;


/**
* @brief   Power Modes Encoding for VR55XX
*/
typedef enum
{
    PMIC_NORMAL_MODE    = 0x1U,     /**< @brief Normal Mode.     */
    PMIC_RESET_MODE     = 0x2U,     /**< @brief Reset Mode.      */
    PMIC_SHUTDOWN_MODE  = 0x3U,     /**< @brief Shutdown Mode.   */
    PMIC_STANDBY_MODE   = 0x4U,     /**< @brief Standby Mode.    */
    PMIC_DEEPSLEEP_MODE = 0x5U      /**< @brief Deep Sleep Mode. */

} Pmic_VR55XX_PowerModeType;

/**
* @brief   The structure contains the mode configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8ModeConfigId;
    Pmic_VR55XX_PowerModeType ePowerMode;
    uint16 u16MainModeReg;
    uint16 u16MainStateMachineReg;
    uint16 u16MainControlReg1;
    uint16 u16MainControlReg2;
    uint16 u16MainControlReg3;
    uint16 u16MainVmonReg;
    uint16 u16MainLvb1StbyDsvReg;

} Pmic_VR55XX_ModeConfigType;


/**
* @brief   The structure contains the clock configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8ClockConfigId;
    boolean bExternalFinIsEnable;
    uint16 u16MainClockReg1;
    uint16 u16MainClockReg2;

} Pmic_VR55XX_ClockConfigType;


/**
* @brief   The structure contains the reaction configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8ReactionConfigId;

    uint16 u16MainInterruptMaskReg1;
    uint16 u16MainInterruptMaskReg2;
    uint16 u16MainThermalShutdownReg;

    uint16 u16FailSafeInterruptMaskReg;

} Pmic_VR55XX_ReactionConfigType;


#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/**
* @brief   The structure contains the AMUX channel configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8AmuxChannelId;
    uint16 u16MainAmuxReg;

} Pmic_VR55XX_AmuxChannelConfigType;
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/**
* @brief   The structure contains the SVS setting configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8SvsConfigId;
    uint16 u16FailsafeSvsReg;
} Pmic_VR55XX_SVSConfigType;
#endif

#if (STD_ON == PMIC_WATCHDOG_API)
/**
* @brief   The structure contains the watchdog configuration type for VR55XX.
*/
typedef struct
{
    uint8 u8WatchdogConfigId;
    uint16 u16WatchdogWindowReg;

} Pmic_VR55XX_WatchdogConfigType;
#endif

#if (STD_ON == PMIC_DEVICE_INFO_API)
/**
* @brief   The structure contains the device information type for VR55XX.
*/
typedef struct
{
    uint8 u8FamilyId;
    uint8 u8DeviceId;
    uint8 u8MetalMaskRev;
    uint8 u8FullMaskRev;
} Pmic_VR55XX_DeviceInfoType;
#endif

/**
* @brief   The structure contains the raw fault events statuses for VR55XX.
*/
typedef struct
{
    boolean bSkipGeneralFlagsReg;
    boolean bSkipFlags1Reg;
    boolean bSkipFlags2Reg;
    boolean bSkipFlags3Reg;
    boolean bSkipGlobalFlagsReg;
    boolean bSkipVoltageStatusReg;
    boolean bSkipSafeInputStatusReg;
    boolean bSkipDiagnosticSafetyReg;
    boolean bSkipFaultErrorCounter;

    uint16 u16GeneralFlagsReg;
    uint16 u16Flags1Reg;
    uint16 u16Flags2Reg;
    uint16 u16Flags3Reg;
    uint16 u16GlobalFlagsReg;
    uint16 u16VoltageStatusReg;
    uint16 u16SafeInputsStatusReg;
    uint16 u16DiagnosticSafetyReg;
    uint8 u8FaultErrorCounter;

} Pmic_VR55XX_RawFaultType;

/**********************************************************************************/
/*                                  OTP-MAIN REGISTER                             */
/**********************************************************************************/
/***********************************************************/
/*                         GENERIC                         */
/***********************************************************/
#define PMIC_VR55XX_M_GET_OTP_REG_INDEX_U8(u8MainOtpAddr)                ((uint8)((uint8)(u8MainOtpAddr)     - (uint8)0x18U))
#define PMIC_VR55XX_FS_GET_OTP_REG_INDEX_U8(u8FailSafeOtpAddr)           ((uint8)((uint8)(u8FailSafeOtpAddr) - (uint8)0x0BU))

/***********************************************************/
/*                    CFG_VPRE_1_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_3_3_V_SELECT_U8                ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_3_4_V_SELECT_U8                ((uint8)0x10U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_3_5_V_SELECT_U8                ((uint8)0x11U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_3_7_V_SELECT_U8                ((uint8)0x13U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_4_0_V_SELECT_U8                ((uint8)0x16U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_4_5_V_SELECT_U8                ((uint8)0x1BU)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_5_0_V_SELECT_U8                ((uint8)0x20U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_5_1_V_SELECT_U8                ((uint8)0x21U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_5_2_V_SELECT_U8                ((uint8)0x22U)
#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_5_3_V_SELECT_U8                ((uint8)0x23U)

#define PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_U8(value)                      ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_1_OTP_VPREV_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_VPRE_2_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_60_SELECT_U8                  ((uint8)0x06U)
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_70_SELECT_U8                  ((uint8)0x07U)
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_140_SELECT_U8                 ((uint8)0x0EU)
#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_200_SELECT_U8                 ((uint8)0x11U)

#define PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_U8(value)                     ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_2_OTP_VPRESC_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_VPRE_3_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_130_MA_SELECT_U8            ((uint8)0x00U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_260_MA_SELECT_U8            ((uint8)0x01U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_520_MA_SELECT_U8            ((uint8)0x02U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_900_MA_SELECT_U8            ((uint8)0x03U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_130_MA_SELECT_U8            ((uint8)0x00U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_260_MA_SELECT_U8            ((uint8)0x01U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_520_MA_SELECT_U8            ((uint8)0x02U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_900_MA_SELECT_U8            ((uint8)0x03U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_80NS_SELECT_U8             ((uint8)0x00U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_60NS_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_40NS_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_20NS_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_50_MV_SELECT_U8             ((uint8)0x00U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_80_MV_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_120_MV_SELECT_U8            ((uint8)0x02U)
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_150_MV_SELECT_U8            ((uint8)0x03U)

#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRHS_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_3_OTP_VPRESRLS_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_3_OTP_VPRETOFF_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_VPRE_3_OTP_VPREILIM_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BOOST_1_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_4_50_V_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_00_V_SELECT_U8              ((uint8)0x06U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_09_V_SELECT_U8              ((uint8)0x07U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_19_V_SELECT_U8              ((uint8)0x08U)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_40_V_SELECT_U8              ((uint8)0x0AU)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_5_74_V_SELECT_U8              ((uint8)0x0DU)
#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_6_00_V_SELECT_U8              ((uint8)0x0FU)

#define PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_U8(value)                     ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_1_OTP_VBSTV_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BOOST_2_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_160_SELECT_U8                ((uint8)0x06U)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_125_SELECT_U8                ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_79_SELECT_U8                 ((uint8)0x0EU)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_67_SELECT_U8                 ((uint8)0x0FU)

#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_60NS_SELECT_U8         ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_50NS_SELECT_U8         ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_70NS_SELECT_U8         ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_80NS_SELECT_U8         ((uint8)0x03U)

#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_U8(value)                    ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTSC_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_U8(value)               ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_2_OTP_VBSTTONTIME_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BOOST_3_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_100_SELECT_U8                ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_300_SELECT_U8                ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_500_SELECT_U8                ((uint8)0x03U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_2_A_SELECT_U8           ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_3_A_SELECT_U8           ((uint8)0x02U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_125_PF_SELECT_U8          ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_75_PF_SELECT_U8           ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_175_PF_SELECT_U8          ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_225_PF_SELECT_U8          ((uint8)0x03U)

#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_750_KOHM_SELECT_U8        ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_500_KOHM_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_1000_KOHM_SELECT_U8            ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_250_KOHM_SELECT_U8             ((uint8)0x03U)


#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_U8(value)                    ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTSR_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_U8(value)                  ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTILIM_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_U8(value)                 ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTCCOMP_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_U8(value)                 ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BOOST_3_OTP_VBSTRCOMP_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK1_1_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_V_OTP_1_8_V_SELECT_U8           ((uint8)0xB1U)

#define PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_U8(value)                    ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK1_1_OTP_BUCK1V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK1_2_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_2_4_A_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_ILIM_OTP_3_6_A_SELECT_U8             ((uint8)0x03U)
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_1_0_UH_SELECT_U8        ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_0_47_UH_SELECT_U8        ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BUCK_X_X_OTP_BUCK_X_LSELECT_OTP_1_5_UH_SELECT_U8        ((uint8)0x02U)


#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_ILIM_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_U8(value)         ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK1_2_OTP_BUCK1_LSELECT_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK2_1_OTP                      */
/***********************************************************/

#define PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK2_1_OTP_BUCK2V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK2_2_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_ILIM_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_U8(value)         ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK2_2_OTP_BUCK2_LSELECT_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK3_1_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_0_V_SELECT_U8                    ((uint8)0x00U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_1_V_SELECT_U8                    ((uint8)0x01U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_2_V_SELECT_U8                    ((uint8)0x02U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_25_V_SELECT_U8                   ((uint8)0x03U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_3_V_SELECT_U8                    ((uint8)0x04U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_35_V_SELECT_U8                   ((uint8)0x05U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_5_V_SELECT_U8                    ((uint8)0x06U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_6_V_SELECT_U8                    ((uint8)0x07U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_8_V_SELECT_U8                    ((uint8)0x08U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_1_85_V_SELECT_U8                   ((uint8)0x09U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_0_V_SELECT_U8                    ((uint8)0x0AU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_1_V_SELECT_U8                    ((uint8)0x0BU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_15_V_SELECT_U8                   ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_25_V_SELECT_U8                   ((uint8)0x0DU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_3_V_SELECT_U8                    ((uint8)0x0EU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_4_V_SELECT_U8                    ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_5_V_SELECT_U8                    ((uint8)0x10U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_2_8_V_SELECT_U8                    ((uint8)0x11U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_15_V_SELECT_U8                   ((uint8)0x12U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_2_V_SELECT_U8                    ((uint8)0x13U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_25_V_SELECT_U8                   ((uint8)0x14U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_3_V_SELECT_U8                    ((uint8)0x15U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_35_V_SELECT_U8                   ((uint8)0x16U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_4_V_SELECT_U8                    ((uint8)0x17U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_5_V_SELECT_U8                    ((uint8)0x18U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_3_8_V_SELECT_U8                    ((uint8)0x19U)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_4_0_V_SELECT_U8                    ((uint8)0x1AU)
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_4_1_V_SELECT_U8                    ((uint8)0x1BU)

#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_U8(value)                ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3V_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_U8(value)         ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK3_1_OTP_BUCK3_LSELECT_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_BUCK3_2_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK3_ILIM_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK1_COMP_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_BUCK3_2_OTP_BUCK2_COMP_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_LDO_ALL1_OTP                     */
/***********************************************************/
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_5_V_SELECT_U8                    ((uint8)0x00U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_6_V_SELECT_U8                    ((uint8)0x01U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_8_V_SELECT_U8                    ((uint8)0x02U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_1_85_V_SELECT_U8                   ((uint8)0x03U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_2_15_V_SELECT_U8                   ((uint8)0x04U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_2_5_V_SELECT_U8                    ((uint8)0x05U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_2_8_V_SELECT_U8                    ((uint8)0x06U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_0_V_SELECT_U8                    ((uint8)0x07U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_1_V_SELECT_U8                    ((uint8)0x08U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_15_V_SELECT_U8                   ((uint8)0x09U)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_2_V_SELECT_U8                    ((uint8)0x0AU)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_3_V_SELECT_U8                    ((uint8)0x0BU)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_3_35_V_SELECT_U8                   ((uint8)0x0CU)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_4_0_V_SELECT_U8                    ((uint8)0x0DU)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_4_9_V_SELECT_U8                    ((uint8)0x0EU)
#define PMIC_VR55XX_CFG_LDO_ALL_X_OTP_LDO_X_V_OTP_5_0_V_SELECT_U8                    ((uint8)0x0FU)

#define PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_LDO_ALL1_OTP_LDO3V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_LDO_ALL2_OTP                     */
/***********************************************************/
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_1_1_V_SELECT_U8                    ((uint8)0x00U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_1_2_V_SELECT_U8                    ((uint8)0x01U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_1_6_V_SELECT_U8                    ((uint8)0x02U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_1_8_V_SELECT_U8                    ((uint8)0x03U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_2_5_V_SELECT_U8                    ((uint8)0x04U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_2_8_V_SELECT_U8                    ((uint8)0x05U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_3_3_V_SELECT_U8                    ((uint8)0x06U)
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_5_0_V_SELECT_U8                    ((uint8)0x07U)

#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO1V_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_LDO_ALL2_OTP_LDO2V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SEQ_1_OTP                        */
/***********************************************************/
#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_U8(value)              ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK2S_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_U8(value)              ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_1_OTP_BUCK3S_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SEQ_2_OTP                        */
/***********************************************************/
#define PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_0_8_V_SELECT_U8                    ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_3_3_V_SELECT_U8                    ((uint8)0x01U)

#define PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_U8(value)              ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_2_OTP_LDO3S_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_2_OTP_BUCK1S_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_2_OTP_HVLDOV_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SEQ_3_OTP                        */
/***********************************************************/
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_250US_SELECT_U8           ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_500US_SELECT_U8           ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_1000US_SELECT_U8          ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_2000US_SELECT_U8          ((uint8)0x03U)

#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_3_OTP_LDO1S_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_3_OTP_LDO2S_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_U8(value)        ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_3_OTP_SLOT_WIDTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SEQ_4_OTP                        */
/***********************************************************/
#define PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_4_OTP_BOOSTS_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SEQ_4_OTP_HVLDOS_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_CLOCK_1_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_8_SELECT_U8            ((uint8)0x00U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_10_SELECT_U8           ((uint8)0x01U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_44_SELECT_U8           ((uint8)0x04U)

#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_120NS_SELECT_U8           ((uint8)0x00U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_210NS_SELECT_U8           ((uint8)0x01U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_300NS_SELECT_U8           ((uint8)0x02U)
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_560NS_SELECT_U8           ((uint8)0x03U)

#define PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_1_OTP_CLK_DIV2_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_U8(value)        ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_1_OTP_VPRE_PFM_TON_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_CLOCK_2_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_U8(value)             ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_2_OTP_VBST_PH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_2_OTP_BUCK1_PH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_CLOCK_3_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK2_PH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_3_OTP_BUCK3_PH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_CLOCK_4_OTP                      */
/***********************************************************/
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_9_SELECT_U8           ((uint8)0x02U)
#define PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_8_SELECT_U8           ((uint8)0x01U)

#define PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_CLOCK_4_OTP_CLK_DIV1_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SM_2_OTP                         */
/***********************************************************/
#define PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SM_2_OTP_DIE_CENTER_TEMP_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_I2C_OTP                          */
/***********************************************************/
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_EXTERNAL_REGULATOR_SELECT_U8       ((uint8)0x00U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_VPRE_SELECT_U8                     ((uint8)0x01U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_LDO1_SELECT_U8                     ((uint8)0x02U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_LDO2_SELECT_U8                     ((uint8)0x03U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_BUCK2_SELECT_U8                    ((uint8)0x04U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_BUCK3_SELECT_U8                    ((uint8)0x05U)
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_LDO3_SELECT_U8                     ((uint8)0x06U)

#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_I2C_OTP_I2CDEVADDR_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_U8(value)      ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_I2C_OTP_VDDIO_REG_ASSIGN_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_SSRAMP_OTP                          */
/***********************************************************/
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_130_MA_SELECT_U8                    ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_260_MA_SELECT_U8                    ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_520_MA_SELECT_U8                    ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_900_MA_SELECT_U8                    ((uint8)0x03U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SSRAMP_OTP_VPRESRHS_MSB_OTP_MASK8 ))

#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_DVS_15_6_SELECT_U8                ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_DVS_7_8_SELECT_U8                 ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_DVS_2_6_SELECT_U8                 ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_DVS_2_23_SELECT_U8                ((uint8)0x03U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK12DVS_RAMP_OTP_MASK8 ))

#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_DVS_10_42_SELECT_U8                   ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_DVS_3_47_SELECT_U8                    ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_DVS_2_6_SELECT_U8                     ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_DVS_2_08_SELECT_U8                    ((uint8)0x03U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SSRAMP_OTP_BUCK3_RAMP_OTP_MASK8 ))

#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SELECT_00_U8                        ((uint8)0x00U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SELECT_01_U8                        ((uint8)0x01U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SELECT_02_U8                        ((uint8)0x02U)
#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SELECT_03_U8                        ((uint8)0x03U)

#define PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_U8(value)                   ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_SSRAMP_OTP_VPRE_TON_MIN_OTP_MASK8 ))

/**********************************************************************************/
/*                                  OTP FAIL-SAFE REGISTER                        */
/**********************************************************************************/
/***********************************************************/
/*                    CFG_UVOV_1_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_1_8_V_SELECT_U8           ((uint8)0xB1U)

#define PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_1_OTP_VCORE_V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_2_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_2_OTP_VCOREOVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_2_OTP_VDDIOOVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_3_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_0_STEPS_AVAILABLE_SELECT_U8          ((uint8)0x00U)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_2_STEPS_AVAILABLE_SELECT_U8          ((uint8)0x01U)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_4_STEPS_AVAILABLE_SELECT_U8          ((uint8)0x03U)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_8_STEPS_AVAILABLE_SELECT_U8          ((uint8)0x07U)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_16_STEPS_AVAILABLE_SELECT_U8         ((uint8)0x0FU)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_32_STEPS_AVAILABLE_SELECT_U8         ((uint8)0x1FU)
#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_64_STEPS_AVAILABLE_SELECT_U8         ((uint8)0x3FU)

#define PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_3_OTP_VCORE_SVS_CLAMP_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_4_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_4_OTP_VMON1OVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_4_OTP_VMON2OVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_5_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_5_OTP_VMON3OVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_5_OTP_VMON4OVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_6_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_6_OTP_VCOREUVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_6_OTP_VDDIOUVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_7_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_7_OTP_VMON1UVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_7_OTP_VMON2UVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_8_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_8_OTP_VMON3UVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_8_OTP_VMON4UVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_UVOV_9_OTP                       */
/***********************************************************/
#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_OVTH_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_UVOV_9_OTP_HVLDO_VMON_UVTH_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_I2C_OTP                          */
/***********************************************************/
#define PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_I2C_OTP_I2CDEVID_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_1_OTP                            */
/***********************************************************/
#define PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_0_8_V_SELECT_U8           ((uint8)0x00U)
#define PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_3_3_V_SELECT_U8           ((uint8)0x02U)

#define PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_1_OTP_HVLDO_V_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_2_OTP                            */
/***********************************************************/
#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_256MS_SELECT_U8           ((uint8)0x00U)
#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_1024MS_SELECT_U8          ((uint8)0x01U)
#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_32_5S_SELECT_U8          ((uint8)0x02U)
#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_67S_SELECT_U8          ((uint8)0x03U)

#define PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_2_OTP_WD_INIT_TIMEOUT_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_DEGLITCH1_OTP                    */
/***********************************************************/
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_MCU_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_U8(value)          ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH1_OTP_UV_VDDIO_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_DEGLITCH2_OTP                    */
/***********************************************************/
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_HVLDO_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON1_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH2_OTP_UV_VMON2_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_DEGLITCH3_OTP                    */
/***********************************************************/
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_5US_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_15US_SELECT_U8             ((uint8)0x01U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_25US_SELECT_U8             ((uint8)0x02U)
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_40US_SELECT_U8             ((uint8)0x03U)

#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON3_OTP_MASK8 ))
#define PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_U8(value)            ((uint8)( (uint8)( (value) << PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_SHIFT8 ) & PMIC_VR55XX_CFG_DEGLITCH3_OTP_UV_VMON4_OTP_MASK8 ))

/***********************************************************/
/*                    CFG_LBIST_BYP_OTP                    */
/***********************************************************/
#define PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_DISABLE_SELECT_U8             ((uint8)0x36U)
#define PMIC_VR55XX_CFG_LBIST_BYP_OTP_LBIST_DIS_OTP_ENABLE_SELECT_U8              ((uint8)0x00U)
#define PMIC_VR55XX_CFG_LBIST_BYP_NOT_OTP_LBIST_DIS_NOT_OTP_DISABLE_SELECT_U8     ((uint8)0xC9U)
#define PMIC_VR55XX_CFG_LBIST_BYP_NOT_OTP_LBIST_DIS_NOT_OTP_ENABLE_SELECT_U8      ((uint8)0xFFU)

/**********************************************************************************/
/*                                  MAIN REGISTER                                 */
/**********************************************************************************/
/***********************************************************/
/*                    M_SM_CTRL1                           */
/***********************************************************/
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_16MS_SELECT_U16                      ((uint16)0x00U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_32MS_SELECT_U16                      ((uint16)0x01U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_128MS_SELECT_U16                     ((uint16)0x02U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_512MS_SELECT_U16                     ((uint16)0x03U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_1024MS_SELECT_U16                    ((uint16)0x04U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_4096MS_SELECT_U16                    ((uint16)0x05U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_8192MS_SELECT_U16                    ((uint16)0x06U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_16384MS_SELECT_U16                   ((uint16)0x07U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_65536MS_SELECT_U16                   ((uint16)0x08U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_131072MS_SELECT_U16                  ((uint16)0x09U)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_262144MS_SELECT_U16                  ((uint16)0x0AU)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_524288MS_SELECT_U16                  ((uint16)0x0BU)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_1048576MS_SELECT_U16                 ((uint16)0x0CU)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_2097152MS_SELECT_U16                 ((uint16)0x0DU)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_4194304MS_SELECT_U16                 ((uint16)0x0EU)
#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_8388608MS_SELECT_U16                 ((uint16)0x0FU)

#define PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_U16(value)                            ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_SHIFT16 ) & PMIC_VR55XX_M_SM_CTRL1_TIMER_STBY_WINDOW_MASK16 ))

/***********************************************************/
/*                    M_REG_CTRL2                          */
/***********************************************************/
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_130_MA_SELECT_U16                  ((uint16)0x00U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_260_MA_SELECT_U16                  ((uint16)0x01U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_520_MA_SELECT_U16                  ((uint16)0x02U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_900_MA_SELECT_U16                  ((uint16)0x03U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_130_MA_SELECT_U16                  ((uint16)0x00U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_260_MA_SELECT_U16                  ((uint16)0x01U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_520_MA_SELECT_U16                  ((uint16)0x02U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_900_MA_SELECT_U16                  ((uint16)0x03U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_130_MA_SELECT_U16                  ((uint16)0x00U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_260_MA_SELECT_U16                  ((uint16)0x01U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_520_MA_SELECT_U16                  ((uint16)0x02U)
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_900_MA_SELECT_U16                  ((uint16)0x03U)

#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_50_SELECT_U16                        ((uint16)0x00U)
#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_100_SELECT_U16                       ((uint16)0x01U)
#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_300_SELECT_U16                       ((uint16)0x02U)
#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_500_SELECT_U16                       ((uint16)0x03U)

#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_SHIFT16 ) & PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MSB_MASK16 ))
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_SHIFT16 ) & PMIC_VR55XX_M_REG_CTRL2_VPRESRHS_MASK16 ))
#define PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_SHIFT16 ) & PMIC_VR55XX_M_REG_CTRL2_VPRESRLS_MASK16 ))
#define PMIC_VR55XX_M_REG_CTRL2_VBSTSR_U16(value)                           ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_REG_CTRL2_VBSTSR_SHIFT16 ) & PMIC_VR55XX_M_REG_CTRL2_VBSTSR_MASK16 ))

/***********************************************************/
/*                    M_AMUX                            */
/***********************************************************/
#define PMIC_VR55XX_M_AMUX_AMUX_GND_SELECT_U16                        ((uint16)0x00U)
#define PMIC_VR55XX_M_AMUX_AMUX_VDDIO_SELECT_U16                      ((uint16)0x01U)
#define PMIC_VR55XX_M_AMUX_AMUX_TEMPERATURE_SELECT_U16                ((uint16)0x02U)
#define PMIC_VR55XX_M_AMUX_AMUX_BANDGAP_MAIN_SELECT_U16               ((uint16)0x03U)
#define PMIC_VR55XX_M_AMUX_AMUX_BANDGAP_FAIL_SAFE_SELECT_U16          ((uint16)0x04U)
#define PMIC_VR55XX_M_AMUX_AMUX_BUCK1_SELECT_U16                      ((uint16)0x05U)
#define PMIC_VR55XX_M_AMUX_AMUX_BUCK2_SELECT_U16                      ((uint16)0x06U)
#define PMIC_VR55XX_M_AMUX_AMUX_BUCK3_SELECT_U16                      ((uint16)0x07U)
#define PMIC_VR55XX_M_AMUX_AMUX_VPRE_SELECT_U16                       ((uint16)0x08U)
#define PMIC_VR55XX_M_AMUX_AMUX_VBOOST_SELECT_U16                     ((uint16)0x09U)
#define PMIC_VR55XX_M_AMUX_AMUX_LDO1_SELECT_U16                       ((uint16)0x0AU)
#define PMIC_VR55XX_M_AMUX_AMUX_LDO2_SELECT_U16                       ((uint16)0x0BU)
#define PMIC_VR55XX_M_AMUX_AMUX_VBOS_SELECT_U16                       ((uint16)0x0CU)
#define PMIC_VR55XX_M_AMUX_AMUX_VSUP1_SELECT_U16                      ((uint16)0x0EU)
#define PMIC_VR55XX_M_AMUX_AMUX_PWRON1_SELECT_U16                     ((uint16)0x0FU)
#define PMIC_VR55XX_M_AMUX_AMUX_PWRON2_SELECT_U16                     ((uint16)0x10U)
#define PMIC_VR55XX_M_AMUX_AMUX_HVLDO_SELECT_U16                      ((uint16)0x11U)
#define PMIC_VR55XX_M_AMUX_AMUX_LDO3_SELECT_U16                       ((uint16)0x12U)


#define PMIC_VR55XX_M_AMUX_AMUX_U16(value)                            ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_AMUX_AMUX_SHIFT16 ) & PMIC_VR55XX_M_AMUX_AMUX_MASK16 ))

/***********************************************************/
/*                    M_TSD_CFG                            */
/***********************************************************/
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_75_SELECT_U16                 ((uint16)0x00U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_90_SELECT_U16                 ((uint16)0x01U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_105_SELECT_U16                ((uint16)0x02U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_120_SELECT_U16                ((uint16)0x03U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_135_SELECT_U16                ((uint16)0x04U)
#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_150_SELECT_U16                ((uint16)0x05U)

#define PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_U16(value)                    ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_SHIFT16 ) & PMIC_VR55XX_M_TSD_CFG_DIE_CENTER_TEMP_MASK16 ))

/***********************************************************/
/*                    M_CLOCK1                             */
/***********************************************************/
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_16000000_SELECT_U16               ((uint16)0x09U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_17000000_SELECT_U16               ((uint16)0x0AU)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_18000000_SELECT_U16               ((uint16)0x0BU)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_19000000_SELECT_U16               ((uint16)0x0CU)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_20000000_SELECT_U16               ((uint16)0x00U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_21000000_SELECT_U16               ((uint16)0x01U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_22000000_SELECT_U16               ((uint16)0x02U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_23000000_SELECT_U16               ((uint16)0x03U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_24000000_SELECT_U16               ((uint16)0x04U)
#define PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_U16(value)                        ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_SHIFT16 ) & PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16 ))

#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_DISABLED_SELECT_U16               ((uint16)0x00U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_VPRE_CLK_SELECT_U16               ((uint16)0x01U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_BOOST_CLK_SELECT_U16              ((uint16)0x02U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_BUCK1_CLK_SELECT_U16              ((uint16)0x03U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_BUCK2_CLK_SELECT_U16              ((uint16)0x04U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_BUCK3_CLK_SELECT_U16              ((uint16)0x05U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_FOUT_CLK_SELECT_U16               ((uint16)0x06U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_CLK20M_MAIN_DIV48_SELECT_U16      ((uint16)0x07U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_CLK20M_FS_DIV48_SELECT_U16        ((uint16)0x08U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_CLK_FIN_DIV_SELECT_U16            ((uint16)0x09U)
#define PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_U16(value)                        ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_SHIFT16 ) & PMIC_VR55XX_M_CLOCK1_FOUT_MUX_SEL_MASK16 ))

#define PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_U16(value)                          ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_SHIFT16 ) & PMIC_VR55XX_M_CLOCK1_FOUT_PHASE_MASK16 ))

/***********************************************************/
/*                    M_CLOCK2                             */
/***********************************************************/
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_100000_SELECT_U16                ((uint16)0x00U)
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_300000_SELECT_U16                ((uint16)0x01U)
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_600000_SELECT_U16                ((uint16)0x03U)
#define PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_U16(value)                       ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_SHIFT16 ) & PMIC_VR55XX_M_CLOCK2_LOW_POWER_CLK_MASK16 ))

/***********************************************************/
/*                    M_VMON_REGx                          */
/***********************************************************/
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16     ((uint16)0x00U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_VPRE_SELECT_U16                   ((uint16)0x01U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_LDO1_SELECT_U16                   ((uint16)0x02U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_LDO2_SELECT_U16                   ((uint16)0x03U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_BUCK3_SELECT_U16                  ((uint16)0x04U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_BOOST_SELECT_U16                  ((uint16)0x05U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_1_REG_ASSIGN_LDO3_SELECT_U16                   ((uint16)0x06U)

#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16     ((uint16)0x00U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_VPRE_SELECT_U16                   ((uint16)0x01U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_LDO1_SELECT_U16                   ((uint16)0x02U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_LDO2_SELECT_U16                   ((uint16)0x03U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_BUCK3_SELECT_U16                  ((uint16)0x04U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_BOOST_SELECT_U16                  ((uint16)0x05U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_2_REG_ASSIGN_LDO3_SELECT_U16                   ((uint16)0x06U)

#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16     ((uint16)0x00U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_VPRE_SELECT_U16                   ((uint16)0x01U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_LDO1_SELECT_U16                   ((uint16)0x02U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_LDO2_SELECT_U16                   ((uint16)0x03U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_BUCK3_SELECT_U16                  ((uint16)0x04U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_BOOST_SELECT_U16                  ((uint16)0x05U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_3_REG_ASSIGN_LDO3_SELECT_U16                   ((uint16)0x06U)

#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_EXTERNAL_REGULATOR_SELECT_U16     ((uint16)0x00U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_VPRE_SELECT_U16                   ((uint16)0x01U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_LDO1_SELECT_U16                   ((uint16)0x02U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_LDO2_SELECT_U16                   ((uint16)0x03U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_BUCK3_SELECT_U16                  ((uint16)0x04U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_BOOST_SELECT_U16                  ((uint16)0x05U)
#define PMIC_VR55XX_M_VMON_REGx_VMON_4_REG_ASSIGN_LDO3_SELECT_U16                   ((uint16)0x06U)

#define PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_SHIFT16 ) & PMIC_VR55XX_M_VMON_REGx_VMON1_REG_ASSIGN_MASK16 ))
#define PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_SHIFT16 ) & PMIC_VR55XX_M_VMON_REGx_VMON2_REG_ASSIGN_MASK16 ))
#define PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_SHIFT16 ) & PMIC_VR55XX_M_VMON_REGx_VMON3_REG_ASSIGN_MASK16 ))
#define PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_SHIFT16 ) & PMIC_VR55XX_M_VMON_REGx_VMON4_REG_ASSIGN_MASK16 ))

/***********************************************************/
/*                       M_LVB1_STBY_DVS                      */
/***********************************************************/
#define PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_1_8_V_SELECT_U16                     ((uint16)0xB1U)

#define PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_U16(value)                           ((uint16)( (uint16)( (value) << PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_SHIFT16 ) & PMIC_VR55XX_M_LVB1_STBY_DVS_BUCK1_STBY_MASK16 ))

/***********************************************************/
/*                       M_DEVICEID                        */
/***********************************************************/
#define PMIC_VR55XX_M_DEVICEID_FAM_ID_U16(value)                                    ((uint16)( (uint16)( (value) & PMIC_VR55XX_M_DEVICEID_FAM_ID_MASK16 ) >> PMIC_VR55XX_M_DEVICEID_FAM_ID_SHIFT16 ))
#define PMIC_VR55XX_M_DEVICEID_DEV_ID_U16(value)                                    ((uint16)( (uint16)( (value) & PMIC_VR55XX_M_DEVICEID_DEV_ID_MASK16 ) >> PMIC_VR55XX_M_DEVICEID_DEV_ID_SHIFT16 ))
#define PMIC_VR55XX_M_DEVICEID_MMREV_U16(value)                                     ((uint16)( (uint16)( (value) & PMIC_VR55XX_M_DEVICEID_MMREV_MASK16 ) >> PMIC_VR55XX_M_DEVICEID_MMREV_SHIFT16 ))
#define PMIC_VR55XX_M_DEVICEID_FMREV_U16(value)                                     ((uint16)( (uint16)( (value) & PMIC_VR55XX_M_DEVICEID_FMREV_MASK16 ) >> PMIC_VR55XX_M_DEVICEID_FMREV_SHIFT16 ))

/***********************************************************/
/*                       M_TM_ENTRY                        */
/***********************************************************/
#define PMIC_VR55XX_M_TM_ENTRY_KEY1_U16             ((uint16)0xD5A7U)
#define PMIC_VR55XX_M_TM_ENTRY_KEY2_U16             ((uint16)0xB8EEU)
#define PMIC_VR55XX_M_TM_ENTRY_KEY3_U16             ((uint16)0x0F37U)

/***********************************************************/
/*                       M_MIRRORCMD                       */
/***********************************************************/
#define PMIC_VR55XX_M_OTPCMD_CRC_GENERATE_KEY_U16             ((uint16)0x0125U)
#define PMIC_VR55XX_M_OTPCMD_CRC_CHECK_KEY_U16                ((uint16)0x0124U)

/**********************************************************************************/
/*                            FAIL-SAFE REGISTER                                  */
/**********************************************************************************/
/***********************************************************/
/*                       FS_I_OVUV_SAFE_REACTIONx          */
/***********************************************************/
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_DISABLED_SELECT_U16                ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_ASSERT_SELECT_U16             ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTIONX_FS0B_AND_RSTB_ASSERT_SELECT_U16    ((uint16)0x02U)

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VDDIO_OV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_U16(value)           ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_U16(value)           ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_HVLDO_VMON_OV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_U16(value)             ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_U16(value)             ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_VCOREMON_OV_FS_IMPACT_MASK16 ))

#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON1_OV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON2_OV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON3_OV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_UV_FS_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_VMON4_OV_FS_IMPACT_MASK16 ))

/***********************************************************/
/*                       FS_I_WD_CFG                       */
/***********************************************************/
#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_DISABLED_SELECT_U16                ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_FS0B_ASSERT_SELECT_U16             ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_FS0B_AND_RSTB_ASSERT_SELECT_U16    ((uint16)0x02U)

#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_SHIFT16 ) & PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_LIMIT_MASK16 ))
#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_SHIFT16 ) & PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_MASK16 ))
#define PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_U16(value)                         ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_WD_CFG_WD_FS_IMPACT_MASK16 ))

#define PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_CNT_VALUE_U16(value)                     ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_CNT_MASK16 ) >> PMIC_VR55XX_FS_I_WD_CFG_WD_ERR_CNT_SHIFT16 ))
#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_CNT_VALUE_U16(value)                     ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_CNT_MASK16 ) >> PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_CNT_SHIFT16 ))
#define PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_VALUE_U16(value)                   ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_MASK16 ) >> PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_SHIFT16 ))

/***********************************************************/
/*                       FS_I_SAFE_INPUTS                  */
/***********************************************************/
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_DISABLED_SELECT_U16            ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_10US_SELECT_U16                ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_20US_SELECT_U16                ((uint16)0x02U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_50US_SELECT_U16                ((uint16)0x03U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_60US_SELECT_U16                ((uint16)0x04U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_80US_SELECT_U16                ((uint16)0x05U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_100US_SELECT_U16               ((uint16)0x06U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_200US_SELECT_U16               ((uint16)0x07U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_300US_SELECT_U16               ((uint16)0x08U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_500US_SELECT_U16               ((uint16)0x09U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_1MS_SELECT_U16                 ((uint16)0x0AU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_2MS_SELECT_U16                 ((uint16)0x0BU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_3MS_SELECT_U16                 ((uint16)0x0CU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_5MS_SELECT_U16                 ((uint16)0x0DU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_8MS_SELECT_U16                 ((uint16)0x0EU)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_10MS_SELECT_U16                ((uint16)0x0FU)

#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_DISABLED_SELECT_U16                      ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_FCCU1_AND_FCCU2_PAIR_SELECT_U16          ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_FCCU1_OR_FCCU2_INDEPENDENT_SELECT_U16    ((uint16)0x02U)
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_FCCU1_ONLY_SELECT_U16                    ((uint16)0x03U)

#define PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_U16(value)                     ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_SHIFT16 ) & PMIC_VR55XX_FS_I_SAFE_INPUTS_TIMING_WINDOW_STBY_MASK16 ))
#define PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_U16(value)                               ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_SHIFT16 ) & PMIC_VR55XX_FS_I_SAFE_INPUTS_FCCU_CFG_MASK16 ))

/***********************************************************/
/*                       FS_I_SVS                          */
/***********************************************************/
#define PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_U16(value)                                     ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_SHIFT16 ) & PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_MASK16 ))

/***********************************************************/
/*                       FS_I_FSSM                         */
/***********************************************************/
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_DISABLED_SELECT_U16                       ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_FS0B_ASSERT_SELECT_U16                    ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_FS0B_AND_RSTB_ASSERT_SELECT_U16           ((uint16)0x02U)

#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_2_SELECT_U16                           ((uint16)0x00U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_6_SELECT_U16                           ((uint16)0x01U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_8_SELECT_U16                           ((uint16)0x02U)
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_12_SELECT_U16                          ((uint16)0x03U)

#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_U16(value)                                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_SHIFT16 ) & PMIC_VR55XX_FS_I_FSSM_FLT_ERR_IMPACT_MASK16 ))
#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_U16(value)                             ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_SHIFT16 ) & PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_LIMIT_MASK16 ))

#define PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_VALUE_U16(value)                             ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_MASK16 ) >> PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_SHIFT16 ))

/***********************************************************/
/*                       FS_WD_WINDOW_DUR                  */
/***********************************************************/
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_DISABLE_SELECT_U16        ((uint16)0x00U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_1MS_SELECT_U16            ((uint16)0x01U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_2MS_SELECT_U16            ((uint16)0x02U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_3MS_SELECT_U16            ((uint16)0x03U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_4MS_SELECT_U16            ((uint16)0x04U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_6MS_SELECT_U16            ((uint16)0x05U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_8MS_SELECT_U16            ((uint16)0x06U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_12MS_SELECT_U16           ((uint16)0x07U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_16MS_SELECT_U16           ((uint16)0x08U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_24MS_SELECT_U16           ((uint16)0x09U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_32MS_SELECT_U16           ((uint16)0x0AU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_64MS_SELECT_U16           ((uint16)0x0BU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_128MS_SELECT_U16          ((uint16)0x0CU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_256MS_SELECT_U16          ((uint16)0x0DU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_512MS_SELECT_U16          ((uint16)0x0EU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_1024MS_SELECT_U16         ((uint16)0x0FU)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_31_25_SELECT_U16                ((uint16)0x00U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_37_5_SELECT_U16                 ((uint16)0x01U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_50_0_SELECT_U16                 ((uint16)0x02U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_62_5_SELECT_U16                 ((uint16)0x03U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_68_75_SELECT_U16                ((uint16)0x04U)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16           ((uint16)0x00U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_1MS_SELECT_U16               ((uint16)0x01U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_2MS_SELECT_U16               ((uint16)0x02U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_3MS_SELECT_U16               ((uint16)0x03U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_4MS_SELECT_U16               ((uint16)0x04U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_6MS_SELECT_U16               ((uint16)0x05U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_8MS_SELECT_U16               ((uint16)0x06U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_12MS_SELECT_U16              ((uint16)0x07U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_16MS_SELECT_U16              ((uint16)0x08U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_24MS_SELECT_U16              ((uint16)0x09U)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_32MS_SELECT_U16              ((uint16)0x0AU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_64MS_SELECT_U16              ((uint16)0x0BU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_128MS_SELECT_U16             ((uint16)0x0CU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_256MS_SELECT_U16             ((uint16)0x0DU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_512MS_SELECT_U16             ((uint16)0x0EU)
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_1024MS_SELECT_U16            ((uint16)0x0FU)

#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_U16(value)                ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_SHIFT16 ) & PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_RECOVERY_MASK16 ))
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_U16(value)                      ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_SHIFT16 ) & PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_MASK16 ))
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_U16(value)                   ((uint16)( (uint16)( (value) << PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_SHIFT16 ) & PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_MASK16 ))
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_VALUE_U16(value)                ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_MASK16 ) >> PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_SHIFT16 ))
#define PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(value)             ((uint16)( (uint16)( (value) & PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_MASK16 ) >> PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_SHIFT16 ))

/***********************************************************/
/*                       FS_TM_ENTRY                        */
/***********************************************************/
#define PMIC_VR55XX_FS_TM_ENTRY_KEY1_U16             ((uint16)0xD5A7U)
#define PMIC_VR55XX_FS_TM_ENTRY_KEY2_U16             ((uint16)0xB8EEU)
#define PMIC_VR55XX_FS_TM_ENTRY_KEY3_U16             ((uint16)0x0F37U)

/***********************************************************/
/*                       FS_OTPCMD                         */
/***********************************************************/
#define PMIC_VR55XX_FS_OTPCMD_CRC_GENERATE_KEY_U16             ((uint16)0x0125U)
#define PMIC_VR55XX_FS_OTPCMD_CRC_CHECK_KEY_U16                ((uint16)0x0124U)

/***********************************************************/
/*                       FS_STATES                         */
/***********************************************************/
#define PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16             ((uint16)0x0006U)
#define PMIC_VR55XX_FS_STATES_FSM_STATES_ABIST2_U16              ((uint16)0x0008U)
#define PMIC_VR55XX_FS_STATES_FSM_STATES_ASSERT_FS0B_U16         ((uint16)0x0009U)
#define PMIC_VR55XX_FS_STATES_FSM_STATES_NORMAL_FS_U16           ((uint16)0x000AU)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PMIC_VR55XX_TYPES_H */
