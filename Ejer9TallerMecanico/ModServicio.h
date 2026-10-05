#pragma once
#include"Servicio.h"
#include"Chaperia.h"
#include"Mantenimiento.h"
class ModServicio
{
private:
	Servicio** servicios;
	int tam;
	int ind;
public:
	ModServicio(int tam);
	~ModServicio();
	int getTam();
	int getInd();
	void registrar(Servicio* s);
	void ordenar();
	Servicio* buscar(int codigo);
	string toJson();
};

