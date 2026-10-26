#pragma once
#include "Libro.h"
class LibroFisico :
    public Libro
{
private:
    int nroEj;
public:
    LibroFisico(int codigo);
    LibroFisico(int codigo, string titulo, string autor,int nroEj);
    ~LibroFisico();
    int getNroEj();
    string toString();
};

