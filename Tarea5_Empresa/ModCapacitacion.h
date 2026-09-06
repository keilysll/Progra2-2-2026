#pragma once
#include"Capacitacion.h"
class ModCapacitacion
{
private:
	Capacitacion** capacitaciones;
	int tam;
	int ind;

public:
	ModCapacitacion(int tam);
	~ModCapacitacion();
	int getTam();
	int getInd();
	void registrar(Capacitacion* c);
	Capacitacion* buscar(int codigo);
	void ordenar();
	string toJson();
};

