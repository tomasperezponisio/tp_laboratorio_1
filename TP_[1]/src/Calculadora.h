/*
 * Calculadora.h
 *
 *  Created on: 4 Sept 2021
 *      Author: Tomas
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>

/// \brief muestra un menu de opciones y retorna como entero la opcion seleccionada. Recibe 4 enteros,
///        dos son flags para iniciar el menu sin que se hayan recibido los operandos,
///        los otros dos son los operandos a ser mostrados una vez que se vayan ingresando
///
/// \param flagOpA int    / es el flag para inciar el menu mostrando o no el operandoA
/// \param operandoA int  / es el operandoA
/// \param flagOpB int    / es el flag para inciar el menu mostrando o no el operandoB
/// \param operandoB      / int es el operandoB
/// \return int           / es la opcion elegida por el usuario
///
///
int menu(int flagOpA, int operandoA, int flagOpB, int operandoB);

/// \brief Recibe dos valores int y una direccion de memoria, si se puede hacer la suma escribe
///        en la direccion y devuelve 1, si la suma no se pudo hacer devuelve 0
///
/// \param operandoA int       / es uno de los operadores a sumar
/// \param operandoB int       / es el otro operador a sumar
/// \param resultado int*      / es la direccion de memoria donde se escribe el resultado de la suma en caso de hacerse
/// \return int                / es el retorno de comprobacion (0-1)
///
///
int sumar(int operandoA, int operandoB, int *resultado);

/// \brief Recibe dos valores enteros (el segundo se le resta al primero) y una direccion de memoria, si se puede hacer
///        la resta escribe en la direccion y devuelve 1, si la resta no se pudo hacer devuelve 0
///
/// \param operandoA int       / es el minuendo
/// \param operandoB int       / es el sustraendo
/// \param resultado int*      / es la direccion de memoria donde se escribe el resultado de la resta en caso de hacerse
/// \return int                / es el retorno de comprobacion (0-1)
///
///
int restar(int operandoA, int operandoB, int *resultado);

/// \brief Recibe dos valores int (el primero es el dividendo, el segundo es el divisor) y una direccion de memoria si se
///        puede hacer la division escribe en la direccion y devuelve 1, si la division no se pudo hacer por NULL en la direccion
///        de memoria recibida devuelve 0, si no se pudo hacer porque el divisor es 0 devuelve 2
///
/// \param operandoA int       / es el dividendo
/// \param operandoB int       / es el divisor
/// \param resultado float*    / es la direccion de memoria donde se escribe el resultado de la division en caso de hacerse
/// \return int                / es el retorno de comprobacion (0-1-2)
///
///
int dividir(int operandoA, int operandoB, float *resultado);

/// \brief Recibe dos valores int y una direccion de memoria si se puede hacer la multiplicacion escribe
///        en la direccion y devuelve 1, si la multiplicacion no se pudo hacer por NULL en la direccion
///        de memoria recibida devuelve 0
///
/// \param operandoA int       / es uno de los factores
/// \param operandoB int       / es el otro factor
/// \param resultado int*      / es la direccion de memoria donde se escribe el resultado de la multiplicacion en caso de hacerse
/// \return int                / es el retorno de comprobacion (0-1)
///
///
int multiplicar(int operandoA, int operandoB, int *resultado);

/// \brief Recibe un valor y una direccion de memoria, si se puede hacer el factoral devuelve 1, si no se pudo
///        realizar devuelve 0 por NULL en la direccion de memoria o devuelve 2 por recibir un operando fuera de rango
///        (rango correcto operando >=0  y <= 12)
///
/// \param operandoA int       / es el entero a calcular el factorial
/// \param resultado int*      / es la direccion de memoria donde se escribe el resultado del factorial en caso de hacerse
/// \return int                / es el retorno de comprobacion (0-1-2)
///
///
int factorial(int operandoA, int *resultado);

#endif /* CALCULADORA_H_ */
