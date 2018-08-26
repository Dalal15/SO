// importo el archivo linkedlist.h
#include "linkedlist.h"
#include "process.h"
// Libreria estandar de C
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

static Nodo* node_init(process* proceso)
{
	Nodo* nodo = malloc(sizeof(Nodo));
	nodo -> proceso = proceso;
	nodo -> sig = NULL;
	return nodo;
}



/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init()
{ LinkedList* list = malloc(sizeof(LinkedList));
	list -> count = 0;
	list -> inicio = NULL;
	list -> ultimo = NULL;
	return list;

}


/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, process* element)
{
  Nodo* nuevo = node_init(element);
	if(list -> count == 0)
	{
		list -> ultimo = nuevo;
		list -> inicio = nuevo;
	}
	else
	{
		list -> ultimo -> sig = nuevo;
		list -> ultimo = nuevo;
	}
	list -> count++;
	/*printf("%i\n", list->inicio->proceso->nav_count );*/

}

/** Inserta el elemento dado en la posicion indicada */


/** Concatena a la lista una segunda lista */


static void node_destroy_all(Nodo* nodo)
{
	if(nodo -> sig)
	{
		node_destroy_all(nodo -> sig);
	}
	free(nodo);
}

//en verdad es un pop_left
process* linkedlist_pop(LinkedList* list)
{
	Nodo * actual;
	  actual = list -> inicio;
		list -> inicio = list->inicio->sig;
		list->count--;
		return actual->proceso;

}

process* linkedlist_get(LinkedList* list, int position)
{Nodo * actual;
  actual = list -> inicio;
  int i = 0;
  while( i < position )
  {actual = actual -> sig;
    i++;
  }
return actual -> proceso ;
}

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{
	if (list->count == 0){
    free(list);
  }
  else{
    //Se irá liberando la memoria nodo a nodo
    Nodo * actual = list->inicio;
    while (actual->sig != NULL){
      //Se guarda una referencia al elemento siguiente
      Nodo * next = actual->sig;
      //Se libera el elemento actual
      process_free(actual);
      //Se actualiza el elemento "actual"
      actual = next;
    }
    process_free(actual);
    free(list);
  }
}
