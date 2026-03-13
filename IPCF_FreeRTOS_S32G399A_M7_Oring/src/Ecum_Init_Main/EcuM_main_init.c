/**
 * @file EcuM_main_init.c
 * @brief EcuM Initialization Module Implementation
 *
 * Unified initialization management following AUTOSAR EcuM pattern.
 * Implements the hybrid architecture with PreOS/PostOS separation.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

/* EcuM module headers */

#include "EcuM_main_init.h"
#include "EcuM_CpuLoadTest.h"

/* RTD Drivers Headers */
#include "CDD_I2c.h"
#include "Clock_Ip.h"
#include "FlexCAN_Ip.h"
#include "Platform.h"
#include "Port.h"
#include "Siul2_Port_Ip.h"

/* Generated headers */
#include "Clock_Ip_PBcfg.h"
#include "FlexCAN_Ip_Sa_PBcfg.h"
#include "Siul2_Port_Ip_Cfg.h"

/* Application headers */
#include "FlexCAN_Ip_main.h"
#include "Pmic_driver_main.h"
#include "TJA1145A_Spi_Baremetal.h"
#include "picc_main.h"

/* FreeRTOS headers (for diagnostics) */
#include "FreeRTOS.h"
#include "task.h"
#include "Mcu.h"

#include <string.h>


/*==================================================================================================
 *										   main()
 * Entry
 *==================================================================================================*/

/**
 * @brief Application entry point
 */
int main(void) {
  /* Initialize diagnostic subsystem (must be first, before any RTOS call) */
  EcuM_Diag_Init();

  /* CPU load stress-test (only active when ECUM_CPULOAD_TEST_ENABLE == 1) */
  EcuM_CpuLoadTest_Init();
  /* Initialize the Mcu driver */
   Mcu_Init(NULL_PTR);



  /* Platform initialization */
  Platform_Init(NULL_PTR);

  /* Initialize pins */
  Port_Init(NULL_PTR);

 // Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

  /* Initialize I2c driver */
  I2c_Init(NULL_PTR);

  Pmic_driver_init();

  Clock_Ip_EnableModuleClock(SPI5_CLK);

  Spi_Baremetal_Init(2U); /* Prescaler = 2 for ~1MHz SPI clock */

  Spi_Baremetal_Tja1145_Init();

  FlexCAN_Ip_Init(FLEXCAN_INST, &FlexCAN_State0, &FlexCAN_Config0);

  FlexCAN_Ip_SetStartMode(FLEXCAN_INST);

  FlexCAN_Process_Init();

  Spi_Baremetal_Tja1145_SetCanActive();

  AINFC_CAN_Main_task();

  /* Start main task */
  PICC_Mian_Task();

  /* Main loop (normally won't reach here - scheduler takes over) */
  for (;;) {
    /* Idle loop */
  }

  return 0;
}

#ifdef __cplusplus
}
#endif
