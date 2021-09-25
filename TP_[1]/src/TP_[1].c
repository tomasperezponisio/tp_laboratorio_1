/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculadora.h"
#include "BibliotecaPersonal.h"

int main(void) {
	setbuf(stdout, NULL);

	char seguir = 's';
	char salir;
	int operandoA;
	int operandoB;
	int flagOpA = 0;
	int flagOpB = 0;
	int resultadoSuma;
	int flagSuma = 0;
	int resultadoResta;
	int flagResta = 0;
	float resultadoDivision;
	int flagDivision = 0;
	int resultadoMultiplicacion;
	int flagMultiplicacion = 0;
	int resultadoFactorialA;
	int resultadoFactorialB;
	int flagFactorialA = 0;
	int flagFactorialB = 0;
	int flagCalcular = 0;

	do {
		switch (menu(flagOpA, operandoA, flagOpB, operandoB)) {
		case 1:
			printf("1er operando. ");
			operandoA = pedirEntero();
			flagOpA = 1;
			break;
		case 2:
			printf("2do operando. ");
			operandoB = pedirEntero();
			flagOpB = 1;
			break;
		case 3:
			if (flagOpA == 0) {
				if (flagOpB == 0) {
					printf(
							"Hay que ingresar ambos operandos para poder calcular las operaciones\n");
					break;
				} else {
					printf("Falta ingresar el primer operando (operandoA)\n");
					break;
				}
			} else {
				if (flagOpB == 0) {
					printf("Falta ingresar el segundo operando (operandoB)\n");
					break;
				} else {
					flagCalcular = 1;
					printf("Calcular las operaciones:\n");
					// calcular la suma o avisar si no se pudo hacer
					if (sumar(operandoA, operandoB, &resultadoSuma)) {
						printf("   La suma se hizo\n");
						flagSuma = 1;
					} else {
						printf(
								"   La suma no se hizo, direccion de memoria = NULL");
						flagSuma = 0;
					}
					// calcular la resta o avisar si no se pudo hacer
					if (restar(operandoA, operandoB, &resultadoResta)) {
						printf("   La resta se hizo\n");
						flagResta = 1;
					} else {
						printf(
								"   La resta no se hizo, direccion de memoria = NULL\n");
						flagResta = 0;
					}
					// calcular la division o avisar si no se pudo hacer
					switch (dividir(operandoA, operandoB, &resultadoDivision)) {
					case 0:
						printf(
								"   La division no se hizo, direccion de memoria = NULL\n");
						flagDivision = 0;
						break;
					case 1:
						printf("   La division se hizo\n");
						flagDivision = 1;
						break;
					case 2:
						printf("   La division no se hizo, divisor == 0\n");
						flagDivision = 0;
						break;
					}
					// calcular la multiplicacion o avisar si no se pudo hacer
					if (multiplicar(operandoA, operandoB,
							&resultadoMultiplicacion)) {
						printf("   La multiplicacion se hizo\n");
						flagMultiplicacion = 1;
					} else {
						printf(
								"   La multiplicacion no se hizo, direccion de memoria = NULL\n");
						flagMultiplicacion = 0;
					}
					// calcular el factorial del primer operando o avisar si no se pudo hacer
					switch (factorial(operandoA, &resultadoFactorialA)) {
					case 0:
						printf(
								"   No se pudo calcular el factorial de A, direccion de memoria == NULL\n");
						flagFactorialA = 0;
						break;
					case 1:
						printf("   El factorial de A se hizo\n");
						flagFactorialA = 1;
						break;
					case 2:
						printf(
								"   No se pudo calcular el factorial de A, fuera de rango, debe ser >= 0 y <= 12\n");
						flagFactorialA = 0;
						break;
					}
					// calcular el factorial del segundo operando o avisar si no se pudo hacer
					switch (factorial(operandoB, &resultadoFactorialB)) {
					case 0:
						printf(
								"   No se pudo calcular el factorial de B, direccion de memoria == NULL\n");
						flagFactorialB = 0;
						break;
					case 1:
						printf("   El factorial de B se hizo\n");
						flagFactorialB = 1;
						break;
					case 2:
						printf(
								"   No se pudo calcular el factorial de B, fuera de rango, debe ser >= 0 y <= 12\n");
						flagFactorialB = 0;
						break;
					}
				}
			}
			break;
		case 4:
			if (flagCalcular == 0) {
				printf(
						"Hay que calcular las operaciones para mostrar los resultados\n");
			} else {
				printf("Muestra los resultados \n");
				if (flagSuma) {
					printf("   La suma da: %d \n", resultadoSuma);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
				if (flagResta) {
					printf("   La resta da: %d \n", resultadoResta);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
				if (flagDivision) {
					printf("   La division da: %.2f \n", resultadoDivision);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
				if (flagMultiplicacion) {
					printf("   La multiplicacion da: %d \n",
							resultadoMultiplicacion);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
				if (flagFactorialA) {
					printf("   El factorial del primer operando da: %d \n",
							resultadoFactorialA);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
				if (flagFactorialB) {
					printf("   El factorial del segundo operando da: %d \n",
							resultadoFactorialB);
				} else {
					printf("   Reingrese los operandos e intente nuevamente\n");
				}
			}
			break;
		case 5:
			printf("Esta seguro que quiere salir? (S/N)\n");
			fflush(stdin);
			scanf("%c", &salir);
			salir = tolower(salir);
			if (salir == 's') {
				seguir = 'n';
			} else {
				break;
			}
			break;
		default:
			printf("Opcion Invalida\n");
		}
		system("pause");

	} while (seguir == 's');

	return EXIT_SUCCESS;
}
