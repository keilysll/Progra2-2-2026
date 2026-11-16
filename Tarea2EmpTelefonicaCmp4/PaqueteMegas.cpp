#include "PaqueteMegas.h"

PaqueteMegas::PaqueteMegas(int saldo):Paquete(saldo)
{
}

PaqueteMegas::~PaqueteMegas()
{
}

string PaqueteMegas::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"megas\",\"saldo megas\":"<<saldo<<"}";
	return ss.str();
}
int PaqueteMegas::consumirMegas(int megas)
{
	if (saldo > megas)
		return consumir(megas);
	return 0;
}

int PaqueteMegas::disponibleMegas(int megas)
{
	if(saldo>megas)
		return saldo;
	return 0;
}
