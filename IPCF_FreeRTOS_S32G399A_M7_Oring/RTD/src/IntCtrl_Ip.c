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
*   @file
*
*   @addtogroup IntCtrl_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "IntCtrl_Ip.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION_C        0
#define CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C                   4
#define CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C                   2
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "IntCtrl_Ip.c and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip.c and IntCtrl_Ip.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip.c and IntCtrl_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /*  Check if current file and Mcal.h are of the same version */
    #if ((CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of IntCtrl_Ip.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if defined(S32K3XX) || defined(SAF85) || defined(S32R41) || defined(S32XX)
extern uint32 __RAM_INTERRUPT_START[1U];
#else
extern uint32 __INT_SRAM_START[1U];
#endif
#define PLATFORM_START_SEC_CONST_8
#include "Platform_MemMap.h"

#if defined(S32XX)
static uint8 const aMscmCore2CoreIrqId[169]={4, 0, 1, 2, 3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 5, 6, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 7, 8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, \
                                             0xff, 0xff, 0xff, 0xff, 9, 10, 11, 12, 13};
#endif

#define PLATFORM_STOP_SEC_CONST_8
#include "Platform_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                OsIf_Trusted_Call3params(IntCtrl_Ip_InstallHandlerPrivileged,(eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_EnableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_DisableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_SetPriorityPrivileged,(eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPriorityPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearPendingPrivileged,(eIrqNumber))
#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_SetPendingPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPendingPrivileged,(eIrqNumber))
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetActivePrivileged,(eIrqNumber))
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
    #define Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_SetTargetCoresPrivileged,(eIrqNumber),(u8TargetCores))
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged,(eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetDirectedCpuInterruptPrivileged,(eIrqNumber))
#endif
#else /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                IntCtrl_Ip_InstallHandlerPrivileged((eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_EnableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_DisableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                IntCtrl_Ip_SetPriorityPrivileged((eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPriorityPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearPendingPrivileged((eIrqNumber))
#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_SetPendingPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPendingPrivileged((eIrqNumber))
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetActivePrivileged((eIrqNumber))
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
    #define Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores)  \
                IntCtrl_Ip_SetTargetCoresPrivileged((eIrqNumber),(u8TargetCores))
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged((eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)
#endif
#endif /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler);
void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority);
uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber);
#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber);
#if (INT_CTRL_IP_CORTEXM == STD_ON)
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber);
#endif
#endif
#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
void IntCtrl_Ip_SetTargetCoresPrivileged(IRQn_Type eIrqNumber, uint8 u8TargetCores);
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget);
void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
#endif


void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */

    sint32 s32Dev_irqNumber = (sint32)eIrqNumber;
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= s32Dev_irqNumber);
    DevAssert(s32Dev_irqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
#if defined(S32K3XX) || defined(SAF85) || defined(S32R41) || defined(S32XX)
    DevAssert(S32_SCB->VTOR >= (uint32)__RAM_INTERRUPT_START);
#else
    DevAssert(S32_SCB->VTOR >= (uint32)__INT_SRAM_START);
#endif
#endif /* (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH) */
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))

#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    OsIf_SuspendAllInterrupts();
    /* x2 = &VTABLE */
    ASM_KEYWORD("ldr x3,=VTABLE");
    /* x2 = &VTABLE[irq_id] */
    ASM_KEYWORD("add x3,x3,x0,lsl #3");
    /* VTABLE[irq_id] = isr_handler */
        /* Save the former handler pointer */
    if (NULL_PTR != pfOldHandler)
    {
        /* *pfOldHandler =  */
        ASM_KEYWORD("ldr x4,[x3]");
        ASM_KEYWORD("str x4,[x2]");
    }
    ASM_KEYWORD("str x1,[x3]");

    (void)eIrqNumber;
    (void)pfNewHandler;
    OsIf_ResumeAllInterrupts();
#else
    /* The 'irq_id' parameter is in r0 and the 'isr_handler' parameter is in r1 according to AAPCS */

    /* r2 = &VTABLE */
    ASM_KEYWORD("ldr r3,=VTABLE");
    /* r2 = &VTABLE[irq_id] */
    ASM_KEYWORD("add r3,r3,r0,lsl #2");
    /* Save the former handler pointer */
    if (NULL_PTR != pfOldHandler)
    {
        /* *pfOldHandler =  */
        ASM_KEYWORD("ldr r4,[r3]");
        ASM_KEYWORD("str r4,[r2]");

    }
    /* VTABLE[irq_id] = isr_handler */
    ASM_KEYWORD("str r1,[r3]");
#endif
    (void)eIrqNumber;
    (void)pfNewHandler;

#else
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)S32_SCB->VTOR;

    /* Save the former handler pointer */
    if (NULL_PTR != pfOldHandler)
    {
        *pfOldHandler = (IntCtrl_Ip_IrqHandlerType)pVectorRam[((sint32)eIrqNumber) + 16];
    }

    /* Set handler into vector table */
    pVectorRam[((sint32)eIrqNumber) + 16] = pfNewHandler;
#if (INT_CTRL_IP_INVALIDATE_CACHE == STD_ON)
    /* Invalidate ICache */
    S32_SCB->ICIALLU = 0UL;
#endif

#endif

    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
}

void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Enable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
#else
    S32_NVIC->ISER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Disable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Disable interrupt */
    S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    /* Disable interrupt */
    S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
#else
    S32_NVIC->ICER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number and priority - dev_irqNumber is used to avoid compiler warning */
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
    DevAssert(u8Priority < (uint8)(1U << INT_CTRL_IP_NVIC_PRIO_BITS));

#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint8 u8Shift = (uint8) (8U - INT_CTRL_IP_NVIC_PRIO_BITS);

#if (INT_CTRL_IP_CORTEXM == STD_ON)
    /* Set Priority for device specific Interrupts */
    S32_NVIC->IP[(uint32)(eIrqNumber)] = (uint8)((((uint32)u8Priority) << u8Shift) & 0xFFUL);
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    uint32_t u32IprVectorId = ((uint32_t)(eIrqNumber) >> 2U);
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)eIrqNumber) & 0x3U) << 3U);
    /* Clear the old value from the register */
    S32_GICD->GICD_IPRIORITYR[u32IprVectorId] &= ~(0xFFUL << u8PriByteShift);
    S32_GICD->GICD_IPRIORITYR[u32IprVectorId] |= ((uint32_t)(((((uint32_t)u8Priority) << u8Shift)) & 0xFFUL)) << u8PriByteShift;
#else
    uint32_t u32IprVectorId = ((uint32_t)(eIrqNumber) >> 2U) - 8;
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)eIrqNumber) & 0x3U) << 3U);
    /* Clear the old value from the register */
    S32_GICD->GICD_IPRIORITYR[u32IprVectorId] &= ~(0xFFUL << u8PriByteShift);
    S32_GICD->GICD_IPRIORITYR[u32IprVectorId] |= ((uint32_t)(((((uint32_t)u8Priority) << u8Shift)) & 0xFFUL)) << u8PriByteShift;
#endif

#else
    uint32_t u32IprVectorId = (uint32_t)(eIrqNumber) >> 2U;
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)eIrqNumber) & 0x3U) << 3U);

    /* Clear the old value from the register */
    S32_NVIC->IP[u32IprVectorId] &= ~(0xFFUL << u8PriByteShift);

    S32_NVIC->IP[u32IprVectorId] |= ((uint32_t)(((((uint32_t)u8Priority) << u8Shift)) & 0xFFUL)) << u8PriByteShift;
#endif
}

uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_IRQ_MIN <= eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);

#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint8 u8Priority;
    uint8 u8Shift = (uint8)(8U - INT_CTRL_IP_NVIC_PRIO_BITS);

#if (INT_CTRL_IP_CORTEXM == STD_ON)
    /* Get Priority for device specific Interrupts  */
    u8Priority = (uint8)(S32_NVIC->IP[(uint32)(eIrqNumber)] >> u8Shift);
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    uint32_t u32IprVectorId = ((uint32_t)(eIrqNumber) >> 2U);
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)(eIrqNumber)) & 0x3U) << 3U);
    u8Priority = ((uint8_t)(S32_GICD->GICD_IPRIORITYR[u32IprVectorId] >> u8PriByteShift)) >> u8Shift;
#else
    uint32_t u32IprVectorId = ((uint32_t)(eIrqNumber) >> 2U) - 8;
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)(eIrqNumber)) & 0x3U) << 3U);
    u8Priority = ((uint8_t)(S32_GICD->GICD_IPRIORITYR[u32IprVectorId] >> u8PriByteShift)) >> u8Shift;
#endif
#else
    uint32_t u32IprVectorId = (uint32_t)(eIrqNumber) >> 2U;
    uint8_t u8PriByteShift = (uint8_t)((((uint8_t)(eIrqNumber)) & 0x3U) << 3U);
    u8Priority = ((uint8_t)(S32_NVIC->IP[u32IprVectorId] >> u8PriByteShift)) >> u8Shift;
#endif
    return u8Priority;
}

void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Clear Pending Interrupt */
    S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    /* Clear Pending Interrupt */
    S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

#else
    /* Clear Pending Interrupt */
    S32_NVIC->ICPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Set Pending Interrupt */
    S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    /* Set Pending Interrupt */
    S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U) - 1] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

#else
    /* Set Pending Interrupt */
    S32_NVIC->ISPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}

uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
/* Get Pending Interrupt */
    return ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#else
/* Get Pending Interrupt */
    return ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL) - 1] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#endif

#else
    /* Get Pending Interrupt */
    return ((((S32_NVIC->ISPR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#endif
}
#if (INT_CTRL_IP_CORTEXM == STD_ON)
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Get Active Interrupt */
    return ((((S32_NVIC->IABR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
}
#endif
#endif /*#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)*/

#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 * @implements    IntCtrl_Ip_SetTargetCores_Activity
 */
void IntCtrl_Ip_SetTargetCoresPrivileged(IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((uint32)eIrqNumber) <= (uint32)INT_CTRL_IP_IRQ_MAX);
    /* Check interrupt routing is not locked for this IRQ */
    DevAssert((IP_MSCM->IRSPRC[eIrqNumber] & (uint16)(MSCM_IRSPRC_LOCK_MASK)) == (uint16)MSCM_IRSPRC_LOCK(0));
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    DevAssert(((uint16)u8TargetCores) <= (uint16)INTCTRL_IP_CORE_MASK);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    IP_MSCM->IRSPRC[(uint32)eIrqNumber - 32] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
#else
    IP_MSCM->IRSPRC[(uint32)eIrqNumber] = (uint16)u8TargetCores & (uint16)INTCTRL_IP_CORE_MASK;
#endif
}


#endif

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)

void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
#if defined(S32XX)
    /* Check IRQ number */
    DevAssert(aMscmCore2CoreIrqId[(uint32)eIrqNumber] != (uint8)0xff);
#endif
    /* Check IRQ number */
    DevAssert((sint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INTCTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint32 u32CurrentCpu;
    uint32 u32IrqId;

    u32CurrentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
#if defined(S32XX)
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber - 32];
#else
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber];
#endif
#else
    u32IrqId = (uint32)eIrqNumber - (uint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN;
#endif
    /* Clear Directed CPU Pending Interrupt */
    MSCM_IRCPnIRx->IRCPnIRx[u32CurrentCpu][u32IrqId].IntStatusR = 0x7FU;

}

uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
#if defined(S32XX)
    /* Check IRQ number */
    DevAssert(aMscmCore2CoreIrqId[(uint32)eIrqNumber] != (uint8)0xff);
#endif
    /* Check IRQ number */
    DevAssert((sint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INTCTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */


    uint32 u32CurrentCpu;
    uint32 u32IrqId;

    u32CurrentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
#if defined(S32XX)
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber - 32];
#else
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber];
#endif
#else
    u32IrqId = (uint32)eIrqNumber - (uint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN;
#endif

    return ((MSCM_IRCPnIRx->IRCPnIRx[u32CurrentCpu][u32IrqId].IntStatusR != 0U) ? TRUE : FALSE);
}


void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
#if defined(S32XX)
    /* Check IRQ number */
    DevAssert(aMscmCore2CoreIrqId[(uint32)eIrqNumber] != (uint8)0xff);
#endif
    /* Check IRQ number */
    DevAssert((sint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INTCTRL_IP_DIRECTED_CPU_INT_MAX);
#endif
    uint32 u32Core;
    uint32 u32Target;
    uint32 u32IrqId;
    
#if defined(S32XX)
#if  (MCAL_PLATFORM_ARM  == MCAL_ARM_AARCH64)
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber - 32];
#else
    u32IrqId = (uint32)aMscmCore2CoreIrqId[(uint32)eIrqNumber];
#endif
#else
    u32IrqId = (uint32)eIrqNumber - (uint32)INTCTRL_IP_DIRECTED_CPU_INT_MIN;
#endif

    if (INTCTRL_IP_TARGET_OTHERS == eCpuTarget)
    {
        for (u32Core = 0U; u32Core < INTCTRL_IP_MSI_CORE_CNT; u32Core++)
        {
            /* Add Fault Injection point for processor number */
                MCAL_FAULT_INJECTION_POINT(PLATFORM_CPN_ERROR_CPUINTERRUPT);
            /* Generate a Directed CPU Interrupt to every other core */
            if (u32Core != (MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM)))
            {
                MSCM_IRCPnIRx->IRCPnIRx[u32Core][u32IrqId].IGR = 0x1U;
            }
        }
    }
    else
    {
        if (INTCTRL_IP_TARGET_SELF == eCpuTarget)
        {
            u32Target = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
        }
        else
        {
            u32Target = (uint32)eCpuTarget;
        }

        /* Generate Directed CPU Interrupt to target core */
        MSCM_IRCPnIRx->IRCPnIRx[u32Target][u32IrqId].IGR = 0x1U;
    }
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/





/**
 * @internal
 * @brief         Initializes the configured interrupts at interrupt controller level.
 * @implements    IntCtrl_Ip_Init_Activity
 */
IntCtrl_Ip_StatusType IntCtrl_Ip_Init(const IntCtrl_Ip_CtrlConfigType *pIntCtrlCtrlConfig)
{

#if (INTCTRL_IP_ENABLE_VTOR_CONFIG == STD_ON)
    S32_SCB->VTOR = pIntCtrlCtrlConfig->u32VectorTableAddress;
#endif

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pIntCtrlCtrlConfig != NULL_PTR);
    DevAssert(pIntCtrlCtrlConfig->u32ConfigIrqCount <= INT_CTRL_IP_IRQ_COUNT);
#endif
    uint32 u32IrqIdx;
    for (u32IrqIdx = 0; u32IrqIdx < pIntCtrlCtrlConfig->u32ConfigIrqCount; u32IrqIdx++)
    {
        IntCtrl_Ip_ClearPending(pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].eIrqNumber);
        IntCtrl_Ip_SetPriority(pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                               pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].u8IrqPriority);

        /* Install the configured handler */
        IntCtrl_Ip_InstallHandler(pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                                  pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].pfHandler,
                                  NULL_PTR);

        if (pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].bIrqEnabled)
        {
            IntCtrl_Ip_EnableIrq(pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].eIrqNumber);
        }
        else
        {
            IntCtrl_Ip_DisableIrq(pIntCtrlCtrlConfig->aIrqConfig[u32IrqIdx].eIrqNumber);
        }
    }

    return INTCTRL_IP_STATUS_SUCCESS;
}

#if (INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON)
/**
 * @internal
 * @brief         Initializes the configured routing interrupts.
 * @implements    IntCtrl_Ip_ConfigIrqRouting_Activity
 */
IntCtrl_Ip_StatusType IntCtrl_Ip_ConfigIrqRouting(const IntCtrl_Ip_GlobalRouteConfigType *routeConfig)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(routeConfig != NULL_PTR);
    DevAssert(routeConfig->u32ConfigIrqCount <= INT_CTRL_IP_IRQ_COUNT);
#endif
    uint32 u32IrqIdx;
    for (u32IrqIdx = 0; u32IrqIdx < routeConfig->u32ConfigIrqCount; u32IrqIdx++)
    {
#if (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON)
        /* Configure routing */
        IntCtrl_Ip_SetTargetCores(routeConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                                  routeConfig->aIrqConfig[u32IrqIdx].u8TargetCores);
#endif
        /* Install the configured handler */
        IntCtrl_Ip_InstallHandler(routeConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                                  routeConfig->aIrqConfig[u32IrqIdx].pfHandler,
                                  NULL_PTR);
    }
    return INTCTRL_IP_STATUS_SUCCESS;
}
#endif

/**
 * @internal
 * @brief         Installs a handler for an IRQ.
 * @implements    IntCtrl_Ip_InstallHandler_Activity
 */
void IntCtrl_Ip_InstallHandler(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
    Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler);
}

/**
 * @internal
 * @brief         Enables an interrupt request.
 * @implements    IntCtrl_Ip_EnableIrq_Activity
 */
void IntCtrl_Ip_EnableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Disables an interrupt request.
 * @implements    IntCtrl_Ip_DisableIrq_Activity
 */
void IntCtrl_Ip_DisableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Sets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_SetPriority_Activity
 */
void IntCtrl_Ip_SetPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority);
}

/**
 * @internal
 * @brief         Gets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_GetPriority_Activity
 */
uint8 IntCtrl_Ip_GetPriority(IRQn_Type eIrqNumber)
{
    return (uint8)Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Clears the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_ClearPending_Activity
 */
void IntCtrl_Ip_ClearPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber);
}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
/**
 * @internal
 * @brief         Sets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_SetPending_Activity
 */
void IntCtrl_Ip_SetPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Gets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetPending_Activity
 */
boolean IntCtrl_Ip_GetPending(IRQn_Type eIrqNumber)
{
    return (Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}

/**
 * @internal
 * @brief         Gets the active flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetActive_Activity
 */
#if (INT_CTRL_IP_CORTEXM == STD_ON)
boolean IntCtrl_Ip_GetActive(IRQn_Type eIrqNumber)
{
    /*Gets the active flag for an interrupt request */
    return (Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
#endif
#endif /* INT_CTRL_IP_STANDALONE_APIS*/

#if ((INT_CTRL_IP_MSCM_SYSTEM_INTERRUPT_ROUTER == STD_ON) && (INT_CTRL_IP_ROUTING_CONTROL_REGISTER == STD_ON))
/**
 * @internal
 * @brief         Sets the target cores for an interrupt request.
 * @implements    IntCtrl_Ip_SetTargetCores_Activity
 */
void IntCtrl_Ip_SetTargetCores(IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
    /* Sets the target cores for an interrupt request */
    Call_IntCtrl_Ip_SetTargetCoresPrivileged(eIrqNumber,u8TargetCores);
}
#endif

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
/**
 * @internal
 * @brief         Clear directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged_Activity
 */
void IntCtrl_Ip_ClearDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber);
}
/**
 * @internal
 * @brief         Get directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_GetDirectedCpuInterrupt_Activity
 */
boolean IntCtrl_Ip_GetDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    return (Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
/**
 * @internal
 * @brief         Generates an interrupt request to a CPU target.
 * @implements    IntCtrl_Ip_GenerateDirectedCpuInterrupt_Activity
 */
void IntCtrl_Ip_GenerateDirectedCpuInterrupt(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
    Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget);
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */
