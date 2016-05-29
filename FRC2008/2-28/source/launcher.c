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

//NAME of Gain				ID
#define LAUNCHER_P				13
#define LAUNCHER_I				0
#define LAUNCHER_D				0
#define LAUNCHER_DENOM          100
#define LAUNCHER_I_MAX          100
#define GAIN_1		32  //0.1s * 40t/s = 4 ticks -- 127/4 = 32

#define LAUNCHER_M          1
#define POT_FLOOR           (pot_top - 2300)
#define POT_CUTOFF          1500
#define POT_HOME            (pot_top - 850)
#define TOP_DELTA           100
#define FLOOR_MOTOR         -127
#define WANTED_BRAKE_TICKS  10
#define CAL_TICKS_AMT       9
#define OPEN_B              1
#define CLOSE_B             0

#define ARM_OP_STICK        p4_y
#define OP_HOME             p3_sw_aux1
#define OP_FLOOR            p3_sw_trig
#define OP_LAUNCH           p3_sw_top
#define OP_ARM              p3_sw_aux2
#define OP_IDLE             p4_sw_top

#define LAUNCH_MOTOR        pwm07=pwm08
#define LAUNCH_BRAKE_FWD    relay5_fwd
#define LAUNCH_BRAKE_REV    relay5_rev
#define BRAKE_DELTA         1 //1 or 0
#define MANUAL_UP_DENOM     2
#define MANUAL_DOWN_DENOM   2

unsigned char ticks=0;
unsigned char good_to_launch=0;
int motor_l; //launcher motor placeholder
int motor_g; //gripper motor placeholder
int launcher_pot;
PID launcher;

void Launcher_Handler(void){
    Launcher_State_Machine();
    LAUNCH_MOTOR = (unsigned char) LimitChar(motor_l);
   // GRIPPER_MOTOR = (unsigned char) (g_output + 127);
}

void Launcher_State_Machine(void){
    //all in function variables
    static int state=FINDING_TOP,launcher_pot_old=0,joystick=0,pot_top=POT_CUTOFF,pot_bottom=1000;
    static unsigned char brake_ticks=0,cal_ticks=0,home_lock_ticks=0,brake=0,crap_ticks=0;
    pot_bottom = POT_FLOOR;
    //get the launcher pot value
    launcher_pot = Get_ADC_Result(1) * 4;
    printf("Pot: %4d | Top: %4d | Bottom: %4d | ticks: %d | state: %d | m: %3d\n\r",launcher_pot,pot_top,pot_bottom,cal_ticks,state,motor_l);

    //Do Operator Control
    joystick = (int) (ARM_OP_STICK) - 127;
    if(OP_HOME) state = HOME;
    if(OP_FLOOR) state = FLOOR;
    if(OP_IDLE) state = IDLE;

    //Make sure its ok to launch
    if(state != LAUNCHING)
        good_to_launch = 0;

    //state machine
    switch(state)
    {

        case FINDING_TOP:
            motor_l = 0;
            brake = OPEN_B;
            if(launcher_pot == launcher_pot_old){
                cal_ticks++;
                if(cal_ticks >= CAL_TICKS_AMT){
                    pot_top = launcher_pot;
                    state = IDLE;
                }
            }
            else cal_ticks = 0;
            break;

        case FINDING_BOTTOM:
            break;

        case HOME:
            if(launcher_pot > POT_HOME)
                state = HOME_FROM_TOP;
            else
                state = HOME_FROM_BOTTOM;
            break;

        case HOME_FROM_TOP:
            brake = OPEN_B;
            //motor_l = 0;
            motor_l = -64;//((POT_HOME - launcher_pot) * LAUNCHER_P)/LAUNCHER_DENOM;//GetPID(&launcher,POT_HOME,launcher_pot);
            if(launcher_pot <= (POT_HOME + 25)){
                brake = CLOSE_B;
                if(home_lock_ticks > 7)
                    state=LOCKED;
                home_lock_ticks++;
            }
            break;
        case HOME_FROM_BOTTOM:
            state = IDLE;
            break;
        case LOCKED:
            home_lock_ticks=0;
            brake = CLOSE_B;
            motor_l = 0;
            break;
        case FLOOR:
            brake = OPEN_B;
            motor_l = FLOOR_MOTOR; //((POT_HOME - launcher_pot) * LAUNCHER_P)/LAUNCHER_DENOM;
            if(launcher_pot <= pot_bottom){
                brake = CLOSE_B;
                state = BRAKING;
                brake_ticks=0;
            }
            break;

        case BRAKING:
            brake = CLOSE_B;
            motor_l = FLOOR_MOTOR;//((POT_HOME - launcher_pot) * LAUNCHER_P)/LAUNCHER_DENOM;
            if(brake_ticks > WANTED_BRAKE_TICKS)
                state = LOADED;
            brake_ticks++;
            break;

        case ARMED:
            brake = CLOSE_B;
            motor_l = 0;
            if(OP_LAUNCH)
                state = LAUNCHING;
            break;


        case LOADED:
            brake_ticks = 0;
            motor_l=0;
            brake = CLOSE_B;
            if(OP_ARM) state = ARMED;
            break;

        case LAUNCHING:
            //when launch is finished go back home
            brake = OPEN_B;

            //if(launcher_pot > (launcher_pot_old+4) ){//dont launch until the brake releases
                good_to_launch = 1; //Full bore forward
            //}
            if(good_to_launch){
                motor_l = 127; //full bore forward
            }
            else motor_l = 0; //stop motor

            if(launcher_pot >= (pot_top-TOP_DELTA)){
                printf("**************  Cutoff: %d \r\n",launcher_pot);
                state = IDLE;
            }
            break;

        case MANUAL:
            brake = OPEN_B;
            if(joystick >= 0)
                motor_l = joystick / MANUAL_UP_DENOM;
            else
                motor_l = joystick / MANUAL_DOWN_DENOM;

            break;
        case IDLE:
            motor_l = 0;
            brake = OPEN_B;
            cal_ticks=0;
            break;
        default:
            state = IDLE;
            break;
    }
    launcher_pot_old=launcher_pot;

    if(p4_wheel > 127){
        if(p4_sw_trig) brake = OPEN_B;
        else brake = CLOSE_B;
    }

    if(brake) OpenBrake();
    else CloseBrake();
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


