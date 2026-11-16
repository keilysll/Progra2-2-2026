#pragma once
#include"ListaEnlazada.h"
#include"Equipo.h"
#include"Evento.h"
#include"Gol.h"
#include"Cambio.h"
class Partido
{
private:
	int id;
	Equipo* local;
	Equipo* visitante;
	ListaEnlazada<Evento> eventos;
public:
	Partido(int id);
	Partido(int id, Equipo* local, Equipo* visitante);
	~Partido();
	int getId();
	string toString();
	static string toStringPtr(Partido* p);
	bool operator==(Partido* p);
	void gol(int minuto, string equipo, int ci);
	void cambio(int minuto, string equipo, int ci,Jugador* nuevo);

};
