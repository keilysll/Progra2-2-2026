#pragma once
#include "Muestra.h"
class Energetica :
    public Muestra
{
private:
    int energia;
    int radiacion;
public:
    Energetica(int cod, string descrip,int energia,int radiacion);
    ~Energetica();
    int getEner();
    int getRad();
    string toString();
};

