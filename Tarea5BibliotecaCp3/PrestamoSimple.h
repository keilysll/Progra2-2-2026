#pragma once
#include "Prestamo.h"
class PrestamoSimple :
    public Prestamo
{

public:
    PrestamoSimple(int id, Libro* l, Socio* s, int fechaIni, int fechaDev);
    ~PrestamoSimple();
    string toString();
};

