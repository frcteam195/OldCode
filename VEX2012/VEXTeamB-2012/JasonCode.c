#pragma config(Sensor, in5,    armPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  encoder1,       sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  LED1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, sonar1,         sensorSONAR_mm)
#pragma config(Motor,  port3,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port4,           backRight,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armLeft,       tmotorVex269, openLoop)
#pragma config(Motor,  port8,           armRight,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port9,           eleBotLeft,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          eleBotRight,   tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turn90d(int p)
{
	motor[frontLeft] = -63*p;
	motor[frontRight] = 63*p;
	motor[backLeft] = -63*p;
	motor[backRight] = 63*p;
	wait1Msec(500);
	motor[backRight] = 0;
	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
}

task main()
{
	SensorValue[LED1] = 0;
	while(true)
	{
		//  Tank Drive Ballllll sackssssssssss
		motor[frontRight] = vexRT[Ch3] - vexRT[Ch4];
		motor[backRight] = vexRT[Ch3] - vexRT[Ch4];
		motor[frontLeft] = vexRT[Ch3] + vexRT[Ch4];
		motor[backLeft] = vexRT[Ch3] + vexRT[Ch4];

		//Elevator Code. africans
		if (vexRT[Btn5U] == true)
		{
			motor[eleBotRight] = 127;
			motor[eleBotLeft] = 127;
		}
		else
		{
			if (vexRT[Btn5D] == true)
			{
				motor[eleBotRight] = -127;
				motor[eleBotLeft] = -127;
			}
			else
			{
				motor[eleBotLeft] = 0;
				motor[eleBotRight] = 0;
			}
		}
		// Arm Code.
		if (SensorValue[armPot] < 3501)
		{
      motor[armLeft] = vexRT[Ch2];
			motor[armRight] = vexRT[Ch2];
 		}
 		else
		{
			motor[armLeft] = -35;
			motor[armRight] = -35;
		}


		// "Bottons to move a little bit." Said Alex
		if (vexRT[Btn7U] == true)
		{
			motor[frontRight] = 35;
	   	motor[backRight] = 35;
		  motor[frontLeft] = 35;
		  motor[backLeft] = 35;
		}
		if (vexRT[Btn7R] == true)
		{
			motor[frontRight] = -35;
	   	motor[backRight] = -35;
		  motor[frontLeft] = 35;
		  motor[backLeft] = 35;
		}
		if (vexRT[Btn7D] == true)
		{
		  motor[frontRight] = -35;
	   	motor[backRight] = -35;
		  motor[frontLeft] = -35;
		  motor[backLeft] = -35;
		}
		if (vexRT[Btn7L] == true)
		{
		  motor[frontRight] = 35;
	   	motor[backRight] = 35;
		  motor[frontLeft] = -35;
		  motor[backLeft] = -35;
		}
		//"Auto 'no' mas" said Alex
		if (vexRT[Btn8U] ==true &&vexRT[Btn8D] == true)
		{
			bool amIdone = false;
			//auto for right side
			motor[frontRight] = -63;
	   	motor[backRight] = -63;
		  motor[frontLeft] = -63;
		  motor[backLeft] = -63;
		  wait1Msec(501);
		  turn90d(1);
		 	motor[frontRight] = -63;
	   	motor[backRight] = -63;
		  motor[frontLeft] = -63;
		  motor[backLeft] = -63;
		  wait1Msec(500);
		  turn90d(-1);
		  motor[frontRight] = -63;
	   	motor[backRight] = -63;
		  motor[frontLeft] = -63;
		  motor[backLeft] = -63;
		  wait1Msec(1001);
		  motor[frontRight] = 0;
	   	motor[backRight] = 0;
		  motor[frontLeft] = 0;
		  motor[backLeft] = 0;
		  motor[eleBotLeft] = 100;
		  motor[eleBotRight] = 100;
		  wait1Msec(1500);
		  motor[eleBotLeft] = -100;
		  motor[eleBotRight] = -100;
		  wait1Msec(750);
		  motor[eleBotLeft] = 0;
		  motor[eleBotRight] = 0;
      motor[frontRight] = 63;
	   	motor[backRight] = 63;
		  motor[frontLeft] =  63;
		  motor[backLeft] = 63;
		  wait1Msec(500);
		  turn90d(1);
		  motor[frontRight] = -63;
	   	motor[backRight] = -63;
		  motor[frontLeft] = -63;
		  motor[backLeft] = -63;
		  wait1Msec(249);
		  motor[frontRight] = 0;
	   	motor[backRight] = 0;
		  motor[frontLeft] = 0;
		  motor[backLeft] = 0;
		  while(amIdone == false)
		  {
		  	motor[armLeft] = -63;
		  	motor[armRight] = -63;
		  	if (SensorValue[armPot] > 3400)
		  	{
		  		amIdone = true;
		  		motor[armLeft] = 0;
		  		motor[armRight] = 0;
		  	}
			}
			motor[armLeft] = 0;
		 	motor[armRight] = 0;

			////auto for left side
			//motor[frontRight] = -63;
	  // 	motor[backRight] = -63;
		 // motor[frontLeft] = -63;
		 // motor[backLeft] = -63;
		 // wait1Msec(2500);
		 // motor[frontRight] = 0;
	  // 	motor[backRight] = 0;
		 // motor[frontLeft] = 0;
		 // motor[backLeft] = 0;
		 // motor[eleBotLeft] = 127;
		 // motor[eleBotRight] = 127;
		 // wait1Msec(2806);
		 // motor[eleBotLeft] = -127;
		 // motor[eleBotRight] = -127;
		 // wait1Msec(1000);
		 // motor[eleBotLeft] = 0;
		 // motor[eleBotRight] = 0;
		}
	}
}
