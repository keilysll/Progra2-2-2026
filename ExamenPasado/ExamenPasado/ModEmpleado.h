#pragma once
#include"Empleado.h"
class ModEmpleado
{
private:
	Empleado** empleados;
	int tam;
	int ind;
public:
	ModEmpleado(int tam);
	~ModEmpleado();
	int getTam();
	int getInd();
	void registrar(Empleado* e);
	Empleado* buscar(int ci);
	string toJson();



};

