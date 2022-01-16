#include "../../inc/hardware/memoria.hpp"

Memoria::Memoria(int qtd_segmentos) {
  this->qtd_segmentos = qtd_segmentos;

  for (int i = 0; i < qtd_segmentos; i++) {
    Processo processo;
    segmento[i] = processo;
  }
}

void Memoria::imprimir() {
  map<int, Processo>::iterator it;
  cout << endl;

  for (it = this->segmento.begin(); it != this->segmento.end(); it++) {
    it->second.imprimir();
  }
  cout << endl;
}
