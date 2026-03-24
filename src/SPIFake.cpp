#include "ArduinoFake.h"

void SPIClass::begin() { getArduinoFakeContext()._SPI.getFake(this)->begin(); };

void SPIClass::end() { getArduinoFakeContext()._SPI.getFake(this)->end(); };

void SPIClass::beginTransaction(SPISettings settings) {
  getArduinoFakeContext()._SPI.getFake(this)->beginTransaction(settings);
};

void SPIClass::endTransaction(void) {
  getArduinoFakeContext()._SPI.getFake(this)->endTransaction();
};

uint8_t SPIClass::transfer(uint8_t data) {
  return getArduinoFakeContext()._SPI.getFake(this)->transfer(data);
};

uint16_t SPIClass::transfer16(uint16_t data) {
  return getArduinoFakeContext()._SPI.getFake(this)->transfer16(data);
};

void SPIClass::transfer(void *buf, size_t count) {
  return getArduinoFakeContext()._SPI.getFake(this)->transfer(buf, count);
};

SPIClass SPI;
