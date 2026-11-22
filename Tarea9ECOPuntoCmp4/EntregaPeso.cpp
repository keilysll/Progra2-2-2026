#include "EntregaPeso.h"

EntregaPeso::EntregaPeso(int id, string material, int gramos):Entrega(id,material)
{
	this->gramos = gramos;
}

EntregaPeso::~EntregaPeso()
{
}

int EntregaPeso::getCantidad()
{
	return gramos;
}

string EntregaPeso::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"material\":\""<<material<<"\",\"tipo\":\"peso\",\"cantidad\":"<<gramos<<",\"puntos\":"<<puntos<<"}";
	return ss.str();
}
