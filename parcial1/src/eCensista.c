/*
 * eCensista.c
 *
 *  Created on: 25 may. 2022
 *      Author: lapir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "laibrery.h"
#include "eVivienda.h"
#include "eCensista.h"



int imprimirCensistas(eCensista* array,int len )
{
	int retorno = -1;
	if (array != NULL && len >0 )
		{


			printf("\n 				  **LISTADO CENSISTAS** \n");
			printf("------------------------------------------------------------------------------\n");
			printf(" LEGAJO     NOMBRE		  EDAD		 TELEFONO			 ");


			for (int i =0; i<len; i++)
			{


				imprimirUnCensista(array[i]);
			}

			printf("------------------------------------------------------------------------------\n");

			retorno = 0;
		}
	return retorno;
}

void imprimirUnCensista(eCensista censista)
{


	printf("\n %d 		%s  		%d 		 %s   \n",
			censista.legajoCensista,censista.nombre,censista.edad,censista.telefono);

}
