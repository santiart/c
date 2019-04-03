#include <stdio.h>
#include <stdlib.h>
#include "suma.h"
#include "resta.h"
#include "multiplicacion.h"
#include "division.h"
#include "factorial.h"

int main()
{
    int num1;
    int num2;
    int opcion;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    int resultadoFactorial;
    int resultadoFactorial2;
    int flag=1;

    do{
    printf("              :: C A L C U L A D O R A ::              \n");
    printf("Escoja una Opcion:                                     \n");
    printf(" 1_Ingresar primer numero     2_ingresar segundo numero\n");
    printf(" 3_realizar calculos          4_mostrar resultados     \n");
    printf(" 5_salir                                               \n");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("ingrese el primer numero: ");
            scanf("%d",&num1);
            break;
        case 2:
            printf("ingrese el segundo numero: ");
            scanf("%d",&num2);
            break;
        case 3:
            resultadoSuma=obtenerSuma(num1,num2);
            resultadoResta=obtenerResta(num1,num2);
            resultadoMultiplicacion=obtenerMultiplicacion(num1,num2);
            resultadoDivision=obtenerDivision(num1,num2);
            resultadoFactorial=obtenerFactorial(num1);
            resultadoFactorial2=obtenerFactorial(num2);
        case 4:
            printf("\n el resultado de la suma %d+%d es: %d",num1,num2,resultadoSuma);
            printf("\n el resultado de la resta %d-%d es: %d",num1,num2,resultadoResta);
            printf("\n el resultado de la multiplicacion %d*%d es: %d",num1,num2,resultadoMultiplicacion);
            printf("\n el resultado de la division %d/%d es: %.2f",num1,num2,resultadoDivision);
            printf("\n el resultado factorial de %d es: %d ",num1,resultadoFactorial);
            printf("y el resultado factorial de %d es: %d",num2,resultadoFactorial2);
        case 5:
            printf("\n pulse ENTER para salir... \n");

    }
    printf("\n");
    system("pause");
    system("cls");
    }while(opcion!=5);
    return 0;
}
