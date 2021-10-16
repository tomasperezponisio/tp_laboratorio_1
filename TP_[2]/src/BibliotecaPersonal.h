/*
 * BibliotecaPersonal.h
 *
 *  Created on: 16 Oct 2021
 *      Author: Tomas Perez Ponisio
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

int miStrlen(char vect[]);

int validarCadena(char vect[]);

int pedirCadena(char cadena[], char mensaje[], int limite);

int mayusculaPrimerCaracter(char cadena[]);

int getInt(int *pResultado);

int myGets(char *cadena, int longitud);

int validarEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

int esNumerica(char *cadena);

int getFloat(float *pResultado);

int validarFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

int esNumericoFlotante(char str[]);

#endif /* BIBLIOTECAPERSONAL_H_ */
