#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include <conio.h>


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOK = 0;
    f = fopen(path,"r");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parser_EmployeeFromText(f,pArrayListEmployee);
        todoOK = 1;
        fclose(f);

    }
    return todoOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int todoOk = 0;
    int tam;

    f = fopen(path,"rb");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
    }
    printf("craga binaria de empleados exitosa!!!\n");
    fclose(f);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp = employee_new();
    Employee* pEmpAux = employee_new();
    int todoOk = 0;
    int i;
    int idMax = 0;
    int auxSueldoInt;
    int auxHorasInt;
    char* auxNombre = (char*)malloc(sizeof(char)*100);
    char* auxHoras = (char*)malloc(sizeof(char)*50);
    char* auxSueldo =(char*)malloc(sizeof(char)*50);

    for(i=0 ; i<ll_len(pArrayListEmployee); i++)
    {
        pEmpAux = (Employee*)ll_get(pArrayListEmployee,i);
        if(pEmpAux->id>idMax)
        {
            idMax = pEmpAux->id;
        }
    }

    if(pArrayListEmployee != NULL)
    {

        while(!getStringLetras("ingrese el nombre del empleado:\n",auxNombre))
        {
            printf("intente de nuevo...\n");
        }
        fflush(stdin);
        while(!getStringNumeros("ingrese el sueldo del empleado:\n",auxSueldo))
        {
            printf("intente de nuevo...\n");
        }
        while(!getStringNumeros("ingrese la cantidad de horas trabajadas por el empleado:\n",auxHoras))
        {
            printf("intente de nuevo...\n");
        }
        auxSueldoInt = atoi(auxSueldo);
        auxHorasInt = atoi(auxHoras);
        if( pEmp != NULL)
        {
            employee_setId(pEmp,idMax);
            employee_setNombre(pEmp,auxNombre);
            employee_setSueldo(pEmp,auxSueldoInt);
            employee_setHorasTrabajadas(pEmp,auxHorasInt);
            ll_add(pArrayListEmployee,pEmp);
            todoOk = 1;
        }
        printf("alta de empleado exitosa!!!\n\n");
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int todoOk
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int todoOk = 0;
    int i;
    char* auxOption = (char*)malloc(sizeof(char));
    int option;
    int flag = 0;
    int Id;
    char* auxId = (char*)malloc(sizeof(char));
    int Sueldo;
    int Horas;
    char* auxnombre = (char*)malloc(sizeof(char));
    char* auxSueldo = (char*)malloc(sizeof(char));
    char* auxHoras = (char*)malloc(sizeof(char));

    if(pArrayListEmployee != NULL)
    {
        while(!getStringNumeros("ingrese el id del empleado a modificar:\n",auxId))
        {
            printf("intente de nuevo...\n");
        }
        Id = atoi(auxId);
        for(i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);

            if(pEmp->id == Id)
            {
                pEmp = ll_pop(pArrayListEmployee,i);
                flag = 1;
                printf("usted ha seleccionado al empleado: \n");
                printf("%d  %s  %d  %d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
                break;
            }
        }
        if(flag == 1)
        {
            do
            {
                printf("    ::M O D I F I C A C I O N  D E L  E M P L E A D O::   \n");
                printf("1_Modificar el Nombre              2_Modificar el Sueldo  \n");
                printf("3_Modificar la cantidad de horas   4_Salir...             \n");
                while(!getStringNumeros("ingrese una opcion: \n",auxOption))
                {
                    printf("intente ingresar la opcion nuevamente...\n");
                }
                option = atoi(auxOption);
                switch(option)
                {
                case 1:
                    while(!getStringLetras("ingrese el nuevo nombre: \n",auxnombre))
                    {
                        printf("intente de nuevo...\n");
                    }
                    employee_setNombre(pEmp,auxnombre);
                    todoOk = 1;
                    printf("modificacion de empleado exitosa!!!\n");
                    break;
                case 2:
                    while(!getStringNumeros("ingrese el nuevo sueldo:\n",auxSueldo))
                    {
                        printf("intente de nuevo...\n");
                    }
                    Sueldo = atoi(auxSueldo);
                    employee_setSueldo(pEmp,Sueldo);
                    todoOk = 1;
                    printf("modificacion de empleado exitosa!!!\n");
                    break;
                case 3:
                    while(!getStringNumeros("ingrese la nueva cantidad de horas:\n",auxHoras))
                    {
                        printf("intente de nuevo...\n");
                    }
                    Horas = atoi(auxHoras);
                    employee_setHorasTrabajadas(pEmp,Horas);
                    todoOk = 1;
                    printf("modificacion de empleado exitosa!!!\n");
                    break;
                case 4:
                    printf("hasta luego\n");
                    todoOk = 1;
                    break;
                default:
                    printf("ha ingresado una opcion incorrecta, intente de nuevo...\n");
                }
                system("pause");
                system("cls");
            }
            while(option != 4);
            ll_push(pArrayListEmployee,i,pEmp);
        }
        else
        {
            printf("el id no existe...\n");
        }
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmp = employee_new();
    int id;
    int i;
    char respuesta;
    char* auxId = (char*)malloc(sizeof(char));
    int flag = 0;

    while(!getStringNumeros("ingrese el id del empleado a dar de baja\n",auxId))
    {
        printf("intente de nuevo...\n");
    }
    id = atoi(auxId);
    for(i=0 ; i<ll_len(pArrayListEmployee); i++)
    {
        pEmp = (Employee*)ll_get(pArrayListEmployee,i);
        if(pEmp->id == id)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("usted ha seleccionado al empleado: \n");
        printf("Id   Nombre   Horas Trabajadas   Sueldo \n");
        printf("%d  %10s  %10d   %10d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
    }
    printf("desea continuar con la baja?: (s/n)\n");
    fflush(stdin);
    respuesta = getche();
    printf("\n");
    if(respuesta == 's')
    {
        ll_remove(pArrayListEmployee,i);

        printf("baja de empleado exitosa!!!\n");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tam;
    int todoOk = 1;
    int i;
    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("id   -   name - hours worked  - salary\n");
        for( i = 0; i<tam; i++)
        {
            Employee* pEmp =(Employee*)ll_get(pArrayListEmployee,i);
            printf("%d %10s %10d  %10d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
        }
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    void* pVoid1;
    void* pVoid2;
    char* auxOption =(char*)malloc(sizeof(char));
    int option;
    int todoOk = 0;
    int id1;
    int id2;
    int hours1;
    int hours2;
    int salary1;
    int salary2;
    do
    {
        printf("   :: ORDENAR::              \n");
        printf("1_Por nombre   2_Por id      \n");
        printf("3_Por sueldo   4_Porn sueldo \n");
        printf("5_Salir...                   \n");

        while(!getStringNumeros("ingrese una opcion: \n",auxOption))
        {
            printf("intente de nuevo...\n");
        }
        option = atoi(auxOption);
        switch(option)
        {
            case 1:
                ll_sort(pArrayListEmployee,employee_sortName,1);
                break;

        }
    }while(option != 5);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* pEmp;
    int todoOk = 0;
    int i;
    f = fopen(path,"w");

    if(pArrayListEmployee == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(i=0 ; i<ll_len(pArrayListEmployee) ; i++)
        {
            pEmp = employee_new();
            pEmp = ll_get(pArrayListEmployee, i);
            fprintf(f,"%d,%s,%d,%d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* pEmp;
    int i;
    int todoOk = -1;
    f = fopen(path,"wb");
    if(pArrayListEmployee == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //f = fopen(path,"wb");
        for(i=0 ; i<ll_len(pArrayListEmployee) ; i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmp,sizeof(Employee),1,f);
        }

        fclose(f);
    }
    return todoOk;
}
