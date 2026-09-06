#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Elector
{
private:
	int ci;
	string nombre;
	int fono;
public:
	Elector(int ci, string nombre,int fono);
	~Elector();
	int getCi();
	string getNombre();
	int getFono();
	void setCi(int ci);
	void setNombre(string nombre);
	void setFono(int fono);
	string toJson();


};

