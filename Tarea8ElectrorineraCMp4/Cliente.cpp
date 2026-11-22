#include "Cliente.h"

Cliente::Cliente(string nombre, int saldo)
{
	this->nombre = nombre;
	this->saldo = saldo;
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
}

Cliente::~Cliente()
{
}

void Cliente::registrarBono(Bono* b)
{
	bonos.registrar(b);
}

string Cliente::getNombre()
{
	return nombre;
}

ListaEnlazada<Bono>& Cliente::getBonos()
{
	return  bonos;
}

int Cliente::getSaldo()
{
	return saldo;
}

void Cliente::cargar(Carga* c)
{

	if (c->getKm() <= 0)
	{
		throw exception(("kwh invalido en la carga " + to_string(c->getId())).c_str());
	}

	int disponible = 0;
	for (int i = 0; i < bonos.getTam(); i++)
	{
		Bono* b = bonos.getDato(i);
		if (b->aplicable(c))
		{
			disponible = disponible + b->getKwh();
		}
	}

	int falta = c->getKm() - disponible;
	if (falta < 0) falta = 0;
	int costo = falta * c->getTarifa();

	if (costo>saldo)
	{
		throw exception(("saldo insuficiente " + nombre + " no pudo realizar la carga " + to_string(c->getId())).c_str());
	}
	int pendiente = c->getKm();
	for (int i = 0; i < bonos.getTam(); i++)
	{
		Bono* b = bonos.getDato(i);
		if (b->aplicable(c))
		{
			int cubre = pendiente;
			if (b->getKwh() < pendiente)
				cubre = b->getKwh();
			b->usar(cubre);
			pendiente = pendiente - cubre;
		}
	}
	saldo = saldo - costo;
	c->setCosto(costo);
	cargas.registrar(c);
}

void Cliente::registrarCarga(Carga* c)
{
	cargas.registrar(c);
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"saldo\":"<<saldo<<",\"bonos\":"<<bonos.toJson(Bono::toJsonPtr)<<",\"cargas\":"<<cargas.toJson(Carga::toJsonPtr)<<"}";
	return ss.str();
}

bool Cliente::odenarNombreASC(Cliente* c1, Cliente* c2)
{
	return c1->getNombre()  > c2->getNombre();
}

bool Cliente::operator==(Cliente* c)
{
	return c->nombre == nombre;
}

string Cliente::toJsonPtr(Cliente* c)
{
	return c->toJson();
}

int Cliente::totalFacturado()
{
	int total = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		total = total + cargas.getDato(i)->getCosto();
	}
	return total;
}

int Cliente::totalKwh()
{
	int total = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		total = total + cargas.getDato(i)->getKm();
	}
	return total;
}

int Cliente::cantidadCargasRapidas()
{
	int cant = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		CargaRapida* cr = dynamic_cast<CargaRapida*>(cargas.getDato(i));
		if (cr != NULL)
		{
			cant++;
		}
	}
	return cant;
}
