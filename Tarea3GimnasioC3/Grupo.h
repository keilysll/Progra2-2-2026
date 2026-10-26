#pragma once
#include"ListaArray.h"
#include"Socio.h"
#include"SingletonSocios.h"
#include"Sesion.h"
class Grupo
{
protected:
	string id;
	ListaArray<Socio> inscritos;
	ListaArray<Sesion> sesiones;
public:
	Grupo(string id);
	~Grupo();
	string getId();
	virtual string toString() = 0;
	void inscribir(int ci);
	void registrarSesion(int fecha);
	static string toStringPtr(Grupo* g);
};

