#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

#define QTY_PROVINCIA 51
#define QTY_DESCRIPCION 250
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int  idLocalidad;
    char provincia[QTY_PROVINCIA];
    int  codigoPostal;
    char descripcion[QTY_DESCRIPCION];
    int  isEmpty;

}Localidad;

int local_inicializarArray(Localidad array[], int limite);

int local_altaForzada(Localidad array[], int limite, int indice, int* idLocalidad, char provincia[], int codigoPostal ,char descripcion[]);

int local_imprimirArray(Localidad array[], int limite);
/*
int local_CargarArray(Localidad array[],int limite, int indice,int* idLocalidad);

int local_BuscarId(Localidad array[],int limite, int idRaza);
*/

#endif // LOCALIDAD_H_INCLUDED
