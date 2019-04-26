#include <stdio.h>
#include <stdlib.h>

float obtenerDivision(int x, int y)
{
    float resta;
    if(y!=0)
    {
        resta=(float)x/y;

    }
    else{
        printf("no se puede dividir por 0 \n" );
    }
        return resta;
}
