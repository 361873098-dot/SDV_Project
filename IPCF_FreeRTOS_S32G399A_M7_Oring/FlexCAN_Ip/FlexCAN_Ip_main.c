/*!
** Copyright 2021 NXP
** @file FlexCAN_Ip_main.c
** @brief
**         FlexCAN AINFC interface module.
**         Provides AINFC_Can_TxMsg / AINFC_Can_RxMsgL and 10ms cyclic
* processing.
**         Supports 2 TX MBs and 2 RX MBs.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
 *                                         MACRO DEFINITIONS
 *==================================================================================================*/

#define ECUM_PERIODIC_TASK_STACK_SIZE (256U) /* 1KB */



/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

#include "FlexCAN_Ip_main.h"
#include "FlexCAN_Ip.h"
#include "Mcal.h"
#include "TJA1145A_Spi_Baremetal.h"

#include <string.h>


/*==================================================================================================
 *                                         GLOBAL VARIABLES
 *==================================================================================================*/

/** TX counters (for debugging) */
volatile uint32 g_canTxCount = 0;
volatile uint32 g_canTxCount2 = 0;

/** RX counters (for debugging) */
volatile uint32 g_canRxCount = 0;
volatile uint32 g_canRxCount2 = 0;

/** Task execution counter (for debugging) */
uint32 EcuM_Period_10ms_cnt = 0;


/*==================================================================================================
 *                                         PRIVATE VARIABLES
 *==================================================================================================*/

/** TX data buffers for 2 TX channels */
static uint8 g_txData0[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
static uint8 g_txData1[8] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18};

static uint8 g_RxData0[8]={0};
static uint8 g_RxData1[8]={0};


/** RX message buffer structures for 2 RX channels */
static Flexcan_Ip_MsgBuffType g_rxBuffer0;
static Flexcan_Ip_MsgBuffType g_rxBuffer1;

/** TX busy flags for each MB */
static volatile boolean g_txBusy[2] = {FALSE, FALSE};

/** RX configured flags for each MB */
static volatile boolean g_rxConfigured[2] = {FALSE, FALSE};

/** TX data info - standard frame, 8 bytes, polling mode */
static const Flexcan_Ip_DataInfoType g_txDataInfo = {.msg_id_type =
                                                         FLEXCAN_MSG_ID_STD,
                                                     .data_length = 8u,
                                                     .is_polling = TRUE,
                                                     .is_remote = FALSE};

/** RX data info - standard frame, 8 bytes, polling mode */
static const Flexcan_Ip_DataInfoType g_rxDataInfo = {.msg_id_type =
                                                         FLEXCAN_MSG_ID_STD,
                                                     .data_length = 8u,
                                                     .is_polling = TRUE,
                                                     .is_remote = FALSE};

/** TX CAN ID lookup table (indexed by MB: 0->MB0, 1->MB1) */
static const uint32 g_txMsgId[2] = {AINFC_TX_MSG_ID_0, AINFC_TX_MSG_ID_1};

/** RX CAN ID lookup table (indexed by RX channel: 0->MB2, 1->MB3) */
static const uint32 g_rxMsgId[2] = {AINFC_RX_MSG_ID_0, AINFC_RX_MSG_ID_1};

/*==================================================================================================
 *                                         PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Initialize FlexCAN Message Buffers for AINFC interface
 */
void FlexCAN_Process_Init(void) {
  /* Configure RX Message Buffer 0 (MB2, ID=0x200) */
  FlexCAN_Ip_ConfigRxMb(0U, AINFC_RX_MB0, &g_rxDataInfo, AINFC_RX_MSG_ID_0);
  FlexCAN_Ip_Receive(0U, AINFC_RX_MB0, &g_rxBuffer0, FALSE);
  g_rxConfigured[0] = TRUE;

  /* Configure RX Message Buffer 1 (MB3, ID=0x201) */
  FlexCAN_Ip_ConfigRxMb(0U, AINFC_RX_MB1, &g_rxDataInfo, AINFC_RX_MSG_ID_1);
  FlexCAN_Ip_Receive(0U, AINFC_RX_MB1, &g_rxBuffer1, FALSE);
  g_rxConfigured[1] = TRUE;

  /* Reset counters and flags */
  g_canTxCount = 0;
  g_canTxCount2 = 0;
  g_canRxCount = 0;
  g_canRxCount2 = 0;
  g_txBusy[0] = FALSE;
  g_txBusy[1] = FALSE;
}

/**
 * @brief Send a CAN message via specified MB
 */
unsigned char AINFC_Can_TxMsg(unsigned char Bus_ID, unsigned char Mbx,
                              unsigned char *msg_frame) {
  Flexcan_Ip_StatusType status;
  uint32 msgId;

  /* Determine CAN ID based on MB index */
  if (Mbx == AINFC_TX_MB0) {
    msgId = g_txMsgId[0];
  } else if (Mbx == AINFC_TX_MB1) {
    msgId = g_txMsgId[1];
  } else {
    return AINFC_CAN_ERROR;
  }

  /* Check if previous TX on this MB completed */
  if (Mbx < 2U && g_txBusy[Mbx]) {
    /* Poll for completion */
    FlexCAN_Ip_MainFunctionWrite((uint8)Bus_ID, Mbx);
    status = FlexCAN_Ip_GetTransferStatus((uint8)Bus_ID, Mbx);
    if (status == FLEXCAN_STATUS_SUCCESS) {
      g_txBusy[Mbx] = FALSE;
      if (Mbx == AINFC_TX_MB0) {
        g_canTxCount++;
      } else {
        g_canTxCount2++;
      }
    } else if (status == FLEXCAN_STATUS_ERROR) {
      g_txBusy[Mbx] = FALSE;
    } else {
      /* Still busy */
      return AINFC_CAN_BUSY;
    }
  }

  /* Send new message */
  status = FlexCAN_Ip_Send((uint8)Bus_ID, Mbx, &g_txDataInfo, msgId,
                           (const uint8 *)msg_frame);
  if (status == FLEXCAN_STATUS_SUCCESS) {
    if (Mbx < 2U) {
      g_txBusy[Mbx] = TRUE;
    }
    return AINFC_CAN_OK;
  } else if (status == FLEXCAN_STATUS_BUSY) {
    return AINFC_CAN_BUSY;
  }

  return AINFC_CAN_ERROR;
}

/**
 * @brief Receive a CAN message from specified MB
 */
unsigned char AINFC_Can_RxMsgL(unsigned char Bus_ID, unsigned char Mbx,
                               unsigned char *msg_frame) {
  Flexcan_Ip_StatusType status;
  Flexcan_Ip_MsgBuffType *pRxBuf;
  uint8 rxIdx; /* 0 or 1 for internal arrays */

  /* Map MB index to internal RX channel */
  if (Mbx == AINFC_RX_MB0) {
    rxIdx = 0U;
    pRxBuf = &g_rxBuffer0;
  } else if (Mbx == AINFC_RX_MB1) {
    rxIdx = 1U;
    pRxBuf = &g_rxBuffer1;
  } else {
    return AINFC_CAN_ERROR;
  }

  /* Check if RX is configured */
  if (!g_rxConfigured[rxIdx]) {
    return AINFC_CAN_ERROR;
  }

  /* Poll for received message */
  FlexCAN_Ip_MainFunctionRead((uint8)Bus_ID, Mbx);

  /* Check RX status */
  status = FlexCAN_Ip_GetTransferStatus((uint8)Bus_ID, Mbx);

  if (status == FLEXCAN_STATUS_SUCCESS) {
    /* Message received - copy data to output buffer */
    uint8 i;
    uint8 len = pRxBuf->dataLen;
    if (len > 8U) {
      len = 8U;
    }
    for (i = 0; i < len; i++) {
      msg_frame[i] = pRxBuf->data[i];
    }
    /* Zero-fill remaining bytes */
    for (; i < 8U; i++) {
      msg_frame[i] = 0U;
    }

    /* Update counter */
    if (rxIdx == 0U) {
      g_canRxCount++;
    } else {
      g_canRxCount2++;
    }

    /* Re-configure RX for next message */
    FlexCAN_Ip_Receive((uint8)Bus_ID, Mbx, pRxBuf, FALSE);

    return AINFC_CAN_OK;
  } else if (status == FLEXCAN_STATUS_ERROR) {
    /* RX error - re-configure */
    FlexCAN_Ip_Receive((uint8)Bus_ID, Mbx, pRxBuf, FALSE);
    return AINFC_CAN_ERROR;
  }

  /* FLEXCAN_STATUS_BUSY - no new message */
  return AINFC_CAN_NO_MSG;
}

/**
 * @brief 10ms periodic CAN processing
 *
 * Handles 2 TX and 2 RX message cyclic processing.
 */
void AINFC_Can_Cyclic_10ms(void) {
  /* ====================================================================
   * RX Processing - poll both RX MBs
   * ==================================================================== */

  /* RX MB0 (ID=0x200) */
  (void)AINFC_Can_RxMsgL(0U, AINFC_RX_MB0, g_RxData0);

  /* RX MB1 (ID=0x201) */
  (void)AINFC_Can_RxMsgL(0U, AINFC_RX_MB1, g_RxData1);

  /* ====================================================================
   * TX Processing - send on both TX MBs
   * ==================================================================== */

  /* TX MB0 (ID=0x100): update data with counter */
  g_txData0[0] = (uint8)(g_canTxCount & 0xFFU);
  g_txData0[1] = (uint8)((g_canTxCount >> 8) & 0xFFU);
  (void)AINFC_Can_TxMsg(0U, AINFC_TX_MB0, g_txData0);

  /* TX MB1 (ID=0x101): update data with counter */
  g_txData1[0] = (uint8)(g_canTxCount2 & 0xFFU);
  g_txData1[1] = (uint8)((g_canTxCount2 >> 8) & 0xFFU);
  (void)AINFC_Can_TxMsg(0U, AINFC_TX_MB1, g_txData1);
}





/*==================================================================================================
 *										   PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief 10ms Periodic Task
 */
void AINFC_CAN_Period_10ms_Task(void *pvParameters) 
{
  TickType_t xLastWakeTime;
  const TickType_t xPeriod = pdMS_TO_TICKS(10); /* 10ms period */

  (void)pvParameters;

  /* Initialize the xLastWakeTime variable with current time */
  xLastWakeTime = xTaskGetTickCount();

  for (;;) {
	EcuM_Period_10ms_cnt++;

	/* ====================================================================
	 * TJA1145 Periodic Test (every 100ms = every 10 iterations)
	 * For SPI waveform debugging with oscilloscope
	 * ==================================================================== */
	if ((EcuM_Period_10ms_cnt % 10U) == 0U) {
	  Spi_Baremetal_Tja1145_PeriodicTest();
	}

	/* ====================================================================
	 * AINFC CAN Periodic Processing (2 TX + 2 RX)
	 * ==================================================================== */
	AINFC_Can_Cyclic_10ms();

	/* ====================================================================
	 * Wait until next 10ms period - allows lower priority tasks to run
	 * ==================================================================== */
	vTaskDelayUntil(&xLastWakeTime, xPeriod);
  }
}


void AINFC_CAN_Main_task(void) 
{

	BaseType_t os_status;

	/* ========================================================================
	 * Create EcuM_Period_10ms_Task (periodic task)
	 * Priority 2 - runs after RX task processes messages
	 * ======================================================================== */
	os_status = xTaskCreate((TaskFunction_t)AINFC_CAN_Period_10ms_Task, "ANIFC_CAN_10ms",
							ECUM_PERIODIC_TASK_STACK_SIZE, NULL,
							tskIDLE_PRIORITY + 2, NULL);
	if (os_status != pdPASS) {
	  while (1) {
	  }
	}

}


#ifdef __cplusplus
}
#endif

/* END FlexCAN_Ip_main */
/*!
** @}
*/
