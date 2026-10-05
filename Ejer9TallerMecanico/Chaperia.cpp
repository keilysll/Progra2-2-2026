#include "Chaperia.h"

Chaperia::Chaperia(int codigo, string descrip, int costo, string detalle):Servicio(codigo,descrip,costo)
{
	this->detalle = detalle;
}

Chaperia::~Chaperia()
{
}

string Chaperia::getDetalle()
{
	return detalle;
}

string Chaperia::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"Chaperia\",\"codigo\":"<<codigo<<",\"descripcion\":\""<<descrip<<"\",\"costo\":"<<costo<<",\"detalle\":\""<<detalle<<"\"}";
	return ss.str();
}
