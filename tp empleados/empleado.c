#include "empleado.h"


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
    printf("\n%d    %10s      %10s    %10c    %10.2f   %10s\n ",emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo,nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int contador=0;
    printf("\nLegajo        Nombre         Apellido          Sexo   Sueldo       Sector  \n\n");
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
        printf("\n no hay empleados para mostrar \n");
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
            fflush(stdin);
            scanf("%f", &vec[indice].sueldo );

            printf("\n ingrese Sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales); \n\n");
            fflush(stdin);
            scanf("%d", &vec[indice].idSector);

            /*
            printf("\n ingrese el sector: ");
            scanf("%s", &vec[indice].idSector);
            */

            vec[indice].estado = 1;

            printf("Alta empleado exitosa!!!\n\n");
        }
    }
}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{
    int todoOk;
    int i;

    for(i=0; i<tam; i++)
    {
        if(idSector==sectores[i].id)
        {
            strcpy(desc, sectores[i].desc);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");
    int i;
    int j;

    for(i=0; i<tamSec; i++)
    {
        printf("Sector:  %s \n\n",sectores[i].desc);
        for(j=0; j<tam; j++)
        {
            if((empleados[j].idSector==sectores[i].id)&&(empleados[j].estado==1))
            {
                mostrarEmpleado(sectores,tamSec,empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int i;
    int j;
    int contador;
    system("cls");

    for(i=0 ; i<tamSec ; i++)
    {
        contador=0;
        printf("Sector: %s \n\n",sectores[i].desc);

        for(j=0 ; j<tam ; j++)
        {
            if((sectores[i].id == empleados[j].idSector)&&(empleados[j].estado == 1))
            {
                mostrarEmpleado(sectores,tamSec,empleados[j]);
                contador++;
            }
        }
        printf("Cantidad de empleados: %d\n\n",contador);
    }
}
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector)
{
    int indice;
    int esta;
    int legajo;
    int opcion;
    char seguir='s';
    char confirmar;

    indice=buscarLibre(vec, tam);

    if(indice==-1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        printf("\n ingrese el legajo del empleado a modificar: ");
        scanf("%d",&legajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta!=-1)
        {


            do
            {
                system("cls");
                printf("            ::M O D I F I C A C I O N::          \n");
                printf("  1_ Modificar Legajo      2_Modificar Sueldo    \n");
                printf("  3_ Modificar  Nombre     4_ Modificar Apellido \n");
                printf("  5_ Modificar sector      6_ Modificar Sexo     \n");
                printf("  7_ Salir...                                    \n");

                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("ingrese el nuevo legajo: \n");
                    fflush(stdin);
                    scanf("%d",&vec[esta].legajo);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 2:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("ingrese el nuevo sueldo: \n");
                    fflush(stdin);
                    scanf("%f",&vec[esta].sueldo);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 3:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("ingrese el nuevo nombre: \n");
                    fflush(stdin);
                    gets(vec[esta].nombre);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 4:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("ingrese el nuevo apellido: \n");
                    fflush(stdin);
                    gets(vec[esta].apellido);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 5:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("\n ingrese el nuevo Sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales); \n\n");
                    fflush(stdin);
                    scanf("%d",&vec[esta].idSector);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 6:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].legajo=legajo;

                    printf("ingrese el nuevo sexo: \n");
                    fflush(stdin);
                    scanf("%c",&vec[esta].sexo);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 7:
                    printf("\n confirmar salida s/n?...\n");
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
            while(seguir == 's');

        }
    }
}
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int esta;
    int legajo;
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

            if( tolower(confirmar== 's'))
            {
                vec[esta].legajo=legajo;

                vec[esta].estado=0;
                printf("\n Baja de empleado exitosa!!!\n\n");
            }
            else
            {
                printf("\n Baja de empleado cancelada \n\n");
            }
        }
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \param sentido int indica el orden sentidio del orden, siendo 0 ascendente y 1 descendente
 * \return void
 *
 */
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector, int sentido)
{
    int i;
    int j;
    eEmpleado auxInt;
    for(i = 0 ; i < tam - 1  ; i++)
    {
        for(j = i + 1 ; j < tam  ; j++)
        {
            if(( sentido && vec[i].legajo < vec[j].legajo )
                    || (!sentido && vec[i].legajo > vec[j].legajo))
            {
                auxInt = vec[i];
                vec[i] = vec[j];
                vec[j] = auxInt;
            }
        }
    }
    printf("\n Orden de empleados exitosa!!!, presione la opcion 5 para ver la lista en orden \n\n");
}
