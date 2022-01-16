#include "../inc/kernel.hpp"

Kernel::Kernel(Hardware *hardware) {
  this->politica    = hardware->politica;
  this->processador = new Processador(hardware->cores);
  this->memoria     = new Memoria(hardware->segmentos);
  this->disco       = new Disco(hardware->blocos);
}
