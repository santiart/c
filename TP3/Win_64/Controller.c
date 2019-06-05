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
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int tam)
{
    int todoOK = 1;

    return todoOK;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int tam)
{
    return 1;
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
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char ext[] = ".csv";
    char nombreArchivo[100];
    strcpy(nombreArchivo,path);
    strcat(nombreArchivo,ext);
    FILE* f;
    f = fopen(nombreArchivo,"r");
    if(f == NULL){
        printf("no se pudo abrir el archivo...\n");
        todoOk = 1;
        return todoOk;
    }
    fprintf("Id              Full_Name            Hours Worked           Salary \n");
    for(int i=0 ; i<tam ; i++){
        fprintf(f,"%d,%s,%d,%d",pArrayListEmployee->)
    }
    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    char ext[] = "bin.";
    char nombreArchivo[100];
    strcpy(nombreArchivo,path);
    strcat(nombreArchivo,ext);
    FILE* f;

    f = fopen(nombreArchivo,"rb");
    if(f == NULL){
        printf("no se pudo abrir el archivo...\n");
        todoOk = 0;
        return todoOk;
    }
    for(int i=0 ; i<tam ; i++){
        fwrite(*(pArrayListEmployee+i),sizeof(LinkedList),1,f);
    }
    fclose(f);
    return todoOk;
}
