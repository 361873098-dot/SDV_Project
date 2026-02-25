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
*   @addtogroup IIC_DRIVER IIC Driver
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
#include "I2c_Ip.h"
#include "I2c_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_IRQ_VENDOR_ID_C                      43
#define I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define I2C_IP_IRQ_SW_MAJOR_VERSION_C               4
#define I2C_IP_IRQ_SW_MINOR_VERSION_C               0
#define I2C_IP_IRQ_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ip.h header file are of the same vendor */
#if (I2C_IP_IRQ_VENDOR_ID_C != I2C_IP_VENDOR_ID)
    #error "I2c_Ip_Irq.c and I2c_Ip.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip.h header file are of the same Autosar version */
#if ((I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != I2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != I2C_IP_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != I2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip_Irq.c and I2c_Ip.h are different"
#endif
/* Check if current file and I2c_Ip.h header file are of the same Software version */
#if ((I2C_IP_IRQ_SW_MAJOR_VERSION_C != I2C_IP_SW_MAJOR_VERSION) || \
     (I2C_IP_IRQ_SW_MINOR_VERSION_C != I2C_IP_SW_MINOR_VERSION) || \
     (I2C_IP_IRQ_SW_PATCH_VERSION_C != I2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_Irq.c and I2c_Ip.h are different"
#endif
/* Check if current file and I2c_Ip_Irq.h header file are of the same vendor */
#if (I2C_IP_IRQ_VENDOR_ID_C != I2C_IP_IRQ_VENDOR_ID)
    #error "I2c_Ip_Irq.c and I2c_Ip_Irq.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_Irq.h header file are of the same Autosar version */
#if ((I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != I2C_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != I2C_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != I2C_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip_Irq.c and I2c_Ip_Irq.h are different"
#endif
/* Check if current file and I2c_Ip_Irq.h header file are of the same Software version */
#if ((I2C_IP_IRQ_SW_MAJOR_VERSION_C != I2C_IP_IRQ_SW_MAJOR_VERSION) || \
     (I2C_IP_IRQ_SW_MINOR_VERSION_C != I2C_IP_IRQ_SW_MINOR_VERSION) || \
     (I2C_IP_IRQ_SW_PATCH_VERSION_C != I2C_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip_Irq.c and I2c_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

#if (I2C_INSTANCE_COUNT >= 1U)
ISR(I2c_Ip_IRQHandler0)
{
    /* Call interrupt handler instance 0 */
    I2c_Ip_ModuleIRQHandler(0u);
}
#endif

#if (I2C_INSTANCE_COUNT >= 2U)
ISR(I2c_Ip_IRQHandler1)
{
    /* Call interrupt handler instance 1 */
    I2c_Ip_ModuleIRQHandler(1u);
}
#endif

#if (I2C_INSTANCE_COUNT >= 3U)
ISR(I2c_Ip_IRQHandler2)
{
    /* Call interrupt handler instance 2 */
    I2c_Ip_ModuleIRQHandler(2u);
}
#endif

#if (I2C_INSTANCE_COUNT >= 4U)
ISR(I2c_Ip_IRQHandler3)
{
    /* Call interrupt handler instance 3 */
    I2c_Ip_ModuleIRQHandler(3u);
}
#endif

#if (I2C_INSTANCE_COUNT >= 5U)
ISR(I2c_Ip_IRQHandler4)
{
    /* Call interrupt handler instance 4 */
    I2c_Ip_ModuleIRQHandler(4u);

}
#endif

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

