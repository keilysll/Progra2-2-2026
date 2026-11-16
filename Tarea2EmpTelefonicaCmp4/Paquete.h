#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Paquete
{
protected:
	int saldo;
	int consumir(int cantidad);
public:
	Paquete(int saldo);
	~Paquete();
	int getSaldo();
	virtual string toJson() = 0;
	static string toJsonPtr(Paquete* p);
	virtual int consumirMinutos(int minutos);
	virtual int consumirMegas(int megas);
	virtual int disponibleMinutos();
	virtual int disponibleMegas(int megas);
	
};

