#include "DivZeroException.h"

DivZeroException::DivZeroException(int a, int b)
{
	stringstream ss;
	ss << "Div Zero  a :" << a << " b: " << b;
	mensaje = ss.str();
}

DivZeroException::~DivZeroException()
{
}

const char* DivZeroException::what() const
{
	return mensaje.c_str();
}
