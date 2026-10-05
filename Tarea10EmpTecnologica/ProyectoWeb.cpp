#include "ProyectoWeb.h"

ProyectoWeb::ProyectoWeb(string nombre, string tecnologia):Proyecto(nombre)
{
	this->tecnologia = tecnologia;
}

ProyectoWeb::~ProyectoWeb()
{
}

string ProyectoWeb::getTecnologia()
{
	return tecnologia;
}

string ProyectoWeb::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"tecnologia\":\""<<tecnologia<<"\",\"tipo\":\"web\",\"modelos\":"<<modelos.toJson()<<"}";
	return ss.str();
}
