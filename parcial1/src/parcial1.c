/*
 ============================================================================
 Name        : parcial1.c
 Author      : Marcos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "laibrery.h"
#include "eVivienda.h"
#include "eCensista.h"

#define LENVIVIENDAS 5
#define LENCALLE 25

#define LENCENSISTAS 3

int main(void)
{

	//declaro variables a usar
	setbuf(stdout, NULL);

	eVivienda aViviendas[LENVIVIENDAS];
	eCensista aCensistas[LENCENSISTAS]={{100,"Ana" , 34, "1203-2345"}, {101,"Juan", 24, "4301-54678"}, {102, "Sol", 47, "4301-54678"}};
		int opcionMenu;
		int id=20000;
		int indiceLibre;//indice
		int auxId;
		int auxIndice;
		int flagAlta=-1;

	//inicializo array de tipo estructura aViviendas
		if(inicializacionViviendas(aViviendas,LENVIVIENDAS)==0)
		{
//pre menu
//se repetira siempre que opcionMenu sea diferente a 4
			do{
//pregunto al usuario que quiere hacer
				if(utn_getNumero(&opcionMenu,"\n Por favor ingrese una opcion: \n"
															"1) Altas de vivienda \n"
													 		"2) Modificar vivienda\n"
															"3) Baja de vivienda\n"
															"4) Listar viviendas\n"
															"5) Listar censistas  \n"
															"6)	Listar censistas con sus respectivas viviendas\n"
															"7) Salir\n ",
															"ERROR opcion incorrecta \n",1,7,3)==0)
				{
	//comienzo de meu
					switch(opcionMenu)
					{
	//alta	vivienda
						case 1:
							if(buscarLugarLibre(aViviendas,LENVIVIENDAS,&indiceLibre)==0 &&
							alta(aViviendas, aCensistas,LENCENSISTAS,indiceLibre,&id)==0)
							{
								printf("\n alta realizada");
								flagAlta=0;
							}
							else
							{
								printf("\n el alta no pudo ser realizada");
							}

							break;
		//modificacion vivienda
						case 2:
							if(flagAlta==0)
							{
								if(imprimirViviendas(aViviendas,LENVIVIENDAS)==0 &&
									utn_getNumero(&auxId,"\nIngrese el id de vivienda que desea modificar\n","\nError \n",20000,30000,2) == 0 &&
									 buscarViviendaPorId(aViviendas,LENVIVIENDAS,auxId,&auxIndice)==0)
								{
									imprimirUnaVivienda(aViviendas[auxIndice]);
									modificarViviendas(&aViviendas[auxIndice],LENCALLE);
								}
								else
								{
									printf("\n la modificacion no pudo ser realizada");
								}
							}
							else
							{
								printf("no hay nada que modificar");
							}


							break;
		//baja vivvienda
						case 3:
							if(flagAlta==0)
							{
								if(imprimirViviendas(aViviendas,LENVIVIENDAS)==0 &&
									utn_getNumero(&auxId,"\nIngrese el id de vivienda que desea dar de baja\n","\nError \n",20000,30000,2) == 0 &&
									 buscarViviendaPorId(aViviendas,LENVIVIENDAS,auxId,&auxIndice)==0 &&
									  bajaVivienda(&aViviendas[auxIndice])==0
									)
								{
									printf("\n baja exitosa");
								}
								else
								{
									printf("\n la baja no pudo ser realizada");
								}
							}
							else
							{
								printf("no hay nada que dar de baja");
							}

							break;
		//listar viviendas
						case 4:
							if(flagAlta==0)
							{
								if(ordenarArray(aViviendas,LENVIVIENDAS )==0)
								{
									imprimirViviendas(aViviendas,LENVIVIENDAS);
								}
							}
							else
							{
								printf("no hay nada que listar");
							}

							break;
		//listar censistas
						case 5:
							imprimirCensistas(aCensistas,LENCENSISTAS);
							break;

						//case6
						case 6:
						//	int listarCencistas(eVivienda* aViviendas, int lenViviendas,eCensista* aCensistas , int lenCensistas)
							if(listarCencistas(aViviendas,LENVIVIENDAS,aCensistas,LENCENSISTAS)==0)
							{
								printf("entre a la 145");
							}
							break;
						//listar censistas
							//mostrar datos del censista junto a sus viviendas censadas
					}
				}

			}while(opcionMenu != 7);
		}

	return EXIT_SUCCESS;
}
