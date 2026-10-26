#include "BioLab.h"

BioLab::BioLab() :criaturas(10), equipos(10), expediciones(10)
{
}

BioLab::~BioLab()
{
}

bool BioLab::registrarCriatura(Criatura* c)
{
	if (!c)
	{
		return false;
	}
	criaturas.registrar(c);
	return true;
}

bool BioLab::registrarEquipo(Equipo* e)
{
	if (!e)
	{
		return false;
	}
	equipos.registrar(e);
	return true;
}

bool BioLab::crearExpedicion(int id, int codigoCriatura, string nombreEquipo)
{
	Expedicion auxExp(id);
	if (expediciones.buscar(&auxExp))          // id duplicado
	{
		return false;
	}
	Terrestre auxCri(codigoCriatura);
	Criatura* c = criaturas.buscar(&auxCri);
	if (!c)                                    // criatura no existe
	{
		return false;
	}
	Equipo auxEq(nombreEquipo, 0, 0);
	Equipo* e = equipos.buscar(&auxEq);
	if (!e)                                    // equipo no existe
	{
		return false;
	}
	if (c->getPeligro() > e->getSeguridad())   // criatura demasiado peligrosa
	{
		return false;
	}
	expediciones.registrar(new Expedicion(id, c, e));
	return true;
}

Expedicion& BioLab::operator[](int id)
{
	Expedicion aux(id);
	Expedicion* e = expediciones.buscar(&aux);
	if (!e)
	{
		static Expedicion vacia(0);   // expedición "nula": rechaza toda muestra
		return vacia;
	}
	return *e;
}

string BioLab::expedicionesToString()
{
	expediciones.ordenar(Expedicion::OrdenarPorId);
	stringstream ss;
	ss << "{\"expediciones\":" << expediciones.toString(Expedicion::toStringPtr) << "}";
	return ss.str();
}

string BioLab::criaturaMasInvestigada()
{
	Criatura* mejor = NULL;
	int maxCant = 0;
	for (int i = 0; criaturas[i] != NULL; i++)
	{
		int cant = 0;
		for (int j = 0; expediciones[j] != NULL; j++)
		{
			if (*(expediciones[j]->getCriatura()) == criaturas[i])
			{
				cant++;
			}
		}
		if (cant > maxCant)
		{
			maxCant = cant;
			mejor = criaturas[i];
		}
	}
	if (!mejor)
	{
		return "";
	}
	return mejor->toString();
}

int BioLab::expedicionMayorValor()
{
	int idMejor = 0;
	int maxValor = -1;
	for (int i = 0; expediciones[i] != NULL; i++)
	{
		int valor = expediciones[i]->energiaUsada();
		if (valor > maxValor)
		{
			maxValor = valor;
			idMejor = expediciones[i]->getId();
		}
	}
	return idMejor;
}

int BioLab::energiaMagicaTotal()
{
	int total = 0;
	for (int i = 0; expediciones[i] != NULL; i++)
	{
		Mistica* m = dynamic_cast<Mistica*>(expediciones[i]->getCriatura());
		if (m)
		{
			total += expediciones[i]->energiaUsada();
		}
	}
	return total;
}

string BioLab::generarInforme()
{
	expediciones.ordenar(Expedicion::OrdenarPorId);
	stringstream ss;
	ss << "{\"criaturaMasInvestigada\":" << criaturaMasInvestigada()
		<< ",\"expedicionMayorValor\":" << expedicionMayorValor()
		<< ",\"energiaMagicaTotal\":" << energiaMagicaTotal()
		<< ",\"detalleExpediciones\":" << expediciones.toString(Expedicion::detalleToStringPtr) << "}";
	return ss.str();
}
