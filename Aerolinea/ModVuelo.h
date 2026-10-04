#pragma once
#include"Vuelo.h"
class ModVuelo
{
private:
	Vuelo** vuelos;
	int tam;
	int ind;
public:
	ModVuelo(int tam);
	~ModVuelo();
	int getTam();
	int getInd();
	void registrar(Vuelo* v);
	Vuelo* buscar(int numero);
	string toJson();
};
