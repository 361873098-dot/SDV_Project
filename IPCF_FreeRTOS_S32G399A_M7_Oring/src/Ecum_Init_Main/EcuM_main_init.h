/**
 * @file EcuM_main_init.h
 * @brief EcuM Initialization Module Header
 *
 * Provides unified initialization management following AUTOSAR EcuM pattern.
 * Separates PreOS (hardware) initialization from PostOS (RTOS-dependent)
 * initialization.
 *
 * The main() function in EcuM_main_init.c implements:
 *   Phase 1: PreOS hardware driver initialization
 *   Phase 2: PreOS communication middleware initialization (PICC_PreOS_Init)
 *   Phase 3: PostOS task creation and scheduler start (OsTask_Creation_All)
 */

#ifndef ECUM_MAIN_INIT_H
#define ECUM_MAIN_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

/* No public API functions — main() is the entry point */

#ifdef __cplusplus
}
#endif

#endif /* ECUM_MAIN_INIT_H */
