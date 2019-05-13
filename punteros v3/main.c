#include <stdio.h>
#include <stdlib.h>

void mostrarVector1(int vec[], int tam);
void mostrarVector2(int vec[], int tam);
void mostrarVector3(int* vec, int tam);
void mostrarVector4(int* vec, int tam);
int main()
{
    int vec[] = {3,5,2,4,3};

    mostrarVector1(vec,5);
    printf("\n\n");
    mostrarVector2(vec,5);
    printf("\n\n");
    mostrarVector3(vec,5);
    printf("\n\n");
    mostrarVector4(vec,5);

   // mostrarVector4()
    //int* p;

    //printf("%d\n", &vec[0]);

    //printf("%d\n", *(vec+1));//mostrar distintos indices del vector
/*
    for(int i= 0; i< 5; i++)
    {
        printf("%d \n", *(vec+i));
    }
*/

    return 0;
}

void mostrarVector1(int vec[], int tam)
{
    for(int i=0;i<5;i++)
    {
        printf("indice: %d\n", vec[i]);
    }
}

void mostrarVector2(int vec[], int tam)
{
    for(int i=0;i<5;i++)
    {
        printf("indice:%d\n", *(vec+i));
    }
}

void mostrarVector3(int* vec, int tam)//no esta bien visto
{
    for(int i=0;i<5;i++)
    {
        printf("indice: %d\n",vec[i]);
    }
}

void mostrarVector4(int* vec, int tam)
{
    for(int i=0;i<5;i++)
    {
        printf("indice: %d\n", *(vec+i));
    }
}
