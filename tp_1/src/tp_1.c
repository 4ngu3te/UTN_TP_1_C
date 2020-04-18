/*
 ============================================================================
 Name        : tp_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir*/
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {
	setbuf(stdout,NULL);
	int A;
	int B;
	int bufferA;
	int bufferB;

	int bufferOperacion;
	int bufferFactA;
	int bufferFactB;

	int menu;
	int opcion;

	A = utn_getNumero(&bufferA,"\nIngrese un numero del 0 al 9","Error",0,9,3);
		if(A==0)
			{
				printf("\n A= %d",bufferA);
			}
	B = utn_getNumero(&bufferB,"\nIngrese un numero del 0 al 9","Error",0,9,3);
		if(B==0)
			{
				printf("\n B= %d",bufferB);
			}

		do
		{
			menu = utn_getNumero(&opcion,"\n1-Sumar\n2-Restar\n3-Dividir\n4-Multiplicar\n5-Factorizar\n6-Salir","Error",1,6,2);
				switch(opcion)
				{
					case 1:
						if(sumar(&bufferOperacion,bufferA,bufferB) == 0)
						{
							printf("\nLa suma es: %d", bufferOperacion);
						}
						break;
					case 2:
						if(restar(&bufferOperacion,bufferA,bufferB) == 0)
						{
							printf("\nLa resta es: %d", bufferOperacion);
						}
						break;
					case 3:
						if(dividir(&bufferOperacion,bufferA,bufferB) == 0)
						{
							printf("\nResultado: %d", bufferOperacion);
						}
						else if(dividir(&bufferOperacion,bufferA,bufferB) == 1)
						{
							printf("\nNo es posible dividir por 0");
						}
						break;
					case 4:
						if(multiplicar(&bufferOperacion,bufferA,bufferB) == 0)
						{
							printf("\nResultado: %d", bufferOperacion);
						}
						break;
					case 5:
						if(factorizarA(&bufferFactA,bufferA) == 0)
						{
							printf("\nEl factorial de A: %d", bufferFactA);
						}
						if(factorizarB(&bufferFactB,bufferB) == 0)
						{
							printf("\nEl factorial de B: %d", bufferFactB);
						}
						break;

				}
		}while(opcion!=6);

		return EXIT_SUCCESS;
}

