#ifndef __MEMORIA_HPP
#define __MEMORIA_HPP

#include <iostream>
#include <map>
#include <string>

#include "../processo.hpp"

using namespace std;

class Memoria {
 private:
 public:
  map<int, Processo> segmentos;
  int                qtd_segmentos;
  Memoria(int qtd_segmentos);
  void imprimir();
};

#endif