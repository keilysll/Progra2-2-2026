
#include <iostream>
#include"Aerolinea.h"
int main()
{
    Aerolinea a1("BOA", 10, 10, 10);
    a1.getClientes().registrar(new Cliente("Maria", 1312, 7758));
    a1.getClientes().registrar(new Cliente("Raul", 1313, 7124));
    a1.getClientes().registrar(new Cliente("Jose", 1314, 7668));

    a1.getAviones().registrar(new Avion(123, 30,"Boeing"));
    a1.getAviones().registrar(new Avion(124, 35, "Cessna"));

    a1.registrarVuelo(1, "Cochabamba", "Santa Cruz", 123);
    a1.registrarVuelo(2, "Tarija", "Cochabamba", 124);

    a1.agregarPasajero(1, 1313);
    a1.agregarPasajero(1, 1312);
    a1.agregarPasajero(2, 1314);
   
   cout << a1.toJson() << endl;

}

