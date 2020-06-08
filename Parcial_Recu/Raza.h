#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

#define QTY_NOMBRE 51
#define QTY_PAIS 25
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int  idRaza;
    char nombre[QTY_NOMBRE];
    char pais[QTY_PAIS];
    int  isEmpty;
}Raza;

int raza_inicializarArray(Raza array[], int limite);

//int raza_HardcodeoArray(Raza array[]);

int raza_altaForzada(Raza array[], int limite, int indice, int* idRaza, char nombre[], char pais[]);

int raza_imprimirArray(Raza array[], int limite);

int raza_CargarArray(Raza array[],int limite, int indice,int* idRaza);

int raza_BuscarId(Raza array[],int limite, int idRaza);

#endif // RAZA_H_INCLUDED
