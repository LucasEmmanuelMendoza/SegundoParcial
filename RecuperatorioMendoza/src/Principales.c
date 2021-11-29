#include "Principales.h"

/// @fn void PedirDatosCliente(eCliente[], int, char[], char[], char[], int*, int[], eLocalidad[], int) Pide los datos para generar un nuevo cliente
/// @param listado
/// @param tam
/// @param empresa
/// @param cuitEmpresa
/// @param direccionEmpresa
/// @param localidadEmpresa
/// @param listaIdBajas
/// @param listado2
/// @param tam2
void PedirDatosCliente (eCliente listado[], int tam, char empresa[], char cuitEmpresa[], char direccionEmpresa[], int* localidadEmpresa, int listaIdBajas[], eLocalidad listado2[], int tam2)
{
	PedirCuit (cuitEmpresa);

	PedirCadena ("Ingrese el nombre de la empresa: \n", empresa);
	ArregloNombrePropio (empresa);

	PedirCadena ("Ingrese la dirección: \n", direccionEmpresa);
	ArregloNombrePropio (direccionEmpresa);

	MostrarLocalidades (listado2, tam2);
	*localidadEmpresa = PedirEntero ("Ingrese el id de la localidad: \n", 1, tam2);
}

//1
/// @fn int AltaCliente(eCliente[], int, int, char[], char[], char[], int) Ingresa los datos obtenidos en PedirDatosCliente en una posición del array de clientes que esté vacía
/// @param listado
/// @param tamListado
/// @param id
/// @param empresa
/// @param cuit
/// @param direccion
/// @param localidad
/// @return
int AltaCliente (eCliente listado[], int tamListado, int id, char empresa[], char cuit[], char direccion[], int localidad)
{
	int i;
	int retorno;
	retorno = 0;

	for (i=0; i<tamListado; i++)
	{
		if (listado[i].estado == 0)
		{
			listado[i].idCliente = id;
			strcpy (listado[i].cuit, cuit);
			strcpy (listado[i].empresa, empresa);
			strcpy (listado[i].direccion, direccion);
			listado[i].idLocalidad = localidad;
			listado[i].estado = 1;

			printf ("ID Cliente: %d", listado[i].idCliente);

			break;
		}
	}

	return retorno;
}

int ModificarDatos (eCliente listado[], int tamListado, eLocalidad listado2[], int tamListado2)
{
	int idMod;
	int opcion;
	int retorno;
	int posClienteMod;
	char direccionMod[30];
	int idLocalidadPedida;

	retorno = 0;

	idMod = PedirEntero ("\nIngrese su id: \n", 1, TAMCLIENTES);

	opcion = PedirEntero ("Ingrese una opción para modificar: 1) Dirección - 2) Localidad ", 1, 2);
	posClienteMod = BuscarPosCliente (listado, tamListado, idMod);

	switch (opcion)
	{
	case 1:
		PedirCadena ("Ingrese la nueva direccion: \n", direccionMod);
		strcpy (listado[posClienteMod].direccion, direccionMod);
		retorno = 1;
		break;

	case 2:
		MostrarLocalidades (listado2, tamListado2);

		idLocalidadPedida = PedirEntero ("Ingrese el id de la nueva localidad: \n", 1, tamListado2);

		listado[posClienteMod].idLocalidad = idLocalidadPedida;

		retorno = 1;
		break;
	}
	return retorno;
}

/// @fn int BajaCliente(eCliente[], int, ePedido[], int) Pide el id para dar de baja un cliente y lo elimina de la lista, cambiando su estado a 0 y eliminando también todos sus pedidos
/// @param listado
/// @param tamListado
/// @param pedidos
/// @param tamPedidos
/// @return
int BajaCliente (eCliente listado[], int tamListado, ePedido pedidos[], int tamPedidos)
{
	int retorno;
	int retornoPos;
	int idADarDeBaja;
	int i;

	retorno = 0;

	idADarDeBaja = PedirEntero ("\nIngrese el id del cliente a dar de baja: \n", 1, tamListado);

	retornoPos = BuscarPosCliente (listado, tamListado, idADarDeBaja);

	listado[retornoPos].estado = 0;

	for (i=0; i<tamPedidos; i++)
	{
		if (pedidos[i].idCliente == idADarDeBaja)
		{
			pedidos[i].isEmpty = 1;
			retorno = 1;
		}
	}

	return retorno;
}

/// @fn int PedirDatosDelPedido(ePedido[], int, int, int*, float*, int*, eChofer[], int) Pide los datos para generar un nuevo pedido
/// @param listado
/// @param tamListado
/// @param tamListaBajas2
/// @param idCliente
/// @param kilosPedido
/// @param idChofer
/// @param choferes
/// @param tamChoferes
/// @return
int PedirDatosDelPedido (ePedido listado[], int tamListado, int tamListaBajas2, int* idCliente, float* kilosPedido, int* idChofer, eChofer choferes[], int tamChoferes)
{
	*idCliente = PedirEntero ("\nIngrese el id de un cliente: \n", 0 , 200);

	*kilosPedido = PedirFlotante ("Ingrese la cantidad de kilos de residuos que se recolectaran del cliente: \n");

	ImprimirChoferes (choferes, tamChoferes);

	*idChofer = PedirEntero ("Ingrese el id del chofer que recolectará el pedido: \n", 0, tamChoferes);

	return 0;
}

/// @fn int AddPedido(ePedido[], int, int, float, int, int) Agrega los datos pasados como parámetro al espacio de un array de pedidos que esté vacío
/// @param listado
/// @param tamListado
/// @param idPedido
/// @param kilosPorPedido
/// @param idCliente
/// @param Chofer
/// @return
int AddPedido (ePedido listado[], int tamListado, int idPedido, float kilosPorPedido, int idCliente, int Chofer)
{
	int i;
	int retorno;

	retorno = 0;

	for (i=0; i<tamListado; i++)
	{
		if (listado[i].isEmpty == 1)
		{
			listado[i].idCliente = idCliente;
			listado[i].idPedido = idPedido;
			listado[i].kilosPedido = kilosPorPedido;
			listado[i].idChofer = Chofer;
			strcpy (listado[i].estado,"Pendiente");
			listado[i].isEmpty = 0;
			break;
			retorno = 1;
		}
	}

	printf ("%d", listado[i].idPedido);

	return retorno;

}

/// @fn void ProcesarResiduos(ePedido[], int) Pide el id de un pedido pendiente para ingresar la cantidad de cada tipo de residuo que se va a procesar
///
/// @param listado
/// @param tamListado
void ProcesarResiduos (ePedido listado[], int tamListado)
{
	int idSeleccionado;
	int pos;
	float sumaTotalTipos;

	idSeleccionado = PedirEntero ("Ingrese el id del pedido: \n", 1, TAMPEDIDOS+1);

	pos = BuscarPosPedido (listado, tamListado, idSeleccionado);


	printf ("%f\n", listado[pos].kilosPedido);

	do{
		((listado[pos]).cantidadPorTipo)[1] = PedirFlotante ("Ingrese la cantidad de residuo de HDPE:  ");
		((listado[pos]).cantidadPorTipo)[2] = PedirFlotante ("\nIngrese la cantidad de residuo de LDPE: ");
		((listado[pos]).cantidadPorTipo)[3] = PedirFlotante ("\nIngrese la cantidad de residuo de PP: ");

		sumaTotalTipos = ((listado[pos]).cantidadPorTipo)[1] + ((listado[pos]).cantidadPorTipo)[2] + ((listado[pos]).cantidadPorTipo)[3];

	}while(sumaTotalTipos > listado[pos].kilosPedido);

	printf ("Id Cliente: %d", listado[pos].idCliente);

	strcpy (listado[pos].estado, "Completado");
}

/// @fn void ImprimirClientesPendientes(eCliente[], int, ePedido[], int, eLocalidad[], int) Imprime una lista de clientes con sus datos y la cantida de pedidos pendientes que tiene
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
/// @param listado3
/// @param tamLocalidades
void ImprimirClientesPendientes (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2, eLocalidad listado3[], int tamLocalidades)
{
	int i;
	int j;
	int cantPedidosPendientes;
	char localidad[30];

	printf ("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("| %10s | %20s |  %10s | %30s | %30s | %35s |\n","idCliente", "Empresa", "Cuit", "Dirección", "Localidad", "Cantidad de pedidos pendientes");
	printf ("|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	for (i=0; i<tamListado; i++)
	{
		if (listado[i].estado == 1)
		{
			cantPedidosPendientes = CalcularCantPedidosPendientes (listado2, tamListado2, listado[i].idCliente);

			for (j=0; j<tamLocalidades; j++)
			{
				if (listado[i].idLocalidad == listado3[j].id)
				{
					strcpy (localidad, listado3[j].descripcion);
				}
			}
			printf ("| %10d | %20s | %10s | %30s | %30s | %35d |\n", listado[i].idCliente, listado[i].empresa, listado[i].cuit, listado[i].direccion, localidad, cantPedidosPendientes);

		}

	}

	printf ("|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

}

/// @fn int CalcularCantPedidosPendientes(ePedido[], int, int) Calcula la cantidad de pedidos pendientes para un cliente, ingresando su id como parámetro
/// @param listado2
/// @param tamListado2
/// @param idCliente1
/// @return
int CalcularCantPedidosPendientes (ePedido listado2[], int tamListado2, int idCliente1)
{
	int j;
	int cantPendientes;

	cantPendientes = 0;

		for (j=0; j<tamListado2; j++)
		{
			if (listado2[j].isEmpty == 0 && (idCliente1 == listado2[j].idCliente ) && (strcmp (listado2[j].estado, "Pendiente") == 0))
			{
				cantPendientes = cantPendientes + 1;
			}
		}

	return cantPendientes;
}

///  @fn int ImprimirPedidosPendientes(eCliente[], int, ePedido[], int) Imprime una lista de los pedidos que están en estado "Pendiente" los datos: cuit y direccion del cliente y los kilos del pedido
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
/// @return
int ImprimirPedidosPendientes (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2)
{
	int retorno;
	int i;
	int j;

	retorno = 0;
	printf ("\n---------------------------------------------------------------------\n");
	printf ("| %20s | %20s | %20s |", "Cuit", "Dirección", "Kilos del Pedido");
	printf ("\n|--------------------------------------------------------------------|\n");

	for (i=0; i<tamListado2; i++)//pedidos
	{
		for (j=0; j<tamListado; j++)//clientes
		{
			if (strcmp (listado2[i].estado, "Pendiente") == 0 && listado2[i].idCliente == listado[j].idCliente)
			{
				printf ("| %20s | %20s | %20.2f |\n", listado[j].cuit, listado[j].direccion, listado2[i].kilosPedido);
				retorno = 1;
				break; //cuando encuentra los datos del cliente para ese pedido, rompe la búsqueda de los clientes y pasa al siguiente pedido
			}
		}
	}

	printf ("|--------------------------------------------------------------------|\n");

	return retorno;
}

//8
/// @fn void ImprimirPedidosProcesados(eCliente[], int, ePedido[], int) Imprime una lista de los pedidos procesados junto con la cantida de cada tipo de residuo procesado en cada uno
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
void ImprimirPedidosProcesados (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2)
{
	int i;
	int j;
	printf ("\n---------------------------------------------------------------------------------------------------------------------\n");
	printf ("| %20s | %20s | %20s | %20s | %20s |","Cuit Del Cliente", "Dirección del cliente", "Cantidad HDPE", "Cantidad LDPE", "Cantidad PP");
	printf ("\n|-------------------------------------------------------------------------------------------------------------------|\n");

	for (i=0; i<tamListado2; i++)
	{
		for(j=0; j<tamListado; j++)
		{
			if (listado[j].estado == 1)
			{
				if (strcmp (listado2[i].estado, "Completado") == 0)
				{
					if (listado2[i].idCliente == listado[j].idCliente)
					{
						printf ("| %20s |  %20s | %20.2f | %20.2f | %20.2f |\n", listado[j].cuit, listado[j].direccion, (((listado2[i]).cantidadPorTipo)[1]), (((listado2[i]).cantidadPorTipo)[2]), (((listado2[i]).cantidadPorTipo)[3]));
					}
				}
			}
		}
	}

	printf ("---------------------------------------------------------------------------------------------------------------------\n");

}

//9
/// @fn int CalcularPendientesLoc(eCliente[], int, ePedido[], int, eLocalidad[], int) Calcula cuantos pedidos pendientes hay para una localidad pedida
/// @param clientes
/// @param tamClientes
/// @param pedidos
/// @param tamPedidos
/// @param localidades
/// @param tamLocalidades
/// @return
int CalcularPendientesLoc (eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, eLocalidad localidades[], int tamLocalidades)
{
	int idLocalidadPedida;
	int cantPedidosPendientes;
	int i;
	int j;

	cantPedidosPendientes = 0;

	MostrarLocalidades (localidades, tamLocalidades);

	idLocalidadPedida = PedirEntero ("Ingrese la localidad: \n", 1, tamLocalidades);

	for (i=0; i<tamPedidos; i++)
	{
		for (j=0; j<tamClientes; j++)
		{
			if ((strcmp(pedidos[i].estado, "Pendiente") == 0) && (pedidos[i].idCliente == clientes[j].idCliente) && clientes[j].idLocalidad == idLocalidadPedida)
			{
				cantPedidosPendientes = cantPedidosPendientes +1;
				break;
			}
		}
	}

	return cantPedidosPendientes;
}

//10
/// @fn float PromedioPPRecicladoPorCliente(eCliente[], int, ePedido[], int) Calcula el promedio de residuo de polipropileno reciclado por cliente
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
/// @return
float PromedioPPRecicladoPorCliente (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2)
{
	float sumaTotalKilos;
	int cantidadClientes;
	float promedio;
	int i;

	sumaTotalKilos = 0;
	cantidadClientes = 0;

	for (i=0; i<tamListado2; i++)
	{
		sumaTotalKilos = sumaTotalKilos + ((((listado2[i]).cantidadPorTipo)[3]));
	}

	for (i=0; i<tamListado; i++)
	{
		if (listado[i].estado == 1)
		{
			cantidadClientes ++;
		}
	}

	promedio = (float) sumaTotalKilos / cantidadClientes;

	return promedio;
}

/// @fn int CalcularClienteConMasPedidos(ePedido[], int, eCliente[], int, eCliente*) calcula cual es el cliente con más pedidos y lo guarda en un puntero a cliente
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
/// @param clienteReturn
/// @return
int CalcularClienteConMasPedidos (ePedido listado[], int tamListado, eCliente listado2[], int tamListado2, eCliente* clienteReturn)
{
	int retorno;
	int i;

	int banderaPrimero;

	int maxCantPedidos;
	int cantPedidosPendientes;
	int cantPedidosCompletados;
	int cantPedidosTotalAux;
	int posCliente;

	retorno = 0;

	banderaPrimero = 1;

	printf ("Acaaaaa");

		for(i=1; i<tamListado; i++)
		{
			if (banderaPrimero == 1)
			{
				cantPedidosCompletados = CalcularCantPedidosPorFiltro(listado, tamListado, i, "Completado");
				cantPedidosPendientes = CalcularCantPedidosPorFiltro(listado, tamListado, i, "Pendiente");
				maxCantPedidos = cantPedidosCompletados + cantPedidosPendientes;
				posCliente = BuscarPosCliente(listado2, tamListado2, i);
				*clienteReturn = listado2[posCliente];
				banderaPrimero = 0;
			}
			else
			{
				cantPedidosCompletados = CalcularCantPedidosPorFiltro(listado, tamListado, i, "Completado");
				cantPedidosPendientes = CalcularCantPedidosPorFiltro(listado, tamListado, i, "Pendiente");
				cantPedidosTotalAux = cantPedidosCompletados + cantPedidosPendientes;

				if (cantPedidosTotalAux > maxCantPedidos)
				{
					maxCantPedidos = cantPedidosTotalAux;
					posCliente = BuscarPosCliente(listado2, tamListado2, i);
					*clienteReturn = listado2[posCliente];
				}
			}
			retorno = 1;
		}


	return retorno;
}

int CalcularCantPedidosPorFiltro (ePedido listado[], int tamListado, int idCliente, char filtro[])
{
	int j;
	int cantPedidosFiltro;

	cantPedidosFiltro = 0;

	for (j=0; j<tamListado; j++)
	{
		printf ("%s", listado[j].estado);

		if (listado[j].isEmpty == 0 && (idCliente == listado[j].idCliente) && (strcmp ((listado[j].estado), filtro) == 0))
		{
			cantPedidosFiltro = cantPedidosFiltro +1;
		}
	}

	return cantPedidosFiltro;
}

/// @fn int ClienteConMasPedidosPorFiltro(eCliente[], int, ePedido[], int, char[], eCliente*) Calcula cuál es el cliente con más pedidos segun un filtro de estado (Completado / Pendiente)
/// @param listado
/// @param tamListado
/// @param listado2
/// @param tamListado2
/// @param filtro1
/// @param clienteReturn
/// @return
int ClienteConMasPedidosPorFiltro (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2, char filtro1[], eCliente* clienteReturn)
{
	int retorno;
	int i;
	int primerCliente;
	int maxCantidadFiltro;
	int cantFiltro;
	int posCliente;

	retorno = 0;
	primerCliente = 1;


		for (i=1; i<tamListado+1; i++)
		{
			if (primerCliente == 1)
			{
				maxCantidadFiltro = CalcularCantPedidosPorFiltro (listado2, tamListado, i, filtro1);
				posCliente = BuscarPosCliente (listado, tamListado, i);
				*clienteReturn = listado [posCliente];
				primerCliente = 0;
			}
			else
			{
				cantFiltro = CalcularCantPedidosPorFiltro(listado2, tamListado, i, filtro1);

				if (cantFiltro > maxCantidadFiltro)
				{
					maxCantidadFiltro = cantFiltro = CalcularCantPedidosPorFiltro(listado2, tamListado, i, filtro1);
					posCliente = BuscarPosCliente (listado, tamListado, i);
					*clienteReturn  = listado[posCliente];
				}
			}
			retorno = 1;
		}


	return retorno;
}


//14
/// @fn int MostrarPedidosCompletadosLuegoDeUnaHora(ePedido[], int, eCliente[], int, eChofer[], int, float) Imprime una lista de los productos completados que fueron recolectados por clientes
/// que ingresaron a trabajar luego de una hora (filtroHora)
/// @param pedidos
/// @param tamPedidos
/// @param clientes
/// @param tamClientes
/// @param choferes
/// @param tamChoferes
/// @param filtroHora
/// @return
/*
int MostrarPedidosCompletadosLuegoDeUnaHora (ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eChofer choferes[], int tamChoferes, float filtroHora)
{
	int retorno;
		int i;
		int j;
		int k;

		retorno = 0;

		printf ("\n---------------------------------------------------------------------------\n");
		printf ("| %10s | %15s | %20s | %20s |", "Id Pedido", "Cuit Cliente", "Dirección", "Kilos Pedido |\n");
		printf ("\n---------------------------------------------------------------------------\n");
		for (i=0; i<tamChoferes; i++)
		{
			if (choferes [i].horaDeEntrada > filtroHora)
			{
				for (j=0; j<tamPedidos; j++)
				{
					for (k=0; k<tamClientes; k++)
					{
						if (pedidos[j].idCliente == clientes[k].idCliente && pedidos[j].isEmpty == 0 && clientes[k].estado == 1 && choferes[i].id == pedidos[j].idChofer && strcmp(pedidos[j].estado, "Completado")==0)
						{
							printf ("| %10d | %15s | %20s | %20.2f |\n", pedidos[j].idPedido, clientes[k].cuit, clientes[k].direccion, pedidos[j].kilosPedido);
						}
					}
				}
			}
		}

		printf ("\n---------------------------------------------------------------------------\n");

		return retorno;
}*/

int MostrarPedidosCompletadosLuegoDeUnaHora (ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes, eChofer choferes[], int tamChoferes, float filtroHora)
{
	int retorno;
	int i;
	int j;
	int k;

	retorno = 0;

	printf ("| %10s | %15s | %20s | %13s |", "Id Pedido", "Cuit Cliente", "Dirección", "Kilos Pedido\n");

	for (i=0; i<tamChoferes; i++)
	{
		for (j=0; j<tamPedidos; j++)
		{
			for (k=0; k<tamClientes; k++)
			{
				if (pedidos[j].idCliente == clientes[k].idCliente && pedidos[j].isEmpty == 0 && clientes[k].estado == 1 && choferes[i].id == pedidos[j].idChofer && strcmp(pedidos[j].estado, "Completado")==0 && choferes [i].horaDeEntrada > filtroHora)
				{
					printf ("| %10d | %15s | %20s | %13f |\n", pedidos[j].idPedido, clientes[k].cuit, clientes[k].direccion, pedidos[j].kilosPedido);
					break;
				}
			}
		}
	}

	return retorno;
}

