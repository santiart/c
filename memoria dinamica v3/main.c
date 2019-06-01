#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#define TAM 5

int main()
{
    int* ptrNum;
    int* ptrAux;
    char respuesta;
    ptrNum = (int*)malloc(sizeof(int)*5);
    if(ptrNum == NULL)
    {
        printf("no se pudo obtener memoria...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<TAM;i++)
    {
        printf("ingrese un numero: \n");
        scanf("%d",ptrNum+i);
    }
    for(int i=0;i<TAM;i++)
    {
        printf("%d", *(ptrNum+i));
    }
    printf("\n\n");
    printf("desea agregar mas numeros? (s/n)...\n");
    respuesta = getche();
    printf("\n\n");
    if(tolower(respuesta)=='s')
    {
        ptrAux=(int*)realloc(ptrNum,sizeof(int)*TAM+5);
        if((ptrAux=NULL))
        {
            printf("no se pudo realocar la memoria\n");
            system("pause");
            exit(EXIT_FAILURE);
        }
        for(int i=TAM;i<TAM+5;i++)
        {
            printf("ingrese un numero: \n");
            scanf("%d", ptrNum+i);
        }
        for(int i=0;i<TAM+5;i++)
        {
            printf("%d", *(ptrNum+i));
        }
    }

    return 0;
}
