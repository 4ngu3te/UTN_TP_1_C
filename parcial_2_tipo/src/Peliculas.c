/*
 * Peliculas.c
 *
 *  Created on: 23 jun. 2020
 *      Author: Franco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peliculas.h"
#include "utn.h"
#include "LinkedList.h"

Peliculas* new_pelicula()//
{
  Peliculas* this =(Peliculas*)malloc(sizeof(Peliculas));
  if(this!=NULL)
    {
      pelicula_setId(this,0);
      pelicula_setNombre(this," ");
      pelicula_setDia(this," ");
      pelicula_setHorario(this,0);
      pelicula_setSala(this,0);
      pelicula_setCant_Entradas(this,0);
      pelicula_setMonto(this,0);
    }
  return this;
}
Peliculas* pelicula_newParametros(char* id, char* nombre,char* dia, char* horario, char* sala, char* cantidad_entradas)
{
  Peliculas* this = new_pelicula();
  if(id!=NULL && nombre!=NULL && dia!=NULL && horario!=NULL && sala!=NULL && cantidad_entradas!=NULL)
    {
      pelicula_setId(this,atoi(id));
      pelicula_setNombre(this,nombre);
      pelicula_setDia(this,dia);
      pelicula_setHorario(this,atoi(horario));
      pelicula_setSala(this,atoi(sala));
      pelicula_setCant_Entradas(this,atoi(cantidad_entradas));
    }
  return this;
}
void dias(char* dia)
{
  int dia_seleccionado =  atoi(dia);
  switch(dia_seleccionado){
    case 1:
      strcpy(dia,"Lunes");
      break;
    case 2:
      strcpy(dia,"Martes");
      break;
    case 3:
      strcpy(dia,"Miercoles");
      break;
    case 4:
      strcpy(dia,"Jueves");
      break;
    case 5:
      strcpy(dia,"Viernes");
      break;
    case 6:
      strcpy(dia,"Sabado");
      break;
    case 0:
      strcpy(dia,"Domingo");
      break;
  }

}
int pelicula_setId(Peliculas* this,int id)
{
	int ok=-1;
	if(this!=NULL && id>0){
		this->id_venta = id;
		ok=0;
	}
	return ok;
}
int pelicula_setNombre(Peliculas* this,char* nombre)
{
	int ok=-1;
	if(this!=NULL && strlen(nombre)>0)
	  {
	    strcpy(this->nombre_pelicula,nombre);
	    ok=0;
	  }
	return ok;
}
int pelicula_setDia(Peliculas* this,char* dia)
{
	int ok=-1;
	if(this!=NULL && strlen(dia)>0)
	  {
	    strcpy(this->dia,dia);
	    ok=0;
	  }
	return ok;
}
int pelicula_setHorario(Peliculas* this,int horario)
{
	int ok=-1;
	if(this!=NULL && horario>=0)
	  {
	    this->horario= horario;
	    ok=0;
	  }
	return ok;
}
int pelicula_setSala(Peliculas* this,int Sala)
{
	int ok=-1;
	if(this!=NULL && Sala>=0)
	  {
	    this->sala = Sala;
	    ok=0;
	  }
	return ok;
}
int pelicula_setCant_Entradas(Peliculas* this,int Cant_Entradas)
{
	int ok=-1;
	if(this!=NULL && Cant_Entradas>=0)
	  {
	    this->cantidad_entradas = Cant_Entradas;
	    ok=0;
	  }
	return ok;
}
int pelicula_setMonto(Peliculas* this,int monto)
{
	int ok=-1;
	if(this!=NULL && monto>=0)
	  {
	    this->monto = monto;
	    ok=0;
	  }
	return ok;
}
/*
 *
 * GETTERS
 *
 */
int pelicula_getId(Peliculas* this,int* id)
{
	int ok=-1;
	if(this!=NULL && id>0){
	    *id = this->id_venta;
		ok=0;
	}
	return ok;
}
int pelicula_getNombre(Peliculas* this,char* nombre)
{
	int ok=-1;
	if(this!=NULL && strlen(nombre)>0)
	  {
	    strcpy(nombre,this->nombre_pelicula);
	    ok=0;
	  }
	return ok;
}
int pelicula_getDia(Peliculas* this,char* dia)
{
	int ok=-1;
	if(this!=NULL)
	  {
	    strcpy(dia,this->dia);
	    ok=0;
	  }
	return ok;
}
int pelicula_getHorario(Peliculas* this,int* horario)
{
	int ok=-1;
	if(this!=NULL && horario>=0)
	  {
	    *horario = this->horario;
	    ok=0;
	  }
	return ok;
}
int pelicula_getSala(Peliculas* this,int* Sala)
{
	int ok=-1;
	if(this!=NULL && Sala>=0)
	  {
	    *Sala = this->sala;
	    ok=0;
	  }
	return ok;
}
int pelicula_getCant_Entradas(Peliculas* this,int* Cant_Entradas)
{
	int ok=-1;
	if(this!=NULL && Cant_Entradas>=0)
	  {
	    *Cant_Entradas = this->cantidad_entradas;
	    ok=0;
	  }
	return ok;
}
int pelicula_getMonto(Peliculas* this,float* monto)
{
	int ok=-1;
	if(this!=NULL && monto>=0)
	  {
	    *monto = this->monto;
	    ok=0;
	  }
	return ok;
}
void pelicula_delete(Peliculas* this)
{
     if(this!=NULL)
       {
	 free(this);
       }
}
void mostrar_peliculas_sin_monto(Peliculas* pArrayList)
{
  if(pArrayList!=NULL)
      {
        printf("\n%1d %10s 	  %5d 	  %10s	 	%2d 		%d\n",pArrayList->id_venta,pArrayList->nombre_pelicula,pArrayList->horario,pArrayList->dia,pArrayList->sala,pArrayList->cantidad_entradas);
      }
    else
      {
        printf("\nNo hay peliculas para mostrar.");
      }
}
void MostrarPeli(Peliculas* pArrayList)
{
  printf("\n%1d %10s 	  %5d 	  %10s	 	%2d 		%d\n",pArrayList->id_venta,pArrayList->nombre_pelicula,pArrayList->horario,pArrayList->dia,pArrayList->sala,pArrayList->cantidad_entradas);
}

int comparaPelis_cant_entradas(void* pPeliA,void* pPeliB)
{
  if(pPeliA !=NULL && pPeliB!=NULL)
    {
      if(((Peliculas*)pPeliA)->cantidad_entradas > ((Peliculas*)pPeliB)->cantidad_entradas)
	{
	    return 1;
	}
      if(((Peliculas*)pPeliA)->cantidad_entradas > ((Peliculas*)pPeliB)->cantidad_entradas)
	{
	    return -1;
	}

    }

    return 0;
}
void* calcular_monto(void* element)
{
  Peliculas* monto = (Peliculas*)element;
  float monto_total;
  char auxDia[21];
  int cant_entradas;
  pelicula_getCant_Entradas(monto,&cant_entradas);
  pelicula_getDia(monto,auxDia);
  fflush(stdin);
  if(element!=NULL)
    {
    if(strcmp(auxDia,"Lunes")==0 || strcmp(auxDia,"Martes")==0)
      {
	monto_total = cant_entradas*240;
	if(cant_entradas >= 3)
	  {
	    monto_total = monto_total*0.90;
	  }
      }
    else
      {
	monto_total = cant_entradas*350;
	if(cant_entradas >= 3)
	  {
	    monto_total = monto_total*0.90;
	  }
      }
    }
    pelicula_setMonto(monto,monto_total);

    return element;
}
int auto_id(LinkedList* this)
{
    int ultimoId,id,i;
    static int id_incre;

    Peliculas* nPeli;

	if(this!=NULL)
	  {
	    for(i=0;i<ll_len(this);i++)
	      {
		nPeli =(Peliculas*)ll_get(this,i);
		pelicula_getId(nPeli,&id);

		if(i==0 && id>0)
		  {
		    ultimoId = id;
		  }
		else if(id>ultimoId)
		  {
		    ultimoId = id;
		  }
	      }
	  }
	if(ultimoId > id_incre)
	  {
	    id_incre=ultimoId+1;
	  }
	else
	  {
	    id_incre++;
	  }
	//printf("id_incr %d",id_incre);
	return id_incre;

}
/*int sacar_cant_entradas_por_sala(Peliculas* this)
{
  int op;
  int i;
  int sala;
  int cant;
  int ok=-1;

  if(this!=NULL)
    {
      utn_getNumero(&op,"Ingrese numero de sala: ","Sala inexistente",1,5,3);
      for(i=0;i<ll_len(this);i++)
	{
	  this = (Peliculas*)ll_get(this,i);
	  pelicula_getSala(this,&sala);
	  if(sala == op)
	    {
	      cant= cant + this->cantidad_entradas;
	      printf("%d",cant);
	      ok=1;
	    }
	}
    }


  return ok;
}*/
