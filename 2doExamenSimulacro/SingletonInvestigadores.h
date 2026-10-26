#pragma once
#include"ListaArray.h"
#include"Investigador.h"
class SingletonInvestigadores
{
private:
	ListaArray<Investigador> investigadores;
public:
	~SingletonInvestigadores();
	static SingletonInvestigadores& getInst();
	bool operator<<(Investigador * i);
	Investigador* operator[](int codigo);

private:
	SingletonInvestigadores();

};

