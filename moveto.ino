/*
 * calculate delta between actual position and setpoint
 * if delta is big move high speed
 * then if delta is lower reduce speed
 * if delta is lower than 1 stop movement
 * treshold values are empiric values depending on observatory design
 */
void moveto(){
  char reply[20];
 //moveto();
  if (moveto_flag){
    if (abs(setpoint - newPosition) >= DPPV){
      (setpoint>newPosition)? sprintf(reply, VMAX_E):sprintf(reply, VMAX_W); //high speed
    } else {
      (setpoint>newPosition)? sprintf(reply, VMIN_E):sprintf(reply, VMIN_W); //low speed
    }
    if (abs(setpoint - newPosition) < DPSTOP){
      sprintf(reply, STOP); //stop movement
      moveto_flag=false;
      reached=true;
      parked = park;
      park=false;
    }
    //if (send_flag){
    SerialB.print(reply);
    while(SerialB.transmit());
    //send_flag=false;
    //}
  }
}
