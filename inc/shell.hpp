#ifndef __SHELL_HPP
#define __SHELL_HPP

#include <iostream>
#include <map>
#include <string>

#include "kernel.hpp"

using namespace std;

class Shell {
 private:
  Kernel *kernel;
  void    help();
  void    bold(int status);
  void    italic(int status);

 public:
  Shell(Kernel *kernel);
  void imprimir();
};

#endif