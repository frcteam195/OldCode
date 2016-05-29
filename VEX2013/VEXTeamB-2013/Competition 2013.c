#pragma config(Sensor, in1,    elePot,         sensorPotentiometer)
#pragma config(Sensor, in2,    autoPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  autoBtn,        sensorTouch)
#pragma config(Sensor, dgtl2,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           backLeft,      tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port5,           backRight,     tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port6,           collectorRight, tmotorVex269, openLoop)
#pragma config(Motor,  port7,           collectorLeft, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port8,           eleRight,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           eleLeft,       tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"

// Global Variables
int eleCommand = 35;
const int elePositions[5] = {35, elePositions[0] + 200, elePositions[0] + 1200, elePositions[0] + 3500, elePositions[0] + 1000};


enum	//Elevator Positions
{
	HOME = 0, BUMP = 1, DUMP = 2, FLIP = 3, autoPush = 4
};

void setPosition(int command = 0)
{
	if (command == 0) command = 35;
	eleCommand = command;
}

void driveMotorsOn(float direction)
{
	motor[frontRight] = 127*direction;
	motor[backRight] = 127*direction;
	motor[frontLeft] = 127*direction;
	motor[backLeft] = 127*direction;
}

void motorsOff()
{
	motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[backLeft] = 0;
	motor[collectorRight] = 0;
	motor[collectorLeft] = 0;
	motor[eleLeft] = 0;
	motor[eleRight] = 0;
}

void turn90Blue()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while (SensorValue[leftEncoder] < 360 && SensorValue[rightEncoder] < 360)
	{
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
	}
	motorsOff();
	ClearTimer(T1);
}

void turn90Red()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	while (SensorValue[leftEncoder] > - 360 && SensorValue[rightEncoder] > -360)
	{
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = -127;
		motor[backLeft] = -127;
	}
	motorsOff();
	ClearTimer(T1);
}

void ArcadeDrive()
{
	bool halfSpeed = false;
	//Buttons to control speed
	//FIX THIS STUFF
	if (vexRT[Btn7D] == true)
	{
		if(!halfSpeed)
		{
			motor[frontRight] = vexRT[Ch2] - vexRT[Ch1];
			motor[backRight] = vexRT[Ch2] - vexRT[Ch1];
			motor[frontLeft] = vexRT[Ch2] + vexRT[Ch1];
			motor[backLeft] = vexRT[Ch2] + vexRT[Ch1];
		}
		halfSpeed = true;
	}
	else
	{
		motor[frontRight] = (vexRT[Ch2] - vexRT[Ch1])*.5;
		motor[backRight] = (vexRT[Ch2] - vexRT[Ch1])*.5;
		motor[frontLeft] = (vexRT[Ch2] + vexRT[Ch1])*.5;
		motor[backLeft] = (vexRT[Ch2] + vexRT[Ch1])*.5;
	}
}

void CollecterMotors()
{
	//Take those puppiues in
	if (vexRT[Btn6U] == 1)
	{
		motor[collectorRight] = 127;
		motor[collectorLeft] = 127;
	}
	else
	{
		//Spit thoes babiues out
		if (vexRT[Btn5U] == 1)
		{
			motor[collectorRight] = -127;
			motor[collectorLeft] = -127;
		}
		else
		{
			motor[collectorRight] = 0;
			motor[collectorLeft] = 0;
		}
	}
}

void liftButtons()
{
	if (vexRT[Btn8U] && vexRT[Btn8R] == 1) setPosition(elePositions[FLIP]);
	if (vexRT[Btn7U] == 1) setPosition(elePositions[DUMP]);
	if (vexRT[Btn7L] == 1) setPosition(elePositions[BUMP]);
	if (vexRT[Btn7D] == 1) setPosition(elePositions[HOME]);
	if (vexRT[Btn7R] == 1) setPosition(elePositions[autoPush]);
}

void ele_pid()
{
	const float k = .3;
	int error = 0;
	int change = 0;

	error = SensorValue[elePot] - eleCommand;
	change = error * k;

	if (change > 127) change = 127;
	else if ( change < -127) change = -127;

	motor[eleLeft] = change;
	motor[eleRight] = change;
}

void pre_auton()
{
	bStopTasksBetweenModes = false;
}
//==========================================
task autonomous()
{
	//Blue Front Auto====================================
	if (SensorValue[autoPot] < 1000)
	{
		motorsOff();
	}
	//Blue Back Auto==================================================
	if (SensorValue[autoPot] > 1000 && SensorValue[autoPot] < 2000)
	{
		int secondAuto = 0;
		motorsOff();
		ClearTimer(T1);
		while ( secondAuto == 0 )
		{
			if (SensorValue[autoBtn] == 1)
			{
				secondAuto = 1;
			}
		}
		while ( secondAuto == 1 )
		{
			ClearTimer(T1);
			while (time1[T1] < 500)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
			}
			ele_pid();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (SensorValue[leftEncoder] < 1054 && SensorValue[rightEncoder] > - 1054)
			{
				setPosition(elePositions[HOME]);
				ele_pid();
				driveMotorsOn(1);
			}
			ClearTimer(T1);
			motorsOff();
			turn90Blue();
			while (time1[T1] < 500)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
			}
			ClearTimer(T1);
			motorsOff();
			ele_pid();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (SensorValue[leftEncoder] < 900 && SensorValue[rightEncoder] > -900)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
				driveMotorsOn(1);
			}
			motorsOff();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (time1[T1] < 500)
			{
				setPosition(elePositions[autoPush]);
				ele_pid();
			}
			ClearTimer(T1);
			while (SensorValue[leftEncoder] < 800 && SensorValue[rightEncoder] > -800)
			{
				setPosition(elePositions[autoPush]);
				ele_pid();
				driveMotorsOn(.5);
			}
			motorsOff();
			ClearTimer(T1);
			while (time1[T1] < 7000)
			{
				ele_pid();
				motor[collectorLeft] = -127;
				motor[collectorRight] = -127;
			}
			ClearTimer(T1);
			while (SensorValue[leftEncoder] > 200 && SensorValue[rightEncoder] < -200)
			{
				ele_pid();
				driveMotorsOn(-.5);
			}
			motorsOff();
			setPosition(elePositions[BUMP]);
			ele_pid();
			break;
		}
	}

	//Red Back Auto===================================================
	if (SensorValue[autoPot] > 2000 && SensorValue[autoPot] < 3000)
	{
		int secondAuto = 0;
		ClearTimer(T1);
		while ( secondAuto == 0 )
		{
			ele_pid();
			if (SensorValue[autoBtn] == 1)
			{
				secondAuto = 1;
			}
		}
		while ( secondAuto == 1 )
		{
			ClearTimer(T1);
			while (time1[T1] < 500)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
			}
			ele_pid();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (SensorValue[leftEncoder] < 1054 && SensorValue[rightEncoder] > - 1054)
			{
				setPosition(elePositions[HOME]);
				ele_pid();
				driveMotorsOn(1);
			}
			ClearTimer(T1);
			motorsOff();
			turn90Red();
			while (time1[T1] < 500)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
			}
			ClearTimer(T1);
			motorsOff();
			ele_pid();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (SensorValue[leftEncoder] < 900 && SensorValue[rightEncoder] > -900)
			{
				setPosition(elePositions[BUMP]);
				ele_pid();
				driveMotorsOn(1);
			}
			motorsOff();
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			while (time1[T1] < 500)
			{
				setPosition(elePositions[autoPush]);
				ele_pid();
			}
			ClearTimer(T1);
			while (SensorValue[leftEncoder] < 800 && SensorValue[rightEncoder] > -800)
			{
				setPosition(elePositions[autoPush]);
				ele_pid();
				driveMotorsOn(.5);
			}
			while (time1[T1] < 7000)
			{
				ele_pid();
				motor[collectorLeft] = -127;
				motor[collectorRight] = -127;
			}
			motorsOff();
			ClearTimer(T1);
			while (SensorValue[leftEncoder] > 200 && SensorValue[rightEncoder] < -200)
			{
				ele_pid();
				driveMotorsOn(-.5);
			}
			motorsOff();
			setPosition(elePositions[BUMP]);
			ele_pid();
			break;
		}
	}
	//Red Front Auto===================================================
	if (SensorValue[autoPot] > 3000)
	{
		motorsOff();
	}
}
//=============================================

task usercontrol()
{
	while(true)
	{
		ArcadeDrive();
		CollecterMotors();
		ele_pid();
		liftButtons();
	}
}
