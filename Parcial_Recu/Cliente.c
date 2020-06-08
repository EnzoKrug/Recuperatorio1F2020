
#include "Cliente.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente array[],int limite)
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

int cli_altaForzadaArray(Cliente array[],int limite, int indice, int* idCliente, char nombre[],char apellido[],char localidad[],char telefono[], int edad, char sexo)
{
    int retorno = -1;
	Cliente buffer;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL)
	{
		strncpy(buffer.nombre,nombre,QTY_NOMBRE);
		strncpy(buffer.apellido,apellido,QTY_APELLIDO);
        strncpy(buffer.localidad,localidad,QTY_LOCALIDAD);
		strncpy(buffer.telefono,telefono,QTY_TELEFONO);
		buffer.edad = edad;
		buffer.sexo = sexo;
		retorno = 0;
		buffer.idCliente = *idCliente;
		buffer.isEmpty = OCUPADO;
		array[indice] = buffer;
		(*idCliente)++;
	}
	return retorno;
}
/*
int cli_HardcodeoArray(Cliente array[])
{
 	int i;
    Cliente buffer [] =  {  {0,"manzano" , "algo a" , "eeee" ,"eeee",52,'f',OCUPADO } ,
                            {1,"naranjo" , "algo b" , "eeee" ,"eeee",21,'m',OCUPADO } ,
                            {2,"peral"   , "algo c" , "eeee" ,"eeee",35,'m',OCUPADO } ,
                            {3,"ciruelo" , "algo d" , "eeee" ,"eeee",15,'f',OCUPADO } ,
                            {4,"limonero", "algo e" , "eeee" ,"eeee",18,'m',OCUPADO }};

    for( i=0; i<5; i++)
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
int cli_imprimir(Cliente elemento[], int indice)
{
	int retorno=-1;
	if(elemento[indice].isEmpty == OCUPADO)
	{
		retorno=0;
		printf("\n%14d %15s %11s %14s %14s %5d %8c %9d",elemento[indice].idCliente,elemento[indice].nombre,
                                                        elemento[indice].apellido,elemento[indice].localidad,
                                                        elemento[indice].telefono,elemento[indice].edad,
                                                        elemento[indice].sexo,elemento[indice].isEmpty);
	}
	return retorno;
}

int cli_printCliente(Cliente elemento[], int indice)
{
	int retorno=-1;
	if(elemento[indice].isEmpty == OCUPADO)
	{
		retorno=0;
		printf("\n\t-------------------------------------------------------------------------------------------");
        printf("\n\t ID_CLIENTE  -  NOMBRE  -  APELLIDO  -  LOCALIDAD  -  TELEFONO  -  EDAD  -  SEXO  -  ESTADO");
        printf("\n\t-------------------------------------------------------------------------------------------");
		printf("\n%14d %15s %11s %14s %14s %5d %8c %9d",elemento[indice].idCliente,elemento[indice].nombre,
                                                        elemento[indice].apellido,elemento[indice].localidad,
                                                        elemento[indice].telefono,elemento[indice].edad,
                                                        elemento[indice].sexo,elemento[indice].isEmpty);
        printf("\n\t-------------------------------------------------------------------------------------------");
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
int cli_imprimirArray(Cliente array[],int limite)
{
	int retorno = -1;
	int i;
	if(limite > 0)
	{
		retorno = 0;
		printf("\n\t-------------------------------------------------------------------------------------------");
        printf("\n\t ID_CLIENTE  -  NOMBRE  -  APELLIDO  -  LOCALIDAD  -  TELEFONO  -  EDAD  -  SEXO  -  ESTADO");
        printf("\n\t-------------------------------------------------------------------------------------------");
		for(i=0;i<limite;i++)
		{
		    if(array[i].isEmpty == OCUPADO)
            {
                cli_imprimir(array,i);
                //printf("\n\t---------------------------------------------------------------------------------");
            }

		}
		printf("\n\t-------------------------------------------------------------------------------------------");
	}
	return retorno;
}

/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int cli_BuscarId(Cliente array[],int limite,int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].idCliente == idCliente)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cli_altaArray(Cliente array[], int limite, int indice, int* id)
{
	int retorno = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,QTY_NOMBRE,"\nNombre?\n","\nERROR.",2) == 0 &&
            utn_getNombre(bufferCliente.apellido,QTY_APELLIDO,"\nApellido?\n","\nERROR.",2) == 0 &&
			utn_getDescripcion(bufferCliente.localidad,QTY_LOCALIDAD,"\nLocalidad?\n","\nERROR.",2) == 0 &&
			utn_getDescripcion(bufferCliente.telefono,QTY_TELEFONO,"\nTelefono?","\nERROR.",2) == 0 &&
            utn_getNumero(&bufferCliente.edad,"\nEdad?","\nERROR.",1,100,2) == 0 &&
            utn_getChar(&bufferCliente.sexo,"\nSexo?","\nERROR.",'f','m',2) == 0)
		{
			retorno = 0;
			bufferCliente.idCliente = *id;
			bufferCliente.isEmpty = OCUPADO;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return retorno;
}

int cli_getEmptyIndex(Cliente array[], int limite)
{
    int retorno = -1;
    int i;
	if(array != NULL && limite)
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

int cli_menuModificarDuenio()
{
	int opcion;

    printf("\n\nModificar Cliente:");
	printf("\n==========================");
	printf("\n  1- Modificar nombre");
	printf("\n  2- Modificar apellido");
	printf("\n  3- Modificar localidad");
	printf("\n  4- Modificar telefono");
	printf("\n  5- Modificar edad");
	printf("\n  6- Modificar sexo");
	printf("\n  7- Cancelar modificacion");
	printf("\n  8- Guardar y salir");
	printf("\n==========================");

    utn_getNumero(&opcion,"\nIngrese opcion: ","\nERROR.",1,8,2);


	return opcion;
}

int cli_modificarArray(Cliente array[], int limite, int indice)
{
    int retorno = -1;
    int opcion;
    Cliente buffer;
    char respuesta = 'n';
	if(array != NULL && limite && indice < limite && indice >= 0)
	{
	    buffer = array[indice]; // Creo una copia
	    cli_printCliente(array,indice);
        retorno = 0;
	    do
        {
            opcion = cli_menuModificarDuenio();
            switch(opcion)
            {
            case 1:
                printf("\n-----NOMBRE-----");
                utn_getNombre(array[indice].nombre,QTY_NOMBRE,"\nNombre?\n","\nERROR.",2);
                cli_printCliente(array,indice);
                break;
            case 2:
                printf("\n-----APELLIDO-----");
                utn_getNombre(array[indice].apellido,QTY_APELLIDO,"\nApellido?\n","\nERROR.",2);
                cli_printCliente(array,indice);
                break;
            case 3:
                printf("\n-----LOCALIDAD-----");
                utn_getDescripcion(array[indice].localidad,QTY_LOCALIDAD,"\nLocalidad?\n","\nERROR.",2);
                cli_printCliente(array,indice);
                break;
            case 4:
                printf("\n-----TELEFONO-----");
                utn_getDescripcion(array[indice].telefono,QTY_TELEFONO,"\nTelefono?","\nERROR.",2);
                cli_printCliente(array,indice);
                break;
            case 5:
                printf("\n-----EDAD-----");
                utn_getNumero(&array[indice].edad,"\nEdad?","\nERROR.",1,100,2);
                cli_printCliente(array,indice);
                break;
            case 6:
                printf("\n-----SEXO-----");
                utn_getChar(&array[indice].sexo,"\nSexo?","\nERROR.",'f','m',2);
                cli_printCliente(array,indice);
                break;
            case 7:
                printf("\n-----CANCELAR CAMBIOS-----");
                cli_printCliente(array,indice);
                utn_getChar(&respuesta,"\nEsta seguro que desea cancelar [s/n]","\nERROR.",'s','n',2);
                if(respuesta == 's')
                {
                    array[indice] = buffer;
                    printf("\nModificacion cancelada");
                }
                break;
            }
        }while(opcion!=8);
	}
	return retorno;
}

int cli_swapArray(Cliente array[], int i, int j)
{
    int retorno = -1;
    Cliente buffer;
    if(array != NULL)
    {
        buffer   = array[i];
        array[i] = array[j];
        array[j] = buffer;
        retorno  = 0;
    }
	return retorno;
}

int cli_getPromedioEdadHombresYmujeres(Cliente array[],int limite)
{
    int retorno = -1;
    int i;
    int contadorHombres;
    int acumHombres;
    float promHombres;
    int contadorMujeres;
    int acumMujeres;
    float promMujeres;
    if(array != NULL && limite > 0)
    {
        contadorHombres = 0;
        acumHombres = 0;
        contadorMujeres = 0;
        acumMujeres = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].sexo == 'm')
            {
                acumHombres += array[i].edad;
                contadorHombres++;
            }
            else
            {
                if(array[i].isEmpty == OCUPADO && array[i].sexo == 'f')
                {
                    acumMujeres += array[i].edad;
                    contadorMujeres++;
                }
            }
        }

        promHombres = ((float)acumHombres)/contadorHombres;
        promMujeres = ((float)acumMujeres)/contadorMujeres;
        if(contadorHombres == 0)
        {
            printf("\nNo hay hombres para promediar.");
        }
        else
        {
            printf("\nPromedio de edad Hombres: %.3f",promHombres);
        }
        if(contadorMujeres == 0)
        {
            printf("\nNo hay mujeres para promediar.");
        }
        else
        {
            printf("\nPromedio de edad Mujeres: %.3f",promMujeres);
        }

        retorno = 0;
    }
    return retorno;
}

int cli_getPorcentajeQueHayDeMujeres(Cliente array[], int limite)
{
    int retorno = -1;
    int i;
    int contadorMujeres;
    int contadorHombres;
    int totalClientes;
    int getPorcentajeMujeres;
    if(array != NULL && limite > 0)
    {
        contadorHombres = 0;
        contadorMujeres = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].sexo == 'm')
            {
                contadorHombres++;
            }
            else
            {
                if(array[i].isEmpty == OCUPADO && array[i].sexo == 'f')
                {
                    contadorMujeres++;
                }
            }
        }
        totalClientes = contadorHombres + contadorMujeres;
        getPorcentajeMujeres = ((float)contadorMujeres*100)/totalClientes;
        printf("\n\t\t\t\tHay %%%d de clientes que son mujeres",getPorcentajeMujeres);
        retorno = 0;
    }
    return retorno;
}
