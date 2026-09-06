#pragma once
#include"MesaAsignada.h"
class ModMesaAsignada
{
private:
	MesaAsignada** mesas;
	int tam;
	int ind;
public:
	ModMesaAsignada(int tam);
	~ModMesaAsignada();
	void registrar(MesaAsignada* mesa);
	MesaAsignada* buscar(int nro);
	int getInd();
	int getTam();
	string toJson();

};

