#include "PedirDatos.h"
#include "index.h"
/*#include <string.h>
#include <stdio.h>
#include <stdlib.h> */

int PedirEntero (char mensaje[], int min, int max)
{
	int i;
	int retorno;
	char numero[15];
	int tam;
	int numeroAux;

	retorno = 1;

	do {
		printf ("%s", mensaje);
		scanf ("%s", numero);
		tam = strlen (numero);

			for (i=0; i<tam; i++)
			{
				if (isdigit(numero[i]) == 0 /* || isalpha (numero[i] == 1)*/)
				{
					printf ("Error!!!\n");
					printf ("%s", mensaje);
					scanf ("%s", numero);
					tam = strlen (numero);
					i=0;
				}
			}

			numeroAux = atoi (numero);

	}while (numeroAux < min || numeroAux > max);

	retorno = numeroAux;

	return retorno;
}

float PedirFlotante (char mensaje[])
{
	float retorno;

	printf ("%s", mensaje);
	scanf ("%f", &retorno);

	return retorno;
}

/*
float PedirFlotante (char mensaje[])
{
	char numero1[6];
	float retorno;
	//int tam;
	int i;

	printf ("%s", mensaje);
	scanf ("%s", numero1);
	//tam = strlen (numero1);

	for (i=0; i<6; i++)
	{
		if (numero1[i]!=46 && (isdigit (numero1[i]) == 0 || isalpha (numero1[i])==1))
		{
			printf ("Ingrese un número flotante!\n");
			printf ("%s", mensaje);
			scanf ("%s", numero1);
			i=0;
		}
	}

	retorno = atof (numero1);

	return retorno;
}*/

int PedirCuit (char cuitPedido[])
{
	int retorno;

	retorno = 0;

	do {
		PedirCadena ("Ingrese su número de cuit sin guiones, por ejemplo, \"11312341871\": \n", cuitPedido);
		retorno = 1;
	}while (strlen(cuitPedido)!=11);

	return retorno;
}


int PedirCadena (char mensaje[], char cadena[])
{
	int retorno;
	int retorno2;
	/* int tam;
	int i;*/
	retorno = 0;


	do{
		printf ("%s", mensaje);
		fflush (stdin);
		gets (cadena);
		retorno2 = SonLetras (cadena, strlen(cadena));

		retorno = 1;

	}while (retorno2 == -1);

	ArregloNombrePropio (cadena);
	//printf ("%s", cadena);
	/*
	printf ("Cadena: %s", cadena);

	tam = strlen (cadena);

		for (i=0; i<tam; i++)
		{
			if (cadena[i] != 32 && (isalpha(cadena[i]) != 0 || isdigit(cadena[i]) != 0)) //32 = código ASCII del espacio //si lo que ingresó el usuario no es ni letra ni número
			{
				printf ("Error!!!");
				printf ("%s", mensaje);
				fflush (stdin);
				gets (cadena);

				i = 0; //reinicio el índice para que vuelva a empezar por el primer lugar al recibir una nueva cadena
			}
		}
	 */

	return retorno;
}

int SonLetras (char cadena[], int rango)
{
	int i;
	int retorno;

	retorno = -1;

	if (cadena != NULL && rango >0)
	{
		retorno = 0;

		for (i=0; cadena[i] != '\0'; i++)
		{
			if (!( (cadena[i]>= 'a' && cadena[i] <'z') || (cadena [i] >= 'A' && cadena [i] <= 'Z') || cadena [i] == 32 ))
			{
				retorno = -2;
				break;
			}
		}
	}

	return retorno;
}
