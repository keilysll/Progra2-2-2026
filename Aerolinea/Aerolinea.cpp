#include "Aerolinea.h"

Aerolinea::Aerolinea(string nombre, int tamMaxAviones, int tamMaxClientes, int tamMaxVuelos):clientes(tamMaxClientes), aviones(tamMaxAviones), vuelos(tamMaxVuelos)
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

ModPersona& Aerolinea::getClientes()
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

void Aerolinea::registrarVuelo(int numeroVuelo, int placaAvion)
{
	Avion* a = aviones.buscar(placaAvion);
	if (a != NULL)
	{
		Vuelo* v = new Vuelo(numeroVuelo, a);
		vuelos.registrar(v);
	}
}

void Aerolinea::registrarPasajeroEnVuelo(int numeroVuelo, int fila, int columna, int ciPersona)
{
	Vuelo* v = vuelos.buscar(numeroVuelo);
	Persona* p = clientes.buscar(ciPersona);
	if (v != NULL && p != NULL)
	{
		v->registrarPasajero(fila, columna, p);
	}
}

string Aerolinea::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\"" << nombre << "\",\"clientes\":" << clientes.toJson() << ",\"aviones\":" << aviones.toJson() << ",\"vuelos\":" << vuelos.toJson() << "}";
	return ss.str();
}
