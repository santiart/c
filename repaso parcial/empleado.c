#include "empleado.h"
#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void inicializarSectores(eSector sectores[], int cantidad)
{
    eSector sec[]=
    {
        {1,"RRHH\n"},
        {2,"Compras\n"},
        {3,"Ventas\n"},
        {4,"Atencion al cliente\n"},
        {5,"Sistemas\n"}
    };
    for(int i = 0; i< cantidad; i++)
    {
        sectores[i].id = sec[i].id ;
        strcpy(sectores[i].descripcion, sec[i].descripcion);
    }
}
void inicializarMenus(eMenu menues[], int cantidad)
{

    eMenu menu[]=
    {
        {1,"Sopa\n",35},
        {2,"Ensalada\n",},
        {3,"Milanesa con pure\n"},
        {4,"Pizza\n"},
        {5,"Guiso\n"},
        {6,"Puchero\n"},
        {7,"Churrasco\n"},
        {8,"Pastel de papas\n"},
        {9,"Ravioles\n"},
        {10,"Fideos con salsa\n"}
    };
    for(int i = 0; i< cantidad; i++)
    {
        menu[i].codigoMenu= menues[i].codigoMenu;
        strcpy(menu[i].descripcion, menues[i].descripcion);
    }
}
void iniciarlizarEmpleados(eEmpleado emp[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        emp[i].isEmpty = 0;
    }
}
int buscarEspacio(eEmpleado emp[], int tam)
{
    int espacio = -1;
    for(int i = 0; i<tam; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            espacio = i;
            break;
        }
    }
    return espacio;
}

int menuPrincipal()
{
    int opcionPrincipal;
    printf("**---Bienvenidos a mi ABM---**\n\n");
    printf("1.- Alta Empleado.\n");
    printf("2.- Modificar Empleado.\n");
    printf("3.- Baja Empleado.\n");
    printf("4.- Mostrar Empleado.\n");
    printf("5.- Listar Empleados.\n");
    printf("6.- Salir.\n");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcionPrincipal);

    return opcionPrincipal;
}
void mostrarSectores(eSector sec[], int tamSec)
{
    for(int i = 0; i<tamSec; i++)
    {
        printf("");
        printf("%d ",sec[i].id);
        printf(" %s",sec[i].descripcion);
    }
}
int altaEmpleado(eEmpleado emp[], int tam, eSector sec[], int tamSec, int id)
{
    int sePudoAlta=0;
    int indice;
    char auxNomb[51];
    int salir = 0;
    char auxApell[51];
    char auxSex;
    float auxSalario;
    int auxDia;
    int auxMes;
    int auxAnio;
    int auxSector;

    indice = id;

    if(buscarEspacio(emp,tam)!=-1)
    {
        emp[indice].legajo = indice;
        system("cls");
        printf("Bienvenido a la alta de empleados.\n");
        do
        {

            fflush(stdin);
            printf("\nIngrese apellido: ");
            gets(auxApell);
            if(esSoloLetras(auxApell)==1)
            {
                strcpy(emp[indice].apellido,auxApell);
                salir=1;
            }
            else
            {
                printf("Ingrese solo letras\n");
                system("pause");
            }
        }while(salir==0);
        salir = 0;
        do
        {
            fflush(stdin);
            printf("\nIngrese nombre: ");
            gets(auxNomb);
            if(esSoloLetras(auxNomb)==1)
            {
                strcpy(emp[indice].nombre,auxNomb);
                salir=1;
            }
            else
            {
                printf("Ingrese solo letras\n");
            }
        }while(salir==0);
        fflush(stdin);
        printf("\nIngrese sexo: ");
        scanf("%c",&auxSex);
        if(esSoloLetra(auxSex)==1)
        {
            emp[indice].sexo = auxSex;
        }
        printf("\nIngrese salario: ");
        scanf("%f",&auxSalario);
        if(auxSalario>0)
        {
            emp[indice].salario = auxSalario;
        }
        else
        {
            printf("\nEl salario no puede ser menor a 0, por favor ingrese un salario correcto.");
            printf("\nIngrese un salario: ");
            scanf("%f",&auxSalario);
        }
        printf("\nFecha de ingreso.");
        printf("\nIngrese el dia: ");
        scanf("%d",&auxDia);
        if(esDia(auxDia)==1);
        {
            emp[indice].fechaIngreso.dia = auxDia;
        }
        printf("\nIngrese el mes: ");
        scanf("%d",&auxMes);
        if(esMes(auxMes)==1);
        {
            emp[indice].fechaIngreso.mes = auxMes;
        }
        printf("\nIngrese el anio: ");
        scanf("%d",&auxAnio);
        if(esAnio(auxAnio)==1)
        {
            emp[indice].fechaIngreso.anio = auxAnio;
        }
        system("cls");
        printf("Sectores\n");
        mostrarSectores(sec, tamSec);
        printf("Ingrese sector: ");
        scanf("%d",&auxSector);
        int i = 0;
        while(i<tamSec || auxSector ==sec[i].id)
        {
            if(auxSector==sec[i].id)
            {
                emp[indice].idSector = auxSector;
                break;
            }
        i++;
        }
        emp[indice].isEmpty = 1;
        printf("\nAlta realizada con exito!!\n");
        system("pause");
        sePudoAlta = 1;
    }
    else
    {
        system("cls");
        printf("\nNo hay espacio en el sistema para dar un nuevo alta.\n");
        system("pause");
    }
    return sePudoAlta;
}

void mostrarEmpleados(eEmpleado emp[], int tam)
{
    printf("Estado, Legajo, Apellido, Nombre, Sexo, Salario, Fecha Ingreso, Sector.\n");
    for(int i = 0; i<tam; i++)
    {
        printf("%d %d %s %s %c %.2f %d\%d\%d %i\n", emp[i].isEmpty, emp[i].legajo, emp[i].apellido, emp[i].nombre, emp[i].sexo, emp[i].salario, emp[i].fechaIngreso.dia, emp[i].fechaIngreso.mes, emp[i].fechaIngreso.anio, emp[i].idSector);
    }
}
int menuModifica()
{
    system("cls");
    int opcionModifica;
    printf("Bienvenidos al modificador de empleados.\n\n");
    printf("1.- Apellido.\n");
    printf("2.- Nombre.\n");
    printf("3.- Sexo.\n");
    printf("4.- Salario.\n");
    printf("5.- Fecha ingreso.\n");
    printf("6.- Sector.\n");
    printf("7.- Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcionModifica);

    return opcionModifica;
}
int buscarEmpleado(eEmpleado emp[], int tam, int legajoAbuscar)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(emp[i].isEmpty==1 && emp[i].legajo == legajoAbuscar)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarEmpleado(eEmpleado emp)
{
    printf("Legajo  Nombre  Estado");
    printf("%d %s %d",emp.legajo, emp.nombre, emp.isEmpty);
    system("pause");
}
void modificarEmpleado(eEmpleado emp[], int tam)
{
    int auxLeg;
    int auxEstLeg;
    char opcion='n';
    int salirModifica = 0;
    int salirCase = 0;
    int indice;
    int id=0;
    do{
        system("cls");
        printf("Bienvenido al modificador de empleados.\n\n");
        printf("Por favor ingrese el legajo del empleado a editar: ");
        scanf("%d",&auxLeg);
        auxEstLeg=buscarEmpleado(emp,tam,auxLeg);
        if(auxEstLeg == auxLeg)
        {
            system("cls");
            printf("Existe un empleado con ese legajo: %d\n",auxLeg);
            printf("Quiere modificarlo, 's' o 'n': ");
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                indice = id;
                switch(menuModifica())
                {
                case 1:
                    do
                    {
                        char auxApell[51];
                        fflush(stdin);
                        printf("\nIngrese apellido a modificar: ");
                        gets(auxApell);
                        if(esSoloLetras(auxApell)==1)
                        {
                            strcpy(emp[indice].apellido,auxApell);
                            salirCase=1;
                        }
                        else
                        {
                            printf("Ingrese solo letras\n");
                            system("pause");
                        }
                    }while(salirCase==0);
                    salirCase=0;
                    break;
                case 7:
                    salirModifica=1;
                    break;
                }
            }
        }
        else
        {
            system("cls");
            printf("No existe un empleado con ese legajo.\n");
            system("pause");
        }
    }while(salirModifica==0);
}
