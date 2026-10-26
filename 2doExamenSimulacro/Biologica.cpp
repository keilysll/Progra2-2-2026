#include "Biologica.h"

Biologica::Biologica(int cod, string descrip, int peso, int pureza):Muestra(cod,descrip)
{
	this->peso = peso;
	this->pureza = pureza;
}

Biologica::~Biologica()
{
}

int Biologica::getPeso()
{
	return peso;
}

int Biologica::getPureza()
{
	return pureza;
}

string Biologica::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"biologica\",\"codigo\":"<<cod<<",\"descripcion\":\""<<descrip<<"\",\"pesoGramos\":"<<peso<<",\"pureza\":"<<pureza<<"}";
	return ss.str();
}
