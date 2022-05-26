/*
 * eVivienda.c
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

#define LENCALLE 25
#define MINLEGAJO 100
#define MAXLEGAJO 102

int inicializacionViviendas(eVivienda* array, int len) // inicializar una array de estructuira en 1 // 1 LIBRE // 0 Ocupado
{
	int retorno = -1;
	int i;

		if(array != NULL && len > 0)
		{
		  for (i = 0; i < len ; i++)
		  {
			  array[i].isEmpty = 1;
		  }
		  retorno = 0;
		}
	  return retorno;
}

int alta(eVivienda* aViviendas,eCensista* aCensistas,int lenCensistas, int indice, int* id) ////int addPassengers(Passenger* array,int len, int indice, int* id);
{
	int retorno = -1;
	eVivienda bufferVivienda;
//	eCensista bufferCensista[3]={{100,"Ana" , 34, "1203-2345"}, {101,"Juan", 24, "4301-54678"}, {102, "Sol", 47, "4301-54678"}};
	if (aViviendas != NULL && aCensistas != NULL && lenCensistas >0 && indice >=0 && id != NULL)
	{
			//veridico que los campos a completar, esten bien completados
		if (
				utn_getNombre(bufferVivienda.calle,LENCALLE,"\n ingrese el nombre de la calle","\n error",2)==0 &&
				utn_getNumero(&bufferVivienda.cantidadPersonas,"\n ingrese la cantidad de personas del domicilio","\n error",1,50,2)==0&&
				utn_getNumero(&bufferVivienda.cantidadHabitaciones,"\n ingrese la cantidad de habitaciones","\n error",1,15,2)==0&&
				utn_getNumero(&bufferVivienda.idTipoVivienda,"\n ingrese el tipo de vivienda: \n 1- CASSA \n 2- DEPARTAMENTO "
						" \n 3- CASILLA \n 4-RANCHO ","\n error",1,4,2)==0 &&
				imprimirCensistas(aCensistas,lenCensistas)==0 &&
				utn_getNumero(&bufferVivienda.legajoCensista,"\n ingrese el legajon del Censista","\n error",MINLEGAJO,MAXLEGAJO,2)==0
			)

			{
	//getAlfanumerico

				bufferVivienda.idVivienda = *id;
				bufferVivienda.isEmpty = 0;
				aViviendas[indice] = bufferVivienda;
				*id = *id + 1 ;

				retorno =0;
			}
	}

	return retorno;
}

int buscarLugarLibre(eVivienda* array, int len, int* lugarLibre)
{
	int i;
	int retorno  = -1;

	if (len > 0 && array!= NULL && lugarLibre != NULL){

		for (i = 0;i<len; i++)
		{
			if (array[i].isEmpty == 1)
			{

				*lugarLibre = i;

				retorno = 0;
			}
		}
	}

	return retorno;
}


int imprimirViviendas(eVivienda* array,int len)
{
	int retorno = -1;
		if (array != NULL && len >0)
		{


			printf("\n 				  **LISTADO EMPLEADOS** \n");
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("ID VIVIENDA	 	CALLE		 CANT. PERSONAS		 CANT. HABITACIONES		 TIPO VIVIENDA		 ");

			for (int i = 0;i<len ;i++)
			{
				if(array[i].isEmpty == 0)
				{

					imprimirUnaVivienda(array[i]);
				}
			}

			printf("------------------------------------------------------------------------------------------------------------------\n");

			retorno = 0;
		}
	return retorno;
}
/*
int imprimir(aImprimir* array,int len,*funcTitulos, *funcImprinirUna )
{
	int retorno = -1;
		if (array != NULL && len >0)
		{


			funcTitulos();

			for (int i = 0;i<len ;i++)
			{
				if(array[i].isEmpty == 0)
				{

					funcImprinirUna(array[i]);
				}
			}

			printf("------------------------------------------------------------------------------------------------------------------\n");

			retorno = 0;
		}
	return retorno;
}

imprimir(aViviendas, 10, &imprimirTitulosViviendas, &imprimirUnaVivienda)

void imprimirTitulosViviendas(){

	printf("\n 				  **LISTADO EMPLEADOS** \n");
	printf("------------------------------------------------------------------------------------------------------------------\n");
	printf("ID VIVIENDA	 	CALLE		 CANT. PERSONAS		 CANT. HABITACIONES		 TIPO VIVIENDA		 ");

}
*/
void imprimirUnaVivienda(eVivienda vivienda)
{
	eTipoVivienda auxTipoVivienda[4]={{1,"CASA"},{2,"DEPARTAMENTO"},{3,"CASILLA"},{4,"RANCHO"}};
	int i;
	for( i=0;i<5;i++)
	{
		if(vivienda.idTipoVivienda == auxTipoVivienda[i].idTipoVivienda)
		{
			break;
		}
	}

	printf("\n%d	 		%s			 %d    			%d	  		 %s    	 \n",
			vivienda.idVivienda,vivienda.calle,vivienda.cantidadPersonas,vivienda.cantidadHabitaciones,
			auxTipoVivienda[i].descripcion);

}

int buscarViviendaPorId(eVivienda* array, int len,int id, int *indice)
{
	int retorno = -1;

	if (array != NULL && len >0 && indice != NULL)
	{
			for(int i=0 ; i<len ;i++)
			{
				if(array[i].isEmpty==0 && id==array[i].idVivienda)
				{
					*indice=i;
					retorno=0;
					break;
				}
			}

	}

	return retorno;
}

void modificarViviendas(eVivienda* bufferVivienda,int tamanioTexto)
{
	if(bufferVivienda != NULL && tamanioTexto >0)
	{
		int opcion;

			do{
				if(utn_getNumero(&opcion,"Por favor ingrese el numero de  opcion que "
												"desea modificar: \n"
												"1) Calle \n"
												"2) Cantidad de personas\n"
												"3) Cantidad de habitaciones\n"
												"4) Tipo de vivienda\n"
												"5)	Legajo del Censista \n"
												"6) SALIR \n",
												"ERROR opcion incorrecta \n",1,6,2)== 0)
				{

					switch (opcion)
					{

						case 1 :

							if(utn_getNombre(bufferVivienda->calle,tamanioTexto,"\n Ingrese el nuevo nombre de calle \n","\nError \n", 2)==0)
							{

								printf("modificacion ok");

							}
							break;

						case 2 :

							if(utn_getNumero(&bufferVivienda->cantidadPersonas, "\n Ingrese la nueva cantidad de personas","\nError \n",1,20,2) == 0)
							{
								printf("modificacion ok");
							}

							break;
						case 3 :

							if(utn_getNumero(&bufferVivienda->cantidadHabitaciones, "\n Ingrese la nueva cantidad de habitaciones","\nError \n",1,20,2) == 0)
							{
								printf("modificacion ok");
							}
							break;
						case 4 :

							if(utn_getNumero(&bufferVivienda->idTipoVivienda,"\n Ingrese el nuevo tipo de vivienda: \n 1- CASSA \n 2- DEPARTAMENTO "
													" \n 3- CASILLA \n 4-RANCHO ","\n error",1,4,2)==0)
							{
								printf("modificacion ok");
							}
							break;

						case 5:

							if(utn_getNumero(&bufferVivienda->legajoCensista,"\n ingrese el legajon del Censista","\n error",MINLEGAJO,MAXLEGAJO,2)==0)
							{
								printf("modificacion ok");
							}
							break;
						}

				}

			}while(opcion != 6);
		}

}

int bajaVivienda(eVivienda* bufferVivienda)
{
	int retorno = -1;

	if(bufferVivienda != NULL)
	{
		if(bufferVivienda != NULL && bufferVivienda->isEmpty == 0)
		{
			bufferVivienda->isEmpty = 1;

			retorno = 0;
		}
	}

	return retorno;
}

int ordenarArray(eVivienda* list, int len)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int j;
	eVivienda bufferSwap;

	if (list != NULL && len >0){


			do {
				  flagSwap = 0;

				  for (i = 0 ; i<len-1; i++) //posicion a comparar
				  {
						if(list[i].isEmpty == 1)
						{
								continue;
						}
						for (j=i+1 ; j<len ; j++) //recorro posiciones proximas
						{
							if(list[j].isEmpty==0)
								break;
						}

						if(list[j].isEmpty==1)//si recorre todo y no hay nada
						{
							break;
						}


							if(strncmp(list[i].calle,list[j].calle,LENCALLE) < 0) // ascendente
							{
								flagSwap = 1;
								bufferSwap = list[i];
								list[i] = list[j];
								list[j] = bufferSwap;
							}
							else
							{
								if(strncmp(list[i].calle,list[j].calle,LENCALLE)==0 &&
										list[i].cantidadPersonas > list[j].cantidadPersonas)
								{
									flagSwap = 1;
									bufferSwap = list[i];
									list[i] = list[j];
									list[j] = bufferSwap;
								}

							}

						 i=j-1;
				  }
				  len--;
			}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}


int listarCencistas(eVivienda* aViviendas, int lenViviendas,eCensista* aCensistas , int lenCensistas)
{
	int retorno=-1;
	printf("linea 349");
	if(aViviendas != NULL && lenViviendas> 0 && aCensistas != NULL && lenCensistas > 0)
	{

		for(int i = 0;i<lenCensistas;i++)
		{
			imprimirUnCensista(aCensistas[i]);
			for(int j=0;j<lenViviendas;i++)
			{
				if(aViviendas[i].legajoCensista == aCensistas[j].legajoCensista)
				{

				//	void imprimirUnCensista(eCensista censista)
					imprimirUnaVivienda(aViviendas[i]);

					retorno =0;

				}
			}

		}
	}

	return retorno;
}


