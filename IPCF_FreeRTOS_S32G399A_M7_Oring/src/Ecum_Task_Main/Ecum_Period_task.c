/**
 * @file Ecum_Period_task.c
 * @brief EcuM Periodic Task Module Implementation
 *
 * Unified periodic task management for all modules.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

#include "Ecum_Period_task.h"

/* Standard types */
#include "Mcal.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"

/* FlexCAN periodic processing */
#include "FlexCAN_Ip_main.h"

/* Bare-metal SPI TJA1145 periodic test */
#include "Spi_Baremetal.h"

/*==================================================================================================
 *                                         GLOBAL VARIABLES
 *==================================================================================================*/

/** Task execution counter (for debugging) */
uint32 EcuM_Period_10ms_cnt = 0;

/*==================================================================================================
 *                                         PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief 10ms Periodic Task
 */
void EcuM_Period_10ms_Task(void *pvParameters) {
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

#ifdef __cplusplus
}
#endif
