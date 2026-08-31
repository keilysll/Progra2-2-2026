#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Proyecto
{
private:
	int num;
	string nombre;
public:
	Proyecto(int num, string nombre);
	~Proyecto();
	int getNum();
	string getNombre();
	void setNum(int num);
	void setNombre(string nombre);
	string toJson();

};

