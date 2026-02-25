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
*   @file       Power_Ip_CortexA.c
*   @version    4.0.2
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip_CortexA.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CORTEXM4.c
* @requirements
*/
#define POWER_IP_CORTEXA_VENDOR_ID_C                       43
#define POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION_C        4
#define POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION_C        4
#define POWER_IP_CORTEXA_AR_RELEASE_REVISION_VERSION_C     0
#define POWER_IP_CORTEXA_SW_MAJOR_VERSION_C                4
#define POWER_IP_CORTEXA_SW_MINOR_VERSION_C                0
#define POWER_IP_CORTEXA_SW_PATCH_VERSION_C                2


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_CortexA.c file and Power_Ip_CortexA.h file are of the same vendor */
#if (POWER_IP_CORTEXA_VENDOR_ID_C != POWER_IP_CORTEXA_VENDOR_ID)
    #error "Power_Ip_CortexA.c and Power_Ip_CortexA.h have different vendor ids"
#endif

/* Check if Power_Ip_CortexA.c file and Power_Ip_CortexA.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CORTEXA_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CORTEXA_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXA_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CORTEXA_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_CortexA.c and Power_Ip_CortexA.h are different"
#endif

/* Check if Power_Ip_CortexA.c file and Power_Ip_CortexA.h file are of the same Software version */
#if ((POWER_IP_CORTEXA_SW_MAJOR_VERSION_C != POWER_IP_CORTEXA_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXA_SW_MINOR_VERSION_C != POWER_IP_CORTEXA_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXA_SW_PATCH_VERSION_C != POWER_IP_CORTEXA_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_CortexA.c and Power_Ip_CortexA.h are different"
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                     LOCAL FUNCTION
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


#if (defined(MCAL_PLATFORM_ARM) && (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64))
void Power_Ip_CortexA64_WarmReset(void)
{
    /* Write into RR bit of RMR register to issue WARMRESETREQ. */
    ASM_KEYWORD("mrs x0, RMR_EL3");
    ASM_KEYWORD("orr x0, x0, #(1<<1)");
    ASM_KEYWORD("msr RMR_EL3, x0");

    /* Clear SCTLR.C to prevent further data cache allocation.. */
    ASM_KEYWORD("mrs x0, SCTLR_EL1");
    ASM_KEYWORD("and x0, x0, #(~(1<<2))");
    ASM_KEYWORD("msr SCTLR_EL1, x0");

    /* Select CCSIDR register by writing into CSSELR (LEVEL = L1, InD = D-CACHE) */
    ASM_KEYWORD("mov x0, #0");
    ASM_KEYWORD("msr CSSELR_EL1, x0");
    ASM_KEYWORD("dsb sy");

    /* Calculate values to be written into DC CISW (According to the complete
     * ARM CCSIDR encodings, L1 D-CACHE is always configured as 4-way and
     * has 16-words cache lines) */
    ASM_KEYWORD("mov x1, #0");
    ASM_KEYWORD("mov x2, #0x40000000");
    ASM_KEYWORD("mov x3, #0x80000000");
    ASM_KEYWORD("mov x4, #0xC0000000");

    /* Get the number of sets (i.e. value of CCSIDR[NumSets] = CCSIDR[27:13]) */
    ASM_KEYWORD("mrs x0, CCSIDR_EL1");
    ASM_KEYWORD("lsr x6, x0, #13");
    ASM_KEYWORD("and x6, x6, #0x3FFF");

    /* Line length = 16-Word = 64-byte = 2^6 => The lowest bit of "Set" is 6 */
    ASM_KEYWORD("mov x5, #0x40");

    ASM_KEYWORD("clean_invalidate_loop:");
    /* Clean and invalidate all the ways (lines) of the current set (DC CISW)*/
    ASM_KEYWORD("DC CISW, x1");
    ASM_KEYWORD("DC CISW, x2");
    ASM_KEYWORD("DC CISW, x3");
    ASM_KEYWORD("DC CISW, x4");

    /* Calculate the next set index */
    ASM_KEYWORD("add x1, x1, x5");
    ASM_KEYWORD("add x2, x2, x5");
    ASM_KEYWORD("add x3, x3, x5");
    ASM_KEYWORD("add x4, x4, x5");

    /* Decrease the set counter */
    ASM_KEYWORD("subs x6, x6, #1");
    ASM_KEYWORD("b.ne clean_invalidate_loop");

    /* Disable data coherency with other cores in the cluster, by clearing the CPUECTLR.SMPEN bit. */
    ASM_KEYWORD("mrs x0, S3_1_C15_C2_1");
    ASM_KEYWORD("and x0, x0, #(~(1<<6))");
    ASM_KEYWORD("msr S3_1_C15_C2_1, x0");

    /* Execute an ISB instruction to ensure that all the register changes from the previous steps have been committed. */
    ASM_KEYWORD("isb");

    /* Execute a DSB SY instruction to ensure that all cache, TLB and branch predictor maintenance operations issued by
    any core in the cluster device before the SMPEN bit was cleared have completed. */
    ASM_KEYWORD("dsb sy");

    /* Execute WFI */
    EXECUTE_WAIT();
}
#endif /* (defined(MCAL_PLATFORM_ARM) && (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)) */


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif



/** @} */
