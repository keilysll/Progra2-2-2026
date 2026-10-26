#pragma once
#include "Criatura.h"
class Terrestre :
    public Criatura
{
private:
    int velocidad;

public:
    Terrestre(int codigo);
    Terrestre(int codigo, string nombre, int peligro, int velocidad);
    ~Terrestre();
    int getVelocidad();
    string toString();
};

