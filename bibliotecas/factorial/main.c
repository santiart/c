#include <stdio.h>
#include <stdlib.h>


int obtenerFactorial(int x);
int main()
{
    int num1;
    int numero;



    printf("ingrese un numero: ");
    scanf("%d",&num1);

    numero=obtenerFactorial(num1);
    printf("el valor del factorial es: %d",numero);

    return 0;
}
int obtenerFactorial(int x)
{
    int i;
    int resultadof=1;
    for(i=1;i<=x;i++)
    {
        resultadof=resultadof*i;
    }

    return resultadof;
}



/*
int main()
{
    int numero;
    int *n;
    numero=3;
    n=&numero;

    printf("%d",numero);
    printf("\n%p",n);
    printf("\n%d",*n);
    return 0;
}
*/
