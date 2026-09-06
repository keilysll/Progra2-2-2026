#pragma once
#include"ModCliente.h"
#include"Avion.h"
#define CANT_MAXCLIENTES_AVUELO 10
class Vuelo
{
private:
	int codigo;
	string origen;
	string destino;
	Avion* a;
	ModCliente clientes;
public:
	Vuelo(int codigo, string origen, string destino, Avion* a);
	~Vuelo();
	int getCodigo();
	string getOrigen();
	string getDestino();
	Avion* getAv();
	ModCliente& getCliente();
	void registrarClienteaVuelo(Cliente* c);
	string toJson();


};

