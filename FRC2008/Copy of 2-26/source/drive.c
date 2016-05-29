//Drive.c
//Base driver for FIRST RoboticsTeam 125 NUTRONS
// Feb 2007
//Tom Bottiglieri
//Dependancies: IFI Library 200X, PID.c, Gyro.c, Encoder,c

/* Testing Intstructions:
Work back from end of call stack...

1) Drive()
2) TankDrive()
3) Tune Angluar PID
4) Test TurnToHeading()
5) Test DriveStraight()
6) Tune Linear PID
7) DriveDisance()

*/
#include "ifi_frc.h"
#include "ifi_code.h"
#include "encoder.h"
#include "gyro.h"
#include "pid.h"
#include "drive.h"
#include "robot.h"
#include "adc.h"
#include "teleop.h"
#include <stdio.h>



//Initialize global variables here
int wheel_l;
int wheel_r;

unsigned char drive_initialized, brakes_engaged,gear=0,orientation=1;
PID angular_position; //used to turn to heading
PID linear_position; //used to drive distances
PIDGains angular_gains,linear_gains;



//InitDrive
//Turns on all of the PID loops and resets everything to 0
//Called by: InitialzeRobot
//Calls: PID, ResetDriveDependancies
void Initialize_Drive(void)
{
	//Load from EEPROM?
	//For now, set to default!
	if(!drive_initialized)
	{
	    drive_initialized = 1;
		angular_gains.pGain = TURN_P_GAIN_DEFAULT;
		angular_gains.iGain = TURN_I_GAIN_DEFAULT;
		angular_gains.dGain = TURN_D_GAIN_DEFAULT;
		angular_gains.iMin = TURN_MIN_I_DEFAULT;
		angular_gains.iMax = TURN_MAX_I_DEFAULT;

		linear_gains.pGain = LINEAR_P_GAIN_DEFAULT;
		linear_gains.iGain = LINEAR_I_GAIN_DEFAULT;
		linear_gains.dGain = LINEAR_D_GAIN_DEFAULT;
		linear_gains.iMin = LINEAR_MIN_I_DEFAULT;
		linear_gains.iMax = LINEAR_MAX_I_DEFAULT;
	}
	else
	{
		//Load gains from another function? Testing?
	}

	InitPID(&angular_position, angular_gains.pGain , angular_gains.iGain, angular_gains.dGain, angular_gains.iMax);
	InitPID(&linear_position,  linear_gains.pGain , linear_gains.iGain, linear_gains.dGain,linear_gains.iMax);

	ResetDriveDependancies();

	drive_initialized = 1;
}

//Reset Drive Dependancies
//Allows scripted autonomous mode to work
//Called by: InitDrive, Autonomous
//Calls: Reset Encoders, Reset Gyro Angle
void ResetDriveDependancies(void)
{
	RESET_LEFT_ENCODER;
	RESET_RIGHT_ENCODER;
	Reset_Gyro_Angle();
}

//TankDrive
//Called from operator control, scales unsigned chars to signed
//Inputs direct stick values
//Calls: Nothing
//Called by: Operator Control
void TankDrive(void)
{
	wheel_l = (int) TWO_STICK_LEFT - 127;
	wheel_r = (int) TWO_STICK_RIGHT - 127;
	//printf("WL: %3d  | WR: %3d \r\n",wheel_l,wheel_r);
}

//Drive
//Low level Drive control
//Inputs speed and turn rate, acceses wheel rate variables
//Calls: Nothing
//Called by: DriveStraight, OneStickDrive
void Drive(int speed, int turn)
{
	wheel_l = (speed + turn);
	wheel_r = (speed - turn);
	//printf("l: %3d | r: %3d \r\n",wheel_l,wheel_r);
}

void DifferentialDrive(void){

    int speed_in = (int)(ONE_STICK_SPEED) - 127;
    int steer_in = (int)(ONE_STICK_TURN) - 127;
    int abs_speed_in = abs(speed_in);
    int abs_steer_in = abs(steer_in);

    int speed = speed_in;//(speed_in * abs_speed_in) / 127;
    int steer = steer_in;//(steer_in * abs_steer_in) / 127;

    int steer_mul = (127-abs_speed_in)+ MIN_STEER ;
    steer = (steer * steer_mul)/(127 + MIN_STEER);

    Drive(speed,steer);

    //printf("Y_OUT: %3d | X_IN: %3d | steer: %3d \r\n",speed_in,steer_in,steer);
}


void ShiftLow(void){
    gear=0;
}

void ShiftHigh(void){
    gear=1;
}

void SwitchGears(void){
    gear=!gear;
}

void SwitchGear(char wanted_gear){
    gear = wanted_gear;
}

void OrientationFwd(void){
    orientation = 1;
}

void OrientationRev(void){
    orientation = 0;
}

//TurnToHeading
//Turns to a relative heading
//Can be scripted
//Returns status (0 - Working, 1 - Done, -1 - Error)
char TurnToHeading(int wanted_heading)
{
    int cur_heading;
    cur_heading = Get_Gyro_Angle();
	if( (cur_heading < (wanted_heading -  ANGULAR_ERROR)) || cur_heading > (wanted_heading +  ANGULAR_ERROR)) //Are we within our error bounds?
	{
		Drive( 0 , GetPID( &angular_position , cur_heading, wanted_heading));
		return 0;
	}
	else return 1;
}


//DriveStraight
//keeps robot in a straight line while driving straight
//Calls: Drive
//Called by: DriveDistance, Autonomous
void DriveStraight(char speed)
{
	int heading = GYRO_ANGLE;
	Drive( speed , GetPID( &angular_position, heading, 0 ) );
}

//DriveDistance
//Drives a certain distance at a set speed
//Calls: DriveStraight
//Called by: Autonomous
char DriveDistance(char speed, int wanted_distance) //return -1,0,1 (error, working, done)
{
	static int cur_distance = 0;
	cur_distance = (LEFT_ENCODER + RIGHT_ENCODER) / 2;

	if( (cur_distance < (wanted_distance -  LINEAR_ERROR)) || cur_distance > (wanted_distance +  LINEAR_ERROR)) //Are we within our error bounds?
	{
		DriveStraight( GetPID( &linear_position , cur_distance, wanted_distance));
		return 0;
	}
	else return 1;
}

void Human_Brake_Handler(void)
{
    static unsigned char old_wheel;
    if(p2_wheel!=old_wheel)
    {
        if(p2_wheel>127){
            EngageBrakes();
        }
        else{
            StopBrakes();
        }
    }
}
//EngageBrakes
//Turns brakes on
//Called by: Operator Control, Autonomous
//Calls: Nothing
void EngageBrakes(void)
{
	brakes_engaged = ENGAGED;
}

//StopBrakes
//Turns brakes off
//Called by: Operator Control, Autonomous
//Calls: Nothing
void StopBrakes(void)
{
	brakes_engaged = NOT_ENGAGED;
}

void LimitSpeed(char input)
{
    if(wheel_r>input) wheel_r=input;
    else if (wheel_r < -1 * input) wheel_r= -1*input;

    if(wheel_l>input) wheel_l=input;
    else if (wheel_l < -1 * input) wheel_l= -1*input;
    //printf("Limit Speed: R: %d | L : %d | In: %d\r\n",(int) wheel_r, (int) wheel_l, (int) input);
}

//DriveHandler
//Dependancy of Drive Base "driver"
//Needs to be called every loop we want robot to move
//Called by: Slow loop, Fast Loop
void DriveHandler(void)
{
    static int c_launch=0,c_left=0,c_right=0,c_pot,c_left_last=0;
    static unsigned char l_temp,r_temp;
    //Initialize
    if(!drive_initialized)
        Initialize_Drive();

    //Gear shifting
    if(gear){
        SHIFTER_RELAY_FWD = 1;
        SHIFTER_RELAY_REV = 0;
    }
    else{
        SHIFTER_RELAY_FWD = 0;
        SHIFTER_RELAY_REV = 1;
    }
   // printf("FWD: %d | REV: %d | Gear: %d\r\n",SHIFTER_RELAY_FWD,SHIFTER_RELAY_REV,gear);
    //Control Motors

    if(orientation){
        l_temp = (unsigned char) LimitChar(~wheel_l) ; //flip polarity
        r_temp = (unsigned char) LimitChar(wheel_r) ;
    }
    else{
        r_temp = (unsigned char) LimitChar(~wheel_l) ; //flip polarity
        l_temp = (unsigned char) LimitChar(wheel_r) ;
        r_temp = 255 - r_temp;
        l_temp = 255 - l_temp;
    }


    LEFT_WHEEL_PWM = l_temp;
    RIGHT_WHEEL_PWM = r_temp;

	//printf("            **     LEFT WHEEL: %d     RIGHT WHEEL: %d\r\n",(int)(wheel_l * LEFT_WHEEL_INVERT) + 127,(int)(wheel_r * RIGHT_WHEEL_INVERT) + 127);
}

