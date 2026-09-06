#include "Capacitacion.h"

Capacitacion::Capacitacion(int codigo, string nombre):instructores(5),inscritos(10),sesiones(5)
{
	this->codigo = codigo;
	this->nombre = nombre;
}

Capacitacion::~Capacitacion()
{
}

int Capacitacion::getCodigo()
{
	return codigo;
}

string Capacitacion::getNombre()
{
	return nombre;
}

ModEmpleado& Capacitacion::getinstructores()
{
	return instructores;
}

ModEmpleado& Capacitacion::getinscritos()
{
	return inscritos;
}

ModSesion& Capacitacion::getsesiones()
{
	return sesiones;
}

void Capacitacion::asignarInstructor(Empleado* e)
{
	instructores.registrar(e);
}

void Capacitacion::inscribirEmpleados(Empleado* e)
{
	inscritos.registrar(e);
}

void Capacitacion::agregaronSesion(Sesion* s)
{
	sesiones.registrar(s);
}

void Capacitacion::setCodigo(int codigo)
{
	this->codigo = codigo;
	
}

void Capacitacion::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Capacitacion::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codigo\":" << codigo << ",";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Instructores\":" << instructores.toJson() << ",";
	ss << "\"Inscritos\":" << inscritos.toJson();
	ss << "}";
	return ss.str();
}
