#pragma once
#include "ModEmpleado.h"
#include"ModProyecto.h"
class Empresa
{
private:
	string nombre;
	ModEmpleado empleados;
	ModProyecto proyectos;
public:
	Empresa(string nombre, int cantMaxEmpleado, int canMaxProyecto);
	~Empresa();
	string getNombre();
	ModEmpleado& getEmpleado();
	ModProyecto& getProyecto();
	void registrarEmpleados(Empleado * e);
	void registrarProyec(Proyecto* p);
	string toJson();
};

