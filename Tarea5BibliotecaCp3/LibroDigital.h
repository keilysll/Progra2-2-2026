#pragma once
#include "Libro.h"
class LibroDigital :
    public Libro
{
private:
    int tamMB;
public:
    LibroDigital(int codigo);
    LibroDigital(int codigo, string titulo, string autor, int tamMb);
    ~LibroDigital();
    int getTam();
    string toString();
};

