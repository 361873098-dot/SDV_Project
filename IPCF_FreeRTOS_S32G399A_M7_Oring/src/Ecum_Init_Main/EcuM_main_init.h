/**
 * @file EcuM_main_init.h
 * @brief EcuM Initialization Module Header
 *
 * Provides unified initialization management following AUTOSAR EcuM pattern.
 * Separates PreOS (hardware) initialization from PostOS (RTOS-dependent)
 * initialization.
 */

#ifndef ECUM_MAIN_INIT_H
#define ECUM_MAIN_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         FUNCTION PROTOTYPES
 *==================================================================================================*/

/**
 * @brief Pre-OS Initialization
 *
 * Performs all hardware initialization before RTOS scheduler starts:
 * - Clock initialization
 * - Platform initialization (includes interrupt controller)
 * - Port/GPIO initialization
 * - DMA initialization
 * - SPI initialization
 * - TJA1145A CAN transceiver initialization
 *
 * @note Must be called before EcuM_StartOS()
 */
void EcuM_PreOS_Init(void);

/**
 * @brief Start RTOS and create tasks
 *
 * Creates all application tasks and starts the RTOS scheduler:
 * - EcuM_PostOS_Init_Task (priority 4) - One-time RTOS-dependent init (PICC
 * module)
 * - PICC_Rx_Msg_Task (priority 3) - IPCF RX message processing
 * - EcuM_Period_10ms_Task (priority 2) - Periodic task (CAN, PICC, Power SM)
 *
 * @note This function does not return (scheduler takes over)
 */
void EcuM_StartOS(void);

#ifdef __cplusplus
}
#endif

#endif /* ECUM_MAIN_INIT_H */
