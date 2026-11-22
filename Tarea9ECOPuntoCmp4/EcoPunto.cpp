#include "EcoPunto.h"

EcoPunto::EcoPunto(string nombre)
{
	this->nombre = nombre;
}

EcoPunto::~EcoPunto()
{
}

string EcoPunto::getNombre()
{
	return nombre;
}

void EcoPunto::operator+=(Participantes* p)
{
	participantes.agregar(p);
}

void EcoPunto::entregar(string nombre, Entrega* e)
{
	Participantes* p = participantes.buscar(nombre);
	p->entregar(e);

}

void EcoPunto::canjear(string nombre, int pts)
{
	participantes.buscar(nombre)->canjear(pts);
}

int EcoPunto::puntosOtorgados()
{
	int total = 0;
	for (int i = 0; i < participantes.size(); i++)
	{
		total = total + participantes.obtener(i)->totalOtorgado();
	}
	return total;
}

int EcoPunto::gramosReciclados()
{
	int cant = 0;
	for (int i = 0; i < participantes.size(); i++)
	{
		cant = cant + participantes.obtener(i)->totalGramos();
	}
	return cant;
}

string EcoPunto::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"participantes\":"<<participantes.toJson()<<"}";
	return ss.str();
}
