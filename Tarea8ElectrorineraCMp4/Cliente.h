#pragma once
#include"Bono.h"
#include"BonoEstandar.h"
#include"BonoUniversal.h"
#include"Carga.h"
#include"CargaEstandar.h"
#include"CargaRapida.h"
#include"ListaEnlazada.h"
class Cliente
{
private:
	string nombre;
	int saldo;
	ListaEnlazada<Bono> bonos;
	ListaEnlazada<Carga>cargas;
public:
	Cliente(string nombre, int saldo);
	Cliente(string nombre);
	~Cliente();
	void registrarBono(Bono* b);
	string getNombre();
	ListaEnlazada<Bono>& getBonos();
	int getSaldo();
	void cargar(Carga* c);
	void registrarCarga(Carga* c);
	string toJson();
	static bool odenarNombreASC(Cliente* c1, Cliente* c2);
	bool operator == (Cliente* c);
	static 	string toJsonPtr(Cliente* c);
	int totalFacturado();
	int totalKwh();
	int cantidadCargasRapidas();
};

