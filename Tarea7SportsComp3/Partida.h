#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include"SingletonJugadores.h"
using namespace std;
class Partida
{
protected:
	int id;
	int duracion;
public:
	Partida(int id,int duracion);
	~Partida();
	int getId();
	int getDurac();
	virtual string toString() = 0;
	static string toStringPtr(Partida* p);
	static bool OrdenarDuracionDes(Partida* p1, Partida* p2);
};

