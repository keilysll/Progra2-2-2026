#pragma once
#include"ListaEnlazada.h"
#include"Cliente.h"
class Banco
{
private:
	string nombre;
	string direccion;
	ListaEnlazada<Cliente>clientes;
public:
	Banco(string nombre, string direccion);
	~Banco();
	string toJson();
	void registrarCliente(string nombre, int fono);
	void registrarCredito(string nombre, Credito* c);
	void registrarPago(string nombre,int id, int fecha);
	void registrarPago(string nombre, int id, int fecha,int monto);
};

