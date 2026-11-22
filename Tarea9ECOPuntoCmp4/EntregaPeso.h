#pragma once
#include "Entrega.h"
class EntregaPeso :
    public Entrega
{
private:
    int gramos;
public:
    EntregaPeso(int id,string material,int gramos);
    ~EntregaPeso();
    int getCantidad();
    string toJson();

};

