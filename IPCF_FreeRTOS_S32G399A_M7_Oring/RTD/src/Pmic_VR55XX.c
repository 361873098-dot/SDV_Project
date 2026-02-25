/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Pmic_VR55XX
*   Dependencies         : MCU,DET,DEM,RTE,I2C,PORT,DIO,OCOTP
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.2
*   Build Version        : S32_RTD_4_0_2_P04_D2312_ASR_REL_4_4_REV_0000_20231219
*
*   (c) Copyright 2020-2023 NXP
*   All Rights Reserved.
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
*   @file Pmic_VR55XX.c
*
*   @addtogroup PMIC_VR5510 Pmic VR5510 driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_Internals.h"
#include "Pmic_VR55XX.h"
#include "SchM_Pmic.h"
#include "Pmic_VR55XX_i2c_external_access.h"
#include "Pmic_VR55XX_pin_external_access.h"
#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
#include "Pmic_VR55XX_ocotp_external_access.h"
#endif

#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_VENDOR_ID_C                      43
#define PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION_C       4
#define PMIC_VR55XX_AR_RELEASE_MINOR_VERSION_C       4
#define PMIC_VR55XX_AR_RELEASE_REVISION_VERSION_C    0
#define PMIC_VR55XX_SW_MAJOR_VERSION_C               4
#define PMIC_VR55XX_SW_MINOR_VERSION_C               0
#define PMIC_VR55XX_SW_PATCH_VERSION_C               2

/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Pmic_Internals header file are of the same vendor */
#if (PMIC_VR55XX_VENDOR_ID_C != PMIC_INTERNALS_VENDOR_ID)
    #error "Pmic_VR55XX.c and Pmic_Internals.h have different vendor ids"
#endif
/* Check if current file and Pmic_Internals header file are of the same Autosar version */
#if ((PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_MINOR_VERSION_C    != PMIC_INTERNALS_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_REVISION_VERSION_C != PMIC_INTERNALS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_VR55XX.c and Pmic_Internals.h are different"
#endif
/* Check if current file and Pmic_Internals header file are of the same Software version */
#if ((PMIC_VR55XX_SW_MAJOR_VERSION_C != PMIC_INTERNALS_SW_MAJOR_VERSION) || \
     (PMIC_VR55XX_SW_MINOR_VERSION_C != PMIC_INTERNALS_SW_MINOR_VERSION) || \
     (PMIC_VR55XX_SW_PATCH_VERSION_C != PMIC_INTERNALS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_VR55XX.c and Pmic_Internals.h are different"
#endif

/* Check if current file and Pmic_VR55XX header file are of the same vendor */
#if (PMIC_VR55XX_VENDOR_ID_C != PMIC_VR55XX_VENDOR_ID)
    #error "Pmic_VR55XX.c and Pmic_VR55XX.h have different vendor ids"
#endif
/* Check if current file and Pmic_VR55XX header file are of the same Autosar version */
#if ((PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION_C    != PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_MINOR_VERSION_C    != PMIC_VR55XX_AR_RELEASE_MINOR_VERSION) || \
     (PMIC_VR55XX_AR_RELEASE_REVISION_VERSION_C != PMIC_VR55XX_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Pmic_VR55XX.c and Pmic_VR55XX.h are different"
#endif
/* Check if current file and Pmic_VR55XX header file are of the same Software version */
#if ((PMIC_VR55XX_SW_MAJOR_VERSION_C != PMIC_VR55XX_SW_MAJOR_VERSION) || \
     (PMIC_VR55XX_SW_MINOR_VERSION_C != PMIC_VR55XX_SW_MINOR_VERSION) || \
     (PMIC_VR55XX_SW_PATCH_VERSION_C != PMIC_VR55XX_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Pmic_VR55XX.c and Pmic_VR55XX.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Dio header file are of the same Autosar version */
    #if ((PMIC_VR55XX_AR_RELEASE_MAJOR_VERSION_C != SCHM_PMIC_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_AR_RELEASE_MINOR_VERSION_C != SCHM_PMIC_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Pmic_VR55XX.c and SchM_Pmic.h are different"
    #endif

#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define PMIC_VR5510_I2C_READ_BIT_MASK_U8       ((uint8)0x1U)
#define PMIC_VR5510_CRC_SEED_VALUE_U8          ((uint8)0xFFU)
#define PMIC_VR5510_NUM_OF_OSC_FREQ            ((uint8)16U)
#define PMIC_VR5510_NUM_OF_WD_REFRESH_LIMIT    ((uint8)4U)
#define PMIC_VR5510_ARRAY_WD_REFRESH_LIMIT     {6U ,4U ,2U ,1U}
#define PMIC_VR5510_NUM_OF_WD_PERIOD           ((uint8)16U)
#define PMIC_VR5510_CRC_TABLE_SIZE             (256U)
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
#define PMIC_VR5510_REVERSE(x) (x) = (uint16)((uint16)((x) & (uint16)0xAAAA) >> 1U) | (uint16)((uint16)((x) & (uint16)0x5555) << 1U);\
                   (x) = (uint16)((uint16)((x) & (uint16)0xCCCC) >> 2U) | (uint16)((uint16)((x) & (uint16)0x3333) << 2U);\
                   (x) = (uint16)((uint16)((x) & (uint16)0xF0F0) >> 4U) | (uint16)((uint16)((x) & (uint16)0x0F0F) << 4U);\
                   (x) = (uint16)((uint16)((x) >> 8U) | (uint16)((x) << 8U))
#define PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OFFSET_OTP_ADDR8     ((uint8)7U)
#endif

/**
 * @brief    Oscillator Frequency
 * @details  The enumeration with all the possible oscillator frequencies.
 */
#define PMIC_VR5510_OSC20MHZ   ((uint16)0x0U)   /* IRCOSC's frequency is 20MHz */
#define PMIC_VR5510_OSC24MHZ   ((uint16)0x4U)   /* IRCOSC's frequency is 24MHz */
#define PMIC_VR5510_OSC16MHZ   ((uint16)0x9U)   /* IRCOSC's frequency is 16MHz */
#define PMIC_VR5510_OSC19MHZ   ((uint16)0xCU)   /* IRCOSC's frequency is 19MHz */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
typedef enum
{
    PMIC_VR55XX_MODE_ENTRY = 0xA55AU,
    PMIC_VR55XX_MODE_EXIT  = 0x5A5AU

} Pmic_VR55XX_DirectionType;
#endif

/**
 * @brief    Oscillator Step Direction
 * @details  The enumeration with step direction possibilities.
 */
typedef enum
{
    PMIC_VR5510_OSC_STEPUP    = 0x00U,   /* Step up IRCOSC's frequency by 1MHz   */
    PMIC_VR5510_OSC_STEPDOWN  = 0x01U    /* Step down IRCOSC's frequency by 1MHz */

} Pmic_OscillatorStepType;
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
#define PMIC_START_SEC_VAR_CLEARED_16
#include "Pmic_MemMap.h"
/**
* @brief            Pmic_au16FsState get FS_State register. This bit will use to check after wait time
*/
static uint16 Pmic_au16FsState[PMIC_MAX_DEVICECONFIGS];
#define PMIC_STOP_SEC_VAR_CLEARED_16
#include "Pmic_MemMap.h"
#endif

#define PMIC_START_SEC_CONST_8
#include "Pmic_MemMap.h"
/**
* @brief          CRC8 lookup table.for CRC8 of polynomial 0x1D.
*/
static const uint8 Pmic_au8CrcLookupTable[PMIC_VR5510_CRC_TABLE_SIZE] =
{
    0x00U, 0x1DU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU, 0x9CU,
    0x81U, 0xA6U, 0xBBU, 0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9EU, 0x25U, 0x38U,
    0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U, 0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U,
    0xD4U, 0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU, 0x4AU, 0x57U, 0x70U, 0x6DU,
    0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U, 0x13U,
    0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U, 0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U,
    0xB5U, 0xA8U, 0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU,
    0x11U, 0x42U, 0x5FU, 0x78U, 0x65U, 0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U,
    0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU, 0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU,
    0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U, 0x26U, 0x3BU,
    0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U,
    0x9DU, 0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U, 0x03U, 0x1EU, 0x39U, 0x24U,
    0x77U, 0x6AU, 0x4DU, 0x50U, 0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U,
    0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU, 0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U,
    0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U, 0x35U, 0x28U, 0x0FU,
    0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
    0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U,
    0x79U, 0x5EU, 0x43U, 0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U, 0x5AU, 0x47U,
    0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U, 0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U,
    0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U
};
#define PMIC_STOP_SEC_CONST_8
#include "Pmic_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

static void Pmic_VR55XX_I2C_Bus_Release(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
#endif
#endif

    const Pmic_InterfaceUnitConfigType * pTempInterfaceUnit = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pInterfaceConfig;
    uint8 u8I2cNoOfClockToggles = 18U;
    volatile uint32 u32WaitTicks = 0U;

    /* set the pin as GPIO - seems to set as output by default*/
    Pmic_VR55XX_Port_SetPinMode(PMIC_SIUL_INSTANCE_U8, pTempInterfaceUnit->u32I2cSclPinIndex, pTempInterfaceUnit->u8I2cSclPinInitialMode);

    /* bit bang 9 clocks */
    SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_02();
    do
    {
        (void)Pmic_VR55XX_Dio_FlipChannel(PMIC_SIUL_INSTANCE_U8, pTempInterfaceUnit->u16I2cSclDioChannelId);

        /* delay cpu_Freq/i2c_Freq cycles*/
        u32WaitTicks = (uint32) ((pTempInterfaceUnit->u32CPUFreq)/(pTempInterfaceUnit->u32I2cFreq));
        do
        {
            ASM_KEYWORD("nop"); /* wait the required number of cycles */
            u32WaitTicks--;
        } while ((0U < u32WaitTicks));
        u8I2cNoOfClockToggles--;

    } while ((uint8)0U < u8I2cNoOfClockToggles);

    SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_02();
    /* revert the pin to SCL again */
    Pmic_VR55XX_Port_SetPinMode(PMIC_SIUL_INSTANCE_U8, pTempInterfaceUnit->u32I2cSclPinIndex, pTempInterfaceUnit->u8I2cSclPinMode);
}

#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
#endif

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_StateTransition(const Pmic_DeviceIndexType u32DeviceId, const uint16 u16StateDst);
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs);
#endif
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops(const Pmic_DeviceIndexType u32DeviceId);

static void Pmic_VR55XX_BusyLoops(const Pmic_DeviceIndexType u32DeviceId);

    #if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
    static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
    static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
    #endif

#else
#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
#endif

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_StateTransition(const Pmic_DeviceIndexType u32DeviceId, const uint16 u16StateDst);
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs);
#endif
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks(const Pmic_DeviceIndexType u32DeviceId);
static void Pmic_VR55XX_BusyTicks(const Pmic_DeviceIndexType u32DeviceId,const uint32 u32TimeoutValueUs);

    #if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
    static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
    static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
    #endif

#endif
#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
#endif

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_StateTransition(const Pmic_DeviceIndexType u32DeviceId, const uint16 u16StateDst);
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs);
#endif

static Pmic_ReturnType Pmic_VR55XX_TimeoutWait(const Pmic_DeviceIndexType u32DeviceId);
static void Pmic_VR55XX_BusyWait(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs);
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection);
#endif
static Pmic_ReturnType Pmic_VR55XX_ConfigureOscillatorFrequency(const Pmic_DeviceIndexType u32DeviceId, const uint16 DesiredOscFreq);
static Pmic_ReturnType Pmic_VR55XX_StepOscillatorFrequency(const Pmic_DeviceIndexType u32DeviceId, const Pmic_OscillatorStepType eStepDirection);
static Pmic_ReturnType Pmic_VR55XX_TimeWaitInitFS(const Pmic_DeviceIndexType u32DeviceId);
static Pmic_ReturnType Pmic_VR55XX_InitFailSafeUnit(const Pmic_DeviceIndexType u32DeviceId);
static Pmic_ReturnType Pmic_VR55xx_ConfigureFailSafe(const Pmic_DeviceIndexType u32DeviceId);
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
static Pmic_ReturnType Pmic_VR55XX_ClearFault(const Pmic_DeviceIndexType u32DeviceId);
static Pmic_ReturnType Pmic_VR55XX_ExecuteReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId);
#endif
static Pmic_ReturnType Pmic_VR55XX_ValidateCRC8(const uint8 * pu8Data,const uint8 u8DataLength,const uint8 u8FrameCrc);
static uint8 Pmic_VR55XX_CalculateCRC8(const uint8 * pu8Data, const uint8 u8DataLength);
#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"


#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
/*!
* @brief Pmic_VR55XX_TimeoutLoops_DebugMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
    uint16 u16RegValue = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter Debug Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16 == (u16RegValue & PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }
            } while ((uint32)0U < u32TimeOut);
        }
        else
        {
            /* Exit Debug Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16 != (u16RegValue & PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }
            } while ((uint32)0U < u32TimeOut);
        }
        if ((uint32)0U == u32TimeOut)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif /* ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED)) */

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
/*!
* @brief Pmic_VR55XX_TimeoutLoops_StateTransition.
*
* @param[in] u32DeviceId.
* @param[in] u16StateDst.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_StateTransition(const Pmic_DeviceIndexType u32DeviceId, const uint16 u16StateDst)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
    uint16 u16RegValue = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        /* Wait for FSU State Transition */
        do
        {
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
            u32TimeOut--;
            if ((u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) >= u16StateDst)
            {
                /* Expectation state catches */
                break;
            }
        } while ((uint32)0U < u32TimeOut);
        /* Update value for Pmic_au16FsState */
        Pmic_au16FsState[u32DeviceId] = u16RegValue;
        if ((uint32)0U == u32TimeOut)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_TimeoutLoops_FaultErrCnt.
*
* @param[in] u32DeviceId.
* @param[in] u32TimeoutValueUs.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
    uint16 u16RegValue = 0U;

    (void)u32TimeoutValueUs;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        /* Wait for the Fault Error Counter to be decremented to 0 */
        do
        {
            /* Nothing */
            u32TimeOut--;
        } while (
                    ((uint32)0U < u32TimeOut)
                );

        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_FSSM_ADDR8, &u16RegValue);
        if ((uint16)0U != (u16RegValue & PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_MASK16))
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif

/*!
* @brief Pmic_VR55XX_TimeoutLoops.
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        do
        {
            /* Nothing */
            u32TimeOut--;
        } while ((uint32)0U < u32TimeOut);

        eInternalStatus |= PMIC_E_TIMEOUT;
        Pmic_abErrorDetected[u32DeviceId] = TRUE;
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_BusyLoops.
*
* @param[in] u32DeviceId.
*
*/
static void Pmic_VR55XX_BusyLoops(const Pmic_DeviceIndexType u32DeviceId)
{
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        do
        {
            /* Nothing */
            u32TimeOut--;
        } while ((uint32)0U < u32TimeOut);
    }
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_VR55XX_TimeoutLoops_MainTestMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
    uint16 u16RegValue = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter Main Test Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_STATUS1_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16 == (u16RegValue & PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }

            } while ((uint32)0U < u32TimeOut);
        }
        else
        {
            /* Exit Main Test Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_STATUS1_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16 != (u16RegValue & PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }
            } while ((uint32)0U < u32TimeOut);
        }

        if ((uint32)0U == u32TimeOut)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_TimeoutLoops_FailSafeTestMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutLoops_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
    uint16 u16RegValue = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter FailSafe Test Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16 == (u16RegValue & PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }
            } while ((uint32)0U < u32TimeOut);
        }
        else
        {
            /* Exit FailSafe Test Mode */
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32TimeOut--;
                if (PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16 != (u16RegValue & PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16))
                {
                    /* Expectation state catches */
                    break;
                }
            } while ((uint32)0U < u32TimeOut);
        }
        if ((uint32)0U == u32TimeOut)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif /* (STD_ON == PMIC_OTP_EMULATION_MODE_API) */

#else

#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
/*!
* @brief Pmic_VR55XX_TimeoutTicks_DebugMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint16 u16RegValue = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter Debug Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16 != (u16RegValue & PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }
        else
        {
            /* Exit Debug Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16 == (u16RegValue & PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }
        if (u32ElapsedTicks > u32TimeoutTicks)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif /* ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED)) */

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
/*!
* @brief Pmic_VR55XX_TimeoutTicks_StateTransition.
*
* @param[in] u32DeviceId.
* @param[in] u16StateDst.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_StateTransition(const Pmic_DeviceIndexType u32DeviceId,const uint16 u16StateDst)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint16 u16RegValue = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        /* Wait for FSU State Transition */
        CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

        do
        {
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
            u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
        } while (
                    ((u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) < u16StateDst) &&
                    (u32ElapsedTicks <= u32TimeoutTicks)
                );
        /* Update value for Pmic_au16FsState */
        Pmic_au16FsState[u32DeviceId] = u16RegValue;
        if (u32ElapsedTicks > u32TimeoutTicks)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_TimeoutTicks_FaultErrCnt.
*
* @param[in] u32DeviceId.
* @param[in] u32TimeoutValueUs.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint16 u16RegValue = 0U;
    uint32 CurrentTicks = 0U;
    uint32 u32TimeoutTicks = 0U;

    if (OSIF_COUNTER_DUMMY == (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE)
    {
        u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    }
    else
    {
        u32TimeoutTicks = OsIf_MicrosToTicks(u32TimeoutValueUs, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    }

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        /* Wait for the Fault Error Counter to be decremented to 0 */
        CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

        do
        {
            /* Wait for the watchdog refreshes to decrement FEC */
            u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
        } while (u32ElapsedTicks <= u32TimeoutTicks);

        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_FSSM_ADDR8, &u16RegValue);
        if ((uint16)0U != (u16RegValue & PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_MASK16))
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif /* (STD_ON == PMIC_WATCHDOG_ENABLED) */

/*!
* @brief Pmic_VR55XX_TimeoutTicks.
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

        do
        {
            /* Busy wait */
            u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
        } while (u32ElapsedTicks <= u32TimeoutTicks);

        eInternalStatus |= PMIC_E_TIMEOUT;
        Pmic_abErrorDetected[u32DeviceId] = TRUE;
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_BusyTicks.
*
* @param[in] u32DeviceId.
* @param[in] u32TimeoutValueUs.
*
* @return Pmic_ReturnType.
*/
static void Pmic_VR55XX_BusyTicks(const Pmic_DeviceIndexType u32DeviceId,const uint32 u32TimeoutValueUs)
{
    uint32 u32ElapsedTicks = 0U;
    uint32 CurrentTicks = 0U;
    uint32 u32TimeoutTicks = 0U;

    if (OSIF_COUNTER_DUMMY == (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE)
    {
        u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    }
    else
    {
        u32TimeoutTicks = OsIf_MicrosToTicks(u32TimeoutValueUs, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    }

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
        do
        {
            /* Busy wait */
            u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
        } while (u32ElapsedTicks <= u32TimeoutTicks);
    }
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_VR55XX_TimeoutTicks_MainTestMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint16 u16RegValue = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter Main Test Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_STATUS1_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16 != (u16RegValue & PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }
        else
        {
            /* Exit Main Test Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_STATUS1_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16 == (u16RegValue & PMIC_VR55XX_M_TM_STATUS1_M_TM_ACTIVE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }

        if (u32ElapsedTicks > u32TimeoutTicks)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_TimeoutTicks_FailSafeTestMode.
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutTicks_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32ElapsedTicks = 0U;
    uint16 u16RegValue = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = 0U;

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_VR55XX_MODE_ENTRY == eDirection)
        {
            /* Enter FailSafe Test Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16 != (u16RegValue & PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }
        else
        {
            /* Exit FailSafe Test Mode */
            CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);

            do
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            } while (
                        (PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16 == (u16RegValue & PMIC_VR55XX_FS_STATES_FS_TM_ACTIVE_MASK16) ) &&
                        (u32ElapsedTicks <= u32TimeoutTicks)
                    );
        }

        if (u32ElapsedTicks > u32TimeoutTicks)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
    }

    return eInternalStatus;
}
#endif /* (STD_ON == PMIC_OTP_EMULATION_MODE_API) */

#endif  /* (STD_OFF == PMIC_TIMEOUT_MECHANISM_LOOPS) */

#if ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED))
/*!
* @brief Pmic_VR55XX_TimeoutWait_DebugMode.
*
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_DebugMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops_DebugMode(u32DeviceId, eDirection);
#else
    return Pmic_VR55XX_TimeoutTicks_DebugMode(u32DeviceId, eDirection);
#endif
}
#endif /* ((STD_ON == PMIC_OTP_EMULATION_MODE_API) || (STD_ON == PMIC_WATCHDOG_ENABLED)) */

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
/*!
* @brief Pmic_VR55XX_TimeoutWait_StateTransition.
*
* @param[in] u32DeviceId.
* @param[in] u16StateDst.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_StateTransition(const Pmic_DeviceIndexType u32DeviceId, const uint16 u16StateDst)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops_StateTransition(u32DeviceId, u16StateDst);
#else
    return Pmic_VR55XX_TimeoutTicks_StateTransition(u32DeviceId, u16StateDst);
#endif
}

/*!
* @brief Pmic_VR55XX_TimeoutWait_FaultErrCnt.
*
* @param[in] u32DeviceId.
* @param[in] u32TimeoutValueUs.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_FaultErrCnt(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops_FaultErrCnt(u32DeviceId, u32TimeoutValueUs);
#else
    return Pmic_VR55XX_TimeoutTicks_FaultErrCnt(u32DeviceId, u32TimeoutValueUs);
#endif
}
#endif

/*!
* @brief Pmic_VR55XX_TimeoutWait.
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait(const Pmic_DeviceIndexType u32DeviceId)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops(u32DeviceId);
#else
    return Pmic_VR55XX_TimeoutTicks(u32DeviceId);
#endif
}

/*!
* @brief Pmic_VR55XX_BusyWait.
*
* @param[in] u32DeviceId.
* @param[in] u32TimeoutValueUs.
*
* @return Pmic_ReturnType.
*/
static void Pmic_VR55XX_BusyWait(const Pmic_DeviceIndexType u32DeviceId, const uint32 u32TimeoutValueUs)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    (void)u32TimeoutValueUs;
    Pmic_VR55XX_BusyLoops(u32DeviceId);
#else
    Pmic_VR55XX_BusyTicks(u32DeviceId, u32TimeoutValueUs);
#endif
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_VR55XX_TimeoutWait_MainTestMode.
*
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_MainTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops_MainTestMode(u32DeviceId, eDirection);
#else
    return Pmic_VR55XX_TimeoutTicks_MainTestMode(u32DeviceId, eDirection);
#endif
}

/*!
* @brief Pmic_VR55XX_TimeoutWait_FailSafeTestMode.
*
*
* @param[in] u32DeviceId.
* @param[in] eDirection.
*
* @return Pmic_ReturnType.
*/
static Pmic_ReturnType Pmic_VR55XX_TimeoutWait_FailSafeTestMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_VR55XX_DirectionType eDirection)
{
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    return Pmic_VR55XX_TimeoutLoops_FailSafeTestMode(u32DeviceId, eDirection);
#else
    return Pmic_VR55XX_TimeoutTicks_FailSafeTestMode(u32DeviceId, eDirection);
#endif
}
#endif
static Pmic_ReturnType Pmic_VR55XX_ConfigureOscillatorFrequency(const Pmic_DeviceIndexType u32DeviceId, const uint16 DesiredOscFreq)
{
    const sint32 Pmic_VR55XX_au32OscFreqToSteps[PMIC_VR5510_NUM_OF_OSC_FREQ] =
    {
        0,  /* 0000 - 20MHz */
        1,  /* 0001 - 21MHz */
        2,  /* 0010 - 22MHz */
        3,  /* 0011 - 23MHz */
        4,  /* 0100 - 24MHz */
        0,  /* Reserved */
        0,  /* Reserved */
        0,  /* Reserved */
        0,  /* Reserved */
       -4,  /* 1001 - 16MHz */
       -3,  /* 1010 - 17MHz */
       -2,  /* 1011 - 18MHz */
       -1,  /* 1100 - 19MHz */
        0,  /* Reserved */
        0,  /* Reserved */
        0   /* Reserved */
    };
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    Pmic_OscillatorStepType eStepDirection = PMIC_VR5510_OSC_STEPUP;
    sint32 NumSteps = 0;
    uint16 CurrentOscFreq = 0U;
    uint16 u16RegValue = 0U;

    eInternalStatus   |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, &u16RegValue);
    CurrentOscFreq = (uint16)(u16RegValue       & PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16);

    if (CurrentOscFreq != DesiredOscFreq)
    {
        NumSteps = Pmic_VR55XX_au32OscFreqToSteps[DesiredOscFreq] - Pmic_VR55XX_au32OscFreqToSteps[CurrentOscFreq];

        eStepDirection = ((NumSteps > 0)? (PMIC_VR5510_OSC_STEPUP) : (PMIC_VR5510_OSC_STEPDOWN));
        NumSteps    = ((NumSteps > 0)? (NumSteps) : (-NumSteps));

        while (0 != NumSteps)
        {
            NumSteps--;
            eInternalStatus |= Pmic_VR55XX_StepOscillatorFrequency(u32DeviceId, eStepDirection);

            /* Step once every 10us */
            Pmic_VR55XX_BusyWait(u32DeviceId, 10U);
        }

        eInternalStatus   |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, &u16RegValue);
        CurrentOscFreq  = (uint16)(u16RegValue & PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16);

        if (CurrentOscFreq != DesiredOscFreq)
        {
            eInternalStatus |= PMIC_E_CLOCK;
        }
    }

    return eInternalStatus;
}

static Pmic_ReturnType Pmic_VR55XX_StepOscillatorFrequency(const Pmic_DeviceIndexType u32DeviceId, const Pmic_OscillatorStepType eStepDirection)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16MainClockReg1 = 0U;
    uint16 u16CurrentFreq = 0u;
    uint16 u16DesiredFreq = 0u;

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, &u16MainClockReg1);
    u16CurrentFreq = (uint16)(u16MainClockReg1 & PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16);
    u16DesiredFreq = u16CurrentFreq;

    if (
           (PMIC_VR5510_OSC_STEPUP == eStepDirection) &&
           (PMIC_VR5510_OSC24MHZ != u16CurrentFreq)
       )
    {
        if (PMIC_VR5510_OSC19MHZ == u16CurrentFreq)
        {
            u16DesiredFreq = PMIC_VR5510_OSC20MHZ;
        }
        else
        {
            u16DesiredFreq = (uint16)(u16CurrentFreq + (uint16)1U);
        }
    }
    else if (
                (PMIC_VR5510_OSC_STEPDOWN == eStepDirection) &&
                (PMIC_VR5510_OSC16MHZ != u16CurrentFreq)
            )
    {
        if (PMIC_VR5510_OSC20MHZ == u16CurrentFreq)
        {
            u16DesiredFreq = PMIC_VR5510_OSC19MHZ;
        }
        else
        {
            u16DesiredFreq = (uint16)(u16CurrentFreq - (uint16)1U);
        }
    }
    else
    {
        /* Do nothing */
    }

    if (u16DesiredFreq != u16CurrentFreq)
    {
        u16MainClockReg1 = (uint16)(u16MainClockReg1 & ((uint16)~PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16)) | PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_U16(u16DesiredFreq);

        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, u16MainClockReg1);
    }

    return eInternalStatus;
}

static Pmic_ReturnType Pmic_VR55XX_TimeWaitInitFS(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
    volatile uint32 u32TimeOut = PMIC_TIMEOUT_DURATION;
#else
    uint32 u32ElapsedTicks = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(PMIC_TIMEOUT_DURATION, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter((OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
#endif
    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        /* Wait for INIT_FS State Transition */
#if (STD_ON == PMIC_TIMEOUT_MECHANISM_LOOPS)
        do
        {
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
            u32TimeOut--;
            if ((u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) == PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16)
            {
                /* Expectation state catches */
                break;
            }
        } while ((uint32)0U < u32TimeOut);

        if (0U == u32TimeOut)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
#else

        do
        {
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
            u32ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, (OsIf_CounterType)PMIC_TIMEOUT_OSIF_COUNTER_TYPE);
            if ((u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16) == PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16)
            {
                /* Expectation state catches */
                break;
            }
        } while (u32ElapsedTicks <= u32TimeoutTicks);
        if (u32ElapsedTicks > u32TimeoutTicks)
        {
            eInternalStatus |= PMIC_E_TIMEOUT;
            Pmic_abErrorDetected[u32DeviceId] = TRUE;
        }
#endif
    }

    return eInternalStatus;
}

static Pmic_ReturnType Pmic_VR55XX_InitFailSafeUnit(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
    /* device mode is normal_fs or not */
    if (PMIC_VR55XX_FS_STATES_FSM_STATES_NORMAL_FS_U16 != (u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16))
    {
        /* If failsafe is not Init_FS, driver will switch to Init_fs */
        if (PMIC_VR55XX_FS_STATES_FSM_STATES_INIT_FS_U16 != (u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16))
        {
            /* Switch Back InitFs before configure failsafe */
            eInternalStatus |= Pmic_VR55XX_GotoInitFS(u32DeviceId);
        }

        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, &u16RegValue);
        /* (FS_DIAG_SAFETY[LBIST_BYPASSED] != 0)? */
        /* (FS_DIAG_SAFETY[LBIST_DONE] = 1) and (FS_DIAG_SAFETY[LBIST_PASS] = 1) and (FS_DIAG_SAFETY[ABIST1_OK] = 1)? */
        if
        (
            (PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16 != (uint16)(u16RegValue & PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16)) &&
            ((uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16) !=
            (uint16)(u16RegValue & (uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16)))
        )
        {
            eInternalStatus |= PMIC_E_CORRUPTED;
        }

        /* (FS_STATE_IOS[PGOOD_SNS] != 1) or (FS_STATE_IOS[RSTB_SNS] != 1)? */
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
        if
        (
            (PMIC_VR55XX_FS_SAFE_IOS_RSTB_SNS_MASK16 | PMIC_VR55XX_FS_SAFE_IOS_PGOOD_SNS_MASK16)
            != (uint16)(u16RegValue & (PMIC_VR55XX_FS_SAFE_IOS_RSTB_SNS_MASK16 | PMIC_VR55XX_FS_SAFE_IOS_PGOOD_SNS_MASK16))
        )
        {
            eInternalStatus |= PMIC_E_SIGNAL;
        }

        if (PMIC_E_OK == eInternalStatus)
        {
            /* write setting to fail safe register */
            eInternalStatus |= Pmic_VR55xx_ConfigureFailSafe(u32DeviceId);

        /* If watchdog monitoring is disabled by OTP, the FSU state machine will remain in INIT_FS. */
#if (STD_ON == PMIC_WATCHDOG_ENABLED)

            Pmic_abGateWdgTrigger[u32DeviceId] = FALSE;

            /* Service watchdog one time to transition from "INIT_FS" to "WAIT_ABIST2" state*/
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &u16RegValue);
            if (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 == PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue))
            {
                eInternalStatus |= Pmic_VR55XX_TriggerWatchdog(u32DeviceId);
            }
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
            else
            {
                /* There is no external watchdog driver. Notify upper layer to start the triggering task */
                if (NULL_PTR != Pmic_pConfigStruct->Pmic_pWdgTaskNotification)
                {
                    Pmic_pConfigStruct->Pmic_pWdgTaskNotification(u32DeviceId, PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue), PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_VALUE_U16(u16RegValue));
                }
            }
#endif /* (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API) */

            /* Busy-wait until FS_STATES[FSM_STATES] = ABIST2 (or Higher) */
            eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ABIST2_U16);

            /* Busy-wait until FS_STATES[FSM_STATES] = ASSERT_FS0B (or Higher) */
            eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ASSERT_FS0B_U16);

            /* (FS_STATES[REG_CORRUPT] != 0)? */
            if (PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16 == (uint16)(Pmic_au16FsState[u32DeviceId] & PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16))
            {
                eInternalStatus |= PMIC_E_CORRUPTED;
            }
            else
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, &u16RegValue);
                /* (FS_DIAG_SAFETY[LBIST_BYPASSED] != 0)? */
                /* (FS_DIAG_SAFETY[LBIST_DONE] = 1) and (FS_DIAG_SAFETY[LBIST_PASS] = 1) and (FS_DIAG_SAFETY[ABIST1_OK] = 1 and (FS_DIAG_SAFETY[ABIST2_OK] = 1)? */
                if
                (
                    (PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16 != (uint16)(u16RegValue & PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16)) &&
                    ((uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 \
                            | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST1_OK_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16) !=
                    (uint16)(u16RegValue & (uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 \
                            | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST1_OK_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16)))
                )
                {
                    eInternalStatus |= PMIC_E_CORRUPTED;
                }
                else
                {
                    /* Exit Debug Mode */
                    /* (FS_STATES[DBG_MODE] = 1)? */
                    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
                    if (PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16 == (uint16)(u16RegValue & PMIC_VR55XX_FS_STATES_DBG_MODE_MASK16) )
                    {
                        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, PMIC_VR55XX_FS_STATES_DBG_EXIT_MASK16);
                        eInternalStatus |= Pmic_VR55XX_TimeoutWait_DebugMode(u32DeviceId, PMIC_VR55XX_MODE_EXIT );
                    }

                    /* Clear all the flags in FS_GRL_FLAGS by clearing FS_DIAG_SAFETY and FS_OVUVREG_STATUS */
                    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, PMIC_VR55XX_FS_DIAG_SAFETY_RWBITS_MASK32);
                    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8, PMIC_VR55XX_FS_OVUVREG_STATUS_RWBITS_MASK32);

                    eInternalStatus |= Pmic_VR55XX_ClearFault(u32DeviceId);

                    eInternalStatus |= Pmic_VR55XX_ExecuteReleaseFs0b(u32DeviceId);
                }
            }
#endif /* STD_ON == PMIC_WATCHDOG_ENABLED */
        }
    }
    else
    {
        (void)u16RegValue;
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
        /* enable gate for wdg_trigger */
        Pmic_abGateWdgTrigger[u32DeviceId] =  FALSE;
#endif
    }

    return eInternalStatus;
}

static Pmic_ReturnType Pmic_VR55xx_ConfigureFailSafe(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
#endif
#endif
    const Pmic_VR55XX_InitConfigType * pInitConfig = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pHwDeviceConfig->Pmic_Ipw_pVR55XXHwDeviceConfig->pDeviceInitConfig;
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;

#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    uint32 u32OcotpData = 0U;

    if ((Std_ReturnType)E_OK == Pmic_VR55XX_Ocotp_ReadShadowRegister(PMIC_OCOTP_ISTANCE, Pmic_pConfigStruct->Pmic_u32DiePreocessOcotpIndex, &u32OcotpData))
    {
        if (0U != (u32OcotpData & PMIC_OCOTP_DIE_PROCESS_MASK))
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_SVS_ADDR8, pInitConfig->u16FailSafeSvsReg);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_SVS_ADDR8, (uint16)(~(pInitConfig->u16FailSafeSvsReg)));
        }
        else
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_SVS_ADDR8, pInitConfig->u16FailSafeSvsReg & ((uint16)(~PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_MASK16)));
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_SVS_ADDR8, (uint16)(~(pInitConfig->u16FailSafeSvsReg & ((uint16)(~PMIC_VR55XX_FS_I_SVS_SVS_OFFSET_MASK16)))));
        }
    }
    (void)u32OcotpData;
#else
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_SVS_ADDR8, pInitConfig->u16FailSafeSvsReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_SVS_ADDR8, (uint16)(~(pInitConfig->u16FailSafeSvsReg)));
#endif
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION1_ADDR8, pInitConfig->u16FailSafeReactionReg1);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_OVUV_SAFE_REACTION1_ADDR8, (uint16)(~(pInitConfig->u16FailSafeReactionReg1)));

    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_OVUV_SAFE_REACTION2_ADDR8, pInitConfig->u16FailSafeReactionReg2);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_OVUV_SAFE_REACTION2_ADDR8, (uint16)(~(pInitConfig->u16FailSafeReactionReg2)));

#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
    /* There is no external watchdog driver. Self-initialize the Watchdog registers */
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_WD_CFG_ADDR8, pInitConfig->u16FailSafeWatchdogConfigReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_WD_CFG_ADDR8, (uint16)(~(pInitConfig->u16FailSafeWatchdogConfigReg)));
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_SEED_ADDR8, pInitConfig->u16FailSafeWatchdogSeedReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, pInitConfig->u16FailSafeWatchdogDurationReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8, (uint16)(~(pInitConfig->u16FailSafeWatchdogDurationReg)));
#endif /* (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API) */

    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_SAFE_INPUTS_ADDR8, pInitConfig->u16FailSafeInputsReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_SAFE_INPUTS_ADDR8, (uint16)(~(pInitConfig->u16FailSafeInputsReg)));

    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_FSSM_ADDR8, pInitConfig->u16FailSafeStateMachineReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_FSSM_ADDR8, (uint16)(~(pInitConfig->u16FailSafeStateMachineReg)));

    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_ABIST2_CTRL_ADDR8, pInitConfig->u16FailSafeAbist2Reg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_ABIST2_CTRL_ADDR8, (uint16)(~(pInitConfig->u16FailSafeAbist2Reg)));

    return eInternalStatus;
}

#if (STD_ON == PMIC_WATCHDOG_ENABLED)
static Pmic_ReturnType Pmic_VR55XX_ClearFault(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;
    uint32 u32WdgRfrCnt = 0U;
    const uint32 au32RfrLimitValue[PMIC_VR5510_NUM_OF_WD_REFRESH_LIMIT] = PMIC_VR5510_ARRAY_WD_REFRESH_LIMIT;
    /* Array mapping Watchdog window period values to time given in microseconds */
    const uint32 Pmic_VR55XX_au32WindowPeriodToUs[PMIC_VR5510_NUM_OF_WD_PERIOD] =
    {
        0U,
        1000U,
        2000U,
        3000U,
        4000U,
        6000U,
        8000U,
        12000U,
        16000U,
        24000U,
        32000U,
        64000U,
        128000U,
        256000U,
        512000U,
        1024000U
    };

    /* Decrement the Fault Error Counter to 0 */
    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_FSSM_ADDR8, &u16RegValue);
    u32WdgRfrCnt = PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_VALUE_U16(u16RegValue);
    if (0U != u32WdgRfrCnt)
    {

        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_WD_CFG_ADDR8, &u16RegValue);
        u32WdgRfrCnt = u32WdgRfrCnt * (au32RfrLimitValue[PMIC_VR55XX_FS_I_WD_CFG_WD_RFR_LIMIT_VALUE_U16(u16RegValue)] + 1U);
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &u16RegValue);

        if (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 == PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue))
        {
            while (0U != u32WdgRfrCnt--)
            {
                eInternalStatus |= Pmic_VR55XX_TriggerWatchdog(u32DeviceId);
            }
        }
        else
        {
            eInternalStatus |= Pmic_VR55XX_TimeoutWait_FaultErrCnt(u32DeviceId, (u32WdgRfrCnt + 1U) * Pmic_VR55XX_au32WindowPeriodToUs[PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue)]);
        }
    }

    return eInternalStatus;
}
static Pmic_ReturnType Pmic_VR55XX_ExecuteReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId)
{
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;

    SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_03();
    /* Read wdg_seed [15:0], not wdg_seed, rotate bit [0:15] */
    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_SEED_ADDR8, &u16RegValue);
    PMIC_VR5510_REVERSE(u16RegValue);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_RELEASE_FS0B_ADDR8, (uint16)(~u16RegValue) );

    SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_03();
    /* Busy-wait until FS_STATES[FSM_STATES] = NORMAL_FS */
    eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_NORMAL_FS_U16);

    /* Check status bit FS_STATE_IOS[FS0B_SNS] */
    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
    if (PMIC_VR55XX_FS_SAFE_IOS_FS0B_SNS_MASK16 != (uint16)(u16RegValue & PMIC_VR55XX_FS_SAFE_IOS_FS0B_SNS_MASK16))
    {
        eInternalStatus |= PMIC_E_SIGNAL;
    }

    return eInternalStatus;
}
#endif
/*!
* @brief Pmic_VR55XX_CalculateCRC8.
*
* @param[in] u32DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[out] pu16ValueOut.
*
* @return Pmic_ReturnType.
*/
static uint8 Pmic_VR55XX_CalculateCRC8(const uint8 * pu8Data, const uint8 u8DataLength)
{
    uint8 u8CrcValue;    /* Result. */
    uint8 u8TableIndex;  /* Index in the CRC table. */
    uint8 u8DataIndex;   /* Index in the data buffer. */

    /* Set CRC seed value. */
    u8CrcValue = PMIC_VR5510_CRC_SEED_VALUE_U8;

    for (u8DataIndex = 0U; u8DataIndex < u8DataLength; ++u8DataIndex)
    {
        u8TableIndex = u8CrcValue ^ pu8Data[u8DataIndex];
        u8CrcValue   = Pmic_au8CrcLookupTable[u8TableIndex];
    }

    return u8CrcValue;
}

static Pmic_ReturnType Pmic_VR55XX_ValidateCRC8(const uint8 * pu8Data,const uint8 u8DataLength,const uint8 u8FrameCrc)
{
    Pmic_ReturnType eCrcStatus = PMIC_E_DATA;
    uint8 u8CalculatedCrc;   /* Computed CRC value. */

    u8CalculatedCrc = Pmic_VR55XX_CalculateCRC8(pu8Data, u8DataLength);

    if (u8CalculatedCrc == u8FrameCrc)
    {
        eCrcStatus = PMIC_E_OK;
    }

    return eCrcStatus;
}

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"


/*!
* @brief Pmic_VR55XX_I2C_ReadRegister.
*
* @param[in] u32DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[out] pu16ValueOut.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_I2C_ReadRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, uint16 * pu16ValueOut)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(pu16ValueOut != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
    DevAssert(u8RegAddr <= MAX_I2C_ADDRESS_REGISTER);
#endif
#endif
    /* Warning: Both statuses have to be initialized to E_OK so that the function
     *          does not return inexistent errors when Pmic_abErrorDetected is TRUE. */
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    const Pmic_InterfaceUnitConfigType * pTempInterfaceUnit = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pInterfaceConfig;
    uint16 u16DeviceAddress = 0U;
    uint8 Pmic_au8DataBuffer[PMIC_BYTES_PER_COMMAND_U32];
    const Pmic_VR55XX_I2cSetupType * pI2cSendSetup;
    const Pmic_VR55XX_I2cSetupType * pI2cReadSetup;
    Pmic_VR55XX_I2cSetupType xI2cInterface = {
        (uint32)pTempInterfaceUnit->u8ChannelId,
        u16DeviceAddress,
        TRUE,
        TRUE,
        (uint8)(PMIC_PAYLOAD_SIZE_U32 - 3U),
        PMIC_TIMEOUT_DURATION
    };

    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_MAIN_UNIT == eDestination)
        {
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            u16DeviceAddress = ((TRUE == Pmic_abTestMode[u32DeviceId])? PMIC_VR55XX_TEST_MODE_MAIN_UNIT_ADDR8 : pTempInterfaceUnit->u8MainUnitAddress);
#else
            u16DeviceAddress = pTempInterfaceUnit->u8MainUnitAddress;
#endif
        }
        else
        {
#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            u16DeviceAddress = ((TRUE == Pmic_abTestMode[u32DeviceId])? PMIC_VR55XX_TEST_MODE_FAIL_SAFE_UNIT_ADDR8 : pTempInterfaceUnit->u8FailSafeUnitAddress);
#else
            u16DeviceAddress = pTempInterfaceUnit->u8FailSafeUnitAddress;
#endif
        }

        Pmic_au8DataBuffer[0U] = (uint8)(u16DeviceAddress << 1U) | PMIC_VR5510_I2C_READ_BIT_MASK_U8;
        Pmic_au8DataBuffer[1U] = u8RegAddr;

        /* Enter critical section */
        SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_01();
        xI2cInterface.u16SlaveAddress = u16DeviceAddress;
        pI2cSendSetup = &xI2cInterface;
        ReturnStatus = Pmic_VR55XX_I2cTransferExternal(pI2cSendSetup, &Pmic_au8DataBuffer[1U], NULL_PTR);
        if ((Std_ReturnType)E_OK == ReturnStatus)
        {
            xI2cInterface.bRepeatedStart = FALSE;
            xI2cInterface.u8NumberOfBytes = (uint8)(PMIC_PAYLOAD_SIZE_U32 - 1U);
            pI2cReadSetup = &xI2cInterface;
            ReturnStatus = Pmic_VR55XX_I2cTransferExternal(pI2cReadSetup, NULL_PTR, &Pmic_au8DataBuffer[2U]);

            /* Exit critical section */
            SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01();

            if ((Std_ReturnType)E_OK == ReturnStatus)
            {
                MCAL_FAULT_INJECTION_POINT(PMIC_FIP_01_CHANGE_CRC);

                eInternalStatus = Pmic_VR55XX_ValidateCRC8(Pmic_au8DataBuffer, (uint8)(PMIC_BYTES_PER_COMMAND_U32 - 1U), Pmic_au8DataBuffer[4U]);
            }
            if ((Std_ReturnType)E_OK == ReturnStatus)
            {
                *pu16ValueOut = (uint16)(((uint16)Pmic_au8DataBuffer[2U] << 8U) | (uint16)Pmic_au8DataBuffer[3U]);
            }
        }
        else
        {
            /* Exit critical section */
            SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_01();
        }

        MCAL_FAULT_INJECTION_POINT(PMIC_FIP_02_CHANGE_READ_STATUS);

        Pmic_abErrorDetected[u32DeviceId] = (((ReturnStatus == (Std_ReturnType)E_OK) && (eInternalStatus == PMIC_E_OK))? (FALSE) : (TRUE));
    }

    return ((ReturnStatus == (Std_ReturnType)E_OK)? (eInternalStatus) : (PMIC_E_COM));
}

/*!
* @brief Pmic_VR55XX_I2C_WriteRegister.
*
* @param[in] u32DeviceId.
* @param[in] eDestination.
* @param[in] u8RegAddr.
* @param[in] u16WriteValue.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_I2C_WriteRegister(const Pmic_DeviceIndexType u32DeviceId, const Pmic_InterfaceDstType eDestination, const uint8 u8RegAddr, const uint16 u16WriteValue)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
    DevAssert(u8RegAddr <= MAX_I2C_ADDRESS_REGISTER);
#endif
#endif
    /* Warning: The status has to be initialized to E_OK so that the function does
     *          not return inexistent errors when Pmic_abErrorDetected is TRUE. */
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;
    const Pmic_InterfaceUnitConfigType * pTempInterfaceUnit = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pInterfaceConfig;
    uint16 u16DeviceAddress = 0U;
    uint8 Pmic_au8DataBuffer[PMIC_BYTES_PER_COMMAND_U32];
    const Pmic_VR55XX_I2cSetupType * pI2cSetup;
    Pmic_VR55XX_I2cSetupType xI2cInterface =
    {
        (uint32)pTempInterfaceUnit->u8ChannelId,
        u16DeviceAddress,
        TRUE,
        FALSE,
        (uint8)(PMIC_PAYLOAD_SIZE_U32),
        PMIC_TIMEOUT_DURATION
    };
    if (FALSE == Pmic_abErrorDetected[u32DeviceId])
    {
        if (PMIC_MAIN_UNIT == eDestination)
        {
    #if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            u16DeviceAddress = (uint16)((TRUE == Pmic_abTestMode[u32DeviceId])? PMIC_VR55XX_TEST_MODE_MAIN_UNIT_ADDR8 : pTempInterfaceUnit->u8MainUnitAddress);
    #else
            u16DeviceAddress = (uint16)(pTempInterfaceUnit->u8MainUnitAddress);
    #endif
        }
        else
        {
    #if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
            u16DeviceAddress = (uint16)((TRUE == Pmic_abTestMode[u32DeviceId])? PMIC_VR55XX_TEST_MODE_FAIL_SAFE_UNIT_ADDR8 : pTempInterfaceUnit->u8FailSafeUnitAddress);
    #else
            u16DeviceAddress = (uint16)(pTempInterfaceUnit->u8FailSafeUnitAddress);
    #endif
        }

        Pmic_au8DataBuffer[0U] = (uint8)((uint8)(u16DeviceAddress << 1U) & (uint8)(~PMIC_VR5510_I2C_READ_BIT_MASK_U8));
        Pmic_au8DataBuffer[1U] = u8RegAddr;
        Pmic_au8DataBuffer[2U] = (uint8)((uint16)(u16WriteValue >> 8U) & 0x00FFU);
        Pmic_au8DataBuffer[3U] = (uint8)(u16WriteValue & 0x00FFU);
        Pmic_au8DataBuffer[4U] = Pmic_VR55XX_CalculateCRC8(Pmic_au8DataBuffer, (uint8)(PMIC_BYTES_PER_COMMAND_U32 - 1U));

        /* Enter critical section */
        SchM_Enter_Pmic_PMIC_EXCLUSIVE_AREA_00();
        xI2cInterface.u16SlaveAddress = u16DeviceAddress;
        pI2cSetup = &xI2cInterface;

        ReturnStatus = Pmic_VR55XX_I2cTransferExternal(pI2cSetup, &Pmic_au8DataBuffer[1U], NULL_PTR);

        /* Exit critical section */
        SchM_Exit_Pmic_PMIC_EXCLUSIVE_AREA_00();

        MCAL_FAULT_INJECTION_POINT(PMIC_FIP_03_CHANGE_WRITE_STATUS);

        Pmic_abErrorDetected[u32DeviceId] = ((ReturnStatus == (Std_ReturnType)E_OK)? (FALSE) : (TRUE));
    }

    return ((ReturnStatus == (Std_ReturnType)E_OK)? ((Pmic_ReturnType)(PMIC_E_OK)) : ((Pmic_ReturnType)(PMIC_E_COM)));
}

#if (STD_ON == PMIC_WATCHDOG_API)
/*!
* @brief Pmic_VR55XX_TriggerWatchdog.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_TriggerWatchdog(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint32 u32SeedValue = 0U;
    uint16 u16RetSeedValue = 0U;

    if (FALSE == Pmic_abGateWdgTrigger[u32DeviceId])
    {
        if (FALSE == Pmic_abIsWdgTrigger[u32DeviceId])
        {
            Pmic_abIsWdgTrigger[u32DeviceId] = TRUE;
            /* Read the seed each time */
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_SEED_ADDR8, &u16RetSeedValue);

            if (
                    PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_SELECTION_OTP_MASK8 == (PMIC_VR55XX_CFG_ASIL_LEVEL_OTP_WD_SELECTION_OTP_MASK8 & \
                    (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pHwDeviceConfig->Pmic_Ipw_pVR55XXHwDeviceConfig->pDeviceOtpConfig->paOtpFailSafeConfig) \
                    [PMIC_VR55XX_FS_GET_OTP_REG_INDEX_U8(PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OTP_ADDR8 - PMIC_VR55XX_FS_CFG_ASIL_LEVEL_OFFSET_OTP_ADDR8)].u8RegisterData)
                )
            {
                /* Calculate the watchdog seed with watchdog type challenge */
                u32SeedValue  = (uint32)u16RetSeedValue * 4U;
                u32SeedValue += 2U;
                u32SeedValue  = (uint32)~u32SeedValue;
                u32SeedValue /= 4U;
                u16RetSeedValue  = (uint16)u32SeedValue;
            }

            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_ANSWER_ADDR8, u16RetSeedValue);

            Pmic_abIsWdgTrigger[u32DeviceId] = FALSE;
        }
    }
    (void)u16RetSeedValue;

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_DisableWatchdog.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_DisableWatchdog(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;

    /* Switch Back InitFs before configure SVS */
    eInternalStatus |= Pmic_VR55XX_GotoInitFS(u32DeviceId);

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &u16RegValue);
    u16RegValue &= (uint16)(~PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_MASK16);

    /* Configure Watchdog window disable */
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, u16RegValue);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8, (uint16)(~u16RegValue));

    Pmic_abGateWdgTrigger[u32DeviceId] =  FALSE;

    /* Service watchdog one time to transition from "INIT_FS" to "WAIT_ABIST2" state*/
    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &u16RegValue);
    if (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 == PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue))
    {
        eInternalStatus |= Pmic_VR55XX_TriggerWatchdog(u32DeviceId);
    }

    /* Busy-wait until FS_STATES[FSM_STATES] = ABIST2 (or Higher) */
    eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ABIST2_U16);

    /* Busy-wait until FS_STATES[FSM_STATES] = ASSERT_FS0B (or Higher) */
    eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ASSERT_FS0B_U16);

    /* (FS_STATES[REG_CORRUPT] != 0)? */
    if (PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16 == (uint16)(Pmic_au16FsState[u32DeviceId] & PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16))
    {
        eInternalStatus |= PMIC_E_CORRUPTED;
    }
    else
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, &u16RegValue);
        /* (FS_DIAG_SAFETY[LBIST_BYPASSED] != 0)? */
        /* (FS_DIAG_SAFETY[LBIST_DONE] = 1) and (FS_DIAG_SAFETY[LBIST_PASS] = 1) and (FS_DIAG_SAFETY[ABIST2_OK] = 1)? */
        if
        (
            (PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16 != (uint16)(u16RegValue & PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16)) &&
            ((uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16) !=
            (uint16)(u16RegValue & (uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16)))
        )
        {
            eInternalStatus |= PMIC_E_CORRUPTED;
        }

        if (PMIC_E_CORRUPTED != (eInternalStatus & PMIC_E_CORRUPTED))
        {
            /* Clear all the flags in FS_GRL_FLAGS by clearing FS_DIAG_SAFETY and FS_OVUVREG_STATUS */
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, PMIC_VR55XX_FS_DIAG_SAFETY_RWBITS_MASK32);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8, PMIC_VR55XX_FS_OVUVREG_STATUS_RWBITS_MASK32);

            eInternalStatus |= Pmic_VR55XX_ClearFault(u32DeviceId);

            eInternalStatus |= Pmic_VR55XX_ExecuteReleaseFs0b(u32DeviceId);
        }
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_ReleaseFs0b.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_ReleaseFs0b(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif

    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegValue);
    if (PMIC_E_OK == eInternalStatus)
    {
        /* If failsafe is Assert_Fs0b state, driver will execute release FS0b pin */
        if (PMIC_VR55XX_FS_STATES_FSM_STATES_ASSERT_FS0B_U16 == (u16RegValue & PMIC_VR55XX_FS_STATES_FSM_STATES_MASK16))
        {
            /* Clear all the flags in FS_GRL_FLAGS by clearing FS_DIAG_SAFETY and FS_OVUVREG_STATUS */
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, PMIC_VR55XX_FS_DIAG_SAFETY_RWBITS_MASK32);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8, PMIC_VR55XX_FS_OVUVREG_STATUS_RWBITS_MASK32);
            /* Clear fault if have */
            eInternalStatus |= Pmic_VR55XX_ClearFault(u32DeviceId);
            /* Execute release FS0B pin */
            eInternalStatus |= Pmic_VR55XX_ExecuteReleaseFs0b(u32DeviceId);
        }
        else
        {
            eInternalStatus |= PMIC_E_NOK;
        }

    }

    return eInternalStatus;
}
#endif /* (STD_ON == PMIC_WATCHDOG_ENABLED) */

/*!
* @brief Pmic_VR55XX_InitDevice.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_InitDevice(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegStatesValue = 0U;
    uint16 u16RegFlagValue = 0U;

    Pmic_VR55XX_I2C_Bus_Release(u32DeviceId);

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &u16RegStatesValue);
    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG_ADDR8, &u16RegFlagValue);

    /* Clear all flags in M_FLAG by clearing M_FLAG1/2/3 */
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG1_ADDR8, PMIC_VR55XX_M_FLAG1_RWBITS_MASK16);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG2_ADDR8, PMIC_VR55XX_M_FLAG2_RWBITS_MASK16);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, PMIC_VR55XX_M_FLAG3_RWBITS_MASK16);

    if (PMIC_E_OK == eInternalStatus)
    {

        /* (FS_STATES[OTP_CORRUPT] = 1)? */
        if (PMIC_VR55XX_FS_STATES_OTP_CORRUPT_MASK16 == (uint16)(u16RegStatesValue & PMIC_VR55XX_FS_STATES_OTP_CORRUPT_MASK16))
        {
            eInternalStatus |= PMIC_E_CORRUPTED;
        }

        /* (M_FLAG[TSD_BIST_ERR_FLG] = 1) ?*/
        if (PMIC_VR55XX_M_FLAG_TSD_BIST_ERR_G_MASK16 == (uint16)(u16RegFlagValue & PMIC_VR55XX_M_FLAG_TSD_BIST_ERR_G_MASK16))
        {
            eInternalStatus |= PMIC_E_CORRUPTED;
        }

        if (PMIC_E_OK == eInternalStatus)
        {
            eInternalStatus |= Pmic_VR55XX_InitFailSafeUnit(u32DeviceId);
        }
    }

    return eInternalStatus;
}

#if (STD_ON == PMIC_OTP_EMULATION_MODE_API)
/*!
* @brief Pmic_VR55XX_EmulateDeviceOTP.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_EmulateDeviceOTP(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    const Pmic_VR55XX_OtpConfigType * pOtpConfig = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pHwDeviceConfig->Pmic_Ipw_pVR55XXHwDeviceConfig->pDeviceOtpConfig;
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint8 u8Counter;

    /* Enter Debug Mode */
    eInternalStatus |= Pmic_VR55XX_TimeoutWait_DebugMode(u32DeviceId, PMIC_VR55XX_MODE_ENTRY);
    if (PMIC_E_OK == eInternalStatus)
    {
        /* Initiate the Main - OTP Registers */
        /* Enter Main Test Mode */
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MEMORY0_ADDR8, 0u);

        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_ENTRY_ADDR8, PMIC_VR55XX_M_TM_ENTRY_KEY1_U16);
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_ENTRY_ADDR8, PMIC_VR55XX_M_TM_ENTRY_KEY2_U16);
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_ENTRY_ADDR8, PMIC_VR55XX_M_TM_ENTRY_KEY3_U16);
        Pmic_abTestMode[u32DeviceId] = TRUE;

        eInternalStatus |= Pmic_VR55XX_TimeoutWait_MainTestMode(u32DeviceId, PMIC_VR55XX_MODE_ENTRY);
        if (PMIC_E_OK == eInternalStatus)
        {
            /* Write data to registers */
            for (u8Counter = 0U; u8Counter < pOtpConfig->u8NoOfOtpMainRegister; ++u8Counter)
            {
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MIRRORDATA_ADDR8, (uint16)((*pOtpConfig->paOtpMainConfig)[u8Counter].u8RegisterData));
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MIRRORCMD_ADDR8, (uint16)(PMIC_VR55XX_M_MIRRORCMD_WRITE_MASK16 | (uint16)((*pOtpConfig->paOtpMainConfig)[u8Counter].u8RegisterAddr)));
            }

            /* Generate the CRC. The signature will be checked later in Pmic_InitDevice through the OTP_CORRUPT bit */
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_OTPCMD_ADDR8, PMIC_VR55XX_M_OTPCMD_CRC_GENERATE_KEY_U16);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_OTPCMD_ADDR8, PMIC_VR55XX_M_OTPCMD_CRC_CHECK_KEY_U16);

            /* Exit Main Test Mode by writing the dummy value to M_TM_ENTRY register */
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TM_ENTRY_ADDR8, PMIC_VR55XX_M_TM_ENTRY_KEY1_U16);
            Pmic_abTestMode[u32DeviceId] = FALSE;

            eInternalStatus |= Pmic_VR55XX_TimeoutWait_MainTestMode(u32DeviceId, PMIC_VR55XX_MODE_EXIT);

            /* Initiate the Fail-Safe - OTP Registers */
            /* Enter Fail-Safe Test Mode */
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_TM_ENTRY_ADDR8, PMIC_VR55XX_FS_TM_ENTRY_KEY1_U16);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_TM_ENTRY_ADDR8, PMIC_VR55XX_FS_TM_ENTRY_KEY2_U16);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_TM_ENTRY_ADDR8, PMIC_VR55XX_FS_TM_ENTRY_KEY3_U16);
            Pmic_abTestMode[u32DeviceId] = TRUE;

            eInternalStatus |= Pmic_VR55XX_TimeoutWait_FailSafeTestMode(u32DeviceId, PMIC_VR55XX_MODE_ENTRY);
            if (PMIC_E_OK == eInternalStatus)
            {
                /* Write data to registers */
                for (u8Counter = 0U; u8Counter < pOtpConfig->u8NoOfOtpFailSafeRegister; ++u8Counter)
                {
                    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId,PMIC_FAIL_SAFE_UNIT,PMIC_VR55XX_FS_MIRRORDATA_ADDR8,(uint16)((*pOtpConfig->paOtpFailSafeConfig)[u8Counter].u8RegisterData));
                    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId,PMIC_FAIL_SAFE_UNIT,PMIC_VR55XX_FS_MIRRORCMD_ADDR8,(uint16)(PMIC_VR55XX_FS_MIRRORCMD_WRITE_MASK16 | (uint16)((*pOtpConfig->paOtpFailSafeConfig)[u8Counter].u8RegisterAddr)));

                }

                /* Generate the CRC. The signature will be checked later in Pmic_InitDevice through the OTP_CORRUPT bit */
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OTPCMD_ADDR8, PMIC_VR55XX_FS_OTPCMD_CRC_GENERATE_KEY_U16);
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OTPCMD_ADDR8, PMIC_VR55XX_FS_OTPCMD_CRC_CHECK_KEY_U16);

                /* Exit Fail-Safe Test Mode by writing dummy value to FS_TM_ENTRY register */
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_TM_ENTRY_ADDR8, PMIC_VR55XX_FS_TM_ENTRY_KEY1_U16);
                Pmic_abTestMode[u32DeviceId] = FALSE;

                eInternalStatus |= Pmic_VR55XX_TimeoutWait_FailSafeTestMode(u32DeviceId, PMIC_VR55XX_MODE_EXIT);
            }
        }
    }

    return eInternalStatus;
}
#endif /* (STD_ON == PMIC_OTP_EMULATION_MODE_API) */

/*!
* @brief Pmic_VR55XX_InitClock.
*
*
* @param[in] u32DeviceId.
* @param[in] u32ClockSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_InitClock(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ClockSettingIndexType u32ClockSettingID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16MainClockReg1     = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paClockConfig)[u32ClockSettingID].Pmic_Ipw_pVR55XXClockConfig->u16MainClockReg1;
    uint16 u16MainClockReg2     = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paClockConfig)[u32ClockSettingID].Pmic_Ipw_pVR55XXClockConfig->u16MainClockReg2;
    boolean bExternalFinIsEnable = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paClockConfig)[u32ClockSettingID].Pmic_Ipw_pVR55XXClockConfig->bExternalFinIsEnable;
    uint16 DesiredOscFreq    = (uint16)(u16MainClockReg1 & PMIC_VR55XX_M_CLOCK1_CLK_INT_FREQ_MASK16);
    uint16 u16ModeReg = 0U;

    eInternalStatus |= Pmic_VR55XX_ConfigureOscillatorFrequency(u32DeviceId, DesiredOscFreq);

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, &u16ModeReg);

    if (PMIC_E_OK == eInternalStatus)
    {
        if (
             (TRUE == bExternalFinIsEnable) &&
             (PMIC_VR55XX_M_CLOCK1_EXT_FIN_SEL_MASK16 == (u16MainClockReg1 & PMIC_VR55XX_M_CLOCK1_EXT_FIN_SEL_MASK16))
           )
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, (uint16)(u16ModeReg & (uint16)(~PMIC_VR55XX_M_MODE_EXT_FIN_DIS_MASK16)));
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, (uint16)(u16MainClockReg1 & (uint16)(~PMIC_VR55XX_M_CLOCK1_EXT_FIN_SEL_MASK16)));
        }
        else
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, (uint16)(u16ModeReg | PMIC_VR55XX_M_MODE_EXT_FIN_DIS_MASK16));
        }

        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK1_ADDR8, u16MainClockReg1);
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CLOCK2_ADDR8, u16MainClockReg2);
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_SetMode.
*
*
* @param[in] u32DeviceId.
* @param[in] u32ModeSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetMode(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ModeIndexType u32ModeSettingID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    const Pmic_VR55XX_ModeConfigType * pModeConfig = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paModeConfig)[u32ModeSettingID].Pmic_Ipw_pVR55XXModeConfig;
    const Pmic_VR55XX_OtpConfigType * pOtpRegisterConfig = (*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].pHwDeviceConfig->Pmic_Ipw_pVR55XXHwDeviceConfig->pDeviceOtpConfig;
    uint16 u16RegValue = 0U;

    switch (pModeConfig->ePowerMode)
    {
        case PMIC_NORMAL_MODE:
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, pModeConfig->u16MainModeReg);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL1_ADDR8, pModeConfig->u16MainControlReg1);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL2_ADDR8, pModeConfig->u16MainControlReg2);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL3_ADDR8, pModeConfig->u16MainControlReg3);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_VMON_REGX_ADDR8, pModeConfig->u16MainVmonReg);
            break;
        }

        case PMIC_RESET_MODE:
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, pModeConfig->u16MainModeReg);
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8,(uint16)((uint16)(u16RegValue & \
                                                            PMIC_VR55XX_FS_SAFE_IOS_W_BITS_MASK16) | PMIC_VR55XX_FS_SAFE_IOS_RST_REQ_MASK16));
            break;
        }

        case PMIC_SHUTDOWN_MODE:
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, pModeConfig->u16MainModeReg);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_SM_CTRL1_ADDR8, (uint16)((pModeConfig->u16MainStateMachineReg) | \
                                                            PMIC_VR55XX_M_SM_CTRL1_GOTO_OFF_MASK16));
            break;
        }

        case PMIC_STANDBY_MODE:
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, pModeConfig->u16MainModeReg);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_SM_CTRL1_ADDR8, pModeConfig->u16MainStateMachineReg);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL1_ADDR8, pModeConfig->u16MainControlReg1);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL2_ADDR8, pModeConfig->u16MainControlReg2);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_REG_CTRL3_ADDR8, pModeConfig->u16MainControlReg3);
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_LVB1_STBY_DVS_ADDR8, pModeConfig->u16MainLvb1StbyDsvReg);

            if (
                    PMIC_VR55XX_CFG_2_OTP_STBY_SAFE_DIS_OTP_MASK8 != (PMIC_VR55XX_CFG_2_OTP_STBY_SAFE_DIS_OTP_MASK8 & \
                    (*pOtpRegisterConfig->paOtpFailSafeConfig)[PMIC_VR55XX_FS_GET_OTP_REG_INDEX_U8(PMIC_VR55XX_FS_CFG_2_OTP_ADDR8)].u8RegisterData)
                )
            {
                eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8,(uint16)((uint16)(u16RegValue & \
                                                                PMIC_VR55XX_FS_SAFE_IOS_W_BITS_MASK16) | PMIC_VR55XX_FS_SAFE_IOS_STBY_REQ_MASK16));
            }

            break;
        }

        case PMIC_DEEPSLEEP_MODE:
        {
            eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, pModeConfig->u16MainModeReg);
            break;
        }

        default:
        {
            /* Default case - should never enter here. */
            break;
        }
    }

    /* Wait for the PMIC to transition into the selected mode */
    if (PMIC_E_OK == eInternalStatus)
    {
        if ((PMIC_RESET_MODE == pModeConfig->ePowerMode) || (PMIC_SHUTDOWN_MODE == pModeConfig->ePowerMode))
        {
            eInternalStatus |= Pmic_VR55XX_TimeoutWait(u32DeviceId);
        }
    }

    return eInternalStatus;
}

#if (STD_ON == PMIC_WATCHDOG_API)
/*!
* @brief Pmic_VR55XX_ConfigureWatchdog.
*
*
* @param[in] u32DeviceId.
* @param[in] u32WatchdogSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_ConfigureWatchdog(const Pmic_DeviceIndexType u32DeviceId, const Pmic_WatchdogSettingIndexType u32WatchdogSettingID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16WatchdogWindowReg = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paWatchdogConfig)[u32WatchdogSettingID].Pmic_Ipw_pVR55XXWatchdogConfig->u16WatchdogWindowReg;

    eInternalStatus  = Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, u16WatchdogWindowReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_NOT_WD_WINDOW_DUR_ADDR8, (uint16)(~u16WatchdogWindowReg));

#if (PMIC_EXTERNAL_WATCHDOG_API == STD_OFF)
    if (NULL_PTR != Pmic_pConfigStruct->Pmic_pWdgTaskNotification)
    {
        Pmic_pConfigStruct->Pmic_pWdgTaskNotification(u32DeviceId, PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16WatchdogWindowReg), PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_VALUE_U16(u16WatchdogWindowReg));
    }
#endif

    return eInternalStatus;
}
#endif

#if (STD_ON == PMIC_SET_ANALOG_MUX_API)
/*!
* @brief Pmic_VR55XX_SetAnalogMux.
*
*
* @param[in] u32DeviceId.
* @param[in] u32AmuxChannelID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetAnalogMux(const Pmic_DeviceIndexType u32DeviceId, const Pmic_AmuxChannelIndexType u32AmuxChannelID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    uint16 u16MainAmuxReg = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paAmuxChannelConfig)[u32AmuxChannelID].Pmic_Ipw_pVR55XXAmuxChannelConfig->u16MainAmuxReg;

    return Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_AMUX_ADDR8, u16MainAmuxReg);
}
#endif

/*!
* @brief Pmic_VR55XX_GetRawFaultEvents.
*
*
* @param[in] u32DeviceId.
* @param[out] pRawFaultEventsOut_VR55XX.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GetRawFaultEvents(const Pmic_DeviceIndexType u32DeviceId, Pmic_VR55XX_RawFaultType * pRawFaultEventsOut_VR55XX)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(pRawFaultEventsOut_VR55XX != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipGeneralFlagsReg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16GeneralFlagsReg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipFlags1Reg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG1_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16Flags1Reg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipFlags2Reg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG2_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16Flags2Reg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipFlags3Reg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16Flags3Reg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipGlobalFlagsReg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_GRL_FLAGS_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16GlobalFlagsReg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipVoltageStatusReg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16VoltageStatusReg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipSafeInputStatusReg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16SafeInputsStatusReg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipDiagnosticSafetyReg)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u16DiagnosticSafetyReg = u16RegValue;
    }

    if (FALSE == pRawFaultEventsOut_VR55XX->bSkipFaultErrorCounter)
    {
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_FSSM_ADDR8, &u16RegValue);
        pRawFaultEventsOut_VR55XX->u8FaultErrorCounter = (uint8)PMIC_VR55XX_FS_I_FSSM_FLT_ERR_CNT_VALUE_U16(u16RegValue);
    }

    return eInternalStatus;
}

/*!
* @brief Pmic_VR55XX_SetReactions.
*
*
* @param[in] u32DeviceId.
* @param[in] u32ReactionSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SetReactions(const Pmic_DeviceIndexType u32DeviceId, const Pmic_ReactionSettingIndexType u32ReactionSettingID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 MainInterruptMaskReg1  = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paReactionConfig)[u32ReactionSettingID].Pmic_Ipw_pVR55XXReactionConfig->u16MainInterruptMaskReg1;
    uint16 MainInterruptMaskReg2  = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paReactionConfig)[u32ReactionSettingID].Pmic_Ipw_pVR55XXReactionConfig->u16MainInterruptMaskReg2;
    uint16 MainThermalShutdownReg = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paReactionConfig)[u32ReactionSettingID].Pmic_Ipw_pVR55XXReactionConfig->u16MainThermalShutdownReg;
    uint16 FailSafeIntReg         = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paReactionConfig)[u32ReactionSettingID].Pmic_Ipw_pVR55XXReactionConfig->u16FailSafeInterruptMaskReg;

    eInternalStatus  = Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_INT_MASK1_ADDR8, MainInterruptMaskReg1);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_INT_MASK2_ADDR8, MainInterruptMaskReg2);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_TSD_CFG_ADDR8, MainThermalShutdownReg);
    eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_INTB_MASK_ADDR8, FailSafeIntReg);

    return eInternalStatus;
}

#if (STD_ON == PMIC_DEVICE_INFO_API)
/*!
* @brief Pmic_VR55XX_GetDeviceInfo.
*
*
* @param[in] u32DeviceId.
* @param[in] pDeviceInfoOut.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GetDeviceInfo(const Pmic_DeviceIndexType u32DeviceId, Pmic_VR55XX_DeviceInfoType * pDeviceInfoOut)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(pDeviceInfoOut != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16DeviceIdReg = 0U;

    eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_MAIN_UNIT, PMIC_VR55XX_M_DEVICEID_ADDR8, &u16DeviceIdReg);

    if (PMIC_E_OK == eInternalStatus)
    {
        pDeviceInfoOut->u8FamilyId = (uint8)PMIC_VR55XX_M_DEVICEID_FAM_ID_U16(u16DeviceIdReg);
        pDeviceInfoOut->u8DeviceId = (uint8)PMIC_VR55XX_M_DEVICEID_DEV_ID_U16(u16DeviceIdReg);
        pDeviceInfoOut->u8MetalMaskRev = (uint8)PMIC_VR55XX_M_DEVICEID_MMREV_U16(u16DeviceIdReg);
        pDeviceInfoOut->u8FullMaskRev = (uint8)PMIC_VR55XX_M_DEVICEID_FMREV_U16(u16DeviceIdReg);
    }

    return eInternalStatus;
}
#endif

#if (STD_ON == PMIC_SWITCH_SVS_API)
/*!
* @brief Pmic_VR55XX_SwitchSVS.
*
*
* @param[in] u32DeviceId.
* @param[in] u32SvsSettingID.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_SwitchSVS(const Pmic_DeviceIndexType u32DeviceId, const Pmic_SvsSettingIndexType u32SvsSettingID)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(Pmic_pConfigStruct != NULL_PTR);
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 FailsafeSvsReg = (*(*Pmic_pConfigStruct->Pmic_paDeviceConfig)[u32DeviceId].paSVSConfig)[u32SvsSettingID].Pmic_Ipw_pVR55XXSVSConfig->u16FailsafeSvsReg;
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
    uint16 u16RegValue = 0U;
#endif

#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    uint32 u32OcotpData = 0U;
    boolean bDieprocessEnable = FALSE;

    if ((Std_ReturnType)E_OK == Pmic_VR55XX_Ocotp_ReadShadowRegister(PMIC_OCOTP_ISTANCE, Pmic_pConfigStruct->Pmic_u32DiePreocessOcotpIndex, &u32OcotpData))
    {
        if (0U != (u32OcotpData & PMIC_OCOTP_DIE_PROCESS_MASK))
        {
            bDieprocessEnable = TRUE;
        }
    }

    if (TRUE == bDieprocessEnable)
    {
#endif
        /* Switch Back InitFs before configure SVS */
        eInternalStatus |= Pmic_VR55XX_GotoInitFS(u32DeviceId);

        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_SVS_ADDR8, FailsafeSvsReg);
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_I_NOT_SVS_ADDR8, (uint16)(~(FailsafeSvsReg)));

        /* If watchdog monitoring is disabled by OTP, the FSU state machine will remain in INIT_FS. */
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
        Pmic_abGateWdgTrigger[u32DeviceId] =  FALSE;

        /* Service watchdog one time to transition from "INIT_FS" to "WAIT_ABIST2" state*/
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_WD_WINDOW_DUR_ADDR8, &u16RegValue);
        if (PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_DISABLE_SELECT_U16 == PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue))
        {
            eInternalStatus |= Pmic_VR55XX_TriggerWatchdog(u32DeviceId);
        }
#if (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API)
        else
        {
            /* There is no external watchdog driver. Notify upper layer to start the triggering task */
            if (NULL_PTR != Pmic_pConfigStruct->Pmic_pWdgTaskNotification)
            {
                Pmic_pConfigStruct->Pmic_pWdgTaskNotification(u32DeviceId, PMIC_VR55XX_FS_WD_WINDOW_DUR_WD_WINDOW_VALUE_U16(u16RegValue), PMIC_VR55XX_FS_WD_WINDOW_DUR_WDW_DC_VALUE_U16(u16RegValue));
            }
        }
#endif /* (STD_OFF == PMIC_EXTERNAL_WATCHDOG_API) */

        /* Busy-wait until FS_STATES[FSM_STATES] = ABIST2 (or Higher) */
        eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ABIST2_U16);

        /* Busy-wait until FS_STATES[FSM_STATES] = ASSERT_FS0B (or Higher) */
        eInternalStatus |= Pmic_VR55XX_TimeoutWait_StateTransition(u32DeviceId, PMIC_VR55XX_FS_STATES_FSM_STATES_ASSERT_FS0B_U16);

        /* (FS_STATES[REG_CORRUPT] != 0)? */
        if (PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16 == (uint16)(Pmic_au16FsState[u32DeviceId] & PMIC_VR55XX_FS_STATES_REG_CORRUPT_MASK16))
        {
            eInternalStatus |= PMIC_E_CORRUPTED;
        }
        else
        {
            eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, &u16RegValue);
            /* (FS_DIAG_SAFETY[LBIST_BYPASSED] != 0)? */
            /* (FS_DIAG_SAFETY[LBIST_DONE] = 1) and (FS_DIAG_SAFETY[LBIST_PASS] = 1) and (FS_DIAG_SAFETY[ABIST2_OK] = 1)? */
            if
            (
                (PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16 != (uint16)(u16RegValue & PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_BYPASSED_MASK16)) &&
                ((uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16) !=
                (uint16)(u16RegValue & (uint16)(PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_PASS_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_LBIST_DONE_MASK16 | PMIC_VR55XX_FS_DIAG_SAFETY_ABIST2_OK_MASK16)))
            )
            {
                eInternalStatus |= PMIC_E_CORRUPTED;
            }
            else
            {
                /* Clear all the flags in FS_GRL_FLAGS by clearing FS_DIAG_SAFETY and FS_OVUVREG_STATUS */
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_DIAG_SAFETY_ADDR8, PMIC_VR55XX_FS_DIAG_SAFETY_RWBITS_MASK32);
                eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_OVUVREG_STATUS_ADDR8, PMIC_VR55XX_FS_OVUVREG_STATUS_RWBITS_MASK32);

                eInternalStatus |= Pmic_VR55XX_ClearFault(u32DeviceId);

                eInternalStatus |= Pmic_VR55XX_ExecuteReleaseFs0b(u32DeviceId);
            }
        }

#endif /* STD_ON == PMIC_WATCHDOG_ENABLED */
#if (STD_ON == PMIC_DIE_PROCESS_ENABLE)
    }
#endif

    return eInternalStatus;
}

#endif /* STD_ON == PMIC_SWITCH_SVS_API) */

/*!
* @brief Pmic_VR55XX_GotoInitFS.
*
*
* @param[in] u32DeviceId.
*
* @return Pmic_ReturnType.
*/
Pmic_ReturnType Pmic_VR55XX_GotoInitFS(const Pmic_DeviceIndexType u32DeviceId)
{
#ifdef PMIC_IP_DEV_ERROR_DETECT
#if (STD_ON == PMIC_IP_DEV_ERROR_DETECT)
    DevAssert(PMIC_MAX_DEVICECONFIGS > u32DeviceId);
#endif
#endif
    Pmic_ReturnType eInternalStatus = PMIC_E_OK;
    uint16 u16RegValue = 0U;
#if (STD_ON == PMIC_WATCHDOG_ENABLED)
        Pmic_abGateWdgTrigger[u32DeviceId] =  TRUE;
#endif
        /* Must back to failsafe init state before driver re-configure SVS */
        eInternalStatus |= Pmic_VR55XX_I2C_ReadRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, &u16RegValue);
        u16RegValue |= PMIC_VR55XX_FS_SAFE_IOS_GOTO_INITFS_MASK16;
        eInternalStatus |= Pmic_VR55XX_I2C_WriteRegister(u32DeviceId, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_SAFE_IOS_ADDR8, u16RegValue);
        /* wait failsafe sate back to InitFs */
        eInternalStatus |= Pmic_VR55XX_TimeWaitInitFS(u32DeviceId);

    return eInternalStatus;
}

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
