#include "WPILib.h"
#include <math.h>
#include "Utilities.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* CURRENT_VERSION = "4.3.1";
// DriverStationLCD *LCD = NULL;

// PID GLOBALS =======================================================================================================

const UINT8 na = 4;  // 4 axis
UINT8 t_axis;

enum axis_def 
{
	pivot,
	gripper,
	elevator,
	mini
};

enum tune_control 
{
	off,
	up,
	down,
	both
};

// HOMING
volatile int homing_state[na];

enum homing_states
{
	homed,
	start,
	moving_to_park_dly,
	moving_to_park,
	parked,
	moving_to_stops,
	moving_to_stops_dly,
	moving_to_home,
	at_home,
	homed_parking
};


// IRQ
const double IRQ_RATE = 10000.0; // period in microseconds
const float irq_rate_ms = IRQ_RATE / 1000; // period in milliseconds
const float irq_rate_sec = IRQ_RATE / 1000000; // period in milliseconds

// I/O	
volatile float pos_pot[na];		//assume    0 to  1
volatile float motor_out[na];	 	//assume  -1 to +1
volatile float vel_cmd[na];
volatile float pot_in[na];

// FACTORS (to convert raw pot values to inches)
const float gripper_pot_factor = 6.0;
const float pivot_pot_factor = 13.157;
const float elevator_pot_factor = 18.34;
const float minibot_pot_factor = 7;

// CMD         
volatile float pos_cmd[na];			
volatile float pos_cmd_i[na];
volatile float direction[na];

// PARAMETERS  IN
volatile float pot_offset[na];   	// from home routine
volatile float park_position[na];

// PID TUNING
volatile float p_up[na]; 		//out
volatile float p_dn[na]; 		//in
volatile float d_up[na];  		
volatile float d_dn[na];  		

volatile float tune_pot_a;
volatile float tune_pot_b;

volatile float tune_d;
volatile float tune_p;

// LIMITS
volatile float limit_up[na];
volatile float limit_dn[na];
volatile float speed[na];

//PID TEST SETUP
volatile float t_lim_up [na];
volatile float t_lim_dn [na];
volatile float t_pos_up [na];
volatile float t_pos_dn [na];
volatile float t_jog_time [na];

const bool slow_mo = true;

// USABLE VALUES 
volatile float rate[na]; // use to check for stall
volatile float error[na]; // use to check for 'at position' 
volatile float pot_pos[na]; // position with offset factored in

volatile float stopped_rate[na];
volatile float stopped_last[na];

volatile float pos_last[na]; // unusable, just needed a static

volatile float dly_tmr;
volatile float launch_time = 0;

// @OTHER GLOBALS ======================================================================================

volatile int auto_straight_state = 0;
volatile int auto_split_state = 0;

volatile float auto_drive_vel;
volatile float auto_drive_turn;
volatile float auto_dir_error;

const float mini_deploy_val = 36.75;
const float mini_armed_val = 30.3;
volatile bool minibot_commanded_to_launch = false;
const float minibot_launch_time_value = 110.0;

const float midpoint_voltage = 3.5; // !!
const float line_end_combined_voltage = 4.67;
volatile float auto_drive_speed; // Set in autonomousinit
const float auto_turn_speed = 0.4;

volatile bool two_tubes;
volatile bool auto_split;

volatile int auto_dir;

const float fork_combined_voltage = 9.4;
const float black_detect_voltage = 2.75;

enum pwm_inputs
{
	left_jags_in = 1, // Y-cable, hence "jags"
	right_jags_in, // Y
	elevator_jags_in, // Y
	pivot_jag_in,
	gripper_jag_in,
	minibot_jag_in
};

enum analog_channels_mod_1
{
	elevator_pot_in = 1,
	pivot_pot_in,
	gripper_pot_in,
	accelerometer_in,
	minibot_pot_in,
	ps_left_in,
	ps_right_in,
	battery_voltage
};

/*
enum analog_channels_mod_2
{
	tune_pot_1 = 1,
	tune_pot_2,
	minibot_pot_in,
	ps_mid_in
};
*/

enum digital_ios
{
	digital_io_1 = 1,
	digital_io_2,
	digital_io_3,
	digital_io_4,
	digital_io_5,
	digital_io_6,
	digital_io_7,
	digital_io_8
};

enum joystick_values
{
	right_black_stick_val = 1,
	left_black_stick_val,
	appendage_stick_val
};

enum joy_buttons
{
	button_trigger = 1, // Gripper Close
	button_2, // Pivot Down (around 55 degrees)
	button_3, // Elevator Home
	button_4, // Tube Pickup (state machine) / Drag depending on stick
	button_5, // allows robot to be driven with the appendage joystick (may not be enabled)
	button_6, // unused
	button_7, // 7 through 12 are the pre-set elevator heights
	button_8,
	button_9,
	button_10,
	button_11,
	button_12
};

enum RefSide {left_side, right_side};

enum auto_straight_states
{
	str_command_elevator,
	str_drive_forward,
	str_slow_down,
	str_halt_at_line,
	str_command_pivot,
	str_pivot_down_delay,
	str_retract_pivot,
	str_gripper_closing,
	str_back_up,
	str_park_pivot,
	str_park_elevator,
	str_spin_on_tmr,
	str_find_line,
	str_drive_to_center_field
};

enum auto_split_states
{
	spl_drive_to_split,
	spl_drive_past_split,
	spl_turn_on_timer,
	spl_find_line,
	spl_execute_partial_straight_machine,
	spl_back_up
};

enum directions
{
	dir_left = -1,
	dir_right = 1
};

enum pivot_pickup_states
{
	pickup_parked,
	pickup_start,
	pickup_to_floor_dly,
	pickup_to_floor,
	pickup_grab_dly,
	pickup_test_grab,
	pickup_failed,
	pickup_got_tube,
	pickup_got_tube_dly,
	pickup_pivoting_up
};

enum pivot_score_states
{
	score_check_tube,
	score_pivot_down,
	score_gripper_wait
};

bool drives_enabled;

// Potentiometer values for elevator
float rack_locations_pot[7];

// Jaguar drive values
float joy_velocity = 0.0;
float joy_turn = 0.0;
float tank_left = 0.0;
float tank_right = 0.0;

// Elevator values
float elevator_current_height = 0.0;
float elevator_target_height = 0.0;
float elevator_home_height = 0.01;

// States for the state machines
int score_state = 0;
int pickup_state = 0;
int drag_state = 0;
int gripper_state = 0;
int elevator_state = 0;

// Testing code
bool gyro_code_enabled = false;
bool pivot_is_moving = false;
float virtual_pivot = 45.0;

// Pivot positions (Pot values)
const float pivot_home_val = 0.57 * pivot_pot_factor;
const float pivot_score_val = 24.5;
volatile float pivot_floor_val;
const float pivot_tolerance = 0.0;

// Gripper positions (pot values)
const float gripper_open_val = 24.0;
const float gripper_closed_val = 0.48 * gripper_pot_factor;
const float gripper_tolerance = 0.2;
volatile float gripper_slightly_open;

float gripper_current_val = 0.0;
float gripper_target_val = 0.0;

float accelerometer_cal = 0.0;
bool accelerometer_code_enabled = true;

float cal_acceleration;
float turn_adjust_value;

const int num_accelerometer_samples = 100000;

FILE *pInFile;
FILE *pOutFile;

char* home_path = "test.txt";

volatile int match_period;

enum match_period
{
	teleoperated,
	autonomous
};

float test_var = 0.0;

// END OF GLOBAL VARIABLES ============================================================================================

/**
 * Code for Knightmare 2K11
 * FIRST Robotics Competition, Logomotion 2011, Team 195
 * Credited to Brandon Duffany, George Bucci, Carmine Mauriello
 */

class Knightmare2K11 : public IterativeRobot
{
	// @Object declarations
	
	RobotDrive myRobot;
	
	Joystick stick_left;
	Joystick stick_right;
	Joystick stick_appendage;
	
	Accelerometer accelerometer;
	
	AnalogChannel elevator_pot;
	AnalogChannel pivot_pot;
	AnalogChannel gripper_pot;
	// AnalogChannel distance_sensor;
	AnalogChannel photosensor_left;
	AnalogChannel photosensor_right;
	
	AnalogChannel minibot_pot;
	// AnalogChannel tune1;
	// AnalogChannel tune2;
	// AnalogChannel photosensor_mid;
	
	DigitalInput auto_two_tube_switch;
	DigitalInput auto_split_switch;
	DigitalInput auto_direction_switch;
	
	Timer match_time;
	Timer teleop_time;
	
	Jaguar jags_elevator;
	Jaguar jag_gripper;
	Jaguar jag_pivot;
	Jaguar jag_minibot;

public:
	
	Knightmare2K11(void):
		
		// @Construction
		
		myRobot(left_jags_in, right_jags_in),
				
		stick_left(left_black_stick_val),
		stick_right(right_black_stick_val),
		stick_appendage(appendage_stick_val),
		
		// AnalogModule 1
		
		accelerometer(accelerometer_in),
		elevator_pot(elevator_pot_in),
		pivot_pot(pivot_pot_in),
		gripper_pot(gripper_pot_in),
		// distance_sensor(dist_sensor_in),
		photosensor_left(ps_left_in),
		photosensor_right(ps_right_in),
		minibot_pot(minibot_pot_in),
		
		/*
		// AnalogModule 2
		tune1(2, tune_pot_1),
		tune2(2, tune_pot_2),
		photosensor_mid(2, ps_mid_in),
		*/
		
		auto_two_tube_switch(digital_io_1),
		auto_split_switch(digital_io_2),
		auto_direction_switch(digital_io_3),
		
		// PWM Objects
		
		match_time(),
		teleop_time(),
		
		jags_elevator(elevator_jags_in),
		jag_gripper(gripper_jag_in),
		jag_pivot(pivot_jag_in),
		jag_minibot(minibot_jag_in)
		
	{
		GetWatchdog().SetExpiration(0.1);
	}
	
	// Check to see if the desired axis is at the position
	bool at_position(UINT8 axis, float tolerance = 1)
	{
		return (fabs (error[axis]) < tolerance);
	}
	
	// Checks to see if the axis is stalled
	bool stalled(UINT8 axis, float tolerance = 0.03)
	{
		return (fabs (stopped_rate[axis]) < tolerance);
	}
	
	// P and D values for PID routine
	void load_tuning_parameters(void)
	{
		t_axis = 255;  //shut down tuning routine

		p_up[gripper] = 0.1006; 		
		p_dn[gripper] = 0.1006; 		
		d_up[gripper] = 2.0224;  		
		d_dn[gripper] = 2.0224;
		
		p_up[pivot] = 0.0431; 	
		p_dn[pivot] = 0.0431; 		
		d_up[pivot] = 0.9175;  		
		d_dn[pivot] = 0.9175;

		p_up[elevator] = 0.1834; 		
		p_dn[elevator] = 0.1834; 		
		d_up[elevator] = 0.0845;  		
		d_dn[elevator] = 0.0845;

		p_up[mini] = 0.127082; 		
		p_dn[mini] = 0.127082; 		
		d_up[mini] = 5.563001;  		
		d_dn[mini] = 5.563001;
		
		park_position[gripper] = 0.5;
		park_position[pivot] = 5.5; // @@@ NATIONALS: 3.5
		park_position[elevator] = 1.8;
		park_position[mini] = 1; // !!
		
		pivot_floor_val = 45.6; // @@@ NATIONALS: 46.0
		gripper_slightly_open = park_position[gripper] + 1.5;
	}
	
	// Called once at robot init
	
	
	void pid_tune_setup(void)
	{
		for (UINT8 axis = 0; axis < na; axis++)
		{
			t_lim_up [axis] =  .3;
			t_lim_dn [axis] =  -0.3;
			t_pos_up [axis] =  16;
			t_pos_dn [axis] =  8;
			t_jog_time [axis] = 2; //2 sec between jogs
			pot_offset[axis] = 0;  //ultimately set by the homing routines
		}
	}
	
	void set_position(UINT8 axis, float pos_target, float up = 1, float dn = -0.35, float spd=1000)
	{
		if (axis > na) 
			return;

		if (dn > 0)
			dn *= -1;

		if (up < 0)
			up *= -1;

		limit_up[axis] = up;
		limit_dn[axis] = dn;
		speed[axis] = spd;
		direction[axis] = pos_target - pos_pot[axis];
		pos_cmd [axis]= pos_target;
		// enable_drive (axis);
	}
	
	void stop(UINT8 axis)
	{
		static float last_pos_stopped;
		static float pos_stopped;
		pos_stopped = pos_pot[axis];
		pos_stopped = last_pos_stopped;
		set_position(axis, pos_stopped, .3, -.3, 5);
		last_pos_stopped = pos_stopped;
	}
	
	// Returns whether the delay timer is negative
	bool delay_passed()
	{
		return dly_tmr < 0;
	}
	
	// PID Routine; Called periodically ==============================================================================
	void pid(void) //PID_IRQ
	{
		static volatile UINT8 num_executions;
		// static bool first_minibot_launched = true;
		
		pot_in[gripper] = gripper_pot.GetAverageVoltage() * gripper_pot_factor;
		pot_in[pivot] = pivot_pot.GetAverageVoltage() * pivot_pot_factor;
		pot_in[elevator] = elevator_pot.GetAverageVoltage() * elevator_pot_factor;
		pot_in[mini] = minibot_pot.GetAverageVoltage() * minibot_pot_factor;
		
		dly_tmr -= (irq_rate_sec * 2); // IRQ rate is actually 50hz
		
		for (UINT32 axis = 0; axis < na; axis++)
		{
			
			if (pos_cmd[axis] > pos_cmd_i[axis])
			{
				pos_cmd_i[axis] += (speed[axis] * irq_rate_sec);
				if (pos_cmd_i[axis] > pos_cmd[axis])
					pos_cmd_i[axis] = pos_cmd[axis];
			}
			else
			{
				pos_cmd_i[axis] -= (speed[axis] * irq_rate_sec);
				if (pos_cmd_i[axis] < pos_cmd[axis])
					pos_cmd_i[axis] = pos_cmd[axis];
			}
			
			pos_pot[axis] = pot_in[axis] - pot_offset[axis];
			error[axis] = pos_cmd_i[axis] - pos_pot[axis];
			rate[axis] = (pos_pot[axis] - pos_last[axis]) / irq_rate_ms;
			pos_last[axis]  = pos_pot[axis];
			
			num_executions++;
			
			if (num_executions > 40) // !!
			{
				num_executions = 0;
				
				stopped_rate[axis] = (pos_pot[axis] - stopped_last[axis]) / irq_rate_ms;
				stopped_last[axis] = pos_pot[axis];
			}
			
			if (direction > 0)  // up
				vel_cmd[axis]  = (error[axis]  * p_up[axis]) - (rate[axis]  * d_up[axis]);
			else
				vel_cmd[axis]  = (error[axis]  * p_dn[axis]) - (rate[axis]  * d_dn[axis]);
			
			limit_up[mini] = 0.3;
			limit_dn[mini] = -0.3;
			
			if (vel_cmd[axis]  > limit_up[axis]) 
				vel_cmd[axis]  = limit_up[axis];
			else if (vel_cmd[axis]  <  limit_dn[axis])
				vel_cmd[axis]  = limit_dn[axis];

			if (axis == elevator)
				if (pos_pot[axis] < 18 && vel_cmd[axis] < 0)
					vel_cmd[axis] /= 2;
			
			motor_out[axis] = vel_cmd[axis];
			
		}
		
		/*
		if(minibot_commanded_to_launch)
		{
			if(first_minibot_launched){
				launch_time = teleop_time.Get();
				first_minibot_launched = false;
			}
				
			motor_out[mini] = 0.4;
			if(pos_pot[mini] > mini_deploy_val + 0.5 || teleop_time.Get() > (launch_time + 0.5))
			{
				motor_out[mini] = 0;
				if (teleop_time.Get() > launch_time + 3)
					minibot_commanded_to_launch = false;
			}
		}
		*/
		
		if (drives_enabled)
		{
			jag_gripper.Set(motor_out[gripper]); 
			jag_pivot.Set(motor_out[pivot] * -1); // (Potentiometer is reversed)
		    jags_elevator.Set(motor_out[elevator]);
			jag_minibot.Set(motor_out[mini]);
		}
		else
		{
			jag_gripper.Set(0); 
			jag_pivot.Set(0);
		    jags_elevator.Set(0);
		    jag_minibot.Set(0);
		}
	}
	
	// PID tuning (with oscilloscope)... No longer in use
	
	void tune_jog(void)
	{
		GetWatchdog().Feed();
		
		static volatile float time;
		static volatile float pos;
		
		if (t_axis > na) 
			return;
		
		if (t_jog_time[t_axis] < .1) 
			return;

		time += 0.01;
		
		if ((time >= 0) && ( time < t_jog_time[t_axis] )) 
			return;
		
		time = 0;
		
		if (pos == 12) pos = 24;
		else pos = 12;
			
		set_position(t_axis, pos, 1, -.35);
		
		/*
		
		if  (pot_pos[t_axis] < t_pos_dn[t_axis])
		       set_position  (t_axis, t_pos_up[t_axis], t_lim_up[t_axis],t_lim_dn[t_axis]);

		if  (pot_pos[t_axis] > t_pos_up[t_axis])
		       set_position  (t_axis, t_pos_dn[t_axis], t_lim_up[t_axis],t_lim_dn[t_axis]);
		
		*/
	}
	
	void tune(UINT8 axis, float spread, UINT32 ctrl=3)
	{
		
		if (axis > na) return; 			// spread = 02 means adjust  1/2   to   2x
	       	t_axis = axis;				// spread =10 means adjust 1/10th to 10x
		
		     				// spread =30 means adjust 1/30th to 30x
	    
		// tune_pot_a = 5 - tune1.GetAverageVoltage();
		// tune_pot_b = 5 - tune2.GetAverageVoltage(); 
		
	    if ((ctrl &1) == 1)
		{
			p_up[axis] = (pow (spread, (tune_pot_a / 2.5)) / spread ) / 10;     //  pot = 0 to 1
			d_up[axis] = (pow (spread, (tune_pot_b / 2.5)) / spread );
		}
		
	    if ((ctrl &1) == 1) 
		{
			p_dn[axis] = (pow(spread, (tune_pot_a * 2.5)) / spread );
			d_dn[axis] = (pow(spread, (tune_pot_b * 2.5)) / spread );
		}
		
	    tune_p = p_up[axis];
	    tune_d = d_up[axis];

	}

	void setup_drives(void)
	{
		for (UINT8 axis = 0; axis < na; axis++)
			set_position(axis, 10, 0, 0 ,0);
		
		drives_enabled = true; // %%	
	}
	
	void init_homes()
	{
		for (int i = 0; i < na; i++) // !!
			homing_state[i] = start;
	}
	
	void home_all(void)
	{
		if (homing_state[pivot] != homed)
			set_position(gripper, 10, 0.3, -0.3);

		home(pivot);
		
		if (homing_state[pivot] == homed)
			home(gripper);
		
		if (homing_state[gripper] == homed)
			home(elevator);
		
		// !!
		if (homing_state[elevator] == homed)
			home(mini);
	}
	
	void home(UINT8 axis)
	{
		switch(homing_state[axis])
		{
			case homed:
				return;
			break;
			case start:
				set_position(axis, park_position[axis], 0.3, -0.3);
				homing_state[axis] = moving_to_park_dly;
				dly_tmr = 1;
			break;
			case moving_to_park_dly:
				if (delay_passed())
					homing_state[axis] = moving_to_park;
			break;
			case moving_to_park:
				if (at_position(axis))
					homing_state[axis] = parked;
				if (stalled(axis))
					homing_state[axis] = parked;
			break;
			case parked:
				if (axis != elevator)
					set_position(axis, -20, 0.3, -0.3); // drive to mechanical stop
				else
					set_position(axis, -20, 0.3, -0.3, 8); // drive to mechanical stop (limited)
				
				dly_tmr = 0.8;
				homing_state[axis] = moving_to_stops_dly;
			break;
			case moving_to_stops_dly:
				if (delay_passed())
					homing_state[axis] = moving_to_stops;
			break;
			case moving_to_stops:
				if (stalled(axis), 0.01)
					homing_state[axis] = at_home;
			break;
			case at_home:
				pot_offset[axis] = pot_in[axis];
				set_position(axis, park_position[axis], 0.3, -0.3);
				homing_state[axis] = homed_parking;
			break;
			case homed_parking:
				if (at_position(axis))
					homing_state[axis] = homed;
			break;
		}
	}
	
	// @ACCELEROMETER CALIBRATION ====================================================================================
	void calibrate_accelerometer(void)
	{
		for (int i = 0; i < num_accelerometer_samples; i++)
			accelerometer_cal += accelerometer.GetAcceleration();
			
		accelerometer_cal /= -1 * num_accelerometer_samples;
	}
	
	// @INIT =========================================================================================================
	
	// Reads values for offset, etc.
	void read_vals()
	{
		static float temp[na];
		
		ifstream infile (home_path);
		
		if (infile.is_open())
		{
			infile >> temp[pivot] 
			       >> temp[gripper] 
			       >> temp[elevator] 
			       >> temp[mini];
		}
		else
		{
			// Load default values (remember to update these every once in a while)
			pot_offset[pivot] = 0.240848;
			pot_offset[gripper] = 0.485163;
			pot_offset[elevator] = 0.0254781;
			pot_offset[mini] = 0.66;	
			// dsprint("READ ERROR", LCD, 3);
		}
		
		for (int axis = pivot; axis < na; axis++)
			pot_offset[axis] = temp[axis];
		
		infile.close();
	}
	
	void store_pot_offsets()
	{
		ofstream outfile (home_path);
		
		if (outfile.is_open())
		{
			outfile.clear();
			
			for (int axis = pivot; axis < na; axis++) // !!
				outfile << pot_offset[axis] << endl;
			
			outfile << endl;
		}
		else
		{
			// Do nothing
		}

		outfile.close();
	}
	
	void RobotInit(void)
	{
		// pid_tune_setup();
		// LCD = DriverStationLCD::GetInstance();
		
		read_vals();
		load_tuning_parameters();
		populate();
		calibrate_accelerometer();
		setup_drives();
		
	}

	// @AUTONOMOUS ===================================================================================================
	
	void AutonomousInit(void)
	{
		GetWatchdog().SetEnabled(false);
		
		match_period = autonomous;
		
		match_time.Reset();
		match_time.Start();
	
		// Read the digital switches
		
		two_tubes = (auto_two_tube_switch.Get() == 1);
		auto_split = (auto_split_switch.Get() == 1);
		auto_dir = (auto_direction_switch.Get() == 1) ? dir_left : dir_right;
		
		auto_drive_speed = auto_split ? 0.3 : 0.4;
		
		set_position(gripper, gripper_open_val, 0.2, -0.2);
		set_position(pivot, park_position[pivot], 0.4, -0.4);
		set_position(mini, park_position[mini], 0.3, -0.3);
		
		if (two_tubes)
			init_homes();
	}
	
	void AutonomousPeriodic(void)
	{
		pid();
	}

    void AutonomousContinuous(void)
    {
    	if (two_tubes)
    	{
    		home_all();
    	}
    	else
    	{
			if (auto_split)
				auto_split_machine();
			else
				auto_straight_machine();
    	}
    	// print_diagnostics();
    	
    	taskDelay(1);
	}
	
    void auto_straight_machine()
    {	
    	switch (auto_straight_state)
    	{
	    	case str_command_elevator:
	    		set_position(elevator, rack_locations_pot[auto_split ? 5 : 6], 0.7, -0.6);
	    		dly_tmr = 1.6;
	    		auto_straight_state = str_drive_forward;
	    	break;
	    	case str_drive_forward:
	    		if (! hit_line_end())
	    			 auto_drive_with_sensors(auto_split ? auto_drive_speed : 0.4);
	    		
	    		if (delay_passed())
	    			auto_straight_state = str_slow_down;
	    	break;
	    	case str_slow_down:
	    		if (! hit_line_end())
	    			 auto_drive_with_sensors(auto_drive_speed);
	    		else
	    		{
	    			dly_tmr = 0.2;
	    			auto_straight_state = str_halt_at_line;
	    		}
	    	break;
	    	case str_halt_at_line:
	    		drive_bot((auto_drive_speed - 0.1) * -1);
	    		
	    		if (delay_passed())
	    			auto_straight_state = str_command_pivot;
	    	break;
	    	case str_command_pivot:
	    		set_position(pivot, pivot_score_val, 0.3, -0.3);
	    		dly_tmr = 0.2;
	    		
	    		auto_straight_state = str_pivot_down_delay;
	    	break;
	    	case str_pivot_down_delay:
	    		if (delay_passed())
	    			auto_straight_state = str_retract_pivot;
	    	break;
	    	case str_retract_pivot:
	    		if (at_position(pivot, 2))
	    		{
	    			set_position(gripper, park_position[gripper], 0.6, -0.6);
	    			set_position(pivot, park_position[pivot], 0.3, -0.3);
	    			dly_tmr = 1;
	    			auto_straight_state = str_gripper_closing;
	    		}
	    	break;
	    	case str_gripper_closing:
	    		if (delay_passed())
	    		{
		    		dly_tmr = 2.0;
		    		auto_straight_state = str_back_up;
	    		}
	    	break;
	    	case str_back_up:
	    		drive_bot((auto_drive_speed) * -1);
	    		
	    		if (delay_passed())
	    			auto_straight_state = str_park_pivot;
	    	break;
	    	case str_park_pivot:
	    		if (at_position(gripper, 5))
	    		{
	    			set_position(pivot, park_position[pivot], 0.4, -0.4);
	    			auto_straight_state = str_park_elevator;
	    		}
	    	break;
	    	case str_park_elevator:
	    		if (at_position(pivot, 2))
	    		{
	    			set_position(elevator, park_position[elevator], 0.5, -0.4);
	    			dly_tmr = 2;
	    			// auto_straight_state = str_spin_on_tmr;
	    		}
	    	break;
	    	case str_spin_on_tmr:
	    		drive_bot(0, auto_turn_speed - 0.3);
	    		
	    		if (delay_passed())
	    		{
	    			auto_straight_state = str_find_line;
	    		}
	    	break;
	    	case str_find_line:
	    		drive_bot(0, auto_turn_speed);
	    		
	    		if ((photosensor_left.GetVoltage() <= midpoint_voltage) || 
	    			(photosensor_right.GetVoltage() <= midpoint_voltage))
	    		{	
	    			dly_tmr = 2;
	    			auto_straight_state = str_drive_to_center_field;
	    		}
	    	break;
	    	case str_drive_to_center_field:
	    		if (delay_passed())
	    			auto_straight_state = -1; // Exit state machine
	    		else
	    			auto_drive_with_sensors(auto_drive_speed);
	    	break;
    	}
    }
    
    void auto_split_machine()
    {
    	static float detection_voltage;
    	
    	switch (auto_split_state)
    	{
	    	case spl_drive_to_split:
	    		if (! at_split())
	    			 auto_drive_with_sensors(auto_drive_speed);
	    		else
	    		{
	    			dly_tmr = 0.25;
	    			auto_split_state = spl_drive_past_split;
	    		}
	    	break;
	    	case spl_drive_past_split:
	    		drive_bot(0.2);
	    		
	    		if (delay_passed())
	    		{
		    		dly_tmr = (auto_dir == dir_left) ? 0.1 : 0.2; // 0.1 for left
		    		auto_split_state = spl_turn_on_timer;
	    		}
	    	case spl_turn_on_timer:
	    		drive_bot(0, auto_turn_speed * auto_dir);
	    		
	    		if (delay_passed())
	    		{
	    			auto_drive_speed = 0.3;
	    			auto_split_state = spl_find_line;
	    		}
	    	break;
	    	case spl_find_line:
	    		drive_bot(0, auto_turn_speed * auto_dir);
	    		
	    		detection_voltage = (auto_dir == dir_left) ? photosensor_right.GetVoltage() : photosensor_left.GetVoltage();
	    		
	    		if (detection_voltage <= midpoint_voltage)
	    			auto_split_state = spl_execute_partial_straight_machine;
	    	break;
	    	case spl_execute_partial_straight_machine:
	    		auto_straight_machine();
	    		
	    		if (auto_straight_state > str_park_elevator)
	    		{
	    			dly_tmr = 4.5;
	    			auto_split_state = spl_back_up;
	    		}
	    	break;
	    	case spl_back_up:
	    		drive_bot(auto_drive_speed * -1);
	    		
	    		if (delay_passed())
	    			auto_split_state++;
	    	break;
    	}
    	
    }
    
	// @TELEOPERATED =================================================================================================

	void TeleopInit(void)
	{
		teleop_time.Reset();
		teleop_time.Start();
		
		GetWatchdog().SetEnabled(false);
		match_period = teleoperated;
		
		if (stick_right.GetZ() >= 0)
			set_position(mini, park_position[mini], 0.4, -0.4);
	}
	
	void TeleopPeriodic(void)
	{
		pid();
		// tune_jog();	
	}

	// @MAIN =========================================================================================================
	
	void TeleopContinuous(void)
	{
		GetWatchdog().Feed();
		
		// setup_drives();
		// tune(mini, 30);
		
		// print_diagnostics();
		teleop_home_routine();
		
		base_methods();
		arm_methods();

		Wait(0.005); // wait for a motor update time
		taskDelay(1); // free up the processor for PID
	}
		
	bool robot_homed()
	{
		return homing_state[mini] == homed; // !!!
	}
	
	void base_methods()
	{
		joystick_drive(stick_right);
		
		if (robot_homed())
			drag_tube();
	}
	
	// Methods for arm operator
	void arm_methods()
	{
		if (robot_homed())
		{
			elevator_state_machine();
			pickup_state_machine();
			score_tube();
			park_all_axes();
			deploy_minibot();
		}
	}
	
	void park_all_axes()
	{
		if (button_pressed(stick_right, button_11))
		{
			set_position(pivot, park_position[pivot], 0.3, -0.3);
			set_position(elevator, park_position[elevator], 0.3, -0.3);
			set_position(gripper, park_position[gripper], 0.3, -0.3);
		}
	}
	
	void teleop_home_routine()
	{
		static INT8 homeflag, write_flag; // Prevents multiple storing of pot offsets
		
		if (button_pressed(stick_right, button_8) && button_pressed(stick_right, button_9))
		{
			init_homes();
			homeflag = 1;
		}
		
		if (homeflag == 1)
			home_all();
		
		if (write_flag != 1 && robot_homed() && homeflag == 1) // !!
		{
			store_pot_offsets();
			write_flag = 1;
		}
	}
	
	void print_diagnostics()
	{
		// Pot offsets
		
		// dsprint("poscmd", pos_cmd[pivot], LCD, 1);
		
		/*
		dsprint("pivot o", pot_offset[pivot], LCD, 1);
		dsprint("grip o", pot_offset[gripper], LCD, 2);
		dsprint("elevator o", pot_offset[elevator], LCD, 3);
		dsprint("mini o", pot_offset[mini], LCD, 4);
		*/
		
		// dsprint("accel", accelerometer.GetAcceleration(), LCD, 4);
		// dsprint("dist sensor", distance_sensor.GetVoltage(), LCD, 5);
		
		// Digital Inputs
		// dsprint("switch1", (int) auto_two_tube_switch.Get(), LCD, 3);
		// dsprint("switch2", (int) auto_split_switch.Get(), LCD, 4);
		
		// Pot positions
		
		/*
		dsprint("grip pos", pos_pot[gripper], LCD, 1);
		dsprint("pivot pos", pos_pot[pivot], LCD, 2);
		dsprint("elev pos", pos_pot[elevator], LCD, 3);
		dsprint("mini pos", pos_pot[mini], LCD, 4);
		*/

		// Encoder stuff
		
		/*
		dsprint("pos cmd gr", pos_cmd[gripper], LCD, 1);
		dsprint("pos cmd pv", pos_cmd[pivot], LCD, 2);
		dsprint("pos cmd el", pos_cmd[elevator], LCD, 3);
		dsprint("pos cmd mn", pos_cmd[mini], LCD, 4);
		*/
		
		// dsprint("tune1", tune1.GetVoltage(), LCD, 1);
		// dsprint("mini pot", minibot_pot.GetVoltage(), LCD, 2);
		// dsprint("tune_p", tune_p, LCD, 4);
		
		// dsprint("z axis", stick_right.GetZ(), LCD, 6);
		
		
		// dsprint("pos pot pv", pos_pot[pivot], LCD, 6);
		
		// Pivot tests
		/*
		dsprint("error[pivot]", pos_pot[gripper], LCD, 1);
		dsprint("pivot pos", pos_pot[pivot], LCD, 2);
		dsprint("auto state", auto_state, LCD, 3);
		*/
		
		// Line sensors
		// dsprint("Left Eye", photosensor_left.GetVoltage(), LCD, 1);
		// dsprint("Right Eye", photosensor_right.GetVoltage(), LCD, 2);
		// dsprint("Combined", photosensor_right.GetVoltage() + photosensor_left.GetVoltage(), LCD, 3);
		// dsprint("Diff. L - R", photosensor_left.GetVoltage() - photosensor_right.GetVoltage(), LCD, 4);

		// dsprint("G. Stalled", (int) stalled(gripper, 0.1), LCD, 1);
		// dsprint("pick. state", pickup_state, LCD, 2);
		// dsprint("S rate", stopped_rate[gripper], LCD, 3);
		
		// States
		// dsprint("A. State", auto_straight_state, LCD, 5);
		
		// dsprint(CURRENT_VERSION, LCD, 6);
	}
	
	// @DISABLED FUNCTIONS ===========================================================================================
	
	void DisabledInit(void)
	{
	}
	
	void DisabledPeriodic(void)
	{
	}

	void DisabledContinuous(void)
	{
	}
	
	// @VARIABLE POPULATION ==========================================================================================
	
	void populate()
	{
		rack_locations_pot[0] = park_position[elevator];
		rack_locations_pot[1] = 7;
		rack_locations_pot[2] = 13;
		rack_locations_pot[3] = 42;
		rack_locations_pot[4] = 49;
		rack_locations_pot[5] = 79;
		rack_locations_pot[6] = 84.5;
	}
	
	// @JOYSTICK FUNCTIONS ==========================================================================================
		
	bool button_pressed(Joystick& stick, int button)
	{
		return stick.GetRawButton(button);
	}
	
	// Returns an integer value representing
	// a button on the specified stick
	int get_button(Joystick& stick)
	{
		for (int i = 0; i <= 12; i++)
			if (stick.GetRawButton(i))
				return i; // button
		
		return -1;
	}
	
	// Returns a potentiometer value (for the elevator)
	// depending on what button is pressed
	float get_target_from_button(int button)
	{
		switch (button)
		{
			case button_3:
				return rack_locations_pot[0];
			break;
			case button_7:
				return rack_locations_pot[6];
			break;
			case button_8:
				return rack_locations_pot[5];
			break;
			case button_9:
				return rack_locations_pot[4];
			break;
			case button_10:
				return rack_locations_pot[3];
			break;
			case button_11:
				return rack_locations_pot[2];
			break;
			case button_12:
				return rack_locations_pot[1];
			break;
			default:
				return -1;
			break;
		}
	}
	
	/* Drives the robot based on programmed values
	 * ex. drive_bot() stops the robot;
	 *     drive_bot(1.0) drives the robot straight forward at full speed;
	 * 	   drive_bot(0, 0.5) turns the robot right at half speed.
	 */
	void drive_bot(float vel = 0, float turn = 0)
	{
		float velocity = vel;
		// Accelerometer ("Gyro") code
		cal_acceleration = accelerometer.GetAcceleration() + accelerometer_cal;
		velocity *= -1;
		
		myRobot.ArcadeDrive(velocity, turn - cal_acceleration, false);
	}
	
	// Drives the robot based on the specified stick
	void joystick_drive(Joystick& drivestick)
	{
		int input_power = 3;
		
		// Accelerometer ("Gyro") code
		cal_acceleration = accelerometer.GetAcceleration() + accelerometer_cal;
		turn_adjust_value = 1.0;
		
		joy_velocity = pow (drivestick.GetY(), input_power);
		if (input_power % 2 == 0 && drivestick.GetY() < 0) 
			joy_velocity *= -1;
		
		joy_turn = pow (drivestick.GetX(), input_power);
		if (input_power % 2 == 0 && drivestick.GetX() < 0) 
			joy_turn *= -1;
		
		turn_adjust_value = (fabs ((3.0 * pow((1 - fabs(joy_velocity)), 5) + 0.5)));
		
		myRobot.ArcadeDrive(joy_velocity, (joy_turn * turn_adjust_value) - cal_acceleration, false);
	}
	
	// Applies a cubic curve to the joystick input value.
	float convert_to_cubic(float input)
	{
		return pow (input, 3);
	}
	
	// @RESET ALL
	void reset_all(void)
	{
		// !!
	}
	
	// @ELEVATOR FUNCTIONS ===========================================================================================
	
	// Determines whether the elevator is ready to move
	bool elevator_can_move(void)
	{
		return (get_button(stick_appendage) != -1 && pickup_state == pickup_parked);
	}
	
	/** 
	 * State machine for the elevator.
	 * The reason this is a state machine is that we want to 
	 * be able to check whether the elevator is moving or not.
	 */
	void elevator_state_machine(void)
	{
		if (get_button(stick_appendage) != -1)
		{
			if (get_target_from_button(get_button(stick_appendage)) != -1)
			{	
				set_position(elevator, get_target_from_button(get_button(stick_appendage)), 1, -1);
				
				// All right, here's how this works. If the gripper is slightly open from the score tube function
				// and you told the elevator to go to position 0 (floor), then close the gripper.
				if ((float_equality(get_target_from_button(get_button(stick_appendage)), rack_locations_pot[0], 0.1))
					&& (float_equality(pos_cmd[gripper], gripper_slightly_open, 0.1))) 
					set_position(gripper, park_position[gripper], 0.3, -0.3);
			}
		}
	}
	
	// State machine for picking up a tube
	void pickup_state_machine(bool auto_execute = false)
	{
		switch(pickup_state)
		{
			case pickup_parked:
				if (float_equality(pos_pot[elevator], park_position[elevator], 6))
					if (button_pressed(stick_appendage, button_4))
						pickup_state = pickup_start;
			break;
			case pickup_start:
				set_position(gripper, park_position[gripper], 1, -1); // close gripper
				set_position(pivot, pivot_floor_val, 0.3, -0.3); // @@@ Change to 0.4 for real bot
				pickup_state = pickup_to_floor_dly;
				dly_tmr = 0.2; // 0.2
			break;
			case pickup_to_floor_dly:
				if (delay_passed())
					pickup_state = pickup_to_floor;
			break;
			case pickup_to_floor:
				if (at_position (pivot, 5.5))
				{
					if (at_position(pivot, 3.5))
					{
						set_position(gripper, gripper_open_val, 1, -1);
						dly_tmr = 0.2; // 0.2
						pickup_state = pickup_grab_dly;
					}
				}
				else
				{
					if (stalled(pivot, 2))
						pickup_state = pickup_failed;
				}
			break;
			case pickup_grab_dly:
				if (delay_passed())
					pickup_state = pickup_test_grab;
			break;
			case pickup_test_grab:
				if (at_position(gripper, 2))
					pickup_state = pickup_failed;
				else
				{
					if (stalled(gripper, 2))
						pickup_state = pickup_got_tube;
				}
			break;
			case pickup_failed:
				set_position(gripper, park_position[gripper], 0.8, -0.8);
				set_position(pivot, park_position[pivot], 0.8, -0.8); // @@@ set to 0.8 for real bot
				pickup_state = pickup_parked;
			break;
			case pickup_got_tube:
				set_position(pivot, park_position[pivot], 0.8, -0.8); // @@@ set to 0.8 for real bot
				dly_tmr = 0.2;
				pickup_state = pickup_got_tube_dly;
			break;
			case pickup_got_tube_dly:
				if (delay_passed())
					pickup_state = pickup_pivoting_up;
			break;
			case pickup_pivoting_up:
				if (at_position(pivot, 3))
				{
					if (at_position(gripper, 1))
						pickup_state = pickup_failed;
					else
						if (stalled(gripper))
						{
							set_position(gripper, gripper_open_val, 0.28, -0.28);
							pickup_state = pickup_parked;
						}
				}
			break;
		}
	}
	
	// State machine for the dragging tube
	void drag_tube(void)
	{
		switch (drag_state)
		{
			case 0: // Wait for button input
				if (button_pressed(stick_right, button_2))
					drag_state++;
			break;
			case 1: // Initiate pivoting down
				set_position(gripper, park_position[gripper]); // close gripper
				set_position(pivot, pivot_floor_val, 0.3, -0.3); //@@@ set to 0.4 on real bot
				dly_tmr = 0.2;
				drag_state++;
			break;
			case 2: // Delay
				if (delay_passed())
					drag_state++;
			break;
			case 3: // Attempting to go down
				if (at_position (pivot, 4))
					drag_state++;
				else
				{
					if (stalled(pivot, 4))
						drag_state = 100; // Failure
				}
			break;
			case 4: // At the floor
				if (! button_pressed(stick_right, button_2))
				{
					set_position(pivot, park_position[pivot], 0.4, -0.4);
					drag_state = 0;
				}
			break;
			case 100: // Failure; Go back up
				set_position(pivot, park_position[pivot], 0.7, -0.7); // @@@ set to 0.7 for real bot
				drag_state = 0;
			break;
		}
	}
	
	// State machine for the pivot scoring
	void score_tube(void)
	{
		static bool button, old_button;
		button = button_pressed(stick_appendage, button_2);
		
		if (button != old_button)
		{
			if (button)
			{
				if (float_equality(pos_cmd[elevator], rack_locations_pot[5], 0.1))
				{
					// One of the side columns, High row
					set_position(pivot, pivot_score_val + 4, 0.4, -0.4);
				}
				else
				{
					// Everything else
					set_position(pivot, pivot_score_val, 0.4, -0.4);
				}
			}
			else
			{	
				set_position(pivot, park_position[pivot], 0.4, -0.4);
			}
		}
		
		old_button = button;
		
		if (button_pressed(stick_appendage, button_trigger))
			set_position(gripper, gripper_slightly_open, 0.8, -0.8);
	}
	
	// @AUTONOMOUS, LINE TRACKING FUNCTIONS
	
	// Drive straight adjusting for line sensor values
	void auto_drive_with_sensors(float velocity = 0.4)
	{
		auto_drive_vel = velocity * -1; // Reversed motors
		auto_dir_error = photosensor_left.GetVoltage() - photosensor_right.GetVoltage();
		
		// Accelerometer
		cal_acceleration = accelerometer.GetAcceleration() + accelerometer_cal;
		
		auto_dir_error -= cal_acceleration;
		auto_dir_error /= (! auto_split) ? (17 * velocity) : (17 * velocity);
		
		myRobot.ArcadeDrive(auto_drive_vel, auto_dir_error, false);
	}

	// Checks if the robot has reached the end of the tape for the line tracking system. 
	// (There is a horizontal stub which causes the light readings to suddenly spike)
	bool hit_line_end() // !!
	{
		return ((photosensor_left.GetVoltage() < midpoint_voltage) && 
				(photosensor_right.GetVoltage() < midpoint_voltage));
	}

	// Checks if the robot is at a split in the lines
	bool at_split()
	{
		return hit_line_end();
	}

	// @MINIBOT FUNCTIONS

	// Called continuously
	void deploy_minibot()
	{
		static bool launch_ready = false;
		
		if (deploy_ok())
		{
			launch_ready = (stick_right.GetZ() >= 0);
			
			if (launch_ready)
			{
				if (! minibot_commanded_to_launch)
					set_position(mini, mini_armed_val, 0.5, -0.5);
				
				if ( at_position(mini) && button_pressed(stick_right, button_6) )
				{
					minibot_commanded_to_launch = true;
					set_position(mini, mini_deploy_val, 1, -1);
				}
				
				if (at_position(mini) && 
				    button_pressed(stick_right, button_7) &&
				    teleop_time.Get() >= minibot_launch_time_value)
				{
					minibot_commanded_to_launch = true;
					set_position(mini, mini_deploy_val, 1, -1);
				}
			}
			else
				set_position(mini, park_position[mini], 0.4, -0.4);
		}
		else
			set_position(mini, park_position[mini], 0.4, -0.4);
	}
		
	// Makes sure we are on the last 30 seconds before we put down the minibot
	bool deploy_ok()
	{
		// if (match_time.HasPeriodPassed(90))
			return true;
		
		return false;
	}
	
};

START_ROBOT_CLASS(Knightmare2K11);
