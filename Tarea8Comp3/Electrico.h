#pragma once
#include "Vehiculo.h"
class Electrico :
    public Vehiculo
{
public:
    Electrico(string placa);
    Electrico(string placa, string propetario, int capBat);
    ~Electrico();
    string toString();
};

