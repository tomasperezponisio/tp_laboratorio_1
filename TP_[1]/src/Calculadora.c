/*
 * Calculadora.c
 *
 *  Created on: 4 Sept 2021
 *      Author: Tomas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int menu()
{
    int opcion;

    system("cls");
    printf("///--- CALCULADORA ---///\n");
    printf("1. Ingresar 1er operando (A = x)\n");
    printf("2. Ingresar 2do operando (B = y)\n");
    printf("3. Calcular todas las operaciones\n");
    printf("  * Suma (A + B)\n");
    printf("  * Resta (A - B)\n");
    printf("  * Multiplicacion (A * B)\n");
    printf("  * Division (A / B)\n");
    printf("  * Factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    printf("\nIndique opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int sumar(int operandoA, int operandoB, int* resultado)
{
    int todoOk = 0;
    if (resultado != NULL)
    {
        *resultado = operandoA + operandoB;
        todoOk = 1;
    }
    return todoOk;
}

int restar(int operandoA, int operandoB, int* resultado)
{
    int todoOk = 0;
    if (resultado != NULL)
    {
        *resultado = operandoA - operandoB;
        todoOk = 1;
    }
    return todoOk;
}

int dividir(int operandoA, int operandoB, float* resultado)
{
    int todoOk = 0;
    if (resultado != NULL)
    {
        if (operandoB != 0)
        {
            *resultado = (float) operandoA / operandoB;
            todoOk = 1;
        }
        else
        {
            todoOk = 2;
        }
    }
    return todoOk;
}

int multiplicar(int operandoA, int operandoB, int* resultado)
{
    int todoOk = 0;
    if (resultado != NULL)
    {
        *resultado = operandoA * operandoB;
        todoOk = 1;
    }
    return todoOk;
}

int factorial(int operandoA, int* resultado)
{
    int todoOk = 0; // devuelvo error 0 si la direccion es NULL
    int fact = 0;
    if (resultado != NULL) // si la direccion recivida no es NULL entro
    {
        if (operandoA < 0 || operandoA > 12) // si el operando está fuera de rango devuelvo error 2
        {
            todoOk = 2;
        }
        else
        {
            fact = 1;
            for (int i = 2; i <= operandoA; i++)
            {
                fact = fact * i;
            }
            todoOk = 1;
        }
    }
    *resultado = fact;
    return todoOk;
}
