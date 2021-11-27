/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Tomas Perez Ponisio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "BibliotecaPersonal.h"
#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);
	char seguir = 's';
	char salir;
	int nextId = 20000;
	int cantidadEmpleados = 0;
	float salarioPromedio;
	float sumaSalarios;
	employee list[TAM];

	if (initEmployees(list, TAM)) {
		printf("Error al iniciar list\n");
	}

	do
	    {
	        switch (menu())
	        {
	        case 1:
	            if (newEmployee(list, TAM, &nextId))
	            {
	                printf("No se pudo realizar el alta\n");
	            }
	            else
	            {
	                printf("Alta exitosa\n");
	                cantidadEmpleados++;
	            }

	            break;
	        case 2:
	            if ( cantidadEmpleados == 0)
	            {
	                printf("No hay empleados cargados para editar\n");
	            }
	            else
	            {
	                printf("Modificar Empleado\n");
	                if(!editEmployee(list, TAM))
	                {
	                    printf("No se pudo modificar\n");
	                }
	                /*else
	                {
	                    printf("Cambios realizados con exito\n");
	                }*/

	            }
	            break;
	        case 3:
	            if ( cantidadEmpleados == 0)
	            {
	                printf("No hay empleados cargados para dar de baja\n");
	            }
	            else
	            {
	                if(!removeEmployee(list, TAM))
	                {
	                    printf("No se pudo realizar la baja\n");
	                }
	                else
	                {
	                    printf("Baja exitosa\n");
	                }
	            }
	            break;
	        case 4:
	            if ( cantidadEmpleados == 0)
	            {
	                printf("No hay empleados cargados para mostrar\n");
	            }
	            else
	            {
	                if(printEmployees(list, TAM))
	                {
	                    printf("No se pudo mostrar lo empleados\n");
	                }
	            }
	            break;
	        case 5:
	            if ( cantidadEmpleados == 0)
	            {
	                printf("No hay empleados cargados para mostrar\n");
	            }
	            else
	            {
	                if( salaryPromedio(list, TAM, &salarioPromedio, &sumaSalarios) )
	                {
	                    printf("No se pudo mostrar la informacion de los salarios\n");
	                }
	                else
	                {
	                    system("cls");
	                    printf("  *** Informe Salarios *** \n\n");
	                    printf("Total salarios: $%.2f\n", sumaSalarios);
	                    printf("Salario promedio: %.2f\n", salarioPromedio);
	                    printf("---------------------------------------------------------------------------\n");
	                    printf("   ID  Apellido                Nombre                 Sueldo       Sector  \n");
	                    printf("---------------------------------------------------------------------------\n");
	                    cobranBien(list, TAM, salarioPromedio, sumaSalarios);
	                }

	            }
	            break;
	        case 6:
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
	        }
	        system("pause");

	    }
	    while(seguir == 's');
	return EXIT_SUCCESS;
}
