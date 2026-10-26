#include "Terrestre.h"

Terrestre::Terrestre(int codigo) :Criatura(codigo, " ", 0)
{
}

Terrestre::Terrestre(int codigo, string nombre, int peligro, int velocidad):Criatura(codigo,nombre,peligro)
{
	this ->velocidad = velocidad;
}

Terrestre::~Terrestre()
{
}

int Terrestre::getVelocidad()
{
	return velocidad;
}

string Terrestre::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\"terrestre\",\"codigo\":"<<codigo<<",\"nombre\":\""<<nombre<<"\",\"peligrosidad\":"<<peligro<<",\"velocidadMax\":"<<velocidad<<"}";
	return ss.str();
}
