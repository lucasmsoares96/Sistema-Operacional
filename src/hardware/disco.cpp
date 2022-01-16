#include "../../inc/hardware/disco.hpp"

#include <iterator>

Disco::Disco(int qtd_blocos) {
  this->qtd_blocos = qtd_blocos;
  this->atual      = 0;
  for (int i = 0; i < qtd_blocos; i++) {
    Processo processo;
    blocos.push_back(processo);
  }
}

void Disco::imprimir() {
  cout << endl;
  for (auto& bloco : blocos) {
    bloco.imprimir();
  }
  cout << endl;
}

Processo Disco::buscar_em(int bloco) {
  std::list<Processo>::iterator it;
  advance(it, bloco);
  return *it;
}

void Disco::gravar_em(int bloco, Processo processo) {
  std::list<Processo>::iterator it = blocos.begin();
  advance(it, bloco);
  *it = processo;
}