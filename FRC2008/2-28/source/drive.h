#ifndef _DRIVE_H
#define _DRIVE_H

//Drive.h
//Base driver for FIRST RoboticsTeam 125 NUTRONS
// Feb 2007
//Tom Bottiglieri
//Dependancies: IFI Library 200X, PID.c, Gyro.c, Encoder,c

//Macros for drive.c
#define ENGAGED                  1
#define NOT_ENGAGED              0
#define LEFT_WHEEL_INVERT		-1
#define RIGHT_WHEEL_INVERT		+1
#define LEFT_WHEEL_PWM			pwm04=pwm05
#define RIGHT_WHEEL_PWM			pwm01=pwm02
#define BRAKE_RELAY             relay2_fwd
#define SHIFTER_RELAY_FWD       relay1_fwd
#define SHIFTER_RELAY_REV       relay1_rev
#define GYRO_ANGLE				Get_Gyro_Angle()
#define LEFT_ENCODER			Get_Encoder_2_Count()
#define RIGHT_ENCODER			Get_Encoder_3_Count()
#define RESET_LEFT_ENCODER      Reset_Encoder_2_Count()
#define RESET_RIGHT_ENCODER     Reset_Encoder_3_Count()
#define LINEAR_ERROR			5 //Encoder ticks for +/- linear position control
#define ANGULAR_ERROR			5 //milli(radians/degrees) for +/- angular position control

#define ONE_STICK_SPEED         p2_y
#define ONE_STICK_TURN          p2_x
#define TWO_STICK_LEFT          p1_y
#define TWO_STICK_RIGHT         p2_y
#define MIN_STEER               60

#define TAPER               5
#define TAPER_M             (TAPER - 127)

//Angluar PID
#define TURN_P_GAIN_DEFAULT		10
#define TURN_I_GAIN_DEFAULT		0
#define TURN_D_GAIN_DEFAULT		0
#define TURN_MIN_I_DEFAULT		-100
#define TURN_MAX_I_DEFAULT		100

//Linear PID
#define LINEAR_P_GAIN_DEFAULT	10
#define LINEAR_I_GAIN_DEFAULT	0
#define LINEAR_D_GAIN_DEFAULT	0
#define LINEAR_MIN_I_DEFAULT	-100
#define LINEAR_MAX_I_DEFAULT	100



//InitDrive
//Turns on all of the PID loops and resets everything to 0
//Called by: InitialzeRobot
//Calls: PID, ResetDriveDependancies
void Initialize_Drive(void);

//Reset Drive Dependancies
//Allows scripted autonomous mode to work
//Called by: InitDrive, Autonomous
//Calls: Reset Encoders, Reset Gyro Angle
void ResetDriveDependancies(void);
//TankDrive
//Called from operator control, scales unsigned chars to signed
//Inputs direct stick values
//Calls: Nothing
//Called by: Operator Control
void TankDrive(void);
//diff drive
void DifferentialDrive(void);
//Drive
//Low level Drive control
//Inputs speed and turn rate, acceses wheel rate variables
//Calls: Nothing
//Called by: DriveStraight, OneStickDrive
void Drive(int speed, int turn);
//TurnToHeading
//Turns to a relative heading
//Can be scripted
//Returns status (0 - Working, 1 - Done, -1 - Error)
char TurnToHeading(int wanted_heading);

//DriveStraight
//keeps robot in a straight line while driving straight
//Calls: Drive
//Called by: DriveDistance, Autonomous
void DriveStraight(char speed);
//DriveDistance
//Drives a certain distance at a set speed
//Calls: DriveStraight
//Called by: Autonomous
char DriveDistance(char speed, int wanted_distance); //return -1,0,1 (error, working, done)

void SwitchGears(void);
void ShiftHigh(void);
void ShiftLow();
void SwitchGear(char wanted_gear);
void OrientationFwd(void);
void OrientationRev(void);

void Human_Brake_Handler(void);
//EngageBrakes
//Turns brakes on
//Called by: Operator Control, Autonomous
//Calls: Nothing
void EngageBrakes(void);


//StopBrakes
//Turns brakes off
//Called by: Operator Control, Autonomous
//Calls: Nothing
void StopBrakes(void);

//DriveHandler
//Dependancy of Drive Base "driver"
//Needs to be called every loop we want robot to move
//Called by: Slow loop, Fast Loop
void DriveHandler(void);
void LimitSpeed(char input);

#endif
