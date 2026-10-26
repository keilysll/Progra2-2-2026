#pragma once
#include"Socio.h"
#include"ModGenerico.h"
class SingletonSocios
{
private:
	ModGenerico<Socio>socios;
public:
	~SingletonSocios();
	static SingletonSocios& getInst();
	bool operator<<(Socio* s);
	string toString();
	Socio* buscar(int ci);
private:
	SingletonSocios();

};

