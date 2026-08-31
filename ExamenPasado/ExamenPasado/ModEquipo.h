#pragma once
#include"Equipo.h"
class ModEquipo
{
	Equipo** equipos;
	int tam;
	int ind;
public:
	ModEquipo(int tam);
	~ModEquipo();
	int getTam();
	int getInd();
	void registrar(Equipo* e);
	Equipo* buscar(int nro);
	string toJson();
};

