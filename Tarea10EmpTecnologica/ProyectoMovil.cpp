#include "ProyectoMovil.h"

ProyectoMovil::ProyectoMovil(string nombre, string plataforma):Proyecto(nombre)
{
	this->plataforma = plataforma;
}

ProyectoMovil::~ProyectoMovil()
{
}

string ProyectoMovil::getPlataforma()
{
	return plataforma;
}

string ProyectoMovil::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"plataforma\":\""<<plataforma<<"\",\"tipo\":\"movil\",\"modelos\":"<<modelos.toJson()<<"}";
	return ss.str();
}
