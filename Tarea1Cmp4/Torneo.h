#pragma once
#include"ListaEnlazada.h"
#include"Partido.h"
#include"Equipo.h"
class Torneo
{
private:
	ListaEnlazada<Equipo> equipos;
	ListaEnlazada<Partido> partidos;
	int modo;
public:
	Torneo();
	~Torneo();
	Torneo& getEquipos();
	Torneo& getPartidos();

	void registrar(string nombre);
	void registrar(int id, Equipo* local, Equipo* visitante);
	Equipo* buscar(string nombre);
	string toString();
	Partido* buscar(int id);
};

