#include <stdio.h>
#include <stdlib.h>

int obtenerMultiplicacion(int x, int y);
int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese otro numero: ");
    scanf("%d",&numero2);
    resultado=obtenerMultiplicacion(numero1,numero2);
    printf("el resultado de la multiplicacion es: %d",resultado);
    return 0;
}
int obtenerMultiplicacion(int x, int y)
{
    int multiplicacion;
    multiplicacion=x*y;
    return multiplicacion;
}
