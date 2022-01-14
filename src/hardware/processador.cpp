#include "../../inc/hardware/processador.hpp"

Processador::Processador(int qtd_nucleos) {
  this->nucleos = new Nucleo[qtd_nucleos];
}

void Processador::imprimir() {
  for (int i = 0; i < this->qtd_nucleos; i++) {
    cout << endl
         << "Processo: " << nucleos[i].processo.processo
         << "Ciclos: " << nucleos[i].processo.ciclos
         << "Max Quantom: " << nucleos[i].processo.max_quantum
         << "Timestamp: " << nucleos[i].processo.timestamp
         << "Prioridade: " << nucleos[i].processo.prioridade
         << "Punição: " << nucleos[i].processo.punicao << endl;
  }
}