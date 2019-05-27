#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
    int id;
    char nombre[20];
    //char apellido[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int estado;
}eEmpleado;

int main()
{
    FILE* empleado;
    eEmpleado emp, *ptrEmp;
    ptrEmp = &emp;

    empleado = fopen("./empleados.txt", "w");
    if(empleado == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    printf("ingrese un id: ");
    scanf("%d", &ptrEmp->id);
    printf("%d", ptrEmp->id);

    return 0;
}
