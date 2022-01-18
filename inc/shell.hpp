#ifndef __SHELL_HPP
#define __SHELL_HPP

#include <atomic>
#include <iostream>
#include <map>
#include <string>

#include "../inc/global.hpp"
#include "escalonador.hpp"

using namespace std;

class Shell {
 private:
  Escalonador *escalonador;
  void         help();
  void         bold(int status);
  void         italic(int status);
  bool         loop = true;
  template <class C>
  void function1(void (C::*function)(), C &c);

 public:
  Shell(Escalonador *escalonador);
  void imprimir();
};

#endif