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
*   @file Pmic_VR55XX_i2c_external_access.c
*
*   @addtogroup i2c_external_access
*   @{
*/

#if defined (__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pmic_VR55XX_i2c_external_access.h"

#ifdef USE_IPV_IIC
    #include "I2c_Ip.h"
#elif defined USE_IPV_LPI2C
    #include "Lpi2c_Ip.h"
#elif defined USE_IPV_I3C
    #include "I3c_Ip.h"
#elif defined USE_I3C
    #include "CDD_I3c.h"
#else
    #include "CDD_I2c.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_VENDOR_ID_C                      43
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C       4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C       4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C    0
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C               4
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MINOR_VERSION_C               0
#define PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against I2c External Access header file */
#if ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_VENDOR_ID_C != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_VENDOR_ID)
    #error "I2c External Access source file and I2c External Access header file have different vendor ids"
#endif
#if (( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C    != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION    ) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C    != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION    ) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION ))
     #error "AUTOSAR Version Numbers of I2c External Access source file and I2c External Access header file are different"
#endif
#if (( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MAJOR_VERSION_C != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MAJOR_VERSION) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MINOR_VERSION_C != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_MINOR_VERSION) || \
     ( PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_PATCH_VERSION_C != PMIC_VR55XX_I2C_EXTERNAL_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c External Access source file and I2c External Access header file are different"
#endif

#ifdef USE_IPV_IIC
    /* Check if current file and I2c_Ip header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != I2C_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != I2C_IP_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != I2C_IP_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of I2c External Access source file and I2c_Ip.h are different"
    #endif
    #endif
#elif defined USE_IPV_LPI2C
    /* Check if current file and Lpi2c_Ip header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != LPI2C_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != LPI2C_IP_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != LPI2C_IP_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of I2c External Access source file and Lpi2c_Ip.h are different"
    #endif
    #endif
#elif defined USE_IPV_I3C
    /* Check if current file and I3c_Ip header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != I3C_IP_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != I3C_IP_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != I3C_IP_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of I2c External Access source file and I3c_Ip.h are different"
    #endif
    #endif
#elif defined USE_I3C
    /* Check if current file and I3c header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != I3C_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != I3C_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != I3C_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of I2c External Access source file and CDD_I3c.h are different"
    #endif
    #endif
#else
    /* Check if current file and I2c header file are of the same version */
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MAJOR_VERSION_C != I2C_AR_RELEASE_MAJOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_MINOR_VERSION_C != I2C_AR_RELEASE_MINOR_VERSION) || \
         (PMIC_VR55XX_I2C_EXTERNAL_ACCESS_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of I2c External Access source file and CDD_I2c.h are different"
    #endif
    #endif
#endif

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/



/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PMIC_START_SEC_CODE
#include "Pmic_MemMap.h"

static Std_ReturnType Pmic_VR55XX_WaitForAsyncTransmitEnd(const uint32 u32I2c, const uint32 u32Timeout);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_WaitForAsyncTransmitEnd
 * Description   : Checks if the I2C transfer has ended
 *
 *END**************************************************************************/
static Std_ReturnType Pmic_VR55XX_WaitForAsyncTransmitEnd(const uint32 u32I2c, const uint32 u32Timeout)
{
    Std_ReturnType    eTempRet = (Std_ReturnType)E_NOT_OK;
    uint32 u32I2cStatus;
    uint32 u32TimeValue = u32Timeout;

#ifdef USE_IPV_IIC
    do
    {
        u32I2cStatus = (uint32)I2c_Ip_MasterGetTransferStatus(u32I2c);
        u32TimeValue--;
    }
    while ((u32I2cStatus != (uint32)I2C_IP_BUSY_STATUS) && (u32TimeValue > 0U));
    if (u32I2cStatus == 0U)
    {
        eTempRet = (Std_ReturnType)E_OK;
    }
#elif defined USE_IPV_LPI2C
    do
    {
        u32I2cStatus = (uint32)Lpi2c_Ip_MasterGetTransferStatus(u32I2c, NULL_PTR);
        u32TimeValue--;
    }
    while ((u32I2cStatus != (uint32)LPI2C_IP_BUSY_STATUS) && (u32TimeValue > 0U));
    if (u32I2cStatus == 0U)
    {
        eTempRet = (Std_ReturnType)E_OK;
    }
#elif defined USE_IPV_I3C
    do
    {
        u32I2cStatus = (uint32)I3c_Ip_MasterGetTransferStatus((uint8)u32I2c, NULL_PTR);
        u32TimeValue--;
    }
    while ((u32I2cStatus != (uint32)I3C_IP_STATUS_SUCCESS) && (u32TimeValue > 0U));
    if (u32I2cStatus == I3C_IP_STATUS_SUCCESS)
    {
        eTempRet = (Std_ReturnType)E_OK;
    }
#elif defined USE_I3C
    do
    {
        u32I2cStatus = (uint32)I3c_GetTransferStatus((uint8)u32I2c, NULL_PTR);
        u32TimeValue--;
    }
    while ((u32I2cStatus != (uint32)I3C_STATUS_SUCCESS) && (u32TimeValue > 0U));
    if (u32I2cStatus == (uint32)I3C_STATUS_SUCCESS)
    {
        eTempRet = (Std_ReturnType)E_OK;
    }
#else
    do
    {
        u32I2cStatus = (uint32)I2c_GetStatus((uint8)(0xFFU & u32I2c));
        u32TimeValue--;
    }
    while ((u32I2cStatus != (uint32)I2C_CH_FINISHED) && (u32TimeValue > 0U));
    if (u32I2cStatus == (uint32)I2C_CH_FINISHED)
    {
        eTempRet = (Std_ReturnType)E_OK;
    }
#endif

    return eTempRet;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Pmic_VR55XX_I2cTransferExternal
 * Description   : I2C access for external devices
 *
 *END**************************************************************************/
Std_ReturnType Pmic_VR55XX_I2cTransferExternal(const Pmic_VR55XX_I2cSetupType * pI2cSetupTypePtr, uint8 * pTxBufferPtr, uint8 * pRxBufferPtr)
{
    Std_ReturnType eStatus = E_OK;

#ifdef USE_IPV_IIC
    (void)pI2cSetupTypePtr->bRepeatedStart;
    /* Set the slave address for master */
    I2c_Ip_MasterSetSlaveAddress(pI2cSetupTypePtr->u32I2c, (uint8)pI2cSetupTypePtr->u16SlaveAddress);
#elif defined USE_IPV_LPI2C
    (void)pI2cSetupTypePtr->bRepeatedStart;
    /* Set the slave address for master */
    Lpi2c_Ip_MasterSetSlaveAddr(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u16SlaveAddress, FALSE);
#elif defined USE_IPV_I3C
    (void)pI2cSetupTypePtr->bRepeatedStart;
    I3c_Ip_TransferConfigType Request_Tx;

    Request_Tx.SlaveAddress = (uint8)pI2cSetupTypePtr->u16SlaveAddress;
    Request_Tx.SendStop = TRUE;
    Request_Tx.TransferSize = I3C_IP_TRANSFER_BYTES;
    Request_Tx.BusType = I3C_IP_BUS_TYPE_I2C;

#elif defined USE_I3C
    (void)pI2cSetupTypePtr->bRepeatedStart;
    I3c_RequestType Request_Tx;

    Request_Tx.SlaveAddress = (uint8)pI2cSetupTypePtr->u16SlaveAddress;
    Request_Tx.SendStop = TRUE;
    Request_Tx.TransferSize = I3C_TRANSFER_BYTES;
    Request_Tx.BusType = I3C_BUS_TYPE_I2C;

#else
    I2c_RequestType eRequest;

    eRequest.SlaveAddress = (I2c_AddressType)pI2cSetupTypePtr->u16SlaveAddress;
    eRequest.BitsSlaveAddressSize = FALSE;
    eRequest.HighSpeedMode = FALSE;
    eRequest.ExpectNack = FALSE;
    eRequest.RepeatedStart = pI2cSetupTypePtr->bRepeatedStart;
    eRequest.BufferSize = pI2cSetupTypePtr->u8NumberOfBytes;
#endif

    /* Start I2C transfer */
#ifdef USE_IPV_IIC
    if ((pTxBufferPtr != NULL_PTR) && (pRxBufferPtr == NULL_PTR))
    {
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I2c_Ip_MasterSendData(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)I2c_Ip_MasterSendDataBlocking(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE, pI2cSetupTypePtr->u32Timeout);
        }
    }
    else if ((pTxBufferPtr == NULL_PTR) && (pRxBufferPtr != NULL_PTR))
    {
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I2c_Ip_MasterReceiveData(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)I2c_Ip_MasterReceiveDataBlocking(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE, pI2cSetupTypePtr->u32Timeout);
        }
    }
    else
    {
        /* Input buffers are not properly */
        eStatus = (Std_ReturnType)E_NOT_OK;
    }

#elif defined USE_IPV_LPI2C
    if ((pTxBufferPtr != NULL_PTR) && (pRxBufferPtr == NULL_PTR))
    {
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)Lpi2c_Ip_MasterSendData(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)Lpi2c_Ip_MasterSendDataBlocking(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE, pI2cSetupTypePtr->u32Timeout);
        }
    }
    else if ((pTxBufferPtr == NULL_PTR) && (pRxBufferPtr != NULL_PTR))
    {
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)Lpi2c_Ip_MasterReceiveData(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)Lpi2c_Ip_MasterReceiveDataBlocking(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, TRUE, pI2cSetupTypePtr->u32Timeout);
        }
    }
    else
    {
        /* Input buffers are not properly */
        eStatus = (Std_ReturnType)E_NOT_OK;
    }

#elif defined USE_IPV_I3C
    if ((pTxBufferPtr != NULL_PTR) && (pRxBufferPtr == NULL_PTR))
    {
        Request_Tx.Direction = I3C_IP_WRITE;
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I3c_Ip_MasterSend(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)I3c_Ip_MasterSendBlocking(pI2cSetupTypePtr->u32I2c, pTxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
        }
    }
    else if ((pTxBufferPtr == NULL_PTR) && (pRxBufferPtr != NULL_PTR))
    {
        Request_Tx.Direction = I3C_IP_READ;
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I3c_Ip_MasterReceive(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            eStatus = (Std_ReturnType)I3c_Ip_MasterReceiveBlocking(pI2cSetupTypePtr->u32I2c, pRxBufferPtr, pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
        }
    }
    else
    {
        /* Input buffers are not properly */
        eStatus = (Std_ReturnType)E_NOT_OK;
    }

#elif defined USE_I3C
    if ((pTxBufferPtr != NULL_PTR) && (pRxBufferPtr == NULL_PTR))
    {
        Request_Tx.Direction = I3C_SEND;
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I3c_AsyncTransfer(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), pTxBufferPtr, (uint8)pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Sbc_Ip_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            (void)pI2cSetupTypePtr->u32Timeout; /* Unused parameter. */
            eStatus = (Std_ReturnType)I3c_SyncTransfer(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), pTxBufferPtr, (uint8)pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
        }
    }
    else if ((pRxBufferPtr != NULL_PTR) && (pTxBufferPtr == NULL_PTR))
    {
        Request_Tx.Direction = I3C_RECEIVE;
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I3c_AsyncTransfer(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), pRxBufferPtr, (uint8)pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Sbc_Ip_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32I2c, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            (void)pI2cSetupTypePtr->u32Timeout; /* Unused parameter. */
            eStatus = (Std_ReturnType)I3c_SyncTransfer(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), pRxBufferPtr, (uint8)pI2cSetupTypePtr->u8NumberOfBytes, &Request_Tx);
        }
    }
    else
    {
        /* Input buffers are not properly */
        eStatus = (Std_ReturnType)E_NOT_OK;
    }

#else
    if ((pTxBufferPtr != NULL_PTR) && (pRxBufferPtr == NULL_PTR))
    {
        eRequest.DataDirection = I2C_SEND_DATA;
        eRequest.DataBuffer = (I2c_DataType *)pTxBufferPtr;
    }
    else if ((pRxBufferPtr != NULL_PTR) && (pTxBufferPtr == NULL_PTR))
    {
        eRequest.DataDirection = I2C_RECEIVE_DATA;
        eRequest.DataBuffer = (I2c_DataType *)pRxBufferPtr;
    }
    else
    {
        /* Input buffers are not properly */
        eStatus = (Std_ReturnType)E_NOT_OK;
    }
    if (eStatus == (Std_ReturnType)E_OK)
    {
        if (FALSE == pI2cSetupTypePtr->bSyncTransmit)
        {
            eStatus = (Std_ReturnType)I2c_AsyncTransmit(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), &eRequest);
            /* Wait until transmision is done */
            eStatus |= (Std_ReturnType)Pmic_VR55XX_WaitForAsyncTransmitEnd(pI2cSetupTypePtr->u32Timeout, pI2cSetupTypePtr->u32Timeout);
        }
        else
        {
            (void)pI2cSetupTypePtr->u32Timeout; /* Unused parameter. */
            eStatus = (Std_ReturnType)I2c_SyncTransmit(((uint8)(0xFFU & pI2cSetupTypePtr->u32I2c)), &eRequest);
        }
    }

#endif

    return eStatus;
}

#define PMIC_STOP_SEC_CODE
#include "Pmic_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @}*/
