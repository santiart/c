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
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->sueldo = 0;
        nuevoEmpleado->horasTrabajadas = 0;
    }
    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* nuevoEmpleado = employee_new();
    int todoOk = 1;
    if(nuevoEmpleado != NULL)
    {

        if((employee_setId(nuevoEmpleado,atoi(idStr)))==1)
        {
            if(employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))==1)
            {
                if(employee_setNombre(nuevoEmpleado,nombreStr)==1)
                {
                    if(employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))==1)
                    {
                        todoOk = 0;
                    }
                }
            }
        }
        if(todoOk == 1)
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }

    }
    return nuevoEmpleado;
}
int employee_setId(Employee* this,int id)
{

    int todoOk = 0;
    if(this != NULL && id >= 0)
    {
        this->id= (id+1);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{

    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk = 0;
    if(this != NULL && strlen(nombre)>2)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int todoOk = 0;
    if(this != NULL && sueldo > 0 && sueldo < 200000)
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
    if(this != NULL && horasTrabajadas >=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if(this != NULL && horasTrabajadas >=0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_sortName(void* pVoid1, void* pVoid2)
{
    char* name1 = (char*)malloc(sizeof(char));
    char* name2 = (char*)malloc(sizeof(char));
    int todoOk = 0;
    employee_getNombre(pVoid1,name1);
    employee_getNombre(pVoid2,name2);

    if(strcmp(name1,name2)>0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int employee_sortSalary(void* pVoid1, void* pVoid2)
{
    int salary1,salary2,todoOk;
    employee_getSueldo(pVoid1,&salary1);
    employee_getSueldo(pVoid2,&salary2);
    if(salary1>salary2)
    {
        todoOk = 1;
    }
    return todoOk;
}

int employee_sortHours(void* pVoid1,void* pVoid2)
{
    int hours1,hours2,todoOk;
    employee_getHorasTrabajadas(pVoid1,&hours1);
    employee_getHorasTrabajadas(pVoid2,&hours2);
    if(hours1>hours2)
    {
        todoOk = 1;
    }
    return todoOk;
}

int employee_sortId(void* pVoid1,void* pVoid2)
{
    int Id1,Id2,todoOk;
    employee_getId(pVoid1,&Id1);
    employee_getId(pVoid2,&Id2);
    if(Id1>Id2)
    {
        todoOk = 1;
    }
    return todoOk;
}
