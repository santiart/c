#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    int numero;
    int legajo;
    int telefono;
};

int main()
{
    char seguir;
    char contadorNombre, contadorApellido;
    int contadorNumero,contadorLegajo,contadorTelefono=0;
    char acumuladorNombre, acumuladorApellido;
    int acumuladorNumero,acumuladorLegajo,acumuladorTelefono;
    int num;

    do
    {
        printf("               ::   A G E N D A  ::                 ");
        printf("\n");

        struct datosPersonales agenda;

        printf("\n ingrese el nombre: ");
        gets(agenda.nombre);
        printf("\n ingrese el apellido: ");
        gets(agenda.apellido);
        fflush(stdin);
        printf("\n ingrese el numero: ");
        scanf("%d",&agenda.numero);
        fflush(stdin);
        printf("\n ingrese el legajo: ");
        scanf("%d",&agenda.legajo);
        fflush(stdin);
        printf("\n ingrese el numero de telefono: ");
        scanf("%d",&agenda.telefono);
        fflush(stdin);
        printf("\n\n");


        acumuladorNombre+=agenda.nombre;
        acumuladorApellido+=agenda.apellido;
        acumuladorNumero+=agenda.numero;
        acumuladorLegajo+=agenda.legajo;
        acumuladorTelefono+=agenda.telefono;

        contadorNombre++;


        printf("\n    nombre       apellido          numero            legajo           telefono ");
        printf("\n %10s    %10s     %10d     %10d     %10d", agenda.nombre, agenda.apellido, agenda.numero, agenda.legajo, agenda.telefono,"\n");

        printf("\n Desea ingresar otro  numero ?  si/no \n");
        scanf("%c",&seguir);
        fflush(stdin);
        printf("\n");
        system("pause");
        system("cls");

    }
    while (seguir=!'no');


    printf("\n");
    return 0;
}
