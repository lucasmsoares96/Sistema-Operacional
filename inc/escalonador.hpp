#ifndef __ESCALONADOR_HPP
#define __ESCALONADOR_HPP

#include <unistd.h>

#include <chrono>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <thread>

#include "../inc/kernel.hpp"
#include "../inc/processo.hpp"

using namespace std;

class Escalonador {
 private:
  string         nome_arquivo;
  string         politica;
  list<Processo> processos_novos;
  list<Processo> processos_bloqueados;
  list<Processo> processos_prontos;
  list<Processo> processos_finalizados;
  list<Processo> processos_concluidos;
  Processo       processo_executando;
  string         tipos[3];

  void           ler_processos();
  void           gerar_resultado();
  void           executar_politica();
  void           executar_mecanismo();

 public:
  Kernel* kernel;
  Escalonador(Kernel* kernel, string nome_arquivo);
  void executar_escalonador();
};

#endif