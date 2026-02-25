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
*   @internal
*   @addtogroup Platform_Ipw
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_TypesDef.h"
#include "Platform_Ipw.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_IPW_VENDOR_ID_C                   43
#define CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    4
#define CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    4
#define CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C 0
#define CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C            4
#define CDD_PLATFORM_IPW_SW_MINOR_VERSION_C            0
#define CDD_PLATFORM_IPW_SW_PATCH_VERSION_C            2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_TYPESDEF_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_Ipw_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_TypesDef.h are different"
#endif

/* Check if current file and Platform_Ipw header file are of the same vendor */
#if (CDD_PLATFORM_IPW_VENDOR_ID_C != CDD_PLATFORM_IPW_VENDOR_ID)
    #error "Platform_Ipw.c and Platform_Ipw.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw header file are of the same Autosar version */
#if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif
/* Check if current file and Platform_Ipw header file are of the same Software version */
#if ((CDD_PLATFORM_IPW_SW_MAJOR_VERSION_C != CDD_PLATFORM_IPW_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_MINOR_VERSION_C != CDD_PLATFORM_IPW_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_IPW_SW_PATCH_VERSION_C != CDD_PLATFORM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw.c and Platform_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((CDD_PLATFORM_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_PLATFORM_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Platform_Ipw.c and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if ((STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
#define Call_System_Ip_ConfigIrq(eIrq, bEnable)       OsIf_Trusted_Call2params(System_Ip_ConfigIrq, (eIrq), (bEnable))
#define Call_System_Ip_SetAhbSlavePriority(bPriority) OsIf_Trusted_Call1param(System_Ip_SetAhbSlavePriority, (bPriority))
#else
#define Call_System_Ip_ConfigIrq(eIrq, bEnable)       System_Ip_ConfigIrq((eIrq), (bEnable))
#define Call_System_Ip_SetAhbSlavePriority(bPriority) System_Ip_SetAhbSlavePriority((bPriority))
#endif


static Std_ReturnType Platform_Ipw_InitIntCtrl(const IntCtrl_Ip_CtrlConfigType * pIntCtrlCtrlConfig)
{
    /* Initializes the configured interrupts at interrupt controller level */
    (void)IntCtrl_Ip_Init(pIntCtrlCtrlConfig);
    /* return value */
    return E_OK;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief         Initializes the platform settings based on user configuration.
 */
void Platform_Ipw_Init(const Platform_Ipw_ConfigType * pConfig)
{
#if (PLATFORM_SYS_CFG == STD_ON)
    uint8 u8IrqIdx;
#endif
    Std_ReturnType ret = (Std_ReturnType)E_OK;

    /* Initialize interrupts at interrupt controller level */
    if (NULL_PTR != pConfig->pIntCtrlConfig)
    {
        ret = Platform_Ipw_InitIntCtrl(pConfig->pIntCtrlConfig);
    }
    /* Configure core-related interrupt requests */
    if (ret ==(Std_ReturnType)E_OK)
    {
#if (PLATFORM_SYS_CFG == STD_ON)
        if (NULL_PTR != pConfig->aSystemConfig)
        {
            for (u8IrqIdx = 0u; u8IrqIdx < (pConfig->aSystemConfig)->u8SysIrqsCount; u8IrqIdx++)
            {
                Call_System_Ip_ConfigIrq((pConfig->aSystemConfig)->aSystemIrqs[u8IrqIdx].eIrq, (pConfig->aSystemConfig)->aSystemIrqs[u8IrqIdx].bEnable);
            }   
            Call_System_Ip_SetAhbSlavePriority((pConfig->aSystemConfig)->bAhbSlavePriority);
        }
#endif /* if (PLATFORM_SYS_CFG == STD_ON) */
    }
}

#if (PLATFORM_MSCM_CFG == STD_ON)
/**
 * @brief         Initializes the platform settings for non-core elements  based on user configuration.
 */

void Platform_Ipw_InitNonCore(const Platform_Ipw_NonCoreConfigType * pConfig)
{
    uint32 u32IrqIdx;
    if (NULL_PTR != pConfig->pIntRouteConfig)
    {
        for (u32IrqIdx = 0; u32IrqIdx < (pConfig->pIntRouteConfig)->u32ConfigIrqCount; u32IrqIdx++)
        {
            IntCtrl_Ip_SetTargetCores(pConfig->pIntRouteConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                                      pConfig->pIntRouteConfig->aIrqConfig[u32IrqIdx].u8TargetCores);
            IntCtrl_Ip_InstallHandler(pConfig->pIntRouteConfig->aIrqConfig[u32IrqIdx].eIrqNumber,
                                      pConfig->pIntRouteConfig->aIrqConfig[u32IrqIdx].pfHandler,
                                      NULL_PTR);
        }
    }
}

#endif /* if (PLATFORM_MSCM_CFG == STD_ON) */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"
