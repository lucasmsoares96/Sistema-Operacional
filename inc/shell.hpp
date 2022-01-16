#ifndef __SHELL_HPP
#define __SHELL_HPP

#include <iostream>
#include <map>
#include <string>

#include "escalonador.hpp"

using namespace std;

class Shell {
 private:
  Escalonador *escalonador;
  void         help();
  void         bold(int status);
  void         italic(int status);

 public:
  Shell(Escalonador *escalonador);
  void imprimir();
};

#endif