#include "FunctionFake.h"
#include "ArduinoFake.h"

void init(void)
{
    ArduinoFakeInstance0(Function)->init();
}

void pinMode(uint8_t pin, uint8_t mode)
{
    ArduinoFakeInstance0(Function)->pinMode(pin, mode);
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    ArduinoFakeInstance0(Function)->digitalWrite(pin, val);
}

int digitalRead(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->digitalRead(pin);
}

int analogRead(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->analogRead(pin);
}

void analogWrite(uint8_t pin, int val)
{
    ArduinoFakeInstance0(Function)->analogWrite(pin, val);
}

void analogReference(uint8_t mode)
{
    ArduinoFakeInstance0(Function)->analogReference(mode);
}

void analogReadResolution(uint8_t mode)
{
    ArduinoFakeInstance0(Function)->analogReadResolution(mode);
}

unsigned long millis(void)
{
    return ArduinoFakeInstance0(Function)->millis();
}

unsigned long micros(void)
{
    return ArduinoFakeInstance0(Function)->micros();
}

void delay(unsigned long value)
{
    ArduinoFakeInstance0(Function)->delay(value);
}

void delayMicroseconds(unsigned int us)
{
    ArduinoFakeInstance0(Function)->delayMicroseconds(us);
}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance0(Function)->pulseIn(pin, state, timeout);
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance0(Function)->pulseInLong(pin, state, timeout);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    ArduinoFakeInstance0(Function)->shiftOut(dataPin, clockPin, bitOrder, val);
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    return ArduinoFakeInstance0(Function)->shiftIn(dataPin, clockPin, bitOrder);
}

void detachInterrupt(uint8_t interruptNum) {
    ArduinoFakeInstance0(Function)->detachInterrupt(interruptNum);
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
	ArduinoFakeInstance0(Function)->attachInterrupt(interruptNum, userFunc, mode);
}

void cli(void) {
    ArduinoFakeInstance0(Function)->cli();
}

void sei(void) {
    ArduinoFakeInstance0(Function)->sei();
}

void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
    ArduinoFakeInstance0(Function)->tone(pin, frequency, duration);
}

void noTone(uint8_t pin)
{
    ArduinoFakeInstance0(Function)->noTone(pin);
}

long random(long max)
{
    return ArduinoFakeInstance0(Function)->random(max);
}

long random(long min, long max)
{
    return ArduinoFakeInstance0(Function)->random(min, max);
}

void randomSeed(unsigned long seed)
{
    return ArduinoFakeInstance0(Function)->randomSeed(seed);
}

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
    return ArduinoFakeInstance0(Function)->map(value, fromLow, fromHigh, toLow, toHigh);
}

void yield()
{
    ArduinoFakeInstance0(Function)->yield();
}


uint8_t digitalPinToPort(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->digitalPinToPort(pin);
}
uint8_t digitalPinToBitMask(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->digitalPinToBitMask(pin);
}
uint8_t digitalPinToTimer(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->digitalPinToTimer(pin);
}
volatile uint8_t * portOutputRegister(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->portOutputRegister(pin);
}
volatile uint8_t * portInputRegister(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->portInputRegister(pin);
}
volatile uint8_t * portModeRegister(uint8_t pin)
{
    return ArduinoFakeInstance0(Function)->portModeRegister(pin);
}
