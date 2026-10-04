#pragma once
#include"Persona.h"
class Asiento
{
private:
	int fila;
	int columna;
	Persona* pasajero;
public:
	Asiento(int fila, int columna);
	~Asiento();
	int getFila();
	int getColumna();
	Persona* getPasajero();
	void setPasajero(Persona* pasajero);
	bool estaVacio();
	string toJson();
};
