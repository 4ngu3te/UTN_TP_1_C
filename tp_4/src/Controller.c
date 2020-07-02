/*
 * Controller.c
 *
 *  Created on: 26 jun. 2020
 *      Author: Franco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "parser.h"
#include "utn.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
  int ok=-1;
  FILE* pFile;
  if(path!=NULL && pArrayListEmployee!=NULL)
    {
      pFile =fopen(path,"r");
	if(pFile!=NULL)
	  {
	      if(parser_PeliculaFromText(pFile,pArrayListEmployee)==1)
		{
		  printf("\nLeido\n");
		  ok = 1;
		}
	      else if(parser_PeliculaFromText(pFile,pArrayListEmployee)==0)
		{
		  printf("\nMal leido");
		}
	      else
		{
		  printf("\nError");
		}
	  }
    }

  return ok;
}
int controller_ListPeliculas(LinkedList* pArrayListEmployee)
{
    int ok=-1;
    int i;
    Peliculas* auxEmp;
    int tamList;
    if(pArrayListEmployee!=NULL)
      {
	tamList=ll_len(pArrayListEmployee);
	printf("\nID    NOMBRE    HORARIO 		 DIA   		SALA  	CANT ENTRADAS\n");
	for(i=0;i<tamList;i++)
	  {
	    auxEmp = (Peliculas*)ll_get(pArrayListEmployee,i);
	    mostrar_peliculas_sin_monto(auxEmp);
	    ok=1;
	  }
      }
    return ok;
}
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
  int ok=-1;
  FILE* pArch;
  Peliculas* peli;
  int id,horario,cantidad_entradas,i,sala;
  float monto;
  char nombre[20];
  char dia[20];
  int tam=-1;


      if(path!=NULL && pArrayList!=NULL)
	{
	  tam=ll_len(pArrayList);
	  ll_map(pArrayList,calcular_monto);

	  if(tam>0)
	    {
	     pArch = fopen(path,"w");
	      if(pArch!=NULL)
		{
		  fprintf(pArch,"id,nombre,dia,horario,sala,cantidad_entradas,monto\n");

		  for(i=0;i<tam;i++)
		    {
		      peli=(Peliculas*)ll_get(pArrayList,i);
		      pelicula_getId(peli,&id);
		      pelicula_getNombre(peli,nombre);
		      pelicula_getDia(peli,dia);
		      pelicula_getHorario(peli,&horario);
		      pelicula_getSala(peli,&sala);
		      pelicula_getCant_Entradas(peli,&cantidad_entradas);
		      pelicula_getMonto(peli,&monto);
		      fprintf(pArch,"%d,%s,%s,%d,%d,%d,%.2f\n",id,nombre,dia,horario,sala,cantidad_entradas,monto);
		    }
		  fclose(pArch);
		  if(i == tam)
		    {
		      ok=1;
		    }

		}
	    }
	}
      if(ok==1)
	{
	  text("Guardado");

	}
      else
	{
	  text("Error al escribir");
	}

     return ok;
}
int controller_informes(LinkedList* pArrayList)
{
  system("cls");
  int ok=-1;
  int sala;
  int cant=0;
  float monto=0;
  char peli[21];
  int op_in;
  int op;
  Peliculas* this;
  if(pArrayList!=NULL)
    {
      do{
	  op_in = menuOrdenamiento();
	  switch(op_in)
	  {
	    case 1:
	      utn_getNumero(&op,"Ingrese numero de sala: ","Sala inexistente",1,5,3);
	      fflush(stdin);
	            for(int i = 0;i<ll_len(pArrayList);i++)
	      	{
	      	  this = (Peliculas*)ll_get(pArrayList,i);
	      	  pelicula_getSala(this,&sala);

	      	  if(sala == op)
	      	    {
	      	      cant= cant + this->cantidad_entradas;
	      	      ok=1;
	      	      break;
	      	    }
	      	}
	       printf("Se vendieron %d entradas en la sala %d\n",cant,sala);
	      break;
	    case 2:
	      utn_getNumero(&op,"Ingrese numero de sala: ","Sala inexistente",1,5,3);
	      fflush(stdin);
	      for(int i = 0;i<ll_len(pArrayList);i++)
		{
		  this = (Peliculas*)ll_get(pArrayList,i);
		  pelicula_getSala(this,&sala);
		  ll_map(pArrayList,calcular_monto);

		  if(sala == op)
		    {
		      monto = monto + this->monto;
		      ok=1;

		    }
		}
	      printf("Monto total facturado en la sala %d :%.2f\n",sala,monto);
	      break;
	    case 3:
	      utn_getNumero(&op,"Ingrese numero de sala: ","Sala inexistente",1,5,3);
	      fflush(stdin);
	      for(int i = 0;i<ll_len(pArrayList);i++)
		{
		  this = (Peliculas*)ll_get(pArrayList,i);
		  pelicula_getNombre(this,peli);
		  pelicula_getSala(this,&sala);
		  if(sala == op)
		    {
		      printf("En la sala %d se proyecto %s\n",sala,peli);
		      ok=1;
		    }
		}
	      break;
	  }
      }while(op_in!=4);
    }
  return ok;
}
int controller_ord_cantEntradas(LinkedList* this)
{
  system("cls");
  int ok=-1;
  int i;

  if(this!=NULL)
    {
      for(i= 0;i<ll_len(this);i++)
	{
	  (Peliculas*)ll_get(this,i);
	  ll_sort(this,comparaPelis_cant_entradas,1);
	  ok=1;
	}
    }
  return ok;
}

int controller_clone(LinkedList* this){
  system("cls");
  int ok=-1;
  int op;
  int ubicacion,ubicacion2;
  char nombreArchivo[21];
  text("Sistema de clonado de listas");
  LinkedList* listaOrdenada;
  Peliculas* Aux;
  if(this!=NULL)
    {
      listaOrdenada = ll_clone(this);
      if(listaOrdenada!=NULL)
	{
	  debug();
	  ll_containsAll(listaOrdenada,this);
	      controller_ord_cantEntradas(listaOrdenada);
	      controller_ListPeliculas(listaOrdenada);
	      text("Lista copiada correctamente");
	      utn_getNumero(&op,"\n1.Desea generar un archivo de esta lista?\n2.Desea borrar la lista?\n3.Desea manipular la lista?","Error",1,3,3);
	      switch(op){
		case 1:
		  get_string("Nombre del archivo a crear: ",nombreArchivo);
		  controller_saveAsText(nombreArchivo,listaOrdenada);
		  ok=1;
		  break;
		case 2:
		  if(ll_deleteLinkedList(listaOrdenada)==0)
		    {
		      text("\nLista borrada con exito");
		      ok=1;
		    }
		  break;
		case 3:
		   controller_ListPeliculas(listaOrdenada);
		   printf("\nMover una pelicula a una posicion deseada\nIngrese el id de la pelicula que desea mover: ");
		   scanf("%d",&ubicacion);
		   Aux=(Peliculas*)ll_pop(listaOrdenada,ubicacion-1);
		   printf("Ingresar la posicion en la cual se va a agregar la siguiente pelicula:\n");
		   MostrarPeli(Aux);
		   scanf("%d",&ubicacion2);
		   if(ll_push(listaOrdenada,ubicacion2-1,Aux)==0)
		     {

		       text("\nAcomodada correctamente");
		     }
		   mostrar_peliculas_sin_monto(Aux);
		   ok=1;
		  break;

	}
      }
    }
  return ok;
}

int controller_addPelicula(LinkedList* pArrayList)
{
    int ok=-1;
    int auxId;
    int auxHorario;
    int auxSala;
    int auxCant_Entradas;
    char auxNombre[21];
    char dia[20];


    if(pArrayList!=NULL)
      {
	//debug();
	Peliculas* nPeli = new_pelicula();
	if(nPeli!=NULL)
	  {
	    auxId=auto_id(pArrayList);


	    utn_getNumero(&auxHorario,"Horario: ","\nError",0,24,3);
	    getString(dia,"Dia:","\nError",0,20,3);
	    fflush(stdin);
	    utn_getNumero(&auxSala,"Sala: ","\nError",1,6,3);
	    utn_getNumero(&auxCant_Entradas,"Cantidad de entradas: ","\nError",1,15,3);
	    getString(auxNombre,"Nombre:\n","\nError",0,20,3);
	    ok =1;
	  }
	if(ok==1)
	  {

	   pelicula_setId(nPeli,auxId);
	   pelicula_setNombre(nPeli,auxNombre);
	   pelicula_setDia(nPeli,dia);
	   pelicula_setHorario(nPeli,auxHorario) ;
	   pelicula_setSala(nPeli,auxSala);
	   pelicula_setCant_Entradas(nPeli,auxCant_Entradas);

	   if(ll_add(pArrayList,nPeli)==0)
	     {
	       text("ok");
	     }
	  }

      }
    return ok;
}


















