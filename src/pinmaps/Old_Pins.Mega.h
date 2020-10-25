// -------------------------------------------------------------------------------------------------
// Pin map pour Mega1280 ou Mega2560

#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)

// Encodeur incrémental
#define Enc_CanalA  3   //PE5
#define Enc_CanalB  2   //PE4

// Boutons Poussoirs
#define Rot_CW      22  //PA0  Rotation horaire
#define Rot_CCW     23  //PA1  Rotation Antihoraire
#define Open_Roof   24  //PA2  Ouverture Toit
#define Close_Roof  25  //PA3  Fermeture Toit
#define Auto        26  //PA4  Automatic operation
#define Manu        27  //PA5  Manual operation
#define Spare0      28  //PA6
#define Spare1      29  //PA7
#define Spare2      30
#define Spare3      31

// Fin de course
#define Index_Nord  32  //      Index Nord
#define Roof_Opened 33  //      Toit Fermé
#define Roof_Closed 34  //      Toit Ouvert
#define Effraction  35  //      Capteurs divers en série, Porte, chocs, Presence

// Sorties
#define Roof_Dir    6   //      Direction Toiture
#define Roof_Pwm    7   //      Vitesse Toiture
#define Light       41  //      Lumière
#define Siren       42  //      Sirène d'alerte  
#define OSpare0     43
#define Beep        44  //      Beep during move

// Capteurs Divers


#else
#error "Mauvais processeur pour cette configuration!"

#endif

#define Spare0   0  //PE0 ( RXD0/PCINT8 ) _ Digital pin 0 (RX0)
#define Spare1   1  //PE1 ( TXD0 ) _ Digital pin 1 (TX0)
#define Enc_CanalA   2 Encoder A //PE4 ( OC3B/INT4 ) _ Digital pin 2 (PWM)
#define Enc_CanalB   3 Encoder B //PE5 ( OC3C/INT5 ) _ Digital pin 3 (PWM)
#define Spare4   4  //PG5 ( OC0B ) _ Digital pin 4 (PWM)
#define Spare5   5  //PE3 ( OC3A/AIN1 ) _ Digital pin 5 (PWM)
#define Roof_Dir   6  Direction Toiture //PH3 ( OC4A ) _ Digital pin 6 (PWM)
#define Roof_Pwm   7  Vitesse Toiture //PH4 ( OC4B ) _ Digital pin 7 (PWM)
#define Spare8   8  //PH5 ( OC4C ) _ Digital pin 8 (PWM)
#define Spare9   9  //PH6 ( OC2B ) _ Digital pin 9 (PWM)
#define Spare10   10  //PB4 ( OC2A/PCINT4 ) _ Digital pin 10 (PWM)
#define Spare11   11  //PB5 ( OC1A/PCINT5 ) _ Digital pin 11 (PWM)
#define Spare12   12  //PB6 ( OC1B/PCINT6 ) _ Digital pin 12 (PWM)
#define Spare13   13  //PB7 ( OC0A/OC1C/PCINT7 ) _ Digital pin 13 (PWM)
#define Spare14   14  //PJ1 ( TXD3/PCINT10 ) _ Digital pin 14 (TX3)
#define Spare15   15  //PJ0 ( RXD3/PCINT9 ) _ Digital pin 15 (RX3)
#define Spare16   16  //PH1 ( TXD2 ) _ Digital pin 16 (TX2)
#define Spare17   17  //PH0 ( RXD2 ) _ Digital pin 17 (RX2)
#define Spare18   18  //PD3 ( TXD1/INT3 ) _ Digital pin 18 (TX1)
#define Spare19   19  //PD2 ( RXDI/INT2 ) _ Digital pin 19 (RX1)
#define Spare20   20  //PD1 ( SDA/INT1 ) _ Digital pin 20 (SDA)
#define Spare21   21  //PD0 ( SCL/INT0 ) _ Digital pin 21 (SCL)
#define Rot_CW   22 Rotation horaire //PA0 ( AD0 ) _ Digital pin 22
#define Rot_CCW   23 Rotation Antihoraire //PA1 ( AD1 ) _ Digital pin 23
#define Open_Roof   24 Ouverture Toit //PA2 ( AD2 ) _ Digital pin 24
#define Close_Roof   25 Fermeture Toit //PA3 ( AD3 ) _ Digital pin 25
#define Auto   26 Automatic operation //PA4 ( AD4 ) _ Digital pin 26
#define Manu   27 Manual operation //PA5 ( AD5 ) _ Digital pin 27
#define Spare28   28  //PA6 ( AD6 ) _ Digital pin 28
#define Spare29   29  //PA7 ( AD7 ) _ Digital pin 29
#define Spare30   30  //PC7 ( A15 ) _ Digital pin 30
#define Spare31   31  //PC6 ( A14 ) _ Digital pin 31
#define Index_Nord   32  Index Nord //PC5 ( A13 ) _ Digital pin 32
#define Roof_Opened   33  Toit Fermé //PC4 ( A12 ) _ Digital pin 33
#define Roof_Closed   34  Toit Ouvert //PC3 ( A11 ) _ Digital pin 34
#define Effraction   35  Capteurs divers en série //PC2 ( A10 ) _ Digital pin 35
#define Spare36   36  //PC1 ( A9 ) _ Digital pin 36
#define Spare37   37  //PC0 ( A8 ) _ Digital pin 37
#define Spare38   38  //PD7 ( T0 ) _ Digital pin 38
#define Spare39   39  //PG2 ( ALE ) _ Digital pin 39
#define Spare40   40  //PG1 ( RD ) _ Digital pin 40
#define Light   41  Lumière //PG0 ( WR ) _ Digital pin 41
#define Siren   42  Sirène d'alerte //PL7 _ Digital pin 42
#define Spare43   43  //PL6 _ Digital pin 43
#define Beep   44  Beep during move //PL5 ( OC5C ) _ Digital pin 44 (PWM)
#define Spare45   45  //PL4 ( OC5B ) _ Digital pin 45 (PWM)
#define Spare46   46  //PL3 ( OC5A ) _ Digital pin 46 (PWM)
#define Spare47   47  //PL2 ( T5 ) _ Digital pin 47
#define Spare48   48  //PL1 ( ICP5 ) _ Digital pin 48
#define Spare49   49  //PL0 ( ICP4 ) _ Digital pin 49
#define Spare50   50  //PB3 ( MISO/PCINT3 ) _ Digital pin 50 (MISO)
#define Spare51   51  //PB2 ( MOSI/PCINT2 ) _ Digital pin 51 (MOSI)
#define Spare52   52  //PB1 ( SCK/PCINT1 ) _ Digital pin 52 (SCK)
#define Spare53   53  //PB0 ( SS/PCINT0 ) _ Digital pin 53 (SS)
#define Spare54   A0  //PF0 ( ADC0 ) _ Analog pin 0
#define Spare55   A1  //PF1 ( ADC1 ) _ Analog pin 1
#define Spare56   A2  //PF2 ( ADC2 ) _ Analog pin 2
#define Spare57   A3  //PF3 ( ADC3 ) _ Analog pin 3
#define Spare58   A4  //PF4 ( ADC4/TCK ) _ Analog pin 4
#define Spare59   A5  //PF5 ( ADC5/TMS ) _ Analog pin 5
#define Spare60   A6  //PF6 ( ADC6/TDO ) _ Analog pin 6
#define Spare61   A7  //PF7 ( ADC7/TDI ) _ Analog pin 7
#define Spare62   A8  //PK0 ( ADC8/PCINT16 ) _ Analog pin 8
#define Spare63   A9  //PK1 ( ADC9/PCINT17 ) _ Analog pin 9
#define Spare64   A10  //PK2 ( ADC10/PCINT18 ) _ Analog pin 10
#define Spare65   A11  //PK3 ( ADC11/PCINT19 ) _ Analog pin 11
#define Spare66   A12  //PK4 ( ADC12/PCINT20 ) _ Analog pin 12
#define Spare67   A13  //PK5 ( ADC13/PCINT21 ) _ Analog pin 13
#define Spare68   A14  //PK6 ( ADC14/PCINT22 ) _ Analog pin 14
#define Spare69   A15  //PK7 ( ADC15/PCINT23 ) _ Analog pin 15

