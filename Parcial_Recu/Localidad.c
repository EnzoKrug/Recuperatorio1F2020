
#include "Localidad.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>

static int local_imprimir(Localidad elemento);

int local_inicializarArray(Localidad array[], int limite)
{
    int retorno = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
	return retorno;
}
int local_altaForzada(Localidad array[], int limite, int indice, int* idLocalidad, char provincia[], int codigoPostal ,char descripcion[])
{
    int retorno = -1;
    Localidad buffer;
    if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idLocalidad != NULL)
    {
        strncpy(buffer.provincia,provincia,QTY_PROVINCIA);
        strncpy(buffer.descripcion,descripcion,QTY_DESCRIPCION);
        buffer.codigoPostal = codigoPostal;
        buffer.idLocalidad = *idLocalidad;
        buffer.isEmpty = OCUPADO;
        retorno = 0;
        array[indice] = buffer;
        (*idLocalidad)++;
    }
    return retorno;
}

static int local_imprimir(Localidad elemento)
{

	int retorno = -1;
	if(elemento.isEmpty == OCUPADO)
	{
		retorno = 0;
		printf("\n\%13d %17s %7d %14s %7d ",elemento.idLocalidad,
                                            elemento.provincia,
                                            elemento.codigoPostal,
                                            elemento.descripcion,
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
int local_imprimirArray(Localidad array[],int limite)
{
	int retorno = -1;
	int i;
	if(limite > 0)
	{
		retorno = 0;
        printf("\n\t-------------------------------------------------------------------------");
		printf("\n\t ID_LOCALIDAD  -  PROVINCIA  -  CODIGO_POSTAL  -  DESCRIPCION  -  ESTADO ");
        printf("\n\t-------------------------------------------------------------------------");
		for(i=0;i<limite;i++)
		{
		    if(array[i].isEmpty == OCUPADO)
            {
                local_imprimir(array[i]);
               //printf("\n\t--------------------------------------------------");
            }
		}
        printf("\n\t-------------------------------------------------------------------------");
	}
	return retorno;
}
/*
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
}*/
