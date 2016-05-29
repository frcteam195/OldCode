#include "WPILib.h"
#include "Vision/AxisCamera.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 

/* NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES 
 * NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES 
 * NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES 
 * NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES NOTES */

// ALL INPUTS AND OUTPUTS VALUES ARE NUMBER THEY SAY ON BOARD 1 TO X 
	// NOT 0 TO X-1
	

/*
 * START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP 
 * START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP 
 * START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP START I/O MAP 
 */

		//pnumatic slot 8 out
	enum
	{
		kicker_front_lock = 1,
		kicker_front_unlock,
		

		
		omni_front_drop_up = 5,
		omni_front_drop_down,
		
		omni_rear_drop_up,
		omni_rear_drop_down
	};
	
	enum
	{
		analogue_slot_one = 1,
		analugue_slot_two,
		empty_slot_three,
		digitalsidecar_slot_four,
		empty_slot_five,
		empty_slot_six,
		solinoid_slot_seven,
		solinoid_slot_eight
		
	};

	//pwm electric out
	enum
	{
		front_right_drive = 1,
		rear_right_drive,
		front_left_drive,
		rear_left_drive,
	
		rear_roller_position,
		front_roller_position,
	
		winch_motor_position,
		winch_servo_position
	};

	//relay electronic out
	enum
	{
		left_tilting_motor = 1,
		right_tilting_motor,
		compressor_out,

	};

	//digital I/O
	enum
	{
		front_kicker_limit = 1,
		dio_empty_two,
	
		top_tilter_limit,
		bottom_tilter_limit,
	
		compressor_pressure,
		dio_empty_6,
		dio_empty_7,
		encoder_slot_a,
		encoder_slot_b,
		dio_empty_10,
		auto_switch_one,
		auto_switch_two,
		auto_switch_three,
		auto_mode
	};
	
/*
 * END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP
 * END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP
 * END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP END I/O MAP 
 */


/* 
 * START DRIVER STATION MAP START DRIVER STATION MAP START DRIVER STATION MAP 
 * START DRIVER STATION MAP START DRIVER STATION MAP START DRIVER STATION MAP 
 * START DRIVER STATION MAP START DRIVER STATION MAP START DRIVER STATION MAP 
 */	
	//joystick positions
	enum
	{
		left_stick_position = 1, 
		right_stick_position,
		apendage_stick_position,
		test_stick_position
	};
		//apendage joystick button positions
	enum
	{
		apendage_winch_shift = 1,
		apendage_empty_two,
		apendage_ratchet_latch,
		apendage_empty_four,
		apendage_empty_five,
		apendage_tilter_forward,
		apendage_tilter_reverse,
		apendage_empty_eight,
		apendage_empty_nine,
		apendage_empty_ten,
		apendage_empty_eleven
	};
		//left drive stick buttons
	enum
		{
			ldrive_rear_omni = 1,
			ldrive_front_omni,
				ldrive_empty_three,
				ldrive_empty_four,
				ldrive_empty_five,
				ldrive_empty_six,
			ldrive_front_kick,
			ldrive_empty_eight,
				ldrive_empty_nine,
				ldrive_empty_ten,
				ldrive_empty_eleven,
		};
	
	enum
	{
		kicker_state_idle = 0,
		
		kicker_state_front_fire = 1,
		kicker_state_front_lim_pause,
		kicker_state_front_time_pause,
		kicker_state_front_retract,
		kicker_state_front_lock,
		
		kicker_state_loosen,
		kicker_state_set_ready,
		
		kicker_state_rear_fire,
		kicker_state_rear_lim_pause,
		kicker_state_rear_time_pause,
		kicker_state_rear_retract,
		kicker_state_rear_lock
	};
	
	enum
	{
		tilter_state_idle = 0,
		tilter_state_forward,
		tilter_state_reverse,
	};
	
	enum
	{
		roller_state_idle = 0,
		roller_state_front,
	};

/*
 * END DRIVER STATION MAP END DRIVER STATION MAP END DRIVER STATION MAP 
 * END DRIVER STATION MAP END DRIVER STATION MAP END DRIVER STATION MAP 
 * END DRIVER STATION MAP END DRIVER STATION MAP END DRIVER STATION MAP 
 */	
	
	//what a limit switch returns when it is pressed or not
	enum
	{
		switch_active = 0,
		switch_inactive
	};

	//omni state machine states
	enum
	{
		omni_state_up = 0,
		omni_state_front_down,
		omni_state_rear_down,
	};
	
	enum
	{
		drive_tank = 0,
		drive_arcade,
	};
	
	int kicker_state = kicker_state_idle;
	
	bool kicker_active = false;
	bool kicker_front_working = false;
	bool kicker_rear_working = true;
	
	//smc change values on real robot.
	const float kick_retract_error_time = 2.0;
	const float kick_lock_wait_time = .1;
	const float kick_kicking_wait_time = 1.0;

	int roller_side_rolling = 0;
	float roller_speed = 0.0;
	
	int roller_state = 0;

	float winch_speed = 0.0;
	bool winch_active = false;
	bool ratchet_latched = false;
	

	int omni_state = 0;
	bool omni_active = false;

	int tilter_state = 0;
	bool tilter_active = false;	
	
	int sol_num_test = 0;
	bool sol_test_down = false;
	
	float drive_left = 0.0;
	float drive_right = 0.0;
	
	float drive_forward = 0.0;
	float drive_turn = 0.0;
	
	int drive_state = drive_tank;
	
	int auto_strategy_choice = 0;
	

class RobotDemo : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	
	Joystick leftstick; 		// arcade joystick/ left tank
	Joystick rightstick;		// right joystick
	Joystick apendagestick;		// used by secondary driver to 
	Joystick teststick;			//used for testing systems
	
	Compressor compressor;	
	
	DigitalInput tilter_top_lim;
	DigitalInput tilter_bottom_lim;
	DigitalInput kicker_front_lim;
	
	DigitalInput switch1;
	DigitalInput switch2;
	DigitalInput switch3;
	DigitalInput mode;

	
	Relay tilter_motor_left;
	Relay tilter_motor_right;
	
	Solenoid lock_front_kicker;
	Solenoid unlock_front_kicker;
	
	Solenoid up_front_omni;
	Solenoid down_front_omni;
	Solenoid up_rear_omni;
	Solenoid down_rear_omni;
		
	Timer timertest;
	Timer kicker_timer;
	
	Jaguar front_roller;
	Jaguar rear_roller;
	Jaguar winch_motor;

	
	Servo hanger_ratchet;
	
	Encoder auto_encoder;
	
/*
*MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS
*MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS
*MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS
*MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS MAIN CODE STARTS
*/
	public:
		RobotDemo(void):
			
			myRobot(front_left_drive , rear_left_drive,
					front_right_drive , rear_right_drive),
		
			leftstick(left_stick_position),
			rightstick(right_stick_position),
			apendagestick(apendage_stick_position),
			teststick(test_stick_position),
		
			compressor(compressor_pressure, compressor_out),
		
			tilter_top_lim(top_tilter_limit),
			tilter_bottom_lim(bottom_tilter_limit),
			kicker_front_lim(front_kicker_limit),
			
			switch1(auto_switch_one),
			switch2(auto_switch_two),
			switch3(auto_switch_three),
			mode(auto_mode),

		
			tilter_motor_left(left_tilting_motor),
			tilter_motor_right(right_tilting_motor),
		
			lock_front_kicker(kicker_front_lock),
			unlock_front_kicker(kicker_front_unlock),
			
			up_front_omni(omni_front_drop_up),
			down_front_omni(omni_front_drop_down),
			up_rear_omni(omni_rear_drop_up),
			down_rear_omni(omni_rear_drop_down),
		
			timertest(),
			kicker_timer(),
			
			front_roller(front_roller_position),
			rear_roller(rear_roller_position),
			winch_motor(winch_motor_position),
		
			//smc
			hanger_ratchet(8),
			auto_encoder(encoder_slot_a, encoder_slot_b, false, Encoder::k1X)
			
			//camera 480/ 360 0 compression, try if to slow
			//320 / 240
			{
				GetWatchdog().SetExpiration(0.1);
				AxisCamera & camera = AxisCamera::GetInstance();
			}
		
		void inputpannel(void)
		{
			kicker_state = set_active_kicker();
			
			tilter_state = get_tilter_direction();
			
			omni_state = set_active_omni();
			
			drive_state = set_drive_state();
			
			roller_speed = apendagestick.GetZ();
			
			roller_state = set_roller_state();
					
			drive_left = set_left_drive();
			drive_right = set_right_drive();
			
			drive_forward = set_forward_drive();
			drive_turn = set_turn_drive();			
		}
		
		float set_right_drive()
		{
			return rightstick.GetY();
		}
		
		float set_left_drive()
		{
			return leftstick.GetY();
		}
		
		float set_forward_drive()
		{
			return leftstick.GetY();
		}
		
		float set_turn_drive()
		{
			return  -1 * leftstick.GetX();
		}
		
		void drive_state_machine()
		{
			switch(drive_state)
			{
			case drive_tank:
			{
				tank_drive();
			}
			break;
			
			case drive_arcade:
			{
				arcade_drive();
			}
			break;
			}
		}
		
		void arcade_drive(void)
		{
			myRobot.ArcadeDrive(drive_forward, drive_turn, false);
			Wait(.05);
		}
		
		void tank_drive(void)
		{
			myRobot.TankDrive(drive_left, drive_right);
			Wait(.05);
		}
		
		int set_drive_state()
		{
			if(leftstick.GetZ() > 0)
			{
				return drive_arcade;
			}
			
			return drive_tank;
		}
			//drives robot forward 
			//to be used in autonomous mode
		
		//
		void auto_drive(float speed)
		{
			myRobot.Drive(speed, 0.0);
			Wait(.05);
		}
			//drives robot forward for a set amount of time during autonomous
			//only this function can run while it is running
		void auto_drive(float speed, int distance)
		{
			auto_encoder.Start();
			myRobot.Drive(speed, 0.0);
			
			while(auto_encoder.GetRaw() < distance && IsAutonomous())
			{
			}
			myRobot.Drive(0.0 , 0.0);
			Wait(.05);
			
			auto_encoder.Stop();
			auto_encoder.Reset();
		}
		
		void auto_drive(float speed, float time, float turn)
		{
			myRobot.Drive(speed, turn);
			Wait(time);
			
			myRobot.Drive(0.0, 0.0);
			Wait(.05);
		}
		
		void auto_kick(int to_kick)
		{
			if (to_kick == kicker_state_front_fire ||
				to_kick == kicker_state_rear_fire)
			{
				kicker_state = to_kick;
			}
			else
			{
				kicker_state = kicker_state_front_fire;
			}
			kicker_active = true;
			
			while(kicker_active && IsAutonomous())
			{
				kicker_state_machine();
			}
		}
		// 15.5 inches, 36 inches, 36 inches
		//Strategy Position 3
			void auto_POS3()
			{
					//start roller
				roller_auto(roller_state_front);
					//drive forward - find out exact units of measure for speed and time
				auto_drive(-.17, 744);
					//drive backward
				//auto_drive(.17, );
					//kick the ball
				auto_kick(kicker_state_front_fire);
				
					//drive forward - find out exact units of measure for speed and time
				auto_drive(-.17, 1440);
					//drive backward
				//auto_drive(-.17, 2.0);
					//kick the ball
				auto_kick(kicker_state_front_fire);

				//drive forward - find out exact units of measure for speed and time
				auto_drive(-.17, 1440);
					//drive backward
				//auto_drive(-.17, 2.0);
					//kick the ball
				auto_kick(kicker_state_front_fire);
			}
			//End strategy Position 3
			// x inches, 36 inches 
			//Strategy Position 2
				void auto_POS2()
				{
						//Roller on
					roller_auto(roller_state_front);
						//Drive forward
					auto_drive(-.17, 1440);
						//Kick
					auto_kick(kicker_state_front_fire);

						//Drive forward at specied speed for specified time(seconds)
					auto_drive(-.17, 1440);
						//Kick
					auto_kick(kicker_state_front_fire);
						//Back omni down
					omni_auto(omni_state_rear_down);

					//Turn robot
					//auto_drive(.1, 1.0, .25);
					//Back omni up
					//omni_auto(omni_state_rear_up);
					//Drive back
					//auto_drive(-speed, time);
				}
				//End strategy Position 2
				void auto_POS1()
				{
						//Roller on
					roller_auto(roller_state_front);
						//Drive forward
					auto_drive(-.17, 20);
						//Kick
					auto_kick(kicker_state_front_fire);

					//Front omni down
					//omni_auto(omni_state_front_down);
					//Turn robot
					//auto_drive(0, time, rotate);
					//Front omni up
					//omni_auto(omni_state_front_up);
					//Drive back
					//auto_drive(-speed, time);
				}
				
				void auto_default()
				{
					auto_drive(-.17,1000);
					auto_drive(0.0);
				}
				
		int getInput(void)
		{
			auto_strategy_choice = 0;
			if(switch1.Get() == switch_active)
			{
				return 1;
			}
			if (switch2.Get() == switch_active)
			{
				return 2;
			}
			if (switch3.Get() == switch_active)
			{
				return 3;
			}			
			return 0;
		}
		
		
		void roller_auto(int state)
		{
			if(state == roller_state_front)
			{
				roller_state = state;
			}
			else
			{
				roller_state = roller_state_idle;
			}
			
			roller_state_machine();
		}
		
		void omni_auto(int state)
		{
			if(state == omni_state_front_down ||
					state == omni_state_rear_down)
			{
				omni_state = state;
			}
			else
			{
				omni_state = omni_state_up;
			}
			
			omni_state_machine();
			
		}
	
	//kicker functions
	//KICKER KICKER KICKER KICKER
	//smc kicker
		void restart_kicker_timer()
		{
			kicker_timer.Stop();
			kicker_timer.Reset();
			kicker_timer.Start();			
		}
		
		void reset_kicker_timer()
		{
			kicker_timer.Stop();
			kicker_timer.Reset();
		}
		
		bool check_kicker_front_lim(void)
		{
			if(kicker_front_lim.Get() == switch_active)
			{
				return true;
			}
			
			return false;
		}
		
		int set_active_kicker(void)
		{
			
			if(!kicker_active && !winch_active)
			{
				if(leftstick.GetRawButton(ldrive_front_kick))
				{
					kicker_active = true;
					return kicker_state_front_fire;
				}
				else
				{
					return kicker_state_idle;
				}				
			}
			else
			{
				return kicker_state;
			}
		}
		
		void kicker_shoot_front(void)
		{
			lock_front_kicker.Set(false);
			unlock_front_kicker.Set(true);
		}
		
		void kicker_retract(void)
		{
			winch_motor.Set(1.0);
		}
		
		void kicker_lock(void)
		{
			unlock_front_kicker.Set(false);
			
			lock_front_kicker.Set(true);
		}
		
		void kicker_state_machine(void)
		{
			switch(kicker_state)
			{
				case kicker_state_idle:
				{
						kicker_active = false;
						compressor.Start();
						kicker_lock();
				}
				break;
				
				case kicker_state_front_fire:
				{
					kicker_shoot_front();
					compressor.Stop();
					kicker_state = kicker_state_front_lim_pause;
				}
				break;
				
				case kicker_state_front_lim_pause:
				{
					if(!check_kicker_front_lim())
					{
						kicker_timer.Start();
						kicker_state = kicker_state_front_time_pause;
					}
				}
				break;
				
				case kicker_state_front_time_pause:
				{
					if(kicker_timer.HasPeriodPassed(kick_kicking_wait_time))
					{
						kicker_state = kicker_state_front_retract;
						
						restart_kicker_timer();
					}
				}
				break;
				
				case kicker_state_front_retract:
				{
					kicker_retract();
					if(check_kicker_front_lim())
					{
						kicker_state = kicker_state_front_lock;
						
						restart_kicker_timer();
					}
					else if(kicker_timer.HasPeriodPassed(kick_retract_error_time))
					{
						//kicker_front_working = false;
						
						kicker_state = kicker_state_front_lock;
						restart_kicker_timer();
					}
				}
				break;
				
				case kicker_state_front_lock:
				{
					kicker_lock();
					if (kicker_timer.HasPeriodPassed(kick_lock_wait_time))
					{
						kicker_state = kicker_state_loosen;
						winch_motor.Set(0.0);
						restart_kicker_timer();
					}
				}
				break;
				
				case kicker_state_loosen:
				{
					winch_motor.Set(-0.5);
					if(kicker_timer.HasPeriodPassed(.75))
					{
						kicker_state = kicker_state_set_ready;
						
						reset_kicker_timer();
						compressor.Start();
					}
				}
				break;
				
				case kicker_state_set_ready:
				{
					kicker_state = kicker_state_idle;
					kicker_active = false;
					compressor.Start();
					winch_motor.Set(0.0);
				}
				break;
			}
		}
	//roller functions
	//ROLLER ROLLER ROLLER ROLLER ROLLER ROLLER
	//smc roller
			//sees if speed withindeadband of roller then sets the value of
			//the front and back roller as oppisite each other
		
		void roller_state_machine()
		{
			
			switch(roller_state)
			{
				case roller_state_idle:
				{
					kill_rollers();
				}
				break;
				
				case roller_state_front:
				{
					if(roller_speed > 0)
					{
						run_front_roller(-.3);
					}
					else
					{
						run_front_roller(.3);
					}
				}
				break;
			}
		}
		
		void run_front_roller(float speed)
		{
			front_roller.Set(speed);
		}
		
		void kill_rollers()
		{
			front_roller.Set(0.0);
		}
			//placed a deadband on the roller speed to be able to turn 
			//turn it off without setting value to exactly zero
		int set_roller_state()
		{   
			if(!kicker_active)
			{
				if(!kicker_active)
				{
					if (roller_speed > 0.9 || roller_speed < -0.9)
					{
						return roller_state_front;
					}
				}
			}
			
			return roller_state_idle;
		}
	//winch functions
	//WINCH WINCH WINCH WINCH WINCH WINCH
	//smc winch
		
	//omni functions
	//OMNI OMNI OMNI OMNI OMNI OMNI
	//smc omni
		void omni_drop_front()
		{
			up_front_omni.Set(false);
			down_front_omni.Set(true);
		}
		
		void omni_drop_rear()
		{
			up_rear_omni.Set(false);
			down_rear_omni.Set(true);
		}
		
		void pull_up_omni()
		{
			down_front_omni.Set(false);
			down_rear_omni.Set(false);
			
			up_front_omni.Set(true);
			up_rear_omni.Set(true);
		}
		
		int set_active_omni()
		{
			if(omni_active)
			{
				if(leftstick.GetRawButton(ldrive_front_omni)
						&& omni_state == omni_state_front_down)
				{
					return omni_state_front_down;
				}
				else if(leftstick.GetRawButton(ldrive_rear_omni)
						&& omni_state == omni_state_rear_down)
				{
					return omni_state_rear_down;
				}
				else
				{
					return omni_state_up;
				}
			}
			else
			{
				if(leftstick.GetRawButton(ldrive_front_omni))
				{
					return omni_state_front_down;
				}
				else if(leftstick.GetRawButton(ldrive_rear_omni))
				{
					return omni_state_rear_down;
				}
				else
				{
					return omni_state_up;
				}
			}
			return omni_state_up;
		}
		
		void omni_state_machine()
		{
			switch(omni_state)
			{
			case omni_state_up:
			{
				omni_active = false;
				pull_up_omni();
			}
			break;
			
			case omni_state_front_down:
			{
				omni_active = true;
				omni_drop_front();
			}
			break;
			
			case omni_state_rear_down:
			{
				omni_active = true;
				omni_drop_rear();
			}
			break;
			}
		}	
		
	//tilter functions
	//TILTER TILTER TILTER TILTER TILTER
	//smc tilter
		
			//sets direction of tilter motors depending on the 
			//joystick value. sets deadband so slight movement does
			// turn on tilter
		void set_tilter_forward(void)
		{
			tilter_motor_left.Set(Relay::kForward);
			tilter_motor_right.Set(Relay::kForward);
		}
		
		void set_tilter_reverse(void)
		{
			tilter_motor_left.Set(Relay::kReverse);
			tilter_motor_right.Set(Relay::kReverse);
		}
		
		void set_tilter_idle(void)
		{
			tilter_motor_left.Set(Relay::kOff);
			tilter_motor_right.Set(Relay::kOff);
		}
		
		//smc
		int get_tilter_direction()
		{
			if(tilter_active)
			{
				if (apendagestick.GetRawButton(apendage_tilter_forward) 
						&& tilter_state == tilter_state_forward)
				{
					return tilter_state_forward;
				}
				else if(apendagestick.GetRawButton (apendage_tilter_reverse) 
						&& tilter_state == tilter_state_reverse)
				{
					return tilter_state_reverse;
				}
			}
			else 
			{
				if (apendagestick.GetRawButton(apendage_tilter_forward))
				{
					return tilter_state_forward;
				}
				else if(apendagestick.GetRawButton(apendage_tilter_reverse))
				{
					return tilter_state_reverse;
				}
			}
			return tilter_state_idle;
		}
			
			//sees if any tilter limit switches are pressed
			// returns a diffrent value depending on which one
			//to be used later.
		bool top_tilter_lim()
		{
			if(tilter_top_lim.Get() == switch_active)
			{
				return true;
			}
			
			return false;
		}
		
		bool bottom_tilter_lim()
		{
			if(tilter_bottom_lim.Get() == switch_active)
			{
				return true;
			}
					
			return false;
		}
		
		void tilter_state_machine(void)
		{
			switch(tilter_state)
			{
				//idle
				case tilter_state_idle:
				{
					tilter_active = false;
					set_tilter_idle();
				}
				break;
				//moving up
				case tilter_state_forward:
				{
					tilter_active = true;
					if(top_tilter_lim())
					{
						tilter_state = tilter_state_idle;
					}
					else
					{
						set_tilter_forward();
					}
				}
				break;
				//moving down
				case tilter_state_reverse:
				{
					tilter_active = true;
					if (bottom_tilter_lim())
					{
						tilter_state = tilter_state_idle;
					}
					else
					{
						set_tilter_reverse();
					}
				}
				break;			
			}
		}
		
		void Autonomous(void)
		{
			
			GetWatchdog().SetEnabled(false);
			
			compressor.Start();
			//smc_auto
			return;
			GetWatchdog().SetEnabled(false);

					auto_strategy_choice = getInput();

					//Choose strategy
					switch(auto_strategy_choice)
					{
						//switch 1
						case 1:
						{
							auto_POS1();
						}
						break;
						//switch 2
						
						case 2:
						{
							auto_POS2();
						}
						break;
						//switch 3
						case 3:
						{
							auto_POS3();
						}
						break;
						//default setting
						default: 
						case 0:
						{
							auto_default();
						}
						break;
					}
		}

		void OperatorControl(void)
		{
			GetWatchdog().SetEnabled(true);
			compressor.Start();
			kicker_lock();
			
			while (IsOperatorControl())
			{
				GetWatchdog().Feed();
				
				inputpannel();
				
				//drive_state_machine();				
					arcade_drive();			
				roller_state_machine();
				
				kicker_state_machine();
				
				//winch_state_machine(winch_state);
				
				//latch_ratchet(ratchet_latched);
				
				tilter_state_machine();
				
				omni_state_machine();
			}
		}
};

START_ROBOT_CLASS(RobotDemo);
