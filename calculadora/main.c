#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "factorial.h"

int main()
{
    float resultadoDivision;
    int resultado;
    int numero1;
    int numero2;
    int operacion;
    int i;
    int n=1;
    int rfactoreo=1;
    do
    {

        printf("\n       :: C A L C U L A D O R A::     ");
        printf("\n       1_ Suma            4_division  ");
        printf("\n       2_ Resta           5_factorial ");
        printf("\n       3_ Multiplicacion  6_Salir     ");
        printf("\n       elija una operacion de calculo:   ");
        scanf("%d",&operacion);
        switch(operacion)
        {
        case 1:
            printf("\n ingrese el primer numero: ");
            scanf("%d",&numero1);
            printf("\n ingrese el segundo numero");
            scanf("%d",&numero2);
            resultado=numero1+numero2;
            printf("\n el resultado de %d+%d es: %d ",numero1,numero2,resultado);
            break;
        case 2:
            printf("\ningrese el primer numero: ");
            scanf("%d",&numero1);
            printf("\ningrese el segundo numero: ");
            scanf("%d",&numero2);
            resultado=numero1-numero2;
            printf("\nel resultado de %d-%d es: %d",numero1,numero2,resultado);
            break;
        case 3:
            printf("\ningrese el primer numero: ");
            scanf("%d",&numero1);
            printf("\ningrese el segundo numero: ");
            scanf("%d",&numero2);
            resultado=numero1*numero2;
            printf("\nel resultado de %d*%d es: %d",numero1,numero2,resultado);
            break;
        case 4:
            printf("\ningrese el primer numero: ");
            scanf("%d",&numero1);
            printf("\ningrese el segundo numero: ");
            scanf("%d",&numero2);
            if(numero2!=0)
            {
                resultadoDivision=(float)numero1/numero2;
                printf("el resultado de la division de %d/%d es: %.2f",numero1,numero2,resultadoDivision);
            }
            else
            {
                printf("\n el resultado no se puede mostrar porque el divisor es 0");
            }
            break;
        case 5:
            printf("ingrese el numero que quiera factorizar: ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                rfactoreo=rfactoreo*i;
            }
            printf("el resultado de factoreo de %d es: %d",n,rfactoreo);
            break;
        case 6:
            printf("      pulse ENTER para salir...      ");
        }
    getch();
    printf("\n");
    system("pause");
    system("cls");
    }while(operacion!=6);
    return 0;
}
