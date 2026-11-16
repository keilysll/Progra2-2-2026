#pragma once
#include"ListaEnlazada.h"
#include"Socio.h"
class SingletonSocios
{
private:
	ListaEnlazada<Socio> socios;
public:
	~SingletonSocios();
	static SingletonSocios& getInst();
	ListaEnlazada<Socio>* getSocios();
	string toString();
private:
	SingletonSocios();

};

