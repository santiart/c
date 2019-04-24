#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41];
    int i ;
    int menu;

    do
    {
        menu=Menu();
        scanf(&menu);

        switch(menu)
        {
        case 1:
            printf("uno");
        }

    }while(menu!=5);
    printf("ingrese su nombre: ");
    gets(nombre);

    printf("ingrese su apellido: ");
    gets(apellido);

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, " ,");
    strcat(nombreCompleto, nombre);
    strlwr(nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0; strlen(nombreCompleto); i++)
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    return 0;
}
