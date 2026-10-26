#pragma once
#include "Cargador.h"
class CargadorLento :
    public Cargador
{
private:
    int costo;
public:
    CargadorLento(string codigo, int potencia);
    ~CargadorLento();
    int getCosto();
    string toString();
};

