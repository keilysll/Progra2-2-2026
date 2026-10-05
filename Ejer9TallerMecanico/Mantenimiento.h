#pragma once
#include "Servicio.h"
class Mantenimiento :
    public Servicio
{
private:
    int km;
public:
    Mantenimiento(int codigo, string descrip, int costo,int km);
    ~Mantenimiento();
    int getKm();
    string toJson();
};

