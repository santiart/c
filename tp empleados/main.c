#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"
#define  TAM 4
#define TAMSEC 5


int main()
{
    int opcion;
    char seguir='s';
    char confirmar;
    int sentidoA = 0;
    eSector sectores[]=
    {
        {1,"sistemas"},
        {2,"RRHH"},
        {3,"compras"},
        {4,"ventas"},
        {5,"legales"},
    };
    eEmpleado lista[TAM];
    /*
    {
        {1111,"juan", "perez", 'm', 53000,1,1},
        {2222,"ana", "sanchez",'f', 40000,1,2},
        {3333,"pablo","dominguez",'m',38000,1,4}
    }; //hardcodeo
    */
    inicializarEmpleados(lista, TAM);

    do
    {
        printf("\n\n");
        system("cls");
        printf("         ::A B M      E M P L E A D O S::      \n\n");
        printf(" 1- Alta Empleado\n 2- Baja Empleado\n 3- Modificacion Empleado\n 4- Ordenar Empleados\n 5- Listar Empleados\n 6- Listar sectores con empleados\n 7- Cantidad de empleados por sector\n 8- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


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
            ordenarEmpleados(lista,TAM, sectores, TAMSEC, sentidoA );
            system("pause");
            break;
        case 5:
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 6:
            mostrarSectoresConEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;
        case 7:
            mostrarCantEmpleadosXSector(lista,TAM,sectores,TAMSEC);
            system("pause");
            break;
        case 8:
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

