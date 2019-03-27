#include <stdio.h>
#include <stdlib.h>

int obtenerResta(int x, int y);
int main()
{
    int numero1;
    int numero2;
    int resultador;
    char resultadosigno;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese un numero: ");
    scanf("%d",&numero2);

    resultador=obtenerResta(numero1,numero2);
    printf("el resultado de y el signo de la resta son: %d \n",resultador);
    return 0;

}
int obtenerResta(int x, int y)
{
    int resta;
    char signo;
    resta=x-y;
    if(resta>=0)
    {
        signo='p';
    }
    else{
        signo='n';
    }
   return resta;
}

