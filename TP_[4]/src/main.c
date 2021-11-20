/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include <ctype.h>
#include "Controller.h"
#include "Employee.h"

// ******  FUNCIONES UTILIZADAS  *******

/*
        // ll_newLinkedList ---- UTILIZADA en el main y en varias funciones controller
        // ll_len -------------- UTILIZADA en varias funciones controller
        // ll_add -------------- UTILIZADA en la funcion controller_addEmployee
        // ll_get -------------- UTILIZADA en varias funciones controller
        // ll_set -------------- UTILIZADA en la funcion controller_replaceEmployee
        // ll_remove ----------- UTILIZADA en la funcion ll_pop
        // ll_clear ------------ UTILIZADA en la funcion controller_clearList
        // ll_deleteLinkedList - UTILIZADA en la funcion controller_deleteList
        // ll_indexOf ---------- UTILIZADA en la funcion controller_findEmployee
        // ll_isEmpty ---------- UTILIZADA en la funcion controller_ListEmployee
        // ll_push ------------- UTILIZADA en la funcion controller_addEmployee
        // ll_pop -------------- UTILIZADA en la funcion controller_removeEmployee
        // ll_contains --------- UTILIZADA en la funcion controller_removeEmployee
        // ll_containsAll ------ UTILIZADA en las funciones controller_subList y en controller_cloneList
        // ll_subList ---------- UTILIZADA en la funcion controller_subList
        // ll_clone ------------ UTILIZADA en la funcion controller_cloneList
        // ll_sort ------------- UTILIZADA en la funcion controller_sortEmployee
*/

int main()
{
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
                printf("Error al listar empleados\n");
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
            if ( !controller_replaceEmployee(listaEmpleados) )
            {
                printf("Error al reemplazar empleado\n");
            }
            break;
        case 11:
            if ( !controller_clearList(listaEmpleados) )
            {
                printf("Error al borrar los empleados\n");
            }
            break;
        case 12:
            if ( !controller_deleteList(listaEmpleados) )
            {
                printf("Error al vaciar la lista\n");
            }
            listaEmpleados = NULL;
            break;
        case 13:
            if ( !controller_findEmployee(listaEmpleados) )
            {
                printf("Error al busca indice\n");
            }
            break;
        case 14:
            if ( !controller_subList(listaEmpleados) )
            {
                printf("Error al crear sublista\n");
            }
            break;
        case 15:
            if ( !controller_cloneList(listaEmpleados) )
            {
                printf("Error al clonar lista\n");
            }
            break;
        case 20:
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
