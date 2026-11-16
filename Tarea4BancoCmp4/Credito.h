#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Pago.h"
using namespace std;
class Credito
{
protected:
	int cuota;

public:
	Credito(int cuota);
	~Credito();
	int getCuota();
	virtual string toJson() = 0;
	static string toJsonPtr(Credito* c);
	virtual string getTipo() = 0;
	virtual void pagar(Pago* p) = 0;
	virtual void pagar(Pago* p, string cliente) = 0;
};

