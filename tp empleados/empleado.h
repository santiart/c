#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct
{
    int dia, mes,anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    int estado;
    eFecha fechaNac;
} eEmpleado;


void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int legajo);
void altaDeEmpleado(eEmpleado vec [], int tam);
void modificarEmpleado(eEmpleado vec [], int tam);
