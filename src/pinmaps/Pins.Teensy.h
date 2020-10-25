// -------------------------------------------------------------------------------------------------
// Pin map for Teensy3.x

#if defined(__MK20DX256__) || defined(_mk20dx128_h_) || defined(__MK20DX128__)

// Encodeur incrémental
#define Enc_CanalA  11
#define Enc_CanalB  12

// Boutons Poussoirs

#define Rot_CW      13  //  Rotation horaire
#define Rot_CCW     14  //  Rotation Antihoraire
#define Open_Roof   15  //  Ouverture Toit
#define Close_Roof  16  //  Fermeture Toit
#define Flap_open   17  //  Ouverture Obturateur
#define Flap_Close  18  //  Fermeture Obturateur
#define Spare0      6
#define Spare1      23

// Fin de course
#define Index_Nord  19  //  Index Nord
#define Roof_Opened 20  //  Toit Fermé
#define Roof_Closed 21  //  Toit Ouvert
#define Effraction  22  //  Capteurs divers en série, Porte, chocs, Presence

// Sorties
#define Roof_Dir    2  //  Direction Toiture
#define Roof_Pwm    3   //  Vitesse Toiture
#define Light       4  //  Lumière
#define Siren       7  //  Sirène d'alerte  
#define OSpare0     5
#define Beep        8  //  Beep during move

// Capteurs Divers

#else
#error "Mauvais processeur pour cette configuration!"

#endif
