#pragma once

#include "PrintFake.h"
#include "arduino/Stream.h"

#ifndef NO_IGNORE_CHAR
  #define NO_IGNORE_CHAR  '\x01' // a char not found in a valid ASCII numeric field
#endif

using StreamFake = Stream;

template <typename TBase>
class StreamFakeProxy : public PrintFakeProxy<TBase>
{
public:
    StreamFakeProxy(TBase* fake) : PrintFakeProxy<TBase>(fake)
    {
    }

    size_t write(uint8_t value) override
    {
        return getFake()->write(value);
    }

    int available() override
    {
        return getFake()->available();
    }

    int read() override
    {
        return getFake()->read();
    }

    int peek() override
    {
        return getFake()->peek();
    }

    void flush() override
    {
        getFake()->flush();
    }

    void setTimeout(unsigned long timeout) override
    {
        getFake()->setTimeout(timeout);
    }

    unsigned long getTimeout(void) override
    {
        return getFake()->getTimeout();
    }

    using PrintFakeProxy<TBase>::getFake;
};