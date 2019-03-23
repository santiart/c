#include <stdio.h>
#include <stdlib.h>


int pedirNota(void);
float promedioNotas(int suma,int cantidad);
int sacarAprobacion(int notaMin, int nota);

int main()
{
    int notaI;
    int aprobar;
    aprobar=sacarAprobacion();
    int aprobados=0;
    int sumaAprobados=0;
    int desaprobados;
    float promedios;
    float promDesaprobados=0;
    for(int i=0;i<5;i++)
    {
        notaI=pedirNota();
        sumaAprobados+=aprobados;

    }
}

/** \brief
    int elNumeroIngresado;
    int aprobar;
    int aprobados;
    int noAprobados;
    float promedio;
    elNumeroIngresado=pedirNota();
    printf("el numero ingresado es: %d", elNumeroIngresado);
    promedio=promedioNotas(100,5);
    printf("el promedio es: %f", promedio);
    aprobar=sacarAprobacion(6,10);
    if(sacarAProbacion(6,elNumeroIngresado))
    {
        aprobados++;
    }
    else
    {
        noAprobados++
    }

return 0;
}

int sacarAprobacion(int notaMin, int nota)
{
    int retorno;
    if(nota>= notaMin)
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int pedirNota()
{
    int i;
    int nota;
    for(i=0;i<5;i++)
    {

    }

}


float sacarPromedio(int suma,int cantidad)
{
    float retorno;
    retorno=(float)suma/cantidad;
    return retorno;
}
 *pide un numero
 * \param void
 * \return int
 *numero a devolver
 *
int pedirNumero(void);
/** \brief
 *
 * \param suma int
 * \param cantidad int
 * \return float
 *


int main()
{
    int elnumeroIngresado;
    elnumeroIngresado=pedirNumero();
    printf("el numero ingresado es: %d");
    float promedio;
    promedio=sacarPromedio();
    printf("el promedio es de: \n %f", promedio);

}

int

pedirNumero()
{
    int numero;
    do
    {
        printf("ingrese un numero: %d");
        scanf("&d",&numero);
    }while(numero<0||numero>10);
    {
        return numero;
    }
}










int pedirNumero(void);
int main()
{
   int elNumeroIngresado;
   elNumeroIngresado=pedirNumero();
   printf("el numero ingresado es: \n %d", elNumeroIngresado);


}
int pedirNumero()
{
    int numero;
    do
    {
        printf("ingrese un numero: \n");
        scanf("%d",&numero);
    }while(numero<0||numero>10);

    return numero;

}

    int numero;

    printf("ingrese un numero del 0 al 10: \n");
    scanf("%d",&numero);
    while(numero<0 || numero>10)
    {
        scanf("%d",&numero);
    }

    printf("usted ingreso: %d",numero);
*/

    //tomarnum(int)
    //return=numero
