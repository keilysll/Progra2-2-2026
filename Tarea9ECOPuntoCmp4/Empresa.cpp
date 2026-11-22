#include "Empresa.h"

Empresa::Empresa(string nombre):Participantes(nombre)
{

}

Empresa::~Empresa()
{
}

string Empresa::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"tipo\":\"empresa\",\"puntos\":"<<puntos<<",\"entregas\":"<<entregas.toJson()<<"}";
	return ss.str();
}

void Empresa::entregar(Entrega* e)
{
	int id = e->getId();

	// 1. cantidad valida
	if (e->getCantidad() <= 0)
	{
		delete e;
		throw exception(("cantidad invalida en la entrega " + to_string(id)).c_str());
	}

	// 2. el material existe (si no existe, buscar lanza el error)
	Material* m;
	try
	{
		m = Tarifario::getInst().buscar(e->getMaterial());
	}
	catch (exception&)
	{
		delete e;
		throw;
	}

	// 3. el material es del tipo de la entrega
	EntregaPeso* ep = dynamic_cast<EntregaPeso*>(e);
	EntregaUnidad* eu = dynamic_cast<EntregaUnidad*>(e);
	MaterialPeso* mp = dynamic_cast<MaterialPeso*>(m);
	MaterialUnidad* mu = dynamic_cast<MaterialUnidad*>(m);
	if ((ep != NULL && mp == NULL) || (eu != NULL && mu == NULL))
	{
		delete e;
		throw exception(("el material " + m->getNombre() + " no es compatible con la entrega " + to_string(id)).c_str());
	}

	// 4. una empresa no puede entregar por unidad
	if (eu != NULL)
	{
		delete e;
		throw exception(("una empresa no puede entregar por unidad (entrega " + to_string(id) + ")").c_str());
	}

	// 5. todo bien: puntos DOBLES, sumar y guardar
	int pts = m->puntos(e->getCantidad()) * 2;
	e->setPuntos(pts);
	entregas.agregar(e);
	puntos = puntos + pts;
}
