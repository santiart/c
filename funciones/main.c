#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int x, int y, int z);

int main()
{
    int num1;
    int num2;
    int num3;
    int maximo;

    printf("ingrese el numero: ",num1);
    scanf("%d",&num1);
    printf("ingrese el numero: ",num2);
    scanf("%d",&num2);
    printf("ingrese el numero: ",num3);
    scanf("%d",&num3);
    maximo=obtenerMaximo(num1,num2,num3);
    printf("el valor del maximo es: %d",maximo);



    return 0;
}
int obtenerMaximo(int x, int y, int z)
{
    int maximo;
    if(x>y&&x>z)
    {
        maximo=x;
    }
    else
    {
        if(y>=x&&y>z)
        {
            maximo=y;
        }
        else
        {
            maximo=z;
        }
    }
    return maximo;
}




/*
void unaFuncion(int x);
int main()

{
    int x=15;

    printf("el valor de x en el main es: %d\n", x);

    unaFuncion(x);

    printf("el valor de x al final del main es: %d\n",x);

    return 0;
}

void unaFuncion(int x)
{
    x=4;
    printf("el valor de x en el void es: %d\n",x);
}




int sumar(int x, int y);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("ingrese un numero: ");
    scanf("%d",&num1);
    printf("ingrese un numero: ");
    scanf("%d",&num2);

    resultado=sumar(num1,num2);

    printf("el resultado de la suma es: %d",resultado);

    return 0;

}

int sumar(int num1, int num2)
{
    int suma;
    suma=num1+num2;
    return suma;
}
*/
