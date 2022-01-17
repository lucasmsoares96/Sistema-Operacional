#include "../inc/processo.hpp"

Processo::Processo() {
  processo    = 0;
  ciclos      = 0;
  cnt_ciclos  = 0;
  max_quantum = 0;
  timestamp   = 0;
  prioridade  = 0;
  punicao     = 0;
  cnt_quantum = 0;
  punido      = false;
  tipo        = list<string>();
}

Processo::Processo(int          processo,
                   int          ciclos,
                   int          cnt_ciclos,
                   int          max_quantum,
                   int          timestamp,
                   int          prioridade,
                   int          punicao,
                   int          cnt_quantum,
                   bool         punido,
                   list<string> tipo) {
  this->processo    = processo;
  this->ciclos      = ciclos;
  this->cnt_ciclos  = cnt_ciclos;
  this->max_quantum = max_quantum;
  this->timestamp   = timestamp;
  this->prioridade  = prioridade;
  this->punicao     = punicao;
  this->cnt_quantum = cnt_quantum;
  this->punido      = punido;
  this->tipo        = tipo;
}

void Processo::imprimir() {
  cout << "Processo:    " << processo << "\tCiclos:      " << ciclos
       << "\tCnt Ciclos:  " << cnt_ciclos
       << "\tMax Quantum: " << max_quantum
       << "\tCnt Quantum: " << cnt_quantum
       << "\tTimestamp:   " << timestamp << "\tPrioridade:  " << prioridade
       << "\tPunição:     " << punicao << "\tPunido:      " << punido
       << endl;
  //  << "\tTipo:        " << tipo.back() << endl;
}