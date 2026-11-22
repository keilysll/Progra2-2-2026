#pragma once
#include "Carga.h"
class CargaRapida :
    public Carga

{
public:
    CargaRapida(int id, int fecha, int kwh);
    ~CargaRapida();
    int getCosto();
    string toJson();
    int getTarifa();
};

