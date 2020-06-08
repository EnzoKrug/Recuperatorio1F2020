

      /**
        Soy un veterinario que necesita atender a las mascotas de sus clientes, para tener el
        control vamos a tener un sistema ....el sistema debe realizar las siguientes
        funcionalidades.(los datos deben ser hardcodeados)

        1-Tenemos un listado de clientes(nombre, apellido,localidad,teléfono,edad,sexo).
        tenemos por ahora 5 clientes(dueños de mascotas) pero tengo lugar para 10.

        2-Tenemos un listado de mascotas(hasta 20 mascotas)(nombre,tipo{gato
        ,perro,raro},raza,edad,peso,sexo) ( en el listado por pantalla debería aparecer el
        nombre del dueño)
        y esta distribuido así:
        Dos gatas los tiene una mujer
        Dos perros y un gato un señor
        Un pitbull y una iguana lo tiene una chica
        Un labrador un chico
        Dos gatos y un Bulldog un señor

        3-Tenemos un listado de clientes con mascota , que muestra a los clientes con su
        listado de mascotas

        4-Alta de mascota, se pueden cargar todos los datos y se debe mostrar el listado de
        dueños disponibles
        5-Baja de mascota, es lógica, y queda el lugar disponible para otra mascota.
        6-Modificar mascota , todo menos el dueño.

        ******************************** 3da parte
        7-Alta dueño.
        8-Borrado de dueño en cascada
        9- ordenar las mascotas por tipo y listarlas con sus dueños.

        ******************************** 4ta parte
        10-Modificación Dueño
        11- Listar los clientes con más de una mascota
        12- Listar las mascotas de más de tres años, con respectivos dueños.

        ******************************** 5ta parte
        13- Listar las mascotas por un tipo en particular{perro,gato,raro}
        14 -ordenar a los dueños por cantidades de mascotas y mostrarlos.
        15 ordenar a los dueños por cantidades de mascotas y por orden alfabético de los
        nombres y mostrarlos.
        16 - el promedio de edad entre las mascotas
        17 - el promedio de edad entre las mascotas, por tipo
        18 -el promedio que tengo entre varones y mujeres de mis clientes

        consulta, en el punto del alta de mascota, le tenemos que mostrar una lista de razas y que las elija? como en clientes? HAY QUE HACERLO ASI

        Para el punto 19, todas las mascotas de la persona tiene que ser del mismo sexo?. Ej: todas hermbras?
        no , con una sola basta

        ger consulta, cuando das de alta la mascota,  elegis el tipo y elegis el tipo te tiene que aparecer las razas? se me exploto abm mientras hago lso cambios
        es para estar seguro
        de si era asi
        raza es como cliente.... listas las razas existentes y el cliente selecciona una
        lo mismo que con cliente para mascota
      */

#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
#include "utn.h"

int main()
{
    Cliente arrayClientes[QTY_CLIENTES];
    Mascota arrayMascotas[QTY_MASCOTAS];
    Raza arrayRazaMascotas[QTY_RAZAS];
    int opcion;
    int idCliente = 0;
    int idMascota = 0;
    int idRaza = 0;
    int auxIdCliente;
    int auxIdMascota;
    int auxIdRaza;
    int indiceCliente;
    int indiceMascota;
    int indiceRaza;
    char respuesta;
    int ordenMascotas;
    int ordenDuenios;
    int auxTipoMascota;
    float promEdadesMascotas;

    if(!cli_inicializarArray(arrayClientes,QTY_CLIENTES) && !pets_inicializarArray(arrayMascotas,QTY_MASCOTAS) &&
       !raza_inicializarArray(arrayRazaMascotas,QTY_RAZAS))
    {
            printf("\nINIT CLIENTES MASCOTAS Y RAZA OK!!\n");
    }

    cli_altaForzadaArray(arrayClientes,QTY_CLIENTES,0,&idCliente,"Vanesa","Perez","Avellaneda","15-5956-2513",35,'f');
    cli_altaForzadaArray(arrayClientes,QTY_CLIENTES,1,&idCliente,"Juan","Pavon","Barracas","15-9632-2354",40,'m');
    cli_altaForzadaArray(arrayClientes,QTY_CLIENTES,2,&idCliente,"Mariela","Lopez","Lanus","15-3625-4587",20,'f');
    cli_altaForzadaArray(arrayClientes,QTY_CLIENTES,3,&idCliente,"Hernan","Zapatta","Balvanera","15-3625-4458",18,'m');
    cli_altaForzadaArray(arrayClientes,QTY_CLIENTES,4,&idCliente,"Alan","Dominguez","San telmo","15-4875-9625",32,'m');

    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,0,&idMascota,0,0,"Amapola",1,5,20.5,'h');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,1,&idMascota,0,0,"Bella",1,4,20.5,'h');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,2,&idMascota,1,1,"Pollo",0,1,20.5,'m');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,3,&idMascota,1,1,"Dogy",0,9,20.5,'m');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,4,&idMascota,1,0,"Garfield",1,10,20.5,'m');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,5,&idMascota,2,2,"Toby",0,10,20.5,'h');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,6,&idMascota,2,3,"Roberto",2,10,20.5,'m');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,7,&idMascota,3,4,"Rocco",0,10,20.5,'h');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,8,&idMascota,4,0,"Gary",1,4,20.5,'m');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,9,&idMascota,4,0,"Jesper",1,15,20.5,'h');
    pets_altaForzadaArray(arrayMascotas,QTY_MASCOTAS,10,&idMascota,4,5,"Pluto",0,10,20.5,'m');

    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,0,&idRaza,"Siames","Tailandia");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,1,&idRaza,"Dogo","Argentina");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,2,&idRaza,"Pitbull","EE.UU");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,3,&idRaza,"Iguana Verde","Mexico");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,4,&idRaza,"Labrador","Canada");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,5,&idRaza,"Bulldog","Frances");
    raza_altaForzada(arrayRazaMascotas,QTY_RAZAS,6,&idRaza,"Hamster dorado","Siria");

    raza_imprimirArray(arrayRazaMascotas,QTY_RAZAS);

    //printf("\n\n\n");

    do
    {
            printf("\n--------------MENU DE OPCIONES--------------\n");
            printf("\n1.  MOSTRAR CLIENTES");
            printf("\n2.  MOSTRAR MASCOTAS");
            printf("\n3.  MOSTRAR CLIENTES CON SUS MASCOTAS");
            printf("\n4.  CARGAR MASCOTA");
            printf("\n5.  ELIMINAR MASCOTA");
            printf("\n6.  MODIFICAR MASCOTA");
            printf("\n7.  CARGAR CLIENTE");
            printf("\n8.  ELIMINAR DUENIO EN CASCADA");
            printf("\n9.  ORDENAR MASCOTAS POR TIPO Y LISTAR CON SUS DUENIOS");
            printf("\n10. MODIFICAR DUENIO");
            printf("\n11. LISTAR CLIENTES CON MAS DE UNA MASCOTA");
            printf("\n12. LISTAR MASCOTAS CON MAS DE 3 AÑOS CON SUS DUENIOS");
            printf("\n13. LISTAR LAS MASCOTAS POR UN TIPO EN PARTICULAR");
            printf("\n14. ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS Y LISTARLOS");
            printf("\n15. ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS Y ORDEN ALFABETICO Y LISTAR");
            printf("\n16. PROMEDIO DE EDAD ENTRE MASCOTAS");
            printf("\n17. PROMEDIO DE EDAD ENTRE MASCOTAS POR TIPO");
            printf("\n18. PORCENTAJE DE MUJERES SOBRE EL TOTAL DE CLIENTES");
            printf("\n19. LISTAR DUENIOS CON MASCOTAS DEL MISMO SEXO");
            printf("\n20. Salir");
            printf("\n--------------------------------------------\n");

        utn_getNumero(&opcion,"\nIngrese la opcion:","\nERROR.",1,20,2);

        switch(opcion)
        {
        case 1:
            printf("\n -----MOSTRAR CLIENTES-----");
            cli_imprimirArray(arrayClientes,QTY_CLIENTES);
            break;
        case 2:
            printf("\n -----MOSTRAR MASCOTAS-----");
            info_PrintMascotasConSusDuenios(arrayMascotas,QTY_MASCOTAS,arrayClientes,QTY_CLIENTES,arrayRazaMascotas,QTY_RAZAS);
            break;
        case 3:
            printf("\n --------MOSTRAR CLIENTES CON SUS MASCOTAS--------\n");
            info_PrintClientesConSusMascotas(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS);
            break;
        case 4:
            printf("\n --------CARGAR MASCOTA--------\n");
            indiceMascota = pets_getEmptyIndex(arrayMascotas,QTY_MASCOTAS);
            if(indiceMascota >= 0)
            {
                cli_imprimirArray(arrayClientes,QTY_CLIENTES);
                if(!utn_getNumero(&auxIdCliente,"\nIngrese el ID del cliente en donde desea cargar la mascota: ","\nERROR.",0,QTY_CLIENTES,2))
                {
                    indiceCliente = cli_BuscarId(arrayClientes,QTY_CLIENTES,auxIdCliente);
                    if(indiceCliente >= 0)
                    {
                        printf("\nID ENCONTRADO CON EXITO!!");
                        if(!raza_imprimirArray(arrayRazaMascotas,QTY_RAZAS) &&
                           !utn_getNumero(&auxIdRaza,"\nIngrese el ID de raza que desea tener su mascota: ","\nERROR.",0,QTY_RAZAS,2))
                        {
                            indiceRaza = raza_BuscarId(arrayRazaMascotas,QTY_RAZAS,auxIdRaza);
                            if(indiceRaza >= 0 && !pets_cargarArray(arrayMascotas,QTY_MASCOTAS,indiceMascota,&idMascota,auxIdRaza,auxIdCliente))
                            {
                                printf("\nID ENCONTRADO CON EXITO!!");
                                printf("\nSe cargo correctamente");
                            }
                        }
                    }
                    else
                    {
                        printf("\nID no registrado.");
                    }
                }
            }
            else
            {
                printf("\nNO HAY MAS LUGAR!!");
            }
            break;
        case 5:
            printf("\n --------ELIMINAR MASCOTA--------\n");
            pets_imprimirArray(arrayMascotas,QTY_MASCOTAS);
            if(!utn_getNumero(&auxIdMascota,"\nIngrese el ID de la mascota que desea eliminar: ","\nERROR.",0,QTY_MASCOTAS,2))
            {
                indiceMascota = pets_buscarId(arrayMascotas,QTY_MASCOTAS,auxIdMascota);
                if(indiceMascota >= 0)
                {
                    printf("\n\t----------------------------------------------------------------------------");
                    printf("\n\t  ID_MASCOTA   -   NOMBRE   -   TIPO   -  EDAD  -  SEXO  -  PESO  -  ESTADO ");
                    printf("\n\t----------------------------------------------------------------------------");
                    pets_imprimir(arrayMascotas,indiceMascota);
                    printf("\n\t----------------------------------------------------------------------------");
                    utn_getChar(&respuesta,"\nEsta seguro que desea eliminar?[s/n]: ","\ERROR.",'s','n',2);
                    if(respuesta == 's')
                    {
                        pets_eliminarArray(arrayMascotas,QTY_MASCOTAS,indiceMascota);
                        printf("\nSe elimino de manera correcta");
                    }
                    else
                    {
                        printf("\nOperacion cancelada");
                    }
                }
                else
                {
                    printf("\nID no registrado.");
                }
            }
            break;
        case 6:
            printf("\n --------MODIFICAR MASCOTA--------\n");
            info_PrintMascotasConSusDuenios(arrayMascotas,QTY_MASCOTAS,arrayClientes,QTY_CLIENTES,arrayRazaMascotas,QTY_RAZAS);
            if(!utn_getNumero(&auxIdMascota,"\nIngrese el ID de la mascota que desea modificar: ","\nERROR.",0,QTY_MASCOTAS,2))
            {
                indiceMascota = pets_buscarId(arrayMascotas,QTY_MASCOTAS,auxIdMascota);
                if(indiceMascota >= 0)
                {
                    printf("\nID encontrado!!");
                    if(!info_ModificarMascota(arrayMascotas,QTY_MASCOTAS,arrayClientes,QTY_CLIENTES,arrayRazaMascotas,QTY_RAZAS,indiceMascota))
                    {
                        printf("\nSe modifico de manera correcta");
                    }
                    else
                    {
                        printf("\nOcurrio un error");
                    }
                }
                else
                {
                    printf("\nID no registrado.");
                }
            }
            break;
        case 7:
            printf("\n --------CARGAR CLIENTE--------\n");
            indiceCliente = cli_getEmptyIndex(arrayClientes,QTY_CLIENTES);
            if(!cli_altaArray(arrayClientes,QTY_CLIENTES,indiceCliente,&idCliente))
            {
                printf("\nSe cargo con exito.");
            }
            else
            {
                printf("\nOcurrio un error.");
            }
            break;
        case 8:
            printf("\n--------Eliminar cliente con sus mascotas (CASCADA)--------");
            cli_imprimirArray(arrayClientes,QTY_CLIENTES);
            utn_getNumero(&idCliente,"\nIngrese el id del cliente que desea eliminar: ","\nERROR.",0,QTY_CLIENTES,2);
            indiceCliente = cli_BuscarId(arrayClientes,QTY_CLIENTES,idCliente);
            if(indiceCliente >= 0)
            {
                printf("\nID registrado.");
                cli_printCliente(arrayClientes,indiceCliente);
                if(!info_eliminarClienteConMascotas(arrayClientes,arrayMascotas,QTY_MASCOTAS,indiceCliente,idCliente))
                {
                    printf("\nEliminado con exito.");
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            }
            else
            {
                printf("\nID no registrado.");
            }
            break;
        case 9:
             printf("\n --------ORDENAR MASCOTAS POR TIPO Y LISTAR CON SUS DUENIOS--------\n");
             if(!utn_getNumero(&ordenMascotas,"\n1. ASCENDENTE\n2. DESCENDENTE\n","\nERROR.",1,2,2))
             {
                 if(!pets_sortMascotasPorTipo(arrayMascotas,QTY_MASCOTAS,ordenMascotas))
                 {
                     printf("\nOrdenado OK.");
                     info_PrintMascotasConSusDuenios(arrayMascotas,QTY_MASCOTAS,arrayClientes,QTY_CLIENTES,arrayRazaMascotas,QTY_RAZAS);
                 }
                 else
                 {
                     printf("\nOcurrio un error.");
                 }
             }
            break;
        case 10:
            printf("\n --------MODIFICAR DUENIO--------\n");
            cli_imprimirArray(arrayClientes,QTY_CLIENTES);
            utn_getNumero(&idCliente,"\nIngrese el ID del cliente a modificar: ","\nERROR.",0,QTY_CLIENTES,2);
            indiceCliente = cli_BuscarId(arrayClientes,QTY_CLIENTES,idCliente);
            if(indiceCliente >= 0)
            {
                printf("\nID registrado.");
                if(!cli_modificarArray(arrayClientes,QTY_CLIENTES,indiceCliente))
                {
                    printf("\nDuenio modificado con exito.");
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            }
            else
            {
                printf("\nID no registrado.");
            }
            break;
        case 11:
            printf("\n------LISTAR CLIENTES CON MAS DE UNA MASCOTA-----");
            if(!info_printClientesConMasDeUnaMascota(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS))
            {
                printf("\nListado con exito.");
            }
            else
            {
                printf("\nOcurrio un error.");
            }
            break;
            case 12:
                printf("\n-----LISTAR MASCOTAS CON MAS DE 3 ANIOS CON SUS DUENIOS-----");
                if(!info_printMascotasConMasAniosYsusDuenios(arrayMascotas,QTY_MASCOTAS,arrayClientes,QTY_CLIENTES,3))
                {
                    printf("\nListado con exito.");
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            break;
            case 13:
                printf("\n-----LISTAR LAS MASCOTAS POR UN TIPO EN PARTICULAR-----");
                if(!utn_getNumero(&auxTipoMascota,"\n1. PERRO\n2. GATO\n3. RARO\nIngrese una opcion: ","\nERROR.",1,3,2))
                {
                    pets_printMascotaPorTipo(arrayMascotas,QTY_MASCOTAS,auxTipoMascota);
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            break;
            case 14:
                printf("\n-----ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS Y LISTARLOS-----");
                if(!utn_getNumero(&ordenDuenios,"\n1. ASCENDENTE\n2. DESCENDENTE\n","\nERROR.",1,2,2))
                {
                    if(!info_sortDueniosPorCantidadMascotas(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS,ordenDuenios))
                    {
                        printf("\nOrdenado OK.");
                        info_PrintClientesConSusMascotas(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS);

                    }
                    else
                    {
                        printf("\nOcurrio un error.");
                    }
                }
            break;
            case 15:
                printf("\n-------ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS Y ORDEN ALFABETICO Y LISTAR-------");
                if(!utn_getNumero(&ordenDuenios,"\n1. ASCENDENTE\n2. DESCENDENTE\n","\nERROR.",1,2,2))
                {
                    if(!info_sortDueniosPorCantidadMascotasYnombre(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS,ordenDuenios))
                    {
                        printf("\nOrdenado OK.");
                        info_PrintClientesConSusMascotas(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS);

                    }
                    else
                    {
                        printf("\nOcurrio un error.");
                    }
                }
            break;
            case 16:
                printf("\n--------PROMEDIO DE EDAD ENTRE MASCOTAS--------");
                promEdadesMascotas = pets_getPromedioEdades(arrayMascotas,QTY_MASCOTAS);
                if(promEdadesMascotas > 0)
                {
                    pets_imprimirArray(arrayMascotas,QTY_MASCOTAS);
                    printf("\nPromedio de las mascotas: %.3f",promEdadesMascotas);
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            break;
            case 17:
                printf("\n--------PROMEDIO DE EDAD ENTRE MASCOTAS POR TIPO--------");
                pets_imprimirArray(arrayMascotas,QTY_MASCOTAS);
                if(!pets_getPromedioEdadesPorTipo(arrayMascotas,QTY_MASCOTAS,3))
                {
                    printf("\nPromedio sacado con exito.");
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            break;
            case 18:
               printf("\n-------PROMEDIO EDAD DE HOMBRES Y MUJERES-------");
                if(!cli_imprimirArray(arrayClientes,QTY_CLIENTES))
                {
                    cli_getPromedioEdadHombresYmujeres(arrayClientes,QTY_CLIENTES);
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
                /*printf("\n-------PORCENTAJE DE MUJERES SOBRE EL TOTAL DE CLIENTES-------");
                if(!cli_imprimirArray(arrayClientes,QTY_CLIENTES))
                {
                    cli_getPorcentajeQueHayDeMujeres(arrayClientes,QTY_CLIENTES);
                }
                else
                {
                    printf("\nOcurrio un error.");
                }*/
            break;
            case 19:
                printf("\n------LISTAR DUENIOS CON MASCOTAS DEL MISMO SEXO------");
                if(!info_printDueniosConMascotasDelMismoSexo(arrayClientes,QTY_CLIENTES,arrayMascotas,QTY_MASCOTAS,arrayRazaMascotas,QTY_RAZAS))
                {
                    printf("\nLista mostrada con exito.");
                }
                else
                {
                    printf("\nOcurrio un error.");
                }
            break;
        }

    }while(opcion!=20);
    return 0;
}








