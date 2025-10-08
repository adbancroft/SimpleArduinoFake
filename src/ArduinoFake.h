#pragma once
// clang-format off

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <unordered_map>
#include <cstring>
#include <cstdint>
#include <stdexcept>
#include "fakeit.hpp"

#include "arduino/Arduino.h"

#include "Function.h"
#include "Stream.h"
#include "Serial.h"
#include "Wire.h"
#include "Client.h"
#include "Print.h"
#include "SPI.h"
#include "EEPROM.h"

#define ArduinoFake(mock) _ArduinoFakeGet##mock()

#define ArduinoFakeReset() \
    getArduinoFakeContext()->reset()

#define ArduinoFakeInstance(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeMock(mock) \
    new mock##FakeProxy(ArduinoFakeInstance(mock))

#define _ArduinoFakeGetMock(mock) \
    getArduinoFakeContext()->_##mock.Fake

#define _ArduinoFakeGetFunction() _ArduinoFakeGetMock(Function)
#define _ArduinoFakeGetSerial() _ArduinoFakeGetMock(Serial)
#define _ArduinoFakeGetWire() _ArduinoFakeGetMock(Wire)
#define _ArduinoFakeGetSPI() _ArduinoFakeGetMock(SPI)
#define _ArduinoFakeGetEEPROM() _ArduinoFakeGetMock(EEPROM)
#define _ArduinoFakeGetStream() _ArduinoFakeGetMock(Stream)
#define _ArduinoFakeGetClient() _ArduinoFakeGetMock(Client)
#define _ArduinoFakeGetPrint() _ArduinoFakeGetMock(Print)
#define _ArduinoFakeGet() _ArduinoFakeGetMock(Function)

#define _ArduinoFakeInstanceGetter1(mock) \
    mock##Fake* mock() \
    { \
        if (!this->_##mock.Instance){ \
            this->_##mock.Instance = &this->_##mock.Fake.get(); \
        } \
        return this->_##mock.Instance; \
    }

#define _ArduinoFakeInstanceGetter2(name, clazz) \
    name##Fake* name(class clazz* instance) \
    { \
        if (Mapping[instance]) { \
            return (name##Fake*) Mapping[instance]; \
        } \
        if (dynamic_cast<name##FakeProxy*>(instance)) { \
            return dynamic_cast<name##FakeProxy*>(instance)->get##name##Fake(); \
        } \
        throw std::runtime_error("Unknown instance"); \
    }

template <class FakeT>
struct ArduinoFake_t
{
    fakeit::Mock<FakeT> Fake;
    FakeT *Instance;

    void reset(void)
    {
        Fake.Reset();
        Instance = nullptr;
    }
};

class ArduinoFakeContext
{
    public:
        ArduinoFake_t<FunctionFake> _Function;
        ArduinoFake_t<SerialFake> _Serial;
        ArduinoFake_t<WireFake> _Wire;
        ArduinoFake_t<StreamFake> _Stream;
        ArduinoFake_t<ClientFake> _Client;
        ArduinoFake_t<PrintFake> _Print;
        ArduinoFake_t<SPIFake> _SPI;
        ArduinoFake_t<EEPROMFake> _EEPROM;
        
        std::unordered_map<void*, void*> Mapping;

        _ArduinoFakeInstanceGetter1(Print)
        _ArduinoFakeInstanceGetter1(Stream)
        _ArduinoFakeInstanceGetter1(Serial)
        _ArduinoFakeInstanceGetter1(Wire)
        _ArduinoFakeInstanceGetter1(Client)
        _ArduinoFakeInstanceGetter1(Function)
        _ArduinoFakeInstanceGetter1(SPI)
        _ArduinoFakeInstanceGetter1(EEPROM)

        _ArduinoFakeInstanceGetter2(Print, Print)
        _ArduinoFakeInstanceGetter2(Client, Client)
        _ArduinoFakeInstanceGetter2(Stream, Stream)
        _ArduinoFakeInstanceGetter2(Serial, Serial_)
        _ArduinoFakeInstanceGetter2(Wire, TwoWire)
        _ArduinoFakeInstanceGetter2(SPI, SPIClass)
        _ArduinoFakeInstanceGetter2(EEPROM, EEPROMClass)

        ArduinoFakeContext()
        {
            this->reset();
        }

        void reset(void)
        {
            _Function.reset();
            _Serial.reset();
            _Wire.reset();
            _Stream.reset();
            _Client.reset();
            _Print.reset();
            _SPI.reset();
            _EEPROM.reset();

            Mapping.clear();
            Mapping[&::Serial] = this->Serial();
            Mapping[&::Wire] = this->Wire();
            Mapping[&::SPI] = this->SPI();
            Mapping[&::EEPROM] = this->EEPROM();
        }
};

ArduinoFakeContext* getArduinoFakeContext();

// clang-format on