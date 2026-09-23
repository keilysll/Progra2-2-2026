#pragma once
#include "ElementoGrafico.h"
class EGSimple :
    public ElementoGrafico // clase abstracta pq los hereda
{
protected:
    int x;
    int y;
public:
    EGSimple(int id, int x, int y);
    ~EGSimple();
    int getX();
    int getY();
};

