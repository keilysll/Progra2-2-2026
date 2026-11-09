#pragma once
#include "Hilo.h"
#include"ContSingleton.h"
class HiloIncrementador :
    public Hilo
{
public:
    HiloIncrementador(int nro);
    ~HiloIncrementador();
    void procesar();
};

