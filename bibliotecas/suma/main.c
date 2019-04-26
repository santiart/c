#include <stdio.h>
#include <stdlib.h>

int obtenerSuma(int x, int y);
int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese un numero: ");
    scanf("%d",&numero2);
    resultado=obtenerSuma(numero1,numero2);
    printf("el resultado de la suma es: %d",resultado);
    return 0;
}
int obtenerSuma(int x, int y)
{
    int suma;
    suma=x+y;
    return suma;
}
