#pragma once
#include <cassert>
#include <array>

#include "Manager1.h"
#include "Manager2.h"
#include "Manager3.h"
#include "Manager4.h"

enum class Singletons
{
#define SINGLETON(NAME) NAME,
#include "Singleton.inc"
#undef SINGLETON
    Count
};

class SingletonFactory
{

public:
    
    static size_t GetSizeOfSingleton(const Singletons& type)
    {
        switch (type)
        {
#define SINGLETON(NAME) \
    case Singletons::NAME: \
        return sizeof(NAME);
#include "Singleton.inc"
#undef SINGLETON

        default:
        {
            assert(false && "GetSizeOfSingleton -> unknown type");
            return 0;
        }
        }
    }

    static constexpr size_t GetNeededMemory()
    {
        size_t size = 0;

        for (size_t i = 0; i < static_cast<size_t>(Singletons::Count); ++i)
        {
            size += GetSizeOfSingleton(static_cast<Singletons>(i));
        }

        return size;
    }

    static size_t CreateSingleton(const Singletons& type, std::array<SingletonBase*, static_cast<size_t>(Singletons::Count)>& singletons, char* buffer)
    {
        switch (type)
        {
#define SINGLETON(NAME) \
            case Singletons::NAME: \
                NAME::m_Instance = new(buffer)NAME; \
                singletons[static_cast<size_t>(type)] = NAME::m_Instance; \
                break;
#include "Singleton.inc"
#undef SINGLETON

            default:
            {
                assert(false && "CreateSingleton -> unknown type");
                break;
            }
        }

        return GetSizeOfSingleton(type);
    }
};
