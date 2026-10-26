#pragma once
#include "Criatura.h"
class Mistica :
    public Criatura
{
private:
    int energia;

public:
    Mistica(int codigo);
    Mistica(int codigo, string nombre, int peligro,int energia);
    ~Mistica();
    int getEnergia();
    string toString();

};

