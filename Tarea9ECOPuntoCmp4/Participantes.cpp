#include "Participantes.h"

Participantes::Participantes(string nombre)
{
	this->nombre = nombre;
	this->puntos = 0;
}

Participantes::~Participantes()
{
}

string Participantes::getNombre()
{
	return nombre;
}

int Participantes::getPuntos()
{
	return puntos;
}

void Participantes::entregar(Entrega* e)
{
	entregas.agregar(e);
}

void Participantes::canjear(int pts)
{
	if (pts > puntos)
	{
		throw exception(("puntos insuficientes de " + nombre + " para canjear " + to_string(pts)).c_str());
	}
	puntos = puntos - pts;
}

string Participantes::getClave() const
{
	return nombre;
}

int Participantes::totalOtorgado()
{
	int total = 0;
	for (int i = 0; i < entregas.size(); i++)
	{
		total = total + entregas.obtener(i)->getPuntos();
	}
	return total;
}

int Participantes::totalGramos()
{
	int total = 0;
	for (int i = 0; i < entregas.size(); i++)
	{
		EntregaPeso* ep = dynamic_cast<EntregaPeso*>(entregas.obtener(i));
		if (ep != NULL)
			total = total + ep->getCantidad();
	}
	return total;
}
