#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int cont = 0;
    char auxNombre[120];
    char auxId[100];
    char auxHoras[120];
    char auxSueldo[120];

    if(pFile == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
        while(!feof(pFile))
        {
            pEmp = employee_new();
            if(pEmp !=NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);
                pEmp = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
            }
            if(pEmp != NULL)
            {
                ll_add(pArrayListEmployee,(Employee*)pEmp);
                cont++;
            }
        }
        printf("carga de empleados exitosa!!!\n");
    }
    return cont;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int todoOk = 0;
    if(pFile == NULL)
    {
        printf("error, no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else{
        while(!feof(pFile)){
            pEmp = employee_new();
            fread(pEmp,sizeof(Employee),1,pFile);
            if(feof(pFile))
            {
                break;
            }
            ll_add(pArrayListEmployee,pEmp);
        }
        todoOk = 1;
    }
    return todoOk;
}
