/*
 ============================================================================
 Name        : tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include "Empleado.h"
#define t 1000


int main(void) {
	setbuf(stdout,NULL);

	char respuesta = 's';
	char seguir = 's';
	int idEmpleado = 1023;
	int primeraVez = 1;
	eEmpleado datos[t];
	inicializarEmpleado(datos,t);
	hardcodeo(datos,t);
		if(primeraVez==1){
		switch(menu()){
			case 1:
				if(cargarEmpleado(&idEmpleado,datos,t)){idEmpleado++;primeraVez++;}
			break;
			case 2:
				printf("Desea salir? s/n");
				scanf("%c",&respuesta);
					if(respuesta == 's'){
						seguir = 'n';
					}
				break;
			}
		}
		do{
		switch(menu2()){
		case 1:
			if(cargarEmpleado(&idEmpleado,datos,t)){idEmpleado++;}
			break;
		case 2:
			modificarDatos(datos,t);
			break;
		case 3:
			bajaEmpleado(datos,t);
			break;
		case 4:
			switch(menuInformes()){
			case 1:
				ordenarEmpleado(datos,t);
				break;
			case 2:
				informeTotalSueldos(datos,t);
				break;
			}
			break;
		case 5:
			mostrarPersonas(datos,t);
			break;
		case 6:
			printf("Desea salir? s/n");
			fflush(stdin);
			scanf("%c",&respuesta);
				if(respuesta == 's'){
					seguir = 'n';
				}
			}

		}while(seguir == 's');


	return EXIT_SUCCESS;
}


