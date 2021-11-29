#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idCliente;
	char empresa[50];
	char cuit[13];
	char direccion[50];
	int idLocalidad;
	int estado;
}eCliente;

typedef struct{
	int idCliente;
	int idPedido;
	float kilosPedido;
	int isEmpty;
	char estado[15];
	float cantidadPorTipo[3];
	int idChofer;
}ePedido;

typedef struct{
	int id;
	char descripcion[30];
}eLocalidad;

typedef struct{
	int id;
	char nombre[30];
	float horaDeEntrada;
}eChofer;

/*Original:  typedef struct{
	int idCliente;
	char empresa[50];
	char cuit[13];
	char direccion[50];
	int idLocalidad;
	int estado;
}eCliente;

typedef struct{
	int idCliente;
	int idPedido;
	float kilosPedido;
	int isEmpty;
	char estado[15];
	float cantidadPorTipo[3];
	int idChofer;
}ePedido;

typedef struct{
	int id;
	char descripcion[30];
}eLocalidad;

typedef struct{
	int id;
	char nombre[30];
	float horaDeEntrada;
}eChofer;*/


int PedirEntero (char mensaje[], int min, int max);
int PedirCuit (char cuitPedido[]);
int PedirCadena (char mensaje[], char cadena[]);
float PedirFlotante (char mensaje[]);
int SonLetras (char cadena[], int rango);


#endif /* PEDIRDATOS_H_ */
