void roof(){

if (cmd_Open) {
  digitalWrite(Roof_Dir, ROOF_OPEN);
  } else 
  {
    digitalWrite(Roof_Dir, ROOF_CLOSE);
  }
if (cmd_Open | cmd_Close) {
  analogWrite(Roof_Pwm, ROOF_SPEED);
  } else 
  {
    analogWrite(Roof_Pwm, ROOF_STOP);
  }
if ((cmd_Open) & (!V_R_opened)){
  cmd_Open=false;
  analogWrite(Roof_Pwm, ROOF_STOP);
  }
if ((cmd_Close) & (!V_R_closed)){
  cmd_Close=false;
  analogWrite(Roof_Pwm, ROOF_STOP);
  }
}
