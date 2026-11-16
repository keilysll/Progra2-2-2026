#include "Material.h"

Material::Material(string codigo, string titulo)
{
	this->codigo = codigo;
	this->titulo = titulo;
}

Material::~Material()
{
}

string Material::getCod()
{
	return codigo;
}

string Material::getTitulo()
{
	return titulo;
}

string Material::toJsonPtr(Material* m)
{
	return m->toJson();
}

bool Material::operator==(Material* m)
{
	return codigo == m->codigo;
}

bool Material::operator==(Material& m)
{
	return codigo == m.codigo;
}


