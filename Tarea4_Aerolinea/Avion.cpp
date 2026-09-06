#include "Avion.h"

Avion::Avion(int codigo, int capacidad, string modelo)
{
	this->codigo = codigo;
	this->capacidad = capacidad;
	this->modelo = modelo;
}

Avion::~Avion()
{
}

int Avion::getCodigo()
{
	return codigo;
}

int Avion::getCapacidad()
{
	return capacidad;
}

string Avion::getModelo()
{
	return modelo;
}

void Avion::setCodigo(int codigo)
{
	this->codigo = codigo;
	
}

void Avion::setCapacidad(int capacidad)
{
	this->capacidad = capacidad;

}

void Avion::setModelo(string modelo)
{
	this->modelo = modelo;
}

string Avion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codigo\":" << codigo << ",";
	ss << "\"Capacidad\":" << capacidad << ",";
	ss << "\"Modelo\":\"" << modelo << "\"";
	ss << "}";
	return ss.str();
}
