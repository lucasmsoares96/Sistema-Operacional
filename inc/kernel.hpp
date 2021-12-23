#ifndef __KERNEL_HPP
#define __KERNEL_HPP

#include <iostream>
#include <string>

#include "./hardware.hpp"
#include "./hardware/cpu.hpp"
#include "./hardware/disco.hpp"
#include "./hardware/memoria.hpp"

using namespace std;

class Kernel {
 private:
 public:
  Hardware *hardware;
  Cpu      *cpu;
  Memoria  *memoria;
  Disco    *disco;
  Kernel(string file_name);
  void imprimir();
};

#endif