#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
    int telefono;
};

int main()
{
        struct datosPersonales vecAgenda[TAM];
    int i;

    for(i=0; i<TAM; i++)
    {
        printf("\n ingrese el nombre: ");
        gets(vecAgenda[i].nombre);
        printf("\n ingrese el apellido: ");
        gets(vecAgenda[i].apellido);
        fflush(stdin);
        printf("\n ingrese la calle: ");
        gets(vecAgenda[i].calle);
        fflush(stdin);
        printf("\n ingrese el numero: ");
        scanf("%d",&vecAgenda[i].numero);
        fflush(stdin);
        printf("\n ingrese su numero de telefono: ");
        scanf("%d",&vecAgenda[i].telefono);
        fflush(stdin);
        printf("\n\n");

    }
    printf("\n    nombre          apellido          calle          numero        telefono ");
    for(i=0; i<TAM; i++)
    {
        printf("\n %10s    %10s     %10s     %10d     %10d", vecAgenda[i].nombre, vecAgenda[i].apellido, vecAgenda[i].calle, vecAgenda[i].numero, vecAgenda[i].telefono,"\n");
    }
    printf("\n");

    return 0;
}
/*
int main()
{
    struct datosPersonales agenda;
    strcpy(agenda.nombre, "Santiago");
    strcpy(agenda.apellido,"Aguado");
    strcpy(agenda.calle,"Montevideo");
    agenda.numero=1650;
    agenda.telefono=65165416;

    printf("el nombre es: %s",agenda.nombre);
    printf("\n el apellido es: %s",agenda.apellido);
    printf("\n la calle es: %s",agenda.calle);
    printf("\n el numero es: %d",agenda.numero);
    printf("\n el te4lefono es: %d",agenda.telefono);
}


int main()
{

    struct datosPersonales agenda;
    printf("ingrese el nombre: ");
    gets(agenda.nombre);
    printf("\n ingrese el apellido: ");
    gets(agenda.apellido);
    fflush(stdin);
    printf("\n ingrese la calle: ");
    gets(agenda.calle);
    fflush(stdin);
    printf("\n ingrese el numero: ");
    scanf("%d",&agenda.numero);
    fflush(stdin);
    printf("ingrese su numero de telefono: ");
    scanf("%d",&agenda.telefono);
    fflush(stdin);
    printf("\n el nombre es: %s",agenda.nombre);
    printf("\n el apellido es: %s",agenda.apellido);
    printf("\n la calle es: %s",agenda.calle);
    printf("\n el numero es: %d",agenda.numero);
    printf("\n el numero de telefono es: %d",agenda.telefono);

    return 0;
}


int main()
{
    struct datosPersonales vecAgenda[3];
    int i;

    for(i=0; i<3; i++)
    {
        printf("\n");
        printf("\ningrese el nombre: ");
        gets(vecAgenda[i].nombre);
        printf("\n ingrese el apellido: ");
        gets(vecAgenda[i].apellido);
        fflush(stdin);
        printf("\n ingrese la calle: ");
        gets(vecAgenda[i].calle);
        fflush(stdin);
        printf("\n ingrese el numero: ");
        scanf("%d",&vecAgenda[i].numero);
        fflush(stdin);
        printf("\n ingrese su numero de telefono: ");
        scanf("%d",&vecAgenda[i].telefono);
        fflush(stdin);
        printf("\n\n");
        printf("\n el nombre es: %s",vecAgenda[i].nombre);
        printf("\n el apellido es: %s",vecAgenda[i].apellido);
        printf("\n la calle es: %s",vecAgenda[i].calle);
        printf("\n el numero es: %d",vecAgenda[i].numero);
        printf("\n el numero de telefono es: %d",vecAgenda[i].telefono);

    }

    return 0;
}
int main()
{
    //si tiene el mismo formato ahorro datos
    for(i=0;i<3;i++)
    {
        vecAmigos[i]=vecContactos[i]; //asignancion
        printf("\n amigos/nombre %d amigos copiado &s", i,vecAmigos[i].nombre);
        printf("\n amigos/apellido %d amigos copiado &s", i,vecAmigos[i].apellido);
        printf("\n amigos/calle %d amigos copiado &s", i,vecAmigos[i].calle);
        printf("\n amigos/numero %d amigos copiado &d", i,vecAmigos[i].numero);
        printf("\n amigos/telefono %d amigos copiado &d", i,vecAmigos[i].telefono);
    }

}
*/
