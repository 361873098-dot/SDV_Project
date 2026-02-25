/**
 * @file main.c
 * @brief M-Core Inter-Core Communication Application - Main Program
 *
 * IPC Shared Memory Driver application with PICC middleware.
 * Integrates PICC inter-core communication middleware module for A-Core communication.
 *
 * Copyright 2024 NXP
 * All Rights Reserved.
 */

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
 *                                         Header Includes
 *==================================================================================================*/
 #include "Mcu.h"
/* MCU/Platform initialization */
#include "CDD_Pmic.h"
#include "CDD_I2c.h"

/* Application headers */
#include "Picc_main.h"

/*==================================================================================================
 *                                         Macro Definitions
 *==================================================================================================*/

/** Wait timeout */
#define WAIT_TIMEOUT (1000U / portTICK_PERIOD_MS)

/*==================================================================================================
 *                                         Private Variables
 *==================================================================================================*/
uint16 read_m_deviceid;
uint16 read_m_mode;
uint16 read_m_flag1;
uint16 read_m_flag2;
uint16 read_m_flag3_0;
uint16 read_m_flag3;
uint16 read_fs_state;
uint16 read_m_otp_vpre;
uint32 TestLoopCnt = 999999999;
uint32 loop_cnt = 0;



/*==================================================================================================
 *                                         Initialization Entry
 *==================================================================================================*/


void Pmic_driver_init(void)
{

	  /* Initialize Pmic driver */
		  
	  Pmic_Init(NULL_PTR);
	
	  /* Install Gpio ISR */
	
	 /* Initialize Vr5510 device */
	  Pmic_InitDevice(PmicConf_PmicDevice_PmicDevice_0);
	
	
	  /*  Read FLAG3 Register */
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, &read_m_flag3_0);
	/*	  Read M_DEVICEID Register	  */
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_DEVICEID_ADDR8, &read_m_deviceid);
	
	/*	  Read M_MODE Register	  */
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_MODE_ADDR8, &read_m_mode);
	
	/*	  Read M_FLAG Register	  */
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG1_ADDR8, &read_m_flag1);
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG2_ADDR8, &read_m_flag2);
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_FLAG3_ADDR8, &read_m_flag3);
	
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_MAIN_UNIT, PMIC_VR55XX_M_CFG_VPRE_2_OTP_ADDR8, &read_m_otp_vpre);
	
	/*	  Read FS_STATE Register  */
	Pmic_ReadRegister(PmicConf_PmicDevice_PmicDevice_0, PMIC_FAIL_SAFE_UNIT, PMIC_VR55XX_FS_STATES_ADDR8, &read_fs_state);


}

#if defined(__cplusplus)
}
#endif

