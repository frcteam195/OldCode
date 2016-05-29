/*******************************************************************************
*
*	TITLE:		disabled.c
*
*	VERSION:	0.1 (Beta)
*
*	DATE:		31-Dec-2007
*
*	AUTHOR:		R. Kevin Watson
*				kevinw@jpl.nasa.gov
*
*	COMMENTS:	This file best viewed with tabs set to four.
*
*				You are free to use this source code for any non-commercial
*				use. Please do not make copies of this source code, modified
*				or un-modified, publicly available on the internet or elsewhere
*				without permission. Thanks.
*
*				Copyright ©2007-2008 R. Kevin Watson. All rights are reserved.
*
********************************************************************************
*
*	Change log:
*
*	DATE         REV  DESCRIPTION
*	-----------  ---  ----------------------------------------------------------
*	31-Dec-2007  0.1  RKW Original
*
*******************************************************************************/

#include "ifi_frc.h"
#include "pwm.h"
#include "gyro.h"
#include "timers.h"
#include "interrupts.h"
#include "serial_ports.h"
#include "ifi_code.h"
#include "disabled.h"

/*******************************************************************************
*
*	FUNCTION:		Disabled_Init()
*
*	PURPOSE:		This is where you put code that needs to execute
*					just once at the start of disabled mode.
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is valid
*					and all robot controller outputs (PWMs and relays) are
*					disabled.
*
*******************************************************************************/
void Disabled_Init(void)
{
	// this is where the the gyro bias calculation should start
	// Start_Gyro_Bias_Calc();
}

/*******************************************************************************
*
*	FUNCTION:		Disabled()
*
*	PURPOSE:		This is where you put code that you want to execute while
*					your robot is disabled.	While in autonomous mode, this
*					function is called every 26.2ms when after data is received
*					from the master processor.
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is valid
*					and all robot controller outputs (PWMs and relays) are
*					disabled.
*
*******************************************************************************/
void Disabled(void)
{
    static unsigned int i = 0;
	static unsigned int j = 0;
	int temp_gyro_rate;
	long temp_gyro_angle;
	int temp_gyro_bias;
	long temp_gyro_angle_fast;

	i++;
	j++; // this will rollover every ~1000 seconds


	// enable this block of code to test your gyro
	if(j == 10)
	{
		printf("\r\nCalculating Gyro Bias...\r\n");
	}
	if(j == 38) // let the gyro stablize for a second before starting a calibration
	{
		// start a gyro bias calculation
		Start_Gyro_Bias_Calc();
	}
	if(j == 130) // allow calibration routine to run for four seconds
	{
		// terminate the gyro bias calculation
		Stop_Gyro_Bias_Calc();

		// reset the gyro heading angle
		Reset_Gyro_Angle();

		temp_gyro_bias = Get_Gyro_Bias();
		printf("Gyro Bias=%d\r\n", temp_gyro_bias);
	}
	if(i == 35 && j >= 191)
	{
		temp_gyro_rate = Get_Gyro_Rate();
		temp_gyro_angle = Get_Gyro_Angle();
		printf("Gyro Rate=%d\r\n", temp_gyro_rate);
        printf("Gyro Angle=%d\r\n\r\n", (int)temp_gyro_angle);
	}

	// reset the loop counter
	if(i >= 38)
	{
		i = 0;
	}

}

/*******************************************************************************
*
*	FUNCTION:		Disabled_Spin()
*
*	PURPOSE:		While in disabled mode, this function is called
*					continuously between calls to Disabled().
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is valid
*					and all robot controller outputs (PWMs and relays) are
*					disabled.
*
*******************************************************************************/
void Disabled_Spin(void)
{
	// enable this function if you want to process gyro data during disabled mode
	 Process_Gyro_Data(TRUE);
}
