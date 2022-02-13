#ifndef __PROCESSO_HPP
#define __PROCESSO_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "../lib/json.hpp"

using json = nlohmann::json;

using namespace std;

class Processo {
 private:
 public:
  int          processo;
  int          ciclos;
  int          cnt_ciclos;
  float        rst_ciclos;
  int          max_quantum;
  int          rst_quantum;
  int          timestamp;
  int          prioridade;
  int          punicao;
  int          segmentos;
  int          posicao;
  int          tentativas;
  bool         alocado;
  bool         punido;
  list<string> tipo;

  Processo();

  Processo(int          processo,
           int          ciclos,
           int          cnt_ciclos,
           float        rst_ciclos,
           int          max_quantum,
           int          rst_quantum,
           int          timestamp,
           int          prioridade,
           int          punicao,
           int          segmentos,
           int          posicao,
           int          tentativas,
           bool         alocado,
           bool         punido,
           list<string> tipo);
  void imprimir();
};
#endif