#ifndef _LIB_195
#define _LIB_195

//Robot wide Macros
#define COMPRESSOR_RELAY	relay4_fwd
#define COMPRESSOR_SWITCH	rc_dig_in18
#define TILT_RELAY_FWD      relay2_fwd
#define TILT_RELAY_REV      relay2_rev
#define LAUNCH_POT          4
#define LAUNCH_CURRENT      1
#define LEFT_CURRENT        3
#define RIGHT_CURRENT       2


#define LAUNCHER_PWM        pwm07=pwm08

typedef struct
{
    char top_row,
         middle_row,
         bottom_row,
         start,
         home,
         floor,
         human,
         manual_control,
         spoiler_mode,
         small_up,
         small_down;
} Buttons;

void Button_Handler(void);
void Calculate_Gyro_Bias(void);
void Disable_Drive_Encoders(void);
void Disable_Encoder_1(void);
void Disable_Encoder_2(void);
void Disable_Encoder_3_6(void);
void Auto_Selection_Handler();
int abs(int in);
unsigned char Get_Auto_Mode(void);
int LimitChar(int in);


#endif
