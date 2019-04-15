#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int Opcion(char nombre, char apellido, char sexo, int legajo)
{
    int opcion;

    printf("Elija una opcion...\n");
    printf("\n 1_alta de empleado... \n 2_baja de empleado... \n 3_modificacion empleado...\n 4_ordenar empleados...\n 5_lista empleados...6_salir \n");
    scanf("%d",&opcion);

    return opcion;
}
