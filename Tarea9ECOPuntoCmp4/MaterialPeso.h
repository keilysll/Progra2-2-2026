#pragma once
#include "Material.h"
class MaterialPeso :
    public Material
{
public:
    MaterialPeso(string nombre, int pts);
    ~MaterialPeso();
    string toJson() const;
    int puntos(int cantidad);
};

