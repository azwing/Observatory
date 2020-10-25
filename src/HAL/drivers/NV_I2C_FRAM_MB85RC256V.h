// -----------------------------------------------------------------------------------
// non-volatile storage for MB85RC256V, Adafruit I2C FRAM module

#pragma once

#include <Wire.h>
#include "Adafruit_FRAM_I2C.h"  // https://github.com/hjd1964/Adafruit_FRAM_I2C
Adafruit_FRAM_I2C fram = Adafruit_FRAM_I2C();
#define E2END 32767

class nvs {
  public:
    void init() {
    fram.begin(&HAL_Wire);
    }

    void poll() {
    }

    byte read(int i) {
      delayMicroseconds(3);
      return fram.read8(i);
    }

    void update(int i, byte j) {
      delayMicroseconds(3);
      fram.write8(i,j);
    }

    void write(int i, byte j) {
      update(i, j);
    }

    // write int numbers into EEPROM at position i (2 bytes)
    void writeInt(int i, int j) {
      uint8_t *k = (uint8_t*)&j;
      update(i + 0, *k); k++;
      update(i + 1, *k);
    }

    // read int numbers from EEPROM at position i (2 bytes)
    int readInt(int i) {
      uint16_t j;
      uint8_t *k = (uint8_t*)&j;
      *k = read(i + 0); k++;
      *k = read(i + 1);
      return j;
    }

    // write 4 byte variable into EEPROM at position i (4 bytes)
    void writeQuad(int i, byte *v) {
      update(i + 0, *v); v++;
      update(i + 1, *v); v++;
      update(i + 2, *v); v++;
      update(i + 3, *v);
    }

    // read 4 byte variable from EEPROM at position i (4 bytes)
    void readQuad(int i, byte *v) {
      *v = read(i + 0); v++;
      *v = read(i + 1); v++;
      *v = read(i + 2); v++;
      *v = read(i + 3);
    }

    // write String into EEPROM at position i (16 bytes)
    void writeString(int i, char l[]) {
      for (int l1 = 0; l1 < 16; l1++) {
        update(i + l1, *l); l++;
      }
    }

    // read String from EEPROM at position i (16 bytes)
    void readString(int i, char l[]) {
      for (int l1 = 0; l1 < 16; l1++) {
        *l = read(i + l1); l++;
      }
    }

    // write 4 byte float into EEPROM at position i (4 bytes)
    void writeFloat(int i, float f) {
      writeQuad(i, (byte*)&f);
    }

    // read 4 byte float from EEPROM at position i (4 bytes)
    float readFloat(int i) {
      float f;
      readQuad(i, (byte*)&f);
      return f;
    }

    // write 4 byte long into EEPROM at position i (4 bytes)
    void writeLong(int i, long l) {
      writeQuad(i, (byte*)&l);
    }

    // read 4 byte long from EEPROM at position i (4 bytes)
    long readLong(int i) {
      long l;
      readQuad(i, (byte*)&l);
      return l;
    }

    // read count bytes from EEPROM starting at position i
    void readBytes(int i, byte *v, byte count) {
      for (int j=0; j<count; j++) { *v = read(i + j); v++; }
    }
};

nvs nv;
