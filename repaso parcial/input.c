#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include <ctype.h>

float sumar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float restar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float dividir(float numeroX, float numeroY)
{
    float resultado;
    if(numeroY == 0)
    {
        printf("\n\nNo se puede dividir por '0'\n\n");
    }
    else
    {
        resultado = numeroX/numeroY;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial(int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1; i<=numero; i++)
            fact=fact*i;
    }
    return fact;
}
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje)
{
    int aux;
    int contador;
    int ok = 0;

    printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
    scanf("%d", &aux);

    while((aux<min || aux>max) && contador < intentos)
    {
        contador++;
        //fflush(stdin);

        if(contador == intentos)
        {
            break;
        }
        printf("%s %d y %d.\n\n", eMensaje, min, max);
        printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
        scanf("%d", &aux);
    }
    if(contador < intentos)
    {
        *dato = aux;
        ok = 1;
    }
    return ok;
}
int getInt(char* mensaje)
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

float getFloat(char* mensaje)
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;

}

char getChar(char* mensaje)
{
    fflush(stdin);
    char aux;
    printf("%s",mensaje);
    scanf("%c",&aux);
    return aux;
}
int esNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }
    return sePudo;
}
int esDia(int dia)
{
    int sePudo = 0;
    if(dia<1 || dia> 32)
    {
        sePudo = 0;
    }
    else
    {
        sePudo=1;
    }
    return sePudo;
}
int esMes(int mes)
{
    int sePudo = 0;
    if(mes<1 || mes> 12)
    {
        sePudo = 0;
    }
    else
    {
        sePudo=1;
    }
    return sePudo;
}

int esAnio(int anio)
{
    int sePudo = 0;
    if(anio<1900 || anio> 2019)
    {
        sePudo =0;
    }
    else
    {
        sePudo=1;
    }
    return sePudo;
}

int esSoloLetra(char letra)
{
    int sePudo=0;
    if((letra<'a'||letra>'z')&&(letra<'A'||letra>'Z'))
    {
        sePudo=0;
    }
    else
    {
        sePudo=1;
    }
    return sePudo;
}
int esSoloLetras(char cadena[])
{
    int sePudo = 0;
    int contNoSePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        //if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        if((cadena[i]<'a'||cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            contNoSePudo++;
        }
        i++;
    }
    if(contNoSePudo>=1)
    {
        sePudo=0;
    }
    else
    {
        sePudo=1;
    }
    return sePudo;
}
int esAlfaNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }

    return sePudo;
}
int esTelefono(char cadena[])
{
    int sePudo=0;
    int i=0;
    int cantidadGuiones=0;
    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]!='-')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        if(cadena[i]=='-')
        {
            cantidadGuiones++;
        }
        i++;
    }
    if(cantidadGuiones==1)
    {
        sePudo=1;
    }
    return sePudo;
}

int burbujeo(char cadena[], int largoCadena, char signo)
{
    int retorno=0;
    char aux;
    if(signo=='<')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]>cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    else if(signo=='>')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]<cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}
