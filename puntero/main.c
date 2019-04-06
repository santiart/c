#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dameEdad(int* edad,char* mensaje);
int dameEdadDos(int* edad,char* mensaje);
int dameEdadTres(int* edad, char* mensaje);
int main()
{
    int laEdad;
    int seCargo;
    do
    {
        seCargo=dameEdadTres(&laEdad,"ingrese edad\n");

        if(seCargo==1)
        {
            printf("se pudo\n");
        }
        else
        {
            printf("no se pudo\n");
        }
    }
    while(seCargo==0);
    printf("la edad ingresada es: %d",laEdad);

    /*
        if(dameEdadTres(&laEdad,"dame la edad")==1)
        {
            printf("la edad es: %d",laEdad);
        }
        else
        {
            printf("no se pudo obtener la edad");
        }
    */
    return 0;
}
/*
dameEdad(int* edad, char* mensaje)
{
    int aux=0;
    int sePudo=0;
    printf(mensaje);
    sePudo=scanf("%d",&aux);
    if(sePudo==1)
    {
        *edad=aux;
    }
    return sePudo;
}
/** \brief en esta funcion pedimos la edad de la persona
 *
 * \param edad int* obtiene la edad
 * \param mensaje char* muestra el mensaje de si se pudo o no
 * \return int devuelve el mensaje
 *
 */
/*
int dameEdadDos(int* edad,char* mensaje)
{
   char cadenaCargada[20];//puntero memoria
   int sePudo=1;
   printf(mensaje);
   scanf("%s",cadenaCargada);
   *edad=atoi(cadenaCargada);

   return sePudo;
}
*/
int dameEdadTres(int*edad,char*mensaje)
{
    char cadenaCargada[20];
    int i;
    int sePudo=1;
    int cantCaracteres;
    printf(mensaje);
    sePudo=scanf("%s",cadenaCargada);
    for(i=0; i<strlen(cadenaCargada); i++)
    {
        if(cadenaCargada[i]<'0' || cadenaCargada[i]>'9')
        {
            sePudo=0;
            break;
        }
    }
    if(sePudo==1)
    {
        *edad=atoi(cadenaCargada);
    }

    return sePudo;
}
