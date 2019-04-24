#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"


void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    for( i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    char consigioNombre;

    consigioNombre=obtenerSector(sectores,tam, emp.idSector, nombreSector);
    if(!consigioNombre)
    {
        strcpy(nombreSector,"Sin Definir");
    }
    printf("\n%d    %s      %s    %c    %.2f   %s\n ",emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo,nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int contador=0;
    printf("\nLegajo  Nombre  Apellido  Sexo  Sueldo  Sector  \n\n");
    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    if(contador==0)
    {
        printf("\n no hay empleados para mostrar");
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
            indice=i;
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

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int legajo;
    int esta;

    indice=buscarLibre(vec, tam);

    if(indice==-1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        printf("\n ingrese el legajo: ");
        scanf("%d",&legajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta!=-1)
        {
            printf("\n ya existe un empleado con ese legajo en el sistema");
            mostrarEmpleado(sectores,tamSector,vec[esta]);
        }
        else
        {
            vec[indice].legajo=legajo;

            printf("\n ingrese el nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("\n ingrese el apellido: ");
            fflush(stdin);
            gets(vec[indice].apellido);

            printf("\n ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("\n Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            /*
            printf("\n ingrese el sector: ");
            scanf("%s", &vec[indice].idSector);
            */

            vec[indice].estado = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector)
{
    int indice;
    int esta;
    int legajo;

        indice=buscarLibre(vec, tam);

    if(indice==-1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        printf("\n ingrese el legajo: ");
        scanf("%d",&legajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta!=-1)
        {
            printf("\n usted ha seleccionado al empleado : \n");
            mostrarEmpleado(sectores,tamSector,vec[esta]);

            vec[esta].legajo=legajo;

            printf("\n Ingrese sueldo: ");
            scanf("%f", &vec[esta].sueldo );

            printf("\n ingrese el sector: ");
            scanf("%d", &vec[esta].);

            vec[esta].estado = 1;

            printf("Modifiacion de empleado exitosa!!!\n\n");
        }
    }
}
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int esta;
    int legajo;
    char seguir='s';
    char confirmar;

    indice=buscarLibre(vec, tam);

    if(indice==-1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        printf("\n ingrese el legajo del empleado a dar de baja: ");
        scanf("%d",&legajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta!=-1)
        {
            printf("\n usted ha seleccionado al empleado : \n");
            mostrarEmpleado(sectores,tamSector,vec[esta]);

            printf("\n confirmar la baja? (s/n)...");
            fflush(stdin);
            confirmar=getche();

            if( tolower(confirmar)== 's')
            {
                seguir='n';
                vec[esta].legajo=legajo;

                vec[esta].estado=0;
                printf("\n Baja de empleado exitosa!!!\n\n");
            }


        }
        printf("\n Baja de empleado cancelada \n\n");
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int j;
    int auxInt;

    for(i = 0 ; i < tam ; i++)
    {
        for(j = 0 ; j < tam ; j++)
        {
            if(vec[i].legajo> vec[j].legajo)
            {
                auxInt = vec[i].legajo;
                vec[i].legajo = vec[j].legajo;
                vec[j].legajo = auxInt;


            }
        }
    }
    printf("\n Orden de empleados exitosa!!!, presione la opcion 5 para ver la lista en orden \n\n");
}
