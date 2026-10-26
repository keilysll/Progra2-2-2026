#pragma once
#include "Mision.h"
class MisionEntrega :
    public Mision
{
private:
    double peso;
    string origen;
    string destino;
public:
    MisionEntrega(int id, int idDron, int durMin,double peso,string origen,string destino);
    ~MisionEntrega();
    double getPeso();
    string getOrigen();
    string getDestino();
    string toString();
};

