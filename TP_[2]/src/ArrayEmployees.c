/*
 * ArrayEmployees.c
 *
 *  Created on: 16 Oct 2021
 *      Author: Tomas Perez Ponisio
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "BibliotecaPersonal.h"

int menu() {
	int opcion = 0;
	system("cls");
	printf("     *** ABM Empleados ***\n");
	printf("1- Alta Empleado\n");
	printf("2- Modificar Empleado\n");
	printf("3- Baja Empleado\n");
	printf("4- Informar Empleados\n");
	printf("5- Informe Salarios\n");
	printf("6- Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	//printf("\n");
	return opcion;
}

int initEmployees(employee list[], int len) {
	int todoOk = -1;
	if (list != NULL && len > 0) {
		todoOk = 0;
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
	}
	return todoOk;
}

int findFree(employee list[], int len) {
	int indice = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty) {
			indice = i;
			break;
		}
	}
	return indice;
}
int addEmployee(employee list[], int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int todoOk = -1;
	int indice;

	if (list != NULL && len > 0 && name != NULL && lastName != NULL
			&& salary > 0 && sector > 0) {
		indice = findFree(list, len);

		list[indice].id = id;
		strncpy(list[indice].name, name, sizeof(list[indice].name));
		strcpy(list[indice].name, name);
		strncpy(list[indice].lastName, lastName, sizeof(list[indice].lastName));
		strcpy(list[indice].lastName, lastName);
		list[indice].salary = salary;
		list[indice].sector = sector;
		list[indice].isEmpty = 0;

		todoOk = 0;
	}
	return todoOk;
}
int newEmployee(employee list[], int len, int *pId) {
	int todoOk = -1;
	int indice;

	int auxId;
	char auxName[15];
	char auxLastName[15];
	float auxSalary;
	int auxSector;

	if (list != NULL && len > 0 && pId != NULL) {
		system("cls");
		printf("  ***Alta Empleado*** \n\n");
		indice = findFree(list, len);
		if (indice == -1) {
			printf("No hay lugar\n");
		} else {
			auxId = *pId;
			(*pId)++;

			if (!pedirCadena(auxName, "Ingrese Nombre: ", sizeof(auxName))) {
				printf("Error al ingresar nombre\n");
			}

			if (!pedirCadena(auxLastName, "Ingrese Apellido: ",
					sizeof(auxLastName))) {
				printf("Error al ingresar el apellido\n");
			}

			if (!validarFloat(&auxSalary, "Ingrese el sueldo: ",
					"Error, un sueldo valido: ", 1, 1000000, 3)) {
				printf("Error al ingresar el sueldo\n");
			}

			if (!validarEntero(&auxSector, "Ingrese el sector: ",
					"Error, ingrese nuevamente (sectores del 1 al 5): ", 1, 5,
					3)) {
				printf("Error al ingresar el sector\n");
			}

			todoOk = addEmployee(list, len, auxId, auxName, auxLastName,
					auxSalary, auxSector);
		}
	}
	return todoOk;
}

int menuSort() {
	int retorno;
	printf("Mostrar en orden ascendente o descendente? (a/d): ");
	fflush(stdin);
	char opcion = getchar();
	opcion = tolower(opcion);
	while (opcion != 'a' && opcion != 'd') {
		printf("Opcion incorrecta, ingrese nuevamente (a/d): ");
		fflush(stdin);
		opcion = getchar();
		opcion = tolower(opcion);
	}
	if (opcion == 'a') {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(employee list[], int len, int order) {
	int todoOk = -1;
	employee auxEmployee;
	if (list != NULL && len > 0 && order >= 0 && order <= 1) {
		todoOk = 0;
		switch (order) {
		case 1:
			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					if (strcmp(list[i].lastName, list[j].lastName) > 0
							|| (strcmp(list[i].lastName, list[j].lastName) == 0
									&& list[i].sector > list[j].sector)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
			break;
		case 0:
			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					if (strcmp(list[i].lastName, list[j].lastName) < 0
							|| (strcmp(list[i].lastName, list[j].lastName) == 0
									&& list[i].sector < list[j].sector)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
			break;
		}
	}
	return todoOk;
}

void printEmployee(employee e) {
	printf(" %4d  %-15s         %-15s       $%-8.1f       %-2d\n", e.id,
			e.lastName, e.name, e.salary, e.sector);
}

int printEmployees(employee list[], int len) {
	int todoOk = -1;
	int flag = 1;
	int orden;
	if (list != NULL && len > 0) {
		orden = menuSort();
		sortEmployees(list, len, orden);

		system("cls");
		printf("                     ***Lista de Empleados  ***\n");
		printf(
				"---------------------------------------------------------------------------\n");
		printf(
				"   ID  Apellido                Nombre                 Sueldo       Sector  \n");
		printf(
				"---------------------------------------------------------------------------\n");

		for (int i = 0; i < len; i++) {
			if (!list[i].isEmpty) {
				printEmployee(list[i]);
				flag = 0;
			}
		}
		if (flag) {
			printf("No hay empleados para mostrar.\n");

		}
		todoOk = 0;
	}
	return todoOk;
}

int findEmployeeById(employee list[], int len, int id) {
	int indice = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].id == id && list[i].isEmpty == 0) {
			indice = i;
			break;
		}
	}
	return indice;
}

int removeEmployee(employee list[], int len) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	if (list != NULL && len > 0) {
		system("cls");
		printf("   *** Baja Empleado *** \n\n");
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = findEmployeeById(list, len, id);

		if (indice == -1) {
			printf("El id: %d no esta registrado en el sistema\n", id);
		} else {
			printEmployee(list[indice]);
			printf("Confirma baja?: ");
			fflush(stdin);
			scanf("%c", &confirma);
			if (confirma == 's') {
				list[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada por el usuario.\n");
			}
		}
	}
	return todoOk;
}

int editEmployee(employee list[], int len) {
	int todoOk = 0;
	int indice;
	int id;
	char confirma;
	char seguir = 's';
	char salir;
	employee auxEmployee;
	if (list != NULL && len > 0) {
		system("cls");
		printf("   *** Modificar Empleado *** \n\n");
		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = findEmployeeById(list, len, id);

		if (indice == -1) {
			printf("El id: %d no esta registrado en el sistema\n", id);
		} else {
			do {
				switch (editMenu(list, len, indice)) {
				case 1:
					printf("Modificar nombre: ");
					fflush(stdin);
					gets(auxEmployee.name);
					printf("Confirma cambio de nombre? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S') {
						strcpy(list[indice].name, auxEmployee.name);
					} else {
						printf("Edición cancelada\n");
					}
					break;
				case 2:
					printf("Modificar apellido: ");
					fflush(stdin);
					gets(auxEmployee.lastName);
					printf("Confirma cambio de apellido? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S') {
						strcpy(list[indice].lastName, auxEmployee.lastName);
					} else {
						printf("Edición cancelada\n");
					}
					break;
				case 3:
					printf("Modificar sueldo: ");
					scanf("%f", &auxEmployee.salary);
					printf("Confirma cambio de sueldo? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S') {
						list[indice].salary = auxEmployee.salary;
					} else {
						printf("Edición cancelada\n");
					}
					break;
				case 4:
					printf("Modificar sector: ");
					scanf("%d", &auxEmployee.sector);
					printf("Confirma cambio de sector? (S/N)\n");
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = toupper(confirma);
					if (confirma == 'S') {
						list[indice].sector = auxEmployee.sector;
					} else {
						printf("Edición cancelada\n");
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
				//system("pause");
			} while (seguir == 's');

			todoOk = 1;
			/* printEmployee(list[indice]);
			 printf("Confirma baja?: ");
			 fflush(stdin);
			 scanf("%c", &confirma);
			 if (confirma == 's')
			 {
			 list[indice].isEmpty = 1;
			 todoOk = 1;
			 }
			 else
			 {
			 printf("Baja cancelada por el usuario.\n");
			 }*/
		}
	}
	return todoOk;
}

int editMenu(employee list[], int len, int indice) {
	int opcion = 0;
	system("cls");
	printf("     *** Modificar Empleado ***\n");
	printf("| Nombre: %s   | Apellido: %s   | Sueldo: %.1f   | Sector: %d\n",
			list[indice].name, list[indice].lastName, list[indice].salary,
			list[indice].sector);
	printf("1- Editar Nombre\n");
	printf("2- Editar Apellido\n");
	printf("3- Editar Sueldo\n");
	printf("4- Editar Sector\n");
	printf("5- Salir\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);
	printf("\n");
	return opcion;
}

int salaryPromedio(employee list[], int len, float *pSalario, float *sumaSalarios)
{
    int todoOk = -1;
    float auxSalario = 0;
    int contadorSalarios = 0;

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                auxSalario += list[i].salary;
                contadorSalarios++;
            }
        }
        todoOk = 0;

        *pSalario = (float)auxSalario /contadorSalarios;
        *sumaSalarios = auxSalario;
    }
    return todoOk;
}


int cobranBien(employee list[], int len, float salarioPromedio, float totalSalario)
{
    int todoOk = -1;
    int contador = 0;

    salaryPromedio(list,len, &salarioPromedio, &totalSalario);

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                if(list[i].salary > salarioPromedio)
                {
                    printEmployee(list[i]);
                    contador++;
                }
            }
        }
        todoOk = 0;
    }

    printf("Hay %d persona/s que cobra/n mas del promedio de salarios en total\n", contador);

    return todoOk;
}
