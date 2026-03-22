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
};