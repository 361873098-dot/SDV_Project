/*
*  Copyright 2021-2023 NXP.
*  This software is owned or controlled by NXP and may only be used strictly in accordance with the applicable license terms.  
*  By expressly accepting such terms or by downloading, installing, activating and/or otherwise using the software  
*  you are agreeing that you have read, and that you agree to comply with and are bound by, such license terms.  
*  If you do not agree to be bound by the applicable license terms, then you may not retain, install, activate or otherwise use the software.  
*/  

#include "stdint.h"

const uint8_t dcd_commands[20] = {

	/* HEADER */
	0xd2, 0x0, 0x4, 0x60, 
	
	/* COMMANDS */


	/* RESERVED */
	/* GMAC */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	
};
