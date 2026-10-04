#include "Asiento.h"

Asiento::Asiento(int fila, int columna)
{
	this->fila = fila;
	this->columna = columna;
	this->pasajero = NULL;
}

Asiento::~Asiento()
{
}

int Asiento::getFila()
{
	return fila;
}

int Asiento::getColumna()
{
	return columna;
}

Persona* Asiento::getPasajero()
{
	return pasajero;
}

void Asiento::setPasajero(Persona* pasajero)
{
	this->pasajero = pasajero;
}

bool Asiento::estaVacio()
{
	return pasajero == NULL;
}

string Asiento::toJson()
{
	stringstream ss;
	ss << "{\"fila\":" << fila << ",\"columna\":" << columna << ",\"pasajero\":";
	if (pasajero == NULL)
	{
		ss << "\"vacio\"";
	}
	else
	{
		ss << pasajero->toJson();
	}
	ss << "}";
	return ss.str();
}
