#include <iostream>
#include <string>
#include <thread>

#include "../inc/escalonador.hpp"
#include "../inc/hardware.hpp"
#include "../inc/kernel.hpp"
#include "../inc/shell.hpp"

using namespace std;

void task1(string msg) {
  cout << "task1 says: " << msg;
}

int main() {
  srand(time(NULL));

  string       arquivo_hardware  = "config.json";
  string       arquivo_processos = "processos.json";
  Hardware    *hardware          = new Hardware(arquivo_hardware);
  Kernel      *kernel            = new Kernel(hardware);
  Escalonador *escalonador = new Escalonador(kernel, arquivo_processos);
  Shell       *shell       = new Shell(escalonador);

  shell->imprimir();

  return 0;
}