#include "ifi_code.h"
#include <stdio.h>
#include "ifi_frc.h"
#include "ir.h"


char cmd_up,cmd_dn,cmd_l,cmd_r;

char Get_IR_Result(void){
    static char cmd_up_ticks=0,cmd_dn_ticks=0,cmd_l_ticks=0,cmd_r_ticks=0;
    static char cmd_up_flag=0,cmd_dn_flag=0,cmd_l_flag=0,cmd_r_flag=0;

    //Get UP command
    if(CMD_UP_IN){
        cmd_up_flag = 1;
        cmd_up_ticks = 0;
    }
    if(cmd_up_flag && !CMD_UP_IN){
        cmd_up_ticks++;
        if(cmd_up_ticks > 5){
            cmd_up_flag = 0;
        }
    }

    //Get dn command
    if(CMD_DN_IN){
        cmd_dn_flag = 1;
        cmd_dn_ticks = 0;
    }
    if(cmd_dn_flag && !CMD_DN_IN){
        cmd_dn_ticks++;
        if(cmd_dn_ticks > 5){
            cmd_dn_flag = 0;
        }
    }

    //Get L command
    if(CMD_L_IN){
        cmd_l_flag = 1;
        cmd_l_ticks = 0;
    }
    if(cmd_l_flag && !CMD_L_IN){
        cmd_l_ticks++;
        if(cmd_l_ticks > 5){
            cmd_l_flag = 0;
        }
    }

    //Get UP command
    if(CMD_R_IN){
        cmd_r_flag = 1;
        cmd_r_ticks = 0;
    }
    if(cmd_r_flag && !CMD_R_IN){
        cmd_r_ticks++;
        if(cmd_r_ticks > 5){
            cmd_r_flag = 0;
        }
    }

    if(cmd_up_flag) return IR_UP;
    else if(cmd_dn_flag) return IR_DN;
    else if(cmd_l_flag) return IR_L;
    else if(cmd_r_flag) return IR_R;
    else return 0;


//    printf("Up: %d | Down: %d | Left: %d | Right: %d \r\n",cmd_up_flag,cmd_dn_flag,cmd_l_flag,cmd_r_flag);


}
