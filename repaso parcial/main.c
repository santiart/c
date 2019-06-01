#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#include "input.h"
#define MAX_EMPLEADOS 2
#define TAM_SECTORES 5
#define TAM_MENUES 10

int main()
{
    int flag = 0;
    int id=0;
    eEmpleado empleados[MAX_EMPLEADOS];

    eSector sectores[TAM_SECTORES];
    eMenu menues[TAM_MENUES];
    iniciarlizarEmpleados(empleados, MAX_EMPLEADOS);
    inicializarSectores(sectores, TAM_SECTORES);
    inicializarMenus(menues, TAM_MENUES);

    char contMenu ='n';

    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 1:
            if(altaEmpleado(empleados, MAX_EMPLEADOS, sectores, TAM_SECTORES,id)==1)
            {
                flag = 1;
                id++;
            }
            break;
        case 2:
            if(flag == 1)
            {
                modificarEmpleado(empleados, MAX_EMPLEADOS);
            }
            else
            {
                printf("No se puede modificar ningun empleado hasta haber realizado un alta primero.\n");
                system("pause");
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            mostrarEmpleados(empleados, MAX_EMPLEADOS);
            system("pause");
            break;
        case 6:
            printf("Desea salir, ingrese 'n' o 's': ");
            fflush(stdin);
            contMenu = tolower(contMenu);
            scanf("%c",&contMenu);
            if(contMenu == 's');
            {
                break;
            }
            break;
        default:
            printf("has ingresado una opcion incorrecta.");
        }
    }
    while(contMenu=='n');

    return 0;
}
