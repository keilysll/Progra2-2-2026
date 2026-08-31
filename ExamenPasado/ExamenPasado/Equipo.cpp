#include "Equipo.h"

Equipo::Equipo(int nro, int cantMaxEm):empleados(10)
{
}

Equipo::~Equipo()
{
}

ModEmpleado& Equipo::getEmpleados()
{
	return empleados;
}

int Equipo::getNro()
{
	return nro;
}

string Equipo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nro\":" << nro << ",";
	ss << "\"Integrantes\":\"" << empleados.toJson() << "\"";
	ss << "}";
	return ss.str();
}
