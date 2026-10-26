#include "Mistica.h"

Mistica::Mistica(int codigo) :Criatura(codigo," ", 0)
{
}

Mistica::Mistica(int codigo, string nombre, int peligro, int energia) :Criatura(codigo,nombre,peligro)
{
	this->energia = energia;
}

Mistica::~Mistica()
{
}

int Mistica::getEnergia()
{
	return energia;
}

string Mistica::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"mistica\",\"codigo\":"<<codigo<<",\"nombre\":\""<<nombre<<"\",\"peligrosidad\":"<<peligro<<",\"energiaMagica\":"<<energia<<"}";
	return ss.str();
}
