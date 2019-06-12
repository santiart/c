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

                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data,csv",listaEmpleados);
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
