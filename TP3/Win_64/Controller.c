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
    int todoOK = 1;
    f = fopen(path,"r");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parser_EmployeeFromText(f,pArrayListEmployee);
        todoOK = 0;

    }
    fclose(f);
    return todoOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee,int tam)
{
    FILE* f;
    int todoOk = 1;

    f = fopen(path,"rb");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
        todoOk = 0;
    }
    printf("craga binaria de empleados exitosa!!!\n");
    fclose(f);
    return todoOk;
}
int controller_autoIncId(LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    pEmp = employee_new();
    int len;
    int id = 0;
    int auxId;
    int prevId;

    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if(len > 0)
        {
            for(int i = 0; i<len ; i++)
            {
                pEmp = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(pEmp,&auxId);
                if(auxId > id)
                {
                    prevId = id;
                    id = auxId;
                    if(prevId + 1 != id)
                    {
                        id = prevId;
                    }
                }
                id++;
            }
        }
        else
        {
            id = 1;
        }
    }

    return id;
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
    Employee* pEmp;
    int todoOk = 1;
    int id;
    int auxSueldoInt;
    int auxHorasInt;
    char auxNombre[100];
    char auxHoras[50];
    char auxSueldo[50];

    if(pArrayListEmployee != NULL)
    {
        id = controller_autoIncId(pArrayListEmployee);
        while(!getStringLetras("ingrese el nombre del empleado:\n",auxNombre))
        {
            printf("intente de nuevo...\n");
        }
        while(!getStringNumeros("ingrese el sueldo del empleado:\n",auxSueldo))
        {
            printf("intente de nuevo...\n");
        }
        auxSueldoInt = atoi(auxSueldo);
        while(!getStringNumeros("ingrese la cantidad de horas trabajadas por el empleado:\n",auxHoras))
        {
            printf("intente de nuevo...\n");
        }
        auxHorasInt = atoi(auxHoras);
        if( pEmp != NULL)
        {
            employee_setId(pEmp,id);
            employee_setNombre(pEmp,auxNombre);
            employee_setSueldo(pEmp,auxSueldoInt);
            employee_setHorasTrabajadas(pEmp,auxHorasInt);
            todoOk = 0;
        }
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
    int todoOk = 1;
    char auxOption[50];
    int option;
    char respuesta = 's';
    char confirmar;
    int idingresado;
    int Id;
    char auxId[50];
    int Sueldo;
    int Horas;
    char auxnombre[100];
    char auxSueldo[50];
    char auxHoras[50];

    if(pArrayListEmployee != NULL)
    {
        while(!getStringNumeros("ingrese el id del empleado a modificar:\n",auxId))
        {
            printf("intente de nuevo...\n");
        }
        Id = atoi(auxId);
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&idingresado);

            if(idingresado == Id)
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
                        todoOk = 0;
                        break;
                    case 2:
                        while(!getStringNumeros("ingrese el nuevo sueldo:\n",auxSueldo))
                        {
                            printf("intente de nuevo...\n");
                        }
                        Sueldo = atoi(auxSueldo);
                        employee_setSueldo(pEmp,Sueldo);
                        todoOk = 0;
                        break;
                    case 3:
                        while(!getStringNumeros("ingrese la nueva cantidad de horas:\n",auxHoras))
                        {
                            printf("intente de nuevo...\n");
                        }
                        Horas = atoi(auxHoras);
                        employee_setHorasTrabajadas(pEmp,Horas);
                        todoOk = 0;
                        break;
                    case 4:
                        printf("¿desea salir? (s/n)\n");
                        fflush(stdin);
                        confirmar = getche();
                        if(tolower(confirmar)=='s')
                        {
                            respuesta = 'n';
                        }
                        todoOk = 0;
                        break;
                    default:
                        printf("ha ingresado una opcion incorrecta, intente de nuevo...\n");
                    }
                    system("pause");
                    system("cls");
                }
                while((respuesta = 's'));
            }
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
    Employee* pEmp;
    int todoOk;

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
    Employee* pEmp = employee_new();
    int tam;
    int todoOk = 1;
    int id;
    int sueldo;
    int horas;
    char nombre[100];
    tam = ll_len(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        printf("id,name,hours worked,salary\n");
        for(int i = 0; i<tam; i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&id);
            employee_getNombre(pEmp,nombre);
            employee_getHorasTrabajadas(pEmp,&horas);
            employee_getSueldo(pEmp,&sueldo);
            printf("%d,- %10s - %10d - %10d\n\n",id,nombre,horas,sueldo);
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
    int* auxId;
    char* auxNombre;
    int* auxSueldo;
    int* auxHoras;
    char ext[] = ".csv";
    char nombreArchivo[100];

    strcpy(nombreArchivo,path);
    strcat(nombreArchivo,ext);


    if(pArrayListEmployee == NULL && path == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        f = fopen(nombreArchivo,"r");
        auxId = malloc(sizeof(int));
        auxNombre = malloc(sizeof(char));
        auxHoras = malloc(sizeof(int));
        auxSueldo = malloc(sizeof(int));
        fprintf(f,"Id              Full_Name            Hours Worked           Salary \n");
        for(int i=0 ; i<ll_len(pArrayListEmployee) ; i++)
        {
            pEmp = ll_get(pArrayListEmployee, i);
            employee_getId(pEmp,auxId);
            employee_getNombre(pEmp,auxNombre);
            employee_getHorasTrabajadas(pEmp,auxHoras);
            employee_getSueldo(pEmp,auxSueldo);
            fprintf(f,"%d,%s,%d,%d",*auxId,*auxNombre,*auxHoras,*auxSueldo);
        }
        free(auxId);
        free(auxNombre);
        free(auxHoras);
        free(auxSueldo);
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
    int todoOk = -1;
    char ext[] = ".csv";
    char nombreArchivo[100];
    strcpy(nombreArchivo,path);
    strcat(nombreArchivo,ext);
    f = fopen(nombreArchivo,"wb");
    if(pArrayListEmployee == NULL && path == NULL )
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        f = fopen(path,"wb");
        for(int i=0 ; i<ll_len(pArrayListEmployee) ; i++)
        {
            pEmp = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmp,sizeof(Employee),1,f);
        }
        fclose(f);
    }
    return todoOk;
}
