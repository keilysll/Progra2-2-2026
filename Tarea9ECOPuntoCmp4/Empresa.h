#pragma once
#include "Participantes.h"
class Empresa :
    public Participantes
{
public:
    Empresa(string nombre);
    ~Empresa();
    string toJson();
    void entregar(Entrega* e);
};

