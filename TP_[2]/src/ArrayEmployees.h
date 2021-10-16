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

/** \brief pide los datos para ser cargados en el empleado correspondiente llamando a la funcion addEmployee
 *         los datos se piden llamando a las funciones que piden y validan cada tipo de datos
 * \param list[] employee
 * \param len int
 * \param pId int*
 * \return int todoOk (-1) si hubo un error, 0 si no hubo problemas
 *
 */
int newEmployee(employee list[], int len, int *pId);

/** \brief toma los datos que pide newEMployee y los carga en la lista de empleados en el primer lugar vacio que encuentre
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

/** \brief recibe un empleado y lo imprime
 *
 * \param e employee
 * \return void
 *
 */
void printEmployee(employee e);

/** \brief imprime los empleados que estan activos en al lista
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(employee list[], int len);

/** \brief busca en el array en los espacios ocupados el id que recibe y devuelve el indice si se encuentra el id
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(employee list[], int len, int id);

/** \brief pide el id del emeplado que se desea remover y pone el campo isEmpty como true
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(employee list[], int len);

/** \brief es el menu para elegir que criterio enviar para ordenar
 *
 * \return int 1 para ordenar ascendente, 0 para ordenar descendente
 *
 */
int menuSort();

/** \brief ordena los elementos del array de empleados segun el orden que se le ingrese, 1 para ordenar
*          en orden ascendente, 0 en orden descendente. Por apellido y por sector.
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(employee list[], int len, int order);

/** \brief recibe la lista de empleados y a traves de un menu permite modificar
 *         campos del empleado seleccionado
 * \param list[] employee
 * \param len int
 * \return int devuelve 1 si la edicion se pudo realizar, 0 en caso contrario
 *
 */
int editEmployee(employee list[], int len);

/** \brief es el menu de seleccion para editar los emeplados , recibe el indice del empleado a editar
 *         muestra las opciones y mantiene actualizado el empleado en edicion
 * \param list[] employee
 * \param len int
 * \param indice int
 * \return int devuelve la opcion seleccionada
 *
 */
int editMenu(employee list[], int len, int indice);

#endif /* ARRAYEMPLOYEES_H_ */
