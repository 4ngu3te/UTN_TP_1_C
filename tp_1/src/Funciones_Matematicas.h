/*
 * Funciones_Matematicas.h
 *
 *  Created on: 3 jul. 2020
 *      Author: Franco
 */

#ifndef FUNCIONES_MATEMATICAS_H_
#define FUNCIONES_MATEMATICAS_H_
void calcular(int valor_1,int valor_2);
int suma(int valor_1,int valor_2);
int resta(int valor_1,int valor_2);
float division(int valor_1,int valor_2);
int multiplicacion(int valor_1,int valor_2);
long long factorizar(int valor_1);
void mostrar_resultados(int valor_1,int valor_2);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
#endif /* FUNCIONES_MATEMATICAS_H_ */
