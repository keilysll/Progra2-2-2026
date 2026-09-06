#pragma once
#include"Vuelo.h"
class ModVuelo
{
private:
	int tam;
	int ind;
	Vuelo** vuelos;
public:
	ModVuelo(int tam);
	~ModVuelo();
	int getTam();
	int getInd();
	void registrar(Vuelo* v);
	Vuelo* buscar(int codigo);
	string toJson();
};

