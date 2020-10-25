void startup(){
analogWrite(Roof_Pwm, 0);
cmd_Open =0;
cmd_Close=0;
SerialB.print("X\n\r");
while(SerialB.transmit());
started++;
}
