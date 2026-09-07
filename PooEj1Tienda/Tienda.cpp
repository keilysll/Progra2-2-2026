#include "Tienda.h"

Tienda::Tienda(string nombre, int cantMaxPro, int cantMaxCli, int cantMaxVen):productos(cantMaxPro),clientes(cantMaxCli),ventas(cantMaxVen)
{
}

Tienda::~Tienda()
{
}

ModCliente& Tienda::getCliente()
{
	return clientes;
}

ModProducto& Tienda::getProducto()
{
	return productos;
}

ModVenta& Tienda::getVentas()
{
	return ventas;
}

void Tienda::registrarVenta(int num, int ci)
{
    Cliente* c = clientes.buscar(ci);

    if (c != NULL)
    {
        ventas.registrar(new Venta(num, c));
    }
    else
    {
        cout << "Cliente no encontrado" << endl;
    }
}

void Tienda::registrarProductoEnVenta(int num, int codigo)
{
    Venta* v = ventas.buscar(num);
    if (v != NULL)
    {
        Producto* p = productos.buscar(codigo);

        if (p != NULL)
        {
            v->getProducto().registrar(p);
        }
      
    }
}

void Tienda::mostrar()
{
    cout << "============================" << endl;
    cout << "         TIENDA: " << nombre << endl;
    cout << "============================" << endl;

    cout << "\n--- CLIENTES ---" << endl;
    clientes.mostrar();

    cout << "\n--- PRODUCTOS ---" << endl;
    productos.mostrar();

    cout << "\n--- VENTAS ---" << endl;
    ventas.mostrar();
}

