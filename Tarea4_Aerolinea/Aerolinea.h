#pragma once
#include"ModCliente.h"
#include"ModAvion.h"
#include"ModVuelo.h"
class Aerolinea
{
private:
	string nombre;
	ModCliente clientes;
	ModAvion aviones;
	ModVuelo vuelos;
public:
	Aerolinea(string nombre, int cantClientes,int cantAviones, int cantVuelos);
	~Aerolinea();
	string getNombre();
	ModCliente& getClientes();
	ModAvion& getAviones();
	ModVuelo& getVuelos();
	void registrarVuelo(int codigo, string origen, string destino, int codigoAvion);
	void agregarPasajero(int codigo, int ciCliente);

	string toJson();

};

