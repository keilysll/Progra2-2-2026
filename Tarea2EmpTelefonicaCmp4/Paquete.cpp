#include "Paquete.h"

int Paquete::consumir(int cantidad)
{
	int usado;
	if (saldo < cantidad)
		usado = saldo;
	else
		usado = cantidad;
	saldo = saldo - usado;
	return usado;
}

Paquete::Paquete(int saldo)
{
	this->saldo = saldo;
}

Paquete::~Paquete()
{
}

int Paquete::getSaldo()
{
	return saldo;
}

string Paquete::toJsonPtr(Paquete* p)
{
	return p->toJson();
}

int Paquete::consumirMinutos(int minutos)
{
	return 0;
}

int Paquete::consumirMegas(int megas)
{
	return 0;
}

int Paquete::disponibleMinutos()
{
	return 0;
}

int Paquete::disponibleMegas(int megas)
{
	return 0;
}
