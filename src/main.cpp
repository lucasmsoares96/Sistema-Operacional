#include <iostream>
#include <string>

#include "../inc/escalonador.hpp"
#include "../inc/kernel.hpp"
#include "../inc/shell.hpp"

using namespace std;

int main() {
  string       arquivo_hardware  = "config.json";
  string       arquivo_processos = "processos.json";
  Kernel      *kernel            = new Kernel(arquivo_hardware);
  Shell       *shell             = new Shell(kernel);
  Escalonador *escalonador = new Escalonador(kernel, arquivo_processos);

  shell->imprimir();

  return 0;
}