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

/* MCU/Platform includes */
#include "Clock_Ip.h"
#include "Clock_Ip_PBcfg.h"
#include "IntCtrl_Ip.h"
#include "Mcal.h"
#include "Platform.h"
#include "Siul2_Port_Ip.h"
// #include "Siul2_Port_Ip_Cfg.h"
/* Bare-metal SPI driver (direct register control) */
#include "Spi_Baremetal.h"

/* TJA1145A CAN transceiver - now handled by Spi_Baremetal */
/* #include "Tja1145A_main.h" */

/* FlexCAN module */
#include "FlexCAN_Ip.h"
#include "FlexCAN_Ip_Sa_PBcfg.h"
#include "FlexCAN_Ip_main.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

/* EcuM module headers */
#include "EcuM_main_init.h"
#include "Ecum_Period_task.h"

/*==================================================================================================
 *                                         MACRO DEFINITIONS
 *==================================================================================================*/

/** Task stack sizes */
#define ECUM_INIT_TASK_STACK_SIZE (256U)     /* 1KB */
#define ECUM_RX_TASK_STACK_SIZE (192U)       /* 768B */
#define ECUM_PERIODIC_TASK_STACK_SIZE (256U) /* 1KB */

/** FlexCAN instance */
#define FLEXCAN_INST 0U

/*==================================================================================================
 *                                         EXTERNAL DECLARATIONS
 *==================================================================================================*/

/* CAN IRQ handler - defined in FlexCAN_Ip_Irq.c */
extern void CAN0_ORED_0_7_MB_IRQHandler(void);

/* PICC tasks - defined in Picc_main.c */
extern void PICC_ModuleInit(void);

/*==================================================================================================
 *                                         PRIVATE VARIABLES
 *==================================================================================================*/

/** Exit code for main loop */
volatile uint8 exit_code = 0;

/*==================================================================================================
 *                                         INIT DEBUG VARIABLES
 *==================================================================================================*/
/* Debug variables for initialization verification - readable in debugger */
typedef struct {
  Clock_Ip_StatusType clock_status;
  boolean tja1145_baremetal_result; /* Bare-metal SPI TJA1145 init result */
  Flexcan_Ip_StatusType flexcan_status;
  uint8 init_step; /* Current init step (1-10) */
} EcuM_InitDebug_t;

volatile EcuM_InitDebug_t g_EcuM_InitDebug = {0};

/*==================================================================================================
 *                                         PRIVATE FUNCTION PROTOTYPES
 *==================================================================================================*/

static void EcuM_PostOS_Init_Task(void *params);

/*==================================================================================================
 *                                         PUBLIC FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Pre-OS Initialization
 */
void EcuM_PreOS_Init(void) {
  /* ========================================================================
   * 1. Clock Initialization - MUST be first
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 1U;
  g_EcuM_InitDebug.clock_status = Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

  /* ========================================================================
   * 2. Platform Initialization (includes IntCtrl_Ip_Init internally)
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 2U;
  Platform_Init(NULL_PTR);

  /* ========================================================================
   * 3. Port/GPIO Initialization
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 3U;
  Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

  /* ========================================================================
   * 4. SPI CS Pin Note: PK_11 is configured as hardware PCS0 (PORT_MUX_ALT5)
   *    The SPI peripheral automatically controls CS - no manual init needed
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 4U;

  /* ========================================================================
   * 5. DMA Initialization (required before SPI)
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 5U;

  /* ========================================================================
   * 6. SPI Initialization - Using BARE-METAL driver (direct register control)
   * This directly configures DSPI5 pins and registers
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 6U;

  /* Enable DSPI5 clock before accessing its registers */
  g_EcuM_InitDebug.init_step = 60U; /* Debug: about to enable clock */
  Clock_Ip_EnableModuleClock(SPI5_CLK);
  g_EcuM_InitDebug.init_step = 61U; /* Debug: clock enabled */

  /* Initialize bare-metal SPI with correct pin configuration */
  /* This will set PK_14 to ALT3 (not GPIO!) and configure IMCR1007 */
  Spi_Baremetal_Init(2U); /* Prescaler = 2 for ~1MHz SPI clock */

  /* ========================================================================
   * 7. TJA1145A CAN Transceiver Initialization - Using BARE-METAL SPI
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 7U;

  /* Bare-metal TJA1145 initialization */
  /* Spi_Baremetal_Tja1145_Init returns 0 on success, non-zero on failure */
  g_EcuM_InitDebug.tja1145_baremetal_result =
      (Spi_Baremetal_Tja1145_Init() == 0U) ? TRUE : FALSE;

  /* ========================================================================
   * 8. FlexCAN Interrupt Handler Installation this two function can be deleted
   because Platform_Init has  been init for this INT;
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 8U;
  // IntCtrl_Ip_EnableIrq(CAN0_ORED_0_7_MB_IRQn);
  //  IntCtrl_Ip_InstallHandler(CAN0_ORED_0_7_MB_IRQn,
  //  CAN0_ORED_0_7_MB_IRQHandler,NULL_PTR);

  /* ========================================================================
   * 9. FlexCAN Module Initialization
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 9U;
  g_EcuM_InitDebug.flexcan_status =
      FlexCAN_Ip_Init(FLEXCAN_INST, &FlexCAN_State0, &FlexCAN_Config0);
  FlexCAN_Ip_SetStartMode(FLEXCAN_INST);

  /* ========================================================================
   * 10. FlexCAN Message Buffer Configuration
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 10U;
  FlexCAN_Process_Init();

  /* ========================================================================
   * 11. TJA1145 CAN Active Mode - MUST be after FlexCAN init
   *     TXD must be HIGH (recessive) when CMC is set, otherwise TJA1145
   *     enters Listen-only mode instead of Active mode.
   * ======================================================================== */
  g_EcuM_InitDebug.init_step = 11U;
  Spi_Baremetal_Tja1145_SetCanActive();
}

/**
 * @brief Start RTOS and create tasks
 */
void EcuM_StartOS(void) {
  BaseType_t os_status;

  /* ========================================================================
   * Create EcuM_PostOS_Init_Task (high priority, runs first then deletes)
   * ======================================================================== */
  os_status = xTaskCreate((TaskFunction_t)EcuM_PostOS_Init_Task, "EcuM_Init",
                          ECUM_INIT_TASK_STACK_SIZE, NULL,
                          tskIDLE_PRIORITY + 4, /* Highest priority for init */
                          NULL);
  if (os_status != pdPASS) {
    /* Handle error - block indefinitely */
    while (1) {
    }
  }

  /* ========================================================================
   * Create EcuM_Period_10ms_Task (periodic task)
   * Priority 2 - runs after RX task processes messages
   * ======================================================================== */
  os_status = xTaskCreate((TaskFunction_t)EcuM_Period_10ms_Task, "EcuM_10ms",
                          ECUM_PERIODIC_TASK_STACK_SIZE, NULL,
                          tskIDLE_PRIORITY + 2, NULL);
  if (os_status != pdPASS) {
    while (1) {
    }
  }

  /* ========================================================================
   * Start RTOS scheduler - this function does not return
   * ======================================================================== */
  vTaskStartScheduler();
}

/*==================================================================================================
 *                                         PRIVATE FUNCTIONS
 *==================================================================================================*/

/**
 * @brief Post-OS Initialization Task
 *
 * Performs RTOS-dependent initialization, then deletes itself.
 * This includes PICC module initialization which requires queues.
 */
static void EcuM_PostOS_Init_Task(void *params) {
  (void)params;

  /* ========================================================================
   * Add other RTOS-dependent module initializations here in the future
   * ======================================================================== */

  /* ========================================================================
   * Initialization complete - delete this task
   * ======================================================================== */
  vTaskDelete(NULL);
}

/*==================================================================================================
 *                                         FreeRTOS Hooks
 *==================================================================================================*/

void vApplicationMallocFailedHook(void) {
  taskDISABLE_INTERRUPTS();
  while (1) {
    /* block indefinitely */
  }
}

/* ============================================================================
 * Stack overflow diagnostic variables (for TRACE32)
 * ============================================================================
 */
typedef struct {
  char task_name[configMAX_TASK_NAME_LEN]; /* Overflowed task name */
  uint32_t overflow_count;                 /* Overflow count */
  uint32_t sp_value;                       /* Stack pointer value */
  uint32_t lr_value;                       /* Return address */
  uint32_t timestamp;                      /* Overflow timestamp */
} StackOverflowInfo_t;

static volatile StackOverflowInfo_t g_stack_overflow_info = {0};

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
  (void)pxTask;

  /* Save overflowed task info */
  if (pcTaskName != NULL) {
    uint32_t i;
    for (i = 0; i < configMAX_TASK_NAME_LEN - 1 && pcTaskName[i] != '\0'; i++) {
      g_stack_overflow_info.task_name[i] = pcTaskName[i];
    }
    g_stack_overflow_info.task_name[i] = '\0';
  } else {
    g_stack_overflow_info.task_name[0] = '?';
    g_stack_overflow_info.task_name[1] = '\0';
  }

  /* Record overflow count */
  g_stack_overflow_info.overflow_count++;

  /* Save stack pointer */
  register uint32_t sp_reg __asm("sp");
  g_stack_overflow_info.sp_value = sp_reg;

  /* Save LR */
  register uint32_t lr_reg __asm("lr");
  g_stack_overflow_info.lr_value = lr_reg;

  /* Save timestamp (if available) */
  g_stack_overflow_info.timestamp = xTaskGetTickCount();

  /* Disable interrupts */
  taskDISABLE_INTERRUPTS();

/* Trigger debugger breakpoint */
#ifdef DEBUG
  __asm volatile("BKPT #1"); /* Breakpoint 1 = stack overflow */
#endif

  while (1) {
    /* Stack overflow!
     * View variable g_stack_overflow_info in TRACE32:
     * - task_name: which task overflowed
     * - overflow_count: overflow count
     * - sp_value: SP register value
     * - lr_value: LR register value
     * - timestamp: overflow time
     */
  }
}

/*==================================================================================================
 *										   main()
 * Entry
 *==================================================================================================*/

/**
 * @brief Application entry point
 */
int main(void) {
  /* Pre-OS Hardware Initialization */
  EcuM_PreOS_Init();

  /* Start RTOS and create tasks */
  EcuM_StartOS();

  /* Main loop (normally won't reach here - scheduler takes over) */
  for (;;) {
    /* Idle loop */
  }

  return 0;
}

#ifdef __cplusplus
}
#endif
