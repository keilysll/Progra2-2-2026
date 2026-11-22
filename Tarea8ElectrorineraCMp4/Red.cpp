#include "Red.h"

Red::Red(string nombre)
{
	this->nombre = nombre;
}

Red::~Red()
{
}

string Red::getNombre()
{
	return nombre;
}

void Red::operator+=(Cliente* c)
{
	Cliente temp (c->getNombre());

	if (clientes.buscar(&temp) != NULL)
	{
		throw exception(("el cliente "+ c->getNombre() + " ya esta registrado").c_str());
	}
	clientes.registrar(c);
}

void Red::registrarBono(string nombre, Bono* b)
{
	Cliente* c = clientes.buscar(new Cliente( nombre));
	if (c == NULL)
	{
		throw exception(("cliente " + nombre + " no encontrado").c_str());
	}
	c->registrarBono(b);
	
}

void Red::registrarCarga(string nombre, Carga* c)
{
	Cliente* cl = clientes.buscar(new Cliente(nombre));
	if (cl == NULL)
	{
		throw exception(("cliente " + nombre + " no encontrado").c_str());
	}
	cl->cargar(c);
}

string Red::toJson()
{
	clientes.ordenar(Cliente::odenarNombreASC);
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"clientes\":"<<clientes.toJson(Cliente::toJsonPtr)<<"}";
	return ss.str();
}

int Red::totalFacturado()
{
	int total = 0;
	for (int i = 0; i < clientes.getTam(); i++)
	{
		total = total + clientes.getDato(i)->totalFacturado();
	}
	return total;
}

string Red::clienteMayorConsumo()
{
	if (clientes.getTam() == 0) return "";
	Cliente* mayor = clientes.getDato(0);
	for (int i = 0; i < clientes.getTam(); i++)
	{
		Cliente* c = clientes.getDato(i);
		if (c->totalKwh() > mayor->totalKwh())
		{
			mayor = c;
		}
	}
	return mayor->getNombre();
}

int Red::cantidadCargasRapidas()
{
	int cant = 0;
	for (int i = 0; i < clientes.getTam(); i++)
	{
		cant = cant + clientes.getDato(i)->cantidadCargasRapidas();
	}
	return cant;
}


