#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#define TAM 3
#define TAMSEC 5


int main()
{
    int opcion;
    int opcionM;
    int opcionE;
    int opcionA;
    char seguir = 's';
    char confirmar;
    int sentido;

    eFecha fechas[]=
    {
        {1,"10/02/2000"};
        {2,"3/05/2009"};
        {3,"20/08/2013"};
    }
    eSector sectores[]=
    {
        {1, "Sistemas"};
        {2, "RRHH"};
        {3, "Compras"};
        {4, "Ventas"};
        {5, "Legales"};
    }
    eAlmuerzo menu[]=
    {
        {1,"Ravioles"};
        {2,"Pizza"};
        {3,"Sopa"};
        {4,"Ensalada"};
        {5,"Milanesa"};
    }
    eEmpleado lista[TAM]=
    {
        {1111,"Perez","Juan",'m', 50000,1,1,1,2};
        {1111,"Sanchez","Ana",'f', 45000,1,3,4,5};
        {1111,"Dominguez","Pablo",'m', 23500,1,2},2,4;
    }

    do
    {
        system("cls");
        printf("    ::L I S T A  D E  C O M I D A S::     ");
        printf("   1- Menu Empleados \n 2- Menu Menues \n 3- Menu Almuerzos \n 4- Salir... \n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            do
            {
                printf("\n\n");
                system("cls");
                printf("         ::A B M      E M P L E A D O S::      \n\n");
                printf(" 1- Alta Empleado\n 2- Baja Empleado\n 3- Modificacion Empleado\n 4- Ordenar Empleados\n 5- Listar Empleados\n 6- Listar sectores con empleados\n 7- Cantidad de empleados por sector\n 8- Salir\n\n");
                printf("Ingrese opcion: ");
                scanf("%d", &opcionE);


                switch(opcionE)
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
                    printf("\n Opcion invalida, intente de nuevo...");
                    system("break");
                }
            }
            while(seguir=='s');
            break;

        case 2:

            do
            {

                printf("\n\n");
                system("cls");
                printf("          :: M E N U     M E N U E S::       \n");
                printf(" 1_ Alta de Menu \n 2_ Baja de Menu \n 3_ Modificacion de Menues \n 4_ Listar Menues \n 5_ Salir\n\n");
                scanf("%d",opcionM);

                switch(opcionM)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:


                    break;
                case 4:

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
                    printf("\n Opcion invalida, intente de nuevo...");
                    system("break");

                }

            }
            while (seguir == 's');
        }

    }

    return 0;
}
