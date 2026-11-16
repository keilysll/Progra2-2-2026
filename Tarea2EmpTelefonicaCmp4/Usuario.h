#pragma once
#include"ListaEnlazada.h"
#include"Detalle.h"
#include"Llamada.h"
#include"Descarga.h"
#include"Paquete.h"
#include"PaqueteMegas.h"
#include"PaqueteMinutos.h"
class Usuario
{
private:
	string nombre;
	int saldo;
	ListaEnlazada<Paquete>paquetes;
	ListaEnlazada<Detalle> detalles;
public:
	Usuario(string nombre, int saldo);
	Usuario(string nombre);
	~Usuario();
	string getNombre();
	int getSaldo();
	Usuario& getPaquetes();
	void registrar(Paquete* p);
	void ejecutarAccion(Detalle* d);
	void registrarPaquete(Paquete* p);
	string toJson();
	bool operator==(Usuario* u);
	static string toJsonPtr(Usuario* u);
};

