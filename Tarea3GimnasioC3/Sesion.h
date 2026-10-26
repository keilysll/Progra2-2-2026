#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"Socio.h"
#include"ListaArray.h"
using namespace std;
class Sesion
{
private:
	int fecha;
	ListaArray<Socio> asistentes;

public:
	Sesion(int fecha);
	~Sesion();
	int getFecha();
	string toString();
	static string toStringPtr(Sesion* s);
	void registrarAsistente(Socio* a);
	bool operator==(Sesion* s);
};

