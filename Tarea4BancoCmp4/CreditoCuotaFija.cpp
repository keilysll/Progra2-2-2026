#include "CreditoCuotaFija.h"

CreditoCuotaFija::CreditoCuotaFija(int cuota):Credito(cuota)
{
}

CreditoCuotaFija::~CreditoCuotaFija()
{
}

string CreditoCuotaFija::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":"<<cuota<<"}";
	return ss.str();
}

void CreditoCuotaFija::pagarCuota()
{
	cuota = cuota - 10;
}

string CreditoCuotaFija::getTipo()
{
	return "fija";
}

void CreditoCuotaFija::pagar(Pago* p)
{
	if (p->getTipo() == "cuota")
	{
		pagarCuota();
	}
}

void CreditoCuotaFija::pagar(Pago* p, string cliente)
{
	if (p->getTipo() == "cuota")
		pagarCuota();
}
