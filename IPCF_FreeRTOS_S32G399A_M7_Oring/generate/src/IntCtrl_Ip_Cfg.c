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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "IntCtrl_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C                   4
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C                   2
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C        0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_CFG_VENDOR_ID)
    #error "IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Autosar version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IntCtrl_Ip_Cfg.C and IntCtrl_Ip_Cfg.h are different"
#endif
/* Check if current file and IntCtrl_Ip_Cfg header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip_Cfg.c and IntCtrl_Ip_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/* List of configuration for interrupts  */
static const IntCtrl_Ip_IrqConfigType aIrqConfiguration[] = {
    {MSCM_Pcie_1_MSI_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT2_IRQn, (boolean)TRUE, 4U, ipc_shm_hardirq},
    {MSCM_Pcie_0_MSI_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTI_INT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTI_INT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA0_0_15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA0_16_31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA0_ERR0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA1_0_15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA1_16_31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA1_ERR0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT6_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT7_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM6_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM7_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {QSPI0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {QSPI1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {QSPI2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STCU2_LBIST_MBIST_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {USDHC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_ORED_0_7_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_ORED_8_127_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_ORED_0_7_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_ORED_8_127_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_ORED_0_7_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_ORED_8_127_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_ORED_0_7_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_ORED_8_127_MB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PIT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PIT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FTM0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FTM1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_Common_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH0_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH0_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH1_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH1_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH2_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH2_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH3_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH3_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH4_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {GMAC0_CH4_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MSCM_INT6_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SAR_ADC0_INT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SAR_ADC1_INT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_NCERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_CERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_CH0_RX_FIFO_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_CH1_RX_FIFO_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_WKUP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_STATUS_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_CMBERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_TX_BUFF_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_RX_BUFF_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLEXRAY0_MODULE_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LINFLEXD0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LINFLEXD1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LINFLEXD2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MC_RGM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FCCU_ALARM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FCCU_MISC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SBSW_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU0_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU0_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU0_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU1_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU1_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU1_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU2_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU2_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU2_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU3_TX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU3_RX_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {HSE_MU3_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DDR0_SCRUB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DDR0_PHY_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTU_FIFO_FULL_EMPTY_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTU_M_RELOAD_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CTU_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TMU_ALARM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {RTC_SYS_CONT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_ORED_DMA_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_LINK_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_AXI_MSI_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_PHY_DOWM_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_PHY_UP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_INTA_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_INTB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_INTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_INTD_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_MISC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_PCS_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE0_TLP_NC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CORTEX_A53_ERR_L2RAM_CLUSTER0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CORTEX_A53_ERR_LIVLOCK_CLUSTER0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CORTEX_A53_ERR_L2RAM_CLUSTER1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CORTEX_A53_ERR_LIVLOCK_CLUSTER1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {JDC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT8_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT9_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT10_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SWT11_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM8_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM9_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM10_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM11_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCSCM_INT7_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCSCM_INT8_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCSCM_INT9_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCSCM_INT10_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCSCM_INT11_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_INT0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_INT1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_INT2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_INT3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR14_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR16_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR17_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR18_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR19_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR20_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR21_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR22_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR23_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR24_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR25_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR26_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {LLCE0_ICSR27_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_CH0_STAT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_CH1_STAT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_CH2_STAT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_CH3_STAT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_BMU1_BMU2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_HIF_NC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_UT_GPT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_PMT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PFE0_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STM_TS_CH_REQ_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SIUL1_ORED_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {USB0_OTG_CORE_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {USB0_OTG_WKP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {WKPU_GRP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_ORED_DMA_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_STAT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_AXI_MSI_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_PHY_LDOWN_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_PHY_LUP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_INTA_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_INTB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_INTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_INTD_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_MISC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_PCS_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PCIE1_TLP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {XRDC_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {XRDC_MANAGER_ERR_IRQn, (boolean)FALSE, 0U, undefined_handler},
};
const IntCtrl_Ip_CtrlConfigType intCtrlConfig = {
    195U,
    aIrqConfiguration
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

