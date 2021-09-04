/*
 * Calculadora.c
 *
 *  Created on: 4 Sept 2021
 *      Author: Tomas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

float sumar(float operandoA, float operandoB)
{
    float resultado;
    resultado = operandoA + operandoB;
    return resultado;
}

float restar(float operandoA, float operandoB)
{
    float resultado;
    resultado = operandoA - operandoB;
    return resultado;
}

float dividir(float operandoA, float operandoB)
{
    float resultado;
    resultado = (float) operandoA / (float) operandoB;
    return resultado;
}

float multiplicar(float operandoA, float operandoB)
{
    float resultado;
    resultado = operandoA * operandoB;
    return resultado;
}

int factorial(int operandoA)
{
    int factorial = 1;
    for (int i = 1; i <= operandoA; i++)
    {
        factorial *= i;
    }
    return factorial;
}
