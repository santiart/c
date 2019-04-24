#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#define TAM 3
#define TAMSEC 5


int main()
{
    eFecha fechas[]=
    {
        {1,"10/02/2000"};
        {2,"3/05/2009"};
        {3,"20/08/2013"};
    }
    eSector sectores[]=
    {
        {1, "Sistemas"};
        {2, "RRHH"};
        {3, "Compras"};
        {4, "Ventas"};
        {5, "Legales"};
    }
    eAlmuerzo menu[]=
    {
        {1,"Ravioles"};
        {2,"Pizza"};
        {3,"Sopa"};
        {4,"Ensalada"};
        {5,"Milanesa"};
    }
    eEmpleado lista[TAM]=
    {
        {1111,"Perez","Juan",'m', 50000,1,1,1,2};
        {1111,"Sanchez","Ana",'f', 45000,1,3,4,5};
        {1111,"Dominguez","Pablo",'m', 23500,1,2},2,4;
    }

    do{
        printf("    ::L I S T A  D E  C O M I D A S::     ");
        printf("   1-")
    }

    return 0;
}
