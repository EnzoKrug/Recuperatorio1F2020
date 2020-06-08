#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define QTY_NOMBRE 51
#define QTY_APELLIDO 51
#define QTY_LOCALIDAD 40
#define QTY_TELEFONO 13
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int  idCliente;
    char nombre[QTY_NOMBRE];
	char apellido[QTY_APELLIDO];
	char localidad[QTY_LOCALIDAD];
	char telefono[QTY_TELEFONO];
	int  edad;
	char sexo;
	int  isEmpty;
}Cliente;

int cli_inicializarArray(Cliente array[],int limite);

//int cli_HardcodeoArray(Cliente array[]);

int cli_altaForzadaArray(Cliente array[],int limite, int indice, int* idCliente, char nombre[],char apellido[],char localidad[],char telefono[], int edad, char sexo);

int cli_printCliente(Cliente elemento[], int indice);

int cli_imprimir(Cliente elemento[], int indice);

int cli_imprimirArray(Cliente array[],int limite);

int cli_BuscarId(Cliente array[],int limite,int idCliente);

int cli_altaArray(Cliente array[],int limite, int indice, int* id);

int cli_getEmptyIndex(Cliente array[], int limite);

int cli_menuModificarDuenio();

int cli_modificarArray(Cliente array[], int limite, int indice);

int cli_swapArray(Cliente array[], int i, int j);

int cli_getPromedioEdadHombresYmujeres(Cliente array[],int limite);

int cli_getPorcentajeQueHayDeMujeres(Cliente array[], int limite);

#endif // CLIENTE_H_INCLUDED
