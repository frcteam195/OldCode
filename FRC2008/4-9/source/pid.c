#include <stdio.h>
#include "pid.h"


char GetPID(PID * pid, int set_point, int position)
{
  long pTerm, dTerm, iTerm, error, output;
  error = set_point - position;

  pTerm = (long)(pid->pGain * error)/PGAIN_D;   // calculate the proportional term

	// calculate the integral state with appropriate limiting
  pid->iState += error;

  if (pid->iState > pid->iMax)
	  pid->iState = pid->iMax;
  else if (pid->iState < pid->iMin)
	  pid->iState = pid->iMin;


  iTerm = (pid->iGain * pid->iState)/IGAIN_D;  // calculate the integral term

  dTerm = (pid->dGain * (error - pid->dState))/DGAIN_D;
  pid->dState = error;

  output= pTerm + dTerm + iTerm;

  if(output>127) output=127;
  else if(output < -127) output=-127;

//   printf("in pid: %d | error: %d | P: %d | I: %d | D: %d\r", (int)output, (int)error,(int)pTerm,(int)iTerm,(int)dTerm);


  return (int) output;
}


void InitPID(PID *pid,int p, int i, int d, int i_max)
{
    pid->pGain = p;
    pid->iGain = i;
    pid->dGain = d;
	pid->iMin=-i_max;
	pid->iMax=i_max;
}
