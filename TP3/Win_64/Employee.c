#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->horasTrabajadas = 0;
    }
    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){

    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    int todoOk = 0;
    if(nuevoEmpleado != NULL)
    {
        if(employee_setId(nuevoEmpleado,atoi(idStr))==1)
        {
            if(employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))==1)
            {
                if(employee_setNombre(nuevoEmpleado,nombreStr)==1)
                {
                    if(employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))==1)
                    {
                        todoOk = 1;
                    }
                }
            }
        }
        if(todoOk == 0)
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }

    }
    return nuevoEmpleado;
}
int employee_setId(Employee* this,int id){

    int todoOk = 0;
    if(this != NULL && id > 0 && id > 100000)
    {
        this->id= id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id){

    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre){

    int todoOk = 0;
    if(this != NULL && nombre != NULL){
        *(this->nombre) = *nombre;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre){

    int todoOk = 0;
    if(this != NULL && *nombre != NULL){
        strcpy(*(this->nombre),*nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;
    if(this != NULL && sueldo > 0 && sueldo > 100000)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{

    int todoOk = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
