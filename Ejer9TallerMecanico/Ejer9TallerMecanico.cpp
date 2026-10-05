/*
Una taller mecanico desea un sistema para atender a sus clientes.
Existen dos tipos de servicios:
• chaperia, compuesto por código, descripcion, costo y la descripcion del trabajo realizado.
• mantenimiento, compuesto por código, descripcion, costo y kilometraje.
Los servicios se reservan de dos maneras:
• Simple, en la cual se debe registrar: identificador, atención, cliente y vehiculo.
• Multiple, en el cual se deben registrar: identificador, la primera atención, la segunda atención, cliente y vehiculo.
*/
using namespace std;
#include<iostream>
#include "Taller.h"

Taller taller;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[],\"reservas\":[]}" << endl;
	// Registramos clientes(CI,nombre,fono)
	taller.registrar(new Cliente(12345, "Pedro", 55555));
	taller.registrar(new Cliente(12346, "Juan", 55556));
	taller.registrar(new Cliente(12347, "Maria", 55557));
	// Registramos vehiculos(CI, placa, Km)
	taller.registrar(12345, new Vehiculo("asdf", 5000));
	taller.registrar(12345, new Vehiculo("qwer", 10000));
	taller.registrar(12346, new Vehiculo("rtyu", 20000));
	taller.registrar(12347, new Vehiculo("vbnm", 50000));

	cout << taller.toJson() << endl;
	if (taller.toJson() == "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[],\"reservas\":[]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	cout << "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[]}" << endl;
	
	//registramos servicio de chaperia (codigo,descripcion,costo,detalle)
	taller.registrarServicio(new Chaperia(2, "chaperia", 1000, "Arreglos"));
	taller.registrarServicio(new Chaperia(3, "pintura", 500, "Pintado y pulido"));
	//registramos servicio en Mantenimiento (codigo,descripcion,costo,km)
	taller.registrarServicio(new Mantenimiento(1, "5MKM", 1000, 5500));
	taller.registrarServicio(new Mantenimiento(4, "10MKM", 2000, 1080));
	cout << taller.toJson() << endl;
	if (taller.toJson() == "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout << "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"vehiculo\":{\"placa\":\"asdf\",\"modelo\":5000}},\"atencion\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}}]}" << endl;
	
	//Registramos reserva(idReserva, codigoServicio, ciCliente, placaVehiculo)
	taller.registrarReserva(1, 1, 12345, "asdf");

	cout << taller.toJson() << endl;
	if (taller.toJson() == "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"vehiculo\":{\"placa\":\"asdf\",\"modelo\":5000}},\"atencion\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	cout << "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"vehiculo\":{\"placa\":\"asdf\",\"modelo\":5000}},\"atencion\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}},{\"ReservaCombo\":{\"id\":3,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"vehiculo\":{\"placa\":\"rtyu\",\"modelo\":20000}},\"atencion1\":{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"},\"atencion2\":{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"}},{\"ReservaCombo\":{\"id\":4,\"cliente\":{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557},\"vehiculo\":{\"placa\":\"vbnm\",\"modelo\":50000}},\"atencion1\":{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},\"atencion2\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}}]}" << endl;
	
	//Registramos reserva multiple(idReserva, codigoServicio1, codigoServicio2, ciCliente, placaVehiculo)
	taller.registrarReserva(3, 4, 2, 12346, "rtyu");
	taller.registrarReserva(4, 3, 1, 12347, "vbnm");

	cout << taller.toJson() << endl;
	if (taller.toJson() == "{\"clientes\":[{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556,\"vehiculos\":[{\"placa\":\"rtyu\",\"modelo\":20000}]},{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557,\"vehiculos\":[{\"placa\":\"vbnm\",\"modelo\":50000}]},{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555,\"vehiculos\":[{\"placa\":\"asdf\",\"modelo\":5000},{\"placa\":\"qwer\",\"modelo\":10000}]}],\"servicios\":[{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"},{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"},{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"}],\"reservas\":[{\"ReservaSimple\":{\"id\":1,\"cliente\":{\"ci\":12345,\"nombre\":\"Pedro\",\"fono\":55555},\"vehiculo\":{\"placa\":\"asdf\",\"modelo\":5000}},\"atencion\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}},{\"ReservaCombo\":{\"id\":3,\"cliente\":{\"ci\":12346,\"nombre\":\"Juan\",\"fono\":55556},\"vehiculo\":{\"placa\":\"rtyu\",\"modelo\":20000}},\"atencion1\":{\"tipo\":\"Mantenimiento\",\"codigo\":4,\"descripcion\":\"10MKM\",\"costo\":2000,\"kilometros\":\"1080\"},\"atencion2\":{\"tipo\":\"Chaperia\",\"codigo\":2,\"descripcion\":\"chaperia\",\"costo\":1000,\"detalle\":\"Arreglos\"}},{\"ReservaCombo\":{\"id\":4,\"cliente\":{\"ci\":12347,\"nombre\":\"Maria\",\"fono\":55557},\"vehiculo\":{\"placa\":\"vbnm\",\"modelo\":50000}},\"atencion1\":{\"tipo\":\"Chaperia\",\"codigo\":3,\"descripcion\":\"pintura\",\"costo\":500,\"detalle\":\"Pintado y pulido\"},\"atencion2\":{\"tipo\":\"Mantenimiento\",\"codigo\":1,\"descripcion\":\"5MKM\",\"costo\":1000,\"kilometros\":\"5500\"}}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 25;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int main()
{
	int nota = pregunta1()+pregunta2() + pregunta3()+ pregunta4();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}