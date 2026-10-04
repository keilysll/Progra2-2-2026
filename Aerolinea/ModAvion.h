#pragma once
#include"Avion.h"
class ModAvion
{
private:
	Avion** aviones;
	int tam;
	int ind;
public:
	ModAvion(int tam);
	~ModAvion();
	int getTam();
	int getInd();
	void registrar(Avion* a);
	Avion* buscar(int placa);
	string toJson();
};
