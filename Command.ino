// -----------------------------------------------------------------------------------
// Command processing

// last RA/Dec time
unsigned long _coord_t=0;

// help with commands
enum Command {COMMAND_NONE, COMMAND_SERIAL_A, COMMAND_SERIAL_B, COMMAND_SERIAL_C, COMMAND_SERIAL_ST4, COMMAND_SERIAL_X};
cb cmdA;  // the first Serial is always enabled
#ifdef HAL_SERIAL_B_ENABLED
cb cmdB;
#endif
#ifdef HAL_SERIAL_C_ENABLED
cb cmdC;
#endif

char _replyX[50]=""; cb cmdX;  // virtual command channel for internal use
char commande[20];


//============== /interface commands

// process commands
void processCommands() {

// Abort      abort.py      :A#     returns 0
// Disconnect disconnect.py :Q#     returns 0
// Connect    connect.py    :char(6)#     returns 0
// Close      close.py      :C#     returns 0
// Open       open.py       :O#     returns 0
// Goto       goto.py       :Gxxxx# returns 0
// Move CW    move_ccw.py   :ME#    returns 0
// Move CCW   move_cw.py    :MW#    returns 0
// Unpark     unpark.py     :P#     returns 0
// Parking    park.py       :U#     returns 0
// Status     status.py     :S#     returns a space separated string 0/1 Unparked/Parked 0/1 Slit Closed/Opene float current azimuth


    // command processing
    static char reply[200];
    static char command[3];
    static char parameter[25];
    static bool commandError = false;
    static bool quietReply   = false;

    bool supress_frame = false;
//    char *conv_end;

    // accumulate the command
    command[0]='A';
    command[1]=' ';
    
    if ((SerialA.available()>0) && (!cmdA.ready())) cmdA.add(SerialA.read());
#ifdef HAL_SERIAL_B_ENABLED
    if ((SerialB.available()>0) && (!cmdB.ready())) cmdB.add(SerialB.read());
#endif
#ifdef HAL_SERIAL_C_ENABLED
    if ((SerialC.available()>0) && (!cmdC.ready())) cmdC.add(SerialC.read());
#endif


    // send any reply
#ifdef HAL_SERIAL_TRANSMIT
    if (SerialA.transmit()) return;
  #ifdef HAL_SERIAL_B_ENABLED
    if (SerialB.transmit()) return;
  #endif
  #ifdef HAL_SERIAL_C_ENABLED
    if (SerialC.transmit()) return;
  #endif
#endif

    // if a command is ready, process it
    Command process_command = COMMAND_NONE;
    if (cmdA.ready()) { strcpy(command,cmdA.getCmd()); strcpy(parameter,cmdA.getParameter()); cmdA.flush(); SerialA.flush(); process_command=COMMAND_SERIAL_A; }
#ifdef HAL_SERIAL_B_ENABLED
    else if (cmdB.ready()) { strcpy(command,cmdB.getCmd()); strcpy(parameter,cmdB.getParameter()); cmdB.flush(); SerialB.flush();  process_command=COMMAND_SERIAL_B; }
#endif
#ifdef HAL_SERIAL_C_ENABLED
    else if (cmdC.ready()) { strcpy(command,cmdC.getCmd()); strcpy(parameter,cmdC.getParameter()); cmdC.flush(); SerialC.flush(); process_command=COMMAND_SERIAL_C; }
#endif
    else if (cmdX.ready()) { strcpy(command,cmdX.getCmd()); strcpy(parameter,cmdX.getParameter()); cmdX.flush(); process_command=COMMAND_SERIAL_X; }
    else return;

    if (process_command) {
// Command is two chars followed by an optional parameter...
      commandError=false;
// Handles empty and one char replies
      reply[0]=0; reply[1]=0;

  // Abort      abort.py      :A#
  if (command[0]=='A') {
    SerialB.print(STOP);  // stop immediately
    cmd_Open=false;
    cmd_Close=false;
    moveto_flag=false;
    rotation=STOPPED;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Disconnect disconnect.py :Q#
  if (command[0]=='Q') {
    SerialB.print(HARDSTOP);  // Hard Stop immediately
    cmd_Open=false;
    cmd_Close=false;
    moveto_flag=false;
    rotation=HALTED;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Connect    connect.py    :char(6)#
  if (command[0]==(char)6) {
    SerialB.print("G0\n");  //Initialize 18V15
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Close      close.py      :C#
  if (command[0]=='C') {
    cmd_Close=true;
    cmd_Open=false;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Open       open.py       :O#
  if (command[0]=='O') {
    cmd_Open=true;
    cmd_Close=false;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Goto       goto.py       :GTxxxx#
  if ((command[0]=='G') & (command[1]=='T') & !parked) {
    goalsetpoint=atof(parameter);
    if (goalsetpoint ==0) goalsetpoint +=360;
    setpoint=800*goalsetpoint/360;
    moveto_flag=true;
    reached=false;
    rotation=CW;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Move CW    move_ccw.py   :ME#
  // Move CCW   move_cw.py    :MW#
  if ((command[0]=='M') & !parked) {
    if (command[1]=='E'){
      SerialB.print(VMAX_E); // move full speed E
      rotation=CW;
      reached=false;
      quietReply=false;
    } else
    if (command[1]=='W'){
      SerialB.print(VMAX_W); //move full speed W
      rotation=CCW;
      reached=false;
      quietReply=false;
    }
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing

  // Unpark     unpark.py     :U#
  if (command[0]=='U') {
    parked=false;
    reached=false;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing
  
  // Parking    park.py       :P#
  if (command[0]=='P') {
    goalsetpoint=360;
    setpoint=800; //assume park is always at north
    moveto_flag=true;
    rotation=CW;
    park=true;
    reached=false;
    quietReply=false;
    sprintf(reply,"%d\n",quietReply);
  } else  // Resume Parsing
  
  // Status     status.py     :S#
  if (command[0]=='S') {
    static char status[20];
    static char trimmed[20];
    static float angle;
    int i=0, j=0;
    angle = (float)newPosition/800*360;
    if (reached) angle = goalsetpoint;  //if moveto ended and stopped make status = to setpoint avoiding accuracy issues
    dtostrf(angle, 6, 1, status);
    while(status[j] != 0){
      if (status[j] !=' ') trimmed[i++]=status[j];
      j++;
    }
    trimmed[i]=0;   
    sprintf(reply,"%d %d %s",parked, !V_R_opened, trimmed);
    quietReply=false;
  } else  // Resume Parsing

    // Status debug     :W#
  if (command[0]=='W') {
    static char status[20];
    static char trimmed[20];
    static float angle;
    int i=0, j=0;
    angle = (float)newPosition/800*360;
    if (reached) angle = goalsetpoint;  //if moveto ended and stopped make status = to setpoint avoiding accuracy issues
    dtostrf(angle, 6, 1, status);
    while(status[j] != 0){
      if (status[j] !=' ') trimmed[i++]=status[j];
      j++;
    }
    trimmed[i]=0;   
    sprintf(reply,"\n___\nAzimuth = %s\nEncoder = %ld\n",trimmed, newPosition);
    quietReply=false;
  } else  // Resume Parsing

  // Status debug     :Z#
  if (command[0]=='Z') {
    SerialB.print(VMAX_E);
    while(SerialB.transmit());
    calibration=true;
    reached=false;
    calib=0;
    quietReply=false;
  } else  // Resume Parsing

/************************
 * commandes 18V15 (debug)
 ************************/
if (command[0]=='D') {
        if (command[1]=='f') {
          myEnc.write(0);
            sprintf(commande, "F%s\n%c", parameter, 0);
            SerialB.print(commande);
            sprintf(reply,"ffff:parameter= %s commande= %s \n",parameter, commande);
            quietReply=false;
            rotation=CW;
        } else
        if (command[1]=='r') {
          myEnc.write(0);
            sprintf(commande, "R%s\n%c", parameter, 0);
            SerialB.print(commande);
            sprintf(reply,"ffff:parameter= %s commande= %s \n",parameter, commande);
            quietReply=false;
            rotation=CCW;
        } else
        if (command[1]=='F') {
            sprintf(reply,"%d",newPosition);
            SerialB.print(VMAX_E);
            quietReply=false;
            rotation=CW;
        } else
        if (command[1]=='R') {
            sprintf(reply, "Full Reverse");
            SerialB.print(VMAX_W);
            quietReply=false;
            rotation=CCW;
        } else
        if (command[1]=='S') {
            sprintf(reply, "Stopped");
            SerialB.print(STOP);
            quietReply=false;
            rotation=STOPPED;
        } else
        if (command[1]=='X') {
            sprintf(reply, "Hard Stop");
            SerialB.print(HARDSTOP);
            quietReply=false;
            rotation=HALTED;
        } else
        if (command[1]=='I') {
            sprintf(reply, "Sending G0");
            SerialB.print(INITV15);
            quietReply=false;
            rotation=STOPPED;
            myEnc.write(0);
        } else commandError=true;
      } else  // Resume Parsing

      if (!quietReply) {
        if (commandError) reply[0]='0'; else reply[0]='1';
        reply[1]=0;
        supress_frame=true;
      }

      if ((strlen(reply)>0)) {
        if (process_command==COMMAND_SERIAL_A) {
          SerialA.print(reply);
        } 
        while(SerialA.transmit());
      }
      quietReply=false;
   }    //process_command
}
