#include "Material.h"

Material::Material(string nombre, int pts)
{
	this->nombre = nombre;
	this->pts = pts;
}

Material::~Material()
{
}

string Material::getNombre()
{
	return nombre;
}

int Material::getPts()
{
	return pts;
}

string Material::getClave() const
{
	return nombre;
}

