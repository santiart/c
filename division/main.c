#include <stdio.h>
#include <stdlib.h>

float obtenerDivision(int x, int y);
int main()
{
    int numero1;
    int numero2;
    float resultado;

    printf("ingrese un numero: ");
    scanf("%d",&numero1);
    printf("ingrese otro numero: ");
    scanf("%d",&numero2);
    resultado=obtenerDivision(numero1,numero2);
    printf("el resultado de la division es: %.2f",resultado);
    return 0;
}
float obtenerDivision(int x, int y)
{
    float resta;
    if(y!=0)
    {
        resta=(float)x/y;

    }
    else{
        printf("no se puede dividir por 0 \n" );
    }
        return resta;
}
