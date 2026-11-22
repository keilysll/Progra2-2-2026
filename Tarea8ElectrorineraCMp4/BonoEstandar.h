#pragma once
#include "Bono.h"
class BonoEstandar :
    public Bono
{
public:
    BonoEstandar(int kwh);
    ~BonoEstandar();
    string toJson();
    bool aplicable(Carga* c);
};

