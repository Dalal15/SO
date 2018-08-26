#pragma once



struct Process
{
  /* pid que se asociará según cuando llegue (i) */
  int pid;
  /* nombre obtenido del archivo txt */
  char *nombre;
  /* nombre del estado waiting/ready etc */
  char* estado;
  /* tiempo llegada */
  int t_inicio;
/* tiempo final */
  int t_final;

  /* direccion del que disparo */
  int* ejec;

  int* bloq;

  int n;

  int count_e;

  int count_b;


};

typedef struct Process process;


process* process_init();

void process_free(process* proceso);
