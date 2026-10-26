#include "SingletonVehiculos.h"
SingletonVehiculos::SingletonVehiculos():vehiculos(10)
{
}

SingletonVehiculos::~SingletonVehiculos()
{
}

SingletonVehiculos& SingletonVehiculos::getInst()
{
	static SingletonVehiculos inst;
	return inst;
}

bool SingletonVehiculos::operator<<(Vehiculo* v)
{
	if (!v)
	{
		return false;
	}

	vehiculos.registrar(v);
	return true;

}

Vehiculo* SingletonVehiculos::operator[](string placa)
{
	Vehiculo* vHib = vehiculos.buscar(new Hibrido(placa));
	return vHib;
}


string SingletonVehiculos::toString()
{
	vehiculos.ordenar(Vehiculo::CmpAs);
	stringstream ss;
	ss << vehiculos.toString(Vehiculo::toStringPtr);
	return ss.str();
}
