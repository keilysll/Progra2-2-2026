#pragma once
#include"ModPersona.h"
#include"ModAvion.h"
#include"ModVuelo.h"
class Aerolinea
{
private:
	string nombre;
	ModPersona clientes;
	ModAvion aviones;
	ModVuelo vuelos;
public:
	Aerolinea(string nombre, int tamMaxAviones, int tamMaxClientes, int tamMaxVuelos);
	~Aerolinea();
	string getNombre();
	ModPersona& getClientes();
	ModAvion& getAviones();
	ModVuelo& getVuelos();

	void registrarVuelo(int numeroVuelo, int placaAvion);
	void registrarPasajeroEnVuelo(int numeroVuelo, int fila, int columna, int ciPersona);

	string toJson();
};
