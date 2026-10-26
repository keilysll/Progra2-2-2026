#include "MisionVigilancia.h"

MisionVigilancia::MisionVigilancia(int id, int idDron, int durMin, string zona, double area):Mision(id,idDron,durMin)

{
	tipo = "vigilancia";
	this->zona = zona;
	this->area = area;
}

MisionVigilancia::~MisionVigilancia()
{
}

string MisionVigilancia::getZona()
{
	return zona;
}

double MisionVigilancia::getArea()
{
	return area;
}

string MisionVigilancia::toString()
{
	stringstream ss;
	ss << "{\"tipo\":\""<<tipo<<"\",\"id\":"<<id<<",\"dronId\":"<<idDron<<",\"duracionMin\":"<<durMin<<",\"zona\":\""<<zona<<"\",\"areaKm2\":"<<area<<"}";
	return ss.str();
}
