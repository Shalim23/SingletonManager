#pragma once
#include <iostream>
#include "Singleton.h"

class Manager3 : public Singleton<Manager3>
{
public:
    void Display() { std::cout << a << " " << b << " " << c << '\n'; }
    ~Manager3() { std::cout << "Manager3 died\n"; }
private:
    long long a = 5;
    double b = 6.0;
    double c = 3.0;
};

