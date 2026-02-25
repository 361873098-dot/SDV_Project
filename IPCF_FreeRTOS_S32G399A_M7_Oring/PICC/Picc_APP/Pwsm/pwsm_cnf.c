/********************************************************************************
* COPYRIGHT (C) Vitesco Technologies 2025
* ALL RIGHTS RESERVED.
*
* The reproduction, transmission or use of this document or its
* contents is not permitted without express written authority.
* Offenders will be liable for damages. All rights, including rights
* created by patent grant or registration of a utility model or design,
* are reserved.
*********************************************************************************
*
*  File name:           $Source: pwsm_cnf.c $
*  Revision:            $Revision: 1.0 $
*  Author:              $Author: Li Song (uic59152)  $
*  Module acronym:      PWSM
*  Specification:
*  Date:                $Date: 2025/12/18  $
*
*  Description:     This Unit processes the power supply module
*
*********************************************************************************
*
*  Changes:
*
*
*********************************************************************************/

/***********************************************************************************************************************
*  include files
***********************************************************************************************************************/
#include "Platform.h"
#include "pwsm_cnf.h"
#include "Dio.h"


/***********************************************************************************************************************
 *  Function name    : Pwsm_WriteWakeup()
 *
 *  Description      : Write level to specified channel.
 *
 *  List of arguments: none
 *
 *  Return value     : Level: Specifies the channel desired level.
 *
 ***********************************************************************************************************************/
void Pwsm_WriteWakeup(uint8 Level)
{


	Dio_WriteChannel(DioConf_DioChannel_VR5510_PWRON2, Level);

}


/***********************************************************************************************************************
 *  Function name    : Pwsm_GetIgkStatus()
 *
 *  Description      : Get status of ignition key.
 *
 *  List of arguments: none
 *
 *  Return value     : Ignition status
 *
 ***********************************************************************************************************************/
uint8 Pwsm_GetIgkStatus(void)
{
	return Dio_ReadChannel(DioConf_DioChannel_IGN_KEY);
}



