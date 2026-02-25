/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IIC
*   Dependencies         : MCU,PORT,DET,RTE
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
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
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
#include "CDD_I2c_PBcfg.h"
#include "I2c_Ipw_PBcfg.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_PBCFG_VENDOR_ID_C                     43
#define I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C      4
#define I2C_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define I2C_PBCFG_SW_MAJOR_VERSION_C              4
#define I2C_PBCFG_SW_MINOR_VERSION_C              0
#define I2C_PBCFG_SW_PATCH_VERSION_C              2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same vendor */
#if (I2C_PBCFG_VENDOR_ID_C != I2C_PBCFG_VENDOR_ID)
    #error "CDD_I2c_PBcfg.c and CDD_I2c_PBcfg.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same Autosar version */
#if ((I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != I2C_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C     != I2C_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_REVISION_VERSION_C  != I2C_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_I2c_PBcfg.c and CDD_I2c_PBcfg.h are different"
#endif
/* Check if current file and CDD_I2c_PBcfg.h header file are of the same software version */
#if ((I2C_PBCFG_SW_MAJOR_VERSION_C != I2C_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_PBCFG_SW_MINOR_VERSION_C != I2C_PBCFG_SW_MINOR_VERSION) || \
     (I2C_PBCFG_SW_PATCH_VERSION_C != I2C_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_I2c_PBcfg.c and CDD_I2c_PBcfg.h are different"
#endif
/* Check if current file and I2c_Ipw_PBcfg.h header file are of the same vendor */
#if (I2C_PBCFG_VENDOR_ID_C != I2C_IPW_PBCFG_VENDOR_ID)
    #error "CDD_I2c_PBcfg.c and I2c_Ipw_PBcfg.h have different vendor ids"
#endif
/* Check if current file and I2c_Ipw_PBcfg.h header file are of the same Autosar version */
#if ((I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != I2C_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C     != I2C_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_PBCFG_AR_RELEASE_REVISION_VERSION_C  != I2C_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_I2c_PBcfg.c and I2c_Ipw_PBcfg.h are different"
#endif

/* Check if current file and I2c_Ipw_PBcfg.h header file are of the same software version */
#if ((I2C_PBCFG_SW_MAJOR_VERSION_C != I2C_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_PBCFG_SW_MINOR_VERSION_C != I2C_IPW_PBCFG_SW_MINOR_VERSION) || \
     (I2C_PBCFG_SW_PATCH_VERSION_C != I2C_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_I2c_PBcfg.c and I2c_Ipw_PBcfg.h are different"
#endif

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if ((I2C_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (I2C_PBCFG_AR_RELEASE_MINOR_VERSION_C  != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CDD_I2c_PBcfg.c and Dem.h are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* I2C_DISABLE_DEM_REPORT_ERROR_STATUS */

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/**
* @brief          Paritition IDs.
* @details        Paritition IDs.
*
* @api
*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "I2c_MemMap.h"

/**
* @brief        Definition of I2c hardware channel structure.
* @details      Configures the hardware peripheral of an I2c channel.
*               Configuration set by calling I2c_Init() API.
*/

static const I2c_HwUnitConfigType I2c_ChannelConfigPB[1] =
{
    /* Start of I2c_ChannelConfig[0] */
    {
        /* The hardware channel ID. */
        (I2c_HwUnitType) I2C_IIC_4,

        /* The Partition Id */
        (I2c_PartCoreType) I2C_SPURIOUS_CORE_ID,

        /* The master/slave mode of the channel. */
        I2C_MASTER_MODE,

        /* The hardware channel type */
        I2C_IIC_CHANNEL,

        {
            &I2c_Ipw_ChannelConfig0
        }
    } /* end of I2c_ChannelConfig[0]. */
};

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
/**
* @brief          Initialization data for the I2c driver.
* @details        A structure is provided to the I2c initialization routines for configuration.
*                 The configuration structure for spurious_core.
*
*/
const I2c_ConfigType I2c_PBCfgVariantPredefined_spurious_core =
{
    /* The Partition Core Id */
    (I2c_PartCoreType) I2C_SPURIOUS_CORE_ID,

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &I2c_DemConfig,
#endif

    /* Pointer to I2c hardware unit configuration. */
    &I2c_ChannelConfigPB
};

/**
* @brief          Initialization data for the I2c driver.
* @details        A pointer to such a structure is provided to the I2c initialization routines for configuration.
*
*/
const I2c_ConfigType * const I2c_PBCfgVariantPredefined[I2C_MAX_CORE_ID] =
{
    /** @brief  Pointer to configuration structure of I2c */
    &I2c_PBCfgVariantPredefined_spurious_core
};

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

