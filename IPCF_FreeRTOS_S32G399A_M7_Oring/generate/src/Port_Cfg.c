/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                4
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                2

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if Port_Cfg.c and Port.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on first SIUL2 instance
*/
static const uint16 Port_SIUL2_0_au16InMuxSettingsIndex[96] =
{
    /* Index to address the input settings for pad 0 */
    (uint16)1,
    /* Index to address the input settings for pad 1 */
    (uint16)0,
    /* Index to address the input settings for pad 2 */
    (uint16)2,
    /* Index to address the input settings for pad 3 */
    (uint16)3,
    /* Index to address the input settings for pad 4 */
    (uint16)4,
    /* Index to address the input settings for pad 5 */
    (uint16)5,
    /* Index to address the input settings for pad 6 */
    (uint16)6,
    /* Index to address the input settings for pad 7 */
    (uint16)7,
    /* Index to address the input settings for pad 8 */
    (uint16)9,
    /* Index to address the input settings for pad 9 */
    (uint16)11,
    /* Index to address the input settings for pad 10 */
    (uint16)16,
    /* Index to address the input settings for pad 11 */
    (uint16)20,
    /* Index to address the input settings for pad 12 */
    (uint16)22,
    /* Index to address the input settings for pad 13 */
    (uint16)25,
    /* Index to address the input settings for pad 14 */
    (uint16)28,
    /* Index to address the input settings for pad 15 */
    (uint16)31,
    /* Index to address the input settings for pad 16 */
    (uint16)33,
    /* Index to address the input settings for pad 17 */
    (uint16)38,
    /* Index to address the input settings for pad 18 */
    (uint16)41,
    /* Index to address the input settings for pad 19 */
    (uint16)44,
    /* Index to address the input settings for pad 20 */
    (uint16)47,
    /* Index to address the input settings for pad 21 */
    (uint16)51,
    /* Index to address the input settings for pad 22 */
    (uint16)54,
    /* Index to address the input settings for pad 23 */
    (uint16)56,
    /* Index to address the input settings for pad 24 */
    (uint16)58,
    /* Index to address the input settings for pad 25 */
    (uint16)62,
    /* Index to address the input settings for pad 26 */
    (uint16)65,
    /* Index to address the input settings for pad 27 */
    (uint16)71,
    /* Index to address the input settings for pad 28 */
    (uint16)76,
    /* Index to address the input settings for pad 29 */
    (uint16)82,
    /* Index to address the input settings for pad 30 */
    (uint16)89,
    /* Index to address the input settings for pad 31 */
    (uint16)95,
    /* Index to address the input settings for pad 32 */
    (uint16)99,
    /* Index to address the input settings for pad 33 */
    (uint16)104,
    /* Index to address the input settings for pad 34 */
    (uint16)108,
    /* Index to address the input settings for pad 35 */
    (uint16)112,
    /* Index to address the input settings for pad 36 */
    (uint16)113,
    /* Index to address the input settings for pad 37 */
    (uint16)117,
    /* Index to address the input settings for pad 38 */
    (uint16)120,
    /* Index to address the input settings for pad 39 */
    (uint16)124,
    /* Index to address the input settings for pad 40 */
    (uint16)126,
    /* Index to address the input settings for pad 41 */
    (uint16)128,
    /* Index to address the input settings for pad 42 */
    (uint16)132,
    /* Index to address the input settings for pad 43 */
    (uint16)137,
    /* Index to address the input settings for pad 44 */
    (uint16)0,
    /* Index to address the input settings for pad 45 */
    (uint16)0,
    /* Index to address the input settings for pad 46 */
    (uint16)139,
    /* Index to address the input settings for pad 47 */
    (uint16)140,
    /* Index to address the input settings for pad 48 */
    (uint16)142,
    /* Index to address the input settings for pad 49 */
    (uint16)144,
    /* Index to address the input settings for pad 50 */
    (uint16)147,
    /* Index to address the input settings for pad 51 */
    (uint16)150,
    /* Index to address the input settings for pad 52 */
    (uint16)153,
    /* Index to address the input settings for pad 53 */
    (uint16)156,
    /* Index to address the input settings for pad 54 */
    (uint16)159,
    /* Index to address the input settings for pad 55 */
    (uint16)160,
    /* Index to address the input settings for pad 56 */
    (uint16)162,
    /* Index to address the input settings for pad 57 */
    (uint16)163,
    /* Index to address the input settings for pad 58 */
    (uint16)164,
    /* Index to address the input settings for pad 59 */
    (uint16)166,
    /* Index to address the input settings for pad 60 */
    (uint16)168,
    /* Index to address the input settings for pad 61 */
    (uint16)169,
    /* Index to address the input settings for pad 62 */
    (uint16)172,
    /* Index to address the input settings for pad 63 */
    (uint16)177,
    /* Index to address the input settings for pad 64 */
    (uint16)183,
    /* Index to address the input settings for pad 65 */
    (uint16)187,
    /* Index to address the input settings for pad 66 */
    (uint16)193,
    /* Index to address the input settings for pad 67 */
    (uint16)195,
    /* Index to address the input settings for pad 68 */
    (uint16)197,
    /* Index to address the input settings for pad 69 */
    (uint16)199,
    /* Index to address the input settings for pad 70 */
    (uint16)201,
    /* Index to address the input settings for pad 71 */
    (uint16)205,
    /* Index to address the input settings for pad 72 */
    (uint16)209,
    /* Index to address the input settings for pad 73 */
    (uint16)211,
    /* Index to address the input settings for pad 74 */
    (uint16)213,
    /* Index to address the input settings for pad 75 */
    (uint16)215,
    /* Index to address the input settings for pad 76 */
    (uint16)217,
    /* Index to address the input settings for pad 77 */
    (uint16)219,
    /* Index to address the input settings for pad 78 */
    (uint16)221,
    /* Index to address the input settings for pad 79 */
    (uint16)224,
    /* Index to address the input settings for pad 80 */
    (uint16)227,
    /* Index to address the input settings for pad 81 */
    (uint16)228,
    /* Index to address the input settings for pad 82 */
    (uint16)231,
    /* Index to address the input settings for pad 83 */
    (uint16)0,
    /* Index to address the input settings for pad 84 */
    (uint16)0,
    /* Index to address the input settings for pad 85 */
    (uint16)232,
    /* Index to address the input settings for pad 86 */
    (uint16)233,
    /* Index to address the input settings for pad 87 */
    (uint16)234,
    /* Index to address the input settings for pad 88 */
    (uint16)235,
    /* Index to address the input settings for pad 89 */
    (uint16)236,
    /* Index to address the input settings for pad 90 */
    (uint16)237,
    /* Index to address the input settings for pad 91 */
    (uint16)238,
    /* Index to address the input settings for pad 92 */
    (uint16)239,
    /* Index to address the input settings for pad 93 */
    (uint16)240,
    /* Index to address the input settings for pad 94 */
    (uint16)241,
    /* Index to address the input settings for pad 95 */
    (uint16)242
};

/**
* @brief Array of elements storing indexes in Port_<SIUL2 Instance>_aInMuxSettings table where IN settings for each pad reside on second SIUL2 instance
*/
static const uint16 Port_SIUL2_1_au16InMuxSettingsIndex[191] =
{
    /* Index to address the input settings for pad 0 */
    (uint16)0,
    /* Index to address the input settings for pad 1 */
    (uint16)0,
    /* Index to address the input settings for pad 2 */
    (uint16)0,
    /* Index to address the input settings for pad 3 */
    (uint16)0,
    /* Index to address the input settings for pad 4 */
    (uint16)0,
    /* Index to address the input settings for pad 5 */
    (uint16)0,
    /* Index to address the input settings for pad 6 */
    (uint16)0,
    /* Index to address the input settings for pad 7 */
    (uint16)0,
    /* Index to address the input settings for pad 8 */
    (uint16)0,
    /* Index to address the input settings for pad 9 */
    (uint16)0,
    /* Index to address the input settings for pad 10 */
    (uint16)0,
    /* Index to address the input settings for pad 11 */
    (uint16)0,
    /* Index to address the input settings for pad 12 */
    (uint16)0,
    /* Index to address the input settings for pad 13 */
    (uint16)0,
    /* Index to address the input settings for pad 14 */
    (uint16)0,
    /* Index to address the input settings for pad 15 */
    (uint16)0,
    /* Index to address the input settings for pad 16 */
    (uint16)0,
    /* Index to address the input settings for pad 17 */
    (uint16)0,
    /* Index to address the input settings for pad 18 */
    (uint16)0,
    /* Index to address the input settings for pad 19 */
    (uint16)0,
    /* Index to address the input settings for pad 20 */
    (uint16)0,
    /* Index to address the input settings for pad 21 */
    (uint16)0,
    /* Index to address the input settings for pad 22 */
    (uint16)0,
    /* Index to address the input settings for pad 23 */
    (uint16)0,
    /* Index to address the input settings for pad 24 */
    (uint16)0,
    /* Index to address the input settings for pad 25 */
    (uint16)0,
    /* Index to address the input settings for pad 26 */
    (uint16)0,
    /* Index to address the input settings for pad 27 */
    (uint16)0,
    /* Index to address the input settings for pad 28 */
    (uint16)0,
    /* Index to address the input settings for pad 29 */
    (uint16)0,
    /* Index to address the input settings for pad 30 */
    (uint16)0,
    /* Index to address the input settings for pad 31 */
    (uint16)0,
    /* Index to address the input settings for pad 32 */
    (uint16)0,
    /* Index to address the input settings for pad 33 */
    (uint16)0,
    /* Index to address the input settings for pad 34 */
    (uint16)0,
    /* Index to address the input settings for pad 35 */
    (uint16)0,
    /* Index to address the input settings for pad 36 */
    (uint16)0,
    /* Index to address the input settings for pad 37 */
    (uint16)0,
    /* Index to address the input settings for pad 38 */
    (uint16)0,
    /* Index to address the input settings for pad 39 */
    (uint16)0,
    /* Index to address the input settings for pad 40 */
    (uint16)0,
    /* Index to address the input settings for pad 41 */
    (uint16)0,
    /* Index to address the input settings for pad 42 */
    (uint16)0,
    /* Index to address the input settings for pad 43 */
    (uint16)0,
    /* Index to address the input settings for pad 44 */
    (uint16)0,
    /* Index to address the input settings for pad 45 */
    (uint16)0,
    /* Index to address the input settings for pad 46 */
    (uint16)0,
    /* Index to address the input settings for pad 47 */
    (uint16)0,
    /* Index to address the input settings for pad 48 */
    (uint16)0,
    /* Index to address the input settings for pad 49 */
    (uint16)0,
    /* Index to address the input settings for pad 50 */
    (uint16)0,
    /* Index to address the input settings for pad 51 */
    (uint16)0,
    /* Index to address the input settings for pad 52 */
    (uint16)0,
    /* Index to address the input settings for pad 53 */
    (uint16)0,
    /* Index to address the input settings for pad 54 */
    (uint16)0,
    /* Index to address the input settings for pad 55 */
    (uint16)0,
    /* Index to address the input settings for pad 56 */
    (uint16)0,
    /* Index to address the input settings for pad 57 */
    (uint16)0,
    /* Index to address the input settings for pad 58 */
    (uint16)0,
    /* Index to address the input settings for pad 59 */
    (uint16)0,
    /* Index to address the input settings for pad 60 */
    (uint16)0,
    /* Index to address the input settings for pad 61 */
    (uint16)0,
    /* Index to address the input settings for pad 62 */
    (uint16)0,
    /* Index to address the input settings for pad 63 */
    (uint16)0,
    /* Index to address the input settings for pad 64 */
    (uint16)0,
    /* Index to address the input settings for pad 65 */
    (uint16)0,
    /* Index to address the input settings for pad 66 */
    (uint16)0,
    /* Index to address the input settings for pad 67 */
    (uint16)0,
    /* Index to address the input settings for pad 68 */
    (uint16)0,
    /* Index to address the input settings for pad 69 */
    (uint16)0,
    /* Index to address the input settings for pad 70 */
    (uint16)0,
    /* Index to address the input settings for pad 71 */
    (uint16)0,
    /* Index to address the input settings for pad 72 */
    (uint16)0,
    /* Index to address the input settings for pad 73 */
    (uint16)0,
    /* Index to address the input settings for pad 74 */
    (uint16)0,
    /* Index to address the input settings for pad 75 */
    (uint16)0,
    /* Index to address the input settings for pad 76 */
    (uint16)0,
    /* Index to address the input settings for pad 77 */
    (uint16)0,
    /* Index to address the input settings for pad 78 */
    (uint16)0,
    /* Index to address the input settings for pad 79 */
    (uint16)0,
    /* Index to address the input settings for pad 80 */
    (uint16)0,
    /* Index to address the input settings for pad 81 */
    (uint16)0,
    /* Index to address the input settings for pad 82 */
    (uint16)0,
    /* Index to address the input settings for pad 83 */
    (uint16)0,
    /* Index to address the input settings for pad 84 */
    (uint16)0,
    /* Index to address the input settings for pad 85 */
    (uint16)0,
    /* Index to address the input settings for pad 86 */
    (uint16)0,
    /* Index to address the input settings for pad 87 */
    (uint16)0,
    /* Index to address the input settings for pad 88 */
    (uint16)0,
    /* Index to address the input settings for pad 89 */
    (uint16)0,
    /* Index to address the input settings for pad 90 */
    (uint16)0,
    /* Index to address the input settings for pad 91 */
    (uint16)0,
    /* Index to address the input settings for pad 92 */
    (uint16)0,
    /* Index to address the input settings for pad 93 */
    (uint16)0,
    /* Index to address the input settings for pad 94 */
    (uint16)0,
    /* Index to address the input settings for pad 95 */
    (uint16)0,
    /* Index to address the input settings for pad 96 */
    (uint16)0,
    /* Index to address the input settings for pad 97 */
    (uint16)0,
    /* Index to address the input settings for pad 98 */
    (uint16)0,
    /* Index to address the input settings for pad 99 */
    (uint16)0,
    /* Index to address the input settings for pad 100 */
    (uint16)0,
    /* Index to address the input settings for pad 101 */
    (uint16)0,
    /* Index to address the input settings for pad 102 */
    (uint16)0,
    /* Index to address the input settings for pad 103 */
    (uint16)0,
    /* Index to address the input settings for pad 104 */
    (uint16)0,
    /* Index to address the input settings for pad 105 */
    (uint16)0,
    /* Index to address the input settings for pad 106 */
    (uint16)0,
    /* Index to address the input settings for pad 107 */
    (uint16)0,
    /* Index to address the input settings for pad 108 */
    (uint16)0,
    /* Index to address the input settings for pad 109 */
    (uint16)0,
    /* Index to address the input settings for pad 110 */
    (uint16)0,
    /* Index to address the input settings for pad 111 */
    (uint16)0,
    /* Index to address the input settings for pad 112 */
    (uint16)1,
    /* Index to address the input settings for pad 113 */
    (uint16)6,
    /* Index to address the input settings for pad 114 */
    (uint16)11,
    /* Index to address the input settings for pad 115 */
    (uint16)18,
    /* Index to address the input settings for pad 116 */
    (uint16)25,
    /* Index to address the input settings for pad 117 */
    (uint16)30,
    /* Index to address the input settings for pad 118 */
    (uint16)34,
    /* Index to address the input settings for pad 119 */
    (uint16)38,
    /* Index to address the input settings for pad 120 */
    (uint16)42,
    /* Index to address the input settings for pad 121 */
    (uint16)46,
    /* Index to address the input settings for pad 122 */
    (uint16)48,
    /* Index to address the input settings for pad 123 */
    (uint16)0,
    /* Index to address the input settings for pad 124 */
    (uint16)0,
    /* Index to address the input settings for pad 125 */
    (uint16)0,
    /* Index to address the input settings for pad 126 */
    (uint16)0,
    /* Index to address the input settings for pad 127 */
    (uint16)0,
    /* Index to address the input settings for pad 128 */
    (uint16)0,
    /* Index to address the input settings for pad 129 */
    (uint16)0,
    /* Index to address the input settings for pad 130 */
    (uint16)0,
    /* Index to address the input settings for pad 131 */
    (uint16)0,
    /* Index to address the input settings for pad 132 */
    (uint16)0,
    /* Index to address the input settings for pad 133 */
    (uint16)0,
    /* Index to address the input settings for pad 134 */
    (uint16)0,
    /* Index to address the input settings for pad 135 */
    (uint16)0,
    /* Index to address the input settings for pad 136 */
    (uint16)0,
    /* Index to address the input settings for pad 137 */
    (uint16)0,
    /* Index to address the input settings for pad 138 */
    (uint16)0,
    /* Index to address the input settings for pad 139 */
    (uint16)0,
    /* Index to address the input settings for pad 140 */
    (uint16)0,
    /* Index to address the input settings for pad 141 */
    (uint16)0,
    /* Index to address the input settings for pad 142 */
    (uint16)0,
    /* Index to address the input settings for pad 143 */
    (uint16)0,
    /* Index to address the input settings for pad 144 */
    (uint16)51,
    /* Index to address the input settings for pad 145 */
    (uint16)54,
    /* Index to address the input settings for pad 146 */
    (uint16)56,
    /* Index to address the input settings for pad 147 */
    (uint16)57,
    /* Index to address the input settings for pad 148 */
    (uint16)58,
    /* Index to address the input settings for pad 149 */
    (uint16)59,
    /* Index to address the input settings for pad 150 */
    (uint16)60,
    /* Index to address the input settings for pad 151 */
    (uint16)61,
    /* Index to address the input settings for pad 152 */
    (uint16)63,
    /* Index to address the input settings for pad 153 */
    (uint16)68,
    /* Index to address the input settings for pad 154 */
    (uint16)70,
    /* Index to address the input settings for pad 155 */
    (uint16)72,
    /* Index to address the input settings for pad 156 */
    (uint16)74,
    /* Index to address the input settings for pad 157 */
    (uint16)0,
    /* Index to address the input settings for pad 158 */
    (uint16)77,
    /* Index to address the input settings for pad 159 */
    (uint16)80,
    /* Index to address the input settings for pad 160 */
    (uint16)82,
    /* Index to address the input settings for pad 161 */
    (uint16)84,
    /* Index to address the input settings for pad 162 */
    (uint16)86,
    /* Index to address the input settings for pad 163 */
    (uint16)88,
    /* Index to address the input settings for pad 164 */
    (uint16)89,
    /* Index to address the input settings for pad 165 */
    (uint16)91,
    /* Index to address the input settings for pad 166 */
    (uint16)94,
    /* Index to address the input settings for pad 167 */
    (uint16)96,
    /* Index to address the input settings for pad 168 */
    (uint16)101,
    /* Index to address the input settings for pad 169 */
    (uint16)105,
    /* Index to address the input settings for pad 170 */
    (uint16)106,
    /* Index to address the input settings for pad 171 */
    (uint16)110,
    /* Index to address the input settings for pad 172 */
    (uint16)113,
    /* Index to address the input settings for pad 173 */
    (uint16)116,
    /* Index to address the input settings for pad 174 */
    (uint16)117,
    /* Index to address the input settings for pad 175 */
    (uint16)120,
    /* Index to address the input settings for pad 176 */
    (uint16)123,
    /* Index to address the input settings for pad 177 */
    (uint16)125,
    /* Index to address the input settings for pad 178 */
    (uint16)128,
    /* Index to address the input settings for pad 179 */
    (uint16)133,
    /* Index to address the input settings for pad 180 */
    (uint16)136,
    /* Index to address the input settings for pad 181 */
    (uint16)140,
    /* Index to address the input settings for pad 182 */
    (uint16)145,
    /* Index to address the input settings for pad 183 */
    (uint16)147,
    /* Index to address the input settings for pad 184 */
    (uint16)149,
    /* Index to address the input settings for pad 185 */
    (uint16)153,
    /* Index to address the input settings for pad 186 */
    (uint16)156,
    /* Index to address the input settings for pad 187 */
    (uint16)161,
    /* Index to address the input settings for pad 188 */
    (uint16)167,
    /* Index to address the input settings for pad 189 */
    (uint16)173,
    /* Index to address the input settings for pad 190 */
    (uint16)178
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on first SIUL2 instance
*/
static const Port_PinModeAvailabilityArrayType Port_SIUL2_0_au16PinModeAvailability =
{

    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_GPIO |
        SIUL2_0_PORT1_GPIO |
        SIUL2_0_PORT2_GPIO |
        SIUL2_0_PORT3_GPIO |
        SIUL2_0_PORT4_GPIO |
        SIUL2_0_PORT5_GPIO |
        SIUL2_0_PORT6_GPIO |
        SIUL2_0_PORT7_GPIO |
        SIUL2_0_PORT8_GPIO |
        SIUL2_0_PORT9_GPIO |
        SIUL2_0_PORT10_GPI |
        SIUL2_0_PORT11_GPIO |
        SIUL2_0_PORT12_GPIO |
        SIUL2_0_PORT13_GPIO |
        SIUL2_0_PORT14_GPIO |
        SIUL2_0_PORT15_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_GPIO |
        SIUL2_0_PORT17_GPIO |
        SIUL2_0_PORT18_GPIO |
        SIUL2_0_PORT19_GPIO |
        SIUL2_0_PORT20_GPIO |
        SIUL2_0_PORT21_GPIO |
        SIUL2_0_PORT22_GPIO |
        SIUL2_0_PORT23_GPIO |
        SIUL2_0_PORT24_GPIO |
        SIUL2_0_PORT25_GPIO |
        SIUL2_0_PORT26_GPIO |
        SIUL2_0_PORT27_GPIO |
        SIUL2_0_PORT28_GPIO |
        SIUL2_0_PORT29_GPIO |
        SIUL2_0_PORT30_GPIO |
        SIUL2_0_PORT31_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_GPIO |
        SIUL2_0_PORT33_GPIO |
        SIUL2_0_PORT34_GPIO |
        SIUL2_0_PORT35_GPIO |
        SIUL2_0_PORT36_GPI |
        SIUL2_0_PORT37_GPIO |
        SIUL2_0_PORT38_GPI |
        SIUL2_0_PORT39_GPIO |
        SIUL2_0_PORT40_GPIO |
        SIUL2_0_PORT41_GPIO |
        SIUL2_0_PORT42_GPIO |
        SIUL2_0_PORT43_GPI |
        SIUL2_0_PORT44_GPIO |
        SIUL2_0_PORT45_GPIO |
        SIUL2_0_PORT46_GPIO |
        SIUL2_0_PORT47_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_GPIO |
        SIUL2_0_PORT49_GPIO |
        SIUL2_0_PORT50_GPIO |
        SIUL2_0_PORT51_GPIO |
        SIUL2_0_PORT52_GPIO |
        SIUL2_0_PORT53_GPIO |
        SIUL2_0_PORT54_GPIO |
        SIUL2_0_PORT55_GPIO |
        SIUL2_0_PORT56_GPIO |
        SIUL2_0_PORT57_GPIO |
        SIUL2_0_PORT58_GPIO |
        SIUL2_0_PORT59_GPIO |
        SIUL2_0_PORT60_GPIO |
        SIUL2_0_PORT61_GPIO |
        SIUL2_0_PORT62_GPIO |
        SIUL2_0_PORT63_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GPIO |
        SIUL2_0_PORT65_GPIO |
        SIUL2_0_PORT66_GPIO |
        SIUL2_0_PORT67_GPIO |
        SIUL2_0_PORT68_GPIO |
        SIUL2_0_PORT69_GPIO |
        SIUL2_0_PORT70_GPIO |
        SIUL2_0_PORT71_GPIO |
        SIUL2_0_PORT72_GPIO |
        SIUL2_0_PORT73_GPIO |
        SIUL2_0_PORT74_GPIO |
        SIUL2_0_PORT75_GPIO |
        SIUL2_0_PORT76_GPIO |
        SIUL2_0_PORT77_GPIO |
        SIUL2_0_PORT78_GPIO |
        SIUL2_0_PORT79_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_GPIO |
        SIUL2_0_PORT81_GPIO |
        SIUL2_0_PORT82_GPIO |
        SIUL2_0_PORT83_GPIO |
        SIUL2_0_PORT84_GPIO |
        SIUL2_0_PORT85_GPIO |
        SIUL2_0_PORT86_GPIO |
        SIUL2_0_PORT87_GPIO |
        SIUL2_0_PORT88_GPIO |
        SIUL2_0_PORT89_GPIO |
        SIUL2_0_PORT90_GPIO |
        SIUL2_0_PORT91_GPIO |
        SIUL2_0_PORT92_GPIO |
        SIUL2_0_PORT93_GPIO |
        SIUL2_0_PORT94_GPIO |
        SIUL2_0_PORT95_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_GPIO |
        SIUL2_0_PORT97_GPIO |
        SIUL2_0_PORT98_GPIO |
        SIUL2_0_PORT99_GPIO |
        SIUL2_0_PORT100_GPIO |
        SIUL2_0_PORT101_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT1_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT1_JTAGC_TDO |
        SIUL2_0_PORT5_JTAGC_TMS_OUT |
        SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_OUT |
        SIUL2_0_PORT11_GMAC_0_GMAC0_PPS_2 |
        SIUL2_0_PORT12_GMAC_0_GMAC0_PPS_3 |
        SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_OUT |
        SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_OUT |
        SIUL2_0_PORT15_DSPI_0_DSPI0_SOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_I2C_0_I2C0_SDA_OUT |
        SIUL2_0_PORT17_I2C_0_I2C0_SCL_OUT |
        SIUL2_0_PORT19_I2C_1_I2C1_SCL_OUT |
        SIUL2_0_PORT20_I2C_1_I2C1_SDA_OUT |
        SIUL2_0_PORT21_I2C_2_I2C2_SCL_OUT |
        SIUL2_0_PORT22_I2C_2_I2C2_SDA_OUT |
        SIUL2_0_PORT23_I2C_3_I2C3_SCL_OUT |
        SIUL2_0_PORT24_I2C_0_I2C0_SDA_OUT |
        SIUL2_0_PORT25_LINFLEX_1_LIN1_TX |
        SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_OUT |
        SIUL2_0_PORT27_FLEXRAY_0_FR_TXE_A_b |
        SIUL2_0_PORT28_FLEXRAY_0_FR_TXD_A |
        SIUL2_0_PORT29_FLEXCAN_3_CAN3_TX |
        SIUL2_0_PORT30_FLEXRAY_0_FR_TXE_B_b |
        SIUL2_0_PORT31_FLEXRAY_0_FR_TXD_B */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_I2C_0_I2C0_SCL_OUT |
        SIUL2_0_PORT33_I2C_4_I2C4_SDA_OUT |
        SIUL2_0_PORT35_PFE_MAC0_PFE_MAC0_PPS_0 |
        SIUL2_0_PORT37_LLCE_LIN_2_LLCE_LIN2_TX |
        SIUL2_0_PORT39_LLCE_LIN_3_LLCE_LIN3_TX |
        SIUL2_0_PORT40_LLCE_LIN_1_LLCE_LIN1_TX |
        SIUL2_0_PORT41_LINFLEX_0_LIN0_TX |
        SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_OUT |
        SIUL2_0_PORT44_FLEXCAN_0_CAN0_TX |
        SIUL2_0_PORT46_USDHC_0_SD0_CLK |
        SIUL2_0_PORT47_USDHC_0_SD0_CMD_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_USDHC_0_SD0_D_0_OUT |
        SIUL2_0_PORT49_USDHC_0_SD0_D_1_OUT |
        SIUL2_0_PORT50_USDHC_0_SD0_D_2_OUT |
        SIUL2_0_PORT51_USDHC_0_SD0_D_3_OUT |
        SIUL2_0_PORT52_USDHC_0_SD0_D_4_OUT |
        SIUL2_0_PORT53_USDHC_0_SD0_D_5_OUT |
        SIUL2_0_PORT54_USDHC_0_SD0_D_6_OUT |
        SIUL2_0_PORT55_USDHC_0_SD0_D_7_OUT |
        SIUL2_0_PORT56_USDHC_0_SD0_RST |
        SIUL2_0_PORT57_USDHC_0_SD0_VSELECT |
        SIUL2_0_PORT60_GMAC_0_GMAC0_MDC |
        SIUL2_0_PORT61_GMAC_0_GMAC0_MD_OUT |
        SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_OUT |
        SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_OUT |
        SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_OUT |
        SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_OUT |
        SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_OUT |
        SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_OUT |
        SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_OUT |
        SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_OUT |
        SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_OUT |
        SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_OUT |
        SIUL2_0_PORT73_DSPI_3_DSPI3_PCS4 |
        SIUL2_0_PORT74_DSPI_4_DSPI4_PCS3 |
        SIUL2_0_PORT75_DSPI_4_DSPI4_PCS4 |
        SIUL2_0_PORT76_DSPI_5_DSPI5_PCS3 |
        SIUL2_0_PORT77_DSPI_5_DSPI5_PCS4 |
        SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_OUT |
        SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_PFE_MAC2_PFE_MAC2_MDC |
        SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_OUT |
        SIUL2_0_PORT82_PFE_MAC0_PFE_MAC0_MDC |
        SIUL2_0_PORT83_MISC_CLKOUT0 |
        SIUL2_0_PORT84_MISC_CLKOUT1 |
        SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_OUT |
        SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_OUT |
        SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_OUT |
        SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_OUT |
        SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_OUT |
        SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_OUT |
        SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_OUT |
        SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_OUT |
        SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 96 - 111
        SIUL2_0_PORT96_QUADSPI_QSPI_CK_A |
        SIUL2_0_PORT97_QUADSPI_QSPI_CK_A_b |
        SIUL2_0_PORT98_QUADSPI_QSPI_CK_2A |
        SIUL2_0_PORT99_QUADSPI_QSPI_CK_2A_b |
        SIUL2_0_PORT100_QUADSPI_QSPI_CS_A0 |
        SIUL2_0_PORT101_QUADSPI_QSPI_CS_A1 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U)
                ),
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT4_FLEXRAY_0_FR_DBG_0 |
        SIUL2_0_PORT6_DSPI_1_DSPI1_SOUT |
        SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_OUT |
        SIUL2_0_PORT8_LLCE_LPSPI_0_LLCE_LPSPI0_SIN |
        SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_OUT |
        SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_OUT |
        SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_OUT |
        SIUL2_0_PORT13_LINFLEX_1_LIN1_TX |
        SIUL2_0_PORT15_LINFLEX_0_LIN0_TX */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_OUT |
        SIUL2_0_PORT17_FLEXCAN_0_CAN0_TX |
        SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_OUT |
        SIUL2_0_PORT19_FLEXCAN_1_CAN1_TX |
        SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_OUT |
        SIUL2_0_PORT21_LLCE_FLEXRAY_LLCE_FR_DBG_2 |
        SIUL2_0_PORT22_LLCE_FLEXRAY_LLCE_FR_DBG_3 |
        SIUL2_0_PORT23_PFE_MAC1_PFE_MAC1_MDC |
        SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_OUT |
        SIUL2_0_PORT25_FLEXCAN_3_CAN3_TX |
        SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_OUT |
        SIUL2_0_PORT27_FLEXCAN_2_CAN2_TX |
        SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_OUT |
        SIUL2_0_PORT29_I2C_3_I2C3_SDA_OUT |
        SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_OUT |
        SIUL2_0_PORT31_I2C_0_I2C0_SDA_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_OUT |
        SIUL2_0_PORT34_I2C_4_I2C4_SCL_OUT |
        SIUL2_0_PORT39_PFE_MAC0_PFE_MAC0_PPS_0 |
        SIUL2_0_PORT40_LINFLEX_1_LIN1_TX |
        SIUL2_0_PORT41_FLEXCAN_2_CAN2_TX |
        SIUL2_0_PORT42_DSPI_1_DSPI1_PCS2 |
        SIUL2_0_PORT44_LLCE_CAN_0_LLCE_CAN0_TX |
        SIUL2_0_PORT45_MISC_TAMPER_LOOP_OUT0 |
        SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_OUT |
        SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_QUADSPI_QSPI_CS_B0 |
        SIUL2_0_PORT49_QUADSPI_QSPI_CS_B1 |
        SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_OUT |
        SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_OUT |
        SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_OUT |
        SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_OUT |
        SIUL2_0_PORT54_QUADSPI_QSPI_CK_B |
        SIUL2_0_PORT55_QUADSPI_QSPI_CK_B_b |
        SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_OUT |
        SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_OUT |
        SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_OUT |
        SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_OUT |
        SIUL2_0_PORT60_PFE_MAC1_PFE_MAC1_MDC |
        SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_OUT |
        SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_OUT |
        SIUL2_0_PORT63_DSPI_3_DSPI3_SOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_LINFLEX_2_LIN2_TX |
        SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_OUT |
        SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_OUT |
        SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_OUT |
        SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_OUT |
        SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_OUT |
        SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_OUT |
        SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_OUT |
        SIUL2_0_PORT72_DSPI_3_DSPI3_PCS3 |
        SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_OUT |
        SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_PFE_MAC0_PFE_MAC0_MDC |
        SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_OUT |
        SIUL2_0_PORT82_PFE_MAC2_PFE_MAC2_MDC |
        SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_OUT |
        SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_OUT |
        SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_OUT |
        SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_OUT |
        SIUL2_0_PORT11_DSPI_5_DSPI5_SOUT |
        SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_OUT |
        SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_OUT |
        SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_OUT |
        SIUL2_0_PORT18_I2C_4_I2C4_SDA_OUT |
        SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_OUT |
        SIUL2_0_PORT20_LLCE_FLEXRAY_LLCE_FR_DBG_1 |
        SIUL2_0_PORT23_GMAC_0_GMAC0_MDC |
        SIUL2_0_PORT24_GMAC_0_GMAC0_MD_OUT |
        SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_OUT |
        SIUL2_0_PORT26_DSPI_0_DSPI0_PCS2 |
        SIUL2_0_PORT27_LINFLEX_2_LIN2_TX |
        SIUL2_0_PORT28_MISC_TAMPER_LOOP_OUT0 |
        SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_OUT |
        SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_OUT |
        SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_OUT |
        SIUL2_0_PORT45_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_I2C_2_I2C2_SCL_OUT |
        SIUL2_0_PORT49_I2C_1_I2C1_SCL_OUT |
        SIUL2_0_PORT50_I2C_1_I2C1_SDA_OUT |
        SIUL2_0_PORT51_I2C_3_I2C3_SCL_OUT |
        SIUL2_0_PORT52_I2C_2_I2C2_SDA_OUT |
        SIUL2_0_PORT53_I2C_3_I2C3_SDA_OUT |
        SIUL2_0_PORT55_I2C_0_I2C0_SCL_OUT |
        SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_OUT |
        SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_OUT |
        SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_OUT |
        SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_FLEXCAN_0_CAN0_TX |
        SIUL2_0_PORT66_DSPI_0_DSPI0_PCS3 |
        SIUL2_0_PORT67_DSPI_0_DSPI0_PCS4 |
        SIUL2_0_PORT68_DSPI_1_DSPI1_PCS3 |
        SIUL2_0_PORT69_DSPI_1_DSPI1_PCS4 |
        SIUL2_0_PORT70_DSPI_2_DSPI2_PCS3 |
        SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_OUT |
        SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_OUT |
        SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_OUT |
        SIUL2_0_PORT79_I2C_3_I2C3_SCL_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_OUT |
        SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_OUT |
        SIUL2_0_PORT82_I2C_3_I2C3_SDA_OUT |
        SIUL2_0_PORT95_FLEXRAY_0_FR_DBG_1 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_FLEXRAY_0_FR_DBG_2 |
        SIUL2_0_PORT7_FLEXRAY_0_FR_DBG_3 |
        SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_OUT |
        SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_OUT |
        SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_OUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT17_I2C_4_I2C4_SCL_OUT |
        SIUL2_0_PORT19_LLCE_FLEXRAY_LLCE_FR_DBG_0 |
        SIUL2_0_PORT25_DSPI_4_DSPI4_SOUT |
        SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_OUT |
        SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_OUT |
        SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_OUT |
        SIUL2_0_PORT30_I2C_3_I2C3_SCL_OUT |
        SIUL2_0_PORT31_FLEXTIMER_1_FTM1_CH3 */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_PFE_MAC0_PFE_MAC0_PPS_0 |
        SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(9U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT52_DSPI_0_DSPI0_PCS1 |
        SIUL2_0_PORT53_DSPI_0_DSPI0_PCS2 |
        SIUL2_0_PORT54_DSPI_1_DSPI1_PCS1 |
        SIUL2_0_PORT55_DSPI_1_DSPI1_PCS2 |
        SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_C2_TXD_2 |
        SIUL2_0_PORT63_GMAC_0_GMAC0_RMII_REF_CLK */
        (uint16)( SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_OUT |
        SIUL2_0_PORT71_DSPI_2_DSPI2_PCS4 |
        SIUL2_0_PORT78_DSPI_0_DSPI0_PCS5 |
        SIUL2_0_PORT79_DSPI_0_DSPI0_PCS6 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_DSPI_0_DSPI0_PCS7 |
        SIUL2_0_PORT82_GMAC_0_GMAC0_RMII_REF_CLK */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT25_DSPI_0_DSPI0_PCS1 |
        SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_OUT */
        (uint16)( SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT41_DSPI_1_DSPI1_PCS1 */
        (uint16)( SHL_PAD_U32(9U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_C2_TXD_3 */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_OUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT25_PFE_PFE_UART_TX */
        (uint16)( SHL_PAD_U32(9U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT41_PFE_PFE_UART_TX */
        (uint16)( SHL_PAD_U32(9U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_ONLY_INPUT_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT9_BOOT_RCON0 |
        SIUL2_0_PORT10_BOOT_RCON1 |
        SIUL2_0_PORT10_WKPU_WKUP22 |
        SIUL2_0_PORT11_BOOT_RCON2 |
        SIUL2_0_PORT12_BOOT_RCON3 |
        SIUL2_0_PORT13_BOOT_RCON4 |
        SIUL2_0_PORT14_BOOT_RCON5 |
        SIUL2_0_PORT15_BOOT_RCON6 */
        (uint16)( SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_BOOT_RCON7 |
        SIUL2_0_PORT17_BOOT_RCON8 |
        SIUL2_0_PORT18_BOOT_RCON9 |
        SIUL2_0_PORT19_BOOT_RCON10 |
        SIUL2_0_PORT20_BOOT_RCON11 |
        SIUL2_0_PORT21_BOOT_RCON12 |
        SIUL2_0_PORT22_BOOT_RCON13 |
        SIUL2_0_PORT23_BOOT_RCON14 |
        SIUL2_0_PORT24_BOOT_RCON15 |
        SIUL2_0_PORT25_BOOT_RCON16 |
        SIUL2_0_PORT26_BOOT_RCON17 |
        SIUL2_0_PORT27_BOOT_RCON18 |
        SIUL2_0_PORT28_BOOT_RCON19 |
        SIUL2_0_PORT29_BOOT_RCON20 |
        SIUL2_0_PORT30_BOOT_RCON21 |
        SIUL2_0_PORT31_BOOT_RCON22 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_BOOT_RCON23 |
        SIUL2_0_PORT33_BOOT_RCON24 |
        SIUL2_0_PORT34_BOOT_RCON25 |
        SIUL2_0_PORT35_BOOT_RCON26 |
        SIUL2_0_PORT36_BOOT_RCON27 |
        SIUL2_0_PORT36_WKPU_WKUP17 |
        SIUL2_0_PORT37_BOOT_RCON28 |
        SIUL2_0_PORT38_BOOT_RCON29 |
        SIUL2_0_PORT38_WKPU_WKUP18 |
        SIUL2_0_PORT39_BOOT_RCON30 |
        SIUL2_0_PORT40_BOOT_RCON31 |
        SIUL2_0_PORT43_WKPU_WKUP0 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT0_JTAGC_TDI |
        SIUL2_0_PORT2_BOOT_BOOTMOD_0 |
        SIUL2_0_PORT3_BOOT_BOOTMOD_1 |
        SIUL2_0_PORT4_JTAGC_TCK |
        SIUL2_0_PORT5_JTAGC_TMS_IN |
        SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_IN |
        SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_IN |
        SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_IN |
        SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_IN |
        SIUL2_0_PORT10_LLCE_LPSPI_0_LLCE_LPSPI0_SIN |
        SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_IN |
        SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN |
        SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_IN |
        SIUL2_0_PORT14_DSPI_0_DSPI0_SIN |
        SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_I2C_0_I2C0_SDA_IN |
        SIUL2_0_PORT17_I2C_0_I2C0_SCL_IN |
        SIUL2_0_PORT18_I2C_4_I2C4_SDA_IN |
        SIUL2_0_PORT19_I2C_1_I2C1_SCL_IN |
        SIUL2_0_PORT20_I2C_1_I2C1_SDA_IN |
        SIUL2_0_PORT21_I2C_2_I2C2_SCL_IN |
        SIUL2_0_PORT22_I2C_2_I2C2_SDA_IN |
        SIUL2_0_PORT23_I2C_3_I2C3_SCL_IN |
        SIUL2_0_PORT24_I2C_0_I2C0_SDA_IN |
        SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_IN |
        SIUL2_0_PORT26_LINFLEX_1_LIN1_RX |
        SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_IN |
        SIUL2_0_PORT28_FLEXCAN_2_CAN2_RX |
        SIUL2_0_PORT29_I2C_3_I2C3_SDA_IN |
        SIUL2_0_PORT30_FLEXCAN_3_CAN3_RX |
        SIUL2_0_PORT31_I2C_0_I2C0_SDA_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FLEXRAY_0_FR_RXD_B |
        SIUL2_0_PORT33_SIUL_OFFCC_EIRQ_13 |
        SIUL2_0_PORT34_SIUL_OFFCC_EIRQ_14 |
        SIUL2_0_PORT35_SIUL_OFFCC_EIRQ_15 |
        SIUL2_0_PORT36_LLCE_LIN_1_LLCE_LIN1_RX |
        SIUL2_0_PORT37_SIUL_OFFCC_EIRQ_28 |
        SIUL2_0_PORT38_LLCE_LIN_2_LLCE_LIN2_RX |
        SIUL2_0_PORT39_SIUL_OFFCC_EIRQ_30 |
        SIUL2_0_PORT40_SIUL_OFFCC_EIRQ_31 |
        SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_IN |
        SIUL2_0_PORT42_LINFLEX_0_LIN0_RX |
        SIUL2_0_PORT43_FLEXCAN_0_CAN0_RX |
        SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_IN |
        SIUL2_0_PORT47_USDHC_0_SD0_CMD_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_USDHC_0_SD0_D_0_IN |
        SIUL2_0_PORT49_USDHC_0_SD0_D_1_IN |
        SIUL2_0_PORT50_I2C_1_I2C1_SDA_IN |
        SIUL2_0_PORT51_USDHC_0_SD0_D_3_IN |
        SIUL2_0_PORT52_I2C_2_I2C2_SDA_IN |
        SIUL2_0_PORT53_I2C_3_I2C3_SDA_IN |
        SIUL2_0_PORT54_USDHC_0_SD0_D_6_IN |
        SIUL2_0_PORT55_USDHC_0_SD0_D_7_IN |
        SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_IN |
        SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_IN |
        SIUL2_0_PORT58_USDHC_0_SD0_DQS |
        SIUL2_0_PORT59_MISC_TAMPER_EXTIN0 |
        SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_IN |
        SIUL2_0_PORT61_GMAC_0_GMAC0_MD_IN |
        SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_IN |
        SIUL2_0_PORT63_GMAC_0_GMAC0_RX_ER */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_GMAC_0_GMAC0_COL |
        SIUL2_0_PORT65_GMAC_0_GMAC0_CRS |
        SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_IN |
        SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_IN |
        SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_IN |
        SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_IN |
        SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_IN |
        SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_IN |
        SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_IN |
        SIUL2_0_PORT73_PFE_MAC1_PFE_MAC1_RXDV_IN |
        SIUL2_0_PORT74_GMAC_0_GMAC0_RXD_0_IN |
        SIUL2_0_PORT75_GMAC_0_GMAC0_RXD_1_IN |
        SIUL2_0_PORT76_GMAC_0_GMAC0_RXD_2_IN |
        SIUL2_0_PORT77_GMAC_0_GMAC0_RXD_3_IN |
        SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_IN |
        SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_IN |
        SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_IN |
        SIUL2_0_PORT82_I2C_3_I2C3_SDA_IN |
        SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_IN |
        SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_IN |
        SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_IN |
        SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_IN |
        SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_IN |
        SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_IN |
        SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_IN |
        SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_IN |
        SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_IN |
        SIUL2_0_PORT94_QUADSPI_QSPI_INTA_b |
        SIUL2_0_PORT95_DSPI_1_DSPI1_SIN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_IN |
        SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_IN |
        SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_IN |
        SIUL2_0_PORT10_DSPI_5_DSPI5_SIN |
        SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_IN |
        SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_IN |
        SIUL2_0_PORT13_FLEXTIMER_0_FTM0_EXT_CLK |
        SIUL2_0_PORT14_LINFLEX_0_LIN0_RX |
        SIUL2_0_PORT15_PFE_MAC1_PFE_MAC1_COL */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_IN |
        SIUL2_0_PORT17_I2C_4_I2C4_SCL_IN |
        SIUL2_0_PORT18_FLEXCAN_0_CAN0_RX |
        SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_IN |
        SIUL2_0_PORT20_FLEXCAN_1_CAN1_RX |
        SIUL2_0_PORT21_CTU_CTU_EXT_TRIG |
        SIUL2_0_PORT22_SIUL_OFFCC_EIRQ_3 |
        SIUL2_0_PORT23_SIUL_OFFCC_EIRQ_4 |
        SIUL2_0_PORT24_SIUL_OFFCC_EIRQ_5 |
        SIUL2_0_PORT25_SIUL_OFFCC_EIRQ_6 |
        SIUL2_0_PORT26_FLEXCAN_3_CAN3_RX |
        SIUL2_0_PORT27_FLEXTIMER_1_FTM1_EXT_CLK |
        SIUL2_0_PORT28_LINFLEX_2_LIN2_RX |
        SIUL2_0_PORT29_FLEXRAY_0_FR_RXD_A |
        SIUL2_0_PORT30_I2C_3_I2C3_SCL_IN |
        SIUL2_0_PORT31_SIUL_OFFCC_EIRQ_12 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_I2C_0_I2C0_SCL_IN |
        SIUL2_0_PORT33_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 |
        SIUL2_0_PORT34_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 |
        SIUL2_0_PORT36_LINFLEX_1_LIN1_RX |
        SIUL2_0_PORT37_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 |
        SIUL2_0_PORT38_SIUL_OFFCC_EIRQ_29 |
        SIUL2_0_PORT39_PFE_MAC0_PFE_MAC0_COL |
        SIUL2_0_PORT40_ADCSAR_0_ADCSAR0_INJ_TRIG |
        SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_IN |
        SIUL2_0_PORT42_FLEXCAN_2_CAN2_RX |
        SIUL2_0_PORT43_LLCE_CAN_0_LLCE_CAN0_RX |
        SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_I2C_2_I2C2_SCL_IN |
        SIUL2_0_PORT49_QUADSPI_QSPI_INTB_b |
        SIUL2_0_PORT50_USDHC_0_SD0_D_2_IN |
        SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_IN |
        SIUL2_0_PORT52_USDHC_0_SD0_D_4_IN |
        SIUL2_0_PORT53_USDHC_0_SD0_D_5_IN |
        SIUL2_0_PORT55_I2C_0_I2C0_SCL_IN |
        SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_IN |
        SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN |
        SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_IN |
        SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_IN |
        SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_IN |
        SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_IN |
        SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_IN |
        SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_IN |
        SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_IN |
        SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_IN |
        SIUL2_0_PORT70_GMAC_0_GMAC0_RX_ER |
        SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_RMII_REF_CLK |
        SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_IN |
        SIUL2_0_PORT73_GMAC_0_GMAC0_RXDV_IN |
        SIUL2_0_PORT74_PFE_MAC1_PFE_MAC1_RXD_0_IN |
        SIUL2_0_PORT75_PFE_MAC1_PFE_MAC1_RXD_1_IN |
        SIUL2_0_PORT76_PFE_MAC1_PFE_MAC1_RXD_2_IN |
        SIUL2_0_PORT77_PFE_MAC1_PFE_MAC1_RXD_3_IN |
        SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_IN |
        SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_IN |
        SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_IN */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_IN |
        SIUL2_0_PORT10_GMAC_0_GMAC0_PST_TS_TRIG_0 |
        SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_IN |
        SIUL2_0_PORT13_PFE_MAC1_PFE_MAC1_RX_ER |
        SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_IN */
        (uint16)( SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_LINFLEX_1_LIN1_RX |
        SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_IN |
        SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_IN |
        SIUL2_0_PORT19_SIUL_OFFCC_EIRQ_0 |
        SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_IN |
        SIUL2_0_PORT21_SIUL_OFFCC_EIRQ_2 |
        SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_IN |
        SIUL2_0_PORT25_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 |
        SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_IN |
        SIUL2_0_PORT27_SIUL_OFFCC_EIRQ_8 |
        SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_IN |
        SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_IN |
        SIUL2_0_PORT30_FLEXTIMER_1_FTM1_CH3 |
        SIUL2_0_PORT31_PFE_MAC2_PFE_MAC2_PST_TS_TRIG_0 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_IN |
        SIUL2_0_PORT33_PFE_MAC0_PFE_MAC0_CRS |
        SIUL2_0_PORT34_PFE_MAC0_PFE_MAC0_COL |
        SIUL2_0_PORT36_SIUL_OFFCC_EIRQ_27 |
        SIUL2_0_PORT37_ADCSAR_1_ADCSAR1_TRIG |
        SIUL2_0_PORT38_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 |
        SIUL2_0_PORT41_PFE_MAC0_PFE_MAC0_RX_ER |
        SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT49_I2C_1_I2C1_SCL_IN |
        SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_IN |
        SIUL2_0_PORT51_I2C_3_I2C3_SCL_IN |
        SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_IN |
        SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_IN |
        SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_IN |
        SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN |
        SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_RMII_REF_CLK */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_IN |
        SIUL2_0_PORT65_LINFLEX_2_LIN2_RX |
        SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_RX_ER |
        SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_IN |
        SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_IN |
        SIUL2_0_PORT79_I2C_3_I2C3_SCL_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT9_GMAC_0_GMAC0_PST_TS_TRIG_1 |
        SIUL2_0_PORT10_GMAC_0_GMAC0_AUX_TRIG_2 */
        (uint16)( SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_IN |
        SIUL2_0_PORT20_SIUL_OFFCC_EIRQ_1 |
        SIUL2_0_PORT24_GMAC_0_GMAC0_MD_IN |
        SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_IN |
        SIUL2_0_PORT27_MISC_TAMPER_EXTIN0 |
        SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_IN |
        SIUL2_0_PORT29_SIUL_OFFCC_EIRQ_10 |
        SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_IN |
        SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 |
        SIUL2_0_PORT33_I2C_4_I2C4_SDA_IN |
        SIUL2_0_PORT34_I2C_4_I2C4_SCL_IN |
        SIUL2_0_PORT36_ADCSAR_0_ADCSAR0_TRIG |
        SIUL2_0_PORT38_ADCSAR_1_ADCSAR1_INJ_TRIG |
        SIUL2_0_PORT41_PFE_MAC2_PFE_MAC2_RX_ER |
        SIUL2_0_PORT42_DSPI_4_DSPI4_SIN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_RX_ER |
        SIUL2_0_PORT63_FLEXTIMER_1_FTM1_EXT_CLK */
        (uint16)( SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_IN |
        SIUL2_0_PORT65_FLEXCAN_0_CAN0_RX |
        SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_IN |
        SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT5_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT9_GMAC_0_GMAC0_AUX_TRIG_3 */
        (uint16)( SHL_PAD_U32(9U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_PFE_MAC1_PFE_MAC1_CRS |
        SIUL2_0_PORT26_SIUL_OFFCC_EIRQ_7 |
        SIUL2_0_PORT27_PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 |
        SIUL2_0_PORT28_SIUL_OFFCC_EIRQ_9 |
        SIUL2_0_PORT29_PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 |
        SIUL2_0_PORT30_PFE_MAC2_PFE_MAC2_COL */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN |
        SIUL2_0_PORT42_PFE_PFE_UART_RX */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT62_PFE_MAC2_PFE_MAC2_TXD_2 |
        SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN */
        (uint16)( SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_PFE_MAC2_PFE_MAC2_RXDV_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT6_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT26_PFE_PFE_UART_RX |
        SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN |
        SIUL2_0_PORT29_PFE_MAC2_PFE_MAC2_CRS |
        SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN */
        (uint16)( SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63
        SIUL2_0_PORT63_PFE_MAC2_PFE_MAC2_TXD_3 */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_IN */
        (uint16)( SHL_PAD_U32(1U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INPUT7_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_IN */
        (uint16)( SHL_PAD_U32(13U)
                ),
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT1_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT5_JTAGC_TMS_INOUT |
        SIUL2_0_PORT9_LLCE_LPSPI_0_LLCE_LPSPI0_SCK_INOUT |
        SIUL2_0_PORT13_DSPI_0_DSPI0_SCK_INOUT |
        SIUL2_0_PORT14_FLEXTIMER_1_FTM1_CH0_INOUT */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_I2C_0_I2C0_SDA_INOUT |
        SIUL2_0_PORT17_I2C_0_I2C0_SCL_INOUT |
        SIUL2_0_PORT19_I2C_1_I2C1_SCL_INOUT |
        SIUL2_0_PORT20_I2C_1_I2C1_SDA_INOUT |
        SIUL2_0_PORT21_I2C_2_I2C2_SCL_INOUT |
        SIUL2_0_PORT22_I2C_2_I2C2_SDA_INOUT |
        SIUL2_0_PORT23_I2C_3_I2C3_SCL_INOUT |
        SIUL2_0_PORT24_I2C_0_I2C0_SDA_INOUT |
        SIUL2_0_PORT26_FLEXTIMER_0_FTM0_CH2_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_I2C_0_I2C0_SCL_INOUT |
        SIUL2_0_PORT33_I2C_4_I2C4_SDA_INOUT |
        SIUL2_0_PORT42_FLEXTIMER_0_FTM0_CH5_INOUT |
        SIUL2_0_PORT47_USDHC_0_SD0_CMD_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_USDHC_0_SD0_D_0_INOUT |
        SIUL2_0_PORT49_USDHC_0_SD0_D_1_INOUT |
        SIUL2_0_PORT50_USDHC_0_SD0_D_2_INOUT |
        SIUL2_0_PORT51_USDHC_0_SD0_D_3_INOUT |
        SIUL2_0_PORT52_USDHC_0_SD0_D_4_INOUT |
        SIUL2_0_PORT53_USDHC_0_SD0_D_5_INOUT |
        SIUL2_0_PORT54_USDHC_0_SD0_D_6_INOUT |
        SIUL2_0_PORT55_USDHC_0_SD0_D_7_INOUT |
        SIUL2_0_PORT61_GMAC_0_GMAC0_MD_INOUT |
        SIUL2_0_PORT62_USB_USB_ULPI_DATA_0_INOUT |
        SIUL2_0_PORT63_USB_USB_ULPI_DATA_1_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT64_USB_USB_ULPI_DATA_2_INOUT |
        SIUL2_0_PORT65_USB_USB_ULPI_DATA_3_INOUT |
        SIUL2_0_PORT66_GMAC_0_GMAC0_TX_CLK_INOUT |
        SIUL2_0_PORT67_GMAC_0_GMAC0_TX_EN_INOUT |
        SIUL2_0_PORT68_GMAC_0_GMAC0_TXD_0_INOUT |
        SIUL2_0_PORT69_GMAC_0_GMAC0_TXD_1_INOUT |
        SIUL2_0_PORT70_GMAC_0_GMAC0_TXD_2_INOUT |
        SIUL2_0_PORT71_GMAC_0_GMAC0_TXD_3_INOUT |
        SIUL2_0_PORT72_GMAC_0_GMAC0_RX_CLK_INOUT |
        SIUL2_0_PORT78_PFE_MAC0_PFE_MAC0_TX_EN_INOUT |
        SIUL2_0_PORT79_PFE_MAC0_PFE_MAC0_MD_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_GMAC_0_GMAC0_TS_CLK_INOUT |
        SIUL2_0_PORT85_QUADSPI_QSPI_DATA_A_0_INOUT |
        SIUL2_0_PORT86_QUADSPI_QSPI_DATA_A_1_INOUT |
        SIUL2_0_PORT87_QUADSPI_QSPI_DATA_A_2_INOUT |
        SIUL2_0_PORT88_QUADSPI_QSPI_DATA_A_3_INOUT |
        SIUL2_0_PORT89_QUADSPI_QSPI_DATA_A_4_INOUT |
        SIUL2_0_PORT90_QUADSPI_QSPI_DATA_A_5_INOUT |
        SIUL2_0_PORT91_QUADSPI_QSPI_DATA_A_6_INOUT |
        SIUL2_0_PORT92_QUADSPI_QSPI_DATA_A_7_INOUT |
        SIUL2_0_PORT93_QUADSPI_QSPI_DQS_A_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT2_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT7_DSPI_1_DSPI1_PCS0_INOUT |
        SIUL2_0_PORT9_FLEXTIMER_0_FTM0_CH1_INOUT |
        SIUL2_0_PORT11_FLEXTIMER_0_FTM0_CH3_INOUT |
        SIUL2_0_PORT12_FLEXTIMER_0_FTM0_CH4_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_DSPI_0_DSPI0_PCS0_INOUT |
        SIUL2_0_PORT18_FLEXTIMER_0_FTM0_CH2_INOUT |
        SIUL2_0_PORT20_FLEXTIMER_1_FTM1_CH2_INOUT |
        SIUL2_0_PORT24_PFE_MAC1_PFE_MAC1_MD_INOUT |
        SIUL2_0_PORT26_DSPI_4_DSPI4_PCS0_INOUT |
        SIUL2_0_PORT28_FLEXTIMER_1_FTM1_CH1_INOUT |
        SIUL2_0_PORT29_I2C_3_I2C3_SDA_INOUT |
        SIUL2_0_PORT30_LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_INOUT |
        SIUL2_0_PORT31_I2C_0_I2C0_SDA_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_FLEXTIMER_1_FTM1_CH4_INOUT |
        SIUL2_0_PORT34_I2C_4_I2C4_SCL_INOUT |
        SIUL2_0_PORT46_QUADSPI_QSPI_DATA_B_0_INOUT |
        SIUL2_0_PORT47_QUADSPI_QSPI_DATA_B_3_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT50_QUADSPI_QSPI_DATA_B_4_INOUT |
        SIUL2_0_PORT51_QUADSPI_QSPI_DATA_B_1_INOUT |
        SIUL2_0_PORT52_QUADSPI_QSPI_DQS_B_INOUT |
        SIUL2_0_PORT53_QUADSPI_QSPI_DATA_B_7_INOUT |
        SIUL2_0_PORT56_QUADSPI_QSPI_DATA_B_5_INOUT |
        SIUL2_0_PORT57_QUADSPI_QSPI_DATA_B_2_INOUT |
        SIUL2_0_PORT58_QUADSPI_QSPI_DATA_B_6_INOUT |
        SIUL2_0_PORT59_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT |
        SIUL2_0_PORT61_PFE_MAC1_PFE_MAC1_MD_INOUT |
        SIUL2_0_PORT62_DSPI_3_DSPI3_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT65_FLEXTIMER_1_FTM1_CH2_INOUT |
        SIUL2_0_PORT66_PFE_MAC1_PFE_MAC1_TX_CLK_INOUT |
        SIUL2_0_PORT67_PFE_MAC1_PFE_MAC1_TX_EN_INOUT |
        SIUL2_0_PORT68_PFE_MAC1_PFE_MAC1_TXD_0_INOUT |
        SIUL2_0_PORT69_PFE_MAC1_PFE_MAC1_TXD_1_INOUT |
        SIUL2_0_PORT70_PFE_MAC1_PFE_MAC1_TXD_2_INOUT |
        SIUL2_0_PORT71_GMAC_0_GMAC0_RMII_REF_CLK_INOUT |
        SIUL2_0_PORT78_PFE_MAC2_PFE_MAC2_TX_EN_INOUT |
        SIUL2_0_PORT79_PFE_MAC2_PFE_MAC2_MD_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT81_PFE_MAC2_PFE_MAC2_MD_INOUT |
        SIUL2_0_PORT95_FLEXTIMER_1_FTM1_CH1_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT3_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT6_FLEXTIMER_1_FTM1_CH2_INOUT |
        SIUL2_0_PORT7_FLEXTIMER_1_FTM1_CH3_INOUT |
        SIUL2_0_PORT8_DSPI_1_DSPI1_SCK_INOUT |
        SIUL2_0_PORT9_DSPI_5_DSPI5_SCK_INOUT |
        SIUL2_0_PORT12_DSPI_5_DSPI5_PCS0_INOUT |
        SIUL2_0_PORT15_FLEXTIMER_0_FTM0_CH4_INOUT */
        (uint16)( SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT16_FLEXTIMER_0_FTM0_CH5_INOUT |
        SIUL2_0_PORT17_FLEXTIMER_0_FTM0_CH0_INOUT |
        SIUL2_0_PORT18_I2C_4_I2C4_SDA_INOUT |
        SIUL2_0_PORT19_FLEXTIMER_1_FTM1_CH0_INOUT |
        SIUL2_0_PORT24_GMAC_0_GMAC0_MD_INOUT |
        SIUL2_0_PORT25_FLEXTIMER_0_FTM0_CH3_INOUT |
        SIUL2_0_PORT29_FLEXTIMER_1_FTM1_CH2_INOUT |
        SIUL2_0_PORT30_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT |
        SIUL2_0_PORT31_LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT32_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT |
        SIUL2_0_PORT41_FLEXTIMER_0_FTM0_CH4_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(9U)
                ),
        /* Pads 48 - 63
        SIUL2_0_PORT48_I2C_2_I2C2_SCL_INOUT |
        SIUL2_0_PORT49_I2C_1_I2C1_SCL_INOUT |
        SIUL2_0_PORT50_I2C_1_I2C1_SDA_INOUT |
        SIUL2_0_PORT51_I2C_3_I2C3_SCL_INOUT |
        SIUL2_0_PORT52_I2C_2_I2C2_SDA_INOUT |
        SIUL2_0_PORT53_I2C_3_I2C3_SDA_INOUT |
        SIUL2_0_PORT55_I2C_0_I2C0_SCL_INOUT |
        SIUL2_0_PORT60_LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_INOUT |
        SIUL2_0_PORT61_LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_INOUT |
        SIUL2_0_PORT62_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT |
        SIUL2_0_PORT63_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 64 - 79
        SIUL2_0_PORT71_PFE_MAC1_PFE_MAC1_TXD_3_INOUT |
        SIUL2_0_PORT72_PFE_MAC1_PFE_MAC1_RX_CLK_INOUT |
        SIUL2_0_PORT78_FLEXTIMER_0_FTM0_CH1_INOUT |
        SIUL2_0_PORT79_I2C_3_I2C3_SCL_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 80 - 95
        SIUL2_0_PORT80_FLEXTIMER_1_FTM1_CH5_INOUT |
        SIUL2_0_PORT81_PFE_MAC0_PFE_MAC0_MD_INOUT |
        SIUL2_0_PORT82_I2C_3_I2C3_SDA_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U)
                ),
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT4_MODE: */
    {
        /* Pads 0 - 15
        SIUL2_0_PORT8_FLEXTIMER_1_FTM1_CH0_INOUT |
        SIUL2_0_PORT11_LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_INOUT |
        SIUL2_0_PORT12_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                ),
        /* Pads 16 - 31
        SIUL2_0_PORT17_I2C_4_I2C4_SCL_INOUT |
        SIUL2_0_PORT27_LLCE_LPSPI_2_LLCE_LPSPI2_SCK_INOUT |
        SIUL2_0_PORT28_LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT |
        SIUL2_0_PORT29_LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_INOUT |
        SIUL2_0_PORT30_I2C_3_I2C3_SCL_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 32 - 47
        SIUL2_0_PORT41_DSPI_4_DSPI4_SCK_INOUT */
        (uint16)( SHL_PAD_U32(9U)
                ),
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT64_FLEXTIMER_1_FTM1_CH1_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT5_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31
        SIUL2_0_PORT28_LLCE_LPSPI_2_LLCE_LPSPI2_SIN_INOUT */
        (uint16)( SHL_PAD_U32(12U)
                ),
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79
        SIUL2_0_PORT64_PFE_MAC2_PFE_MAC2_RX_CLK_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT6_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }

};

/**
* @brief Array of bits storing availability of PortPinModes for MSCRs on second SIUL2 instance
*/
static const Port_PinModeAvailabilityArrayType Port_SIUL2_1_au16PinModeAvailability =
{

    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_GPIO |
        SIUL2_1_PORT113_GPIO |
        SIUL2_1_PORT114_GPIO |
        SIUL2_1_PORT115_GPIO |
        SIUL2_1_PORT116_GPIO |
        SIUL2_1_PORT117_GPIO |
        SIUL2_1_PORT118_GPIO |
        SIUL2_1_PORT119_GPIO |
        SIUL2_1_PORT120_GPIO |
        SIUL2_1_PORT121_GPIO |
        SIUL2_1_PORT122_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_GPIO |
        SIUL2_1_PORT145_GPIO |
        SIUL2_1_PORT146_GPI |
        SIUL2_1_PORT147_GPIO |
        SIUL2_1_PORT148_GPI |
        SIUL2_1_PORT149_GPIO |
        SIUL2_1_PORT150_GPI |
        SIUL2_1_PORT151_GPIO |
        SIUL2_1_PORT152_GPI |
        SIUL2_1_PORT153_GPIO |
        SIUL2_1_PORT154_GPI |
        SIUL2_1_PORT155_GPIO |
        SIUL2_1_PORT156_GPI |
        SIUL2_1_PORT157_GPIO |
        SIUL2_1_PORT158_GPI |
        SIUL2_1_PORT159_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT160_GPI |
        SIUL2_1_PORT161_GPIO |
        SIUL2_1_PORT162_GPI |
        SIUL2_1_PORT163_GPIO |
        SIUL2_1_PORT164_GPI |
        SIUL2_1_PORT165_GPIO |
        SIUL2_1_PORT166_GPI |
        SIUL2_1_PORT167_GPIO |
        SIUL2_1_PORT168_GPI |
        SIUL2_1_PORT169_GPIO |
        SIUL2_1_PORT170_GPI |
        SIUL2_1_PORT171_GPIO |
        SIUL2_1_PORT172_GPI |
        SIUL2_1_PORT173_GPIO |
        SIUL2_1_PORT174_GPI |
        SIUL2_1_PORT175_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT176_GPI |
        SIUL2_1_PORT177_GPIO |
        SIUL2_1_PORT178_GPIO |
        SIUL2_1_PORT179_GPI |
        SIUL2_1_PORT180_GPIO |
        SIUL2_1_PORT181_GPIO |
        SIUL2_1_PORT182_GPI |
        SIUL2_1_PORT183_GPI |
        SIUL2_1_PORT184_GPIO |
        SIUL2_1_PORT185_GPIO |
        SIUL2_1_PORT186_GPIO |
        SIUL2_1_PORT187_GPIO |
        SIUL2_1_PORT188_GPIO |
        SIUL2_1_PORT189_GPIO |
        SIUL2_1_PORT190_GPIO */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_ALT1_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_OUT |
        SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_OUT |
        SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_OUT |
        SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_OUT |
        SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_OUT |
        SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_OUT |
        SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_OUT |
        SIUL2_1_PORT119_I2C_2_I2C2_SDA_OUT |
        SIUL2_1_PORT120_I2C_2_I2C2_SCL_OUT |
        SIUL2_1_PORT121_DSPI_4_DSPI4_PCS2 |
        SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_OUT |
        SIUL2_1_PORT145_LLCE_CAN_1_LLCE_CAN1_TX |
        SIUL2_1_PORT147_LLCE_CAN_2_LLCE_CAN2_TX |
        SIUL2_1_PORT149_LLCE_CAN_3_LLCE_CAN3_TX |
        SIUL2_1_PORT151_LLCE_CAN_4_LLCE_CAN4_TX |
        SIUL2_1_PORT153_LLCE_CAN_5_LLCE_CAN5_TX |
        SIUL2_1_PORT155_LLCE_CAN_6_LLCE_CAN6_TX |
        SIUL2_1_PORT157_LLCE_CAN_7_LLCE_CAN7_TX |
        SIUL2_1_PORT159_LLCE_CAN_8_LLCE_CAN8_TX */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_LLCE_CAN_9_LLCE_CAN9_TX |
        SIUL2_1_PORT163_LLCE_CAN_10_LLCE_CAN10_TX |
        SIUL2_1_PORT165_LLCE_CAN_11_LLCE_CAN11_TX |
        SIUL2_1_PORT167_LLCE_CAN_12_LLCE_CAN12_TX |
        SIUL2_1_PORT169_LLCE_CAN_13_LLCE_CAN13_TX |
        SIUL2_1_PORT171_LLCE_CAN_14_LLCE_CAN14_TX |
        SIUL2_1_PORT173_LLCE_CAN_15_LLCE_CAN15_TX |
        SIUL2_1_PORT175_LLCE_LIN_0_LLCE_LIN0_TX */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_LLCE_FLEXRAY_LLCE_FR_TXE_A_b |
        SIUL2_1_PORT178_LLCE_FLEXRAY_LLCE_FR_TXD_A |
        SIUL2_1_PORT180_LLCE_FLEXRAY_LLCE_FR_TXE_B_b |
        SIUL2_1_PORT181_LLCE_FLEXRAY_LLCE_FR_TXD_B |
        SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_OUT |
        SIUL2_1_PORT185_DSPI_2_DSPI2_SOUT |
        SIUL2_1_PORT186_USB_USB_ULPI_STP |
        SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_OUT |
        SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_OUT |
        SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_OUT |
        SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_OUT |
        SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_OUT |
        SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_OUT |
        SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_OUT |
        SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_OUT |
        SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_OUT |
        SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_OUT |
        SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_OUT |
        SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_OUT |
        SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_OUT |
        SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_OUT |
        SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_OUT |
        SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_OUT |
        SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_OUT |
        SIUL2_1_PORT157_DSPI_2_DSPI2_SOUT |
        SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_OUT |
        SIUL2_1_PORT163_DSPI_3_DSPI3_SOUT |
        SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_OUT |
        SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_OUT |
        SIUL2_1_PORT169_DSPI_4_DSPI4_SOUT |
        SIUL2_1_PORT171_LINFLEX_2_LIN2_TX |
        SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_OUT |
        SIUL2_1_PORT175_LINFLEX_0_LIN0_TX */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_OUT |
        SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_OUT |
        SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_OUT |
        SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_OUT |
        SIUL2_1_PORT184_FLEXCAN_2_CAN2_TX |
        SIUL2_1_PORT185_FLEXCAN_3_CAN3_TX |
        SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_OUT |
        SIUL2_1_PORT187_PFE_MAC2_PFE_MAC2_C2_TXD_1 |
        SIUL2_1_PORT188_FLEXRAY_0_FR_DBG_2 |
        SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_OUT |
        SIUL2_1_PORT190_FLEXCAN_1_CAN1_TX */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_OUT |
        SIUL2_1_PORT113_I2C_1_I2C1_SDA_OUT |
        SIUL2_1_PORT114_I2C_1_I2C1_SCL_OUT |
        SIUL2_1_PORT115_GMAC_0_GMAC0_RMII_REF_CLK |
        SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_OUT |
        SIUL2_1_PORT120_DSPI_4_DSPI4_PCS1 |
        SIUL2_1_PORT122_I2C_0_I2C0_SDA_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_I2C_0_I2C0_SCL_OUT |
        SIUL2_1_PORT151_PFE_MAC0_PFE_MAC0_PPS_0 |
        SIUL2_1_PORT153_I2C_0_I2C0_SDA_OUT |
        SIUL2_1_PORT155_DSPI_4_DSPI4_PCS1 |
        SIUL2_1_PORT157_DSPI_4_DSPI4_PCS2 |
        SIUL2_1_PORT159_I2C_0_I2C0_SCL_OUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_I2C_0_I2C0_SDA_OUT |
        SIUL2_1_PORT163_I2C_1_I2C1_SCL_OUT |
        SIUL2_1_PORT165_I2C_1_I2C1_SDA_OUT |
        SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_OUT |
        SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_OUT |
        SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_OUT |
        SIUL2_1_PORT173_DSPI_5_DSPI5_SOUT |
        SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_OUT |
        SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_OUT |
        SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_OUT |
        SIUL2_1_PORT184_FLEXRAY_0_FR_DBG_0 |
        SIUL2_1_PORT185_FLEXRAY_0_FR_DBG_1 |
        SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_OUT |
        SIUL2_1_PORT187_DSPI_2_DSPI2_PCS2 |
        SIUL2_1_PORT188_LLCE_FLEXRAY_LLCE_FR_DBG_2 |
        SIUL2_1_PORT189_FLEXRAY_0_FR_DBG_3 |
        SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_OUT |
        SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_OUT |
        SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_OUT |
        SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT159_DSPI_5_DSPI5_PCS1 */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_DSPI_5_DSPI5_PCS2 |
        SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_OUT |
        SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_OUT |
        SIUL2_1_PORT173_MISC_TAMPER_LOOP_OUT0 |
        SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_PFE_MAC1_PFE_MAC1_MDC |
        SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_OUT |
        SIUL2_1_PORT184_LLCE_FLEXRAY_LLCE_FR_DBG_0 |
        SIUL2_1_PORT185_LLCE_FLEXRAY_LLCE_FR_DBG_1 |
        SIUL2_1_PORT186_PFE_MAC2_PFE_MAC2_C2_TXD_0 |
        SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_OUT |
        SIUL2_1_PORT189_LLCE_FLEXRAY_LLCE_FR_DBG_3 |
        SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT114_DSPI_5_DSPI5_PCS1 |
        SIUL2_1_PORT115_DSPI_5_DSPI5_PCS2 */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175
        SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_OUT |
        SIUL2_1_PORT175_I2C_1_I2C1_SCL_OUT */
        (uint16)( SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_GMAC_0_GMAC0_MDC |
        SIUL2_1_PORT178_GMAC_0_GMAC0_MD_OUT |
        SIUL2_1_PORT184_PFE_MAC2_PFE_MAC2_C2_TX_CLK |
        SIUL2_1_PORT185_PFE_MAC2_PFE_MAC2_C2_TX_EN |
        SIUL2_1_PORT186_DSPI_2_DSPI2_PCS1 |
        SIUL2_1_PORT188_DSPI_3_DSPI3_PCS1 |
        SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_OUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                )
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175
        SIUL2_1_PORT175_LLCE_LPSPI_3_LLCE_LPSPI3_SIN */
        (uint16)( SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_OUT |
        SIUL2_1_PORT189_DSPI_3_DSPI3_PCS2 */
        (uint16)( SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U)
                )
    }
    ,
    /*  Mode PORT_ONLY_INPUT_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT146_WKPU_WKUP1 |
        SIUL2_1_PORT148_WKPU_WKUP2 |
        SIUL2_1_PORT150_WKPU_WKUP3 |
        SIUL2_1_PORT152_WKPU_WKUP4 |
        SIUL2_1_PORT154_WKPU_WKUP5 |
        SIUL2_1_PORT156_WKPU_WKUP6 |
        SIUL2_1_PORT158_WKPU_WKUP7 */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT160_WKPU_WKUP8 |
        SIUL2_1_PORT162_WKPU_WKUP9 |
        SIUL2_1_PORT164_WKPU_WKUP10 |
        SIUL2_1_PORT166_WKPU_WKUP11 |
        SIUL2_1_PORT168_WKPU_WKUP12 |
        SIUL2_1_PORT170_WKPU_WKUP13 |
        SIUL2_1_PORT172_WKPU_WKUP14 |
        SIUL2_1_PORT174_WKPU_WKUP15 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT176_WKPU_WKUP16 |
        SIUL2_1_PORT179_WKPU_WKUP20 |
        SIUL2_1_PORT182_WKPU_WKUP21 |
        SIUL2_1_PORT183_WKPU_WKUP19 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U)
                )
    }
    ,
    /*  Mode PORT_INPUT1_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_IN |
        SIUL2_1_PORT113_I2C_1_I2C1_SDA_IN |
        SIUL2_1_PORT114_I2C_1_I2C1_SCL_IN |
        SIUL2_1_PORT115_FLEXTIMER_0_FTM0_CH5 |
        SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_IN |
        SIUL2_1_PORT117_PFE_MAC0_PFE_MAC0_RXDV_IN |
        SIUL2_1_PORT118_PFE_MAC0_PFE_MAC0_RXD_0_IN |
        SIUL2_1_PORT119_PFE_MAC0_PFE_MAC0_RXD_1_IN |
        SIUL2_1_PORT120_PFE_MAC0_PFE_MAC0_RXD_2_IN |
        SIUL2_1_PORT121_PFE_MAC0_PFE_MAC0_RXD_3_IN |
        SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_I2C_0_I2C0_SCL_IN |
        SIUL2_1_PORT145_FLEXTIMER_0_FTM0_PHA |
        SIUL2_1_PORT146_LLCE_CAN_1_LLCE_CAN1_RX |
        SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_IN |
        SIUL2_1_PORT148_LLCE_CAN_2_LLCE_CAN2_RX |
        SIUL2_1_PORT149_FLEXTIMER_0_FTM0_PHB |
        SIUL2_1_PORT150_LLCE_CAN_3_LLCE_CAN3_RX |
        SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_IN |
        SIUL2_1_PORT152_LLCE_CAN_4_LLCE_CAN4_RX |
        SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_IN |
        SIUL2_1_PORT154_LLCE_CAN_5_LLCE_CAN5_RX |
        SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_IN |
        SIUL2_1_PORT156_LLCE_CAN_6_LLCE_CAN6_RX |
        SIUL2_1_PORT158_LLCE_CAN_7_LLCE_CAN7_RX |
        SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT160_LLCE_CAN_8_LLCE_CAN8_RX |
        SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_IN |
        SIUL2_1_PORT162_LLCE_CAN_9_LLCE_CAN9_RX |
        SIUL2_1_PORT163_I2C_1_I2C1_SCL_IN |
        SIUL2_1_PORT164_LLCE_CAN_10_LLCE_CAN10_RX |
        SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_IN |
        SIUL2_1_PORT166_LLCE_CAN_11_LLCE_CAN11_RX |
        SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_IN |
        SIUL2_1_PORT168_LLCE_CAN_12_LLCE_CAN12_RX |
        SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN |
        SIUL2_1_PORT170_LLCE_CAN_13_LLCE_CAN13_RX |
        SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_IN |
        SIUL2_1_PORT172_LLCE_CAN_14_LLCE_CAN14_RX |
        SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_IN |
        SIUL2_1_PORT174_LLCE_CAN_15_LLCE_CAN15_RX |
        SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT176_LLCE_LIN_0_LLCE_LIN0_RX |
        SIUL2_1_PORT177_SIUL_OFFCC_EIRQ_2 |
        SIUL2_1_PORT178_SIUL_OFFCC_EIRQ_3 |
        SIUL2_1_PORT179_LLCE_FLEXRAY_LLCE_FR_RXD_A |
        SIUL2_1_PORT180_GMAC_0_GMAC0_PST_TS_TRIG_0 |
        SIUL2_1_PORT181_GMAC_0_GMAC0_PST_TS_TRIG_1 |
        SIUL2_1_PORT182_LLCE_FLEXRAY_LLCE_FR_RXD_B |
        SIUL2_1_PORT183_LLCE_LIN_3_LLCE_LIN3_RX |
        SIUL2_1_PORT184_USB_USB_ULPI_CLK |
        SIUL2_1_PORT185_USB_USB_ULPI_DIR |
        SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_IN |
        SIUL2_1_PORT187_USB_USB_ULPI_NXT |
        SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_IN |
        SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_IN |
        SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INPUT2_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_FLEXCAN_1_CAN1_RX |
        SIUL2_1_PORT113_SIUL_OFFCC_EIRQ_23 |
        SIUL2_1_PORT114_SIUL_OFFCC_EIRQ_24 |
        SIUL2_1_PORT115_SIUL_OFFCC_EIRQ_25 |
        SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_IN |
        SIUL2_1_PORT117_PFE_MAC2_PFE_MAC2_RXDV_IN |
        SIUL2_1_PORT118_PFE_MAC2_PFE_MAC2_RXD_0_IN |
        SIUL2_1_PORT119_PFE_MAC2_PFE_MAC2_RXD_1_IN |
        SIUL2_1_PORT120_PFE_MAC2_PFE_MAC2_RXD_2_IN |
        SIUL2_1_PORT121_PFE_MAC2_PFE_MAC2_RXD_3_IN |
        SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_IN |
        SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_IN |
        SIUL2_1_PORT151_SIUL_OFFCC_EIRQ_0 |
        SIUL2_1_PORT152_FLEXTIMER_0_FTM0_EXT_CLK |
        SIUL2_1_PORT153_I2C_0_I2C0_SDA_IN |
        SIUL2_1_PORT154_SIUL_OFFCC_EIRQ_8 |
        SIUL2_1_PORT155_RTC_RTC_EXT_CLK |
        SIUL2_1_PORT156_DSPI_2_DSPI2_SCK |
        SIUL2_1_PORT158_DSPI_2_DSPI2_SIN |
        SIUL2_1_PORT159_I2C_0_I2C0_SCL_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT160_SIUL_OFFCC_EIRQ_9 |
        SIUL2_1_PORT161_I2C_0_I2C0_SDA_IN |
        SIUL2_1_PORT162_DSPI_3_DSPI3_SCK |
        SIUL2_1_PORT164_DSPI_3_DSPI3_SIN |
        SIUL2_1_PORT165_I2C_1_I2C1_SDA_IN |
        SIUL2_1_PORT166_DSPI_4_DSPI4_SCK |
        SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_IN |
        SIUL2_1_PORT168_SIUL_OFFCC_EIRQ_11 |
        SIUL2_1_PORT170_DSPI_4_DSPI4_SIN |
        SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_IN |
        SIUL2_1_PORT172_LINFLEX_2_LIN2_RX |
        SIUL2_1_PORT174_DSPI_5_DSPI5_SIN |
        SIUL2_1_PORT175_I2C_1_I2C1_SCL_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT176_LINFLEX_0_LIN0_RX |
        SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_IN |
        SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_IN |
        SIUL2_1_PORT179_LLCE_LPSPI_3_LLCE_LPSPI3_SIN |
        SIUL2_1_PORT180_GMAC_0_GMAC0_AUX_TRIG_2 |
        SIUL2_1_PORT181_GMAC_0_GMAC0_AUX_TRIG_3 |
        SIUL2_1_PORT182_SIUL_OFFCC_EIRQ_7 |
        SIUL2_1_PORT183_PFE_MAC0_PFE_MAC0_CRS |
        SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_IN |
        SIUL2_1_PORT185_SIUL_OFFCC_EIRQ_17 |
        SIUL2_1_PORT186_FLEXCAN_3_CAN3_RX |
        SIUL2_1_PORT187_DSPI_2_DSPI2_SIN |
        SIUL2_1_PORT188_DSPI_3_DSPI3_SIN |
        SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_IN |
        SIUL2_1_PORT190_SIUL_OFFCC_EIRQ_22 */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INPUT3_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_IN |
        SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN |
        SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_RX_ER |
        SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN |
        SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_IN |
        SIUL2_1_PORT117_SIUL_OFFCC_EIRQ_26 |
        SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_IN |
        SIUL2_1_PORT119_I2C_2_I2C2_SDA_IN |
        SIUL2_1_PORT120_I2C_2_I2C2_SCL_IN |
        SIUL2_1_PORT122_I2C_0_I2C0_SDA_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_IN |
        SIUL2_1_PORT152_PFE_MAC0_PFE_MAC0_RX_ER |
        SIUL2_1_PORT156_FLEXTIMER_1_FTM1_PHA |
        SIUL2_1_PORT158_FLEXTIMER_1_FTM1_PHB */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT165_SIUL_OFFCC_EIRQ_10 |
        SIUL2_1_PORT167_PFE_MAC0_PFE_MAC0_COL |
        SIUL2_1_PORT168_PFE_MAC0_PFE_MAC0_CRS |
        SIUL2_1_PORT170_PFE_MAC0_PFE_MAC0_RX_ER |
        SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN |
        SIUL2_1_PORT172_DSPI_5_DSPI5_SCK |
        SIUL2_1_PORT174_MISC_TAMPER_EXTIN0 |
        SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN */
        (uint16)( SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_IN |
        SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_IN |
        SIUL2_1_PORT179_SIUL_OFFCC_EIRQ_4 |
        SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_IN |
        SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_IN |
        SIUL2_1_PORT184_SIUL_OFFCC_EIRQ_16 |
        SIUL2_1_PORT185_PFE_MAC2_PFE_MAC2_TX_EN |
        SIUL2_1_PORT186_SIUL_OFFCC_EIRQ_18 |
        SIUL2_1_PORT187_FLEXCAN_2_CAN2_RX |
        SIUL2_1_PORT188_SIUL_OFFCC_EIRQ_20 |
        SIUL2_1_PORT189_SIUL_OFFCC_EIRQ_21 |
        SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_IN */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INPUT4_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_PFE_MAC2_PFE_MAC2_RXD_3_IN |
        SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_IN |
        SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_RX_ER |
        SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_RMII_REF_CLK |
        SIUL2_1_PORT116_FLEXTIMER_0_FTM0_EXT_CLK |
        SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN |
        SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN |
        SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN |
        SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT152_PFE_MAC2_PFE_MAC2_RX_ER */
        (uint16)( SHL_PAD_U32(8U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT167_PFE_MAC2_PFE_MAC2_COL |
        SIUL2_1_PORT168_PFE_MAC2_PFE_MAC2_CRS |
        SIUL2_1_PORT170_PFE_MAC2_PFE_MAC2_RX_ER */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT178_GMAC_0_GMAC0_MD_IN |
        SIUL2_1_PORT180_SIUL_OFFCC_EIRQ_5 |
        SIUL2_1_PORT181_SIUL_OFFCC_EIRQ_6 |
        SIUL2_1_PORT184_PFE_MAC2_PFE_MAC2_TX_CLK |
        SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN |
        SIUL2_1_PORT187_SIUL_OFFCC_EIRQ_19 |
        SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN |
        SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN |
        SIUL2_1_PORT190_PFE_MAC2_PFE_MAC2_RXD_2_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INPUT5_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN |
        SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_IN |
        SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN |
        SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_RMII_REF_CLK |
        SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT152_SIUL_OFFCC_EIRQ_1 */
        (uint16)( SHL_PAD_U32(8U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN */
        (uint16)( SHL_PAD_U32(7U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_IN |
        SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_IN |
        SIUL2_1_PORT186_PFE_MAC2_PFE_MAC2_TXD_0 |
        SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN |
        SIUL2_1_PORT188_PFE_MAC2_PFE_MAC2_RXD_0_IN |
        SIUL2_1_PORT189_PFE_MAC2_PFE_MAC2_RXD_1_IN |
        SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INPUT6_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_IN |
        SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191
        SIUL2_1_PORT187_PFE_MAC2_PFE_MAC2_TXD_1 |
        SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_IN */
        (uint16)( SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U)
                )
    }
    ,
    /*  Mode PORT_INPUT7_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_IN |
        SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_IN */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191 */
        (uint16)0x0000
    }
    ,
    /*  Mode PORT_INOUT1_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_USB_USB_ULPI_DATA_7_INOUT |
        SIUL2_1_PORT113_PFE_MAC0_PFE_MAC0_TXD_1_INOUT |
        SIUL2_1_PORT114_PFE_MAC0_PFE_MAC0_TXD_2_INOUT |
        SIUL2_1_PORT115_PFE_MAC0_PFE_MAC0_TXD_3_INOUT |
        SIUL2_1_PORT116_FLEXTIMER_0_FTM0_CH0_INOUT |
        SIUL2_1_PORT117_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT |
        SIUL2_1_PORT118_FLEXTIMER_0_FTM0_CH4_INOUT |
        SIUL2_1_PORT119_I2C_2_I2C2_SDA_INOUT |
        SIUL2_1_PORT120_I2C_2_I2C2_SCL_INOUT |
        SIUL2_1_PORT122_PFE_MAC0_PFE_MAC0_TX_CLK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC0_PFE_MAC0_TXD_0_INOUT */
        (uint16)( SHL_PAD_U32(0U)
                ),
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191
        SIUL2_1_PORT184_DSPI_2_DSPI2_SCK_INOUT |
        SIUL2_1_PORT187_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT |
        SIUL2_1_PORT188_USB_USB_ULPI_DATA_4_INOUT |
        SIUL2_1_PORT189_USB_USB_ULPI_DATA_5_INOUT |
        SIUL2_1_PORT190_USB_USB_ULPI_DATA_6_INOUT */
        (uint16)( SHL_PAD_U32(8U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(13U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INOUT2_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT |
        SIUL2_1_PORT113_PFE_MAC2_PFE_MAC2_TXD_1_INOUT |
        SIUL2_1_PORT114_PFE_MAC2_PFE_MAC2_TXD_2_INOUT |
        SIUL2_1_PORT115_PFE_MAC2_PFE_MAC2_TXD_3_INOUT |
        SIUL2_1_PORT116_LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT |
        SIUL2_1_PORT118_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT |
        SIUL2_1_PORT119_LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT |
        SIUL2_1_PORT120_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT |
        SIUL2_1_PORT122_PFE_MAC2_PFE_MAC2_TX_CLK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(6U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(8U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_PFE_MAC2_PFE_MAC2_TXD_0_INOUT |
        SIUL2_1_PORT145_LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_INOUT |
        SIUL2_1_PORT147_LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_INOUT |
        SIUL2_1_PORT151_FLEXTIMER_0_FTM0_CH0_INOUT |
        SIUL2_1_PORT153_DSPI_2_DSPI2_SCK_INOUT |
        SIUL2_1_PORT155_DSPI_2_DSPI2_PCS0_INOUT |
        SIUL2_1_PORT159_DSPI_3_DSPI3_SCK_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_DSPI_3_DSPI3_PCS0_INOUT |
        SIUL2_1_PORT165_DSPI_4_DSPI4_SCK_INOUT |
        SIUL2_1_PORT167_DSPI_4_DSPI4_PCS0_INOUT |
        SIUL2_1_PORT173_FLEXTIMER_0_FTM0_CH3_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(13U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_LLCE_LPSPI_3_LLCE_LPSPI3_SCK_INOUT |
        SIUL2_1_PORT178_LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_INOUT |
        SIUL2_1_PORT180_FLEXTIMER_0_FTM0_CH3_INOUT |
        SIUL2_1_PORT181_LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_INOUT |
        SIUL2_1_PORT186_DSPI_2_DSPI2_PCS0_INOUT |
        SIUL2_1_PORT189_DSPI_3_DSPI3_SCK_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(13U)
                )
    }
    ,
    /*  Mode PORT_INOUT3_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT112_FLEXTIMER_1_FTM1_CH3_INOUT |
        SIUL2_1_PORT113_I2C_1_I2C1_SDA_INOUT |
        SIUL2_1_PORT114_I2C_1_I2C1_SCL_INOUT |
        SIUL2_1_PORT116_PFE_MAC0_PFE_MAC0_RX_CLK_INOUT |
        SIUL2_1_PORT122_I2C_0_I2C0_SDA_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(4U) |
                  SHL_PAD_U32(10U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159
        SIUL2_1_PORT144_I2C_0_I2C0_SCL_INOUT |
        SIUL2_1_PORT153_I2C_0_I2C0_SDA_INOUT |
        SIUL2_1_PORT159_I2C_0_I2C0_SCL_INOUT */
        (uint16)( SHL_PAD_U32(0U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 160 - 175
        SIUL2_1_PORT161_I2C_0_I2C0_SDA_INOUT |
        SIUL2_1_PORT163_I2C_1_I2C1_SCL_INOUT |
        SIUL2_1_PORT165_I2C_1_I2C1_SDA_INOUT |
        SIUL2_1_PORT167_FLEXTIMER_0_FTM0_CH0_INOUT |
        SIUL2_1_PORT169_LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT |
        SIUL2_1_PORT171_FLEXTIMER_0_FTM0_CH2_INOUT |
        SIUL2_1_PORT175_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(7U) |
                  SHL_PAD_U32(9U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT177_FLEXTIMER_0_FTM0_CH1_INOUT |
        SIUL2_1_PORT178_FLEXTIMER_0_FTM0_CH2_INOUT |
        SIUL2_1_PORT181_FLEXTIMER_0_FTM0_CH4_INOUT |
        SIUL2_1_PORT186_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT |
        SIUL2_1_PORT190_LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(5U) |
                  SHL_PAD_U32(10U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INOUT4_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127
        SIUL2_1_PORT113_LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT |
        SIUL2_1_PORT114_LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT |
        SIUL2_1_PORT115_LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT |
        SIUL2_1_PORT116_PFE_MAC2_PFE_MAC2_RX_CLK_INOUT */
        (uint16)( SHL_PAD_U32(1U) |
                  SHL_PAD_U32(2U) |
                  SHL_PAD_U32(3U) |
                  SHL_PAD_U32(4U)
                ),
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175
        SIUL2_1_PORT167_LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT |
        SIUL2_1_PORT171_LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT |
        SIUL2_1_PORT175_DSPI_5_DSPI5_SCK_INOUT */
        (uint16)( SHL_PAD_U32(7U) |
                  SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT178_PFE_MAC1_PFE_MAC1_MD_INOUT |
        SIUL2_1_PORT188_FLEXTIMER_1_FTM1_CH0_INOUT |
        SIUL2_1_PORT190_FLEXTIMER_1_FTM1_CH4_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(12U) |
                  SHL_PAD_U32(14U)
                )
    }
    ,
    /*  Mode PORT_INOUT5_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175
        SIUL2_1_PORT171_DSPI_5_DSPI5_PCS0_INOUT |
        SIUL2_1_PORT175_I2C_1_I2C1_SCL_INOUT */
        (uint16)( SHL_PAD_U32(11U) |
                  SHL_PAD_U32(15U)
                ),
        /* Pads 176 - 191
        SIUL2_1_PORT178_GMAC_0_GMAC0_MD_INOUT |
        SIUL2_1_PORT189_LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT */
        (uint16)( SHL_PAD_U32(2U) |
                  SHL_PAD_U32(13U)
                )
    }
    ,
    /*  Mode PORT_INOUT6_MODE: */
    {
        /* Pads 0 - 15 */
        (uint16)0x0000,
        /* Pads 16 - 31 */
        (uint16)0x0000,
        /* Pads 32 - 47 */
        (uint16)0x0000,
        /* Pads 48 - 63 */
        (uint16)0x0000,
        /* Pads 64 - 79 */
        (uint16)0x0000,
        /* Pads 80 - 95 */
        (uint16)0x0000,
        /* Pads 96 - 111 */
        (uint16)0x0000,
        /* Pads 112 - 127 */
        (uint16)0x0000,
        /* Pads 128 - 143 */
        (uint16)0x0000,
        /* Pads 144 - 159 */
        (uint16)0x0000,
        /* Pads 160 - 175 */
        (uint16)0x0000,
        /* Pads 176 - 191
        SIUL2_1_PORT188_LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT */
        (uint16)( SHL_PAD_U32(12U)
                )
    }

};

/**
* @brief Array of elements storing information about IN functionalities on the first SIUL2 instance
*/
static const Port_InMuxSettingType Port_SIUL2_0_aInMuxSettings[244] =
{
    /* INMUX settings for pad not available: */
    { NO_INPUTMUX_U16, 0U, 0U},
    /* INMUX settings for pad PORT0:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* JTAGC_TDI input func */
    {61U, 0U, 0U},
    /* INMUX settings for pad PORT4:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* BOOT_BOOTMOD_0 input func */
    {48U, 0U, 0U},
    /* INMUX settings for pad PORT6:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* BOOT_BOOTMOD_1 input func */
    {49U, 0U, 0U},
    /* INMUX settings for pad PORT8:    {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* JTAGC_TCK input func */
    {60U, 0U, 0U},
    /* INMUX settings for pad PORT10:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* JTAGC_TMS_IN input func */
    {50U, 0U, 0U},
    /* INMUX settings for pad PORT12:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_1_FTM1_CH2_IN input func */
    {155U, 2U, 1U},
    /* INMUX settings for pad PORT14:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI1_PCS0_IN input func */
    {473U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH3_IN input func */
    {156U, 2U, 1U},
    /* INMUX settings for pad PORT16:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI1_SCK_IN input func */
    {474U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH0_IN input func */
    {153U, 2U, 1U},
    /* INMUX settings for pad PORT18:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_SCK_IN input func */
    {288U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_CH1_IN input func */
    {144U, 2U, 1U},
    /* DSPI_5_DSPI5_SCK_IN input func */
    {494U, 2U, 1U},
    /* GMAC_0_GMAC0_PST_TS_TRIG_1 input func */
    {52U, 2U, 0U},
    /* GMAC_0_GMAC0_AUX_TRIG_3 input func */
    {25U, 2U, 0U},
    /* INMUX settings for pad PORT20:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_SIN input func */
    {289U, 2U, 1U},
    /* DSPI_5_DSPI5_SIN input func */
    {495U, 2U, 1U},
    /* GMAC_0_GMAC0_PST_TS_TRIG_0 input func */
    {51U, 2U, 0U},
    /* GMAC_0_GMAC0_AUX_TRIG_2 input func */
    {24U, 2U, 0U},
    /* INMUX settings for pad PORT22:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH3_IN input func */
    {146U, 2U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_IN input func */
    {290U, 2U, 1U},
    /* INMUX settings for pad PORT24:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN input func */
    {283U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_CH4_IN input func */
    {147U, 2U, 1U},
    /* DSPI_5_DSPI5_PCS0_IN input func */
    {493U, 2U, 1U},
    /* INMUX settings for pad PORT26:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_0_DSPI0_SCK_IN input func */
    {469U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_EXT_CLK input func */
    {149U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_RX_ER input func */
    {348U, 2U, 1U},
    /* INMUX settings for pad PORT28:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_0_DSPI0_SIN input func */
    {470U, 2U, 1U},
    /* LINFLEX_0_LIN0_RX input func */
    {0U, 3U, 0U},
    /* FLEXTIMER_1_FTM1_CH0_IN input func */
    {153U, 3U, 1U},
    /* INMUX settings for pad PORT30:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH4_IN input func */
    {147U, 3U, 1U},
    /* PFE_MAC1_PFE_MAC1_COL input func */
    {343U, 2U, 1U},
    /* INMUX settings for pad PORT32:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 2U, 0U},
    /* DSPI_0_DSPI0_PCS0_IN input func */
    {468U, 2U, 1U},
    /* LINFLEX_1_LIN1_RX input func */
    {224U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_CH5_IN input func */
    {148U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_CRS input func */
    {344U, 2U, 1U},
    /* INMUX settings for pad PORT34:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_0_I2C0_SCL_IN input func */
    {54U, 2U, 0U},
    /* I2C_4_I2C4_SCL_IN input func */
    {211U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_CH0_IN input func */
    {143U, 2U, 1U},
    /* INMUX settings for pad PORT36:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_4_I2C4_SDA_IN input func */
    {212U, 2U, 1U},
    /* FLEXCAN_0_CAN0_RX input func */
    {1U, 3U, 0U},
    /* FLEXTIMER_0_FTM0_CH2_IN input func */
    {145U, 2U, 1U},
    /* INMUX settings for pad PORT38:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SCL_IN input func */
    {205U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH0_IN input func */
    {153U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_0 input func */
    {398U, 2U, 1U},
    /* INMUX settings for pad PORT40:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SDA_IN input func */
    {206U, 2U, 1U},
    /* FLEXCAN_1_CAN1_RX input func */
    {119U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH2_IN input func */
    {155U, 3U, 1U},
    /* SIUL_OFFCC_EIRQ_1 input func */
    {399U, 2U, 1U},
    /* INMUX settings for pad PORT42:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_2_I2C2_SCL_IN input func */
    {207U, 2U, 1U},
    /* CTU_CTU_EXT_TRIG input func */
    {318U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_2 input func */
    {400U, 2U, 1U},
    /* INMUX settings for pad PORT44:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_2_I2C2_SDA_IN input func */
    {208U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_3 input func */
    {401U, 2U, 1U},
    /* INMUX settings for pad PORT46:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_3_I2C3_SCL_IN input func */
    {209U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_4 input func */
    {402U, 2U, 1U},
    /* INMUX settings for pad PORT48:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 7U, 0U},
    /* SIUL_OFFCC_EIRQ_5 input func */
    {403U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_MD_IN input func */
    {345U, 4U, 1U},
    /* GMAC_0_GMAC0_MD_IN input func */
    {15U, 4U, 0U},
    /* INMUX settings for pad PORT50:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH3_IN input func */
    {146U, 3U, 1U},
    /* SIUL_OFFCC_EIRQ_6 input func */
    {404U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 input func */
    {355U, 2U, 1U},
    /* INMUX settings for pad PORT52:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LINFLEX_1_LIN1_RX input func */
    {224U, 3U, 1U},
    /* FLEXCAN_3_CAN3_RX input func */
    {121U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_CH2_IN input func */
    {145U, 3U, 1U},
    /* DSPI_4_DSPI4_PCS0_IN input func */
    {488U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_7 input func */
    {405U, 2U, 1U},
    /* PFE_PFE_UART_RX input func */
    {322U, 2U, 1U},
    /* INMUX settings for pad PORT54:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SCK_IN input func */
    {304U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_EXT_CLK input func */
    {159U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_8 input func */
    {406U, 2U, 1U},
    /* MISC_TAMPER_EXTIN0 input func */
    {316U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 input func */
    {355U, 3U, 1U},
    /* INMUX settings for pad PORT56:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXCAN_2_CAN2_RX input func */
    {120U, 2U, 1U},
    /* LINFLEX_2_LIN2_RX input func */
    {225U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH1_IN input func */
    {154U, 2U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SIN_IN input func */
    {305U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_9 input func */
    {407U, 2U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN input func */
    {308U, 2U, 1U},
    /* INMUX settings for pad PORT58:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_3_I2C3_SDA_IN input func */
    {210U, 4U, 1U},
    /* FLEXRAY_0_FR_RXD_A input func */
    {128U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH2_IN input func */
    {155U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_10 input func */
    {408U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 input func */
    {335U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_CRS input func */
    {364U, 2U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_IN input func */
    {306U, 2U, 1U},
    /* INMUX settings for pad PORT60:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXCAN_3_CAN3_RX input func */
    {121U, 3U, 1U},
    /* I2C_3_I2C3_SCL_IN input func */
    {209U, 3U, 1U},
    /* FLEXTIMER_1_FTM1_CH3 input func */
    {156U, 3U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_IN input func */
    {299U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_COL input func */
    {363U, 2U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN input func */
    {284U, 2U, 1U},
    /* INMUX settings for pad PORT62:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 3U, 0U},
    /* SIUL_OFFCC_EIRQ_12 input func */
    {410U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_PST_TS_TRIG_0 input func */
    {375U, 2U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN input func */
    {300U, 2U, 1U},
    /* INMUX settings for pad PORT64:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXRAY_0_FR_RXD_B input func */
    {129U, 2U, 1U},
    /* I2C_0_I2C0_SCL_IN input func */
    {54U, 3U, 0U},
    /* FLEXTIMER_1_FTM1_CH4_IN input func */
    {157U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 input func */
    {335U, 3U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_IN input func */
    {308U, 3U, 1U},
    /* INMUX settings for pad PORT66:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_13 input func */
    {411U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 input func */
    {335U, 4U, 1U},
    /* PFE_MAC0_PFE_MAC0_CRS input func */
    {324U, 2U, 1U},
    /* I2C_4_I2C4_SDA_IN input func */
    {212U, 3U, 1U},
    /* INMUX settings for pad PORT68:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_14 input func */
    {412U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 input func */
    {355U, 4U, 1U},
    /* PFE_MAC0_PFE_MAC0_COL input func */
    {323U, 2U, 1U},
    /* I2C_4_I2C4_SCL_IN input func */
    {211U, 3U, 1U},
    /* INMUX settings for pad PORT70:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_15 input func */
    {413U, 2U, 1U},
    /* INMUX settings for pad PORT72:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LIN_1_LLCE_LIN1_RX input func */
    {279U, 2U, 1U},
    /* LINFLEX_1_LIN1_RX input func */
    {224U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_27 input func */
    {425U, 2U, 1U},
    /* ADCSAR_0_ADCSAR0_TRIG input func */
    {430U, 2U, 1U},
    /* INMUX settings for pad PORT74:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_28 input func */
    {426U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_PST_TS_TRIG_0 input func */
    {335U, 5U, 1U},
    /* ADCSAR_1_ADCSAR1_TRIG input func */
    {432U, 2U, 1U},
    /* INMUX settings for pad PORT76:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LIN_2_LLCE_LIN2_RX input func */
    {280U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_29 input func */
    {427U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_PST_TS_TRIG_0 input func */
    {355U, 5U, 1U},
    /* ADCSAR_1_ADCSAR1_INJ_TRIG input func */
    {433U, 2U, 1U},
    /* INMUX settings for pad PORT78:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_30 input func */
    {428U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_COL input func */
    {323U, 3U, 1U},
    /* INMUX settings for pad PORT80:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_31 input func */
    {429U, 2U, 1U},
    /* ADCSAR_0_ADCSAR0_INJ_TRIG input func */
    {431U, 2U, 1U},
    /* INMUX settings for pad PORT82:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH4_IN input func */
    {147U, 4U, 1U},
    /* DSPI_4_DSPI4_SCK_IN input func */
    {489U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_RX_ER input func */
    {328U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_ER input func */
    {368U, 2U, 1U},
    /* INMUX settings for pad PORT84:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LINFLEX_0_LIN0_RX input func */
    {0U, 2U, 0U},
    /* FLEXCAN_2_CAN2_RX input func */
    {120U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH5_IN input func */
    {148U, 3U, 1U},
    /* DSPI_4_DSPI4_SIN input func */
    {490U, 2U, 1U},
    /* PFE_PFE_UART_RX input func */
    {322U, 3U, 1U},
    /* INMUX settings for pad PORT86:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXCAN_0_CAN0_RX input func */
    {1U, 2U, 0U},
    /* LLCE_CAN_0_LLCE_CAN0_RX input func */
    {233U, 2U, 1U},
    /* INMUX settings for pad PORT92:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_B_0_IN input func */
    {40U, 2U, 0U},
    /* INMUX settings for pad PORT94:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_CMD_IN input func */
    {3U, 2U, 0U},
    /* QUADSPI_QSPI_DATA_B_3_IN input func */
    {41U, 2U, 0U},
    /* INMUX settings for pad PORT96:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_D_0_IN input func */
    {4U, 2U, 0U},
    /* I2C_2_I2C2_SCL_IN input func */
    {207U, 3U, 1U},
    /* INMUX settings for pad PORT98:   {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_D_1_IN input func */
    {5U, 2U, 0U},
    /* QUADSPI_QSPI_INTB_b input func */
    {47U, 2U, 0U},
    /* I2C_1_I2C1_SCL_IN input func */
    {205U, 3U, 1U},
    /* INMUX settings for pad PORT100:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SDA_IN input func */
    {206U, 5U, 1U},
    /* USDHC_0_SD0_D_2_IN input func */
    {8U, 2U, 0U},
    /* QUADSPI_QSPI_DATA_B_4_IN input func */
    {45U, 2U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_D_3_IN input func */
    {9U, 2U, 0U},
    /* QUADSPI_QSPI_DATA_B_1_IN input func */
    {42U, 2U, 0U},
    /* I2C_3_I2C3_SCL_IN input func */
    {209U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_2_I2C2_SDA_IN input func */
    {208U, 4U, 1U},
    /* USDHC_0_SD0_D_4_IN input func */
    {10U, 2U, 0U},
    /* QUADSPI_QSPI_DQS_B_IN input func */
    {46U, 2U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_3_I2C3_SDA_IN input func */
    {210U, 2U, 1U},
    /* USDHC_0_SD0_D_5_IN input func */
    {11U, 2U, 0U},
    /* QUADSPI_QSPI_DATA_B_7_IN input func */
    {43U, 2U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_D_6_IN input func */
    {7U, 2U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_D_7_IN input func */
    {6U, 2U, 0U},
    /* I2C_0_I2C0_SCL_IN input func */
    {54U, 4U, 0U},
    /* INMUX settings for pad PORT112:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_B_5_IN input func */
    {38U, 2U, 0U},
    /* INMUX settings for pad PORT114:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_B_2_IN input func */
    {39U, 2U, 0U},
    /* INMUX settings for pad PORT116:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USDHC_0_SD0_DQS input func */
    {12U, 2U, 0U},
    /* QUADSPI_QSPI_DATA_B_6_IN input func */
    {44U, 2U, 0U},
    /* INMUX settings for pad PORT118:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* MISC_TAMPER_EXTIN0 input func */
    {316U, 3U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_IN input func */
    {300U, 3U, 1U},
    /* INMUX settings for pad PORT120:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_IN input func */
    {309U, 2U, 1U},
    /* INMUX settings for pad PORT122:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_MD_IN input func */
    {15U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_MD_IN input func */
    {345U, 2U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_IN input func */
    {310U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DATA_0_IN input func */
    {384U, 2U, 1U},
    /* DSPI_3_DSPI3_PCS0_IN input func */
    {483U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN input func */
    {291U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_ER input func */
    {368U, 3U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_2 input func */
    {379U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RX_ER input func */
    {16U, 2U, 0U},
    /* USB_USB_ULPI_DATA_1_IN input func */
    {385U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RMII_REF_CLK input func */
    {366U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_EXT_CLK input func */
    {159U, 3U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN input func */
    {298U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_3 input func */
    {380U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_COL input func */
    {13U, 2U, 0U},
    /* USB_USB_ULPI_DATA_2_IN input func */
    {386U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH1_IN input func */
    {154U, 3U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_CLK_IN input func */
    {367U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_CRS input func */
    {14U, 2U, 0U},
    /* USB_USB_ULPI_DATA_3_IN input func */
    {387U, 2U, 1U},
    /* LINFLEX_2_LIN2_RX input func */
    {225U, 3U, 1U},
    /* FLEXCAN_0_CAN0_RX input func */
    {1U, 4U, 0U},
    /* PFE_MAC2_PFE_MAC2_RXDV_IN input func */
    {373U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH2_IN input func */
    {155U, 5U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_TX_CLK_IN input func */
    {26U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_TX_CLK_IN input func */
    {354U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_TX_EN_IN input func */
    {55U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_TX_EN_IN input func */
    {356U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_TXD_0_IN input func */
    {56U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_TXD_0_IN input func */
    {357U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_TXD_1_IN input func */
    {59U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_TXD_1_IN input func */
    {358U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC1_PFE_MAC1_TXD_2_IN input func */
    {359U, 2U, 1U},
    /* GMAC_0_GMAC0_RX_ER input func */
    {16U, 3U, 0U},
    /* PFE_MAC1_PFE_MAC1_RX_ER input func */
    {348U, 3U, 1U},
    /* GMAC_0_GMAC0_TXD_2_IN input func */
    {57U, 2U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RMII_REF_CLK_IN input func */
    {23U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RMII_REF_CLK input func */
    {346U, 2U, 1U},
    /* PFE_MAC1_PFE_MAC1_TXD_3_IN input func */
    {360U, 2U, 1U},
    /* GMAC_0_GMAC0_TXD_3_IN input func */
    {58U, 2U, 0U},
    /* INMUX settings for pad PORT144:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RX_CLK_IN input func */
    {17U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RX_CLK_IN input func */
    {347U, 2U, 1U},
    /* INMUX settings for pad PORT146:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC1_PFE_MAC1_RXDV_IN input func */
    {353U, 2U, 1U},
    /* GMAC_0_GMAC0_RXDV_IN input func */
    {18U, 2U, 0U},
    /* INMUX settings for pad PORT148:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RXD_0_IN input func */
    {19U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RXD_0_IN input func */
    {349U, 2U, 1U},
    /* INMUX settings for pad PORT150:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RXD_1_IN input func */
    {20U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RXD_1_IN input func */
    {350U, 2U, 1U},
    /* INMUX settings for pad PORT152:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RXD_2_IN input func */
    {21U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RXD_2_IN input func */
    {351U, 2U, 1U},
    /* INMUX settings for pad PORT154:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_RXD_3_IN input func */
    {22U, 2U, 0U},
    /* PFE_MAC1_PFE_MAC1_RXD_3_IN input func */
    {352U, 2U, 1U},
    /* INMUX settings for pad PORT156:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH1_IN input func */
    {144U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_TX_EN_IN input func */
    {336U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TX_EN_IN input func */
    {376U, 2U, 1U},
    /* INMUX settings for pad PORT158:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_MD_IN input func */
    {325U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_MD_IN input func */
    {365U, 3U, 1U},
    /* I2C_3_I2C3_SCL_IN input func */
    {209U, 5U, 1U},
    /* INMUX settings for pad PORT160:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_1_FTM1_CH5_IN input func */
    {158U, 2U, 1U},
    /* INMUX settings for pad PORT162:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC2_PFE_MAC2_MD_IN input func */
    {365U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_MD_IN input func */
    {325U, 3U, 1U},
    /* GMAC_0_GMAC0_TS_CLK_IN input func */
    {27U, 2U, 0U},
    /* INMUX settings for pad PORT164:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_3_I2C3_SDA_IN input func */
    {210U, 3U, 1U},
    /* INMUX settings for pad PORT170:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_0_IN input func */
    {28U, 2U, 0U},
    /* INMUX settings for pad PORT172:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_1_IN input func */
    {29U, 2U, 0U},
    /* INMUX settings for pad PORT174:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_2_IN input func */
    {30U, 2U, 0U},
    /* INMUX settings for pad PORT176:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_3_IN input func */
    {31U, 2U, 0U},
    /* INMUX settings for pad PORT178:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_4_IN input func */
    {32U, 2U, 0U},
    /* INMUX settings for pad PORT180:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_5_IN input func */
    {33U, 2U, 0U},
    /* INMUX settings for pad PORT182:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_6_IN input func */
    {34U, 2U, 0U},
    /* INMUX settings for pad PORT184:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DATA_A_7_IN input func */
    {35U, 2U, 0U},
    /* INMUX settings for pad PORT186:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_DQS_A_IN input func */
    {36U, 2U, 0U},
    /* INMUX settings for pad PORT188:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* QUADSPI_QSPI_INTA_b input func */
    {37U, 2U, 0U},
    /* INMUX settings for pad PORT190:  {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_1_DSPI1_SIN input func */
    {475U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH1_IN input func */
    {154U, 4U, 1U}

};

/**
* @brief Array of elements storing information about IN functionalities on the second SIUL2 instance
*/
static const Port_InMuxSettingType Port_SIUL2_1_aInMuxSettings[183] =
{
    /* INMUX settings for pad not available: */
    { NO_INPUTMUX_U16, 0U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DATA_7_IN input func */
    {391U, 2U, 1U},
    /* FLEXCAN_1_CAN1_RX input func */
    {119U, 3U, 1U},
    /* FLEXTIMER_1_FTM1_CH3_IN input func */
    {156U, 4U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_3_IN input func */
    {372U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN input func */
    {294U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SDA_IN input func */
    {206U, 3U, 1U},
    /* SIUL_OFFCC_EIRQ_23 input func */
    {421U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN input func */
    {293U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_TXD_1_IN input func */
    {338U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_1_IN input func */
    {378U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SCL_IN input func */
    {205U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_24 input func */
    {422U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_RX_ER input func */
    {328U, 3U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_ER input func */
    {368U, 4U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN input func */
    {292U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_TXD_2_IN input func */
    {339U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_2_IN input func */
    {379U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH5 input func */
    {148U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_25 input func */
    {423U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_IN input func */
    {291U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_RMII_REF_CLK input func */
    {326U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RMII_REF_CLK input func */
    {366U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_TXD_3_IN input func */
    {340U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_3_IN input func */
    {380U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RX_CLK_IN input func */
    {327U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_CLK_IN input func */
    {367U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH0_IN input func */
    {143U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_EXT_CLK input func */
    {149U, 3U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_IN input func */
    {298U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RXDV_IN input func */
    {333U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXDV_IN input func */
    {373U, 3U, 1U},
    /* SIUL_OFFCC_EIRQ_26 input func */
    {424U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN input func */
    {297U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RXD_0_IN input func */
    {329U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_0_IN input func */
    {369U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH4_IN input func */
    {147U, 5U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN input func */
    {296U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RXD_1_IN input func */
    {330U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_1_IN input func */
    {370U, 3U, 1U},
    /* I2C_2_I2C2_SDA_IN input func */
    {208U, 3U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_IN input func */
    {294U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RXD_2_IN input func */
    {331U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_2_IN input func */
    {371U, 3U, 1U},
    /* I2C_2_I2C2_SCL_IN input func */
    {207U, 4U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN input func */
    {285U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_RXD_3_IN input func */
    {332U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_3_IN input func */
    {372U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* PFE_MAC0_PFE_MAC0_TX_CLK_IN input func */
    {334U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TX_CLK_IN input func */
    {374U, 3U, 1U},
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 4U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_0_I2C0_SCL_IN input func */
    {54U, 5U, 0U},
    /* PFE_MAC0_PFE_MAC0_TXD_0_IN input func */
    {337U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_0_IN input func */
    {377U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_PHA input func */
    {150U, 2U, 1U},
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_IN input func */
    {302U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_1_LLCE_CAN1_RX input func */
    {234U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_IN input func */
    {301U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_2_LLCE_CAN2_RX input func */
    {235U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_PHB input func */
    {151U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_3_LLCE_CAN3_RX input func */
    {236U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH0_IN input func */
    {143U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_0 input func */
    {398U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_4_LLCE_CAN4_RX input func */
    {237U, 2U, 1U},
    /* FLEXTIMER_0_FTM0_EXT_CLK input func */
    {149U, 4U, 1U},
    /* PFE_MAC0_PFE_MAC0_RX_ER input func */
    {328U, 4U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_ER input func */
    {368U, 5U, 1U},
    /* SIUL_OFFCC_EIRQ_1 input func */
    {399U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI2_SCK_IN input func */
    {479U, 3U, 1U},
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 5U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_5_LLCE_CAN5_RX input func */
    {238U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_8 input func */
    {406U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI2_PCS0_IN input func */
    {478U, 3U, 1U},
    /* RTC_RTC_EXT_CLK input func */
    {467U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_6_LLCE_CAN6_RX input func */
    {239U, 2U, 1U},
    /* DSPI_2_DSPI2_SCK input func */
    {479U, 4U, 1U},
    /* FLEXTIMER_1_FTM1_PHA input func */
    {160U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_7_LLCE_CAN7_RX input func */
    {240U, 2U, 1U},
    /* DSPI_2_DSPI2_SIN input func */
    {480U, 3U, 1U},
    /* FLEXTIMER_1_FTM1_PHB input func */
    {161U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_3_DSPI3_SCK_IN input func */
    {484U, 3U, 1U},
    /* I2C_0_I2C0_SCL_IN input func */
    {54U, 6U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_8_LLCE_CAN8_RX input func */
    {241U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_9 input func */
    {407U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_3_DSPI3_PCS0_IN input func */
    {483U, 3U, 1U},
    /* I2C_0_I2C0_SDA_IN input func */
    {53U, 6U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_9_LLCE_CAN9_RX input func */
    {242U, 2U, 1U},
    /* DSPI_3_DSPI3_SCK input func */
    {484U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* I2C_1_I2C1_SCL_IN input func */
    {205U, 5U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_10_LLCE_CAN10_RX input func */
    {243U, 2U, 1U},
    /* DSPI_3_DSPI3_SIN input func */
    {485U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_4_DSPI4_SCK_IN input func */
    {489U, 3U, 1U},
    /* I2C_1_I2C1_SDA_IN input func */
    {206U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_10 input func */
    {408U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_11_LLCE_CAN11_RX input func */
    {244U, 2U, 1U},
    /* DSPI_4_DSPI4_SCK input func */
    {489U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_4_DSPI4_PCS0_IN input func */
    {488U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH0_IN input func */
    {143U, 5U, 1U},
    /* PFE_MAC0_PFE_MAC0_COL input func */
    {323U, 4U, 1U},
    /* PFE_MAC2_PFE_MAC2_COL input func */
    {363U, 3U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_IN input func */
    {284U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_12_LLCE_CAN12_RX input func */
    {245U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_11 input func */
    {409U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_CRS input func */
    {324U, 3U, 1U},
    /* PFE_MAC2_PFE_MAC2_CRS input func */
    {364U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_IN input func */
    {285U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_13_LLCE_CAN13_RX input func */
    {246U, 2U, 1U},
    /* DSPI_4_DSPI4_SIN input func */
    {490U, 3U, 1U},
    /* PFE_MAC0_PFE_MAC0_RX_ER input func */
    {328U, 5U, 1U},
    /* PFE_MAC2_PFE_MAC2_RX_ER input func */
    {368U, 6U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH2_IN input func */
    {145U, 4U, 1U},
    /* DSPI_5_DSPI5_PCS0_IN input func */
    {493U, 3U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN input func */
    {286U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_14_LLCE_CAN14_RX input func */
    {247U, 2U, 1U},
    /* LINFLEX_2_LIN2_RX input func */
    {225U, 4U, 1U},
    /* DSPI_5_DSPI5_SCK input func */
    {494U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* FLEXTIMER_0_FTM0_CH3_IN input func */
    {146U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_CAN_15_LLCE_CAN15_RX input func */
    {248U, 2U, 1U},
    /* DSPI_5_DSPI5_SIN input func */
    {495U, 3U, 1U},
    /* MISC_TAMPER_EXTIN0 input func */
    {316U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_5_DSPI5_SCK_IN input func */
    {494U, 4U, 1U},
    /* I2C_1_I2C1_SCL_IN input func */
    {205U, 6U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_IN input func */
    {286U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LIN_0_LLCE_LIN0_RX input func */
    {278U, 2U, 1U},
    /* LINFLEX_0_LIN0_RX input func */
    {0U, 4U, 0U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_2 input func */
    {400U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH1_IN input func */
    {144U, 4U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_SCK_IN input func */
    {312U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* SIUL_OFFCC_EIRQ_3 input func */
    {401U, 3U, 1U},
    /* FLEXTIMER_0_FTM0_CH2_IN input func */
    {145U, 5U, 1U},
    /* PFE_MAC1_PFE_MAC1_MD_IN input func */
    {345U, 3U, 1U},
    /* GMAC_0_GMAC0_MD_IN input func */
    {15U, 3U, 0U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_IN input func */
    {314U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_FLEXRAY_LLCE_FR_RXD_A input func */
    {273U, 2U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_SIN input func */
    {313U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_4 input func */
    {402U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_PST_TS_TRIG_0 input func */
    {51U, 3U, 0U},
    /* GMAC_0_GMAC0_AUX_TRIG_2 input func */
    {24U, 3U, 0U},
    /* FLEXTIMER_0_FTM0_CH3_IN input func */
    {146U, 5U, 1U},
    /* SIUL_OFFCC_EIRQ_5 input func */
    {403U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* GMAC_0_GMAC0_PST_TS_TRIG_1 input func */
    {52U, 3U, 0U},
    /* GMAC_0_GMAC0_AUX_TRIG_3 input func */
    {25U, 3U, 0U},
    /* FLEXTIMER_0_FTM0_CH4_IN input func */
    {147U, 6U, 1U},
    /* SIUL_OFFCC_EIRQ_6 input func */
    {404U, 3U, 1U},
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_IN input func */
    {307U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_FLEXRAY_LLCE_FR_RXD_B input func */
    {274U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_7 input func */
    {405U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* LLCE_LIN_3_LLCE_LIN3_RX input func */
    {281U, 2U, 1U},
    /* PFE_MAC0_PFE_MAC0_CRS input func */
    {324U, 4U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_CLK input func */
    {383U, 2U, 1U},
    /* DSPI_2_DSPI2_SCK_IN input func */
    {479U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_16 input func */
    {414U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TX_CLK input func */
    {374U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DIR input func */
    {392U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_17 input func */
    {415U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TX_EN input func */
    {376U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* DSPI_2_DSPI2_PCS0_IN input func */
    {478U, 2U, 1U},
    /* FLEXCAN_3_CAN3_RX input func */
    {121U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_18 input func */
    {416U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_IN input func */
    {293U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_0 input func */
    {377U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_NXT input func */
    {393U, 2U, 1U},
    /* DSPI_2_DSPI2_SIN input func */
    {480U, 2U, 1U},
    /* FLEXCAN_2_CAN2_RX input func */
    {120U, 4U, 1U},
    /* SIUL_OFFCC_EIRQ_19 input func */
    {417U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_IN input func */
    {292U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_TXD_1 input func */
    {378U, 3U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DATA_4_IN input func */
    {388U, 2U, 1U},
    /* DSPI_3_DSPI3_SIN input func */
    {485U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_20 input func */
    {418U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SIN_IN input func */
    {297U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_0_IN input func */
    {369U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH0_IN input func */
    {153U, 5U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DATA_5_IN input func */
    {389U, 2U, 1U},
    /* DSPI_3_DSPI3_SCK_IN input func */
    {484U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_21 input func */
    {419U, 2U, 1U},
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SCK_IN input func */
    {296U, 2U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_1_IN input func */
    {370U, 2U, 1U},
    /* INMUX settings for pad :         {IMCR reg, IMCR.SSS Val, IMCR SIUL2 Instance} */
    /* USB_USB_ULPI_DATA_6_IN input func */
    {390U, 2U, 1U},
    /* SIUL_OFFCC_EIRQ_22 input func */
    {420U, 2U, 1U},
    /* FLEXTIMER_1_FTM1_CH4_IN input func */
    {157U, 3U, 1U},
    /* PFE_MAC2_PFE_MAC2_RXD_2_IN input func */
    {371U, 2U, 1U},
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_IN input func */
    {283U, 3U, 1U}

};

/**
* @brief Array of elements storing information about INOUT functionalities on the first SIUL2 instance
*/
static const Port_InoutSettingType Port_SIUL2_0_aInoutMuxSettings[PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16] =
{
    /* Inout settings for pad PORT5 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* JTAGC_TMS_INOUT inout functionality */
    {5U, 15U, 50U, 0U, 0U}, 
    /* Inout settings for pad PORT6 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_1_FTM1_CH2_INOUT inout functionality */
    {6U, 17U, 155U, 2U, 1U}, 
    /* Inout settings for pad PORT7 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_1_DSPI1_PCS0_INOUT inout functionality */
    {7U, 16U, 473U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH3_INOUT inout functionality */
    {7U, 17U, 156U, 2U, 1U}, 
    /* Inout settings for pad PORT8 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_1_DSPI1_SCK_INOUT inout functionality */
    {8U, 17U, 474U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH0_INOUT inout functionality */
    {8U, 18U, 153U, 2U, 1U}, 
    /* Inout settings for pad PORT9 :   {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_SCK_INOUT inout functionality */
    {9U, 15U, 288U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH1_INOUT inout functionality */
    {9U, 16U, 144U, 2U, 1U}, 
    /* DSPI_5_DSPI5_SCK_INOUT inout functionality */
    {9U, 17U, 494U, 2U, 1U}, 
    /* Inout settings for pad PORT11 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH3_INOUT inout functionality */
    {11U, 16U, 146U, 2U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_SOUT_INOUT inout functionality */
    {11U, 18U, 290U, 2U, 1U}, 
    /* Inout settings for pad PORT12 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH4_INOUT inout functionality */
    {12U, 16U, 147U, 2U, 1U}, 
    /* DSPI_5_DSPI5_PCS0_INOUT inout functionality */
    {12U, 17U, 493U, 2U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT inout functionality */
    {12U, 18U, 283U, 2U, 1U}, 
    /* Inout settings for pad PORT13 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_0_DSPI0_SCK_INOUT inout functionality */
    {13U, 15U, 469U, 2U, 1U}, 
    /* Inout settings for pad PORT14 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_1_FTM1_CH0_INOUT inout functionality */
    {14U, 15U, 153U, 3U, 1U}, 
    /* Inout settings for pad PORT15 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH4_INOUT inout functionality */
    {15U, 17U, 147U, 3U, 1U}, 
    /* Inout settings for pad PORT16 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {16U, 15U, 53U, 2U, 0U}, 
    /* DSPI_0_DSPI0_PCS0_INOUT inout functionality */
    {16U, 16U, 468U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH5_INOUT inout functionality */
    {16U, 17U, 148U, 2U, 1U}, 
    /* Inout settings for pad PORT17 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C0_SCL_INOUT inout functionality */
    {17U, 15U, 54U, 2U, 0U}, 
    /* FLEXTIMER_0_FTM0_CH0_INOUT inout functionality */
    {17U, 17U, 143U, 2U, 1U}, 
    /* I2C_4_I2C4_SCL_INOUT inout functionality */
    {17U, 18U, 211U, 2U, 1U}, 
    /* Inout settings for pad PORT18 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH2_INOUT inout functionality */
    {18U, 16U, 145U, 2U, 1U}, 
    /* I2C_4_I2C4_SDA_INOUT inout functionality */
    {18U, 17U, 212U, 2U, 1U}, 
    /* Inout settings for pad PORT19 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C1_SCL_INOUT inout functionality */
    {19U, 15U, 205U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH0_INOUT inout functionality */
    {19U, 17U, 153U, 4U, 1U}, 
    /* Inout settings for pad PORT20 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C1_SDA_INOUT inout functionality */
    {20U, 15U, 206U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH2_INOUT inout functionality */
    {20U, 16U, 155U, 3U, 1U}, 
    /* Inout settings for pad PORT21 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_2_I2C2_SCL_INOUT inout functionality */
    {21U, 15U, 207U, 2U, 1U}, 
    /* Inout settings for pad PORT22 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_2_I2C2_SDA_INOUT inout functionality */
    {22U, 15U, 208U, 2U, 1U}, 
    /* Inout settings for pad PORT23 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_3_I2C3_SCL_INOUT inout functionality */
    {23U, 15U, 209U, 2U, 1U}, 
    /* Inout settings for pad PORT24 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {24U, 15U, 53U, 7U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_MD_INOUT inout functionality */
    {24U, 16U, 345U, 4U, 1U}, 
    /* GMAC_0_GMAC0_MD_INOUT inout functionality */
    {24U, 17U, 15U, 4U, 0U}, 
    /* Inout settings for pad PORT25 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH3_INOUT inout functionality */
    {25U, 17U, 146U, 3U, 1U}, 
    /* Inout settings for pad PORT26 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH2_INOUT inout functionality */
    {26U, 15U, 145U, 3U, 1U}, 
    /* DSPI_4_DSPI4_PCS0_INOUT inout functionality */
    {26U, 16U, 488U, 2U, 1U}, 
    /* Inout settings for pad PORT27 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SCK_INOUT inout functionality */
    {27U, 18U, 304U, 2U, 1U}, 
    /* Inout settings for pad PORT28 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_1_FTM1_CH1_INOUT inout functionality */
    {28U, 16U, 154U, 2U, 1U}, 
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT inout functionality */
    {28U, 18U, 308U, 2U, 1U}, 
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SIN_INOUT inout functionality */
    {28U, 19U, 305U, 2U, 1U}, 
    /* Inout settings for pad PORT29 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_3_I2C3_SDA_INOUT inout functionality */
    {29U, 16U, 210U, 4U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH2_INOUT inout functionality */
    {29U, 17U, 155U, 4U, 1U}, 
    /* LLCE_LPSPI_2_LLCE_LPSPI2_SOUT_INOUT inout functionality */
    {29U, 18U, 306U, 2U, 1U}, 
    /* Inout settings for pad PORT30 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS0_INOUT inout functionality */
    {30U, 16U, 299U, 2U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT inout functionality */
    {30U, 17U, 284U, 2U, 1U}, 
    /* I2C_3_I2C3_SCL_INOUT inout functionality */
    {30U, 18U, 209U, 3U, 1U}, 
    /* Inout settings for pad PORT31 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {31U, 16U, 53U, 3U, 0U}, 
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT inout functionality */
    {31U, 17U, 300U, 2U, 1U}, 
    /* Inout settings for pad PORT32 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_0_I2C0_SCL_INOUT inout functionality */
    {32U, 15U, 54U, 3U, 0U}, 
    /* FLEXTIMER_1_FTM1_CH4_INOUT inout functionality */
    {32U, 16U, 157U, 2U, 1U}, 
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS1_INOUT inout functionality */
    {32U, 17U, 308U, 3U, 1U}, 
    /* Inout settings for pad PORT33 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_4_I2C4_SDA_INOUT inout functionality */
    {33U, 15U, 212U, 3U, 1U}, 
    /* Inout settings for pad PORT34 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_4_I2C4_SCL_INOUT inout functionality */
    {34U, 16U, 211U, 3U, 1U}, 
    /* Inout settings for pad PORT41 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH4_INOUT inout functionality */
    {41U, 17U, 147U, 4U, 1U}, 
    /* DSPI_4_DSPI4_SCK_INOUT inout functionality */
    {41U, 18U, 489U, 2U, 1U}, 
    /* Inout settings for pad PORT42 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH5_INOUT inout functionality */
    {42U, 15U, 148U, 3U, 1U}, 
    /* Inout settings for pad PORT46 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_B_0_INOUT inout functionality */
    {46U, 16U, 40U, 2U, 0U}, 
    /* Inout settings for pad PORT47 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_CMD_INOUT inout functionality */
    {47U, 15U, 3U, 2U, 0U}, 
    /* QUADSPI_QSPI_DATA_B_3_INOUT inout functionality */
    {47U, 16U, 41U, 2U, 0U}, 
    /* Inout settings for pad PORT48 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_0_INOUT inout functionality */
    {48U, 15U, 4U, 2U, 0U}, 
    /* I2C_2_I2C2_SCL_INOUT inout functionality */
    {48U, 17U, 207U, 3U, 1U}, 
    /* Inout settings for pad PORT49 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_1_INOUT inout functionality */
    {49U, 15U, 5U, 2U, 0U}, 
    /* I2C_1_I2C1_SCL_INOUT inout functionality */
    {49U, 17U, 205U, 3U, 1U}, 
    /* Inout settings for pad PORT50 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_2_INOUT inout functionality */
    {50U, 15U, 8U, 2U, 0U}, 
    /* QUADSPI_QSPI_DATA_B_4_INOUT inout functionality */
    {50U, 16U, 45U, 2U, 0U}, 
    /* I2C_1_I2C1_SDA_INOUT inout functionality */
    {50U, 17U, 206U, 5U, 1U}, 
    /* Inout settings for pad PORT51 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_3_INOUT inout functionality */
    {51U, 15U, 9U, 2U, 0U}, 
    /* QUADSPI_QSPI_DATA_B_1_INOUT inout functionality */
    {51U, 16U, 42U, 2U, 0U}, 
    /* I2C_3_I2C3_SCL_INOUT inout functionality */
    {51U, 17U, 209U, 4U, 1U}, 
    /* Inout settings for pad PORT52 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_4_INOUT inout functionality */
    {52U, 15U, 10U, 2U, 0U}, 
    /* QUADSPI_QSPI_DQS_B_INOUT inout functionality */
    {52U, 16U, 46U, 2U, 0U}, 
    /* I2C_2_I2C2_SDA_INOUT inout functionality */
    {52U, 17U, 208U, 4U, 1U}, 
    /* Inout settings for pad PORT53 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_5_INOUT inout functionality */
    {53U, 15U, 11U, 2U, 0U}, 
    /* QUADSPI_QSPI_DATA_B_7_INOUT inout functionality */
    {53U, 16U, 43U, 2U, 0U}, 
    /* I2C_3_I2C3_SDA_INOUT inout functionality */
    {53U, 17U, 210U, 2U, 1U}, 
    /* Inout settings for pad PORT54 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_6_INOUT inout functionality */
    {54U, 15U, 7U, 2U, 0U}, 
    /* Inout settings for pad PORT55 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USDHC_0_SD0_D_7_INOUT inout functionality */
    {55U, 15U, 6U, 2U, 0U}, 
    /* I2C_0_I2C0_SCL_INOUT inout functionality */
    {55U, 17U, 54U, 4U, 0U}, 
    /* Inout settings for pad PORT56 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_B_5_INOUT inout functionality */
    {56U, 16U, 38U, 2U, 0U}, 
    /* Inout settings for pad PORT57 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_B_2_INOUT inout functionality */
    {57U, 16U, 39U, 2U, 0U}, 
    /* Inout settings for pad PORT58 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_B_6_INOUT inout functionality */
    {58U, 16U, 44U, 2U, 0U}, 
    /* Inout settings for pad PORT59 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS1_INOUT inout functionality */
    {59U, 16U, 300U, 3U, 1U}, 
    /* Inout settings for pad PORT60 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS2_INOUT inout functionality */
    {60U, 17U, 309U, 2U, 1U}, 
    /* Inout settings for pad PORT61 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_MD_INOUT inout functionality */
    {61U, 15U, 15U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_MD_INOUT inout functionality */
    {61U, 16U, 345U, 2U, 1U}, 
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS3_INOUT inout functionality */
    {61U, 17U, 310U, 2U, 1U}, 
    /* Inout settings for pad PORT62 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_0_INOUT inout functionality */
    {62U, 15U, 384U, 2U, 1U}, 
    /* DSPI_3_DSPI3_PCS0_INOUT inout functionality */
    {62U, 16U, 483U, 2U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT inout functionality */
    {62U, 17U, 291U, 2U, 1U}, 
    /* Inout settings for pad PORT63 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_1_INOUT inout functionality */
    {63U, 15U, 385U, 2U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT inout functionality */
    {63U, 17U, 298U, 2U, 1U}, 
    /* Inout settings for pad PORT64 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_2_INOUT inout functionality */
    {64U, 15U, 386U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH1_INOUT inout functionality */
    {64U, 18U, 154U, 3U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_RX_CLK_INOUT inout functionality */
    {64U, 19U, 367U, 2U, 1U}, 
    /* Inout settings for pad PORT65 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_3_INOUT inout functionality */
    {65U, 15U, 387U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH2_INOUT inout functionality */
    {65U, 16U, 155U, 5U, 1U}, 
    /* Inout settings for pad PORT66 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TX_CLK_INOUT inout functionality */
    {66U, 15U, 26U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TX_CLK_INOUT inout functionality */
    {66U, 16U, 354U, 2U, 1U}, 
    /* Inout settings for pad PORT67 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TX_EN_INOUT inout functionality */
    {67U, 15U, 55U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TX_EN_INOUT inout functionality */
    {67U, 16U, 356U, 2U, 1U}, 
    /* Inout settings for pad PORT68 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TXD_0_INOUT inout functionality */
    {68U, 15U, 56U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TXD_0_INOUT inout functionality */
    {68U, 16U, 357U, 2U, 1U}, 
    /* Inout settings for pad PORT69 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TXD_1_INOUT inout functionality */
    {69U, 15U, 59U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TXD_1_INOUT inout functionality */
    {69U, 16U, 358U, 2U, 1U}, 
    /* Inout settings for pad PORT70 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TXD_2_INOUT inout functionality */
    {70U, 15U, 57U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TXD_2_INOUT inout functionality */
    {70U, 16U, 359U, 2U, 1U}, 
    /* Inout settings for pad PORT71 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TXD_3_INOUT inout functionality */
    {71U, 15U, 58U, 2U, 0U}, 
    /* GMAC_0_GMAC0_RMII_REF_CLK_INOUT inout functionality */
    {71U, 16U, 23U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_TXD_3_INOUT inout functionality */
    {71U, 17U, 360U, 2U, 1U}, 
    /* Inout settings for pad PORT72 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_RX_CLK_INOUT inout functionality */
    {72U, 15U, 17U, 2U, 0U}, 
    /* PFE_MAC1_PFE_MAC1_RX_CLK_INOUT inout functionality */
    {72U, 17U, 347U, 2U, 1U}, 
    /* Inout settings for pad PORT78 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TX_EN_INOUT inout functionality */
    {78U, 15U, 336U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TX_EN_INOUT inout functionality */
    {78U, 16U, 376U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH1_INOUT inout functionality */
    {78U, 17U, 144U, 3U, 1U}, 
    /* Inout settings for pad PORT79 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_MD_INOUT inout functionality */
    {79U, 15U, 325U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_MD_INOUT inout functionality */
    {79U, 16U, 365U, 3U, 1U}, 
    /* I2C_3_I2C3_SCL_INOUT inout functionality */
    {79U, 17U, 209U, 5U, 1U}, 
    /* Inout settings for pad PORT80 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_1_FTM1_CH5_INOUT inout functionality */
    {80U, 17U, 158U, 2U, 1U}, 
    /* Inout settings for pad PORT81 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* GMAC_0_GMAC0_TS_CLK_INOUT inout functionality */
    {81U, 15U, 27U, 2U, 0U}, 
    /* PFE_MAC2_PFE_MAC2_MD_INOUT inout functionality */
    {81U, 16U, 365U, 2U, 1U}, 
    /* PFE_MAC0_PFE_MAC0_MD_INOUT inout functionality */
    {81U, 17U, 325U, 3U, 1U}, 
    /* Inout settings for pad PORT82 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_3_I2C3_SDA_INOUT inout functionality */
    {82U, 17U, 210U, 3U, 1U}, 
    /* Inout settings for pad PORT85 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_0_INOUT inout functionality */
    {85U, 15U, 28U, 2U, 0U}, 
    /* Inout settings for pad PORT86 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_1_INOUT inout functionality */
    {86U, 15U, 29U, 2U, 0U}, 
    /* Inout settings for pad PORT87 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_2_INOUT inout functionality */
    {87U, 15U, 30U, 2U, 0U}, 
    /* Inout settings for pad PORT88 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_3_INOUT inout functionality */
    {88U, 15U, 31U, 2U, 0U}, 
    /* Inout settings for pad PORT89 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_4_INOUT inout functionality */
    {89U, 15U, 32U, 2U, 0U}, 
    /* Inout settings for pad PORT90 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_5_INOUT inout functionality */
    {90U, 15U, 33U, 2U, 0U}, 
    /* Inout settings for pad PORT91 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_6_INOUT inout functionality */
    {91U, 15U, 34U, 2U, 0U}, 
    /* Inout settings for pad PORT92 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DATA_A_7_INOUT inout functionality */
    {92U, 15U, 35U, 2U, 0U}, 
    /* Inout settings for pad PORT93 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* QUADSPI_QSPI_DQS_A_INOUT inout functionality */
    {93U, 15U, 36U, 2U, 0U}, 
    /* Inout settings for pad PORT95 :  {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_1_FTM1_CH1_INOUT inout functionality */
    {95U, 16U, 154U, 4U, 1U}

};

/**
* @brief Array of elements storing information about INOUT functionalities on the second SIUL2 instance
*/
static const Port_InoutSettingType Port_SIUL2_1_aInoutMuxSettings[PORT_SIUL2_1_INOUT_TABLE_NUM_ENTRIES_U16] =
{
    /* Inout settings for pad PORT112 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_7_INOUT inout functionality */
    {112U, 15U, 391U, 2U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT inout functionality */
    {112U, 16U, 294U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH3_INOUT inout functionality */
    {112U, 17U, 156U, 4U, 1U}, 
    /* Inout settings for pad PORT113 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TXD_1_INOUT inout functionality */
    {113U, 15U, 338U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TXD_1_INOUT inout functionality */
    {113U, 16U, 378U, 2U, 1U}, 
    /* I2C_1_I2C1_SDA_INOUT inout functionality */
    {113U, 17U, 206U, 3U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT inout functionality */
    {113U, 18U, 293U, 3U, 1U}, 
    /* Inout settings for pad PORT114 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TXD_2_INOUT inout functionality */
    {114U, 15U, 339U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TXD_2_INOUT inout functionality */
    {114U, 16U, 379U, 3U, 1U}, 
    /* I2C_1_I2C1_SCL_INOUT inout functionality */
    {114U, 17U, 205U, 4U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT inout functionality */
    {114U, 18U, 292U, 3U, 1U}, 
    /* Inout settings for pad PORT115 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TXD_3_INOUT inout functionality */
    {115U, 15U, 340U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TXD_3_INOUT inout functionality */
    {115U, 16U, 380U, 3U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS0_INOUT inout functionality */
    {115U, 18U, 291U, 3U, 1U}, 
    /* Inout settings for pad PORT116 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH0_INOUT inout functionality */
    {116U, 15U, 143U, 3U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SOUT_INOUT inout functionality */
    {116U, 16U, 298U, 3U, 1U}, 
    /* PFE_MAC0_PFE_MAC0_RX_CLK_INOUT inout functionality */
    {116U, 17U, 327U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_RX_CLK_INOUT inout functionality */
    {116U, 18U, 367U, 3U, 1U}, 
    /* Inout settings for pad PORT117 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT inout functionality */
    {117U, 15U, 297U, 3U, 1U}, 
    /* Inout settings for pad PORT118 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH4_INOUT inout functionality */
    {118U, 15U, 147U, 5U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT inout functionality */
    {118U, 16U, 296U, 3U, 1U}, 
    /* Inout settings for pad PORT119 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_2_I2C2_SDA_INOUT inout functionality */
    {119U, 15U, 208U, 3U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS3_INOUT inout functionality */
    {119U, 16U, 294U, 3U, 1U}, 
    /* Inout settings for pad PORT120 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_2_I2C2_SCL_INOUT inout functionality */
    {120U, 15U, 207U, 4U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT inout functionality */
    {120U, 16U, 285U, 3U, 1U}, 
    /* Inout settings for pad PORT122 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TX_CLK_INOUT inout functionality */
    {122U, 15U, 334U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TX_CLK_INOUT inout functionality */
    {122U, 16U, 374U, 3U, 1U}, 
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {122U, 17U, 53U, 4U, 0U}, 
    /* Inout settings for pad PORT144 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* PFE_MAC0_PFE_MAC0_TXD_0_INOUT inout functionality */
    {144U, 15U, 337U, 2U, 1U}, 
    /* PFE_MAC2_PFE_MAC2_TXD_0_INOUT inout functionality */
    {144U, 16U, 377U, 2U, 1U}, 
    /* I2C_0_I2C0_SCL_INOUT inout functionality */
    {144U, 17U, 54U, 5U, 0U}, 
    /* Inout settings for pad PORT145 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS3_INOUT inout functionality */
    {145U, 16U, 302U, 2U, 1U}, 
    /* Inout settings for pad PORT147 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_2_LLCE_LPSPI2_PCS2_INOUT inout functionality */
    {147U, 16U, 301U, 2U, 1U}, 
    /* Inout settings for pad PORT151 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH0_INOUT inout functionality */
    {151U, 16U, 143U, 4U, 1U}, 
    /* Inout settings for pad PORT153 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI2_SCK_INOUT inout functionality */
    {153U, 16U, 479U, 3U, 1U}, 
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {153U, 17U, 53U, 5U, 0U}, 
    /* Inout settings for pad PORT155 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI2_PCS0_INOUT inout functionality */
    {155U, 16U, 478U, 3U, 1U}, 
    /* Inout settings for pad PORT159 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_3_DSPI3_SCK_INOUT inout functionality */
    {159U, 16U, 484U, 3U, 1U}, 
    /* I2C_0_I2C0_SCL_INOUT inout functionality */
    {159U, 17U, 54U, 6U, 0U}, 
    /* Inout settings for pad PORT161 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_3_DSPI3_PCS0_INOUT inout functionality */
    {161U, 16U, 483U, 3U, 1U}, 
    /* I2C_0_I2C0_SDA_INOUT inout functionality */
    {161U, 17U, 53U, 6U, 0U}, 
    /* Inout settings for pad PORT163 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* I2C_1_I2C1_SCL_INOUT inout functionality */
    {163U, 17U, 205U, 5U, 1U}, 
    /* Inout settings for pad PORT165 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_4_DSPI4_SCK_INOUT inout functionality */
    {165U, 16U, 489U, 3U, 1U}, 
    /* I2C_1_I2C1_SDA_INOUT inout functionality */
    {165U, 17U, 206U, 4U, 1U}, 
    /* Inout settings for pad PORT167 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_4_DSPI4_PCS0_INOUT inout functionality */
    {167U, 16U, 488U, 3U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH0_INOUT inout functionality */
    {167U, 17U, 143U, 5U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS1_INOUT inout functionality */
    {167U, 18U, 284U, 3U, 1U}, 
    /* Inout settings for pad PORT169 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS2_INOUT inout functionality */
    {169U, 17U, 285U, 2U, 1U}, 
    /* Inout settings for pad PORT171 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH2_INOUT inout functionality */
    {171U, 17U, 145U, 4U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT inout functionality */
    {171U, 18U, 286U, 2U, 1U}, 
    /* DSPI_5_DSPI5_PCS0_INOUT inout functionality */
    {171U, 19U, 493U, 3U, 1U}, 
    /* Inout settings for pad PORT173 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH3_INOUT inout functionality */
    {173U, 16U, 146U, 4U, 1U}, 
    /* Inout settings for pad PORT175 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS3_INOUT inout functionality */
    {175U, 17U, 286U, 3U, 1U}, 
    /* DSPI_5_DSPI5_SCK_INOUT inout functionality */
    {175U, 18U, 494U, 4U, 1U}, 
    /* I2C_1_I2C1_SCL_INOUT inout functionality */
    {175U, 19U, 205U, 6U, 1U}, 
    /* Inout settings for pad PORT177 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_3_LLCE_LPSPI3_SCK_INOUT inout functionality */
    {177U, 16U, 312U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH1_INOUT inout functionality */
    {177U, 17U, 144U, 4U, 1U}, 
    /* Inout settings for pad PORT178 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_3_LLCE_LPSPI3_SOUT_INOUT inout functionality */
    {178U, 16U, 314U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH2_INOUT inout functionality */
    {178U, 17U, 145U, 5U, 1U}, 
    /* PFE_MAC1_PFE_MAC1_MD_INOUT inout functionality */
    {178U, 18U, 345U, 3U, 1U}, 
    /* GMAC_0_GMAC0_MD_INOUT inout functionality */
    {178U, 19U, 15U, 3U, 0U}, 
    /* Inout settings for pad PORT180 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* FLEXTIMER_0_FTM0_CH3_INOUT inout functionality */
    {180U, 16U, 146U, 5U, 1U}, 
    /* Inout settings for pad PORT181 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_3_LLCE_LPSPI3_PCS0_INOUT inout functionality */
    {181U, 16U, 307U, 2U, 1U}, 
    /* FLEXTIMER_0_FTM0_CH4_INOUT inout functionality */
    {181U, 17U, 147U, 6U, 1U}, 
    /* Inout settings for pad PORT184 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI2_SCK_INOUT inout functionality */
    {184U, 15U, 479U, 2U, 1U}, 
    /* Inout settings for pad PORT186 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* DSPI_2_DSPI2_PCS0_INOUT inout functionality */
    {186U, 16U, 478U, 2U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS2_INOUT inout functionality */
    {186U, 17U, 293U, 2U, 1U}, 
    /* Inout settings for pad PORT187 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* LLCE_LPSPI_1_LLCE_LPSPI1_PCS1_INOUT inout functionality */
    {187U, 15U, 292U, 2U, 1U}, 
    /* Inout settings for pad PORT188 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_4_INOUT inout functionality */
    {188U, 15U, 388U, 2U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH0_INOUT inout functionality */
    {188U, 18U, 153U, 5U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SIN_INOUT inout functionality */
    {188U, 20U, 297U, 2U, 1U}, 
    /* Inout settings for pad PORT189 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_5_INOUT inout functionality */
    {189U, 15U, 389U, 2U, 1U}, 
    /* DSPI_3_DSPI3_SCK_INOUT inout functionality */
    {189U, 16U, 484U, 2U, 1U}, 
    /* LLCE_LPSPI_1_LLCE_LPSPI1_SCK_INOUT inout functionality */
    {189U, 19U, 296U, 2U, 1U}, 
    /* Inout settings for pad PORT190 : {Mscr Id, AltFunc, Imcr Id, Imcr value, Imcr Siul Instance} */
    /* USB_USB_ULPI_DATA_6_INOUT inout functionality */
    {190U, 15U, 390U, 2U, 1U}, 
    /* LLCE_LPSPI_0_LLCE_LPSPI0_PCS0_INOUT inout functionality */
    {190U, 17U, 283U, 3U, 1U}, 
    /* FLEXTIMER_1_FTM1_CH4_INOUT inout functionality */
    {190U, 18U, 157U, 3U, 1U}

};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

/**
* @brief Array of values storing the length of tables with INOUT functionality information on each of the SIUL2 instance on the platform
*/
const uint16 Port_au16NumInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    PORT_SIUL2_0_INOUT_TABLE_NUM_ENTRIES_U16,
    PORT_SIUL2_1_INOUT_TABLE_NUM_ENTRIES_U16
};

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

/**
* @brief Array of pointers to the tables storing information about pin availability on each of the SIUL2 instance on the platform
*/
const Port_PinModeAvailabilityArrayType * const Port_apSiul2InstancePinModeAvailability[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    &Port_SIUL2_0_au16PinModeAvailability,
    &Port_SIUL2_1_au16PinModeAvailability
};

/**
* @brief Array of pointers to the tables storing information about IN functionality on each of the SIUL2 instance on the platform
*/
const Port_InMuxSettingType * const Port_apInMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInMuxSettings,
    Port_SIUL2_1_aInMuxSettings
};

/**
* @brief Array of pointers to the tables storing information about indexes in the IN functionality tables on each of the SIUL2 instance on the platform
*/
const uint16 * const Port_apInMuxSettingsIndex[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_au16InMuxSettingsIndex,
    Port_SIUL2_1_au16InMuxSettingsIndex
};

/**
* @brief Array of pointers to the tables storing information about INOUT functionality on each of the SIUL2 instance on the platform
*/
const Port_InoutSettingType * const Port_apInoutMuxSettings[PORT_NUM_SIUL2_INSTANCES_U8] =
{
    Port_SIUL2_0_aInoutMuxSettings,
    Port_SIUL2_1_aInoutMuxSettings
};

#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"

#endif /* PORT_SET_PIN_MODE_API */

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */

