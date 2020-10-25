// -----------------------------------------------------------------------------------
// Configuration pour Arduino Mega
// 

#define Mega_ON   //  <- Definir à ON pour valider cette configuration

#ifdef Mega_ON
// -------------------------------------------------------------------------------------------------------------------------
// Ajuster en fonction de votre configuration --------------------------------------------------------------

// Vitess par défault du port com, Default=9600
#define SERIAL_B_BAUD_DEFAULT 9600


// -------------------------------------------------------------------------------------------------------------------------
#define FileVersionConfig 1
#include "src/pinmaps/Pins.Mega.h"
#endif
