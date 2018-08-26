#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "process.h"
#include "cpu.h"
#include "linkedlist.h"

//funcion argumento de qsort
int compare_pointed_to_data(const void* a, const void* b) {
    // a is a pointer into the array of pointers
    process *ptr_to_left_struct = *(process**)a;
    process *ptr_to_right_struct = *(process**)b;

    if ( ptr_to_left_struct->t_inicio < ptr_to_right_struct->t_inicio)
        return -1;
    else if (ptr_to_left_struct->t_inicio > ptr_to_right_struct->t_inicio)
        return 1;
    else
        return 0;
}



int main(int argc, char** argv)
{

	/* preguntar si podemos asumir que daran bien el input, si vendran ordenados */

	int q;

  if(argc!= 4 )
		{
			printf("Por default sera el quantum 3\n");
			q = 3;
		}

		else
		{
			q = atoi(argv[3]);
		}

FILE* input_file = fopen(argv[1], "r");

if(!input_file)
{
	printf("¡El archivo %s no existe!\n", argv[1]);
	return 2;
}

int id = 1;
process *array_process[40]; //deberia hacer realloc , puedo guardar int antes en todo caso pa cachar cuantos procesos son y segun eso dar memoria
while(1)
{

	char * lines[0];
	lines[0] = malloc (256);

	 int data;
	 int conteo;

	//obtengo el nombre proceso
	 fscanf (input_file, "%127s", lines[0]);

	 if(strlen(lines[0])==0)
	 { free(lines[0]);
		 printf("%s\n","que se termine" );
		 break;
	 }
   //se que es factible y creo proceso
	 process*  proceso = process_init();
	 proceso->pid = id;
	 array_process[id-1] = proceso;
	 proceso->estado = malloc(20);
	 proceso->estado = "NUEVO";

  //obtengo el tiempo de llegada
	fscanf(input_file,"%d", &data);
	proceso->t_inicio = data;
	proceso->nombre = lines[0];

	//obtengo el N
	fscanf(input_file,"%d", &data);

	proceso->n = data;
	conteo = data*2 -1;

	proceso->ejec= malloc(sizeof(int)*data);
	proceso->bloq= malloc(sizeof(int)*data-1);

	int cont_ejec = 0;
	int cont_bloq = 0;

	for (int index = 0; index < conteo; index++){

			fscanf(input_file,"%d", &data);
			if (index%2==0)
			{
				proceso->ejec[cont_ejec]= data;
				cont_ejec++;
			}

			else{

				proceso->bloq[cont_bloq]= data;
				cont_bloq++;
			}

		};
		id++;
		printf("EL PROCESO de id: %i de nombre %s\n",proceso->pid,proceso->nombre );
		printf("%s\n","-------------------------------" );

}

//arreglo ordenado
qsort(array_process, id-1, sizeof(process*), compare_pointed_to_data);

//estructuras para la simulacion
cpu* cpu = cpu_init();
LinkedList* cola_ready = linkedlist_init();
LinkedList* cola_waiting = linkedlist_init();

int tiempo =0;
int llegada =0;

while(1)
{

	if(array_process[llegada]->t_inicio == tiempo)
	{
		printf("En t = %i se creo el proceso %s\n", tiempo, array_process[llegada]->nombre);
		printf("En t = %i el proceso %s está ready\n" , tiempo, array_process[llegada]->nombre);

		linkedlist_append(cola_ready,array_process[llegada]);
		llegada++;
	}

	if (cpu->libre ==0 && cola_ready->inicio == NULL)
	{
		//si esta libre debo sacar de cola y pasar a running
		printf("En t = %i el proceso %s está running\n" , tiempo, "idle");
	}

	if (cpu->libre ==0 && cola_ready->inicio != NULL)
	{
		//si esta libre debo sacar de cola y pasar a running

		process* proceso = linkedlist_pop(cola_ready);
		proceso->estado ="RUNNING";
		cpu->libre = 1;
		cpu->proceso = proceso;
	}

	if(cpu->libre ==1)
	{
		printf("En t = %i el proceso %s está running\n" , tiempo, cpu->proceso->nombre);
	}

	tiempo++;
	if (tiempo ==30)
	{
		break;
	}


}

}
