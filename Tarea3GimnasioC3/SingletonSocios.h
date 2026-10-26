#pragma once
#include"ListaArray.h"
#include"Socio.h"
class SingletonSocios
{
private:
	ListaArray<Socio> socios;
public:
	~SingletonSocios();
	static SingletonSocios& getInst();
	ListaArray<Socio>* getSocios();
	string toString();
private:
	SingletonSocios();


};

