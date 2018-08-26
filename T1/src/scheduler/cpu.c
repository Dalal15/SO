// Importo el archivo arraylist.h
#include "cpu.h"
#include "process.h"
// Libreria estandar de C
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: Debes completar las siguientes funciones
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una arraylist inicialmente vacia y retorna su puntero */
cpu* cpu_init()
{ cpu* cpu = malloc(sizeof(cpu));


	cpu -> libre = 0; /* parte libre */
	cpu -> proceso = NULL; /*aqui creo que tendre que dar memoria */


	return cpu;

}

void cpu_free(cpu* cpu){

}
