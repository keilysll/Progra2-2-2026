#pragma once
#include"ModEmpleado.h"
#define CANT_MAX_EMPLAEQUIPOS 10
class Equipo
{
private:
	int nro;
	ModEmpleado empleados;
public:
	Equipo(int nro);
	~Equipo();
	ModEmpleado& getEmpleados();

};

