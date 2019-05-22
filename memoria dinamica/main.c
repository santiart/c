#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define TAMA 10

int validarMalloc(void* punt);


int main()
{
    int* pnum;
    int* paux;
    int i;
    pnum = (int*) malloc(sizeof(int) * TAM);
    if (validarMalloc(pnum)==1)
    {
        exit(1);
    }
    for(i=0;i<TAM;i++)
    {
        printf("\ningrese numero: ");
        scanf("%d", pnum+i);
    }
    for(i=0;i<TAM;i++)
    {
        printf("%d", *(pnum+i));
    }
    paux = (int*) realloc(pnum, sizeof(int)*TAMA);
    if(paux!=NULL)
    {
        pnum=paux;
    }
    else
    {
        printf("no se pudo realocar memoria");
    }
        for(i=5;i<TAMA;i++)
    {
        printf("\ningrese numero: ");
        scanf("%d", pnum+i);
    }
    for(i=0;i<TAMA;i++)
    {
        printf("%d", *(pnum+i));
    }
    paux = (int*) realloc(pnum, sizeof(int)*TAM);
    if(paux!=NULL)
    {
        pnum=paux;
    }
    else
    {
        printf("no se pudo realocar memoria");
    }
        for(i=0;i<TAM;i++)
    {
        printf("\ningrese numero: ");
        scanf("%d", pnum+i);
    }
    for(i=0;i<TAM;i++)
    {
        printf("%d", *(pnum+i));
    }
    free(pnum);



    return 0;
}

int validarMalloc(void* punt)
{
    if(punt == NULL)
    {
        printf("no se consiguio memoria\n");
        system("pause");
        return(1);
    }
    else
    {
        return(0);
    }
}
