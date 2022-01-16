#include "../../inc/hardware/processador.hpp"

Processador::Processador(int qtd_nucleos) {
  this->nucleos = new Processo[qtd_nucleos];
}

void Processador::imprimir() {
  for (int i = 0; i < this->qtd_nucleos; i++) {
    cout << endl
         << "Processo: " << nucleos[i].processo
         << "Ciclos: " << nucleos[i].ciclos
         << "Max Quantom: " << nucleos[i].max_quantum
         << "Timestamp: " << nucleos[i].timestamp
         << "Prioridade: " << nucleos[i].prioridade
         << "Punição: " << nucleos[i].punicao << endl;
  }
}