#include "../../inc/hardware/cpu.hpp"

Cpu::Cpu(int cores) {
  this->cores = cores;
  for (int i = 0; i < cores; i++) {
    processo p;
    p.description = "-";
    p.quantum     = 0;
    p.timestamp   = 0;
    lista.push_back(p);
  }
}

void Cpu::imprimir() {
  cout << endl;
  int cont = 0;
  for (processo item : lista) {
    cont += 1;
    cout << "Core " << cont << "\t"
         << "Description: " << item.description << "\t"
         << "Quantum " << item.quantum << "\t"
         << "Timestamp: " << item.timestamp << endl;
  }
  cout << endl;
}