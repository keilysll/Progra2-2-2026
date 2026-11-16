#pragma once
#include"ListaEnlazada.h"
#include"Jugador.h"
class Equipo
{
private:
	string nombre;
	ListaEnlazada<Jugador> jugadores;
public:
	Equipo(string nombre);
	~Equipo();
	string getNombre();
	string toString();
	static string toStringPtr(Equipo* e);
	static bool ordenarNombreDes(Equipo* e1, Equipo* e2);
	void nuevoJugador(int ci, string nombre, int fono);
	Jugador* bucarJugador(int ci);
	bool operator==(Equipo* e);
	void eliminarJugador(int ci);
	void agregarJugador(Jugador* j);


};

