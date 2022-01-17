#include "../../inc/hardware/memoria.hpp"

Memoria::Memoria(int qtd_segmentos) {
  this->qtd_segmentos = qtd_segmentos;

  for (int i = 0; i < qtd_segmentos; i++) {
    Processo processo;
    segmentos[i] = processo;
  }
}

void Memoria::imprimir() {
  cout << endl;
  for (auto segmento : segmentos) {
    segmento.second.imprimir();
  }
  cout << endl;
}
