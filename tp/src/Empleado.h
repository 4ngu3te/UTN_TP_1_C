/*
 * Empleado.h
 *
 *  Created on: 16 may. 2020
 *      Author: FrancoGollo
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct{
	int id;
	char nombre[20];
	char apellido[20];
	float salario;
	int sector;
	int isEmpty;
}eEmpleado;

#endif /* EMPLEADO_H_ */

int menu();
int menu2();
int menuInformes();
void inicializarEmpleado(eEmpleado pArray[],int limite);
int buscarLibre(eEmpleado pArray[],int limite);
int cargarEmpleado(int *idx,eEmpleado pArray[], int limite);
void modificarDatos(eEmpleado pArray[],int limite);
void mostrarPersonas(eEmpleado pArray[],int limite);
void mostrarPersona(eEmpleado pArray);
void bajaEmpleado(eEmpleado pArray[],int limite);
void ordenarEmpleado(eEmpleado pArray[],int limite);
void informeTotalSueldos(eEmpleado pArray[],int limite);
void modificarMayus(char *s);
