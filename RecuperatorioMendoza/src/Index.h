#include "PedirDatos.h"

#ifndef INDEX_H_
#define INDEX_H_

int BuscarPosCliente (eCliente listado[], int tamListado, int id);
int BuscarPosPedido (ePedido listado[], int tamListado, int id);
void ArregloNombrePropio (char cadena1[]);
void InicializarArray (eCliente listado[], int tamListado);
void InicializarPedidos (ePedido listado[], int tamListado);
void Inicializar (int listado[], int len);

#endif /* INDEX_H_ */
