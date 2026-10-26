#pragma once
#include "Vehiculo.h"
class Hibrido :
    public Vehiculo
{
private:
    int capCom;

public:
    Hibrido(string placa);
    Hibrido(string placa, string propetario, int capBat, int capCom);
    ~Hibrido();
    int getCapCom();
    string toString();
};

