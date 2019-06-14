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
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

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
                if(flag == 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag = 1;
                    break;
                }
                else
                {
                    printf("el archivo ya se ha abierto antes...\n");
                }
                break;
            case 2:
                if(flag == 0)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    flag = 1;
                    break;
                }
                else
                {
                    printf("el archivo ya se ha abierto antes...\n");
                }
                break;
            case 3:
                if(flag == 1)
                {
                    controller_addEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("cargue el archivo antes de dar de alta...\n");
                }
                break;
            case 4:
                if(flag == 1)
                {
                    controller_editEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("debe ingresar a los empleados primero...\n");
                }
                break;
            case 5:
                if(flag == 1)
                {
                    controller_removeEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("debe ingresar empleados primero...\n");
                }
                break;
            case 6:
                if(flag == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
                break;
            case 7:
                if(flag == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                    break;
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
                break;
            case 8:
                if(flag == 1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    break;
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
                break;
            case 9:
                if(flag == 1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    break;
                }
                else
                {
                    printf("primero debe ingresar a los empleados...\n");
                }
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
