#include <stdio.h>
#include <stdlib.h>
#define TAM 1

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int estado;
}eEmpleado;

int buscarLugarLibre(eEmpleado* lista, int tam);
void altaEmpleado(eEmpleado* lista, int tam);

int main()
{
    FILE* empleado;
    eEmpleado emp, *ptrEmp;
    ptrEmp = &emp;

    empleado = fopen("./empleados.csv", "w");
    if(empleado == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    altaEmpleado(ptrEmp,TAM);
    /*
    printf("ingrese un id: ");
    scanf("%d", &ptrEmp->id);
    printf("%d", ptrEmp->id);
    */



    return 0;
}

int buscarLugarLibre(eEmpleado* lista, int tam)
{
    int indice=-1;
    for(int i = 0;i < tam; i++)
    {
        if(lista->estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado* lista, int tam)
{
    //eEmpleado emp, *pEmp;
    //pEmp=&emp;
    int indice;
    int id;
    char auxNombre[20];
    char auxApellido[20];
    char auxSexo;
    char auxSueldo[20];
    indice = buscarLugarLibre(lista,tam);

    if(indice!=-1)
    {
        printf("no hay lugar disponible en el sistema\n");
    }
    else
    {
        id=indice+1;

        while(!getStringLetras("ingrese el nombre del empleado: \n"),auxNombre)
        {
           //printf("debe usar solo letras...\n");
        }
        strcpy(lista->nombre,auxNombre);

    }

}
