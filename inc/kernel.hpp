#ifndef __KERNEL_HPP
#define __KERNEL_HPP

#include <iostream>
#include <string>

#include "./hardware.hpp"
#include "./hardware/disco.hpp"
#include "./hardware/memoria.hpp"
#include "./hardware/processador.hpp"

using namespace std;

class Kernel {
 private:
 public:
  Hardware    *hardware;
  Processador *processador;
  Memoria     *memoria;
  Disco       *disco;
  string       politica;

  Kernel(Hardware *hardware);
  void imprimir();
};

#endif