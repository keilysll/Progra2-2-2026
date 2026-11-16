#include "Descarga.h"

Descarga::Descarga(int id, int megas, int fecha):Detalle(id,fecha)
{
	this->megas = megas;
}

Descarga::~Descarga()
{
}

int Descarga::getMegas()
{
	return megas;
}

string Descarga::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"tipo\":\"descarga\"}";
	return ss.str();
}

int Descarga::getCantidad()
{
	return megas;
}

int Descarga::consumir(Paquete* p, int pendiente)
{
	return p->consumirMegas(pendiente);
}

int Descarga::disponible(Paquete* p)
{
	return p->disponibleMegas(megas);
}

string Descarga::getTipo()
{
	return "la descarga";
}
