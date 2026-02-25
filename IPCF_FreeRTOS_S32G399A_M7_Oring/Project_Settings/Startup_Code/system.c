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
*   Build Version        : S32_RTD_4_0_2_D2306_ASR_REL_4_4_REV_0000_20230630
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*================================================================================================
*   @file    system.c
*   @version 4.0.2
*
*   @brief   AUTOSAR Platform - SYSTEM
*   @details SYSTEM
*            This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#if defined(S32G2XX)
    #include "S32G274A_MSCM.h"
    #include "S32G274A_FXOSC.h"
    #include "S32G274A_MC_CGM.h"
    #include "S32G274A_MC_CGM_1.h"
    #include "S32G274A_MC_CGM_2.h"
    #include "S32G274A_SCB.h"
    #include "S32G274A_MPU.h"
    #include "S32G274A_MC_ME.h"
    #include "S32G274A_MC_RGM.h"
    #include "S32G274A_SECURITY.h"
    #include "S32G274A_MDM_AP.h"
    #include "S32G274A_SIUL2.h"
#elif defined(S32R45)
    #include "S32R45_MSCM.h"
    #include "S32R45_FXOSC.h"
    #include "S32R45_MC_CGM.h"
    #include "S32R45_MC_CGM_1.h"
    #include "S32R45_MC_CGM_2.h"
    #include "S32R45_SCB.h"
    #include "S32R45_MPU.h"
    #include "S32R45_MC_ME.h"
    #include "S32R45_MC_RGM.h"
    #include "S32R45_SECURITY.h"
    #include "S32R45_MDM_AP.h"
    #include "S32R45_SIUL2.h"
#elif defined(S32G3XX)
    #include "S32G399A_MSCM.h"
    #include "S32G399A_FXOSC.h"
    #include "S32G399A_MC_CGM.h"
    #include "S32G399A_MC_CGM_1.h"
    #include "S32G399A_MC_CGM_2.h"
    #include "S32G399A_SCB.h"
    #include "S32G399A_MPU.h"
    #include "S32G399A_MC_ME.h"
    #include "S32G399A_MC_RGM.h"
    #include "S32G399A_SECURITY.h"
    #include "S32G399A_MDM_AP.h"
    #include "S32G399A_SIUL2.h"
#endif
#include "Mcal.h"
#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
#include "gic500.h"
#else
#include "nvic.h"
#include "core_specific.h"
#endif
#include "system.h"


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CA53_0_0 (0UL)
#define CA53_0_1 (1UL)
#define CA53_1_0 (2UL)
#define CA53_1_1 (3UL)
#define CM7_0    (4UL)
#define CM7_1    (5UL)
#define CM7_2    (6UL)
#define CM7_3    (7UL)

#define SIUL2_MINOR_MASK             (0x0FU)
#define SIUL2_MINOR_SHIFT            (0x0U)
#define SIUL2_MAJOR_MASK             (0xF0U)
#define SIUL2_MAJOR_SHIFT            (0x4U)


#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
#define SVC_GoToSupervisor()
#define SVC_GoToUser()
#else
#define SVC_GoToSupervisor()      ASM_KEYWORD("svc 0x0")
#define SVC_GoToUser()            ASM_KEYWORD("svc 0x1")
#endif

#define S32_SCB_CPACR_CPx_SHIFT(CpNum)            (2U*((uint32)CpNum))
#define S32_SCB_CPACR_CPx_MASK(CpNum)             (0x3U << S32_SCB_CPACR_CPx_SHIFT(CpNum))
#define S32_SCB_CPACR_CPx(CpNum, x)               (((uint32)(((uint32)(x))<<S32_SCB_CPACR_CPx_SHIFT((CpNum))))&S32_SCB_CPACR_CPx_MASK((CpNum)))

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_VAR_CLEARED_32
#include "Platform_MemMap.h"
/* Allocate a global variable which will be overwritten by the debugger if attached(in CMM), to catch the core after reset. */
uint32 RESET_CATCH_CORE;
#define PLATFORM_STOP_SEC_VAR_CLEARED_32
#include "Platform_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/*================================================================================================*/
/*
 * @brief Initializes the caches on the platform based on build options. This requires the MPU areas to be configured and enabled before calling this routine.
 * @param: None
 *
 * @return: None
 */
static INLINE void sys_m7_cache_init(void);
/*
 * @brief Disables any previously configured and initialized cache, please make sure MPU is enabled before calling these apis
 * @param: None
 *
 * @return: None
 */
static INLINE void sys_m7_cache_disable(void);
/*
 * @brief Performs a cache clean operation over the configured caches.
 * @param: None
 *
 * @return: None
 */
static INLINE void sys_m7_cache_clean(void);

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void);
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    extern uint32 startup_getControlRegisterValue(void);
    extern uint32 startup_getAipsRegisterValue(void);
    extern void Suspend_Interrupts(void);
    extern void Resume_Interrupts(void);
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/


/*================================================================================================*/
/**
* @brief    startup_go_to_user_mode
* @details  Function called from startup.s to switch to user mode if MCAL_ENABLE_USER_MODE_SUPPORT
*           is defined
*/
/*================================================================================================*/
void startup_go_to_user_mode(void);
void startup_go_to_user_mode(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    ASM_KEYWORD("svc 0x1");
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/
}

/*================================================================================================*/
/**
* @brief   Default IRQ handler
* @details Infinite Loop
*/
/*================================================================================================*/
void default_interrupt_routine(void)
{
    while(TRUE){};
}

/*================================================================================================*/
/**
* @brief Sys_GoToSupervisor
* @details function used to enter to supervisor mode.
*           check if it's needed to switch to supervisor mode and make the switch.
*           Return 1 if switch was done
*/
/*================================================================================================*/

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
uint32 Sys_GoToSupervisor(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;
    uint32 u32SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        u32SwitchToSupervisor = 0U;
    }
    else
    {
        u32SwitchToSupervisor = 1U;
        SVC_GoToSupervisor();
    }

    return u32SwitchToSupervisor;
}

/*================================================================================================*/
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
/*================================================================================================*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (1UL == u32SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return u32returnValue;
}

uint32 Sys_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

/*================================================================================================*/
/**
* @brief Sys_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
void Sys_SuspendInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x3");
    }
}
/*================================================================================================*/
/**
* @brief Sys_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
void Sys_ResumeInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x2");
    }
}
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/


/*================================================================================================*/
/**
* @brief Sys_GetCoreID
* @details Function used to get the ID of the currently executing thread
*/
/*================================================================================================*/
#if !defined(USING_OS_AUTOSAROS)
uint8 Sys_GetCoreID(void)
{
    return ((uint8)(IP_MSCM->CPXNUM & MSCM_CPXNUM_CPN_MASK));
}
#endif /*!defined(USING_OS_AUTOSAROS)*/

/*================================================================================================*/
/**
* @brief Sys_StartSecondaryCores
* @details Function used to start the secondary cores
*/
/*================================================================================================*/
#if (defined(CORE0) && defined(MULTIPLE_IMAGE))

static void Sys_StartSecondaryCores(void)
{
#ifdef START_CM7_1
    extern const uint32 __CORE1_START_ADDRESS;

    IP_MC_ME->PRTN0_CORE1_ADDR = (uint32)&__CORE1_START_ADDRESS;
    IP_MC_ME->PRTN0_CORE1_PCONF = 1;
    IP_MC_ME->PRTN0_CORE1_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;
    while (!(IP_MC_ME->PRTN0_CORE1_STAT & MC_ME_PRTN0_CORE1_STAT_CCS_MASK)) {};
    IP_MC_RGM->PRST_0[0].PRST_0 &= ~MC_RGM_PRST_0_PERIPH_1_RST(1);
    while(IP_MC_RGM->PSTAT_0[0].PSTAT_0 & MC_RGM_PSTAT_0_PERIPH_1_STAT_MASK);
#endif /*START_CM7_1*/
#ifdef START_CM7_2
    extern const uint32 __CORE2_START_ADDRESS;

    IP_MC_ME->PRTN0_CORE2_ADDR = (uint32)&__CORE2_START_ADDRESS;
    IP_MC_ME->PRTN0_CORE2_PCONF = 1;
    IP_MC_ME->PRTN0_CORE2_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;
    while (!(IP_MC_ME->PRTN0_CORE2_STAT & MC_ME_PRTN0_CORE2_STAT_CCS_MASK)) {};
    IP_MC_RGM->PRST_0[0].PRST_0 &= ~MC_RGM_PRST_0_PERIPH_2_RST(1);
    while(IP_MC_RGM->PSTAT_0[0].PSTAT_0 & MC_RGM_PSTAT_0_PERIPH_2_STAT_MASK);
#endif /*START_CM7_2*/
#ifdef START_CM7_3
    extern const uint32_t __CORE3_START_ADDRESS;

    IP_MC_ME->PRTN0_CORE4_ADDR = (uint32)&__CORE3_START_ADDRESS;
    IP_MC_ME->PRTN0_CORE4_PCONF = 1;
    IP_MC_ME->PRTN0_CORE4_PUPD = 1;
    IP_MC_ME->CTL_KEY = 0x5AF0;
    IP_MC_ME->CTL_KEY = 0xA50F;
    while (!(IP_MC_ME->PRTN0_CORE4_STAT & MC_ME_PRTN0_CORE4_STAT_CCS_MASK)) {};
    IP_MC_RGM->PRST_0[0].PRST_0 &= ~MC_RGM_PRST_0_PERIPH_6_RST(1);
    while(IP_MC_RGM->PSTAT_0[0].PSTAT_0 & MC_RGM_PSTAT_0_PERIPH_6_STAT_MASK);
#endif /*START_CM7_3*/
}
#endif /*(defined(CORE0) && defined(MULTIPLE_IMAGE))*/

/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */

void SystemInit(void)
{
    uint32 i;
    uint32 coreMask;
#ifdef MPU_ENABLE
    uint8 regionNum = 0U;
#endif

    uint32 coreId = OsIf_GetCoreID();

    switch(coreId)
    {
        case CA53_0_0:
            /* There is only one bitfield for all Cortex A53 interrupt steering. Fall trough */
        case CA53_0_1:
            /* There is only one bitfield for all Cortex A53 interrupt steering. Fall trough */
        case CA53_1_0:
            /* There is only one bitfield for all Cortex A53 interrupt steering. Fall trough */
        case CA53_1_1:
            coreMask = (1UL << MSCM_IRSPRC_GIC500_SHIFT);
            break;
        case CM7_0:
            coreMask = (1UL << MSCM_IRSPRC_M7_0_SHIFT);
            break;
        case CM7_1:
            coreMask = (1UL << MSCM_IRSPRC_M7_1_SHIFT);
            break;
        case CM7_2:
            coreMask = (1UL << MSCM_IRSPRC_M7_2_SHIFT);
            break;
#if defined(S32G3XX)
        case CM7_3:
            coreMask = (1UL << MSCM_IRSPRC_M7_3_SHIFT);
            break;
#endif
        default:
            coreMask = 0UL;
            break;
    }

    /* Configure IP_MSCM to enable/disable interrupts routing to Core processor */
    for (i = 0; i < MSCM_IRSPRC_COUNT; i++)
    {
        IP_MSCM->IRSPRC[i] |= coreMask;
    }

#if (defined(CORE0) && defined(MULTIPLE_IMAGE))
    Sys_StartSecondaryCores();
#endif

#if (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)

    gic500_enableGIC();

    /* fill the interrupts_vector with the default interrupt rutine */
    for (i=0; i<A53_NUM_OF_VECTORS; i++)
    {
        g_INT_vectors[i] = (isr_t)default_interrupt_routine;
    }

#else

  NVIC_SetPriorityGrouping(0); /* 0 means 7 bits for prio, 1 for sub-prio */
  S32_SCB->CCR |=  1;          /* processor can enter Thread mode from any level under the
                                   control of an EXC_RETURN value, PendSV priority set to 0 */
  S32_SCB->SHPR3 = 0;

/**************************************************************************/
                      /* FPU ENABLE*/
/**************************************************************************/
#ifdef ENABLE_FPU
    /* Enable CP10 and CP11 coprocessors */
    S32_SCB->CPACR |= (S32_SCB_CPACR_CPx(10U, 3U) | S32_SCB_CPACR_CPx(11U, 3U));

    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();

#endif /*ENABLE_FPU*/

/**************************************************************************/
                      /* DEFAULT MEMORY ENABLE*/
/**************************************************************************/
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
/**************************************************************************/
                      /* MPU ENABLE*/
/**************************************************************************/
#ifdef MPU_ENABLE
    /*Checking if cache is enable before*/
    if (((((uint32)1U << (uint32)17U) & S32_SCB->CCR) != (uint32)0) || ((((uint32)1U << (uint32)16U) & S32_SCB->CCR) != (uint32)0))
    {
        /* synchronize cache before update mpu */
        sys_m7_cache_disable();
    }
    /* Set default memory regions */
    for (regionNum = 0U; regionNum < CPU_MPU_MEMORY_COUNT; regionNum++)
    {
        S32_MPU->RNR  = regionNum;
        S32_MPU->RBAR = rbar[regionNum];
        S32_MPU->RASR = rasr[regionNum];
    }

    /* Enable MPU */
    S32_MPU->CTRL |= S32_MPU_CTRL_ENABLE_MASK;
    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
#endif /*MPU_ENABLE*/

/**************************************************************************/
            /* ENABLE CACHE */
/**************************************************************************/
#if defined(D_CACHE_ENABLE) || defined(I_CACHE_ENABLE)
    sys_m7_cache_init();
#endif /*defined(D_CACHE_ENABLE) || defined(I_CACHE_ENABLE)*/
/*
 * SystemWfiConfig : Implement errata ERR051149
 */
#if defined(ERR_CORTEX_M7_E051149) || defined(ERR_CORTEX_M7_E051166)
    SystemWfiConfig();
#endif

#endif /*(MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)*/

}
   
static void sys_m7_cache_init(void)
{
#ifdef D_CACHE_ENABLE
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    /*init Data caches*/
    S32_SCB->CSSELR = 0U;                       /* select Level 1 data cache */

    MCAL_DATA_SYNC_BARRIER();
    ccsidr = S32_SCB->CCSIDR;
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do {
      ways = (uint32)(CCSIDR_WAYS(ccsidr));
      do {
        S32_SCB->DCISW = (((sets << SCB_DCISW_SET_SHIFT) & SCB_DCISW_SET_MASK) |
                      ((ways << SCB_DCISW_WAY_SHIFT) & SCB_DCISW_WAY_MASK)  );

    MCAL_DATA_SYNC_BARRIER();
      } while (ways-- != 0U);
    } while(sets-- != 0U);
    MCAL_DATA_SYNC_BARRIER();
    S32_SCB->CCR |=  (uint32)SCB_CCR_DC_MASK;  /* enable D-Cache */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
#endif /*D_CACHE_ENABLE*/

#ifdef I_CACHE_ENABLE
    /*init Code caches*/
    S32_SCB->ICIALLU = 0UL;                    /* invalidate I-Cache */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    S32_SCB->CCR |=  (uint32)SCB_CCR_IC_MASK;  /* enable I-Cache */
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
#endif /*I_CACHE_ENABLE*/
}

static INLINE void sys_m7_cache_disable(void)
{
    sys_m7_cache_clean();
    S32_SCB->CCR &= ~((uint32)1U << 17U);
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
    S32_SCB->CCR &= ~((uint32)1U << 16U);
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
}

static INLINE void sys_m7_cache_clean(void)
{
#ifdef D_CACHE_ENABLE
    uint32 ccsidr = 0U;
    uint32 sets = 0U;
    uint32 ways = 0U;

    S32_SCB->CSSELR = 0U;                       /* select Level 1 data cache */
    MCAL_DATA_SYNC_BARRIER();
    ccsidr = S32_SCB->CCSIDR;
    sets = (uint32)(CCSIDR_SETS(ccsidr));
    do {
      ways = (uint32)(CCSIDR_WAYS(ccsidr));
      do {
        S32_SCB->DCCISW = (((sets << SCB_DCCISW_SET_SHIFT) & (uint32)SCB_DCCISW_SET_MASK) |
                      ((ways << SCB_DCCISW_WAY_SHIFT) & (uint32)SCB_DCCISW_WAY_MASK)  );
        MCAL_DATA_SYNC_BARRIER();
      } while (ways-- != 0U);
    } while(sets-- != 0U);
    MCAL_DATA_SYNC_BARRIER();
    S32_SCB->CSSELR = (uint32)((S32_SCB->CSSELR) | 1U);
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
#endif /*D_CACHE_ENABLE*/

#ifdef I_CACHE_ENABLE
    S32_SCB->ICIALLU = 0UL;
    MCAL_DATA_SYNC_BARRIER();
    MCAL_INSTRUCTION_SYNC_BARRIER();
#endif /*I_CACHE_ENABLE*/
}
/*================================================================================================*/
/*
 * SystemWfiConfig : Implement errata ERR051149
 * SystemWfiConfig : Implement errata ERR051166
 */
#if defined(ERR_CORTEX_M7_E051149) || defined(ERR_CORTEX_M7_E051166)
void SystemWfiConfig(void)
{
    uint32 u32EdbStatus = 0U;
#ifdef S32G3XX
/*  Major Mask Revision
    0000b - Rev 1.x
    0001b - Rev 2.x
    Minor Mask Revision
    0000b - Rev x.0
    0001b - Rev x.1 */
    uint32 U32MajorMinor = (uint32_t)(IP_SIUL2_0->MIDR1);
    uint8 Minor = (uint8)((U32MajorMinor & SIUL2_MINOR_MASK) >> SIUL2_MINOR_SHIFT);
    uint8 Major = (uint8)((U32MajorMinor & SIUL2_MAJOR_MASK) >> SIUL2_MAJOR_SHIFT);
    if (Major == 0U && Minor == 0U)
    {
#endif
        u32EdbStatus = (uint32_t)(IP_SECURITY_CC->EXT_DBGSTAT & SECURITY_EXT_DBGSTAT_EDB_MASK);
        if (u32EdbStatus == 0U)
        {
            IP_MDM_AP->DAP_EN_CTRL &= ~MDM_AP_DAP_EN_CTRL_CSPNIDEN_MASK;
            IP_MDM_AP->DAP_EN_CTRL &= ~MDM_AP_DAP_EN_CTRL_CSPIDEN_MASK;
            IP_MDM_AP->DAP_EN_CTRL &= ~MDM_AP_DAP_EN_CTRL_CNIDEN_MASK;
            IP_MDM_AP->DAP_EN_CTRL &= ~MDM_AP_DAP_EN_CTRL_CDBGEN_MASK;
            IP_MDM_AP->CONTROL |= MDM_AP_CONTROL_CM7_0_EDBGREQ_MASK;
            IP_MDM_AP->CONTROL |= MDM_AP_CONTROL_CM7_1_EDBGREQ_MASK;
            IP_MDM_AP->CONTROL |= MDM_AP_CONTROL_CM7_2_EDBGREQ_MASK;
#ifdef S32G3XX
#if defined(ERR_CORTEX_M7_E051166)
            IP_MDM_AP->CORTEX_A53_A0_IP_DBG |= MDM_AP_CORTEX_A53_A0_IP_DBG_CM7_3_EDBGREQ_MASK;
#endif
#endif
        }
        else
        {
            /* do nothing */
        }
#ifdef S32G3XX
    }
    else
    {
        /* do nothing */
    }
#endif
}
#endif

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif /*__cplusplus */
