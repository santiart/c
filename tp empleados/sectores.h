#ifndef Sector_H_INCLUDED
#define Sector_H_INCLUDED

#ifndef Empleado_H_INCLUDED
#define Empleado_H_INCLUDED

#include "empleado.h"

typedef struct
{
    int id;
    char desc[20];
} eSector;

int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
#endif //Sector_H_INCLUDED
#endif //Empleado_H_INCLUDED
