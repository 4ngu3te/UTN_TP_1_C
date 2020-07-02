/*
 * Empleado.c
 *
 *  Created on: 16 may. 2020
 *      Author: FrancoGollo
 */
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>

int menu(){

	int opcion;
	printf("B I E N V E N I D O\n\n1-Alta Empleado\n2-Salir\n\nIngrese Opcion:");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menu2(){
	system("cls");
	int opcion;
	printf("\nB I E N V E N I D O\n\n1-Alta Empleado\n2-Modificar Empleado\n3-Baja Empleado\n4-Informes\n5-Mostrar Empleados\n6-Salir\n\nIngrese Opcion:");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
int menuInformes(){
	system("cls");
	int opcion;
	printf("I N F O R M E S\n\n1-Empleados ordenados por Nombre y Sector\n2-Total sueldos\n\nIngrese Opcion:");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
void inicializarEmpleado(eEmpleado pArray[],int limite){
	for(int i = 0;i<limite;i++){
		pArray[i].isEmpty = 1;
	}
}
int buscarLibre(eEmpleado pArray[],int limite){
	int indice = -1;
	for(int i = 0;i<limite;i++){
		if(pArray[i].isEmpty){
			//printf("La poscicion %d del sistema se encuentra libre",i);
			indice = i;
			break;
		}
	}
	return indice;
}
int cargarEmpleado(int *idx,eEmpleado pArray[], int limite){
	system("cls");
	int ok = 0;
	int indice = buscarLibre(pArray,limite);
	eEmpleado auxEmpleado;

	system("cls");

	printf("\nEstamos en Alta empleado\n");

	if(indice == -1){//hay lugar?
		printf("Sistema completo\n");
		getche();
	}else{
			auxEmpleado.id= *idx;

			printf("\nIngrese nombre: ");
			fflush(stdin);
			gets(auxEmpleado.nombre);
			modificarMayus(auxEmpleado.nombre);

			printf("\nIngrese apellido: ");
			fflush(stdin);
			gets(auxEmpleado.apellido);
			modificarMayus(auxEmpleado.apellido);

			printf("\nIngrese Salario: ");
			fflush(stdin);
			scanf("%f",&auxEmpleado.salario);

			printf("\nIngrese Sector: ");
			fflush(stdin);
			scanf("%d",&auxEmpleado.sector);

			auxEmpleado.isEmpty = 0;

			pArray[indice] = auxEmpleado;
			ok = 1;
		}
	return ok;
}
int buscarPersona(int id, eEmpleado pArray[],int limite){
	int indice = -1;
		for(int i = 0;i<limite;i++){
			if(pArray[i].id == id && pArray[i].isEmpty == 0){
				//printf("La poscicion %d del sistema se encuentra libre",i);
				indice = i;
				break;
			}
		}
		return indice;

}
void modificarDatos(eEmpleado pArray[],int limite){
	int id;
	int indice;
	int modificaciones;
		system("cls");
		printf("\n*********MODIFICAR PERSONA*********\n");
		mostrarPersonas(pArray,limite);
	printf("\nIngrese el id de a modificar:");
	fflush(stdin);
	scanf("%d",&id);
	indice = buscarPersona(id,pArray,limite);
		if(indice == -1){
			printf("No hay usuarios con ID: %d",id);
		}else{
			mostrarPersona(pArray[indice]);
			printf("\nDato a modificar\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5.Volver\n\n");
                    fflush(stdin);
                    scanf("%d",&modificaciones);
         switch(modificaciones){
                case 1:
                    printf("\nNuevo Nombre");
                    fflush(stdin);
                    gets(pArray[indice].nombre);
                    modificarMayus(pArray[indice].nombre);
                    break;
                case 2:
                    printf("\nNuevo Apellido:");
                    fflush(stdin);
                    gets(pArray[indice].apellido);
                    modificarMayus(pArray[indice].apellido);
                    break;
                case 3:
                    printf("\nNuevo Salario:");
                    fflush(stdin);
                    scanf("%f",&pArray[indice].salario);
                    break;
                case 4:
                    printf("\nNueva Sector:");
                    fflush(stdin);
                    scanf("%d",&pArray[indice].sector);
                    break;
                case 5:
                	break;
		}
	}
}
void mostrarPersonas(eEmpleado pArray[],int limite){
	system("cls");
	int flag = 0;
	printf("**********LISTADO DE EMPLEADOS**********\n");
	printf(" ID         Nombre   Apellido    Salario    Sector\n");
		for(int i = 0;i<limite;i++){

			if(pArray[i].isEmpty == 0)
			{
				flag = 1;
				mostrarPersona(pArray[i]);
			}

			}
			if(flag == 0)
			{
				printf("*******No hay empleados para mostrar*******");
			}
			getche();
}
void mostrarPersona(eEmpleado pArray){
	printf("%d %15s %10s   %.2f      %d\n",pArray.id,pArray.nombre,pArray.apellido,pArray.salario,pArray.sector);
}
void bajaEmpleado(eEmpleado pArray[],int limite){
	system("cls");
	int id;
	int indice;
	char confirma = 's';
	printf("\n************BAJA EMPLEADO************");
	mostrarPersonas(pArray,limite);
	printf("Ingrese el id del Empleado: ");
	fflush(stdin);
	scanf("%d",&id);
	indice = buscarPersona(id,pArray,limite);
		if(indice == -1){
			printf("\nNo hay empleados con ese ID: %d.",id);
		}else{
			mostrarPersona(pArray[indice]);
			printf("\nConfirma la baja?");
			fflush(stdin);
			scanf("%c",&confirma);
				if(confirma == 's'){
					pArray[indice].isEmpty = 1;
					printf("\nSe ha realizado la baja con exito");
				}else{
					printf("\nOperacion cancelada");
				}
		}
}
void ordenarEmpleado(eEmpleado pArray[],int limite){
	eEmpleado aux;
	printf("\nOrdenando Empleados\n\n");
	for(int i = 0;i<limite;i++){
		for(int j = i+1;j<limite;j++){
			if(strcmp(pArray[i].nombre,pArray[j].nombre)>=0 && pArray[i].sector > pArray[j].sector){
				aux = pArray[i];
				pArray[i]=pArray[j];
				pArray[j]= aux;

			}
		}
	}
	mostrarPersonas(pArray,limite);
	getche();
}

void informeTotalSueldos(eEmpleado pArray[],int limite){
	float total = 0;
	float promedio = 0;
	int cantidadEmpleados;
		for(int i = 0;i<limite;i++){
			total = total + pArray[i].salario;
			cantidadEmpleados = i;
		}
		fflush(stdin);
		printf("\nEl total de los sueldos es $ %.2f",total);
		promedio = total / cantidadEmpleados;
		printf("\nEl promedio de los sueldos es $ %.2f",promedio);

		for(int j = 0;j<limite;j++){
			if(pArray[j].salario > promedio){
				printf("\nSuperan el promedio de sueldos:\n");
				mostrarPersona(pArray[j]);
			}
		}

		getche();

}

void modificarMayus(char *s){
	int indice = 1;
	s[0]=toupper(s[0]);
	while(s[indice]!= '\0'){
		s[indice] = tolower(s[indice]);
		if(s[indice] == ' '){
			s[indice+1]=toupper(s[indice+1]);
			indice++;
		}
		indice++;
	}

}
