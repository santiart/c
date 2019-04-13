#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 5

int getNota(char *mensaje,float *nota);
int getSexo(char *sexo);


typedef struct
{
    char nombre[20];
    int nota;
}Alumno;


int main()
{
    Alumno Estudiante[TAMANIO];
    int i;
    int j;

    for(i=0;i<TAMANIO;i++)
    {
        while((getNota("\n ingrese la nota")))
    }





    return 0;
}
int getNota(char *mensaje,float *nota)
{
    char ingreso[50];
    int retorno=0;
    printf(mensaje);
    scanf("%s", ingreso);

    if(strlen(ingreso)==6)
    {
        strcpy(nota,ingreso);
        retorno=1;
    }
    return retorno;

}
