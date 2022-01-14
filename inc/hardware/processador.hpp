#ifndef __PROCESSADOR_HPP
#define __PROCESSADOR_HPP

#include <iostream>
#include <string>

#include "../processo.hpp"

using namespace std;

// enum estado{
//   Novo,
//   Pronto,
//   Executando,
//   Bloqueado,
//   Finalizado,
// };

enum Estado {
  Livre,
  Ocupado,
};


typedef struct {
  Processo processo;
  Estado   estado;
} Nucleo;

class Processador {
 private:
  int qtd_nucleos;

 public:
  Nucleo* nucleos;

  Processador(int qtd_nucleos);
  void imprimir();
};

#endif