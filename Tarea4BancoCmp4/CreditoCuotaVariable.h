#pragma once
#include "Credito.h"
#include"Amortizacion.h"
class CreditoCuotaVariable :
    public Credito
{
public:
    CreditoCuotaVariable(int cuota);
    ~CreditoCuotaVariable();
    string toJson();
    void amortizar(int monto);
    string getTipo();
    void pagar(Pago* p);
    void pagar(Pago* p, string cliente);
};

