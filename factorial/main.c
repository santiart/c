#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i;
    int n=1;
    int resultado=1;

    printf("ingrese un numero: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        resultado=resultado*i;
    }
    printf("el valor del factorial es: %d",resultado);
    return 0;
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
