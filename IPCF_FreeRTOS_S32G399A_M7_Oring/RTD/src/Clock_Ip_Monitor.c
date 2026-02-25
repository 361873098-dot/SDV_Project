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
*   @file       Clock_Ip_Monitor.c
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
#include "SchM_Mcu.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_MONITOR_VENDOR_ID_C                      43
#define CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_MONITOR_SW_MINOR_VERSION_C               0
#define CLOCK_IP_MONITOR_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_MONITOR_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Monitor.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Monitor.c file and SchM_Mcu.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCU_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != SCHM_MCU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and SchM_Mcu.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
#define CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE            80U
#define CLOCK_IP_CMU_FC_VAR                                     3U
#define CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION                  33U
#define CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION                  11U
#define CLOCK_IP_DIVIDE_BY_1000                                 1000U

#if defined(CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1)
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1
#else
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 1U
#endif

#if defined(CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1)
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1
#else
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 3U
#endif

#if defined(CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2)
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2
#else
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 9U
#endif

#if defined(CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2)
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2
#else
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 5U
#endif

#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

static uint32 HashCmu[CLOCK_IP_CMU_INFO_SIZE];

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

/*  TODO ARTD-738  Implement CMU in Clock_Ip driver    */

static void Clock_Ip_ClockMonitorEmpty(Clock_Ip_CmuConfigType const* Config);
static void Clock_Ip_ClockMonitorEmpty_Disable(Clock_Ip_NameType Name);

#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config);
static void Clock_Ip_SetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config);
static void Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name);
static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config);
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_ClockMonitorEmpty(Clock_Ip_CmuConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}

static void Clock_Ip_ClockMonitorEmpty_Disable(Clock_Ip_NameType Name)
{
    (void)Name;
    /* No implementation */
}


#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
static void Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name)
{
    const Clock_Ip_CmuInfoType * CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Name][CLOCK_IP_CMU_INDEX]];
    Clock_Ip_ClockMonitorType* const CmuFc    = CmuInformation->CmuInstance;

    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 FrequencyCheckStatus;

#if (defined (CLOCK_IP_S32K118) || defined(CLOCK_IP_S32K116))
    if(0U == ((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT))
    {
        /* Enable clock gate for CMU0 device */
        IP_PCC->PCCn[62] |= PCC_PCCn_CGC_MASK;
    }
    if(0U == ((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT))
    {
        /* Enable clock gate for CMU1 device */
        IP_PCC->PCCn[63] |= PCC_PCCn_CGC_MASK;
    }
#endif

    /* Enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01();
    /* Only disable frequency check if it is enabled */
    if (CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED == (CmuFc->GCR & CMU_FC_GCR_FCE_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait for frequency check to be running. */
        do
        {
            FrequencyCheckStatus = (CmuFc->SR & CMU_FC_SR_RS_MASK);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while((CLOCK_IP_CMU_FREQUENCY_CHECK_STOPPED == FrequencyCheckStatus) && (!TimeoutOccurred));

        /* timeout notification */
        if (TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Name);
        }
        else
        {
            /* Disable frequency check */
            CmuFc->GCR &= ~CMU_FC_GCR_FCE_MASK;

            /* Disable interupts */
            CmuFc->IER &= ~(CMU_FC_IER_FLLIE_MASK | CMU_FC_IER_FHHIE_MASK | CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FHHAIE_MASK);

            /* Clear flags */
            CmuFc->SR |= (CMU_FC_SR_FLL_MASK | CMU_FC_SR_FHH_MASK);
        }
    }
    else
    {
        /* Disable interupts */
        CmuFc->IER &= ~(CMU_FC_IER_FLLIE_MASK | CMU_FC_IER_FHHIE_MASK | CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FHHAIE_MASK);

        /* Clear flags */
        CmuFc->SR |= (CMU_FC_SR_FLL_MASK | CMU_FC_SR_FHH_MASK);
    }

    /* Exit critical region. */
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01();
}

/* Reset CMU register */
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
        Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Config->Name);
    }
}

static void Clock_Ip_SetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config)
{
    const Clock_Ip_CmuInfoType * CmuInformation;
    Clock_Ip_ClockMonitorType* CmuFc;

    uint32 ReferenceClk = 0U;
    uint32 MonitoredClk = 0U;
    uint32 BusClk = 0U;
    uint32 RefCount = 0U;
    uint32 HfRef = 0U;
    uint32 LfRef = 0U;
    uint32 Cmp1;
    uint32 Cmp2;
    uint32 DivideBy;
    uint32 DividerResult;
    uint32 ModuloValue;

    if (NULL_PTR != Config)
    {
        CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]];
        CmuFc    = CmuInformation->CmuInstance;

        /* Do not calculate cmu values if these values are already calculated and written in hw registers */
        if (HashCmu[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]] != ((((uint32)Config->Enable) ^ ((uint32)Config->Interrupt) ^ ((uint32)Config->MonitoredClockFrequency)  ^ ((uint32)Config->Name))))
        {
            HashCmu[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]] = ((((uint32)Config->Enable) ^ ((uint32)Config->Interrupt) ^ ((uint32)Config->MonitoredClockFrequency)  ^ ((uint32)Config->Name)));

            switch(CmuInformation->Reference)
            {
        #if defined(CLOCK_IP_HAS_FIRC_CLK)
                case FIRC_CLK:
                {
                    ReferenceClk = Clock_Ip_GetConfiguredFrequencyValue(FIRC_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_FXOSC_CLK)
                case FXOSC_CLK:
                {
                    ReferenceClk = Clock_Ip_GetConfiguredFrequencyValue(FXOSC_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_SIRC_CLK)
                case SIRC_CLK:
                {
                    ReferenceClk = Clock_Ip_GetConfiguredFrequencyValue(SIRC_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
                default:
                    ReferenceClk = 0U;
                    break;
            }

            MonitoredClk = Config->MonitoredClockFrequency / CLOCK_IP_DIVIDE_BY_1000;

            switch(CmuInformation->Bus)
            {
        #if defined(CLOCK_IP_HAS_XBAR_DIV3_CLK)
                case XBAR_DIV3_CLK:
                {
                    BusClk = Clock_Ip_GetConfiguredFrequencyValue(XBAR_DIV3_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_XBAR_DIV6_CLK)
                case XBAR_DIV6_CLK:
                {
                    BusClk = Clock_Ip_GetConfiguredFrequencyValue(XBAR_DIV3_CLK) / 2U / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_AIPS_SLOW_CLK)
                case AIPS_SLOW_CLK:
                {
                    BusClk = Clock_Ip_GetConfiguredFrequencyValue(AIPS_SLOW_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_SYS_DIV8_CLK)
                case SYS_DIV8_CLK:
                {
                    BusClk = Clock_Ip_GetConfiguredFrequencyValue(SYS_DIV8_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    break;
                }
        #endif
        #if defined(CLOCK_IP_HAS_BUS_CLK)
                case BUS_CLK:
                {
                    if(1U == (IP_SMC->PMSTAT & SMC_PMSTAT_PMSTAT_MASK))
                    {
                        BusClk = Clock_Ip_GetConfiguredFrequencyValue(BUS_RUN_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    }
                    else
                    {
                        BusClk = Clock_Ip_GetConfiguredFrequencyValue(BUS_VLPR_CLK) / CLOCK_IP_DIVIDE_BY_1000;
                    }
                    break;
                }
        #endif
                default:
                    BusClk = 0U;
                    break;
            }
    #if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
            CLOCK_IP_DEV_ASSERT(ReferenceClk != 0U);
            CLOCK_IP_DEV_ASSERT(BusClk != 0U);
            CLOCK_IP_DEV_ASSERT(MonitoredClk != 0U);
    #endif
            /* Avoid divide by zero */
            if ((ReferenceClk != 0U) && (BusClk != 0U) && (MonitoredClk != 0U))
            {
                /* Cmp1 = ceiling of (3 * fRef/ fBus) */
                Cmp1 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 * ReferenceClk) / BusClk);
                /* Cmp2 = ceiling of (8 + (5 * fRef / fMonitor)) */
                Cmp2 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 * ReferenceClk) / MonitoredClk);

                /* REF count = Max(cmp1,cmp2) */
                RefCount = (Cmp1 > Cmp2) ? Cmp1 : Cmp2;
                RefCount = (CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE > RefCount) ? CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE: RefCount;

                /* MonitoredClk max */
                HfRef = MonitoredClk * (1000U + CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION);
                /* ReferenceClk min */
                DivideBy = ReferenceClk * (1000U - CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
                /* (MonitoredClk max) div (ReferenceClk min) */
                DividerResult = (uint32) HfRef / DivideBy;
                ModuloValue = HfRef - (DivideBy * DividerResult);

                /* DividerResult mul RefCount */
                HfRef = (DividerResult * RefCount) + ((ModuloValue * RefCount)/ DivideBy);
                HfRef += (CLOCK_IP_CMU_FC_VAR + 1U);

                /* MonitoredClk min */
                LfRef = MonitoredClk * (1000U - CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION);
                /* ReferenceClk max */
                DivideBy = ReferenceClk * (1000U + CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
                /* (MonitoredClk min) div (ReferenceClk max) */
                DividerResult = (uint32) LfRef / DivideBy;
                ModuloValue = LfRef - (DivideBy * DividerResult);

                LfRef = (DividerResult * RefCount) + ((ModuloValue * RefCount)/ DivideBy);
                LfRef -= CLOCK_IP_CMU_FC_VAR;

                /* Set reference counter */
                CmuFc->RCCR = RefCount;

                /* Set high limit */
                CmuFc->HTCR = HfRef;

                /* Set low limit */
                CmuFc->LTCR = LfRef;
            }
        }

        /* Enable/disable interrupts */
        CmuFc->IER = Config->Interrupt;
    }
}


static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config)
{
    const Clock_Ip_CmuInfoType *CmuInformation;
    Clock_Ip_ClockMonitorType* CmuFc;

    if (NULL_PTR != Config)
    {
        CmuInformation  = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]];
        CmuFc    = CmuInformation->CmuInstance;

        /* Enable cmu */
        if (Config->Enable != 0U)
        {
            CmuFc->GCR |= CMU_FC_GCR_FCE_MASK;
        }
        else
        {
            CmuFc->GCR &= ~CMU_FC_GCR_FCE_MASK;
        }
    }
}

#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE > 0U

uint32 Clock_Ip_CMU_GetInterruptStatus(uint8 IndexCmu)
{
    uint32 CmuIsrValue;

    /* Read flags */
    CmuIsrValue = Clock_Ip_apxCmu[IndexCmu]->SR & CLOCK_IP_CMU_ISR_MASK;
    return CmuIsrValue;
}

/**
* @brief        This function clear the CMU interrupt flag from CMU module.
* @details      Called by RGM ISR routine when a user notification for CMU FCCU events is configured
*
* @return       void
*
* @implements Clock_Ip_CMU_ClockFailInt_Activity
*
*/
void Clock_Ip_CMU_ClockFailInt(void)
{
    uint32 CmuIerValue;
    uint32 CmuIsrValue;
    uint32 IndexCmu;

    for (IndexCmu = 0U; IndexCmu < CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE; IndexCmu++)
    {
        /* Read flags */
        CmuIsrValue = Clock_Ip_apxCmu[IndexCmu]->SR & CLOCK_IP_CMU_ISR_MASK;

        /* Check whether driver is initialized */
        if(NULL_PTR != Clock_Ip_pxConfig)
        {
            /* Read interrupt enable */
            CmuIerValue = Clock_Ip_apxCmu[IndexCmu]->IER & CLOCK_IP_CMU_ISR_MASK;

            /* Filter all interrupts that are not enabled from cmuIsrValue */
            CmuIsrValue = CmuIsrValue & CmuIerValue;

            /* If at least one interrupt has been triggered */
            if (CmuIsrValue != 0U)
            {
                /* Clear status flag */
                Clock_Ip_apxCmu[IndexCmu]->SR = CmuIsrValue;

#ifdef CLOCK_IP_CMU_FCCU_NOTIFICATION
                CLOCK_IP_CMU_FCCU_NOTIFICATION(Clock_Ip_aeCmuNames[IndexCmu]);
#else
                Clock_Ip_ReportClockErrors(CLOCK_IP_CMU_ERROR, Clock_Ip_aeCmuNames[IndexCmu]);
#endif
            }
        }
        else
        {
            /* Clear status flag */
            Clock_Ip_apxCmu[IndexCmu]->SR = CmuIsrValue;
        }
    }

}
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_ClockMonitorCallbackType Clock_Ip_axCmuCallbacks[CLOCK_IP_CMU_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_ClockMonitorEmpty,                /* Reset */
        Clock_Ip_ClockMonitorEmpty,                /* Set */
        Clock_Ip_ClockMonitorEmpty_Disable,        /* Disable */
        Clock_Ip_ClockMonitorEmpty,                /* Enable */
    },
#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
    {
        Clock_Ip_ResetCmuFcFceRefCntLfrefHfref,          /* Reset */
        Clock_Ip_SetCmuFcFceRefCntLfrefHfref,            /* Set */
        Clock_Ip_DisableCmuFcFceRefCntLfrefHfref,        /* Disable */
        Clock_Ip_EnableCmuFcFceRefCntLfrefHfref,         /* Enable */
    },
#endif


};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

