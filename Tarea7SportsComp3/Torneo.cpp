#include "Torneo.h"

Torneo::Torneo(int id, string nombre):partidas(10)
{
	this->id = id;
	this->nombre = nombre;
}

Torneo::~Torneo()
{
}

bool Torneo::operator<<(Partida* p)
{
	if (!p)
	{
		return false;

	}
	partidas.registrar(p);
	return true;
}

string Torneo::toString()
{
	partidas.ordenar(Partida::OrdenarDuracionDes);
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"nombre\":\""<<nombre<<"\",\"partidas\":"<<partidas.toJson(Partida::toStringPtr)<<"}";
	return ss.str();
}

string Torneo::jugadorMasVictorias()
{
	Jugador* mejor = NULL;
	int MaxVic = 0;
	for (int i = 0; i < partidas.getInd(); i++)
	{
		PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(partidas[i]);
		if (pi == NULL)
		{
			continue;
		}
		Jugador* candidato = pi->getGanador();

		int victorias = 0;
		for (int j = 0; j < partidas.getInd(); j++)
		{
			PartidaIndividual* pj = dynamic_cast<PartidaIndividual*>(partidas[j]);
			if (pj != NULL && pj->getGanador()->getId() == candidato->getId())
			{
				victorias++;
			}
		}

		if (victorias > MaxVic)
		{
			MaxVic = victorias;
			mejor = candidato;
		}
	}
	if (mejor == NULL)
	{
		return "";
	}
	return mejor->toString();
}

int Torneo::duracionMaxima()
{
	int max = 0;
	for (int i = 0; i < partidas.getInd(); i++)
	{
		if (partidas[i]->getDurac() > max)
		{
			max = partidas[i]->getDurac();
		}
	}
	return max;
}
