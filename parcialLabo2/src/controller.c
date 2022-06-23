/*
 * controller.c
 *
 *  Created on: 23 jun. 2022
 *      Author: lapir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"
#include "servicios.h"
#include "parser.h"
#include "laibrery.h"
#include "controller.h"


/*
static int controller_printPassenger (Passenger* pPassenger);

static int controller_ListPassengerStatic(LinkedList* pArrayListPassenger);
static int controller_getMaximoId(LinkedList* pArrayListPassenger);
static int controller_ValidarId (LinkedList* pArrayListPassenger, int id);
*/
static int controller_printServicio(eServicios* pServicio);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicios)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListServicios != NULL && path != NULL)
	{
		pFile = fopen (path, "r");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if(parser_ServiciosFromText(pFile, pArrayListServicios))
			{
				printf("\n archivo cargado \n");
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListServicios)
{
	eServicios*  pAuxServicio = NULL;
	int retorno = 0;
	int tamanio;

	if (pArrayListServicios != NULL)
	{

		tamanio = ll_len(pArrayListServicios);//pido tamanio linkelist

		printf("\n 				              **LISTADO SERVICIO** \n");
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID SERVICIO	 	DESCRIPCION		 TIPO		 PRECIO/UNITARIO		CANTIDAD	TOTAL SERVICIO");
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{
			pAuxServicio = (eServicios*)ll_get(pArrayListServicios,i);//obtengo puntero

			if(pAuxServicio != NULL)
			{
				controller_printServicio(pAuxServicio);
			}
		}
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 1;
	}
    return retorno;
}

static int controller_printServicio (eServicios* pServicio)
{
	int retorno = 0;
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;

	if (pServicio != NULL &&
		Servicios_getId(pServicio,&id) &&
		Servicios_getDescripcion(pServicio,descripcion)&&
		Servicios_getTipo(pServicio,&tipo)&&
		Servicios_getPrecio(pServicio,&precio)&&
		Servicios_getCantidad(pServicio,&cantidad)&&
		Servicios_getTotal(pServicio,&total))
	{
		printf("\n	%d	 	%-10s	 	 %-10d		  %.2f	 		%d	 	%.2f             \n",
					id,     descripcion,       tipo,      precio,     cantidad,     total);
		retorno = 1;
	}
	return retorno;
}




/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_sortPassenger(LinkedList* pArrayListServicios)
{
	int retorno =0;
	int i;
	int flagSwap;
	int limite;
	char bufferDescripcion[LENDESCRIPCION];
	char bufferSigDescripcion[LENDESCRIPCION];

	eServicios* pAuxServicio=NULL;
	eServicios* pAuxSigServicio=NULL;


//printf("\n previo a validar");
	if(pArrayListServicios != NULL)
	{
		//printf("\n despues de validar");
		retorno = 1;
		limite = ll_len(pArrayListServicios);
	//	printf("\n limite: %d",limite);
		do
		{
			flagSwap = 0;

			for(i=0;i<limite-1;i++)
			{
				for(int j=i+1;j<limite;j++)
				{
					pAuxServicio = ll_get(pArrayListServicios,i);
					pAuxSigServicio = ll_get(pArrayListServicios,j);

					if(pAuxServicio != NULL && pAuxSigServicio  != NULL)
					{
						//printf("\n ambos punteros difernetes de NULL");
						Servicios_getDescripcion(pAuxServicio,bufferDescripcion);
						Servicios_getDescripcion(pAuxSigServicio,bufferSigDescripcion);

						if(strncmp(bufferDescripcion,bufferSigDescripcion,LENDESCRIPCION) < 0)
						{
							ll_set(pArrayListServicios, i, pAuxSigServicio);
							ll_set(pArrayListServicios, j, pAuxServicio);
							flagSwap=1;
						}
						else if(strncmp(bufferDescripcion,bufferSigDescripcion,LENDESCRIPCION) == 0)
						{
							continue;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicios)
{
	int retorno = 0;
	int id;
	char descripcion[LENDESCRIPCION];
	int tipo;
	float precio;
	int cantidad;
	float total;
	eServicios*  pAuxServicio;
	FILE* pFile;

	if (path != NULL && pArrayListServicios != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListServicios);i++ )
		{
			pAuxServicio = ll_get(pArrayListServicios,i);
			if (pAuxServicio != NULL &&
				Servicios_getId(pAuxServicio,&id) &&
				Servicios_getDescripcion(pAuxServicio,descripcion)&&
				Servicios_getTipo(pAuxServicio,&tipo)&&
				Servicios_getPrecio(pAuxServicio,&precio)&&
				Servicios_getCantidad(pAuxServicio,&cantidad)&&
				Servicios_getTotal(pAuxServicio,&total))

			{
				//ESCRIBO E ARCHIVO
				fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",id,descripcion,tipo,precio,cantidad,total);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	eServicios*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListPassenger);i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL)
			{
				fwrite(pAuxPassenger, sizeof(eServicios),1,pFile);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}


int controller_Map (LinkedList* listaServicios)
{
	if (listaServicios != NULL)
	{
		ll_map(listaServicios, calcular);
		printf("\n**Los totales se asignaron correctamente**\n");
	}
	return 1;
}
void calcular(void* pElemento)//int calcular(void* pResultado, void(*pHacer)(int, float,float*))
{
	int cantidad;
	float precio;
	float total;

	if (pElemento != NULL)
	{
		Servicios_getCantidad(pElemento,&cantidad);
		Servicios_getPrecio(pElemento,&precio);
		total = multiplicar(cantidad,precio);
		Servicios_setTotal(pElemento,total);
	}
}
float multiplicar (int cantidad, float precio)
{
	float total;

	total = cantidad*precio;

	return total;
}



