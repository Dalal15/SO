#include "process.h"
// Libreria estandar de C
#include <stdlib.h>



process* process_init()
{ process* proceso = malloc(sizeof(process));


	proceso -> pid = 0; /* que parta nula y se la paso */
	proceso -> nombre = NULL; /*aqui creo que tendre que dar memoria */
	proceso -> estado = NULL; //RAROOOOOO
	proceso -> t_inicio = 0;
  proceso -> t_final = 0;
	proceso -> ejec = NULL;
	proceso -> bloq = NULL;
	proceso -> n = 0;
	proceso-> count_b = 0;
	proceso-> count_e = 0;


	return proceso;

}

void process_free(process* proceso)
{



    //Se irá liberando la memoria nodo a nodo, no hay last en verdad aqui ejejje
    //process * actual = proceso;
    /*while (actual->last != NULL){
      //Se guarda una referencia al elemento siguiente
      process * next = actual->last;
      //Se libera el elemento actual
			free(actual->direcciones);
		  free(actual->asteroides);
      free(actual);
      //Se actualiza el elemento "actual"
      actual = next;

    }*/
	//	free(proceso->direcciones);
	  //free(proceso->asteroides);
    //free(actual);





}
