#include <stdio.h>
#include <stdlib.h>

int obtenerFactorial(int x);
int main()
{
    int numero;

    numero=obtenerFactorial(numero);
    printf("el valor del factorial es: %d",numero);

    return 0;
}
int obtenerFactorial(int x)
{
    int i;
    int x1=1;
    int resultadof=1;

    printf("ingrese un numero: ");
    scanf("%d",&x1);
    for(i=1;i<=x1;i++)
    {
        resultadof=resultadof*i;
    }

    return resultadof;
}
