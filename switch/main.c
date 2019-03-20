#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hora;
    scanf("%d",&hora);
    switch(hora)
    {
        case 0 ... 6:
            {
                printf("a dormir \n");
                break;
            }
        case 7 ... 9:
            {
                printf("buen dia \n");
                break;
            }
        case 10 ... 23:
            {
                printf("hola");
                break;
            }
        default:{

        printf("hora no valida");
        break;
        }

    }

    return 0;
}
