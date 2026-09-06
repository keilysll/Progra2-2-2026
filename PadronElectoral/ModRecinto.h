#pragma once
#include"Recinto.h"
class ModRecinto
{
private:
	Recinto** recintos;
	int tam;
	int ind;
public:
	ModRecinto(int tam);
	~ModRecinto();
	void registrar(Recinto* r);
	Recinto* buscar(int codigo);
	int getInd();
	int getTam();
	string toJson();
};

