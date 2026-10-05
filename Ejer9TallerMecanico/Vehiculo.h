#pragma once
using namespace std;
#include<iostream>
#include<string>
#include<sstream>
class Vehiculo
{
private:
	string placa;
	int km;

public:
	Vehiculo(string placa, int km);
	~Vehiculo();
	string getPlaca();
	int getKm();
	string toJson();
};

