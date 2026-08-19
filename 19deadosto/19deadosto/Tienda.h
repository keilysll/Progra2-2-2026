#pragma once
#include"ModCliente.h"
#include"ModProducto.h"
#include"ModVenta.h"
class Tienda
{
private:
	string nombre;
	ModCliente clientes;
	ModProducto productos;
	ModVenta ventas;

public:
	Tienda(string nombre, int cantMaxPro, int cantMaxCli, int cantMaxVen);
	~Tienda();
	ModCliente& getCliente();
	ModProducto& getProducto();
	ModVenta& getVentas();
	void registrarVenta(int num,int ci);
	void registrarProductoEnVenta(int num, int codigo);
	void mostrar();
	
};

