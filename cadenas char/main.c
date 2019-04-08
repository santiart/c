#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char nombre[20]={"JUAN"};
    char apellido[20]={"PEREZ"};
    char nombreCompleto[41];
    int i ;

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto, " ,");
    strcat(nombreCompleto, nombre);
    strlwr(nombreCompleto);

    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(i=0; strlen(nombreCompleto);i++)
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    return 0;
}
