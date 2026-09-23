#pragma once
#include "EGSimple.h"
class Punto :
    public EGSimple // clase concreta
{
public:
    Punto(int id, int x, int y);
    ~Punto();
    void dibujar();
    void borrar();

};

