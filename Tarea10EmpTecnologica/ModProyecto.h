#pragma once
#include"Proyecto.h"
#include"ProyectoMovil.h"
#include"ProyectoWeb.h"
class ModProyecto
{
private:
	Proyecto** proyectos;
	int tam;
	int ind;
public:
	ModProyecto(int tam);
	~ModProyecto();
	int getTam();
	int getInd();
	void registrar(Proyecto* p);
	Proyecto* buscar(string nombre);
	string toJson();
};

