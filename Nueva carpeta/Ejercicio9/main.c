#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int contador;
    int contadorA=0;
    int contadorE=0;
    int contadorI=0;
    int contadorO=0;
    int contadorU=0;

    for(contador=0;contador<20;contador++)
    {
        printf("Ingresar una letra\n");
        letra=getchar();
        getchar();//estoy tomando el \n

        switch(letra)
        {
            case 'a':
                contadorA++;
                break;
            case 'e':
                contadorE++;
                break;
            case 'i':
                contadorI++;
                break;
            case 'o':
                contadorO++;
                break;
            case 'u':
                contadorU++;
                break;
        }

        //system("clear");
    }

    printf("Cantidad de A: %d\n", contadorA);
    printf("Cantidad de E: %d\n", contadorE);
    printf("Cantidad de I: %d\n", contadorI);
    printf("Cantidad de O: %d\n", contadorO);
    printf("Cantidad de U: %d\n", contadorU);

    return 0;
}
