#include "Expedicion.h"

Expedicion::Expedicion(int id) :muestras(20)
{
	this->id = id;
	criatura = NULL;
	equipo = NULL;
}

Expedicion::Expedicion(int id, Criatura* criatura, Equipo* equipo) :muestras(20)
{
	this->id = id;
	this->criatura = criatura;
	this->equipo = equipo;
}

Expedicion::~Expedicion()
{
}

int Expedicion::getId()
{
	return id;
}

double Expedicion::capacidadUsadaKg()
{
	int gramos = 0;
	for (int i = 0; muestras[i] != NULL; i++)
	{
		Biologica* b = dynamic_cast<Biologica*>(muestras[i]);
		if (b)
		{
			gramos += b->getPeso();
		}
	}
	return static_cast<double>(gramos) / 1000;
}

int Expedicion::energiaUsada()
{
	int total = 0;
	for (int i = 0; muestras[i] != NULL; i++)
	{
		Energetica* e = dynamic_cast<Energetica*>(muestras[i]);
		if (e)
		{
			total += e->getEner();
		}
	}
	return total;
}

int Expedicion::valorCientifico()
{
	int valor = 0;
	for (int i = 0; muestras[i] != NULL; i++)
	{
		Biologica* b = dynamic_cast<Biologica*>(muestras[i]);
		Energetica* e = dynamic_cast<Energetica*>(muestras[i]);
		if (b)
		{
			valor += b->getPureza() + b->getPeso() / 100;
		}
		if (e)
		{
			valor += e->getEner() + e->getRad() * 2;
		}
	}
	Mistica* m = dynamic_cast<Mistica*>(criatura);
	Terrestre* t = dynamic_cast<Terrestre*>(criatura);
	if (m)
	{
		valor += m->getEnergia() / 10;
	}
	if (t)
	{
		valor += t->getVelocidad() / 10;
	}
	return valor;
}

bool Expedicion::operator<<(Muestra* m)
{
	if (!m || !equipo)
	{
		return false;
	}
	Biologica* b = dynamic_cast<Biologica*>(m);
	Energetica* e = dynamic_cast<Energetica*>(m);
	if (b)
	{
		double nuevo = capacidadUsadaKg() + static_cast<double>(b->getPeso()) / 1000;
		if (nuevo > equipo->getCapc())
		{
			return false;
		}
	}
	if (e)
	{
		if (energiaUsada() + e->getEner() > equipo->getCapc() * 10)
		{
			return false;
		}
	}
	muestras.registrar(m);
	return true;
}

bool Expedicion::operator==(Expedicion* e)
{
	return id == e->id;
}

string Expedicion::toString()
{
	stringstream ss;
	ss << "{\"id\":" << id << ",\"criaturaCodigo\":" << criatura->getCodigo()
		<< ",\"equipo\":\"" << equipo->getNombre() << "\""
		<< ",\"muestras\":" << muestras.toString(Muestra::toStringPtr)
		<< ",\"valorCientifico\":" << valorCientifico() << "}";
	return ss.str();
}

string Expedicion::toStringPtr(Expedicion* e)
{
	return e->toString();
}

bool Expedicion::OrdenarPorId(Expedicion* a, Expedicion* b)
{
	return a->id > b->id;
}

Criatura* Expedicion::getCriatura()
{
	return criatura;
}

string Expedicion::detalleToString()
{
	stringstream ss;
	Mistica* m = dynamic_cast<Mistica*>(criatura);
	Terrestre* t = dynamic_cast<Terrestre*>(criatura);
	ss << "{\"id\":" << id;
	if (m)
	{
		ss << ",\"tipoCriatura\":\"mistica\",\"energiaMagica\":" << m->getEnergia();
	}
	if (t)
	{
		ss << ",\"tipoCriatura\":\"terrestre\",\"velocidadMax\":" << t->getVelocidad();
	}
	ss << "}";
	return ss.str();
}

string Expedicion::detalleToStringPtr(Expedicion* e)
{
	return e->detalleToString();
}