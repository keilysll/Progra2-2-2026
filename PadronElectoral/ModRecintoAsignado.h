#pragma once
#include"RecintoAsignado.h"
class ModRecintoAsignado
{
private:
	RecintoAsignado** recintos;
	int tam;
	int ind;
public:
	ModRecintoAsignado(int tam);
	~ModRecintoAsignado();
	void registrar(RecintoAsignado* r);
	RecintoAsignado* buscar(int codigo);
	int getInd();
	int getTam();
	string toJson();
};

