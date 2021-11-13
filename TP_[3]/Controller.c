#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "BibliotecaPersonal.h"
#include <ctype.h>
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("\nArchivo ""data.csv"" cargado con exito. (modo texto).\n");

        pFile = fopen( path, "r");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if ( parser_EmployeeFromText( pFile, pArrayListEmployee ) )
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("\nArchivo ""data.bin"" cargado con exito. (modo binario).\n");

        pFile = fopen( path, "rb");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if ( parser_EmployeeFromBinary( pFile, pArrayListEmployee ) )
            {
                printf( "Carga de archivo binario exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    Employee* auxEmpleado;

    if ( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("Alta de empleado\n");

        auxEmpleado = employee_new();
        id = buscarMayorId(pArrayListEmployee);
        id = id + 1;
        pedirCadena(nombre, "Ingrese nombre: ", 50);
        validarEntero(&sueldo, "Ingrese el sueldo: ", "Ingrese un sueldo valido (10.000-100.000): ", 10000, 100000, 10);
        validarEntero(&horasTrabajadas, "Ingrese horas trabajadas: ", "Ingrese cantidad de horas valida (0-1000): ", 0, 1000, 10);

        if ( employee_setId(auxEmpleado, id) &&
                employee_setNombre(auxEmpleado, nombre) &&
                employee_setSueldo(auxEmpleado, sueldo) &&
                employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas)
           )
        {
            ll_add( pArrayListEmployee, auxEmpleado );
            printf("Empleado cargado con exito\n");
        }
        else
        {
            employee_delete(auxEmpleado);
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmpleado;

    char seguir = 's';
    char salir;

    int id;
    int opcion;
    int indice;

    char nombre[50];
    int sueldo;
    int horasTrabajadas;

    char confirma;

    controller_ListEmployee(pArrayListEmployee);

    if ( pArrayListEmployee != NULL )
    {
        //system("cls");
        printf("Modificar datos de empleado\n");

        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = buscarEmpleadosId( pArrayListEmployee, id );
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmpleado = ll_get(pArrayListEmployee, indice);

            do
            {
                system("cls");
                printf("\n");
                printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
                showEmployee(auxEmpleado);
                opcion = menuEdit();

                switch (opcion)
                {
                case 1:
                    system("cls");
                    printf("  Editar Nombre  \n");
                    pedirCadena(nombre, "Ingrese nombre: ", 50);

                    printf("Confirma cambio nombre? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setNombre(auxEmpleado, nombre);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }


                    break;
                case 2:
                    system("cls");
                    printf("  Editar Horas Trabajadas\n");
                    validarEntero(&horasTrabajadas, "Ingrese horas trabajadas: ", "Ingrese cantidad de horas valida (0-1000): ", 0, 1000, 10);

                    printf("Confirma cambio horas trabajadas? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }

                    break;
                case 3:
                    system("cls");
                    printf("  Editar sueldo\n");
                    validarEntero(&sueldo, "Ingrese el sueldo: ", "Ingrese un sueldo valido (10.000-100.000): ", 10000, 100000, 10);

                    printf("Confirma cambio sueldo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setSueldo(auxEmpleado, sueldo);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }

                    break;
                case 4:
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }
            while(seguir == 's');

        }
    }

    return todoOk;
}

int menuEdit()
{
    int opcion = 0;
    //system("cls");
    printf("\n");
    printf("     *** Menu de edicion ***\n");
    printf("  1- Editar nombre\n");
    printf("  2- Editar horas trabajadas\n");
    printf("  3- Editar sueldo\n");
    printf("  4- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    Employee* auxEmpleado;

    controller_ListEmployee(pArrayListEmployee);

    if ( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("Baja de empleado\n");

        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = buscarEmpleadosId( pArrayListEmployee, id );
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmpleado = ll_get(pArrayListEmployee, indice);
            printf("Empleado seleccionado: ");
            showEmployee(auxEmpleado);
            printf("\n");
            printf("Confirma la baja? (S/N)\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if ( tolower(confirma) == 's' )
            {
                ll_remove(pArrayListEmployee, indice);
                printf("Baja exitosa\n");
                todoOk = 1;
            }
        }

    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmpleado;
    if (pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Listar empleados\n");

        printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get( pArrayListEmployee, i );
            showEmployee(auxEmpleado);
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    char seguir = 's';
    char salir;

    int todoOk = 0;
    int opcion;
    if ( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("Ordenar empleados\n");

        do
        {
            opcion = menuSort();

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("  Ordenar por Horas trabajadas de menor a mayor  \n");
                ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 1 );
                controller_ListEmployee(pArrayListEmployee);

                break;
            case 2:
                system("cls");
                printf("  Ordenar por Horas trabajadas de mayor a menor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosHorasTrabajadas, 0 );
                controller_ListEmployee(pArrayListEmployee);

                break;
            case 3:
                system("cls");
                printf("  Ordenar por Sueldo de menor a mayor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 1 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                system("cls");
                printf("  Ordenar por Sueldo de mayor a menor\n");
                ll_sort( pArrayListEmployee, compararEmpleadosSueldo, 0 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 5:
                printf("Esta seguro que quiere salir? (S/N)\n");
                fflush(stdin);
                scanf("%c", &salir);
                salir = toupper(salir);
                if (salir == 'S')
                {
                    seguir = 'n';
                }
                else
                {
                    break;
                }
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            system("pause");
        }
        while(seguir == 's');
    }
    return todoOk;

}

int menuSort()
{
    int opcion = 0;
    system("cls");
    printf("     *** Menu de ordenamiento ***\n");
    printf("  1- Ordenar por Horas trabajadas de menor a mayor\n");
    printf("  2- Ordenar por Horas trabajadas de mayor a menor\n");
    printf("  3- Ordenar por Sueldo de menor a mayor\n");
    printf("  4- Ordenar por Sueldo de mayor a menor\n");
    printf("  5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}

int compararEmpleadosHorasTrabajadas(void* employeeA, void* employeeB)
{
    int todoOk= 0;

    if( ((Employee*)employeeA)->horasTrabajadas > ((Employee*)employeeB)->horasTrabajadas )
    {
        todoOk= 1;
    }
    if( ((Employee*)employeeA)->horasTrabajadas < ((Employee*)employeeB)->horasTrabajadas )
    {
        todoOk = -1;
    }
    return todoOk;
}

int compararEmpleadosSueldo(void* employeeA, void* employeeB)
{
    int todoOk= 0;

    if(((Employee*)employeeA)->sueldo > ((Employee*)employeeB)->sueldo)
    {
        todoOk= 1;
    }
    if(((Employee*)employeeA)->sueldo <
            ((Employee*)employeeB)->sueldo)
    {
        todoOk = -1;
    }
    return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("\nArchivo ""data.csv"" guardado con exito. (modo texto).\n");

        pFile = fopen(path, "w"); // abro el archivo
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
            exit(1);
        }

        fprintf( pFile, "id,nombre,horasTrabajadas,sueldo\n" );

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if ( employee_getId( auxEmpleado, &id ) &&
                    employee_getNombre( auxEmpleado, nombre ) &&
                    employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
                    employee_getSueldo(auxEmpleado, &sueldo)
               )
            {
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("\nArchivo ""data.bin"" guardado con exito. (modo binario).\n");

        pFile = fopen(path, "wb"); // abro el archivo
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
            exit(1);
        }

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);

//            // asi esta en la clase de baus
//            if ( (auxEmpleado + i) != NULL )

            if ( (auxEmpleado) != NULL )
            {
                fwrite( auxEmpleado, sizeof(Employee), 1, pFile );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

