#include "../inc/processo.hpp"

Processo::Processo() {
  processo    = 0;
  ciclos      = 0;
  cnt_ciclos  = 0;
  max_quantum = 0;
  timestamp   = 0;
  prioridade  = 0;
  punicao     = 0;
  punido      = false;
  tipo        = list<string>();
}

Processo::Processo(int          processo,
                   int          ciclos,
                   float        cnt_ciclos,
                   int          max_quantum,
                   int          timestamp,
                   int          prioridade,
                   int          punicao,
                   bool         punido,
                   list<string> tipo) {
  this->processo    = processo;
  this->ciclos      = ciclos;
  this->cnt_ciclos  = cnt_ciclos;
  this->max_quantum = max_quantum;
  this->timestamp   = timestamp;
  this->prioridade  = prioridade;
  this->punicao     = punicao;
  this->punido      = punido;
  this->tipo        = tipo;
}

void Processo::imprimir() {
  cout.precision(2);
  cout << "Processo: " << processo << "\tCiclos: " << ciclos
       << "\tCnt_Ciclos: " << cnt_ciclos
       << "\tMax_Quantum: " << max_quantum << "\tTimestamp: " << timestamp
       << "\tPrioridade: " << prioridade;
  //  << "\tPunição: " << punicao
  //  << "\tPunido: " << punido;
  if (tipo.size() > 0) {
    cout << "\tTipo: " << tipo.back() << endl;
  } else {
    cout << "\tTipo: " << endl;
  }
}