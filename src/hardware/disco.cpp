#include "../../inc/hardware/disco.hpp"

Disco::Disco(int blocos) {
  this->blocos = blocos;
  this->atual  = 0;
  valorDisco novo;

  novo.key       = 0;
  novo.value     = "-";
  for (int i = 0; i < blocos; i++) {
    fila.push(novo);
  }
}

void Disco::imprimir() {
  cout << endl;
  queue<valorDisco> aux     = fila;
  long unsigned int tamanho = fila.size();

  for (long unsigned int i = 0; i < tamanho; i++) {
    if (aux.front().key != 0) {
      cout << "Bloco " << i << "\t"
           << "value: " << aux.front().value << "\t"
           << "key: " << aux.front().key << "\t"
           << "Estado: "
           << "Ocupado" << endl;
    } else {
      cout << "Bloco " << i << "\t"
           << "value: " << aux.front().value << "\t"
           << "key: " << aux.front().key << "\t"
           << "Estado: "
           << "Livre" << endl;
    }
    aux.pop();
  }
  cout << endl;
}