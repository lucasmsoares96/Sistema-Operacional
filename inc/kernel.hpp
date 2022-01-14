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
  Hardware *hardware;

 public:
  Processador *processador;
  Memoria     *memoria;
  Disco       *disco;

  Kernel(string file_name);
  void imprimir();
};

#endif