/*
 * Gestion d'Obervatoire
 * Interface avec Indi Script gateway
 * Serial Lib basé sur le code original du driver Onstep de Howard Dutton 
 */

// firmware info, these are returned by the ":GV?#" commands
#define FirmwareDate          __DATE__
#define FirmwareTime          __TIME__
#define FirmwareVersionMajor  1
#define FirmwareVersionMinor  2      // minor version 0 to 99
#define FirmwareVersionPatch  "a"     // for example major.minor patch: 1.3c
#define FirmwareVersionConfig 1       // internal, for tracking configuration file changes
#define FirmwareName          "Observatoire"
#define ENCODER_USE_INTERRUPTS

//#include <math.h>
#include <Encoder.h>
#include "config.h"
#include "src/HAL/HAL.h"
//#include "src/lib/FPoint.h"
#include "Globals.h"
//#include "src/lib/Sound.h"
#include "src/lib/Command.h"


// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

Encoder myEnc(Enc_CanalA, Enc_CanalB);

#define CW 1
#define STOPPED 0
#define CCW -1
#define HALTED -2

// ____       _               
/// ___|  ___| |_ _   _ _ __  
//\___ \ / _ \ __| | | | '_ \ 
// ___) |  __/ |_| |_| | |_) |
//|____/ \___|\__|\__,_| .__/ 
//                     |_|

void setup() {
    // take a half-second to let any connected devices come up before we start setting up pins
  delay(500);
  char tmp[50];
  
  // initialize the Non-Volatile Memory
  //nv.init();

  // set pins for input/output as specified in Config.h and PinMap.h
  initPins();

  // if this is the first startup set EEPROM to defaults
  //initWriteNvValues();
  
  // now read any saved values from EEPROM into varaibles to restore our last state
  //initReadNvValues();

  // start hardware timer, initialize motors, etc.
  // initialize Serial comm
  SerialA.begin(9600);
  sprintf(tmp, "AZConcept, %s %d:%d-%s %s %s \n",FirmwareName, FirmwareVersionMajor, FirmwareVersionMinor,FirmwareVersionPatch, FirmwareDate, FirmwareTime);
  SerialA.print(tmp);
  while(SerialA.transmit());

  SerialB.begin(9600);
  SerialB.print("GO\n\r");
  while(SerialB.transmit());
}

// _                      
//| |    ___   ___  _ __  
//| |   / _ \ / _ \| '_ \ 
//| |__| (_) | (_) | |_) |
//|_____\___/ \___/| .__/ 
//                 |_|

void loop() {
  char reply[40];
  char temp[40];

if (started<2) startup(); //avoid start due to non stabilized inputs

//******************** Time debug
/*
    t_start = micros();   
    sprintf(reply,"Time_Inputs = %ld\n\r", t_end);
    SerialA.print(reply);
    while(SerialA.transmit());
    t_end = micros() - t_start;
    
*/
//====================

//   _____                     _           
//  | ____|_ __   ___ ___   __| | ___ _ __ 
//  |  _| | '_ \ / __/ _ \ / _` |/ _ \ '__|
//  | |___| | | | (_| (_) | (_| |  __/ |   
//  |_____|_| |_|\___\___/ \__,_|\___|_|
  
  newPosition = myEnc.read();
/*  if (newPosition != (oldPosition)) {
    oldPosition = newPosition;
  }
*/
//============================== check moveto

  moveto();

//============================== end check moveto
    if (!V_Auto){
      processCommands();
    }
    
    inputs();

    roof();
//=============================== Reset position when reaching Index
    if ((V_Index==LOW)& !flagindex){
      //sprintf(reply, "Position = %ld\n", newPosition);
      //SerialA.print(reply);
      //while(SerialA.transmit());
      flagindex=true;
      if (rotation == CW){
        myEnc.write(1);
        newPosition=1;
      }
    } else if (V_Index==HIGH) flagindex=false;
    if ((V_Sync==HIGH)& !flagsync){
      flagsync=true;
    } else if (V_Sync==LOW) flagsync = false;
// __  __                   
//|  \/  | __ _ _ __  _   _ 
//| |\/| |/ _` | '_ \| | | |
//| |  | | (_| | | | | |_| |
//|_|  |_|\__,_|_| |_|\__,_|

    if (!V_Manu)
    {
      reached=false;
    if (!V_Open){
      cmd_Open=true;
      }
    if (!V_Close){
      cmd_Close=true;
      }
    if((V_Open & V_Close)){
      cmd_Open=false;
      cmd_Close=false;
    }
    
    if ((V_MW==LOW) & !rotate) {
      rotate = true;
      rotation=CW;
      SerialB.print(VHALF_E);
      while(SerialB.transmit());
    } else
    if ((V_ME==LOW) & !rotate) {
      rotate = true;
      rotation=CCW;
      SerialB.print(VHALF_W);
      while(SerialB.transmit());
    } else
    if ((V_MW == HIGH) & (V_ME == HIGH)){
      rotate = false;
      rotation=STOPPED;
      SerialB.print(STOP);
      while(SerialB.transmit());
    }
    } //end manu
}
