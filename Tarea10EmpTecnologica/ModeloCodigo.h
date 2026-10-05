#pragma once
#include "Modelo.h"
class ModeloCodigo :
    public Modelo
{
private:
    string lenguaje;
public:
    ModeloCodigo(string nombre,string lenguaje);
    ~ModeloCodigo();
    string getLenguaje();
    string toJson();
};

