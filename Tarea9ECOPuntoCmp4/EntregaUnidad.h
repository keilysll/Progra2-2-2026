#pragma once
#include "Entrega.h"
class EntregaUnidad :
    public Entrega
{
private:
    int unidades;
public:
    EntregaUnidad(int id, string material, int unidades);
    ~EntregaUnidad();
    int getCantidad();
    string toJson();


};

