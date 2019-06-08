#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


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
    if(f == NULL){
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else{
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
    if(f == NULL){
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else{
        parser_EmployeeFromBinary(f,pArrayListEmployee);
        todoOk = 0;
    }
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

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
    return 1;
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
        fprintf("Id              Full_Name            Hours Worked           Salary \n");
        for(int i=0 ; i<tam ; i++)
        {
            pEmp = ll_get(pArrayListEmployee, i);
            employee_getId(pEmp,auxId);
            employee_getNombre(pEmp,auxNombre);
            employee_getHorasTrabajadas(pEmp,i);
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
