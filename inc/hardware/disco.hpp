#ifndef __DISCO_HPP
#define __DISCO_HPP

#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct {
  int    key;
  string value;
} valorDisco;

class Disco {
 public:
  queue<valorDisco> fila;
  int               blocos;
  int               atual;

  Disco(int blocos);
  void bloco();
  void imprimir();
};

#endif