#pragma once
#include <iostream>
#include "Singleton.h"

class Manager4 : public Singleton<Manager4>
{
public:
    void Display() { std::cout << a << " " << b << '\n'; }
    ~Manager4() { std::cout << "Manager4 died\n"; }
private:
    char a = 5;
    int b = 6;
};

