#pragma once
#include "Pago.h"
class Amortizacion :
    public Pago
{
private:
    int monto;
public:
    Amortizacion(int id,int fecha,int monto);
    ~Amortizacion();
    int getMonto();
    string toJson();
    string getTipo();
};

