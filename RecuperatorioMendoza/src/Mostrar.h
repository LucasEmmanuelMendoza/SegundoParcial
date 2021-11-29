/*
 * Mostrar.h
 *
 *  Created on: 27 nov. 2021
 *      Author: lukit
 */

#ifndef MOSTRAR_H_
#define MOSTRAR_H_

//#include "PedirDatos.h"
#include "Index.h"

void ImprimirPedidosPendientesConId (eCliente listado[], int tamListado, ePedido listado2[], int tamListado2);
void ImprimirChoferes (eChofer listado[], int tamListado);
void MostrarLocalidades (eLocalidad listado[], int tamListado);
void ImprimirClientes (eCliente listado[], int tamListado, eLocalidad localidades[], int tamLocalidades);
void ImprimirUnCliente (eCliente cliente, eLocalidad localidades[], int tamLocalidades);
void ImprimirPedidos (ePedido listado[], int tamListado);
void ImprimirUnPedido (ePedido pedido);


#endif /* MOSTRAR_H_ */
