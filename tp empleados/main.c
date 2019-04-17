#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define  TAM 3


typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    int estado;
} eEmpleado;


void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[],int tam);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int legajo);
void altaDeEmpleado(eEmpleado vec [], int tam);
void modificarEmpleado(eEmpleado vec [], int tam);

int main()
{
    int opcion;
    char seguir='s';
    char confirmar;
    eEmpleado lista[TAM];// {{1111,"juan", "perez", 'm', 53000,1},{"ana", "sanchez", 2222, 'f', 40000,1}}; //hardcodeo
    inicializarEmpleados(lista, TAM);

    do
    {
        printf("\n\n");
        system("cls");
        printf("         ::A B M      E M P L E A D O S::      \n\n");
        printf("1- Alta Empleado\n 2- Baja Empleado\n 3- Modificacion Empleado\n 4- Ordenar Empleados\n 5- Listar Empleados\n 6- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            altaDeEmpleado(lista, TAM);
            system("pause");
            break;
        case 2:
            printf("\n baja empleado");
            break;

        case 3:
            printf("\n modificacion empleados");
            break;

        case 4:
            printf("\n ordenar empleados");
            break;
        case 5:
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\n confirmar salida s/n?...");
            fflush(stdin);
            confirmar=getche();

            if( tolower(confirmar)== 's')
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

    return 0;
}

void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    int estado;
    for( i=0; i<tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eEmpleado emp)
{
    printf("\n%d    %s      %s    %c    %.2f \n ",emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo);
}

void mostrarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    int contador=0;
    printf("\nlegajo  nombre  apellido  sexo  sueldo ");
    for(i=0; i<tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(vec[i]);
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

void altaDeEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;

    indice=buscarLibre(vec, tam);

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
            mostrarEmpleado(vec[esta]);
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

            vec[indice].estado = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}
void modificarEmpleado(eEmpleado vec[], int tam,int legajo)
{
    int indice;
    int esta;
    int i;

    indice=buscarLibre(vec, tam);

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
            printf("\n usted selecciono al empleado: ");
            mostrarEmpleado(vec[esta]);

            printf("ingrese el nuevo valor de sueldo: ");
            scanf("%.2f",& sueldo);
            fflush(stdin);

            printf("modificacion de sueldo exitosa!!!...");
        }


}
