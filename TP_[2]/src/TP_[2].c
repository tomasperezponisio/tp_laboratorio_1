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
	char seguir = 's';
	char salir;
	int nextId = 20000;
	employee list[TAM];

	//---*******     LISTA DE EMPLEADOS HARDCODEADOS PARA PROBAR
	/*employee list[TAM] =
	 {
	 {1, "Juan", "Perez", 10000, 1, 0},
	 {222, "Maria", "Garcia", 12000, 1, 0},
	 {333, "Julia", "Balinia", 11000, 3, 0},
	 {444, "Pedro", "Corrales", 13500, 2, 0},
	 {555, "Cristina", "Ponisio", 15000, 1, 0},
	 {666, "Alejandro", "Perez", 16500, 3, 0},
	 {777, "Paula", "Gomez", 9500, 2, 0}
	 };*/

	if (initEmployees(list, TAM)) {
		printf("Error al iniciar list\n");
	}

	do {
		switch (menu()) {
		case 1:
			if (newEmployee(list, TAM, &nextId)) {
				printf("No se pudo realizar el alta\n");
			} else {
				printf("Alta exitosa\n");
			}

			break;
		case 2:
			printf("Modificar Empleado\n");
			if (!editEmployee(list, TAM)) {
				printf("No se pudo modificar\n");
			}
			/*else
			 {
			 printf("Cambios realizados con exito\n");
			 }*/
			break;
		case 3:
			if (!removeEmployee(list, TAM)) {
				printf("No se pudo realizar la baja\n");
			} else {
				printf("Baja exitosa\n");
			}
			break;
		case 4:
			if (printEmployees(list, TAM)) {
				printf("No se pudo mostrar lo empleados\n");
			}

			break;
		case 5:
			printf("Esta seguro que quiere salir? (S/N)\n");
			fflush(stdin);
			scanf("%c", &salir);
			salir = toupper(salir);
			if (salir == 'S') {
				seguir = 'n';
			} else {
				break;
			}
			break;
		default:
			printf("Opcion invalida\n");
		}
		system("pause");

	} while (seguir == 's');
	return EXIT_SUCCESS;
}
