#ifndef __CPU_HPP
#define __CPU_HPP

#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef struct {
  int    core;
  int    quantum;
  int    timestamp;
  string description;
} processo;

class Cpu {
 public:
  Cpu(int cores);
  list<processo> lista;
  int            cores;
  void           imprimir();
};

#endif