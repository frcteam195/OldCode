#ifndef _LAUNCH_H
#define _LAUNCH_H

 void Launcher_State_Machine(void);
 void OpenBrake(void);
 void CloseBrake(void);
 void ToggleTilter(void);
void SetTilter(unsigned char in);

void Launcher_Handler(void);

#endif
