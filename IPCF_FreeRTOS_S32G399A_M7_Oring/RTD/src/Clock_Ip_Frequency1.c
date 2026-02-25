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
*   @file       Clock_Ip_Frequency1.c
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

#if defined(CLOCK_IP_PLATFORM_SPECIFIC1)

#ifdef CLOCK_IP_GET_FREQUENCY_API
#if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)


/*==================================================================================================
*                                     SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_FREQUENCY1_VENDOR_ID_C                      43
#define CLOCK_IP_FREQUENCY1_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_FREQUENCY1_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_FREQUENCY1_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_FREQUENCY1_SW_MAJOR_VERSION_C               4
#define CLOCK_IP_FREQUENCY1_SW_MINOR_VERSION_C               0
#define CLOCK_IP_FREQUENCY1_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Frequency1.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_FREQUENCY1_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Frequency1.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Frequency1.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_FREQUENCY1_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY1_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY1_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Frequency1.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Frequency1.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_FREQUENCY1_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY1_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY1_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Frequency1.c and Clock_Ip_Private.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef struct{

    Clock_Ip_NameType Name;
    uint32 Frequency;

}extSignalFreq;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_SELECTOR_SOURCE_NO  64U
#define CLOCK_IP_EXT_SIGNALS_NO      17U
#define CLOCK_IP_DFS_MASK_0_CHANNEL  1U
#define CLOCK_IP_DFS_MASK_1_CHANNEL  2U
#define CLOCK_IP_DFS_MASK_2_CHANNEL  4U
#define CLOCK_IP_DFS_MASK_3_CHANNEL  8U
#define CLOCK_IP_DFS_MASK_4_CHANNEL  16U
#define CLOCK_IP_DFS_MASK_5_CHANNEL  32U
#define CLOCK_IP_MUL_BY_16384        14U
#define CLOCK_IP_MUL_BY_2048         11U
#define CLOCK_IP_MUL_BY_32           5U
#define CLOCK_IP_MUL_BY_16           4U
#define CLOCK_IP_MUL_BY_4            2U
#define CLOCK_IP_MUL_BY_2            1U
#define CLOCK_IP_DISABLED            0U
#define CLOCK_IP_ENABLED             0xFFFFFFFFU

#define CLOCK_IP_FTM_0_EXT_REF_CLK_INDEX_ENTRY       0U
#define CLOCK_IP_FTM_1_EXT_REF_CLK_INDEX_ENTRY       1U
#define CLOCK_IP_GMAC_0_EXT_REF_CLK_INDEX_ENTRY      2U
#define CLOCK_IP_GMAC_0_EXT_RX_CLK_INDEX_ENTRY       3U
#define CLOCK_IP_GMAC_0_EXT_TX_CLK_INDEX_ENTRY       4U
#define CLOCK_IP_GMAC_1_EXT_REF_CLK_INDEX_ENTRY      5U
#define CLOCK_IP_GMAC_1_EXT_RX_CLK_INDEX_ENTRY       6U
#define CLOCK_IP_GMAC_1_EXT_TX_CLK_INDEX_ENTRY       7U
#define CLOCK_IP_GMAC_EXT_TS_CLK_INDEX_ENTRY         8U
#define CLOCK_IP_SERDES_0_LANE_0_TX_INDEX_ENTRY      9U
#define CLOCK_IP_SERDES_0_LANE_0_CDR_INDEX_ENTRY     10U
#define CLOCK_IP_SERDES_1_LANE_0_TX_INDEX_ENTRY      11U
#define CLOCK_IP_SERDES_1_LANE_0_CDR_INDEX_ENTRY     12U

#define CLOCK_IP_COREPLL_FREQ                        2000000000U
#define CLOCK_IP_COREPLL_CHECKSUM                    4147U
#define CLOCK_IP_PERIPHPLL_FREQ                      2000000000U
#define CLOCK_IP_PERIPHPLL_CHECKSUM                  4147U
#define CLOCK_IP_DDRPLL_FREQ                         1600000000U
#define CLOCK_IP_DDRPLL_CHECKSUM                     4137U
#define CLOCK_IP_ACCELPLL_FREQ                       2400000000U
#define CLOCK_IP_ACCELPLL_CHECKSUM                   0U
#define CLOCK_IP_COREDFS1_FREQ                       800000000U
#define CLOCK_IP_COREDFS1_CHECKSUM                   5694U
#define CLOCK_IP_COREDFS2_FREQ                       800000000U
#define CLOCK_IP_COREDFS2_CHECKSUM                   5694U
#define CLOCK_IP_COREDFS3_FREQ                       0U
#define CLOCK_IP_COREDFS3_CHECKSUM                   5943U
#define CLOCK_IP_COREDFS4_FREQ                       0U
#define CLOCK_IP_COREDFS4_CHECKSUM                   5943U
#define CLOCK_IP_COREDFS5_FREQ                       0U
#define CLOCK_IP_COREDFS5_CHECKSUM                   5943U
#define CLOCK_IP_COREDFS6_FREQ                       0U
#define CLOCK_IP_COREDFS6_CHECKSUM                   5943U
#define CLOCK_IP_PERIPHDFS1_FREQ                     800000000U
#define CLOCK_IP_PERIPHDFS1_CHECKSUM                 5694U
#define CLOCK_IP_PERIPHDFS2_FREQ                     631578947U
#define CLOCK_IP_PERIPHDFS2_CHECKSUM                 5666U
#define CLOCK_IP_PERIPHDFS3_FREQ                     0U
#define CLOCK_IP_PERIPHDFS3_CHECKSUM                 5943U
#define CLOCK_IP_PERIPHDFS4_FREQ                     1000000000U
#define CLOCK_IP_PERIPHDFS4_CHECKSUM                 5687U
#define CLOCK_IP_PERIPHDFS5_FREQ                     1000000000U
#define CLOCK_IP_PERIPHDFS5_CHECKSUM                 5687U
#define CLOCK_IP_PERIPHDFS6_FREQ                     1000000000U
#define CLOCK_IP_PERIPHDFS6_CHECKSUM                 5687U

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static uint32 get_Zero_Frequency(void);
static uint32 get_FIRC_CLK_Frequency(void);
static uint32 get_FXOSC_CLK_Frequency(void);
static uint32 get_SIRC_CLK_Frequency(void);
static uint32 get_COREPLL_CLK_Frequency(void);
static uint32 get_PERIPHPLL_CLK_Frequency(void);
static uint32 get_DDRPLL_CLK_Frequency(void);
static uint32 get_ACCELPLL_CLK_Frequency(void);
static uint32 get_COREPLL_PHI0_Frequency(void);
static uint32 get_COREPLL_PHI1_Frequency(void);
static uint32 get_COREPLL_DFS1_Frequency(void);
static uint32 get_COREPLL_DFS2_Frequency(void);
static uint32 get_COREPLL_DFS3_Frequency(void);
static uint32 get_COREPLL_DFS4_Frequency(void);
static uint32 get_COREPLL_DFS5_Frequency(void);
static uint32 get_COREPLL_DFS6_Frequency(void);
static uint32 get_PERIPHPLL_PHI0_Frequency(void);
static uint32 get_PERIPHPLL_PHI1_Frequency(void);
static uint32 get_PERIPHPLL_PHI2_Frequency(void);
static uint32 get_PERIPHPLL_PHI3_Frequency(void);
static uint32 get_PERIPHPLL_PHI4_Frequency(void);
static uint32 get_PERIPHPLL_PHI5_Frequency(void);
static uint32 get_PERIPHPLL_PHI6_Frequency(void);
static uint32 get_PERIPHPLL_PHI7_Frequency(void);
static uint32 get_PERIPHPLL_DFS1_Frequency(void);
static uint32 get_PERIPHPLL_DFS2_Frequency(void);
static uint32 get_PERIPHPLL_DFS3_Frequency(void);
static uint32 get_PERIPHPLL_DFS4_Frequency(void);
static uint32 get_PERIPHPLL_DFS5_Frequency(void);
static uint32 get_PERIPHPLL_DFS6_Frequency(void);
static uint32 get_DDRPLL_PHI0_Frequency(void);
static uint32 get_ACCELPLL_PHI0_Frequency(void);
static uint32 get_ACCELPLL_PHI1_Frequency(void);
static uint32 get_ftm_0_ext_ref_Frequency(void);
static uint32 get_ftm_1_ext_ref_Frequency(void);
static uint32 get_gmac_0_ext_ref_Frequency(void);
static uint32 get_gmac_0_ext_rx_Frequency(void);
static uint32 get_gmac_0_ext_tx_Frequency(void);
static uint32 get_gmac_ext_ts_Frequency(void);
static uint32 get_gmac_1_ext_tx_Frequency(void);
static uint32 get_gmac_1_ext_rx_Frequency(void);
static uint32 get_gmac_1_ext_ref_Frequency(void);
static uint32 get_SERDES_0_LANE_0_TX_Frequency(void);
static uint32 get_SERDES_0_LANE_0_CDR_Frequency(void);
static uint32 get_SERDES_1_LANE_0_TX_Frequency(void);
static uint32 get_SERDES_1_LANE_0_CDR_Frequency(void);
static uint32 get_XBAR_2X_CLK_Frequency(void);
static uint32 get_XBAR_CLK_Frequency(void);
static uint32 get_XBAR_DIV2_CLK_Frequency(void);
static uint32 get_XBAR_DIV3_CLK_Frequency(void);
static uint32 get_XBAR_DIV4_CLK_Frequency(void);
static uint32 get_XBAR_DIV6_CLK_Frequency(void);
static uint32 get_A53_CORE_CLK_Frequency(void);
static uint32 get_A53_CORE_DIV2_CLK_Frequency(void);
static uint32 get_A53_CORE_DIV10_CLK_Frequency(void);
static uint32 get_ACCEL3_CLK_Frequency(void);
static uint32 get_ACCEL3_DIV3_CLK_Frequency(void);
static uint32 get_ACCEL4_CLK_Frequency(void);
static uint32 get_DDR_CLK_Frequency(void);
static uint32 get_PER_CLK_Frequency(void);
static uint32 get_GMAC0_REF_CLK_Frequency(void);
static uint32 get_GMAC0_REF_DIV_CLK_Frequency(void);
static uint32 get_GMAC1_REF_DIV_CLK_Frequency(void);
static uint32 get_PERIPHPLL_PHI0_Frequency(void);
static uint32 get_CLKOUT0_CLK_Frequency(void);
static uint32 get_CLKOUT1_CLK_Frequency(void);
static uint32 get_A53_CORE_DIV10_CLK_Frequency(void);
static uint32 get_FLEXCAN_CLK_Frequency(void);
static uint32 get_FLEXCAN0_CLK_Frequency(void);
static uint32 get_FLEXCAN1_CLK_Frequency(void);
static uint32 get_FLEXCAN2_CLK_Frequency(void);
static uint32 get_FLEXCAN3_CLK_Frequency(void);
static uint32 get_FLEXCAN4_CLK_Frequency(void);
static uint32 get_FLEXCAN5_CLK_Frequency(void);
static uint32 get_FLEXCAN6_CLK_Frequency(void);
static uint32 get_FLEXCAN7_CLK_Frequency(void);
static uint32 get_FLEXRAY_CLK_Frequency(void);
static uint32 get_FRAY0_CLK_Frequency(void);
static uint32 get_FLEXTIMERA_CLK_Frequency(void);
static uint32 get_FTIMER0_CLK_Frequency(void);
static uint32 get_FLEXTIMERB_CLK_Frequency(void);
static uint32 get_FTIMER1_CLK_Frequency(void);
static uint32 get_GMAC_TS_CLK_Frequency(void);
static uint32 get_GMAC0_RX_CLK_Frequency(void);
static uint32 get_GMAC0_TX_CLK_Frequency(void);
static uint32 get_GMAC0_TS_CLK_Frequency(void);
static uint32 get_GMAC1_RX_CLK_Frequency(void);
static uint32 get_GMAC1_TX_CLK_Frequency(void);
static uint32 get_GMAC1_TS_CLK_Frequency(void);
static uint32 get_LBIST_CLK_Frequency(void);
static uint32 get_LBIST0_CLK_Frequency(void);
static uint32 get_LBIST1_CLK_Frequency(void);
static uint32 get_LBIST2_CLK_Frequency(void);
static uint32 get_LBIST3_CLK_Frequency(void);
static uint32 get_LBIST4_CLK_Frequency(void);
static uint32 get_LBIST5_CLK_Frequency(void);
static uint32 get_LBIST6_CLK_Frequency(void);
static uint32 get_LBIST7_CLK_Frequency(void);
static uint32 get_LIN_BAUD_CLK_Frequency(void);
static uint32 get_LINFLEX_CLK_Frequency(void);
static uint32 get_LIN0_CLK_Frequency(void);
static uint32 get_LIN1_CLK_Frequency(void);
static uint32 get_QSPI_2X_CLK_Frequency(void);
static uint32 get_QSPI_1X_CLK_Frequency(void);
static uint32 get_QSPI0_CLK_Frequency(void);
static uint32 get_SPI_CLK_Frequency(void);
static uint32 get_SPI0_CLK_Frequency(void);
static uint32 get_SPI1_CLK_Frequency(void);
static uint32 get_SPI2_CLK_Frequency(void);
static uint32 get_SPI3_CLK_Frequency(void);
static uint32 get_SPI4_CLK_Frequency(void);
static uint32 get_SPI5_CLK_Frequency(void);
static uint32 get_USDHC_CLK_Frequency(void);
static uint32 get_USDHC0_CLK_Frequency(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const uint32 Clock_Ip_au32EnableDivider[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};

typedef uint32 (*getFreqType)(void);

static const getFreqType Clock_Ip_apfFreqTableClkSrc[CLOCK_IP_SELECTOR_SOURCE_NO] =
{
   get_FIRC_CLK_Frequency,                  /* clock name for 0  hardware value */
   get_SIRC_CLK_Frequency,                  /* clock name for 1  hardware value */
   get_FXOSC_CLK_Frequency,                 /* clock name for 2  hardware value */
   get_Zero_Frequency,                      /* clock name for 3  hardware value */
   get_COREPLL_PHI0_Frequency,              /* clock name for 4  hardware value */
   get_COREPLL_PHI1_Frequency,              /* clock name for 5  hardware value */
   get_Zero_Frequency,                      /* clock name for 6  hardware value */
   get_Zero_Frequency,                      /* clock name for 7  hardware value */
   get_Zero_Frequency,                      /* clock name for 8  hardware value */
   get_Zero_Frequency,                      /* clock name for 9  hardware value */
   get_Zero_Frequency,                      /* clock name for 10 hardware value */
   get_Zero_Frequency,                      /* clock name for 11 hardware value */
   get_COREPLL_DFS1_Frequency,              /* clock name for 12 hardware value */
   get_COREPLL_DFS2_Frequency,              /* clock name for 13 hardware value */
   get_COREPLL_DFS3_Frequency,              /* clock name for 14 hardware value */
   get_Zero_Frequency,                      /* clock name for 15 hardware value */
   get_COREPLL_DFS5_Frequency,              /* clock name for 16 hardware value */
   get_COREPLL_DFS6_Frequency,              /* clock name for 17 hardware value */
   get_PERIPHPLL_PHI0_Frequency,            /* clock name for 18 hardware value */
   get_PERIPHPLL_PHI1_Frequency,            /* clock name for 19 hardware value */
   get_PERIPHPLL_PHI2_Frequency,            /* clock name for 20 hardware value */
   get_PERIPHPLL_PHI3_Frequency,            /* clock name for 21 hardware value */
   get_PERIPHPLL_PHI4_Frequency,            /* clock name for 22 hardware value */
   get_PERIPHPLL_PHI5_Frequency,            /* clock name for 23 hardware value */
   get_PERIPHPLL_PHI6_Frequency,            /* clock name for 24 hardware value */
   get_PERIPHPLL_PHI7_Frequency,            /* clock name for 25 hardware value */
   get_PERIPHPLL_DFS1_Frequency,            /* clock name for 26 hardware value */
   get_PERIPHPLL_DFS2_Frequency,            /* clock name for 27 hardware value */
   get_PERIPHPLL_DFS3_Frequency,            /* clock name for 28 hardware value */
   get_PERIPHPLL_DFS4_Frequency,            /* clock name for 29 hardware value */
   get_PERIPHPLL_DFS5_Frequency,            /* clock name for 30 hardware value */
   get_PERIPHPLL_DFS6_Frequency,            /* clock name for 31 hardware value */
   get_Zero_Frequency,                      /* clock name for 32 hardware value */
   get_Zero_Frequency,                      /* clock name for 33 hardware value */
   get_ftm_0_ext_ref_Frequency,             /* clock name for 34 hardware value */
   get_ftm_1_ext_ref_Frequency,             /* clock name for 35 hardware value */
   get_DDRPLL_PHI0_Frequency,               /* clock name for 36 hardware value */
   get_gmac_0_ext_tx_Frequency,             /* clock name for 37 hardware value */
   get_gmac_0_ext_rx_Frequency,             /* clock name for 38 hardware value */
   get_gmac_0_ext_ref_Frequency,            /* clock name for 39 hardware value */
   get_Zero_Frequency,                      /* clock name for 40 hardware value */
   get_SERDES_0_LANE_0_CDR_Frequency,       /* clock name for 41 hardware value */
   get_Zero_Frequency,                      /* clock name for 42 hardware value */
   get_Zero_Frequency,                      /* clock name for 43 hardware value */
   get_gmac_ext_ts_Frequency,               /* clock name for 44 hardware value */
   get_GMAC0_REF_DIV_CLK_Frequency,         /* clock name for 45 hardware value */
   get_Zero_Frequency,                      /* clock name for 46 hardware value */
   get_Zero_Frequency,                      /* clock name for 47 hardware value */
   get_Zero_Frequency,                      /* clock name for 48 hardware value */
   get_Zero_Frequency,                      /* clock name for 49 hardware value */
   get_Zero_Frequency,                      /* clock name for 50 hardware value */
   get_Zero_Frequency,                      /* clock name for 51 hardware value */
   get_Zero_Frequency,                      /* clock name for 52 hardware value */
   get_Zero_Frequency,                      /* clock name for 53 hardware value */
   get_GMAC1_REF_DIV_CLK_Frequency,         /* clock name for 54 hardware value */
   get_Zero_Frequency,                      /* clock name for 55 hardware value */
   get_gmac_1_ext_tx_Frequency,             /* clock name for 56 hardware value */
   get_gmac_1_ext_rx_Frequency,             /* clock name for 57 hardware value */
   get_gmac_1_ext_ref_Frequency,            /* clock name for 58 hardware value */
   get_SERDES_1_LANE_0_TX_Frequency,        /* clock name for 59 hardware value */
   get_SERDES_1_LANE_0_CDR_Frequency,       /* clock name for 60 hardware value */
   get_Zero_Frequency,                      /* clock name for 61 hardware value */
   get_ACCELPLL_PHI0_Frequency,             /* clock name for 62 hardware value */
   get_COREPLL_DFS4_Frequency,              /* clock name for 63 hardware value */
};

static const getFreqType Clock_Ip_apfFreqTableClkSrc_1[CLOCK_IP_SELECTOR_SOURCE_NO] =
{
   get_FIRC_CLK_Frequency,              /* clock name for 0  hardware value */
   get_Zero_Frequency,                  /* clock name for 1  hardware value */
   get_Zero_Frequency,                  /* clock name for 2  hardware value */
   get_Zero_Frequency,                  /* clock name for 3  hardware value */
   get_Zero_Frequency,                  /* clock name for 4  hardware value */
   get_Zero_Frequency,                  /* clock name for 5  hardware value */
   get_Zero_Frequency,                  /* clock name for 6  hardware value */
   get_Zero_Frequency,                  /* clock name for 7  hardware value */
   get_Zero_Frequency,                  /* clock name for 8  hardware value */
   get_Zero_Frequency,                  /* clock name for 9  hardware value */
   get_Zero_Frequency,                  /* clock name for 10 hardware value */
   get_Zero_Frequency,                  /* clock name for 11 hardware value */
   get_Zero_Frequency,                  /* clock name for 12 hardware value */
   get_Zero_Frequency,                  /* clock name for 13 hardware value */
   get_Zero_Frequency,                  /* clock name for 14 hardware value */
   get_Zero_Frequency,                  /* clock name for 15 hardware value */
   get_Zero_Frequency,                  /* clock name for 16 hardware value */
   get_Zero_Frequency,                  /* clock name for 17 hardware value */
   get_Zero_Frequency,                  /* clock name for 18 hardware value */
   get_Zero_Frequency,                  /* clock name for 19 hardware value */
   get_Zero_Frequency,                  /* clock name for 20 hardware value */
   get_Zero_Frequency,                  /* clock name for 21 hardware value */
   get_Zero_Frequency,                  /* clock name for 22 hardware value */
   get_Zero_Frequency,                  /* clock name for 23 hardware value */
   get_Zero_Frequency,                  /* clock name for 24 hardware value */
   get_Zero_Frequency,                  /* clock name for 25 hardware value */
   get_Zero_Frequency,                  /* clock name for 26 hardware value */
   get_Zero_Frequency,                  /* clock name for 27 hardware value */
   get_Zero_Frequency,                  /* clock name for 28 hardware value */
   get_Zero_Frequency,                  /* clock name for 29 hardware value */
   get_Zero_Frequency,                  /* clock name for 30 hardware value */
   get_Zero_Frequency,                  /* clock name for 31 hardware value */
   get_Zero_Frequency,                  /* clock name for 32 hardware value */
   get_Zero_Frequency,                  /* clock name for 33 hardware value */
   get_Zero_Frequency,                  /* clock name for 34 hardware value */
   get_Zero_Frequency,                  /* clock name for 35 hardware value */
   get_Zero_Frequency,                  /* clock name for 36 hardware value */
   get_Zero_Frequency,                  /* clock name for 37 hardware value */
   get_Zero_Frequency,                  /* clock name for 38 hardware value */
   get_gmac_0_ext_ref_Frequency,        /* clock name for 39 hardware value */
   get_Zero_Frequency,                  /* clock name for 40 hardware value */
   get_Zero_Frequency,                  /* clock name for 41 hardware value */
   get_Zero_Frequency,                  /* clock name for 42 hardware value */
   get_Zero_Frequency,                  /* clock name for 43 hardware value */
   get_Zero_Frequency,                  /* clock name for 44 hardware value */
   get_Zero_Frequency,                  /* clock name for 45 hardware value */
   get_Zero_Frequency,                  /* clock name for 46 hardware value */
   get_Zero_Frequency,                  /* clock name for 47 hardware value */
   get_Zero_Frequency,                  /* clock name for 48 hardware value */
   get_Zero_Frequency,                  /* clock name for 49 hardware value */
   get_Zero_Frequency,                  /* clock name for 50 hardware value */
   get_Zero_Frequency,                  /* clock name for 51 hardware value */
   get_Zero_Frequency,                  /* clock name for 52 hardware value */
   get_Zero_Frequency,                  /* clock name for 53 hardware value */
   get_Zero_Frequency,                  /* clock name for 54 hardware value */
   get_Zero_Frequency,                  /* clock name for 55 hardware value */
   get_Zero_Frequency,                  /* clock name for 56 hardware value */
   get_Zero_Frequency,                  /* clock name for 57 hardware value */
   get_gmac_1_ext_ref_Frequency,        /* clock name for 58 hardware value */
   get_Zero_Frequency,                  /* clock name for 59 hardware value */
   get_Zero_Frequency,                  /* clock name for 60 hardware value */
   get_Zero_Frequency,                  /* clock name for 61 hardware value */
   get_Zero_Frequency,                  /* clock name for 62 hardware value */
   get_Zero_Frequency,                  /* clock name for 63 hardware value */
};

static const getFreqType Clock_Ip_apfFreqTable[CLOCK_IP_NAMES_NO] =

{
    get_FIRC_CLK_Frequency,                       /* FIRC_CLK             */
    get_FXOSC_CLK_Frequency,                      /* FXOSC_CLK            */
    get_SIRC_CLK_Frequency,                       /* SIRC_CLK             */
    get_COREPLL_CLK_Frequency,                    /* COREPLL_CLK          */
    get_PERIPHPLL_CLK_Frequency,                  /* PERIPHPLL_CLK        */
    get_DDRPLL_CLK_Frequency,                     /* DDRPLL_CLK           */
    get_ACCELPLL_CLK_Frequency,                   /* ACCELPLL_CLK         */
    get_COREPLL_PHI0_Frequency,                   /* COREPLL_PHI0         */
    get_COREPLL_PHI1_Frequency,                   /* COREPLL_PHI1         */
    get_COREPLL_DFS1_Frequency,                   /* COREPLL_DFS1         */
    get_COREPLL_DFS2_Frequency,                   /* COREPLL_DFS2         */
    get_COREPLL_DFS3_Frequency,                   /* COREPLL_DFS3         */
    get_COREPLL_DFS4_Frequency,                   /* COREPLL_DFS4         */
    get_COREPLL_DFS5_Frequency,                   /* COREPLL_DFS5         */
    get_COREPLL_DFS6_Frequency,                   /* COREPLL_DFS6         */
    get_PERIPHPLL_PHI0_Frequency,                 /* PERIPHPLL_PHI0       */
    get_PERIPHPLL_PHI1_Frequency,                 /* PERIPHPLL_PHI1       */
    get_PERIPHPLL_PHI2_Frequency,                 /* PERIPHPLL_PHI2       */
    get_PERIPHPLL_PHI3_Frequency,                 /* PERIPHPLL_PHI3       */
    get_PERIPHPLL_PHI4_Frequency,                 /* PERIPHPLL_PHI4       */
    get_PERIPHPLL_PHI5_Frequency,                 /* PERIPHPLL_PHI5       */
    get_PERIPHPLL_PHI6_Frequency,                 /* PERIPHPLL_PHI6       */
    get_PERIPHPLL_PHI7_Frequency,                 /* PERIPHPLL_PHI7       */
    get_PERIPHPLL_DFS1_Frequency,                 /* PERIPHPLL_DFS1       */
    get_PERIPHPLL_DFS2_Frequency,                 /* PERIPHPLL_DFS2       */
    get_PERIPHPLL_DFS3_Frequency,                 /* PERIPHPLL_DFS3       */
    get_PERIPHPLL_DFS4_Frequency,                 /* PERIPHPLL_DFS4       */
    get_PERIPHPLL_DFS5_Frequency,                 /* PERIPHPLL_DFS5       */
    get_PERIPHPLL_DFS6_Frequency,                 /* PERIPHPLL_DFS6       */
    get_DDRPLL_PHI0_Frequency,                    /* DDRPLL_PHI0          */
    get_ACCELPLL_PHI0_Frequency,                  /* ACCELPLL_PHI0        */
    get_ACCELPLL_PHI1_Frequency,                  /* ACCELPLL_PHI1        */
    get_ftm_0_ext_ref_Frequency,                  /* ftm_0_ext_ref        */
    get_ftm_1_ext_ref_Frequency,                  /* ftm_1_ext_ref        */
    get_gmac_0_ext_ref_Frequency,                 /* gmac_0_ext_ref       */
    get_gmac_0_ext_rx_Frequency,                  /* gmac_0_ext_rx        */
    get_gmac_0_ext_tx_Frequency,                  /* gmac_0_ext_tx        */
    get_gmac_ext_ts_Frequency,                    /* gmac_ext_ts          */
    get_gmac_1_ext_tx_Frequency,                  /* gmac_0_ext_tx        */
    get_gmac_1_ext_rx_Frequency,                  /* gmac_0_ext_rx        */
    get_gmac_1_ext_ref_Frequency,                 /* gmac_0_ext_ref       */
    get_SERDES_0_LANE_0_TX_Frequency,             /* SERDES_0_LANE_0_TX   */
    get_SERDES_0_LANE_0_CDR_Frequency,            /* SERDES_0_LANE_0_CDR  */
    get_SERDES_1_LANE_0_TX_Frequency,             /* SERDES_1_LANE_0_TX   */
    get_SERDES_1_LANE_0_CDR_Frequency,            /* SERDES_1_LANE_0_CDR  */
    get_XBAR_2X_CLK_Frequency,                    /* XBAR_2X_CLK          */
    get_XBAR_CLK_Frequency,                       /* XBAR_CLK             */
    get_XBAR_DIV2_CLK_Frequency,                  /* XBAR_DIV2_CLK        */
    get_XBAR_DIV3_CLK_Frequency,                  /* XBAR_DIV3_CLK        */
    get_XBAR_DIV4_CLK_Frequency,                  /* XBAR_DIV4_CLK        */
    get_XBAR_DIV6_CLK_Frequency,                  /* XBAR_DIV6_CLK        */
    get_A53_CORE_CLK_Frequency,                   /* A53_CORE_CLK         */
    get_A53_CORE_DIV2_CLK_Frequency,              /* A53_CORE_DIV2_CLK    */
    get_A53_CORE_DIV10_CLK_Frequency,             /* A53_CORE_DIV10_CLK   */
    get_ACCEL3_CLK_Frequency,                     /* ACCEL3_CLK           */
    get_ACCEL3_DIV3_CLK_Frequency,                /* ACCEL3_DIV3_CLK      */
    get_ACCEL4_CLK_Frequency,                     /* ACCEL4_CLK           */
    get_DDR_CLK_Frequency,                        /* DDR_CLK              */
    get_PER_CLK_Frequency,                        /* PER_CLK              */
    get_GMAC0_REF_CLK_Frequency,                  /* GMAC_0_REF_CLK       */
    get_GMAC0_REF_DIV_CLK_Frequency,              /* GMAC0_REF_DIV_CLK   */
    get_GMAC1_REF_DIV_CLK_Frequency,              /* GMAC1_REF_DIV_CLK   */
    get_PERIPHPLL_PHI0_Frequency,                 /* SERDES0_REF_CLK clock */
    get_PERIPHPLL_PHI0_Frequency,                 /* SERDES1_REF_CLK clock */
    NULL_PTR,                                      /* THE_LAST_PRODUCER_CLK */
    get_ACCEL4_CLK_Frequency,                     /* ACCEL4_LAX0_CLK */
    get_ACCEL4_CLK_Frequency,                     /* ACCEL4_LAX1_CLK */
    get_PER_CLK_Frequency,                        /* ADC0_CLK */
    get_PER_CLK_Frequency,                        /* ADC1_CLK */
    get_CLKOUT0_CLK_Frequency,                    /* CLKOUT0_CLK */
    get_CLKOUT1_CLK_Frequency,                    /* CLKOUT1_CLK */
    get_A53_CORE_CLK_Frequency,                   /* CORE_A53_CLUSTER_0_CLK */
    get_A53_CORE_CLK_Frequency,                   /* CORE_A53_CLUSTER_1_CLK */
    get_XBAR_CLK_Frequency,                       /* CORE_M7_0_CLK */
    get_XBAR_CLK_Frequency,                       /* CORE_M7_1_CLK */
    get_XBAR_CLK_Frequency,                       /* CORE_M7_2_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* CRC0_CLK */
    get_PER_CLK_Frequency,                        /* CTU0_CLK */
    get_DDR_CLK_Frequency,                        /* DDR0_CLK */
    get_XBAR_CLK_Frequency,                       /* DMA0_CLK */
    get_XBAR_CLK_Frequency,                       /* DMA1_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* DMAMUX0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* DMAMUX1_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* DMAMUX2_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* DMAMUX3_CLK */
    get_XBAR_CLK_Frequency,                       /* DMA_CRC0_CLK */
    get_XBAR_CLK_Frequency,                       /* DMA_CRC1_CLK */
    get_A53_CORE_DIV10_CLK_Frequency,             /* EIM0_CLK */
    get_XBAR_DIV6_CLK_Frequency,                  /* EIM1_CLK */
    get_XBAR_DIV6_CLK_Frequency,                  /* EIM2_CLK */
    get_XBAR_DIV6_CLK_Frequency,                  /* EIM3_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* EIM_BBE32DSP_CLK clock */
    get_XBAR_DIV3_CLK_Frequency,                  /* EIM_LAX0_CLK clock */
    get_XBAR_DIV3_CLK_Frequency,                  /* EIM_LAX1_CLK clock */
    get_XBAR_DIV3_CLK_Frequency,                  /* EIM_PER1_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* EIM_CLK */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_CPU0_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_CPU1_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_CPU2_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_EDMA0_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_EDMA1_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_LAX0_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_LAX1_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_PER_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM_PER1_CLK clock */
    get_XBAR_DIV6_CLK_Frequency,                  /* ERM0_CLK */
    get_XBAR_CLK_Frequency,                       /* FDMA0_CLK clock */
    get_FLEXCAN_CLK_Frequency,                    /* FLEXCAN_CLK */
    get_FLEXCAN0_CLK_Frequency,                   /* FLEXCAN0_CLK */
    get_FLEXCAN1_CLK_Frequency,                   /* FLEXCAN1_CLK */
    get_FLEXCAN2_CLK_Frequency,                   /* FLEXCAN2_CLK */
    get_FLEXCAN3_CLK_Frequency,                   /* FLEXCAN3_CLK */
    get_FLEXCAN4_CLK_Frequency,                   /* FLEXCAN4_CLK */
    get_FLEXCAN5_CLK_Frequency,                   /* FLEXCAN5_CLK */
    get_FLEXCAN6_CLK_Frequency,                   /* FLEXCAN6_CLK */
    get_FLEXCAN7_CLK_Frequency,                   /* FLEXCAN7_CLK */
    get_FLEXRAY_CLK_Frequency,                    /* FLEXRAY_CLK */
    get_FRAY0_CLK_Frequency,                      /* FRAY0_CLK */
    get_FLEXTIMERA_CLK_Frequency,                 /* FLEXTIMERA_CLK */
    get_FTIMER0_CLK_Frequency,                    /* FTIMER0_CLK */
    get_FLEXTIMERB_CLK_Frequency,                 /* FLEXTIMERB_CLK */
    get_FTIMER1_CLK_Frequency,                    /* FTIMER1_CLK */
    get_GMAC_TS_CLK_Frequency,                    /* GMAC_TS_CLK */
    get_GMAC0_TS_CLK_Frequency,                   /* GMAC0_TS_CLK */
    get_GMAC0_RX_CLK_Frequency,                   /* GMAC0_RX_CLK */
    get_GMAC0_TX_CLK_Frequency,                   /* GMAC0_TX_CLK */
    get_GMAC1_TS_CLK_Frequency,                   /* GMAC1_TS_CLK */
    get_GMAC1_RX_CLK_Frequency,                   /* GMAC1_RX_CLK */
    get_GMAC1_TX_CLK_Frequency,                   /* GMAC1_TX_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* IIC0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* IIC1_CLK */
    get_LBIST_CLK_Frequency,                      /* LBIST_CLK */
    get_LBIST0_CLK_Frequency,                     /* LBIST0_CLK */
    get_LBIST1_CLK_Frequency,                     /* LBIST1_CLK */
    get_LBIST2_CLK_Frequency,                     /* LBIST2_CLK */
    get_LBIST3_CLK_Frequency,                     /* LBIST3_CLK */
    get_LBIST4_CLK_Frequency,                     /* LBIST4_CLK */
    get_LBIST5_CLK_Frequency,                     /* LBIST5_CLK */
    get_LBIST6_CLK_Frequency,                     /* LBIST6_CLK */
    get_LBIST7_CLK_Frequency,                     /* LBIST7_CLK */
    get_LIN_BAUD_CLK_Frequency,                   /* LIN_BAUD_CLK clock */
    get_LINFLEX_CLK_Frequency,                    /* LINFLEX_CLK */
    get_LIN0_CLK_Frequency,                       /* LIN0_CLK */
    get_LIN1_CLK_Frequency,                       /* LIN1_CLK */
    get_FIRC_CLK_Frequency,                       /* OCOTP0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* PIT0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* PIT1_CLK */
    get_QSPI_2X_CLK_Frequency,                    /* QSPI_2X_CLK */
    get_QSPI_1X_CLK_Frequency,                    /* QSPI_1X_CLK */
    get_QSPI0_CLK_Frequency,                      /* QSPI0_CLK */
    get_FIRC_CLK_Frequency,                       /* SIUL0_CLK */
    get_FIRC_CLK_Frequency,                       /* SIUL1_CLK */
    get_SPI_CLK_Frequency,                        /* SPI_CLK */
    get_SPI0_CLK_Frequency,                       /* SPI0_CLK */
    get_SPI1_CLK_Frequency,                       /* SPI1_CLK */
    get_SPI2_CLK_Frequency,                       /* SPI2_CLK */
    get_SPI3_CLK_Frequency,                       /* SPI3_CLK */
    get_SPI4_CLK_Frequency,                       /* SPI4_CLK */
    get_SPI5_CLK_Frequency,                       /* SPI5_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM1_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM2_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM3_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM4_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM5_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM6_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* STM7_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT0_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT1_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT2_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT3_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT4_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT5_CLK */
    get_FIRC_CLK_Frequency,                       /* SWT6_CLK */
    get_USDHC_CLK_Frequency,                      /* USDHC_CLK */
    get_USDHC0_CLK_Frequency,                     /* USDHC0_CLK */
    get_XBAR_DIV6_CLK_Frequency,                  /* WKPU0_CLK */
    get_XBAR_DIV3_CLK_Frequency,                  /* XBAR_DIV3_FAIL_CLK */
    get_XBAR_CLK_Frequency,                       /* XBAR_MIPICSI201_CLK clock */
    get_XBAR_CLK_Frequency,                       /* XBAR_MIPICSI223_CLK clock */
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/* External oscillators */
static uint32 Clock_Ip_u32Fxosc = CLOCK_IP_DEFAULT_FXOSC_FREQUENCY;
static extSignalFreq Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_EXT_SIGNALS_NO] =  {{FTM_0_EXT_REF_CLK,0U},{FTM_1_EXT_REF_CLK,0U},{GMAC_0_EXT_REF_CLK,0U},{GMAC_0_EXT_RX_CLK,0U},{GMAC_0_EXT_TX_CLK,0U},{GMAC_1_EXT_REF_CLK,0U},{GMAC_1_EXT_RX_CLK,0U},{GMAC_1_EXT_TX_CLK,0U},{GMAC_EXT_TS_CLK,0U},{SERDES_0_LANE_0_TX,0U},{SERDES_0_LANE_0_CDR,0U},{SERDES_1_LANE_0_TX,0U},{SERDES_1_LANE_0_CDR,0U}};
static uint32 Clock_Ip_u32CorePllFreq        = CLOCK_IP_COREPLL_FREQ;
static uint32 Clock_Ip_u32CorePllChecksum    = CLOCK_IP_COREPLL_CHECKSUM;
static uint32 Clock_Ip_u32PeriphPllFreq      = CLOCK_IP_PERIPHPLL_FREQ;
static uint32 Clock_Ip_u32PeriphPllChecksum  = CLOCK_IP_PERIPHPLL_CHECKSUM;
static uint32 Clock_Ip_u32DdrPllFreq         = CLOCK_IP_DDRPLL_FREQ;
static uint32 Clock_Ip_u32DdrPllChecksum     = CLOCK_IP_DDRPLL_CHECKSUM;
static uint32 Clock_Ip_u32AccelPllFreq       = CLOCK_IP_ACCELPLL_FREQ;
static uint32 Clock_Ip_u32AccelPllChecksum   = CLOCK_IP_ACCELPLL_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs1Freq       = CLOCK_IP_COREDFS1_FREQ;
static uint32 Clock_Ip_u32CoreDfs1Checksum   = CLOCK_IP_COREDFS1_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs2Freq       = CLOCK_IP_COREDFS2_FREQ;
static uint32 Clock_Ip_u32CoreDfs2Checksum   = CLOCK_IP_COREDFS2_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs3Freq       = CLOCK_IP_COREDFS3_FREQ;
static uint32 Clock_Ip_u32CoreDfs3Checksum   = CLOCK_IP_COREDFS3_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs4Freq       = CLOCK_IP_COREDFS4_FREQ;
static uint32 Clock_Ip_u32CoreDfs4Checksum   = CLOCK_IP_COREDFS4_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs5Freq       = CLOCK_IP_COREDFS5_FREQ;
static uint32 Clock_Ip_u32CoreDfs5Checksum   = CLOCK_IP_COREDFS5_CHECKSUM;
static uint32 Clock_Ip_u32CoreDfs6Freq       = CLOCK_IP_COREDFS6_FREQ;
static uint32 Clock_Ip_u32CoreDfs6Checksum   = CLOCK_IP_COREDFS6_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs1Freq     = CLOCK_IP_PERIPHDFS1_FREQ;
static uint32 Clock_Ip_u32PeriphDfs1Checksum = CLOCK_IP_PERIPHDFS1_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs2Freq     = CLOCK_IP_PERIPHDFS2_FREQ;
static uint32 Clock_Ip_u32PeriphDfs2Checksum = CLOCK_IP_PERIPHDFS2_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs3Freq     = CLOCK_IP_PERIPHDFS3_FREQ;
static uint32 Clock_Ip_u32PeriphDfs3Checksum = CLOCK_IP_PERIPHDFS3_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs4Freq     = CLOCK_IP_PERIPHDFS4_FREQ;
static uint32 Clock_Ip_u32PeriphDfs4Checksum = CLOCK_IP_PERIPHDFS4_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs5Freq     = CLOCK_IP_PERIPHDFS5_FREQ;
static uint32 Clock_Ip_u32PeriphDfs5Checksum = CLOCK_IP_PERIPHDFS5_CHECKSUM;
static uint32 Clock_Ip_u32PeriphDfs6Freq     = CLOCK_IP_PERIPHDFS6_FREQ;
static uint32 Clock_Ip_u32PeriphDfs6Checksum = CLOCK_IP_PERIPHDFS6_CHECKSUM;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static uint32 PLL_VCO(const PLLDIG_Type *Base);
static uint32 DFS_OUTPUT(const DFS_Type *Base, uint32 Channel, uint32 Fin);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Return zero frequency */
static uint32 get_Zero_Frequency(void)
{
    return 0U;
}

/* Return FIRC_CLK frequency */
static uint32 get_FIRC_CLK_Frequency(void) {

    return CLOCK_IP_FIRC_FREQUENCY;
}
/* Return FXOSC_CLK frequency */
static uint32 get_FXOSC_CLK_Frequency(void) {

    return Clock_Ip_u32Fxosc;
}
/* Return SIRC_CLK frequency */
static uint32 get_SIRC_CLK_Frequency(void) {

    return CLOCK_IP_SIRC_FREQUENCY;
}
/* Return COREPLL_CLK frequency */
static uint32 get_COREPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32CorePllChecksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD))
    {
        Clock_Ip_u32CorePllChecksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD);
        Clock_Ip_u32CorePllFreq = PLL_VCO(IP_CORE_PLL);
    }
    return (((IP_CORE_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32CorePllFreq : 0U;
}
/* Return PERIPHPLL_CLK frequency */
static uint32 get_PERIPHPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32PeriphPllChecksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD))
    {
        Clock_Ip_u32PeriphPllChecksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD);
        Clock_Ip_u32PeriphPllFreq = PLL_VCO(IP_PERIPH_PLL);
    }
    return (((IP_PERIPH_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32PeriphPllFreq : 0U;
}
/* Return DDRPLL_CLK frequency */
static uint32 get_DDRPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32DdrPllChecksum != (IP_DDR_PLL->PLLCLKMUX ^ IP_DDR_PLL->PLLDV ^ IP_DDR_PLL->PLLFD))
    {
        Clock_Ip_u32DdrPllChecksum = (IP_DDR_PLL->PLLCLKMUX ^ IP_DDR_PLL->PLLDV ^ IP_DDR_PLL->PLLFD);
        Clock_Ip_u32DdrPllFreq = PLL_VCO(IP_DDR_PLL);
    }
    return (((IP_DDR_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32DdrPllFreq : 0U;
}
/* Return ACCELPLL_CLK frequency */
static uint32 get_ACCELPLL_CLK_Frequency(void) {

    if (Clock_Ip_u32AccelPllChecksum != (IP_ACCEL_PLL->PLLCLKMUX ^ IP_ACCEL_PLL->PLLDV ^ IP_ACCEL_PLL->PLLFD))
    {
        Clock_Ip_u32AccelPllChecksum = (IP_ACCEL_PLL->PLLCLKMUX ^ IP_ACCEL_PLL->PLLDV ^ IP_ACCEL_PLL->PLLFD);
        Clock_Ip_u32AccelPllFreq = PLL_VCO(IP_ACCEL_PLL);
    }
    return (((IP_ACCEL_PLL->PLLSR & PLLDIG_PLLSR_LOCK_MASK) >> PLLDIG_PLLSR_LOCK_SHIFT) != 0U) ? Clock_Ip_u32AccelPllFreq : 0U;
}
/* Return COREPLL_PHI0 frequency */
static uint32 get_COREPLL_PHI0_Frequency(void) {

    uint32 Frequency = get_COREPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_CORE_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_CORE_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return COREPLL_PHI1 frequency */
static uint32 get_COREPLL_PHI1_Frequency(void) {

    uint32 Frequency = get_COREPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_CORE_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_CORE_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return COREPLL_DFS1 frequency */
static uint32 get_COREPLL_DFS1_Frequency(void) {

    if (Clock_Ip_u32CoreDfs1Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[0U]))
    {
        Clock_Ip_u32CoreDfs1Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[0U]);
        Clock_Ip_u32CoreDfs1Freq = DFS_OUTPUT(IP_CORE_DFS,0U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_0_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs1Freq : 0U;
}
/* Return COREPLL_DFS2 frequency */
static uint32 get_COREPLL_DFS2_Frequency(void) {

    if (Clock_Ip_u32CoreDfs2Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[1U]))
    {
        Clock_Ip_u32CoreDfs2Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[1U]);
        Clock_Ip_u32CoreDfs2Freq = DFS_OUTPUT(IP_CORE_DFS,1U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_1_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs2Freq : 0U;
}
/* Return COREPLL_DFS3 frequency */
static uint32 get_COREPLL_DFS3_Frequency(void) {

    if (Clock_Ip_u32CoreDfs3Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[2U]))
    {
        Clock_Ip_u32CoreDfs3Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[2U]);
        Clock_Ip_u32CoreDfs3Freq = DFS_OUTPUT(IP_CORE_DFS,2U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_2_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs3Freq : 0U;
}
/* Return COREPLL_DFS4 frequency */
static uint32 get_COREPLL_DFS4_Frequency(void) {

    if (Clock_Ip_u32CoreDfs4Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[3U]))
    {
        Clock_Ip_u32CoreDfs4Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[3U]);
        Clock_Ip_u32CoreDfs4Freq = DFS_OUTPUT(IP_CORE_DFS,3U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_3_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs4Freq : 0U;
}
/* Return COREPLL_DFS5 frequency */
static uint32 get_COREPLL_DFS5_Frequency(void) {

    if (Clock_Ip_u32CoreDfs5Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[4U]))
    {
        Clock_Ip_u32CoreDfs5Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[4U]);
        Clock_Ip_u32CoreDfs5Freq = DFS_OUTPUT(IP_CORE_DFS,4U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_4_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs5Freq : 0U;
}
/* Return COREPLL_DFS6 frequency */
static uint32 get_COREPLL_DFS6_Frequency(void) {

    if (Clock_Ip_u32CoreDfs6Checksum != (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[5U]))
    {
        Clock_Ip_u32CoreDfs6Checksum = (IP_CORE_PLL->PLLCLKMUX ^ IP_CORE_PLL->PLLDV ^ IP_CORE_PLL->PLLFD ^ IP_CORE_PLL->PLLSR ^ IP_CORE_DFS->DVPORT[5U]);
        Clock_Ip_u32CoreDfs6Freq = DFS_OUTPUT(IP_CORE_DFS,5U,get_COREPLL_CLK_Frequency());
    }
    return ((((IP_CORE_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_5_CHANNEL) != 0U) ? Clock_Ip_u32CoreDfs6Freq : 0U;
}
/* Return PERIPHPLL_PHI0 frequency */
static uint32 get_PERIPHPLL_PHI0_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI1 frequency */
static uint32 get_PERIPHPLL_PHI1_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI2 frequency */
static uint32 get_PERIPHPLL_PHI2_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[2U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI3 frequency */
static uint32 get_PERIPHPLL_PHI3_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[3U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI4 frequency */
static uint32 get_PERIPHPLL_PHI4_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[4U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI5 frequency */
static uint32 get_PERIPHPLL_PHI5_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[5U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI6 frequency */
static uint32 get_PERIPHPLL_PHI6_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[6U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_PHI7 frequency */
static uint32 get_PERIPHPLL_PHI7_Frequency(void) {

    uint32 Frequency = get_PERIPHPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PERIPH_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_PERIPH_PLL->PLLODIV[7U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return PERIPHPLL_DFS1 frequency */
static uint32 get_PERIPHPLL_DFS1_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs1Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[0U]))
    {
        Clock_Ip_u32PeriphDfs1Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[0U]);
        Clock_Ip_u32PeriphDfs1Freq = DFS_OUTPUT(IP_PERIPH_DFS,0U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_0_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs1Freq : 0U;
}
/* Return PERIPHPLL_DFS2 frequency */
static uint32 get_PERIPHPLL_DFS2_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs2Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[1U]))
    {
        Clock_Ip_u32PeriphDfs2Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[1U]);
        Clock_Ip_u32PeriphDfs2Freq = DFS_OUTPUT(IP_PERIPH_DFS,1U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_1_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs2Freq : 0U;
}
/* Return PERIPHPLL_DFS3 frequency */
static uint32 get_PERIPHPLL_DFS3_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs3Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[2U]))
    {
        Clock_Ip_u32PeriphDfs3Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[2U]);
        Clock_Ip_u32PeriphDfs3Freq = DFS_OUTPUT(IP_PERIPH_DFS,2U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_2_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs3Freq : 0U;
}
/* Return PERIPHPLL_DFS4 frequency */
static uint32 get_PERIPHPLL_DFS4_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs4Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[3U]))
    {
        Clock_Ip_u32PeriphDfs4Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[3U]);
        Clock_Ip_u32PeriphDfs4Freq = DFS_OUTPUT(IP_PERIPH_DFS,3U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_3_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs4Freq : 0U;
}
/* Return PERIPHPLL_DFS5 frequency */
static uint32 get_PERIPHPLL_DFS5_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs5Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[4U]))
    {
        Clock_Ip_u32PeriphDfs5Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[4U]);
        Clock_Ip_u32PeriphDfs5Freq = DFS_OUTPUT(IP_PERIPH_DFS,4U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_4_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs5Freq : 0U;
}
/* Return PERIPHPLL_DFS6 frequency */
static uint32 get_PERIPHPLL_DFS6_Frequency(void) {

    if (Clock_Ip_u32PeriphDfs6Checksum != (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[5U]))
    {
        Clock_Ip_u32PeriphDfs6Checksum = (IP_PERIPH_PLL->PLLCLKMUX ^ IP_PERIPH_PLL->PLLDV ^ IP_PERIPH_PLL->PLLFD ^ IP_PERIPH_PLL->PLLSR ^ IP_PERIPH_DFS->DVPORT[5U]);
        Clock_Ip_u32PeriphDfs6Freq = DFS_OUTPUT(IP_PERIPH_DFS,5U,get_PERIPHPLL_CLK_Frequency());
    }
    return ((((IP_PERIPH_DFS->PORTSR >> DFS_PORTSR_PORTSTAT_SHIFT) & DFS_PORTSR_PORTSTAT_MASK) & CLOCK_IP_DFS_MASK_5_CHANNEL) != 0U) ? Clock_Ip_u32PeriphDfs6Freq : 0U;
}
/* Return DDRPLL_PHI0 frequency */
static uint32 get_DDRPLL_PHI0_Frequency(void) {

    uint32 Frequency = get_DDRPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_DDR_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_DDR_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return ACCELPLL_PHI0 frequency */
static uint32 get_ACCELPLL_PHI0_Frequency(void) {

    uint32 Frequency = get_ACCELPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_ACCEL_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_ACCEL_PLL->PLLODIV[0U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return ACCELPLL_PHI1 frequency */
static uint32 get_ACCELPLL_PHI1_Frequency(void) {

    uint32 Frequency = get_ACCELPLL_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_ACCEL_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DE_MASK) >> PLLDIG_PLLODIV_DE_SHIFT)];                                    /*  Divider enable/disable */
    Frequency /= (((IP_ACCEL_PLL->PLLODIV[1U] & PLLDIG_PLLODIV_DIV_MASK) >> PLLDIG_PLLODIV_DIV_SHIFT) + 1U);                                          /*  Apply divider value */
    return Frequency;
}
/* Return ftm_0_ext_ref frequency */
static uint32 get_ftm_0_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_FTM_0_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
/* Return ftm_1_ext_ref frequency */
static uint32 get_ftm_1_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_FTM_1_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_0_ext_ref frequency */
static uint32 get_gmac_0_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_0_ext_rx frequency */
static uint32 get_gmac_0_ext_rx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_RX_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_0_ext_tx frequency */
static uint32 get_gmac_0_ext_tx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_0_EXT_TX_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_1_ext_ref frequency */
static uint32 get_gmac_1_ext_ref_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_REF_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_1_ext_rx frequency */
static uint32 get_gmac_1_ext_rx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_RX_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_1_ext_tx frequency */
static uint32 get_gmac_1_ext_tx_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_1_EXT_TX_CLK_INDEX_ENTRY].Frequency;
}
/* Return gmac_ext_ts frequency */
static uint32 get_gmac_ext_ts_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_GMAC_EXT_TS_CLK_INDEX_ENTRY].Frequency;
}
/* Return SERDES_0_LANE_0_TX frequency */
static uint32 get_SERDES_0_LANE_0_TX_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_SERDES_0_LANE_0_TX_INDEX_ENTRY].Frequency;
}
/* Return SERDES_0_LANE_0_CDR frequency */
static uint32 get_SERDES_0_LANE_0_CDR_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_SERDES_0_LANE_0_CDR_INDEX_ENTRY].Frequency;
}
/* Return SERDES_1_LANE_0_TX frequency */
static uint32 get_SERDES_1_LANE_0_TX_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_SERDES_1_LANE_0_TX_INDEX_ENTRY].Frequency;
}
/* Return SERDES_1_LANE_0_CDR frequency */
static uint32 get_SERDES_1_LANE_0_CDR_Frequency(void) {

    return Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_SERDES_1_LANE_0_CDR_INDEX_ENTRY].Frequency;
}
/* Return XBAR_2X_CLK frequency */
static uint32 get_XBAR_2X_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)]();                 /*  Selector value */
}
/* Return XBAR_CLK frequency */
static uint32 get_XBAR_CLK_Frequency(void) {

    return get_XBAR_2X_CLK_Frequency() >> 1U;
}
/* Return XBAR_DIV2_CLK frequency */
static uint32 get_XBAR_DIV2_CLK_Frequency(void) {

    return get_XBAR_2X_CLK_Frequency() >> 2U;
}
/* Return XBAR_DIV3_CLK frequency */
static uint32 get_XBAR_DIV3_CLK_Frequency(void) {

    return get_XBAR_2X_CLK_Frequency() / 6U;
}
/* Return XBAR_DIV4_CLK frequency */
static uint32 get_XBAR_DIV4_CLK_Frequency(void) {

    return get_XBAR_2X_CLK_Frequency() >> 3U;
}
/* Return XBAR_DIV6_CLK frequency */
static uint32 get_XBAR_DIV6_CLK_Frequency(void) {

    return get_XBAR_2X_CLK_Frequency() / 12U;
}
/* Return A53_CORE_CLK frequency */
static uint32 get_A53_CORE_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_1->MUX_0_CSS & MC_CGM_1_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_1_MUX_0_CSS_SELSTAT_SHIFT)]();                 /*  Selector value */
}
/* Return A53_CORE_DIV2_CLK frequency */
static uint32 get_A53_CORE_DIV2_CLK_Frequency(void) {

    return get_A53_CORE_CLK_Frequency() >> 1U;
}
/* Return A53_CORE_DIV10_CLK frequency */
static uint32 get_A53_CORE_DIV10_CLK_Frequency(void) {

    return get_A53_CORE_CLK_Frequency() / 10U;
}
/* Return ACCEL3_CLK frequency */
static uint32 get_ACCEL3_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_0_CSS & MC_CGM_2_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_0_CSS_SELSTAT_SHIFT)]();                    /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_2->MUX_0_DC_0 & MC_CGM_2_MUX_0_DC_0_DE_MASK) >> MC_CGM_2_MUX_0_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_0_DC_0 & MC_CGM_2_MUX_0_DC_0_DIV_MASK) >> MC_CGM_2_MUX_0_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return ACCEL3_DIV3_CLK frequency */
static uint32 get_ACCEL3_DIV3_CLK_Frequency(void) {

    return get_ACCEL3_CLK_Frequency() / 3U;
}
/* Return ACCEL4_CLK frequency */
static uint32 get_ACCEL4_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_1_CSS & MC_CGM_2_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_1_CSS_SELSTAT_SHIFT)]();                    /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_2->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DE_MASK) >> MC_CGM_MUX_1_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_1_DC_0 & MC_CGM_2_MUX_1_DC_0_DIV_MASK) >> MC_CGM_2_MUX_1_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return DDR_CLK frequency */
static uint32 get_DDR_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_5->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)]();                    /*  Selector value */
}
/* Return PER_CLK frequency */
static uint32 get_PER_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();                    /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DE_MASK) >> MC_CGM_MUX_3_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DIV_MASK) >> MC_CGM_MUX_3_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return GMAC_0_REF_CLK frequency */
static uint32 get_GMAC0_REF_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_15_CSS & MC_CGM_MUX_15_CSS_SELSTAT_MASK) >> MC_CGM_MUX_15_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    return Frequency;
}
/* Return GMAC0_REF_DIV_CLK frequency */
static uint32 get_GMAC0_REF_DIV_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc_1[((IP_MC_CGM_0->MUX_15_CSS & MC_CGM_MUX_15_CSS_SELSTAT_MASK) >> MC_CGM_MUX_15_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_15_DC_0 & MC_CGM_MUX_15_DC_0_DE_MASK) >> MC_CGM_MUX_15_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_15_DC_0 & MC_CGM_MUX_15_DC_0_DIV_MASK) >> MC_CGM_MUX_15_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return GMAC1_REF_DIV_CLK frequency */
static uint32 get_GMAC1_REF_DIV_CLK_Frequency(void) {

    uint32 Frequency = Clock_Ip_apfFreqTableClkSrc_1[((IP_MC_CGM_2->MUX_3_CSS & MC_CGM_MUX_3_CSS_SELSTAT_MASK) >> MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)]();                    /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_2->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DE_MASK) >> MC_CGM_MUX_3_DC_0_DE_SHIFT)];                               /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_3_DC_0 & MC_CGM_MUX_3_DC_0_DIV_MASK) >> MC_CGM_MUX_3_DC_0_DIV_SHIFT) + 1U);                                     /*  Apply divider value */
    return Frequency;
}
/* Return CLKOUT0_CLK frequency */
static uint32 get_CLKOUT0_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_1_CSS & MC_CGM_MUX_1_CSS_SELSTAT_MASK) >> MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DE_MASK) >> MC_CGM_MUX_1_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_1_DC_0 & MC_CGM_MUX_1_DC_0_DIV_MASK) >> MC_CGM_MUX_1_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return CLKOUT1_CLK frequency */
static uint32 get_CLKOUT1_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_2_CSS & MC_CGM_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_MUX_2_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_2_DC_0 & MC_CGM_MUX_2_DC_0_DE_MASK) >> MC_CGM_MUX_2_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_2_DC_0 & MC_CGM_MUX_2_DC_0_DIV_MASK) >> MC_CGM_MUX_2_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return FLEXCAN_CLK frequency */
static uint32 get_FLEXCAN_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_7_CSS & MC_CGM_MUX_7_CSS_SELSTAT_MASK) >> MC_CGM_MUX_7_CSS_SELSTAT_SHIFT)]();                  /*  Selector value */
}
/* Return FLEXCAN0_CLK frequency */
static uint32 get_FLEXCAN0_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN1_CLK frequency */
static uint32 get_FLEXCAN1_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN2_CLK frequency */
static uint32 get_FLEXCAN2_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN3_CLK frequency */
static uint32 get_FLEXCAN3_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN4_CLK frequency */
static uint32 get_FLEXCAN4_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN5_CLK frequency */
static uint32 get_FLEXCAN5_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN6_CLK frequency */
static uint32 get_FLEXCAN6_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXCAN7_CLK frequency */
static uint32 get_FLEXCAN7_CLK_Frequency(void) {

    return get_FLEXCAN_CLK_Frequency();
}
/* Return FLEXRAY_CLK frequency */
static uint32 get_FLEXRAY_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_6_CSS & MC_CGM_MUX_6_CSS_SELSTAT_MASK) >> MC_CGM_MUX_6_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_6_DC_0 & MC_CGM_MUX_6_DC_0_DE_MASK) >> MC_CGM_MUX_6_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_6_DC_0 & MC_CGM_MUX_6_DC_0_DIV_MASK) >> MC_CGM_MUX_6_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return FRAY0_CLK frequency */
static uint32 get_FRAY0_CLK_Frequency(void) {

    return get_FLEXRAY_CLK_Frequency();
}
/* Return FLEXTIMERA_CLK frequency */
static uint32 get_FLEXTIMERA_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_4_CSS & MC_CGM_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_MUX_4_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DE_MASK) >> MC_CGM_MUX_4_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_4_DC_0 & MC_CGM_MUX_4_DC_0_DIV_MASK) >> MC_CGM_MUX_4_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return FTIMER0_CLK frequency */
static uint32 get_FTIMER0_CLK_Frequency(void) {

    return get_FLEXTIMERA_CLK_Frequency();
}
/* Return FLEXTIMERB_CLK frequency */
static uint32 get_FLEXTIMERB_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_5_CSS & MC_CGM_MUX_5_CSS_SELSTAT_MASK) >> MC_CGM_MUX_5_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_MUX_5_DC_0_DE_MASK) >> MC_CGM_MUX_5_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_5_DC_0 & MC_CGM_MUX_5_DC_0_DIV_MASK) >> MC_CGM_MUX_5_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return FTIMER1_CLK frequency */
static uint32 get_FTIMER1_CLK_Frequency(void) {

    return get_FLEXTIMERB_CLK_Frequency();
}
/* Return GMAC0_RX_CLK frequency */
static uint32 get_GMAC0_RX_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_11_CSS & MC_CGM_MUX_11_CSS_SELSTAT_MASK) >> MC_CGM_MUX_11_CSS_SELSTAT_SHIFT)]();               /*  Selector value */
}
/* Return GMAC_TS_CLK frequency */
static uint32 get_GMAC_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_SELSTAT_MASK) >> MC_CGM_MUX_9_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DE_MASK) >> MC_CGM_MUX_9_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DIV_MASK) >> MC_CGM_MUX_9_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return GMAC0_TS_CLK frequency */
static uint32 get_GMAC0_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_SELSTAT_MASK) >> MC_CGM_MUX_9_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DE_MASK) >> MC_CGM_MUX_9_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DIV_MASK) >> MC_CGM_MUX_9_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return GMAC0_TX_CLK frequency */
static uint32 get_GMAC0_TX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_10_CSS & MC_CGM_MUX_10_CSS_SELSTAT_MASK) >> MC_CGM_MUX_10_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_10_DC_0 & MC_CGM_MUX_10_DC_0_DE_MASK) >> MC_CGM_MUX_10_DC_0_DE_SHIFT)];                        /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_10_DC_0 & MC_CGM_MUX_10_DC_0_DIV_MASK) >> MC_CGM_MUX_10_DC_0_DIV_SHIFT) + 1U);                              /*  Apply divider value */
    return Frequency;
}
/* Return GMAC1_RX_CLK frequency */
static uint32 get_GMAC1_RX_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_4_CSS & MC_CGM_2_MUX_4_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_4_CSS_SELSTAT_SHIFT)]();               /*  Selector value */
}
/* Return GMAC1_TS_CLK frequency */
static uint32 get_GMAC1_TS_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_9_CSS & MC_CGM_MUX_9_CSS_SELSTAT_MASK) >> MC_CGM_MUX_9_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DE_MASK) >> MC_CGM_MUX_9_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_9_DC_0 & MC_CGM_MUX_9_DC_0_DIV_MASK) >> MC_CGM_MUX_9_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return GMAC1_TX_CLK frequency */
static uint32 get_GMAC1_TX_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_2->MUX_2_CSS & MC_CGM_2_MUX_2_CSS_SELSTAT_MASK) >> MC_CGM_2_MUX_2_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_2->MUX_2_DC_0 & MC_CGM_2_MUX_2_DC_0_DE_MASK) >> MC_CGM_2_MUX_2_DC_0_DE_SHIFT)];                        /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->MUX_2_DC_0 & MC_CGM_2_MUX_2_DC_0_DIV_MASK) >> MC_CGM_2_MUX_2_DC_0_DIV_SHIFT) + 1U);                              /*  Apply divider value */
    return Frequency;
}
/* Return LBIST_CLK frequency */
static uint32 get_LBIST_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_0_CSS & MC_CGM_MUX_0_CSS_SELSTAT_MASK) >> MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)]();            /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DE_MASK) >> MC_CGM_MUX_0_DC_0_DE_SHIFT)];                           /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_0_DC_0 & MC_CGM_MUX_0_DC_0_DIV_MASK) >> MC_CGM_MUX_0_DC_0_DIV_SHIFT) + 1U);                                 /*  Apply divider value */
    return Frequency;
}
/* Return LBIST0_CLK frequency */
static uint32 get_LBIST0_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST1_CLK frequency */
static uint32 get_LBIST1_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST2_CLK frequency */
static uint32 get_LBIST2_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST3_CLK frequency */
static uint32 get_LBIST3_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST4_CLK frequency */
static uint32 get_LBIST4_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST5_CLK frequency */
static uint32 get_LBIST5_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST6_CLK frequency */
static uint32 get_LBIST6_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LBIST7_CLK frequency */
static uint32 get_LBIST7_CLK_Frequency(void) {

    return get_LBIST_CLK_Frequency();
}
/* Return LIN_BAUD_CLK frequency */
static uint32 get_LIN_BAUD_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_8_CSS & MC_CGM_MUX_8_CSS_SELSTAT_MASK) >> MC_CGM_MUX_8_CSS_SELSTAT_SHIFT)]();                  /*  Selector value */
}
/* Return LINFLEX_CLK frequency */
static uint32 get_LINFLEX_CLK_Frequency(void) {

    return get_LIN_BAUD_CLK_Frequency() >> 1U;
}
/* Return LIN0_CLK frequency */
static uint32 get_LIN0_CLK_Frequency(void) {

    return get_LIN_BAUD_CLK_Frequency();
}
/* Return LIN1_CLK frequency */
static uint32 get_LIN1_CLK_Frequency(void) {

    return get_LIN_BAUD_CLK_Frequency();
}
/* Return QSPI_2X_CLK frequency */
static uint32 get_QSPI_2X_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_12_CSS & MC_CGM_MUX_12_CSS_SELSTAT_MASK) >> MC_CGM_MUX_12_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_12_DC_0 & MC_CGM_MUX_12_DC_0_DE_MASK) >> MC_CGM_MUX_12_DC_0_DE_SHIFT)];                        /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_12_DC_0 & MC_CGM_MUX_12_DC_0_DIV_MASK) >> MC_CGM_MUX_12_DC_0_DIV_SHIFT) + 1U);                              /*  Apply divider value */
    return Frequency;
}
/* Return QSPI_1X_CLK frequency */
static uint32 get_QSPI_1X_CLK_Frequency(void) {

    return get_QSPI_2X_CLK_Frequency() >> 1U;
}
/* Return QSPI0_CLK frequency */
static uint32 get_QSPI0_CLK_Frequency(void) {

    return get_QSPI_2X_CLK_Frequency();
}
/* Return SPI_CLK frequency */
static uint32 get_SPI_CLK_Frequency(void) {

    return Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_16_CSS & MC_CGM_MUX_16_CSS_SELSTAT_MASK) >> MC_CGM_MUX_16_CSS_SELSTAT_SHIFT)]();              /*  Selector value */
}
/* Return SPI0_CLK frequency */
static uint32 get_SPI0_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();
}
/* Return SPI1_CLK frequency */
static uint32 get_SPI1_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();
}
/* Return SPI2_CLK frequency */
static uint32 get_SPI2_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();
}
/* Return SPI3_CLK frequency */
static uint32 get_SPI3_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();
}
/* Return SPI4_CLK frequency */
static uint32 get_SPI4_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();
}
/* Return SPI5_CLK frequency */
static uint32 get_SPI5_CLK_Frequency(void) {

    return get_SPI_CLK_Frequency();

}
/* Return USDHC_CLK frequency */
static uint32 get_USDHC_CLK_Frequency(void) {

    uint32 Frequency;
    Frequency  = Clock_Ip_apfFreqTableClkSrc[((IP_MC_CGM_0->MUX_14_CSS & MC_CGM_MUX_14_CSS_SELSTAT_MASK) >> MC_CGM_MUX_14_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->MUX_14_DC_0 & MC_CGM_MUX_14_DC_0_DE_MASK) >> MC_CGM_MUX_14_DC_0_DE_SHIFT)];                        /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->MUX_14_DC_0 & MC_CGM_MUX_14_DC_0_DIV_MASK) >> MC_CGM_MUX_14_DC_0_DIV_SHIFT) + 1U);                              /*  Apply divider value */
    return Frequency;
}
/* Return USDHC0_CLK frequency */
static uint32 get_USDHC0_CLK_Frequency(void) {

    return get_USDHC_CLK_Frequency();
}
/* Return PLL_VCO frequency */
#define CLOCK_IP_PLL_VCO_MAX_FREQ             (2622000000U)
static uint32 PLL_VCO(const PLLDIG_Type *Base)
{
    uint32 Fin;
    uint32 Rdiv;
    uint32 Mfi;
    uint32 Mfn;
    uint32 Fout = 0U;
    uint32 Var1;
    uint32 Var2;
    uint32 Var3;
    uint32 Var4;
    uint32 Var5;
    boolean Overflow = FALSE;

    Fin  = (((Base->PLLCLKMUX & PLLDIG_PLLCLKMUX_REFCLKSEL_MASK) >> PLLDIG_PLLCLKMUX_REFCLKSEL_SHIFT) == 0U) ? get_FIRC_CLK_Frequency() : get_FXOSC_CLK_Frequency();   /* input freq */
    Rdiv = ((Base->PLLDV & PLLDIG_PLLDV_RDIV_MASK) >> PLLDIG_PLLDV_RDIV_SHIFT);              /* Rdiv */
    Mfi  = ((Base->PLLDV & PLLDIG_PLLDV_MFI_MASK) >> PLLDIG_PLLDV_MFI_SHIFT);                /* Mfi */
    Mfn  = ((Base->PLLFD & PLLDIG_PLLFD_MFN_MASK) >> PLLDIG_PLLFD_MFN_SHIFT);                /* Mfn */


    Var1 = Mfi / Rdiv;                                      /* Mfi divided by Rdiv */
    Var2 = Mfi - (Var1 * Rdiv);                             /* Mfi minus Var1 multiplied by Rdiv */
    Var3 = (Rdiv << CLOCK_IP_MUL_BY_16384) + (Rdiv << CLOCK_IP_MUL_BY_2048);  /* Rdiv multiplied by 18432 */
    Var4 = Fin / Var3;                                      /* Fin divide by (Rdiv multiplied by 18432) */
    Var5 = Fin - (Var4 * Var3);                               /* Fin minus Var4 multiplied by (Rdiv mul 18432) */

    if (0U != Fin)
    {
        if (Var1 == ((uint32)(Var1 * Fin) / Fin))
        {
            Fout = Var1 * Fin;                                      /* Var1 multipied by Fin */
        }
        else
        {
            Overflow = TRUE;
        }

        if ((Var2 == ((uint32)(Fin * Var2) / Fin)) && (CLOCK_IP_PLL_VCO_MAX_FREQ >= Fout))
        {
            Fout += Fin / Rdiv * Var2;                              /* Fin divided by Rdiv and multiplied by Var2 */
        }
        else
        {
            Overflow = TRUE;
        }

        if (0U != Var4)
        {
            if ((Mfn == ((uint32)(Var4 * Mfn) / Var4)) && (CLOCK_IP_PLL_VCO_MAX_FREQ >= Fout))
            {
                Fout += Var4 * Mfn;                                     /* Mfn multiplied by Var4 */
            }
            else
            {
                Overflow = TRUE;
            }
        }

        if (0U != Mfn)
        {
            if ((Var5  == ((uint32)(Var5 * Mfn) / Mfn)) && (CLOCK_IP_PLL_VCO_MAX_FREQ >= Fout))
            {
                Fout += Var5 * Mfn / Var3;                              /* Var5 multiplied by Mfn and divide by (Rdiv mul 18432) */
            }
            else
            {
                Overflow = TRUE;
            }
        }
    }

    if (TRUE == Overflow)
    {
        Fout = 0U;
    }

    return Fout;
}
/* Return DFS_OUTPUT frequency */
static uint32 DFS_OUTPUT(const DFS_Type *Base, uint32 Channel, uint32 Fin)
{
    uint32 Mfi;
    uint32 Mfn;
    uint32 Divider;
    uint32 DividerResult;
    uint32 DividerModulo;
    uint32 Fout = 0U;
    boolean Overflow = FALSE;

    Mfi = ((Base->DVPORT[Channel] & DFS_DVPORT_MFI_MASK) >> DFS_DVPORT_MFI_SHIFT);              /* Mfi */
    Mfn = ((Base->DVPORT[Channel] & DFS_DVPORT_MFN_MASK) >> DFS_DVPORT_MFN_SHIFT);              /* Mfn */

    Divider = ((Mfi << CLOCK_IP_MUL_BY_32) + (Mfi << CLOCK_IP_MUL_BY_4) + Mfn);               /* mfi multiplied by 36 add mfn */
    DividerResult = (Divider != 0U) ? (Fin / Divider) : 0U;                 /* Fin divide by Divider */
    DividerModulo = Fin - (Divider * DividerResult);                        /* Fin minus DividerResult multiplied by Divider */

    if (Divider != 0U)
    {
        if ((DividerResult << CLOCK_IP_MUL_BY_16) <= ((DividerResult << CLOCK_IP_MUL_BY_16) + (DividerResult << CLOCK_IP_MUL_BY_2)))
        {
            Fout += (DividerResult << CLOCK_IP_MUL_BY_16) + (DividerResult << CLOCK_IP_MUL_BY_2);
        }
        else
        {
            Overflow = TRUE;
        }

        if (Fout <= (Fout + (((DividerModulo << CLOCK_IP_MUL_BY_16) + (DividerModulo << CLOCK_IP_MUL_BY_2)) / Divider)))
        {
            Fout += ((DividerModulo << CLOCK_IP_MUL_BY_16) + (DividerModulo << CLOCK_IP_MUL_BY_2)) / Divider;
        }
        else
        {
            Overflow = TRUE;
        }
    }

    if (TRUE == Overflow)
    {
        Fout = 0U;
    }

    return Fout;
}
/* Return external frequency */
void Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_NameType ExtOscName, uint32 Frequency)
{
    (void)ExtOscName;
    Clock_Ip_u32Fxosc = Frequency;
}
/* Return external frequency */
void Clock_Ip_SetExternalSignalFrequency(Clock_Ip_NameType SignalName, uint32 Frequency)
{
    uint32 Index;
    for (Index = 0U; Index < CLOCK_IP_EXT_SIGNALS_NO; Index++)
    {
        if (SignalName == Clock_Ip_axExtSignalFreqEntries[Index].Name)
        {
            Clock_Ip_axExtSignalFreqEntries[Index].Frequency = Frequency;
            break;
        }
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/* return frequency */
uint32 Clock_Ip_GetFreq(Clock_Ip_NameType ClockName)
{
    return Clock_Ip_apfFreqTable[ClockName]();
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"




#endif
#endif


#endif /* (CLOCK_IP_PLATFORM_SPECIFIC1) */

#ifdef __cplusplus
}
#endif

/** @} */
