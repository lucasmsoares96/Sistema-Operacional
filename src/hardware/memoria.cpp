#include "../../inc/hardware/memoria.hpp"

// void Memoria::Insert(int key, valorMemoria valor) {
//   this->RAM.hash[key] = key;
// }

Memoria::Memoria(int segmentos) {
  this->segmentos = segmentos;
  for (int i = 0; i < segmentos; i++) {
    this->RAM.hash[i].key       = 0;
    this->RAM.hash[i].value = "-";
  }
}

void Memoria::imprimir() {
  cout << endl;
  map<int, valorMemoria>::iterator it;

  for (it = this->RAM.hash.begin(); it != this->RAM.hash.end(); it++) {
    if (it->second.key == 0) {
      cout << "Segmento " << it->first << "\t"
           << "value: " << it->second.value << "\t"
           << "key: "
           << "EMPTY"
           << "\t"
           << "Estado: "
           << "Livre" << endl;
    } else {
      cout << "Segmento " << it->first << "\t"
           << "value: " << it->second.value << "\t"
           << "key: " << it->second.key << "\t"
           << "Estado: Em uso" << endl;
    }
  }
  cout << endl;
}
