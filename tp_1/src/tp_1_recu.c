/*
 ============================================================================
 Name        : tp_1_recu.c
 Author      : Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones_Matematicas.h"


int main(void)
{
    setbuf(stdout,NULL);
    int a = 0;
    int b = 0;
    int op;

    do{
	printf("Bienvenido a la calculadora..."
			      "\n1. Ingresar 1er operando(A=%d)"
			      "\n2. Ingresar 2do operando(B=%d)"
			      "\n3. Calcular todas las operaciones"
			      "\n4. Informar resultados"
			      "\n5. Salir"
			      "\n--> :",a,b);
	scanf("%d",&op);

	switch(op)
	{
	  case 1:
	    utn_getNumero(&a,"Numero A: ","Invalido",-999999,999999,3);
	    break;
	  case 2:
	    utn_getNumero(&b,"Numero B: ","Invalido",-999999,999999,3);
	    break;
	  case 3:
	    printf("\na) Calcular la suma (A+B)"
		  "\nb) Calcular la resta (A-B)"
		  "\nc) Calcular la division (A/B)"
		  "\nd) Calcular la multiplicacion (A*B)"
		  "\ne) Calcular el factorial (A!)\n");
	    calcular(a,b);
	    break;
	  case 4:
	    mostrar_resultados(a,b);
	    break;
	}
	system("cls");
	system("pause");
    }while(op!=5);
    return EXIT_SUCCESS;
}
