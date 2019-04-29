#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    char desc[20];
} eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    int estado;
    int idSector;
} eEmpleado;


void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector, int sentido);
int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
