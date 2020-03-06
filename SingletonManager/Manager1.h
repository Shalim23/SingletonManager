#pragma once
#include <iostream>
#include "Singleton.h"

class Manager1 : public Singleton<Manager1>
{

public:
	void Display() { std::cout << a << " " << b << '\n'; }

	~Manager1() { std::cout << "Manager1 died\n"; }

private:
	int a = 5;
	double b = 6.0;
};

