#include "SingletonFactory.h"
#include "SingletonManager.h"
#include "SingletonBase.h"


void SingletonManager::Init()
{
	m_Buffer = new char[SingletonFactory::GetNeededMemory()];

    size_t nextSizeToAdd = 0;
    for(size_t i = 0; i < static_cast<size_t>(Singletons::Count); ++i)
    {
        nextSizeToAdd += SingletonFactory::CreateSingleton(static_cast<Singletons>(i),
            m_Singletons, m_Buffer + nextSizeToAdd);
    }
}

void SingletonManager::Shutdown()
{
    for(auto it = m_Singletons.rbegin(); it != m_Singletons.rend(); ++it)
    {
        (*it)->~SingletonBase();
    }
    
    delete[] m_Buffer;
    m_Buffer = nullptr;
}
