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
#include "OsIf.h"
#include "I2c_Ip_HwAccess.h"
#include "I2c_Ip.h"

#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
    #include "Dma_Ip.h"
#endif /* (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE) */

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == I2C_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IP_VENDOR_ID_C                      43
#define I2C_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define I2C_IP_AR_RELEASE_MINOR_VERSION_C       4
#define I2C_IP_AR_RELEASE_REVISION_VERSION_C    0
#define I2C_IP_SW_MAJOR_VERSION_C               4
#define I2C_IP_SW_MINOR_VERSION_C               0
#define I2C_IP_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((I2C_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_IP_AR_RELEASE_MINOR_VERSION_C  != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of OsIf.h and I2c_Ip.c are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/* Check if current file and I2c_Ip_HwAccess.h header file are of the same vendor */
#if (I2C_IP_VENDOR_ID_C != I2C_IP_HWACCESS_VENDOR_ID)
    #error "I2c_Ip.c and I2c_Ip_HwAccess.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip_HwAccess.h header file are of the same Autosar version */
#if ((I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != I2C_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_AR_RELEASE_MINOR_VERSION_C    != I2C_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_AR_RELEASE_REVISION_VERSION_C != I2C_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip.c and I2c_Ip_HwAccess.h are different"
#endif
/* Check if current file and I2c_Ip_HwAccess.h header file are of the same Software version */
#if ((I2C_IP_SW_MAJOR_VERSION_C != I2C_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (I2C_IP_SW_MINOR_VERSION_C != I2C_IP_HWACCESS_SW_MINOR_VERSION) || \
     (I2C_IP_SW_PATCH_VERSION_C != I2C_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip.c and I2c_Ip_HwAccess.h are different"
#endif
/* Check if current file and I2c_Ip.h header file are of the same vendor */
#if (I2C_IP_VENDOR_ID_C != I2C_IP_VENDOR_ID)
    #error "I2c_Ip.c and I2c_Ip.h have different vendor ids"
#endif
/* Check if current file and I2c_Ip.h header file are of the same Autosar version */
#if ((I2C_IP_AR_RELEASE_MAJOR_VERSION_C    != I2C_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IP_AR_RELEASE_MINOR_VERSION_C    != I2C_IP_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IP_AR_RELEASE_REVISION_VERSION_C != I2C_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of I2c_Ip.c and I2c_Ip.h are different"
#endif
/* Check if current file and I2c_Ip.h header file are of the same Software version */
#if ((I2C_IP_SW_MAJOR_VERSION_C != I2C_IP_SW_MAJOR_VERSION) || \
     (I2C_IP_SW_MINOR_VERSION_C != I2C_IP_SW_MINOR_VERSION) || \
     (I2C_IP_SW_PATCH_VERSION_C != I2C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ip.c and I2c_Ip.h are different"
#endif
#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((I2C_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (I2C_IP_AR_RELEASE_MINOR_VERSION_C  != DMA_IP_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Dma_Ip.h and I2c_Ip.c are different"
        #endif
        #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* I2C_IP_DMA_FEATURE_AVAILABLE */

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Devassert header file are of the same Autosar version */
        #if ((I2C_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (I2C_IP_AR_RELEASE_MINOR_VERSION_C  != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Devassert.h and I2c_Ip.c are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* I2C_IP_DEV_ERROR_DETECT */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define I2C_IP_DUMMY_BYTE                     (0xFFU)
#define I2C_DMA_CHANNEL_CONFIG_LIST_SIZE      (10U)
#define I2C_DMA_GLOBAL_CONFIG_LIST_SIZE       (2U)
#if (2U == I2C_INSTANCE_COUNT)
    #define I2C_CONFIGURATION_POINTERS_INIT   {NULL_PTR,NULL_PTR}
#else
    #define I2C_CONFIGURATION_POINTERS_INIT   {NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR}
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#define I2C_START_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

/* Table of base addresses for I2C instances. */
static I2C_Type * const I2c_Ip_apBase[I2C_INSTANCE_COUNT] = IP_I2C_BASE_PTRS;

#define I2C_STOP_SEC_CONST_UNSPECIFIED
#include "I2c_MemMap.h"

/* Master state structure array */
#if(I2C_IP_NUMBER_OF_MASTER_INSTANCES != 0U)

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

I2c_Ip_MasterStateType I2c_Ip_aMasterState[I2C_IP_NUMBER_OF_MASTER_INSTANCES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#endif

/* Slave state structure array */
#if(I2C_IP_NUMBER_OF_SLAVE_INSTANCES != 0U)

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

I2c_Ip_SlaveStateType I2c_Ip_aSlaveState[I2C_IP_NUMBER_OF_SLAVE_INSTANCES];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#endif

#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

/* Pointer to runtime state structure.*/
static I2c_Ip_MasterStateType* I2c_Ip_apMasterStatePtr[I2C_INSTANCE_COUNT] = I2C_CONFIGURATION_POINTERS_INIT;
static I2c_Ip_SlaveStateType* I2c_Ip_apSlaveStatePtr[I2C_INSTANCE_COUNT] = I2C_CONFIGURATION_POINTERS_INIT;

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)

#define I2C_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

/* Structures for configuration the DMA channel */
static Dma_Ip_LogicChannelTransferListType I2c_Ip_aDmaChannelTransferListReceive[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE];
static Dma_Ip_LogicChannelTransferListType I2c_Ip_aDmaChannelTransferListSend[I2C_DMA_CHANNEL_CONFIG_LIST_SIZE];

#define I2C_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2c_MemMap.h"

#endif /* I2C_IP_DMA_FEATURE_AVAILABLE */
/*******************************************************************************
 * Global Functions
 ******************************************************************************/ 
#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
void I2c_Ip_MasterCompleteDMATransfer(uint8 Instance);
#if (STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
void I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance);
#endif /* I2C_IP_DMA_TRANSFER_ERROR_DETECT */
#endif /* I2C_IP_DMA_FEATURE_AVAILABLE */

/**
* @note put all I2C code into defined section
*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"


#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
/* Master Start DMA transfer */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void I2c_Ip_MasterStartDmaTransfer(uint8 Instance);
#endif /* I2C_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterSetBaudRate
 * Description   : set the master baudRate
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterSetBaudRate_Privileged(uint8 Instance,
                                                      uint8 PrescaledShift,
                                                      uint8 PrescalerDivider,
                                                      uint8 ShiftTapPoint)
{
    I2C_Type *BaseAddr;
    uint8 ValReg;
    BaseAddr = I2c_Ip_apBase[Instance];

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(PrescaledShift < 3U);
    DevAssert(PrescalerDivider < 8U);
    DevAssert(ShiftTapPoint < 8U);
#endif

    /* Calculate value of IBFD register f */
    ValReg = (uint8)((PrescaledShift << I2C_PRESCALED_SHIFT_SHIFT) | (PrescalerDivider << I2C_PRESCALER_DIVIDER_SHIFT) | (ShiftTapPoint));

    BaseAddr->IBFD = (uint8)ValReg;

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterGetBaudRate
 * Description   : Get the master baudRate
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterGetBaudRate(uint8 Instance,
                                           uint32 InputClock,
                                           uint32 *BaudRate)
{

    uint8 ValReg;
    uint8 PrescaledShift;
    uint8 PrescalerDivider;
    uint8 ShiftTapPoint;
    uint32 Divider;
    const I2C_Type *BaseAddr;
    const I2c_Ip_MasterStateType *MasterState;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(InputClock > 0U);
#endif

    MasterState = I2c_Ip_apMasterStatePtr[Instance];
    BaseAddr = I2c_Ip_apBase[Instance];

    ValReg = BaseAddr->IBFD;

    /* Table of SCL2TAP values */
    const uint8 I2cScl2Tap[I2C_DIVIDER_ARRAY_SIZE] = I2C_SCL2TAP_ARRAY;
    /* Table of SCL2TAP values when glitch filter is enabled */
    const uint8 I2cScl2TapGlitch[I2C_DIVIDER_ARRAY_SIZE] = I2C_SCL2TAP_GLITCH_ARRAY;
    /* Table of SCLTAP values */
    const uint8 I2cSclTap[I2C_DIVIDER_ARRAY_SIZE] = I2C_SCLTAP_ARRAY;
    /* Table of TAP2TAP values */
    const uint8 I2cTap2Tap[I2C_DIVIDER_ARRAY_SIZE] = I2C_TAP2TAP_ARRAY;
    /* Table of MUL values */
    const uint8 I2cMul[I2C_MUL_ARRAY_SIZE] = I2C_MUL_ARRAY;

    PrescaledShift =  (uint8)(ValReg >> I2C_PRESCALED_SHIFT_SHIFT);
    PrescalerDivider = (uint8)((ValReg & I2C_PRESCALER_DIVIDER_MASK) >> I2C_PRESCALER_DIVIDER_SHIFT);
    ShiftTapPoint = (uint8)(ValReg & I2C_SHIFT_TAP_POINT_MASK);

    if(MasterState->GlitchFilter)
    {
        /* Calculate formula for divider = mul * (2 * (scl2tap + ((scltap - 1) * tap2tap) + 2)) */
        Divider = (uint32)I2cMul[PrescaledShift] * (2U * ((uint32)I2cScl2Tap[PrescalerDivider] + (((uint32)I2cSclTap[ShiftTapPoint] - 1U) * (uint32)I2cTap2Tap[PrescalerDivider]) + 2U));
    }
    else
    {
        /* Calculate formula for divider = mul * (2 * (scl2tap + ((scltap - 1) * tap2tap) + 2)) */
        Divider = (uint32)I2cMul[PrescaledShift] * (2U * ((uint32)I2cScl2TapGlitch[PrescalerDivider] + (((uint32)I2cSclTap[ShiftTapPoint] - 1U) * (uint32)I2cTap2Tap[PrescalerDivider]) + 2U));
    }

    *BaudRate = (uint32)(InputClock/Divider);

    return I2C_IP_SUCCESS_STATUS;
}

#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_CmdDmaTcdInit
 * Description   : This function configures the TCD for I2C DMA transfers
 *
 *END**************************************************************************/
static void I2c_Ip_CmdDmaTcdInit(void)
{

    /* Configure DMA channel for send transfers */
    /* Source  configuration parameters  */
    I2c_Ip_aDmaChannelTransferListSend[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    I2c_Ip_aDmaChannelTransferListSend[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    I2c_Ip_aDmaChannelTransferListSend[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    /* Destination configuration parameters */
    I2c_Ip_aDmaChannelTransferListSend[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    I2c_Ip_aDmaChannelTransferListSend[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    I2c_Ip_aDmaChannelTransferListSend[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    /* Minor/Major Loop parameters */
    I2c_Ip_aDmaChannelTransferListSend[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    I2c_Ip_aDmaChannelTransferListSend[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    /* Disable Hw auto request and enable interrupts */
    I2c_Ip_aDmaChannelTransferListSend[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    I2c_Ip_aDmaChannelTransferListSend[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    /* Source  configuration values */
    I2c_Ip_aDmaChannelTransferListSend[1u].Value = 1U;
    I2c_Ip_aDmaChannelTransferListSend[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Destination configuration values */
    I2c_Ip_aDmaChannelTransferListSend[4u].Value = 0U;
    I2c_Ip_aDmaChannelTransferListSend[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Minor/Major Loop values */
    I2c_Ip_aDmaChannelTransferListSend[6u].Value = 1U;
    /* Disable Hw auto request and enable interrupts */
    I2c_Ip_aDmaChannelTransferListSend[8u].Value = 1U;
    I2c_Ip_aDmaChannelTransferListSend[9u].Value = 1U;

    /* Configure DMA channel for receive transfers*/
    /* Source  configuration parameters  */
    I2c_Ip_aDmaChannelTransferListReceive[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    I2c_Ip_aDmaChannelTransferListReceive[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    I2c_Ip_aDmaChannelTransferListReceive[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    /* Destination configuration parameters  */
    I2c_Ip_aDmaChannelTransferListReceive[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    I2c_Ip_aDmaChannelTransferListReceive[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    I2c_Ip_aDmaChannelTransferListReceive[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    /* Minor/Major Loop parameters */
    I2c_Ip_aDmaChannelTransferListReceive[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    I2c_Ip_aDmaChannelTransferListReceive[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    /* Disable Hw auto request and enable interrupts */
    I2c_Ip_aDmaChannelTransferListReceive[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    I2c_Ip_aDmaChannelTransferListReceive[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    /* Source  configuration values */
    I2c_Ip_aDmaChannelTransferListReceive[1u].Value = 0U;
    I2c_Ip_aDmaChannelTransferListReceive[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Destination configuration values */
    I2c_Ip_aDmaChannelTransferListReceive[4u].Value = 1U;
    I2c_Ip_aDmaChannelTransferListReceive[5u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;
    /* Minor/Major Loop values */
    I2c_Ip_aDmaChannelTransferListReceive[6u].Value = 1U;
    /* Disable Hw auto request and enable interrupts */
    I2c_Ip_aDmaChannelTransferListReceive[8u].Value = 1U;
    I2c_Ip_aDmaChannelTransferListReceive[9u].Value = 1U;
}
#endif /* STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterInit
 * Description   : initialize the I2C master mode driver
 *
 *END**************************************************************************/
 I2c_Ip_StatusType I2c_Ip_MasterInit_Privileged(uint8 Instance,
                                                const I2c_Ip_MasterConfigType * UserConfigPtr)
{
    I2C_Type *BaseAddr;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(UserConfigPtr != NULL_PTR);
    DevAssert(Instance < I2C_INSTANCE_COUNT);

    /*  Check to see if the I2C master instance is already initialized */
    DevAssert(NULL_PTR == I2c_Ip_apMasterStatePtr[Instance]);
#endif

    BaseAddr = I2c_Ip_apBase[Instance];
#if (I2C_IP_NUMBER_OF_MASTER_INSTANCES != 0U)
    I2c_Ip_apMasterStatePtr[Instance] = &I2c_Ip_aMasterState[UserConfigPtr->MasterIndex];
#endif
    I2c_Ip_MasterStateType * MasterState =  I2c_Ip_apMasterStatePtr[Instance];

    /*  Initialize driver status structure */
    MasterState->RxBuff = NULL_PTR;
    MasterState->RxSize = 0U;
    MasterState->TxBuff = NULL_PTR;
    MasterState->TxSize = 0U;
    MasterState->Status = I2C_IP_SUCCESS_STATUS;
    MasterState->I2cIdle = TRUE;
    MasterState->SlaveAddress = UserConfigPtr->SlaveAddress;
    MasterState->TransferType = UserConfigPtr->TransferType;
    MasterState->StopGenerated = TRUE;
    MasterState->GlitchFilter = UserConfigPtr->GlitchFilter;
    MasterState->Blocking = FALSE;

    /* Initialize callback and callback parameter*/
    MasterState->MasterCallback = UserConfigPtr->MasterCallback;
    MasterState->CallbackParam = UserConfigPtr->CallbackParam;

    /*  Store DMA channel number used in transfer */
    MasterState->DmaTxChannel = UserConfigPtr->DmaTxChannel;
    MasterState->DmaRxChannel = UserConfigPtr->DmaRxChannel;

#if (STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
    if(MasterState->TransferType == I2C_USING_DMA)
    {
        I2c_Ip_CmdDmaTcdInit();
    }
#endif /* STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE */

    /* Initial state */
    I2c_Ip_ResetModuleState(BaseAddr);

    /* Configure Glitch Filter */
    I2c_Ip_SetGlitchFilter(BaseAddr, MasterState->GlitchFilter);

    /* Set baud rate */
    BaseAddr->IBFD = (uint8)UserConfigPtr->BaudRate;

    I2c_Ip_SetModuleEnable(BaseAddr, TRUE);

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveInitModule
 * Description   : Enable interrupts and enable module
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveInitModule(I2C_Type *BaseAddr)
{
    /* Interrupts enabled*/
    I2c_Ip_SetBusIRQEnable(BaseAddr, TRUE);

    /* Enable I2C Module*/
    I2c_Ip_SetModuleEnable(BaseAddr, TRUE);

    /* Slave Mode */
    I2c_Ip_SetModuleModSelect(BaseAddr, I2C_SLAVE);

    /* Enable Bus idle interrupt */
    I2c_Ip_SetBusIdleIRQ(BaseAddr, TRUE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveInit
 * Description   : initialize the I2C slave mode driver
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_SlaveInit_Privileged(uint8 Instance,
                                              const I2c_Ip_SlaveConfigType * UserConfigPtr)
{
    I2C_Type *BaseAddr;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(UserConfigPtr != NULL_PTR);
    DevAssert(Instance < I2C_INSTANCE_COUNT);

    DevAssert(NULL_PTR == I2c_Ip_apSlaveStatePtr[Instance]);
#endif
    BaseAddr = I2c_Ip_apBase[Instance];
#if (I2C_IP_NUMBER_OF_SLAVE_INSTANCES != 0U)
    I2c_Ip_apSlaveStatePtr[Instance] = &I2c_Ip_aSlaveState[UserConfigPtr->SlaveIndex];
#endif
    I2c_Ip_SlaveStateType * SlaveState =  I2c_Ip_apSlaveStatePtr[Instance];

    /*  Initialize driver status structure */
    SlaveState->Status = I2C_IP_SUCCESS_STATUS;
    SlaveState->SlaveCallback = UserConfigPtr->SlaveCallback;
    SlaveState->CallbackParam = UserConfigPtr->CallbackParam;
    SlaveState->DataBuffer = NULL_PTR;
    SlaveState->BufferSize = 0U;
    SlaveState->SlaveAddress = UserConfigPtr->SlaveAddress;
    SlaveState->DataAck = TRUE;
    SlaveState->TransferInProgress = FALSE;
    SlaveState->ListeningMode = UserConfigPtr->ListeningMode;
    SlaveState->GlitchFilter = UserConfigPtr->GlitchFilter;

    /* Initial state */
    I2c_Ip_ResetModuleState(BaseAddr);

    /* Configure Glitch Filter */
    I2c_Ip_SetGlitchFilter(BaseAddr, SlaveState->GlitchFilter);

    /* Set Slave Address*/
    I2c_Ip_SetSlaveAddress(BaseAddr, SlaveState->SlaveAddress);

    /* Enable interrupts, module */
    I2c_Ip_SlaveInitModule(BaseAddr);

    /* If slave is in listening mode slave should be ready for addressing */
    if(SlaveState->ListeningMode)
    {
        SlaveState->ReadyForAddressing = TRUE;

        /* Enable Acknowledge in case slave is in listening mode */
        I2c_Ip_SetDataAcknowledge(BaseAddr, TRUE);
    }
    else
    {
        SlaveState->ReadyForAddressing = FALSE;

        /* Disable Acknowledge in case slave is in not listening mode */
        I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
    }

    /* Clear bus interrupt flag*/
    I2c_Ip_ClearBusInterruptFlag(BaseAddr);

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterSendDataEvent
 * Description   : handle a send data event for master
 *
 *END**************************************************************************/
static void I2c_Ip_MasterSendDataEvent(I2C_Type *BaseAddr,
                                       I2c_Ip_MasterStateType *MasterState)
{

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(BaseAddr != NULL_PTR);
    DevAssert(MasterState != NULL_PTR);
#endif

    I2c_Ip_SetDataIBDR(BaseAddr, MasterState->TxBuff[0U]);

    MasterState->TxBuff++;
    MasterState->TxSize--;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterGetTransferStatus
 * Description   : return the current status of the I2C master transfer
 *
 * When performing an a-sync (non-blocking) transfer, the user can call this function
 * to ascertain the state of the current transfer. In addition, if the transfer is still
 * in progress, the user can get the number of words that should be receive.
 *
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterGetTransferStatus(uint8 Instance)
{
    const I2c_Ip_MasterStateType *MasterState;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif
    MasterState = I2c_Ip_apMasterStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif
    return MasterState->Status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveGetTransferStatus
 * Description   : return the current status of the I2C master transfer
 *
 * When performing an a-sync (non-blocking) transfer, the user can call this function
 * to ascertain the state of the current transfer. In addition, if the transfer is still
 * in progress, the user can get the number of words that should be receive.
 *
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_SlaveGetTransferStatus(uint8 Instance)
{
    const I2c_Ip_SlaveStateType *MasterSlave;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif
    MasterSlave = I2c_Ip_apSlaveStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterSlave != NULL_PTR);
#endif
    return MasterSlave->Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_GenerateStopSignal
 * Description   : generates stop signal for mastre I2C module
 *
 *END**************************************************************************/
static void I2c_Ip_GenerateStopSignal(uint8 Instance)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType * MasterState;

    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    /* Check if the module is in master mode */
    if (I2c_Ip_GetModuleModSelect(BaseAddr))
    {
        /* Generate stop */
        I2c_Ip_SetModuleModSelect(BaseAddr, I2C_SLAVE);
        MasterState->StopGenerated = TRUE;
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_StartListening
 * Description   : Makes a slave channel available for processing request in case
 *                 slave is in not listening mode
 *
 *END**************************************************************************/
void I2c_Ip_StartListening(uint8 Instance)
{
    I2c_Ip_SlaveStateType * SlaveState;

    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(SlaveState != NULL_PTR);
    DevAssert(FALSE == SlaveState->ListeningMode);
#endif

    SlaveState->ReadyForAddressing = TRUE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterEndTransfer
 * Description   : ends current transmission or reception
 *
 *END**************************************************************************/
static void I2c_Ip_MasterEndTransfer(I2C_Type *BaseAddr,
                                     I2c_Ip_MasterStateType *MasterState)
{

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
    DevAssert(BaseAddr != NULL_PTR);
#endif
    /* Disable all events */
    I2c_Ip_SetBusIRQEnable(BaseAddr, FALSE);
    I2c_Ip_SetBusIdleIRQ(BaseAddr, FALSE);

    MasterState->TxBuff = NULL_PTR;
    MasterState->TxSize = 0;
    MasterState->RxBuff = NULL_PTR;
    MasterState->RxSize = 0;
    MasterState->I2cIdle = TRUE;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterTransmitAddress
 * Description   : master module sends on I-BUS the slave address and checks for
 * acknowledge
 *
 *END**************************************************************************/
static I2c_Ip_StatusType I2c_Ip_MasterTransmitAddress(uint8 Instance)
{
    uint8 Address;
    I2C_Type * BaseAddr;
    const I2c_Ip_MasterStateType * MasterState;

    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
    DevAssert(MasterState != NULL_PTR);
#endif

    /* Select master mode */
    I2c_Ip_SetModuleModSelect(BaseAddr, I2C_MASTER);

    /* Select transmit mode for master */
    I2c_Ip_SetModuleTransmitMode(BaseAddr, TRUE);

    /* Transmit address */
    Address = (uint8) ((MasterState->SlaveAddress << 1U) + (uint8) ((TRUE == (!MasterState->SendData)) ? (uint8)1U : (uint8)0U));
    I2c_Ip_SetDataIBDR(BaseAddr, Address);

    /* In case master want to receive one byte set NACK */
    if((!MasterState->SendData) && (1U == MasterState->RxSize))
    {
        /* Send NACK */
        I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
    }

    return I2C_IP_SUCCESS_STATUS;
}

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterStartDmaTransfer
 * Description   : starts the DMA transfer (only for master)
 *
 *END**************************************************************************/
static void I2c_Ip_MasterStartDmaTransfer(uint8 Instance)
{
    I2C_Type *BaseAddr = I2c_Ip_apBase[Instance];
    const I2c_Ip_MasterStateType * MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if (MasterState->SendData)
    {

        /* Set source address and major loop transfer size */
        I2c_Ip_aDmaChannelTransferListSend[0u].Value = (uint32)(&(MasterState->TxBuff[0]));
        I2c_Ip_aDmaChannelTransferListSend[3u].Value = (uint32)(&(BaseAddr->IBDR));
        I2c_Ip_aDmaChannelTransferListSend[7u].Value = MasterState->TxSize - 1U;

        (void)Dma_Ip_SetLogicChannelTransferList(MasterState->DmaTxChannel, I2c_Ip_aDmaChannelTransferListSend, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE);
        /* Start DMA channel */
        (void)Dma_Ip_SetLogicChannelCommand(MasterState->DmaTxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }
    else
    {
        /* Set destination address and major loop transfer size */
        I2c_Ip_aDmaChannelTransferListReceive[0u].Value = (uint32) (&(BaseAddr->IBDR));
        I2c_Ip_aDmaChannelTransferListReceive[3u].Value = (uint32)(&(MasterState->RxBuff[0]));
        I2c_Ip_aDmaChannelTransferListReceive[7u].Value = MasterState->RxSize - 2U;

        (void)Dma_Ip_SetLogicChannelTransferList(MasterState->DmaRxChannel, I2c_Ip_aDmaChannelTransferListReceive, I2C_DMA_CHANNEL_CONFIG_LIST_SIZE);
        /* Start DMA channel */
        (void)Dma_Ip_SetLogicChannelCommand(MasterState->DmaRxChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }

    if (MasterState->SendData)
    {
        /* Enable transmit/receive DMA request*/
        I2c_Ip_SetDMAEnable(BaseAddr, TRUE);
    }

    (void)I2c_Ip_MasterTransmitAddress(Instance);
}

#endif /* STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterSendAddress
 * Description   : Sets the 7-bit address of the slave which will be used for
 * any future transfers initiated by the I2C master.
 *
 *END**************************************************************************/
void I2c_Ip_MasterSetSlaveAddress(uint8 Instance, uint8 Address)
{
    I2c_Ip_MasterStateType * MasterState;
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    #if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
    #endif

    MasterState->SlaveAddress = Address;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterDeinit
 * Description   : de-initialize the I2C master mode driver
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterDeinit_Privileged(uint8 Instance)
{
    I2C_Type *BaseAddr;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif

    BaseAddr = I2c_Ip_apBase[Instance];

    I2c_Ip_apMasterStatePtr[Instance] = NULL_PTR;

    /* Disable master */
    I2c_Ip_SetModuleEnable(BaseAddr, FALSE);

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveDeinit
 * Description   : de-initialize the I2C slave mode driver
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_SlaveDeinit_Privileged(uint8 Instance)
{
    I2C_Type *BaseAddr;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif

    BaseAddr = I2c_Ip_apBase[Instance];

    I2c_Ip_apSlaveStatePtr[Instance] = NULL_PTR;

    /* Disable I2C slave */
    I2c_Ip_SetModuleEnable(BaseAddr, FALSE);

    /* Clear slave address */
    I2c_Ip_SetSlaveAddress(BaseAddr, 0U);

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveSetTxBuffer
 * Description   : sets the TX buffer for slave module
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_SlaveSetBuffer(uint8 Instance,
                                        uint8 *TxBuff,
                                        uint32 TxSize)
{
    I2c_Ip_SlaveStateType *SlaveState;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(SlaveState != NULL_PTR);
#endif

    SlaveState->DataBuffer = TxBuff;
    SlaveState->BufferSize = TxSize;

    return I2C_IP_SUCCESS_STATUS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterSendData
 * Description   : perform a non-blocking send transaction on the I2C bus
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterSendData_Privileged(uint8 Instance,
                                                   const uint8 *TxBuff,
                                                   uint32 TxSize,
                                                   boolean SendStop)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType *MasterState;
    I2c_Ip_StatusType ReturnStatus = I2C_IP_SUCCESS_STATUS;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif
    /* Check if driver is busy */
    if(!MasterState->I2cIdle)
    {
        ReturnStatus = I2C_IP_BUSY_STATUS;
    }

    if((MasterState->StopGenerated)&&(I2c_Ip_GetBusBusyEvent(BaseAddr))&&(I2C_IP_SUCCESS_STATUS == ReturnStatus))
    {
        /* Check if bus is busy */
        ReturnStatus = I2C_IP_BUS_BUSY_STATUS;
    }

    if(I2C_IP_SUCCESS_STATUS == ReturnStatus)
    {
        /* Copy parameters to drive state structure */
        MasterState->TxBuff = TxBuff;
        MasterState->TxSize = TxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_IP_BUSY_STATUS;
        MasterState->SendData = TRUE;
        MasterState->SendStop = SendStop;
        MasterState->Blocking = FALSE;

        /* Activate interrupts for DMA transfer*/
        I2c_Ip_SetBusIRQEnable(BaseAddr, TRUE);

        /* Activate interrupts for bus idle */
        I2c_Ip_SetBusIdleIRQ(BaseAddr, TRUE);

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
        if (I2C_USING_DMA == MasterState->TransferType)
        {
            /* Start DMA transfer */
            I2c_Ip_MasterStartDmaTransfer(Instance);
        }
        else
        {
#endif
            (void)I2c_Ip_MasterTransmitAddress(Instance);
#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
        }
#endif
    }

    return ReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceiveData
 * Description   : perform a non-blocking send transaction on the I2C bus
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterReceiveData_Privileged(uint8 Instance,
                                                      uint8 *RxBuff,
                                                      uint32 RxSize,
                                                      boolean SendStop)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType *MasterState;
    I2c_Ip_StatusType ReturnStatus = I2C_IP_SUCCESS_STATUS;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif
    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif

    /* Check if driver is busy */
    if(!MasterState->I2cIdle)
    {
        ReturnStatus = I2C_IP_BUSY_STATUS;
    }

    if((MasterState->StopGenerated)&&(I2c_Ip_GetBusBusyEvent(BaseAddr))&&(I2C_IP_SUCCESS_STATUS == ReturnStatus))
    {
        ReturnStatus = I2C_IP_BUS_BUSY_STATUS;
    }

    if(I2C_IP_SUCCESS_STATUS == ReturnStatus)
    {
        /* Copy parameters to driver state structure */
        MasterState->RxSize = RxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->RxBuff = RxBuff;
        MasterState->Status = I2C_IP_BUSY_STATUS;
        MasterState->SendData = FALSE;
        MasterState->SendStop = SendStop;
        MasterState->Blocking = FALSE;

        /* Acknowledge enabled */
        I2c_Ip_SetDataAcknowledge(BaseAddr, TRUE);

        /* Enable interrupts */
        I2c_Ip_SetBusIRQEnable(BaseAddr, TRUE);

        /* Activate interrupts for bus idle*/
        I2c_Ip_SetBusIdleIRQ(BaseAddr, TRUE);

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
        if (I2C_USING_DMA == MasterState->TransferType)
        {
            /* Start DMA transfer */
            I2c_Ip_MasterStartDmaTransfer(Instance);
        }
        else
        {
#endif
            (void)I2c_Ip_MasterTransmitAddress(Instance);
#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
        }
#endif
    }

    return ReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveStopEvent
 * Description   : performs stop for slave module
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveStopEvent(I2c_Ip_SlaveStateType *SlaveState,
                                  I2c_Ip_StatusType ModuleStatus)
{
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(SlaveState != NULL_PTR);
#endif

    SlaveState->Status = ModuleStatus;

    if (SlaveState->SlaveCallback != NULL_PTR) {

        if(I2C_IP_TX_UNDERRUN_STATUS == ModuleStatus)
        {
#if (STD_ON == I2C_IP_EVENT_ERROR_DETECT)
            SlaveState->SlaveCallback(I2C_SLAVE_EVENT_UNDERRUN, SlaveState->CallbackParam);
#endif
        }
        else if(I2C_IP_RX_OVERRUN_STATUS == ModuleStatus)
        {
#if (STD_ON == I2C_IP_EVENT_ERROR_DETECT)
            SlaveState->SlaveCallback(I2C_SLAVE_EVENT_OVERRUN, SlaveState->CallbackParam);
#endif
        }
        else
        {

            SlaveState->SlaveCallback(I2C_SLAVE_EVENT_STOP, SlaveState->CallbackParam);

        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveReceiveDataEvent
 * Description   : handle a receive data event
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveReceiveDataEvent(I2C_Type *BaseAddr,
                                         I2c_Ip_SlaveStateType *SlaveState)
{
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(BaseAddr != NULL_PTR);
    DevAssert(SlaveState != NULL_PTR);
#endif
    SlaveState->Status = I2C_IP_BUSY_STATUS;

    if (0U == SlaveState->BufferSize)
    {
        if (SlaveState->SlaveCallback != NULL_PTR)
        {
            SlaveState->SlaveCallback(I2C_SLAVE_EVENT_RX_FULL, SlaveState->CallbackParam);
        }
    }

    if (SlaveState->BufferSize > 0U)
    {
        /* Read data from IBDR and store it */
        SlaveState->DataBuffer[0U] = I2c_Ip_GetDataIBDR(BaseAddr);

        SlaveState->DataBuffer++;
        SlaveState->BufferSize--;
    }
    else
    {
        if(!SlaveState->ListeningMode)
        {
            SlaveState->ReadyForAddressing = FALSE;
            I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
        }

        /* Slave end transfer */
        I2c_Ip_SlaveStopEvent(SlaveState, I2C_IP_RX_OVERRUN_STATUS);

        /* Dummy read from IBDR */
        (void) I2c_Ip_GetDataIBDR(BaseAddr);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveSendDataEvent
 * Description   : handle a slave send data event for slave module
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveSendDataEvent(I2C_Type *BaseAddr,
                                      I2c_Ip_SlaveStateType *SlaveState)
{
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(BaseAddr != NULL_PTR);
    DevAssert(SlaveState != NULL_PTR);
#endif
    SlaveState->Status = I2C_IP_BUSY_STATUS;

    if (0U == SlaveState->BufferSize)
    {
        /* Out of data, call callback to allow user to provide a new buffer */
        if (SlaveState->SlaveCallback != NULL_PTR)
        {
            SlaveState->SlaveCallback(I2C_SLAVE_EVENT_TX_EMPTY, SlaveState->CallbackParam);
        }
    }

    if (SlaveState->BufferSize > 0U)
    {
        /* Send data to master*/
        I2c_Ip_SetDataIBDR(BaseAddr, SlaveState->DataBuffer[0U]);

        SlaveState->DataBuffer++;
        SlaveState->BufferSize--;
    }
    else
    {
        if(!SlaveState->ListeningMode)
        {
            SlaveState->ReadyForAddressing = FALSE;
            I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
        }

        /* Slave end transfer */
        I2c_Ip_SlaveStopEvent(SlaveState, I2C_IP_TX_UNDERRUN_STATUS);

        /* Transmit dummy byte */
        I2c_Ip_SetDataIBDR(BaseAddr, I2C_IP_DUMMY_BYTE);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceiveDataEvent
 * Description   : handle a receive data event for master
 *
 *END**************************************************************************/
static void I2c_Ip_MasterReceiveDataEvent(I2C_Type *BaseAddr,
                                          I2c_Ip_MasterStateType *MasterState)
{
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(BaseAddr != NULL_PTR);
    DevAssert(MasterState != NULL_PTR);
#endif
    if (MasterState->RxSize > 0U)
    {
        /* Receive data from slave and store it */
        MasterState->RxBuff[0U] = I2c_Ip_GetDataIBDR(BaseAddr);

        MasterState->RxBuff++;
        MasterState->RxSize--;
    }

    /* End transfer here in case of repeated start */
    if(0U == MasterState->RxSize)
    {
        if (MasterState->StopGenerated)
        {
            MasterState->I2cIdle = TRUE;

            if (MasterState->MasterCallback != NULL_PTR)
            {
                MasterState->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, MasterState->CallbackParam);
            }
        }
        MasterState->Status = I2C_IP_SUCCESS_STATUS;
        I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_AddressAsSlaveEvent
 * Description   : handle a address as slave event for slave I2C module
 *
 *END**************************************************************************/
static void I2c_Ip_AddressAsSlaveEvent(I2C_Type *BaseAddr,
                                       I2c_Ip_SlaveStateType *SlaveState)
{
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(BaseAddr != NULL_PTR);
#endif

    if((TRUE == SlaveState->ReadyForAddressing) || (TRUE == SlaveState->ListeningMode))
    {
        /* Check if slave is transmitting or receiving - check SRW bit */
        if (I2c_Ip_GetSlaveTransmitMode(BaseAddr))
        {
            /* Set TX Mode */
            I2c_Ip_SetModuleTransmitMode(BaseAddr, TRUE);

            /* Request from master to transmit data */
            if (SlaveState->SlaveCallback != NULL_PTR)
            {
                SlaveState->SlaveCallback(I2C_SLAVE_EVENT_TX_REQ, SlaveState->CallbackParam);
            }
            /* Write data to IBDR to clear the IAAS bit! */
            I2c_Ip_SlaveSendDataEvent(BaseAddr, SlaveState);

        }
        else
        {

            if(!SlaveState->ListeningMode)
            {
                I2c_Ip_SetDataAcknowledge(BaseAddr, TRUE);
            }

            /* Request from master to receive data */
            if (SlaveState->SlaveCallback != NULL_PTR)
            {
                SlaveState->SlaveCallback(I2C_SLAVE_EVENT_RX_REQ, SlaveState->CallbackParam);
            }

            /* Set RX Mode */
            I2c_Ip_SetModuleTransmitMode(BaseAddr, FALSE);

            /* Dummy reading */
            (void) I2c_Ip_GetDataIBDR(BaseAddr);
        }
        SlaveState->Status = I2C_IP_BUSY_STATUS;
    }
    else
    {
        /* Dummy read from IBDR */
        (void) I2c_Ip_GetDataIBDR(BaseAddr);

    }
}

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterArbitrationLostHandler
 * Description   : handle master arbitration lost event
 *
 *END**************************************************************************/
static void I2c_Ip_MasterArbitrationLostHandler(uint8 Instance)
{
    I2c_Ip_MasterStateType * MasterState;

    I2C_Type *BaseAddr;
    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    /* Clear the master arbitration lost flag */
    I2c_Ip_ClearMasterArbitrationLostFlag(BaseAddr);

    MasterState->Status = I2C_IP_ARBITRATION_LOST_STATUS;

    /* End transfer */
    I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);

    MasterState->StopGenerated = TRUE;

    if (MasterState->MasterCallback != NULL_PTR)
    {

#if (STD_ON == I2C_IP_EVENT_ERROR_DETECT)
        MasterState->MasterCallback(I2C_MASTER_EVENT_ARBITRATION_LOST, MasterState->CallbackParam);
#else
        MasterState->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, MasterState->CallbackParam);
#endif
    }

    if(I2C_USING_DMA == MasterState->TransferType)
    {
         I2c_Ip_SetDMAEnable(BaseAddr, FALSE);
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_GetBusBusyEvent
 * Description   : handle bus busy event
 *
 *END**************************************************************************/
static void I2c_Ip_BusBusyEventHandler(uint8 Instance)
{
    I2c_Ip_MasterStateType * MasterState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    /* Report success if no error was recorded */
    if (I2C_IP_BUSY_STATUS == MasterState->Status)
    {
        MasterState->Status = I2C_IP_SUCCESS_STATUS;
    }

    I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);

    if (MasterState->MasterCallback != NULL_PTR)
    {
        MasterState->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, MasterState->CallbackParam);
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveTransmitDataEvent
 * Description   : handle slave transmit data event
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveTransmitDataEvent(uint8 Instance)
{
    I2c_Ip_SlaveStateType * SlaveState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

    /* Check the acknowledge from master */
    if (I2c_Ip_GetReceivedACK(BaseAddr))
    {
        /* Transmit next byte to master */
        I2c_Ip_SlaveSendDataEvent(BaseAddr, SlaveState);
    }
    else
    {
        /* Switch to RX mode and dummy read */
        I2c_Ip_SetModuleTransmitMode(BaseAddr, FALSE);
        (void) I2c_Ip_GetDataIBDR(BaseAddr);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterArbitrationHandler
 * Description   : master arbitration handler
 *
 *END**************************************************************************/
static void I2c_Ip_MasterArbitrationHandler(uint8 Instance)
{
    const I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
    if(I2c_Ip_GetMasterArbitrationLostEvent(BaseAddr))
    {
        I2c_Ip_MasterArbitrationLostHandler(Instance);
    }
#endif
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterBusBusyHandler
 * Description   : master bus busy event handler
 *
 *END**************************************************************************/
static void I2c_Ip_MasterBusBusyHandler(uint8 Instance)
{
    const I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    const I2c_Ip_MasterStateType *MasterState;
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if(MasterState->SendData)
    {
        /* Check if bus is idle  */
        if ((!I2c_Ip_GetBusBusyEvent(BaseAddr)) && (0U == MasterState->TxSize))
        {
            I2c_Ip_BusBusyEventHandler(Instance);
        }
    }
    else
    {
        /* Check if bus is idle  */
        if ((!I2c_Ip_GetBusBusyEvent(BaseAddr)) && (0U == MasterState->RxSize))
        {
            I2c_Ip_BusBusyEventHandler(Instance);
        }
    }
}

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveArbitrationLostHandler
 * Description   : handle slave arbitration lost handler
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveArbitrationLostHandler(uint8 Instance)
{
    I2c_Ip_SlaveStateType * SlaveState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

    /* Clear the arbitration lost flag */
    I2c_Ip_ClearMasterArbitrationLostFlag(BaseAddr);

    /* Check address as slave flag */
    if (I2c_Ip_GetAddressAsSlave(BaseAddr))
    {
        /* It was an address transfer */
        I2c_Ip_AddressAsSlaveEvent(BaseAddr, SlaveState);
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveTransferHandler
 * Description   : handle slave receive/transmit event
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveTransferHandler(uint8 Instance)
{
    I2c_Ip_SlaveStateType * SlaveState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];
    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

    /* Module is transmitting or receiving */
    if (I2c_Ip_GetModuleTransmitMode(BaseAddr))
    {

        I2c_Ip_SlaveTransmitDataEvent(Instance);
    }
    else
    {
        if(I2c_Ip_GetTCF(BaseAddr))
        {
            /* Read data from IBDR and store it */
            I2c_Ip_SlaveReceiveDataEvent(BaseAddr, SlaveState);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveHandleTransferEvents
 * Description   : handle slave transfer events
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveHandleTransferEvents(uint8 Instance)
{
    I2c_Ip_SlaveStateType * SlaveState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

    /* Check if slave is addressed as slave */
    if (I2c_Ip_GetAddressAsSlave(BaseAddr))
    {
        /* It was an address transfer */
        I2c_Ip_AddressAsSlaveEvent(BaseAddr, SlaveState);
    }
    else if(!I2c_Ip_GetBusBusyEvent(BaseAddr))
    {
        /* Report success if no error was recorded */
        if(I2C_IP_BUSY_STATUS == SlaveState->Status)
        {

            if(!SlaveState->ListeningMode)
            {
                SlaveState->ReadyForAddressing = FALSE;
                I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
            }

            I2c_Ip_SlaveStopEvent(SlaveState, I2C_IP_SUCCESS_STATUS);
        }
    }
    else
    {
        I2c_Ip_SlaveTransferHandler(Instance);
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SlaveIRQHandler
 * Description   : handle slave I2C module interrupts
 *
 *END**************************************************************************/
static void I2c_Ip_SlaveIRQHandler(uint8 Instance)
{
    const I2c_Ip_MasterStateType * MasterState;
    const I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* If the module is slave */
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if (MasterState != NULL_PTR)
    {
        I2c_Ip_MasterArbitrationHandler(Instance);
        I2c_Ip_MasterBusBusyHandler(Instance);
    }
    else
    {
#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
        /* Check arbitration lost event */
        if (I2c_Ip_GetMasterArbitrationLostEvent(BaseAddr))
        {
            I2c_Ip_SlaveArbitrationLostHandler(Instance);
        }
        else
        {
#endif
            /* No arbitration lost event */
            I2c_Ip_SlaveHandleTransferEvents(Instance);

#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
        }
#endif
    }

    /* Cast to void to avoid compiler warnings */
    (void) BaseAddr;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterLastByteTransmitted
 * Description   : Master last byte transmitted handler
 *
 *END**************************************************************************/
static void I2c_Ip_MasterLastByteTransmitted(uint8 Instance)
{
    I2c_Ip_MasterStateType * MasterState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if (MasterState->SendStop)
    {
        /* Generate stop signal */
        I2c_Ip_GenerateStopSignal(Instance);
    }
    else
    {
        /* Generate repeated start and end transfer */
        I2c_Ip_SetRepeatStart(BaseAddr, TRUE);
        MasterState->StopGenerated = FALSE;
        MasterState->I2cIdle = TRUE;

        MasterState->Status = I2C_IP_SUCCESS_STATUS;

        I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);

        if (MasterState->MasterCallback != NULL_PTR)
        {
            MasterState->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, MasterState->CallbackParam);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceiveAckEvent
 * Description   : Master receive acknowledge event
 *
 *END**************************************************************************/
static void I2c_Ip_MasterReceiveAckEvent(uint8 Instance)
{
    I2c_Ip_MasterStateType * MasterState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    /* End of address cycle? */
    if (MasterState->SendData)
    {
        /* Send the next byte of data */
        I2c_Ip_MasterSendDataEvent(BaseAddr, MasterState);
    }
    else
    {
        /* If is the end of address cycle and master is in RX mode */
        I2c_Ip_SetModuleTransmitMode(BaseAddr, MasterState->SendData);

        /* Dummy read from IBDR */
        (void) I2c_Ip_GetDataIBDR(BaseAddr);

        if ((I2C_USING_DMA == MasterState->TransferType) && (!MasterState->SendData) && (!MasterState->Blocking))
        {
                I2c_Ip_SetDMAEnable(BaseAddr, TRUE);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterGenerateStopEvent
 * Description   : Master generate stop signal event
 *
 *END**************************************************************************/
static void I2c_Ip_MasterGenerateStopEvent(uint8 Instance)
{
    I2c_Ip_MasterStateType * MasterState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    /* Generate Stop Signal */
    I2c_Ip_GenerateStopSignal(Instance);

    MasterState->Status = I2C_IP_RECEIVED_NACK_STATUS;

     /* Master End Transfer */
     I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);

     if (MasterState->MasterCallback != NULL_PTR)
     {
#if (STD_ON == I2C_IP_EVENT_ERROR_DETECT)
         MasterState->MasterCallback(I2C_MASTER_EVENT_NACK, MasterState->CallbackParam);
#else
         MasterState->MasterCallback(I2C_MASTER_EVENT_END_TRANSFER, MasterState->CallbackParam);
#endif
     }

     if(I2C_USING_DMA == MasterState->TransferType)
     {
        I2c_Ip_SetDMAEnable(BaseAddr, FALSE);
     }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterTransmitHandler
 * Description   : Master transmit mode handler
 *
 *END**************************************************************************/
static void I2c_Ip_MasterTransmitHandler(uint8 Instance)
{
    const I2c_Ip_MasterStateType * MasterState;
    const I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* Master Mode */

    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if(I2c_Ip_GetTCF(BaseAddr))
    {
       /* Last byte transmitted ? */
       if ((0U == MasterState->TxSize)&&(MasterState->SendData))
       {
           I2c_Ip_MasterLastByteTransmitted(Instance);
       }
       else
       {
           /* Receive acknowledge */
           if (I2c_Ip_GetReceivedACK(BaseAddr))
           {
               I2c_Ip_MasterReceiveAckEvent(Instance);
           }
           else
           {
               I2c_Ip_MasterGenerateStopEvent(Instance);
           }
       }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceiveHandler
 * Description   : Master receive mode handler
 *
 *END**************************************************************************/
static void I2c_Ip_MasterReceiveHandler(uint8 Instance)
{
    /* Master is in receive mode */

    I2c_Ip_MasterStateType * MasterState;
    I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if(I2c_Ip_GetTCF(BaseAddr))
    {
        /* If last byte to be read */
        if (1U == MasterState->RxSize)
        {
            if (MasterState->SendStop)
            {
                /* Generate Stop Signal */
                I2c_Ip_GenerateStopSignal(Instance);
            }
            else
            {
                /* Generate repeated start */
                I2c_Ip_SetRepeatStart(BaseAddr, TRUE);
                MasterState->StopGenerated = FALSE;
            }
        }
        else
        {
            /* If second last byte to be read */
            if (2U == MasterState->RxSize)
            {
                /* Set noAck = 1 */
                I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
            }
        }
        /* Read data from IBDR and store */
        I2c_Ip_MasterReceiveDataEvent(BaseAddr, MasterState);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_CheckACK
 * Description   : Check if acknowledge was received
 *
 *END**************************************************************************/
static void I2c_Ip_CheckACK(uint8 Instance)
{
    const I2C_Type *BaseAddr;

    BaseAddr = I2c_Ip_apBase[Instance];

    /* Receive acknowledge */
    if (I2c_Ip_GetReceivedACK(BaseAddr))
    {
        I2c_Ip_MasterReceiveAckEvent(Instance);
    }
    else
    {
        I2c_Ip_MasterGenerateStopEvent(Instance);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_EndReceive
 * Description   : Send stop signal or send repeated start
 *
 *END**************************************************************************/
static void I2c_Ip_EndReceive(uint8 Instance)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType * MasterState;

    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if (MasterState->SendStop)
    {
        /* Generate Stop Signal */
        I2c_Ip_GenerateStopSignal(Instance);
    }
    else
    {
        /* Generate repeated start */
        I2c_Ip_SetRepeatStart(BaseAddr, TRUE);
        MasterState->StopGenerated = FALSE;
    }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterSend
 * Description   : Function used for sending data in polling mode
 *
 *END**************************************************************************/
static void I2c_Ip_MasterSend(uint8 Instance)
{
    I2C_Type *BaseAddr;
    BaseAddr = I2c_Ip_apBase[Instance];

    const I2c_Ip_MasterStateType * MasterState;
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if(I2c_Ip_GetBusInterruptFlag(BaseAddr))
    {
        /* Clear I-Bus Interrupt */
        I2c_Ip_ClearBusInterruptFlag(BaseAddr);

        if(I2c_Ip_GetTCF(BaseAddr))
        {
           /* Last byte transmitted ? */
           if ((0U == MasterState->TxSize)&&(MasterState->SendData))
           {
               I2c_Ip_MasterLastByteTransmitted(Instance);
           }
           else
           {
               /* Receive acknowledge */
               if (I2c_Ip_GetReceivedACK(BaseAddr))
               {
                   I2c_Ip_MasterReceiveAckEvent(Instance);
               }
               else
               {
                   I2c_Ip_MasterGenerateStopEvent(Instance);
               }
           }
        }

    I2c_Ip_MasterArbitrationHandler(Instance);
    }

    I2c_Ip_MasterBusBusyHandler(Instance);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceive
 * Description   : Function used for receiving data in polling mode
 *
 *END**************************************************************************/
static void I2c_Ip_MasterReceive(uint8 Instance)
{
    I2C_Type *BaseAddr;
    BaseAddr = I2c_Ip_apBase[Instance];

    I2c_Ip_MasterStateType * MasterState;
    boolean HasInterruptFlag = FALSE;
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    if(I2c_Ip_GetBusInterruptFlag(BaseAddr))
    {
        HasInterruptFlag = TRUE;
        /* Clear bus interrupt flag*/
        I2c_Ip_ClearBusInterruptFlag(BaseAddr);
    }

    /* In case of end of address cycle */
    if(I2c_Ip_GetTCF(BaseAddr)&&(TRUE == HasInterruptFlag))
    {
        if (I2c_Ip_GetModuleTransmitMode(BaseAddr))
        {
            I2c_Ip_CheckACK(Instance);
        }
        else
        {
            /* If last byte to be read */
            if (1U == MasterState->RxSize)
            {
                I2c_Ip_EndReceive(Instance);
            }
            else
            {
                /* If second last byte to be read */
                if (2U == MasterState->RxSize)
                {
                    /* Set noAck = 1 */
                    I2c_Ip_SetDataAcknowledge(BaseAddr, FALSE);
                }
            }
            /* Read data from IBDR and store */
            I2c_Ip_MasterReceiveDataEvent(BaseAddr, MasterState);
        }
    }

    I2c_Ip_MasterArbitrationHandler(Instance);

    I2c_Ip_MasterBusBusyHandler(Instance);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterTransferData
 * Description   : master transfer data on the I2C bus
 *
 *END**************************************************************************/
static void I2c_Ip_MasterTransferData(uint8 Instance,
                                      uint32 Timeout)
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, I2C_TIMEOUT_TYPE);

    I2c_Ip_MasterStateType *MasterState;
    MasterState = I2c_Ip_apMasterStatePtr[Instance];

    CurrentTicks = OsIf_GetCounter(I2C_TIMEOUT_TYPE);

    do
    {
        if(MasterState->SendData)
        {
            /* Master send data */
            I2c_Ip_MasterSend(Instance);
        }
        else
        {
            /* Master receive data */
            I2c_Ip_MasterReceive(Instance);
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, I2C_TIMEOUT_TYPE);

    }while((I2C_IP_BUSY_STATUS == I2c_Ip_MasterGetTransferStatus(Instance)) && (ElapsedTicks < TimeoutTicks));

    if(ElapsedTicks >= TimeoutTicks)
    {
        MasterState->Status = I2C_IP_TIMEOUT_STATUS;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterReceiveDataBlocking
 * Description   : perform a blocking send transaction on the I2C bus
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterReceiveDataBlocking_Privileged(uint8 Instance,
                                                              uint8 *RxBuff,
                                                              uint32 RxSize,
                                                              boolean SendStop,
                                                              uint32 Timeout)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType *MasterState;
    I2c_Ip_StatusType ReturnStatus = I2C_IP_SUCCESS_STATUS;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif
    BaseAddr = I2c_Ip_apBase[Instance];
    MasterState = I2c_Ip_apMasterStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif

    /* Check if driver is busy */
    if(!MasterState->I2cIdle)
    {
        ReturnStatus = I2C_IP_BUSY_STATUS;
    }

    if((MasterState->StopGenerated)&&(I2c_Ip_GetBusBusyEvent(BaseAddr))&&(I2C_IP_SUCCESS_STATUS == ReturnStatus))
    {
        /* Check if bus is busy */
        ReturnStatus = I2C_IP_BUS_BUSY_STATUS;
    }
    if(I2C_IP_SUCCESS_STATUS == ReturnStatus)
    {
        /* Copy parameters to driver state structure */
        MasterState->RxSize = RxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->RxBuff = RxBuff;
        MasterState->Status = I2C_IP_BUSY_STATUS;
        MasterState->SendData = FALSE;
        MasterState->SendStop = SendStop;
        MasterState->Blocking = TRUE;

        /* Acknowledge enabled */
        I2c_Ip_SetDataAcknowledge(BaseAddr, TRUE);

        /* Send Address */
        (void)I2c_Ip_MasterTransmitAddress(Instance);

        /* Master transfer data */
        I2c_Ip_MasterTransferData(Instance, Timeout);

        ReturnStatus = MasterState->Status;
    }

    return ReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2C_DRV_MasterSendDataBlocking
 * Description   : perform a blocking send transaction on the I2C bus
 *
 *END**************************************************************************/
I2c_Ip_StatusType I2c_Ip_MasterSendDataBlocking_Privileged(uint8 Instance,
                                                           const uint8 * TxBuff,
                                                           uint32 TxSize,
                                                           boolean SendStop,
                                                           uint32 Timeout)
{
    const I2C_Type *BaseAddr;
    I2c_Ip_StatusType ReturnStatus = I2C_IP_SUCCESS_STATUS;

#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif
    BaseAddr = I2c_Ip_apBase[Instance];
    I2c_Ip_MasterStateType *MasterState = I2c_Ip_apMasterStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif

    /* Check if driver is busy */
    if(!MasterState->I2cIdle)
    {
        ReturnStatus = I2C_IP_BUSY_STATUS;
    }

    if((MasterState->StopGenerated)&&((I2c_Ip_GetBusBusyEvent(BaseAddr)))&&(I2C_IP_SUCCESS_STATUS == ReturnStatus))
    {
        /* Check if bus is busy */
        ReturnStatus = I2C_IP_BUS_BUSY_STATUS;
    }

    if(I2C_IP_SUCCESS_STATUS == ReturnStatus)
    {
        /* Copy parameters to drive state structure */
        MasterState->TxBuff = TxBuff;
        MasterState->TxSize = TxSize;
        MasterState->I2cIdle = FALSE;
        MasterState->Status = I2C_IP_BUSY_STATUS;
        MasterState->SendData = TRUE;
        MasterState->SendStop = SendStop;
        MasterState->Blocking = TRUE;

        /* Send Address */
        (void)I2c_Ip_MasterTransmitAddress(Instance);

        /* Master transfer data */
        I2c_Ip_MasterTransferData(Instance, Timeout);

        ReturnStatus = MasterState->Status;
    }

     return ReturnStatus;
}

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_TriggerEvent
 * Description   : Send/Receive the last byte of data in case CPU interrupt is not triggered
 *                 when DMA mode is used.
 *
 *END**************************************************************************/
static void I2c_Ip_TriggerEvent(uint8 Instance)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType *MasterState;

    MasterState = I2c_Ip_apMasterStatePtr[Instance];
    BaseAddr = I2c_Ip_apBase[Instance];

    if((MasterState->SendData))
    {
        /* Send the last byte of data in case CPU interrupt is not triggered */
        I2c_Ip_MasterSendDataEvent(BaseAddr, MasterState);
    }
    else
    {
        /* Receive the last byte of data in case CPU interrupt is not triggered */
       I2c_Ip_MasterReceiveHandler(Instance);
    }

}
#endif

#if(STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterCompleteDMATransfer
 * Description   : Finish up a transfer DMA for master. The main purpose of
 *                 this function is to create a function compatible with DMA
 *                 callback type
 *
 *END**************************************************************************/
void I2c_Ip_MasterCompleteDMATransfer(uint8 Instance)
{
    I2C_Type *BaseAddr;
    I2c_Ip_MasterStateType *MasterState;
    uint32 Index;

    MasterState = I2c_Ip_apMasterStatePtr[Instance];
    BaseAddr = I2c_Ip_apBase[Instance];

    if (MasterState->SendData)
    {
        for(Index = 0U;Index < (MasterState->TxSize - 1U);Index++)
        {
            MasterState->TxBuff++;
        }
        MasterState->TxSize = 1;
    }
    else
    {
        for(Index = 0U;Index < (MasterState->RxSize - 2U);Index++)
        {
            MasterState->RxBuff++;
        }
        MasterState->RxSize = 2;
    }

    I2c_Ip_SetDMAEnable(BaseAddr, FALSE);

    /* Send/Receive the last byte of data in case CPU interrupt is not triggered */
    if (I2c_Ip_GetTCF(BaseAddr))
    {
        I2c_Ip_TriggerEvent(Instance);
    }

}

#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterDMATransferErrorHandler
 * Description   : Handle error when transfer DMA for master. The main purpose of
 *                 this function is to create a function compatible with DMA
 *                 callback type
 *
 *END**************************************************************************/
void I2c_Ip_MasterDmaTransferErrorHandler(uint8 Instance)
{
    I2C_Type *BaseAddr;
    Dma_Ip_LogicChannelStatusType DmaStatus;
    I2c_Ip_MasterStateType *MasterState;

    MasterState = I2c_Ip_apMasterStatePtr[Instance];
    BaseAddr = I2c_Ip_apBase[Instance];
    DmaStatus.ChStateValue = DMA_IP_CH_RESET_STATE;

    if (MasterState->SendData)
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(MasterState->DmaTxChannel, &DmaStatus);
    }
    else
    {
        /* Get DMA channel status */
        (void)Dma_Ip_GetLogicChannelStatus(MasterState->DmaRxChannel, &DmaStatus);
    }

    if(DMA_IP_CH_ERROR_STATE == DmaStatus.ChStateValue)
    {
        /* Generate stop signal */
        I2c_Ip_GenerateStopSignal(Instance);

        I2c_Ip_MasterEndTransfer(BaseAddr, MasterState);

        MasterState->Status = I2C_IP_DMA_ERROR_STATUS;

        if (MasterState->MasterCallback != NULL_PTR)
        {
            MasterState->MasterCallback(I2C_MASTER_EVENT_DMA_TRANSFER_ERROR, MasterState->CallbackParam);
        }
    }

    I2c_Ip_SetDMAEnable(BaseAddr, FALSE);
}
#endif

#if (I2C_INSTANCE_COUNT >= 1U)
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaErrorNotification0
 * Description   : Dma error notification for instance 0
 *
 *END**************************************************************************/
void I2c_Ip_DmaErrorNotification0(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterDmaTransferErrorHandler,(0U));
#else
    I2c_Ip_MasterDmaTransferErrorHandler(0U);
#endif
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaCompleteNotification0
 * Description   : Dma complete notification for instance 0
 *
 *END**************************************************************************/
void I2c_Ip_DmaCompleteNotification0(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterCompleteDMATransfer,(0U));
#else
    I2c_Ip_MasterCompleteDMATransfer(0U);
#endif
}
#endif /* I2C_INSTANCE_COUNT >= 1U */

#if (I2C_INSTANCE_COUNT >= 2U)
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaErrorNotification1
 * Description   : Dma error notification for instance 1
 *
 *END**************************************************************************/
void I2c_Ip_DmaErrorNotification1(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterDmaTransferErrorHandler,(1U));
#else
    I2c_Ip_MasterDmaTransferErrorHandler(1U);
#endif
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaCompleteNotification1
 * Description   : Dma complete notification for instance 1
 *
 *END**************************************************************************/
void I2c_Ip_DmaCompleteNotification1(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterCompleteDMATransfer,(1U));
#else
    I2c_Ip_MasterCompleteDMATransfer(1U);
#endif
}
#endif /* I2C_INSTANCE_COUNT >= 2U */

#if (I2C_INSTANCE_COUNT >= 3U)
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaErrorNotification2
 * Description   : Dma error notification for instance 1
 *
 *END**************************************************************************/
void I2c_Ip_DmaErrorNotification2(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterDmaTransferErrorHandler,(2U));
#else
    I2c_Ip_MasterDmaTransferErrorHandler(2U);
#endif
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaCompleteNotification2
 * Description   : Dma complete notification for instance 2
 *
 *END**************************************************************************/
void I2c_Ip_DmaCompleteNotification2(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterCompleteDMATransfer,(2U));
#else
    I2c_Ip_MasterCompleteDMATransfer(2U);
#endif
}
#endif /* I2C_INSTANCE_COUNT >= 3U */

#if (I2C_INSTANCE_COUNT >= 4U)
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaErrorNotification3
 * Description   : Dma error notification for instance 1
 *
 *END**************************************************************************/
void I2c_Ip_DmaErrorNotification3(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterDmaTransferErrorHandler,(3U));
#else
    I2c_Ip_MasterDmaTransferErrorHandler(3U);
#endif
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaCompleteNotification3
 * Description   : Dma complete notification for instance 3
 *
 *END**************************************************************************/
void I2c_Ip_DmaCompleteNotification3(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterCompleteDMATransfer,(3U));
#else
    I2c_Ip_MasterCompleteDMATransfer(3U);
#endif
}
#endif /* I2C_INSTANCE_COUNT >= 4U*/

#if (I2C_INSTANCE_COUNT >= 5U)
#if(STD_ON == I2C_IP_DMA_TRANSFER_ERROR_DETECT)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaErrorNotification4
 * Description   : Dma error notification for instance 1
 *
 *END**************************************************************************/
void I2c_Ip_DmaErrorNotification4(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterDmaTransferErrorHandler,(4U));
#else
    I2c_Ip_MasterDmaTransferErrorHandler(4U);
#endif
}
#endif
/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_DmaCompleteNotification4
 * Description   : Dma complete notification for instance 4
 *
 *END**************************************************************************/
void I2c_Ip_DmaCompleteNotification4(void)
{
#if (STD_ON == I2C_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(I2c_Ip_MasterCompleteDMATransfer,(4U));
#else
    I2c_Ip_MasterCompleteDMATransfer(4U);
#endif
}
#endif /* I2C_INSTANCE_COUNT >= 5U */

#endif /* STD_ON == I2C_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_MasterIRQHandler
 * Description   : handle master I2C module interrupts
 *
 *END**************************************************************************/
static void I2c_Ip_MasterIRQHandler(uint8 Instance)
{
    const I2C_Type *BaseAddr;
    BaseAddr = I2c_Ip_apBase[Instance];

    /* Check the mode - receive or transmit */
    if (I2c_Ip_GetModuleTransmitMode(BaseAddr))
    {
        I2c_Ip_MasterTransmitHandler(Instance);
    }
    else
    {
        I2c_Ip_MasterReceiveHandler(Instance);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_ModuleIRQHandler
 * Description   : handle master/slave I2C module interrupts
 *
 *END**************************************************************************/
 /* @implements I2C0_IRQHandler_Activity */
void I2c_Ip_ModuleIRQHandler_Privileged(uint8 Instance)
{
    uint8 IsrEnable = 0u;
    uint8 IsrStatus = 0u;
    uint8 BusIsrEnabled = 0u;
    uint8 BusIsrStatus = 0u;
    I2C_Type *BaseAddr = I2c_Ip_apBase[Instance];
    const I2c_Ip_MasterStateType* MasterState = I2c_Ip_apMasterStatePtr[Instance];
    const I2c_Ip_SlaveStateType* SlaveState = I2c_Ip_apSlaveStatePtr[Instance];

    /* Check if the driver has been initialized */
    if((NULL_PTR != MasterState) || (NULL_PTR != SlaveState))
    {
        /* the driver has been initialized */
        /* Check i2c interrupts */
        IsrEnable = BaseAddr->IBCR & I2C_IBCR_IBIE_MASK;
        IsrStatus = BaseAddr->IBSR & (I2C_IBSR_IAAS_MASK | I2C_IBSR_TCF_MASK | I2C_IBSR_IBAL_MASK | I2C_IBSR_RXAK_MASK);
        /* Check bus idle interrupts */
        BusIsrEnabled = BaseAddr->IBIC | I2C_IBIC_BIIE_MASK;
        BusIsrStatus =  BaseAddr->IBSR & I2C_IBSR_IBB_MASK;

        if(((0u != IsrEnable) && (0u != IsrStatus)) || ((0u != BusIsrEnabled) && (0u == BusIsrStatus)))
        {

            /* The interrupt is not spurious, clear respective status flags (CPR_RTD_00664).
            * Based on the chapter "Recommended interrupt service flow" in Reference manual: we need to clear the IBIF flag first before the others.
            */
            I2c_Ip_ClearBusInterruptFlag(BaseAddr);

            if (FALSE == I2c_Ip_GetModuleModSelect((const I2C_Type *)BaseAddr))
            {
                I2c_Ip_SlaveIRQHandler(Instance);
            }
            else
            {
                I2c_Ip_MasterIRQHandler(Instance);
            }
        }
        else
        {
            /* The interrupt is spurious, return immediately (CPR_RTD_00664) */
        }
    }
    else
    {
        /* The driver is not initialized, only clear interrupt status flag and return immediately (CPR_RTD_00011) */
        BaseAddr->IBSR &= (uint8)0xFF;
    }

    /* Cast to void to avoid compiler warnings */
    (void) IsrEnable;
    (void) IsrStatus;
    (void) BusIsrEnabled;
    (void) BusIsrStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SetMasterCallback
 * Description   : Sets the master callback
 *
 *END**************************************************************************/
void I2c_Ip_SetMasterCallback(uint8 Instance,
                              I2c_Ip_MasterCallbackType MasterCallback)
{
    I2c_Ip_MasterStateType * MasterState;
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif
    MasterState = I2c_Ip_apMasterStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(MasterState != NULL_PTR);
#endif

    MasterState->MasterCallback = MasterCallback;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ip_SetSlaveCallback
 * Description   : Sets the slave callback
 *
 *END**************************************************************************/
void I2c_Ip_SetSlaveCallback(uint8 Instance,
                             I2c_Ip_SlaveCallbackType SlaveCallback)
{
    I2c_Ip_SlaveStateType * SlaveState;
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < I2C_INSTANCE_COUNT);
#endif
    SlaveState = I2c_Ip_apSlaveStatePtr[Instance];
#if (STD_ON == I2C_IP_DEV_ERROR_DETECT)
    DevAssert(SlaveState != NULL_PTR);
#endif

    SlaveState->SlaveCallback = SlaveCallback;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

