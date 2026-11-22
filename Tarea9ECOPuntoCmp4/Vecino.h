#pragma once
#include "Participantes.h"
class Vecino :
    public Participantes
{
public:

    Vecino(string nombre);
    ~Vecino();
    string toJson();
    void entregar(Entrega* e);
  
};

