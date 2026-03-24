#include "ArduinoFake.h"

#if defined(USBCON)

void Serial_::begin(unsigned long baud_count)
{
    getArduinoFakeContext()._Serial.getFake(this)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, byte config)
{
    getArduinoFakeContext()._Serial.getFake(this)->begin(baud_count, config);
}

void Serial_::end(void)
{
    getArduinoFakeContext()._Serial.getFake(this)->end();
}

int Serial_::available(void)
{
    return getArduinoFakeContext()._Serial.getFake(this)->available();
}

int Serial_::peek(void)
{
    return getArduinoFakeContext()._Serial.getFake(this)->peek();
}

int Serial_::read(void)
{
    return getArduinoFakeContext()._Serial.getFake(this)->read();
}

void Serial_::flush(void)
{
    getArduinoFakeContext()._Serial.getFake(this)->flush();
}

size_t Serial_::write(uint8_t c)
{
    return getArduinoFakeContext()._Serial.getFake(this)->write(c);
}

size_t Serial_::write(const uint8_t *buffer, size_t size)
{
    return getArduinoFakeContext()._Serial.getFake(this)->write(buffer, size);
}

uint32_t Serial_::baud()
{
    return getArduinoFakeContext()._Serial.getFake(this)->baud();
}

uint8_t Serial_::stopbits()
{
    return getArduinoFakeContext()._Serial.getFake(this)->stopbits();
}

uint8_t Serial_::paritytype()
{
    return getArduinoFakeContext()._Serial.getFake(this)->paritytype();
}

uint8_t Serial_::numbits()
{
    return getArduinoFakeContext()._Serial.getFake(this)->numbits();
}

bool Serial_::dtr()
{
    return getArduinoFakeContext()._Serial.getFake(this)->dtr();
}

bool Serial_::rts()
{
    return getArduinoFakeContext()._Serial.getFake(this)->rts();
}

int32_t Serial_::readBreak()
{
    return getArduinoFakeContext()._Serial.getFake(this)->readBreak();
}

Serial_ Serial;

#endif // USBCON