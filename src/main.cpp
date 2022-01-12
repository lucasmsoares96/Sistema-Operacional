#include <iostream>
#include <string>

#include "../inc/kernel.hpp"
#include "../inc/shell.hpp"

using namespace std;

int main() {
  string  hardware_file = "config.json";
  Kernel *kernel        = new Kernel(hardware_file);
  Shell  *shell         = new Shell(kernel);
  
  shell->imprimir();

  return 0;
}