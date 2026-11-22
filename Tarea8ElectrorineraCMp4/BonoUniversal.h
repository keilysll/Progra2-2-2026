#pragma once
#include "Bono.h"
class BonoUniversal :
    public Bono
{
public:
    BonoUniversal(int kwh);
    ~BonoUniversal();
    string toJson();
    bool aplicable(Carga* c);
};

