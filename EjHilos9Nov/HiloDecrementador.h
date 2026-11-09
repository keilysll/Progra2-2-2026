#pragma once
#include "Hilo.h"
#include"ContSingleton.h"
class HiloDecrementador :
    public Hilo
{
public:
    HiloDecrementador(int nro);
    ~HiloDecrementador();
    void procesar();
};

