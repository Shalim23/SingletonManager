#pragma once
#include "SingletonBase.h"

template<typename ClassName>
class Singleton : public SingletonBase
{
public:
	static ClassName& GetInstance() { return *m_Instance; }

protected:
	Singleton() = default;
	~Singleton() {};
	Singleton(const Singleton& other) = delete;
	Singleton(const Singleton&& other) = delete;
	Singleton& operator=(const Singleton& other) = delete;
	Singleton& operator=(const Singleton&& other) = delete;

protected:
	friend class SingletonFactory;

	static ClassName* m_Instance;
};

template<typename ClassName>
ClassName* Singleton<ClassName>::m_Instance = nullptr;