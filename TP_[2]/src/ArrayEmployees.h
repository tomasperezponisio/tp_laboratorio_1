/*
 * ArrayEmployees.h
 *
 *  Created on: 16 Oct 2021
 *      Author: Tomas Perez Ponisio
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} employee;

/** \brief Devuelve un entero del 1 al 5que es la opcion elegida en el menus
 *
 *
 * \return int Return
 **/
int menu();

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list[] employee array de empleados
 * \param len int tamanio del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 **/
int initEmployees(employee list[], int len);

/** \brief recorre la lista viendo los valores de isEmpty y devuelve el indice el primer lugar disponible,
 *
 *
 * \param list[] employee array de empleados
 * \param len int tamanio del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 **/
int findFree(employee list[], int len); // -1 si esta todo lleno o el indice de la primer estructura vacia

int newEmployee(employee list[], int len, int *pId);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 **/
int addEmployee(employee list[], int len, int id, char name[], char lastName[],
		float salary, int sector);

void printEmployee(employee e);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee list[], int len);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int findEmployeeById(employee list[], int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 find a employee] - (0) if Ok
 *
 */
int removeEmployee(employee list[], int len);

int menuSort();

/** \brief Sort the elements in the array of employees, the argument order
 indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(employee list[], int len, int order);

int editEmployee(employee list[], int len);

int editMenu(employee list[], int len, int indice);

#endif /* ARRAYEMPLOYEES_H_ */
