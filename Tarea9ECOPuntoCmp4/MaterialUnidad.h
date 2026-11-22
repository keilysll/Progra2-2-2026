#pragma once
#include "Material.h"
class MaterialUnidad :
    public Material
{
public:
    MaterialUnidad(string nombre, int pts);
    ~MaterialUnidad();
    string toJson()const;
    int puntos(int cantidad);
};

