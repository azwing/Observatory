// -----------------------------------------------------------------------------------
// Configuration universelle
// based on Howard Dutton OnStep idea

#pragma once

#include "Config.Mega.h"

#ifdef Mega_ON
  #define Configuration_Found
#endif
#ifdef Teensy_ON
  #ifdef Configuration_Found
    #define Configuration_Duplicate
  #else
    #define Configuration_Found
  #endif
#endif
#ifdef Configuration_Duplicate
  #error "You have more than one Config.xxx.h file enabled, ONLY ONE can be enabled with _ON."
#endif

#ifndef Configuration_Found
  #error "Choose ONE Config.xxx.h file and enable it for use by turning it _ON."
#endif

// configuration file version

#ifdef FileVersionConfig
  #if FileVersionConfig < FirmwareVersionConfig
    // firmware version 2 is compatible with file version 1
    #if (FileVersionConfig==1) && (FirmwareVersionConfig==2)
      #warning "Configuration: There have been changes to the configuration file format, but OnStep is still backwards compatible for now."
    #else
      #error "Configuration: There have been changes to the configuration file format.  You'll have to make a new Config.xxx.h file."
    #endif
  #elif FileVersionConfig > FirmwareVersionConfig
    #error "Configuration: Configuration file version mismatch."
  #endif
#else
  #if (FirmwareVersionConfig == 1) || (FirmwareVersionConfig == 2)
    #warning "Configuration: Config.xxx.h file version isn't specified (pre-version 1?)"
  #else
    #error "Configuration: There have been changes to the configuration file format.  You'll have to make a new Config.xxx.h file."
  #endif
#endif
