#include "Cliente.h"

Cliente::Cliente(string nombre, int fono)
{
	this->nombre = nombre;
	this->fono = fono;
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
}

Cliente::~Cliente()
{
}

string Cliente::getNombre()
{
	return nombre;
}

int Cliente::getFono()
{
	return fono;
}


ListaEnlazada<Credito>& Cliente::getCreditos()
{
	return creditos;
}

void Cliente::registrar(Credito* c)
{
	creditos.registrar(c);
}

void Cliente::pagar(Pago* p)
{
	for (int i = 0; i < creditos.getTam(); i++)
	{
		creditos.get(i)->pagar(p,nombre);
	}
	pagos.registrar(p);
}
string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"fono\":"<<fono<<",\"creditos\":"<<creditos.toJson(Credito::toJsonPtr)<<",\"pagos\":"<<pagos.toJson(Pago::toJsonPtr)<<"}";
	return ss.str();
}

void Cliente::registrarCredit(Credito* c)
{
	creditos.registrar(c);
}

bool Cliente::operator==(Cliente* c)
{
	return nombre == c->nombre;
}

string Cliente::toJsonPtr(Cliente* c)
{
	return c->toJson();
}
