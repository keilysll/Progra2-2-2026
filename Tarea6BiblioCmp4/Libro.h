#pragma once
#include "Material.h"
class Libro :
    public Material
{
private:
    string autor;
    int nroPag;
public:
    Libro(string codigo);
    Libro(string codigo, string titulo,string autor,int nroPag);
    ~Libro();
    string getAutor();
    int getNroPag();
    string toJson();
    int diasPrestamoMax();
};

