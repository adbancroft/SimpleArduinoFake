#pragma once

template <typename TBase>
class ProxyBase : public TBase
{
public:
    ProxyBase(TBase *pProxied)
    : pProxied_(pProxied)
    {
    }

    TBase* getFake(void)
    {
        return pProxied_;
    }

private:

    TBase *pProxied_;
};