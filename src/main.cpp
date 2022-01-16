#include <iostream>
#include <string>

#include "../inc/escalonador.hpp"
#include "../inc/hardware.hpp"
#include "../inc/kernel.hpp"
#include "../inc/shell.hpp"

using namespace std;

int main() {
  srand(time(NULL));
  string       arquivo_hardware  = "config.json";
  string       arquivo_processos = "processos2.json";
  Hardware    *hardware          = new Hardware(arquivo_hardware);
  Kernel      *kernel            = new Kernel(hardware);
  Escalonador *escalonador = new Escalonador(kernel, arquivo_processos);
  Shell       *shell       = new Shell(escalonador);

  // // // passar para pthread
  escalonador->executar_escalonador();

  shell->imprimir();

  return 0;
}