#pragma once
#include <iostream>
#include<sstream>
#include<string>
using namespace std;
class DivZeroException :
    public exception
{
private:
    string mensaje;
public:
    DivZeroException(int a, int b);
    ~DivZeroException();
    const char* what() const;

};

