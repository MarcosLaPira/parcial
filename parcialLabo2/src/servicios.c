/*
 * servivios.c
 *
 *  Created on: 23 jun. 2022
 *      Author: lapir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"
#include "linkedList.h"
#include "laibrery.h"
#include "parser.h"


//static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
//static int esFlotante(char* cadena,int limite);
/*
static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena,int limite);

*/
eServicios* Servicios_new()
{
	eServicios* newServicio = NULL;
	newServicio = (eServicios*)malloc(sizeof(eServicios));
	if(newServicio != NULL)
	{
		newServicio->id = 0;
		strcpy(newServicio->descripcion," ");
		newServicio->tipo = 0;
		newServicio-> precio = 0;
		newServicio->cantidad = 0;
		newServicio-> total = 0;

		newServicio-> isEmpty = 1;
	}
	return newServicio;
}

eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioStr,char* cantidadStr,char* totalStr)
{
	eServicios* newServicio = Servicios_new ();
	if (newServicio != NULL)
	{
		if(
				Servicios_setIdTxt(newServicio,idStr) ==0 ||
				Servicios_setDescripcion(newServicio,descripcionStr) ==0 ||
				Servicios_setTipoTxt(newServicio,tipoStr)==0 ||
				Passenger_setPrecioTxt(newServicio,precioStr)==0 ||
				Servicios_setCantidadTxt(newServicio,cantidadStr)==0 ||
				Servicios_setTotalTxt(newServicio,totalStr)==0
			)
		{
			free (newServicio);
			newServicio = NULL;
		}
		else
		{
			printf("datos escaneados");
		}
	}
	return newServicio;
}


void Servicios_delete(eServicios* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Servicios_setIdTxt(eServicios* this,char* id) /////////////////////////////////
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,50))
		{
			retorno = 1;
			this->id = atoi(id);
		}
	}
	return retorno;
}
int Servicios_setId(eServicios* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getId(eServicios* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setDescripcion(eServicios* this,char* descripcion)
{
	int retorno = 0;
	if(this != NULL && descripcion!= NULL ) // && strlen(nombre)>0 && strlen(nombre)<=15
	{
		strncpy(this->descripcion,descripcion,LENDESCRIPCION);
		retorno = 1;
	}
	return retorno;
}
int Servicios_getDescripcion(eServicios* this,char* descripcion)
{
	int retorno = 0;
	if(this != NULL &&  descripcion != NULL)
	{
		strncpy(descripcion,this->descripcion,50);
		retorno = 1;
	}
	return retorno;
}

int Servicios_setTipoTxt(eServicios* this,char*tipo)
{
	int retorno = 0;
	if(this != NULL && tipo != NULL)
	{
		if(esNumerica(tipo,50))
		{
			this->tipo =  atoi(tipo);
		}
		retorno = 1;
	}
	return retorno;
}
int Servicios_setTipo(eServicios* this,int tipo)
{
	int retorno = 0;
	if(this != NULL && tipo > 0 && tipo < 4)
	{
		this->tipo = tipo;

		retorno = 1;
	}
	return retorno;
}
int Servicios_getTipo(eServicios* this,int* tipo)
{
	int retorno = 0;
	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}
	return retorno;
}
int Passenger_setPrecioTxt(eServicios* this,char* precio)
{
	int retorno = 0;
	float auxiliarPrecio;
	if(this != NULL && precio!= NULL )
	{
		//if(esFlotante(precio,10)==0)									/////////////////////////////
		auxiliarPrecio = atof(precio);
		if(auxiliarPrecio >= 0)
		{
			retorno = 1;
			this->precio= auxiliarPrecio;
		}
	}
	return retorno;
}
int Servicios_setPrecio(eServicios* this,float precio)
{
	int retorno = 0;
	if(this != NULL &&  precio >= 0 && precio<=100000000)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getPrecio(eServicios* this,float* precio)
{
	int retorno = 0;
	if(this != NULL &&  precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}
int Servicios_setCantidadTxt(eServicios* this,char* cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad != NULL)
	{
		if(esNumerica( cantidad,50))
		{
			this->cantidad =  atoi(cantidad);
			retorno = 1;
		}
	}
	return retorno;
}
int Servicios_setCantidad(eServicios* this,int cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad >= 0)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getCantidad(eServicios* this,int* cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setTotalTxt(eServicios* this,char* total)
{
	int retorno = 0;
	float auxiliarTotal;
	if(this != NULL &&  total != NULL)
	{
		//if(esFlotante(precio,10)==0)
		auxiliarTotal = atof(total);
		this->total = auxiliarTotal;
		retorno = 1;
	}
	return retorno;
}
int Servicios_setTotal(eServicios* this,float total)
{
	int retorno = 0;
	if(this != NULL &&  total >= 0 && total<=10000000)
	{
		this->total = total;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getTotal(eServicios* this,float* total)
{
	int retorno = 0;
	if(this != NULL &&  total != NULL)
	{
		*total = this->total;
		retorno = 1;
	}
	return retorno;
}



int Servicios_BuscarPaxId (LinkedList* pArrayListPassenger, int id)
{
	int tamanio;
	int retorno = 0;
	int idAux;
	eServicios* auxPassenger;

		if (pArrayListPassenger != NULL && id >= 0)
		{
			tamanio = ll_len(pArrayListPassenger);
			for(int i = 0 ; i < tamanio ; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger,i);
				if (auxPassenger != NULL)
				{
					Servicios_getId (auxPassenger,&idAux);

					if(id == idAux)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////
//**************************************************************************************//


/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
/*
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
*/
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/*
static int esFlotante(char* cadena,int limite)
 {
 	int retorno = 1;
 	int flagDecimal=1;

 	int i;
 	if(cadena != NULL && limite>0)
 	{
 		for(i=0; i < limite && cadena[i] != '\0';i++)
 		{
 			if(flagDecimal==1 && i !=0 && cadena[i]=='.')
 			{
 				flagDecimal=0;
 				continue;
 			}
 			if(cadena[i] < '0' || cadena[i] > '9')
 			{
 				retorno = 0;
 				break;
 			}
 		}
 	}
 	return retorno;
 }
*/



