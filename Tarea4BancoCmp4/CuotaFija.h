#pragma once
#include "Pago.h"
class CuotaFija :
    public Pago
{
public:
    CuotaFija(int id,int fecha);
    ~CuotaFija();
    string toJson();
    string getTipo();
};

