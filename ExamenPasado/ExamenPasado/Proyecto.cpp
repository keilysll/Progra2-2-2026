#include "Proyecto.h"

Proyecto::Proyecto(int num, string nombre)
{
	this->num = num;
	this->nombre = nombre;
}

Proyecto::~Proyecto()
{
}

int Proyecto::getNum()
{
	return num;
}

string Proyecto::getNombre()
{
	return nombre;
}

void Proyecto::setNum(int num)
{
	this->num = num;
	
}

void Proyecto::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Proyecto::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nro\":" << num << ",";
	ss << "\"Nombre\":\"" << nombre << "\"";
	ss<<"}";
	return ss.str();
}
