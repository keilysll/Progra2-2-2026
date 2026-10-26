#pragma once
#include "Dron.h"
class Delivery :
    public Dron
{
private:
    double capac;
public:
    Delivery(int id, string modelo, int autoMin, double capac);
    Delivery(int id);
    ~Delivery();
    double getCapc();
    string toString();
    string getTipo();
  
};

