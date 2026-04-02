/**
 * @file EcuM_main_init.c
 * @brief EcuM Initialization Module Implementation
 *
 * Unified initialization management following AUTOSAR EcuM pattern.
 * Implements the hybrid architecture with PreOS/PostOS separation.
 *
 * Boot sequence:
 *   main()
 *   ├── PreOS: Hardware driver initialization (Clock, GPIO, SPI, I2C, PMIC)
 *   ├── PreOS: Communication initialization (FlexCAN, TJA1145, IPCF/PICC)
 *   └── PostOS: OsTask_Creation_All() → vTaskStartScheduler()
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES
 *==================================================================================================*/

/* EcuM module headers */

#include "EcuM_main_init.h"
#include "System_CpuLoadTest.h"

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
#include "pwsm.h"
#include "diag_mgmt.h"

/* FreeRTOS headers */
#include "FreeRTOS.h"
#include "task.h"
#include "Mcu.h"

#include <string.h>
#include "System_Cpuload.h"

/* Centralized task management */
#include "Ostask_main.h"

/** FlexCAN instance */
#define FLEXCAN_INST 0U

/*==================================================================================================
 *                                  PRIVATE FUNCTION DECLARATIONS
 *==================================================================================================*/

static void App_Init_All(void);

/*==================================================================================================
 *                                  PRIVATE FUNCTION DEFINITIONS
 *==================================================================================================*/

static void App_Init_All(void)
{
  /* Register application-level PICC endpoints after middleware is ready. */
  Pwsm_Init();
  DiagMgmt_Init();
  //OTA_Init();
}

/*==================================================================================================
 *                                         main()
 * Entry
 *==================================================================================================*/

/**
 * @brief Application entry point
 *
 * Executes initialization in strict order:
 *   Phase 1 (PreOS): Hardware drivers — no RTOS dependency
 *   Phase 2 (PreOS): Communication middleware — creates IPCF softirq task
 *                     (valid before scheduler) and registers callbacks
 *   Phase 3 (PreOS): Application initialization on top of middleware
 *   Phase 4 (PostOS): Creates application tasks and starts scheduler
 */
int main(void) {
  /* ==================================================================
   * Phase 1: PreOS — Hardware & Driver Initialization
   * ================================================================== */

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

  /* Initialize I2c driver */
  I2c_Init(NULL_PTR);

  /* Initialize PMIC */
  Pmic_driver_init();

  /* Enable SPI5 clock for TJA1145 */
  Clock_Ip_EnableModuleClock(SPI5_CLK);

  /* Initialize SPI bare-metal driver */
  Spi_Baremetal_Init(2U); /* Prescaler = 2 for ~1MHz SPI clock */

  /* Initialize TJA1145 CAN transceiver */
  Spi_Baremetal_Tja1145_Init();

  /* Initialize FlexCAN driver */
  FlexCAN_Ip_Init(FLEXCAN_INST, &FlexCAN_State0, &FlexCAN_Config0);
  FlexCAN_Ip_SetStartMode(FLEXCAN_INST);

  /* Configure FlexCAN Message Buffers (TX/RX) */
  FlexCAN_Process_Init();

  /* Activate TJA1145 CAN mode */
  Spi_Baremetal_Tja1145_SetCanActive();

  /* ==================================================================
   * Phase 2: PreOS — Communication Middleware Initialization
   *
   * PICC_PreOS_Init() performs:
   *   - Creates RX queue (xQueueCreate — valid before scheduler)
   *   - Initializes IPCF driver (ipc_shm_init internally creates
   *     softirq task via xTaskCreate — valid before scheduler)
   *   - Initializes PICC channels, services, and link
   *   - Initializes power management module
   *   - Registers callbacks
   * ================================================================== */
  PICC_PreOS_Init();

  /* ==================================================================
    * Phase 3: PreOS — Application Initialization
    *
    * App_Init_All() performs:
    *   - Registers application-level communication endpoints
    *   - Keeps application initialization out of task creation
    * ================================================================== */
    App_Init_All();

    /* ==================================================================
    * Phase 4: PostOS — Create Tasks & Start Scheduler
   *
   * OsTask_Creation_All() creates:
   *   - OS_10ms    (priority 2): Unified periodic task
   *   - App_Rx_Msg (priority 3): IPCF RX queue processing
   * Then calls vTaskStartScheduler() — does NOT return.
   * ================================================================== */
  OsTask_Creation_All();

  /* Main loop (should never reach here - scheduler takes over) */
  for (;;) {
    /* Idle loop */
  }

  return 0;
}

#ifdef __cplusplus
}
#endif
