#include "ConsultaVirtual.h"

ConsultaVirtual::ConsultaVirtual(string paciente, int costo, string plataforma):Consulta(paciente,costo)
{
	this->plataforma = plataforma;
}

ConsultaVirtual::~ConsultaVirtual()
{
}

string ConsultaVirtual::getPlataforma()
{
	return plataforma;
}

int ConsultaVirtual::ingreso()
{
	return (costo * 80 / 100);
}

string ConsultaVirtual::toJson()

{
	stringstream ss;
	ss << "{\"paciente\":\""<<paciente<<"\",\"costo\":"<<costo<<",\"plataforma\":\""<<plataforma<<"\",\"tipo\":\"virtual\"}";
	return ss.str();
}
