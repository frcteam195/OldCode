#include <stdio.h>
#include "gyro.h"
#include "encoder.h"
#include "robot.h"
#include "ifi_code.h"
#include "ifi_frc.h"

int abs(int in){
    if(in < 0) return (in * -1);
    return in;
}

//void Button_Handler

Buttons controls;
unsigned char current_auto_mode=1;

unsigned char Get_Auto_Mode(void)
{
    return current_auto_mode;
}

int LimitChar(int in){
    if(in > 127) in = 127;
    else if(in < -127) in = -127;
    in += 127;
    return in;
}


void Auto_Selection_Handler()
{
    Pwm1_green=0;
 Pwm1_red =0;
 Pwm2_green =0;
 Pwm2_red =0;
 Relay1_red =0;
 Relay1_green =0;
 Relay2_red =0;
 Relay2_green =0;

 Switch1_LED =0;
 Switch2_LED  =0;
 Switch3_LED =0;

    if(controls.small_up==1)
        current_auto_mode=1;
    else if(controls.small_down==1)
        current_auto_mode=2;

    switch(current_auto_mode){
        case 1:
            Pwm1_green=1;
            break;
        case 2:
            Pwm2_green = 1;
        default: break;
    }
}

void Button_Handler(void)
{
    controls.top_row=controls.middle_row=controls.bottom_row=controls.start=0;
    controls.home=controls.floor=controls.human=controls.manual_control=0;
    controls.spoiler_mode=controls.small_up=controls.small_down=0;

    if(p3_sw_aux2) controls.start = 1;
    if(p3_sw_trig) controls.bottom_row = 1;
    if(p3_sw_top) controls.middle_row = 1;
    if(p3_sw_aux1) controls.top_row = 1;

    //x axis buttons
    if(p3_x < 4) controls.manual_control = 1;
    if(p3_x >= 169 && p3_x <= 172) controls.spoiler_mode = 1;
    if(p3_x >= 189 && p3_x <= 192){
         controls.spoiler_mode = 1;
         controls.manual_control = 1;
    }

    //y axis controls
    if(p3_y < 4) controls.floor = 1;
    if(p3_y >= 169 && p3_y <= 172) controls.human = 1;
    if(p3_y >= 189 && p3_y <= 192){
         controls.floor = 1;
         controls.human = 1;
    }

    //Wheel
    if(p3_wheel < 4) controls.small_up = 1;
    if(p3_wheel >= 169 && p3_wheel <= 172) controls.small_down = 1;

    if(p3_wheel >= 189 && p3_wheel <= 192){
         controls.small_down = 1;
         controls.small_up= 1;
    }
    if(p3_wheel >= 210 && p3_wheel <= 213) controls.home = 1;
    if(p3_wheel >= 223 && p3_wheel <= 228){
         controls.small_down = 1;
         controls.home= 1;
    }
    if(p3_wheel >= 228 && p3_wheel <= 232){
         controls.home = 1;
         controls.small_up= 1;
    }
        if(p3_wheel >= 188 && p3_wheel <= 193
        ){
         controls.small_down = 1;
         controls.small_up= 1;
         controls.home = 1;
    }

    //printf("Bottom: %d | Mid: %d | Top: %d \n\r",(int)controls.bottom_row,(int)controls.middle_row,(int)controls.top_row);
    //printf("Floor: %d | Hum: %d | Home: %d \n\r",(int)controls.floor,(int)controls.human,(int)controls.home);
    //printf("Spoliers: %d | manual:%d | up: %d | down: %d \n\r",(int)controls.spoiler_mode,(int)controls.manual_control,(int)controls.small_up,(int)controls.small_down);
}

void Calculate_Gyro_Bias(void)
{
	static unsigned int i = 0;
	static unsigned int j = 0;
	int temp_gyro_rate;
	long temp_gyro_angle;
	int temp_gyro_bias;
	static char done=0;

    if(done==0)
    {
        i++;
        j++; // this will rollover every ~1000 seconds

        if(j == 10)
        {
            printf("\rCalculating Gyro Bias...");
        }

        if(j == 60)
        {
            // start a gyro bias calculation
            Start_Gyro_Bias_Calc();
        }

        if(j == 300)
        {
            // terminate the gyro bias calculation
            Stop_Gyro_Bias_Calc();

            // reset the gyro heading angle
            Reset_Gyro_Angle();

            printf("Done\r");
        }


        if(i >= 30 && j >= 300)
        {
            temp_gyro_bias = Get_Gyro_Bias();
            temp_gyro_rate = Get_Gyro_Rate();
            temp_gyro_angle = Get_Gyro_Angle();
            printf(" Gyro Bias=%d\r\n", temp_gyro_bias);
            printf(" Gyro Rate=%d\r\n", temp_gyro_rate);
            printf("Gyro Angle=%d\r\n\r\n", (int)temp_gyro_angle);

            i = 0;
            done = 1;
        }
    }

}


void Compressor_Handler(void){
	COMPRESSOR_RELAY = !COMPRESSOR_SWITCH;
}


void Disable_Drive_Encoders(void)
{
#ifdef ENABLE_ENCODER_1
    Disable_Encoder_1();
#endif
#ifdef ENABLE_ENCODER_2
    Disable_Encoder_2();
#endif
}

#ifdef ENABLE_ENCODER_1
void Disable_Encoder_1(void)
{
    // disable interrupt 1
	INTCON3bits.INT2IE = 0;
}
#endif

#ifdef ENABLE_ENCODER_2
void Disable_Encoder_2(void)
{
    // disable interrupt 2
	INTCON3bits.INT3IE = 0;
}
#endif

#ifdef ENABLE_ENCODER_3_6
void Disable_Encoder_3_6(void)
{
    // disable interrupt 3-6
    INTCONbits.RBIE = 0;
}
#endif

