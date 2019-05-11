#include "empleado.h"
#include "input.h"


void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    for( i = 0; i < tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    char consigioNombre;

    consigioNombre=obtenerSector(sectores,tam, emp.Sector, nombreSector);
    if(!consigioNombre)
    {
        strcpy(nombreSector,"Sin Definir");
    }
    printf("\n%d    %10s      %10s     %10.2f   %10s\n ",emp.id, emp.nombre, emp.apellido, emp.sueldo,nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int contador = 0;

    printf("\nLegajo        Nombre         Apellido          Sexo   Sueldo       Sector  \n\n");
    for(i = 0; i < tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n no hay empleados para mostrar \n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec [], int tam, int id)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].estado == 1)&&(vec[i].id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        id = indice + 1;

        vec[indice].id = id;

        while(!getStringLetras("ingrese el nombre: \n", auxNombre))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(vec[indice].nombre, auxNombre);

        while(!getStringLetras("ingrese el apellido: \n", auxApellido))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(vec[indice].apellido, auxApellido);

        while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
        {
            printf("intente de nuevo...\n");
        }

        vec[indice].sueldo = atoi(auxSueldo);
        while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
        {
            printf("intente de nuevo...\n ");
        }

        vec[indice].Sector = atoi(auxSector);

        vec[indice].estado = 1;

        printf("Alta empleado exitosa!!!\n\n");
    }
}



void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector)
{
    int esta;
    int id;
    int opcion;
    char seguir = 's';
    char confirmar;
    char auxOpcion[50];
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];

    while(!getStringNumeros("ingrese el legajo del empleado a modificar: \n", auxId))
    {
        printf("intente de nuevo...\n");
    }
    id = atoi(auxId);
    esta = buscarEmpleado(vec, tam, id);

    if(esta != -1)
    {


        do
        {
            system("cls");
            printf("            ::M O D I F I C A C I O N::          \n");
            printf("  1_ Modificar  Nombre       2_Modificar Sueldo  \n");
            printf("  3_ Modificar Apellido      4_ Modificar sector \n");
            printf("  5_ Salir....                                   \n");

            while(!getStringNumeros("ingrese una opcion: \n", auxOpcion))
            {
                printf("intente de nuevo...\n");
            }
            opcion = atoi(auxOpcion);

            switch(opcion)
            {

                case 1:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringLetras("ingrese el nombre: \n", auxNombre))
                    {
                        printf("intente de nuevo...\n");
                    }

                    strcpy(vec[esta].nombre, auxNombre);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 2:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
                    {
                        printf("intente de nuevo...\n");
                    }
                    vec[esta].sueldo = atoi(auxSueldo);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 3:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringLetras("ingrese el apellido: \n", auxApellido))
                    {
                        printf("intente de nuevo...\n");
                    }
                    strcpy(vec[esta].apellido, auxApellido);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 4:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
                    {
                        printf("intente de nuevo...\n ");
                    }

                    vec[esta].Sector = atoi(auxSector);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].estado = 1;
                    system("pause");
                    break;

                case 5:
                    printf("\n confirmar salida s/n?...\n");
                    fflush(stdin);
                    confirmar = getche();

                    if( tolower(confirmar)== 's')
                    {
                        seguir = 'n';
                    }
                    break;

                default:
                    printf("\n Opcion invalida, intente de nuevo...");
                    system("pause");
                    system("break");

                }
            }
            while(seguir == 's');

        }
        else
        {
            printf("no hay ningun empleado ingresado con ese id...\n");
        }
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int esta;
    int id;
    char confirmar;
    char auxId[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        while(!getStringNumeros("ingrese el id del empleado a dar de baja: \n", auxId))
        {
            printf("intente de nuevo...\n");

        }
        id = atoi(auxId);
        esta=buscarEmpleado(vec, tam, id);

        if(esta != -1)
        {
            printf("\n usted ha seleccionado al empleado : \n");
            mostrarEmpleado(sectores,tamSector,vec[esta]);

            printf("\n confirmar la baja? (s/n)...");
            fflush(stdin);
            confirmar = getche();

            if( tolower(confirmar == 's'))
            {
                vec[esta].id = id;

                vec[esta].estado = 0;
                printf("\n Baja de empleado exitosa!!!\n\n");
            }
            else
            {
                printf("\n Baja de empleado cancelada \n\n");
            }
        }
        else
        {
            printf("no hay empleados ingresados con ese id...\n");
        }
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam)
{
    int i;
    int j;
    eEmpleado aux;

    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j< tam; j++)
        {
            if(vec[i].Sector > vec[j].Sector)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(i = 0 ; i < tam - 1  ; i++)
    {
        for(j = i + 1 ; j < tam  ; j++)
        {
            if(( vec[i].Sector == vec[j].Sector))
            {
                if(strcmp(vec[i].apellido, vec[j].apellido))
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}
void informarSueldos(eEmpleado vec[],int tam)
{
    float promedio = 0;
    float acumulador = 0;
    int contador = 0;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(vec[i].estado)
        {
            acumulador += vec[i].sueldo;
        }
    }

    promedio = acumulador /(i-1);

    for(i = 0; i < tam; i++)
    {
        if(vec[i].estado)
        {
            if(vec[i].sueldo > promedio)
            {
                contador++;
            }
        }

    }
    printf("Suma total de los salarios :%.2f\nPromedio de los salarios :%.2f\nCantidad de empleados que superan el promedio :%d\n",acumulador,promedio,contador);

}

void listarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSector)
{
    int opcion;
    char auxOpcion[50];
    char confirmar;
    char seguir;

    do
    {
        system("cls");
        printf(" 1_Mostrar informacion de empleados\n 2_Mostrar informacion de salarios\n 3_Salir...\n");
        while(!getStringNumeros("ingrese una opcion: \n",auxOpcion ));
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOpcion);
        switch(opcion)
        {
            case 1:
                ordenarEmpleados(vec,tam);
                mostrarEmpleados(vec,tam, sector, tamSector);
                break;
            case 2:
                informarSueldos(vec,tam);
                break;
            case 3:
                printf("\n confirmar salida s/n?...\n");
                fflush(stdin);
                confirmar = getche();

                if( tolower(confirmar)== 's')
                {
                    seguir = 'n';
                }

                break;

            default:
                printf("\n Opcion invalida, intente de nuevo...");
                system("pause");
                system("break");
            break;
        }
    }while(seguir == 's');
}
