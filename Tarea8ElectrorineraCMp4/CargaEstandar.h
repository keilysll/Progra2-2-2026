#pragma once
#include "Carga.h"
class CargaEstandar :
    public Carga
{
public:
    CargaEstandar(int id,int fecha,int kwh);
    ~CargaEstandar();
    int getCosto();
    string toJson();
    int getTarifa();
};

