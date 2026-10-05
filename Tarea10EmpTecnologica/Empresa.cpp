#include "Empresa.h"

Empresa::Empresa(string nombre):modelos(10),proyectos(10)
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

ModModelo& Empresa::getModelos()
{
	return modelos;
}

void Empresa::registrar(Modelo* m)
{
	modelos.registrar(m);
}

void Empresa::registrar(Proyecto* p)
{
	proyectos.registrar(p);
}

void Empresa::registrarProyecto(Proyecto* p)
{
	proyectos.registrar(p);
}

void Empresa::asignarModeloAProyecto(string nombreProy, Modelo* m)
{
	Proyecto* p = proyectos.buscar(nombreProy);
	if (p != NULL)
	{
		p->asignar(m);
	}
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"modelos\":"<<modelos.toJson()<<",\"proyectos\":" << proyectos.toJson() << "}";
	return ss.str();
}
