#pragma once
#include "Proyecto.h"
class ProyectoMovil :
    public Proyecto
{
private:
    string plataforma;
public:
    ProyectoMovil(string nombre, string plataforma);
    ~ProyectoMovil();
    string getPlataforma();
    string toJson();
};

