#pragma once
#include <array>
#include "SingletonFactory.h"

class SingletonBase;

class SingletonManager
{
public:
	void Init();
	void Shutdown();

private:
	char* m_Buffer = nullptr;
	std::array<SingletonBase*, static_cast<size_t>(Singletons::Count)> m_Singletons = {};
};

