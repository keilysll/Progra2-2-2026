#pragma once
#include"ListaEnlazada.h"
#include"Pago.h"
#include"CuotaFija.h"
#include"Amortizacion.h"
#include"CreditoCuotaFija.h"
#include"Credito.h"
#include"CreditoCuotaVariable.h"
class Cliente
{
private:
	string nombre;
	int fono;
	ListaEnlazada<Credito>creditos;
	ListaEnlazada<Pago>pagos;
public:
	Cliente(string nombre, int fono);
	Cliente(string nombre);

	~Cliente();
	string getNombre();
	int getFono();
	ListaEnlazada<Credito>& getCreditos();
	void registrar(Credito* c);
	void pagar(Pago* p);
	string toJson();
	void registrarCredit(Credito* c);
	bool operator ==(Cliente* c);
	static string toJsonPtr(Cliente* c);

};
