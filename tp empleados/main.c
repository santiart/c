#ifndef Empleado_h_INCLUDED
#define Empleado_h_INCLUDED
#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAMSEC 5
#define TAM 100


int main()
{
    int opcion;
    char seguir='s';
    char confirmar;
    char auxOpcion[20];
    eSector sectores[]=
    {
        {1,"sistemas"},
        {2,"RRHH"},
        {3,"compras"},
        {4,"ventas"},
        {5,"legales"},
    };
    eEmpleado lista[TAM];

    inicializarEmpleados(lista, TAM);

    do
    {
        printf("\n\n");
        system("cls");
        printf("         ::A B M      E M P L E A D O S::      \n\n");
        printf(" 1- Alta Empleado\n 2- Baja Empleado\n 3- Modificacion Empleado\n 4- Listar Empleados \n 5- Salir\n\n");
        while(!getStringNumeros("ingrese una opcion: \n", auxOpcion))
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOpcion);

        switch(opcion)
        {
        case 1:
            altaEmpleado(lista, TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 2:
            bajaEmpleado(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 3:
            modificarEmpleado(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 4:
            listarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 5:
            printf("\n confirmar salida s/n?...");
            fflush(stdin);
            confirmar=getche();

            if( tolower(confirmar)== 's')
            {
                seguir='n';
            }
            break;
        default:
            printf("\n Opcion invalida, intente de nuevo... \n");
            system("pause");
            system("break");
        }
    }
    while(seguir=='s');

    return 0;
}
#endif // Empleado_h_INCLUDED
