/*
 * Funciones_Matematicas.c
 *
 *  Created on: 3 jul. 2020
 *      Author: Franco
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones_Matematicas.h"

void calcular(int valor_1,int valor_2)
{
    suma(valor_1,valor_2);
    resta(valor_1,valor_2);
    division(valor_1,valor_2);
    multiplicacion(valor_1,valor_2);
    factorizar(valor_1);
    factorizar(valor_2);
    printf("\nOperaciones realizadas...\n");
}
int suma(int valor_1,int valor_2)
{
  return (valor_1 + valor_2);
}
int resta(int valor_1,int valor_2)
{
  return (valor_1 - valor_2);
}
float division(int valor_1,int valor_2)
{
  float resultado;
  if(valor_1==0)
    {
      return -1;
    }
  else
    {
      resultado = (float)valor_1 / valor_2;
    }
  return resultado;
}
int multiplicacion(int valor_1,int valor_2)
{
  return (valor_1*valor_2);
}
long long factorizar(int valor)
{
    int i;
    long int f = 1;
    if(valor >= 0)
    {
      for(i=1;i<=valor;i++)
      {
	      f =f*i;
      }
    }
    return f;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

void mostrar_resultados(int valor_1,int valor_2)
{
  printf("\nEl resultado de A+B es:...%d",suma(valor_1,valor_2));
  printf("\nEl resultado de A-B es:...%d",resta(valor_1,valor_2));
  printf("\nEl resultado de A*B es:...%d",multiplicacion(valor_1,valor_2));
  printf("\nEl factorial de A es:... %I64d\nEl factorial de B es:...%I64d",factorizar(valor_1),factorizar(valor_2));
  if(division(valor_1,valor_2)==-1)
    {
      printf("\nNo es divisible por 0...");
    }
  else
    {
      printf("\nEl resultado de A/B es: %.2f...\n\n",division(valor_1,valor_2));
    }
}

