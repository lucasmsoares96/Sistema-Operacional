#include "../../inc/hardware/processador.hpp"

Processador::Processador(int qtd_nucleos) {
  this->qtd_nucleos = qtd_nucleos;
  this->nucleos     = new Processo[qtd_nucleos];
}

void Processador::imprimir() {
  for (int i = 0; i < qtd_nucleos; i++) {
    nucleos[i].imprimir();
  }
}