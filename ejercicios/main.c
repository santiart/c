#include <stdio.h>
#include <stdlib.h>

int obtenerProducto(int x, int y);
int obtenerCuadrado(int x);
int main()
{
    int numero1;
    int numero2;
    int resultadop;
    int resultadocuadrado;

    printf("ingrese el primer numero: ");
    scanf("%d",&numero1);
    printf("ingrese un segundo numero: ");
    scanf("%d",&numero2);
    resultadop=obtenerProducto(numero1,numero2);
    printf("el resultado del producto es: %d\n", resultadop);
    resultadocuadrado=obtenerCuadrado(numero1);
    printf("el cuadrado del primer numero es: %d",resultadocuadrado);

    return 0;
}
int obtenerProducto(int x, int y)
{
    int producto;
    producto=x*y;
    return producto;
}
int obtenerCuadrado(int x)
{
    int cuadrado;
    cuadrado=x*x;
    return cuadrado;
}
