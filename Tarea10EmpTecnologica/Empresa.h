#pragma once
#include"ModModelo.h"
#include"ModProyecto.h"
class Empresa
{
private:
	string nombre;
	ModModelo modelos;
	ModProyecto proyectos;
public:
	Empresa(string nombre);
	~Empresa();
	string getNombre();
	ModModelo& getModelos();
	void registrar(Modelo* m);
	void registrar(Proyecto* p);
	void registrarProyecto(Proyecto* p);
	void asignarModeloAProyecto(string nombreProy,Modelo* m);
	string toJson();

};

