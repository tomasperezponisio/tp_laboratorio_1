/*
 * BibliotecaPersonal.c
 *
 *  Created on: 25 Sept 2021
 *      Author: Tomas
 */

#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaPersonal.h"

int encontrarParidad(int numero)
{
    int todoOk = 0;
    if (numero % 2 == 0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int pedirEntero()
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    return entero;
}

int pedirEnteroRango(int min, int max)
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    while (entero < min || entero > max)
    {
        printf("El numero debe estar dentro del rango ingresado, ingreselo nuevamente: ");
        scanf("%d", &entero);
    }
    return entero;
}

int validarDistintoDeCero(int numero)
{
    int todoOk = 0;
    if (numero != 0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int validarDecimales(float numero)
{
    int todoOk = 0;
    if (numero == (int)numero)
    {
        todoOk = 1;
    }
    return todoOk;
}
