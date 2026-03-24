// clang-format off
#include "ArduinoFake.h"
// clang-format on

uint8_t EEPROMClass::read(int idx) {
  return getArduinoFakeContext()._EEPROM.getFake(this)->read(idx);
};
void EEPROMClass::write(int idx, uint8_t val) {
  getArduinoFakeContext()._EEPROM.getFake(this)->write(idx, val);
};
void EEPROMClass::update(int idx, uint8_t val) {
  getArduinoFakeContext()._EEPROM.getFake(this)->update(idx, val);
};
uint16_t EEPROMClass::length() { return getArduinoFakeContext()._EEPROM.getFake(this)->length(); }

EEPROMClass EEPROM;
