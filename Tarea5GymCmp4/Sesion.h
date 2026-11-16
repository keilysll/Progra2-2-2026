#pragma once
#include"ListaEnlazada.h"
#include"Socio.h"
class Sesion
{
private:
	int fecha;
	ListaEnlazada<Socio> asistentes;
public:
	Sesion(int fecha);
	~Sesion();
	string toString();
	static string toStringPtr(Sesion* s);
	void registrarAsistente(Socio* s);
	int getFecha();
	bool operator==(Sesion* s);
};

