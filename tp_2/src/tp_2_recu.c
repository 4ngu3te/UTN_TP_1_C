/*
 ============================================================================
 Name        : tp_2_recu.c
 Author      : Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define t 999

int main(void) {
  setbuf(stdout,NULL);
  int op;
  int primeraVez;
  Empleado datos[t];
  inicializar(datos,t);
  do
    {
      utn_getNumero(&op,"\nBienvenido...\n"
			"\n1. ALTAS."
			"\n2. MODIFICAR."
			"\n3. BAJA."
			"\n4. INFORMAR."
			"\n5. SALIR"
			"\n-->:","Opcion invalida",1,5,3);
      switch(op)
      {
	case 1:
	  if(altaEmpleado(datos,t)==0)
	    {
	      primeraVez++;
	    }
	  else
	    {
	      text("\nError");
	    }
	  break;
	case 2:
	  if(primeraVez>=1)
	    {
	      modificarEmpleado(datos,t);
	    }
	  else
	    {
	      text("\nNo hay empleados...");
	    }
	  break;

	case 3:
	  if(primeraVez>=1)
	    {
	      bajaEmpleado(datos,t);
	    }
	  else
	    {
	      text("\nNo hay empleados...");
	    }
	  break;
	case 4:
	  if(primeraVez>=1)
	    {
	      informes(datos,t);
	    }
	  else
	    {
	      text("\nNo hay empleados para listar...");
	    }
	  break;
      }
      system("cls");

    }while(op!=5);



  return EXIT_SUCCESS;
}
