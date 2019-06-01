#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct{
    int id;
    char descripcion[51];
}eSector;

typedef struct{
    int codigoMenu;
    char descripcion[51];
    float importe;
}eMenu;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codigoAlmuerzo;
    int codigoMenu;
    int legajoEmpleado;
    eFecha fecha;
}eAlmuerzo;

typedef struct{
    int legajo;
    char apellido[51];
    char nombre[51];
    char sexo;
    float salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;
}eEmpleado;

void iniciarlizarEmpleados(eEmpleado emp[], int tam);

int buscarEspacio(eEmpleado emp[], int tam);

void inicializarSectores(eSector sectores[], int cantidad);

void inicializarMenus(eMenu menus[], int cantidad);

int altaEmpleado(eEmpleado emp[], int tam, eSector sec[], int tamSec, int id);

int menuPrincipal();

int menuAlta();

void mostrarSectores(eSector sec[], int tamSec);

void modificarEmpleado(eEmpleado emp[], int tam);

int buscarEmpleado(eEmpleado emp[], int tam, int legajoAbuscar);
void mostrarEmpleados(eEmpleado emp[], int tam);
void mostrarEmpleado(eEmpleado emp);
#endif // EMPLEADO_H_INCLUDED
