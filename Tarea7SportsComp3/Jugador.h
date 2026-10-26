#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Jugador
{
protected:
	int id;
	string nick;
	string pais;

public:
	Jugador(int id);
	Jugador(int id, string nick , string pais);
	~Jugador();
	int getId();
	string getNick();
	string getPais();
	bool operator == (Jugador * j);
	static string toStringPtr(Jugador* j);
	virtual string toString() = 0;
};

