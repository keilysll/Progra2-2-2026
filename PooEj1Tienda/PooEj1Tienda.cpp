#include <iostream>

#include "Tienda.h"

using namespace std;

int main()
{
    Tienda tienda("ABC", 10, 10, 10);

    // REGISTRAR PRODUCTOS
    tienda.getProducto().registrar(new Producto(1, "Pan", 1.0));
    tienda.getProducto().registrar(new Producto(2, "Jugo", 2.5));
    tienda.getProducto().registrar( new Producto(3, "Leche", 5.0));
    tienda.getProducto().registrar(new Producto(4, "Galletas", 3.0));

    // REGISTRAR CLIENTES

    tienda.getCliente().registrar( new Cliente(1313, "Ana", 3245));
    tienda.getCliente().registrar(new Cliente(1243, "Pablo", 3234));
    tienda.getCliente().registrar(new Cliente(1223, "Ariana", 3233));

    // REGISTRAR VENTA
    tienda.registrarVenta(1, 1313);

    // AGREGAR PRODUCTOS A LA VENTA
    
    tienda.registrarProductoEnVenta(1, 2);
    tienda.registrarProductoEnVenta(1, 3);
    tienda.registrarProductoEnVenta(1, 4);

    // MOSTRAR

    tienda.mostrar();

    return 0;
}