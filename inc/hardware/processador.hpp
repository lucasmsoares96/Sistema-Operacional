#ifndef __PROCESSADOR_HPP
#define __PROCESSADOR_HPP

#include <iostream>
#include <string>

#include "../processo.hpp"

using namespace std;

class Processador {
 private:
  int qtd_nucleos;

 public:
  Processo* nucleos;

  Processador(int qtd_nucleos);
  void imprimir();
};

#endif