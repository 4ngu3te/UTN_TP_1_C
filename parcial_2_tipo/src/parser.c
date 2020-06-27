#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Peliculas.h"
#include "parser.h"

int parser_PeliculaFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
  int ok = -1;
  int cant;
  char buff[6][20];
  Peliculas* nPeli = NULL;

  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3],buff[4],buff[5]);

    if(pFile!=NULL && pArrayListEmployee!=NULL)
      {
	while(!feof(pFile))
	  {

	    cant= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buff[0], buff[1], buff[2], buff[3],buff[4],buff[5]);
	    dias(buff[2]);
	    nPeli=pelicula_newParametros(buff[0], buff[1], buff[2], buff[3],buff[4],buff[5]);
	    if(nPeli!=NULL)
	      {
		ll_add(pArrayListEmployee,nPeli);
		ok=1;
	      }
	      if(feof(pFile) && cant >= 6)
		{
		  break;
		}
	  }
      }


    return ok;
}

