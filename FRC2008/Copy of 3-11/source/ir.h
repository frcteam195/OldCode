#ifndef _IR_H
#define _IR_H

#define CMD_UP_IN       rc_dig_in09
#define CMD_R_IN          rc_dig_in10
#define CMD_DN_IN         rc_dig_in11
#define CMD_L_IN        rc_dig_in12

#define IR_UP           1
#define IR_DN           2
#define IR_L            3
#define IR_R            4

char Get_IR_Result(void);

#endif
