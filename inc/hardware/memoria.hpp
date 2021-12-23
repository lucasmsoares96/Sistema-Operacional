#ifndef __MEMORIA_HPP
#define __MEMORIA_HPP

#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef struct {
  int    key;
  string value;
} valorMemoria;

typedef struct Hash Hash;

struct Hash {
  map<int, valorMemoria> hash;
};

class Memoria {
 private:
  Hash RAM;
  int  segmentos;

 public:
  Memoria(int segmentos);
  void imprimir();
};

#endif