#include "Empleado.h"

Empleado::Empleado(string nombre, int ci, string areaEsp, int aniosExp)
{
	this->nombre = nombre;
	this->ci = ci;
	this->areaEsp = areaEsp;
	this->aniosExp = aniosExp;

}

Empleado::~Empleado()
{
}

string Empleado::getNombre()
{
	return nombre;
}

int Empleado::getCi()
{
	return ci;
}

string Empleado::getArea()
{
	return areaEsp;
}

int Empleado::getAniosExp()
{
	return aniosExp;
}

void Empleado::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Empleado::setCi(int ci)
{
	this->ci = ci;
}


string Empleado::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Ci\":" << ci <<",";
	ss << "\"Area de Especializacion\":\"" << areaEsp << "\",";
	ss << "\"Anios de experiencia\":\"" << aniosExp<<"\"";
	ss << "}";
	return ss.str();
}
