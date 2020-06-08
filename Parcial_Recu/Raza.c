
#include "Raza.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>

static int raza_imprimir(Raza elemento);

int raza_inicializarArray(Raza array[], int limite)
{
    int retorno = -1;
	int i;
	if(limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
	return retorno;
}
int raza_altaForzada(Raza array[], int limite, int indice, int* idRaza, char nombre[], char pais[])
{
    int retorno = -1;
    Raza buffer;
    if(limite > 0 && indice < limite && indice >= 0 && idRaza != NULL)
    {
        strncpy(buffer.nombre,nombre,QTY_NOMBRE);
        strncpy(buffer.pais,pais,QTY_PAIS);
        buffer.idRaza = *idRaza;
        buffer.isEmpty = OCUPADO;
        retorno = 0;
        array[indice] = buffer;
        (*idRaza)++;
    }
    return retorno;
}
/*
int raza_HardcodeoArray(Raza array[])
{
 	int i;
    Raza buffer [] =  { {0,"razaGato","pais0",OCUPADO},
                        {1,"razaPerro","pais1",OCUPADO},
                        {2,"Pitbull","pais2",OCUPADO},
                        {3,"razaIguana1","pais3",OCUPADO},
                        {4,"Labrador","pais4",OCUPADO},
                        {5,"Bulldog","pais5",OCUPADO}};

    for(i=0; i<6; i++)
    {
        array[i] = buffer[i];
    }
    return i;
}*/

static int raza_imprimir(Raza elemento)
{

	int retorno = -1;
	if(elemento.isEmpty == OCUPADO)
	{
		retorno = 0;
		printf("\n\%13d %17s %14s %7d", elemento.idRaza,
                                        elemento.nombre,
                                        elemento.pais,
                                        elemento.isEmpty);


	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int raza_imprimirArray(Raza array[],int limite)
{
	int retorno = -1;
	int i;
	if(limite > 0)
	{
		retorno = 0;
        printf("\n\t--------------------------------------------------");
		printf("\n\t ID_RAZA  -  NOMBRE_RAZA  -  PAIS_RAZA  -  ESTADO ");
        printf("\n\t--------------------------------------------------");
		for(i=0;i<limite;i++)
		{
		    if(array[i].isEmpty == OCUPADO)
            {
                raza_imprimir(array[i]);
               //printf("\n\t--------------------------------------------------");
            }
		}
        printf("\n\t--------------------------------------------------");
	}
	return retorno;
}

int Raza_CargarArray(Raza array[],int limite, int indice,int* idRaza)
{
	int retorno = -1;
	Raza buffer;

	if(limite > 0 && indice < limite && indice >= 0 && idRaza != NULL )
	{
		if(	!utn_getNombre(buffer.nombre,QTY_NOMBRE,"\n NOMBRE DE RAZA? ","\nERROR.",2) &&
            !utn_getNombre(buffer.pais,QTY_PAIS,"\n PAIS DE RAZA? ", "\nERROR.",2))
		{
			retorno = 0;
			buffer.idRaza = *idRaza;
			buffer.isEmpty = OCUPADO;
			array[indice] = buffer;
			(*idRaza)++;
		}
	}
	return retorno;
}

int raza_BuscarId(Raza array[],int limite, int idRaza)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].idRaza == idRaza)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
