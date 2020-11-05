// -----------------------------------------------------------------------------------
// Functions for initializing pins, variables, and timers on startup

#define DEBUG_AXIS_MODES_OFF

void initStartupValues() {
  }

void initPins() {
  // initialize the pushbutton pins as input:
  pinMode(Rot_CW, INPUT_PULLUP);    //PA0
  pinMode(Rot_CCW, INPUT_PULLUP);   //PA1
  pinMode(Open_Roof, INPUT_PULLUP); //PA2
  pinMode(Close_Roof, INPUT_PULLUP);//PA3
  pinMode(Auto, INPUT_PULLUP);      //PA4
  pinMode(Manu, INPUT_PULLUP);      //PA5
  pinMode(Spare28,INPUT_PULLUP);    //PA6
  pinMode(Spare29,INPUT_PULLUP);    //PA7
  
  //pinMode(Spare0, INPUT_PULLUP);    //PE0 RX0
  //pinMode(Spare1, INPUT_PULLUP);    //PE1 TX0
  
  //pinMode(Spare2, INPUT_PULLUP);    //PE4
  //pinMode(Spare3, INPUT_PULLUP);    //PE5

  // Sensors pins as inputs (All on Port C
  pinMode(Spare37, INPUT_PULLUP);     //PC0
  pinMode(Spare36, INPUT_PULLUP);     //PC1
  pinMode(Sync, INPUT_PULLUP);        //PC2
  pinMode(Roof_Closed, INPUT_PULLUP); //PC3
  pinMode(Roof_Opened, INPUT_PULLUP); //PC4
  pinMode(Index_Nord, INPUT_PULLUP);  //PC5
  pinMode(Spare31, INPUT_PULLUP);     //PC6
  pinMode(Spare30, INPUT_PULLUP);     //PC7

  
  
  // initialize outputs:
  pinMode(Roof_Dir, OUTPUT);
  pinMode(Roof_Pwm, OUTPUT);
  pinMode(Light, OUTPUT);
  pinMode(Siren, OUTPUT);
  pinMode(Spare0, OUTPUT);
  pinMode(Beep, OUTPUT);
  
  }
