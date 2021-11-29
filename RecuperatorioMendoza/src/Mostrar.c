#include "Mostrar.h"

/// @fn void ImprimirUnPedido(ePedido) Imprime un pedido
/// @param pedido
void ImprimirUnPedido (ePedido pedido)
{
	printf ("\n%6d - %6d - %10.2f\n", pedido.idPedido, pedido.idCliente, pedido.kilosPedido);
}

/// @fn void ImprimirPedidos(ePedido[], int) Imprime el array de pedidos
/// @param listado
/// @param tamListado
void ImprimirPedidos (ePedido listado[], int tamListado)
{
	int i;
	printf ("   Listado de pedidos\n");
	printf ("| %10s | %10s | %10s |\n", "id Pedido", "id Cliente", "Kilos pedido");
	for (i=0; i<tamListado; i++)
	{
		if (listado[i].isEmpty == 0)
		{
			ImprimirUnPedido(listado[i]);
		}
	}
}

/// @fn void ImprimirUnCliente(eCliente, eLocalidad[], int) Imprime un cliente con todos sus datos
/// @param cliente
/// @param localidades
/// @param tamLocalidades
void ImprimirUnCliente (eCliente cliente, eLocalidad localidades[], int tamLocalidades)
{
	int i;

	for (i=0; i<tamLocalidades; i++)
	{
		if (cliente.idLocalidad == localidades[i].id)
		{
			printf ("| %10d | %20s | %10s | %30s | %30s | \n", cliente.idCliente, cliente.empresa, cliente.cuit, cliente.direccion, localidades[i].descripcion);
		}
	}
}

/// @fn void ImprimirClientes(eCliente[], int, eLocalidad[], int) Imprime la lista de clientes con los datos: id Cliente, Empresa, Cuit, Direccion y Localidad
/// @param listado
/// @param tamListado
/// @param localidades
/// @param tamLocalidades
void ImprimirClientes (eCliente listado[], int tamListado, eLocalidad localidades[], int tamLocalidades)
{
	int i;

	printf ("--------------------------------------------------------------------------------------------------------------------\n");
	printf ("| %10s | %20s |  %10s | %30s | %30s|\n","idCliente", "Empresa", "Cuit", "Dirección", "Localidad");
	printf ("--------------------------------------------------------------------------------------------------------------------\n");

	for (i=0; i<tamListado; i++)
	{
		if (listado[i].estado == 1)
		{
			ImprimirUnCliente(listado[i], localidades, tamLocalidades);
		}
	}
	printf ("--------------------------------------------------------------------------------------------------------------------\n");

}

/// @fn void MostrarLocalidades(eLocalidad[], int) Imprime la lista de localidades
/// @param listado
/// @param tamListado
void MostrarLocalidades (eLocalidad listado[], int tamListado)
{
	int i;

	printf ("-----------------------------------\n");
	printf ("| %13s | %15s |\n", "Id Localidad", "Localidad");
	printf ("-----------------------------------\n");

	for (i=0; i<tamListado; i++)
	{
		printf ("| %13d | %15s |\n", listado[i].id, listado[i].descripcion);
	}

	printf ("-----------------------------------\n");


}

/// @fn void ImprimirChoferes(eChofer[], int) Imprime la lista de choferes
/// @param listado
/// @param tamListado
void ImprimirChoferes (eChofer listado[], int tamListado)
{
	int i;

	printf ("---------------------------------------------------------------------\n");
	printf ("| %20s | %20s | %20s |\n", "Id Chofer", "Nombre", "Hora de entrada");
	printf ("---------------------------------------------------------------------\n");
	for (i=0; i<tamListado; i++)
	{
		printf ("| %20d | %20s | %20f |\n", listado[i].id, listado[i].nombre, listado[i].horaDeEntrada);
	}
	printf ("---------------------------------------------------------------------\n");
}

/// @fn void ImprimirPedidosPendientesConId(eCliente[], int, ePedido[], int) Imprime los pedidos que están en estado pendiente, mostrando su id, el cuit y la direccion del cliente y los kilos del pedido
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
void ImprimirPedidosPendientesConId (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2)
{
	int i;
	int j;

	printf ("--------------------------------------------------------------------------------------------\n");
	printf ("| %20s | %20s | %20s | %20s |\n", "Id Pedido", "Cuit", "Dirección", "Kilos Pedido");
	printf ("--------------------------------------------------------------------------------------------\n");
	for (i=0; i<tamListado2; i++)
	{
		for (j=0; j<tamListado; j++)
		{
			if (strcmp (listado2[i].estado, "Pendiente") == 0 && listado2[i].idCliente == listado[j].idCliente)
			{
				printf ("| %20d | %20s | %20s | %20.2f |\n", listado2[i].idPedido, listado[j].cuit, listado[j].direccion, listado2[i].kilosPedido);
				break;
			}
		}
	}
	printf ("--------------------------------------------------------------------------------------------\n");

}
