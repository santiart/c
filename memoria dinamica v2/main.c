#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;


int main()
{
    eEmpleado emp1;
    eEmpleado* pEmp = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(pEmp == NULL)
    {
        printf("no se encontro memoria...\n");
        exit(1);
    }
    else
    {
        printf("ingrese el legajo: \n");
        scanf("%d", &pEmp->legajo);

        printf("ingrese el nombre: \n");
        fflush(stdin);
        scanf("%s", pEmp->nombre);

        printf("ingrese el sexo: \n");
        fflush(stdin);
        scanf("%c", &pEmp->sexo);

        printf("ingrese el sueldo: \n");
        scanf("%f", &pEmp->sueldo);

        printf("%d %10s  %10c  %10.2f", pEmp->legajo, pEmp->nombre, pEmp->sexo,pEmp->sueldo);
    }
    return 0;
}
