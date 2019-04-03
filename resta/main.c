#include <stdio.h>
#include <stdlib.h>


int obtenerResta(int x, int y);
int main()

{
    int numero1;
    int numero2;
    int resultado;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese un numero: ");
    scanf("%d",&numero2);
    resultado=obtenerResta(numero1,numero2);
    printf("el resultado de la resta es: %d",resultado);

    return 0;
}
int obtenerResta(int x, int y)
{
    int resta;
    resta=x-y;
    return resta;
}
