#include "Biblioteca.h"

Biblioteca::Biblioteca(string nombre)
{
	this->nombre = nombre;
}

Biblioteca::~Biblioteca()
{
}

void Biblioteca::operator+=(Material* m)
{
	materiales.registar(m);
}

string Biblioteca::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"materiales\":"<<materiales.toJson(Material::toJsonPtr)<<"}";
	return ss.str();
}

int Biblioteca::prestar(string codigo, int diasUsados)
{
	Material* m = materiales.buscar(new Libro(codigo));

	if (m == NULL)
	{
		throw exception(("material no encontrado: " + codigo).c_str());
	}


	double multa = 0;
	if (diasUsados > m->diasPrestamoMax())
	{
		multa = (diasUsados - m->diasPrestamoMax()) * 5;
	}
	totalMultas = totalMultas + multa;
	return multa;
}

double Biblioteca::getTotalMultas()
{
	return totalMultas;
}

int Biblioteca::detalleLibro(string codigo)
{
	Material* m = materiales.buscar(new Libro(codigo));
	if (m == NULL)
		throw exception(("material no encontrado: " + codigo).c_str());
	Libro* l = dynamic_cast<Libro*>(m);
	if (l == NULL)
		throw exception((codigo + " no es un libro").c_str());
	return l->getNroPag();
}
