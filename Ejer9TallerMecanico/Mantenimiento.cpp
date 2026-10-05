#include "Mantenimiento.h"

Mantenimiento::Mantenimiento(int codigo, string descrip, int costo, int km):Servicio(codigo,descrip,costo)
{
	this->km = km;
}

Mantenimiento::~Mantenimiento()
{
}

int Mantenimiento::getKm()
{
	return km;
}

string Mantenimiento::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"Mantenimiento\",\"codigo\":"<<codigo<<",\"descripcion\":\""<<descrip<<"\",\"costo\":"<<costo<<",\"kilometros\":\""<<km<<"\"}";
	return ss.str();
}
