/****************************************************
* All inputs are on port A and port C
* So we try to get ann these via port read
*****************************************************/

void inputs()
{
  //************* Get all inputs on port A
  pina = PINA;
  B_ME =    pina & B00000001;
  B_MW =    pina & B00000010;
  B_Open =  pina & B00000100;
  B_Close = pina & B00001000;
  B_Manu =  pina & B00010000;
  B_Auto =  pina & B00100000;
//B_???? =  pina & B01000000;
//B_???? =  pina & B10000000;

  if (B_ME!= P_ME)  T_ME=millis();      //if change get timer
  if (millis()-T_ME > 1)  V_ME = B_ME;  //if time without change > debounce time set debounced value
  P_ME = B_ME;  //set oldvalue
  
  if (B_MW!= P_MW)  T_MW=millis();      //if change get timer
  if (millis()-T_MW > 1)  V_MW = B_MW;  //if time without change > debounce time set debounced value
  P_MW = B_MW;  //set oldvalue
  
  if (B_Open!= P_Open)  T_Open=millis();      //if change get timer
  if (millis()-T_Open > 1)  V_Open = B_Open;  //if time without change > debounce time set debounced value
  P_Open = B_Open;  //set oldvalue
  
  if (B_Close!= P_Close)  T_Close=millis();      //if change get timer
  if (millis()-T_Close > 1)  V_Close = B_Close;  //if time without change > debounce time set debounced value
  P_Close = B_Close;  //set oldvalue
  
  if (B_Manu!= P_Manu)  T_Manu=millis();      //if change get timer
  if (millis()-T_Manu > 1)  V_Manu = B_Manu;  //if time without change > debounce time set debounced value
  P_Manu = B_Manu;  //set oldvalue  
  
  if (B_Auto!= P_Auto)  T_Auto=millis();      //if change get timer
  if (millis()-T_Auto > 1)  V_Auto = B_Auto;  //if time without change > debounce time set debounced value
  P_Auto = B_Auto;  //set oldvalue

  pinc = PINC;
//B_???? =      pinc & B00000001;
//B_???? =      pinc & B00000010;
  B_Sync  =     pinc & B00000100;
  B_R_closed  = pinc & B00001000;
  B_R_opened  = pinc & B00010000;
  B_Index =     pinc & B00100000;
//B_???? =      pinc & B01000000;
//B_???? =      pinc & B10000000;

  if (B_Sync!= P_Sync)  T_Sync=millis();      //if change get timer
  if (millis()-T_Sync > 1)  V_Sync = B_Sync;  //if time without change > debounce time set debounced value
  P_Sync = B_Sync;  //set oldvalue

  if (B_R_closed!= P_R_closed)  T_R_closed=millis();      //if change get timer
  if (millis()-T_R_closed > 1)  V_R_closed = B_R_closed;  //if time without change > debounce time set debounced value
  P_R_closed = B_R_closed;  //set oldvalue

  if (B_R_opened!= P_R_opened)  T_R_opened=millis();      //if change get timer
  if (millis()-T_R_opened > 1)  V_R_opened = B_R_opened;  //if time without change > debounce time set debounced value
  P_R_opened = B_R_opened;  //set oldvalue

  if (B_Index!= P_Index)  T_Index=millis();      //if change get timer
  if (millis()-T_Index > 1)  V_Index = B_Index;  //if time without change > debounce time set debounced value
  P_Index = B_Index;  //set oldvalue
}
