#pragma once
#include "Paquete.h"
class PaqueteMinutos :
    public Paquete
{
public:
    PaqueteMinutos(int saldo);
    ~PaqueteMinutos();
    string toJson();
    int consumirMinutos(int minutos);
    int disponibleMinutos(int minutos);
};

