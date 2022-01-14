#include "../inc/kernel.hpp"

Kernel::Kernel(string file_name) {
  this->hardware    = new Hardware(file_name);
  this->processador = new Processador(hardware->cores);
  this->memoria     = new Memoria(hardware->segmentos);
  this->disco       = new Disco(hardware->blocos);
}
