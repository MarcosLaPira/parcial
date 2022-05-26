/*
 * eVivienda.h
 *
 *  Created on: 25 may. 2022
 *      Author: lapir
 */

#ifndef EVIVIENDA_H_
#define EVIVIENDA_H_
#include "eCensista.h"

#define LENCALLE 25
//declaracion de estructura
typedef struct
{
	int idVivienda;
	char calle[LENCALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int idTipoVivienda;
	int legajoCensista;
	int isEmpty;
}eVivienda;

typedef struct
{
	int idTipoVivienda;
	char descripcion[20];

}eTipoVivienda;


#endif /* EVIVIENDA_H_ */

/**
 * inicializa arrray en o
 * @param puntero a espacio en memoria donde se dejara el resultado
 * @param len tamano del array
 * @return devuelve 0 si salio ok y -1 si salio mal
 */
int inicializacionViviendas(eVivienda* array, int len);
/**
 * da de alta un indice del array
 * @param aViviendas  puntero a espacio en memoria deonde se dejara el resultado
 * @param aCensistas  puntero a espacio en memoria para mostrar legajo de  censistas
 * @param lenCensistas  tamano de aCensistas
 * @param indice  lugar de aViviendas a cargar
 * @param id  puntero de id, se incrementa en uno
 * @return devuelve 0 si salio ok y -1 si salio mal
 */
int alta(eVivienda* aViviendas,eCensista* aCensistas,int lenCensistas, int indice, int* id);
/**
 * busca un lugar libre dentro del array pasado por valor
 * @param array a buscar lugar libre
 * @param len  tamano del array
 * @param lugarLibre  indice libre del array
 * @return devuelve 0 si salio ok y -1 si salio mal
 */

int buscarLugarLibre(eVivienda* array, int len, int* lugarLibre);
/**
 * imprime el array pasado por valor
 * @param array a imprimir
 * @param len tamano del array
 * @return  * @return devuelve 0 si salio ok y -1 si salio mal
 */
int imprimirViviendas(eVivienda* array,int len );
/**
 * imprime una vivienda sola
 * espera recibir el array junto con su indice
 * @param pasenger indice del array a ser impreso
 */
void imprimirUnaVivienda(eVivienda vivienda);
/**
 * busca dentro del array un indice valido
 * @param array pasado por valor a ser buscado el indice
 * @param len temano del array
 * @param id id a ser bucado
 * @param indice puntero que devuelve indice en caso de ser encontrado
 * @return @return devuelve 0 si salio ok y -1 si salio mal
 */
int  buscarViviendaPorId(eVivienda* array, int len,int id, int *indice);
/**
 * modifica campo/os del array
 * @param bufferVivienda array pasado por referencia ser modificado
 * @param tamanioTexto  tamano maximo aceptado paralos campos de tipo cadena
 */

void modificarViviendas(eVivienda* bufferVivienda,int tamanioTexto);
/**
 * coloca el campo is empty de el indice pasado del array en 1
 * @param bufferVivienda array pasado por referencia a dar de baja
 * @return devuelve 0 si salio ok y -1 si salio mal
 */
int bajaVivienda(eVivienda* bufferVivienda);
/**
 * ordena el array en funcion al campo calle, en caso de ser coincidentres ordena segun la cantidad de personas
 * @param list array pasado por valor a ser ordenado
 * @param len  tamano del array
 * @return   devuelve 0 si salio ok y -1 si salio mal
 */
int ordenarArray(eVivienda* list, int len);

int listarCencistas(eVivienda* aViviendas, int lenViviendas,eCensista* aCensistas , int lenCensistas);
