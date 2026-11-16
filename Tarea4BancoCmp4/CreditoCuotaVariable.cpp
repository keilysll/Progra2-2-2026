#include "CreditoCuotaVariable.h"

CreditoCuotaVariable::CreditoCuotaVariable(int cuota):Credito(cuota)
{
}

CreditoCuotaVariable::~CreditoCuotaVariable()
{
}

string CreditoCuotaVariable::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":"<<cuota<<"}";
	return ss.str();
}

void CreditoCuotaVariable::amortizar(int monto)
{
	cuota = cuota - monto;
}

string CreditoCuotaVariable::getTipo()
{
	return "variable";
}

void CreditoCuotaVariable::pagar(Pago* p)
{
	if (p->getTipo() == "amortizacion")
	{
		Amortizacion* a = (Amortizacion*)p;
		amortizar(a->getMonto());
	}
}

void CreditoCuotaVariable::pagar(Pago* p, string cliente)
{
	if (p->getTipo() == "amortizacion")
	{
		Amortizacion* a = (Amortizacion*)p;
		if (a->getMonto() > cuota)
		{
			throw exception(("El monto que desea pagar "+cliente+ " es mayor a la deuda").c_str());
		}
		amortizar(a->getMonto());
	}
}
