#include "EntregaUnidad.h"

EntregaUnidad::EntregaUnidad(int id, string material, int unidades):Entrega(id,material)
{
	this ->unidades = unidades;
}

EntregaUnidad::~EntregaUnidad()
{
}

int EntregaUnidad::getCantidad()
{
	return unidades;
}


string EntregaUnidad::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"material\":\""<<material<<"\",\"tipo\":\"unidad\",\"cantidad\":"<<unidades<<",\"puntos\":"<<puntos<<"}";
	return ss.str();
}
