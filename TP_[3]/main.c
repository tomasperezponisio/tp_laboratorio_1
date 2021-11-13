#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <ctype.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	 setbuf(stdout,NULL);
	 char seguir = 's';
	    char salir;
	    LinkedList* listaEmpleados = ll_newLinkedList();
	    do
	    {
	        switch (menu())
	        {
	        case 1:
	            if ( !controller_loadFromText("data.csv", listaEmpleados) )
	            {
	                printf("Error al cargar desde texto\n");
	            }
	            break;
	        case 2:
	            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
	            {
	                printf("Error al cargar desde binario\n");
	            }
	            break;
	        case 3:
	            if ( !controller_addEmployee(listaEmpleados) )
	            {
	                printf("Error en alta de empleado\n");
	            }
	            break;
	        case 4:
	            if ( !controller_editEmployee(listaEmpleados) )
	            {
	                printf("Error en edicion de empleado\n");
	            }
	            break;
	        case 5:
	            if ( !controller_removeEmployee(listaEmpleados) )
	            {
	                printf("Error en baja de empleado\n");
	            }
	            break;
	        case 6:
	            if ( !controller_ListEmployee(listaEmpleados) )
	            {
	                printf("Error en baja de empleado\n");
	            }
	            break;
	        case 7:
	            if ( !controller_sortEmployee(listaEmpleados) )
	            {
	                printf("Error en ordenamiento de empleados\n");
	            }
	            break;
	        case 8:
	            if ( !controller_saveAsText("data.csv", listaEmpleados) )
	            {
	                printf("Error al guardar en modo texto\n");
	            }

	            break;
	        case 9:
	            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
	            {
	                printf("Error al guardar en modo binario\n");
	            }


	            break;
	        case 10:
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
	    return 0;
}

