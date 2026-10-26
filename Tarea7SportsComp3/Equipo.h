#pragma once
#include"Jugador.h"
#include"ListaArray.h"
#include"Pro.h"
#include"Amateur.h"
#include"SingletonJugadores.h"
class Equipo
{
private:
	string nombre;
	string region;
	ListaArray<Jugador> jugadores;
public:
	Equipo(string nombre,string region);
	~Equipo();
	bool operator+= (int id);
	Jugador* operator[](int i);
	string toString();

};

