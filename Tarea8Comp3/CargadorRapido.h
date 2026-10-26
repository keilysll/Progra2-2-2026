#pragma once
#include "Cargador.h"
class CargadorRapido :
    public Cargador
{
private:
    int costo;
public:
    CargadorRapido(string codigo, int potencia);
    ~CargadorRapido();
    int getCosto();
    string toString();



};

