/*
 * parser.c
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
#include "laibrery.h"
#include "parser.h"
#include "controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServiciosFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int retorno = 0;
	int cant;
	char id[50], descripcion[50], tipo[50], precioUnitario[50], cantidad[50], totalServicio[50];
	eServicios* pAuxServicio;

	if (pFile == NULL)
	{
		printf("Error al escanear el archivo.");
		retorno = 0;
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("\n** CARGA DE ARCHIVO EN PROCESO **\n");

		// LECTURA FANTASMA 	- 1   -2    -3    -4   -5   -6
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
			if (cant < 6)
			{
				printf("Error al leer el archivo.");
				break;
			}
			pAuxServicio = Servicios_newParametros(id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
			if(pAuxServicio != NULL)
			{
				ll_add(pArrayListServicios,pAuxServicio);
				printf("\nArchivo cargado con exito! ");
				retorno = 1;
			}
		}
	}
    return retorno;
}
