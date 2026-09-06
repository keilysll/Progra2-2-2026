#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre, int cantClientes, int cantAviones, int cantVuelos):clientes(10),aviones(10),vuelos(10)
{
	this->nombre = nombre;
}

Aerolinea::~Aerolinea()
{
}

string Aerolinea::getNombre()
{
	return nombre;
}

ModCliente& Aerolinea::getClientes()
{
	return clientes;
}

ModAvion& Aerolinea::getAviones()
{
	return aviones;
}

ModVuelo& Aerolinea::getVuelos()
{
	return vuelos;
}

void Aerolinea::registrarVuelo(int codigo, string origen, string destino, int codigoAvion)
{
	Avion* av = aviones.buscar(codigoAvion);

	Vuelo* vuelo = new Vuelo(codigo, origen, destino, av);

	vuelos.registrar(vuelo);
}

void Aerolinea::agregarPasajero(int codigo, int ciCliente)
{
	Vuelo* v = vuelos.buscar(codigo);
	Cliente* c = clientes.buscar(ciCliente);
	if (v != NULL && c != NULL)
	{
		v->registrarClienteaVuelo(c);
	}
}

string Aerolinea::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Nombre\":\"" << nombre << "\",";
	ss << "\"Pasajeros\":" << clientes.toJson() << ",";
	ss << "\"Aviones\":" << aviones.toJson() << ",";
	ss << "\"Vuelos\":" << vuelos.toJson() << ",";
	ss << "}";
	return ss.str();
}
