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
#include "Calculadora.h"

int main(void) {
	setbuf(stdout, NULL);

	float operandoA;
	float operandoB;

	printf("INICIO CALCULADORA\n");
	printf("Ingrese el 1er operando: ");
	scanf("%f", &operandoA);
	printf("Ingrese el 2do operando: ");
	scanf("%f", &operandoB);

	printf("El resultado de %.1f + %.1f es: %.1f\n", operandoA, operandoB, sumar(operandoA, operandoB));
	printf("El resultado de %.1f - %.1f es: %.1f\n", operandoA, operandoB, restar(operandoA, operandoB));
	if (operandoB == 0)
	{
		printf("*ERROR* No se puede dividir por cero\n");
	}
	else
	{
		printf("El resultado de %.1f / %.1f es: %.1f\n", operandoA, operandoB, dividir(operandoA, operandoB));
	}
	printf("El resultado de %.1f * %.1f es: %.1f\n", operandoA, operandoB, multiplicar(operandoA, operandoB));
	if (operandoA != (int)operandoA)
	{
		printf("No existe el factorial de un numero con decimales");
	}
	else
	{
		printf("El factorial de %d es: %d", (int)operandoA, factorial((int)operandoA));
	}

	return EXIT_SUCCESS;
}
