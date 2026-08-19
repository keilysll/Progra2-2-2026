
#include <iostream>
using namespace std;
#include"Tienda.h"

int main()
{
	Tienda tienda("ABC", 10, 10, 10);
	tienda.getProducto().registrar(new Producto (1,"pan", 1.0));
	tienda.getProducto().registrar(new Producto(1, "pan", 1.0));
	tienda.getProducto().registrar(new Producto(1, "pan", 1.0));
	tienda.getProducto().registrar(new Producto(1, "pan", 1.0));

	tienda.registrarVenta(1, 10);// agregacion cliente
	tienda.registrarProductoEnVenta(1,2);


}
