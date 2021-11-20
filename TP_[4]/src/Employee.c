#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        newEmployee->id = 0; // el id es autoincremental?
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee = employee_new();
    if (newEmployee != NULL)
    {
        newEmployee->id = atoi(idStr); // el id es autoincremental?
        strcpy(newEmployee->nombre, nombreStr);
        newEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
        newEmployee->sueldo = atoi(sueldoStr);
    }
    return newEmployee;
}

void employee_delete(Employee* pEmployee)
{
    if (pEmployee != NULL)
    {
        free(pEmployee);
    }
}

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if (this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL && strlen(nombre) > 0 && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if (this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if (this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** ABM Employee ***\n");
    printf("  1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("  2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("  3- Alta de empleado\n");
    printf("  4- Modificar datos de empleado\n");
    printf("  5- Baja de empleado\n");
    printf("  6- Listar empleados\n");
    printf("  7- Ordenar empleados\n");
    printf("  8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("  9- Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("  10- Reemplazar empleado\n");
    printf("  11- Borrar empleados\n");
    printf("  12- Eliminar lista\n");
    printf("  13- Buscar indice empleado\n");
    printf("  14- Sublista\n");
    printf("  15- Clonar lista\n");
    printf("  20- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}

int showEmployee(Employee* employee)
{
    int todoOk = 0;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;

    if (employee != NULL)
    {
        todoOk = 1;
        if ( employee_getId( employee, &id ) &&
                employee_getNombre( employee, nombre ) &&
                employee_getHorasTrabajadas( employee, &horasTrabajadas) &&
                employee_getSueldo(employee, &sueldo)
           )
        {
            printf ("%-7d %-15s %-8d            %-6d\n", id, nombre, horasTrabajadas, sueldo);
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarMayorId(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado = NULL;
    int mayor = 0;
    int id;
    if(pArrayListEmployee != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmpleado, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}

int buscarEmpleadosId(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    int idAux;
    Employee* auxEmpleado;

    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = ll_get(pArrayListEmployee, i);
        if( employee_getId(auxEmpleado, &idAux) && idAux == id)
        {
            indice = i;
        }
    }
    return indice;
}

