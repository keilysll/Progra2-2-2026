#pragma once
#include <iostream>
#include<sstream>
#include<string>
using namespace std;
class NegValueExcep :
    public exception
{
private:
    string mensaje;
public:
    NegValueExcep(int a, int b);
    ~NegValueExcep();
    const char* what() const;

};


