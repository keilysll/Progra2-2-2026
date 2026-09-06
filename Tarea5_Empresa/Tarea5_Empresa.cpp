
#include"Empresa.h"
#include <iostream>

int main()
{
	Empresa emp1("ABCA", 10, 5);
	emp1.getempleados().registrar(new Empleado("Carlos", 55456, "Ventas", 2));
	emp1.getempleados().registrar(new Empleado("Beatriz Soto", 14845, "Ventas", 1));

	emp1.getcapacitaciones().registrar(new Capacitacion(1, "Atencion al cliente"));

	emp1.asignarInstructor(1, 55456);

	
	emp1.inscribirEmpleado(1, 14845);


	emp1.crearSesion(1, 1);
	emp1.registrarAsistencia(1, 1, 14845);

	cout << emp1.toJson() << endl;
}
