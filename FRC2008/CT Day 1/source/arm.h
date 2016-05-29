#ifndef _ARM_H
#define _ARM_H

//Info about system
#define TOP_LIMIT_SWITCH		rc_dig_in12
#define BOTTOM_LIMIT_SWITCH		rc_dig_in11
#define ARM_PWM					pwm03=pwm04
#define ENCODER_PPR				128
#define IN_PER_REV				2
#define LEAD_SCREW_LENGTH		235 // in 0.1 "
#define LENGTH_SCALE_FACTOR		10 //get back to inches from tenths
#define TICK_LENGTH				( (LEAD_SCREW_LENGTH * TICKS_PER_IN) / LENGTH_SCALE_FACTOR )
#define TICKS_PER_IN			(ENCODER_PPR * IN_PER_REV)
#define ALLOWABLE_ERROR         15 //about 1/8"
#define A_CLOSED                  1
#define A_OPEN                    0

#define WRIST_RELAY_FWD         relay4_fwd
#define WRIST_RELAY_REV         relay4_rev
#define FINGER_RELAY_FWD        relay1_fwd
#define FINGER_RELAY_REV        relay1_rev
#define BRAKE_RELAY             relay2_fwd

//Upper and Lower bounds for lead screw.
//This is the first line of defense. Limit switches should be backup
#define LOWER_BOUND_ENCODER 	10
#define UPPER_BOUND_ENCODER		5250

//Slow down near limits
//ex only go half speed when one inch away from limits
#define DOWN_SLOW_DELTA			(LOWER_BOUND_ENCODER + (TICKS_PER_IN * 3)) //start slowing down
#define DOWN_FINE_DELTA			(LOWER_BOUND_ENCODER + (TICKS_PER_IN * 1)) //even slower
#define DOWN_STOP_DELTA			(LOWER_BOUND_ENCODER + (TICKS_PER_IN / 2)) //almost at a dead stop
#define UP_SLOW_DELTA			(UPPER_BOUND_ENCODER - (TICKS_PER_IN * 3)) //start slowing down
#define UP_FINE_DELTA           (UPPER_BOUND_ENCODER - (TICKS_PER_IN * 1)) //even slower

//limit scales for above zones
#define DOWN_SLOW_DENOMINATOR	2
#define DOWN_FINE_DENOMINATOR	2
#define DOWN_STOP_DENOMINATOR   2
#define UP_SLOW_DENOMINATOR		1
#define UP_FINE_DENOMINATOR	    2

//Software dependancies
#define ARM_ENCODER				Get_Encoder_2_Count
#define ARM_ENCODER_RESET		Reset_Encoder_2_Count

#define ARM_P_GAIN              46
#define ARM_I_GAIN              0
#define ARM_D_GAIN              0
#define RAMP_UP_DELTA           3
#define ARM_I_MIN               -100
#define ARM_I_MAX               100



//Control inputs
#define ARM_CONTROL_STICK    (char) ((255- p4_y) - 127)
#define FINGER_SW          p4_sw_trig
#define WRIST_SW              p4_sw_top
#define MANUAL_CONTROL_SW   controls.manual_control
//#define ARM_CONTROL_STICK   p4_y
#define ARM_SW_HOME         controls.floor
#define ARM_SW_FLOOR        controls.home
#define ARM_SW_BOTTOM       controls.bottom_row
#define ARM_SW_MIDDLE       controls.middle_row
#define ARM_SW_TOP          controls.top_row
#define SPOILER_SW          0 //controls.spoiler_mode
#define ARM_SW_HUMAN        controls.human
#define ARM_SW_DO           controls.start

//Positions
#define POS_HOME            0
#define POS_FLOOR           0
#define POS_BOTTOM          1550
#define POS_BOTTOM_SPOILER  1310
#define POS_BOTTOM_DO       (POS_BOTTOM)

#define POS_MIDDLE          3700
#define POS_MIDDLE_SPOILER  3570
#define POS_MIDDLE_DO       (POS_MIDDLE - 1000)

#define POS_TOP             5325
#define POS_TOP_SPOILER  5125
#define POS_TOP_DO       (POS_TOP - 1000)

#define POS_HUMAN_HIGH      3500
#define POS_HUMAN_HIGH_DO   4200

#define POS_HUMAN_LOW       3500
#define POS_HUMAN_LOW_DO    3600

//STATES
#define WRIST_UP            1
#define WRIST_DOWN          0
#define FINGER_OUT          1
#define FINGER_IN           0

#define STATE_HOME          1
#define STATE_FLOOR         3
#define STATE_FLOOR_DO      (STATE_FLOOR_DO + 1)

#define STATE_BOTTOM        5
#define STATE_BOTTOM_DO     (STATE_BOTTOM + 1)
#define STATE_BOTTOM_SPOILER (STATE_BOTTOM + 100)
#define STATE_BOTTOM_SPOILER_DO (STATE_BOTTOM_SPOILER + 1)

#define STATE_MIDDLE        7
#define STATE_MIDDLE_DO     (STATE_MIDDLE + 1)
#define STATE_MIDDLE_SPOILER (STATE_MIDDLE + 100)
#define STATE_MIDDLE_SPOILER_DO (STATE_MIDDLE_SPOILER + 1)

#define STATE_TOP        9
#define STATE_TOP_DO     (STATE_TOP + 1)
#define STATE_TOP_SPOILER (STATE_TOP + 100)
#define STATE_TOP_SPOILER_DO (STATE_TOP_SPOILER + 1)

#define STATE_HUMAN_HIGH      11
#define STATE_HUMAN_HIGH_DO     (STATE_HUMAN_HIGH + 1)
#define STATE_HUMAN_LOW         13
#define STATE_HUMAN_LOW_DO     (STATE_HUMAN_LOW + 1)

#define STATE_IDLE          15





//Prototypes
void Arm_Operator_Control(void);
void Initialize_Arm(void);
void Drive_Arm(char speed);
char Limit_Output(char speed);
void Set_Arm_Position(unsigned int input_position);
void Set_Arm_State(unsigned int input_state);
void Arm_Handler(void);
char RampUpArm(char input, char arm_prev_value);
void End_Effector(char iWrist, char iFinger);

#endif
