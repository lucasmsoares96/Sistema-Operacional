#include "../inc/processo.hpp"

Processo::Processo() {
  processo    = 0;
  ciclos      = 0;
  cnt_ciclos  = 0;
  rst_ciclos  = 0;
  max_quantum = 0;
  rst_quantum = 0;
  timestamp   = 0;
  prioridade  = 0;
  punicao     = 0;
  segmentos   = 0;
  posicao     = 0;
  tentativas  = 0;
  punido      = false;
  alocado     = false;
  tipo        = list<string>();
}

Processo::Processo(int          processo,
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
                   bool         punido,
                   bool         alocado,
                   list<string> tipo) {
  this->processo    = processo;
  this->ciclos      = ciclos;
  this->cnt_ciclos  = cnt_ciclos;
  this->rst_ciclos  = rst_ciclos;
  this->max_quantum = max_quantum;
  this->rst_quantum = rst_quantum;
  this->timestamp   = timestamp;
  this->prioridade  = prioridade;
  this->punicao     = punicao;
  this->segmentos   = segmentos;
  this->posicao     = posicao;
  this->punido      = punido;
  this->tentativas  = tentativas;
  this->alocado     = alocado;
  this->tipo        = tipo;
}

void Processo::imprimir() {
  cout.precision(2);
  cout << "Processo: " << processo << "\tCiclos: " << ciclos
       << "\tCnt_Ciclos: " << cnt_ciclos << "\tRst_Ciclos: " << rst_ciclos
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