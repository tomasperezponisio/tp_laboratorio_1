/*
 * BibliotecaPersonal.h
 *
 *  Created on: 25 Sept 2021
 *      Author: Tomas
 */

#ifndef BIBLIOTECAPERSONAL_H_
#define BIBLIOTECAPERSONAL_H_

/** \brief determina si un numero es par / devuelve 1 en caso afirmativo / 0 en caso negativo
 *
 * \param numero int
 * \return int
 *
 */
int encontrarParidad(int numero);

/** \brief Pide el ingreso de un numero entero y lo retorna
 *
 * \return int
 *
 */
int pedirEntero();

/** \brief pide el ingreso de un numero entero dentro de un rango determinado que se pasa como min y max
 *
 * \param min int
 * \param max int
 * \return int
 *
 */
int pedirEnteroRango(int min, int max);

/// \brief valida si el numero que se le pasa es o no cero / devuelve 1 si no es 0 / devuelve 0 si es 0
///
/// \param numero int
/// \return int
///
///
int validarDistintoDeCero(int numero);

/// \brief valida si el float que se le pasa tiene valores después de la coma / devuelve 1 en caso que no haya decimales despues de la coma / devuelve 0 en caso contrario
///
/// \param numero float
/// \return int
///
///
int validarDecimales(float numero);

#endif /* BIBLIOTECAPERSONAL_H_ */
