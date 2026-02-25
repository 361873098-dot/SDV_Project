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
*   @file       Clock_Ip_Specific.c
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
#define CLOCK_IP_SPECIFIC_VENDOR_ID_C                      43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C               0
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Specific.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Specific.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.c and RegLockMacros.h are different"
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

#define DFS_DVPORT      (DFS_DVPORT_MFN(0u) | DFS_DVPORT_MFI(1U))
#define DFS_PORT_RESET  (DFS_PORTRESET_RESET0_MASK | DFS_PORTRESET_RESET1_MASK | DFS_PORTRESET_RESET2_MASK | DFS_PORTRESET_RESET3_MASK | DFS_PORTRESET_RESET4_MASK | DFS_PORTRESET_RESET5_MASK)


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
/* Power clock ip modules */
static void Clock_Ip_PowerClockIpModules(void)
{
    uint32 TempValue = 0U;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;
    uint32 ResetDomainStatus;

    /* The CMU_FC_27/CMU_FC_28 are accessible only after enabling Partition 1 through MC_ME. */
    /* CMUs are not powered */
    if (0U == (IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_PCS_MASK))
    {
        /* Power CMU devices */
        IP_MC_ME->PRTN1_PCONF       |= MC_ME_PRTN1_PCONF_PCE_MASK;          /* PCE=1: Enable the clock to Partition #1 */
        IP_MC_ME->PRTN1_PUPD        |= MC_ME_PRTN1_PUPD_PCUD_MASK;          /* PCUD=1: Trigger the hardware process */
        Clock_Ip_McMeEnterKey();
        /* Wait until CMU clock is running */
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while((0U == (IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_PCS_MASK)) && (FALSE == TimeoutOccurred));
        /* timeout notification */
        if (TRUE == TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, RESERVED_CLK);
        }
    }

    /* Unlock the access to the register by setting RDC_RDn_CTRL_REG[CTRL_UNLOCK]. */
    TempValue = IP_RDC->RD1_CTRL_REG;
    TempValue &= ~RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK;
    TempValue |= RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK;
    IP_RDC->RD1_CTRL_REG = TempValue;

    /* Write 0 the new configuration for RDC_RDn_CTRL_REG[ICON_INTF_DIS_REQ_ACK]. */
    TempValue = IP_RDC->RD1_CTRL_REG;
    TempValue &= ~RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK;
    IP_RDC->RD1_CTRL_REG = TempValue;

    /* Wait until the update has finished. */
    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    do
    {
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);

        ResetDomainStatus = ((IP_RDC->RD1_STAT_REG) & RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_MASK) >> RESET_RD1_CTRL_REG_RD1_INTERCONNECT_INTERFACE_DISABLE_SHIFT;
    } while ( (ResetDomainStatus != 0U) && (!TimeoutOccurred) );
    /* timeout notification */
    if(TimeoutOccurred)
    {
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, RESERVED_CLK);
    }

    /* Lock the access to the register by clearing RDC_RDn_CTRL_REG[CTRL_UNLOCK]. */
    TempValue = IP_RDC->RD1_CTRL_REG;
    TempValue &= ~RESET_RD1_CTRL_REG_RD1_CTRL_UNLOCK_MASK;
    IP_RDC->RD1_CTRL_REG = TempValue;

    /* Get the domain out of reset */
    IP_MC_RGM->PRST_0[1U].PRST_0 &= ~((uint32)(MC_RGM_PRST_0_PERIPH_0_RST_MASK));


    if (0U != (IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_OSSS_MASK))
    {
        /*  Write the new configuration for PRTNx_PCONF[OSSE]. */
        TempValue   = IP_MC_ME->PRTN1_PCONF;
        TempValue  &= ~MC_ME_PRTN1_PCONF_OSSE_MASK;
        IP_MC_ME->PRTN1_PCONF = TempValue;

        TempValue        = IP_MC_ME->PRTN1_PUPD;
        TempValue       &= ~MC_ME_PRTN1_PUPD_OSSUD_MASK;
        TempValue       |= MC_ME_PRTN1_PUPD_OSSUD_MASK;
        IP_MC_ME->PRTN1_PUPD  = TempValue;

        Clock_Ip_McMeEnterKey();
        /* Wait until CMU clock is running */
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        do
        {
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while((0U != (IP_MC_ME->PRTN1_STAT & MC_ME_PRTN1_STAT_OSSS_MASK)) && (FALSE == TimeoutOccurred));
        /* timeout notification */
        if (TRUE == TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, RESERVED_CLK);
        }
    }
}
/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_HAS_FLASH_WAIT_STATES
/* Clock start ram section code */
#define MCU_START_SEC_RAMCODE
#include "Mcu_MemMap.h"

static void CodeInRam_SetFlashWaitStates(void);

/* Clock start ram section code */
#define MCU_STOP_SEC_RAMCODE
#include "Mcu_MemMap.h"

#endif /* CLOCK_IP_HAS_FLASH_WAIT_STATES */




/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES

void SRAMC_SetRamIWS(void);

/* Function set ram wait states */
void Clock_Ip_SetRamWaitStates(void)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(SRAMC_SetRamIWS);
  #else
    SRAMC_SetRamIWS();
  #endif
#else
  SRAMC_SetRamIWS();
#endif
}
#endif

#ifdef CLOCK_IP_HAS_FLASH_WAIT_STATES
void SetFlashWaitStates(void)
{
    FLASH_SetFlashIWS();
}
#endif

void Clock_Ip_McMeEnterKey(void)
{
    IP_MC_ME->CTL_KEY = 0x5AF0U;                                         /* Enter key */

    IP_MC_ME->CTL_KEY = 0xA50FU;
}

/* Configure the specific modules like eMios */
void Clock_Ip_SpecificPeripheralClockInitialization(Clock_IP_SpecificPeriphConfigType const * Config)
{
    (void)Config;
}
void Clock_Ip_SpecificPlatformInitClock(Clock_Ip_ClockConfigType const * Config)
{
    uint32 CoreDfsIsInReset = IP_CORE_DFS->CTL & DFS_CTL_DFS_RESET_MASK;            /* if master core dfs is in reset */
    uint32 PeriphDfsIsInReset = IP_PERIPH_DFS->CTL & DFS_CTL_DFS_RESET_MASK;        /* if master periph dfs is in reset */
    uint32 RegValue;
    (void)Config;

    /* Power clock ip modules.
     * On some platforms clock ip modules cannot be configured,
     * registers cannot be access until device is powered.
     * Check and power if it is required clock ip modules.
     */
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Clock_Ip_PowerClockIpModules);
#else
    Clock_Ip_PowerClockIpModules();
#endif
#else
    Clock_Ip_PowerClockIpModules();
#endif

    if ((CoreDfsIsInReset != 0U) && (PeriphDfsIsInReset != 0U))
    {
        if ((IP_CORE_PLL->PLLCR & PLLDIG_PLLCR_PLLPD_MASK) != 0U)   /* if CORE_PLL is not enabled */
        {
            IP_CORE_PLL->PLLCLKMUX = 0U;                                                   /* FIRC input reference 48 MHz */
            RegValue = IP_CORE_PLL->PLLDV;
            RegValue &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            IP_CORE_PLL->PLLDV = (RegValue | (PLLDIG_PLLDV_RDIV(1U) | PLLDIG_PLLDV_MFI(30U)));          /* /1 * 30 */
            IP_CORE_PLL->PLLFD &= ~(PLLDIG_PLLFD_MFN_MASK | PLLDIG_PLLFD_SDMEN_MASK);      /* Disable modulation */
            IP_CORE_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;                                /* Start CORE_PLL */
        }

        if ((IP_PERIPH_PLL->PLLCR & PLLDIG_PLLCR_PLLPD_MASK) != 0U)   /* if PERIPH_PLL is not enabled */
        {
            IP_PERIPH_PLL->PLLCLKMUX = 0U;                                                   /* FIRC input reference 48 MHz */
            RegValue = IP_PERIPH_PLL->PLLDV;
            RegValue &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            IP_PERIPH_PLL->PLLDV = (RegValue | (PLLDIG_PLLDV_RDIV(1U) | PLLDIG_PLLDV_MFI(30U)));          /* /1 * 30 */
            IP_PERIPH_PLL->PLLFD &= ~(PLLDIG_PLLFD_MFN_MASK | PLLDIG_PLLFD_SDMEN_MASK);      /* Disable modulation */
            IP_PERIPH_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;                                /* Start PERIPH_PLL */
        }

        IP_CORE_DFS->PORTRESET |= DFS_PORT_RESET;
        IP_CORE_DFS->DVPORT[0U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[1U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[2U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[3U] = DFS_DVPORT; 
        IP_CORE_DFS->DVPORT[4U] = DFS_DVPORT; 
        IP_CORE_DFS->DVPORT[5U] = DFS_DVPORT;
        IP_CORE_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;

        IP_PERIPH_DFS->PORTRESET |= DFS_PORT_RESET;
        IP_PERIPH_DFS->DVPORT[0U] = DFS_DVPORT; 
        IP_PERIPH_DFS->DVPORT[1U] = DFS_DVPORT; 
        IP_PERIPH_DFS->DVPORT[2U] = DFS_DVPORT; 
        IP_PERIPH_DFS->DVPORT[3U] = DFS_DVPORT; 
        IP_PERIPH_DFS->DVPORT[4U] = DFS_DVPORT; 
        IP_PERIPH_DFS->DVPORT[5U] = DFS_DVPORT;
        IP_PERIPH_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    }
    else if (CoreDfsIsInReset != 0U)
    {
        if ((IP_CORE_PLL->PLLCR & PLLDIG_PLLCR_PLLPD_MASK) != 0U)   /* if CORE_PLL is not enabled */
        {
            IP_CORE_PLL->PLLCLKMUX = 0U;                                                   /* FIRC input reference 48 MHz */
            RegValue = IP_CORE_PLL->PLLDV;
            RegValue &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            IP_CORE_PLL->PLLDV = (RegValue | (PLLDIG_PLLDV_RDIV(1U) | PLLDIG_PLLDV_MFI(30U)));          /* /1 * 30 */
            IP_CORE_PLL->PLLFD &= ~(PLLDIG_PLLFD_MFN_MASK | PLLDIG_PLLFD_SDMEN_MASK);      /* Disable modulation */
            IP_CORE_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;                                /* Start CORE_PLL */
        }

        IP_CORE_DFS->PORTRESET |= DFS_PORT_RESET;
        IP_CORE_DFS->DVPORT[0U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[1U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[2U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[3U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[4U] = DFS_DVPORT;
        IP_CORE_DFS->DVPORT[5U] = DFS_DVPORT;
        IP_CORE_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    }
    else if (PeriphDfsIsInReset != 0U)
    {
        if ((IP_PERIPH_PLL->PLLCR & PLLDIG_PLLCR_PLLPD_MASK) != 0U)   /* if PERIPH_PLL is not enabled */
        {
            IP_PERIPH_PLL->PLLCLKMUX = 0U;                                                   /* FIRC input reference 48 MHz */
            RegValue = IP_PERIPH_PLL->PLLDV;
            RegValue &= ~(PLLDIG_PLLDV_RDIV_MASK | PLLDIG_PLLDV_MFI_MASK);
            IP_PERIPH_PLL->PLLDV = (RegValue | (PLLDIG_PLLDV_RDIV(1U) | PLLDIG_PLLDV_MFI(30U)));          /* /1 * 30 */
            IP_PERIPH_PLL->PLLFD &= ~(PLLDIG_PLLFD_MFN_MASK | PLLDIG_PLLFD_SDMEN_MASK);      /* Disable modulation */
            IP_PERIPH_PLL->PLLCR &= ~PLLDIG_PLLCR_PLLPD_MASK;                                /* Start PERIPH_PLL */
        }

        IP_PERIPH_DFS->PORTRESET |= DFS_PORT_RESET;
        IP_PERIPH_DFS->DVPORT[0U] = DFS_DVPORT;
        IP_PERIPH_DFS->DVPORT[1U] = DFS_DVPORT;
        IP_PERIPH_DFS->DVPORT[2U] = DFS_DVPORT;
        IP_PERIPH_DFS->DVPORT[3U] = DFS_DVPORT;
        IP_PERIPH_DFS->DVPORT[4U] = DFS_DVPORT;
        IP_PERIPH_DFS->DVPORT[5U] = DFS_DVPORT;
        IP_PERIPH_DFS->CTL &= ~DFS_CTL_DFS_RESET_MASK;
    }
    else
    {
        /* periph Dfs and core Dfs are not in reset */
    }
}

/* Initialize objects for clock */
void Clock_Ip_ClockInitializeObjects(void)
{
    /* No object to be initialized on this platform */
}

/* Be called after Power mode had changed */
void Clock_Ip_ClockPowerModeChangeNotification(Clock_Ip_PowerModesType PowerMode, Clock_Ip_PowerNotificationType Notification)
{
    (void)PowerMode;
    (void)Notification;
}

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
void Clock_Ip_SpecificSetUserAccessAllowed(void)
{
    /* PLLDIG SetUserAccessAllowed */
#if (defined(MCAL_PLLDIG_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_PLLDIG_REG_PROT_AVAILABLE)
    #if (defined(IP_CORE_PLL_BASE))
    SET_USER_ACCESS_ALLOWED(IP_CORE_PLL_BASE, PLLDIG_PROT_MEM_U32);
    #endif
    #if (defined(IP_PERIPH_PLL_BASE))
    SET_USER_ACCESS_ALLOWED(IP_PERIPH_PLL_BASE, PLLDIG_PROT_MEM_U32);
    #endif
    #if (defined(IP_ACCEL_PLL_BASE))
    SET_USER_ACCESS_ALLOWED(IP_ACCEL_PLL_BASE, PLLDIG_PROT_MEM_U32);
    #endif
    #if (defined(IP_DDR_PLL_BASE))
    SET_USER_ACCESS_ALLOWED(IP_DDR_PLL_BASE, PLLDIG_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_PLLDIG_REG_PROT_AVAILABLE */

    /* DFS SetUserAccessAllowed */
#if (defined(MCAL_DFS_REG_PROT_AVAILABLE))
  #if(STD_ON == MCAL_DFS_REG_PROT_AVAILABLE)
    #if (defined(IP_CORE_DFS_BASE))
    SET_USER_ACCESS_ALLOWED(IP_CORE_DFS_BASE, DFS_PROT_MEM_U32);
    #endif
    #if (defined(IP_PERIPH_DFS_BASE))
    SET_USER_ACCESS_ALLOWED(IP_PERIPH_DFS_BASE, DFS_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_DFS_REG_PROT_AVAILABLE */

    /* FXOSC SetUserAccessAllowed */
#if (defined(MCAL_FXOSC_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_FXOSC_REG_PROT_AVAILABLE)
    #if (defined(IP_FXOSC_BASE))
    SET_USER_ACCESS_ALLOWED(IP_FXOSC_BASE, FXOSC_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_FXOSC_REG_PROT_AVAILABLE */

    /* MC_CGM SetUserAccessAllowed */
#if (defined(MCAL_MC_CGM_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_MC_CGM_REG_PROT_AVAILABLE)
    #if (defined(IP_MC_CGM_0_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_CGM_0_BASE, MC_CGM_PROT_MEM_U32);
    #endif
    #if (defined(IP_MC_CGM_1_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_CGM_1_BASE, MC_CGM_PROT_MEM_U32);
    #endif
    #if (defined(IP_MC_CGM_2_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_CGM_2_BASE, MC_CGM_PROT_MEM_U32);
    #endif
    #if (defined(IP_MC_CGM_5_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_CGM_5_BASE, MC_CGM_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_MC_CGM_REG_PROT_AVAILABLE */

    /* CMU SetUserAccessAllowed */
#if (defined(MCAL_CMU_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_CMU_REG_PROT_AVAILABLE)
    #if (defined(IP_CMU_FC_0_BASE))
    SET_USER_ACCESS_ALLOWED(IP_CMU_FC_0_BASE, CMU_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_CMU_REG_PROT_AVAILABLE */

/* SRAM SetUserAccessAllowed */
#if (defined(MCAL_SRAMC_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_SRAMC_REG_PROT_AVAILABLE)
    #if (defined(IP_SRAMC_BASE))
    SET_USER_ACCESS_ALLOWED(IP_SRAMC_BASE, SRAMC_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_SRAMC_REG_PROT_AVAILABLE */

/* MC_ME SetUserAccessAllowed */
#if (defined(MCAL_MC_ME_REG_PROT_AVAILABLE ))
  #if (STD_ON == MCAL_MC_ME_REG_PROT_AVAILABLE )
    #if (defined(IP_MC_ME_BASE))
        SET_USER_ACCESS_ALLOWED(IP_MC_ME_BASE, MC_ME_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_MC_ME_REG_PROT_AVAILABLE  */

/* MC_RGM SetUserAccessAllowed */
#if (defined(MCAL_MC_RGM_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_MC_RGM_REG_PROT_AVAILABLE)
    #if (defined(IP_MC_RGM_BASE))
    SET_USER_ACCESS_ALLOWED(IP_MC_RGM_BASE, MC_RGM_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_MC_RGM_REG_PROT_AVAILABLE */

/* RDC SetUserAccessAllowed */
#if (defined(MCAL_RDC_REG_PROT_AVAILABLE))
  #if (STD_ON == MCAL_RDC_REG_PROT_AVAILABLE)
    #if (defined(IP_RDC_BASE))
    SET_USER_ACCESS_ALLOWED(IP_RDC_BASE, RDC_PROT_MEM_U32);
    #endif
  #endif
#endif /* MCAL_RDC_REG_PROT_AVAILABLE */
}
#endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */



/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES


/* Clock start rom section code */
#define MCU_START_SEC_CODE_AC
#include "Mcu_MemMap.h"

/* Set Ram IWS */
void SRAMC_SetRamIWS(void)
{
    uint32 IwsSetting = 0U;
    uint32 ConfiguredCoreClock = 0U;
    
#if defined(CLOCK_IP_HAS_XBAR_CLK)
    ConfiguredCoreClock = Clock_Ip_GetConfiguredFrequencyValue(XBAR_CLK);
#endif        

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
    CLOCK_IP_DEV_ASSERT(ConfiguredCoreClock != 0U);
#endif

    if (ConfiguredCoreClock <= 200000000U)
    {
        if (ConfiguredCoreClock <= 100000000U)
        {
            IwsSetting = 0U;
        }
        else
        {
            IwsSetting = 1U;
        }
    }
    else
    {
        if (ConfiguredCoreClock <= 300000000U)
        {
            IwsSetting = 2U;
        }
        else
        {
            IwsSetting = 3U;
        }
    }

    IP_SRAMC->PRAMCR   = (IP_SRAMC->PRAMCR & ~SRAMC_PRAMCR_IWS_MASK)   | SRAMC_PRAMCR_IWS(IwsSetting);
    IP_SRAMC_1->PRAMCR = (IP_SRAMC_1->PRAMCR & ~SRAMC_PRAMCR_IWS_MASK) | SRAMC_PRAMCR_IWS(IwsSetting);
}

/* Clock stop rom section code */
#define MCU_STOP_SEC_CODE_AC
#include "Mcu_MemMap.h"
#endif

#ifdef CLOCK_IP_HAS_FLASH_WAIT_STATES




/* Clock start ram section code */
#define MCU_START_SEC_RAMCODE
#include "Mcu_MemMap.h"

void CodeInRam_SetFlashWaitStates(void)
{
}

/* Clock stop ram section code */
#define MCU_STOP_SEC_RAMCODE
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

typedef void (*SetFlashWaitStatesCallbackType)(void);
SetFlashWaitStatesCallbackType Clock_Ip_pfSetFlashWaitStatesCallback = CodeInRam_SetFlashWaitStates;   /* Set Flash Wait States callback */


/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

void FLASH_SetFlashIWS(void)
{
    Clock_Ip_pfSetFlashWaitStatesCallback();
}


/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif

#endif /* (CLOCK_IP_PLATFORM_SPECIFIC) */

#ifdef __cplusplus
}
#endif

/** @} */

