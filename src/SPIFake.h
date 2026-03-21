#pragma once

#include "arduino/SPI.h"
#include "ProxyBase.h"

using SPIFake = SPIClass;

class SPIFakeProxy : public ProxyBase<SPIFake> {
public:
  SPIFakeProxy(SPIFake *fake) : ProxyBase<SPIFake>(fake) { }
};
