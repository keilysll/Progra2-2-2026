#pragma once
#include"ModCliente.h"
#include"ModServicio.h"
#include"ModReserva.h"
class Taller
{
private:
	ModCliente clientes;
	ModServicio servicios;
	ModReserva reservas;
public:
	Taller();
	~Taller();
	ModCliente& getClientes();
	ModServicio& getServicios();
	void registrar(Cliente* c);
	void registrarServicio(Servicio* s);
	void registrar(int ci, Vehiculo* v);
	void registrarReserva(int id, int codigoSer, int ci, string placa);
	void registrarReserva(int id,int codigoSer1, int codigoSer2, int ci, string placa);
	string toJson();
};

