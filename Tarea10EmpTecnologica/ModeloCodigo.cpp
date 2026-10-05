#include "ModeloCodigo.h"

ModeloCodigo::ModeloCodigo(string nombre, string lenguaje):Modelo(nombre)
{
	this->lenguaje = lenguaje;
}

ModeloCodigo::~ModeloCodigo()
{
}

string ModeloCodigo::getLenguaje()
{
	return lenguaje;
}

string ModeloCodigo::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"lenguajes\":\""<<lenguaje<<"\",\"tipo\":\"codigo\"}";
	return ss.str();
}
