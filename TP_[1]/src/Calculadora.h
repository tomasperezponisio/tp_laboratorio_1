/*
 * Calculadora.h
 *
 *  Created on: 4 Sept 2021
 *      Author: Tomas
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <stdio.h>

/// \brief Permite ingresar dos float y retorna la suma
///
/// \param operandoA float
/// \param operandoB float
/// \return float
///
///
float sumar(float operandoA, float operandoB);

/// \brief Resta dos numeros
///
/// \param operandoA float
/// \param operandoB float
/// \return float
float restar(float operandoA, float operandoB);

/// \brief Multiplica dos numeros
///
/// \param operandoA float
/// \param operandoB float
/// \return float
///
///
float dividir(float operandoA, float operandoB);

/// \brief Divide dos numeros
///
/// \param operandoA float
/// \param operandoB float
/// \return float
///
///
float multiplicar(float operandoA, float operandoB);

/// \brief Calcula el factorial de un numero
///
/// \param operandoA int
/// \return int
///
///
int factorial(int operandoA);

#endif /* CALCULADORA_H_ */
