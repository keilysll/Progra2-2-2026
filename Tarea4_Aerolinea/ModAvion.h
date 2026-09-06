#pragma once
#include"Avion.h"
class ModAvion
{
private:
	int tam;
	int ind;
	Avion** aviones;
public:
	ModAvion(int tam);
	~ModAvion();
	int getTam();
	int getInd();
	void registrar(Avion* a);
	Avion* buscar(int codigo);
	string toJson();

};

