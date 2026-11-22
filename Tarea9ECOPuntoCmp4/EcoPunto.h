#pragma once
#include"Registro.h"
#include"Participantes.h"
#include"Vecino.h"
#include"Empresa.h"
class EcoPunto
{
private:
	string nombre;
	Registro<Participantes>participantes;
public:
	EcoPunto(string nombre);
	~EcoPunto();
	string getNombre();
	void operator+=(Participantes* p);
	void entregar(string nombre,Entrega* e);
	void canjear(string nombre, int pts);
	template<class T>int contar();
	int puntosOtorgados();
	int gramosReciclados();
	string toJson();

};

template<class T>
inline int EcoPunto::contar()
{
	int cont = 0;
	for (int i = 0; i < participantes.size(); i++)
	{
		if (dynamic_cast<T*>(participantes.obtener(i)))
			cont++;
	}
	return cont;
}
