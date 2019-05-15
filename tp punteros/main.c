#include <stdio.h>
#include <stdlib.h>

int main()
{
    //char letra = 'a';
    char palabra[]= "bienvenidos";
    //char* p;
    char* q;
    char** punteroPuntero;
    int i=0;
    //p = &letra;
    q = &palabra;
    punteroPuntero = &q;

    //printf("letra: %c\n", *p);

    while(**(punteroPuntero+i) != '\0')
    {
        printf("letra: %c \n", **(punteroPuntero+i));
        q++;
    }


    printf("\n\n");
    /*
    while(*q != '\0')
    {
        printf("letra: %c  direccion de memoria:%p \n", *q, q);
        q++;
    }
    */
    return 0;
}
