#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Empresa.h"
int main()
{
    Empresa emp1("BNB", 10,10);
    emp1.getEmpleado().registrar(new Empleado("Julian", 1313, 7562));
    emp1.getEmpleado().registrar(new Empleado("Karen", 1312, 7567));
    emp1.getEmpleado().registrar(new Empleado("Marlene", 1314, 7547));

    emp1.getProyecto().registrar(new Proyecto(1, "Inventario"));
    emp1.getProyecto().registrar(new Proyecto(2, "Balances"));
    emp1.getProyecto().registrar(new Proyecto(3, "Recursos"));

    cout<<emp1.toJson()<<endl;
}


