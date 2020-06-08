#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "Raza.h"

#define QTY_NOMBRE 51
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int   idMascota;
    int   idCliente;
    char  nombre[QTY_NOMBRE];
	int   tipo;
    int   idRaza;
	int   edad;
	float peso;
	char  sexo;
	int   isEmpty;
}Mascota;

int pets_inicializarArray(Mascota array[], int limite);

//int pets_HardcodeoArray(Mascota array[]);
int pets_altaForzadaArray(Mascota array[],int limite, int indice, int* idMascota, int idCliente, int idRaza, char nombre[],int tipo,int edad,float peso,char sexo);

int pets_imprimir(Mascota elemento[], int indice);

int pets_imprimirArray(Mascota array[], int limite);

int pets_cargarArray(Mascota array[],int limite, int indice, int* idMascota, int idRaza, int idCliente);

int pets_getEmptyIndex(Mascota array[],int limite);

int pets_buscarId(Mascota array[], int limite, int idMascota);

int pets_eliminarArray(Mascota array[], int limite, int indice);

int pets_modificarArray(Mascota array[], int limite, int indice);

int pets_menuModificar();

int pets_menuModificarMascotaBis();

int pets_swapArray(Mascota array[], int i, int j);

int pets_sortMascotasPorTipo(Mascota array[], int limite, int order);

int pets_printMascotaPorTipo(Mascota array[], int limite, int tipoMascota);

float pets_getPromedioEdades(Mascota array[], int limite);

int pets_getPromedioEdadesPorTipo(Mascota array[], int limite, int cantidadTipos);

#endif // MASCOTA_H_INCLUDED
