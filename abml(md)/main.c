#include <stdio.h>
#include <stdlib.h>
//#include <input.h>
#define TAM 3

typedef struct
{
    int dia,mes,anio;
} eFecha;

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo[10];
    float sueldo;
    eFecha fechaIngreso;
    int estado;
} eEmpleado;

int buscarLugarLibre(eEmpleado* lista, int tam);
void altaEmpleado(eEmpleado* lista, int tam);

int main()
{
    FILE* empleado;
    //FILE* pArchTxt;
    eEmpleado* ptrEmp;
    int escritura;
    ptrEmp = (eEmpleado*)malloc(sizeof(eEmpleado)*TAM);

    empleado = fopen("./empleados.csv", "ab");
    if(empleado == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    altaEmpleado(ptrEmp,TAM);
    fprintf(empleado,"nombre          apellido           sexo                  sueldo\n");
    escritura = fwrite(ptrEmp,sizeof(eEmpleado),TAM,empleado);
    if(escritura<1)
    {
        printf("error al escribir archivo...\n");
    }

    eEmpleado* punteroEmp=(eEmpleado*)malloc(sizeof(eEmpleado)*TAM);
    int i=0;
    while(!feof(empleado))
    {
        printf("esdgdf");
        fread(punteroEmp+i,sizeof(eEmpleado),1,empleado);
        i++;
    }


    //pArchTxt=fopen("./empTexto.txt","w");
    for(int i=0; i<TAM; i++)
    {
        if(ptrEmp->id!=-1)
        {
            fprintf(empleado,"%d\t\%s\t\%s\t\%.2f\n",(ptrEmp+i)->id,(ptrEmp+i)->nombre,(ptrEmp+i)->apellido,(ptrEmp+i)->sueldo);
        }
    }
    printf("id: %d\t\ nombre: %s\t\ apellido: %s\t\sueldo: %.2f\n",ptrEmp->id,ptrEmp->nombre,ptrEmp->apellido,ptrEmp->sueldo);

    fclose(empleado);
    printf("\nalta exitosa!!!");
    return 0;
}

int buscarLugarLibre(eEmpleado* lista, int tam)
{
    int indice=-1;
    for(int i = 0; i < tam; i++)
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
    char auxSexo[10];
    char auxSueldo[20];

    indice = buscarLugarLibre(lista,tam);
    if(indice!=-1)
    {
        printf("no hay lugar disponible en el sistema\n");
    }
    else
    {
        id=indice+1;
        lista->id=id;

        while(!getStringLetras("ingrese el nombre : \n",auxNombre))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(lista->nombre,auxNombre);

        while(!getStringLetras("ingrese el apellido :",auxApellido))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(lista->apellido,auxApellido);

        while(!getStringLetras("ingrese el sexo: ", auxSexo))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(lista->sexo,auxSexo);

        while(!getStringNumeros("ingrese el sueldo: ",auxSueldo))
        {
            printf("intente de nuevo...\n");
        }
        lista->sueldo = atoi(auxSueldo);
    }

}
