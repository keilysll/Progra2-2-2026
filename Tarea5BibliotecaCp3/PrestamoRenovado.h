#pragma once
#include "Prestamo.h"
class PrestamoRenovado :
    public Prestamo
{
private:
    int nuevaFech;
    string motivo;

public:
    PrestamoRenovado(int id, Libro* l, Socio* s, int fechaIni, int fechaDev,int nuevaFech,string motivo);
    ~PrestamoRenovado();
    int getnuevaFech();
    string getMotivo();
    string toString();
};

