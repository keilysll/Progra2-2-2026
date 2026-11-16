#pragma once
#include"ListaEnlazada.h"
#include"Usuario.h"
class Telefonica
{
private:
	string nombre;
	string direccion;
	ListaEnlazada<Usuario> clientes;

public:
	Telefonica(string nombre,string direccion);
	~Telefonica();
	string getNombre();
	string getDicc();
	void registrarCliente(string nombre, int saldo);
	void registrarPaquete(string nombre, Paquete* p);
	void registrarLlamada(string nombre, int id ,int fecha,int duracion);
	void registrarSMS(string nombre, int id, int fecha, int megas);
	string toJson();
};

