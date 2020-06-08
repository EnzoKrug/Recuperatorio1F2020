#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#define QTY_CLIENTES 10
#define QTY_MASCOTAS 20
#define QTY_RAZAS 50

#include "Cliente.h"
#include "Mascota.h"
#include "Raza.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void info_PrintMascotasConSusDuenios(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite);

void info_PrintClientesConSusMascotas(Cliente cli_Array[], int cli_limite, Mascota pet_Array[], int pet_limite);

int info_printMascota(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite, int indice);

int info_ModificarMascota(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, Raza raza_array[], int raza_limite, int indice);

int info_eliminarClienteConMascotas(Cliente cli_array[], Mascota pet_array[], int pet_limite, int indice, int idCliente);

int info_printClientesConMasDeUnaMascota(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite);

int info_printMascotasConMasAniosYsusDuenios(Mascota pet_array[], int pet_limite, Cliente cli_array[], int cli_limite, int anios);

int info_sortDueniosPorCantidadMascotas(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, int order);

int info_sortDueniosPorCantidadMascotasYnombre(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, int order);

int info_printDueniosConMascotasDelMismoSexo(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, Raza raza_array[], int raza_limite);

int info_printCliente(Cliente cli_array[], int cli_limite, Mascota pet_array[], int pet_limite, Raza raza_array[], int raza_limite, int indice);

#endif // INFORMES_H_INCLUDED
