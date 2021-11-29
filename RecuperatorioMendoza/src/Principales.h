/*
 * Principales.h
 *
 *  Created on: 27 nov. 2021
 *      Author: lukit
 */

#ifndef PRINCIPALES_H_
#define PRINCIPALES_H_
#define TAMCLIENTES 200
#define TAMPEDIDOS 1000
#define TAMLOCALIDADES 8
#define TAMCHOFERES 5

#include "Mostrar.h"
//#include "Mostrar.h"


/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> */


void PedirDatosCliente (eCliente listado[], int tam, char empresa[], char cuitEmpresa[], char direccionEmpresa[], int* localidadEmpresa, int listaIdBajas[], eLocalidad listado2[], int tam2);
int AltaCliente (eCliente listado[], int tamListado, int id, char empresa[], char cuit[], char direccion[], int localidad);
int ModificarDatos (eCliente listado[], int tamListado, eLocalidad listado2[], int tamListado2);
int BajaCliente (eCliente listado[], int tamListado, ePedido pedidos[], int tamPedidos);
int PedirDatosDelPedido (ePedido listado[], int tamListado, int tamListaBajas2, int* idCliente, float* kilosPedido, int* idChofer, eChofer choferes[], int tamChoferes);
int AddPedido (ePedido listado[], int tamListado, int idPedido, float kilosPorPedido, int idCliente, int Chofer);
void ProcesarResiduos (ePedido listado[], int tamListado);
void ImprimirClientesPendientes (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2, eLocalidad listado3[], int tamLocalidades);
int CalcularCantPedidosPendientes (ePedido listado2[], int tamListado2, int idCliente1);
int ImprimirPedidosPendientes (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2);
void ImprimirPedidosProcesados (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2);
int CalcularPendientesLoc (eCliente clientes[], int tamClientes, ePedido pedidos[], int tamPedidos, eLocalidad localidades[], int tamLocalidades);
float PromedioPPRecicladoPorCliente (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2);
int CalcularClienteConMasPedidos (ePedido listado[], int tamListado, eCliente listado2[], int tamListado2, eCliente* clienteReturn);
int CalcularCantPedidosPorFiltro (ePedido listado[], int tamListado, int idCliente, char filtro[]);
int ClienteConMasPedidosPorFiltro (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2, char filtro1[],eCliente* clienteReturn);
int MostrarPedidosCompletadosLuegoDeUnaHora (ePedido listado1[], int tamListado1, eCliente listado2[], int tamListado2, eChofer listado3[], int tamListado3, float filtroHora);


#endif /* PRINCIPALES_H_ */
