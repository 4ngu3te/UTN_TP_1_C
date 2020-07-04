/*
 * Empleado.h
 *
 *  Created on: 4 jul. 2020
 *      Author: FrancoGollo
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct{
  int id;
  char nombre[21];
  char apellido[21];
  float salario;
  int sector;
  int isEmpty;
}Empleado;

#endif /* EMPLEADO_H_ */


int id_auto(int f);
void inicializar(Empleado this[],int tam);
int buscarDisponible(Empleado this[],int tam);
int buscar_por_id(Empleado this[],int tam, int id);
int altaEmpleado(Empleado this[],int tam);
void mostrarEmpleado(Empleado this);
void mostrarEmpleados(Empleado this[],int tam);
int bajaEmpleado(Empleado this[],int tam);
int modificarEmpleado(Empleado this[],int tam);
int ordenarEmpleados(Empleado this[],int tam);
int total_y_promedios(Empleado this[],int tam);
int informes(Empleado  this[],int tam);
