#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#define  TAM 3


typedef struct
{
    char nombre[20];
    char apellido[20];
    int legajo;
    char sexo;
    int sueldo;
    int estado;
} eEmpleado;


void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam);
void altaDeEmpleado(eEmpleado vec [], int tam);

int main()
{
    int opcion;
    int flagAlta;
    int flagLista;
    char seguir='s';
    eEmpleado lista[TAM]= {{"juan", "perez", 1111, 'm', 53000,1},{"ana", "sanchez", 2222, 'f', 40000,0}}; //hardcodeo


    do
    {
        printf("         ::A B M      E M P L E A D O S::      ");
        printf("\n\n");
        opcion=Opcion(eEmpleado.nombre,eEmpleado.apellido,eEmpleado.sexo,eEmpleado.legajo,eEmpleado.sueldo);

        switch(opcion)
        {
        case 1:

            if(flagLista==1)
            {
                flagAlta=1;
                printf("\n alta empleado");
                break;
            }
            else
            {
                printf("seleccione primero la lista");
                break;
            }
        case 2:
            printf("\n baja empleado");
            break;

        case 3:
            printf("\n modificacion empleados");
            break;

        case 4:

            if(flagAlta==1)
            {
                printf("\n ordenar empleados");
                break;
            }
        case 5:
            mostrarEmpleados(lista, TAM);
        /*
        flagLista=1;
        printf("\n listar empleados");
        break;
        */
        case 6:
            printf("\n confirmar salida?...");
            fflush(stdin);
            seguir=getche();

            if( tolower(seguir)== 'S')
            {
                seguir='n';
            }
            break;
        default:
            printf("\n Opcion invalida, intente de nuevo...");
            system("break");
        }
    }
    while(seguir=='s');

    system("pause");
    system("cls");

    return 0;
}

void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    int estado;
    for(int i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eEmpleado emp)
{
    printf("\n%d    %s    %c    %.2f \n ",emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo);
}

void mostrarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    int contador=0;
    printf("\n  legajo   nombre    apellido   sexo    sueldo ");

    for(i=0; i<tam; i++)
    {
        if(vec[i].estado==1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
        if(contador=0)
        {
            printf("\n no hay empleados para mostrar");
        }
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice=-1;

    for (i=0; i<tam; i++)
    {
        if(vec[i].estado==0)
        {
            indice=1;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec [], int tam, int legajo)
{
    int i;
    int indice=-1;

    for(i=0; i<tam; i++)
    {
        if((vec[i].estado==1)&&(vec[i].legajo == legajo))
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaDeEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;

    indice=buscarLibre(vec, tam)

           if(indice==-1)
    {
        printf("\n no hay lugar disponible en el sistema");
    }
    else
    {
        printf("\n ingrese el legajo: ");
        scanf("%d",&legajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta!=-1)
        {
            printf("\n ya existe un empleado con ese legajo en el sistema");
            mostrarEmpleado(vec, esta);
        }
        else
        {
            vec[indice].legajo=legajo;

            printf("\n ingrese un nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}
