/**
 * @file Picc_main.h
 * @brief M-Core Inter-Core Communication Application - Header File
 *
 * IPC Shared Memory Driver application with PICC middleware.
 *
 * Copyright 2020-2024 NXP
 * All Rights Reserved.
 */

#ifndef PMIC_DRIVER_MAIN_H
#define PMIC_DRIVER_MAIN_H

#if defined(__cplusplus)
extern "C"{
#endif



/*==================================================================================================
 *                                         Function Declarations
 *==================================================================================================*/

/**
 * @brief Prepare and start main task
 */
void Pmic_driver_init(void);


#if defined(__cplusplus)
}
#endif

#endif /* MAIN_H */


