#include "NegValueExcep.h"

NegValueExcep::NegValueExcep(int a, int b)
{
	stringstream ss;
	ss << "Valores negativos:" << a << " b: " << b;
	mensaje = ss.str();
}

NegValueExcep::~NegValueExcep()
{
}

const char* NegValueExcep::what() const
{
	return mensaje.c_str();
}
