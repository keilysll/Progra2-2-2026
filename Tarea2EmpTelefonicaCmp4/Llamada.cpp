#include "Llamada.h"

Llamada::Llamada(int id, int fecha, int duracion):Detalle(id,fecha)
{
	this->duracion = duracion;
}

Llamada::~Llamada()
{
}

int Llamada::getDuracion()
{
	return duracion;
}

int Llamada::getCantidad()
{
	return duracion;
}

string Llamada::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"minutos\":"<<duracion<<",\"tipo\":\"llamada\"}";
	return ss.str();
}

int Llamada::consumir(Paquete* p, int pendiente)
{
	return p->consumirMinutos(pendiente);
}

int Llamada::disponible(Paquete* p)
{
	return p->disponibleMinutos();
}

string Llamada::getTipo()
{
	return "llamada";
}
