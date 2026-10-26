#pragma once
#include "Muestra.h"
class Biologica :
    public Muestra
{
private:
    int peso;
    int pureza;
public:
    Biologica(int cod, string descrip,int peso,int pureza);
    ~Biologica();
    int getPeso();
    int getPureza();
    string toString();
};

