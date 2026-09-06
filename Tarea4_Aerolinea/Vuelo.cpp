#include "Vuelo.h"

Vuelo::Vuelo(int codigo, string origen, string destino, Avion* a):clientes(CANT_MAXCLIENTES_AVUELO)
{
	this->codigo = codigo;
	this->origen = origen;
	this->destino = destino;
	this->a = a;
}

Vuelo::~Vuelo()
{
}

int Vuelo::getCodigo()
{
	return codigo;
}

string Vuelo::getOrigen()
{
	return origen;
}

string Vuelo::getDestino()
{
	return destino;
}

Avion* Vuelo::getAv()
{
	return a;
}

ModCliente& Vuelo::getCliente()
{
	return clientes;
}

void Vuelo::registrarClienteaVuelo(Cliente* c)
{
	clientes.registrar(c);
}

string Vuelo::toJson()
{
	stringstream ss;
	ss << "{";
	ss << "\"Codigo\":" << codigo << ",";
	ss << "\"Origen\":\"" << origen << "\",";
	ss << "\"Destino\":\"" << destino << "\",";
	ss << "\"Avion\":" << a->toJson() << ",";
	ss << "\"Pasajeros\":" <<clientes.toJson();
	ss << "}";
	return ss.str();
}
