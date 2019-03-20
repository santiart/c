#include <stdio.h>
#include <stdlib.h>

int main()
/*
{
    int i;//indice
    i=0;

    while(i<10)
    {
        printf("numero: %d \n",(i+1));
        i++;
    }
    return 0;
}
  */
{

    int numero;
    int contador=0;

   while(contador<6)
    {
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    if(numero<18)
    {
        printf("es menor de edad\n");
    }
    else if(numero>35){

        printf("es una persona mayor\n");
    }

    else
        {
        printf("es mayor de edad\n");
        }
    }
    contador++;
 }




    /*
   return 0;
    int numero;
    int numero2;
    char letra;
    float altura;

    numero = 10;
    numero2 = 34;
    letra = 'a';
    altura = 23.5;

    numero2 = altura;

    printf("La variable altura vale %.1f y la letra vale %c", altura, letra);

    /*printf("La variable altura vale %d", numero2);*/
    /*printf("La variable altura vale %.0f", altura);*/
    /*printf("La variable letra vale %c", letra);*/
    /*printf("La variable numero vale %d y numero2 vale %d", numero, numero2);
    */
