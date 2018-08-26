// Esta linea sirve para que el codigo de este archivo solo se importe una vez
#pragma once
#include "process.h"


struct lista_nodo;
/** Representa un nodo de una lista */
typedef struct lista_nodo Nodo;

struct lista_nodo
{
	/** Valor insertado en el nodo */
	process* proceso;
	/** Siguiente nodo en la lista */
	Nodo* sig;
};

/** Estructura de una lista ligada */
struct linked_list
  {
	/** Primer elemento de la lista */
	Nodo* inicio;
	/** Último elemento de la lista */
	Nodo* ultimo;
	/** Cantidad de elementos en la lista */
	int count;
};
  // TODO: Completar esto

// Aqui le estoy poniendo un nombre mas simple a la lista para no tener que
// referirme a la lista como struct linked_list
/** Estructura de una lista ligada */
typedef struct linked_list LinkedList;


//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

//OJO: No se debe modificar nada de esto

/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init();

/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, process* element);

/** Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, process* element, int position);

/** Elimina el elemento de la posicion indicada y lo retorna */
int linkedlist_delete(LinkedList* list, int position);

/** Retorna el valor del elemento en la posicion dada */
process* linkedlist_get(LinkedList* list, int position);

process* linkedlist_pop(LinkedList* list);

/** Concatena la segunda lista a la primera lista */
void linkedlist_concatenate(LinkedList* list1, LinkedList* list2);

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list);
