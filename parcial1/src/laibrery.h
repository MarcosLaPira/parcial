/*
 * laibrery.h
 *
 *  Created on: 11 may. 2022
 *      Author: lapir
 */

#ifndef LAIBRERY_H_
#define LAIBRERY_H_



//

int myGets(char cadena[], int tamanio);

int utn_getNombre(char array[], int tamanio, char* mensaje, char* mensajeError, int reintentos );

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int getNumeroFlotante(float* pResultado, char* mensaje, char* errorMensaje, float minimo, float maximo, int reintentos);


int getAlfanumerico(char array[],char* mensaje, char* errorMensaje,int tamano, int reintentos);

int getCadenaTelefonica(char array[],char* mensaje, char* errorMensaje,int tamano, int reintentos);

int esLetraConEspacio(char array[],char* mensaje, char* errorMensaje,int tamano, int reintentos);
int esSoloLetra(char array[],char* mensaje, char* errorMensaje,int tamano, int reintentos);





#endif /* LAIBRERY_H_ */
