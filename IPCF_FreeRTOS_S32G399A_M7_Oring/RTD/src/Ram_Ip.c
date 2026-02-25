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
*   @file       Ram_Ip.c
*   @version    4.0.2
*
*   @brief   RAM driver implementations.
*   @details RAM driver implementations.
*
*   @addtogroup RAM_DRIVER Ram Ip Driver
*   @{
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
#include "Ram_Ip.h"
#include "OsIf.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RAM_IP_VENDOR_ID_C                      43
#define RAM_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define RAM_IP_AR_RELEASE_MINOR_VERSION_C       4
#define RAM_IP_AR_RELEASE_REVISION_VERSION_C    0
#define RAM_IP_SW_MAJOR_VERSION_C               4
#define RAM_IP_SW_MINOR_VERSION_C               0
#define RAM_IP_SW_PATCH_VERSION_C               2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same vendor */
#if (RAM_IP_VENDOR_ID_C != RAM_IP_VENDOR_ID)
    #error "Ram_Ip.c and Ram_Ip.h have different vendor ids"
#endif

/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same Autosar version */
#if ((RAM_IP_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_AR_RELEASE_MINOR_VERSION_C != RAM_IP_AR_RELEASE_MINOR_VERSION) || \
     (RAM_IP_AR_RELEASE_REVISION_VERSION_C != RAM_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ram_Ip.c and Ram_Ip.h are different"
#endif

/* Check if Ram_Ip.c file and Ram_Ip.h file are of the same Software version */
#if ((RAM_IP_SW_MAJOR_VERSION_C != RAM_IP_SW_MAJOR_VERSION) || \
     (RAM_IP_SW_MINOR_VERSION_C != RAM_IP_SW_MINOR_VERSION) || \
     (RAM_IP_SW_PATCH_VERSION_C != RAM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ram_Ip.c and Ram_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Ram_Ip.c file and OsIf.h file are of the same Autosar version */
#if ((RAM_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_IP_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ram_Ip.c and OsIf.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (RAM_IP_GET_RAM_STATE_API == STD_ON)
static void Ram_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs);
static boolean Ram_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);

static void Ram_Ip_ReportRamErrorsEmptyCallback(Ram_Ip_RamReportErrorType Error, uint8 ErrorCode);
static void Ram_Ip_ReportRamErrors(Ram_Ip_RamReportErrorType Error, uint8 ErrorCode);
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#if (RAM_IP_GET_RAM_STATE_API == STD_ON)

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Ram Report Error Callback */
static Ram_Ip_ReportErrorsCallbackType Ram_Ip_pfReportErrorsCallback = Ram_Ip_ReportRamErrorsEmptyCallback;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#endif /* (RAM_IP_GET_RAM_STATE_API == STD_ON) */
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
#if (RAM_IP_GET_RAM_STATE_API == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Ram_Ip_StartTimeout
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
static void Ram_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs)
{
    *StartTimeOut    = OsIf_GetCounter(RAM_IP_TIMEOUT_TYPE);
    *ElapsedTimeOut  = 0U;
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, RAM_IP_TIMEOUT_TYPE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Ram_Ip_TimeoutExpired
 * Description   : Checks for timeout expiration condition
 *
 *END**************************************************************************/
static boolean Ram_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks)
{
    boolean RetVal = FALSE;
    *ElapsedTimeInOut += OsIf_GetElapsed(StartTimeInOut, RAM_IP_TIMEOUT_TYPE);

    if (*ElapsedTimeInOut >= TimeoutTicks)
    {
        RetVal = TRUE;
    }
    return RetVal;
}
#endif

#if (RAM_IP_GET_RAM_STATE_API == STD_ON)
static void Ram_Ip_ReportRamErrorsEmptyCallback(Ram_Ip_RamReportErrorType Error, uint8 ErrorCode)
{
    /* No implementation */
    (void)Error;
    (void)ErrorCode;
}

/* Report Ram errors */
static void Ram_Ip_ReportRamErrors(Ram_Ip_RamReportErrorType Error, uint8 ErrorCode)
{
    Ram_Ip_pfReportErrorsCallback(Error, ErrorCode);
}
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function initializes a given RAM section of the MCU on the common (main) platform.
* @details          Function initializes the RAM section specified by the pointer to the "Mcu_RamConfigType" parameter.
*                   The section's base address, size, value to be written, and write-at-once-size are provided by
*                   the configuration structure.
*                   The function will write the value specified in the configuration structure.
*                   After the write it will read back the RAM to verify that the requested value was
*                   written.
*                   Called by:
*                       - Mcu_InitRamSection() from HLD.
*
* @param[in]        RamConfigPtr   Pointer to RAM section configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           Status signaling if the given RAM section has or has not been successfully initialized.
* @retval           RAM_IP_STATUS_OK        The RAM section check was successful.
* @retval           RAM_IP_STATUS_NOT_OK    The RAM section check was not successful.
*
* @implements Ram_Ip_InitRamSection_Activity
*
*/
Ram_Ip_StatusType Ram_Ip_InitRamSection(const Ram_Ip_RamConfigType * RamConfigPtr)
{
    /* Result of the operation. */
    Ram_Ip_StatusType RamStatus = RAM_IP_STATUS_OK;
    /* Variable for indexing RAM sections. */
    Ram_Ip_RamIndexType RamCounter;
    /* Limit of RamCounter. */
    Ram_Ip_RamSizeType RamCounterLimit;

    RAM_IP_DEV_ASSERT(NULL_PTR != RamConfigPtr);

    RamCounterLimit = (Ram_Ip_RamSizeType)( ((Ram_Ip_RamSizeType)(RamConfigPtr->RamSize)) / (RamConfigPtr->RamWriteSize) );

    RamStatus = RAM_IP_STATUS_OK;
    RamCounter = (Ram_Ip_RamIndexType)0UL;
    while ((RamCounter < RamCounterLimit) && (RAM_IP_STATUS_OK == RamStatus))
    {
        switch (RamConfigPtr->RamWriteSize)
        {
            case (Ram_Ip_RamWriteSizeType)1U:

                ( *((uint8 (*)[1U]) ((uint32) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter]  = (uint8) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)2U:

                ( *((uint16 (*)[1U]) ((uint32) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint16) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)4U:

                ( *((uint32 (*)[1U]) ((uint32) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint32) RamConfigPtr->RamDefaultValue;
                break;

            case (Ram_Ip_RamWriteSizeType)8U:

                ( *((uint64 (*)[1U]) ((uint32) RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] = (uint64) RamConfigPtr->RamDefaultValue;
                break;

            default:
                RamStatus = RAM_IP_STATUS_NOT_OK;
                break;
        }
        RamCounter++;
    }

    if ( RAM_IP_STATUS_OK == RamStatus )
    {
        RamCounter = (Ram_Ip_RamIndexType)0UL;
        /* Check if RAM was initialized correctly. */
        while ((RamCounter < RamCounterLimit) && (RAM_IP_STATUS_OK == RamStatus))
        {
            switch (RamConfigPtr->RamWriteSize)
            {
                case (Ram_Ip_RamWriteSizeType)1U:

                    if ( (uint8) RamConfigPtr->RamDefaultValue  != ( *((uint8 (*)[1U]) ((uint32)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)2U:

                    if ( (uint16) RamConfigPtr->RamDefaultValue != ( *((uint16 (*)[1U]) ((uint32)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)4U:

                    if ( (uint32) RamConfigPtr->RamDefaultValue != ( *((uint32 (*)[1U]) ((uint32)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                case (Ram_Ip_RamWriteSizeType)8U:

                    if ( (uint64) RamConfigPtr->RamDefaultValue != ( *((uint64 (*)[1U]) ((uint32)RamConfigPtr->RamBaseAddrPtr)) )[RamCounter] )
                    {
                        RamStatus = RAM_IP_STATUS_NOT_OK;
                    }
                    break;

                default:
                    RamStatus = RAM_IP_STATUS_NOT_OK;
                    break;
            }
            RamCounter++;
        }
    }

    return RamStatus;
}
#if (RAM_IP_GET_RAM_STATE_API == STD_ON)
/**
* @brief            This service provides the actual status of the microcontroller Ram. (if supported)
* @details
*
* @param[in]        void
*
* @return           State of RAM
*
* @implements Ram_Ip_GetRamState_Activity
*
*/
Ram_Ip_RamStateType Ram_Ip_GetRamState(void)
{
    Ram_Ip_RamStateType RamState = RAM_IP_RAMSTATE_INVALID;
    uint32 TempReg;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;

    /* Stay in this loop until these registers are automatically updated following the
     * completion of the MBIST run. */
    Ram_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, RAM_IP_TIMEOUT_VALUE_US);
    do
    {
        TimeoutOccurred = Ram_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        TempReg = IP_STCU2->MBESW[0];
    } while ( (STCU2_MBESW0_RAM_TEST_MASK32 != (TempReg & STCU2_MBESW0_RAM_TEST_MASK32)) && (!TimeoutOccurred) );

    if (!TimeoutOccurred)
    {
        TempReg = IP_STCU2->MBSSW[0];
        if (STCU2_MBSSW0_RAM_TEST_MASK32 == (TempReg & STCU2_MBSSW0_RAM_TEST_MASK32))
        {
            RamState = RAM_IP_RAMSTATE_VALID;
        }
    }
    else
    {
        /* report callback here */
        Ram_Ip_ReportRamErrors(RAM_IP_REPORT_TIMEOUT_ERROR,RAM_IP_ERR_CODE_RESERVED);
    }

    return RamState;
}
#endif

#if (RAM_IP_GET_RAM_STATE_API == STD_ON)
/**
* @brief            This function installs a callback for reporting errors from Ram driver.
* @details
*
* @param[in]        ReportErrorsCallback    Callback to be installed.
*
* @return           void
*
* @implements Ram_Ip_InstallNotificationsCallback_Activity
*/
void Ram_Ip_InstallNotificationsCallback(Ram_Ip_ReportErrorsCallbackType ReportErrorsCallback)
{
    RAM_IP_DEV_ASSERT(NULL_PTR != ReportErrorsCallback);
    Ram_Ip_pfReportErrorsCallback = ReportErrorsCallback;
}
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

