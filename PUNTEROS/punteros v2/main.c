#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int *p);
int main()
{
    int x = 10;
    int* p = &x;
    //int* q = p;
    int** r = &p;// puntero de puntero

    printf("direccion de memoria de p: %d\n", **r);// puntero a puntero, muestra el 10
    //printf("valor de q: %d\n", *q);
    //printf(" direccion de x: %x \n", &x);

    printf("antes de llamar al puntero x vale %d\n", x);
    leerPuntero(&x);
    printf("despues de llamar al puntero x vale %d\n", x);
    /*
    int* p;

    p = &x;

    printf("%d\n", *p);// valor de direccion de memoria
    printf("%x\n", p);// mostrar en hexa
    printf("%d\n", p);// mostrar en decimal
    printf("%o\n", p);// mostrar en octal
    printf("%b")//numero en binario
    */
    //printf("%d\n", x);
    return 0;
}

void leerPuntero(int* p)
{
    //printf(" direccion guardada en p: %x \n", p);
    *p = 38;



}
