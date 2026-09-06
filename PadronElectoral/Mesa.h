#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Mesa
{
private:
	int codigo;
public:
	Mesa(int codigo);
	~Mesa();
	int getCodigo();
	void setCodigo(int codigo);
	string toJson();
};

