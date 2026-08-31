
#include "Empresa.h"
Empresa::Empresa(string nombre, int cantMaxEmpleado, int canMaxProyecto):empleados(10),proyectos(10)
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

ModEmpleado& Empresa::getEmpleado()
{
	return empleados;
}

ModProyecto& Empresa::getProyecto()
{
	return proyectos;
}

void Empresa::registrarEmpleados(Empleado* e)
{
	empleados.registrar(e);
}

void Empresa::registrarProyec(Proyecto* p)
{
	proyectos.registrar(p);
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Empleados\":" << empleados.toJson() << ",";
	ss << "\"Proyectos\":"<<proyectos.toJson();

	ss << "}";
	return ss.str();
}
