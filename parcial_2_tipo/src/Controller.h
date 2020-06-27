/*
 * Controller.h
 *
 *  Created on: 26 jun. 2020
 *      Author: Franco
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee);
int controller_ListPeliculas(LinkedList* pArrayListEmployee);
int controller_informes(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_ord_cantEntradas(LinkedList* this);
int controller_clone(LinkedList* this);

int controller_addPelicula(LinkedList* pArrayList);
#endif /* CONTROLLER_H_ */
