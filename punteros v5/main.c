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
    char apellido[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;

}eEmpleado;



int main()
{
    eEmpleado unEmpleado = {1234, "juan", "perez", 'm', 45000, {13,5,2019}};

    eEmpleado otroEmpleado = {2222, "ana","farias", 'f', 40000, {12,06,2000}};

    eEmpleado lista[] = {unEmpleado, otroEmpleado};
    for(int i=0; i<2;i++)
    {
        printf("nombre empleado: %s\n", (lista+1)->nombre);
    }

    /*
    eEmpleado* punteroEmp;
    punteroEmp = &unEmpleado;

    printf("id: %d\n", punteroEmp->id);
    printf("nombre: %s \n", punteroEmp->nombre);
    printf("apellido: %s \n", punteroEmp->apellido);
    printf("sexo: %c \n", punteroEmp->sexo);
    printf("sueldo: %.2f\n", punteroEmp->sueldo);
    printf("Anio: %d \n", punteroEmp->fechaIngreso.anio);
    printf("nombre: %s \n", (*punteroEmp).nombre);
    printf("mes: %d \n", (*punteroEmp).fechaIngreso.mes);
*/
    return 0;
}
