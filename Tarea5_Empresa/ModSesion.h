#pragma once
#include"Sesion.h"
class ModSesion
{
private:
	Sesion** sesiones;
	int tam;
	int ind;

public:
	ModSesion(int tam);
	~ModSesion();
	int getTam();
	int getInd();
	void registrar(Sesion* s);
	Sesion* buscar(int nro);
	string toJson();
};

