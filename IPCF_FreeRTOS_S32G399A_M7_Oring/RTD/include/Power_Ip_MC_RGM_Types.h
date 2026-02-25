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

#ifndef POWER_IP_MC_RGM_TYPES_H
#define POWER_IP_MC_RGM_TYPES_H

/**
*   @file       Power_Ip_MC_RGM_Types.h
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
#include "Power_Ip_Specific.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_MC_RGM_TYPES_VENDOR_ID                       43
#define POWER_IP_MC_RGM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_MC_RGM_TYPES_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_MC_RGM_TYPES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_MC_RGM_TYPES_SW_MAJOR_VERSION                4
#define POWER_IP_MC_RGM_TYPES_SW_MINOR_VERSION                0
#define POWER_IP_MC_RGM_TYPES_SW_PATCH_VERSION                2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_MC_RGM_Types.h file and Power_Ip_Specific.h file have same versions */
#if (POWER_IP_MC_RGM_TYPES_VENDOR_ID  != POWER_IP_SPECIFIC_VENDOR_ID)
    #error "Power_Ip_MC_RGM_Types.h and Power_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Power_Ip_MC_RGM_Types.h file and Power_Ip_Specific.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_TYPES_AR_RELEASE_MAJOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_TYPES_AR_RELEASE_MINOR_VERSION    != POWER_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_TYPES_AR_RELEASE_REVISION_VERSION != POWER_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM_Types.h and Power_Ip_Specific.h are different"
#endif

/* Check if Power_Ip_MC_RGM_Types.h file and Power_Ip_Specific.h file are of the same Software version */
#if ((POWER_IP_MC_RGM_TYPES_SW_MAJOR_VERSION != POWER_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_TYPES_SW_MINOR_VERSION != POWER_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_TYPES_SW_PATCH_VERSION != POWER_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Power_Ip_MC_RGM_Types.h and Power_Ip_Specific.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#if (POWER_IP_PERFORM_RESET_API == STD_ON)
/**
* @brief            Reset type to be performed through the Mcu_PerformReset() API.
* @details          Destructive Reset:
*                       - Flash is always reset, so an updated value of the option bits is reloaded
*                         in volatile registers outside of the Flash array.
*                       - Trimming is lost.
*                       - STCU is reset and configured BISTs are executed
*                   Functional Reset:
*                       - Starts the reset sequence from PHASE1 or from PHASE3.
*                       - The volatile registers are not reset; in case of a reset event, the
*                         trimming is maintained.
*                       - No BISTs shall be executed after functional resets.
*/
typedef enum
{
    MCU_FUNC_RESET = 0x5AU,     /**< @brief Functional Reset type. */
    MCU_DEST_RESET = 0x3CU      /**< @brief Destructive Reset type. */

} Power_Ip_MC_RGM_ResetType;
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            Configuration of MC_RGM hardware IP.
* @details          This data configuration is set at module initialization phase.
*/
typedef struct
{
#if (POWER_IP_PERFORM_RESET_API == STD_ON)
    /**< @brief RESET type: Functional vs Destructive. */
    Power_Ip_MC_RGM_ResetType ResetType;
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */

#if (defined(POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT))
  #if (POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT == STD_ON)
    /**< @brief Enable/Disable functional reset sources (RGM_FERD register). */
    uint32 FuncResetOpt;
  #endif
#endif /* POWER_IP_FUNCTIONAL_RESET_DISABLE_SUPPORT */

    /**< @brief Functional Reset Escalation Threshold (RGM_FRET register). */
    uint32 FesThresholdReset;

    /**< @brief Destructive Reset Escalation Threshold (RGM_DRET register). */
    uint32 DesThresholdReset;

#if defined(POWER_IP_FUNCTIONAL_RESET_ENTRY_TIMEOUT_SUPPORT)
  #if (POWER_IP_FUNCTIONAL_RESET_ENTRY_TIMEOUT_SUPPORT == STD_ON)
    uint32 ResetEntryTimeout;
  #endif
#endif

} Power_Ip_MC_RGM_ConfigType;


#if (defined(POWER_IP_RESET_DOMAINS_SUPPORTED))
  #if (POWER_IP_RESET_DOMAINS_SUPPORTED == STD_ON)
/**
* @brief   MC_RGM Core Reset Configuration.
* @details This structure contains information for configuring the cores.
*          The definitions for each Core setting within the structure Mcu_Power_Ip_MC_RGM_CoreConfigType shall contain:
*          - The index of the Core (within its domain).
*          - Power management information (i.e. assert or deassert the reset signal of the Core).
*/
typedef struct
{
    /**< @brief Specifies whether the given core is under MCU control. */
    boolean CoreUnderMcuControl;

    /**< @brief The index of the core within the domain. */
    uint8 CoreIndex;

    /** @brief The reset enable register value of the core. */
    uint32 CorePrstRegValue;

    /** @brief Mask containing the Core blocks to be updated. */
    uint32 CoreBlocksToUpdateMask;

} Power_Ip_MC_RGM_CoreConfigType;

/**
* @brief   MC_RGM COFB Configuration.
* @details This structure contains information for configuring the COFBs (Collection of Functional Blocks).
*          The definitions for each COFB setting within the structure Mcu_Power_Ip_MC_RGM_CofbConfigType shall contain:
*          - The index of the COFB (within its domain).
*          - The list of peripherals enable/disable (i.e. the value of the PRSTx_COFBy register).
*/
typedef struct
{
    /**< @brief Specifies whether the given COFB set is under MCU control. */
    boolean CofbUnderMcuControl;

    /**< @brief The index of the COFB set within the domain. */
    uint8 CofbIndex;

    /** @brief The reset enable register value of the COFB set. */
    uint32 CofbRstRegValue;

    /** @brief Mask containing the COFB blocks to be updated. */
    uint32 CofbBlocksToUpdateMask;

} Power_Ip_MC_RGM_CofbConfigType;

/**
* @brief   MC_RGM Domain Configuration.
* @details This structure contains information for configuring the Domains.
*          The definitions for each Domain setting within the structure Mcu_Power_Ip_MC_RGM_DomainConfigType shall contain:
*          - The index of the Domain.
*          - The configuration settings for the COFBs contained within the Domain.
*/
typedef struct
{
    /**< @brief Specifies whether the given domain is under MCU control. */
    boolean DomainUnderMcuControl;

    /**< @brief Specifies whether the given domain's power management is under MCU control */
    boolean DomainPowerUnderMcuControl;

    /**< @brief The index of the domain. */
    uint8 DomainIndex;

    /** @brief The process configuration register value of the domain. */
    uint32 DomainRdcRegValue;

    /**< @brief Number of COFBs within the domain. */
    uint8 NumberOfCofbs;

    /**< @brief The configuration of the COFBs. */
    const Power_Ip_MC_RGM_CofbConfigType (*ArrayDomainCofbConfigPtr)[];

    /**< @brief Number of cores within the domain. */
    uint8 NumberOfCores;

    /**< @brief The configuration of the cores. */
    const Power_Ip_MC_RGM_CoreConfigType (*ArrayDomainCoreConfigPtr)[];

} Power_Ip_MC_RGM_DomainConfigType;

/**
* @brief   MC_RGM IP Mode Configuration.
* @details This structure contains information for configuring the entire MC_RGM IP.
*/
typedef struct
{
    /**< @brief MC_RGM Mode Domain Settings. */
    const Power_Ip_MC_RGM_DomainConfigType (*ArrayDomainConfigPtr)[POWER_IP_MAX_NUMBER_OF_PARTITIONS];

} Power_Ip_MC_RGM_ModeConfigType;
  #endif /* (POWER_IP_RESET_DOMAINS_SUPPORTED == STD_ON) */
#endif

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED))
  #if (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON)
typedef enum
{
    POWER_MC_RGM_UNINIT = 0,  /**< @brief The MC_RGM driver is uninitialized. */
    POWER_MC_RGM_INIT = 1     /**< @brief The MC_RGM driver is initialized. */
} Power_MC_RGM_StatusType;
  #endif
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* POWER_IP_MC_RGM_TYPES_H */

