#include "Recinto.h"

Recinto::Recinto(int codigo, string nombre, string direccion)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->direccion = direccion;
}

Recinto::~Recinto()
{
}

int Recinto::getCodigo()
{
	return codigo;
}

string Recinto::getNombre()
{
	return nombre;
}

string Recinto::getDireccion()
{
	return direccion;
}

void Recinto::setCodigo(int codigo)
{
	this->codigo = codigo;
	
}

void Recinto::setNombre(string nombre)
{
	this->nombre = nombre;
	
}

void Recinto::setDireccion(string direccion)
{
	this->direccion = direccion;
}

string Recinto::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codigo\":" << codigo << ",";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Direccion\":\"" << direccion << "\"";
	ss << "}";
	return ss.str();
}
