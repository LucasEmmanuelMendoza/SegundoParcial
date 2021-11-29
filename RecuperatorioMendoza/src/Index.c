#include "Index.h"

/// @fn int BuscarPosCliente(eCliente[], int, int) devuelve la posición del cliente en el array, recibiendo como parámetro su id
/// @param listado
/// @param tamListado
/// @param id
/// @return
int BuscarPosCliente (eCliente listado[], int tamListado, int id) //retorna la posición del empleado a buscar
{
	int retorno;
	int i;

	retorno = -1;

	for (i=0; i<tamListado; i++)
	{
		if (tamListado > 0 && listado != NULL && listado[i].idCliente == id)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

/// @fn int BuscarPosPedido(ePedido[], int, int) retorna la posición de un pedido en el array de pedidos, recibiéndo comoparámetro su id
/// @param listado
/// @param tamListado
/// @param id
/// @return
int BuscarPosPedido (ePedido listado[], int tamListado, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for (i=0; i<tamListado; i++)
	{
		if (listado[i].idPedido == id)
		{
			retorno = i;
			break;
		}
	}

	return retorno;
}

void ArregloNombrePropio (char cadena1[])
{
	int tam;
	tam = strlen (cadena1);
	int i;

	strlwr (cadena1);

	for (i=0; i<tam; i ++)
	{
		if (i== 0 || cadena1[i-1] == 32)
		{
			cadena1[i] = toupper (cadena1[i]);
		}
	}
}

/// @fn void InicializarArray(eCliente[], int) Inicializa los clientes del array
/// @param listado
/// @param tamListado
void InicializarArray (eCliente listado[], int tamListado)
{
	int i;

	for (i=0; i<tamListado; i++)
	{
		listado[i].idCliente = 0;
		listado[i].estado = 0;
	}
}

/// @fn void InicializarPedidos(ePedido[], int) Inicializa los pedidos
/// @param listado
/// @param tamListado
void InicializarPedidos (ePedido listado[], int tamListado)
{
	int i;

	for (i=0; i<tamListado; i++)
	{
		listado[i].isEmpty = 1;
		strcpy (listado[i].estado, "Vacío");

	}
}

/// @fn void Inicializar(int[], int) Inicializa un listado de enteros en 0
/// @param listado
/// @param len
void Inicializar (int listado[], int len)
{
	int i;

	for (i=0; i<len; i++)
	{
		listado[i] = 0;
	}
}

