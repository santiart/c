#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* mensaje);// vector de char, escalar de char
int main()
{
    //char nombre[20] = "sebastian";
    char mensaje[] = "hello world";

    mostrarCadena(mensaje);

    return 0;
}

void mostrarCadena(char* message)
{
    /*
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", caracter);

    while(*message != '\0')
    {
        printf("%c", *message);
        message++;
    }
    */
    for(int i=0;*(message + i)!='\0';i++)
    {
        printf("%c", *(message + i));
    }
}
