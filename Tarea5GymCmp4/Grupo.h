#pragma once
#include"SingletonSocios.h"
#include"Socio.h"
#include"ListaEnlazada.h"
#include"Sesion.h"
class Grupo
{
protected:
	string id;
	ListaEnlazada<Socio> inscritos;
	ListaEnlazada<Sesion> sesiones;
public:
	Grupo(string id);
	~Grupo();
	void inscribir(int ci);
	virtual string toString();
	static string toStringPtr(Grupo* g);

};

