#ifndef _PID_H
#define _PID_H

#define PGAIN_D	1000
#define IGAIN_D	1000
#define DGAIN_D	1000


typedef struct{
  int dState;      	// Last position input
  int iState;      	// Integrator state
  int iMax, iMin;  	// Maximum and minimum allowable integrator state

  int	iGain,    	// integral gain
        pGain,    	// proportional gain
        dGain;     	// derivative gain

  unsigned char mode1; //0 for position, 1 for

} PID;

typedef struct
{
	int pGain,
		iGain,
		dGain,
		iMin,
		iMax;
}PIDGains;



char GetPID(PID * pid, int set_point, int position);
void InitPID(PID *pid,int p, int i, int d,int i_max);

#endif
