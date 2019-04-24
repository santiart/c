#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char desc[20];
}eSector;

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
    char almuerzo[20];
}eAlmuerzo;

typedef struct
{
    int legajo;
    char apellido[20];
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;
    eFecha fechaIng;
    eSector idSector;
    eAlmuerzo comida;
}eEmpleado;

void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);


