#pragma once

class SingletonBase
{
    friend class SingletonManager;

protected:
    virtual ~SingletonBase() = 0;
};