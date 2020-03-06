#pragma once
#include <iostream>
#include "Singleton.h"

class Manager2 : public Singleton<Manager2>
{
public:
    void Display() { std::cout << a << " " << b << " " << c <<'\n'; }

    ~Manager2() { std::cout << "Manager2 died\n"; }

private:
    int a = 5;
    double b = 6.0;
    double c = 3.0;
};

