#pragma once
#include "Proyecto.h"
class ModProyecto
{
	Proyecto** proyectos;
	int tam;
	int ind;
public:
	ModProyecto(int tam);
	~ModProyecto();
	int getTam();
	int getInd();
	void registrar(Proyecto* p);
	Proyecto* buscar(int codigo);
	string toJson();
};

