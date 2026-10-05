#pragma once
#include "Medico.h"
class MedicoEspecialista :
    public Medico
{
private:
    string especialidad;
public:
    MedicoEspecialista(string nombre, string especialidad);
    ~MedicoEspecialista();
    string getEspe();
    string toJson();
};

