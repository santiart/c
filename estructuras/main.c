#include <stdio.h>
#include <stdlib.h>

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
};
/*
int main()
{
    struct datosPersonales agenda;
    strcpy(agenda.nombre, "Santiago");
    strcpy(agenda.apellido,"Aguado");
    strcpy(agenda.calle,"Montevideo");
    agenda.numero=1650;

    printf("el nombre es: %s",agenda.nombre);
    printf("\n el apellido es: %s",agenda.apellido);
    printf("\n la calle es: %s",agenda.calle);
    printf("\n el numero es: %s",agenda.numero);
}
*/
int main()
{
    struct datosPersonales agenda;
    printf("ingrese el nombre: ");
    gets(agenda.nombre);
    printf("\n ingrese el apellido: ");
    gets(agenda.apellido);
    printf("\n ingrese la calle: ");
    gets(agenda.calle);
    printf("\n ingrese el numero: ");
    scanf("%d",&numero);

    printf("el nombre es: %s",agenda.nombre);
    printf("\n el apellido es: %s",agenda.apellido);
    printf("\n la calle es: %s",agenda.calle);
    printf("\n el numero es: %s",agenda.numero);

    return 0;
}
