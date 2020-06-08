

#include "Mascota.h"
#include <stdio.h>
#include <string.h>
#include "utn.h"

static const char TXT_TIPOS[3][6]={"Perro","Gato","Raro"};

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pets_inicializarArray(Mascota array[],int limite)
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
int pets_altaForzadaArray(Mascota array[],int limite, int indice, int* idMascota, int idCliente, int idRaza, char nombre[],int tipo,int edad,float peso,char sexo)
{
    int retorno = -1;
	Mascota buffer;

	if(limite > 0 && indice < limite && indice >= 0 && idMascota != NULL)
	{
		strncpy(buffer.nombre,nombre,QTY_NOMBRE);
		buffer.tipo = tipo;
		buffer.edad = edad;
		buffer.peso = peso;
		buffer.sexo = sexo;
		buffer.idCliente = idCliente;
        buffer.idRaza = idRaza;
		retorno = 0;
		buffer.idMascota = *idMascota;
		buffer.isEmpty = OCUPADO;
		array[indice] = buffer;
		(*idMascota)++;

	}
	return retorno;
}
/*
int pets_HardcodeoArray(Mascota array[])
{
 	int i;
    Mascota buffer [] =  {  {0,0,"manzano" ,1,0,52,2.3,'f',OCUPADO},
                            {1,0,"naranjo" ,1,0,21,5.2,'m',OCUPADO},
                            {2,1,"peral"   ,0,1,35,15.2,'m',OCUPADO},
                            {3,1,"ciruelo" ,0,1,15,3.2,'f',OCUPADO},
                            {4,1,"limonero",1,0,18,2,'m',OCUPADO},
                            {5,2,"manzano" ,0,2,52,5,'f',OCUPADO},
                            {6,2,"naranjo" ,2,3,21,6,'m',OCUPADO},
                            {7,3,"peral"   ,0,4,35,8,'m',OCUPADO},
                            {8,4,"ciruelo" ,1,0,15,4,'f',OCUPADO},
                            {9,4,"limonero",1,0,18,2.2,'m',OCUPADO},
                           {10,4,"limonero",0,5,18,10,'m',OCUPADO }};

    for( i=0; i<11; i++) //tipo 0= perro 1=gato 2=raro
    {
        array[i] = buffer[i];
    }
    return i;

}*/

/**
 * \brief Imprime los datos de un cliente
 * \param elemento del producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pets_imprimir(Mascota elemento[], int indice)
{
	int retorno=-1;
	if(elemento[indice].isEmpty == OCUPADO && indice >= 0)
	{
		retorno=0;
		printf("\n%16d%16s%12s%9d%9c%11.2f%8d",elemento[indice].idMascota,elemento[indice].nombre,
                                               TXT_TIPOS[elemento[indice].tipo],elemento[indice].edad,elemento[indice].sexo,
                                               elemento[indice].peso,elemento[indice].isEmpty);
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
int pets_imprimirArray(Mascota array[],int limite)
{
	int retorno = -1;
	int i;
	if(limite > 0)
	{
		retorno = 0;
		printf("\n\t----------------------------------------------------------------------------");
        printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -  EDAD  -  SEXO  -  PESO  -  ESTADO ");
        printf("\n\t----------------------------------------------------------------------------");
		for(i=0;i<limite;i++)
		{
		    if(array[i].isEmpty == OCUPADO)
            {
                pets_imprimir(array,i);
               //printf("\n\t----------------------------------------------------------------------------");
            }

		}
		printf("\n\t----------------------------------------------------------------------------\n");
	}
	return retorno;
}

int pets_getEmptyIndex(Mascota array[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int pets_cargarArray(Mascota array[], int limite, int indice, int* idMascota, int idRaza, int idCliente)
{
	int retorno = -1;
	Mascota buffer;

	if(limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNombre(buffer.nombre,QTY_NOMBRE,"\n NOMBRE? ", "\nERROR.",2) &&
			!utn_getNumero(&buffer.tipo,"\n TIPO DE MASCOTA? [0: PERRO, 1: GATO, 2: RARO]","\nEROOR.",0,2,2) &&
            !utn_getNumero(&buffer.edad,"\n EDAD DE MASCOTA EN AÑOS?","\nEROOR.",1,80,2) &&
            !utn_getNumeroFlotante(&buffer.peso,"\n PESO DE MASCOTA?","\nEROOR.",1,50,2) &&
			!utn_getChar(&buffer.sexo,"\nSEXO DE MASCOTA? [m/h]","\nERROR.",'h','m',2))
		{
			retorno = 0;
			buffer.idCliente = idCliente;
			buffer.idMascota = *idMascota;
			buffer.idRaza = idRaza;
			buffer.isEmpty = OCUPADO;
			array[indice] = buffer;
			(*idMascota)++;
		}
	}
	return retorno;
}

int pets_buscarId(Mascota array[], int limite, int idMascota)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0 && idMascota > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].idMascota == idMascota)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int pets_eliminarArray(Mascota array[], int limite, int indice)
{
    int retorno = -1;
    if(array != NULL && limite > 0 && indice < limite)
    {
        array[indice].isEmpty = LIBRE; //Baja logica
        retorno = 0;
    }
    return retorno;
}

int pets_menuModificar()
{
	int opcion;

    printf("\n\nModificar mascota:");
	printf("\n==================================");
	printf("\n1- Modificar nombre");
	printf("\n2- Modificar tipo");
	printf("\n3- Modificar raza");
	printf("\n4- Modificar edad");
	printf("\n5- Modificar peso");
	printf("\n6- Modificar sexo");
	printf("\n7- Cancelar modificacion");
	printf("\n8- Guardar y salir");

	utn_getNumero(&opcion,"\nIngrese opcion: ","\nERROR.",1,8,2);

	return opcion;
}

int pets_menuModificarMascotaBis()
{
	int opcion;

    printf("\n\nModificar Mascota:");
	printf("\n==========================");
	printf("\n  1- Modificar nombre");
	printf("\n  2- Modificar tipo");
	printf("\n  3- Modificar raza");
	printf("\n  4- Modificar edad");
	printf("\n  5- Modificar peso");
	printf("\n  6- Modificar sexo");
	printf("\n  7- Modificar duenio");
	printf("\n  8- Cancelar modificacion");
	printf("\n  9- Guardar y salir");
	printf("\n==========================");

    utn_getNumero(&opcion,"\nIngrese opcion: ","\nERROR.",1,9,2);


	return opcion;
}

int pets_modificarArray(Mascota array[], int limite, int indice)
{
    int retorno = -1;
    int opcion;
    char respuesta = 'n';
    Mascota buffer;

    if(array != NULL && limite > 0 && indice >= 0 && indice < limite)
    {
        buffer = array[indice]; //Guardo una copia
        retorno = 0;
        do{
            opcion = pets_menuModificar();

            switch(opcion)
            {
            case 1:
                printf("\n----MODIFICAR NOMBRE----");
                utn_getNombre(array[indice].nombre,QTY_NOMBRE,"\nIngrese el nuevo nombre: ","\nERROR.",2);
                break;
            case 2:
                printf("\n----MODIFICAR TIPO----");
                utn_getNumero(&array[indice].tipo,"\nIngrese el nuevo tipo [0: PERRO, 1: GATO, 2: RARO]: ","\nERROR.",0,2,2);
                break;
            case 3:
                printf("\n----MODIFICAR RAZA----");
                printf("\nRaza modificada");
                break;
            case 4:
                printf("\n----MODIFICAR EDAD----");
                utn_getNumero(&array[indice].edad,"\nIngrese la nueava edad: ","\nERROR.",1,50,2);
                break;
            case 5:
                printf("\n----MODIFICAR PESO----");
                utn_getNumeroFlotante(&array[indice].peso,"\nIngrese el nuevo peso: ","\nERROR.",1,100,2);
                break;
            case 6:
                printf("\n----MODIFICAR SEXO----");
                utn_getChar(&array[indice].sexo,"\nIngrese el nuevo sexo [m/h]","\nERROR.",'m','h',2);
                break;
            case 7:
                printf("\n----CANCELAR MODIFICACION----");
                utn_getChar(&respuesta,"\nEsta seguro que desea cancelar [s/n]","\nERROR.",'s','n',2);
                if(respuesta == 's')
                {
                    array[indice] = buffer;
                    printf("\nModificacion cancelada");
                    break;
                }
            }

        }while(opcion != 8);
    }
    return retorno;
}

int pets_swapArray(Mascota array[], int i, int j)
{
    int retorno = -1;
    Mascota buffer;
    if(array != NULL)
    {
        buffer   = array[i];
        array[i] = array[j];
        array[j] = buffer;
        retorno  = 0;
    }
	return retorno;
}

int pets_sortMascotasPorTipo(Mascota array[], int limite, int order)
{
    int i;
    int j;
    int retorno = -1;
    if(array != NULL && limite > 0)
    {
        switch(order)
        {
        case 1: //ASCENDENTE
            for(i=0;i<(limite-1);i++)
            {
                for(j=i+1;j<limite;j++)
                {
                    if((array[i].tipo > array[j].tipo) && array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
                    {
                        pets_swapArray(array,i,j);
                    }
                }
            }
            break;
        case 2: //DESCENDENTE
            for(i=0;i<(limite-1);i++)
            {
                for(j=i+1;j<limite;j++)
                {
                    if((array[i].tipo < array[j].tipo) && array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO)
                    {
                        pets_swapArray(array,i,j);
                    }
                }
            }
            break;
        }
        retorno = 0;
    }
    return retorno;
}

int pets_printMascotaPorTipo(Mascota array[], int limite, int tipoMascota)
{
    int retorno = -1;
    int i;
    if(array != NULL && limite > 0 && tipoMascota > 0)
    {
        retorno = 0;
        printf("\n\t---------------------------MASCOTAS TIPO : %s-----------------------------",TXT_TIPOS[tipoMascota-1]);
        printf("\n\t----------------------------------------------------------------------------");
        printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -  EDAD  -  SEXO  -  PESO  -  ESTADO ");
        printf("\n\t----------------------------------------------------------------------------");
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].tipo == (tipoMascota-1))
            {
                pets_imprimir(array,i);
            }
        }
        printf("\n\t----------------------------------------------------------------------------");
    }
    return retorno;
}

float pets_getPromedioEdades(Mascota array[], int limite)
{
    int retorno = -1;
    int i;
    int acumEdades;
    int contador;
    float promedioEdades;
    if(array != NULL && limite > 0)
    {
        retorno = 0;
        acumEdades = 0;
        contador = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO)
            {
                acumEdades += array[i].edad;
                contador++;
            }
        }
        promedioEdades = ((float)acumEdades)/contador;
        retorno = promedioEdades;
    }
    return retorno;
}

int pets_getPromedioEdadesPorTipo(Mascota array[], int limite, int cantidadTipos)
{
    int retorno = -1;
    int i;
    int j;
    int auxCantidadTipo[] = {0,1,2}; //USO UN AUXILIAR PARA COMPARAR O LA MISMA MATRIZ
    int acumEdades;
    int contador[cantidadTipos];
    float promedioEdades;
    if(array != NULL && limite > 0)
    {

        for(i=0;i<cantidadTipos;i++)
        {
            acumEdades = 0;
            contador[i] = 0;
            for(j=0;j<limite;j++)
            {
                if(array[j].isEmpty == OCUPADO && auxCantidadTipo[i] == array[j].tipo)
                {
                    acumEdades += array[j].edad;
                    contador[i]++;
                }
            }
            promedioEdades = ((float)acumEdades)/contador[i];
            if(contador[i] == 0)
            {
                printf("\nNo hay mascotas de tipo %s para promediar.",TXT_TIPOS[i]);
            }
            else
            {
                printf("\nPromedio de edades de los %ss: %.3f",TXT_TIPOS[i],promedioEdades);
            }
        }
        retorno = 0;
    }
    return retorno;
}
