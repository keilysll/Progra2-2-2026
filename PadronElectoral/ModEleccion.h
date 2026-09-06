#pragma once
#include"Eleccion.h"
class ModEleccion
{
private:
	Eleccion** elecciones;
	int tam;
	int ind;
public:
	ModEleccion(int tam);
	~ModEleccion();
	void registrar(Eleccion* e);
	Eleccion* buscar(int codigo);
	int getInd();
	int getTam();
	string toJson();
};

