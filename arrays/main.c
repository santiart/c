#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5];
    int i;
    int suma;
    int cant;
    float promedio;

    for(int i=0;i<5;i++)
    {
        printf("ingrese un numero: ");
        scanf("%d",&vec[i]);
    }
    printf("el vector con los numeros cargados es: ");
    1
    for(int i=0;i<5;i++)
    {
        printf("%d", vec[i]);
    }
    for(int i=0;i<5;i++){

        suma+=vec[i];
        cant++;
    }
    promedio=(float)suma/cant;
    printf("\n\n");
    printf("la suma de los valores de vec es: %d",suma);
    printf("el promedio de los num es: %f",promedio);


    return 0;
}
