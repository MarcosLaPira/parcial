/*
 ============================================================================
 Name        : parcialLabo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedList.h"
#include "controller.h"
#include "servicios.h"
#include "laibrery.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu = 0;
	int flagAlta = 0;

    LinkedList* listaServicios = ll_newLinkedList();

	    do{
	    	if(utn_getNumero(&menu,"\n\n \t *** INGRESO AL PROGRAMA *** \n"
	    					"\nPor favor ingrese una opcion: \n\n"

	    					"1) Cargar archivo.\n"
	    			 		"2) Imprimir lista.\n"
	    					"3) Asignar totales.\n"
	    					"4) Filtrar por tipo.\n"
	    					"5) Ordenamiento .\n"
							"6) Guardar servicios.\n"
							"7) Salir. \n",

	    					"ERROR opcion incorrecta. \n",1,7,3)==0){

				switch(menu)
				{
				//cargo datos del archivo
					case 1:
						if (controller_loadFromText("data.csv",listaServicios))
						{
							flagAlta = 1;
						}

						break;
						//listar
					case 2 :
						if (flagAlta == 1)
						{
							controller_ListPassenger(listaServicios);
						}
						else {
							printf ("\n error, primer debe de cargar .");
						}


						break;
						//asignacion final
					case 3 :  if (flagAlta == 1)
							{
								controller_Map(listaServicios);
							}
					else {
							printf ("\n error, primer debe de cargar .");
						  }


						break;
							// nievo archivo
					case 4 :

						// LinkedList* ll_filter(LinkedList* this, int(*fn)(void*))
						  	 //: Se deberá generar un archivo igual al original, pero donde solo aparezcan
							 //servicios del tipo seleccionado
						break;
						//ordenamiento
					case 5 : if (flagAlta == 1 && controller_sortPassenger(listaServicios))
							{
									controller_ListPassenger(listaServicios);
							}
							else
							{
								printf ("\nprimero debe de cargar datos.");
							}
						     // Se deberá mostrar por pantalla un listado de los servicios ordenados por
						 	 //descripción de manera ascendente.
						break;
						//guardado en nuevo archivo tipo txt
					case 6 :
						if (flagAlta == 1){
							if(controller_saveAsText("data.txt",listaServicios))
							{
								printf("\nArchivo creado OK.");
							}
						}
						else{
							printf ("\error primero debe de cargar.");
						}

						break;

				}
	    	}
	    }while(menu != 7);

	return EXIT_SUCCESS;
}
