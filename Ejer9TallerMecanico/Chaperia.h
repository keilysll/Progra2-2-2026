#pragma once
#include "Servicio.h"
class Chaperia :
    public Servicio
{
private:
    string detalle;
public:
    Chaperia(int codigo, string descrip, int costo,string detalle);
    ~Chaperia();
    string getDetalle();
    string toJson();

};

