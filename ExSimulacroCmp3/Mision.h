#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Mision
{
protected:
	string tipo;
	int id;
	int idDron;
	int durMin;
public:
	Mision(int id, int idDron,int durMin);
	~Mision();
	int getId();
	int getDronid();
	int getDurMin();
	string getTipo();
	virtual string toString() = 0;
	static string toStringPtr(Mision* m);
	static bool OrdMision(Mision* m1, Mision* m2);
};

