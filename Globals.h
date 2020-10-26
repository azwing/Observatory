// -----------------------------------------------------------------------------------
// Global variables 

#pragma once

// Command processing -------------------------------------------------------------------------------------------------------
#define BAUD 9600
#define MAXPOS  800
#define DPPV  40
#define DPSTOP  1
#define VMAX_E  "F1000\n"
#define VHALF_E "F800\n"
#define VMIN_E  "F320\n"
#define VMAX_W  "R1000\n"
#define VHALF_W "R800\n"
#define VMIN_W  "R320\n"
#define STOP  "F0\n"
#define HARDSTOP  "X\n"
#define INITV15 "G0\n"
#define ROOF_OPEN  true
#define ROOF_CLOSE false
#define ROOF_SPEED 30
#define ROOF_STOP 0


// serial speed
unsigned long baudRate[10] = {115200,56700,38400,28800,19200,14400,9600,4800,2400,1200};

// sound/buzzer
#ifdef DEFAULT_SOUND_ON
boolean soundEnabled = true;
#else
boolean soundEnabled = false;
#endif
volatile int buzzerDuration = 0;

long newPosition, oldPosition  = 800, setpoint=0, tmp, t_start, t_end;

int   pina;
bool  B_ME, B_MW, B_Open, B_Close, B_Manu, B_Auto;  //Button value
bool  P_ME, P_MW, P_Open, P_Close, P_Manu, P_Auto;  //Previous button value
bool  V_ME, V_MW, V_Open, V_Close, V_Manu, V_Auto;  //Debounced button value
long  T_ME, T_MW, T_Open, T_Close, T_Manu, T_Auto;  //Button debounce time

int   pinc, oldpinc;
bool  B_Sync, B_R_closed, B_R_opened, B_Index;      //limit switch Value
bool  P_Sync, P_R_closed, P_R_opened, P_Index;      //Previous limit switch value
bool  V_Sync, V_R_closed, V_R_opened, V_Index;      //Debounced limit switch value
long  T_Sync, T_R_closed, T_R_opened, T_Index;      //Limit switch debounced value

bool  cmd_Open, cmd_Close, cmd_ME, cmd_MW, dir;

bool rotate, flagindex, flagsync;
int rotation=0, vitesse=0, count=0;
char azimuth[80];

bool park=true, parked=false;

bool  moveto_flag=false, reached=false;

int started=0, gotospeed=0;
char gotodir[2];

char  testchar[20]="F1200\n";

float goalsetpoint, delta;
bool  calibration=false;
int calib=0;
