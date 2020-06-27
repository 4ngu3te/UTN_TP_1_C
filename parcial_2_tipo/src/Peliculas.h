/*
 * Peliculas.h
 *
 *  Created on: 23 jun. 2020
 *      Author: FrancoGollo
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_
#include "LinkedList.h"
typedef struct{
  int id_venta;
  char nombre_pelicula[51];
  char dia[21];
  int horario;
  int sala;
  int cantidad_entradas;
  float monto;
}Peliculas;
#endif /* PELICULAS_H_ */
Peliculas* new_pelicula();
Peliculas* pelicula_newParametros(char* id, char* nombre,char* dia, char* horario, char* sala, char* cantidad_entradas);

void dias(char* dia);

/*
 * Setters
 */
int pelicula_setId(Peliculas* this,int id);
int pelicula_setNombre(Peliculas* this,char* nombre);
int pelicula_setDia(Peliculas* this,char* dia);
int pelicula_setHorario(Peliculas* this,int horario);
int pelicula_setSala(Peliculas* this,int Sala);
int pelicula_setCant_Entradas(Peliculas* this,int Cant_Entradas);
int pelicula_setMonto(Peliculas* this,int monto);
/*
 * Getters
 */
int pelicula_getId(Peliculas* this,int* id);
int pelicula_getNombre(Peliculas* this,char* nombre);
int pelicula_getDia(Peliculas* this,char* dia);
int pelicula_getHorario(Peliculas* this,int* horario);
int pelicula_getSala(Peliculas* this,int* Sala);
int pelicula_getCant_Entradas(Peliculas* this,int* Cant_Entradas);
int pelicula_getMonto(Peliculas* this,float* monto);


void pelicula_delete(Peliculas* this);
//int sacar_cant_entradas_por_sala(Peliculas* this);
void MostrarPeli(Peliculas* pArrayList);
void mostrar_peliculas_sin_monto(Peliculas* pArrayList);

int comparaPelis_cant_entradas(void* pPeliA,void* pPeliB);
void* calcular_monto(void* element);
int auto_id(LinkedList* this);
//void* entradas_por_sala(void* element);
