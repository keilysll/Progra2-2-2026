#pragma once
#include "Proyecto.h"
class ProyectoWeb :
    public Proyecto
{
private:
    string tecnologia;
public:
    ProyectoWeb(string nombre,string tecnologia);
    ~ProyectoWeb();
    string getTecnologia();
    string toJson();
};

