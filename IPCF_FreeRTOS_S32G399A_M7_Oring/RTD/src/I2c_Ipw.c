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
*     @file
*
*     @addtogroup I2C_DRIVER I2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I2c_Ipw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IPW_VENDOR_ID_C                    43
#define I2C_IPW_MODULE_ID_C                    255
#define I2C_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define I2C_IPW_AR_RELEASE_MINOR_VERSION_C     4
#define I2C_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define I2C_IPW_SW_MAJOR_VERSION_C             4
#define I2C_IPW_SW_MINOR_VERSION_C             0
#define I2C_IPW_SW_PATCH_VERSION_C             2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Ipw.h header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID_C != I2C_IPW_VENDOR_ID)
    #error "I2c_Ipw.c and I2c_Ipw.h have different vendor ids"
#endif
/* Check if current file and I2c_Ipw.h header file are of the same module */
#if (I2C_IPW_MODULE_ID_C != I2C_IPW_MODULE_ID)
    #error "I2c_Ipw.c and I2c_Ipw.h have different module ids"
#endif
/* Check if current file and I2c_Ipw.h header file are of the same Autosar version */
#if ( (I2C_IPW_AR_RELEASE_MAJOR_VERSION_C     != I2C_IPW_AR_RELEASE_MAJOR_VERSION)   || \
      (I2C_IPW_AR_RELEASE_MINOR_VERSION_C     != I2C_IPW_AR_RELEASE_MINOR_VERSION)   || \
      (I2C_IPW_AR_RELEASE_REVISION_VERSION_C  != I2C_IPW_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of I2c_Ipw.c and I2c_Ipw.h are different"
#endif
/* Check if current file and I2c_Ipw.h header file are of the same Software version */
#if ( (I2C_IPW_SW_MAJOR_VERSION_C != I2C_IPW_SW_MAJOR_VERSION) || \
      (I2C_IPW_SW_MINOR_VERSION_C != I2C_IPW_SW_MINOR_VERSION) || \
      (I2C_IPW_SW_PATCH_VERSION_C != I2C_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_Ipw.c and I2c_Ipw.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define I2C_START_SEC_CODE
/**
* @violates @ref I2c_Ipw_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
*/
#include "I2c_MemMap.h"


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_SlaveCallback
 * Description   : Ipw slave callback
 * Implements    : I2c_Ipw_SlaveCallback_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_SlaveCallback(I2c_Ip_SlaveEventType Event, uint8 UserData)
{
    uint8  Channel;
    Channel = (uint8) UserData;

    switch(Event)
    {
        case I2C_SLAVE_EVENT_TX_REQ:
        {
            I2c_aeChannelStatus[Channel] = I2C_CH_SEND;
            break;
        }
        case I2C_SLAVE_EVENT_RX_REQ:
        {
            I2c_aeChannelStatus[Channel] = I2C_CH_RECEIVE;
            break;
        }
        default:
        {
            /* no action  */
            break;
        }
    }

#ifdef I2C_ERROR_CALLBACK
    if((Event == I2C_SLAVE_EVENT_UNDERRUN) || (Event == I2C_SLAVE_EVENT_OVERRUN))
    {

        I2C_ERROR_CALLBACK((uint8)Event, (uint8)Channel);

    }
    else /* No error event has occurred */
    {
#ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
    }
#else /* I2C_ERROR_CALLBACK */
    #ifdef I2C_MODULE_CALLBACK
    I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
    #endif /* I2C_MODULE_CALLBACK */
#endif

    /* Cast to void to avoid compiler warnings */
    (void) Channel;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_MasterCallback
 * Description   : Ipw master callback
 * Implements    : I2c_Ipw_MasterCallback_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_MasterCallback(I2c_Ip_MasterEventType Event, uint8 UserData)
{
    uint32  Channel;
    Channel = (uint32) UserData;

#ifdef I2C_ERROR_CALLBACK
    if((Event == I2C_MASTER_EVENT_NACK) || (Event == I2C_MASTER_EVENT_ARBITRATION_LOST) || (I2C_MASTER_EVENT_DMA_TRANSFER_ERROR == Event))
    {

        I2C_ERROR_CALLBACK((uint8)Event, (uint8)Channel);

    }
    else /* No error event has occurred */
    {
#ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
#endif /* I2C_MODULE_CALLBACK */
    }
#else /* I2C_ERROR_CALLBACK */
    #ifdef I2C_MODULE_CALLBACK
        I2C_MODULE_CALLBACK((uint8)Event, (uint8)Channel);
    #endif /* I2C_MODULE_CALLBACK */
#endif

    /* Cast to void to avoid compiler warnings */
    (void) Event;
    (void) Channel;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_InitChannel
 * Description   : Initialize a I2c Channel
 * Implements    : I2c_Ipw_InitChannel_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_InitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr)
{
    /**  @violates @ref I2c_Ipw_c_REF_7 The comma operator shall not be used. */
    /**
    * @violates @ref I2c_Ipw_c_REF_9 SMCAL coding guideline , Rule 3.3:
    * Multi-statement macros shall be wrapped in a do–while loop, so the macro can appear safely inside if clauses
    * or other places that expect a single statement or a statement block .
    */
    if(I2C_SLAVE_MODE != ConfigPtr->MasterSlaveConfig)
    {
        (void)I2c_Ip_MasterInit(Channel, ConfigPtr->HwChannelConfig.I2C_IP_IICHwConfig->MasterConfig);
        I2c_Ip_SetMasterCallback(Channel, &I2c_Ipw_MasterCallback);

    }
    else
    {
        (void)I2c_Ip_SlaveInit(Channel, ConfigPtr->HwChannelConfig.I2C_IP_IICHwConfig->SlaveConfig);
        I2c_Ip_SetSlaveCallback(Channel, &I2c_Ipw_SlaveCallback);
    }

}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_StartListening
 * Description   : Makes a slave Channel available for processing requests
 * Implements    : I2c_Ipw_StartListening_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_StartListening(uint8 Channel)
{
    /* Update slave status */
    I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]]= I2C_CH_IDLE;
    I2c_Ip_StartListening(Channel);
}

static I2c_StatusType I2c_Ipw_ConvertStatus(const uint8 Channel, const uint32 Status)
{
    I2c_StatusType I2cStatus;

    switch(Status)
    {
        case 0U: /* STATUS_SUCCESS */
        {
            if(I2C_CH_IDLE == I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]])
            {
                I2cStatus = I2C_CH_IDLE;
            }
            else
            {
                I2cStatus = I2C_CH_FINISHED;
            }

            break;
        }
        case 2U: /* STATUS_BUSY */
        {
            if(I2C_CH_SEND == I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[Channel]])
            {
                I2cStatus = I2C_CH_SEND;
            }
            else
            {
                I2cStatus = I2C_CH_RECEIVE;
            }

            break;
        }
        default:
        {
            I2cStatus = I2C_CH_ERROR_PRESENT;
            break;
        }
    }

    return I2cStatus;
}

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_ReportDemTimeoutError
 * Description   : Reports timeout error to DEM.
 *
 *END**************************************************************************/
static void I2c_Ipw_ReportDemTimeoutError(void)
{
    /* Core ID */
    uint8 CoreId;

    /* Get coreid */
    CoreId = (uint8) I2c_GetCoreID();

    if ((uint32)STD_ON == I2c_apDemCfg[CoreId]->I2c_E_TimeoutFailureCfg.state)
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)I2c_apDemCfg[CoreId]->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
    }
 }
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_GetStatus
 * Description   : Get status of I2C
 * Implements    : I2c_Ipw_GetStatus_Activity
 *
 *END**************************************************************************/
I2c_StatusType I2c_Ipw_GetStatus(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr)
{
    I2c_Ip_StatusType HwStatus;

    if(I2C_SLAVE_MODE != ConfigPtr->MasterSlaveConfig)
    {
        HwStatus = I2c_Ip_MasterGetTransferStatus(Channel);
    }
    else
    {
        HwStatus = I2c_Ip_SlaveGetTransferStatus(Channel);
    }

    return  I2c_Ipw_ConvertStatus(Channel, (uint32)HwStatus);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_DeInitChannel
 * Description   : De initialize a I2c Channel.
 * Implements    : I2c_Ipw_DeInitChannel_Activity
 *
 *END**************************************************************************/
void I2c_Ipw_DeInitChannel(const uint8 Channel, const I2c_HwUnitConfigType * ConfigPtr)
{
    if(I2C_SLAVE_MODE != ConfigPtr->MasterSlaveConfig)
    {
        (void)I2c_Ip_MasterDeinit(Channel);
    }
    else
    {
        (void)I2c_Ip_SlaveDeinit(Channel);
    }

}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_PrepareSlaveBuffer
 * Description   : Prepare the RX or TX buffer for a slave Channel.
 * Implements    : I2c_Ipw_PrepareSlaveBuffer_Activity
 *
 *END**************************************************************************/
void  I2c_Ipw_PrepareSlaveBuffer(uint8 Channel, uint8 NumberOfBytes, I2c_DataType * DataBuffer)
{
    (void) I2c_Ip_SlaveSetBuffer(Channel, DataBuffer, NumberOfBytes);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_AsyncTransmit
 * Description   : Sends or receives an I2C message non-blocking
 * Implements    : I2c_Ipw_AsyncTransmit_Activity
 *
 *END**************************************************************************/
Std_ReturnType I2c_Ipw_AsyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType)
{
    Std_ReturnType TmpReturn;

    /* Cast to void to avoid compiler warnings */
    (void) HwConfigType;

    /* Set slave address */
    (void) I2c_Ip_MasterSetSlaveAddress(Channel, (uint8)Request->SlaveAddress);

    if(I2C_SEND_DATA == Request->DataDirection)
    {
        TmpReturn = (Std_ReturnType)I2c_Ip_MasterSendData(Channel, Request->DataBuffer, (uint32)Request->BufferSize, !(Request->RepeatedStart));
    }
    else
    {
        TmpReturn = (Std_ReturnType)I2c_Ip_MasterReceiveData(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart));
    }

    if((Std_ReturnType)E_OK != TmpReturn)
    {
        TmpReturn = E_NOT_OK;
    }

    return TmpReturn;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2c_Ipw_SyncTransmit
 * Description   : Sends or receives an I2C message blocking
 * Implements    : I2c_Ipw_SyncTransmit_Activity
 *
 *END**************************************************************************/
Std_ReturnType I2c_Ipw_SyncTransmit(uint8 Channel, const I2c_RequestType * Request, const I2c_HwUnitConfigType * HwConfigType)
{
    Std_ReturnType TmpReturn;

    /* Cast to void to avoid compiler warnings */
    (void) HwConfigType;

    /* Set slave address */
    (void) I2c_Ip_MasterSetSlaveAddress(Channel, (uint8)Request->SlaveAddress);

    if(I2C_SEND_DATA == Request->DataDirection)
    {
        TmpReturn = (Std_ReturnType)I2c_Ip_MasterSendDataBlocking(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
    }
    else
    {
        TmpReturn = (Std_ReturnType)I2c_Ip_MasterReceiveDataBlocking(Channel, Request->DataBuffer, Request->BufferSize, !(Request->RepeatedStart), I2C_TIMEOUT);
    }

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if(TmpReturn == (Std_ReturnType) I2C_IP_TIMEOUT_STATUS)
    {
        I2c_Ipw_ReportDemTimeoutError();
    }
#endif

    if((Std_ReturnType)E_OK != TmpReturn)
    {
        TmpReturn = E_NOT_OK;
    }

    return TmpReturn;
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
