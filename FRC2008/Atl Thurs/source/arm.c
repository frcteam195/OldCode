#include <stdio.h>
#include "pid.h"
#include "encoder.h"
#include "ifi_frc.h"
#include "ifi_code.h"
#include "robot.h"
#include "arm.h"

unsigned int arm_position, wanted_position;
static unsigned char wrist=0, finger=0; //end effector contrizole!
PID arm;

extern Buttons controls;
unsigned char arm_state=0;

void Arm_Operator_Control(void)
{

    static unsigned int temp_pos=0;
    static char latch_finger=0,latch_wrist=0;




        if(ARM_SW_HOME==A_CLOSED)
        {
            arm_state = STATE_HOME;
        }
        if(ARM_SW_FLOOR==A_CLOSED)
        {
            arm_state= STATE_FLOOR;
        }
        if(ARM_SW_BOTTOM==A_CLOSED)
        {
            arm_state=STATE_BOTTOM;
            arm_state+=(100*SPOILER_SW);
        }
        if(ARM_SW_MIDDLE==A_CLOSED)
        {
            arm_state=STATE_MIDDLE;
            arm_state+=(100*SPOILER_SW);
        }
        if(ARM_SW_TOP==A_CLOSED)
        {
            arm_state=STATE_TOP;
            arm_state+=(100*SPOILER_SW);
        }
        if(ARM_SW_HUMAN==A_CLOSED)
        {
            arm_state=STATE_HUMAN_HIGH;
        }


        if(arm_state%2 != 0 && ARM_SW_DO) //Make sure we arent in a "do" state
            arm_state++;

        switch(arm_state)
        {
            //Home
            case STATE_HOME:
                temp_pos = POS_HOME;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

            //Floor
            case STATE_FLOOR:
                temp_pos = POS_FLOOR;
                wrist = WRIST_DOWN;
                finger = FINGER_OUT;
                break;

            //Bottom
            case STATE_BOTTOM:
                temp_pos = POS_BOTTOM;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

            case STATE_BOTTOM_DO:
                temp_pos = POS_BOTTOM;
                wrist = WRIST_DOWN;
                finger = FINGER_OUT;
                break;

             case STATE_BOTTOM_SPOILER:
                temp_pos = POS_BOTTOM_SPOILER;
                wrist = WRIST_DOWN;
                finger = FINGER_OUT;
                break;

             case STATE_BOTTOM_SPOILER_DO:
                temp_pos = POS_BOTTOM_SPOILER;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

            //Middle
            case STATE_MIDDLE:
                temp_pos = POS_MIDDLE;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

             case STATE_MIDDLE_DO:
                temp_pos = POS_MIDDLE_DO;
                wrist = WRIST_UP;
                finger = FINGER_OUT;
                break;

             case STATE_MIDDLE_SPOILER:
                temp_pos = POS_MIDDLE_SPOILER;
                wrist = WRIST_DOWN;
                finger = FINGER_OUT;
                break;

             case STATE_MIDDLE_SPOILER_DO:
                temp_pos = POS_MIDDLE_SPOILER;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

            //TOP
            case STATE_TOP:
                temp_pos = POS_TOP;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

             case STATE_TOP_DO:
                temp_pos = POS_TOP_DO;
                wrist = WRIST_UP;
                finger = FINGER_OUT;
                break;

             case STATE_TOP_SPOILER:
                temp_pos = POS_TOP_SPOILER;
                wrist = WRIST_DOWN;
                finger = FINGER_OUT;
                break;

             case STATE_TOP_SPOILER_DO:
                temp_pos = POS_TOP_SPOILER;
                wrist = WRIST_UP;
                finger = FINGER_IN;
                break;

            //Human
            case STATE_HUMAN_HIGH:
                temp_pos = POS_HUMAN_HIGH;
                wrist = WRIST_UP;
                finger = FINGER_OUT;
                break;

            case STATE_HUMAN_LOW:
                temp_pos = POS_HUMAN_LOW;
                wrist = WRIST_DOWN;
                finger = FINGER_IN;
                break;
            case STATE_IDLE:
                temp_pos = arm_position;
                break;

            //Default
            default:
                break;
        }

        //Position control only in automagix
        Set_Arm_Position(temp_pos);

    //else automagix

        //Toggle!!!!!
    if(WRIST_SW==A_CLOSED && latch_wrist == 0)
    {
         wrist= !wrist;
         latch_wrist=1;
    }
    else if(WRIST_SW==A_OPEN) latch_wrist = 0;


    if(FINGER_SW==A_CLOSED && latch_finger==0)
    {
         finger=!finger;
        latch_finger=1;
    }
    else if(FINGER_SW == A_OPEN) latch_finger=0;

    End_Effector(wrist,finger);

}
//Call this from User_Initilization in User_Routines.c
void Initialize_Arm(void)
{
	InitPID(&arm,ARM_P_GAIN,ARM_I_GAIN,ARM_D_GAIN,ARM_I_MIN,ARM_I_MAX);
	arm_position = 0;
	ARM_ENCODER_RESET();
	wanted_position = arm_position;
    wrist = WRIST_UP;
    finger = FINGER_OUT;
	arm_state=STATE_IDLE;
}

//Limit switch functionality
char Limit_Output(char speed)
{
	if(speed <= 0  && BOTTOM_LIMIT_SWITCH == 0){
//	    printf("limiting bottom\n\r"); //Check bottom
		return 0;
	}
	else if(speed >= 0 && TOP_LIMIT_SWITCH == 0){
	//    printf("top limit\n\r");//Check Top
		return 0;
	}
	else
	{
        if(arm_position <= DOWN_STOP_DELTA && speed < 0){
            speed = speed / DOWN_STOP_DENOMINATOR;
      //      printf("1st If - down stop\n\r");
        }

        else if(arm_position <= DOWN_FINE_DELTA && speed < 0){
            speed = speed / DOWN_FINE_DENOMINATOR;
        //                printf("2nd If - down fine\n\r");
        }

        else if(arm_position <= DOWN_SLOW_DELTA && speed < 0){
            speed = speed / DOWN_SLOW_DENOMINATOR;
          //              printf("3rd - down slow\n\r");
        }

        else if(arm_position >= UP_FINE_DELTA && speed > 0){
            speed = speed / UP_FINE_DENOMINATOR;
            //    printf("4th If - up fine\n\r");
        }

        else if(arm_position >= UP_SLOW_DELTA && speed > 0){
            speed = speed / UP_SLOW_DENOMINATOR;
              //  printf("5th if - up slow\n\r");
        }

		return speed; //Default
	}



//	else return speed;


}


//Low Level drive function
void Drive_Arm(char speed)
{
    int temp_speed;

    temp_speed = (int) Limit_Output(speed);
    temp_speed+=127;

    if(temp_speed < 0) temp_speed = 0;
    else if(temp_speed > 254) temp_speed=254;



	ARM_PWM = (unsigned char) temp_speed;
	//printf("driving:: %d \n\r",  temp_speed);
}

void Set_Arm_Position(unsigned int input_position)
{
   // arm_state=STATE_IDLE;
	wanted_position = input_position;
}
void Set_Arm_State(unsigned int input_state)
{
   // arm_state=STATE_IDLE;
	arm_state = input_state;
}
//Call this every loop!
void Arm_Handler(void)
{
    char speed;
    static char old_control,old_speed;

    if(BOTTOM_LIMIT_SWITCH == 0)
        Reset_Encoder_2_Count();
    if(TOP_LIMIT_SWITCH == 0)
    {
        //Set_Encoder_2_Count(UPPER_BOUND_ENCODER);
    }

    Arm_Operator_Control();
    arm_position = ARM_ENCODER();


    if(ARM_CONTROL_STICK <= 15 && ARM_CONTROL_STICK >= -15)
    {
        Relay1_green=1;
	//Check to see if we are already where we want to be
        if( arm_position >= (wanted_position - ALLOWABLE_ERROR) &&  arm_position <= (wanted_position + ALLOWABLE_ERROR)  )
        {
           // printf("In deadband! | actual: %d\n\r",arm_position);
            speed = 0; //Do nothing with motors!
        }
        else //We are not where we want to be
        {
            speed = GetPID(&arm,wanted_position,arm_position);
//            printf("arm wants to move | speed: %d | old_speed %d | wanted: %d | actual: %d\n\r",speed,old_speed,wanted_position,arm_position);
            //Ramp Up, Ramp Down
            speed = RampUpArm(speed,old_speed);


    	}
    	Drive_Arm(speed);
    }
    else
    {
            Relay1_green=0;
            speed =  ARM_CONTROL_STICK/2;
            speed = RampUpArm(speed, old_speed);
            if(speed < -127) speed = -127;
            if(speed > 127) speed = 127;
           // printf("in the fucking else: %d\n\r",speed);
            Drive_Arm((char) speed);
            wanted_position=arm_position;
            printf("In Manual Control: %d\n\r",arm_position);
            arm_state = STATE_IDLE;
	}

	old_control = ARM_CONTROL_STICK;
    old_speed=speed;
}






char RampUpArm(char input,char arm_prev_value)
{
    char old_input = input;

    if( (input - arm_prev_value) > RAMP_UP_DELTA )
        input = arm_prev_value + RAMP_UP_DELTA ;
    else if( (arm_prev_value - input) > RAMP_UP_DELTA )
        input = arm_prev_value - RAMP_UP_DELTA;

    //printf(": %d\n\r",input);

    //this is a kludge... sometimes shit happens.
    if(old_input < 0 && input > 0)
        input *= -1;
    if(old_input > 0 && input < 0)
        input *= -1;
//    printf("In ramp: %d\n\r", (int) input);
    return input;
}

void End_Effector(char iWrist, char iFinger)
{
 //   printf("in EEF: w: %d | f: %d\n\r",iWrist,iFinger);
    if(iWrist == 0)
    {
        WRIST_RELAY_FWD=1;
        WRIST_RELAY_REV=0;
    }
    else
    {
        WRIST_RELAY_FWD=0;
        WRIST_RELAY_REV=1;
    }

    if(iFinger == 0)
    {
        FINGER_RELAY_FWD=1;
        FINGER_RELAY_REV=0;
    }
    else
    {
        FINGER_RELAY_FWD=0;
        FINGER_RELAY_REV=1;
    }
}
