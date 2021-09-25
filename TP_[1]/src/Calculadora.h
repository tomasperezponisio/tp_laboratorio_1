/*
 * Calculadora.h
 *
 *  Created on: 4 Sept 2021
 *      Author: Tomas
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>

/// \brief muestra un menu de opciones y retorna como entero la opcion seleccionada
///
/// \return int
///
///
int menu();

/// \brief Recibe dos valores int y una direccion de memoria, si se puede hacer la suma escribe
///        en la direccion y devuelve 1, si la suma no se pudo hacer devuelve 0
///
/// \param operandoA int
/// \param operandoB int
/// \param resultadoSuma int*
/// \return int
///
///
int sumar(int operandoA, int operandoB, int* resultado);

/// \brief Recibe dos valores int y una direccion de memoria, si se puede hacer la resta escribe en
///        la direccion y devuelve 1, si la resta no se pudo hacer devuelve 0
///
/// \param operandoA int
/// \param operandoB int
/// \param resultado int*
/// \return int
///
///
int restar(int operandoA, int operandoB, int* resultado);

/// \brief Recibe dos valores int y una direccion de memoria si se puede hacer la division escribe
///        en la direccion y devuelve 1, si la division no se pudo hacer por NULL en la direccion
///        de memoria recibida devuelve 0, si no se pudo hacer porque el divisor es 0 devuelve 2
///
/// \param operandoA int
/// \param operandoB int
/// \param resultado float*
/// \return int
///
///
int dividir(int operandoA, int operandoB, float* resultado);


/// \brief Recibe dos valores int y una direccion de memoria si se puede hacer la multiplicacion escribe
///        en la direccion y devuelve 1, si la multiplicacion no se pudo hacer por NULL en la direccion
///        de memoria recibida devuelve 0
///
/// \param operandoA int
/// \param operandoB int
/// \param resultado int*
/// \return int
///
///
int multiplicar(int operandoA, int operandoB, int* resultado);


/// \brief Recibe un valor y una direccion de memoria, si se puede hacer el factoral devuelve 1, si no se pudo
///        realizar devuelve 0 por NULL en la direccion de memoria o devuelve 2 por recibir un operando fuera de rango
///        (rango correcto operando >=0  y <= 12)
///
/// \param operandoA int
/// \param resultado int*
/// \return int
///
///
int factorial(int operandoA, int* resultado);

#endif /* CALCULADORA_H_ */
