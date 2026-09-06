#include "Mesa.h"

Mesa::Mesa(int codigo)
{
	this->codigo = codigo;
}

Mesa::~Mesa()
{
}

int Mesa::getCodigo()
{
	return codigo;
}

void Mesa::setCodigo(int codigo)
{
	this->codigo = codigo;
}

string Mesa::toJson()
{
	stringstream ss;
	ss <<"{";
	ss<< "\"Codigo\":" << codigo;
	ss << "}";
	return ss.str();
}
