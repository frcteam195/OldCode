// STATE        SUB STATE
//
// HOME
//  lift to HOME_POSITION
//  gripper in
//  Tilt back
//
// FLOOR
//  Tilt Forward
//  Lift to bottom
//  Gripper Half
//
// POSSESING
//  Close Gripper
//  Tilt back?
//
// LAUNCHING
//  Release Gripper
//  Ramp Up Motor
//  Push Fast
//  Stop at top
//  "Catch"
//  GOTO: HOME
//
// MANUAL
//  Gripper on joystick
//  Tilt Switch
//
// IDLE
//  Do Nothing
#include "ifi_frc.h"
#include "ifi_code.h"
#include "encoder.h"
#include "gyro.h"
#include "pid.h"
#include "drive.h"
#include "robot.h"
#include "adc.h"
#include "teleop.h"
#include "launcher.h"
#include <stdio.h>


//States
#define HOME                    1
#define FLOOR                   2
#define LOADED                  3
#define ARMED                   4
#define LAUNCHING               5
#define MANUAL                  6
#define IDLE                    7
#define BRAKING                 8
#define FINDING_TOP             9
#define FINDING_BOTTOM          10
#define LOCKED                  11
#define HOME_FROM_TOP           12
#define HOME_FROM_BOTTOM        13
#define PLACING                 14

//NAME of Gain				ID
#define LAUNCHER_P				13
#define LAUNCHER_I				0
#define LAUNCHER_D				0
#define LAUNCHER_DENOM          100
#define LAUNCHER_I_MAX          100
#define GAIN_1		32  //0.1s * 40t/s = 4 ticks -- 127/4 = 32

#define LAUNCHER_M          1
#define POT_FLOOR           (pot_top - 2300)
#define POT_CUTOFF          (pot_top - TOP_DELTA)
#define POT_HOME            (pot_top - 950)
#define POT_TOP_DEFAULT		2400
#define TOP_DELTA           100
#define FLOOR_MOTOR         -127
#define WANTED_BRAKE_TICKS  10
#define CAL_TICKS_AMT       13
#define OPEN_B              1
#define CLOSE_B             0


#define LAUNCH_MOTOR        pwm07=pwm08
#define GRIPPER_MOTOR_A     pwm10
#define GRIPPER_MOTOR_B     pwm11
#define LAUNCH_BRAKE_FWD    relay5_fwd
#define LAUNCH_BRAKE_REV    relay5_rev
#define BRAKE_DELTA         1 //1 or 0
#define MANUAL_UP_DENOM     2
#define MANUAL_DOWN_DENOM   2

unsigned char ticks=0; //keeping track
unsigned char good_to_launch=0; //flag to signal launcher
int motor_l; //launcher motor placeholder
int motor_g; //gripper motor placeholder
unsigned char brake=0,tilter=0; //relays
int launcher_pot; //feedback on launceher position
PID launcher; //probably wont use this..
unsigned char auto_flag;

void Launcher_Autonomous(void){
    Launcher_State_Machine();
    LAUNCH_MOTOR = (unsigned char) LimitChar(-motor_l);
    GRIPPER_MOTOR_A = 127+15;
    GRIPPER_MOTOR_B = 127-15;
}

void Launcher_Handler(void){
    Launcher_State_Machine();
    LAUNCH_MOTOR = (unsigned char) LimitChar(-motor_l);
        GRIPPER_MOTOR_A = (unsigned char) LimitChar(-motor_g);
        GRIPPER_MOTOR_B = (unsigned char) LimitChar(motor_g);


}

void SetGripper(int in){

    motor_g = in;
}

void Launcher_State_Machine(void){
    //all in function variables
    static int state=FINDING_TOP,launcher_pot_old=0,joystick=0,pot_top=POT_TOP_DEFAULT,pot_bottom=1000,pot_delta=0;
    static unsigned char brake_ticks=0,launching_from_home=0,launcher_ticks=0,cal_ticks=0,home_lock_ticks=0,home_ticks=0;

	pot_bottom = POT_FLOOR;

    //get the launcher pot value
    launcher_pot = Get_ADC_Result(1) * 4; //multiply by 4 to account for no oversampling.. just easier this way

    pot_delta = launcher_pot - launcher_pot_old;
   //printf("Pot: %4d | Top: %4d | Bottom: %4d  | s: %d | m: %3d\n\r",launcher_pot,pot_top,pot_bottom,state,motor_l);
   //printf("brake relay: %d | wanted relay: %d \r\n", BRAKE_RELAY,brake);

	////////////////////////////////////////
    //Do Operator Control
	////////////////////////////////////////
    joystick = (int) (ARM_OP_STICK) - 127;
    motor_g = joystick;
	//state changes
    if(state != FINDING_TOP){
        if(OP_HOME) state = HOME;
        if(OP_FLOOR) state = FLOOR;
        if(OP_IDLE) state = IDLE;
    }



    //Make sure its ok to launch
    if(state != LAUNCHING)
        good_to_launch = 0;

    //state machine for launcher
    switch(state)
    {

        case FINDING_TOP:
			//set motor to zero, elastic will pull launcher to top
            motor_l = -8;
            brake = OPEN_B;
			//when the delta between cycles is 0 for a little bit, set new top and cycle state
            if(launcher_pot == launcher_pot_old){
                cal_ticks++;
                if(cal_ticks >= CAL_TICKS_AMT){
                    pot_top = launcher_pot;
                    state = HOME;
                }
            }
            else cal_ticks = 0;
            break;

        case FINDING_BOTTOM:
			//do this later
			state = IDLE;
            break;

        case HOME:

			if(launcher_pot > POT_HOME)
                state = HOME_FROM_TOP;
            else
                state = HOME_FROM_BOTTOM;
			//dont destroy the launcher
            launching_from_home=1;
            break;

        case HOME_FROM_TOP:
            brake = OPEN_B;
            motor_l = -55;
			//slow crappy control loop, use 25 val deadband to account for overshoot time
            if(launcher_pot <= (POT_HOME + 25)){
                brake = CLOSE_B;
				//it takes longer for the brake to engage than to stop the motor, so keep on truckin'
                if(home_lock_ticks > 7)
                    state=LOADED;
                home_lock_ticks++;
            }
            break;

        case HOME_FROM_BOTTOM:
            brake = OPEN_B;
			//little bit of backdrive to slow the elastics down
            motor_l = -17;
            home_ticks++;

			//the brake can only engage when the launcher is moving down
			//or else the brake gets FUBAR'd
			//so, go all the way to the top, then back to the middle
            if(launcher_pot >= (pot_top-TOP_DELTA)){
                motor_l = 0;
                home_lock_ticks++;
				//delay at the top a bit
                if(home_lock_ticks > 10){
                    home_lock_ticks=0;
                    home_ticks = 0;
                    state=HOME;
                }
            }
			//if the ball is on the backdrive is too much
			//instead of an elegant solution, just check time for a stall then release the backdrive
            if( (home_ticks > 42) ){ //this is absolutely random?
                motor_l = 0;
            }
            break;

        case LOCKED:
			//reset stuff
            home_lock_ticks=0;
            home_ticks=0;
			//lock the brake
            brake = CLOSE_B;
			//turn off motor
            motor_l = 0;
            break;

        case FLOOR:
            Compressor_Override();
			//bring this baby to the ground
            brake = OPEN_B;
            motor_l = FLOOR_MOTOR;
            //check to see brakers popped

			// if the motor stalls on the way down breakers will pop
			// and elastic will pull the ball up. when this happens
			// change state to idle
            if(pot_delta > 20){
                state = IDLE ;
            }

			// when we get to the bottom, lock it up
            if(launcher_pot <= pot_bottom){
                brake = CLOSE_B;
                state = BRAKING;
                brake_ticks=0;
            }

            launching_from_home=0;
            break;

        case BRAKING:
          //  Compressor_Override();
            brake = CLOSE_B;
            motor_l = FLOOR_MOTOR;
            if(brake_ticks > WANTED_BRAKE_TICKS)
                state = LOADED;
            brake_ticks++;
            break;

        case ARMED:
            brake = CLOSE_B;
            motor_l = 0;
			// we can only  place when the robot is armed!
            if(OP_ARM && OP_LAUNCH){
                state = PLACING;
                break;
            }

			// we can only  launch when the robot is armed!
			//only launch when the tilter is tilted back
            if(OP_LAUNCH && !tilter){
                good_to_launch = 1; //tell launcher its ok to go
                state = LAUNCHING;
            }
            break;


        case LOADED:
			//lock everything down and reset counters
            home_lock_ticks = 0;
            brake_ticks = 0;
            motor_l=0;
            brake = CLOSE_B;
			//we can only arm when locked
           #ifdef PRACTICE_BOT
            if(OP_ARM)
            #endif
                state = ARMED;
            break;

        case PLACING:
			//drive launcher up slowly to throw ball into overpass
		//	Compressor_Override();
            brake = OPEN_B;
            motor_l = 44;
            if(launcher_pot >= (pot_top-TOP_DELTA)){
                state = IDLE;
            }
            break;

        case LAUNCHING:
            //when launch is finished go back home
            motor_g = 0;
            Compressor_Override();
            brake = OPEN_B;
            launcher_ticks++;

            if(good_to_launch){
                motor_l = 127; //full bore forward
            }
            else motor_l = 0;//-80; //stop motor

			//cutoff launcher when launching from ground with no ball

           /* if( !launching_from_home &&
				(launcher_pot >= ((pot_top - pot_bottom) / 4)) &&
				(launcher_ticks <= 6) )
			{
			    printf("CRAP!!!!!!!\r\n");
                motor_l = 0; //random...
                good_to_launch = 0;
            }
            */

			//cutoff launcher when it hits the top
            if(launcher_pot >= (pot_top-TOP_DELTA)){
               launcher_ticks=0;
               launching_from_home=0;
               ShiftLow();
               Drive(0,0);
               state = IDLE;
            }

            break;

        case MANUAL:
            brake = OPEN_B;
            if(joystick >= 0);
              //  motor_l = joystick / MANUAL_UP_DENOM;
            else;
             //   motor_l = joystick / MANUAL_DOWN_DENOM;
            break;

        case IDLE:
            motor_l = 0;
            brake = OPEN_B;
            cal_ticks=0;
            break;

        default:
            printf("*** We defaulted. Something is really wrong. Call the fire brigade.\r\n");
            state = IDLE;
            break;
    }

	//keep track of launcher pot
    launcher_pot_old=launcher_pot;

	// control the brake
    if(brake) OpenBrake();
    else CloseBrake();

	//control the tilter
    TILT_RELAY_FWD = !tilter;
    TILT_RELAY_REV = !TILT_RELAY_FWD;

}

void ToggleTilter(void){
    tilter = !tilter;
}

void SetTilter(unsigned char in){
    if(in == 1) tilter = 1;
    else if( in == 0) tilter = 0;
}
void OpenBrake(void){
    LAUNCH_BRAKE_FWD = BRAKE_DELTA;
    LAUNCH_BRAKE_REV = 0; //!BRAKE_DELTA;
}

void CloseBrake(void){
    LAUNCH_BRAKE_FWD = !BRAKE_DELTA;
    LAUNCH_BRAKE_REV = 0; //BRAKE_DELTA;
}

void Initialize_Launcher(void){
    InitPID(&launcher, LAUNCHER_P, LAUNCHER_I,LAUNCHER_D,LAUNCHER_I_MAX);
}


