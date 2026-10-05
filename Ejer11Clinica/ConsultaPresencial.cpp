#include "ConsultaPresencial.h"

ConsultaPresencial::ConsultaPresencial(string paciente, int costo, int duracion):Consulta(paciente,costo)
{
	this->duracion = duracion;
}

ConsultaPresencial::~ConsultaPresencial()
{
}

int ConsultaPresencial::getDuracion()
{
	return duracion;
}

int ConsultaPresencial::ingreso()
{
	return costo;
}


string ConsultaPresencial::toJson()
{
	stringstream ss;
	ss << "{\"paciente\":\""<<paciente<<"\",\"costo\":"<<costo<<",\"duracion\":"<<duracion<<",\"tipo\":\"presencial\"}";
	return ss.str();
}
