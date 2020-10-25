// -------------------------------------------------------------------------------------------------
// Pin map pour BluePill

#if defined(__STM32__)

#define  Index_Nord  PA0 //Index NordADC0, CTS2, T2C1E, WKUP
#define  Roof_Opened  PA1 //Toit FerméADC1, RTS2, T2C2
#define  Roof_Closed  PA2 //Toit OuvertADC2, TX2, T2C3
#define  Effraction  PA3 //Capteurs divers en sérieADC3, RX2, T2C4
#define  Auto  PA4 //Automatic operationADC4, NSS1, CK2
#define  Manu  PA5 //Manual operationADC5, SCK1, 
#define  Spare6  PA6 //ADC6, MISO1, T3C1, T1BKIN
#define  Spare7  PA7 //ADC7, MOSI1, T3C2, T1C1N
#define  Roof_Dir  PA8 //Direction ToitureCK1, T3C3, T2C4N
#define  Roof_Pwm  PA9 //Vitesse ToitureTX1, T3C4, T1C2N
#define  Rot_CW  PA10 //Rotation horaireRX1, T1C3
#define  Rot_CCW  PA11 //Rotation AntihoraireUSB+, CTS1, T1C4
#define  Open_Roof  PA12 //Ouverture ToitUSB-, RTS1, T1ETR
#define  Spare13  PA13 //SWDIO, T2CE1
#define  Spare14  PA14 //SWCLK, JTCK
#define  Close_Roof  PA15 //Fermeture ToitJTDI, NSS1, T2CE1
#define  Enc_CanalA  PB0 //Encoder AADC8, T3C4, T1C2N
#define  Enc_CanalB  PB1 //Encoder BADC9, T3C3, T2C4N
#define  Boot1  PB2 //Unused, 
#define  Spare18  PB3 //JTDO, SCK1, T2C2
#define  Spare19  PB4 //JTRST, MISO1, T3C1
#define  Spare20  PB5 //SMBAI1, MOSI1, T2C2
#define  Serial1TX  PB6 //Com USBSCL1, T4C1, TX1
#define  Serial1RX  PB7 //Com USBSDA1, T4C2, RX1
#define  Spare23  PB8 //T4C3, SCL1, CANRX
#define  Spare24  PB9 //T4C4, SDA1, CANTX
#define  Serial3TX  PB10 //Com 18V15SCL2, TX3, 
#define  Serial3RX  PB11 //Com 18V15SDA2, RX3, 
#define  Spare27  PB12 //NSS2, 
#define  Spare28  PB13 //SCK2, 
#define  Spare29  PB14 //MISO2, 
#define  Spare30  PB15 //MOSI2, 
#define  Spare31  PC13 //TAMPER RTC, LED, 
#define  Spare32  PC14 //OSC32 IN, 
#define  Spare33  PC15 //OSC32 OUT, 
#define  ResetBtn  NRST //UnusedReset Button, 


#else
#error "Mauvais processeur pour cette configuration!"

#endif
 
