#pragma once
#include"ListaArray.h"
#include"Jugador.h"
#include"Pro.h"
#include"Amateur.h"
class SingletonJugadores
{
private:
	ListaArray <Jugador> jugadores;
public:
	~SingletonJugadores();
	static SingletonJugadores& getInst();

	bool operator += (Amateur* a);
	bool operator += (Pro* p);
	Jugador* buscar(int id);

private:
	SingletonJugadores();
};

