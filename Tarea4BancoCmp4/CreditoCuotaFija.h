#pragma once
#include "Credito.h"
class CreditoCuotaFija :
    public Credito
{
public:
    CreditoCuotaFija(int cuota);
    ~CreditoCuotaFija();
    string toJson();
    void pagarCuota();
    string getTipo();
    void pagar(Pago* p);
    void pagar(Pago* p, string cliente);

};

