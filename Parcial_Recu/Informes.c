
#include "Informes.h"

static const char TXT_TIPOS[3][6]={"Perro","Gato","Raro"};


int info_printMascota(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite, int indice)
{
    int j;
    int k;
    int retorno = -1;
    if(pet_array != NULL && pet_limite > 0 && raza_array != NULL && raza_limite > 0 && cli_array != NULL && cli_limite > 0 && indice >= 0 && indice < pet_limite)
    {
        retorno = 0;
        for(k=0;k<raza_limite;k++)
        {
            if(raza_array[k].isEmpty == OCUPADO && raza_array[k].idRaza == pet_array[indice].idRaza)
            {
                break;
            }
        }

        for(j=0;j<cli_limite;j++)
        {
            if(cli_array[j].isEmpty == OCUPADO && cli_array[j].idCliente == pet_array[indice].idCliente)
            {
                break;
            }
        }

        printf("\n\t--------------------------------------------------------------------------------------------------------------------");
        printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -   RAZA   -  EDAD  -  SEXO  -  PESO  -  APELLIDO_DUENIO  -  ESTADO_MASCOTA");
        printf("\n\t--------------------------------------------------------------------------------------------------------------------");
        printf("\n%16d%17s%11s%13s%7d%9c%11.2f%16s%16d",pet_array[indice].idMascota,
                                                        pet_array[indice].nombre,
                                                        TXT_TIPOS[pet_array[indice].tipo],
                                                        raza_array[k].nombre,
                                                        pet_array[indice].edad,
                                                        pet_array[indice].sexo,
                                                        pet_array[indice].peso,
                                                        cli_array[j].apellido,
                                                        pet_array[indice].isEmpty);
        printf("\n\t--------------------------------------------------------------------------------------------------------------------");
    }
    return retorno;
}

void info_PrintMascotasConSusDuenios(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite)
{
    int i;
    int j;
    int k;

    printf("\n\t--------------------------------------------------------------------------------------------------------------------");
    printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -   RAZA   -  EDAD  -  SEXO  -  PESO  -  APELLIDO_DUENIO  -  ESTADO_MASCOTA");
    printf("\n\t--------------------------------------------------------------------------------------------------------------------");
    for(i=0;i<pet_limite;i++)
    {
        if(pet_array[i].isEmpty == OCUPADO)
        {
            for(k=0;k<raza_limite;k++)
            {
                if(raza_array[k].isEmpty == OCUPADO)
                {
                    for(j=0;j<cli_limite;j++)
                    {
                        if(cli_array[j].idCliente == pet_array[i].idCliente && cli_array[j].isEmpty == OCUPADO && raza_array[k].idRaza == pet_array[i].idRaza)
                        {
                            printf("\n%16d%17s%11s%13s%7d%9c%11.2f%16s%16d",pet_array[i].idMascota,
                                                                            pet_array[i].nombre,
                                                                            TXT_TIPOS[pet_array[i].tipo],
                                                                            raza_array[k].nombre,
                                                                            pet_array[i].edad,
                                                                            pet_array[i].sexo,
                                                                            pet_array[i].peso,
                                                                            cli_array[j].apellido,
                                                                            pet_array[i].isEmpty);
                        }
                    }
                }
            }
        }
    }
    printf("\n\t--------------------------------------------------------------------------------------------------------------------");
}


void info_PrintClientesConSusMascotas(Cliente cli_Array[], int cli_limite, Mascota pet_Array[], int pet_limite)
{
    int i;
    int j;
    char flagTieneMascota;

    for(i=0; i<cli_limite; i++)
    {
        if(cli_Array[i].isEmpty == OCUPADO)
        {
            printf("\n\t-----------------------------------------------------------------------------------------");
            printf("\n\t\t\t\tCliente: %s %s",cli_Array[i].apellido, cli_Array[i].nombre);
            printf("\n\t-----------------------------------------------------------------------------------------");
            printf("\n\t ID_CLIENTE - ID_MASCOTA - NOMBRE_MASCOTA - TIPO_MASCOTA - SEXO_MASCOTA - ESTADO_CLIENTE");
            printf("\n\t-----------------------------------------------------------------------------------------");

            flagTieneMascota = 'n';
            for(j=0; j<pet_limite; j++)
            {
                if(pet_Array[j].idCliente == cli_Array[i].idCliente && pet_Array[j].isEmpty == OCUPADO)
                {
                    printf("\n%14d %13d %16s %14s %14c %14d",cli_Array[i].idCliente,pet_Array[j].idMascota,pet_Array[j].nombre,
                                                             TXT_TIPOS[pet_Array[j].tipo],pet_Array[j].sexo,cli_Array[i].isEmpty);
                    flagTieneMascota = 's';
                }
            }
        }

        if(flagTieneMascota == 'n')
        {
            printf("\t\t\t%s, No tiene mascotas\n", cli_Array[i].nombre);

        }
    }
            printf("\n\t-----------------------------------------------------------------------------------------");
}

int info_ModificarMascota(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite, int indice)
{
    int retorno = -1;
    int opcion;
    char respuesta = 'n';
    Mascota buffer;
    int auxIdCliente;
    int auxIdRaza;
    int indiceCliente;
    int indiceRaza;

    if(pet_array != NULL && pet_limite > 0 && indice >= 0 && indice < pet_limite)
    {
        buffer = pet_array[indice]; //Creo una copia
        retorno = 0;

        info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);

        do{
            opcion = pets_menuModificarMascotaBis();

            switch(opcion)
            {
            case 1:
                printf("\n----MODIFICAR NOMBRE----");
                utn_getNombre(pet_array[indice].nombre,QTY_NOMBRE,"\nIngrese el nuevo nombre: ","\nERROR.",2);
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                break;
            case 2:
                printf("\n----MODIFICAR TIPO----");
                utn_getNumero(&pet_array[indice].tipo,"\nIngrese el nuevo tipo [0: PERRO, 1: GATO, 2: RARO]: ","\nERROR.",0,2,2);
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                break;
            case 3:
                printf("\n----MODIFICAR RAZA----");
                raza_imprimirArray(raza_array,raza_limite);
                utn_getNumero(&auxIdRaza,"\nIngrese el ID de la nueva raza: ","\nERROR. ID fuera de rango",0,QTY_RAZAS,2);
                indiceRaza = raza_BuscarId(raza_array,raza_limite,auxIdRaza);
                if(indiceRaza >= 0)
                {
                    printf("\nID encontrado");
                    pet_array[indice].idRaza = auxIdRaza;
                    info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                }
                else
                {
                    printf("\nID no registrado");
                }
                break;
            case 4:
                printf("\n----MODIFICAR EDAD----");
                utn_getNumero(&pet_array[indice].edad,"\nIngrese la nueava edad: ","\nERROR.",1,50,2);
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                break;
            case 5:
                printf("\n----MODIFICAR PESO----");
                utn_getNumeroFlotante(&pet_array[indice].peso,"\nIngrese el nuevo peso: ","\nERROR.",1,100,2);
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                break;
            case 6:
                printf("\n----MODIFICAR SEXO----");
                utn_getChar(&pet_array[indice].sexo,"\nIngrese el nuevo sexo [m/h]","\nERROR.",'m','h',2);
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                break;
            case 7:
                printf("\n----MODIFICAR DUENIO----");
                cli_imprimirArray(cli_array,cli_limite);
                utn_getNumero(&auxIdCliente,"\nIngrese el ID del nuevo cliente: ","\nERROR. ID fuera de rango",0,QTY_CLIENTES,2);
                indiceCliente = cli_BuscarId(cli_array,cli_limite,auxIdCliente);
                if(indiceCliente >= 0)
                {
                    printf("\nID encontrado");
                    pet_array[indice].idCliente = auxIdCliente;
                    info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                }
                else
                {
                    printf("\nID no registrado");
                }
                break;
            case 8:
                printf("\n----CANCELAR MODIFICACION----");
                info_printMascota(pet_array,pet_limite,cli_array,cli_limite,raza_array,raza_limite,indice);
                utn_getChar(&respuesta,"\nEsta seguro que desea cancelar [s/n]","\nERROR.",'s','n',2);
                if(respuesta == 's')
                {
                    pet_array[indice] = buffer;
                    printf("\nModificacion cancelada");
                }
                break;
            }
        }while(opcion != 9);
    }
    return retorno;
}

int info_eliminarClienteConMascotas(Cliente cli_array[], Mascota pet_array[], int pet_limite, int indice, int idCliente)
{
    int retorno = -1;
    int i;
    char respuesta = 'n';

    if(pet_array != NULL && pet_limite > 0 && indice >= 0 && indice < pet_limite && cli_array != NULL && idCliente >= 0)
    {
		utn_getChar(&respuesta,"\nEsta seguro de eliminar este cliente? [s/n]","\nERROR.",'s','n',2);

		if(respuesta == 's')
        {
            cli_array[indice].isEmpty = LIBRE;

            for(i=0;i<pet_limite;i++)
            {
                if(cli_array[indice].idCliente == idCliente && pet_array[i].idCliente == idCliente)
                {
                    pet_array[i].isEmpty = LIBRE;
                }
            }
            retorno = 0;
		}
        else
        {
            printf("\nOperación cancelada");
        }
    }
    return retorno;
}

int info_printClientesConMasDeUnaMascota(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite)
{
    int retorno = -1;
    int i;
    int j;
    int mascotasPorCliente[cli_limite]; // Contador
    int masDeUnaMascota; // Flag

    if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0)
    {
        masDeUnaMascota = 0;

        for(i=0;i<cli_limite;i++)
        {
            mascotasPorCliente[i] = 0;
            for(j=0;j<pet_limite;j++)
            {
                if(cli_array[i].idCliente == pet_array[j].idCliente && cli_array[i].isEmpty == OCUPADO && pet_array[j].isEmpty == OCUPADO)
                {
                    mascotasPorCliente[i]++;
                    masDeUnaMascota = 1;
                }
            }
        }
        if(masDeUnaMascota)
        {
            retorno = 0;
            printf("\n\t----------------------------------------------------------------------------------------------------------");
            printf("\n\t ID_CLIENTE  -  NOMBRE  -  APELLIDO  -  LOCALIDAD  -  TELEFONO  -  EDAD  -  SEXO  -  ESTADO - Nro MASCOTAS");
            printf("\n\t----------------------------------------------------------------------------------------------------------");
            for(i=0;i<cli_limite;i++)
            {
                if(mascotasPorCliente[i] > 1)
                {
                    cli_imprimir(cli_array,i);
                    printf("\t%3d", mascotasPorCliente[i]);
                }
            }
        }
        else
        {
            printf("\nNo hay clientes con mas de una mascota");
        }
            printf("\n\t----------------------------------------------------------------------------------------------------------");
    }
    return retorno;
}

int info_printMascotasConMasAniosYsusDuenios(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, int anios)
{
    int retorno = -1;
    int i;
    int j;
    int mascotaConMasAnios; // Flag

    if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0)
    {
        retorno = 0;
        mascotaConMasAnios = 0;
        printf("\n\t--------------------------------------------------------------------------------------------");
        printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -  EDAD  -  SEXO  -  PESO  -  ESTADO - NOMBRE_DUENIO");
        printf("\n\t--------------------------------------------------------------------------------------------");
        for(i=0;i<pet_limite;i++)
        {
            if(pet_array[i].edad > anios && pet_array[i].isEmpty == OCUPADO)
            {
                mascotaConMasAnios = 1;
                for(j=0;j<cli_limite;j++)
                {
                    if(pet_array[i].idCliente == cli_array[j].idCliente && cli_array[j].isEmpty == OCUPADO)
                    {
                        pets_imprimir(pet_array,i);
                        printf("\t%s",cli_array[j].nombre);
                        mascotaConMasAnios = 1;
                    }
                }
            }
        }
        if(!mascotaConMasAnios)
        {
            printf("\n\t\t\t\tNo hay mascotas registradas de mas de %d anios",anios);
        }
        printf("\n\t--------------------------------------------------------------------------------------------");
    }
    return retorno;
}

int info_sortDueniosPorCantidadMascotas(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, int order)
{
    int retorno = -1;
    int i;
    int j;
    int k;
    int cantidadMascotasI;
    int cantidadMascotasJ;
    if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0)
    {
        retorno = 0;
        for(i=0;i<(cli_limite-1);i++)
        {
            cantidadMascotasI = 0;
            for(k=0;k<pet_limite;k++)
            {
                if(cli_array[i].idCliente == pet_array[k].idCliente && pet_array[k].isEmpty == OCUPADO)
                {
                    cantidadMascotasI++;
                }
            }

            for(j=(i+1);j<cli_limite;j++)
            {
                cantidadMascotasJ = 0;
                for(k=0;k<pet_limite;k++)
                {
                    if(cli_array[j].idCliente == pet_array[k].idCliente && pet_array[k].isEmpty == OCUPADO)
                    {
                        cantidadMascotasJ++;
                    }
                }
                switch(order)
                {
                case 1: //ASCENDENTE
                    if(cantidadMascotasI > cantidadMascotasJ)
                    {
                        cli_swapArray(cli_array, i, j);
                    }
                    break;
                case 2: //DESCENDENTE
                    if(cantidadMascotasI < cantidadMascotasJ)
                    {
                        cli_swapArray(cli_array, i, j);
                    }
                    break;
                }
            }
        }
    }
    return retorno;
}

int info_sortDueniosPorCantidadMascotasYnombre(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, int order)
{
    int retorno = -1;
    int i;
    int j;
    int k;
    int cantidadMascotasI;
    int cantidadMascotasJ;
    char auxNombreI[QTY_NOMBRE];//COMPARO CON VARIABLES AUXILIARES PARA NO MODIFICAR LAS ORIGINALES
    char auxNombreJ[QTY_NOMBRE];

    if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0)
    {
        retorno = 0;
        for(i=0;i<(cli_limite-1);i++)
        {
            cantidadMascotasI = 0;
            for(k=0;k<pet_limite;k++)
            {
                if(cli_array[i].idCliente == pet_array[k].idCliente && pet_array[k].isEmpty == OCUPADO)
                {
                    cantidadMascotasI++;
                }
            }

            for(j=(i+1);j<cli_limite;j++)
            {
                cantidadMascotasJ = 0;
                for(k=0;k<pet_limite;k++)
                {
                    if(cli_array[j].idCliente == pet_array[k].idCliente && pet_array[k].isEmpty == OCUPADO)
                    {
                        cantidadMascotasJ++;
                    }
                }
                switch(order)
                {
                case 1: //ASCENDENTE
                    if(cantidadMascotasI > cantidadMascotasJ)
                    {
                        cli_swapArray(cli_array, i, j);
                    }
                    else if(cantidadMascotasI == cantidadMascotasJ)
                    {
                        strncpy(auxNombreI,cli_array[i].nombre,QTY_CLIENTES);
                        strncpy(auxNombreJ,cli_array[j].nombre,QTY_CLIENTES);
                        utn_getStrLwr(auxNombreI);
                        utn_getStrLwr(auxNombreJ);
                        if(strncmp(auxNombreI,auxNombreJ,QTY_CLIENTES) > 0)
                        {
                            cli_swapArray(cli_array, i, j);
                        }
                    }
                    break;
                case 2: //DESCENDENTE
                    if(cantidadMascotasI < cantidadMascotasJ)
                    {
                        cli_swapArray(cli_array, i, j);
                    }
                    else if(cantidadMascotasI == cantidadMascotasJ)
                    {
                        strncpy(auxNombreI,cli_array[i].nombre,QTY_CLIENTES);
                        strncpy(auxNombreJ,cli_array[j].nombre,QTY_CLIENTES);
                        utn_getStrLwr(auxNombreI);
                        utn_getStrLwr(auxNombreJ);
                        if(strncmp(auxNombreI,auxNombreJ,QTY_CLIENTES) < 0)
                        {
                            cli_swapArray(cli_array, i, j);
                        }
                    }
                    break;
                }
            }
        }
    }
    return retorno;
}

int info_printDueniosConMascotasDelMismoSexo(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, Raza raza_array[], int raza_limite)
{
    int retorno = -1;
    int i;
    int j;
    int contadorMacho[cli_limite];
    int contadorHembra[cli_limite];
    int hayMascotasDelMismoSexo; // Flag

    if(cli_array != NULL && cli_limite > 0 && pet_array != NULL && pet_limite > 0 && raza_array != NULL && raza_limite > 0)
    {
        hayMascotasDelMismoSexo = 0;
        for(i=0;i<cli_limite;i++)
        {
            contadorHembra[i] = 0;
            contadorMacho[i] = 0;
            if(cli_array[i].isEmpty == OCUPADO)
            {
                for(j=0;j<pet_limite;j++)
                {
                    if(pet_array[j].isEmpty == OCUPADO && cli_array[i].idCliente == pet_array[j].idCliente)
                    {
                        if(pet_array[j].sexo == 'm')
                        {
                            hayMascotasDelMismoSexo = 1;
                            contadorMacho[i]++;
                        }
                        else
                        {
                            if(pet_array[j].sexo == 'h')
                            {
                                hayMascotasDelMismoSexo = 1;
                                contadorHembra[i]++;
                            }
                        }
                    }
                }
            }
            if(hayMascotasDelMismoSexo)
            {
                if(contadorMacho[i] > 1)
                {
                    info_printCliente(cli_array,cli_limite,pet_array,pet_limite,raza_array,raza_limite,i);
                    printf("\n\t\t\t\t\t\tTiene %d Machos.",contadorMacho[i]);
                }
                else
                {
                    if(contadorHembra[i] > 1)
                    {
                        info_printCliente(cli_array,cli_limite,pet_array,pet_limite,raza_array,raza_limite,i);
                        printf("\n\t\t\t\t\t\tTiene %d Hembras.",contadorHembra[i]);
                    }
                }
            }
        }

        if(!hayMascotasDelMismoSexo)
        {
            printf("\nNo hay duenios que tengan mascotas del mismo sexo.");
        }

        retorno = 0;
    }
    return retorno;
}

int info_printCliente(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, Raza raza_array[], int raza_limite, int indice)
{
    int j;
    int k;
    int retorno = -1;
    if(pet_array != NULL && pet_limite > 0 && raza_array != NULL && raza_limite > 0 && cli_array != NULL && cli_limite > 0 && indice >= 0 && indice < pet_limite)
    {
                        printf("\n\t-------------------------------------------------------------------------------------------");
                        printf("\n\t\t\t\t\tCliente: %s %s",cli_array[indice].apellido, cli_array[indice].nombre);
                        printf("\n\t-------------------------------------------------------------------------------------------");
                        printf("\n\t  ID_MASCOTA   -   NOMBRE_MASCOTA   -   TIPO   -   RAZA   -   SEXO   -   ESTADO_MASCOTA");
                        printf("\n\t-------------------------------------------------------------------------------------------");
        for(j=0;j<pet_limite;j++)
        {
            if(pet_array[j].isEmpty == OCUPADO)
            {
                for(k=0;k<raza_limite;k++)
                {
                    if(raza_array[k].isEmpty == OCUPADO && raza_array[k].idRaza == pet_array[j].idRaza && pet_array[j].idCliente == cli_array[indice].idCliente)
                    {
                        printf("\n%16d%21s%15s%13s%8c%16d", pet_array[j].idMascota,
                                                            pet_array[j].nombre,
                                                            TXT_TIPOS[pet_array[j].tipo],
                                                            raza_array[k].nombre,
                                                            pet_array[j].sexo,
                                                            pet_array[j].isEmpty);
                    }
                }
            }
        }
                        printf("\n\t-------------------------------------------------------------------------------------------");
        retorno = 0;
    }
    return retorno;
}




