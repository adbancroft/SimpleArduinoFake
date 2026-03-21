#pragma once

#include "arduino/EEPROM.h"
#include "ProxyBase.h"

using EEPROMFake = EEPROMClass;

class EEPROMFakeProxy : public ProxyBase<EEPROMFake> {
public:
  EEPROMFakeProxy(EEPROMFake *fake) : ProxyBase<EEPROMFake>(fake) { }
};
