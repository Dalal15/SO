// Esta linea sirve para que el código de este archivo solo se importe una vez
#pragma once
#include "process.h"


struct Cpu
{
  /* 0 si esta libre, 1 si esta ocupada */
  int libre;
  /* proceso e cpu */
  process * proceso;

};

typedef struct Cpu cpu;


cpu* cpu_init();

void cpu_free(cpu* cpu);
