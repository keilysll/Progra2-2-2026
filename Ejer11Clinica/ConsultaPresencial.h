#pragma once
#include "Consulta.h"
class ConsultaPresencial :
    public Consulta
{
private:
    int duracion;
public:
    ConsultaPresencial(string paciente,int costo,int duracion);
    ~ConsultaPresencial();
    int getDuracion();
    int ingreso();
    string toJson();
};

