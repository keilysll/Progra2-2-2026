#pragma once
#include"ModEmpleado.h"
#include"ModCapacitacion.h"
class Empresa
{
private:
	string nombre;
	ModEmpleado empleados;
	ModCapacitacion capacitaciones;
public:
	Empresa(string nombre, int cantMaxEmpleados, int cantMaxCapacitaciones);
	~Empresa();
	string getNombre();
	ModEmpleado& getempleados();
	ModCapacitacion& getcapacitaciones();

	void asignarInstructor(int codigoCapacitacion, int ciInstructor);
	void inscribirEmpleado(int codigoCapacitacion, int ciEmpleado);
	void crearSesion(int codigoCapacitacion, int nroSesion);
	void registrarAsistencia(int codigoCapacitacion, int nroSesion, int ciEmpleado);
	string toJson();
};

