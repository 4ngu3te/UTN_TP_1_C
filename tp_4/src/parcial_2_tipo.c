/*
 ============================================================================
 Name        : parcial_2_tipo.c
 Author      : Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"
#include "utn.h"
int main(void) {
  setbuf(stdout,NULL);
   int opcion;
   LinkedList* listaPeliculas = ll_newLinkedList();
   do{
  	opcion=menu();
          switch(opcion)
          {
              case 1:
                  controller_loadFromText("data.csv",listaPeliculas);
                  break;
              case 2:
        	if(ll_isEmpty(listaPeliculas)!=1){
        	controller_ListPeliculas(listaPeliculas);}
        	else{text("La lista se encuentra vacia");}
              	  break;
              case 3:
        	if(ll_isEmpty(listaPeliculas)!=1){
        	controller_saveAsText("pelisconMonto.csv",listaPeliculas);}
        	else{text("La lista se encuentra vacia");}
              	break;
	      case 4:
		if(ll_isEmpty(listaPeliculas)!=1){
		controller_informes(listaPeliculas);}
        	else{text("La lista se encuentra vacia");}
              	break;
              case 5:
              	if(ll_isEmpty(listaPeliculas)!=1){
              	  controller_ord_cantEntradas(listaPeliculas);}
        	else{text("La lista se encuentra vacia");}
              	break;
              	case 6:
              	if(ll_isEmpty(listaPeliculas)!=1){
              	controller_clone(listaPeliculas);}
		else{text("La lista se encuentra vacia");}
              	break;
              case 7:
        	if(ll_isEmpty(listaPeliculas)!=1){
		controller_addPelicula(listaPeliculas);}
		else{text("La lista se encuentra vacia");}
              	break;
             /* case 8:

              	break;
              case 9:

  		break;*/
          }
          system("pause");
          system("cls");
      }while(opcion != 8);

	return EXIT_SUCCESS;
}
