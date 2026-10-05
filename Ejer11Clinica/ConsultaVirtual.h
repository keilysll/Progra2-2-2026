#pragma once
#include "Consulta.h"
class ConsultaVirtual :
    public Consulta
{
private:
    string plataforma;
public:
    ConsultaVirtual(string paciente,int costo, string plataforma);
    ~ConsultaVirtual();
    string getPlataforma();
    int ingreso();
    string toJson();

};

