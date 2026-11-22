#include "MaterialPeso.h"

MaterialPeso::MaterialPeso(string nombre, int pts):Material(nombre,pts)
{
}

MaterialPeso::~MaterialPeso()
{
}

string MaterialPeso::toJson() const
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"tipo\":\"peso\",\"puntos\":" << pts << "}";
	return ss.str();
}

int MaterialPeso::puntos(int cantidad)
{
	return (cantidad / 1000) * pts;;
}

