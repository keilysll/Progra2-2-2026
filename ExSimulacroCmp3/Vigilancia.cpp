#include "Vigilancia.h"

Vigilancia::Vigilancia(int id, string modelo, int autoMin, int resolucion):Dron(id,modelo,autoMin)
{
	this->resolucion= resolucion;
	tipo = "vigilancia";
}

Vigilancia::Vigilancia(int id):Dron(id," ", 0)
{
}

Vigilancia::~Vigilancia()
{
}

int Vigilancia::getResolucion()
{
	return resolucion;
}

string Vigilancia::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\""<<tipo<<"\",\"id\":"<<id<<",\"modelo\":\""<<modelo<<"\",\"autonomiaMin\":"<<autoMin<<",\"resolucionMP\":"<<resolucion<<"}";
	return ss.str();
}

string Vigilancia::getTipo()
{
	return tipo;
}

