#pragma once
#include "Mision.h"
class MisionVigilancia :
    public Mision
{
private:
    string zona;
    double area;

public:
    MisionVigilancia(int id, int idDron, int durMin,string zona,double area);
    ~MisionVigilancia();
    string getZona();
    double getArea();
    string toString();
};

