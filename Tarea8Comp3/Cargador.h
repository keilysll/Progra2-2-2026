#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Cargador
{
protected:
	string codigo;
	int potencia;
public:
	Cargador(string codigo,int potencia);
	~Cargador();
	string getCodigo();
	int getPotencia();
	virtual string toString() = 0;
	virtual int getCosto() = 0;
	static bool OrdenarPotenciaAsc(Cargador* c1, Cargador* c2);
	static string toStringPtr(Cargador * c);
};

