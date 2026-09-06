#pragma once
#include"ModEmpleado.h"
class Sesion
{
private:
	int nro;
	ModEmpleado asistentes;
public:
	Sesion(int nro);
	~Sesion();
	int getNro();
	ModEmpleado& getAsistentes();
	void setNro(int nro);
	void registrarAsistencia(Empleado* e);
	string toJson();
};

