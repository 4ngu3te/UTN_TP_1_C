/*
 * Empleado.c
 *
 *  Created on: 4 jul. 2020
 *      Author: Franco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define DISP 1
#define OCUPADO 0

int id_auto(int f)
{
  static int in = 1000;
  if(f==1)
    {
      in++;
    }
  return in;
}
void inicializar(Empleado this[],int tam)
{
  int i;
  for(i=0;i<tam;i++)
    {
      this[i].isEmpty= DISP;
    }
}
int buscarDisponible(Empleado this[],int tam)
{
  int i;
  int indice;
  for(i=0;i<tam;i++)
    {
      if(this[i].isEmpty == DISP)
	{
	  indice = i;
	}
    }
  return indice;
}
int buscar_por_id(Empleado this[],int tam, int id)
{
  int i;
  int indice;
  for(i=0;i<tam;i++)
    {
      if(this[i].id == id && this[i].isEmpty == OCUPADO)
	{
	  indice = i;
	}
    }
  return indice;
}
int altaEmpleado(Empleado this[],int tam)
{
  int ok=-1;
  int indice = buscarDisponible(this,tam);
  Empleado Aux;
  printf("\nAlta empleados...\n");

    if(indice==-1)
      {
	printf("\nNo hay lugares disponibles.");
      }
    else
      {
	fflush(stdin);
	getString(Aux.nombre,"\nIngrese el nombre del empleado: ","Error",0,21,3);
	fflush(stdin);
	getString(Aux.apellido,"\nIngrese el apellido del empleado: ","Error",0,21,3);
	fflush(stdin);
	utn_getNumero(&Aux.sector,"\nIngrese el Sector: ","Error",1,10,3);
	printf("\nIngrese Salario: ");
	fflush(stdin);
	scanf("%f",&Aux.salario);
	Aux.id = id_auto(1);
	Aux.isEmpty = OCUPADO;
	this[indice]= Aux;
	mostrarEmpleado(this[indice]);

	ok=0;
      }
    if(ok==0)
      {
	text("\nEmpleado agregado exitosamente\n");
	system("pause");
      }
    return ok;
}
void mostrarEmpleado(Empleado this)
{
  fflush(stdin);
  printf("\n%d  %14s  %14s %.2f%5d\n",this.id,this.nombre,this.apellido,this.salario,this.sector);
}
void mostrarEmpleados(Empleado this[],int tam)
{
  int i;
  text("\nID          NOMBRE         APELLIDO    SALARIO  SECTOR\n");
  for(i=0;i<tam;i++)
    {
      if(this[i].isEmpty == OCUPADO)
	{
	  mostrarEmpleado(this[i]);
	}

    }
}
int bajaEmpleado(Empleado this[],int tam)
{
  int ok = -1;
  int id;
  int indice;
  char respuesta;
  text("\nBaja de empleados:....");
  mostrarEmpleados(this,tam);
  utn_getNumero(&id,"\nIngrese el id del empleado a dar de baja: ","\nID INVALIDO",0,9999,3);
  fflush(stdin);
  indice = buscar_por_id(this,tam,id);
    if(indice==-1)
      {
	printf("\n\nNo hay empleado con el id: %d",id);
      }
    else
      {
	mostrarEmpleado(this[indice]);
	utn_getCaracter(&respuesta,"Desea eliminar al empleado? s/n : ","Error",'n','s',3);
	fflush(stdin);
	if(respuesta == 's')
	  {
	    this[indice].isEmpty = DISP;
	    text("\nEmpleado dado de baja exitosamente.\n");
	    ok=0;
	  }

      }

  return ok;
}
int modificarEmpleado(Empleado this[],int tam)
{
  int ok=-1;
  int id;
  int op;
  int indice;
  fflush(stdin);
  system("cls");
  mostrarEmpleados(this,tam);
  utn_getNumero(&id,"\nIngrese el id del empleado a modificar: ","\nID INVALIDO",1000,9999,3);
  indice = buscar_por_id(this,tam,id);
  if(indice==-1)
    {
      printf("\n\nNo hay empleado con el id: %d",id);
    }
  else
    {
      mostrarEmpleado(this[indice]);

      do
	{
	  fflush(stdin);
	  utn_getNumero(&op,"\n1.Cambiar Nombre."
	  			"\n2.Cambiar Apellido."
	  			"\n3.Cambiar Salario."
	  			"\n4.Cambiar Sector."
	  			"\n5.Salir"
	  			"\n-->:","\nID INVALIDO",1,5,3);

	  switch(op)
	    {
	    case 1:
	      printf("\nNuevo Nombre:");
	      fflush(stdin);
	      gets(this[indice].nombre);
	      modificarMayus(this[indice].nombre);
	      ok=0;
	      break;
	    case 2:
	      printf("\nNuevo Apellido:");
	      fflush(stdin);
	      gets(this[indice].apellido);
	      modificarMayus(this[indice].apellido);
	      ok=0;
	      break;
	    case 3:
	      printf("\nNuevo Salario: ");
	      fflush(stdin);
	      scanf("%f",&this[indice].salario);
	      ok=0;
	      break;
	    case 4:
	      utn_getNumero(&this[indice].sector,"\nNuevo Sector: ","Error",1,10,3);
	      ok=0;
	      break;
	    }
	  if(ok==0)
	    {
	      system("cls");
	      text("Modificado correctamente\n\n");
	      mostrarEmpleado(this[indice]);
	    }
	}while(op!=5);

    }
  return ok;
}

int ordenarEmpleados(Empleado this[],int tam)
{
  int i;
  int j;
  int ok =-1;
  Empleado Aux;

  for(i=0;i<tam-1;i++)
    {
      for(j=i+1;j<tam;j++)
	{
	  if(strcmp(this[i].apellido,this[j].apellido)>=0 && this[i].sector > this[j].sector)
	    {
	      Aux = this[i];
	      this[i] = this[j];
	      this[j] = Aux;
	      ok=0;
	    }
	}
    }
  return ok;
}
int total_y_promedios(Empleado this[],int tam)
{
  int i,k;
  int ok=-1;
  float total=0;
  float promedio;
  int cant_empleados;
    for(i=0;i<tam;i++)
      {
	if(this[i].isEmpty == OCUPADO)
	  {
	    total+=this[i].salario;
	  }
      }
    promedio = total / i;
   for(k=0;k<tam;k++)
     {
       if(this[k].isEmpty == OCUPADO && this[k].salario > promedio)
	 {
	   cant_empleados = k;
	 }
     }
    printf("\nLa totalidad de los sueldos pagados es %.2f...",total);
    printf("\nEl promedio de los salarios es: %.2f...",promedio);
    printf("\nLa cantidad de empleados que superan el salario promedio: %d\n\n",cant_empleados);
  return ok;
}
int informes(Empleado  this[],int tam)
{
  int ok = -1;
  int op;
  do
    {
      utn_getNumero(&op,"\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector."
			"\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio."
			"\n3. Salir."
			"\n-->: ","\nOpcion invalida...\n",1,3,3);
      switch(op)
      {
	case 1:
	  if(ordenarEmpleados(this,tam)==0)
	    {
	      text("\nEmpleados ordenados correctamente...\n\n");
	      mostrarEmpleados(this,tam);
	    }
	  break;
	case 2:
	  total_y_promedios(this,tam);
	  break;
      }
    }while(op!=3);
  return ok;
}


