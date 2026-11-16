#pragma once
#include "Material.h"
class Revista :
    public Material
{
private:
    int edicion;
public:
    Revista(string codigo, string titulo,int edicion);
    ~Revista();
    int getEdicion();
    string toJson();
    int diasPrestamoMax();
};

