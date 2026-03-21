#pragma once

#include "arduino/Print.h"
#include "ProxyBase.h"

using PrintFake = Print;

template <typename TBase>
class PrintFakeProxy  : public ProxyBase<TBase>
{
public:
    PrintFakeProxy(TBase* fake)
    : ProxyBase<TBase>(fake)
    {
    }
};
