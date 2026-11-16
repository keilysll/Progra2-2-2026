#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Jugador
{
private:
	int ci;
	string nombre;
	int fono;

public:
	Jugador(int ci,string nombre,int fono);
	Jugador(int ci);
	~Jugador();
	int getCi();
	string getNombre();
	int getFono();
	string toString();
	static string toStringPtr(Jugador* j);
	static bool ordenarCiAsc(Jugador* j1, Jugador* j2);
	bool operator==(Jugador* j);

};

