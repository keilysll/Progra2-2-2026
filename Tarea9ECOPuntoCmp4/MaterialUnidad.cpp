#include "MaterialUnidad.h"

MaterialUnidad::MaterialUnidad(string nombre, int pts):Material(nombre,pts)
{
}

MaterialUnidad::~MaterialUnidad()
{
}

int MaterialUnidad::puntos(int cantidad)
{
	return cantidad * pts;
}

string MaterialUnidad::toJson() const
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"tipo\":\"unidad\",\"puntos\":"<<pts<<"}";
	return ss.str();
}
