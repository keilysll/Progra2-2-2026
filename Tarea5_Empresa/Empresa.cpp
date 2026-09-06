#include "Empresa.h"

Empresa::Empresa(string nombre, int cantMaxEmpleados, int cantMaxCapacitaciones):empleados(10),capacitaciones(10)
{
	this->nombre = nombre;
}

Empresa::~Empresa()
{
}

string Empresa::getNombre()
{
	return nombre;
}

ModEmpleado& Empresa::getempleados()
{
	return empleados;
}

ModCapacitacion& Empresa::getcapacitaciones()
{
	return capacitaciones;
}

void Empresa::asignarInstructor(int codigoCapacitacion, int ciInstructor)
{
	Capacitacion* cap = capacitaciones.buscar(codigoCapacitacion);
	Empleado* emp = empleados.buscar(ciInstructor);
	if (cap != NULL && emp != NULL)
	{
		cap->asignarInstructor(emp);
	}
}

void Empresa::inscribirEmpleado(int codigoCapacitacion, int ciEmpleado)
{
	Capacitacion* cap = capacitaciones.buscar(codigoCapacitacion);
	Empleado* emp = empleados.buscar(ciEmpleado);
	if (cap != NULL && emp != NULL)
	{
		cap->inscribirEmpleados(emp);
	}
}

void Empresa::crearSesion(int codigoCapacitacion, int nroSesion)
{
	Capacitacion* cap = capacitaciones.buscar(codigoCapacitacion);
	if (cap != NULL)
	{
		cap->agregaronSesion(new Sesion(nroSesion));
	}
}

void Empresa::registrarAsistencia(int codigoCapacitacion, int nroSesion, int ciEmpleado)
{
	Capacitacion* cap = capacitaciones.buscar(codigoCapacitacion);
	if (cap == NULL) return;

	Sesion* ses = cap->getsesiones().buscar(nroSesion);
	Empleado* emp = empleados.buscar(ciEmpleado);
	if (ses != NULL && emp != NULL)
	{
		ses->registrarAsistencia(emp);
	}
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Empleados\":" << empleados.toJson() << ",";
	ss << "\"Capacitaciones\":" << capacitaciones.toJson();
	ss << "}";
	return ss.str();
}
