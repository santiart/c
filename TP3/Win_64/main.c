#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.CSV (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    char auxOption[50];
    int flagT = 0;
    int flagB = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagCargaT = 0;
    int flagCargaB = 0;
    do{
            printf("              :: A B M   E M P L E A D O S ::                     \n");
            printf("1_Cargar empleados desde texto  2_Cargar empleados desde binario  \n");
            printf("3_Alta de empleado              4_Modificar empleado              \n");
            printf("5_Baja de empleado              6_Listar empleados                \n");
            printf("7_Ordenar empleados             8_Guardar empleados en texto      \n");
            printf("9_Guardar empleados en binario  10_Salir...                       \n");
            while(!getStringNumeros("ingrese una opcion:\n",auxOption))
            {
                printf("intente de nuevo...\n");
            }
            option = atoi(auxOption);
        switch(option)
        {
            case 1:
                if(flagT == 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flagT = 1;
                    flagCargaT = 1;
                }
                else
                {
                    printf("el archivo ya se ha abierto antes...\n");
                }
                break;
            case 2:
                if(flagB == 0)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    flagB = 1;
                    flagCargaB = 1;
                }
                else
                {
                    printf("el archivo ya se ha abierto antes...\n");
                }
                break;
            case 3:
                if(flagCargaT == 1 || flagCargaB == 1)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("cargue el archivo antes de dar de alta...\n");
                }
                break;
            case 4:
                if(flagCargaT == 1 || flagCargaB == 1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("debe ingresar a los empleados primero...\n");
                }
                break;
            case 5:
                if(flagCargaT == 1 || flagCargaB == 1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("debe ingresar empleados primero...\n");
                }
                break;
            case 6:
                if(flagCargaT == 1 || flagCargaB == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
                break;
            case 7:
                if(flagCargaT == 1 || flagCargaB == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data,bin",listaEmpleados);
                break;
            case 10:
            printf("hasta luego\n");
            break;
            default:
                printf("opcion inexitente...\n");
                break;
        }
    system("pause");
    system("cls");
    }while(option != 10);
    return 0;
}
