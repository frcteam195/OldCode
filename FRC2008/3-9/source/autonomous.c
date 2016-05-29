/*******************************************************************************
*
*	TITLE:		autonomous.c
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
#include "encoder.h"
#include "serial_ports.h"
#include "ifi_code.h"
#include "autonomous.h"
#include "drive.h"
#include "ir.h"
#include "launcher.h"

/*******************************************************************************
*
*	FUNCTION:		Autonomous_Init()
*
*	PURPOSE:		This is where you put code that you want to execute
*					just once at the start of autonomous mode.
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is invalid
*					(i.e., all analog inputs are set to 127 and digital inputs
*					are set to zero) and all robot controller outputs (PWMs and
*					relays) are	enabled.
*
*******************************************************************************/
void Autonomous_Init(void)
{
	// this is where the the gyro bias calculation should end
	// Stop_Gyro_Bias_Calc()
}

/*******************************************************************************
*
*	FUNCTION:		Autonomous()
*
*	PURPOSE:		This is where you put code that you want to execute while
*					your robot is in autonomous mode. While in autonomous mode,
*					this function is called every 26.2ms after new data is
*					received from the master processor.
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is invalid
*					(i.e., all analog inputs are set to 127 and digital inputs
*					are set to zero) and all robot controller outputs (PWMs and
*					relays) are	enabled.
*
*******************************************************************************/
void Autonomous(void)
{
    static int launch_stick = 0, speed=0,turn_r,state=0;
    static unsigned char out=127;
    static char d_cmd = 0;
    	// example code to test your gyro and encoder(s)

	int turn_p;
	static long error, sum_error,last_error,p,d,delta_error,vel,last_vel,vel_error,last_vel_error;
    static int ticks=1,pressed=0,latch=0,ir_cmd,old_ir_cmd;

    ShiftHigh();

    ir_cmd = Get_IR_Result();
    pressed = 0;
    printf("angle: %d \r\n",(int)Get_Gyro_Angle());

    if(ir_cmd == 0)
        latch = 0;

    if(ir_cmd == IR_UP){
        if(latch) {
            ir_cmd = 0;
            printf("latching\r\n");
        }
        latch++;
    }

    if(ir_cmd == IR_DN ){
        if(latch){
            ir_cmd = 0;
        }
        latch++;

    }

    switch(ir_cmd){
        case IR_UP:
            speed += 58;
            turn_r = -6;
               // Reset_Gyro_Angle();
                //ShiftHigh();
                //Drive(125,0);
            break;
        case IR_DN:
           // if(speed > 0) speed=58;
            speed = 0;//58;
            ToggleTilter();
            turn_r=0;
           // Reset_Gyro_Angle();
            //ShiftHigh();
            //Drive(-125,0);
            break;
        case IR_L:
            //Reset_Gyro_Angle();
            //ShiftLow();
            //Drive(0,-45);
            if(speed > 0)
                speed = 58;
            else if(speed < 0)
                speed = -58;

           if(speed > 116)
                turn_r = -135;
            else if(speed < -116)
                turn_r = -135;
            else
                turn_r = -110;

            state=1;
            break;
        case IR_R:
           // Reset_Gyro_Angle();
           //ShiftLow();
            //Drive(0,45);

              if(speed > 0)
                speed = 58;
            else if(speed < 0)
                speed = -58;

           if(speed > 116)
                turn_r = 135;
            else if(speed < -116)
                turn_r = 135;
            else
                turn_r = 110;

            break;
        default:
            //Drive(0,0);
           // speed=0;
            turn_r=0;
            break;
    }


    if(speed>116)speed=116;
    else if(speed<-116)speed=-116;
    //printf("SpeeD: %d | Turn: %d \r\n",speed,turn_r);
    Drive(speed,turn_r);

    old_ir_cmd;
    ticks++;
    DriveHandler();
    Launcher_Handler();
    Compressor_Handler();
}

/*******************************************************************************
*
*	FUNCTION:		Autonomous_Spin()
*
*	PURPOSE:		While in autonomous mode, this function is called
*					continuously between calls to Autonomous().
*
*	CALLED FROM:	main() in ifi_frc.c
*
*	PARAMETERS:		None
*
*	RETURNS:		Nothing
*
*	COMMENTS:		While in this mode, all operator interface data is invalid
*					(i.e., all analog inputs are set to 127 and digital inputs
*					are set to zero) and all robot controller outputs (PWMs and
*					relays) are	enabled.
*
*******************************************************************************/
void Autonomous_Spin(void)
{
	// enable this function if you want to process gyro data during autonomous mode
	 Process_Gyro_Data(TRUE);
}
