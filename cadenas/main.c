#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[50];

    fflush(stdin);
    gets(cadena);
    printf("%s",cadena);
    return 0;
}
