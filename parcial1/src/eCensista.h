/*
 * eCensista.h
 *
 *  Created on: 25 may. 2022
 *      Author: lapir
 */

#ifndef ECENSISTA_H_
#define ECENSISTA_H_

#define LENNOMBRE 25
#define LENTELEFONO 15

typedef struct
{
	int legajoCensista;
	char nombre[LENNOMBRE];
	int edad;
	char telefono[LENTELEFONO];
}eCensista;

#endif /* ECENSISTA_H_ */
/**
 * imprime el array pasado por valor
 * @param array a imprimir
 * @param len tamano del array
 * @return  * @return devuelve 0 si salio ok y -1 si salio mal
 */
int imprimirCensistas(eCensista* array,int len );
/**
 * imprime una vivienda sola
 * espera recibir el array junto con su indice
 * @param censista indice del array a ser impreso
 */
void imprimirUnCensista(eCensista censista);
