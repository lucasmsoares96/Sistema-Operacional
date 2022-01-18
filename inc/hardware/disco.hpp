#ifndef __DISCO_HPP
#define __DISCO_HPP

#include <iostream>
#include <list>
#include <string>

#include "../processo.hpp"

using namespace std;
class Disco {
 public:
  list<Processo> blocos;
  int            qtd_blocos;

  Disco(int blocos);
  void     imprimir();
  void     limpar();
  Processo buscar_em(int bloco);
  void     gravar_em(int bloco, Processo processo);
};

#endif